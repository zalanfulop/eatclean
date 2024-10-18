#ifndef USER_H
#define USER_H
#include <iostream>
#include <fstream>
#include <sstream>

class User{
private:
    std::string name;
    int score;
    // Save current score
    void saveScore() const;
public:
    // Constructor
    User(const std::string& name);
    // Constructor if the user is loaded from file
    User(const std::string& name, int score);



    // Getters
    std::string getName() const;
    int getScore() const;

    // Update score
    void addScore(int points);

    // Display user info
    void displayInfo() const;
};
#endif