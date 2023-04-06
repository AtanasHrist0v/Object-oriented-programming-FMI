#include "Matrix.h"
#include <iostream>

void Matrix::copyFrom(const Matrix& other) {
	this->rows = other.rows;
	this->columns = other.columns;
	this->matrix = new int* [this->rows];

	for (size_t i = 0; i < this->rows; i++) {
		this->matrix[i] = new int[this->columns];
		for (size_t j = 0; j < this->columns; j++) {
			this->matrix[i][j] = other.matrix[i][j];
		}
	}
}
void Matrix::free() {
	for (size_t i = 0; i < this->rows; i++) {
		delete[] this->matrix[i];
		this->matrix[i] = nullptr;
	}
	delete[] this->matrix;
	this->matrix = nullptr;
	this->rows = 0;
	this->columns = 0;
}

Matrix::Matrix(unsigned rows, unsigned columns) {
	this->matrix = new int* [rows] {};
	for (size_t i = 0; i < rows; i++) {
		this->matrix[i] = new int[columns] {};
	}
}
Matrix::Matrix(const Matrix& other) {
	copyFrom(other);
}
Matrix& Matrix::operator=(const Matrix& other) {
	if (this != &other) {
		free();
		copyFrom(other);
	}

	return *this;
}
Matrix::~Matrix() {
	free();
}
Matrix& Matrix::operator+=(const Matrix& other) {
	if (this->rows != other.rows || this->columns != other.columns) {
		throw "Error";
	}

	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			this->matrix[i][j] += other.matrix[i][j];
		}
	}
	return *this;
}
Matrix& Matrix::operator-=(const Matrix& other) {
	*this *= -1;
	*this += other;
	return *this;
}
Matrix& Matrix::operator*=(const Matrix& other) {
	if (this->columns != other.rows) {
		throw "Error";
	}

	Matrix result(this->rows, other.columns);
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < other.columns; j++) {
			for (size_t k = 0; k < this->columns; k++) {
				result.matrix[i][j] += this->matrix[k][j] * other.matrix[j][k];
			}
		}
	}

	*this = result;
	//result.free();
	return *this;
}
Matrix& Matrix::operator*=(int number) {
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			this->matrix[i][j] *= number;
		}
	}
}
void Matrix::fill(const int* arr, unsigned arrSize) {
	if (this->rows * this->columns != arrSize) {
		return;
	}

	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			this->matrix[i][j] = arr[i + j];
		}
	}
}
void Matrix::print() const {
	for (size_t i = 0; i < this->rows; i++) {
		for (size_t j = 0; j < this->columns; j++) {
			std::cout << this->matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() 	{

}