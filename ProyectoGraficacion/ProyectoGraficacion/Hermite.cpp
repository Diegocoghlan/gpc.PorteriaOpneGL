#include <iostream>
#include <math.h>
#include "Hermite.h"
#include "ObjReader.h"
#include <ctime>
#include <GL/glut.h>

void draw(float xd, float yd, float zd);

#define N 50
double s, t; 
int i, di; 
float Punto[4][3]; 
int speed = 16;     

ObjReader f1("Pelota.obj");
ObjReader f2("Porteria.obj");

Hermite::Hermite(float Puntos[][3], int d) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {

			Punto[i][j] = Puntos[i][j];
		}
	}
	di = d;
	i = 0;
	t = 0; 
}

void Timer(int value) {
	if (i <= N) {
		float pow3 = pow(t, 3);
		float pow2 = pow(t, 2);

		float b0 = 2 * pow3 - 3 * pow2 + 1;
		float b1 = -2 * pow3 + 3 * pow2;
		float b2 = pow3 - 2 * pow2 + t;
		float b3 = pow3 - pow2;

		float x = b0 * Punto[0][0] +
			b1 * Punto[1][0] +
			b2 * Punto[2][0] +
			b3 * Punto[3][0];

		float y = b0 * Punto[0][1] +
			b1 * Punto[1][1] +
			b2 * Punto[2][1] +
			b3 * Punto[3][1];

		float z = b0 * Punto[0][2] +
			b1 * Punto[1][2] +
			b2 * Punto[2][2] +
			b3 * Punto[3][2];
		if (di == 1) { 
			draw(x, y, z);
		}
		else {
			glColor3f(1, 0, 1);
			glVertex3f(x, y, z);
		}
		t += s;
		i++;
		glutTimerFunc(speed, Timer, 0);
	}
	glEnd();
	glutSwapBuffers();
}

void Hermite::curva() {
	//glColor3f(1, 0, 1);
	//glBegin(GL_LINE_STRIP);
	s = 1.0 / N;
	glutTimerFunc(0, Timer, 0);   

}

void draw(float xd, float yd, float zd) {

	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glPushMatrix();
	//glRotatef(10, 1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (GLfloat i = -10; i <= 10; i += 1) {
		glVertex3f(i, 0, 10); glVertex3f(i, 0, -10);
		glVertex3f(10, 0, i); glVertex3f(-10, 0, i);
	}
	glEnd();
	glPopMatrix();

	

	glPushMatrix();
	//glRotatef(-30, 0.0, 1.0, 0.0);
	//glColor3f(1.0, 1.0, 0.0);
	f2.drawFiguras(0, 0, 0);
	glPopMatrix();

	glPushMatrix();
	f1.drawFiguras(xd, yd, zd);
	glPopMatrix();

	

	//glRotatef(90.0, 0.0, 1.0, 0.0); 
}
