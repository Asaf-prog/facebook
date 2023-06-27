#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Facebook.h"
#include "Status.h"
#include <fstream>
class CoObject
{
	protected:
		string name;
		vector<Friend*>myFriends;
		vector<Status const*> myStatus;

		CoObject() = delete;
		CoObject(string name) : name(name) {};
		CoObject(const CoObject& other) = delete;

	public:
	bool setName(const string n);
	const string getName()const;

	bool addFriend(Friend* newFriend);
	bool addStatus(string status, string fileNative = "", int choice = ONLY_CONTECT);
	bool removeFriend(Friend* newFriend);
	bool checkExistFriend(const Friend* newFriend) const;
	
	void operator+=(Friend& other);
	void operator=(const CoObject& other) = delete;

	bool printFriends() const;
	void printSatus() const;

	Friend* getFriendByIndex(int index) const noexcept(false);
	virtual int getArrayIndex() const = 0;

	void writeToFile(ofstream& faceFile, ofstream& objFile,ofstream& statusFile) const;
	virtual void toOs(ostream& os)const {};

	friend ostream& operator <<(ostream& os, const CoObject& obj)
	{
		os << obj.name.size() << obj.name << endl;
		obj.toOs(os);
		return os;
	}
	virtual ~CoObject();
};
