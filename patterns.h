#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Pattern{
protected:
    vector <string> *Vt;
    vector <string> *Vn;
    vector <string> *a;
    vector <string> *b;

public:
    Pattern(){}
    Pattern(vector <string> *VT,vector <string> *VN, vector <string> *A,vector <string> *B);
    int Define_alphabet(string str, vector <string> *v);
    int Search_alpha();
    int Search_beta();
    int Define_type();
    int print_language();

};

class Pattern_1: public Pattern{

public:
    Pattern_1(vector <string> *VT,
              vector <string> *VN,
              vector <string> *A,
              vector <string> *B) : Pattern(VT, VN, A,B){}

    int Search_alpha();
    int Search_beta();

};

class Pattern_2: public Pattern
{
public:
    Pattern_2(vector <string> *VT,
              vector <string> *VN,
              vector <string> *A,
              vector <string> *B) : Pattern(VT, VN, A,B){}
    int Search_alpha();
    int Search_beta();

};

class Pattern_3: public Pattern
{
public:
    Pattern_3(vector <string> *VT,
              vector <string> *VN,
              vector <string> *A,
              vector <string> *B) : Pattern(VT, VN, A,B){}
    int Search_alpha();
    int Search_beta();

};

class Pattern_4: public Pattern
{
public:
    Pattern_4(vector <string> *VT,
              vector <string> *VN,
              vector <string> *A,
              vector <string> *B) : Pattern(VT, VN, A,B){}
    int Search_alpha();
    int Search_beta();

};



