#include <wx/wx.h>

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

private:
    void SetRadius();
    // 测试其他线程修改窗口尺寸
    void OtherThreadChangeSize();

    void OnQuit(wxCommandEvent & event);
    void OnThreadEvent(wxThreadEvent& event);
};
