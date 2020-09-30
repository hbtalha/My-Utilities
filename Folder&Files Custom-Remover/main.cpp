#include <iostream>
#include <filesystem>

using namespace std;
using namespace std::filesystem;

int main()
{
   try
   {
      path root_path = "D:/Documents/School/Programming/_C++/Books/C++ Without Fear (3rd Edition)/Exercises/";
      recursive_directory_iterator iter(root_path), endit;

      for(; iter != endit; ++iter)
      {
         string folder = iter->path().filename().string();
         string extension = iter->path().extension().string();

         if(folder == "bin" || folder == "obj")
            remove_all(iter->path().string());

         if(extension == ".save" || extension == ".depend" || extension == ".layout")
            filesystem::remove(iter->path().string());
      }
   }
   catch(exception& e)
   {
      cout << e.what() << endl;
   }

    return 0;
}
