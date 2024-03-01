# Tower of Hanoi Simulation

A C program to simulate the Tower of Hanoi puzzle. The program utilizes a stack data structure to represent each of the three poles and demonstrates the solution for moving a stack of disks from one pole to another, adhering to the puzzle's rules.

## Features

- Customizable tower size through user input.
- Utilizes stack operations (push and pop) to simulate disk moves.
- Prints each disk move from source to destination pole.

## Compilation and Execution

1. **Compilation**: Compile the program using a C compiler, such as GCC, with the command: `gcc -o tower_of_hanoi main.c`.
2. **Running the Program**: Run the compiled program with `./tower_of_hanoi` and follow the prompts to enter the tower size.

## How It Works

1. The program prompts the user to input the number of disks in the tower.
2. It then calculates the total number of moves required and displays each move, following the rules of the Tower of Hanoi puzzle.
3. Disks are moved between poles using a specific algorithm that ensures the minimum number of moves is used.

## Understanding the Output

- The output consists of a series of instructions indicating how to move each disk from one pole to another.
- The poles are represented as 1 (source pole), 2 (auxiliary pole), and 3 (destination pole).

Enjoy solving the Tower of Hanoi puzzle with any number of disks!
