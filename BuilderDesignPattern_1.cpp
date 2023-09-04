#include<iostream>
#include<string>
using namespace std;

class DesktopProduct
{
    string monitor;
    string keyboard;
    string ram;
    string processor;
public:
    void setMonitor(string monitor) {this->monitor=monitor;}
    void setKeyboard(string keyboard) {this->keyboard=keyboard;}
    void setRam(string ram) {this->ram=ram;}
    void setProcessor(string processor) {this->processor=processor;}
    void showSpecs()
    {
        cout << "---------------------------------------------" << endl;
        cout << "Monitor   : " << monitor << endl;
        cout << "Keyboard  : " << keyboard << endl;
        cout << "Ram       : " << ram << endl;
        cout << "Processor : " << processor << endl;
        cout << "--------------------------------------------" << endl;
    }
};

class DesktopBuilder
{
protected:
    DesktopProduct *desktop;
public:
    DesktopBuilder() { desktop = new DesktopProduct();}
    virtual void buildMonitor () = 0;
    virtual void buildKeyboard () = 0;
    virtual void buildRam () = 0;
    virtual void buildProcessor () = 0;
    virtual DesktopProduct * getDesktop()
    {
        return desktop;
    }
};

class DellDesktop : public DesktopBuilder
{
public:
    void buildMonitor() override {desktop->setMonitor("Dell 27 inch Monitor");}
    void buildKeyboard() override {desktop->setKeyboard("Dell Keyboard");}
    void buildRam() override {desktop->setRam("32 GB RAM");}
    void buildProcessor() override {desktop->setProcessor("Intel Core I7 12th Gen");}
};

class HPDesktop : public DesktopBuilder
{
public:
    void buildMonitor() override {desktop->setMonitor("HP 21 inch Monitor");}
    void buildKeyboard() override {desktop->setKeyboard("HP Keyboard");}
    void buildRam() override {desktop->setRam("16 GB RAM");}
    void buildProcessor() override {desktop->setProcessor("Intel Core I5 10th Gen");}
};


class DesktopDirector
{
    DesktopBuilder *desktopBuilder;
public:
    DesktopDirector(DesktopBuilder *desktopBuilder) {this->desktopBuilder=desktopBuilder;}
    DesktopProduct * BuildDesktop()
    {
        desktopBuilder->buildMonitor();
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildRam();
        desktopBuilder->buildProcessor();
        return desktopBuilder->getDesktop();
    }
};


int main()
{
    DellDesktop *dellDesktop = new DellDesktop();
    DesktopDirector *desktopDirector1 = new DesktopDirector(dellDesktop);
    DesktopProduct* desktop1 = desktopDirector1->BuildDesktop();
    desktop1->showSpecs();

    delete dellDesktop;
    delete desktopDirector1;

    return 0;
}
