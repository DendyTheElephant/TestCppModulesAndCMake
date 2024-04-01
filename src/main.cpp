//#include <QCoreApplication>
//#include <QDebug>

//int main(int argc, char *argv[]) {
//    QCoreApplication a(argc, argv);
//    qDebug() << "Hello World";
//    return QCoreApplication::exec();
//}

#include <iostream>
//import <iostream>;
import DendyEngineCore;

int main()
{
    std::cout << "Hello World" << std::endl;
    if (__cplusplus >= 202101L) std::cout << "C++23("<<__cplusplus<<"L)";
    else if (__cplusplus >= 202002L) std::cout << "C++20("<<__cplusplus<<"L)";
    else if (__cplusplus >= 201703L) std::cout << "C++17("<<__cplusplus<<"L)";
    else if (__cplusplus >= 201402L) std::cout << "C++14("<<__cplusplus<<"L)";
    else if (__cplusplus >= 201103L) std::cout << "C++11("<<__cplusplus<<"L)";
    else if (__cplusplus >= 199711L) std::cout << "C++98("<<__cplusplus<<"L)";
    else std::cout << "pre-standard C++." << __cplusplus;
    std::cout << std::endl;

    DendyEngine::CDendyEngineCore DendyEngine;
    DendyEngine.DoStuff();
}