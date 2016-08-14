#include <iostream>
#include <regex>

using namespace std;

int main()
{
    regex space("\\s+");
    cout << regex_match("   ", space) << endl;
}