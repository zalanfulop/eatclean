import duckdb
from pathlib import Path

# A shell script could be used to create the .db
# For now I will touch it.
path_to_data = Path(__file__).parent.parent / 'data'
database = duckdb.connect(path_to_data / 'appetit.db')

# returns a list
result = database.execute("SHOW TABLES").fetchall()

if len(result) == 0:
    table_data_path = path_to_data / 'user_data.csv'
    database.execute(f"CREATE TABLE users AS SELECT * FROM '{table_data_path.as_posix()}'")
    print('A new table was created.')

print(database.execute("SHOW TABLES").fetchall())
print(database.execute("SELECT * FROM users").fetchall())
database.close()
