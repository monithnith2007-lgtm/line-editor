# Simple Line Editor in C

## Team Members

* Member 1: _monith.s_____________________
* Member 2: ______priyas.r________________
* Member 3: _______sanjay_______________

## Project Description

A simple command-line line editor written in C.

The editor allows users to create, view, modify, save, and load a small text document through simple terminal commands.

The document lines are stored in memory using an array of strings.

## Data Structure

The project uses a two-dimensional character array:

```c
char lines[100][200];
```

* Maximum number of lines: 100
* Maximum characters per line: 199
* Each array element stores one line of the document.

This data structure is simple to understand and suitable for a small text editor.

## Features Implemented

The following core features from the problem statement are implemented:

### 1. Insert a Line

Adds a new line of text at a specified line number.

Existing lines are shifted down to make space for the new line.

### 2. Delete a Line

Removes a line at the specified line number.

The lines below it are shifted upward.

### 3. Display the Document

Displays all current lines with their line numbers.

### 4. Save the Document

Saves the current document to:

```text
document.txt
```

### 5. Load the Document

Loads the previously saved document from:

```text
document.txt
```

## Commands

| Command   | Purpose           |
| --------- | ----------------- |
| `insert`  | Add a new line    |
| `delete`  | Delete a line     |
| `display` | Display all lines |
| `save`    | Save the document |
| `load`    | Load the document |
| `exit`    | Exit the editor   |

## Example

```text
===== SIMPLE LINE EDITOR =====
Commands: insert, delete, display, save, load, exit

> insert
Enter line number: 1
Enter text: Hello World
Line inserted successfully.

> display
1. Hello World

> save
Document saved successfully.

> exit
Exiting editor...
```

## Files

```text
line_editor.c
HELP.md
README.md
document.txt
```

### `line_editor.c`

Main C source code containing the line editor implementation.

### `HELP.md`

Contains instructions and examples for using the editor commands.

### `README.md`

Contains project information, features, data structure, and instructions.

### `document.txt`

Stores the saved document.

## How to Compile

Open the terminal in the project folder and run:

```text
gcc line_editor.c -o editor
```

## How to Run

On Windows PowerShell:

```text
.\editor.exe
```

## Requirements

* C compiler such as GCC
* VS Code or another code editor
* Windows Terminal / PowerShell or another command-line terminal

## Project Objective

The objective of this project is to design and build a working command-line line editor in C using basic data structures, functions, file handling, and terminal commands.
