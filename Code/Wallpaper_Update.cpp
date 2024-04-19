#include "Wallpaper_Update.h"
#include "Windows.h"
#include <iostream>
#include <opencv2/opencv.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <locale>
#include <codecvt>
#include <conio.h>
#include <Shobjidl_core.h>
#include <filesystem>



using namespace cv;

int counter = 1;


std::string path = "c:/To-Do/Initial_wallpaper.png";


std::string editing_Wallpaper(std::vector<std::string> tasks)
{
    
    Mat wallpaper_image = imread(path);
    int screenWidth = wallpaper_image.cols;

    
    
     // Position of the text
    int fontFace = FONT_HERSHEY_SIMPLEX;
    double fontScale = 1;
    Scalar color(255, 255, 255); // Text color (white in this case)
    int thickness = 3; // Text thickness
    Mat temp=wallpaper_image;
    for (int i = 0; i < tasks.size(); i++) {
        std::string task_name = tasks[i];
        Point textOrg(screenWidth - 120, 100+i*30);
        putText(temp, task_name, textOrg, fontFace, fontScale, color, thickness);
    }

    std::string newpath = "c:/To-Do/Temp/new_wallpaper";
    newpath += std::to_string(counter)+".png";
    counter++;
 

  
    imwrite(newpath, temp);
    bool pol = set_wallpaper(newpath);
    
    return newpath;
    



}

void extract_path() {
    std::wstring wstr;
    wchar_t buffer[MAX_PATH];

    
    if (SystemParametersInfoW(SPI_GETDESKWALLPAPER, MAX_PATH, buffer, 0)) {
        buffer[MAX_PATH - 1] = L'\0';
        wstr = buffer;
    }

    std::locale loc("");


    std::codecvt<wchar_t, char, std::mbstate_t> const& codecvt = std::use_facet<std::codecvt<wchar_t, char, std::mbstate_t>>(loc);

  
    char buffe[1024] = { 0 };

   
    std::mbstate_t state = std::mbstate_t();
    const wchar_t* from_next;
    char* to_next;
    codecvt.out(state, wstr.data(), wstr.data() + wstr.size(), from_next, buffe, buffe + sizeof(buffe), to_next);

    std::string str(buffe, to_next);
    imwrite("c:/To-Do/Initial_wallpaper.png", imread(str));



}



bool set_wallpaper(std::string path_to_updated_wallpaper)
{ 

    
    std::wstring imagePath = StringToWideString(path_to_updated_wallpaper);

  
    if (!SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void*)imagePath.c_str(), SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
        std::cerr << "Error setting wallpaper." << std::endl;
        return false;
    }

    return true;

}



std::wstring StringToWideString(const std::string& str)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), NULL, 0);
    std::wstring wstrTo(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, &str[0], (int)str.size(), &wstrTo[0], size_needed);
    return wstrTo;
}


