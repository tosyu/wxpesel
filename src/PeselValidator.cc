#include "PeselValidator.h"

#include <wx/wx.h>
#include <array>

std::array<unsigned short int, 11> multipliers = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3, 1};

bool PeselValidator::Validate(wxString pesel)
{
    if (pesel.size() != 11)
        return false;

    int sum = 0;
    for (int i = 0; i < pesel.size(); i++)
    {
        sum += (unsigned int)(pesel.at(i)) * multipliers.at(i);
    }

    return sum % 10 == 0;
}