class User:
    def __init__(self, name = str, score = 0):
        if not isinstance(name, str):
            raise ValueError("Name must be a string.")
        if not isinstance(score, int):
            raise ValueError("Score must be an integer.")

        self.name = name
        self.score = score

    def getName(self):
        return self.name

    def getScore(self):
        return self.score

    # 
    # 
    def play(self, win) -> None:
            """ Add a score if the user gives a correct answer.
            Gets the input: return value of a Food object's askQuestion method.
            """
            if win:
                 self.score += 1

    def saveScore(self):
        pass
        # give me a question: asks from a food item

        # 

        # loads data into database
        # create container to store obejcts in memory when a user decides to play