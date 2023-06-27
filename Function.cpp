#pragma once
#include "header.h"

//Main while with start
void start(Facebook& facebook)
{
	int choose;
	do {
		printMenu();
		cin >> choose;
		getchar();//Clean buffer from ENTER
		try {
			switch (choose)
			{
			case 1:
				addMember(facebook);
				break;
			case 2:
				addPage(facebook);
				break;
			case 3:
				addStatus(facebook);
				break;
			case 4:
				showAllStatusOfEntity(facebook);
				break;
			case 5:
				presentTheLastTenStatus(facebook);
				break;
			case 6:
				makeNewFriends(facebook);
				break;
			case 7:
				cancelFreindShip(facebook);
				break;
			case 8:
				addLike(facebook);
				break;
			case 9:
				removeLikeFromPage(facebook);
				break;
			case 10:
				presentAllTheEntities(facebook);
				break;
			case 11:
				printFreinds(facebook);
				break;
			defualt:
				break;
			}
		}

	catch (Exceptions& exp)
	{
		cout << exp.printExp() << endl;
	}
	catch (...)
	{
		cout << "Error occured" << endl;
	}
	} while (choose >= 1 && choose <= 11);
}
//Main menu
void printMenu()
{
	cout << endl;
	cout << "Facebook Main Menu:" << endl;
	cout << "Choose methode:" << endl;
	cout << "1. Add member" << endl;
	cout << "2. Add page" << endl;
	cout << "3. Add status member/page" << endl;
	cout << "4. Show all statuses of member/page" << endl;
	cout << "5. Show recent 10 statuses of member friends" << endl;
	cout << "6. Make new friends" << endl;
	cout << "7. Cancel friends" << endl;
	cout << "8. Add friend to page" << endl;
	cout << "9. Remove friend from page" << endl;
	cout << "10. Show all entity of the system" << endl;
	cout << "11. Show all friends of member/page" << endl;
	cout << endl;
	cout << "12. EXIT" << endl;
}
//Add member
void addMember(Facebook& facebook)
{
	char name[NAME_LEN];
	int d, m, y;
	cout << "Enter name of member:" << endl;
	cin.getline(name, NAME_LEN);
	cout << "Enter BirthDay Format: Day/Mounth/Year:" << endl;
	cin >> d >> m >> y;
	facebook.addMember(name, d, m, y);//struct date
}
//this functon add status to entity  
void addStatus(Facebook& facebook)
{
	int choose;
	cout << "Choose to who add status:" << endl;
	cout << "1. Members" << endl;
	cout << "2. Pages" << endl;
	cin >> choose;
	if (choose == 1){
		if (facebook.getFriendsSize() == 0) {
			cout << THIS_ARE_NO_FRIEND << endl;
			return;
		}
		addStatusToMember(facebook);
	}

	else if (choose == 2)
	{
		if (facebook.getPagesSize() == 0) {
			cout << THIS_ARE_NO_PAGES << endl;
			return;
		}
		addStatusToPage(facebook);
	}
	else
		{
			cout << "Invalid choice" << endl;
			return;
		}
}
void addStatusToPage(Facebook& facebook)
{
	int choosenP,choose;
	cout << "Choose the page:" << endl;
	facebook.printAllPages();
	cin >> choosenP;
	char status[STATUS_LEN];
	char fileName[STATUS_LEN];
	cout << "Enter the status:" << endl;
	getchar();//Clean buffer from ENTER
	cin.getline(status, STATUS_LEN);
	cout << "Do you want add Picture/Video to the status? (Choose key)" << endl;
	cout << "1. Picture" << endl;
	cout << "2. Video" << endl;
	cout << "3. No" << endl;
	cin >> choose;
	if (choose != ONLY_CONTECT && choose != CONTECT_WITH_VIDEO && choose != CONTECT_WITH_PICTURE)
	{
		cout << "Invalid choice" << endl;
		return;
	}
	
	if (choose != ONLY_CONTECT)
	{
		cout << "Enter the file name:" << endl;
		getchar();//Clean buffer from ENTER
		cin.getline(fileName, STATUS_LEN);
		facebook.addStatusToPage(choosenP - 1, status, fileName, choose);
	}
	else
		facebook.addStatusToPage(choosenP - 1, status);
	
}
void addStatusToMember(Facebook& facebook)
{
	int choosenF;
	int choose;
	cout << "Choose the member:" << endl;
	facebook.printAllMembers();
	cin >> choosenF;
	char status[STATUS_LEN];
	char fileName[STATUS_LEN];
	cout << "Enter the status:" << endl;
	getchar();//Clean buffer from ENTER
	cin.getline(status, STATUS_LEN);
	cout << "Do you want add Picture/Video to the status? (Choose key)" << endl;
	cout << "1. Picture" << endl;
	cout << "2. Video" << endl;
	cout << "3. No" << endl;
	cin >> choose;
	if (choose != ONLY_CONTECT && choose != CONTECT_WITH_VIDEO && choose != CONTECT_WITH_PICTURE)
	{
		cout << "Invalid choice" << endl;
		return;
	}
	if (choose != ONLY_CONTECT)
	{
		cout << "Enter the file name:" << endl;
		getchar();//Clean buffer from ENTER
		cin.getline(fileName, STATUS_LEN);
		facebook.addStatusToMember(choosenF - 1, status, fileName, choose);
	}
	else
		facebook.addStatusToMember(choosenF - 1, status);
}
//Show all Statuses of member/page
void showAllStatusOfEntity(Facebook& facebook)
{
	int choose;
	cout << "Choose who status to present:" << endl;
	cout << "1. Members" << endl;
	cout << "2. Pages" << endl;
	cin >> choose;
	if (choose == 1)
	{
		presentAllSatusMember(facebook);
	}
	else if (choose == 2) {
		if (facebook.getPagesSize() == 0) {
			cout << THIS_ARE_NO_PAGES << endl;
			return;
		}
		presentAllSatusPages(facebook);
	}
	else
	{
		cout << "Invalid choice" << endl;
		return;
	}
}
void presentAllSatusMember(Facebook& facebook)
{
	int choosenF;
	cout << "Choose the member:" << endl;
	facebook.printAllMembers();
	cin >> choosenF;
	facebook.printStatusOfFriends(choosenF - 1);
}
void presentAllSatusPages(Facebook& facebook)
{
	int choosenP;
	cout << "Choose the pages:" << endl;
	facebook.printAllPages();
	cin >> choosenP;
	facebook.printStatusOfPages(choosenP - 1);
	
}
void presentTheLastTenStatus(Facebook& facebook)
{
	int choose;
	cout << "Choose a friend: " << endl;
	facebook.printAllMembers();
	cin >> choose;
	facebook.printLast10StatusF(choose - 1);
	
}
void makeNewFriends(Facebook& facebook)
{
	if (facebook.getFriendsSize() == 0) {
		cout << THIS_ARE_NO_FRIEND << endl;
		return;
	}
	int first, second;
	cout << "Choose the 1st member:" << endl;
	facebook.printAllMembers();
	cin >> first;

	if (first - 1 > facebook.getFriendsSize()) {
		cout << NO_EXIST_MESSAGE << endl;
		return;
	}

	cout << "Choose the 2st friend:" << endl;
	facebook.printAllMembers();
	cin >> second;
	while (second == first)
	{
		cout << "You chose the same member please chose another" << endl;
		facebook.printAllMembers();
		cin >> second;
	}
	first--;//Fix to be index of array
	second--;//Fix to be index of array
	facebook.makeNewFriend(first, second);//Make Friend[first] with Friend[Second]
}
void cancelFreindShip(Facebook& facebook)
{
	cout << "Cancel Friend Ship:" << endl;
	int first, second;
	cout << "Choose the 1st member:" << endl;
	facebook.printAllMembers();
	cin >> first;
	if (first > facebook.getFriendsSize())
	{
		cout << NO_EXIST_MESSAGE << endl;
		return;
	}
	cout << "Choose the 2st friend:" << endl;
	if (!facebook.printSecificFriends(first - 1))
		return;

	cin >> second;
	first--;//Fix to be index of array
	second--;//Fix to be index of array
	facebook.cancelFreindShip(first, second);
}
void addPage(Facebook& facebook)
{
	char name[NAME_LEN];
	cout << "Enter name of the page:" << endl;
	cin.getline(name, NAME_LEN);
	facebook.addPage(name);
}
void addLike(Facebook& facebook)
{
	int choosenF, choosenP;
	cout << "Choose the page that's you want to add:" << endl;
	facebook.printAllPages();
	cin >> choosenP;
	if (choosenP > facebook.getPagesSize())
	{
		cout << NO_EXIST_MESSAGE << endl;
		return;
	}
	cout << "Choose friend that's you want to add for the page:" << endl;
	facebook.printAllMembers();
	cin >> choosenF;
	facebook.addLike(choosenF - 1, choosenP - 1);
}
void removeLikeFromPage(Facebook& facebook)
{
	cout << "Cancel like from page:" << endl;
	int first, second;
	cout << "Choose the page:" << endl;
	facebook.printAllPages();
	cin >> first;
	if (first > facebook.getPagesSize())
	{
		cout << NO_EXIST_MESSAGE << endl;
		return;
	}
	if (!facebook.printPageMembers(first - 1))
		return;
	cout << "Choose the friend to remove:" << endl;
	cin >> second;
	first--;//Fix to be index of array
	second--;//Fix to be index of array
	facebook.removeLikeFromPage(first, second);
}
//this function present all the entities how found in the system 
void presentAllTheEntities(Facebook& facebook)
{
	cout << "Pages:\n";
	facebook.printAllPages();
	cout << "Members:\n";
	facebook.printAllMembers();
}
//Print friends of page/member
void printFreinds(Facebook& facebook)
{
	int choose;
	cout << "Choose print friends from members or from pages:" << endl;
	cout << "1. Members" << endl;
	cout << "2. Pages" << endl;
	cin >> choose;
	if (choose == 1)
		printMemberFriends(facebook);
	else if (choose == 2)
		printMemberPages(facebook);
	else
	{
		cout << "Invalid choice" << endl;
		return;
	}
}
void printMemberPages(Facebook& facebook)
{
	int choose;
	cout << "Choose page:" << endl;
	facebook.printAllPages();
	cin >> choose;
	choose--;
	facebook.printSecificLiked(choose);
	
}
void printMemberFriends(Facebook& facebook)
{
	int choose;
	cout << "Choose member:" << endl;
	facebook.printAllMembers();
	cin >> choose;
	choose--;//Fix to make index of array
	facebook.printSecificFriends(choose);
}

void saveDataToFile(Facebook& facebook)
{
	facebook.saveAllData();	
}
void getDataFromFile(Facebook& facebook)
{
	facebook.getDataFromFile();
}
