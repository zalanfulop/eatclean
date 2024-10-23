from pathlib import Path
from food import Food
from user import User
import random

# Function definitions
def convert_vals(line = str) -> list:
    """Takes a string of values separated with '|',
    puts the values into a list,
    converts the elements to the correct type for Food class.
    """
    vals = line.split('|')
    vals[1] = int(vals[1])
    for i in range(2, len(vals)):
        vals[i] = float(vals[i])
    return vals

# Define path to data
path = Path(__file__).parent.parent / 'data/food_data_clean.csv'

# Open te file and read it's content
with open (path, 'r') as file:
    data = file.read()

# Define a container to hold all food items in memory
food_items = list()

# Fill up the list with Food instances.
for line in data.split('\n'):
    food_items.append(Food(*convert_vals(line)))

# Choose an existring user
user = User('zazi')

# Case structure for interactive user experience.
megegy_menet = True
while megegy_menet:
    print('Please input a number according to your choice and press ENTER.')
    print('1 - I am a user. Show info!')
    print('2 - Give me a question!')
    print('3 - Exit.')
    while True:
        try:
            choice = int(input('Input: '))
            break
        except ValueError:
            print('The input should be a whole number.')
            #raise ValueError('Your choice should be a whole number.')

    match choice:
        case 1:
            # logic to ask the username and read the user data from a database
            # logic to give info on username and current score
            print(f'You are logged in as: {user.getName()}')
            print(f'Your score is: {user.getScore()}')
        case 2:
            answer_bool = food_items[random.randint(0, len(food_items) - 1)].askQuestion()
            print(f'Valaszod helyes?: {answer_bool}')
            user.play(answer_bool)

        case 2:
            megegy_menet = False
            print('Good bye!')
        case default:
            print("Choose 1 || 2.")