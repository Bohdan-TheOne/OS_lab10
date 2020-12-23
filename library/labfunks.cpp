#include "labfunks.h"

using namespace std;

void nameOutput(int num) {
	cout << "Not Sycn thread" << endl;
	for (int i = 0; i < num; ++i) {
		cout << "Bohdan ";
		cout << "Chepeliuk ";
		cout << "63253452" << endl;
	}
}

void mergeSort(int* arr, long n) {
    if (!arr) {
        return;
    }
    if (n > 1) {
        long splitPoint = n / 2;
        long lN = splitPoint, rN = n - splitPoint;
        long k = 0;

        int* subArrL = new int[lN];
        int* subArrR = new int[rN];
        for (long i = 0; i < lN; ++i, ++k) {
            subArrL[i] = arr[k];
        }
        for (long j = 0; j < rN; ++j, ++k) {
            subArrR[j] = arr[k];
        }

        mergeSort(subArrL, lN);
        mergeSort(subArrR, rN);

        long i, j;
        i = j = k = 0;
        while (i < lN && j < rN) {
            if (subArrL[i] < subArrR[j]) {
                arr[k] = subArrL[i];
                ++i;
            }
            else {
                arr[k] = subArrR[j];
                ++j;
            }
            ++k;
        }

        while (i < lN) {
            arr[k] = subArrL[i];
            ++i;
            ++k;
        }
        while (j < rN) {
            arr[k] = subArrR[j];
            ++j;
            ++k;
        }
        delete[] subArrL;
        delete[] subArrR;
    }
}

