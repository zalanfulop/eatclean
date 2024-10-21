from food import Food
import random

class User:
    def __init__(self, name = str, score = 0):
        if not isinstance(name, str):
            raise ValueError("Name must be a string.")
        if not isinstance(score, int):
            raise ValueError("Score must be an integer.")

        self.name = name
        self.score = score

    def getName(self):
        print(f"User name is: {self.name}")

    def getScore(self):
        print(f'Score of {self.name} is {self.score}')

    # Take the whole list? Who should choose a food item?
    def play(self, items=list[Food]) -> None:
        if items[random.randint(0, len(items) - 1)].askQuestion():
            self.score += 1;


    def saveScore(self):
        pass
        # give me a question: asks from a food item

        # 

        # loads data into database
        # create container to store obejcts in memory when a user decides to play

        





user1 = User('matyika')
user1.getName()