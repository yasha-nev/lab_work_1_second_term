#include "patterns.h"

Pattern::Pattern(vector <string> *VT,vector <string> *VN, vector <string> *A, vector <string> *B)
{
    Vt = VT;
    Vn = VN;
    a = A;
    b = B;
}

int Pattern::Define_alphabet(string str, vector <string> *v)
{
    for (int i = 0; i < v->size(); i++){
        if (str == (*v)[i]) return 1;
	}
	return 0;
}

int Pattern::print_language(){
    cout << "vt" << endl;
    for (int i = 0; i < Vt->size(); i++) cout << &Vt[i] << " ";
    cout << endl;
    cout << "vn" << endl;
    for (int i = 0; i < Vn->size(); i++) cout << &Vn[i] << " ";
    cout << endl;
    cout << "a" << endl;
    for (int i = 0; i < a->size(); i++) cout << &a[i] << " ";
    cout << endl;
    cout << "b" << endl;
    for (int i = 0; i < b->size(); i++) cout << &b[i] << " ";
    cout << endl;
    return 0;
}

int Pattern::Search_alpha()
{
    return 1;
}

int Pattern::Search_beta()
{
    return 1;
}

int Pattern::Define_type()
{
    int t = 0;
    t += Search_alpha();
    t += Search_beta();
    if (t == 2) return 1;
    else return 0;
}

int Pattern_1::Search_alpha()
{
    for (int i = 0; i < (*a).size(); i++){
        for (int j = 0; j < (*a)[i].size(); j++){
            if (Define_alphabet((*a)[i].substr(j, 1), Vt) != 1 &&
                Define_alphabet((*a)[i].substr(j, 1), Vn) != 1)
                return 0;
        }
    }
    return 1;

}

int Pattern_1::Search_beta()
{
    for (int i = 0; i < b->size(); i++){
        for (int j = 0; j < (*b)[i].size(); j ++){
            if (Define_alphabet((*b)[i].substr(j, 1),Vt) != 1 &&
                Define_alphabet((*b)[i].substr(j, 1), Vn) != 1)
                return 0;
        }
    }
    return 1;
}

int Pattern_2::Search_alpha()
{
    //print_language();
    for (int i = 0; i < a->size(); i++){
        for (int j = 0; j < (*a)[i].size(); j ++){
            if (Define_alphabet((*a)[i].substr(j, 1), Vt) == 1 ||
                Define_alphabet((*a)[i].substr(j, 1), Vn) != 1)
                    return 0;
        }
    }
    return 1;
}

int Pattern_2::Search_beta()
{
    for (int i = 0; i < (*b).size(); i++){
        for (int j = 0; j < (*b)[i].size(); j ++){
            if (Define_alphabet((*b)[i].substr(j, 1),Vt) != 1 &&
                Define_alphabet((*b)[i].substr(j, 1) ,Vn) != 1)
                return 0;
        }
    }
    return 1;
}

int Pattern_3::Search_alpha()
{
    for (int i = 0; i < (*a).size(); i++){
        for (int j = 0; j < (*a)[i].size(); j ++){
            if ((Define_alphabet((*a)[i].substr(j, 1), Vn) != 1) ||
                (Define_alphabet((*a)[i].substr(j, 1), Vt) == 1))
                return 0;
        }
    }
    return 1;
}

int Pattern_3::Search_beta()
{
    if (Define_alphabet((*b)[0],Vt) == 0) return 0;

    for (int i = 1; i < (*b).size(); i++){
        if (Define_alphabet((*b)[i].substr(0, 1),Vt) == 0) return 0;
        for (int j = 1; j < (*b)[i].size(); j++){
            if (Define_alphabet((*b)[i],Vn) != 1)
                return 0;
        }
    }
    return 1;
}

int Pattern_4::Search_alpha()
{

    for (int i = 0; i < a->size(); i++){
        for (int j = 1; j < (*a)[i].size(); j++){
            if ((Define_alphabet((*a)[i].substr(j, 1),Vt) == 1) ||
                (Define_alphabet((*a)[i].substr(j, 1),Vn) != 1))
                return 0;
        }
    }
    return 1;
}

int Pattern_4::Search_beta()
{
    for (int i = 0; i < (*b).size() - 1; i++){
        if ((*b)[i].size() != 1){
            for (int j = 0; j < (*b)[i].size()-1; j++){
                if ((Define_alphabet((*b)[i].substr(j, 1),Vn) != 1) ||
                    (Define_alphabet((*b)[i].substr(j, 1),Vt) == 1))
                    return 0;
            }
        }
        if (Define_alphabet((*b)[i].substr((*b)[i].size() - 1, 1),Vt) == 0) return 0;
    }
    return 1;
}



