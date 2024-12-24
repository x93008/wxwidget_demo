#include "window1.h"

class MyApp : public wxApp {
public:
    virtual bool OnInit() {
        MyFrame* frame = new MyFrame("Transparent Window Example");
        frame->Show(true);
        return true;
    }
};

// IMPLEMENT_APP会替代main函数，windows上会使用WinMain函数
// 如果需要在初始化前做一些操作，可以在OnInit中做
IMPLEMENT_APP(MyApp);
