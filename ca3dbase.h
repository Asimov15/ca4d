
class ca3Dbase {

public:
	ca3Dbase(unsigned int size, bool wrap);
	~ca3Dbase();

	int size;
	bool wrap;
	int turn;

	void initglut(int argc, char **argv);

	/* CA logic */
	void initspace1(unsigned int size, bool wrap);
	void initspace2(unsigned int size, bool wrap);
	void initspace3(unsigned int size, bool wrap);
	void initspace4(unsigned int size, bool wrap);
	void initspace5(unsigned int size, bool wrap);
	void initspace6(unsigned int size, bool wrap);
	void initspace7(unsigned int size, bool wrap);
	void initspace8(unsigned int size, bool wrap);
	void initspace9(unsigned int size, bool wrap);
	void initspace10(unsigned int size, bool wrap);
	void initspace11(unsigned int size, bool wrap);
	void initspace12(unsigned int size, bool wrap);
	void initspace13(unsigned int size, bool wrap);
	void initspace14(unsigned int size, bool wrap);
	void initspace15(unsigned int size, bool wrap);
	void initspace16(unsigned int size, bool wrap);
	void initspace17(unsigned int size, bool wrap);
	void initspace18(unsigned int size, bool wrap);
	spaceNd* space;
	void taketurn();
	void mutateall();
	virtual void mutatebyindex(int i) = 0;
	
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
	double zpos;
	void keyboard(unsigned char key, int x, int y);
};


class ca3Dglobal 
{
public:
	static ca3Dbase* CurrentCA;

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
