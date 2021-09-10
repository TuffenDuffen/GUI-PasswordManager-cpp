﻿#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(3, cMain::OnEnter)
wxEND_EVENT_TABLE()

cMain::cMain() : wxFrame(nullptr, 0, "Password Manager", wxDefaultPosition,  wxSize(800, 600))
{
    Filer = new cFiler("data");
    if(!Filer->New)
    {
        Login = new cLogin(this);
    }
    
}

cMain::~cMain()
{
    
}

void cMain::OnEnter(wxCommandEvent& event)
{
    if(Login->Input->GetValue() == Filer->File[0]) Login->Text->SetLabel("IN!!");
    event.Skip();
}