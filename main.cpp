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
        }
    }
    in.close();

    cout << "Введите слово для которого нужно подобрать анотоним:" << endl;
    string word;
    cin >> word;

    int index = dict.find(word);
    if ( dict[index + word.length()] == ';' )
    {
        
    }

    return 0;
}