#include "FrameApp.h"

FrameApp::FrameApp(const wxString& title): wxFrame(NULL, wxID_ANY, title)
{
	this->fontButtonText.SetFaceName("Sans Serif");
	this->fontHeaderText.SetFaceName("Sans Serif");

	this->fontButtonText.SetPointSize(15);
	this->fontHeaderText.SetPointSize(22);

	// INITIAL PANEL
	this->initialPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800,600));

	this->initialStaticText = new wxStaticText(this->initialPanel, wxID_ANY, "Welcome to car dealership managing app", wxPoint(150,100));
	this->initialStaticText->SetFont(this->fontHeaderText);

	this->initialButtonEnterUser = new wxButton(this->initialPanel, wxID_ANY, "Enter as User", wxPoint(310, 150), wxSize(180, 50));
	this->initialButtonEnterUser->SetFont(this->fontButtonText);
	this->initialButtonEnterUser->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEnterUserClicked, this);

	this->initialButtonEnterAdmin = new wxButton(this->initialPanel, wxID_ANY, "Enter as Admin", wxPoint(310, 240), wxSize(180, 50));
	this->initialButtonEnterAdmin->SetFont(this->fontButtonText);
	this->initialButtonEnterAdmin->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEnterAdminClicked, this);

	// LOGIN PANEL
	this->loginPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
	this->loginPanel->Hide();

	this->loginButtonBack = new wxButton(this->loginPanel, wxID_ANY, "Back", wxPoint(10, 10), wxSize(140, 40));
	this->loginButtonBack->SetFont(this->fontButtonText);
	this->loginButtonBack->Bind(wxEVT_BUTTON, &FrameApp::OnButtonLoginBackClicked, this);


	this->loginStaticTextLogin = new wxStaticText(this->loginPanel, wxID_ANY, "Login", wxPoint(365, 100));
	this->loginStaticTextLogin->SetFont(this->fontHeaderText);

	this->loginUsernameLabel = new wxStaticText(this->loginPanel, wxID_ANY, "Username", wxPoint(310, 150));
	this->loginUsernameLabel->SetFont(this->fontButtonText);

	this->loginUsernameInput = new wxTextCtrl(this->loginPanel, wxID_ANY, "", wxPoint(310, 180), wxSize(180,30));
	this->loginUsernameInput->SetFont(this->fontButtonText);

	this->loginPasswordLabel = new wxStaticText(this->loginPanel, wxID_ANY, "Password", wxPoint(310, 220));
	this->loginPasswordLabel->SetFont(this->fontButtonText);

	this->loginPasswordInput = new wxTextCtrl(this->loginPanel, wxID_ANY, "", wxPoint(310, 250), wxSize(180, 30), wxTE_PASSWORD);
	this->loginPasswordInput->SetFont(this->fontButtonText);

	this->loginButton = new wxButton(this->loginPanel, wxID_ANY, "login", wxPoint(310, 290), wxSize(180, 50));
	this->loginButton->SetFont(this->fontButtonText);
	this->loginButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonLoginClicked, this);

	this->loginStaticTextDont = new wxStaticText(this->loginPanel, wxID_ANY, "Don't have admin account? Register below", wxPoint(213,430));
	this->loginStaticTextDont->SetFont(this->fontButtonText);

	this->loginButtonEnterRegister = new wxButton(this->loginPanel, wxID_ANY, "Register", wxPoint(330, 460), wxSize(140,30));
	this->loginButtonEnterRegister->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEnterRegister, this);



	// REGISTER PANEL
	this->registerPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
	this->registerPanel->Hide();

	this->registerButtonBack = new wxButton(this->registerPanel, wxID_ANY, "Back", wxPoint(10, 10), wxSize(140, 40));
	this->registerButtonBack->SetFont(this->fontButtonText);
	this->registerButtonBack->Bind(wxEVT_BUTTON, &FrameApp::OnButtonRegisterBackClicked, this);

	this->registerStaticTextLogin = new wxStaticText(this->registerPanel, wxID_ANY, "Register", wxPoint(345, 100));
	this->registerStaticTextLogin->SetFont(this->fontHeaderText);

	this->registerUsernameLabel = new wxStaticText(this->registerPanel, wxID_ANY, "Username", wxPoint(310, 150));
	this->registerUsernameLabel->SetFont(this->fontButtonText);

	this->registerUsernameInput = new wxTextCtrl(this->registerPanel, wxID_ANY, "", wxPoint(310, 180), wxSize(180, 30));
	this->registerUsernameInput->SetFont(this->fontButtonText);

	this->registerPasswordLabel = new wxStaticText(this->registerPanel, wxID_ANY, "Password", wxPoint(310, 220));
	this->registerPasswordLabel->SetFont(this->fontButtonText);

	this->registerPasswordInput = new wxTextCtrl(this->registerPanel, wxID_ANY, "", wxPoint(310, 250), wxSize(180, 30), wxTE_PASSWORD);
	this->registerPasswordInput->SetFont(this->fontButtonText);

	this->registerPasswordLabelRepeat = new wxStaticText(this->registerPanel, wxID_ANY, "Password", wxPoint(310, 290));
	this->registerPasswordLabelRepeat->SetFont(this->fontButtonText);

	this->registerPasswordInputRepeat = new wxTextCtrl(this->registerPanel, wxID_ANY, "", wxPoint(310, 320), wxSize(180, 30), wxTE_PASSWORD);
	this->registerPasswordInputRepeat->SetFont(this->fontButtonText);

	this->registerCodeLabel = new wxStaticText(this->registerPanel, wxID_ANY, "Code", wxPoint(310, 360));
	this->registerCodeLabel->SetFont(this->fontButtonText);

	this->registerCodeInput = new wxTextCtrl(this->registerPanel, wxID_ANY, "", wxPoint(310, 390), wxSize(180, 30), wxTE_PASSWORD);
	this->registerCodeInput->SetFont(this->fontButtonText);


	this->registerButton = new wxButton(this->registerPanel, wxID_ANY, "register", wxPoint(310, 430), wxSize(180, 50));
	this->registerButton->SetFont(this->fontButtonText);
	this->registerButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonRegisterClicked, this);




	// INFO PANEL
	this->infoPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));
	this->infoPanel->Hide();
	
	this->infoButtonBack = new wxButton(this->infoPanel, wxID_ANY, "Back", wxPoint(10, 10), wxSize(140, 40));
	this->infoButtonBack->SetFont(this->fontButtonText);
	this->infoButtonBack->Bind(wxEVT_BUTTON, &FrameApp::OnButtonInfoBackClicked, this);

	this->infoListOfCar = new wxListCtrl(this->infoPanel, wxID_ANY, wxPoint(150, 100), wxSize(500, 400), wxLC_REPORT);

	this->infoListOfCar->InsertColumn(0, wxT("Price"));
	this->infoListOfCar->InsertColumn(1, wxT("Mileages"));
	this->infoListOfCar->InsertColumn(2, wxT("ID"));
	this->infoListOfCar->InsertColumn(3, wxT("Brand"));
	this->infoListOfCar->InsertColumn(4, wxT("Model"));
	for (int i = 0;i < 111;i++) {
		wxString carText;
		carText.Printf("car %d", i);
		this->infoListOfCar->InsertItem(0, carText);
	}

	this->infoListOfCar->Bind(wxEVT_LIST_COL_CLICK, &FrameApp::OnColumnClick, this);


	this->infoSearchInput = new wxTextCtrl(this->infoPanel, wxID_ANY, "", wxPoint(150, 70), wxSize(300, 22));

	this->infoChoices = new wxArrayString();
	this->infoChoices->Add(wxT("price"));
	this->infoChoices->Add(wxT("mileages"));
	this->infoChoices->Add(wxT("id"));
	this->infoChoices->Add(wxT("brand"));
	this->infoChoices->Add(wxT("model"));

	this->infoChoiceSearchBy = new wxChoice(this->infoPanel, wxID_ANY, wxPoint(470, 70), wxSize(80, 25), *this->infoChoices);
	this->infoChoiceSearchBy->SetSelection(0);

	this->infoSearchButton = new wxButton(this->infoPanel, wxID_ANY, "Search",  wxPoint(570, 70), wxSize(80, 25));

	this->infoButtonEnterSpecific = new wxButton(this->infoPanel, wxID_ANY, "More info", wxPoint(330, 510), wxSize(140, 40));
	this->infoButtonEnterSpecific->SetFont(this->fontButtonText);
	this->infoButtonEnterSpecific->Bind(wxEVT_BUTTON, &FrameApp::OnButtonSpecificEnterClicked, this);




	// INFO SPECIFIC PANEL
	this->specicInfoPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));

	this->specificlabelId = new wxStaticText(this->specicInfoPanel, wxID_ANY, "ID: ", wxPoint(70, 120));
	this->specificInputId = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 120), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelMileage = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Mileage: ", wxPoint(70, 170));
	this->specificInputMileage = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 170), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelPrice = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Price: ", wxPoint(70, 220));
	this->specificInputPrice = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 220), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelBrand = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Brand: ", wxPoint(70, 270));
	this->specificInputBrand = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 270), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelModel = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Model: ", wxPoint(70, 320));
	this->specificInputModel = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 320), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelEngineCapacity = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Engine Capacity: ", wxPoint(70, 370));
	this->specficInputEngineCapacity = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 370), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelBodyType = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Body Type: ", wxPoint(420, 120));
	this->specificInputBodyType = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 120), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelYear = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Year: ", wxPoint(420, 170));
	this->specificInputYear = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 170), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelEnginePower = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Engine Power: ", wxPoint(420, 220));
	this->specificInputEnginePower = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 220), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelGearbox = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Gearbox: ", wxPoint(420, 270));
	this->specificInputGearbox = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 270), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelSeatingCapacity = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Seating Capacity: ", wxPoint(420, 320));
	this->specificInputSeatingCapacity = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 320), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelFuelType = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Fuel Type: ", wxPoint(420, 370));
	this->specificInputFuelType = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 370), wxSize(180, 30), wxTE_READONLY);
	this->specificButtonBack = new wxButton(this->specicInfoPanel, wxID_ANY, "Back", wxPoint(10, 10), wxSize(140, 40));
	this->specicInfoPanel->Hide();




}

void FrameApp::OnColumnClick(wxListEvent& event) {
	// Pobieranie indeksu klikniętej kolumny
	int columnIndex = event.GetColumn();

	// Sortowanie tabeli według klikniętej kolumny
}
void FrameApp::OnButtonEnterUserClicked(wxCommandEvent& evt)
{
	this->initialPanel->Hide();
	this->infoPanel->Show();
}

void FrameApp::OnButtonEnterAdminClicked(wxCommandEvent& evt)
{
	this->initialPanel->Hide();
	this->loginPanel->Show();
}

void FrameApp::OnButtonEnterRegister(wxCommandEvent& evt)
{
	this->loginPanel->Hide();
	this->registerPanel->Show();
}

void FrameApp::OnButtonLoginClicked(wxCommandEvent& evt)
{
	this->loginPanel->Hide();
	this->infoPanelAdmin->Show();
}

void FrameApp::OnButtonRegisterClicked(wxCommandEvent& evt)
{
	this->registerPanel->Hide();
	this->loginPanel->Show();
}

void FrameApp::OnButtonLoginBackClicked(wxCommandEvent& evt)
{
	this->loginPanel->Hide();
	this->initialPanel->Show();
}

void FrameApp::OnButtonRegisterBackClicked(wxCommandEvent& evt)
{
	this->registerPanel->Hide();
	this->loginPanel->Show();
}

void FrameApp::OnButtonInfoBackClicked(wxCommandEvent& evt)
{
	this->infoPanel->Hide();
	this->initialPanel->Show();
}

void FrameApp::OnButtonSpecificBackClicked(wxCommandEvent& evt)
{
	this->specicInfoPanel->Hide();
	this->infoPanel->Show();
}

void FrameApp::OnButtonInfoAdminBackClicked(wxCommandEvent& evt)
{
	this->infoPanelAdmin->Hide();
	this->loginPanel->Show();
}

void FrameApp::OnButtonSpecificAdminBackClicked(wxCommandEvent& evt)
{
	this->specicInfoPanelAdmin->Hide();
	this->infoPanelAdmin->Show();
}

void FrameApp::OnButtonSpecificEnterClicked(wxCommandEvent& evt)
{
	this->infoPanel->Hide();
	this->specicInfoPanel->Show();

}
