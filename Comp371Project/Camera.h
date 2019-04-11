#pragma once
//#include "../glm/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"

class Camera
{
public:
	Camera();
	~Camera();
	
	void setPosition(glm::vec3 pos);
	void setFOV(float fov);
	void setFocal(float focal);
	void setARatio(float aratio);

	glm::vec3 getPostion();
	float getFOV();
	float getFocal();
	float getARatio();
	glm::vec3 position;
private:
	//glm::vec3 position;
	float field_of_view;
	float focal_length;
	float aspect_ratio;
	



};

