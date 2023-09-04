/* Abstract factory pattern can be defined as factory of factories. Abstract factory defines an abstract class
for creating families of related objects, but without specifying their concrete sub-class*/
/*When we need our system to be independent of how objects are created. It allows clients to create objects
without knowing their specific implementations, promoting loose coupling between the client code
and the concrete classes*/
// Factory Method is used to hide the complexity of the object creation to client code

#include <iostream>
#include <string>
using namespace std;

//Interface
class ILabel
{
protected:
    string title;
public:
    virtual void setLabelTitle() = 0;
    virtual string getLabelTitle() = 0;
};

//Concrete Class1
class Header : public ILabel
{
public:
    void setLabelTitle()
    {
        this->title = "Header";
    }
    string getLabelTitle()
    {
        return this->title;
    }
};

//Concrete Class2
class Footer : public ILabel
{
public:
    void setLabelTitle()
    {
        this->title = "Footer";
    }
    string getLabelTitle()
    {
        return this->title;
    }
};

//Factory class
class LabelFactory
{
public:
    ILabel * createLabel(string labelType)
    {
        if (labelType == "Header")
            return new Header();
        else
            return new Footer;
    }
};

//Interface for Window
class IWindow
{
protected:
    string windowType;
public:
    virtual void setWindowType() = 0;
    virtual string getWindowType() = 0;
};
//Concrete class1
class SmallWindow : public IWindow
{
public:
    void setWindowType()
    {
        this->windowType = "Small Window";
    }
    string getWindowType()
    {
        return this->windowType;
    }
};
//Concrete class2
class BigWindow : public IWindow
{
public:
    void setWindowType()
    {
        this->windowType = "Big Window";
    }
    string getWindowType()
    {
        return this->windowType;
    }
};
//Factory Class
class WindowFactory
{
public:
    IWindow * createWindow(string windowType)
    {
        if (windowType == "Small")
            return new SmallWindow();
        else
            return new BigWindow();
    }
};

class AbstractFactory
{
public:
    virtual void createLabelFactory()=0;
    virtual void createWindowFactory()=0;
};

class smallGUI:public AbstractFactory
{
public:
    void createLabelFactory()
    {
        LabelFactory lblFactory;
        ILabel *label = lblFactory.createLabel("Footer");
        label->setLabelTitle();
        cout << label->getLabelTitle() << endl;

    }
    void createWindowFactory()
    {
        WindowFactory windowFactory;
        IWindow *window = windowFactory.createWindow("Small");
        window->setWindowType();
        cout << window->getWindowType() << endl;
    }
};
class bigGUI:public AbstractFactory
{
public:
    void createLabelFactory()
    {
        LabelFactory lblFactory;
        ILabel *label = lblFactory.createLabel("Header");
        label->setLabelTitle();
        cout << label->getLabelTitle() << endl;
    }
    void createWindowFactory()
    {
        WindowFactory windowFactory;
        IWindow *window = windowFactory.createWindow("Big");
        window->setWindowType();
        cout << window->getWindowType() << endl;
    }

};

int main()
{
    AbstractFactory *abs = new smallGUI();
    abs->createLabelFactory();
    abs->createWindowFactory();
    delete abs;
    abs = new bigGUI();
    abs->createLabelFactory();
    abs->createWindowFactory();
    return 0;

}
