#include "proj.h"
#include <dlfcn.h>

using namespace std;

typedef void(*name_t)(int);

int main(int argc, char** argv) {
	void *libFirst;
	libFirst = dlopen("../library/liblabTenDyn.so", RTLD_LAZY);
	if(libFirst == 0) {
		cout << "libdyn.so is NOT loaded!" << endl;
		return -1;
	} else {
		cout << "libdyn.so is loaded!" << endl;
	}

	name_t nameOut;
	nameOut = (name_t)dlsym(libFirst, "nameOutput");
	(*nameOut)(5);

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
