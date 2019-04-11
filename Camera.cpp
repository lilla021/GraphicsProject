#include "Camera.h"



Camera::Camera()
{
	

}


Camera::~Camera()
{
}


void Camera::setPosition(glm::vec3 pos)
{
	position = pos;
}

void Camera::setFOV(float fov)
{
	field_of_view = fov;
}

void Camera::setFocal(float focal)
{
	focal_length = focal;
}

void Camera::setARatio(float aratio)
{
	aspect_ratio = aratio;
}

glm::vec3 Camera::getPostion()
{
	return position;
}

float Camera::getFOV()
{
	return field_of_view;
}

float Camera::getFocal()
{
	return focal_length;
}

float Camera::getARatio()
{
	return aspect_ratio;
}

