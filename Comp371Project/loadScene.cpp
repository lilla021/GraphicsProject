
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "loadScene.h"
#include "Scene.h"
//#include "CImg.h"

using namespace std;

loadScene::loadScene(string name)
{
	fileName = name;
	numObjects = 0;
}

loadScene::~loadScene()
{
}

void loadScene::readFile()
{
	Ray ray;
	//SINGLETON
	Scene* scene = scene->getInstance();
	
	file.open(fileName);
	if (!file)
	{
		cerr << "Unable to open file " << fileName << endl;
		system("pause");
		exit(1);
	}

	string line;
	getline(file, line);

	//check if first line is an integer value
	if (line.find("%d") != string::npos)
		fileError();
	

	sscanf_s(line.c_str(), "%d", &numObjects);
	
	cout << numObjects << "Total number of objets: " << endl;

	 
	while (getline(file, line))
	{
		
		//find Camera object
		if (line.find("camera") != string::npos)
		{
			cout << endl << endl << "CAMERA FOUND!";
			numObjects--;
			cout << endl << "Number of objects left: " << numObjects;

			for (int i = 0; i < 4; i++)
			{
				getline(file, line);
				if (line.find("pos") != string::npos)
				{
					cout << endl << "Position:";
					glm::vec3 pos;
					sscanf_s(line.c_str(), "pos: %f %f %f", &pos.x, &pos.y, &pos.z);
					camera.setPosition(pos);
					cout << endl << camera.position.x << " " << camera.position.y << " " << camera.position.z <<endl;
					
					//ray.setOrigin(pos);
					//cout << endl << ray.origin.x << " " << ray.origin.y << " " << ray.origin.z << endl;

				}
				else if (line.find("fov") != string::npos)
				{
					cout << endl << "Field of View:";
					float fov;
					sscanf_s(line.c_str(), "fov: %f", &fov);
					camera.setFOV(fov);
					cout << endl << camera.getFOV() << endl;

				}
				else if (line.find("f") != string::npos)
				{
					cout << endl << "Focal Length:";
					float focal;
					sscanf_s(line.c_str(), "f: %f", &focal);
					camera.setFocal(focal);
					cout << endl << camera.getFocal() << endl;
				}
				else if (line.find("a") != string::npos)
				{
					cout << endl << "Aspect Ratio:";
					float aratio;
					sscanf_s(line.c_str(), "a: %f", &aratio);
					camera.setARatio(aratio);
					cout << endl << camera.getARatio() << endl;
				}

			}
			
			scene->setCamera(camera);
			//Camera.setPosition();
		}
		//find plane object
		if (line.find("plane") != string::npos)
		{
			cout << endl << endl << endl << "PLANE FOUND!";
			numObjects--;
			cout << endl << "Number of objects left: " << numObjects;

			for (int i = 0; i < 6; i++)
			{
				getline(file, line);
				if (line.find("nor") != string::npos)
				{
					cout << endl << "Normal:";
					glm::vec3 norm;
					sscanf_s(line.c_str(), "nor: %f %f %f", &norm.x, &norm.y, &norm.z);
					plane.setNormal(norm);
					cout << endl << plane.normal.x << " " << plane.normal.y << " " << plane.normal.z << endl;

				}
				else if (line.find("pos") != string::npos)
				{
					cout << endl << "Position:";
					glm::vec3 pos;
					sscanf_s(line.c_str(), "pos: %f %f %f", &pos.x, &pos.y, &pos.z);
					plane.setPosition(pos);
					cout << endl << plane.position.x << " " << plane.position.y << " " << plane.position.z << endl;
				}
				else if (line.find("amb") != string::npos)
				{
					cout << endl << "Ambient:";
					glm::vec3 amb;
					sscanf_s(line.c_str(), "amb: %f %f %f", &amb.x, &amb.y, &amb.z);
					plane.setAmbient(amb);
					cout << endl << plane.ambient.x << " " << plane.ambient.y << " " << plane.ambient.z << endl;
				}
				else if (line.find("dif") != string::npos)
				{
					cout << endl << "Diffuse:";
					glm::vec3 diff;
					sscanf_s(line.c_str(), "dif: %f %f %f", &diff.x, &diff.y, &diff.z);
					plane.setDiffuse(diff);
					cout << endl << plane.diffuse.x << " " << plane.diffuse.y << " " << plane.diffuse.z << endl;
				}
				else if (line.find("spe") != string::npos)
				{
					cout << endl << "Specular:";
					glm::vec3 spec;
					sscanf_s(line.c_str(), "spe: %f %f %f", &spec.x, &spec.y, &spec.z);
					plane.setSpecular(spec);
					cout << endl << plane.specular.x << " " << plane.specular.y << " " << plane.specular.z << endl;
				}
				else if (line.find("shi") != string::npos)
				{
					cout << endl << "Shininess:";
					float shine;
					sscanf_s(line.c_str(), "shi: %f", &shine);
					plane.setShininess(shine);
					cout << endl << plane.getShininess() << endl;
				}

			}
			scene->setPlane(plane);

		}
		//find mesh object
		if (line.find("mesh") != string::npos)
		{
			cout << endl << endl << endl << "MESH FOUND!";
			numObjects--;
			cout << endl << "Number of objects left: " << numObjects;


			for (int i = 0; i < 5; i++)
			{
				getline(file, line);

				if (line.find("file") != string::npos)
				{
					cout << endl << "File Name:";
					string file;
					// Find position of ':' using find() 
					int pos = line.find(":");
					// Copy substring after pos 
					file = line.substr(pos + 2);
					//sscanf_s(line.c_str(), "file: %f %f %f", &file);
					mesh.setFileName(file);
					cout << endl << mesh.getFileName() << endl;
				}
				else if (line.find("amb") != string::npos)
				{
					cout << endl << "Ambient:";
					glm::vec3 amb;
					sscanf_s(line.c_str(), "amb: %f %f %f", &amb.x, &amb.y, &amb.z);
					mesh.setAmbient(amb);
					cout << endl << mesh.ambient.x << " " << mesh.ambient.y << " " << mesh.ambient.z << endl;
				}
				else if (line.find("dif") != string::npos)
				{
					cout << endl << "Diffuse:";
					glm::vec3 diff;
					sscanf_s(line.c_str(), "dif: %f %f %f", &diff.x, &diff.y, &diff.z);
					mesh.setDiffuse(diff);
					cout << endl << mesh.diffuse.x << " " << mesh.diffuse.y << " " << mesh.diffuse.z << endl;
				}
				else if (line.find("spe") != string::npos)
				{
					cout << endl << "Specular:";
					glm::vec3 spec;
					sscanf_s(line.c_str(), "spe: %f %f %f", &spec.x, &spec.y, &spec.z);
					mesh.setSpecular(spec);
					cout << endl << mesh.specular.x << " " << mesh.specular.y << " " << mesh.specular.z << endl;
				}
				else if (line.find("shi") != string::npos)
				{
					cout << endl << "Shininess:";
					float shine;
					sscanf_s(line.c_str(), "shi: %f", &shine);
					mesh.setShininess(shine);
					cout << endl << mesh.getShininess() << endl;
				}

			}
			scene->setMesh(mesh);
		}
		//find Camera object
		if (line.find("sphere") != string::npos)
		{
			cout << endl << endl << endl << "SPHERE FOUND!";
			numObjects--;
			cout << endl << "Number of objects left: " << numObjects;

			for (int i = 0; i < 6; i++)
			{
				getline(file, line);
				if (line.find("pos") != string::npos)
				{
					cout << endl << "Position:";
					glm::vec3 pos;
					sscanf_s(line.c_str(), "pos: %f %f %f", &pos.x, &pos.y, &pos.z);
					sphere.setPosition(pos);
					cout << endl << sphere.position.x << " " << sphere.position.y << " " << sphere.position.z << endl;
				}
				else if (line.find("rad") != string::npos)
				{
					cout << endl << "Radius:";
					float rad;
					sscanf_s(line.c_str(), "rad: %f", &rad);
					sphere.setRadius(rad);
					cout << endl << sphere.getRadius() << endl;

				}
				else if (line.find("amb") != string::npos)
				{
					cout << endl << "Ambient:";
					glm::vec3 amb;
					sscanf_s(line.c_str(), "amb: %f %f %f", &amb.x, &amb.y, &amb.z);
					sphere.setAmbient(amb);
					cout << endl << sphere.ambient.x << " " << sphere.ambient.y << " " << sphere.ambient.z << endl;
				}
				else if (line.find("dif") != string::npos)
				{
					cout << endl << "Diffuse:";
					glm::vec3 diff;
					sscanf_s(line.c_str(), "dif: %f %f %f", &diff.x, &diff.y, &diff.z);
					sphere.setDiffuse(diff);
					cout << endl << sphere.diffuse.x << " " << sphere.diffuse.y << " " << sphere.diffuse.z << endl;
				}
				else if (line.find("spe") != string::npos)
				{
					cout << endl << "Specular:";
					glm::vec3 spec;
					sscanf_s(line.c_str(), "spe: %f %f %f", &spec.x, &spec.y, &spec.z);
					sphere.setSpecular(spec);
					cout << endl << sphere.specular.x << " " << sphere.specular.y << " " << sphere.specular.z << endl;
				}
				else if (line.find("shi") != string::npos)
				{
					cout << endl << "Shininess:";
					float shine;
					sscanf_s(line.c_str(), "shi: %f", &shine);
					sphere.setShininess(shine);
					cout << endl << sphere.getShininess() << endl;
				}
			}

			spheres.push_back(sphere);
		}
		//find light object
		if (line.find("light") != string::npos)
		{
			cout << endl << endl << "LIGHT FOUND!";
			numObjects--;
			cout << endl << "Number of objects left: " << numObjects;

			for (int i = 0; i < 3; i++)
			{
				getline(file, line);
				
				if (line.find("pos") != string::npos)
				{
					cout << endl << "Position:";
					glm::vec3 pos;
					sscanf_s(line.c_str(), "pos: %f %f %f", &pos.x, &pos.y, &pos.z);
					light.setPosition(pos);
					cout << endl << light.position.x << " " << light.position.y << " " << light.position.z << endl;
				}
				else if (line.find("dif") != string::npos)
				{
					cout << endl << "Diffuse:";
					glm::vec3 diff;
					sscanf_s(line.c_str(), "dif: %f %f %f", &diff.x, &diff.y, &diff.z);
					light.setDiffuse(diff);
					cout << endl << light.diffuse.x << " " << light.diffuse.y << " " << light.diffuse.z << endl;
				}
				else if (line.find("spe") != string::npos)
				{
					cout << endl << "Specular:";
					glm::vec3 spec;
					sscanf_s(line.c_str(), "spe: %f %f %f", &spec.x, &spec.y, &spec.z);
					light.setSpecular(spec);
					cout << endl << light.specular.x << " " << light.specular.y << " " << light.specular.z << endl;
				}
			}

			lights.push_back(light);
		}
	}
	scene->setSpheres(spheres);
	scene->setLights(lights);

	cout << endl << endl << fileName << " Has succesfully been read!" << endl << "File reading completed." << endl;
	file.close();
	
}

void loadScene::fileError() 
{
	cout << "Unable to read file " << fileName << " File format error." << endl;
	file.close();
	system("pause");
	exit(1);
}

