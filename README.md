# Fillit

My implementation of [42-fillit](fillit.en.pdf)

### Introduction
Fillit is a project that lets you discover and/or familiarize yourself with a recurring problem in programming: searching for the optimal solution among a huge set of possibilities. In this particular project, you will be charged with creating an algorithm which fits some Tetriminos together into the smallest possible square. A Tetriminos is a 4-blocks geometric figure that most of you might know thanks to the popular game Tetris.

### Goals
Fillit does not consist of recoding Tetris, even if it’s still a variant of this game. Your program will take a file as parameter which contains a list of Tetriminos and arrange them to create the smallest square possible. Obviously, your main goal is to find this smallest square in the minimal amount of time, despite a exponentially growing number of possibilities each time a piece is added. Then, you will have to think carefully about your data structures and your solving algorithm, if you want your program answers before the next millenium.

## Installation

### Requirements
* GNU make
* GNU C Compiler (GCC)

## Usage
```
git clone https://github.com/mihailgolban/Fillit.git
cd Fillit
make
./fillit file
```
## License
[MIT](https://choosealicense.com/licenses/mit/)
