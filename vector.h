	class vector
{
	public:
		double x,y,z;
		vector(double a, double b, double c)
		{
			x = a;
			y = b;
			z = c;
		}
		
		double dp(vector* v2)
		{
			double g;
			g = x*v2->x + y*v2->y + z*v2->z;
			
			return g;
		}
		
		double mag()
		{
			return pow(x*x + y*y + z*z, 0.5);
		}
		
		void scalarp(double f)
		{			
			x *= f;
			y *= f;
			z *= f;			
		}
		
		vector* vadd(vector* v2)
		{
			vector* adder = new vector(0,0,0);
			adder->x = v2->x + x;
			adder->y = v2->y + y;
			adder->z = v2->z + z;
			return adder;
		}
		
		double bangle(vector* v)
		{			
			double g,h,i;
			g = this->dp(v);
			h = v->mag();						
			i = this->mag();						
			return acos(g / ( h * i)); // returns radians
		}
		
		vector* cross(vector* v)
		{
			vector* i = new vector(1,0,0);
			vector* j = new vector(0,1,0);
			vector* k = new vector(0,0,1);
			vector* t1;
			vector* t3;			
			
			i->scalarp(y*v->z - z*v->y);
			j->scalarp(z*v->x - x*v->z);
			t1 = i->vadd(j);
			k->scalarp(x*v->y - y*v->x);
			t3 = t1->vadd(k);
			delete i;
			delete j;
			delete k;
			delete t1;
			return t3;
		}
		
		vector* copyv()
		{
			vector* w = new vector(0,0,0);
			w->x = x;
			w->y = y;
			w->z = z;
			return w;
		}
};


