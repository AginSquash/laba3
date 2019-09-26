#include <iostream>
#include <fstream>
#include <string>

#define CORRESPONDS ':'
#define END_LINE '|'

using namespace std;

string getWordAfter(string dict, const int index)
{
    int end_index = index;
    while ( dict[end_index + 1] != END_LINE)
    {
        end_index++;
    }
    return dict.substr(index, end_index ) ;
}

int main() {

    string line;

    string dict = "";
    ifstream in("dict.txt");
    if (in.is_open())
    {
        while (getline(in, line))
        {
            dict += line + END_LINE;
        }
    }
    in.close();

    cout << dict << endl;

    cout << "Введите слово для которого нужно подобрать антоним:" << endl;
    string word;
    cin >> word;

    const int index = dict.find(word);


    cout << "dict[ (index + word.length() ) ]: " << dict[ (index + word.length() ) ] << endl;

    cout << "dict[ (index - 1) ]: " << dict[ (index - 1) ] << endl;

    /*if ( dict[ (index + word.length() ) ] == end_line )
    {
        cout << "End line";
    } else if ( dict[ (index - 1) ] == ':' ) {

        cout << "Middle";
    } */

    switch ( dict[ (index + word.length()) ] )
    {
        case CORRESPONDS:

            string antonym = getWordAfter(dict, index + word.length() );
            cout << antonym << endl;
            break;

    }

    return 0;
}