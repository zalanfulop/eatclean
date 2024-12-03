from pathlib import Path
from food import Food
from user import User
import random
import duckdb

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

# Path which is common for both food and user data
path_base = Path(__file__).parent.parent / 'data'
path_food = path_base / 'food_data_clean.csv'
path_user = path_base / ''

# Open te file and read it's content
with open (path_food, 'r') as file:
    data = file.read()

# Define a container to hold all food items in memory
food_items = list()

# Fill up the list with Food instances.
for line in data.split('\n'):
    food_items.append(Food(*convert_vals(line)))

# Create a DuckDB to store user info.
# For now, you won't be able to update the table
# Should I update the database and then write the csv as well?
database = duckdb.connect(path_base / 'appetit.db')

# Get the number of tables defined in the database
tables = database.execute("SHOW TABLES").fetchall()
# If there are not any, create one for the users.
if len(tables) == 0:
    table_data_path = path_base / 'user_data.csv'
    database.execute(f"CREATE TABLE users AS SELECT * FROM '{table_data_path.as_posix()}'")
    print('The users table was created.')



# Choose an existing user
user = None

# Case structure for interactive user experience.
megegy_menet = True
while megegy_menet:
    print('----------------------------------------')
    if not user == None:
        # Logic to give info on username and current score.
        print(f'You are logged in as: {user.getName()}. Your score is: {user.getScore()}')
        print('----------------------------------------')
    print('Please input a number according to your choice and press ENTER.')
    print('1 - Log in with an existing user.')
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
            # The input is always a string
            username = input('Username: ')
            # A list holding a tuple: (name, score)
            # (Assumes that there are no users with the same name.)
            user_data = database.execute(f"SELECT * FROM users WHERE name = '{username}'").fetchall()

            # When the list contain a tuple
            if user_data:
                user = User(*user_data[0])
            else:
                print('There are not any user with the provided name.')
        case 2:
            if not user == None:
                answer_bool = food_items[random.randint(0, len(food_items) - 1)].askQuestion()
                #print(f'Valaszod helyes?: {answer_bool}')
                user.play(answer_bool)
            else:
                print('You need to log in to play.')

        case 3:
            # To exit the case loop.
            megegy_menet = False
            # Close database
            database.close()

            print('Good bye!')
        case default:
            print("Choose 1, 2 or 3.")