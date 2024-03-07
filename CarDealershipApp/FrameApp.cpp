#include "FrameApp.h"

FrameApp::FrameApp(const wxString& title): wxFrame(NULL, wxID_ANY, title)
{
	wxPanel* mainPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	wxButton* BtnChange = new wxButton(mainPanel, wxID_ANY, wxString("Cos"), wxPoint(111, 200));
	mainPanel->Show();


}
