// I Malia Kuykendall certify that this programming assignment reflects my own work,
// without the use of any external individuals (other than course/department staff ), generative-AI,
// or any other forbidden resources. I understand/accept the consequences of cheating as outlined
// in the course syllabus.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float mean(float arr [], int size) {
	int index = 0;
	float mean = 0.0;
	for (index = 0; index < size; index++) {
		mean += arr[index];
	}
	mean = round((mean/size) * 1000) / 1000;

	return mean;
}

float median(float arr[], int size) {
	int x;
	float finalMedian;
	if (size % 2 == 0) {
		float bottomHalf = arr[size/2 - 1];
		float topHalf = arr[(size/2)];
		finalMedian = (bottomHalf+topHalf)/2;
		finalMedian = round(finalMedian * 1000) / 1000;
	}
	if (size % 2 == 1) {
		x = size / 2;
		finalMedian = arr[x];
	}

	return finalMedian;
}

float mode(float arr[], int size) {
	float mode = -1;
	int highestOccurence = 1;

	int i;
	int j;
	for (i = 0; i < size; i++) {
		int occurences = 1;
		float check = arr[i];
		for (j = i+1; j < size; j++) {
			if (check == arr[j]) {
				occurences++;
			}
		}

		if (occurences > highestOccurence) {
			highestOccurence = occurences;
			mode = check;
		}
		else if (occurences == highestOccurence && occurences > 1) {
			mode = -1;
		}
	}

	return mode;
}

float std_dev(float arr[], int size) {
	float standardDeviation = 0;
	float squaredDifference = 0;

	int i;
	for (i = 0; i < size; i++) {
		squaredDifference = (arr[i] - mean(arr, size));
		squaredDifference = squaredDifference * squaredDifference;
		standardDeviation += squaredDifference;
	}

	standardDeviation = sqrt(standardDeviation/size);
	standardDeviation = round(standardDeviation * 1000) / 1000;
	return standardDeviation;
}

int * rounded_vals(float arr [], int size) {

	int roundedArr[size];
	int i;
	for (i = 0; i < size; i++) {
		roundedArr[i] = round(arr[i]);
	}

	return roundedArr;
}


char * ascii(float arr [], int size) {
	char asciiArr[size];
	int i;
	int roundedVal;
	for (i = 0; i < size; i++) {
		roundedVal = round(arr[i]);

		if (roundedVal >= 32 && roundedVal < 127) {
			char charVal = (char) roundedVal;
			asciiArr[i] = charVal;
		}
		else {
			asciiArr[i] = '*';
		}
	}

	return asciiArr;
}

int main(int argc, char * argv[ ] ) {
	int size = argc - 1;
	float arr[size];

	int index = 0;
	for (index = 0; index < size; index++) {
		arr[index] = atof(argv[index + 1]);
	}

	printf("%.3f\n", mean(arr,size));
	printf("%.3f\n", median(arr,size));
	printf("%.3f\n", mode(arr,size));
	printf("%.3f\n", std_dev(arr,size));
	rounded_vals(arr,size);
	ascii(arr,size);

	return 0;
}
