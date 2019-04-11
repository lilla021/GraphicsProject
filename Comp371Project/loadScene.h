#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "Camera.h"
#include "Sphere.h"
#include "Plane.h"
#include "Light.h"
#include "Mesh.h"
#include "RayTracer.h"


using namespace std;
class loadScene
{
public:
	loadScene(string name);
	void readFile();
	~loadScene();
private:
	int numObjects;

	ifstream file;
	string fileName;
	void fileError();
	
	Camera camera;
	Sphere sphere;
	Plane plane;
	Light light;
	Mesh mesh;

	vector <Sphere> spheres;
	vector <Light> lights;
	
	Ray ray;
	RayTracer tracer;

	
};
