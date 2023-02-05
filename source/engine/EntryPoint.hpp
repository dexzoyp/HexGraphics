#pragma once

extern Hex::Application* Hex::CreateApplication();

int main(int argc, char** argv)
{
    auto app = Hex::CreateApplication();
    app->Run();
    delete app;
}
