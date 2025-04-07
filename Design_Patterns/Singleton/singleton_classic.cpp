#include <iostream>

class Singleton{
    private:
    static Singleton* instance;

    Singleton(){
        std::cout << "An instance of class Singleton is created!\n";
    }

    // Delete copy constructor and copy assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    public:
    static Singleton* get_instance(){
        if (!instance){
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage(){
        std::cout << "Hello cutie, I am your Sngleton, truely signle!\n";
    }

};

Singleton* Singleton::instance = nullptr;

int main(){

    Singleton* s1 = Singleton::get_instance();
    Singleton* s2 = Singleton::get_instance();

    if (s1 == s2){
        std::cout << "s1 and s2 are the same!\n";
    }

    s1->showMessage();
    return 0;
}