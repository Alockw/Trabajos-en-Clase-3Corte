#include<iostream>
#include<string>
using namespace std;
//funcion de hash de suma simple
unsigned int SimpleHash(const string& input){
    unsigned int hash=0;
    for (char c: input){
        hash += static_cast<unsigned int>(c);
    }
    return hash;
}
int main (){
    //datos de entreda
    string input="Hola mundo!";
    //calculas el hash
    unsigned int hashValue = SimpleHash(input);
    //mostrar el hash
    cout<<"datos de entrada: "<< input <<endl;
    cout<<"Valor hash: "<< hashValue <<endl;
    return 0;
    }