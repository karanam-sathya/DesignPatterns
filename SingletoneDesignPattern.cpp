#include<iostream>
using namespace std;

//Eager Loading Singleton example
class EagerLoadingSingleton
{
    static EagerLoadingSingleton Singleton;
    EagerLoadingSingleton()=default;
public:
    static EagerLoadingSingleton& getInstance ()
    {
        return Singleton;
    }
    EagerLoadingSingleton(const EagerLoadingSingleton&)=delete;
    EagerLoadingSingleton(EagerLoadingSingleton&&)=delete;
    EagerLoadingSingleton& operator=(const EagerLoadingSingleton &)=delete;
    EagerLoadingSingleton& operator=(EagerLoadingSingleton&&) = delete;
};
EagerLoadingSingleton EagerLoadingSingleton::Singleton;
typedef EagerLoadingSingleton& ELS;

//Lazy Loading Singleton example
class LazyLoadingSingleton
{
    static LazyLoadingSingleton * Singleton;
    LazyLoadingSingleton() = default;
public:
    static LazyLoadingSingleton& getInstance ()
    {
        if (Singleton == nullptr)
        {
            Singleton = new LazyLoadingSingleton();
        }
        return *Singleton;
    }
    LazyLoadingSingleton(const LazyLoadingSingleton&)=delete;
    LazyLoadingSingleton(LazyLoadingSingleton&&)=delete;
    LazyLoadingSingleton& operator=(const LazyLoadingSingleton &)=delete;
    LazyLoadingSingleton& operator=(LazyLoadingSingleton&&) = delete;
};
LazyLoadingSingleton* LazyLoadingSingleton::Singleton = nullptr;
typedef LazyLoadingSingleton& LLS;


int main()
{
    ELS instance1 = EagerLoadingSingleton::getInstance();

    LLS instance2 = LazyLoadingSingleton::getInstance();

    return 0;
}
