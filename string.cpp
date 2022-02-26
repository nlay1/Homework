#include "string.h"
#include<string.h>
#include<iostream>

String:: String()
    : m_buff(new char[1]) , m_size(0)
{
}

String::~String()
{
    delete[] m_buff;
    m_buff = nullptr;
}

String :: String(char* arr)
    
{
    if(arr)
    {
        m_size = strlen(arr);
        m_buff = new char[m_size];
        strcpy(m_buff, arr);
        m_buff[m_size] = '\0';
    }
    else
    {
        m_size = 0; 
        m_buff = nullptr;
    }
}
String :: String(const String& src)
{
    m_size = src.m_size;
    delete[] m_buff;
    m_buff = new char[m_size];
    for(int i = 0; i<m_size; ++i)
    {
        m_buff[i] = src.m_buff[i]; 
    }
    m_buff[m_size]  = '\0';
}

String :: String(String&& src)
{
    m_size = src.m_size;
    m_buff = src.m_buff;
    src.m_buff = nullptr;
    src.m_size = 0;
}

String& String::operator=(const String& rhs)
{
    if(this == &rhs)
    {
        return *this;
    } else if(m_buff)
    {
        delete[] m_buff;
    }
    m_size = rhs.m_size;
    m_buff = new char[m_size];
    for(int i = 0; i < m_size; ++i)
    {
        m_buff[i] = rhs.m_buff[i];
    }
    m_buff[m_size] = '\0';
    return *this;
}

String& String::operator=(String&& rhs)
{
    if(m_buff)
    {
        delete[] m_buff;
    }
    m_size = rhs.m_size;
    m_buff = rhs.m_buff;
    rhs.m_size = 0;
    rhs.m_buff = nullptr;
    return *this;
}

String String:: operator+(const String& rhs)
{
    
    String sum;
    sum.m_size = strlen(m_buff) + strlen(rhs.m_buff);
    int j{};
    for(int i = 0; i<m_size; ++i)
    {
        sum.m_buff[i] = m_buff[j];
        ++j;
    }
    int k{};
    for(int i = m_size; i<sum.m_size; ++i)
    {
        sum.m_buff[i] = rhs.m_buff[k];
        ++k;
    }
    sum.m_buff[sum.m_size] = '\0';
    return sum;
}
char& String::operator[](int pos)
{
    return m_buff[pos];
}

std::ostream& operator<< (std::ostream& os, const String& str)
{
    for(int i = 0; i <= str.m_size; ++i)
    {
        os << str.m_buff[i];
    }
    return os;
}

int String :: get_length() 
{
    return m_size;
}

void String :: push_back(char value)
{
    ++m_size;
    char* ptr = new char[m_size];
    for(int i = 0; i<m_size; ++i)
    {
        ptr[i] = m_buff[i];
    }
    delete[] m_buff;
    m_buff = ptr;
    ptr = nullptr;
    m_buff[m_size] = value;
    ++m_size;
    m_buff[m_size] = '\0';

}

char& String :: at(unsigned int pos)
{
    if(pos > m_size)
    {
        std::cout << "Out of range";
        return m_buff[m_size];
    }
    return m_buff[pos];
}