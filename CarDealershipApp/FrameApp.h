#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>
#include "DataBaseConnector.h"

class FrameApp: public wxFrame
{
public:
	FrameApp(const wxString& title);

	void OnColumnClick(wxListEvent& event);

	void OnButtonEnterUserClicked(wxCommandEvent& evt);
	
	void OnButtonEnterAdminClicked(wxCommandEvent& evt);
	
	void OnButtonEnterRegister(wxCommandEvent& evt);
	
	void OnButtonLoginClicked(wxCommandEvent& evt);
	
	void OnButtonRegisterClicked(wxCommandEvent& evt);

	void OnButtonLoginBackClicked(wxCommandEvent& evt);
	
	void OnButtonRegisterBackClicked(wxCommandEvent& evt);
	
	void OnButtonInfoBackClicked(wxCommandEvent& evt);

	void OnButtonSpecificBackClicked(wxCommandEvent& evt);

	void OnButtonSpecificEnterClicked(wxCommandEvent& evt);




private:
	
	bool adminLogged;

	wxPanel* initialPanel;
	DataBaseConnector dataBase;

	wxStaticText* initialStaticText;
	wxButton* initialButtonEnterUser;
	wxButton* initialButtonEnterAdmin;

	wxButton* loginButtonBack;
	wxPanel* loginPanel;
	wxStaticText* loginStaticTextLogin;
	wxTextCtrl* loginUsernameInput;
	wxStaticText* loginUsernameLabel;
	wxTextCtrl* loginPasswordInput;
	wxStaticText* loginPasswordLabel;
	wxButton* loginButton;
	wxStaticText* loginStaticTextDont;
	wxButton* loginButtonEnterRegister;


	wxButton* registerButtonBack;
	wxPanel* registerPanel;
	wxStaticText* registerStaticTextLogin;
	wxTextCtrl* registerUsernameInput;
	wxStaticText* registerUsernameLabel;
	wxTextCtrl* registerPasswordInput;
	wxStaticText* registerPasswordLabel;
	wxTextCtrl* registerPasswordInputRepeat;
	wxStaticText* registerPasswordLabelRepeat;
	wxTextCtrl* registerCodeInput;
	wxStaticText* registerCodeLabel;
	wxButton* registerButton;

	wxButton* infoButtonBack;
	wxPanel* infoPanel;
	wxStaticText* infoStaticHeaderText;
	wxListCtrl* infoListOfCar;
	wxTextCtrl* infoSearchInput;
	wxChoice* infoChoiceSearchBy;
	wxButton* infoSearchButton;
	wxButton* infoButtonEnterSpecific;
	wxArrayString* infoChoices;

	wxButton* specificButtonBack;
	wxPanel* specicInfoPanel;

	wxButton* infoButtonBackAdmin;

	wxStaticText* specificlabelId;
	wxTextCtrl* specificInputId;
	wxStaticText* specificLabelMileage;
	wxTextCtrl* specificInputMileage;
	wxStaticText* specificLabelPrice;
	wxTextCtrl* specificInputPrice;
	wxStaticText* specificLabelBrand;
	wxTextCtrl* specificInputBrand;
	wxStaticText* specificLabelModel;
	wxTextCtrl* specificInputModel;
	wxStaticText* specificLabelEngineCapacity;
	wxTextCtrl* specficInputEngineCapacity;
	wxStaticText* specificLabelBodyType;
	wxTextCtrl* specificInputBodyType;
	wxStaticText* specificLabelYear;
	wxTextCtrl* specificInputYear;
	wxStaticText* specificLabelEnginePower;
	wxTextCtrl* specificInputEnginePower;
	wxStaticText* specificLabelGearbox;
	wxTextCtrl* specificInputGearbox;
	wxStaticText* specificLabelSeatingCapacity;
	wxTextCtrl* specificInputSeatingCapacity;
	wxStaticText* specificLabelFuelType;
	wxTextCtrl* specificInputFuelType;


	wxButton* adminEnterAddPanel;
	wxButton* adminEditIdButton;
	wxButton* adminEditMileageButton;
	wxButton* adminEditPriceButton;
	wxButton* adminEditBrandButton;
	wxButton* adminEditModelButton;
	wxButton* adminEditEngineCapacityButton;
	wxButton* adminEditBodyTypeButton;
	wxButton* adminEditYearButton;
	wxButton* adminEditEnginePowerButton;
	wxButton* adminEditGearboxButton;
	wxButton* adminEditSeatingCapacityButton;
	wxButton* adminEditFuelTypeButton;
	
	wxPanel* adminAddPanel;
	wxButton* adminAddPanelSubmit;
	wxStaticText* addLabelId;
	wxTextCtrl* addInputId;
	wxStaticText* addLabelMileage;
	wxTextCtrl* addInputMileage;
	wxStaticText* addLabelPrice;
	wxTextCtrl* addInputPrice;
	wxStaticText* addLabelBrand;
	wxTextCtrl* addInputBrand;
	wxStaticText* addLabelModel;
	wxTextCtrl* addInputModel;
	wxStaticText* addLabelEngineCapacity;
	wxTextCtrl* addInputEngineCapacity;
	wxStaticText* addLabelBodyType;
	wxTextCtrl* addInputBodyType;
	wxStaticText* addLabelYear;
	wxTextCtrl* addInputYear;
	wxStaticText* addLabelEnginePower;
	wxTextCtrl* addInputEnginePower;
	wxStaticText* addLabelGearbox;
	wxTextCtrl* addInputGearbox;
	wxStaticText* addLabelSeatingCapacity;
	wxTextCtrl* addInputSeatingCapacity;
	wxStaticText* addLabelFuelType;
	wxTextCtrl* addInputFuelType;
	wxButton* addButtonBack;


	
	wxFont fontHeaderText;
	wxFont fontButtonText;
	


};

