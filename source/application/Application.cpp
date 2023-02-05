#include <HexEngine.hpp>
#include <iostream>

class App : public Hex::Application
{
public:
    App(){
        std::cout << "Hello App!\n";
    }
    ~App(){
        std::cout << "Destroy App!\n";
    }
};
Hex::Application* Hex::CreateApplication()
{
    return new App();
}
