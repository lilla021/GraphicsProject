#include "Light.h"

Light::Light()
{
}


Light::~Light()
{
}

void Light::setPosition(glm::vec3 pos)
{
	position = pos;
}

void Light::setAmbient(glm::vec3 amb)
{
	ambient = amb;
}

void Light::setDiffuse(glm::vec3 diff)
{
	diffuse = diff;
}

void Light::setSpecular(glm::vec3 spec)
{
	specular = spec;
}

glm::vec3 Light::getPosition()
{
	return position;
}

glm::vec3 Light::getAmbient()
{
	return ambient;
}

glm::vec3 Light::getDiffuse()
{
	return diffuse;
}

glm::vec3 Light::getSpecular()
{
	return specular;
}
