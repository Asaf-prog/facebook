#pragma once
#include"Facebook.h"
class Pages;
class Status;

typedef struct Date
{
	unsigned int day;
	unsigned int mounth;
	unsigned int year;

}Date;
class Friend : public CoObject
{
private:
	static int index;
	Date birthDate;
	vector<Pages*> likedPages;
	const int savedIndexArray; //The index of facebook array

public:
	Friend(const string n, Date& bDay) noexcept(false);
	Friend(const Friend& other) = delete;//Delete copy constractur to prevent copy person

	bool operator>(const Friend& other) const;

	const Date getBirthDay() const;

	bool removePage(Pages* removePage);
	bool addPage(Pages* page) noexcept(false);
	bool checkExistPage(const Pages* newPage) const;

	void toOs(ostream& os) const override;

	void printStatusLast10OfAllFriends() const;
	void print10Statuses() const;
	int getArrayIndex() const { return savedIndexArray; };
};