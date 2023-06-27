#pragma once 
#include<time.h>
#include<string>
#include <iostream>
using namespace std;
#define MAX_DATE_LEN 31//time.h return max len of date 30;#define ONLY_CONTECT 3
#define CONTECT_WITH_VIDEO 2
#define CONTECT_WITH_PICTURE 1
#define ONLY_CONTECT 3


class Status
{
protected:
	const string content;
	char date[MAX_DATE_LEN];
public:
	Status(const string status)noexcept(false);
	~Status() {};
	Status(const Status& status) = delete;

	bool operator!=(const Status& other) const;
	bool operator==(const Status& other)const;

	virtual void toOs(ostream& os)const { os << ONLY_CONTECT << endl; };

	friend ostream& operator <<(ostream& os, const Status& stat)
	{
		os << stat.content.size() << endl << stat.content << endl;
		stat.toOs(os);
		return os;
	}

	virtual void printStatus() const;
};

class StatusWithVideo: public Status
{
	private:
	const string fileNative;
	public:
		StatusWithVideo(const string status, const string fileName) :Status(status), fileNative(fileName) {};
		void printStatus() const override { cout << "\033[1;31m" << date << content << "\033[0m" << endl; };
		virtual void toOs(ostream& os)const override { os << CONTECT_WITH_VIDEO << endl << fileNative << endl; };
};
class StatusWithPicture : public Status
{
	private:
	const string fileNative;
	public:
		StatusWithPicture(const string status, const string fileName) : Status(status), fileNative(fileName) {};
		void printStatus() const override { cout << "\033[1;33m" << date << content << "\033[0m" <<endl ; };
		virtual void toOs(ostream& os)const override { os << CONTECT_WITH_PICTURE << endl << fileNative << endl; };
};