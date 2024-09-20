#include <iostream>
using namespace std;
#include<string.h>


int main(){
    string s;
    cout<<":";
    cin >> s;
    int len=s.length()-1;
    int i;
    for(i=0;i<len/2;i++){
        char temp;
        temp=s[i];
        s[i]=s[len-i];
        s[len-i]=temp;
    }
    cout << s << endl;

}