#include "Ray.h"


Pixel::Pixel()
{
	x = 0;
	y = 0;
	pixelColor[0] = 0;
	pixelColor[1] = 0;
	pixelColor[2] = 0;

}

Pixel::Pixel(int x1, int y1, glm::vec3 pixelCol)
{
	x = x1;
	y = y1;
	pixelColor[0] = pixelCol[0];
	pixelColor[1] = pixelCol[1];
	pixelColor[2] = pixelCol[2];
}

glm::vec3 Pixel::getPixelColor()
{
	return pixelColor;
}

Ray::Ray()
{
}


Ray::~Ray()
{
}

Ray::Ray(glm::vec3 ori, glm::vec3 dir)
{
	origin = ori;
	direction = dir;
	
}
/*Ray::Ray(Camera cam)
{
	origin = glm::vec3(cam.position.x, cam.position.y, cam.position.z);
	direction = glm::normalize(glm::vec3(x, y, -cam.getFocal) - cam.position);
}*/

void Ray::setPixel(Pixel pix)
{
	pixel = pix;
}

void Ray::setOrigin(glm::vec3 ori)
{
	origin = ori;
}

void Ray::setDirection(glm::vec3 dir)
{
	direction = dir;
}

Pixel Ray::getPixel()
{
	return pixel;
}

glm::vec3 Ray::getOrigin() 
{
	return origin;
}

glm::vec3 Ray::getDirection()
{
	return direction;
}