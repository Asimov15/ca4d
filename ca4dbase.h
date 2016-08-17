
class ca4Dbase {

public:
	ca4Dbase(unsigned int size = 50, bool wrap = true);
	~ca4Dbase();

	int size;
	bool wrap;
	int turn;

	void initglut(int argc, char **argv);

	/* CA logic */
	void initspace1(unsigned int size = 50, bool wrap = true);
	void initspace2(unsigned int size = 50, bool wrap = true);
	void initspace3(unsigned int size = 50, bool wrap = true);
	void initspace4(unsigned int size = 50, bool wrap = true);
	void initspace5(unsigned int size = 50, bool wrap = true);
	void initspace6(unsigned int size = 50, bool wrap = true);
	void initspace8(unsigned int size = 50, bool wrap = true);
	void initspace9(unsigned int size = 50, bool wrap = true);
	void initspace10(unsigned int size = 50, bool wrap = true);
	void initspace11(unsigned int size = 50, bool wrap = true);
	void initspace12(unsigned int size = 50, bool wrap = true);
	void initspace14(unsigned int size = 50, bool wrap = true);
	spaceNd* space;
	void taketurn();
	void mutateall();
	virtual void mutatebyindex(int i) = 0;
	//int countneighbours(int x, int y, int z);
	//int countneighbours(int i, bool useSwapped);
	int run(int argc, char **argv);
	void start();

	/* Rendering */
	cursor* mycursor;
	void initgraphics();
	void reshape(int w, int h);
	void render();

	/* Camera & movement */
	void initcamera();
	bool moveright, moveup, movefor;

	double xvel, yvel, zvel;
	double xang, yang, zang;
	double xloc, yloc, zloc;
	double xpos, ypos, zpos;
	void keyboard(unsigned char key, int x, int y);
};


class ca4Dglobal
{
public:
	static ca4Dbase* CurrentCA;

	static void taketurn()
	{
		CurrentCA->taketurn();
	}

	static void reshape(int w, int h)
	{
		CurrentCA->reshape(w, h);
	}

	static void keyboard(unsigned char key, int x, int y)
	{
		CurrentCA->keyboard(key, x, y);
	}
};
