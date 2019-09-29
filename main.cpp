#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void updateArraySize(string* p_array, int* size );
void print(string *word, string *antonym);

int main() {
    setlocale(LC_ALL, "rus"); // Может правда дело в этом?

    std::string line;

    std::ifstream in("dict.txt");

    string sizeSTR;
    getline(in, sizeSTR); // Получение первой строки
    sizeSTR = sizeSTR.substr(1); //убираем знак &
    const int size = stoi(sizeSTR);
    //string array[ size ];
    string *p_array = new string[size];
    int i = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            p_array[i] = line;
            i++;
        }
    }
    in.close();

    cout << "Введите слово: ";
    string word;
    cin >> word;

    for (int i = 0; i < size; i++)
    {
        cout << "Array: " << p_array[i] << endl;
        cout << "Len: " << p_array[i].length() << endl;
        cout << "Find word: " << p_array[i].find(word) << endl;

        if ( p_array[i].find(word) < p_array[i].length() ) // find почему-то если строка не соддержит word возвращает безумное занчение
        {
            int index = p_array[i].find(':'); // Разбиавем строку на два значения по разделителю
            string dict[2];
            dict[0] = p_array[i].substr(0, index);
            index++;
            dict[1] = p_array[i].substr(index);

            if (dict[0] == word)
            {
                print( &word, &dict[1]);
            } else {
                print( &word, &dict[0]);
            }
            break;
        }
    }
    delete[] p_array;
    return 0;
}

void print(string *word, string *antonym)
{
    cout << "Антоним к \"" << *word << "\" это слово \"" << *antonym << "\"" <<endl;
}