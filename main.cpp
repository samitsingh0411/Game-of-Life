#include "functions.h"

int main() {
	int gridsize = 40;
	Cell** cellgrid = makegrid(gridsize);
	while (true) {
		checkstate(cellgrid, gridsize);
		displaygrid(cellgrid, gridsize);
		sleep_for(700);
		clear_console();
	}
}