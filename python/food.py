
import random

class Food:
    def __init__(self, name, energy, fat, sat_fat, chydrate, sugar, fiber, protein, salt):
        if not isinstance(name, str):
            raise ValueError('Name should be a string!')
        if not isinstance(energy, (int, float)) or energy < 0:
            print(type(energy), energy)
            raise ValueError('Energy should be a non-negative number!')
        if not all(isinstance(val, (int, float)) and val >= 0 for val in [fat, sat_fat, chydrate, sugar, fiber, protein, salt]):
            raise ValueError('Nutrient values should be non-negative numbers!')
        
        # single underscore to indicate privateness
        self._name = name
        self._energy = energy
        self._fat = fat
        self._sat_fat = sat_fat
        self._chydrate = chydrate
        self._sugar = sugar
        self._fiber = fiber
        self._protein = protein
        self._salt = salt

    def displayInfo(self) -> None:
        print(f"Name of food: {self._name}")
        print(f'Energy: {self._energy} kCal.')


    def askQuestion(self) -> bool:
        """Tells the user which food is in question.
        Randomly picks a nutritional value and asks the user to guess the value.
        Returns True if the answer was in the allowed range, False otherwise.
        """
        nutri_names = ('fat', 'saturated fat', 'carbohydrate', 'sugar', 'fiber', 'protein', 'salt')
        nutri_vals = (self._fat, self._sat_fat, self._chydrate, self._sugar, self._fiber, self._protein, self._salt)
        randIndex = random.randint(0, len(nutri_names) - 1)
        actualValue = nutri_vals[randIndex]

        print(f'Name of food: {self._name}')
        print(f'How many grams of {nutri_names[randIndex]} are in 100g of this food?')

        while True:
            userGuess = input("Your choice: ")
            try:
                userGuess = float(userGuess)
                break
            except ValueError:
                print('The guess should be a number.')
                #raise ValueError("The guess should be a number.")

        # Define the bounds of the accepted answer interval
        bonus = 2
        lowerBound, upperBound = actualValue * 0.9 - bonus, actualValue * 1.1 + bonus

        # Check if the guess is in the allowed range
        if userGuess >= lowerBound and userGuess <= upperBound:
            print('Correct! Your guess was within the allowed range.')
            print(f'The exact value is: {actualValue} g.')
            return True
        else:
            print(f'Incorrect. The correct answer is: {actualValue} g.')
            return False