import cs50
from sys import argv, exit

if len(argv) != 2:
    print("invalid number of arguments, usage: python roster.py <house name>")

if len(argv) == 2:

    db = cs50.SQL("sqlite:///students.db")

    line = db.execute("SELECT firstName, middleName, lastName, house, birth FROM Students WHERE house = ? ORDER BY lastName ASC",argv[1])

    for row in line:
        firstName = row["firstName"].strip()
        lastName = row["lastName"].strip()
        birth = str(row["birth"]).strip()

        if row["middleName"] != None:
            middleName = row["middleName"].strip()
            print(firstName + " " + middleName + " " + lastName + ", born " + birth)

        else:
            print(firstName + " " + lastName + ", born " + birth)


