	class Vector3D
{
	public:
		double x,y,z;
		Vector3D(double a, double b, double c)
		{
			x = a;
			y = b;
			z = c;
		}
		
		double dp(Vector3D* v2)
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
		
		Vector3D* vadd(Vector3D* v2)
		{
			Vector3D* adder = new Vector3D(0,0,0);
			adder->x = v2->x + x;
			adder->y = v2->y + y;
			adder->z = v2->z + z;
			return adder;
		}
		
		double bangle(Vector3D* v)
		{			
			double g,h,i;
			g = this->dp(v);
			h = v->mag();						
			i = this->mag();						
			return acos(g / ( h * i)); // returns radians
		}
		
		Vector3D* cross(Vector3D* v)
		{
			Vector3D* i = new Vector3D(1,0,0);
			Vector3D* j = new Vector3D(0,1,0);
			Vector3D* k = new Vector3D(0,0,1);
			Vector3D* t1;
			Vector3D* t3;			
			
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
		
		Vector3D* copyv()
		{
			Vector3D* w = new Vector3D(0,0,0);
			w->x = x;
			w->y = y;
			w->z = z;
			return w;
		}
};


