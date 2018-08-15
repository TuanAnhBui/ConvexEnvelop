//
//  various.hpp
//  ConvexEnvelop
//
//  Created by Bui Anh Tuan on 8/14/18.
//  Copyright © 2018 Bui Anh Tuan. All rights reserved.
//

#ifndef various_hpp
#define various_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
#include "dataTypes.h"


std::vector<Matrix<int>> intersection(std::vector<Matrix<int>> &v1, std::vector<Matrix<int>> &v2);
bool isSameOrbit(Cell,Cell,Cell);
void connectToCenter(Cell tau,Cell sigma,std::vector<std::vector<Cell>> cellList);


#endif /* various_hpp */
