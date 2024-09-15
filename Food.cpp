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
    std::cout << "Your choice: ";

    // Get user input
    float userGuess;
    std::cin >> userGuess;

    // Calculate the allowed range (±10%)
    float lowerBound = actualValue * 0.9;
    float upperBound = actualValue * 1.1;

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