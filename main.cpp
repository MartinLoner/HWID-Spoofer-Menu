#include <Windows.h>
#include <iostream>
#include <tchar.h>
#include <intrin.h>

using namespace std;

void showMenu() {
	cout << "*******************************\n";
	cout << " 1 - Spoof HWID.\n";
	cout << " 2 - Check HWID.\n";
	cout << " 3 - Exit.\n";
	cout << "*******************************\n";
	cout << " Enter your choice and press return: ";
}

int main()
{
	//First part gets the HDD informations
	cout << "Checking HWID information-" << flush;
	for (int i = 0; i <= 10; ++i) {
		Sleep(10);
		cout << "\b\\" << flush;
		Sleep(10);
		cout << "\b|" << flush;
		Sleep(10);
		cout << "\b/" << flush;
		Sleep(10);
		cout << "\b-" << flush;
	}
	cout << "\nDone" << endl;
	Sleep(1000);
	system("CLS");
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	if (GetVolumeInformation(
		_T("C:\\"),
		volumeName,
		ARRAYSIZE(volumeName),
		&serialNumber,
		&maxComponentLen,
		&fileSystemFlags,
		fileSystemName,
		ARRAYSIZE(fileSystemName)))
	{
		DWORD acceptedSerial = 1234567890;
		if (serialNumber == acceptedSerial)
		{
			cout << "Welcome to my application!" << endl;
		}
		else
		{
			cout << "You are not in the system!" << endl;
			Sleep(4000);
			return 0;
		}
	}
	//application code goes below.

	int choice;

	{

		do
		{
			showMenu();
			cin >> choice;

			switch (choice)
			{
			case 1:
				//code to start the program
				break;
			case 2:
				//code to show the current HWID
				break;
			case 3:
				cout << "End of Program.\n";
				break;
			default:
				cout << "Not a Valid Choice. \n"
					<< "Choose again.\n";
				Sleep(500);
				system("CLS");
				break;
			}

		} while (choice != 3);
		return 0;
	}
	system("pause>0");
}