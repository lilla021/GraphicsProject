#include "Plane.h"

Plane::Plane()
{
}


Plane::~Plane()
{
}


void Plane::setNormal(glm::vec3 norm)
{
	normal = norm;
}

void Plane::setPosition(glm::vec3 pos)
{
	position = pos;
}


void Plane::setAmbient(glm::vec3 amb)
{
	ambient = amb;
}


void Plane::setDiffuse(glm::vec3 diff)
{
	diffuse = diff;
}


void Plane::setSpecular(glm::vec3 spec)
{
	specular = spec;
}


void Plane::setShininess(float shine)
{
	shininess = shine;
}


glm::vec3 Plane::getNormal()
{
	return normal;
}

glm::vec3 Plane::getPosition()
{
	return position;
}

glm::vec3 Plane::getAmbient()
{
	return ambient;
}

glm::vec3 Plane::getDiffuse()
{
	return diffuse;
}

glm::vec3 Plane::getSpecular()
{
	return specular;
}

float Plane::getShininess() 
{
	return shininess;
}
