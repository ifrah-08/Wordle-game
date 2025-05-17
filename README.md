# Wordle-game
A simple C-based text version of the Wordle game. Guess the 5-letter word in 6 tries with feedback: `*` for correct position, `?` for correct letter wrong position, and `-` for incorrect letters. Uses dictionary and solution word lists from files.

📋 Description

This is a text-based Wordle game implemented in C. The player has 6 tries to guess a 5-letter word randomly selected from a solution list.

🎮 How to Play

Start the game via the menu.
Enter a valid 5-letter word (must exist in `dictionary.txt`).
Feedback per guess:

`*` → Correct letter in the correct position
`?` → Correct letter in the wrong position
`-` → Incorrect letter

✅ Game Rules

Invalid entries (not 5 letters or not in dictionary) are rejected.
  Game ends when the word is guessed or 6 tries are used.
  Win/loss message displayed accordingly.

🗂 Files

`main.c` – main program (complete `gameplay()` function)
`data/dictionary.txt` – list of valid guess words
`data/solutions.txt` – possible answers

🛠 Instructions

1. Create a new C project and add `main.c`.
2. Ensure `dictionary.txt` and `solutions.txt` are in the `data/` folder.
3. Complete the `gameplay()` function based on the game rules.

