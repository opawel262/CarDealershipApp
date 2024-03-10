#pragma once
#include <wx/wx.h>
#include "InitialPanel.h"
class FrameApp: public wxFrame
{
public:
	FrameApp(const wxString& title);
private:
	InitialPanel* initialPanel;


};

