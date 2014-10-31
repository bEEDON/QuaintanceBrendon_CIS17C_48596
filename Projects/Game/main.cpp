//Brendon Quaintance

#include <iostream>
#include <string>
#include <ctime>
#include <Windows.h>
using namespace std;

struct Hero{
int health, mana,quickAttack,fireAttack,faMana;
};

void refreshScreen(Hero&Ally,Hero&Enemy);
void dots();

int main(){
	

	//Declaring Hero Objects
	Hero Ally;Ally.health=100,Ally.mana=100,Ally.quickAttack = 20,Ally.fireAttack = 40;Ally.faMana =50;
	Hero Enemy;Enemy.health=100,Enemy.mana=100,Enemy.quickAttack = 20,Enemy.fireAttack = 40;

	//Receives command from user
	char answer;

	string intro("");
	for (int i = 0; i < intro.size(); i++){
		cout << intro[i];
		Sleep(50);
	}

	//used for generating random number
	srand(unsigned(time(0)));
	bool fighting=true;

//====== Start of Fighting ==================================================
	while(fighting){

		//Sets Random Chance of Hitting
		int youHit = rand()%3;
		int enemyHit = rand()%3;
		int enemyAttack = rand()%2;
			refreshScreen(Ally,Enemy);

		cout<<"What move would you like to do?\n"
		<<"A.Quick Attack\tB.Fire Attack(-50% Mana)\n\n";
		cin>>answer;

		while((toupper(answer)=='B')&&(Ally.mana<Ally.faMana)){
			refreshScreen(Ally,Enemy);
				cout<<"What move would you like to do?\n"
				<<"A.Quick Attack\tB.Fire Attack(-50 Mana)\n\n"
				<<"Out of Mana! Choose Another Move..\n\n";
				cin>>answer;
		}
		

		while((toupper(answer)!='A')&&(toupper(answer)!='B')){
			refreshScreen(Ally,Enemy);
			cout<<"What move would you like to do?\n"
				<<"A.Quick Attack\tB.Fire Attack(-50 Mana)\n\n"
				<<"Not a Valid Move..\n\n";
			cin>>answer;
		}

		refreshScreen(Ally,Enemy);
		cout<<"You chose to use ";
		switch(toupper(answer)){
			case 'A':cout<<"Quick Attack";break;
			case 'B':cout<<"Fire Attack";break;
		}
		dots();
		//=========== Ally Attack ================================

		if(youHit){
			switch(toupper(answer)){
				case 'A': Enemy.health -= Ally.quickAttack;break;
				case 'B': Enemy.health -= Ally.fireAttack;Ally.mana -= Ally.faMana;break;
			}
			refreshScreen(Ally,Enemy);
			cout<<"Your Attack Hit!";
				Sleep(3000);
		}else{
			switch(toupper(answer)){
					case 'B': Ally.mana-=50;break;
			}
			refreshScreen(Ally,Enemy);
			cout<<"Your Attack Missed!";
			Sleep(3000);
		}
		system("CLS");

		//===== Determine if both are still alive ============
		if(Ally.health<=0){
			refreshScreen(Ally,Enemy);
			cout<<"You're Dead! GAME OVER\n\n";return 0;
		}else if(Enemy.health<=0){
			refreshScreen(Ally,Enemy);
			cout<<"You WIN!\n\n";return 0;
		}

		//=========== Enemy Attack ================================
		refreshScreen(Ally,Enemy);
		cout<<"The Enemy is going to use ";
		if(enemyAttack)cout<<"Quick Attack";
		else cout<<"Fire Attack";
		dots();

		if(enemyHit){
			if(enemyAttack){
				Ally.health -= Enemy.quickAttack;
				refreshScreen(Ally,Enemy);
				cout<<"His attack Hit!\n\n";
				Sleep(3000);
			}else{
				Ally.health -= Enemy.fireAttack;Enemy.mana-=50;
				refreshScreen(Ally,Enemy);
				cout<<"His attack Hit!\n\n";
				Sleep(3000);
			}
		}else{
			if(!enemyAttack)Enemy.mana-=50;
			refreshScreen(Ally,Enemy);
			cout<<"His attack missed!\n\n";
			Sleep(3000);
		}

		//===== Determine if both are still alive ============
			if(Ally.health<=0){
				refreshScreen(Ally,Enemy);
				cout<<"You're Dead! GAME OVER\n\n";fighting=false;
			}else if(Enemy.health<=0){
				refreshScreen(Ally,Enemy);
				cout<<"You WIN!\n\n";fighting=false;
			}
	}
	return 0;

}
void refreshScreen(Hero&Ally,Hero&Enemy){
	system("CLS");

	if(Ally.health<0)Ally.health = 0;
	if(Enemy.health<0)Enemy.health = 0;

	//========= Enemy's Bars =======================
	cout << "-ENEMY-\n"; 
	if(Enemy.health==100){
		cout << "   Health: "<<Enemy.health<<"% ";
		for(int i=0;i<Enemy.health/5;i++){
			cout<<"=";
		}
	}else if((Enemy.health<100)&&(Enemy.health>0)){
		cout << "   Health:  "<<Enemy.health<<"% ";
		for(int i=0;i<Enemy.health/5;i++){
			cout<<"=";
		}
	}else{
		cout << "   Health:   "<<Enemy.health<<"% ";
		for(int i=0;i<Enemy.health/5;i++){
			cout<<"=";
		}
	}
	cout << endl;

	if(Enemy.mana==100){
		cout << "   Mana:   "<<Enemy.mana<<"% ";
		for(int i=0;i<Enemy.mana/5;i++){
			cout<<"=";
		}
	}else if((Enemy.mana<100)&&(Enemy.mana>0)){
		cout << "   Mana:    "<<Enemy.mana<<"% ";
		for(int i=0;i<Enemy.mana/5;i++){
			cout<<"=";
		}
	}else{
		cout << "   Mana:     "<<Enemy.mana<<"% ";
		for(int i=0;i<Enemy.mana/5;i++){
			cout<<"=";
		}
	}
	//========= Your Bars =======================
	cout << "\n\n-You-\n"; 

	if(Ally.health==100){
		cout << "   Health: "<<Ally.health<<"% ";
		for(int i=0;i<Enemy.health/5;i++){
			cout<<"=";
		}
	}else if((Ally.health<100)&&(Ally.health>0)){
		cout << "   Health:  "<<Ally.health<<"% ";
		for(int i=0;i<Ally.health/5;i++){
			cout<<"=";
		}
	}else{
		cout << "   Health:   "<<Ally.health<<"% ";
		for(int i=0;i<Ally.health/5;i++){
			cout<<"=";
		}
	}
	cout << endl;

	if(Ally.mana==100){
		cout << "   Mana:   "<<Ally.mana<<"% ";
		for(int i=0;i<Ally.mana/5;i++){
			cout<<"=";
		}
	}else if((Ally.mana<100)&&(Ally.mana>0)){
		cout << "   Mana:    "<<Ally.mana<<"% ";
		for(int i=0;i<Ally.mana/5;i++){
			cout<<"=";
		}
	}else{
		cout << "   Mana:     "<<Ally.mana<<"% ";
		for(int i=0;i<Ally.mana/5;i++){
			cout<<"=";
		}
	}
	cout<<endl<<endl;
}
void dots(){
	string dots("...");
	for (int i = 0; i < dots.size(); i++){
		cout << dots[i];
		Sleep(1000);
	}
}

