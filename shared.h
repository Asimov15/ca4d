#ifndef SHARED_INCLUDES_HEADER
#define SHARED_INCLUDES_HEADER

#define RT 1.414213562
#define CS 80

#include <stdlib.h>
#include <GL/glut.h>
//#include <GL/gl.h>

#include <math.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <cstring>
#include <unistd.h>

using namespace std;

#include "color.h"
#include "vector.h"
#include "cursor.h"
#include "spaceNd.h"
#include "ca3dbase.h"
#include "conway3d.h"

#include "ca4dbase.h"
#include "conway4d.h"

int main(int argc, char** args);

#endif
