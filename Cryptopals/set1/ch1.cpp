/*
    Cryptopals Challenge Template
    Author: Sourav Sharma
*/

#include <bits/stdc++.h>

void init_code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
}


static const std::string BASE64_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

//hex to bytes
unsigned char hexCharToInt(char c){
    if(c>='0' && c<='9') return c-'0';
    if(c>='a' && c<='f') return c-'a'+10;
    if(c>='A' && c<='F') return c-'A'+10;
    throw std::invalid_argument("Invalid hex character");
}

std::vector<unsigned char> hexToBytes(const std::string& hex){
    std::vector<unsigned char> bytes;
    for(size_t i=0; i<hex.length(); i+=2){
        unsigned char high = hexCharToInt(hex[i]);
        unsigned char low = hexCharToInt(hex[i+1]);
        bytes.push_back((high<<4) | low);
    }
    return bytes;
}

//bytes to base64
std::string bytesToBase64(const std::vector<unsigned char> &bytes){
    std::string result;
    int val = 0, valb = -6;

    for(unsigned char c:bytes){
        val = (val<<8)+c;
        valb+= 8;
        while(valb>=0){
            result.push_back(BASE64_CHARS[(val>>valb) & 0x3F]);
            valb -= 6;
        }
    }

    if(valb>-6)
        result.push_back(BASE64_CHARS[((val<<8) >> (valb+8)) & 0x3F]);

    while(result.size()%4)
        result.push_back('=');

    return result;
}

int main(){

    init_code();
 
    std::ios_base::sync_with_stdio(0); 
    std::cin.tie(NULL);

    std::string hex;
    std::cin >> hex;

    auto bytes = hexToBytes(hex);
    std::string base64 = bytesToBase64(bytes);
    std::cout << base64 << "\n";

    return 0; 
}



