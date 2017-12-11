CC=g++

#CFLAGSLINK=-Wall -lstdc++ -lc -lm -lGL -lGLU -lglut  
#CFLAGSLINK=-Wall -lstdc++ -lm -lGL -lGLU -lglut  
#CFLAGSLINK=-Wall -lstdc++ -lGL -lGLU -lglut  
CFLAGSLINK=-Wall -lGL -lGLU -lglut -std=c++11 
CFLAGS=$(CFLAGSLINK) -c

all: conway

conway: ca4dbase.o conway4d.o main.o spaceNd.o ca3dbase.o conway3d.o 
	$(CC)  ca4dbase.o ca3dbase.o conway3d.o conway4d.o main.o spaceNd.o -o conway $(CFLAGSLINK)

conway4d.o: conway4d.cpp shared.h color.h vector.h cursor.h spaceNd.h conway4d.h  
	$(CC) $(CFLAGS) conway4d.cpp

conway3d.o: conway3d.cpp shared.h color.h vector.h cursor.h spaceNd.h conway3d.h
	$(CC) $(CFLAGS) conway3d.cpp
	
spaceNd.o: spaceNd.cpp shared.h color.h vector.h cursor.h spaceNd.h ca4dbase.h conway4d.h
	$(CC) $(CFLAGS) spaceNd.cpp
	
main.o: main.cpp shared.h color.h vector.h cursor.h spaceNd.h conway4d.h conway3d.h ca3dbase.h
	$(CC) $(CFLAGS) main.cpp

ca4dbase.o: ca4dbase.cpp shared.h color.h vector.h cursor.h spaceNd.h ca4dbase.h 
	$(CC) $(CFLAGS) ca4dbase.cpp
	
ca3dbase.o: ca3dbase.cpp shared.h color.h vector.h cursor.h spaceNd.h ca3dbase.h 
	$(CC) $(CFLAGS) ca3dbase.cpp

clean:
	rm -rf *.o conway
