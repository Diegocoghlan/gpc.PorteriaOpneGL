#include "Figura.h"
#include "Cara.h"
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

Figura::Figura(vector<Cara> faces, string figureName)
{
	this->caras = faces;
	this->figureName = figureName;
	PRP.x = 10;
	PRP.y = 10;
	PRP.z = 10;

	Light.x = -30;
	Light.y = 10;
	Light.z = 10;

	magnitude = sqrt(Light.x * Light.x + Light.y * Light.y + Light.z * Light.z);

	Light.x = Light.x / magnitude;
	Light.y = Light.y / magnitude;
	Light.z = Light.z / magnitude;
}

void Figura::calculateVisibility(int f) {
	TVertex V_a, V_b;
	float vis;

	vertic = caras.at(f).getVertices(); //todos los vertices

	V_a.x = vertic.at(1).getX() - vertic.at(0).getX();
	V_a.y = vertic.at(1).getY() - vertic.at(0).getY();
	V_a.z = vertic.at(1).getZ() - vertic.at(0).getZ();

	//V_b
	V_b.x = vertic.at(2).getX() - vertic.at(0).getX();
	V_b.y = vertic.at(2).getY() - vertic.at(0).getY();
	V_b.z = vertic.at(2).getZ() - vertic.at(0).getZ();

	//N = v_a X V_b
	caras.at(f).normal.A = V_a.y * V_b.z - V_a.z * V_b.y;
	caras.at(f).normal.B = V_a.z * V_b.x - V_a.x * V_b.z;
	caras.at(f).normal.C = V_a.y * V_b.y - V_a.y * V_b.x;
	
	///Determine whether or not a face is visible
	///visible -> Normal . PRP
	///Positivo visible
	///Negativo visiblen't
	///Cero neutro

	vis = (caras.at(f).normal.A * 0) +
		(caras.at(f).normal.B * 0) +
		(caras.at(f).normal.C * 1);
	//printf("%f %f %f %f \n", caras.at(f).normal.A, caras.at(f).normal.B, caras.at(f).normal.C, vis);
	if (vis >= 0)
	{
		caras.at(f).visible = 1;
	}
	else {
		//  cout << "Esta cara no se ve: ";
		//  cout << f << endl;
		caras.at(f).visible = 0;
	}
}

float Figura::calculateIllumination(int f) {
	//Calcula la iluminacion ambiente
	float Iamb, I_d=0, I, N_L;

	//Calculate AMbient Illumination
	Iamb = I_a * K_a;

	//Calculate Difuse illumination
	//I_d = I_l * k_d*(N.L);

	//First convert normal to unit verctor

	float magnitud = sqrt(caras.at(f).normal.A * caras.at(f).normal.A +
		caras.at(f).normal.B * caras.at(f).normal.B +
		caras.at(f).normal.C * caras.at(f).normal.C);

	caras.at(f).normal.A /= magnitud;
	caras.at(f).normal.B /= magnitud;
	caras.at(f).normal.C /= magnitud;

	N_L = (caras.at(f).normal.A * Light.x) +
		(caras.at(f).normal.B * Light.y) +
		(caras.at(f).normal.C * Light.z);

	I_d = I_l * K_d * N_L;

	//Calculate el total de la iluminacion

	I = Iamb + I_d;

	//printf("Face %d I = %f + %f  = %f \n",f,Iamb, I_d,I);

	return I;
}

void Figura::drawObject(float xp, float yp, float zp)
{
	for (unsigned int i = 2; i < caras.size(); i++) {
		calculateVisibility(i);
		if (caras.at(i).visible) {
			I = calculateIllumination(i);
			if (figureName=="Sphere") {
				glColor3f(I, I, 0.5);
				glBegin(GL_POLYGON);
			}
			else if (figureName == "Cube.001") {
				glColor3f(I, I, I);
				glBegin(GL_POLYGON);
			}
			caras.at(i).drawVertices(xp, yp, zp, I);
		}
	}
		
	glFlush();
}

