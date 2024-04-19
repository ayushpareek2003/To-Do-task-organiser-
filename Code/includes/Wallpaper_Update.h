#pragma once

#include "Windows.h"
#include <iostream>
#include <opencv2/opencv.hpp> 
#include <opencv2/highgui/highgui.hpp>
#include <locale>
#include <codecvt>
#include <conio.h>
#include <Shobjidl_core.h>


using namespace cv;






std::string editing_Wallpaper(std::vector<std::string> tasks);
void extract_path();

bool set_wallpaper(std::string path_to_wallpaper);




std::wstring StringToWideString(const std::string& str);








