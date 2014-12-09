/***************************************************************
 * Name:      S2WMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2014-12-06
 * Copyright:  ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "S2WMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(S2WFrame)
#include <wx/string.h>
#include <wx/intl.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(S2WFrame)
const long S2WFrame::ID_STATICTEXT1 = wxNewId();
const long S2WFrame::ID_SPINCTRL1 = wxNewId();
const long S2WFrame::ID_STATICTEXT2 = wxNewId();
const long S2WFrame::ID_COMBOBOX1 = wxNewId();
const long S2WFrame::ID_STATICTEXT4 = wxNewId();
const long S2WFrame::ID_SPINCTRL2 = wxNewId();
const long S2WFrame::ID_STATICTEXT3 = wxNewId();
const long S2WFrame::ID_TEXTCTRL1 = wxNewId();
const long S2WFrame::ID_STATICTEXT5 = wxNewId();
const long S2WFrame::ID_STATICTEXT6 = wxNewId();
const long S2WFrame::ID_BUTTON1 = wxNewId();
const long S2WFrame::ID_BUTTON2 = wxNewId();
const long S2WFrame::ID_PANEL1 = wxNewId();
const long S2WFrame::idMenuQuit = wxNewId();
const long S2WFrame::idMenuAbout = wxNewId();
const long S2WFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(S2WFrame,wxFrame)
    //(*EventTable(S2WFrame)
    //*)
END_EVENT_TABLE()

S2WFrame::S2WFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(S2WFrame)
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem1;
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxMenu* Menu1;
    wxBoxSizer* BoxSizer2;
    wxFlexGridSizer* FlexGridSizer4;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxFlexGridSizer* FlexGridSizer3;
    wxBoxSizer* BoxSizer1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer1;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    FlexGridSizer1->AddGrowableCol(0);
    FlexGridSizer1->AddGrowableRow(2);
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Websocket"));
    FlexGridSizer2 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer2->AddGrowableCol(1);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Port number"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    FlexGridSizer2->Add(StaticText1, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    WSPortNumberSpinCtrl = new wxSpinCtrl(Panel1, ID_SPINCTRL1, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 65535, 0, _T("ID_SPINCTRL1"));
    WSPortNumberSpinCtrl->SetValue(_T("0"));
    FlexGridSizer2->Add(WSPortNumberSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Serial"));
    FlexGridSizer3 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer3->AddGrowableCol(1);
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Port name"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    SerialPortNameComboBox = new wxComboBox(Panel1, ID_COMBOBOX1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_COMBOBOX1"));
    SerialPortNameComboBox->Append(_("/dev/ttyACM0"));
    SerialPortNameComboBox->Append(_("/dev/ttyACM1"));
    FlexGridSizer3->Add(SerialPortNameComboBox, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Baud rate"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    FlexGridSizer3->Add(StaticText4, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    BaudRateSpinCtrl = new wxSpinCtrl(Panel1, ID_SPINCTRL2, _T("0"), wxDefaultPosition, wxDefaultSize, 0, 0, 1000000, 0, _T("ID_SPINCTRL2"));
    BaudRateSpinCtrl->SetValue(_T("0"));
    FlexGridSizer3->Add(BaudRateSpinCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Empty msg"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    FlexGridSizer3->Add(StaticText3, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 5);
    EmptyMsgTextCtrl = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("yourturn"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    FlexGridSizer3->Add(EmptyMsgTextCtrl, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer2->Add(FlexGridSizer3, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer2, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel1, _("Status"));
    FlexGridSizer4 = new wxFlexGridSizer(0, 2, 0, 0);
    FlexGridSizer4->AddGrowableCol(1);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _("Is running\?"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    FlexGridSizer4->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    IsRunningStaticText = new wxStaticText(Panel1, ID_STATICTEXT6, _("No"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
    IsRunningStaticText->SetForegroundColour(wxColour(193,0,0));
    FlexGridSizer4->Add(IsRunningStaticText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(FlexGridSizer4, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(StaticBoxSizer3, 1, wxBOTTOM|wxLEFT|wxRIGHT|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    StartButton = new wxButton(Panel1, ID_BUTTON1, _("Start"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(StartButton, 1, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StopButton = new wxButton(Panel1, ID_BUTTON2, _("Stop"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(StopButton, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(BoxSizer2, 1, wxTOP|wxBOTTOM|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 1, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    SetSizer(BoxSizer1);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    BoxSizer1->Fit(this);
    BoxSizer1->SetSizeHints(this);

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&S2WFrame::OnStartButtonClick);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&S2WFrame::OnStopButtonClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&S2WFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&S2WFrame::OnAbout);
    //*)
}

S2WFrame::~S2WFrame()
{
    if (tunnelIsActive) {
        stopTunnel();
    }
    //(*Destroy(S2WFrame)
    //*)
}

void S2WFrame::myInit()
{
    tunnelIsActive = false;

    WSPortNumberSpinCtrl->SetValue(9002);
    BaudRateSpinCtrl->SetValue(9600);

    boost::filesystem::path someDir("/sys/class/tty");
    boost::filesystem::directory_iterator end_iter;

    if ( boost::filesystem::exists(someDir) && boost::filesystem::is_directory(someDir)) {

        SerialPortNameComboBox->Clear();

        for( boost::filesystem::directory_iterator dir_iter(someDir) ; dir_iter != end_iter ; ++dir_iter) {
            std::string fileName("/dev/");
            fileName += dir_iter->path().filename().string();

            if ( boost::filesystem::exists(fileName)) {
                SerialPortNameComboBox->Append(fileName);
            }
        }
    }

    StopButton->Enable(false);

}

void S2WFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void S2WFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void S2WFrame::setIsRunningStateOnGUI(bool _isRunning)
{
    StopButton->Enable( _isRunning );
    StartButton->Enable( !_isRunning );
    SerialPortNameComboBox->Enable( !_isRunning );
    WSPortNumberSpinCtrl->Enable( !_isRunning );
    EmptyMsgTextCtrl->Enable( !_isRunning );
    BaudRateSpinCtrl->Enable( !_isRunning );

    if (_isRunning) {
        IsRunningStaticText->SetLabel("Yes");
        IsRunningStaticText->SetForegroundColour(wxColor(0, 130, 0));
    } else {
        IsRunningStaticText->SetLabel("No");
        IsRunningStaticText->SetForegroundColour(wxColor(193, 0, 0));
    }

    Layout();
}

void S2WFrame::OnStartButtonClick(wxCommandEvent& event)
{
    std::string device(SerialPortNameComboBox->GetValue());
    std::string emptyMessage(EmptyMsgTextCtrl->GetValue());
    unsigned int baudRate = (unsigned int)BaudRateSpinCtrl->GetValue();

    short websocketPort = (short)WSPortNumberSpinCtrl->GetValue();

    std::cout<<"aaaa"<<std::endl;

    try {
        serialLink_p = new SerialLink(io_service, device, emptyMessage, baudRate);
        websocketLink_p = new WebsocketLink(io_service, websocketPort);

        serialLink_p->setWebsocketLink(websocketLink_p);
        websocketLink_p->setSerialLink(serialLink_p);

        // io_service.run();
        backgroundThread_p = new boost::thread( boost::bind(&boost::asio::io_service::run, &io_service) );
    
        tunnelIsActive = true;
        
        std::cout<<"aaaa"<<std::endl;
    } catch (std::exception& e) {
        std::cout<<e.what()<<std::endl;
    }

    setIsRunningStateOnGUI(true);

}

void S2WFrame::stopTunnel()
{
    try {
        // serialLink_p->destroy();

        io_service.stop();

        backgroundThread_p->join();

        delete serialLink_p;
        delete websocketLink_p;
        delete backgroundThread_p;

        tunnelIsActive = false;

        std::cout<<"aaaa"<<std::endl;
    } catch (std::exception& e) {
        std::cout<<e.what()<<std::endl;
    }

}

void S2WFrame::OnStopButtonClick(wxCommandEvent& event)
{
    std::cout<<"aaaa"<<std::endl;
    stopTunnel();
    setIsRunningStateOnGUI(false);

}
