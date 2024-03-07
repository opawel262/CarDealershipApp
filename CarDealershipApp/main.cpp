#include <wx/wx.h>
#include "FrameApp.h"

class App : public wxApp {
public:
	bool OnInit() {
		FrameApp* frameApp = new FrameApp("Komis Samochodowy :)");
		frameApp->SetClientSize(800, 600);
		frameApp->Center();
		frameApp->Show();
		return true;
	}
};

wxIMPLEMENT_APP(App);s