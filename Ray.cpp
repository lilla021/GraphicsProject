#include "Ray.h"



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

void Ray::setOrigin(glm::vec3 ori)
{
	origin = ori;
}

void Ray::setDirection(glm::vec3 dir)
{
	direction = dir;
}

glm::vec3 Ray::getOrigin() 
{
	return origin;
}

glm::vec3 Ray::getDirection()
{
	return direction;
}