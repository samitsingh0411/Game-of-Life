#include "functions.h"

int main() {
	int gridsize = 10;
	Cell** cellgrid = makegrid(gridsize);
	while (true) {
		checkstate(cellgrid, gridsize);
		displaygrid(cellgrid, gridsize);
		sleep_for(400);
		clear_console();
		sleep_for(400);
	}
}dfsafafa