#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isAnswered = false;
string *updateArraySize(string* p_array, int *size );
void print(string *word, string *antonym);

int main() {

    setlocale(LC_ALL, "rus"); // Строка в память о тех, кто пользуется виндой (F)

    std::string line;
    std::ifstream in("dict.txt");

    int size = 4;

    string *p_array = new string[size];
    int i = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            if ( i == size )
            {
#ifdef DEBUG
                cout << "Массив будет перегружен, вызов updateArray" << endl;
#endif
                p_array = updateArraySize(p_array, & size);

            }
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
#ifdef DEBUG
        cout << "I: " << i << endl;
        cout << "Array: " << p_array[i] << endl;
        cout << "Len: " << p_array[i].length() << endl;
        cout << "Find word: " << p_array[i].find(word) << endl << endl << endl;
#endif
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
    if (!isAnswered)
    {
        cout << "К сожалению, этого слова нет в словаре." << endl;
    }
    delete[] p_array;
    return 0;
}

void print(string *word, string *antonym)
{
    cout << "Антоним к \"" << *word << "\" это слово \"" << *antonym << "\"." <<endl;
    isAnswered = true;
}

string *updateArraySize(string* p_array, int *size )
{
    *size *= 2;
    string *p_new_array = new string[ *size ];
    for (int i = 0; i < (*size/2); i++)
    {
        p_new_array[i] = p_array[i];
    }
#ifdef DEBUG
    cout << "Массив обновлен, новый рамзер: " << *size << endl;
#endif
    delete[] p_array;
    return p_new_array;
}