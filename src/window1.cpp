#include "window1.h"

MyFrame::MyFrame(const wxString& title):wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600), wxFRAME_NO_TASKBAR | wxFRAME_SHAPED | wxFRAME_FLOAT_ON_PARENT) {
    // 设置窗口透明度为 50%
    SetTransparent(128);
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    const int btn_id = 101;
    // 创建一个按钮作为示例
    wxButton* button = new wxButton(panel, btn_id, wxT("Quit"), wxPoint(20, 20));

    Connect(btn_id, wxEVT_COMMAND_BUTTON_CLICKED, 
            wxCommandEventHandler(MyFrame::OnQuit));
}

void MyFrame::OnQuit(wxCommandEvent & event) {
    Close(true);
}
