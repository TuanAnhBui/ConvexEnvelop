//
//  readFiles.hpp
//  matrixOperations
//
//  Created by Bui Anh Tuan on 8/14/18.
//  Copyright © 2018 Bui Anh Tuan. All rights reserved.
//

#ifndef readFiles_hpp
#define readFiles_hpp

#include <iostream>
#include <vector>
#include <math.h>
#include "dataTypes.h"
#include <string>
#include <fstream>

#include <sstream>
//#include "globalVars.h"

extern std::vector<std::vector <Cell>> newOrbit;
extern std::vector<std::vector <Cell>> cellBase;
extern Matrix<int> IdentityMat;
std::vector<std::vector<Cell>> readFiles(int n,int k,std::string path);

#endif /* readFiles_hpp */
