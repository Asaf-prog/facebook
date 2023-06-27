#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#define RELEVANT_STATUS 10
using namespace std;
#include"Pages.h"
#include"friend.h"
#include "Exeptions.h"

int Pages::index = 0;

bool Pages::operator>(const Pages& other)const
{
	int thisSize = myFriends.size();
	int otherSize = other.myFriends.size();
	if (thisSize > otherSize)
		return true;
	else
		return false;
}
//this function print the last ten status of the page
void Pages::printStatusLast10P() const
{
	int index = 0;
	if (myStatus.empty())
	{
		cout << "their is no status to this page " << endl;
		return;
	}
	cout << "The most relevat Statuses: " << endl;
	for (auto i = myStatus.end(); i != myStatus.begin() && index < RELEVANT_STATUS; i--)
	{
		index++;
		cout << index << ". ";
		(*i)->printStatus();
	}
}
//Constructor:
Pages::Pages(const string n) noexcept(false) : CoObject(n), savedIndexArray(index)
{
	if (n.empty())
		throw PageException(NAME_MESSAGE_VALID);

	++index;
}
