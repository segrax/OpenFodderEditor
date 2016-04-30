///-----------------------------------------------------------------
///
/// @file      DialogCreateMap.cpp
/// @author    Robbie
/// Created:   1/05/2016 08:48:33
/// @section   DESCRIPTION
///            cDialogCreateMap class implementation
///
///------------------------------------------------------------------

#include "DialogCreateMap.h"

//Do not add custom headers
//wxDev-C++ designer will remove them
////Header Include Start
////Header Include End

#include "stdafx.hpp"

//----------------------------------------------------------------------------
// cDialogCreateMap
//----------------------------------------------------------------------------
//Add Custom Events only in the appropriate block.
//Code added in other places will be removed by wxDev-C++
////Event Table Start
BEGIN_EVENT_TABLE(cDialogCreateMap,wxDialog)
	////Manual Code Start
	////Manual Code End
	
	EVT_CLOSE(cDialogCreateMap::OnClose)
	EVT_BUTTON(ID_WXBUTTON1,cDialogCreateMap::ButtonCreateMap)
END_EVENT_TABLE()
////Event Table End

cDialogCreateMap::cDialogCreateMap(wxWindow *parent, wxWindowID id, const wxString &title, const wxPoint &position, const wxSize& size, long style)
: wxDialog(parent, id, title, position, size, style)
{
	CreateGUIControls();
}

cDialogCreateMap::~cDialogCreateMap()
{
} 

void cDialogCreateMap::CreateGUIControls()
{
	//Do not add custom code between
	//GUI Items Creation Start and GUI Items Creation End.
	//wxDev-C++ designer will remove them.
	//Add the custom code before or after the blocks
	////GUI Items Creation Start

	WxEdit2 = new wxTextCtrl(this, ID_WXEDIT2, _("15"), wxPoint(102, 70), wxSize(76, 23), 0, wxDefaultValidator, _("WxEdit2"));

	WxEdit1 = new wxTextCtrl(this, ID_WXEDIT1, _("20"), wxPoint(98, 28), wxSize(90, 22), 0, wxDefaultValidator, _("WxEdit1"));

	wxArrayString arrayStringFor_WxComboBox1;
	arrayStringFor_WxComboBox1.Add(_("Jungle"));
	arrayStringFor_WxComboBox1.Add(_("Desert"));
	arrayStringFor_WxComboBox1.Add(_("Ice"));
	arrayStringFor_WxComboBox1.Add(_("Moors"));
	arrayStringFor_WxComboBox1.Add(_("Interrior"));
	arrayStringFor_WxComboBox1.Add(_("HID"));
	arrayStringFor_WxComboBox1.Add(_("Amiga Format Christmas Special"));
	WxComboBox1 = new wxComboBox(this, ID_WXCOMBOBOX1, _("Jungle"), wxPoint(32, 123), wxSize(226, 23), arrayStringFor_WxComboBox1, 0, wxDefaultValidator, _("WxComboBox1"));

	WxButton1 = new wxButton(this, ID_WXBUTTON1, _("Create It"), wxPoint(83, 205), wxSize(119, 27), 0, wxDefaultValidator, _("WxButton1"));

	SetTitle(_("Create Map"));
	SetIcon(wxNullIcon);
	SetSize(8,8,320,277);
	Center();
	
	////GUI Items Creation End
}

void cDialogCreateMap::OnClose(wxCloseEvent& /*event*/) {

	Destroy();
}

/*
 * ButtonCreateMap
 */
void cDialogCreateMap::ButtonCreateMap(wxCommandEvent& event) {

	size_t Width = wxAtoi(WxEdit1->GetValue());
	size_t Height = wxAtoi(WxEdit2->GetValue());

	eTileTypes Tile = (eTileTypes) WxComboBox1->GetSelection();

	g_OFED.CreateMap( Tile, Width, Height );

	Close();
}

