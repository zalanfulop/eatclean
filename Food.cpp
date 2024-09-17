#include "Food.h"
#include <cstdlib> // for rand and srand
#include <ctime> // for time

// Implementation of the Food class
// Should I use pass by reference?
Food::Food(const std::string& name, int energy, float fat, float sat_fat, float chydrate, float sugar, float fiber, float protein, float salt) : name(name), energy(energy), fat(fat), sat_fat(sat_fat), chydrate(chydrate), sugar(sugar), fiber(fiber), protein(protein), salt(salt) {}

void Food::displayInfo() const {
    std::cout << "Food Name: " << name << std::endl;
    std::cout << "Energy: " << energy << " kCal" << std::endl;
    std::cout << "Fat: " << fat << " g" << std::endl;
    std::cout << "   Saturated Fat: " << sat_fat << " g" << std::endl;
    std::cout << "Carbohydrates: " << chydrate << " g" << std::endl;
    std::cout << "   Sugars: " << sugar << " g" << std::endl;
    std::cout << "Fiber: " << fiber << " g" << std::endl;
    std::cout << "Protein: " << protein << " g" << std::endl;
    std::cout << "Salt: " << salt << " g" << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void Food::askQuestion(User* user) const {
    // Seed the random generator
    // Cast to unsigned to satisfy srand requirements (time returns a big signed integer)
    srand((unsigned) time(0));

    // List of nutrient names for selection
    // Leave energy out for now
    std::string nutrients[] = {"Fat", "Saturated Fat", "Carbohydrates", "Sugars", "Fiber", "Protein", "Salt"};
    float values[] = {fat, sat_fat, chydrate, sugar, fiber, protein, salt};

    // Randomly select one nutrient
    // %7 limits the possible values to be on the 0..6 interval
    int randomIndex = rand() % 7; // 7 nutrients
    std::string selectedNutrient = nutrients[randomIndex];
    float actualValue = values[randomIndex];

    // Ask the question
    std::cout << "Name of food: " << name << std::endl;
    std::cout << "How many grams of " << selectedNutrient << " are in 100g of this food?" << std::endl;

    // HELP UPDATE
    if (actualValue <= 20) {
        std::cout << "Tipp: 0 - 20" << std::endl;
    } else if (actualValue <= 40 && actualValue > 20) {
        std::cout << "Tipp: 20 - 40" << std::endl;
    } else if (actualValue <= 60 && actualValue > 40 ) {
        std::cout << "Tipp: 40 - 60" << std::endl;
    } else if(actualValue <= 80 && actualValue > 60 ) {
        std::cout << "Tipp: 60 - 80" << std::endl;
    } else std::cout << "Tipp: 80 - 100";

    // Get user input
    std::cout << "Your choice: ";
    float userGuess;
    std::cin >> userGuess;

    // Calculate the allowed range (±10%)
    int bonus = 2;
    float lowerBound = actualValue * 0.9 - bonus;
    float upperBound = actualValue * 1.1 + bonus;

    // Check if the guess is within the range
    if (userGuess >= lowerBound && userGuess <= upperBound) {
        std::cout << "Correct! Your guess was within the allowed range." << std::endl;
        std::cout << "The exact value is: " << actualValue << " g." << std::endl;
        // UPDATE USER SCORE HERE
        user->addScore(1);
    } else {
        std::cout << "Incorrect. The correct answer is " << actualValue << " g." << std::endl;
    }
}