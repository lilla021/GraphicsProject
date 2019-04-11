#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"

class Plane
{
public:
	Plane();
	~Plane();

	void setNormal(glm::vec3 norm);
	void setPosition(glm::vec3 pos);
	void setAmbient(glm::vec3 amb);
	void setDiffuse(glm::vec3 diff);
	void setSpecular(glm::vec3 spec);
	void setShininess(float shine);

	glm::vec3 getNormal();
	glm::vec3 getPosition();
	glm::vec3 getAmbient();
	glm::vec3 getDiffuse();
	glm::vec3 getSpecular();
	float getShininess();

	glm::vec3 normal;
	glm::vec3 position;
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

private:
	//glm::vec3 position;
	//glm::vec3 normal;
	//glm::vec3 ambient;
	//glm::vec3 diffuse;
	//glm::vec3 specular;
	float shininess;

};

