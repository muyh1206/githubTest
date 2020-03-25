#include<iostream>
#include<Windows.h>
#include <conio.h> //getch()使用
#include<String>
#include "hacker.h"



using namespace std;

#define WIDTH   40  //宽度
#define HEIGHT  15  //高度
void inputPwd(char pwd[],int size){
	char c;
	int i = 0;
	//输入密码
	while(1){
		//如果读到回车符，就返回'\r'
		c = getch();  //getch不会回显
		
		if(c == '\r'){
			pwd[i] = 0; // 等效 pwd[i] = '\0';
			break;
		}
		pwd[i++] = c;
		cout<<"*";
	}
	cout<<endl;
}
void login(void){
	string name;
	char pwd[32];
	while(1){
		system("cls"); //清屏，每次输入之前清楚原来的显示信息
		cout<<"请输入账号：";
		cin>>name;
		cout<<"请输入密码：";
		//cin>>pwd;
		// 实现密码输入
		inputPwd(pwd,sizeof(pwd));

		if(name == "54hk" && !strcmp(pwd, "123456")){
			return;
		}else{
			cout<<"用户名或者密码错误！"<<endl;
			system("pause"); // 错误后就暂停一下，不然system("cls");会清掉，一闪而过，看不到提示信息
		}	
	}
}
void printInMiddle(string msg){
	int leftSpace = (WIDTH - msg.length())/2;

		for(int j= 0; j < leftSpace; j++){
			cout<<" ";
		}
		cout<< msg <<endl;

}
void menuShow(void){
	
	/*
	cout<<"1.网站404攻击"<<endl;
	cout<<"2.网站篡改攻击"<<endl;
	cout<<"3.网站攻击记录"<<endl;
	cout<<"4.攻击修复记录"<<endl;
	cout<<"5.退出"<<endl;
	*/
	string menu[] = {
		"1.网站404攻击",
		"2.网站篡改攻击",
		"3.攻击修复记录",
		"4.网站攻击记录",
		"5.退出"
	};
	//计算菜单项的最大长度
	int max = 0;
	int maxCount =0;
	maxCount = sizeof(menu)/sizeof(menu[0]);
	for(int i = 0; i < maxCount; i++){
		if(menu[i].length() > max){
			max = menu[i].length();
		}
	}
	system("cls");
	//打印标题
	printInMiddle("----黑客攻击系统----");
	int leftSpace = (WIDTH - max)/2;
	for(int i = 0; i < maxCount; i++){
		for(int j= 0; j < leftSpace; j++){
			cout<<" ";
		}
		cout<< menu[i] <<endl;
	}

}
int menuChoise(void){
	//输入功能编号
	int n = 0;
	while(1){
		cout<<"请输入功能菜单编号：";
		cin>>n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout<<"无效输入，请重新输入"<<endl;
			system("pause");
		}else{
			break;
		}
	}
	return n;
}
void attack404(void){
	char id[64];  // 网站ID
	char response[MAXSIZE]; //攻击网站响应信息
	system("cls");
	//int hk_404(char *id, char *response) ;
	printInMiddle("---网站404攻击---");
	cout<<"请输入准备攻击的网站ID：";
	scanf_s("%s",id,sizeof(id));
	cout<<"正在进行网站404攻击……\n";
	//发起攻击
	hk_404(id,response);
	string restr = UTF8ToGBK(response);
	cout<<restr;
	system("pause");
}
void siteEdit(void){
	char id[64];  // 网站ID
	char response[MAXSIZE]; //攻击网站响应信息
	string attackText;
	system("cls");
	//int hk_tamper(char *id, char *para, char *response);
	printInMiddle("---网站篡改攻击---");
	cout<<"请输入准备攻击的网站ID：";
	scanf_s("%s",id,sizeof(id));
	cout<<"请输入你要嵌入的内容:";
	cin>>attackText;
	cout<<"正在进行网站篡改攻击……\n";
	//将本地的GBK编码转换成UTF-8编码
	GBKToUTF8(attackText);
	hk_tamper(id,(char*)attackText.c_str(),response);
	string restr = UTF8ToGBK(response);
	cout<<restr;
	
	system("pause");
}
void attackRecord(void){
	char id[64];  // 网站ID
	char response[MAXSIZE]; //攻击网站响应信息
	system("cls");
	//int hk_record(char *id, char *response) ;
	printInMiddle("---网站攻击记录---");
	cout<<"请输入网站攻击记录ID：";
	scanf_s("%s",id,sizeof(id));
	cout<<"正在进行查看网站攻击记录……\n";
	//查看记录
	hk_record(id,response);
	string restr = UTF8ToGBK(response);
	cout<<restr;
	system("pause");
}
void siteRepair(void){
	char id[64];  // 网站ID
	char response[MAXSIZE]; //攻击网站响应信息
	system("cls");
	//int hk_restore(char *id, char *response) ;
	printInMiddle("---网站攻击修复---");
	cout<<"请输入准备恢复的网站ID：";
	scanf_s("%s",id,sizeof(id));
	cout<<"正在进行攻击修复……\n";
	//发起攻击
	hk_restore(id,response);
	string restr = UTF8ToGBK(response);
	cout<<restr;
	system("pause");
}
void init(void){
	//初始化窗口大小
	//mode con cols=40 lines=15
	char cmd[128];
	sprintf(cmd,"mode con cols=%d lines=%d",WIDTH,HEIGHT);
	system(cmd);
}
int main(void){
	init();
	login();  //实现登录功能
	while(1){
		menuShow();
		int n = menuChoise();
		switch(n){
		case 1:
			attack404();
			break;
		case 2:
			siteEdit();
			break;
		case 3:
			siteRepair();		
			break;
		case 4:
			attackRecord();
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
		
	}
	system("pause");
	return 0;
}