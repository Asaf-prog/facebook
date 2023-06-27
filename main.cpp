#pragma once
#include "header.h"

int main()
{
	Facebook facebook;
	getDataFromFile(facebook);

	cout << "Welcome to facebook!" << endl;
	start(facebook);

	saveDataToFile(facebook);

	return 0;
}