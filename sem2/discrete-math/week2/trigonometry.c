#include <stdio.h>
#include <math.h>

int main() {
	double angle_degrees = 30.0;
	// sin() accepts radians
	// 1 degree = PI/180deg
	double sin_value = sin(angle_degrees * (M_PI / 180.0));
	printf("Nilai sinus dari %.2f derajat adalah: %.4f\n", angle_degrees, sin_value);
}
