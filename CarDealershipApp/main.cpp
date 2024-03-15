#include <wx/wx.h>          // Including the main wxWidgets header file
//#include <sqlite3/sqlite3.h>  // This line is commented out

#include "FrameApp.h"       // Including the declaration of the FrameApp class

class App : public wxApp {  // Defining a new class named App which inherits from wxApp
public:
    bool OnInit() {          // Overriding the OnInit() function of wxApp
        FrameApp* frameApp = new FrameApp("Komis Samochodowy <3");  // Creating an instance of the FrameApp class
        frameApp->SetClientSize(800, 600);    // Setting the initial client size of the frame
        frameApp->Center();                    // Centering the frame on the screen
        frameApp->SetMinClientSize(wxSize(800, 600)); // Setting minimum client size
        frameApp->SetMaxClientSize(wxSize(800, 600)); // Setting maximum client size

        frameApp->Show();  // Displaying the frame
        return true;       // Returning true to indicate successful initialization
    }
};

wxIMPLEMENT_APP(App);  // Macro that declares the entry point of the application
