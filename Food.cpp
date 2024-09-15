#include "Food.h"

// Implementation of the Food class
// Should I use pass by reference?
Food::Food(const std::string& name, int energy, float fat, float sat_fat, float chydrate, float sugar, float fiber, float protein, float salt) : name(name), energy(energy), fat(fat), sat_fat(sat_fat), chydrate(chydrate), sugar(sugar), fiber(fiber), protein(protein), salt(salt) {}

void Food::displayInfo() const {
    std::cout << "Energy: " << energy << " kJ" << std::endl;
}