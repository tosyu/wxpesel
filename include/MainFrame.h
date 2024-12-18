#pragma once

#include <wx/wx.h>

class MainFrame : public wxFrame
{
public:
        MainFrame();
private:
    wxTextCtrl* peselInput;

    void CreateMainForm();
    void OnCheck(wxCommandEvent& event);
};