#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600), wxFRAME_NO_TASKBAR | wxFRAME_SHAPED)
    {
        // 设置窗口透明度为 50%
        SetTransparent(128);

        // 创建一个按钮作为示例
        wxButton* button = new wxButton(this, wxID_ANY, "Click Me", wxPoint(10, 10));
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame("Transparent Window Example");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
