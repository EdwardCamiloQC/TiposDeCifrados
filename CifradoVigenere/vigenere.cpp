#include "vigenere.h"

Vigenere :: Vigenere(const char* alphabet, unsigned size){
    sizeAlphabet = size;
    pAlphabet = new char[size];
    for(unsigned i = 0; i < sizeAlphabet; i++){
        *pAlphabet = *alphabet;
        pAlphabet++;
        alphabet++;
    }
    pAlphabet = pAlphabet - size;
}

void Vigenere :: cifrar(const char* message, const char* password, unsigned size){
    unsigned int numMensaje[size];
    unsigned int numClave[size];
    int aux;
    for(int i = 0; i < size; i++){
        for (int j = 0; j < sizeAlphabet; j++){
            if(*message == *pAlphabet){
                numMensaje[i] = j;
            }
            if(*password == *pAlphabet){
                numClave[i] = j;
            }
            pAlphabet++;
        }
        message++;
        password++;
        pAlphabet = pAlphabet - sizeAlphabet;
    }
    for(int i = 0; i < size; i++){
        aux = (int)(fmod(numMensaje[i] + numClave[i], sizeAlphabet));
        pAlphabet = pAlphabet + aux;
        std :: cout << *pAlphabet;
        pAlphabet = pAlphabet - aux;
    }
    std :: cout << std :: endl;
}

void Vigenere :: desifrar(const char* encryption, const char* password, unsigned size){
    int aux;
    int numCifrado[size];
    int numClave[size];
    for(int i = 0; i < size; i++){
        for (int j = 0; j < sizeAlphabet; j++){
            if(*encryption == *pAlphabet){
                numCifrado[i] = j;
            }
            if(*password == *pAlphabet){
                numClave[i] = j;
            }
            pAlphabet++;
        }
        encryption++;
        password++;
        pAlphabet = pAlphabet - sizeAlphabet;
    }
    for(int i = 0; i < size; i++){
        if(numCifrado[i] - numClave[i] >= 0){
            aux = (int)(fmod(numCifrado[i] - numClave[i], sizeAlphabet));
            pAlphabet = pAlphabet + aux;
            std :: cout << *pAlphabet;
        }else if(numCifrado[i] - numClave[i] < 0){
            aux = (int)(fmod(numCifrado[i] - numClave[i] + sizeAlphabet, sizeAlphabet));
            pAlphabet = pAlphabet + aux;
            std :: cout << *pAlphabet;
        }
        pAlphabet = pAlphabet - aux;
    }
    std :: cout << std :: endl;
}

Vigenere :: ~Vigenere(){
    delete [] pAlphabet;
}
