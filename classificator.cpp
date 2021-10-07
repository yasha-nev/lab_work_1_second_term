#include "classificator.h"

Classificator::~Classificator(){
    delete Vt;
    delete Vn;
    delete a;
    delete b;

}
Classificator::Classificator(vector <string> *vt, vector <string> *vn, vector <string> *A, vector <string> *B ){
    Vt = vt;
    Vn = vn;
    a = A;
    b = B;
}

int Classificator::Define_type()
{

    Pattern p(Vt, Vn, a, b);
    Pattern_1 p1(Vt, Vn, a, b);
    Pattern_2 p2(Vt, Vn, a, b);
    Pattern_3 p3(Vt, Vn, a, b);
    Pattern_4 p4(Vt, Vn, a, b);
    if (p4.Search_alpha() == 1 && p4.Search_beta() == 1)return 4;
    else if (p3.Search_alpha() == 1 && p3.Search_beta() == 1) return 3;
    else if (p2.Search_alpha() == 1 && p2.Search_beta() == 1) return 2;
    else if (p1.Search_alpha() == 1 && p1.Search_beta() == 1) return 1;
    else if (p.Search_alpha() == 1 && p.Search_beta() == 1) return 0;
    else return -1;
}
