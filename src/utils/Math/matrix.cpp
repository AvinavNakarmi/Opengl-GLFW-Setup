#include "matrix.h"

float *Matrix::identity()
{
	float *mat = new float[16]{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1};
	return mat;
}