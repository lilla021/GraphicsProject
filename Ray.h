#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"
#include "Camera.h"

class Ray {
	
public:
	Ray();
	~Ray();
	Ray(glm::vec3 ori, glm::vec3 dir);
	//Ray(Camera cam);
	
	void setOrigin(glm::vec3 ori);
	void setDirection(glm::vec3 dir);

	glm::vec3 getOrigin();
	glm::vec3 getDirection();

	glm::vec3 origin;
	glm::vec3 direction;
};