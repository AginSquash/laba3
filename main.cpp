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

    cout << "Введите слово для которого нужно подобрать анотоним:" << endl;
    string word;
    cin >> word;
    cout << "Антоним к " << word << " - " << dictionary[word] << endl;

    return 0;
}