#ifndef FOOD_H
#define FOOD_H
#include <iostream>

// Definition of Food class
class Food{
private:
    std::string name;
    // Energy is in kJ
    int energy;
    // Idea: aggregate data in a struct
    float fat, sat_fat, chydrate, sugar, fiber, protein, salt;
public:
    // Constructor
    Food(const std::string& name, int energy, float fat, float sat_fat, float chydrate, float sugar, float fiber, float protein, float salt);

    // Method to display information about the food
    void displayInfo() const;
};


#endif