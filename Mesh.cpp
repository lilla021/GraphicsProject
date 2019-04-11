#include "Mesh.h"

Mesh::Mesh()
{
}


Mesh::~Mesh()
{
}

void Mesh::setFileName(string file)
{
	fileName = file;
}

void Mesh::setAmbient(glm::vec3 amb)
{
	ambient = amb;
}

void Mesh::setDiffuse(glm::vec3 diff)
{
	diffuse = diff;
}

void Mesh::setSpecular(glm::vec3 spec)
{
	specular = spec;
}

void Mesh::setShininess(float shine)
{
	shininess = shine;
}

string Mesh::getFileName()
{
	return fileName;
}

glm::vec3 Mesh::getAmbient()
{
	return ambient;
}

glm::vec3 Mesh::getDiffuse()
{
	return diffuse;
}

glm::vec3 Mesh::getSpecular()
{
	return specular;
}

float Mesh::getShininess()
{
	return shininess;
}
