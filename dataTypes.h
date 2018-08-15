//
//  operators.h
//  matrixOperations
//
//  Created by Bui Anh Tuan on 8/12/18.
//  Copyright © 2018 Bui Anh Tuan. All rights reserved.
//

#ifndef operators_h
#define operators_h
#include <sstream>


template <typename T>
class Matrix {
    // implementation
    int col, row;
    typedef std::vector<T> Row;
    
    std::vector<Row> data;
    
public: // interface
    Matrix(): Matrix(1,1) {}
    Matrix(int r, int c): row(r), col(c), data(r, std::vector<T>(c)) {}
    
    int nrow=row;
    int ncol=col;
    
    // allow to use matrix[i][j]
    Row & operator[](int i) {
        return data[i];
    }
    
    void init(std::vector<T> vec){
        for (int i=0;i<nrow;++i)
            for (int j=0;j<ncol;++j)
                data[i][j]=vec[i*ncol+j];
            
    };
    void display(){
        for (int i=0;i<nrow;++i){
            for (int j=0;j<ncol;++j){
                std::cout<<data[i][j]<<"  ";
            }
            std::cout<<std::endl;
        }
    }
    Matrix<T> operator * (const Matrix<T> &right)
    {
        Matrix<T> P(nrow,right.ncol);
        for (int i=0;i<P.nrow;++i)
            for (int j=0;j<P.ncol;++j){
                P.data[i][j]=0;
                for (int k=0;k<ncol;++k)
                    P.data[i][j]+=data[i][k]*right.data[k][j];
            }
        return P;
    }
    
    bool operator == (const Matrix<T> &right)
    {
        if((nrow!=right.nrow)||(ncol!=right.ncol)) return false;
        for (int i=0;i<nrow;++i)
            for (int j=0;j<ncol;++j){
                if(data[i][j]!=right.data[i][j]) return false;
            }
        return true;
    }
};



class Cell{
    int d;
    int orb;
    std::vector<Matrix<int>> stab;
    Matrix<int> matInv;
    Matrix<int> mat;
    std::vector<int> bdr;
public:
    Cell(): d(0),orb{0},stab{},mat(1,1),bdr{}{};
    int dim=d;
    int orbit=orb;
    std::vector<Matrix<int>> stabilizer=stab;
    Matrix<int> matrixInv=matInv;
    Matrix<int> matrix=mat;
    std::vector<int> boundary=bdr;
    
    void init(std::string V){
        std::vector<int> vect;
        
        std::stringstream ss(V);
        
        int i;
        
        while (ss >> i)
        {
            vect.push_back(i);
            if (ss.peek() == ',' || ss.peek()==' ')
                ss.ignore();
        }
        orbit=vect[0];
        
        vect.erase(vect.begin());
        int d=sqrt(vect.size());
        Matrix<int> M(d,d);
        M.init(vect);
        matrix=M;
    }
    void display(){
        std::cout<<"Dimension: "<<dim<<std::endl;
        std::cout<<"In the "<<orbit<<"th orbit"<<std::endl;
        std::cout<<"Cells in the boundary: "<<std::endl;
        for (int i=0;i<boundary.size();++i)
            std::cout<<boundary[i]<<"  ";
        std::cout<<std::endl;
        std::cout<<"Elements of Stabilizer:"<<std::endl;
        for (int i=0;i<stabilizer.size();++i){
            stabilizer[i].display();
            std::cout<<std::endl;
        }
        
        std::cout<<"Group element: "<<std::endl;
        matrix.display();
        
        std::cout<<"Inverse of group element: "<<std::endl;
        matrixInv.display();
    }
};
#endif /* operators_h */
