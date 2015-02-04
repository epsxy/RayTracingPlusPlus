#include <iostream>
#include <fstream>
#include <string>
//#include <cstdlib>
#include <stdlib.h>
#include "sphere.h"
#include "object.h"
#include "cube.h"
#include "material.h"
#include "point.h"
#include "color.h"
#include "scene.h"

using namespace std;

void Scene::loadScene(const string path) {

    int numberOfObjects = 0;
    int nb_sphere = 0;
    int nb_cube = 0;
    int nb_camera = 0;
    int nb_light = 0;
    int line_size = 0;
    int i,j;

    float nb_1, nb_2, nb_3, radius;
    float color_R, color_V, color_B;

    float cp1_1, cp1_2, cp1_3, cp2_1, cp2_2, cp2_3, cp3_1, cp3_2, cp3_3, cp4_1, cp4_2, cp4_3;
    float cp5_1, cp5_2, cp5_3, cp6_1, cp6_2, cp6_3, cp7_1, cp7_2, cp7_3, cp8_1, cp8_2, cp8_3;

    Point center, ar_1, ar_2, ar_3, ar_4, ar_5, ar_6, ar_7, ar_8;

    int comp_sp = 0;
    int comp_cu = 0;
    int comp_ca = 0;
    int comp_li = 0;

    int comp_ob = 0;

    Color color_object;

    string file_name = "input";
    ifstream file_img;
    file_img.open(file_name.c_str());
    const char* line_img_str;

    // Si ouverture OK
    if(file_img) {
        string line_img;
        // Boucle sur les lignes
        while(getline(file_img, line_img)) {
            numberOfObjects++;
            cout << line_img << endl;
            line_img_str = line_img.c_str();
            if(line_img_str[0]=='s'&&line_img_str[1]=='p') {
                nb_sphere++;
            }
            if(line_img_str[0]=='c'&&line_img_str[1]=='u') {
                nb_cube++;
            }
            if(line_img_str[0]=='c'&&line_img_str[1]=='a') {
                nb_camera++;
            }
            if(line_img_str[0]=='l'&&line_img_str[1]=='i') {
                nb_light++;
            }
        }

        Object *arrayOfObjects = new Object[numberOfObjects];
        Sphere *arrayOfSphere = new Sphere[nb_sphere];
        Cube *arrayOfCube = new Cube[nb_cube];
        Camera *arrayOfCamera = new Camera[nb_camera];
        Light *arrayOfLight = new Light[nb_light];

        file_img.clear();
        file_img.seekg(0, file_img.beg);
        while(getline(file_img, line_img)) {
            line_img_str = line_img.c_str();
            line_size = line_img.size();
                // Si la ligne est de type sphere
            if(line_img_str[0]=='s'&&line_img_str[1]=='p') {
                //Sphere spr;
                sscanf(line_img_str, "sp (%f %f %f) %f (%f %f %f)", &nb_1, &nb_2, &nb_3, &radius, &color_R, &color_V, &color_B);
                center.setPoint(nb_1, nb_2, nb_3);
                arrayOfSphere[comp_sp].setCenter(center);
                color_object.setColor(color_R, color_V, color_B);
                arrayOfSphere[comp_sp].setColorObject(color_object);
                arrayOfSphere[comp_sp].setTypeObject("sphere");
                arrayOfSphere[comp_sp].printSphere();
                comp_sp++;
            }
            // si la ligne est de type cube
            if(line_img_str[0]=='c'&&line_img_str[1]=='u') {
                sscanf(line_img_str, "cu (%f %f %f) (%f %f %f) (%f %f %f) (%f %f %f) (%f %f %f) (%f %f %f) (%f %f %f) (%f %f %f) (%f %f %f)", &cp1_1, &cp1_2, &cp1_3, &cp2_1, &cp2_2, &cp2_3, &cp3_1, &cp3_2, &cp3_3, &cp4_1, &cp4_2, &cp4_3, &cp5_1, &cp5_2, &cp5_3, &cp6_1, &cp6_2, &cp6_3, &cp7_1, &cp7_2, &cp7_3, &cp8_1, &cp8_2, &cp8_3, &color_R, &color_V, &color_B);
                ar_1.setPoint(cp1_1, cp1_2, cp1_3);
                ar_2.setPoint(cp2_1, cp2_2, cp2_3);
                ar_3.setPoint(cp3_1, cp3_2, cp3_3);
                ar_4.setPoint(cp4_1, cp4_2, cp4_3);
                ar_5.setPoint(cp5_1, cp5_2, cp5_3);
                ar_6.setPoint(cp6_1, cp6_2, cp6_3);
                ar_7.setPoint(cp7_1, cp7_2, cp7_3);
                ar_8.setPoint(cp8_1, cp8_2, cp8_3);
                arrayOfCube[comp_cu].setCube(ar_1, ar_2, ar_3, ar_4, ar_5, ar_6, ar_7, ar_8);
                color_object.setColor(color_R, color_V, color_B);
                arrayOfCube[comp_cu].setColorObject(color_object);
                arrayOfCube[comp_cu].setTypeObject("cube");
                comp_cu++;
            }
            // si la ligne est de type camera
            if(line_img_str[0]=='c'&&line_img_str[1]=='a') {
                sscanf(line_img_str, "ca (%f %f %f) (%f %f %f) %s", );
                arrayOfCamera[comp_ca].setCamera();
                arrayOfCamera[comp_ca].setTypeObject("camera");
            }
            // si la ligne est de type light
            if(line_img_str[0]=='l'&&line_img_str[1]=='i') {
                sscanf(line_img_str, "li (%f %f %f) %f (%f %f %f)", &cp1_1, &cp1_2, &cp1_3, &nb_1, &color_R, &color_V, &color_B);
                arrayOfLight[comp_li].setLight();
                arrayOfLight[comp_li].setTypeObject("light");
            }
            for(i=0; i<nb_sphere; i++) {
                arrayOfObjects[comp_ob] = arrayOfSphere[i];
                comp_ob++;
            }
            for(i=0; i<nb_cube; i++) {
                arrayOfObjects[comp_ob] = arrayOfCube[i];
            }
        }
    }
    else {
        cerr << "Error when opening input file" << endl;
    }
}
