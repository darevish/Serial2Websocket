/***************************************************************
 * Name:      S2WMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2014-12-06
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef S2WMAIN_H
#define S2WMAIN_H

#include <iterator>
#include <boost/filesystem.hpp>

#include "SerialLink.hpp"
#include "WebsocketLink.hpp"

#include <boost/thread.hpp>

//(*Headers(S2WFrame)
#include <wx/spinctrl.h>
#include <wx/combobox.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class S2WFrame: public wxFrame
{
    public:

        S2WFrame(wxWindow* parent,wxWindowID id = -1);
        void myInit();
        virtual ~S2WFrame();

    private:

        //(*Handlers(S2WFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnStartButtonClick(wxCommandEvent& event);
        void OnStopButtonClick(wxCommandEvent& event);
        //*)

        void setIsRunningStateOnGUI(bool _isRunning);
        void stopTunnel();

        //(*Identifiers(S2WFrame)
        static const long ID_STATICTEXT1;
        static const long ID_SPINCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_COMBOBOX1;
        static const long ID_STATICTEXT4;
        static const long ID_SPINCTRL2;
        // static const long ID_STATICTEXT3;
        // static const long ID_TEXTCTRL1;
        static const long ID_STATICTEXT5;
        static const long ID_STATICTEXT6;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(S2WFrame)
        wxButton* StopButton;
        wxPanel* Panel1;
        // wxTextCtrl* EmptyMsgTextCtrl;
        wxStatusBar* StatusBar1;
        wxComboBox* SerialPortNameComboBox;
        wxStaticText* IsRunningStaticText;
        wxStaticText* StaticText1;
        wxButton* StartButton;
        // wxStaticText* StaticText3;
        wxSpinCtrl* BaudRateSpinCtrl;
        wxSpinCtrl* WSPortNumberSpinCtrl;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText2;
        //*)

        DECLARE_EVENT_TABLE()


        boost::asio::io_service *io_service;
        boost::thread *backgroundThread_p;

        SerialLink *serialLink_p;
        WebsocketLink *websocketLink_p;

        bool tunnelIsActive;
};

#endif // S2WMAIN_H
