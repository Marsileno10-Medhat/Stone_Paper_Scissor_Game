# Rock-Paper-Scissors Game

This project is a C++ console-based implementation of the classic Rock-Paper-Scissors game, designed to allow a player to compete against the computer over multiple rounds. The system tracks game statistics and provides a colorful interface for an engaging user experience. Below is an overview of the functionality and implementation details for version 1.0.

## Version 1.0

The initial version of the Rock-Paper-Scissors game offers a complete gaming experience with the following features:

- **Gameplay**:
  - Players choose between **Stone (Rock)**, **Paper**, or **Scissor** for each round.
  - The computer randomly selects its choice using a random number generator.
  - The winner of each round is determined based on standard rules:
    - Stone beats Scissor.
    - Paper beats Stone.
    - Scissor beats Paper.
    - Identical choices result in a draw.

- **Round Management**:
  - Users specify the number of rounds (1 to 10) at the start.
  - Each round displays the player's choice, the computer's choice, and the round winner.
  - Results are color-coded: green for player wins, red for computer wins, and yellow for draws.

- **Game Statistics**:
  - Tracks the number of player wins, computer wins, and draws.
  - Displays a final game summary with the total rounds, win counts, and the overall winner (player, computer, or draw).
  - The final winner is determined by comparing the number of wins, with draws as a fallback if wins are equal.

- **User Interface**:
  - Console-based interface with clear prompts for input.
  - Input validation ensures valid choices (1 for Stone, 2 for Paper, 3 for Scissor) and round numbers (1 to 10).
  - Option to play again after each game, resetting the screen and colors.

- **Implementation Details**:
  - Uses `struct st_round_info` to store round-specific data (round number, player choice, computer choice, winner).
  - Uses `struct st_full_game_results` to store game statistics (rounds, win counts, final winner).
  - Employs enums (`en_winner` and `en_game_choice`) for managing game states and choices.
  - Random number generation is seeded with `srand((unsigned)time(NULL))` for varied computer choices.
  - Console color changes are implemented using `system("color")` commands (Windows-specific).
  - Standard C++ libraries (`iostream`, `cstdlib`) are used for input/output and random number generation.

### Usage
- **Prerequisites**:
  - A C++ compiler (e.g., g++).
  - The program is designed for Windows due to the use of `system("color")` for console color changes. For other platforms, color functionality may need adjustment.
- **Steps**:
  1. Compile the code: `g++ lvl5_stone_paper_scissor_game.cpp -o RockPaperScissors`.
  2. Run the executable: `./RockPaperScissors`.
  3. Enter the number of rounds (1 to 10).
  4. For each round, select a choice (1 for Stone, 2 for Paper, 3 for Scissor).
  5. View round results and the final game summary.
  6. Choose to play again (Y/N) to start a new game.

### Limitations
- Color functionality is Windows-specific and may not work on other operating systems without modification.
- No persistent storage of game results (e.g., saving scores to a file).
- Limited input validation (assumes numeric inputs; no handling for non-numeric inputs).
- Single-player mode only (no multiplayer support).

### Future Improvements
- Add cross-platform support for console colors (e.g., using ANSI escape codes).
- Implement persistent storage for game results or high scores.
- Enhance input validation to handle non-numeric or invalid inputs gracefully.
- Add support for multiple players or difficulty levels for the computer.
- Include sound effects or additional visual enhancements for a richer experience.