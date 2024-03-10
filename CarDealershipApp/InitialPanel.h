#pragma once
#include <wx/wx.h>

class InitialPanel: wxPanel
{
public:
	InitialPanel(wxFrame* parent);

private:
	void OnButtonLoginClicked(wxCommandEvent& evt);
	void OnButtonRegisterClicked(wxCommandEvent& evt);


	wxStaticText* text1;
	wxButton* toRegisterPanelBtn;
	wxButton* toLoginPanelBtn;
	wxFrame* parentFrame;
	wxSizer* sizer;
	wxFont* font_header;
	wxFont* font_button;

};

