import csv
from sys import argv, exit
import re

if len(argv) < 3:
    print("invalid number of arguments, there should be 3.")
    exit()

with open(argv[1], "r") as database:
    datafile = list(csv.reader(database))
    datafile[0].remove("name")
    keys = datafile[0]



with open(argv[2], "r") as sequence:
    sequencefile = sequence.read()

List = []

for i in range(len(keys)):
    maximum = 0
    count = 0
    position = 0
    prev = 0

    while position < len(sequencefile):
        position = sequencefile.find(keys[i], position)

        if position == -1:
            count = 0
            break

        elif position != -1 and prev == 0:
            count += 1
            maximum = count
            prev = position

        elif position != -1 and ((position - len(keys[i])) == prev):
            count += 1
            prev = position
            if maximum < count:
                maximum = count

        elif position != -1 and ((position - len(keys[i])) != prev):
            count = 1
            prev = position
            if maximum < count:
                maximum = count

        position += 1

    List.append(maximum)

List = list(map(str, List))

newList = list(datafile)
newList.pop(0)

for person in newList:
    if person[1:] == List:
        print(f"{person[0]}")
        break

    elif person == newList[-1]:
        print("no match")





