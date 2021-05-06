import csv
import cs50
from sys import argv, exit

if len(argv) > 2:
    print("Usage: python import.py <csv file>")


open("students.db", "w").close()
db = cs50.SQL("sqlite:///students.db")

db.execute("CREATE TABLE Students (firstName TEXT, middleName TEXT NULL, lastName TEXT, house TEXT, birth NUMERIC)")

with open(argv[1], "r") as characterFile:
    reader = csv.DictReader(characterFile)

    for row in reader:

        name = row["name"].split(" ")
        house = row["house"]
        birth = row["birth"]

        if len(name) >= 3:
            firstName = name[0]
            middleName = name[1]
            lastName = name[2]

            db.execute("INSERT INTO Students(firstName, middleName, lastName, house, birth) VALUES(?, ?, ?, ?, ?)", firstName, middleName, lastName, house, birth)

        else:
            firstName = name[0]
            middleName = None
            lastName = name[1]

            db.execute("INSERT INTO Students(firstName, middleName, lastName, house, birth) VALUES(?, ?, ?, ?, ?)", firstName, middleName, lastName, house, birth)






