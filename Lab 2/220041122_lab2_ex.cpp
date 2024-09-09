#include <iostream>

using namespace std;

int func(const int& par1, char& par2){


//    par1++;
    cout<<"inside func: par1 - "<<par1<<" par2 - "<<par2<<endl;
    return 2;

}



int main()
{
//    char dummy;
//    int a,b,c,d, numerator, denominator;
//    cout << "Enter 1st fraction: ";
//    cin >> a >>dummy>> b;
//    cout << "Enter 2nd fraction: ";
//    cin >> c >>dummy>> d;
//    numerator=a*d+c*b;
//    denominator=b*d;
//    cout << "Sum is: " << numerator <<"/"<<denominator <<endl;
//    return 0;

    int a=55;
    char b='e';
    int d=func(a, b);
    cout<<d<<endl;
    return 0;

}
