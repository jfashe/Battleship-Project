# Readme.md
# ⚓ Battleship - C++ Terminal Game

A simple terminal-based Battleship game written in C++. This project demonstrates object-oriented programming, user input validation, and random ship placement logic using the C++ Standard Library. The game runs in a 5x5 grid and allows the user up to 15 attempts to sink 5 randomly placed ships.

## 🎮 Gameplay

- You attack by entering a pair of coordinates (row and column), both between **1 and 5**.
- The game provides feedback for **hits**, **misses**, and **duplicate attempts**.
- You win by sinking all 5 ships before using up your 15 attacks.

### Example Output:
```
BATTLESHIP * * *
  1 2 3 4 5
1 ~ ~ ~ H ~
2 ~ M ~ ~ ~
3 ~ ~ ~ ~ ~
4 M ~ ~ H ~
5 ~ ~ ~ ~ ~

Your move:
```

## 🚀 Features

- **Random ship placement** using the `#random` library and `random_device`.
- **Input validation** to prevent invalid or non-numeric entries.
- **Simple game loop** that tracks score and remaining attacks.
- **Grid masking**: Ships are hidden until hit.

## C++ Concepts Used

- Object-Oriented Programming (Classes, Constructors and Encapsulation)
- 2D Arrays for grid management
- Random number generation (`<random>`)
- Input validation (`cin.clear()` and `cin.ignore()`)
- Loops and conditionals for game logic

## How to Compile and Run

1. Save the file as `main.cpp`.

2. Compile:
```bash
g++ main.cpp -o playBattleship

3. Run:
./playBattleship
```
By Joshua Fashe

Blinn College
Originally developed as a class project.