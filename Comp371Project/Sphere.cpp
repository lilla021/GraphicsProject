#include "Sphere.h"



Sphere::Sphere()
{
}


Sphere::~Sphere()
{
}

bool Sphere::intersect(Ray ray, double &t)
{
	glm::vec3 origin = ray.getOrigin();
	glm::vec3 direction = ray.getDirection();

	glm::vec3 op = origin - position;

	const float b = 2 * glm::dot(op, direction);
	const float c = glm::dot(op, op) - radius * radius;
	float disc = b * b - 4 * c;

	if (disc < 0)
		return false;
	else
	{
		const float t1 = (-b - sqrt(disc)) / 2;
		const float t2 = (-b + sqrt(disc)) / 2;

		// get the first intersection only
		t = (t1 < t2) ? t1 : t2;

		return true;
	}
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
