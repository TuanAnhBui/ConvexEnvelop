//
//  various.cpp
//  ConvexEnvelop
//
//  Created by Bui Anh Tuan on 8/14/18.
//  Copyright © 2018 Bui Anh Tuan. All rights reserved.
//

#include "various.hpp"
extern std::vector<std::vector <Cell>> newOrbit;

std::vector<Matrix<int>> intersection(std::vector<Matrix<int>> &v1, std::vector<Matrix<int>> &v2)
{

    std::vector<Matrix<int>> v3;

    for (int i=0;i<v1.size();++i)
        if(std::find(v2.begin(),v2.end(),v1[i])!=v2.end()){
            v3.push_back(v1[i]);
        }
    return v3;
}
bool isSameOrbit(Cell tau_1,Cell tau_2,Cell sigma){
    Matrix<int> M,N;
    if ((tau_1.orbit!=tau_2.orbit)||(tau_1.dim!=tau_2.dim)) return false;
    else{
        for (int i=0;i<sigma.stabilizer.size();i++){
            
            N=tau_2.matrixInv*sigma.stabilizer[i];
            M=N*tau_1.matrix;
            if(std::find(tau_1.stabilizer.begin(),tau_1.stabilizer.end(),M)!=tau_1.stabilizer.end()){
                return true;
            }
        }
    }
    
    return false;
}
void connectToCenter(Cell tau,Cell sigma,std::vector<std::vector<Cell>> cellList){
    if(tau.dim==0){
        Cell new_cell;
        new_cell.dim=1;
        new_cell.boundary={};
        
        if (newOrbit[1].size()==0) newOrbit[0].push_back(tau);
        for (int i=0;i<newOrbit[0].size();++i)
            if(!isSameOrbit(tau, newOrbit[0][i], sigma)){
                newOrbit[0].push_back(tau);
            }
    }else{
        std::vector<int> bdr=tau.boundary;
        for (int i=0;i<bdr.size();i++)
            Cell newCell;
    }
}
