#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    setlocale(LC_ALL, "rus"); // Может правда дело в этом?

    std::string line;

    std::ifstream in("dict.txt");

    string size;
    getline(in, size); // Получение первой строки
    size = size.substr(1); //убираем знак &
    string array[ stoi(size) ];
    int i = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            if (i > 0) {
                array[i] = line;
            }
            i++;
        }
    }
    in.close();

    



    return 0;
}