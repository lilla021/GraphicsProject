#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"
#include "Camera.h"

class Pixel
{
public:
	int x;
	int y;
	glm::vec3 pixelColor;
	Pixel();
	Pixel(int x1, int y1, glm::vec3 pixCol);
	glm::vec3 getPixelColor();

};

class Ray {
	
public:
	Ray();
	~Ray();
	Ray(glm::vec3 ori, glm::vec3 dir);
	//Ray(Camera cam);
	
	void setOrigin(glm::vec3 ori);
	void setDirection(glm::vec3 dir);
	void setPixel(Pixel pix);

	glm::vec3 getOrigin();
	glm::vec3 getDirection();
	Pixel getPixel();

	glm::vec3 origin;
	glm::vec3 direction;

	Pixel pixel;
};