#include "window1.h"

#include <cstdio>
#include <thread>

#include "wx/graphics.h"


MyFrame::MyFrame(const wxString& title)
    :wxFrame(NULL, wxID_ANY, title,
            wxDefaultPosition,
            wxSize(800, 600),
            0 // 占位符，方便任意注释下面的行
            | wxFRAME_SHAPED // 允许任意形状,没有此标志位无法调用SetShape
            | wxSIMPLE_BORDER // 简单border,不要标题栏
            // | wxFRAME_NO_TASKBAR // 不要显示任务栏
            // | wxSTAY_ON_TOP // 置顶
            ) {
    // 设置窗口透明度
    SetTransparent(244);
    wxPanel *panel = new wxPanel(this, wxID_ANY);

    // 创建一个按钮作为示例
    wxButton* button = new wxButton(panel, wxID_ANY, wxT("Quit"), wxPoint(20, 20));
    button->GetId();

    Connect(button->GetId(), wxEVT_COMMAND_BUTTON_CLICKED,
            wxCommandEventHandler(MyFrame::OnQuit));
    Bind(wxEVT_THREAD, &MyFrame::OnThreadEvent, this);
    SetRadius();

    OtherThreadChangeSize();
}

void MyFrame::SetRadius() {
    // 获取窗口的大小
    wxSize size = GetClientSize();

    // 创建一个 wxGraphicsPath 对象
    wxGraphicsPath path = wxGraphicsRenderer::GetDefaultRenderer()->CreatePath();

    // 添加圆角矩形路径
    path.AddRoundedRectangle(0, 0, size.GetWidth(), size.GetHeight(), 20.0);

    // 设置窗口形状
    SetShape(path);
}

void MyFrame::OtherThreadChangeSize() {
    // 创建并启动 std::thread
    std::thread([this]() {
            // 模拟一些工作
            std::this_thread::sleep_for(std::chrono::seconds(2));

            // 创建一个 wxThreadEvent 事件，并设置新的窗口大小
            wxThreadEvent event(wxEVT_THREAD);
            event.SetPayload(wxSize(1280, 960));

            // 使用 wxQueueEvent 方法将事件发送到主线程的 this 对象
            wxQueueEvent(this, event.Clone());
            printf("xxxxxxxx\n");
        }).detach();
}

void MyFrame::OnQuit(wxCommandEvent & event) {
    Close(true);
}

void MyFrame::OnThreadEvent(wxThreadEvent& event) {
    // 从事件中获取新的窗口大小
    wxSize newSize = event.GetPayload<wxSize>();
    SetSize(newSize);
    SetRadius();
}

