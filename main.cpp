#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string *updateArraySize(string* p_array, int *size );
void print(string *word, string *antonym);

int main() {
    setlocale(LC_ALL, "rus"); // Строка в память о тех, кто пользуется виндой (F to pay respect)

    std::string line;

    std::ifstream in("dict.txt");

    //string sizeSTR;
    //getline(in, sizeSTR); // Получение первой строки
    //sizeSTR = sizeSTR.substr(1); //убираем знак &

    //int size = stoi(sizeSTR);

    int size = 2;

    //string array[ size ];
    string *p_array = new string[size];
    int i = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            if (size == i + 1 )
            {
                p_array = updateArraySize(p_array, & size);
            }
            cout << "Присваивание line" << endl;
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
        cout << "I: " << i << endl;
        cout << "Array: " << p_array[i] << endl;
        cout << "Len: " << p_array[i].length() << endl;
        cout << "Find word: " << p_array[i].find(word) << endl << endl << endl;

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

string *updateArraySize(string* p_array, int *size )
{
    cout << "Обновление массива запущенно" << endl;
    *size *= 2;
    string *p_new_array = new string[ *size ];
    cout << "Создан массив с размером: " << *size << endl;
    for (int i = 0; i < (*size/2); ++i)
    {
       // cout << "Копированвние " << p_array[i] << endl;
        p_new_array[i] = p_array[i];
    }
    delete[] p_array;
    cout << "Обновление заверенно"<< endl;
    return p_new_array;
}