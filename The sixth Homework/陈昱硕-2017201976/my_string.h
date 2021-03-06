#ifndef MY_STRING_H
#define MY_STRING_H

#include <cstddef>
#include <cstring>

#include <iostream>

class MyString{
private:
    static const size_t kCinLimit_;
    static size_t number_of_strings_;
    size_t length_, size_;
    char *str_;

public:
    static const size_t npos;

    MyString();
    MyString(const char *str);
    MyString(const MyString &str);

    size_t length() const{return length_;}
    static size_t howmany(){return number_of_strings_;}
    char & operator [] (size_t idx){return str_[idx];}
    const char & operator [] (size_t idx) const{return str_[idx];}

    MyString & operator = (const MyString &str);
    MyString & operator += (const MyString &str);
    friend const MyString operator + (const MyString &s1, const MyString &s2);

    char *c_str(){return str_;}
    const char *c_str() const {return str_;}

    char *begin(){return str_;}
    const char *begin() const {return str_;}
    const char *cbegin() const {return str_;}

    char *end(){return str_ + length_;}
    const char *end() const {return str_ + length_;}
    const char *cend() const {return str_ + length_;}

    void append(const char ch);
    char *find(const char ch);
    void erase(char *beg, char *ed);
    void erase(char *beg){erase(beg, end());}

    const MyString substr(const char *beg, size_t len = npos);

#define makeoper(op) \
    const bool operator op (const MyString &str) const{\
        return strcmp(str_, str.str_) op 0;\
    }
    makeoper(< )
    makeoper(<=)
    makeoper(> )
    makeoper(>=)
    makeoper(==)
    makeoper(!=)
#undef makeoper

    friend std :: istream & operator >> (std :: istream &is, MyString &str);
    friend std :: ostream & operator << (std :: ostream &os, const MyString &str);

    virtual ~MyString();
};

#endif