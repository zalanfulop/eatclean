#include "User.h"

// Constructor
User::User(const std::string& name): name(name), score(0) {}
// Constructor when the user is loaded from file
User::User(const std::string& name, int score): name(name), score(score) {}

// Getters
std::string User::getName() const { return name; }
int User::getScore() const { return score; }

// Update score
void User::addScore(int points) { 
    score += points;
    saveScore(); 
}

//Save score
void User::saveScore() const {
    std::ifstream inFile("user_data.txt");
    std::stringstream buffer;
    std::string line, existingName;
    int existingScore;

    // Create a new buffer to rewrite the file with the updated score
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        iss >> existingName >> existingScore;
        if (existingName == name) {
            buffer << name << " " << score << std::endl; // Write updated score
        } else {
            buffer << line << std::endl; // Keep other lines intact
        }
    }    
    inFile.close();

    // Write back the updated content to the file
    std::ofstream outFile("user_data.txt");
    outFile << buffer.str();
    outFile.close();
}

// Display user info
void User::displayInfo() const {
    std::cout << "User: " << name << " | Score: " << score << std::endl;
}