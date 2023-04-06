#pragma once

class Matrix {
private:
	int** matrix = nullptr;
	unsigned rows = 0;
	unsigned columns = 0;

	void copyFrom(const Matrix& other);
	void free();
public:
	Matrix(unsigned rows, unsigned columns);

	Matrix() = default;
	Matrix(const Matrix& other);
	Matrix& operator=(const Matrix& other);
	~Matrix();

	Matrix& operator+=(const Matrix& other);
	Matrix& operator-=(const Matrix& other);
	Matrix& operator*=(const Matrix& other);
	Matrix& operator*=(int number);

	void fill(const int* arr, unsigned arrSize);
	void print() const;
	

	//void setValue(unsigned rowIndex, unsigned columnIndex, int value);
};