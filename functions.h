#pragma once

enum class state {dead, alive};

class Cell {
public:
	state current_state;
	state buffer_state;

	Cell();
};

Cell** makegrid(int size);
void checkstate(Cell** my_grid, int size);
void displaygrid(Cell** my_grid, int size);
void sleep_for(int milisecond);
void clear_console();
