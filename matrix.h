#ifndef _MATRIX
#define _MATRIX

#include<iostream>
#include<vector>

using std::vector;
using std::cout;
using std::pair;
using std::invalid_argument;

class Matrix{
	int rows,cols;
	vector<vector<double>> mat;
	
public:
	Matrix(int,int,double);

	void print();
	void transpose();
	vector<double> diagonal();

	pair<int,int> size(){
		return {rows,cols};
	}

	double at(int x,int y){
		return mat[x][y];
	}

	double operator()(int x,int y){
		return mat[x][y];
	}

	void set(int x,int y,int val){
		mat[x][y]=val;
	}


	Matrix add(Matrix &, Matrix &);
	Matrix sub(Matrix &, Matrix &);
	Matrix mul(Matrix &, Matrix &);

	Matrix mul(double);
	Matrix div(double);

	Matrix operator+( Matrix&);
	Matrix operator-( Matrix&);
	Matrix operator*( Matrix&);

	Matrix operator*(double);
	Matrix operator/(double);

};


Matrix::Matrix(int r=0,int c=0,double val=0){
	rows=r,cols=c;
	for(int i=0;i<r;i++){
		vector<double> row(c,val);
		mat.push_back(row);
	}
}

void Matrix::print(){

	for(auto row:mat){

		for(auto elt:row)
			cout<<elt<<" ";

		cout<<"\n";
	}
}

vector<double> Matrix::diagonal(){
	vector<double> dia;
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<cols;j++){
			if(i==j)
				dia.push_back(mat[i][j]);
		}
	}
	return dia;
}

Matrix Matrix::add(Matrix & A, Matrix & B){

	if(A.rows != B.rows || A.cols!= B.cols){
		throw invalid_argument("matrix size should be same");
	}
	Matrix C(A.rows,A.cols);

	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			C.mat[i][j]=A.mat[i][j]+B.mat[i][j];
	
	return C;
}

Matrix Matrix::sub(Matrix & A, Matrix & B){
	if(A.rows != B.rows || A.cols!= B.cols){
		throw invalid_argument("matrix size should be same");
	}
	Matrix C(A.rows,A.cols);

	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			C.mat[i][j]=A.mat[i][j]-B.mat[i][j];
	
	return C;
}

Matrix Matrix::mul(Matrix & A, Matrix & B){

	if(A.cols != B.rows){
		throw invalid_argument("number of columns of the 1st matrix must equal to the number of rows of the 2nd matrix");
	}
	Matrix C(A.rows,B.cols);
	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			for(int k=0;k<A.cols;k++)
				C.mat[i][j]+= A.mat[i][k]*B.mat[k][j];

	return C;
}

void Matrix::transpose()
{
	Matrix trans(cols,rows);

	for (int i=0; i < rows; ++i)
		{
			for (int j=0; j < cols; ++j)
			{
				trans.mat[j][i] = mat[i][j];
			}
		}
	*this=trans;
}


Matrix Matrix::operator+(Matrix & A){

	if(A.rows != rows || A.cols!= cols){
		throw invalid_argument("matrix size should be same");
	}
	Matrix C(A.rows,A.cols);

	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			C.mat[i][j]=A.mat[i][j]+mat[i][j];
	
	return C;
}

Matrix Matrix::operator-(Matrix & A){

	if(A.rows != rows || A.cols!= cols){
		throw invalid_argument("matrix size should be same");
	}
	Matrix C(A.rows,A.cols);

	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			C.mat[i][j]=mat[i][j]-A.mat[i][j];
	
	return C;
}

Matrix Matrix::operator*(Matrix & A){

	if(cols != A.rows){
		throw invalid_argument("number of columns of the 1st matrix must equal to the number of rows of the 2nd matrix");
	}
	Matrix C(rows,A.cols);
	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			for(int k=0;k<cols;k++)
				C.mat[i][j]+= mat[i][k]*A.mat[k][j];

	return C;
}

Matrix Matrix::operator*(double val){

	Matrix C(rows,cols);
	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			C.mat[i][j]= mat[i][j]*val;

	return C;
}

Matrix Matrix::operator/(double val){
	if(val == 0){
		throw invalid_argument("division by 0 is not allowed");
	}

	Matrix C(rows,cols);
	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			C.mat[i][j]= mat[i][j]/val;

	return C;
}


Matrix Matrix::mul(double val){
	Matrix C(rows,cols);
	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			C.mat[i][j]= mat[i][j]*val;

	return C;
}

Matrix Matrix::div(double val){
	Matrix C(rows,cols);
	for(int i=0;i<C.rows;i++)
		for(int j=0;j<C.cols;j++)
			C.mat[i][j]= mat[i][j]/val;

	return C;
}






#endif