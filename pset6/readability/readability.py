from cs50 import get_string

sentence = get_string("Text: ")

L = 0
W = 0
S = 0

for i in range(len(sentence)):
    if sentence[i].isalpha():
        L += 1
    if sentence[i] == " ":
        W += 1
    if sentence[i] == "." or sentence[i] == "!" or sentence[i] == "?":
        S += 1


W2 = W + 1
aveL = (L / W2) * 100
aveS = (S / W2) * 100

index = int(round(0.0588 * aveL - 0.296 * aveS - 15.8))

if index > 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print("Grade: " + str(index))