#pragma once
#include "Camera.h"
#include "Sphere.h"
#include "Plane.h"
#include "Light.h"
#include "Mesh.h"
#include "Ray.h"
# include <vector>

class Scene
{
public:
		
	static Scene* getInstance();

	void setCamera(Camera cam);
	void setPlane(Plane plane);
	void setMesh(Mesh mesh);
	void setSpheres(vector <Sphere> sph);
	void setLights(vector <Light> light);
	
	Camera getCamera();
	Plane getPlane();
	Mesh getMesh();
	vector <Sphere> getSpheres();
	vector <Light> getLights();

private:
	static Scene* instance;
	Scene();
	~Scene();

	Camera camera;
	Plane plane;
	Mesh mesh;

	vector <Sphere> spheres;
	vector <Light> lights;
};

