#include <iostream>
#include <windows.h>

using namespace std;

int main()
{


    int minutes = 1 * 60000;

    int percentage = 13;

    while (true)
    {
        system("cls");

        SYSTEM_POWER_STATUS battery_status;

        GetSystemPowerStatus(&battery_status);

        int battery_life_percentage = battery_status.BatteryLifePercent;

        cout << "Auto-shutdown when battery is low..." << endl << endl;
        cout << "Current BatteryLifePercent: " << battery_life_percentage;

        if (battery_life_percentage <= percentage)
            break;

            Sleep(minutes);
    }

    system("shutdown -s");


    return 0;
}
