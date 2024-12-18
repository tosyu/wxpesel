#include "MainFrame.h"
#include "PeselValidator.h"

#include <wx/wx.h>
#include <wx/textctrl.h>

MainFrame::MainFrame() : wxFrame(nullptr, wxID_ANY, "Pesel verifier", wxDefaultPosition, wxSize(400, 120), wxDEFAULT_FRAME_STYLE ^ wxRESIZE_BORDER)
{
    this->CreateMainForm();
}

void MainFrame::CreateMainForm()
{
    wxPanel* container = new wxPanel(this);
    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);

    wxTextValidator numberValidator = wxTextValidator(wxFILTER_INCLUDE_CHAR_LIST);

    numberValidator.AddCharIncludes("0123456789");
    
    peselInput = new wxTextCtrl(container, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(200, -1), 0, numberValidator);
    wxButton* submitButton = new wxButton(container, wxID_ANY, "Check");

    wxSizerFlags sizerFlags = wxSizerFlags().Proportion(0).Center().Border(wxALL, 10);

    sizer->AddStretchSpacer();
    sizer->Add(peselInput, sizerFlags);
    sizer->Add(submitButton, sizerFlags);
    sizer->AddStretchSpacer();

    container->SetSizer(sizer);
    sizer->SetSizeHints(this);
    this->SetClientSize(400, 120);

    submitButton->Bind(wxEVT_BUTTON, &MainFrame::OnCheck, this);
}

void MainFrame::OnCheck(wxCommandEvent &event)
{
    if (PeselValidator::Validate(peselInput->GetValue()))
    {
        wxMessageBox("Pesel is valid", "Result", wxICON_INFORMATION);
    } else {
        wxMessageBox("Pesel is not valid", "Result", wxICON_ERROR);
    }
}
