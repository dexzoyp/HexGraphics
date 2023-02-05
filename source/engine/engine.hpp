#pragma once
#include "Core.hpp"

namespace Hex {
    void ENGINE_API HelloEngine();

    class ENGINE_API Application
    {
    public:
        Application();
        virtual ~Application();
        int Run();
    };

    //To be defined from client
    Application* CreateApplication();
};

