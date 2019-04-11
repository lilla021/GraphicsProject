#pragma once
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"
#include <vector>
#include "Sphere.h"
#include "Ray.h"


using namespace std;

class RayTracer
{
public:
	RayTracer();
	~RayTracer();

	vector<Sphere> spheres;

	//glm::vec3 Shading(Ray ray, Sphere sphere, float &t);

	//glm::vec3 trace(int x, int y);
};

