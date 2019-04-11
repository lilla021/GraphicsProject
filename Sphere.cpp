#include "Sphere.h"



Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}


void Sphere::setPosition(glm::vec3 pos)
{
	position = pos;
}

void Sphere::setRadius(float rad)
{
	radius = rad;
}

void Sphere::setAmbient(glm::vec3 amb)
{
	ambient = amb;
}

void Sphere::setDiffuse(glm::vec3 diff)
{
	diffuse = diff;
}

void Sphere::setSpecular(glm::vec3 spec)
{
	specular = spec;
}

void Sphere::setShininess(float shine) 
{
	shininess = shine;
}


glm::vec3 Sphere::getPosition()
{
	return position;
} 

float Sphere::getRadius()
{
	return radius;
}

glm::vec3 Sphere::getAmbient()
{
	return ambient;
}

glm::vec3 Sphere::getDiffuse()
{
	return diffuse;
}

glm::vec3 Sphere::getSpecular()
{
	return specular;
}

float Sphere::getShininess()
{
	return shininess;
}
