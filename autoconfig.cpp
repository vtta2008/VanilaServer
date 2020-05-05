#include <iostream>
#include <Windows.h>


using namespace std;


main()
{

    system("npm install --global --production windows-build-tools");

    //system("npm config set python '%USEPROFILE%/.windows-build-tools/python27/python.exe'");

    system("yarn");

    system("yarn add global cross-env");

    system("yarn dll");

    system("npm install --save-dev stylelint stylelint-config-standard");

    system("yarn dev-win");

};
