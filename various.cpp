//
//  various.cpp
//  ConvexEnvelop
//
//  Created by Bui Anh Tuan on 8/14/18.
//  Copyright © 2018 Bui Anh Tuan. All rights reserved.
//

#include "various.hpp"
extern std::vector<std::vector <Cell>> newOrbit;
extern std::vector<std::vector <Cell>> cellBase;
extern Matrix<int> IdentityMat;

std::vector<Matrix<int>> intersection(std::vector<Matrix<int>> &v1, std::vector<Matrix<int>> &v2)
{

    std::vector<Matrix<int>> v3;

    for (int i=0;i<v1.size();++i)
        if(std::find(v2.begin(),v2.end(),v1[i])!=v2.end()){
            v3.push_back(v1[i]);
        }
    return v3;
}
Matrix<int> isSameOrbit(Cell tau_1,Cell tau_2,Cell sigma){
    Matrix<int> M,N;
    if ((tau_1.orbit!=tau_2.orbit)||(tau_1.dim!=tau_2.dim)) return M;
    else{
        for (int i=0;i<sigma.stabilizer.size();i++){
            
            N=tau_2.matrixInv*sigma.stabilizer[i];
            M=N*tau_1.matrix;
            if(std::find(tau_1.stabilizer.begin(),tau_1.stabilizer.end(),M)!=tau_1.stabilizer.end()){
                return sigma.stabilizer[i];
            }
        }
    }
    
    return M;
}
Cell connectToCenter(Cell tau,Cell sigma,std::vector<std::vector<Cell>> cellList){
    if(tau.dim==0){
        
        if (cellBase[0].size()==0){
            Cell newCell;
            newCell.dim=1;
            newCell.orbit=1;
            newCell.boundary.push_back(tau);
            newCell.boundary.push_back(newOrbit[0][0]);
            newCell.matrix=IdentityMat;
            newCell.matrixInv=IdentityMat;
            newCell.stabilizer=intersection(tau.stabilizer, sigma.stabilizer);
            newOrbit[1].push_back(newCell);
            cellBase[0].push_back(tau);
            
            return newCell;
        }else{
            for (int i=0;i<cellBase[0].size();++i){
                Matrix<int> M=isSameOrbit(tau, newOrbit[0][i], sigma);
                
                if (M.ncol!=0){
                    Cell newCell;
                    newCell.dim=1;
                    newCell.orbit=i+1;
                    newCell.boundary.push_back(tau);
                    newCell.boundary.push_back(newOrbit[0][0]);
                    newCell.matrix=IdentityMat;
                    newCell.matrixInv=IdentityMat;
                    newCell.stabilizer=intersection(tau.stabilizer, sigma.stabilizer);
                    newOrbit[1].push_back(newCell);
                    cellBase[0].push_back(tau);
                    return newCell;
                }
            }
        }

    }else{
        std::vector<Cell> bdr=tau.boundary;
        for (int i=0;i<bdr.size();i++)
            Cell newCell;
    }
    return tau;
}
