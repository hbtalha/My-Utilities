#include <iostream>
#include <filesystem>
#include <algorithm>
#include <windows.h>
#include <conio.h>

using namespace std;
using namespace std::filesystem;

int main()
{
    try
    {
        path file_path = "D:/Desktop/4 Your Eyez Only (2016)/";

        directory_iterator iter(file_path), endit;

        vector<string> vfile_paths, vfile_names;

        for(; iter != endit; ++iter)
        {
            vfile_paths.push_back(iter->path().string());
            vfile_names.push_back(iter->path().filename().string());
        }

        int i = 0, count_ = 1;;
        path previous;
        bool only_1_in_a_row = false;
        while(true)
        {
            cout << endl << endl << vfile_names[i] << endl << endl;

            cout << "->";
            cin >> count_;

            if(count_ == 0) // skip
                ++i;

            // undo the last recent renaming
            else if(count_ == -1 && i != 0 && previous.string().size() > 0 && only_1_in_a_row)
            {

                filesystem::rename(previous, vfile_paths[i -1]);


                only_1_in_a_row = false;

                i--;
            }
            else if(count_ != 0 && count_ != -1)
            {
                path to = file_path.string() + to_string(count_) + " - " + vfile_names[i];
                previous = to;


                filesystem::rename(vfile_paths[i], to);

                only_1_in_a_row = true;

                ++i;
            }


            if(i == vfile_names.size())
            {
                cout << "\a";
                i = 0;

                vfile_names.clear();
                vfile_paths.clear();

                directory_iterator iter(file_path), endit;

                for(; iter != endit; ++iter)
                {
                    vfile_paths.push_back(iter->path().string());
                    vfile_names.push_back(iter->path().filename().string());
                }
            }

            system("cls");

        }
    }
    catch(exception& e)
    {
        cerr << e.what();
    }

    return 0;
}
