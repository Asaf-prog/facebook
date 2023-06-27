#pragma once
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
#include"Status.h"
#include <string.h>
#include <iostream>
#include "Facebook.h"
#include"Exeptions.h"

Status::Status(const string status) noexcept(false) :content(status)
{
	if (status.empty())
	{
		throw StatusException(STATUS_MESSAGE_EXIST);
	}
	time_t curr_time;
	curr_time = time(0);
	strcpy(date, ctime(&curr_time));
}
void Status::printStatus() const
{
	cout << date << content << endl;
}
//Operators
bool Status::operator!=(const Status& other) const
{
	return !(content == other.content);
}
bool Status::operator==(const Status& other) const
{
	if (strcmp(typeid(*this).name(), typeid(other).name()) == 0)
		return content == other.content;
	else 
		return false;
}
