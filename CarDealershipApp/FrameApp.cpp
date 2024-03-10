#include "FrameApp.h"
#include "InitialPanel.h"

FrameApp::FrameApp(const wxString& title): wxFrame(NULL, wxID_ANY, title)
{
	this->initialPanel = new InitialPanel(this);
}
