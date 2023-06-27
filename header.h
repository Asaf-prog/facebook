#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Facebook.h"
#include "CoObject.h"
#include "Pages.h"
#include "Status.h"
#include "friend.h"
#include "Exeptions.h"


#define NAME_LEN 50
#define STATUS_LEN 200




void start(Facebook& facebook);
void printMenu();
void addMember(Facebook& facebook);
void addPage(Facebook& facebook);
void makeNewFriends(Facebook& facebook);
void printFreinds(Facebook& facebook);
void printMemberFriends(Facebook& facebook);
void cancelFreindShip(Facebook& facebook);
void printMemberPages(Facebook& facebook);
void presentAllTheEntities(Facebook& facebook);
void addStatus(Facebook& facebook);
void removeLikeFromPage(Facebook& facebook);
void addLike(Facebook& facebook);
void showAllStatusOfEntity(Facebook& facebook);
void presentAllSatusMember(Facebook& facebook);
void presentAllSatusPages(Facebook& facebook);
void addStatusToMember(Facebook& facebook);
void addStatusToPage(Facebook& facebook);
void addStatus(Facebook& facebook);
void presentTheLastTenStatus(Facebook& facebook);
void saveDataToFile(Facebook& facebook);
void getDataFromFile(Facebook& facebook);