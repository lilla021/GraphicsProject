#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"
#include <iostream>
#include <string>
using namespace std;

class Mesh
{
public:
	Mesh();
	~Mesh();

	void setFileName(string file);
	void setAmbient(glm::vec3 amb);
	void setDiffuse(glm::vec3 diff);
	void setSpecular(glm::vec3 spec);
	void setShininess(float shine);

	string getFileName();
	glm::vec3 getAmbient();
	glm::vec3 getDiffuse();
	glm::vec3 getSpecular();
	float getShininess();

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;

private:
	string fileName;
	float shininess;
};

