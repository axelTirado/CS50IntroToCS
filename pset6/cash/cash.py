from cs50 import get_float
import sys

coin = get_float("Change owed: ")

if coin > 0:
    cents = round(coin * 100)

    quarter = int(cents / 25)
    dime = int((cents % 25) / 10)
    nickle = int(((cents % 25) % 10) / 5)
    pennie = int((((cents % 25) % 10) % 5))

    print(quarter + dime + nickle + pennie)

else:
    coin = get_float("Change owed: ")