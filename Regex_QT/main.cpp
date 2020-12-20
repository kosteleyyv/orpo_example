#include <iostream>
#include <regex>

using namespace std;

int main()
{
    std::regex macadress_regex("([0-9a-fA-F]{2}([:-]|$)){6}$|([0-9a-fA-F]{4}([.]|$)){3}");

    const unsigned int nStringArray=5;

    std::string stringArray[]={
                               "01-0C-CD-00-00-01",
                               "01:0C:CD:00:00:01",
                               "010C.CD00.0001",
                               "010C.CD00.Y001",
                               "01:0C7CD:00:00:01"
                              };

    for(int i=0;i<nStringArray;i++)
    {
        if( std::regex_match(stringArray[i], macadress_regex))
        {
            cout <<"String \""<<stringArray[i]<< "\" is match" << endl;
        }
        else
        {
            cout <<"String \""<<stringArray[i]<< "\" isn't match" << endl;
        }
    }

    return 0;
}
