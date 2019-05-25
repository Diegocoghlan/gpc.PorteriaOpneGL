#ifndef FACE_H
#define FACE_H
#include <cstdlib>
#include <GL/glut.h>
#include <vector>
#include <iostream>
#include "Vertice.h"


using namespace std;

class Cara
{
	typedef struct {
		float A, B, C;
	}TNormal;
public:
	Cara();
	vector<Vertice> getVertices();
	void addVertice(Vertice vertice);
	friend ostream& operator << (ostream& cout, Cara cara);
	void drawVertices(float xp, float yp, float zp, float I);
	TNormal normal;
	int visible;
private:
	vector<Vertice> vertices;

};

#endif
