#include "proj.h"

using namespace std;

int main(int argc, char** argv) {
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

	return 0;
}
