#include <iostream>
#include "version_lib.h"

using namespace std;

int main(int argc, char* argv[])
{
    std::cout << "Version: " << version() << std::endl;
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
