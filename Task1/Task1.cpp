#include <iostream>
using namespace std;


string Big_Endian(char& num, int bytes)
{
    string outputResult;
    char* point;
    for (int i = bytes - 1; i >= 0; i--)
    {
        point = &num + i;
        for (int j = 7; j >= 0; j--) 
        {
            outputResult += ((*point >> j) & 1) ? '1' : '0';
        }
    }
    return outputResult;
    cout << endl;
}

string Little_Endian(char& num, int size) {
    string out;
    char* point;
    for (int i = 0; i < size; i++) {
        point = &num + i;
        for (int j = 7; j >= 0; j--) {
            out += ((*point >> j) & 1) ? '1' : '0';
        }
    }
    return out;
}


int main()
{
    cout << "Input your number: ";

    double numberDouble;
    cin >> numberDouble;

    int numberInt = int(numberDouble);
    float numberFloat = float(numberDouble);
    
    cout << "Int: " << endl;
    cout << "Big Endian: " + Big_Endian((char&)numberInt, sizeof(int)) << endl;
    cout << "Little Endian: " + Little_Endian((char&)numberInt, sizeof(int)) << endl;

    cout << "Float: " << endl;
    cout << "Big Endian: " + Big_Endian((char&)numberFloat, sizeof(float)) << endl;
    cout << "Little Endian: " + Little_Endian((char&)numberFloat, sizeof(float)) << endl;


    cout << "Double: " << endl;
    cout << "Big Endian: " + Big_Endian((char&)numberDouble, sizeof(double)) << endl;
    cout << "Little Endian: " + Little_Endian((char&)numberDouble, sizeof(double)) << endl;
}

