#include "PeselApp.h"
#include "MainFrame.h"

#include <wx/wx.h>

bool PeselApp::OnInit()
{
    MainFrame* mainFrame = new MainFrame();
    mainFrame->Show();

    return true;
}

wxIMPLEMENT_APP(PeselApp);