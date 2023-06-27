#pragma once
using namespace std;
#include <string>

class Exceptions
{
protected:
    string message;
public:
    Exceptions(string message) :message(message) {};
    const string printExp() const { return message; }
};
class BirthdayException :public Exceptions
{
public:
    BirthdayException(string message) :Exceptions(message) {};
};
class ExceptionName :public Exceptions
{
public:
    ExceptionName(string message) :Exceptions(message) {};
};
class PageException :public Exceptions
{
public:
    PageException(string message) :Exceptions(message) {};
};
class StatusException :public Exceptions
{
public:
    StatusException(string message) :Exceptions(message) {};
};
class NoExistExceptions :public Exceptions
{
public:
    NoExistExceptions(string message) :Exceptions(message) {};
};
class TheirIsNoFrineds :public Exceptions
{
public:
    TheirIsNoFrineds(string message) :Exceptions(message) {};
};
class ExistFriend :public Exceptions
{
public:
    ExistFriend(string message) :Exceptions(message) {};
};