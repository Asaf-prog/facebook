#pragma once
#include "Status.h"
#include "CoObject.h"
#include<vector>

class Friend;

class Pages: public CoObject
{
	private:
		static int index;
		string name;
		vector<Friend*> myFriends;
		const int savedIndexArray; //The index of facebook array


	public:
		void printStatusLast10P() const;

		bool operator>(const Pages& other)const;

		int getArrayIndex() const { return savedIndexArray; };

		Pages(const string n) noexcept(false);
		Pages(const Pages& other) = delete;
};