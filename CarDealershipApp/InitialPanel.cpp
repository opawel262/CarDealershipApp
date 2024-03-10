#include "InitialPanel.h"

InitialPanel::InitialPanel(wxFrame* parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize), parentFrame(parent)
{
	this->text1 = new wxStaticText(this, wxID_ANY, "Welcome to the car dealership management application");

    this->font_button = new wxFont();
    this->font_header = new wxFont();

    this->font_header->SetFaceName("Sans Serif");
    this->font_header->SetPointSize(18);

    this->font_button->SetFaceName("Sans Serif");
    this->font_button->SetPointSize(14);



    this->text1->SetFont(*this->font_header);


    this->toLoginPanelBtn = new wxButton(this, wxID_ANY, "Login", wxDefaultPosition, wxSize(150, 50));
    this->toLoginPanelBtn->SetFont(*this->font_button);
    this->toLoginPanelBtn->Bind(wxEVT_BUTTON, &InitialPanel::OnButtonLoginClicked, this);

    this->toRegisterPanelBtn= new wxButton(this, wxID_ANY, "Register", wxDefaultPosition, wxSize(150, 50));
    this->toRegisterPanelBtn->SetFont(*this->font_button);
    this->toRegisterPanelBtn->Bind(wxEVT_BUTTON, &InitialPanel::OnButtonRegisterClicked, this);


    

    this->sizer = new wxBoxSizer(wxVERTICAL);

    sizer->AddStretchSpacer();
    sizer->Add(text1, 0, wxALIGN_CENTER | wxALL, 10);
    sizer->Add(toLoginPanelBtn, 0, wxALIGN_CENTER | wxALL, 10);
    sizer->Add(toRegisterPanelBtn, 0, wxALIGN_CENTER | wxALL, 10);
    sizer->AddStretchSpacer();

    SetSizer(sizer);

    
}

void InitialPanel::OnButtonLoginClicked(wxCommandEvent& evt)
{
    wxMessageBox("Clicknales login przycisk");
}

void InitialPanel::OnButtonRegisterClicked(wxCommandEvent& evt)
{
    wxMessageBox("Cliknales register przycisk");
}
