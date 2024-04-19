#pragma once
#include <wx/wx.h>
#include <filesystem>
#include <vector>
#include <string>
#include "Task.h"
#include "Wallpaper_Update.h"
#include <iostream>
#include <opencv2/opencv.hpp> 
#include <opencv2/highgui/highgui.hpp>

class MainFrame:public wxFrame
{
public:

	MainFrame(const wxString& title);

	cv::Mat nitial_wallpaper;
	


private:
	void groupHandlers();

	void onADDbutton(wxCommandEvent& evt);
	void enterTOadd(wxCommandEvent& evt);

	void ADDtaskFROMinput();

	void createControls();

	void removefromList();

	void selectTask(wxKeyEvent& evt);

	void moveTask(int k);

	void swap(int i, int j);

	void clearButton(wxCommandEvent& evt);

	void closeApp(wxCloseEvent& evt);

	void taskLoader();

	void wallapaper_edit(wxCommandEvent& evt);

	void changeWallpaper(wxCommandEvent& evt);

	void createSTORAGE();
	
	void restoreWallpaper(wxCommandEvent& evt);



	

	wxButton* clearB;
	wxButton* addB;
	wxButton* editWb;
	wxButton* wallpaperCHANGE;
	wxButton* oldWallpaper;
	wxPanel* panel;
	wxStaticText* headline;
	wxTextCtrl* inputfield;
	wxCheckListBox* checklistbox;

	
	



};

