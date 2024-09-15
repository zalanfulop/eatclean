#include "Food.h"
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    // Define file to be opened
    std::ifstream inputFile("food_data_clean.csv");

    // Check if the file was succesfully opened
    if (!inputFile.is_open()) {
        std::cout << "Could not open the file." << std::endl;
        return 1;
    }
    // Container definition to store food objects
    std::vector<Food*> shop_bag;
    std::string line, name;
    // Variable to store calory content [kCal]/100g
    int energy;
    // Variable to store nutrient content of meals [g]/100g
    std::vector<float> floats;
    
    
    while(std::getline(inputFile, line)) {
        std::stringstream ss(line);

        // Clear vector for new data
        floats.clear();

        // Variable to store [name], [nutrient value] strings before conversion
        std::string temp;
        // Variables to store data for Object initialization
        //float fat, sat_fat, chydrate, sugar, fiber, protein, salt;
        // Parse name
        std::getline(ss, name, ';');
        // Parse energy
        std::getline(ss, temp, ';');
        try {
            energy = std::stoi(temp);
        } catch (std::invalid_argument& e) {
            std::cerr << "Invalid number format for energy: " << temp << std::endl;
            continue; // Skip this line if conversion fails
        }
        
        // Read the rest of the nutrient values
        while (std::getline(ss, temp, ';')) {
            try {
                floats.push_back(std::stof(temp));
            } catch (std::invalid_argument& e) {
                std::cerr << "Invalid number format for nutrient: " << temp << std::endl;
                continue; // Skip this line if conversion fails
            }    
        }

        if (floats.size() == 7) {
            // Ensure you have exactly 7 nutrients to pass to the Food constructor
            Food* food = new Food(name, energy, floats[0], floats[1], floats[2], floats[3], floats[4], floats[5], floats[6]);
            shop_bag.push_back(food);
        } else {
            std::cerr << "Skipping line due to incorrect number of nutrients: " << line << std::endl;
        }

    }
    //std::cout << "Size of Food object: " << sizeof(Food) << " bytes" << std::endl;
    // Display the first ten food objects
    for(int i = 0; i < std::min(10, (int)shop_bag.size()); ++i) {
        shop_bag[i]->displayInfo(); 
    }

    for (Food* food : shop_bag) {
        delete food;
    }
    return 0;
}