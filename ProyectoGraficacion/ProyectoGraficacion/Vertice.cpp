#include "Vertice.h"
#include <string>
#include <iostream>


using namespace std;


Vertice::Vertice(float x, float y, float z) //Constructor de vertice
{
	this->x = x;
	this->y = y;
	this->z = z;

}

float Vertice::getX() {
	return x;
}

float Vertice::getY() {
	return y;
}

float Vertice::getZ() {
	return z;
}

ostream& operator << (ostream &cout, Vertice vertice) //Sobrecarga de operador para imprimir vertice
{
	cout << vertice.getX() << ", " << vertice.getY() << ", " << vertice.getZ();
	return cout;
}

