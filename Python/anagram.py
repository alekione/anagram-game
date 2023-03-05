#!/usr/bin/python3

""" This is a python console anagram game.
It is meant for education/entertainment only
"""
import random

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

""" create_word() - creates a word depending on;user level
word: word passed to the function for processing
Return: a processed word for user question
"""

def  create_word(word):
    pword = ""
    length = len(word)
    if level == "1":
        ind = random.randint(0, length)
        for i in range(0, length):
            if i == ind:
                pword += "_"
            else:
                pword += word[i]
    elif level == "2":
        ind = [random.randint(0, length) for i in range(0, 2)]
        for i in range(0, length):
            if i in ind:
                pword += "_"
            else:
                pword += word[i]
    else:
        ind = [random.randint(0, length) for i in range(0, 3)]
        for i in range(0, length):
            if i in ind:
                pword += "_"
            else:
                pword += word[i]
    return pword

""" play() - controls all playing features of the game.
user interacts with the program through this function
"""

def play():
    opt = ["y", "Y", "n", "N"]
    again = "Continue playing? y/n"
    ind = 0
    while ind < len(words):
        attempt = 0
        word = create_word(words[ind])
        print("Fill in the blanks:\n")
        print(">>>", word,"\n")
        while True:
            attempt += 1
            user_word = input(">> ")
            if user_word == words[ind]:
                print("Correct.", again)
                while True:
                    res = input(">> ")
                    if res in opt:
                        break
                    print("invalid option!!")
                if res in ["n", "N"]:
                    print("Thanks for playing")
                    exit(0)
                break
            if user_word != words[ind]:
                print("Incorrect. please try again. Attempts: ", 5 - attempt)
            if attempt == 5:
                print("You're hanged. Correct word is:", words[ind])
                print(again)
                res = input(">> ")
                if res in ["n", "N"]:
                    print("Thanks for playing")
                    exit(0)
                break

        ind += 1
    print("Cogratulation on completing all the words on this level.\n", again)
    res = input(">> ")
    if res in ["n", "N"]:
        print("Thanks for playing")
        exit(0)
    play()

play()
