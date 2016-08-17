class color
{
	public:
		GLfloat* rgb;
		GLfloat alpha;

		color(GLfloat r, GLfloat g, GLfloat b, GLfloat a)
		{
			rgb = new GLfloat[3];
			rgb[0] = r;
			rgb[1] = g;
			rgb[2] = b;
			alpha  = a;
		}
		
		~color()
		{		
			delete rgb;
		}
};
