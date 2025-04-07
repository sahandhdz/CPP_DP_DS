#include <iostream>
#include <memory>

class Singleton{
    private:
    static std::unique_ptr<Singleton> instance;

    // Private constructor
    Singleton(){
        std::cout << "An instance of Singleton class is created!\n";
    }

    // Delete copy constructor and copy assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // declaring std::make_unique<Singleton> as a friend
    friend std::unique_ptr<Singleton> std::make_unique<Singleton>();

    public:
    static Singleton* get_instance(){
        if (!instance){
            // It works only if make_singleton is declared as a friend to the class, 
            // allwoing it to access the private constructor.
            instance = std::make_unique<Singleton>();

            // It works well!
            //instance = std::unique_ptr<Singleton>(new Singleton());
        }
        return instance.get();
    }

    void showMessage(){
        std::cout << "hello, I am a modern Singleton!\n";
    }
};

std::unique_ptr<Singleton> Singleton::instance = nullptr;

int main(int argc, char **argv)
{
    Singleton* s1;
    Singleton* s2;
    
    s1 = Singleton::get_instance();
    s2 = Singleton::get_instance();
    
    if (s1 == s2){
        std::cout << "s1 and s2 are the same!\n";
    }
    
    s1->showMessage();

    
	return 0;
}