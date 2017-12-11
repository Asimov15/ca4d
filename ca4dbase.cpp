#include "shared.h"

ca4Dbase* ca4Dglobal::CurrentCA;

ca4Dbase::ca4Dbase(unsigned int size, bool wrap)
{
	this->size = size;
	this->wrap = wrap;	
	turn = 0;
}

ca4Dbase::~ca4Dbase()
{
	delete space;
	delete mycursor;
}

void ca4Dbase::initglut(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); //set the display to Double buffer, with depth
	glutInitWindowSize(2000, 1000); //set the window size
	glutInitWindowPosition(0, 0); //set the position of the window
	glutCreateWindow("4 D Cellular Automaton"); //the caption of the window
	glutDisplayFunc(ca4Dglobal::taketurn); //use the display function to draw everything
	glutIdleFunc(ca4Dglobal::taketurn); //update any variables in display, display can be changed to anyhing, as long as you move the variables to be updated, in this case, angle++;
	glutReshapeFunc(ca4Dglobal::reshape); //reshape the window accordingly
	glutKeyboardFunc(ca4Dglobal::keyboard); //check the keyboard

}

void ca4Dbase::initspace2(unsigned int size, bool wrap)
{
	int* extents = new int[4]; 
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4, extents, wrap);
	int seedsize;

	// For now - give the middle some random live cells
	// Future development - pass in initial state as parameter
	int middle = (int)(size / 2);
	
	int ordinates[4];	
	
	// seed 2
	seedsize = 5;	
	for (int x = middle - seedsize; x <= middle + seedsize; x++)
	for (int y = middle - seedsize; y <= middle + seedsize; y++)
	for (int z = middle - seedsize; z <= middle + seedsize; z++)	
	for (int w = middle - seedsize; w <= middle + seedsize; w++)	
	{
		ordinates[0] = x;
		ordinates[1] = y;
		ordinates[2] = z;
		ordinates[3] = w;
		ordinates[0] = x + 7;
		ordinates[1] = y + 7;
		ordinates[2] = z + 7;
		ordinates[3] = w + 7;												
		space->setCell(ordinates, 1);	
	}
	
	
	space->swap();
}

void ca4Dbase::initspace3(unsigned int size, bool wrap)
{
	int* extents = new int[4]; 
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4, extents, wrap);
	int seedsize;

	// For now - give the middle some random live cells
	// Future development - pass in initial state as parameter
	int middle = (int)(size / 2);
	
	int ordinates[4];	
	seedsize = 1;	
	for (int x = middle - seedsize; x <= middle + seedsize; x++)
	for (int y = middle - seedsize; y <= middle + seedsize; y++)
	for (int z = middle - seedsize; z <= middle + seedsize; z++)	
	for (int w = middle - seedsize; w <= middle + seedsize; w++)	
	{
		ordinates[0] = x;
		ordinates[1] = y;
		ordinates[2] = z;
		ordinates[3] = w;									
		space->setCell(ordinates, 1);	
	}
	
	space->swap();
}

void ca4Dbase::initspace4(unsigned int size, bool wrap)
{
	int* extents = new int[4]; 
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	int x,y,z,w;
	unsigned char toggle = 0;
	space = new spaceNd(4, extents, wrap);
	int seedsize;

	// For now - give the middle some random live cells
	// Future development - pass in initial state as parameter
	int middle = (int)(size / 2);
	
	int ordinates[4];	
	seedsize = 1;	
	for (x = middle - seedsize; x <= middle + seedsize; x++)
	for (y = middle - seedsize; y <= middle + seedsize; y++)
	for (z = middle - seedsize; z <= middle + seedsize; z++)	
	for (w = middle - seedsize; w <= middle + seedsize; w++)
	{
		ordinates[0] = x;
		ordinates[1] = y;
		ordinates[2] = z;
		ordinates[3] = w;									
		toggle = toggle == 0 ? 1 : 0;		
		space->setCell(ordinates, toggle);	
	}
	
	space->swap();
}


void ca4Dbase::initspace5(unsigned int size, bool wrap)
{
	int* extents = new int[4]; 
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	int x,y,z,w;
	unsigned char toggle = 0;
	space = new spaceNd(4, extents, wrap);
	int seedsize;

	// For now - give the middle some random live cells
	// Future development - pass in initial state as parameter
	int middle = (int)(size / 2);
	
	int ordinates[4];	
	seedsize = 1;	
	for (x = middle - seedsize; x <= middle + seedsize; x++)
	for (y = middle - seedsize; y <= middle + seedsize; y++)
	for (z = middle - seedsize; z <= middle + seedsize; z++)	
	for (w = middle - seedsize; w <= middle + seedsize; w++)
	{
		ordinates[0] = x;
		ordinates[1] = y;
		ordinates[2] = z;
		ordinates[3] = w;									
		toggle = toggle == 0 ? 1 : 0;		
		space->setCell(ordinates, toggle);	
	}
	
	ordinates[0] = middle;
	ordinates[1] = middle;
	ordinates[2] = middle;
	ordinates[3] = middle;									
	
	space->setCell(ordinates, 1);	
	
	ordinates[0] = middle-1;
	ordinates[1] = middle-1;
	ordinates[2] = middle-1;
	ordinates[3] = middle-1;									
	
	space->setCell(ordinates, 1);	
	
	ordinates[0] = middle+1;
	ordinates[1] = middle+1;
	ordinates[2] = middle+1;
	ordinates[3] = middle+1;									
	
	space->setCell(ordinates, 1);		
	
	space->swap();
}

void ca4Dbase::initspace8(unsigned int size, bool wrap)
{
	int* extents = new int[4];
	int i,j;
	int middle = (int)(size / 2);
	int ordinates[4];
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4,extents , wrap);		
	
	ordinates[3] = middle;	
	
	for (i = 10; i <=11; i++)
	{		
		ordinates[0] = i;
		ordinates[1] = 10;
		ordinates[2] = 10;	
		space->setCell(ordinates, 1);		
	}
	
	for (i = 10; i <=11; i++)
	{		
		ordinates[0] = i;
		ordinates[1] = 13;
		ordinates[2] = 10;	
		space->setCell(ordinates, 1);	
	}
	
	for (i = 10; i <=11; i++)
	{
		for (j = 11; j <= 12; j++)
		{		
			ordinates[0] = i;
			ordinates[1] = j;
			ordinates[2] = 11;	
			space->setCell(ordinates, 1);
		}	
	}
	
	space->swap();
}

void ca4Dbase::initspace9(unsigned int size, bool wrap)
{
	int* extents = new int[4];
	int i,j,w;
	int middle = (int)(size / 2);
	int ordinates[4];
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4,extents , wrap);		
	
	ordinates[3] = middle;	
	
	for (i = 11; i <=12; i++)
	for (j = 11; j <=12; j++)
	for (w = 11; w <=12; w++)
	{		
		ordinates[0] = i;
		ordinates[1] = j;
		ordinates[2] = middle;	
		ordinates[3] = w;	
		space->setCell(ordinates, 1);		
	}
	
	for (i = 11; i <=12; i++)
	for (j = 9;  j <=10; j++)	
	{		
		ordinates[0] = i;
		ordinates[1] = j;
		ordinates[3] = 10;	
		ordinates[2] = middle + 1;	
		space->setCell(ordinates, 1);		
	}
	
	for (i = 11; i <=12; i++)
	for (j = 9;  j <=10; j++)	
	{		
		ordinates[0] = i;
		ordinates[1] = j;
		ordinates[3] = 13;	
		ordinates[2] = middle + 1;	
		space->setCell(ordinates, 1);		
	}
	
	space->swap();
}

void ca4Dbase::initspace10(unsigned int size, bool wrap)
{
	int* extents = new int[4];
	int w;	
	int len = (int)(size);
	int ordinates[4];
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4,extents , wrap);		
	
	for (w = 0; w < len; w++)
	{		
		ordinates[0] = 1;
		ordinates[1] = 1;
		ordinates[2] = 1;	
		ordinates[3] = w;	
		space->setCell(ordinates, 1);		
	}
	space->swap();	
}

void ca4Dbase::initspace11(unsigned int size, bool wrap)
{
	int* extents = new int[4];
	int x,w;	
	int len = (int)(size);
	int ordinates[4];
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4,extents , wrap);		
	
	for (x = 0; x < len; x++)
	for (w = 0; w < len; w++)
	{		
		ordinates[0] = x;
		ordinates[1] = 1;
		ordinates[2] = 1;	
		ordinates[3] = w;	
		space->setCell(ordinates, 1);		
	}
	space->swap();	
}

void ca4Dbase::initspace12(unsigned int size, bool wrap)
{
	int* extents = new int[4];
	int i;	  
	int ordinates[4];
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4,extents , wrap);		
	
	
	for (i = 6; i <= 14; i++)
	{		
		ordinates[0] = i;
		ordinates[1] = 10;
		ordinates[2] = 10;	
		ordinates[3] = 10;	
		space->setCell(ordinates, 1);		
		
		ordinates[0] = 10;
		ordinates[1] = i;
		ordinates[2] = 10;	
		ordinates[3] = 10;	
		space->setCell(ordinates, 1);	
		
		ordinates[0] = 10;
		ordinates[1] = 10;
		ordinates[2] = i;	
		ordinates[3] = 10;	
		space->setCell(ordinates, 1);	
		
		ordinates[0] = 10;
		ordinates[1] = 10;
		ordinates[2] = 10;	
		ordinates[3] = i;	
		space->setCell(ordinates, 1);		
	}
	space->swap();	
}

void ca4Dbase::initspace14(unsigned int size, bool wrap)
{
	int* extents = new int[4];
	int i,j,k,l;	  
	int ordinates[4];
	int middle, width;
	
	middle = (int) size / 2;
	width = 5;
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4,extents , wrap);			
	
	for (i = middle - width; i <= middle + width ; i++)
	{		
		for (j = middle - width; j <= middle + width ; j++)
		{		
			for (k = middle - width; k <= middle + width ; k++)
			{		
				for (l = middle - width; l <= middle + width ; l++)
				{		
					ordinates[0] = i;
					ordinates[1] = j;
					ordinates[2] = k;
					ordinates[3] = l;					
					space->setCell(ordinates, 1);				
				}
			}
		}
	}
	space->swap();	
}

void ca4Dbase::initspace6(unsigned int size, bool wrap)
{
	int* extents = new int[4]; 
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	int x,y,z,w;
	unsigned char toggle = 0;
	space = new spaceNd(4, extents, wrap);
	int seedsize;

	// For now - give the middle some random live cells
	// Future development - pass in initial state as parameter
	int middle = (int)(size / 2);
	
	int ordinates[4];	
	seedsize = 3;	
	for (x = middle - seedsize; x <= middle + seedsize; x++)
	for (y = middle - seedsize; y <= middle + seedsize; y++)
	for (z = middle - seedsize; z <= middle + seedsize; z++)	
	for (w = middle - seedsize; w <= middle + seedsize; w++)
	{
		ordinates[0] = x;
		ordinates[1] = y;
		ordinates[2] = z;
		ordinates[3] = w;									
		toggle = toggle == 0 ? 1 : 0;		
		space->setCell(ordinates, toggle);	
	}	
	space->swap();
}


void ca4Dbase::initspace1(unsigned int size, bool wrap)
{
	int* extents = new int[4]; 
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4, extents, wrap);
	int seedsize;
	unsigned char toggle = 0;

	// For now - give the middle some random live cells
	// Future development - pass in initial state as parameter
	int middle = (int)(size / 2);
	
	int ordinates[4];	
		
	seedsize = 8;	
	for (int x = middle - seedsize; x <= middle + seedsize; x++)
	for (int y = middle - seedsize; y <= middle + seedsize; y++)
	for (int z = middle - seedsize; z <= middle + seedsize; z++)	
	for (int w = middle - seedsize; w <= middle + seedsize; w++)	
	{
		ordinates[0] = x;
		ordinates[1] = y;
		ordinates[2] = z;
		ordinates[3] = w;			

		toggle = toggle == 0 ? 1 : 0;
				
		space->setCell(ordinates, toggle);	
	}	
	space->swap();
}


void ca4Dbase::initgraphics()
{	
	zpos = 25;
	xpos = -15;
	ypos = -10;
	xloc = -space->extents[0] / 2;
	moveright = true;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	GLfloat blackAmbientLight[] = { 0.0, 0.0, 0.0 }; 			//set the light ambient to black
	GLfloat whiteDiffuseLight[] = { 1.0, 1.0, 1.0 }; 			//set the diffuse light to white
	glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);

	double radius(0.05);
	vector* position2 = new vector(0, 0, 0);
	vector* orient2 = new vector(1, 0, 0);
	color* blue = new color(0.0, 0.0, 1.0, 1.0);
	color* white = new color(0.0, 0.0, 0.0, 1.0);
	GLfloat* shine = new float(128.0f);
	mycursor = new cursor(blue, white, radius, position2, shine, orient2);
}

void ca4Dbase::initcamera()
{
	xang = yang = zang = 0;
	xvel = yvel = zvel = 0;

	xang = 318.0;
	yang = 128.0;
	yvel = 0.0;
	xvel = 0.0;
}

void ca4Dbase::taketurn()
{
	render();
	
	turn++;
	xang += xvel;
	yang += yvel;
	zang += zvel;

	mutateall();
	space->swap();

	//cout << turn << "," << (space->calculateAlivePercent() * 100.0) << "%, " << (space->calculateChangePercent() * 100.0) <<   "%, " << xang << ", " << yang << ", " << zang << "\n";
}

void ca4Dbase::mutateall()
{
	/*int size = space->size;
	for (int x = 0; x < size; x++)
	for (int y = 0; y < size; y++)
	for (int z = 0; z < size; z++)
	{
	mutatebycoordinates(x, y, z);
	}*/

	for (int i = 0; i < space->matrixSize; i++)
	{
		mutatebyindex(i);
	}
}


void drawString4D(void * font, char *s, float x, float y, float z){
	unsigned int i;

	glDisable(GL_LIGHTING);
	glRasterPos3f(x, y, z);
	glColor3f(1.0, 1.0, 0.0);
	for (i = 0; i < strlen(s); i++)
		glutBitmapCharacter(font, s[i]);

	glEnable(GL_LIGHTING);
}


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
	(std::ostringstream() << std::dec << x)).str()

void ca4Dbase::render()
{
	color* custom;
	vector d(0, 0, 0);
	vector ep(0, 0, 0);

	custom = new color(0.4, 1.0, 0.2, 1.0);

	glClearColor(0.0, 0.0, 0.0, 1.0); 						//clear the screen to black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 	//clear the color buffer and the depth buffer

	glLoadIdentity();

	//light();
	GLfloat blackAmbientLight[] = { 0.0, 0.0, 0.0 }; 			//set the light ambient to black
	GLfloat whiteDiffuseLight[] = { 1.0, 1.0, 1.0 }; 			//set the diffuse light to white
	glLightfv(GL_LIGHT0, GL_AMBIENT, blackAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, whiteDiffuseLight);

	gluLookAt(0, 0, zpos, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); //camera position, x,y,z, looking at x,y,z, Up Positions of the camera    	    	      
	glRotatef(xang, 1.0f, 0.0f, 0.0f);
	glRotatef(yang, 0.0f, 1.0f, 0.0f);
	glRotatef(zang, 0.0f, 0.0f, 1.0f);
	
	int ordinates[4];

	for (float x = 0; x < space->extents[0]; x++)
		for (float y = 0; y < space->extents[1]; y++)
			for (float z = 0; z < space->extents[2]; z++)
				//for (float w = 0; w < space->extents[3]; w++)
				{
					ordinates[0] = x;
					ordinates[1] = y;
					ordinates[2] = z;
					//ordinates[3] = 0;
					ordinates[3] = space->extents[3] / 2;

					unsigned char state = space->getCell(ordinates);
					if (state == 1) 
					{
						float r = (x / space->extents[0]) *.8 + .1;
						float g = (y / space->extents[1]) *.8 + .1;
						float b = (z / space->extents[2]) *.8 + .1;
						custom->rgb[0] = r;
						custom->rgb[1] = g;
						custom->rgb[2] = b;
						//custom->rgb[0] = 1.0;
						//custom->rgb[1] = 1.0;
						//custom->rgb[2] = 1.0;
						custom->alpha = 0.8;						

						d.x = x / 10.0 - (float)space->extents[0] / 20;
						d.y = y / 10.0 - (float)space->extents[1] / 20;
						d.z = z / 10.0 - (float)space->extents[2] / 20;

						//d.x += (w - (space->extents[3] / 2));

						mycursor->moveabs(&d);
						mycursor->setcolor(custom);
						mycursor->pset();
					}
				}

	//std::stringstream ss;
	//ss << turn;
	//string str = ss.str();
	//const char* sstr = str.c_str();
	//drawString4D(GLUT_BITMAP_HELVETICA_18, (char*)sstr, 3, 3, 3);

	glutSwapBuffers(); //swap the buffers     
	usleep(1000000);
}


void ca4Dbase::reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(10, (GLfloat)w / (GLfloat)h, 1.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void ca4Dbase::keyboard(unsigned char key, int x, int y)
{
	if (key == 'a')
	{
		xvel += 1.0;
	}

	if (key == 's')
	{
		xvel -= 1.0;
	}

	if (key == 'd')
	{
		yvel += 1.0;
	}

	if (key == 'f')
	{
		yvel -= 1.0;
	}
	if (key == 'g')
	{
		zvel += 1.0;
	}

	if (key == 'h')
	{
		zvel -= 1.0;
	}

	if (key == 'k')
	{
		zpos += 1.0;
	}

	if (key == 'j')
	{
		zpos -= 1.0;
	}

	if (key == 'z')
	{
		xvel = 0;
		yvel = 0;
		zvel = 0;
	}
}

int ca4Dbase::run(int argc, char **argv)
{
	ca4Dglobal::CurrentCA = this;

	initglut(argc, argv);
	initspace14(size, wrap);
	initgraphics();
	initcamera();

	glutMainLoop(); //call the main loop
	return 0;
}

//void ca4Dbase::start()
//{
	//initspace(size, wrap);
//}
