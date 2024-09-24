# EQUATION SOLVER

## Overview
**EQUATION SOLVER** is a C-based program designed to solve polynomial equations of degree up to 2 and systems of linear equations with up to 3 unknowns. The program uses standard formulas for solving linear and quadratic equations, and the Echelon form of matrices to find the solutions of systems of equations involving up to 3 variables.

## Features
- Solve **linear equations** of the form `ax + b = 0`
- Solve **quadratic equations** of the form `ax² + bx + c = 0`
- Solve systems of equations with up to **3 unknown variables** using matrix Echelon form
- Displays clear results for the calculated roots or unknown variables, if solutions exist

## How It Works
When the program is run, the user is greeted with a simple menu to choose from the following options:
1. Solve a **polynomial equation** (either linear or quadratic)
2. Solve for **unknown variables** using a system of linear equations
3. Exit the program

### Polynomial Solver
The user can choose to solve:
1. A **linear equation** (`ax + b = 0`): Enter the constants `a` and `b` to find the root `x`.
2. A **quadratic equation** (`ax² + bx + c = 0`): Enter the constants `a`, `b`, and `c` to find the roots `x₁` and `x₂`.

### System of Equations Solver
The program can solve for systems with either 2 or 3 unknowns (`x`, `y`, `z`). The user provides coefficients and constants for the equations, which the program will solve using matrix Echelon form.

#### For 2 Unknowns (`x`, `y`):
The user provides coefficients for 2 equations in the form:

- `a₁x + b₁y = d₁`  
- `a₂x + b₂y = d₂`

#### For 3 Unknowns (`x`, `y`, `z`):
The user provides coefficients for 3 equations in the form:

- `a₁x + b₁y + c₁z = d₁`  
- `a₂x + b₂y + c₂z = d₂`  
- `a₃x + b₃y + c₃z = d₃`

The program processes these inputs and outputs the values for `x`, `y`, and `z` (if a solution exists).





