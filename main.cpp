#include "List.cpp"

using namespace std;

int main()
{
    List lst;
    lst.push_back(100);
    lst.push_back(2.1);
    lst.push_back(900);
    lst.push_back(std::string("qwerty"));

    lst.output();
    std::cout<<CastNodeData::string_cast(lst.find("qwerty")->getData())<<std::endl;

    lst.clear();

    lst.push_back(555);
    lst.push_back(std::string("zxc"));
    lst.output();

    system("PAUSE");

    return 0;
}

