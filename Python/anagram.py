#!/usr/bin/python3

""" This is a python console anagram game.
It is meant for education/entertainment only
"""

while True:
    level = input("Please select your preferred level:\n1: easy\n2: medium\n3: hard\n")
    if level == "1" or level == "2" or level == "3":
        break
    print("Invalid argument. Please choose 1, 2 or 3")

""" process the words in the file according to the user chhosen levels.
level 1 - length <4
level 2 - length 4 - 6
level 3 - length 6 and above.
save sorted words in a a list.
"""

words = []
with open("words.txt", "r") as f:
    for line in f:
        word = line.strip()
        if level == "1" and len(word) < 5:
            words.append(word)
        elif level == "2" and (len(word) >= 4 and len(word) <= 6):
            words.append(word)
        elif level == "3" and len(word) > 5:
            words.append(word)
