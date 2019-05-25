#ifndef OBJREADER_H
#define OBJREADER_H
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "Cara.h"
#include "Figura.h"

using namespace std;

class ObjReader
{
public:
	void readObj();
	ObjReader(string archivo);
	//vector<Figura> getFigures();
	void drawFiguras(float xp, float yp, float zp);
	//void drawFace();
private:
	vector<Figura> figuras;
	fstream objFile;
	vector<Cara> caras;
};

#endif