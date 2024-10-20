from food import Food
import random

class User:
    def __init__(self, name, score = 0):
        if not isinstance(name, str):
            raise ValueError("Name should be a string!")
        self.name = name

    def getName(self):
        print(f"User name is: {self.name}")

    # Take the whole list? Who should choose a food item?
    def play(items=list(Food)) -> None:
        # give me a question: asks from a food item

        # 

        # loads data into database
        # create container to store obejcts in memory when a user decides to play

        





user1 = User('matyika')
user1.getName()