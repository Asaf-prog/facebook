#pragma once
using namespace std;
#include<vector>
#include<String>
class Friend;
class Pages;

#define _CRT_SECURE_NO_WARNINGS

#define DATE_MESSAGE_DAY "Invalid day of month."
#define DATE_MESSAGE_MONTH "Invalid month."
#define DATE_MESSAGE_YEAR "Invalid year."
#define NAME_MESSAGE_VALID "Invalid name."
#define NAME_MESSAGE_EXIST "This name already exist in our system."
#define STATUS_MESSAGE_EXIST "Invalid Status."
#define NO_EXIST_MESSAGE "Invalid selection."
#define NO_EXIST_FRIENDS "have no friends."
#define	THIS_FRIEND_ARE_EXIST "This friend are exist in the list of the friends"
#define	THIS_ARE_NO_FRIEND "There are no friends"
#define	THIS_ARE_NO_PAGES "There are no pages"

#include"Status.h"
#include "CoObject.h"
#include"Exeptions.h"

class Facebook
{
	private:
		vector<Friend*> members;
		vector<Pages*> pages;

	public:
		Facebook() {};
		~Facebook();

		void addMember(const string n, unsigned int d, unsigned int m, unsigned int y) noexcept(false);
		void addLike(int f, int P) noexcept(false);
		void addPage(const string n) noexcept(false);
		void makeNewFriend(int index1, int index2) noexcept(false);//Make Friend A with B
		void cancelFreindShip(int index1, int index2) noexcept(false);
		void removeLikeFromPage(int index1, int index2) noexcept(false);
		void addStatusToMember(const int choosenF, const string status,const string fileName = "", int choose = ONLY_CONTECT) noexcept(false);
		void addStatusToPage(const int choosenP, const string status,const string fileName = "", int choose = ONLY_CONTECT) noexcept(false);
		void printAllMembers() const;
		bool printSecificFriends(int index) noexcept(false);
		void printSecificLiked(int index) noexcept(false);
		void printAllPages() const;
		bool printPageMembers(int index) const;
		void printStatusOfFriends(int index) const noexcept(false);
		void printStatusOfPages(int index) const noexcept(false);
		void printLast10StatusF(int index) const noexcept(false);
		bool thisNameExist(const string n) const;
		bool thisPageExist(const string n) const;
		int getFriendsSize() const;
		int getPagesSize() const;
		void saveAllData() const;
		void getDataFromFile();
};