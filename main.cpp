#include "Food.h"
//#include "User.h"
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>


// Save user data to file
void saveUserData(const User* user);

// Load user data from file
User* loadUserData(const std::string& username);

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

    int exit = 0;
    User* user = nullptr;
    User* newUser = nullptr;
    int randomIndex;

    do {
        std::cout << "--------------------------------------------------------------" << std::endl;
        std::cout << "Welcome to the Nutrient Guess Game! What would you like to do?" << std::endl;
        if (user == nullptr) {
            std::cout << "Log into your account to start making guesses!" << std::endl;
        } else {
            std::cout << "You are logged in as: " << user->getName() << std::endl;
            std::cout << "Your score is: " << user->getScore() << std::endl;
        }
        std::cout << "1: Give me a question!" << std::endl;
        std::cout << "2: Create a user." << std::endl;
        std::cout << "3: Choose an existing user." << std::endl;
        std::cout << "4: Exit application." << std::endl;
        std::cout << "Your choice: ";
        
        int choice;
        while (true) {
        std::cin >> choice;

        if (std::cin.fail()) {
            // Input failed, meaning the user entered something that's not an integer
            std::cin.clear(); // Clear the error flag on std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter an integer!" << std::endl;
        } else {
            // Input was successful, exit the loop
            break;
        }
    }
        

        std::string name;
        switch (choice) {
            case 1:
                // Check if there is an active user
                if (user == nullptr) {
                    std::cerr << "You need an active user to make guesses." << std::endl;
                    break;
                }
                // Seed the random generator
                srand((unsigned) time(0));
                // Randomly select a food item from the shopping bag
                // (rand() % (upper_bound - lower_bound + 1)) + lower_bound);
                randomIndex = (rand() % (shop_bag.size() + 1));
                shop_bag[randomIndex]->askQuestion(user);
                
                break;
            case 2:
                std::cout << "Please provide a username: ";
                std::cin >> name;
                // Do not assign the newuser to the user pointer defined outside of the do-while
                // This way you can still create users without losing track of the current one
                newUser = new User(name);
                std::cout << "\nUser created with name: " << name << "." << std::endl;
                saveUserData(newUser);
                delete newUser;
                newUser = nullptr;
                break;
            case 3:
                std::cout << "Please provide your username: ";
                std::cin >> name;

                user = loadUserData(name);
                // Implement logic to initialize the chosen user
                break;
            case 4:
                exit = 4;
                break;
            default:
                std::cerr << "Choose 1, 2, 3 or 4.";
                break;
        }
    } while (!(exit == 4));

    /*//std::cout << "Size of Food object: " << sizeof(Food) << " bytes" << std::endl;
    // Display the first ten food objects
    // he cast ensures that if the vector contains fewer than 10 items, the loop will only iterate over the available elements.
    for(int i = 0; i < std::min(10, (int)shop_bag.size()); ++i) {
        //The arrow operator is shorthand for dereferencing a pointer and accessing a member in one step. So, instead of writing:
        // (*shop_bag[i]).displayInfo();
        shop_bag[i]->displayInfo(); 
        //shop_bag[i]->askQuestion(); 
        
    }*/
    delete user;
    for (Food* food : shop_bag) {
        delete food;
    }
    return 0;
}

// Save user data to file
// The const keyword here guarantees that the method will not modify the user
void saveUserData(const User* user) {
    std::ifstream inFile("user_data.txt");
    std::string line, existingName;
    int existingScore;
    bool userExists = false;

    // Check if the username already exists
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        if (iss >> existingName >> existingScore) {
            if (existingName == user->getName()) {
                std::cout << "Username \"" << existingName << "\" already exists. Choose a different name." << std::endl;
                userExists = true;
                break;
            }
        }
    }
    inFile.close();

    // If the user does not exists, save the new user data
    if(!userExists) {
        std::ofstream outFile("user_data.txt", std::ios::app); // Append mode
        outFile << user->getName() << " " << user->getScore() << std::endl;
        outFile.close();
        std::cout << "User \"" << user->getName() << "\" saved succesfully!" << std::endl;
    } 
}

// Load user data from file
User* loadUserData(const std::string& username) {
    std::ifstream inFile("user_data.txt");
    if (!inFile) {
        std::cerr << "Error opening file for loading user data." << std::endl;
        return nullptr;
    }

    std::string line, name;
    int score;

    while (std::getline(inFile, line)) {
        std::stringstream ss(line);
        ss >> name >> score;

        if (name == username) {
            std::cout << "User found: " << name << " with score: " << score << std::endl;
            return new User(name, score); // Return a new user with found name and score
        }
    }
    std::cout << "There is no user associated with this name." << std::endl;
    return nullptr; 
}