#include "Scene.h"



Scene::Scene()
{
}


Scene::~Scene()
{
}

Scene* Scene::instance = NULL;
Scene* Scene::getInstance()
{
	if (instance == NULL)
		instance = new Scene();
	return instance;
}



void Scene::setCamera(Camera cam)
{
	camera = cam;
}


void Scene::setPlane(Plane pla)
{
	plane = pla;
}

void Scene::setMesh(Mesh mes)
{
	mesh = mes;
}

void Scene::setSpheres(vector <Sphere> sph)
{
	spheres = sph;
}

void Scene::setLights(vector <Light> light)
{
	lights = light;
}

Camera Scene::getCamera()
{
	return camera;
}

Plane Scene::getPlane()
{
	return plane;
}

Mesh Scene::getMesh()
{
	return mesh;

}

vector <Sphere> Scene::getSpheres()
{
	return spheres;
}

vector <Light> Scene::getLights()
{
	return lights;
}