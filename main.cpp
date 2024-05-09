#include "functions.h"

int main() {
	int gridsize = 40;
	Cell** cellgrid = makegrid(gridsize);


	//line
	/*
	cellgrid[4][4].buffer_state = state::alive;
	cellgrid[5][4].buffer_state = state::alive;
	cellgrid[6][4].buffer_state = state::alive;*/


	//still life box
	/*
	cellgrid[4][4].buffer_state = state::alive;
	cellgrid[5][4].buffer_state = state::alive;
	cellgrid[4][5].buffer_state = state::alive;
	cellgrid[5][5].buffer_state = state::alive;*/


	//spaceship
	/*
	cellgrid[4][4].buffer_state = state::alive;
	cellgrid[6][4].buffer_state = state::alive;
	cellgrid[5][5].buffer_state = state::alive;
	cellgrid[5][5].buffer_state = state::alive;
	cellgrid[5][6].buffer_state = state::alive;
	cellgrid[6][5].buffer_state = state::alive;
	*/

	//Game Loop
	while (true) {
		displaygrid(cellgrid, gridsize);
		checkstate(cellgrid, gridsize);
		sleep_for(100);
		clear_console();
	}

}