/***************************************************************
 * Name:      S2WApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2014-12-06
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "S2WApp.h"

//(*AppHeaders
#include "S2WMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(S2WApp);

bool S2WApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	S2WFrame* Frame = new S2WFrame(0);
    	Frame->myInit();
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
