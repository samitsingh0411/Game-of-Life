#include "functions.h"

int main() {
	int gridsize = 10;
	Cell** cellgrid = makegrid(gridsize);
	while (true) {
		checkstate(cellgrid, gridsize);
		displaygrid(cellgrid, gridsize);
		sleep_for(5000);
		clear_console();
	}
}