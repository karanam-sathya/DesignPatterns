/*
Factory pattern consists of a factory class which can produce one or more types of objects.
*/
#include<iostream>
#include<string>
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

int main()
{
    LabelFactory lblFactory;
    ILabel *label = lblFactory.createLabel("Header");
    label->setLabelTitle();
    cout << label->getLabelTitle() << endl;
    return 0;
}
