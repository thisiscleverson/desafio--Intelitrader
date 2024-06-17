#include <iostream>
using namespace std;


unsigned char encrypted_message[] = {
    0b10010110, 0b11110111, 0b01010110, 0b00000001, 0b00010111, 0b00100110, 0b01010111, 0b00000001, 
    0b00010111, 0b01110110, 0b01010111, 0b00110110, 0b11110111, 0b11010111, 0b01010111, 0b00000011
};


unsigned char invertLastTwoBits(unsigned char byte){
    return (byte ^ 0b00000011);
}


unsigned char swapFourBitChunks(unsigned char byte){
    return ((byte & 0b11110000) >> 4) | ((byte & 0b00001111) << 4);
}


void decrypt_message(unsigned char* encrypted_message, int length){
    
    for(int i=0; i < length; i++){
        encrypted_message[i] = swapFourBitChunks(invertLastTwoBits(encrypted_message[i]));
        cout << encrypted_message[i];
    }
    cout << "\n";
}


int main(){
    int length = sizeof(encrypted_message) / sizeof(encrypted_message[0]);

    decrypt_message(encrypted_message, length);

    return 0;
}

