#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;


map <string, string> loadDcitionary()
{
    string line;
    map <string, string> dictionary;
    ifstream in("dict.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            int index = line.find("::");
            dictionary.insert( make_pair( line.substr(0, index), line.substr(index + 2 ) ) );
        }
    }
    in.close();
    return  dictionary;
}

int main() {

    map<string, string> dictionary = loadDcitionary();

    string line;

    string dict = "";
    ifstream in("dict.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            dict += line + ";";
            cout << dict;
        }
    }
    in.close();

    cout << "Введите слово для которого нужно подобрать антоним:" << endl;
    string word;
    cin >> word;

    int index = dict.find(word);

    string str = "";
    if ( dict[index + word.length()] == ';' )
    {
        int n_index = index - 2;
        while (dict[n_index] != ';')
        {
            str += dict[n_index];
            n_index--;
        }

        string new_str = ""; //FIXME можно юзать срез
        for (int i = str.length(); i > 0; i-- )
        {
            if (str[i] != NULL)
            {
                new_str += str[i];
            }
        }

        cout << new_str << endl;
    } else {
        cout << "It Work!" << endl;
        index += word.length() + 2;
        int end_index = index;
        while (dict[end_index] != ';')
        {
            end_index++;
            cout << end_index << endl;
        }
        str = dict.substr(index, end_index);
        cout << str <<endl;
    }


    return 0;
}