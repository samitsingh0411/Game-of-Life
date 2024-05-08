#include "functions.h"

int main() {
	int gridsize = 78;
	Cell** cellgrid = makegrid(gridsize);

	cellgrid[4][4].buffer_state = state::alive;
	//cellgrid[5][4].buffer_state = state::alive;
	cellgrid[6][4].buffer_state = state::alive;
	//cellgrid[2][2].buffer_state = state::alive;

	cellgrid[4][4].current_state = state::alive;
	//cellgrid[5][4].current_state = state::alive;
	cellgrid[6][4].current_state = state::alive;
	//cellgrid[2][2].current_state = state::alive;


	while (true) {
		displaygrid(cellgrid, gridsize);
		checkstate(cellgrid, gridsize);
		sleep_for(100);
		clear_console();
	}
}