/* 
 * File:   SDFLoader.cpp
 * Author: Benedikt Vogler
 * 
 * Created on 8. Juli 2014, 18:52
 */

#include "SDFloader.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Material.hpp"
using namespace std;

SDFLoader::SDFLoader() {
}

SDFLoader::SDFLoader(const SDFLoader& orig) {
}

SDFLoader::~SDFLoader() {
}

/**
 * Loads a scene file and reacts to the commands in it
 * @param scenefile the string to the file
 * @return 
 */
Scene SDFLoader::load(std::string const& scenefile) {
    std::cout << "Loading file: " << scenefile << std::endl;
    
    vector<Material> mvec;
    
    string line;
    ifstream file(scenefile);
    stringstream ss;
    //file.open(scenefile, ios::in);
    if (file.is_open()) {
        while (getline (file,line)){//get line
            ss = stringstream(line);//fill the line into stringstream
            string tmpString;
            ss >> tmpString;
            //is first string define?
            if (tmpString=="define"){
                cout << "defininig: ";
                
                ss >> tmpString;
                if (tmpString=="material"){
                    cout << "a material: "<<endl;
                    //extract name
                    string name;
                    ss>>name;

                    //extract color
                    int tmp1, tmp2, tmp3;
                    ss >> tmp1;
                    ss >> tmp2;
                    ss >> tmp3;
                    Color ca(tmp1, tmp2, tmp3);
                    ss >> tmp1;
                    ss >> tmp2;
                    ss >> tmp3;
                    Color cd(tmp1, tmp2, tmp3);
                    ss >> tmp1;
                    ss >> tmp2;
                    ss >> tmp3;
                    Color cs(tmp1, tmp2, tmp3);
                    float m;
                    ss >> m;
                    Material mat(ca, cd, cs,m, name);
                    cout << "Material specs: "<<endl<<mat;
                    mvec.push_back(mat);
                } else
                    cout << "object to define not implemented:"<<ss.str() <<endl;
            } else
                cout << "Line not supported:"<<line <<endl;
        }
        file.close();
    }else cout << "Unable to open file"; 
    
    return Scene(mvec); 
}



