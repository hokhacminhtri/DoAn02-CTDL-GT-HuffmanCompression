#include "menu.h"

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x,y };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

void bangchon(int chon, int choncu)
{
	if (chon == 1)
	{
		if (choncu == 2)
		{
			gotoxy(26, 11);
			printf(" ");
			gotoxy(46, 11);
			printf(" ");
		}
		gotoxy(26, 10);
		printf("[");
		gotoxy(73, 10);
		printf("]");
	}
	if (chon == 2)
	{
		if (choncu == 1)
		{
			gotoxy(26, 10);
			printf(" ");
			gotoxy(73, 10);
			printf(" ");
		}
		if (choncu == 3)
		{
			gotoxy(26, 12);
			printf(" ");
			gotoxy(50, 12);
			printf(" ");
		}
		gotoxy(26, 11);
		printf("[");
		gotoxy(46, 11);
		printf("]");
	}
	if (chon == 3)
	{
		if (choncu == 2)
		{
			gotoxy(26, 11);
			printf(" ");
			gotoxy(46, 11);
			printf(" ");
		}
		if (choncu == 4)
		{
			gotoxy(26, 13);
			printf(" ");
			gotoxy(50, 13);
			printf(" ");
		}
		gotoxy(26, 12);
		printf("[");
		gotoxy(50, 12);
		printf("]");
	}
	if (chon == 4)
	{
		if (choncu == 3)
		{
			gotoxy(26, 12);
			printf(" ");
			gotoxy(50, 12);
			printf(" ");
		}
		gotoxy(26, 13);
		printf("[");
		gotoxy(50, 13);
		printf("]");
	}

}

void menu()
{
	system("cls");
	int chon = 1;
	int choncu = 0;
	gotoxy(25, 9);
	printf(">> DO AN CAU TRUC DU LIEU VA GIAI THUAT <<");
	gotoxy(30, 10);
	printf("NEN TAP TIN (VAN BAN, HINH ANH, AUDIO,...) \n");
	gotoxy(30, 11);
	printf("GIAI NEN TAP TIN \n");
	gotoxy(30, 12);
	printf("NEN THU MUC \n");
	gotoxy(30, 13);
	printf("GIAI NEN THU MUC \n");

	bangchon(chon, choncu);
	while (1)
	{
		int h;
		if (_kbhit())
		{
			h = _getch();
			if (h == 13)
				break;
			if (h == 80)
			{
				if (chon < 8)
				{
					choncu = chon;
					chon++;
					bangchon(chon, choncu);
				}
			}
			if (h == 72)
			{
				if (chon > 1)
				{
					choncu = chon;
					chon--;
					bangchon(chon, choncu);
				}
			}
		}
	}
	if (chon == 1)
	{
		system("cls");
		cout << "/********************************NEN TAP TIN********************************/" << endl;
		
		clock_t start, finish;
		
		char* inputpath = NULL;
		inputpath = new char[100];
		char* outputpath = NULL;
		outputpath = new char[100];

		if (inputpath == NULL || outputpath == NULL)
		{
			cout << "Khong cap phat bo nho duoc!!!";
		}
		else {
			cout << "Nhap duong dan file input: ";
			cin.getline(inputpath, 100);
			cout << "Nhap duong dan file output: ";
			cin.getline(outputpath, 100);
			
			start = clock();

			NenHuffman(inputpath, outputpath, true);
			delete[] inputpath;
			delete[] outputpath;
		}

		finish = clock();
		clock_t duration = finish - start;
		cout << "\nTHOI GIAN NEN TAP TIN: " << (float)duration / CLOCKS_PER_SEC << " giay" << endl;

		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 2)
	{
		system("cls");
		cout << "/********************************GIAI NEN TAP TIN********************************/" << endl;

		clock_t start, finish;

		char* outputpath = NULL;
		outputpath = new char[100];
		if (outputpath == NULL)
		{
			cout << "Khong cap phat bo nho duoc!!!";
		}
		else
		{
			cout << "Nhap duong dan file can giai nen: ";
			cin.getline(outputpath, 100);

			char* decodepath = NULL;	//duong dan file da giai nen
			decodepath = new char[100];
			printf("Nhap duong dan file da giai nen: ");
			cin.getline(decodepath, 100);

			start = clock();

			DeCompress(outputpath, decodepath);

			delete[] decodepath;
			delete[] outputpath;
		}

		finish = clock();
		clock_t duration = finish - start;
		cout << "\nTHOI GIAN GIAI NEN TAP TIN: " << (float)duration / CLOCKS_PER_SEC << " giay" << endl;

		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 3)
	{
		system("cls");
		cout << "/********************************NEN THU MUC********************************/" << endl;

		clock_t start, finish;

		string input;			//duong path input
		string output;			//duong path output

		vector<char*> path;		//vector de luu cac duong dan file trong thu muc
		vector<char*> pathfolder; //vector de chua cac duong dan folder
		cout << "Nhap vao duong dan thu muc can nen: ";
		getline(cin, input);
		cout << "Nhap vao duong dan thu muc sau khi nen: ";
		getline(cin, output);
		start = clock();

		NenFolder(input, output);

		finish = clock();
		clock_t duration = finish - start;
		cout << "\nTHOI GIAN NEN THU MUC: " << (float)duration / CLOCKS_PER_SEC << " giay" << endl;

		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
	if (chon == 4)
	{
		system("cls");
		cout << "/********************************GIAI NEN THU MUC********************************/" << endl;

		clock_t start, finish;

		string input;			//duong path input
		string output;			//duong path output
		cout << "Nhap vao duong dan thu muc can giai nen: ";
		getline(cin, input);
		cout << "Nhap vao duong dan thu muc sau khi giai nen: ";
		getline(cin, output);
		start = clock();

		GiaiNenFolder(input, output);
		finish = clock();
		clock_t duration = finish - start;

		cout << "\nTHOI GIAN GIAI NEN THU MUC: " << (float)duration / CLOCKS_PER_SEC << " giay" << endl;
		cout << "Press enter to return to menu";
		while (1)
			if (_kbhit())
			{
				int in = _getch();
				if (in == 13)
					system("cls");
				break;
			}
		menu();
	}
}