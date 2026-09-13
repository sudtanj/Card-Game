# U-Card

U-Card is a simple console-based card game written in C++. It was originally created for a student project and has since been released for learning, study, and further development.

## Features

- Two-player game against the computer
- Five-card hand comparison
- Console-based card display
- Keyboard-driven game flow
- Windows and Dev-C++ project configuration

## Requirements

- C++ compiler
- Windows operating system
- Dev-C++ (optional; the project includes Dev-C++ configuration files)

## Running the Game

1. Open the project from `cardgame/` in Dev-C++ or another compatible C++ IDE.
2. Build and run the project.
3. Select a player and follow the on-screen keyboard prompts.

The game uses Windows-specific console functions and therefore is intended to run on Windows.

## Game Flow

1. Choose a player.
2. Deal five cards.
3. Compare the lowest-ranked cards.
4. View the final score and result.
5. Play another round or quit.

## Project Structure

```text
cardgame/
└── Card GAme/
    ├── main.cpp
    ├── UCard_private.h
    ├── Makefile.win
    └── Dev-C++ project files
```

## Screenshots

- [Screenshot 1](ss1.png)
- [Screenshot 2](ss2.png)
- [Screenshot 3](ss3.png)
- [Screenshot 4](ss4.png)

## Planned Improvements

- Improve the card layout and console styling
- Add clearer menus, prompts, and status information
- Replace screen-clearing with a reusable UI function
- Improve input handling and keyboard flow
- Refactor the code into separate game, card, and UI modules
- Replace raw arrays with safer C++ containers
- Improve random-card generation and deck handling
- Add animations, sound effects, and a polished result screen

## License

See the [`LICENSE`](LICENSE) file for project licensing information.
