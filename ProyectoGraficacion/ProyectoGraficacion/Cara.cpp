#include "Cara.h"
#include "Vertice.h"
#include <cstdlib>
#ifdef _WIN32
#include <windows.h>
#endif 
#include <GL/glut.h>
#include <vector>
#include <iostream>
using namespace std;

Cara::Cara() {

}

vector<Vertice> Cara::getVertices() {
	return vertices;
}

void Cara::addVertice(Vertice vertice) {
	vertices.push_back(vertice);
}

ostream& operator << (ostream& cout, Cara cara) //Sobrecarga de operador para imprimir cara
{
	vector<Vertice> vertices = cara.getVertices();
	cout << "Cara: " << endl;
	for (unsigned int i = 0; i < vertices.size(); i++)
		cout << "Vertice " << i + 1 << ": " << vertices.at(i) << endl; //Utiliza sobrecarga de vertices 
	return cout;
}

void Cara::drawVertices(float xp, float yp, float zp,float I)
{
	//glColor3f(I, I, I);
	//glBegin(GL_POLYGON);
	//glBegin(GL_LINE_LOOP);
	//glPushMatrix();
	for (unsigned int i = 0; i < vertices.size(); i++)
		glVertex3f(vertices.at(i).getX()+xp, vertices.at(i).getY()+yp, vertices.at(i).getZ()+zp);
	glEnd();

}

