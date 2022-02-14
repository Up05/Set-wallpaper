#include <iostream>
#include <windows.h>
#include <fstream>

bool fileExists(const char* fileName){
  std::ifstream test(fileName); 
  return (test) ? true : false;
} // https://stackoverflow.com/questions/27587956/how-to-check-if-a-string-has-a-valid-file-path-or-directory-path-format-in-unman
// ifstream is scaryyy!


int main(int argc, char const *argv[])
{
    if(argc == 1){
        std::cout << "setWallaper <C:\\Path\\to\\image\\file.png>";
        return 1;
    }

    if (!fileExists(argv[1])){
        std::cout << "The file doesn't exist!" << std::endl;
        return 1;
    }

    LPWSTR path = (LPWSTR) argv[1];
    if(SystemParametersInfo(SPI_SETDESKWALLPAPER, 0, path, SPIF_UPDATEINIFILE)){
        std::cout << "Wallpaper set, " << argv[1];
    } else
        std::cout << "Failed to set wallpaper";


    return 0;
}

