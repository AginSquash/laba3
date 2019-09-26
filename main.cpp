#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
    setlocale(LC_ALL, "rus"); // Может правда дело в этом?

    std::string line;

    std::ifstream in("dict.txt");

    string sizeSTR;
    getline(in, sizeSTR); // Получение первой строки
    sizeSTR = sizeSTR.substr(1); //убираем знак &
    const int size = stoi(sizeSTR);
    string array[ size ];
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

    cout << "Введите слово: ";
    string word;
    cin >> word;

    for (int i = 0; i < size; i++)
    {
        if ( array[i].find(word) < array[i].length() ) // find почему-то если строка не соддержит word возвращает безумное занчение
        {

        }
    }

    return 0;
}