#include "FrameApp.h"

FrameApp::FrameApp(const wxString& title) : wxFrame(NULL, wxID_ANY, title), dataBase("baza_danych"), adminLogged(false)
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
	this->infoListOfCar->InsertColumn(5, wxT("Year"));
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
	this->specicInfoPanel->Hide();

	this->specificlabelId = new wxStaticText(this->specicInfoPanel, wxID_ANY, "ID: ", wxPoint(70, 125));
	this->specificInputId = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 120), wxSize(180, 30), wxTE_READONLY);
	//this->specificInputId->SetEditable(false);

	this->specificLabelMileage = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Mileage: ", wxPoint(70, 175));
	this->specificInputMileage = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 170), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelPrice = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Price: ", wxPoint(70, 225));
	this->specificInputPrice = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 220), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelBrand = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Brand: ", wxPoint(70, 275));
	this->specificInputBrand = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 270), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelModel = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Model: ", wxPoint(70, 325));
	this->specificInputModel = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 320), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelEngineCapacity = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Engine Capacity: ", wxPoint(70, 375));
	this->specficInputEngineCapacity = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(170, 370), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelBodyType = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Body Type: ", wxPoint(420, 125));
	this->specificInputBodyType = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 120), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelYear = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Year: ", wxPoint(420, 175));
	this->specificInputYear = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 170), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelEnginePower = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Engine Power: ", wxPoint(420, 225));
	this->specificInputEnginePower = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 220), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelGearbox = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Gearbox: ", wxPoint(420, 275));
	this->specificInputGearbox = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 270), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelSeatingCapacity = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Seating Capacity: ", wxPoint(420, 325));
	this->specificInputSeatingCapacity = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 320), wxSize(180, 30), wxTE_READONLY);

	this->specificLabelFuelType = new wxStaticText(this->specicInfoPanel, wxID_ANY, "Fuel Type: ", wxPoint(420, 375));
	this->specificInputFuelType = new wxTextCtrl(this->specicInfoPanel, wxID_ANY, "", wxPoint(520, 370), wxSize(180, 30), wxTE_READONLY);

	this->specificButtonBack = new wxButton(this->specicInfoPanel, wxID_ANY, "Back", wxPoint(10, 10), wxSize(140, 40));
	this->specificButtonBack->SetFont(this->fontButtonText);
	this->specificButtonBack->Bind(wxEVT_BUTTON, &FrameApp::OnButtonSpecificBackClicked, this);



	// Admin add vehicle Panel
	this->adminAddPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(800, 600));

	this->addLabelId = new wxStaticText(this->adminAddPanel, wxID_ANY, "ID: ", wxPoint(70, 125));
	this->addInputId = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(170, 120), wxSize(180, 30));

	this->addLabelMileage = new wxStaticText(this->adminAddPanel, wxID_ANY, "Mileage: ", wxPoint(70, 175));
	this->addInputMileage = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(170, 170), wxSize(180, 30));

	this->addLabelPrice = new wxStaticText(this->adminAddPanel, wxID_ANY, "Price: ", wxPoint(70, 225));
	this->addInputPrice = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(170, 220), wxSize(180, 30));

	this->addLabelBrand = new wxStaticText(this->adminAddPanel, wxID_ANY, "Brand: ", wxPoint(70, 275));
	this->addInputBrand = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(170, 270), wxSize(180, 30));

	this->addLabelModel = new wxStaticText(this->adminAddPanel, wxID_ANY, "Model: ", wxPoint(70, 325));
	this->addInputModel = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(170, 320), wxSize(180, 30));

	this->addLabelEngineCapacity = new wxStaticText(this->adminAddPanel, wxID_ANY, "Engine Capacity: ", wxPoint(70, 375));
	this->addInputEngineCapacity = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(170, 370), wxSize(180, 30));

	this->addLabelBodyType = new wxStaticText(this->adminAddPanel, wxID_ANY, "Body Type: ", wxPoint(420, 125));
	this->addInputBodyType = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(520, 120), wxSize(180, 30));

	this->addLabelYear = new wxStaticText(this->adminAddPanel, wxID_ANY, "Year: ", wxPoint(420, 175));
	this->addInputYear = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(520, 170), wxSize(180, 30));

	this->addLabelEnginePower = new wxStaticText(this->adminAddPanel, wxID_ANY, "Engine Power: ", wxPoint(420, 225));
	this->addInputEnginePower = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(520, 220), wxSize(180, 30));

	this->addLabelGearbox = new wxStaticText(this->adminAddPanel, wxID_ANY, "Gearbox: ", wxPoint(420, 275));
	this->addInputGearbox = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(520, 270), wxSize(180, 30));

	this->addLabelSeatingCapacity = new wxStaticText(this->adminAddPanel, wxID_ANY, "Seating Capacity: ", wxPoint(420, 325));
	this->addInputSeatingCapacity = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(520, 320), wxSize(180, 30));

	this->addLabelFuelType = new wxStaticText(this->adminAddPanel, wxID_ANY, "Fuel Type: ", wxPoint(420, 375));
	this->addInputFuelType = new wxTextCtrl(this->adminAddPanel, wxID_ANY, "", wxPoint(520, 370), wxSize(180, 30));
	this->addButtonBack = new wxButton(this->adminAddPanel, wxID_ANY, "Back", wxPoint(10, 10), wxSize(140, 40));
	this->addButtonBack->SetFont(this->fontButtonText);
	this->addButtonBack->Bind(wxEVT_BUTTON, &FrameApp::OnButtonAddBackClicked, this);
    // admin too

	this->adminEnterAddPanel = new wxButton(this->infoPanel, wxID_ANY,"Add vehicle", wxPoint(330, 10), wxSize(140, 40));
	this->adminEnterAddPanel->Hide();
	this->adminEnterAddPanel->SetFont(this->fontButtonText);
	this->adminEnterAddPanel->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEnterAddPanel, this);

	this->adminAddPanelSubmit = new wxButton(this->adminAddPanel, wxID_ANY, "Add vehicle", wxPoint(330, 510), wxSize(140, 40));

	this->adminEditIdButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(360, 120), wxSize(40, 30));
	this->adminEditIdButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditIdCLicked, this);

	this->adminEditMileageButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(360, 170), wxSize(40, 30));
	this->adminEditMileageButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditMileageClicked, this);

	this->adminEditPriceButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(360, 220), wxSize(40, 30));
	this->adminEditPriceButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditPriceClicked, this);

	this->adminEditBrandButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(360, 270), wxSize(40, 30));
	this->adminEditBrandButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditBrandClicked, this);

	this->adminEditModelButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(360, 320), wxSize(40, 30));
	this->adminEditModelButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditModelClicked, this);

	this->adminEditEngineCapacityButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(360, 370), wxSize(40, 30));
	this->adminEditEngineCapacityButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditEngineCapacityClicked, this);

	this->adminEditBodyTypeButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(710, 120), wxSize(40, 30));
	this->adminEditBodyTypeButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditBodyTypeClicked, this);

	this->adminEditYearButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(710, 170), wxSize(40, 30));
	this->adminEditYearButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditYearClicked, this);

	this->adminEditEnginePowerButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(710, 220), wxSize(40, 30));
	this->adminEditEnginePowerButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditEnginePowerClicked, this);

	this->adminEditGearboxButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(710, 270), wxSize(40, 30));
	this->adminEditGearboxButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditGearboxClicked, this);

	this->adminEditSeatingCapacityButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(710, 320), wxSize(40, 30));
	this->adminEditSeatingCapacityButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditSeatingCapacityClicked, this);

	this->adminEditFuelTypeButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(710, 370), wxSize(40, 30));
	this->adminEditFuelTypeButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditFuelTypeClicked, this);

	this->adminEnterAddPanel->Hide();
	this->adminAddPanel->Hide();
	this->adminEditIdButton->Hide();



}

void FrameApp::OnColumnClick(wxListEvent& event) {
	// Pobieranie indeksu klikniętej kolumny
	int columnIndex = event.GetColumn();

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
	std::string username = this->loginUsernameInput->GetValue().ToStdString();
	std::string password = this->loginPasswordInput->GetValue().ToStdString();

	for (auto& admin : this->dataBase.GetAllAdmins()) {
		if (admin->getUsername() == username && admin->getPassword() == password) {
			this->loginPanel->Hide();
			this->infoPanel->Show();
			this->adminLogged = true;

			// declare elemnts for admin
			this->adminEnterAddPanel->Show();
			this->adminEditIdButton->Show();
			this->adminEnterAddPanel->Hide();
			wxMessageBox("Logged in successfully");
		}
	}
	if(!adminLogged) wxMessageBox("Incorrect credentials");



}

void FrameApp::OnButtonRegisterClicked(wxCommandEvent& evt)
{
	wxString username = this->registerUsernameInput->GetValue();
	wxString password = this->registerPasswordInput->GetValue();
	if (this->registerCodeInput->GetValue() == "informatyka" && password == registerPasswordInputRepeat->GetValue()) {

		Admin newAdmin(username.ToStdString(), password.ToStdString());
		this->dataBase.AddAdmin(newAdmin);
		this->registerPanel->Hide();
		this->loginPanel->Show();
		wxMessageBox("Successfully registered.");
	}
	else {
		wxMessageBox("Not registered because you provided an incorrect code");
	}

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
	this->adminEnterAddPanel->Hide();
	this->adminLogged = false;
}

void FrameApp::OnButtonSpecificBackClicked(wxCommandEvent& evt)
{
	this->specicInfoPanel->Hide();
	this->infoPanel->Show();
}

void FrameApp::OnButtonSpecificEnterClicked(wxCommandEvent& evt)
{
	this->infoPanel->Hide();
	this->specicInfoPanel->Show();

}

void FrameApp::OnButtonEnterAddPanel(wxCommandEvent& evt)
{
	this->infoPanel->Hide();
	this->adminAddPanel->Show();
}

void FrameApp::OnButtonAddBackClicked(wxCommandEvent& evt)
{
	this->adminAddPanel->Hide();
	this->infoPanel->Show();
}

void FrameApp::OnButtonEditIdCLicked(wxCommandEvent& evt)

{
	if (adminEditIdButton->GetLabel() == "Edit") {
		this->adminEditIdButton->SetLabel("Save");
		this->specificInputId->SetEditable(true);

	}
	else {
		this->specificInputId->SetEditable(false);
		this->adminEditIdButton->SetLabel("Edit");
		//this->dataBase.UpdateVehicleId(atoi(this->specificInputId->GetValue().ToStdString().c_str()), atoi(this->specificInputId->GetValue().ToStdString().c_str()));
	}
}

void FrameApp::OnButtonEditMileageClicked(wxCommandEvent& evt)
{
	if (adminEditMileageButton->GetLabel() == "Edit") {
		this->adminEditMileageButton->SetLabel("Save");
		this->specificInputMileage->SetEditable(true);
	}
	else {
		this->specificInputMileage->SetEditable(false);
		this->adminEditMileageButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditPriceClicked(wxCommandEvent& evt)
{
	if (adminEditPriceButton->GetLabel() == "Edit") {
		this->adminEditPriceButton->SetLabel("Save");
		this->specificInputPrice->SetEditable(true);
	}
	else {
		this->specificInputPrice->SetEditable(false);
		this->adminEditPriceButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditBrandClicked(wxCommandEvent& evt)
{
	if (adminEditBrandButton->GetLabel() == "Edit") {
		this->adminEditBrandButton->SetLabel("Save");
		this->specificInputBrand->SetEditable(true);
	}
	else {
		this->specificInputBrand->SetEditable(false);
		this->adminEditBrandButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditModelClicked(wxCommandEvent& evt)
{
	if (adminEditModelButton->GetLabel() == "Edit") {
		this->adminEditModelButton->SetLabel("Save");
		this->specificInputModel->SetEditable(true);
	}
	else {
		this->specificInputModel->SetEditable(false);
		this->adminEditModelButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditEngineCapacityClicked(wxCommandEvent& evt)
{
	if (adminEditEngineCapacityButton->GetLabel() == "Edit") {
		this->adminEditEngineCapacityButton->SetLabel("Save");
		this->specficInputEngineCapacity->SetEditable(true);
	}
	else {
		this->specficInputEngineCapacity->SetEditable(false);
		this->adminEditEngineCapacityButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditBodyTypeClicked(wxCommandEvent& evt)
{
	if (adminEditBodyTypeButton->GetLabel() == "Edit") {
		this->adminEditBodyTypeButton->SetLabel("Save");
		this->specificInputBodyType->SetEditable(true);
	}
	else {
		this->specificInputBodyType->SetEditable(false);
		this->adminEditBodyTypeButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditYearClicked(wxCommandEvent& evt)
{
	if (adminEditYearButton->GetLabel() == "Edit") {
		this->adminEditYearButton->SetLabel("Save");
		this->specificInputYear->SetEditable(true);
	}
	else {
		this->specificInputYear->SetEditable(false);
		this->adminEditYearButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditEnginePowerClicked(wxCommandEvent& evt)
{
	if (adminEditEnginePowerButton->GetLabel() == "Edit") {
		this->adminEditEnginePowerButton->SetLabel("Save");
		this->specificInputEnginePower->SetEditable(true);
	}
	else {
		this->specificInputEnginePower->SetEditable(false);
		this->adminEditEnginePowerButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditGearboxClicked(wxCommandEvent& evt)
{
	if (adminEditGearboxButton->GetLabel() == "Edit") {
		this->adminEditGearboxButton->SetLabel("Save");
		this->specificInputGearbox->SetEditable(true);
	}
	else {
		this->specificInputGearbox->SetEditable(false);
		this->adminEditGearboxButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditSeatingCapacityClicked(wxCommandEvent& evt)
{
	if (adminEditSeatingCapacityButton->GetLabel() == "Edit") {
		this->adminEditSeatingCapacityButton->SetLabel("Save");
		this->specificInputSeatingCapacity->SetEditable(true);
	}
	else {
		this->specificInputSeatingCapacity->SetEditable(false);
		this->adminEditSeatingCapacityButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditFuelTypeClicked(wxCommandEvent& evt)
{
	if (adminEditFuelTypeButton->GetLabel() == "Edit") {
		this->adminEditFuelTypeButton->SetLabel("Save");
		this->specificInputFuelType->SetEditable(true);
	}
	else {
		this->specificInputFuelType->SetEditable(false);
		this->adminEditFuelTypeButton->SetLabel("Edit");
	}
}

