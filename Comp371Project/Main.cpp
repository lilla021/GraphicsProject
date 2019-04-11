#include "../glm/gtc/type_ptr.hpp"
#include "../glm/glm.hpp"
#include "loadScene.h"
#include "Ray.h"
#include "Scene.h"
#include<iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include "../CImg/CImg.h"

using namespace std;
struct Color 
{
	double red, green, blue;
	Color()
	{
		red = 0;
		green = 0;
		blue = 0;
	}

	Color(double r, double g, double b)
	{
		red = r;
		green = g;
		blue = b;
	}

};


int main()
{
	loadScene file("scene2.txt");
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
	const int WIDTH = (2 * aspect * focal * glm::tan(radians / 2));
	const int HEIGHT = (2 * focal * glm::tan(radians / 2));

	cimg_library::CImg<float> image(WIDTH, HEIGHT, 1, 3);
		
	//const float white[] = { 255.0, 255.0, 255.0 };
	//float pixel_color[3];

	glm::vec3 pixel_color(0, 0, 0);

	//vector <Ray> allRays;

	Color white(255, 255, 255);
	//Color pixel_color(0, 0, 0);

	//int numPixels = WIDTH * HEIGHT;
	//Color* pixel_color = new Color[numPixels];

	//Color **pixCol = new Color*[HEIGHT];
	
	//Shoot a ray through each pixel in the image space

	for (int y = 0 ; y < HEIGHT; y++)
	{
		//pixCol[y] = new Color[WIDTH];
		for (int x = 0; x < WIDTH; x++)
		{
			
			//Ray ray(glm::vec3(x, y, 0), glm::vec3(0, 0, -1));
			//Ray ray(glm::vec3(scene->getCamera().position), glm::vec3(0, 0, -1));
		
			glm::vec3 rayOrigin = { scene->getCamera().position[0], scene->getCamera().position[1], scene->getCamera().position[2] + focal };
			//vector<float> pixelPosition = { -static_cast<float>(WIDTH) / 2 + x, static_cast<float>(HEIGHT) / 2 - y, scene->getCamera().position[2] };
			glm::vec3 pix(-static_cast<float>(WIDTH) / 2 + x, static_cast<float>(HEIGHT) / 2 - y, scene->getCamera().position[2]);
			glm::vec3 rayDirection = glm::normalize(pix - rayOrigin);
			Ray ray = Ray(scene->getCamera().position, rayDirection);

			//Pixel pixel(x,y);
			//ray.setPixel(pixel);
			//Color pixel_color(0, 0, 0);
			
			//working!
			//cout << endl << endl << "Ray shot through pixel (" << x << "," << y << ")" << endl;

			double t = INFINITY;

			//if there are spheres
			if (scene->getSpheres().size() > 0)
			{
				for (int i = 0; i < scene->getSpheres().size(); i++)
				{
					if (scene->getSpheres()[i].intersect(ray, t))
					{
						//working
						cout << endl << t * (-1) << endl;
						cout << endl << "Ray intersects sphere " << (i + 1) << " at pixel (" << x << "," << y << ")" << endl;
					
						
						//Shoot shadow rays


						//Color pixels at intersection
						//pixel_color[y*HEIGHT + x] = white;
						//pixel_color = white;

						//pixCol[y][x] = white;
						pixel_color[0] = scene->getSpheres()[i].ambient[0];
						pixel_color[1] = scene->getSpheres()[i].ambient[1];
						pixel_color[2]  = scene->getSpheres()[i].ambient[2];
						
						
						
						//cout << endl << "TESTING " << endl << pixel_color.red << endl << pixel_color.green << endl << pixel_color.blue << endl;
						

					}
					else
					{
						pixel_color[0] = 0;
						pixel_color[1] = 0;
						pixel_color[2] = 0;
						
						
						//cout << endl << "TESTING NO INTERSECT " << endl << pixel_color.red << endl << pixel_color.green << endl << pixel_color.blue << endl;

					}
				}

			}
			Pixel pixel(x, y, pixel_color);
			ray.setPixel(pixel);
			
			//image.draw_point(150, 150, white);
			
			image(ray.getPixel().x, ray.getPixel().y, 0, 0) = ray.getPixel().getPixelColor()[0] * 255;
			image(ray.getPixel().x, ray.getPixel().y, 0, 1) = ray.getPixel().getPixelColor()[1] * 255;
			image(ray.getPixel().x, ray.getPixel().y, 0, 2) = ray.getPixel().getPixelColor()[2] * 255;


			//image.draw_point(x, y, pixel_color);

			//image(x, y, 0, 0) = pixel_color[0] * 255.0f;	//red
			//image(x, y, 0, 1) = pixel_color[1] * 255.0f;	//green
			//image(x, y, 0, 2) = pixel_color[2] * 255.0f;	//blue
			


			//out << pixel_color[y*HEIGHT + x].red << endl;
			//out << pixel_color[y*HEIGHT + x].green << endl;
			//out << pixel_color[y*HEIGHT + x].blue << endl;

			//out << pixCol[y][x].red << endl;
			//out << pixCol[y][x].green << endl;
			//out << pixCol[y][x].blue << endl;
		}
	}

		

	image.normalize(0, 255);
	image.save("render.bmp");
	cimg_library::CImgDisplay main_disp(image, "Render");

	while (!main_disp.is_closed())
	{
		main_disp.wait();
	}
	cout << endl << "DONE!" << endl;
	
	
	
	
	system("pause");
	return 0;
}