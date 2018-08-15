//
//  readFiles.cpp
//  matrixOperations
//
//  Created by Bui Anh Tuan on 8/14/18.
//  Copyright © 2018 Bui Anh Tuan. All rights reserved.
//

#include "readFiles.hpp"


using namespace std;

std::vector<std::vector<Cell>> readFiles(int n,int m,std::string path){
    
    //  Read file from hard disk
//    const string path="/Users/buianhtuan/Documents/ouputGAP/";
    const string listOfcells=path+"listOfCellsIn"+to_string(m)+"thOf"+to_string(n)+"-cells.txt";
    ifstream inCells(listOfcells);
    
    // Check if the file is opening
    if(!inCells)
    {
        std::cerr << "Cannot open the File : "<<listOfcells<<std::endl;
        exit(0);
    }
    
    //  Createa list of Ncells by reading line by line on file and convert them to Cell structure.
    //  cellList[i] is the list of i-cells.
    vector<vector <Cell>> cellList;
    string line;
    getline(inCells,line);
    getline(inCells,line);
    Cell cell;
    vector<Cell> Ncells;
    while (!inCells.eof()){
        
        getline(inCells,line);
        
        if (!(line.size()==0)){
            line.erase(line.begin());
            line.pop_back();
            cell.init(line);
            Ncells.push_back(cell);
        }
        else{
            cellList.push_back(Ncells);
            Ncells.clear();
        }
    }
    
    //  Read the file containing boundaries information
    const string listOfbdr=path+to_string(m)+"thOf"+to_string(n)+"-cellsBeforeEnveloping.txt";
    ifstream inBdr(listOfbdr);
    if(!inBdr)
    {
        std::cerr << "Cannot open the File : "<<listOfbdr<<std::endl;
        exit(0);
    }
    getline(inBdr,line);
    getline(inBdr,line);
    int i(0);
    int j(0);
    vector<int> bdr;
    
    while(!inBdr.eof()){
        getline(inBdr,line);
        if (!(line.size()==0)){
            line.pop_back();
            line.erase(line.begin());
            std::stringstream ss(line);
            
            int k;
            
            while (ss >> k)
            {
                bdr.push_back(k);
                if (ss.peek() == ',' || ss.peek()==' ')
                    ss.ignore();
            }
            
            //          Update the boundary information for the jth of i-cell
            if (i>0){
                for (int s=0;s<bdr.size();++s)
                    cellList[i][j].boundary.push_back(cellList[i-1][bdr[s]-1]);
            }
            j++;
            bdr.clear();
        }else{
            i++;
            j=0;
            bdr.clear();
        }
        
        
    }
    
    //  Read the file containing stabilizer information
    const string listOfstab=path+to_string(m)+"thOf"+to_string(n)+"-stabilizersBeforeEnvoloping.txt";
    ifstream inStab(listOfstab);
    if(!inStab)
    {
        std::cerr << "Cannot open the File : "<<listOfstab<<std::endl;
        exit(0);
    }
    getline(inStab,line);
    getline(inStab,line);
    
    i=0;
    j=0;
    int count=0;
    
    vector<Matrix<int>> stab;
//    Matrix<int> M(6,6);
    vector<int> vect;
    
    while(!inStab.eof()){
        getline(inStab,line);
        if (!(line.size()==0)){
            count=0;
            line.pop_back();
            line.erase(line.begin());
            std::stringstream ss(line);
            
            int k;
            
            while (ss >> k)
            {
                vect.push_back(k);
                if (ss.peek() == ',' || ss.peek()==' ')
                    ss.ignore();
            }
            int d=sqrt(vect.size());
            Matrix<int> M(d,d);
            M.init(vect);
            stab.push_back(M);
            vect.clear();
        }else{
            count++;
            
            if (count==1){
                cellList[i][j].stabilizer=stab;
                
                stab.clear();
                vect.clear();
                j++;
            }else{
                if(count==2){
                    i++;
                    j=0;
                }
            }
            
        }
        
        
    }
    
//  Read the file containing inverse matrix element information
    const string listOfinverse=path+"1thOf3-elmInv-BeforeEnvoloping.txt";

//    const string listOfinverse=path+to_string(m)+"thOf"+to_string(n)+"-elmInv-BeforeEnvoloping.txt";
    ifstream inInverse(listOfinverse);
    if(!inInverse)
    {
        std::cerr << "Cannot open the File : "<<listOfinverse<<std::endl;
        exit(0);
    }
    getline(inInverse,line);
    getline(inInverse,line);
    
    i=0;
    j=0;

    
    vect.clear();
    
    while(!inInverse.eof()){
        getline(inInverse,line);
        if (!(line.size()==0)){
            line.pop_back();
            line.erase(line.begin());
            std::stringstream ss(line);
            
            int k;
            
            while (ss >> k)
            {
                vect.push_back(k);
                if (ss.peek() == ',' || ss.peek()==' ')
                    ss.ignore();
            }
            vect.erase(vect.begin());
            int d=sqrt(vect.size());
            Matrix<int> M(d,d);
            M.init(vect);
            
            cellList[i][j].matrixInv=M;
            cellList[i][j].dim=i;
//            cellList[i][j].matrix.display();
            vect.clear();
            j++;
        }else{
            i++;
            j=0;
            }
        
    }
    for (int i=0;i<cellList.size();++i){
        std::vector<Cell> v={};
        newOrbit.push_back(v);
        cellBase.push_back(v);
    }

    return cellList;
}

