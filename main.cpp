//
//  main.cpp
//  matrixOperations
//
//  Created by Bui Anh Tuan on 8/12/18.
//  Copyright © 2018 Bui Anh Tuan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
#include "dataTypes.h"
#include <string>
#include <fstream>
//#include "globalVars.h"
#include <sstream>
#include "readFiles.hpp"
#include "various.hpp"

std::vector<std::vector <Cell>> newOrbit;
std::vector<std::vector <Cell>> cellBase;
Matrix<int> IdentityMat;
//#include "readFiles.h"


int main() {
    const std::string path="/Users/buianhtuan/Documents/ouputGAP/";
    std::vector<std::vector <Cell>> cellList,Orbit;
    cellList=readFiles(3, 1, path);
    
//    for (int i=0;i<cellList.size();++i){
//        std::vector<Cell> v={};
//        Orbit.push_back(v);
//    }
    unsigned long N=cellList.size()-1;
    IdentityMat=cellList[N][0].matrix;
    
    Cell sigma=cellList[N][0];
    Cell tau;

    tau=connectToCenter(cellList[0][0], sigma, cellList);
    tau.display();
    std::cout<<newOrbit[0].size();
}
