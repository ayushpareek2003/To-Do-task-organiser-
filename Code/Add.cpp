#include "Add.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(Add);

bool Add::OnInit() {
	MainFrame* mframe = new MainFrame("To-Do Application");
	mframe->SetClientSize(800, 600);
	
	mframe->Show();


	

	return true;
}