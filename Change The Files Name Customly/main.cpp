#include <iostream>
#include <filesystem>
#include <dirent.h>
#include <windows.h>
#include <boost/algorithm/string.hpp>

using namespace std;

using namespace std::filesystem;


/*
 for ( unsigned int i = 0; i < rstr.size(); i++)
        {
      //      cout << rstr[i];
            if (isspace(rstr[i]) && isspace(rstr[i+1]))
            {
                rstr.erase(i, i - (i - 1));

             //   cout << "found ";

            //    getch();

                i = -1;
            }
        }
*/

void changeFilesNamesCustomly()
{
    DIR *dp;
    struct dirent *ep;

    const char* path = "D:\\Videos\\TV Shows\\The Big Bang Theory\\Season 11\\";

    dp = opendir(path);

    while ((ep = readdir(dp)))
    {
        string file_name = ep->d_name;

        string _path = path;

        string old_name = _path + ep->d_name;
        const char* old_path_name = old_name.data();

        boost::erase_all(file_name, "The Big Bang Theory ");

        string new_name = _path + file_name;
        const char* new_path_name = new_name.data();

        rename(old_path_name, new_path_name);
    }
}

void changeFilesNamesInABatch(path file_path, string to_erase)
{
    for(auto iter : directory_iterator(file_path))
    {
        string filename = iter.path().filename().string();

        if(filename.find(to_erase) != string::npos)
        {
           boost::erase_all(filename, to_erase);

           filesystem::rename(iter.path().string(), file_path.string() + filename);

           cout << iter.path().string() << " -> " + file_path.string() + filename << endl;
        }
    }
}

int main()
{
    const char* path = "D:/Videos\\TV Shows\\The Big Bang Theory\\Season 1\\S01E02 The Big Bran Hypothesis.mkv";

    SetFileAttributesA(path, FILE_ATTRIBUTE_NORMAL);

    filesystem::path file_path = "D:/Desktop/4 Your Eyez Only (2016) - Copy/";

    changeFilesNamesInABatch(file_path, "J. Cole - ");

    //changeFilesNamesCustomly();

    return 0;
}
