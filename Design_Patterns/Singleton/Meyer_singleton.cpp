#include <iostream>

class Singleton{
    private:
    Singleton(){
        std::cout << "An instance of Singleton class is created!\n";
    }

    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    public:
    // The return should be a reference to instance or a pointer to instance
    static Singleton& get_instance(){
        static Singleton instance;
        return instance;
    }

    // // Another variaton with pointer
    // static Singleton* get_instance(){
    //     static Singleton instance;
    //     return &instance;
    // }

    void showMessage(){
        std::cout << "Hello cutie, I am Meyer's Singleton!\n";
    }
};


int main(){

    Singleton& s1 = Singleton::get_instance();
    Singleton& s2 = Singleton::get_instance();

    if (&s1 == &s2){
        std::cout << "s1 and s2 are the same!\n";
    }else{
        std::cout << "s1 and s2 are not the same!\n";
    }

    s1.showMessage();


    return 0;
}