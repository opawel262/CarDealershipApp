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
	this->infoListOfCar->Bind(wxEVT_LIST_ITEM_SELECTED, &FrameApp::OnListItemSelected, this);

	this->infoListOfCar->InsertColumn(0, wxT("ID"));
	this->infoListOfCar->InsertColumn(1, wxT("Price"));
	this->infoListOfCar->InsertColumn(2, wxT("Mileage"));
	this->infoListOfCar->InsertColumn(3, wxT("Brand"));
	this->infoListOfCar->InsertColumn(4, wxT("Model"));
	this->infoListOfCar->InsertColumn(5, wxT("Year"));

	this->UpdateVehiclePanelList();


	this->infoSearchInput = new wxTextCtrl(this->infoPanel, wxID_ANY, "", wxPoint(150, 70), wxSize(300, 22));
	this->infoSearchInput->Bind(wxEVT_TEXT, &FrameApp::OnSearchInput, this);

	this->infoChoices = new wxArrayString();
	this->infoChoices->Add(wxT("price"));
	this->infoChoices->Add(wxT("mileage"));
	this->infoChoices->Add(wxT("id"));
	this->infoChoices->Add(wxT("brand"));
	this->infoChoices->Add(wxT("model"));
	this->infoChoices->Add(wxT("year"));

	this->infoChoiceSearchBy = new wxChoice(this->infoPanel, wxID_ANY, wxPoint(470, 70), wxSize(80, 25), *this->infoChoices);
	this->infoChoiceSearchBy->SetSelection(0);

	this->infoButtonEnterSpecific = new wxButton(this->infoPanel, wxID_ANY, "More info", wxPoint(250, 510), wxSize(140, 40));
	this->infoButtonEnterSpecific->SetFont(this->fontButtonText);
	this->infoButtonEnterSpecific->Bind(wxEVT_BUTTON, &FrameApp::OnButtonSpecificEnterClicked, this);

	this->infoButtonDelete = new wxButton(this->infoPanel, wxID_ANY, "Delete vehicle", wxPoint(420, 510), wxSize(140, 40));
	this->infoButtonDelete->SetFont(this->fontButtonText);
	this->infoButtonDelete->Bind(wxEVT_BUTTON, &FrameApp::OnButtonDeleteClicked, this);





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
	this->adminAddPanelSubmit->SetFont(this->fontButtonText);
	this->adminAddPanelSubmit->Bind(wxEVT_BUTTON, &FrameApp::OnButtonAddPanelSubmit, this);

	this->adminEditIdButton = new wxButton(this->specicInfoPanel, wxID_ANY, "Edit", wxPoint(360, 120), wxSize(40, 30));
	this->adminEditIdButton->Bind(wxEVT_BUTTON, &FrameApp::OnButtonEditIdCLicked, this);
	this->adminEditIdButton->Enable(false);

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



}
void FrameApp::OnButtonEnterUserClicked(wxCommandEvent& evt)
{
	// Hide the initial panel and show the information panel for regular users
	this->initialPanel->Hide();
	this->infoPanel->Show();
}

void FrameApp::OnButtonEnterAdminClicked(wxCommandEvent& evt)
{
	// Hide the initial panel and show the login panel for admins
	this->initialPanel->Hide();
	this->loginPanel->Show();
}

void FrameApp::OnButtonEnterRegister(wxCommandEvent& evt)
{
	// Hide the login panel and show the registration panel
	this->loginPanel->Hide();
	this->registerPanel->Show();
}

void FrameApp::OnButtonLoginClicked(wxCommandEvent& evt)
{
	// Get the username and password entered by the user
	std::string username = this->loginUsernameInput->GetValue().ToStdString();
	std::string password = this->loginPasswordInput->GetValue().ToStdString();

	// Check if the entered credentials match an admin in the database
	for (auto& admin : this->dataBase.GetAllAdmins()) {
		if (admin.getUsername() == username && admin.getPassword() == password) {
			// Hide the login panel and show the information panel for admins
			this->loginPanel->Hide();
			this->infoPanel->Show();
			this->adminLogged = true;

			// Show admin-specific elements
			this->adminEnterAddPanel->Show();
			this->adminEditIdButton->Show();
			wxMessageBox("Logged in successfully");
		}
	}
	// If no admin with matching credentials is found, display an error message
	if (!adminLogged) wxMessageBox("Incorrect credentials");
}

void FrameApp::OnButtonRegisterClicked(wxCommandEvent& evt)
{
	// Get the username and password entered by the user
	wxString username = this->registerUsernameInput->GetValue();
	wxString password = this->registerPasswordInput->GetValue();

	// Check if the registration code and password match the criteria
	if (this->registerCodeInput->GetValue() == "informatyka" && password == registerPasswordInputRepeat->GetValue()) {
		// Create a new admin object and add it to the database
		Admin newAdmin(username.ToStdString(), password.ToStdString());
		this->dataBase.AddAdmin(newAdmin);
		// Hide the registration panel and show the login panel
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
	// Hide the login panel and show the initial panel
	this->loginPanel->Hide();
	this->initialPanel->Show();
}

void FrameApp::OnButtonRegisterBackClicked(wxCommandEvent& evt)
{
	// Hide the registration panel and show the login panel
	this->registerPanel->Hide();
	this->loginPanel->Show();
}

void FrameApp::OnButtonInfoBackClicked(wxCommandEvent& evt)
{
	// Hide the information panel and show the initial panel
	this->infoPanel->Hide();
	this->initialPanel->Show();
	// Hide the admin enter add panel and set admin logged status to false
	this->adminEnterAddPanel->Hide();
	this->adminLogged = false;
}

void FrameApp::OnButtonSpecificBackClicked(wxCommandEvent& evt)
{
	// Hide the specific info panel and show the information panel
	this->specicInfoPanel->Hide();
	this->infoPanel->Show();
	// Clear all specific input fields and update the vehicle panel list
	this->specificInputId->Clear();
	this->specificInputMileage->Clear();
	this->specificInputPrice->Clear();
	this->specificInputBrand->Clear();
	this->specificInputModel->Clear();
	this->specficInputEngineCapacity->Clear();
	this->specificInputBodyType->Clear();
	this->specificInputYear->Clear();
	this->specificInputEnginePower->Clear();
	this->specificInputGearbox->Clear();
	this->specificInputSeatingCapacity->Clear();
	this->specificInputFuelType->Clear();
	this->UpdateVehiclePanelList();
}

void FrameApp::OnButtonSpecificEnterClicked(wxCommandEvent& evt)
{
	// Get the ID of the selected vehicle from the list
	int idVehicle = atoi(this->infoListOfCar->GetItemText(this->selectedRowIndex, 0));
	// Retrieve the vehicle information from the database
	Vehicle vehicle = dataBase.getVehicle(idVehicle);

	// Set the values of specific input fields with vehicle information
	this->specificInputId->SetValue(wxString::Format("%d", vehicle.getId()));
	this->specificInputMileage->SetValue(wxString::Format("%d", vehicle.getMileage()));
	this->specificInputPrice->SetValue(wxString::Format("%.2f", vehicle.getPrice()));
	this->specificInputBrand->SetValue(wxString::FromUTF8(vehicle.getBrand().c_str()));
	this->specificInputModel->SetValue(wxString::FromUTF8(vehicle.getModel().c_str()));
	this->specficInputEngineCapacity->SetValue(wxString::Format("%2f", vehicle.getEngineCapacity()));
	this->specificInputBodyType->SetValue(wxString::FromUTF8(vehicle.getBodyType().c_str()));
	this->specificInputYear->SetValue(wxString::Format("%d", vehicle.getProductionYear()));
	this->specificInputEnginePower->SetValue(wxString::Format("%d", vehicle.getEnginePower()));
	this->specificInputGearbox->SetValue(wxString::FromUTF8(vehicle.getGearbox().c_str()));
	this->specificInputSeatingCapacity->SetValue(wxString::Format("%d", vehicle.getSeatingCapacity()));
	this->specificInputFuelType->SetValue(wxString::FromUTF8(vehicle.getFuelType().c_str()));

	// Hide the information panel and show the specific info panel
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

void FrameApp::OnButtonAddPanelSubmit(wxCommandEvent& evt)
{
    // Validate and retrieve the id
    wxString idString = this->addInputId->GetValue();
    long id;
    if (!idString.ToLong(&id) || id < 0) {
        wxMessageBox("Invalid ID. Please enter a positive integer.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the mileage
    wxString mileageString = this->addInputMileage->GetValue();
    long mileage;
    if (!mileageString.ToLong(&mileage) || mileage < 0) {
        wxMessageBox("Invalid Mileage. Please enter a positive integer.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the price
    wxString priceString = this->addInputPrice->GetValue();
    double price;
    if (!priceString.ToDouble(&price) || price < 0.0) {
        wxMessageBox("Invalid Price. Please enter a positive number.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the brand
    wxString brand = this->addInputBrand->GetValue();
    if (brand.IsEmpty()) {
        wxMessageBox("Brand cannot be empty.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the model
    wxString model = this->addInputModel->GetValue();
    if (model.IsEmpty()) {
        wxMessageBox("Model cannot be empty.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the engine capacity
    wxString engineCapacityString = this->addInputEngineCapacity->GetValue();
    double engineCapacity;
    if (!engineCapacityString.ToDouble(&engineCapacity) || engineCapacity < 0.0) {
        wxMessageBox("Invalid Engine Capacity. Please enter a positive number.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the body type
    wxString bodyType = this->addInputBodyType->GetValue();
    if (bodyType.IsEmpty()) {
        wxMessageBox("Body Type cannot be empty.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the year
    wxString yearString = this->addInputYear->GetValue();
    long year;
    if (!yearString.ToLong(&year) || year < 0) {
        wxMessageBox("Invalid Year. Please enter a positive integer.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the engine power
    wxString enginePowerString = this->addInputEnginePower->GetValue();
    long enginePower;
    if (!enginePowerString.ToLong(&enginePower) || enginePower < 0) {
        wxMessageBox("Invalid Engine Power. Please enter a positive integer.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the gearbox
    wxString gearbox = this->addInputGearbox->GetValue();
    if (gearbox.IsEmpty()) {
        wxMessageBox("Gearbox cannot be empty.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the seating capacity
    wxString seatingCapacityString = this->addInputSeatingCapacity->GetValue();
    long seatingCapacity;
    if (!seatingCapacityString.ToLong(&seatingCapacity) || seatingCapacity < 0) {
        wxMessageBox("Invalid Seating Capacity. Please enter a positive integer.", "Error", wxICON_ERROR);
        return;
    }

    // Validate and retrieve the fuel type
    wxString fuelType = this->addInputFuelType->GetValue();
    if (fuelType.IsEmpty()) {
        wxMessageBox("Fuel Type cannot be empty.", "Error", wxICON_ERROR);
        return;
    }

	// Create a new vehicle object
	Vehicle newVehicle(id, mileage, price, brand.ToStdString(), model.ToStdString(),
		year, engineCapacity, bodyType.ToStdString(), enginePower,
		gearbox.ToStdString(), seatingCapacity, fuelType.ToStdString());

	// Add the vehicle to the database
	this->dataBase.AddVehicle(newVehicle);

	// Clear text fields after adding the vehicle
	this->addInputId->Clear();
	this->addInputMileage->Clear();
	this->addInputPrice->Clear();
	this->addInputBrand->Clear();
	this->addInputModel->Clear();
	this->addInputEngineCapacity->Clear();
	this->addInputBodyType->Clear();
	this->addInputYear->Clear();
	this->addInputEnginePower->Clear();
	this->addInputGearbox->Clear();
	this->addInputSeatingCapacity->Clear();
	this->addInputFuelType->Clear();

	// Display confirmation message for adding the vehicle
	this->UpdateVehiclePanelList();
	wxMessageBox("Vehicle added successfully");

	// Switch back to the information panel
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
		// Switch to "Save" mode
		this->adminEditMileageButton->SetLabel("Save");
		this->specificInputMileage->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode
		wxString mileageString = this->specificInputMileage->GetValue();
		long mileage;
		if (!mileageString.ToLong(&mileage) || mileage < 0) {
			wxMessageBox("Invalid Mileage. Please enter a positive integer.", "Error", wxICON_ERROR);
			return;
		}
		// Update the database with the new mileage
		dataBase.UpdateVehicleMileage(atoi(this->specificInputId->GetValue()), mileage);

		// Disable editing after saving
		this->specificInputMileage->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditMileageButton->SetLabel("Edit");
	}
}

void FrameApp::OnButtonEditPriceClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditPriceButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditPriceButton->SetLabel("Save");
		this->specificInputPrice->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Get the entered price from the input field
		wxString priceString = this->specificInputPrice->GetValue();
		double price;

		// Convert the price string to a double
		if (!priceString.ToDouble(&price) || price < 0.0) {
			// If conversion fails or price is negative, show an error message
			wxMessageBox("Invalid Price. Please enter a positive number.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new price
		dataBase.UpdateVehiclePrice(atoi(this->specificInputId->GetValue()), price);

		// Disable editing after saving
		this->specificInputPrice->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditPriceButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditBrandClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditBrandButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditBrandButton->SetLabel("Save");
		this->specificInputBrand->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Get the entered brand from the input field
		wxString brand = this->specificInputBrand->GetValue();

		// Check if the brand is empty
		if (brand.IsEmpty()) {
			// If brand is empty, show an error message
			wxMessageBox("Brand cannot be empty.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new brand
		dataBase.UpdateVehicleBrand(atoi(this->specificInputId->GetValue()), brand.ToStdString());

		// Disable editing after saving
		this->specificInputBrand->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditBrandButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditModelClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditModelButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditModelButton->SetLabel("Save");
		this->specificInputModel->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Validate and retrieve the model
		wxString model = this->specificInputModel->GetValue();

		// Check if the model is empty
		if (model.IsEmpty()) {
			// If model is empty, show an error message
			wxMessageBox("Model cannot be empty.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new model
		dataBase.UpdateVehicleModel(atoi(this->specificInputId->GetValue()), model.ToStdString());

		// Disable editing after saving
		this->specificInputModel->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditModelButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditEngineCapacityClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditEngineCapacityButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditEngineCapacityButton->SetLabel("Save");
		this->specficInputEngineCapacity->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Validate and retrieve the engine capacity
		wxString engineCapacityString = this->specficInputEngineCapacity->GetValue();
		double engineCapacity;

		// Check if the engine capacity is a valid positive number
		if (!engineCapacityString.ToDouble(&engineCapacity) || engineCapacity < 0.0) {
			// If not valid, show an error message
			wxMessageBox("Invalid Engine Capacity. Please enter a positive number.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new engine capacity
		dataBase.UpdateVehicleEngineCapacity(atoi(this->specificInputId->GetValue()), engineCapacity);

		// Disable editing after saving
		this->specficInputEngineCapacity->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditEngineCapacityButton->SetLabel("Edit");
	}
}

void FrameApp::OnButtonEditBodyTypeClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditBodyTypeButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditBodyTypeButton->SetLabel("Save");
		this->specificInputBodyType->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Validate and retrieve the body type
		wxString bodyType = this->specificInputBodyType->GetValue();

		// Check if the body type is empty
		if (bodyType.IsEmpty()) {
			// If empty, show an error message
			wxMessageBox("Body Type cannot be empty.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new body type
		dataBase.UpdateVehicleBodyType(atoi(this->specificInputId->GetValue()), bodyType.ToStdString());

		// Disable editing after saving
		this->specificInputBodyType->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditBodyTypeButton->SetLabel("Edit");
	}
}
void FrameApp::OnButtonEditYearClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditYearButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditYearButton->SetLabel("Save");
		this->specificInputYear->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Validate and retrieve the year
		wxString yearString = this->specificInputYear->GetValue();
		long year;

		// Check if the year is a valid positive integer
		if (!yearString.ToLong(&year) || year < 0) {
			// If not valid, show an error message
			wxMessageBox("Invalid Year. Please enter a positive integer.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new year
		dataBase.UpdateVehicleProductionYear(atoi(this->specificInputId->GetValue()), year);

		// Disable editing after saving
		this->specificInputYear->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditYearButton->SetLabel("Edit");
	}
}

void FrameApp::OnButtonEditEnginePowerClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditEnginePowerButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditEnginePowerButton->SetLabel("Save");
		this->specificInputEnginePower->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Validate and retrieve the engine power
		wxString enginePowerString = this->specificInputEnginePower->GetValue();
		long enginePower;

		// Check if the engine power is a valid positive integer
		if (!enginePowerString.ToLong(&enginePower) || enginePower < 0) {
			// If not valid, show an error message
			wxMessageBox("Invalid Engine Power. Please enter a positive integer.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new engine power
		dataBase.UpdateVehicleEnginePower(atoi(this->specificInputId->GetValue()), enginePower);

		// Disable editing after saving
		this->specificInputEnginePower->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditEnginePowerButton->SetLabel("Edit");
	}
}

void FrameApp::OnButtonEditGearboxClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditGearboxButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditGearboxButton->SetLabel("Save");
		this->specificInputGearbox->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Validate and retrieve the gearbox
		wxString gearbox = this->specificInputGearbox->GetValue();

		// Check if the gearbox is empty
		if (gearbox.IsEmpty()) {
			// If empty, show an error message
			wxMessageBox("Gearbox cannot be empty.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new gearbox
		dataBase.UpdateVehicleGearbox(atoi(this->specificInputId->GetValue()), gearbox.ToStdString());

		// Disable editing after saving
		this->specificInputGearbox->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditGearboxButton->SetLabel("Edit");
	}
}

void FrameApp::OnButtonEditSeatingCapacityClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditSeatingCapacityButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditSeatingCapacityButton->SetLabel("Save");
		this->specificInputSeatingCapacity->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Validate and retrieve the seating capacity
		wxString seatingCapacityString = this->specificInputSeatingCapacity->GetValue();
		long seatingCapacity;

		// Check if the seating capacity is a valid positive integer
		if (!seatingCapacityString.ToLong(&seatingCapacity) || seatingCapacity < 0) {
			// If not valid, show an error message
			wxMessageBox("Invalid Seating Capacity. Please enter a positive integer.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new seating capacity
		dataBase.UpdateVehicleSeatingCapacity(atoi(this->specificInputId->GetValue()), seatingCapacity);

		// Disable editing after saving
		this->specificInputSeatingCapacity->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditSeatingCapacityButton->SetLabel("Edit");
	}
}

void FrameApp::OnButtonEditFuelTypeClicked(wxCommandEvent& evt)
{
	// Check if the button is in "Edit" mode
	if (adminEditFuelTypeButton->GetLabel() == "Edit") {
		// Switch to "Save" mode
		this->adminEditFuelTypeButton->SetLabel("Save");
		this->specificInputFuelType->SetEditable(true); // Enable editing
	}
	else {
		// Switch to "Edit" mode

		// Validate and retrieve the fuel type
		wxString fuelType = this->specificInputFuelType->GetValue();

		// Check if the fuel type is empty
		if (fuelType.IsEmpty()) {
			// If empty, show an error message
			wxMessageBox("Fuel Type cannot be empty.", "Error", wxICON_ERROR);
			return; // Exit the function
		}

		// Update the database with the new fuel type
		dataBase.UpdateVehicleFuelType(atoi(this->specificInputId->GetValue()), fuelType.ToStdString());

		// Disable editing after saving
		this->specificInputFuelType->SetEditable(false);

		// Change the button label back to "Edit"
		this->adminEditFuelTypeButton->SetLabel("Edit");
	}
}

void FrameApp::OnButtonDeleteClicked(wxCommandEvent& evt)
{
	// Get the ID of the selected vehicle from the list
	int idVehicle = atoi(this->infoListOfCar->GetItemText(this->selectedRowIndex, 0));
	// Delete the vehicle from the database
	dataBase.DeleteVehicle(idVehicle);
	// Update the vehicle panel list
	this->UpdateVehiclePanelList();
	// Display confirmation message for deleting the vehicle
	wxMessageBox("Vehicle deleted successfully");
}

void FrameApp::OnSearchInput(wxCommandEvent& evt)
{
	wxString inputText = evt.GetString();

	if (inputText.IsEmpty()) {
		this->UpdateVehiclePanelList();
		return;
	}
	else {
		this->infoListOfCar->DeleteAllItems();
		std::vector<Vehicle> vehicles;
		wxString choice = this->infoChoiceSearchBy->GetStringSelection();

		if (choice == "id" || choice == "mileage" || choice == "year") {
			long id;
			// Convert the price string to a int
			if (!inputText.ToLong(&id) || id < 0) {
				// If conversion fails or price is negative, show an error message
				wxMessageBox("Invalid Price. Please enter a positive number.", "Error", wxICON_ERROR);
				return; // Exit the function
			}
		}
		else if (choice == "price") {
			double price;
			// Convert the price string to a double
			if (!inputText.ToDouble(&price) || price < 0.0) {
				// If conversion fails or price is negative, show an error message
				wxMessageBox("Invalid Price. Please enter a positive number.", "Error", wxICON_ERROR);
				return; // Exit the function
			}
		}
		vehicles = this->dataBase.getVehicleWithFilter(choice.ToStdString(),
													   inputText.ToStdString());
		this->UpdateVehiclePanelList(vehicles);
	}
	evt.Skip();
}

void FrameApp::OnListItemSelected(wxListEvent& evt)
{
	this->selectedRowIndex = evt.GetIndex();
}

void FrameApp::UpdateVehiclePanelList()
{
	this->infoListOfCar->DeleteAllItems();

	int rowIndex = 0;

	for (auto& vehicle : dataBase.GetAllVehicles()) {
		this->infoListOfCar->InsertItem(rowIndex, wxString::Format("%d", vehicle.getId()));
		this->infoListOfCar->SetItem(rowIndex, 1, wxString::Format("%.2f", vehicle.getPrice()));
		this->infoListOfCar->SetItem(rowIndex, 2, wxString::Format("%d", vehicle.getMileage()));
		this->infoListOfCar->SetItem(rowIndex, 3, wxString(vehicle.getBrand()));
		this->infoListOfCar->SetItem(rowIndex, 4, wxString(vehicle.getModel()));
		this->infoListOfCar->SetItem(rowIndex, 5, wxString::Format("%d", vehicle.getProductionYear()));

		rowIndex++;
	}
}

void FrameApp::UpdateVehiclePanelList(std::vector<Vehicle>& vehicles)
{
	this->infoListOfCar->DeleteAllItems();

	int rowIndex = 0;

	for (auto& vehicle : vehicles) {
		this->infoListOfCar->InsertItem(rowIndex, wxString::Format("%d", vehicle.getId()));
		this->infoListOfCar->SetItem(rowIndex, 1, wxString::Format("%.2f", vehicle.getPrice()));
		this->infoListOfCar->SetItem(rowIndex, 2, wxString::Format("%d", vehicle.getMileage()));
		this->infoListOfCar->SetItem(rowIndex, 3, wxString(vehicle.getBrand()));
		this->infoListOfCar->SetItem(rowIndex, 4, wxString(vehicle.getModel()));
		this->infoListOfCar->SetItem(rowIndex, 5, wxString::Format("%d", vehicle.getProductionYear()));

		rowIndex++;
	}
}
