// Global module fragment where #includes can happen
module;

#include <iostream>

// first thing after the Global module fragment must be a module command
export module DendyEngineCore;

export // can just export the namespace...
namespace DendyEngine
{

class CDendyEngineCore
{
public:
    void DoStuff()
    {
        std::cout << "CDendyEngineCore::DoStuff() executed!" << std::endl;
    }
};

};
