#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void Scene::load_scene(const string path) {

    int numberOfObjects = 0;
    int line_size = 0;
    int i,j;
    string file_name = "input";
    ifstream file_img;
    file_img.open(file_name.c_str());

    // Si ouverture OK
    if(file_img) {
        string line_img;
        // Boucle sur les lignes
        while(getline(file_img, line_img)) {
            numberOfObjects++;
            line_size = line_img.size();
            // si la ligne est de type sphere
            if(line_img[0]="s"&&line_img[1]="p") {
                j = 4;
                Sphere spr;
                //Sphere.setCenter
            }
            // si la ligne est de type cube
            if(line_img[0]="c"&&line_img[1]="u") {

            }
            // si la ligne est de type camera
            if(line_img[0]="c"&&line_img[1]="a") {

            }
            // si la ligne est de type light
            if(line_img[0]="l"&&line_img[1]="i") {

            }
        }
        m_objectNumber = numberOfObjects;
    }
    // Si erreur
    else {
        cerr << "Error when opening input file" << endl;
    }
    return 0;
}
