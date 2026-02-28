#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#include <shellapi.h>
#include <string.h>
#include <iso646.h>

void SWITCH(int user_input);
void MENU();
void re_StudentMainPath();
int main()
{
	//MythWare Tool v2.1.4
	//Made by chenyuUwU
	char name[] = "Mythware Tool v2.1.4\nMade by chenyuUwU";
	printf(name);
	Sleep(2000);
	system("cls");

	FILE *check_file;
	check_file = fopen("C:\\Program Files\\studentmainpath.ini", "r");

	if (check_file == NULL)
	{
		FILE *ini;
		ini = fopen("C:\\Program Files\\studentmainpath.ini", "w+");

		char block[] = "[StudentMainPath]";
		char var[] = "path=";
		char path[] = "C:\\Program Files (x86)\\Mythware\\极域电子教室软件 v4.0 2015 豪华版\\StudentMain.exe";
		fputs(block, ini);
		fputs("\n", ini);
		fputs(var, ini);
		fputs(path, ini);
		fclose(ini);
	}

	int user_input;
	printf("请选择:\n1:结束进程\n2:重启进程\n3:重新设置学生端主程序路径\n4:退出\n");
	printf("\n在这里输入\nthis->");
	scanf("%d", &user_input);
	SWITCH(user_input);

	system("pause");
	return 0;
}

void MENU()
{
	printf("请选择:\n1:结束进程\n2:重启进程\n3:重新设置学生端主程序路径\n4:退出\n");
	int input;
	printf("\n在这里输入\nthis->");
	scanf("%d", &input);
	SWITCH(input);
}

void SWITCH(int user_input)
{
	switch (user_input)
	{
	case 1:
	{
		system("cls");
		system("taskkill /F /IM StudentMain.exe");
		Sleep(2000);
		system("cls");
		MENU();
	}
	case 2:
	{
		FILE *ini;
		ini = fopen("C:\\Program Files\\studentmainpath.ini", "r");
		char path[] = "path";

		fseek(ini, 24, SEEK_SET);
		fscanf(ini, "%[^\n]", path);

		int start_check = ShellExecuteA(NULL, "open", path, NULL, NULL, SW_SHOW);
		if (start_check > 32)
		{
			system("cls");
			printf("\n极域电子教室已成功启动\n");
			printf("4:返回\n");
		}
		else
		{
			if (start_check == 2)
			{
				system("cls");
				printf("MythWare Tool.exe找不到指定的文件!\n");
			}
		}

		Sleep(2000);
		system("cls");
		MENU();
		fclose(ini);
	}
	case 3:
	{
		re_StudentMainPath();
	}
	case 4:
	{
		exit(0);
	}
	default:
	{
		system("cls");
		printf("请输入正确的选项\n");
		Sleep(2000);
		system("cls");
		MENU();
	}
	}
}

void re_StudentMainPath()
{
	system("cls");
	FILE *re_ini;
	re_ini = fopen("C:\\Program Files\\studentmainpath.ini", "w+");

	char block[] = "[StudentMainPath]";
	char var[] = "path=";
	char path[] = "C:\\Program Files (x86)\\Mythware\\极域电子教室软件 v4.0 2015 豪华版\\StudentMain.exe";

	fputs(block, re_ini);
	fputs("\n", re_ini);
	fputs(var, re_ini);
	printf("请输入学生端主程序的路径:\n");
	printf("例：C:\\Program Files (x86)\\Mythware\\极域电子教室软件 v4.0 2015 豪华版\\StudentMain.exe\n");
	getchar();
	printf("path->");
	gets(path);
	fputs(path, re_ini);
	fseek(re_ini, 24, SEEK_SET);
	fgets(path, 200, re_ini);
	system("cls");
	printf("\033[33m是否要将%s设置为学生端主程序的路径 (y/n)?\033[0m\n", path);
	char YRN = '0';
	scanf("%s", &YRN);
	switch (YRN)
	{
	case 'y':
	case 'Y':printf("\033[32m已将%s设置为学生端主程序路径\033[0m\n", path); break;
	case 'n':
	case 'N':
	{
		system("cls");
		re_StudentMainPath();
	}
	default:re_StudentMainPath();
	}

	fclose(re_ini);
	int second;
	for (second = 5; second >= 0; second--)
	{
		printf("\r%d秒后返回目录", second);
		Sleep(1000);
	}
	system("cls");
	MENU();
}