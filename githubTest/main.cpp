#include<iostream>
#include<Windows.h>
#include <conio.h> //getch()ʹ��
#include<String>
#include "hacker.h"



using namespace std;

#define WIDTH   40  //���
#define HEIGHT  15  //�߶�
void inputPwd(char pwd[],int size){
	char c;
	int i = 0;
	//��������
	while(1){
		//��������س������ͷ���'\r'
		c = getch();  //getch�������
		
		if(c == '\r'){
			pwd[i] = 0; // ��Ч pwd[i] = '\0';
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
		system("cls"); //������ÿ������֮ǰ���ԭ������ʾ��Ϣ
		cout<<"�������˺ţ�";
		cin>>name;
		cout<<"���������룺";
		//cin>>pwd;
		// ʵ����������
		inputPwd(pwd,sizeof(pwd));

		if(name == "54hk" && !strcmp(pwd, "123456")){
			return;
		}else{
			cout<<"�û��������������"<<endl;
			system("pause"); // ��������ͣһ�£���Ȼsystem("cls");�������һ����������������ʾ��Ϣ
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
	cout<<"1.��վ404����"<<endl;
	cout<<"2.��վ�۸Ĺ���"<<endl;
	cout<<"3.��վ������¼"<<endl;
	cout<<"4.�����޸���¼"<<endl;
	cout<<"5.�˳�"<<endl;
	*/
	string menu[] = {
		"1.��վ404����",
		"2.��վ�۸Ĺ���",
		"3.�����޸���¼",
		"4.��վ������¼",
		"5.�˳�"
	};
	//����˵������󳤶�
	int max = 0;
	int maxCount =0;
	maxCount = sizeof(menu)/sizeof(menu[0]);
	for(int i = 0; i < maxCount; i++){
		if(menu[i].length() > max){
			max = menu[i].length();
		}
	}
	system("cls");
	//��ӡ����
	printInMiddle("----�ڿ͹���ϵͳ----");
	int leftSpace = (WIDTH - max)/2;
	for(int i = 0; i < maxCount; i++){
		for(int j= 0; j < leftSpace; j++){
			cout<<" ";
		}
		cout<< menu[i] <<endl;
	}

}
int menuChoise(void){
	//���빦�ܱ��
	int n = 0;
	while(1){
		cout<<"�����빦�ܲ˵���ţ�";
		cin>>n;
		if(cin.fail()){
			cin.clear();
			cin.sync();
			cout<<"��Ч���룬����������"<<endl;
			system("pause");
		}else{
			break;
		}
	}
	return n;
}
void attack404(void){
	char id[64];  // ��վID
	char response[MAXSIZE]; //������վ��Ӧ��Ϣ
	system("cls");
	//int hk_404(char *id, char *response) ;
	printInMiddle("---��վ404����---");
	cout<<"������׼����������վID��";
	scanf_s("%s",id,sizeof(id));
	cout<<"���ڽ�����վ404��������\n";
	//���𹥻�
	hk_404(id,response);
	string restr = UTF8ToGBK(response);
	cout<<restr;
	system("pause");
}
void siteEdit(void){
	char id[64];  // ��վID
	char response[MAXSIZE]; //������վ��Ӧ��Ϣ
	string attackText;
	system("cls");
	//int hk_tamper(char *id, char *para, char *response);
	printInMiddle("---��վ�۸Ĺ���---");
	cout<<"������׼����������վID��";
	scanf_s("%s",id,sizeof(id));
	cout<<"��������ҪǶ�������:";
	cin>>attackText;
	cout<<"���ڽ�����վ�۸Ĺ�������\n";
	//�����ص�GBK����ת����UTF-8����
	GBKToUTF8(attackText);
	hk_tamper(id,(char*)attackText.c_str(),response);
	string restr = UTF8ToGBK(response);
	cout<<restr;
	
	system("pause");
}
void attackRecord(void){
	char id[64];  // ��վID
	char response[MAXSIZE]; //������վ��Ӧ��Ϣ
	system("cls");
	//int hk_record(char *id, char *response) ;
	printInMiddle("---��վ������¼---");
	cout<<"��������վ������¼ID��";
	scanf_s("%s",id,sizeof(id));
	cout<<"���ڽ��в鿴��վ������¼����\n";
	//�鿴��¼
	hk_record(id,response);
	string restr = UTF8ToGBK(response);
	cout<<restr;
	system("pause");
}
void siteRepair(void){
	char id[64];  // ��վID
	char response[MAXSIZE]; //������վ��Ӧ��Ϣ
	system("cls");
	//int hk_restore(char *id, char *response) ;
	printInMiddle("---��վ�����޸�---");
	cout<<"������׼���ָ�����վID��";
	scanf_s("%s",id,sizeof(id));
	cout<<"���ڽ��й����޸�����\n";
	//���𹥻�
	hk_restore(id,response);
	string restr = UTF8ToGBK(response);
	cout<<restr;
	system("pause");
}
void init(void){
	//��ʼ�����ڴ�С
	//mode con cols=40 lines=15
	char cmd[128];
	sprintf(cmd,"mode con cols=%d lines=%d",WIDTH,HEIGHT);
	system(cmd);
}
int main(void){
	init();
	login();  //ʵ�ֵ�¼����
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