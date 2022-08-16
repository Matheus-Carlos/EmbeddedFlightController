#ifndef UTILS_H
	#define UTILS_H

	float sat(float val, float min, float max);
	float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
	float strToFloat(char str[]);
	void copyFloatArray(float src[], float dst[], int len);

#endif // !UTILS_H