#include <iostream>
#include <thread>
#include <chrono>
#include <stdlib.h>

enum state { dead, alive };

class Cell {
public:
	state current_state;
	state buffer_state;

	Cell() {
		int temp = rand() % 2;
		current_state = (temp) ? dead : alive;
		buffer_state = current_state;
	}
};

Cell** makegrid(int size) {
	Cell** my_grid = new Cell * [size];
	for (int i = 0; i < size; i++) {
		my_grid[i] = new Cell[size];
	}

	return my_grid;
}

void checkstate(Cell** my_grid, int size) {
	int alive_count = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			//up
			if (my_grid[((i + size + 1) % size)][j].current_state == alive) {
				alive_count++;
			}
			//down
			if (my_grid[((i - size + 1) % size)][j].current_state == alive) {
				alive_count++;
			}
			//right
			if (my_grid[i][((j + size + 1) % size)].current_state == alive) {
				alive_count++;
			}
			//left
			if (my_grid[i][((j + size - 1) % size)].current_state == alive) {
				alive_count++;
			}
			//upright
			if (my_grid[((i + size + 1) % size)][((j + size + 1) % size)].current_state == alive) {
				alive_count++;
			}
			//upleft
			if (my_grid[((i + size + 1) % size)][((j - size + 1) % size)].current_state == alive) {
				alive_count++;
			}
			//downright
			if (my_grid[((i - size + 1) % size)][((j + size + 1) % size)].current_state == alive) {
				alive_count++;
			}
			//downleft
			if (my_grid[((i - size + 1) % size)][((j - size + 1) % size)].current_state == alive) {
				alive_count++;
			}

			if (alive_count < 2 or alive_count > 3) {
				my_grid[i][j].buffer_state = dead;
			}

			else if (alive_count == 2 or alive_count == 3) {
				my_grid[i][j].buffer_state = alive;
			}
		}

	}

}

void displaygrid(Cell** my_grid, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			my_grid[i][j].current_state = my_grid[i][j].buffer_state;
			if (my_grid[i][j].current_state == alive) {
				std::cout << "* ";
			}

			else {
				std::cout << ". ";
			}
			

		}
		std::cout << "\n";
	}
}

void sleep_for(int milisecond) {
	std::this_thread::sleep_for(std::chrono::milliseconds(milisecond));
}

void clear_console() {
	system("cls");
}
