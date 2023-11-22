#include <iostream>
#include <Windows.h>
#include <string>
#include "debugger.h"
#include <thread>
#include <Urlmon.h>
#pragma comment(lib, "urlmon.lib")

class Variables
{
public:
    std::string option;
    std::string discord = "https://discord.gg/lurkedmodz";
};

class Settings
{
public:
    bool PlayMusicIntro = true;
    bool AntiDebugProtection = true;
};

// TODO
// Add Encryption (i didnt add cuz i didnt want to spoof feed yall retards)
// Dynamically Allocate The Imports (you retards prolly dont know how but a little hint its called lazy importer just google it !)
// Add Anti Dump, Anti VM And More Protection (i dont want to do this but i can next update but sure)
// Add KeyAuth (ill add this next update for you pasters)

int main()
{
    Variables* Vars = new Variables;
    Settings* Config = new Settings;
    if (Config->AntiDebugProtection)
    {
        std::thread(InitializeAntiDebugThread).detach();
    }
    SetConsoleTitleA("Simple Spoofer ud man Made For Lurked Modz");
    if (Config->PlayMusicIntro)
    {
        URLDownloadToFileA(NULL, "", "C:\\Windows\\udmanmapper.wav", 0, NULL);

        PlaySoundA("C:\\Windows\\udmanmapper.wav", NULL, SND_FILENAME | SND_ASYNC);
    }
    main:
    std::cout << (R"(
       __            _            _                    _     
      / / _   _ _ __| | _____  __| |   /\/\   ___   __| |____
     / / | | | | '__| |/ / _ \/ _` |  /    \ / _ \ / _` |_  /
    / /__| |_| | |  |   <  __/ (_| | / /\/\ \ (_) | (_| |/ / 
    \____/\__,_|_|  |_|\_\___|\__,_| \/    \/\___/ \__,_/___|
                                                         )");
    std::cout << "\n\n    Type -help For Commands !!";

a:

    Vars->option.clear();
    std::cout << "\n\n    Enter Choice -> ";
    std::cin >> Vars->option;

    if (Vars->option == "-spoof")
    {
        std::string driver_url = "";
        std::string mapper_url = "";
        std::string driver_path = "C:\\Windows\\Windows10Helper.sys";
        std::string mapper_path = "C:\\Windows\\blueberrymapper.exe";
        std::string command = mapper_path + " " + driver_path;
        HRESULT hr = URLDownloadToFileA(NULL, driver_url.c_str(), driver_path.c_str(), 0, NULL); // download driver
        HRESULT hr2 = URLDownloadToFileA(NULL, mapper_url.c_str(), mapper_path.c_str(), 0, NULL); // download mapper
        if (!SUCCEEDED(hr))
            std::cout << "\n\n    Failed To Download Driver To Disk" << std::endl;
        if (!SUCCEEDED(hr2))
            std::cout << "\n\n    Failed To Download Mapper To Disk" << std::endl;

        int spoofing_result = system(command.c_str());
        std::remove(mapper_path.c_str());
        std::remove(driver_path.c_str());
        driver_path.clear();
        mapper_path.clear();
        if (spoofing_result != 1)
        {
            std::cout << "\n\n    Spoofed Successfully !" << std::endl;
        }

        goto a;
    }
    else if (Vars->option == "-discord")
    {
        std::string command = "start " + Vars->discord;
        system(command.c_str());
        goto a;
    }
    else if (Vars->option == "-help")
    {
        std::cout << "\n\n";
        std::cout << "    [DEBUG] -help, Display All Commands" << std::endl;
        std::cout << "    [DEBUG] -spoof, Spoof Your Computer" << std::endl;
        std::cout << "    [DEBUG] -discord, Open Your Discord" << std::endl;
        std::cout << "    [DEBUG] -clear, Clears The Console" << std::endl;
        goto a;

    }
    else if (Vars->option == "-clear")
    {
        system("cls");
        goto main;
    }
    else {
        std::cout << "\n\n    " << Vars->option << " Does Not Appear To Be A Valid Command" << std::endl;
        goto a;
    }

    delete Vars;
    
}