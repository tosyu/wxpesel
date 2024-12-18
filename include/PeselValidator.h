#pragma once

#include <wx/wx.h>

class PeselValidator
{
public:
    static bool Validate(wxString pesel);
};
