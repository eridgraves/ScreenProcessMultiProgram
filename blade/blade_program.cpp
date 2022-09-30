#include "blade_program.h"
#include "Windows.h"
#include <iostream>
#include<thread>

using namespace std;
using namespace std::chrono_literals;

class ScreenTest
{

    public:

        ScreenTest();

        int CreateTerminalInstance()
        {
            cout << "Opening Shell with \"screen -S bladeProcess\"..." << endl;

            // blade creates a terminal process and starts it running
            system("zsh screen -S bladeProcess");

            // then closes the session (leaving the process running)
            system("zsh screen -d bladeProcess");
        }

        int QuitTerminalInstance()
        {
            cout << "Quitting Screen \"bladeProcess\"" << endl;

            // reattach and quit the screen session created earlier
            system("zsh screen -r bladeProcess");
            system("zsh screen -X quit");
        }
};

// Start the terminal w/process and then detach and sleep to let client connect and try a command.
// TODO: signal when created? via port? 
int main()
{

    cout << "Starting Blade Program: " << endl;

    ScreenTest ST;

    int ret = ST.CreateTerminalInstance();

    this_thread::sleep_for(5s);
    
    
    return 0;
}