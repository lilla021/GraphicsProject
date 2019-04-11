#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"
#include "loadScene.h"
#include "Ray.h"
#include "Scene.h"
#include<iostream>
#define _USE_MATH_DEFINES
#include <math.h>

//#include "CImg.h"
using namespace std;

int main()
{
	loadScene file("scene1.txt");
	file.readFile();

	/*CImg<float> image(100, 100, 1, 3, 0);
	const float color[] = { 1.0,1.0,0.0 };
	image.draw_point(50, 50, color);
	image.save("file.bmp");
	CImgDisplay local(image, "Hah");
	while (true) {
		local.wait();
	}
	*/

	Scene* scene = scene->getInstance();

	cout <<  endl << "IN MAIN" << endl << scene->getCamera().position.x << " " << scene->getCamera().position.y << " " << scene->getCamera().position.z << endl;
	
	//Ray ray;

	//retrieve info needed to calculate image space
	int fov = scene->getCamera().getFOV();
	int focal = scene->getCamera().getFocal();
	int aspect = scene->getCamera().getARatio();
	float radians = M_PI * 60 / 180;

	//image space width and height
	const int width = (2 * aspect * focal * glm::tan(radians / 2));
	const int height = (2 * focal * glm::tan(radians / 2));

	//Shoot a ray through each pixel in the image space

	for (int y = 0 ; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			Ray ray(glm::vec3(x, y, 0), glm::vec3(0, 0, 1));

			//working!
			//cout << endl << endl << "Ray shot through pixel (" << x << "," << y << ")" << endl;

		}
	}
	
	
	
	
	
	
	system("pause");
	return 0;
}