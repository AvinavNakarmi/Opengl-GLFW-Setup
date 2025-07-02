#include "matrix.h"

float* Matrix::identity()
{
	float mat[16] = {
	1,0,0,0,
	0,1,0,0,
	0,0,1,0,
	0,0,0,1
	};
	return mat;
}