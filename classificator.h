#include <iostream>
#include <string.h>
#include <vector>
#include "patterns.h"

using namespace std;

class Classificator
{
	private:
		vector <string> *Vt;
		vector <string> *Vn;
		vector <string> *a;
		vector <string> *b;

	public:
	Classificator(){}
	~Classificator();
    Classificator(vector <string> *VT,
                  vector <string> *VN,
                  vector <string> *A,
                  vector <string> *B);

    int Define_type();
};
