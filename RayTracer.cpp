#include "RayTracer.h"



RayTracer::RayTracer()
{
}


RayTracer::~RayTracer()
{
}

/*glm::vec3 RayTracer::Shading(Ray ray, Sphere sphere, float &t)
{
	glm::vec3 color(0, 0, 0);

	if (sphere.intersect(ray, t)) {
		glm::vec3 V = ray.getDirection();
		glm::vec3 P = ray.getOrigin() + V * t;
		glm::vec3 N = sphere.getNormal(P);

		V = V.normalize();
		N = N.normalize();

		float facing_ratio = N.dot(V);

		color = sphere.get_color() * (facing_ratio * 0.5);
	}
	return color;
}*/


/*glm::vec3 RayTracer::trace(int x, int y) {


	glm::vec3 pix_col(0, 0, 0);


	float min_t = 1000000;
	float t;
	// I will correct this later        
	glm::vec3 ray_origin = glm::vec3(x, y, 0);
	glm::vec3 ray_direction = glm::vec3(0, 0, 1);

	Ray ray(ray_origin, ray_direction);
	for (int i = 0; i < spheres.size(); i++) {
		glm::vec3 color = glm::vec3(0.5, 0.5, 0.5);
		//glm::vec3 color = Shading(ray, spheres[i], t);
		if (min_t > t) {
			pix_col = color;
			min_t = t;
		}
	}
	return pix_col;
}*/