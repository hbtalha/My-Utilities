#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    int percentage;
    string str_percentage;
    cout << "Enter % for shutdown: ";
    getline(cin, str_percentage);

    for (int i = 0; i < str_percentage.size(); ++i)
    {
        if ((! isdigit(str_percentage[i])))
        {
            system("cls");

            cout << "Enter % for shutdown: ";
            getline(cin, str_percentage);

            i = -1;
        }
    }

    percentage = stoi(str_percentage);

    while (true)
    {
        system("cls");

        cout << "Shutdown at battery level of " << percentage << "%" << endl << endl;;

        SYSTEM_POWER_STATUS battery_status;

        GetSystemPowerStatus(&battery_status);

        int battery_life_percentage = battery_status.BatteryLifePercent;

        cout << "Current BatteryLifePercent: " << battery_life_percentage;

        if (battery_life_percentage <= percentage)
            break;

        Sleep(10000);
    }

    system("shutdown -poweroff");


    return 0;
}
