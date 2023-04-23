#ifndef _VIGENERE_H_
    #define _VIGENERE_H_

    #include <iostream>
    #include <math.h>

    class Vigenere{
        private:
            unsigned int ref, sizeAlphabet;
            char* pAlphabet;
        public:
            Vigenere(const char* alphabet, unsigned size);
            void cifrar(const char* message, const char* password, unsigned size);
            void desifrar(const char* encryption, const char* password, unsigned size);
            ~Vigenere();
    };
#endif