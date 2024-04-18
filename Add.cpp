#include "Add.h"
#include "MainFrame.h"

wxIMPLEMENT_APP(Add);

bool Add::OnInit() {
	MainFrame* mframe = new MainFrame("N rr");
	mframe->SetClientSize(800, 600);
	mframe->Show();
	

	return true;
}