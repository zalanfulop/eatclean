#include "User.h"

// Constructor
User::User(std::string& name): name(name), score(0) {}
// Constructor when the user is loaded from file
User::User(std::string& name, int score): name(name), score(score) {}

// Getters
std::string User::getName() const { return name; }
int User::getScore() const { return score; }

// Update score
void User::addScore(int points) { score += points; }

// Display user info
void User::displayInfo() const {
    std::cout << "User: " << name << " | Score: " << score << std::endl;
}