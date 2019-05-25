#ifndef FIGURE_H
#define FIGURE_H
#include "Cara.h"
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class Figura
{
	typedef struct {
		float x, y, z;
	}TVertex;
public:
	Figura(vector<Cara> caras, string figureName);
	void drawObject(float xp, float yp, float zp);
	void calculateVisibility(int f);
	float calculateIllumination(int f);
protected:

private:
	string figureName;
	vector<Cara> caras;
	vector<Vertice> vertic;
	TVertex PRP;
	TVertex Light;
	float I;
	float magnitude;

	float I_a = .8; ///Ambient light intensity
	float K_a = .6; ///Ambient light coefficient
	float I_l = .8; ///Light Intensity
	float K_d = .4; ///
};

#endif // FIGURE_H
