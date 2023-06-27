#pragma once
#include"friend.h"
#include"pages.h"
#include "Facebook.h"
#include <iostream>
#include "Status.h"
#include"Exeptions.h"
#include"CoObject.h"

bool CoObject:: setName(const string n)
{
	name = n;
	return true;
}
const string CoObject::getName()const
{
	return name;
}
bool CoObject::addFriend(Friend* newFriend)
{
	if (checkExistFriend(newFriend) || newFriend == nullptr)
		return false;

	myFriends.push_back(newFriend);
	Pages* temp = dynamic_cast<Pages*>(this);
	if(temp)
	{
		newFriend->addPage(temp);
	}
	else
		newFriend->addFriend((Friend*)this);

	return true;
}
bool CoObject::addStatus(string status, string fileNative,int choice)
{
	Status* stat;
	switch (choice)
	{
	case ONLY_CONTECT:
		stat = new Status(status);
		myStatus.push_back(stat);
		break;
	case CONTECT_WITH_VIDEO:
		stat = new StatusWithVideo(status, fileNative);
		myStatus.push_back(stat);
		break;
	case CONTECT_WITH_PICTURE:
		stat = new StatusWithPicture(status, fileNative);
		myStatus.push_back(stat);
		break;
	defualt:
		throw(StatusException(NO_EXIST_MESSAGE));
	}
	return true;
}

bool CoObject::removeFriend(Friend* newFriend)
{
	if (myFriends.empty())
		throw TheirIsNoFrineds(NO_EXIST_MESSAGE);

	if (!checkExistFriend(newFriend))//first of all check if the friend found in the repository friends
		return false;
	else
	{
		auto itr = myFriends.begin(), itrEnd = myFriends.end();
		for (; itr != itrEnd; ++itr)
		{
			if (*itr == newFriend)
				break;
		}
		myFriends.erase(itr);

		Friend* temp1 = dynamic_cast<Friend*>(this);
		Pages* temp2 = dynamic_cast<Pages*>(this);

		if (temp1)
			newFriend->removeFriend(temp1);
		else if (temp2)
			newFriend->removePage(temp2);

		return true;
	}
}
//this function chrck if the wanted friend found in the array
bool CoObject::checkExistFriend(const Friend* newFriend) const
{
	for (auto i = myFriends.begin(); i != myFriends.end(); ++i)
	{
		if (*i == newFriend)
			return true;
	}
	return false;
}

void CoObject::operator+=(Friend& other)
{
	if (&other != this)
		addFriend(&other);
}

bool CoObject::printFriends() const
{
	if (myFriends.empty())
	{
		cout << name << "'s have no friends." << endl;
		return false;
	}
	int index = 0;
	for (auto i = myFriends.begin(); i != myFriends.end(); ++i)
	{
		cout << index + 1 << ". " << (*i)->getName() << endl;
		index++;
	}
	return true;
}
void CoObject::printSatus() const
{
	if (myStatus.empty())
		cout << getName() << " have no statuses";
	int index = 0;
	auto itr = myStatus.begin(), itrEnd = myStatus.end();
	for (; itr != itrEnd; ++itr)
	{
		cout << index + 1 << ". ";
		(*itr)->printStatus();
		index++;
	}
}
void CoObject::writeToFile(ofstream& faceFile, ofstream& objFile, ofstream& statusFile) const
{
	//Write the entirity
	faceFile << *this;
	
	//Write the the page/friend friends
	objFile << getArrayIndex() << endl;
	objFile << myFriends.size() << endl;
	
	for (auto itr : myFriends)
		objFile << (itr)->getArrayIndex() << endl;

	//Save the entirity status
	statusFile << getArrayIndex() << endl;
	statusFile << myStatus.size() << endl;
	for (auto itr : myStatus)
		statusFile << (*itr);


}

//this function get a index and return the spesific page 
Friend* CoObject::getFriendByIndex(int index) const
{
	if (myFriends.size() < index + 1)
	{
		throw NoExistExceptions(NO_EXIST_MESSAGE);
	}
	return myFriends[index];
}

CoObject:: ~CoObject()
{
	auto itr = myStatus.begin(), itrEnd = myStatus.end();
	for (; itr != itrEnd; ++itr)
		delete* itr;
}