#ifndef VERTEX_H
#define VERTEX_H
#include <string>
#include <iostream>

using namespace std;

class Vertice
{

private:
	float x, y, z;
public:

	Vertice(float x, float y, float z);
	float getX();
	float getY();
	float getZ();
	friend ostream& operator << (ostream& cout, Vertice vertice);

};

#endif
