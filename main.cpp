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
    
    unsigned long N=cellList.size()-1;
    std::cout<<N<<std::endl;
    IdentityMat=cellList[N][0].matrix;
    Cell newCell;
    newCell.dim=0;
    newCell.orbit=1;
    newCell.matrix=IdentityMat;
    newCell.matrixInv=IdentityMat;
    newOrbit[0].push_back(newCell);
    Cell sigma=cellList[N][0];
    for (int i=0;i<cellList[N-1].size();++i)
        connectToCenter(cellList[N-1][i], sigma, cellList);

    for (int i=0;i<4;++i)
        std::cout<<newOrbit[i].size()<<"   ";
    
}
