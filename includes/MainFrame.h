#pragma once
#include <wx/wx.h>

class MainFrame:public wxFrame
{
public:

	MainFrame(const wxString& title);


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
	


	wxButton* clearB;
	wxButton* addB;
	wxPanel* panel;
	wxStaticText* headline;
	wxTextCtrl* inputfield;
	wxCheckListBox* checklistbox;



};

