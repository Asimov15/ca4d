/*
 * David Zuccaro and Brendan Hill
 * Copyright 2014 */


#include "shared.h"

int main(int argc, char **argv)
{
	//unittests::runalltests();

	//conway3Dscanner a;// = new conway3Dscanner();
	//a.scan(0, new rangeInt(2, 8), new rangeInt(2, 8), new rangeInt(0, 6), new rangeInt(26, 26), 250);
	
	//ca3Dbase* ca = new conway3D(2, 6, 5, 8, 20, false);
	//ca3Dbase* ca = new conway3D(1, 1, -1, -1, 50, true); // very interesting

	//ca3Dbase* ca = new conway3D(4, 4, 12, 14, 33, false); //***
	//ca3Dbase* ca = new conway3D(4, 4, 10, 15, 50, false); // very interesting
	//ca3Dbase* ca = new conway3D{4, 4, -1, -1, 30, true}; //***
	//ca3Dbase* ca = new conway3D(4, 5, 8, 23, 38, true); // very interesting
	
	//ca3Dbase* ca = new conway3D(4, 6, -1, -1, 28, true);  
	//ca3Dbase* ca = new conway3D(5, 7, 12, 16, 10, true); //***
	
	// ==================================================

	//ca3Dbase* ca = new conway3D(4, 4, 10, 15, 40, false); // ***
	//ca3Dbase* ca = new conway3D(4, 4, 10, 17, 40, false); // ***
	//ca3Dbase* ca = new conway3D(4, 4, 10, 16, 40, false); // ***
	//ca4Dbase* ca = new conway4D(1, 4, -1, -1, 17, true); // ***
	//ca4Dbase* ca = new conway4D(1, 3, -1, -1, 17, true); // ***
	//ca4Dbase* ca = new conway4D(1, 4, 5, 6, 17, true); // ***
	
	//ca4Dbase* ca = new conway4D(1, 4, 15, 20, 17, true); // ***
	
	//ca4Dbase* ca = new conway4D(2, 5, 15, 20, 17, true); // ***
	
	ca4Dbase* ca = new conway4D(1,4, 10, 20, 20, true); // vi
	
	//ca4Dbase* ca = new conway4D(5, 7, 8, 8, 24, true); // vi
	//ca4Dbase* ca = new conway4D(9, 11, 11, 11, 20, true); // vi
	
	ca->run(argc, argv);
	//delete ca;
	
	return 0;
}
