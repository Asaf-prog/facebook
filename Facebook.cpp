#pragma once
#include "header.h"
#include"friend.h"
#include"pages.h"
#include "Facebook.h"
#include <iostream>
#include <fstream>
#include "Status.h"
#include"Exeptions.h"

//This function adding member
void Facebook::addMember(const string n, unsigned int d, unsigned int m, unsigned int y)
{
	if (thisNameExist(n))
		throw ExceptionName(NAME_MESSAGE_EXIST);

	Date date{ d,m,y };
	members.push_back(new Friend{ n,date });
}
bool Facebook::thisNameExist(const string n) const
{
	auto itr = members.begin(), itrEnd = members.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == n)
			return true;
	}
	return false;
}
bool Facebook::thisPageExist(const string n) const
{
	auto itr = pages.begin(), itrEnd = pages.end();

	for (; itr != itrEnd; ++itr)
	{
		if ((*itr)->getName() == n)
			return true;
	}
	return false;
}
//This function adding page
void Facebook::addPage(const string n)
{
	if (thisPageExist(n))
		throw PageException(NAME_MESSAGE_EXIST);

	pages.push_back(new Pages{ n });
}
//this functon called to the function in friends how connectred between friend and page
void Facebook::addLike(int f, int p)
{
	if (f + 1 > members.size() || pages.size() < p + 1)
		throw NoExistExceptions(NO_EXIST_MESSAGE);
	
	if(!(members[f]->addPage(pages[p])))
		throw NoExistExceptions("This page already liked by the friend.");
}
//This function add status to member chosen
void Facebook::addStatusToMember(const int choosenF, const string status, const string fileName, int choose)
{
	if ((choosenF + 1) > members.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);
	
	if((choose != ONLY_CONTECT) && (fileName == ""))
		throw StatusException(STATUS_MESSAGE_EXIST);
	
	members[choosenF]->addStatus(status,fileName,choose);
}
//This function add status to page chosen
void Facebook::addStatusToPage(const int choosenP, const string status,const string fileName, int choose)
{
	if ((choosenP + 1) > pages.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);

	if(choose != ONLY_CONTECT && fileName == "")
		throw StatusException(STATUS_MESSAGE_EXIST);

	pages[choosenP]->addStatus(status,fileName,choose);
}
//This function making new friend ship between arr[index1]-arr[index2]
void Facebook::makeNewFriend(int index1, int index2)
{
	if (index1 + 1 > members.size() || index2 + 1 > members.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);

	members[index1]->addFriend(members[index2]);
}
//This function cancel friend ship between arr[index1]-arr[index2]
void Facebook::cancelFreindShip(int index1, int index2)
{
	if (index1 + 1 > members.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);

	members[index1]->removeFriend(members[index1]->getFriendByIndex(index2));
}
//This function remove like from page
void Facebook::removeLikeFromPage(int index1, int index2)
{
	if (index1 + 1 > pages.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);

	pages[index1]->removeFriend(pages[index1]->getFriendByIndex(index2));
}
//This function print all members
void Facebook::printAllMembers()const
{
	int index = 0;
	for (auto i = members.begin(); i != members.end(); ++i)
	{
		cout << index + 1 << ". " << (*i)->getName() << endl;
		index++;
	}
}
//This function print friends of specific member
bool Facebook::printSecificFriends(int index)
{
	if (index + 1 > members.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);

	return members[index]->printFriends();
}
//This function print friends of specific page
void Facebook::printSecificLiked(int index)
{
	if (index + 1 > pages.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);

	pages[index]->printFriends();
}
//This function print friends of specific page
bool Facebook::printPageMembers(int index) const
{
	return pages[index]->printFriends();
}
//This function print all pages of facebook
void Facebook::printAllPages()const
{
	int index = 0;

	for (auto i = pages.begin(); i != pages.end(); ++i)
	{
		cout << index + 1 << ". " << (*i)->getName() << endl;
		index++;
	}
}
//This function print all statuses of friend
void Facebook::printStatusOfFriends(int index) const
{
	if (index + 1 > members.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);

	members[index]->printSatus();
}
//This function print all statuses of page
void Facebook::printStatusOfPages(int index) const
{
	if (index + 1 > pages.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);
	pages[index]->printSatus();
}
int Facebook::getFriendsSize() const
{
	return members.size();
}
int Facebook::getPagesSize() const
{
	return pages.size();
}
//This function print last 10 status
void Facebook::printLast10StatusF(int index) const
{
	if (index + 1 > members.size())
		throw NoExistExceptions(NO_EXIST_MESSAGE);

	members[index]->printStatusLast10OfAllFriends();
}
void Facebook::saveAllData() const
{
	ofstream faceFile("facebook.txt", ios::trunc);
	ofstream friendFile("friends.txt", ios::trunc);
	ofstream pagesFile("pages.txt", ios::trunc);
	ofstream statusFriendFile("statusFriend.txt", ios::trunc);
	ofstream statusPagesFile("statusPage.txt", ios::trunc);

	faceFile << members.size() << endl;

	auto i = members.begin();
	auto iE = members.end();

	auto j = pages.begin();
	auto jE = pages.end();

	for (; i != iE; ++i)
		(*i)->writeToFile(faceFile,friendFile,statusFriendFile);

	faceFile << pages.size() << endl;

	for (; j != jE; ++j)
		(*j)->writeToFile(faceFile,pagesFile,statusPagesFile);

	faceFile.close();
	pagesFile.close();
	friendFile.close();
	statusFriendFile.close();
	statusPagesFile.close();

}
void Facebook::getDataFromFile()
{
	ifstream faceFile("facebook.txt");
	ifstream friendFile("friends.txt");
	ifstream pagesFile("pages.txt");
	ifstream statusFriendFile("statusFriend.txt");
	ifstream statusPagesFile("statusPage.txt");

	char temp[STATUS_LEN];
	int memberSize,pageSize;
	string name,status,filestatus;
	int day, month, year;
	int member, newFriend, friendsSize;
	int page, statusSize,statusType;
	int nameSize;

	faceFile >> memberSize;
	for(int i =0; i < memberSize; i++)
	{
		faceFile >> nameSize;
		faceFile.getline(temp, nameSize + 1);
		faceFile >> day >> month >> year;
		addMember(temp, day, month, year);
	}
	faceFile >> pageSize;
	for(int i =0; i < pageSize; i++)
	{
		faceFile >> nameSize;
		faceFile.getline(temp, nameSize + 1);
		addPage(temp);
	}
	for(int i =0; i < memberSize; i++)
	{
		friendFile >> member >> friendsSize;
		for(int i=0; i < friendsSize; i++ )
		{
			friendFile >> newFriend;
			makeNewFriend(member, newFriend);
		}
	}
	for(int i =0; i < pageSize; i++)
	{
		pagesFile >> page >> friendsSize;
		for(int i=0; i < friendsSize; i++ )
		{
			pagesFile >> newFriend;
			addLike(page, newFriend);
		}
	}
	for(int i =0; i < memberSize; i++)
	{
		statusFriendFile >> member >> statusSize;
		for(int i=0; i < statusSize; i++ )
		{
			statusFriendFile >> nameSize;
			statusFriendFile.getline(temp,1);
			statusFriendFile.getline(temp, nameSize + 1);
			statusFriendFile >> statusType;
			if (statusType != ONLY_CONTECT) {
				statusFriendFile >> filestatus;
				addStatusToMember(member, temp, filestatus, statusType);
			}
			else
				addStatusToMember(member, temp);
		}
	}
	for(int i =0; i < pageSize; i++)
	{
		statusPagesFile >> member >> statusSize;
		for(int i=0; i < statusSize; i++ )
		{
			statusPagesFile >> nameSize;
			statusFriendFile.getline(temp,1);
			statusPagesFile.getline(temp, nameSize + 1);
			statusPagesFile >> statusType;
			if (statusType != ONLY_CONTECT) {
				statusPagesFile >> filestatus;
				addStatusToMember(member, temp, filestatus, statusType);
			}
			else
				addStatusToMember(member, temp);
		}
	}
	faceFile.close();
	pagesFile.close();
	friendFile.close();
	statusFriendFile.close();
	statusPagesFile.close();
}
Facebook::~Facebook()
{
	auto i = members.begin();
	auto iE = members.end();

	auto j = pages.begin();
	auto jE = pages.end();

	for (; i != iE; ++i)
		delete* i;

	for (; j != jE; ++j)
		delete* j;

}