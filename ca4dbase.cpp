#include "shared.h"

// This is for directly outputing to an mp4
#include <cstdio>
#include <cstdlib>
#include <cmath>

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
	// glutInitWindowSize(2000, 1000); //set the window size
	glutInitWindowSize(VIDEO_WIDTH, VIDEO_HEIGHT);
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

void ca4Dbase::initspace15(unsigned int size, bool wrap)
{
	int* extents = new int[4];
	int i,j,k,l;	  
	int ordinates[4];
	int middle, width;
	
	middle = (int) size / 2;
	width = 1;
	extents[0] = size;
	extents[1] = size;
	extents[2] = size;
	extents[3] = size;
	space = new spaceNd(4,extents , wrap);			
	
	for (i = middle - width; i < middle + width ; i++)
	{		
		for (j = middle - width; j < middle + width ; j++)
		{		
			for (k = middle - width; k < middle + width ; k++)
			{		
				for (l = middle - width; l < middle + width ; l++)
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

void ca4Dbase::initspace16(unsigned int size, bool wrap)
{
    const bool ENABLE_PERTURBATION = false;
    
    // Create the four-dimensional cellular space
    int extents[4] = 
    {
        static_cast<int>(size),
        static_cast<int>(size),
        static_cast<int>(size),
        static_cast<int>(size)
    };

    space = new spaceNd(4, extents, wrap);

    // Fixed seed ensures reproducible experiments
    std::mt19937 rng(12345);

    // Each cell has a 20% probability of being active
    std::bernoulli_distribution active(0.20);

    int ordinates[4];
    int initialCount = 0;

    for (int x = 0; x < static_cast<int>(size); x++)
    for (int y = 0; y < static_cast<int>(size); y++)
    for (int z = 0; z < static_cast<int>(size); z++)
    for (int w = 0; w < static_cast<int>(size); w++)
    {
        ordinates[0] = x;
        ordinates[1] = y;
        ordinates[2] = z;
        ordinates[3] = w;

        // Random background
		bool alive = active(rng);

		// Four-dimensional central perturbation
		int centre = size / 2;

		bool centralSeed =
			(x >= centre - 2 && x < centre + 2) &&
			(y >= centre - 2 && y < centre + 2) &&
			(z >= centre - 2 && z < centre + 2) &&
			(w >= centre - 2 && w < centre + 2);

		// Force all cells in the central hypercube to be active
		if (ENABLE_PERTURBATION && centralSeed)
			alive = true;

		if (alive)
		{
			space->setCell(ordinates, 1);
			initialCount++;
		}
    }

    space->swap();

    printf("Initial active cells: %d\n", initialCount);
    printf("Initial occupancy: %.4f%%\n",
           100.0 * initialCount / space->matrixSize);
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
	Vector3D* position2 = new Vector3D(0, 0, 0);
	Vector3D* orient2 = new Vector3D(1, 0, 0);
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
	
	// for outputing as mp4
	if (turn >= VIDEO_GENERATIONS)
    {
        stopRecording();
        stopDataLogging();
        stopRadialLogging();
        
        exit(0);
    }
    if (turn == 100)
	{
	    injectPerturbation();
	
	    printf("Perturbation injected at generation %d\n",
	           turn);
	}
    // Record the current generation
    logGeneration();
    logRadialGeneration();

	
	// Render the same generation
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

// This is for directly outputing to an mp4
void ca4Dbase::startRecording()
{
    const char* command =
        "ffmpeg -y "
        "-f rawvideo "
        "-pixel_format rgb24 "
        "-video_size 800x600 "
        "-framerate 5 "
        "-i pipe:0 "
        "-vf vflip "
        "-c:v libx264 "
        "-r 30 "
        "-pix_fmt yuv420p "
        "-crf 18 "
        "ca4d.mp4";

    videoPipe = popen(command, "w");

    if (!videoPipe)
    {
        fprintf(stderr, "Unable to start FFmpeg\n");
        exit(1);
    }
}

void ca4Dbase::recordFrame()
{
    const size_t bufferSize =
        VIDEO_WIDTH * VIDEO_HEIGHT * 3;

    unsigned char* pixels = new unsigned char[bufferSize];

    glFinish();
    glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glReadBuffer(GL_BACK);

    glReadPixels(
        0, 0,
        VIDEO_WIDTH,
        VIDEO_HEIGHT,
        GL_RGB,
        GL_UNSIGNED_BYTE,
        pixels
    );

    size_t bytes = fwrite(
        pixels,
        1,
        bufferSize,
        videoPipe
    );

    delete[] pixels;

    if (bytes != bufferSize)
    {
        fprintf(stderr, "Error writing video frame\n");
        exit(1);
    }
}

void ca4Dbase::stopRecording()
{
    if (videoPipe != nullptr)
    {
        int result = pclose(videoPipe);
        videoPipe = nullptr;

        if (result != 0)
        {
            fprintf(stderr, "FFmpeg reported an error\n");
        }
    }
}

void ca4Dbase::startDataLogging()
{
    dataFile = fopen("ca4d.csv", "w");

    if (!dataFile)
    {
        fprintf(stderr, "Unable to create ca4d.csv\n");
        exit(1);
    }

    fprintf(dataFile, "generation,active_cells,percentage\n");
}

void ca4Dbase::logGeneration()
{
    int activeCount = 0;

    for (int i = 0; i < space->matrixSize; i++)
    {
        if (space->getCell(i) == 1)
            activeCount++;
    }

    double percentage =
        100.0 * activeCount / space->matrixSize;

    fprintf(dataFile, "%d,%d,%.6f\n",
            turn, activeCount, percentage);
}

void ca4Dbase::stopDataLogging()
{
    if (dataFile)
    {
        fclose(dataFile);
        dataFile = nullptr;
    }
}

void ca4Dbase::startRadialLogging()
{
    radialFile = fopen("ca4d_radial.csv", "w");

    if (!radialFile)
    {
        fprintf(stderr, "Cannot create radial CSV file\n");
        exit(1);
    }

    fprintf(radialFile,
        "generation,radius,active_cells,total_cells,density\n");
}

void ca4Dbase::logRadialGeneration()
{
    const int L = space->extents[0];
    const double centre = (L - 1) / 2.0;

    // More than enough bins for the maximum 4D radius
    const int bins = 2 * L + 1;

    int* active = new int[bins]();
    int* total  = new int[bins]();

    int ordinates[4];

    for (int x = 0; x < L; x++)
    for (int y = 0; y < L; y++)
    for (int z = 0; z < L; z++)
    for (int w = 0; w < L; w++)
    {
        ordinates[0] = x;
        ordinates[1] = y;
        ordinates[2] = z;
        ordinates[3] = w;

        // Distance from the centre in each dimension
        double dx = fabs(x - centre);
        double dy = fabs(y - centre);
        double dz = fabs(z - centre);
        double dw = fabs(w - centre);

        // Account for periodic boundaries
        dx = std::min(dx, L - dx);
        dy = std::min(dy, L - dy);
        dz = std::min(dz, L - dz);
        dw = std::min(dw, L - dw);

        // Four-dimensional radial distance
        double radius = sqrt(
            dx*dx + dy*dy + dz*dz + dw*dw
        );

        // Assign to a radial shell of width 1
        int r = static_cast<int>(floor(radius));

        total[r]++;

        if (space->getCell(ordinates) == 1)
            active[r]++;
    }

    // Write results
    for (int r = 0; r < bins; r++)
    {
        if (total[r] == 0)
            continue;

        double density =
            static_cast<double>(active[r]) / total[r];

        fprintf(radialFile, "%d,%d,%d,%d,%.8f\n",
                turn, r, active[r], total[r], density);
    }

    delete[] active;
    delete[] total;
}

void ca4Dbase::stopRadialLogging()
{
    if (radialFile)
    {
        fclose(radialFile);
        radialFile = nullptr;
    }
}

void ca4Dbase::render()
{
	color* custom;
	Vector3D d(0, 0, 0);
	Vector3D ep(0, 0, 0);
	
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
			{
				int count = 0;
				for (float w = 0; w < space->extents[3]; w++)
				{
					ordinates[0] = x;
					ordinates[1] = y;
					ordinates[2] = z;
					ordinates[3] = w;
					if (space->getCell(ordinates) == 1)
						count++;
				}
				if (count == 0)
					continue;
				// ordinates[3] = space->extents[3] / 2;

				// unsigned char state = space->getCell(ordinates);
				
				float intensity = (float)count / space->extents[3];
				float r = 0.0f;
				float g = 0.0f;
				// float b = 1.0f;
				custom->rgb[0] = r;
				custom->rgb[1] = g;
				custom->rgb[2] = intensity;

				custom->alpha = 0.8;						

				d.x = x / 10.0 - (float)space->extents[0] / 20;
				d.y = y / 10.0 - (float)space->extents[1] / 20;
				d.z = z / 10.0 - (float)space->extents[2] / 20;

				//d.x += (w - (space->extents[3] / 2));

				mycursor->moveabs(&d);
				mycursor->setcolor(custom);
				mycursor->pset();
				
			}

	//std::stringstream ss;
	//ss << turn;
	//string str = ss.str();
	//const char* sstr = str.c_str();
	//drawString4D(GLUT_BITMAP_HELVETICA_18, (char*)sstr, 3, 3, 3);

	//glutSwapBuffers(); //swap the buffers     
	//usleep(1000000);
	
	// output to mp4 file
	recordFrame();
	glutSwapBuffers();
	
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
    initspace16(size, wrap);
    initgraphics();
    initcamera();

    startDataLogging();
    startRadialLogging();
    startRecording();

    glutMainLoop();

    return 0;
}

void ca4Dbase::injectPerturbation()
{
    const int centre = space->extents[0] / 2;

    int ordinates[4];
    int activated = 0;

    for (int x = centre - 2; x < centre + 2; x++)
    for (int y = centre - 2; y < centre + 2; y++)
    for (int z = centre - 2; z < centre + 2; z++)
    for (int w = centre - 2; w < centre + 2; w++)
    {
        ordinates[0] = x;
        ordinates[1] = y;
        ordinates[2] = z;
        ordinates[3] = w;

        if (space->getCell(ordinates) == 0)
        {
            space->setCurrentCell(ordinates, 1);
            activated++;
        }
    }

    printf("Perturbation: %d additional cells activated\n",
           activated);
}

//void ca4Dbase::start()
//{
	//initspace(size, wrap);
//}
