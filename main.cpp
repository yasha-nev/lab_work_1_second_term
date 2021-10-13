#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include "classificator.h"

using namespace std;
vector <string> ReadString(fstream &file);

int main(int argc, char *argv[]){
	if (argc < 2){
		return 0;
	}
	vector <string> vn, vt, r, a, b;

	fstream file(argv[1], ios_base::in);
	vt = ReadString(file);
	vn = ReadString(file);
	r = ReadString(file);

	for (int i = 0; i < r.size(); i++){
        if (i%2 == 0) a.push_back(r[i]);
        else b.push_back(r[i]);
	} cout << endl;

	file.close();

    Classificator cls(&vt, &vn, &a, &b);
    int type = cls.Define_type();

    switch(type)
    {
        case(0):
            cout << "Unrestricted Grammar (type 0)" << endl;
            break;

        case(1):
            cout << "Context-Sensitive grammar (type 1)" << endl;
            break;

        case(2):
            cout << "Context-Free Grammar (type 2)" << endl;
            break;

        case(3):
            cout << "Regular Grammar Left (type 3)" << endl;
            break;

        case(4):
            cout << " Regular Grammar Right (type 3)" << endl;
            break;

	 case(-1):
            cout << "no type Grammar" << endl;
            break;
    }


	return 0;
}

vector <string> ReadString(fstream &file){
	int n;
	string t;
	vector <string> str;
	file >> n;
	for (int j = 0; j < n; j++){
		file >> t;
		str.push_back(t);
	}
	return str;
}
