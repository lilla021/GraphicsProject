#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"
#include "Ray.h"

class Sphere
{
public:
	Sphere();
	~Sphere();

	void setPosition(glm::vec3 pos);
	void setRadius(float rad);
	void setAmbient(glm::vec3 amb);
	void setDiffuse(glm::vec3 diff);
	void setSpecular(glm::vec3 spec);
	void setShininess(float shine);
	bool intersect(Ray ray, double &t);

	glm::vec3 getPosition();
	float getRadius();
	glm::vec3 getAmbient();
	glm::vec3 getDiffuse();
	glm::vec3 getSpecular();
	float getShininess(); 

	glm::vec3 position;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

private:
	//glm::vec3 position;
	float radius;
	//glm::vec3 ambient;
	//glm::vec3 diffuse;
	//glm::vec3 specular;
	float shininess;


};

