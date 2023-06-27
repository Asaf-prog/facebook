#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Status.h"
#include "friend.h"
#include <string.h>
#include"Pages.h"
#include"Exeptions.h"
using namespace std;

int Friend::index = 0;

//This function adding like to page
bool Friend::addPage(Pages* newPage)
{
	if (checkExistPage(newPage) || newPage == nullptr)
		return false;

	likedPages.push_back(newPage);
	newPage->addFriend(this);
	return true;
}
//This function checking if the member allready like the page
bool Friend::checkExistPage(const Pages* newPage) const
{
	auto itr = likedPages.begin(), itrEnd = likedPages.end();
	for (; itr != itrEnd; ++itr)
	{
		if (*itr == newPage)
			return true;
	}
	return false;
}
//This function remove like from page
bool Friend::removePage(Pages* removePage)
{
	if (!checkExistPage(removePage) || removePage == nullptr)
		return false;

	if (likedPages.empty())
		throw TheirIsNoFrineds(NO_EXIST_MESSAGE);

	else
	{
		auto itr = likedPages.begin(), itrEnd = likedPages.end();
		for (; itr != itrEnd; ++itr)
		{
			if (*itr == removePage)
			{
				this->likedPages.erase(itr);
				removePage->removeFriend(this);
				return true;
			}
		}
	}
}
//This function return birthday
const Date Friend::getBirthDay() const
{
	return birthDate;
}
//This function printing last 10 statuses of this member
void Friend::printStatusLast10OfAllFriends() const
{
	if (myFriends.empty())
	{
		cout << getName() << " have is no friend" << endl;
		return;
	}
	for (auto i = myFriends.begin(); i != myFriends.end(); ++i)
		(*i)->print10Statuses();
}
//This function print 10 statuses of friend
void Friend::print10Statuses() const
{
	if (myStatus.empty())
	{
		cout << getName() << " have no statuses" << endl;
		return;
	}
	int index = 0;
	cout << getName() << ":" << endl;
	auto itr = myStatus.begin();
	auto itrEnd = myStatus.end() - 1;
	for (; (index < 10) && itrEnd >= itr; --itrEnd, index++)
	{
		(*itrEnd)->printStatus();

		if (itrEnd == itr)
			break;//Prevent iterator to vec[-1]
	}
}
//Operatos
bool Friend::operator>(const Friend& other) const
{
	return myFriends.size() > other.myFriends.size();
}
void Friend::toOs(ostream& os)const 
{
	os << birthDate.day << " " << birthDate.mounth << " " 
	<< birthDate.year << endl;	
}
//Constractor
Friend::Friend(const string n, Date& bDay) noexcept(false): CoObject(n),savedIndexArray(index)
{
	if (bDay.day < 1 || bDay.day > 31)
		throw BirthdayException(DATE_MESSAGE_DAY);
	if (bDay.mounth < 1 || bDay.mounth > 12)
		throw BirthdayException(DATE_MESSAGE_MONTH);
	if (bDay.year <= 0)
		throw BirthdayException(DATE_MESSAGE_YEAR);
	if (n.empty())
		throw ExceptionName(NAME_MESSAGE_VALID);
	
	birthDate = bDay;
	++index;
}