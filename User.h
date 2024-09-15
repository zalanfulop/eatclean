#ifndef USER_H
#define USER_H
#include <iostream>

class User{
private:
    std::string name;
    int score;
public:
    // Constructor
    User(std::string& name);
    // Constructor if the user is loaded from file
    User(std::string& name, int score);

    // Getters
    std::string getName() const;
    int getScore() const;

    // Update score
    void addScore(int points);

    // Display user info
    void displayInfo() const;
};
#endif