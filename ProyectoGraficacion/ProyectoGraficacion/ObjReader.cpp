	#include "Vertice.h"
#include "Cara.h"
#include "Figura.h"
#include "ObjReader.h"
#include <stdio.h>
#include <fstream>
#include <vector>


using namespace std;

ObjReader::ObjReader(string archivo)
{
	//Abre el archivo
	objFile.open(archivo);
	if (objFile) {
		readObj();
	}
	else {
		cerr << "No se encontro el obj" << endl;
	}
}

void ObjReader::readObj()
{
	string ini; //Inicio de la linea 
	string nombre; //Nombre de la figura
	vector<Vertice> vertices; //Lista de vertices
	vector<Cara> caras;//Lista de caras 
	while (getline(objFile, ini))
	{
		stringstream data(ini.substr(2));

		//Verifica el inicio de la fila "o" para el nombre del objeto
		if (ini.substr(0, 2) == "o ")
		{
			data >> nombre;  //Guarda nombre
			if (caras.size() > 0 && vertices.size() > 0)
				figuras.push_back(Figura(caras, nombre));
		}
		else if (ini.substr(0, 2) == "v ")  // "v" para vertice
		{
			float x, y, z;
			data >> x >> y >> z;
			vertices.push_back(Vertice(x, y, z)); //Inserta vertice en lista 
		}
		else if (ini.substr(0, 2) == "f ")  // "f" para cara
		{
			Cara cara;
			int numVertice;
			while (data >> numVertice) //Se reúnen los puntos en una lista para crear la cara 
				cara.addVertice(vertices.at(numVertice - 1));
			caras.push_back(cara);

		}
		figuras.push_back(Figura(caras, nombre));
	}
}

void ObjReader::drawFiguras(float xp, float yp, float zp)
{
	//glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	for (unsigned int i = 0; i < figuras.size(); i++)
		figuras.at(i).drawObject(xp,yp,zp);
}


