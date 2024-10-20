from pathlib import Path
from food import Food
import random

# Function definitions
def convert_vals(line):
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
    #food_items[-1].displayInfo()

megegy_menet = True
while(megegy_menet):
    print('Please input a number according to your choice and press ENTER.')
    print('1 - Give me a question!')
    print('2 - Exit.')
    choice = input('Input: ')
    try:
        choice = int(choice)
    except ValueError:
        raise ValueError('Your choice should be a whole number.')
    
    match choice:
        case 1:
            food_items[random.randint(0, len(food_items) - 1)].askQuestion()
            continue
        case 2:
            megegy_menet = False
        case default:
            "Choose 1 || 2."

















# Display 5 random food items
for _ in range(5):
    a = food_items[random.randint(0, len(food_items) - 1)]
    a.askQuestion()