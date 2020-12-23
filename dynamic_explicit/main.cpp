#include "proj.h"
#include <dlfcn.h>

using namespace std;

typedef void(*name_t)(int);

int main(int argc, char** argv) {
	void *libFirst;
	libFirst = dlopen("../library/liblabTenDyn.so", RTLD_LAZY);
	if(libFirst) {
		cout << "library is loaded!" << endl;
	} else {
		cout << "library is NOT loaded!" << endl;
		return -1;
	}

	int operation;
	int number;
	if (argc > 1) {
		operation = atoi(argv[1]);
		number = atoi(argv[2]);
	} else {
		cin >> operation;
		cin >> number;
	}

    if (!operation) {
        static_show_out(number);
    }
    else {
        static_show_sort(number);
    }
	dlclose(libFirst);

	return 0;
}
