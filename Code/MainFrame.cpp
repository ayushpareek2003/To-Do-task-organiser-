#include "MainFrame.h"
#include <wx/wx.h>
#include <vector>
#include <string>
#include "Task.h"
#include "Wallpaper_Update.h"
#include <iostream>
#include <opencv2/opencv.hpp> 
#include <opencv2/highgui/highgui.hpp>




MainFrame::MainFrame(const wxString& title) :wxFrame(nullptr, wxID_ANY, title) {
	createControls();
	groupHandlers();
	taskLoader();
	createSTORAGE();



}

void MainFrame::groupHandlers()
{
	addB->Bind(wxEVT_BUTTON, &MainFrame::onADDbutton, this);
	inputfield->Bind(wxEVT_TEXT_ENTER, &MainFrame::enterTOadd, this);
	checklistbox->Bind(wxEVT_KEY_DOWN, &MainFrame::selectTask, this);
	clearB->Bind(wxEVT_BUTTON, &MainFrame::clearButton, this);
	editWb->Bind(wxEVT_BUTTON, &MainFrame::wallapaper_edit, this);
	oldWallpaper->Bind(wxEVT_BUTTON, &MainFrame::restoreWallpaper, this);

	


	this->Bind(wxEVT_CLOSE_WINDOW, &MainFrame::closeApp, this);



}

void MainFrame::onADDbutton(wxCommandEvent& evt)
{
	ADDtaskFROMinput();
	
}

void MainFrame::enterTOadd(wxCommandEvent& evt)
{
	ADDtaskFROMinput();

}

void MainFrame::ADDtaskFROMinput()
{
	wxString description = inputfield->GetValue();

	if (!description.IsEmpty()) {
		checklistbox->Insert(description, checklistbox->GetCount());
		inputfield->Clear();

	}
	inputfield->SetFocus();

}

void MainFrame::selectTask(wxKeyEvent& evt)
{
	switch (evt.GetKeyCode()) {
	case(WXK_DELETE):
		removefromList();
		break;
	case(WXK_UP):
		moveTask(-1);
		break;
	case(WXK_DOWN):
		moveTask(1);
		break;
	}


}

void MainFrame::moveTask(int k)
{
	int currIndex = checklistbox->GetSelection();

	if (currIndex == wxNOT_FOUND) {
		return;
	}
	int newIndex = currIndex + k;

	if (newIndex >= 0 && newIndex < checklistbox->GetCount()) {
		swap(currIndex, newIndex);
		checklistbox->SetSelection(newIndex);	
	}

}

void MainFrame::swap(int i, int j)
{
	Task ti{ checklistbox->GetString(i).ToStdString(),checklistbox->IsChecked(i) };
	Task tj{ checklistbox->GetString(j).ToStdString(),checklistbox->IsChecked(j) };

	checklistbox->SetString(i, tj.Descrip);
	checklistbox->Check(i, tj.done);
	
	checklistbox->SetString(j, ti.Descrip);
	checklistbox->Check(j, ti.done);


}

void MainFrame::clearButton(wxCommandEvent& evt)
{
	if (checklistbox->IsEmpty()) {
		return;
	}
	wxMessageDialog dialog(this, "sch me kr rha h clear", "Clear", wxYES_NO | wxCANCEL);

	int result = dialog.ShowModal();

	if (result == wxID_YES) {
		checklistbox->Clear();
	}
	

}

void MainFrame::closeApp(wxCloseEvent& evt)
{
	std::vector<Task> Data;

	for (int y = 0; y < checklistbox->GetCount(); y++) {
		Task temp;
		temp.Descrip = checklistbox->GetString(y);
		temp.done = checklistbox->IsChecked(y);
		Data.push_back(temp);
	}
	save(Data, "C:/To-Do/Task.txt");
	evt.Skip();


}

void MainFrame::taskLoader()
{
	std::vector<Task> Data = load("c:/To-DO/Task.txt");

	for (const Task& task:Data) {
		int index = checklistbox->GetCount();
		checklistbox->Insert(task.Descrip, index);
		checklistbox->Check(index, task.done);

	}

}

void MainFrame::wallapaper_edit(wxCommandEvent& evt)
{

	std::vector<std::string> storing_data_to_add;

	for (int i = 0; i < checklistbox->GetCount(); i++) {
		std::string temp_task = checklistbox->GetString(i).ToStdString();
		storing_data_to_add.push_back(temp_task);

	}

	std::string edited_wallpaper_path = editing_Wallpaper(storing_data_to_add);
	
	 
}

void MainFrame::createSTORAGE()
{
	std::string folderName = "c:/To-DO";

	
	if (!std::filesystem::exists(folderName)) {
		std::filesystem::create_directory(folderName);
		
		
	}
	if (!std::filesystem::exists("c:/To-Do/Temp")) {
		std::filesystem::create_directory("c:/To-Do/Temp");

	}


	extract_path();
	

	
	

	
	

	

	

}

void MainFrame::restoreWallpaper(wxCommandEvent& evt)
{

	std::string path = "c:/To-Do/Initial_wallpaper.png";
	bool result = set_wallpaper(path);




}








void MainFrame::removefromList()
{
	int index = checklistbox->GetSelection();

	if (index == wxNOT_FOUND) {
		return;
	}
	checklistbox->Delete(index);

	while (index >= checklistbox->GetCount()&&index>=0) {
		index--;
	}
	if (index!=-1) {
		checklistbox->SetSelection(index);
	}
}



void MainFrame::createControls() {
	panel = new wxPanel(this);
	wxFont headlineFont(wxFontInfo(wxSize(0, 36)).Bold());
	wxFont mainFont(wxFontInfo(wxSize(0, 24)));

	panel->SetFont(mainFont);

	headline = new wxStaticText(panel, wxID_ANY, "To-Do", wxPoint(0, 22), wxSize(800, -1), wxALIGN_CENTER_HORIZONTAL);
	headline->SetFont(headlineFont);

	inputfield = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(100, 80), wxSize(495, 35),wxTE_PROCESS_ENTER);
	checklistbox = new wxCheckListBox(panel, wxID_ANY, wxPoint(100, 120), wxSize(600, 400));
	addB = new wxButton(panel, wxID_ANY,"Add", wxPoint(600, 80), wxSize(100, 35));
	clearB = new wxButton(panel, wxID_ANY, "Clear", wxPoint(100, 525), wxSize(100, 35));
	editWb = new wxButton(panel, wxID_ANY, "Add on Wallpaper", wxPoint(500, 525), wxSize(210, 35));
	oldWallpaper = new wxButton(panel, wxID_ANY, "Restore Wallpaper", wxPoint(250, 525), wxSize(220, 35));




}




