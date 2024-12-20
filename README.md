Do you ever check the nutrient values on the back of food products you buy? Well, I do. It even became a game in the group to guess nutritional content of snacks before tasting them. As someone who codes, I decided to build this program to get infinitely (or so) many questions to test and enhance our knowledge on what we eat.. and to have fun!

- I got the data from Aleksandr Antonov, Kaggle which is available on this link: [Aleksandr Antonov](https://www.kaggle.com/datasets/trolukovich/nutritional-values-for-common-foods-and-products). 
- The extensively annotated process of data cleaning is found in *../data/data_cleaning.ipynb*. The raw data: *data/nutrition.xlsx*, cleaned data: *food_data_clean.csv*. 
- When I started, learning C++ on the go was one of my objectives. The code is is found at the *cplusplus* folder, and it could be complied with the Makefile. It uses *user_data.txt* to prototype user management system. 
- I realized that it would be beneficial to focus on my Python skills more, so I started to rewrite the whole thing in Python. This allowed me to get to know DuckDB and it's API. These aspirations can be found in the *python* directory. 
- I made an attempt to use a Telegram bot to act as a UI between users and the C++ console application. I managed to send messages to the chatgroup using Python. Can be seen at *telegram_bot/telegram_bot.ipynb*.

Ideas and contributions are welcome!
