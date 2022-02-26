#include<ostream>

class String
{
public: 
    String();
    String(char* arr);
    String(const String& src);
    String(String&& src);
    ~String(); 
public:
    String& operator=(const String& rhs);
    String& operator=(String&& rhs);
public:
    String operator+(const String& rhs);
    char& operator[] (int pos);
    friend std::ostream& operator<<(std::ostream& os, const String& str);
public:
    int get_length(); 
    void push_back(char value);
    char& at(unsigned int pos);
private:

    char* m_buff{nullptr};
    unsigned int m_size{};
        
};