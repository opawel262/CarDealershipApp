#include <wx/wx.h>
//#include <sqlite3/sqlite3.h
#include "FrameApp.h"

class App : public wxApp {
public:
	bool OnInit() {
		FrameApp* frameApp = new FrameApp("Komis Samochodowy <3");
		frameApp->SetClientSize(800, 600);
		frameApp->Center();
		frameApp->SetMinClientSize(wxSize(800, 600));
		frameApp->SetMaxClientSize(wxSize(800, 600));


		frameApp->Show();
		return true;
	}
};

wxIMPLEMENT_APP(App);