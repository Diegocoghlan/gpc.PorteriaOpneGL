#include <iostream>
#include <GL/glut.h>
#include "Hermite.h"
#include "ObjReader.h"
#include <string>
#include <ctime>   
#include <cstdlib>


void tiraBola() {
	int r, v1;
	srand(time(0));  // Initialize random number generator.
	v1 = rand() % 2;
	r = (rand() % 9);
	if (v1 == 0) {
		float punto[4][3] =
		{
		  {-2, .5, 9}, {-r, .5, -9},
		  {0, 20, 0}, {0, -10, 0}
		};
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		Hermite C{ punto, 1 };
		C.curva();
		glPopMatrix();
		glutSwapBuffers();
	}
	else {
		float punto[4][3] =
		{
		  {-2, .5, 9}, {r, .5, -9},
		  {0, 20, 0}, {0, -10, 0}
		};
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		glPushMatrix();
		Hermite C{ punto, 1 };
		C.curva();
		glPopMatrix();
		glutSwapBuffers();
	}


	
}

void specialkey(int key, int a, int b) {
	switch (key) {
	case GLUT_KEY_DOWN:
		tiraBola();
		break;
	}
}

void display(void)
{
	/*ObjReader r1("Pelota.obj");
	ObjReader r2("Porteria.obj");
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	r1.drawFiguras();
	r2.drawFiguras();
	//glFlush();


	glColor3f(1.0, 1.0, 1.0);
	glPushMatrix();
	glRotatef(10, 1.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (GLfloat i = -7; i <= 7; i += 1) {
		glVertex3f(i, -.5, 7); glVertex3f(i, -.5, -7);
		glVertex3f(7, -.5, i); glVertex3f(-7, -.5, i);
	}
	glEnd();

	glPopMatrix();

	//glPushMatrix();
	//glPopMatrix();
	glutSwapBuffers*();*/
	glutSpecialFunc(specialkey);
	
}





void init(void)
{
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glShadeModel(GL_FLAT);
	glMatrixMode(GL_PROJECTION);
	//glOrtho(-10.0, 10, -10, 10.0, -10.0, 10.0);
	glFrustum(3.0, -3.0, -1.8, 1.8, 2.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, -4, -14);

	//glRotatef(-30.0, 0.0, 1.0, 0.0);
}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Figura");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
