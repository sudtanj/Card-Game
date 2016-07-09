/*
Group Members :
1. Sudono Tanjung (00000012273)
2. Rickhen Hermawan(00000012311)
3. Leornado Jivalino  (00000015443)
*/

#include <iostream>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <cmath>
using namespace std;

int cardui(int playerdata[10][10], int jumlahkartu, int player,int datarank[10][10]);
int mainuitop(string programname);
int playerlistui(int listplayer, string space);
int randomnumber(int seed, int playerfactor);
int randomrank(int seed, int playerfactor);

int main(){
	SetConsoleTitle("U Card");
	setlocale(LC_ALL, ".1250");
    SetConsoleOutputCP(1250);
    SetConsoleCP(1250);
    while (0<1){
		int input,player=0;
		int playerdata[10][10];
		int datarank[10][10];
		int hasilplayer[10],samecardvalue,samecardrank,terkecilplayer1=0,terkecilplayer2=0;
		int lokasikartuplayer1=0,lokasikartuplayer2=0,lokasirankplayer1=0,lokasirankplayer2=0;
		int kartuterkecilplayer1=0,kartuterkecilplayer2=0;
	memset(playerdata,0,sizeof(playerdata));
	memset(datarank,0,sizeof(datarank));
	cout << endl;
	mainuitop("U-Card Games");
	cout << endl;
		cout << "  Select Player :" << endl;
		playerlistui(2,"  ");
		cout << "  Your selection is : Player ";
		for (int i=1;i>0;){
		if (_getch()=='1'){
			player=1;
			break;
		}
		else if(_getch()=='2'){
			player=2;	
			break;
		}
		}
	for (int i=1; i>0;){
		system("CLS");
		cout << endl;
		mainuitop("U-Card Games");
		cout << endl;
		cout << "  Press d button on the keyboard to deal...";
		if (_getch()=='d'){
			break;
		}
	}
		system ("CLS");
		cout << endl;
		mainuitop("U-Card Games");
		cout << endl;
	for (int i=0; 2>i; i++){
		cout << "  Player ";
		cout << player-(player-1)+i;
			if (i==player-1){
			cout << " (YOU): " << endl; 
			}
			else {
			cout << " (Computer): " << endl;
			}
		for (int a=0; 5>a; a++){
			for (int b=0; a>b; b++){
				if ((playerdata[player-(player-1)+i][b])==(playerdata[player-(player-1)+i][b-1])){
				a=a-1;
				}
			}
			playerdata[player-(player-1)+i][a]=randomnumber(a,player-(player-1)+i)+1;
			datarank[player-(player-1)+i][a]=randomrank(a,player-(player-1)+i)+1;
		}
		cardui(playerdata,5,player-(player-1)+i,datarank);
		
	}
	for (int i=1;0<i;){
	cout << "Press c to compare card...";
	if (_getch()=='c'){
		break;
	}
	cout << endl;
	}
	terkecilplayer1=datarank[1][0];
	terkecilplayer2=datarank[2][0];
	for (int i=0; 5>i; i++){
		for (int a=0; 5>a; a++){
			if (terkecilplayer1>datarank[1][i]){
			terkecilplayer1=datarank[1][i];
			lokasirankplayer1=i;
			}
			if (terkecilplayer2>datarank[2][a]){
			terkecilplayer2=datarank[2][a];
			lokasirankplayer2=a;
			}
			}
		}
	// lokasi playerdata terkecil
	for (int i=0; 5>i; i++){
		for (int a=0; 5>a; a++){
			if (i==lokasirankplayer1){
			kartuterkecilplayer1=playerdata[1][i];
			lokasikartuplayer1=i;
			}
			if (a==lokasirankplayer2){
			kartuterkecilplayer2=playerdata[1][a];
			lokasikartuplayer2=a;
			}
		}
	}		
	playerdata[1][lokasikartuplayer1]=14;
	playerdata[2][lokasikartuplayer2]=14;	
	system ("CLS");
		cout << endl;
		mainuitop("U-Card Games");
		cout << endl;
	for (int i=0; 2>i; i++){
		cout << "  Player ";
		cout << player-(player-1)+i;
			if (i==player-1){
			cout << " (YOU): " << endl; 
			}
			else {
			cout << " (Computer): " << endl;
			}
		cardui(playerdata,5,player-(player-1)+i,datarank);	
	}
	for (int i=1;0<i;){
	cout << "Press r to show result...";
		if (_getch()=='r'){
			break;
		}
	cout << endl;
	}
	cout << endl;
	for (int a=0; 2>a; a++){
		cout << "  Player ";
		cout << player-(player-1)+a;
			if (a==player-1){
			cout << " (YOU)     : "; 
			}
			else {
			cout << " (Computer): ";
			}
		for (int i=0; i<5; i++){
			if (playerdata[a][i]==1){
				cout << "15 ";
				hasilplayer[a+1]=hasilplayer[a+1]+15;
			}
			else if (playerdata[a+1][i]==11 || playerdata[a+1][i]==12 || playerdata[a+1][i]==13){
				cout << "12 ";
				hasilplayer[a+1]=hasilplayer[a+1]+12;
			}
			else if (playerdata[a+1][i]==14){
			}
			else {
				cout << playerdata[a+1][i] << " ";
				hasilplayer[a+1]=hasilplayer[a+1]+playerdata[a+1][i];
			}
			if (i<4){
				if (playerdata[a+1][i]!=14){
				cout << "+ ";
				}
			}
		}
		cout << "= " << hasilplayer[a+1] << endl;
	}
	if (hasilplayer[1]>hasilplayer[2]){
		if (player==1){
			cout << "You Win";
		}
		else {
			cout << "Computer Win";
		}
	}
	else {
		if (player==2){
			cout << "You Win";
		}
		else {
			cout << "Computer Win";
		}		
	}
	cout << endl;
	cout << "Do you want to play again? (y/n) ";
	if (_getch()=='n'){
		break;
	}
	system("CLS");
	}
	return 0;
}

int playerlistui(int listplayer,string space){
	for (int i=0; listplayer>i; i++){
		cout << space << "------------";
	}
	cout << endl;
	for (int i=0; listplayer>i; i++){
		cout << space << "+          +";
	}
	cout << endl;
	for (int i=0; listplayer>i; i++){
		cout << space << "+ Player ";
		cout << i+1;
		cout << " +";
	}
	cout << endl;
		for (int i=0; listplayer>i; i++){
		cout << space << "+          +";
	}
	cout << endl;
		for (int i=0; listplayer>i; i++){	
		cout << space << "------------";
	}
	cout << endl;
}

int mainuitop(string programname){
	string space="                      ";
	cout << space << "----------------------------------" << endl;
	cout << space << "           ";
	cout << programname;
	cout << space << "                            " << endl;
	cout << space << "----------------------------------" << endl;
	
}

int cardui(int playerdata[10][10], int jumlahkartu,int player, int datarank[10][10]){
	char rank[5];
	string space="  ";
	cout << "  ";
	for (int i=0; jumlahkartu>i; i++){
		if (playerdata[player][i]==1){
	    	cout << "A";
		}
		else if (playerdata[player][i]==11){
			cout << "J";
		}
		else if (playerdata[player][i]==12){
			cout << "Q";
		}
		else if (playerdata[player][i]==13){
			cout << "K";
		}
		else if (playerdata[player][i]==14){
			cout << "<fold> ";
		}
		else {
			cout << playerdata[player][i];
		}
		if (playerdata[player][i]!=14){
		if (datarank[player][i]==1){
			cout << " Diamond";
		}
		else if (datarank[player][i]==2){
			cout << " Club";
		}
		else if (datarank[player][i]==3){
			cout << " Heart";
		}
		else if(datarank[player][i]==4){
			cout << " Spade";
		}
		cout << "  ";
		}
	}
	cout << endl << endl;
	for (int i=0; jumlahkartu>i; i++){
		cout << space <<  "+-------+";
	} 
	cout << endl;
	for (int i=0; jumlahkartu>i; i++){
		cout << space << "|";
		if (playerdata[player][i]==1){
	    	cout << "A";
		}
		else if (playerdata[player][i]==11){
			cout << "J";
		}
		else if (playerdata[player][i]==12){
			cout << "Q";
		}
		else if (playerdata[player][i]==13){
			cout << "K";
		}
		else if (playerdata[player][i]==14){
			cout << " ";
		}
		else {
			cout << playerdata[player][i];
		}
		if (playerdata[player][i]==10){
			cout << "     |";			
		}
		else {
			cout << "      |";
		}
	}
	cout << endl;
	for (int i=0; jumlahkartu>i; i++){
		switch (datarank[player][i]){
		case 1:
		rank[i]='\4';
		break;
		case 2:
		rank[i]='\5';
		break;		
		case 3:
		rank[i]='\3';
		break;
		case 4:
		rank[i]='\6';
		break;
		}
		cout << space << "|";
		if (playerdata[player][i]==14){
		cout << " ";
		}
		else {
		cout << rank[i];
		}
		cout << "      |";
	}
	cout << endl;
	for (int i=0; jumlahkartu>i; i++){
		cout << space << "|   ";
		if (playerdata[player][i]==14){
			cout << "U";
		}
		else {
		cout << rank[i];  
		}
		cout << "   |";
	}
	cout << endl;
	for (int i=0; jumlahkartu>i; i++){
		cout << space << "|   ";
		if (playerdata[player][i]==14){
			cout << "P";
			cout << "   |";
		}
		else {
		cout << "    |";
		}
	}
	cout << endl;
	for (int i=0; jumlahkartu>i; i++){
		cout << space << "|   ";
		if (playerdata[player][i]==14){
			cout << "H";
			cout << "   |";
		}
		else {
		cout << "    |";
		}
	}
	cout << endl;
	for (int i=0; jumlahkartu>i; i++){
		cout << space << "+-------+";
	}
	cout << endl;
	return 0;
}

int randomnumber(int seed, int playerfactor){
	int random;
	int hasil;
	srand(time(NULL));
	random=rand()*seed+playerfactor;
	hasil=random%13;
	return hasil;
}
int randomrank(int seed, int playerfactor){
	int random;
	int hasil;
	srand(time(NULL));
	random=rand()+seed*playerfactor;
	hasil=random%4;
	return hasil;
}
