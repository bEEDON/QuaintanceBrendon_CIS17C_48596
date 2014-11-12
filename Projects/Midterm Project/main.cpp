
/*================================ Lord of the Rings Game =========================================
	
	Author: Brendon Quaintance
	Class:  CIS-17C Professor Lehr
	Date:   November 11, 2014

	Description: This games allows the user to pick from 3 different hero to fight an enemy. Each
		Hero has specific advantages, disadvantages. After picking a hero, the user can buy items
		at an item store. After that, they are sent into the battle with the enemy. While on the battle
		field, the user can chose to use 3 different attacks or use items that they have purchase from 
		the Item Store. Random numbers are generated used to determine attack damages, slow attack chance,
		missing attacks, and picking an attack move for the enemey. Each player has a 25% chance of missing 
		their attack. The game goes on until one of them dies. After the game is over, the user has the
		choice to rematch with the same hero, reselect a different hero, or quit the game.

	Included:
		- Hero Class that has different properties that vary based upon which Hero is chosen to play with.
		- Map that sorts and displays items container with their values amounts.
		- Queue that is used for pushing/popping each amount of each item that the user has.
		- Stack that is  used for pushing/popping total item amount that the user has.
		- Set that is used for sorting and displaying Main Menu Screen.
		- Iterators are used to sequence through the Sets, Maps, and For Loops.
		- Algorithm that is used to sort the title page heading.

	Lines of code: 1330

================================================================================================*/

//Include Libraries
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <Windows.h>
using namespace std;

//Required Libraries for Midterm
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>

//Class that assigns Ally's specific abilities
class Hero{
public:
	int health, mana,att1,att2,att2M,att3,items,armor, att3M;string name,att1N,att2N,att3N;
	Hero(){name="";health=0; mana=0;att1N="";att1=0;att2N="";att2=0;att2M=0;att3N="";att3=0; att3M=0, items=0;armor=0;}
	Hero(string name,int health,int mana,string att1N,int att1,string att2N,int att2,int att2M,string att3N,int att3,int att3M,int items, int armor)
	{
		this->health=health;this->mana=mana;this->att1=att1;this->att2=att2;this->att2M=att2M;this->att3=att3;this->att3M=att3M;
		this->items=items;this->att1N=att1N;this->att2N=att2N;this->att3N=att3N; this->name=name;this->armor=armor;
	}
	~Hero(){};
};

//============== Global Variables =========================================
map<string,int>items;//sorts and displays items container with their values
queue<int> doubleDamage,invisibility,regeneration,haste;//used for pushing/each amount of different items
stack<int> itemCount;//used for pushing/popping total item amount
//=========================================================================

//Included Functions
void nameStamp();
void title();
void printIntro();
char heroSelection();
void assignSkills(char hero,int&speech);
void itemStoreSpeech(Hero&Ally,Hero&Enemy,int&speech);
void itemStore(Hero&Ally,Hero&Enemy);
void itemStoreRefresh(Hero&Ally,int gold);
void preFight(Hero&Ally,Hero&Enemy);
void fightingPhase(Hero&Ally,Hero&Enemy);
void getAnswer(Hero&Ally,Hero&Enemy,char&answer);
void attack(Hero&Ally,Hero&Enemy,char answer);
void refreshScreen(Hero&Ally,Hero&Enemy);
void assignDamage(Hero&Ally,Hero&Enemy);
bool itemBag(Hero&Ally,Hero&Enemy);
void dots();

/*=================================== Main ==============================================
	Purpose: Main function is connected to all the other functions. After all other 
			 functions are called(game is over), it asks the user if they want to 
			 rematch, reselect hero, or quit.
=========================================================================================*/
int main(){
	char choice='2';
	char hero;
	int speech = 1;

	//used for sorting and displaying Main Menu Screen
	set<string> mainMenu;
	mainMenu.insert("              2.)Reselect Hero");
	mainMenu.insert("              3.)Quit");
	mainMenu.insert("              1.)Rematch");

    nameStamp();
	//Title Page
	title();
	//Print Introduction
	printIntro();

	while(choice!='3'){
		//Select a Hero
		if(choice=='2'){
			hero = heroSelection();
		}
		//Assigning Hero properties And Begin Fight
		assignSkills(hero,speech);

		cout<<"\n\n__________________________________ MAIN MENU ___________________________________\n\n";
		for (set<string>::const_iterator p = mainMenu.begin( );p != mainMenu.end( ); ++p){
			 cout << *p << endl;
		}cout<<"\n________________________________________________________________________________";
		cout<<endl<<endl;
		cin>>choice;
		while((choice!='1')&&(choice!='2')&&(choice!='3')){
			system("CLS");
			cout<<"\n\n__________________________________ MAIN MENU ___________________________________\n\n";
			for (set<string>::const_iterator p = mainMenu.begin( );p != mainMenu.end( ); ++p){
				 cout << *p << endl;
			}
			cout<<"\n________________________________________________________________________________";
			cout<<"\n\nInvalid choice!"<<endl<<endl;
			cin>>choice;
		}
	}
	return 0;
}
/*================================= Name Stamp ==========================================
	Purpose: Displays my name, date, class, and project when opened
=========================================================================================*/
void nameStamp(){
	cout<<"\n\n\n\n\n\n\n\n\n\n                            ";
	Sleep(500);
	string s1("Brendon Quaintance\n\n\n                         ");
	string s2("CIS-17C Midterm Project\n                              ");
	string s3("Professor Lehr");
	string s4("November, 2014\n                              ");

	string array [4] = {s3,s1,s4,s2};

	//Sort String Array
	sort(array,array+4);

	for (int i = 0; i < 4; i++){
		string temp = array[i];
		for(int j =0; j<temp.size();j++){
			cout << temp[j];
			Sleep(15);
		}
		Sleep(500);
	}
	Sleep(2000);
	system("CLS");
}
/*=================================== Title ===========================================
	Purpose: Prints out the title "Lord of the Rings" letter by letter.
=========================================================================================*/
void title(){
	cout<<"\n________________________________________________________________________________";
	  string t1("  _\n");
	  string t2(" | | 			            __  ___\n");
	  string t3(" | |			           /  \\| __|\n");
	  string t4(" | |       ____  ____    __        ||||| _|      ____    _  _    _  _____  __\n");
	  string t5(" | |      /    \\|    \\  |   \\      \\__/|_|      |    \\  | || \\  | |/  _  \\/  \\\n");
	  string t6(" | |      | || || ||  | | || \\ ____  _   _  ___ | ||  | | ||  \\ | || / |_|||\\_|\n");
	  string t7(" | |      | || ||    /  | || ||_  _|| |_| || __||    /  | ||   \\| || | __ ||_  \n");
	  string t8(" | |      | || || |\\ \\  | || |  | | |  _  || _| | |\\ \\  | || |\\   || ||_ |\\__\\ \n");
	  string t9(" | |_____ | || || | \\ \\ | || /  |_| |_| |_||___|| | \\ \\ | || | \\  || |_/ /__| |\n");
	 string t10(" |_______|\\____/|_|  \\_\\|___/                   |_|  \\_\\|_||_|  \\_|\\____/ \\___/ \n");
 	string array [10] = {t1,t2,t3,t4,t5,t6,t7,t8,t9,t10};

	for (int i = 0; i < 10; i++){
		string temp = array[i];
		for(int j =0; j<temp.size();j++){
			cout << temp[j];
			Sleep(10);
		}
	}
	cout<<"________________________________________________________________________________";
	cout<<"\n   		             ";
	Sleep(3000);

	string name("By: Brendon Quaintance");
	for(int i = 0;i<name.size();i++){
		cout<<name[i];
		Sleep(30);
	}
	Sleep(5000);
	cout<<"\n\n";
}
/*================================ Print Introdcution =========================================
	Purpose: This function Prints out the introduction of letter by letter
=========================================================================================*/
void printIntro(){
	cout << "\n\n    ";
  
	string intro("      After hiding and lying dormant for 500 years, Sauron, an Evil Dark\n\n Lord, started to reveal himself during the Second Age.");
	string intro2(" By the year of SA\n\n 1000 he had grown powerful enough to establish himself in Mordor in eastern\n\n Middle-earth, where he started building the Dark Tower of Barad-dur close to\n\n Mount Doom.");
	string intro3(" Sauron began assembling armies of Uruk, Graugs and other creatures,\n and started to corrupt the hearts of Men, giving them delusions of wealth and\n\n power.");
	string intro4(" In the Second Age, Sauron took on a fair form and used it under the\n\n alias Annatar, or the Lord of Gifts, to deceive the Elves into creating the\n\n One Ring.");
	string intro5(" While gaining enormous amounts of power with the One ring, he began\n\n to rule all of Mordor and enslave all Allies.");
	string intro6(" All hope of survivability is up\n\n to you. You must destroy him and the Ring of Power!");

	string array [6] = {intro,intro2,intro3,intro4,intro5,intro6};


	for (int i = 0; i < 6; i++){
		string temp = array[i];
		for(int j =0; j<temp.size();j++){
			cout << temp[j];
			Sleep(15);
		}
		Sleep(3500);
	}
	dots();
	Sleep(1000);
}
/*================================ Hero Selection =========================================
	Purpose: This function prompts the user the 3 different heroes and their advantages
			 and disadvantages. The user then picks one of the three heros
=========================================================================================*/
char heroSelection(){
	system("CLS");
	char answer;

	cout<<"HERO SELECTION:\n_______________________________________________________________________________\n"
		<<"     ========)===================== Aragorn ==============================>\n          Aragorn's skills in battle lay primarily in his sword craft. He"
		<<"\n     is a mighty warrior with the sword and easily defeated many types of\n     foes, suchas Trolls and Ringwraiths.\n"
		<<"               Advantage:    Has Armor That Absorbs Extra Damage\n               Disadvantage: Slower Attacks"
		<<"\n\n     >>>=========================== Legolas ==============================>\n          Legolas is an elf of the Woodland Realm of Mirkwood. Legolas \n"
		<<"     specializes in using a bow against the wolves who attack the Fellowship\n     in the mountain pass and against goblins in the Fight in Balin's Tomb."
		<<"\n               Advantage:    Can Fire Attacks Multiple Times\n               Disadvantage: Lower Damage Output"
		<<"\n                                                                        __"
		<<"\n     ============================== Gandalf ===========================(__)\n          Gandalf is wizard of the Secret Fire, wielder of the flame of\n"
		<<"     Anor, and bearer of Narya. He creates blinding flashes and other\n     pyrotechnics to distract the goblins of the Misty Mountains."
		<<"\n               Advantage:    High Magic Attacks\n               Disadvantage: Consumes High Amounts of Mana\n_______________________________________________________________________________";

	cout<<"\nWhich Hero Would You Like to Play?  1.Aragon  2.Legolas  3.Gandalf\n";
	cin>>answer;

	while((answer!='1')&&(answer!='2')&&(answer!='3')){
		cout<<"Not a valid choice!\n\n";
		cin>>answer;
	}
	return answer;
}
/*================================ Assign Skills =========================================
	Purpose: This function assigns property values base on which hero they chose. It then
			 sends the user to the items store(), prefight(), fightingPhase(), and
			 deconstructs the objects after the fighting phase is over.
=========================================================================================*/
void assignSkills(char hero,int&speech){
	Hero Enemy("The Dark Sauron",800,0,"Mind Decay",0,"Black Toxic Fog",0,0,"Smack Down",0,0,1,0);
	if(hero=='1'){
		Hero Ally("Aragorn the Swordsman",200,0,"Spinning Slash",0,"Dagger Stab",0,0,"Lunge Attack",0,0,0,200);
			itemStoreSpeech(Ally,Enemy,speech);
			preFight(Ally,Enemy);//Prefight Prompt
			fightingPhase(Ally,Enemy);//Send Hero to Finght
			Ally.~Ally();//Delete Object after fight
	}else if(hero=='2'){
		Hero Ally("Legolas the Archer",200,100,"Arrowhead Assault",0,"Agility Arrow",0,25,"Focused Shot",0,0,0,0);
			itemStoreSpeech(Ally,Enemy,speech);
			preFight(Ally,Enemy);//Prefight Prompt
			fightingPhase(Ally,Enemy);//Send Hero to Fight
			Ally.~Ally();//Delete Object after fight
	}else if(hero=='3'){
		Hero Ally("Gandalf the Wizard",200,100,"Staff Hit",0,"Supernova",0,50,"Inferno Blast",0,50,0,0);
			itemStoreSpeech(Ally,Enemy,speech);
			preFight(Ally,Enemy);//Prefight Prompt
			fightingPhase(Ally,Enemy);//Send Hero to Fight
			Ally.~Ally();//Delete Object after fight
	}
	Enemy.~Enemy();
}
void itemStoreSpeech(Hero&Ally,Hero&Enemy,int&speech){
	system("CLS");

	if(speech==1){
		string talk("\n\n\n\n\n\n\n\n     Before leaving for battle, you have Gold Coins that can be used to\n\n     purchase items that can assist in you defeating the Evil Dark Lord");
		for (int i = 0; i < talk.size(); i++){
			cout << talk[i];
			Sleep(15);
		}
		dots();
		string talk2("\n\n\n\n              Let's visit Frodo at the Item Store in Hobbiton");
		for (int i = 0; i < talk2.size(); i++){
			cout << talk2[i];
			Sleep(15);
		}
		dots();
	}
	itemStore(Ally,Enemy);
	speech=0;
}
/*================================ Item Store =============================================
	Purpose: This function displays the items that are in the store for the user to purchase.
==========================================================================================*/
void itemStore(Hero&Ally,Hero&Enemy){ 
	char item= 'a';
	char ans = 'a';
	int gold = 400;	
	string item1="Health Potion";int item1C=100;
	string item2="Mana Potion";int item2C=100;
	string item3="Double Damage";int item3C=100;
	string item4="Invisibility";int item4C=100;
	string item5="Regeneration";int item5C=300;
	string item6="Haste";int item6C=100;

	//======== Start with no Items ===============
	items["5.)Invisibility "]=0;
	items["3.)Regeneration "]=0;
	items["1.)Health Potion"]=0;
	items["2.)Mana Potion  "]=0;
	items["4.)Double Damage"]=0;
	items["6.)Haste        "]=0;

	//======== Delete Any Existing Active Items ===============
	while ((!itemCount.empty())&&(!doubleDamage.empty())&&(!invisibility.empty())&&(!regeneration.empty())&&(!haste.empty()))
	 {
		 doubleDamage.pop();
		 invisibility.pop();
		 regeneration.pop();
		 haste.pop();
	 }
	while(!itemCount.empty()){
		itemCount.pop();
	}

	string name;
	system("CLS");
	cout<<"\n__________________________________ Item Store __________________________________\n";

	string talk("      Frodo: Hello!! Welcome ");
	for (int i = 0; i < talk.size(); i++){
		cout << talk[i];
		Sleep(15);
	}
	if(Ally.name=="Aragorn the Swordsman"){
		string name("Aragorn!");
		for (int i = 0; i < name.size(); i++){
		cout << name[i];
		Sleep(15);
		}
	}else if(Ally.name=="Legolas the Archer"){
		string name("Legolas!");
		for (int i = 0; i < name.size(); i++){
		cout << name[i];
		Sleep(15);
		}
	}else{
		string name("Gandalf!");
		for (int i = 0; i < name.size(); i++){
		cout << name[i];
		Sleep(15);
		}
	}Sleep(1000);
	string talk2(" Please let me know if I can\n\n             help you find anything you are looking for");
	for (int i = 0; i < talk2.size(); i++){
		cout << talk2[i];
		Sleep(15);
	}
	dots();
	Sleep(500);
	
	while(ans!='1'){
		int itemAmount = 0;

		itemStoreRefresh(Ally,gold);
		cout<<"\nFrodo: Enter In the Item Number You Wish to Purchase: ";
		cin>>item;

		while((item!='1')&&(item!='2')&&(item!='3')&&(item!='4')&&(item!='5')&&(item!='6')&&(item!='7')){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: Invalid choice!\n\n";
			cin>>item;
		}
		if(item=='1'){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: How many "<<item1<<"(s) would you like to purchase? ";
			cin>>itemAmount;
			if(gold<item1C){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(gold<item1C*itemAmount){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(itemAmount>0){
				items["1.)Health Potion"]+=itemAmount;
				for(int i = 0;i<itemAmount;i++){
					itemCount.push(1);
				}
				gold -= item1C*itemAmount;
				cout<<"\nFrodo: Here is the "<<itemAmount<<" "<<item1<<"(s) that you requested! -"<<item1C*itemAmount<<" Gold";
				Sleep(3000);
			}
		}
		if((item=='2')&&(Ally.name!="Aragorn the Swordsman")){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: How many "<<item2<<"(s) would you like to purchase? ";
			cin>>itemAmount;
			if(gold<item2C){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(gold<item2C*itemAmount){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(itemAmount>0){
				items["2.)Mana Potion  "] += itemAmount;
				for(int i = 0;i<itemAmount;i++){
					itemCount.push(1);
				}
				gold -= item2C*itemAmount;
				cout<<"\nFrodo: Here is the "<<itemAmount<<" "<<item2<<"(s) that you requested! -"<<item2C*itemAmount<<" Gold";
				Sleep(3000);
			}
		}else if(item=='2'){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: You have no use for Mana!";
			Sleep(3000);
		}
		if(item=='3'){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: How many "<<item5<<"(s) would you like to purchase? ";
			cin>>itemAmount;
			if(gold<item4C){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(gold<item5C*itemAmount){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(itemAmount>0){
				items["3.)Regeneration "]+=itemAmount;
				for(int i = 0;i<itemAmount;i++){
					itemCount.push(1);
				}
				gold -= item5C*itemAmount;;
				cout<<"\nFrodo: Here is the "<<itemAmount<<" "<<item5<<"(s) that you requested! -"<<item5C*itemAmount<<" Gold";
				Sleep(3000);
			}
		}
		if(item=='4'){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: How many "<<item3<<"(s) would you like to purchase? ";
			cin>>itemAmount;
			if(gold<item3C){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(gold<item3C*itemAmount){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(itemAmount>0){
				items["4.)Double Damage"]+=itemAmount;
				for(int i = 0;i<itemAmount;i++){
					itemCount.push(1);
				}
				gold -= item3C*itemAmount;
				cout<<"\nFrodo: Here is the "<<itemAmount<<" "<<item3<<"(s) that you requested! -"<<item3C*itemAmount<<" Gold";
				Sleep(3000);
			}
		}
		if(item=='5'){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: How many "<<item4<<"(s) would you like to purchase? ";
			cin>>itemAmount;
			if(gold<item4C){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(gold<item4C*itemAmount){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(itemAmount>0){
				items["5.)Invisibility "]+=itemAmount;
				for(int i = 0;i<itemAmount;i++){
					itemCount.push(1);
				}
				gold -= item4C*itemAmount;;
				cout<<"\nFrodo: Here is the "<<itemAmount<<" "<<item4<<"(s) that you requested! -"<<item4C*itemAmount<<" Gold";
				Sleep(3000);
			}
		}
		if(item=='6'){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: How many "<<item6<<"(s) would you like to purchase? ";
			cin>>itemAmount;
			if(gold<item4C){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(gold<item6C*itemAmount){
				itemStoreRefresh(Ally,gold);
				cout<<"\nFrodo: You do not have enough Gold!\n\n";
				Sleep(2000);
			}else if(itemAmount>0){
				items["6.)Haste        "]+=itemAmount;
				for(int i = 0;i<itemAmount;i++){
					itemCount.push(1);
				}
				gold -= item6C*itemAmount;;
				cout<<"\nFrodo: Here is the "<<itemAmount<<" "<<item6<<"(s) that you requested! -"<<item6C*itemAmount<<" Gold";
				Sleep(3000);
			}
		}
		if(item=='7'){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: Are You Sure You're Ready to Begin Your Journey? You still have "<<gold<<" Gold\n       left..  1.Yes 2.No\n\n";
			cin>>ans;
		}
		while((gold<100)&&(ans!='1')){
			itemStoreRefresh(Ally,gold);
			cout<<"\nFrodo: You Have Run Out of Gold!\n\nAre You Ready to Begin Your Journey 1.Yes 2.No?\n\n";
			cin>>ans;
		}
	}
	itemStoreRefresh(Ally,gold);
	string ally = Ally.name;
	string enemy = Enemy.name;
	string talk4("\nFrodo: Goodluck ");
	string talk5("! May ");
	string talk6(" and the Ring of \n\n       Power be destroyed!!");
	string array[5] ={talk4,ally,talk5,enemy,talk6};

	for (int i = 0; i < 5; i++){
		string temp = array[i];
		for(int j =0; j<temp.size();j++){
			cout << temp[j];
			Sleep(15);
		}
	}
	Sleep(3000);
}
/*============================== Item Store Refresh ======================================
	Purpose: This function refreshes the screen in the item store in order to display
			 and confirm the purchasing of items and the change of gold amount
=========================================================================================*/
void itemStoreRefresh(Hero&Ally,int gold){
	string item1="Health Potion";int item1C=100;
	string item2="Mana Potion";int item2C=100;
	string item3="Double Damage";int item3C=100;
	string item4="Invisibility";int item4C=100;
	string item5="Regeneration";int item5C=300;
	string item6="Haste";int item6C=100;
	string name="";

	if(Ally.name=="Aragorn the Swordsman"){
		name="Aragorn!";
	}else if(Ally.name=="Legolas the Archer"){
		name="Legolas!";
	}else{
		name="Gandalf!";
	}
	system("CLS");
		cout<<"\n__________________________________ Item Store __________________________________\n"
			<<"      Frodo: Hello!! Welcome "<<name<<" Please let me know if I can\n\n             help you find anything you are looking for..."
			<<"\n\n               Items:          Costs:        Description:\n\n"
			<<"            1.) "<<item1<<" "<<item1C<<" Gold   -Fully Restores Health\n"
			<<"            2.) "<<item2<<"   "<<item2C<<" Gold   -Fully Restores Mana\n"
			<<"            3.) "<<item5<<"  "<<item5C<<" Gold   -Fully Restores Health & Mana\n"
			<<"            4.) "<<item3<<" "<<item3C<<" Gold   -Doubles Your Attack Damage\n"
			<<"            5.) "<<item4<<"  "<<item4C<<" Gold   -Causes Enemy's Attack to Miss\n"
			<<"            6.) "<<item6<<"         "<<item6C<<" Gold   -Increases Your Attack Speed\n"
			<<"            7.) Exit\n"
			<<"________________________________________________________________________________\n"
			<<"                              Gold Remaining: "<<gold<<"\n";
}
void preFight(Hero&Ally,Hero&Enemy){
	system("CLS");
	cout<<"\n\n\n\n\n\n\n\n\n\n    "<<Ally.name<<" has gained enough courage to fight "<<Enemy.name<<"!\n\n\n\n\n                      ";
	Sleep(2000);
	string begin("The Battle Will Begin In: 3");
	for (int i = 0; i < begin.size(); i++){
		cout << begin[i];
		Sleep(15);
	}
	int num=3;
	Sleep(1250);
	for(int j=2; j>0;j--){
		system("CLS");
		cout<<"\n\n\n\n\n\n\n\n\n\n    "<<Ally.name<<" has gained enough courage to fight "<<Enemy.name<<"!\n\n\n\n\n         ";
		cout << "             The Battle Will Begin In: ";
		cout<<j;
		Sleep(1250);		
	}
}
/*================================ Fighting Phase =========================================
	Purpose: This is a recursive function beings the fighting phase of the game. After each 
			 round, it checks to see if both character are still alive. If so, it starts
			 another round by calling its own function name;
=========================================================================================*/
void fightingPhase(Hero&Ally,Hero&Enemy){
	system("CLS");
	//Receives command from user
	char answer;

	//used for generating random number
	srand(unsigned(time(0)));

	//Sets 66% Chance of Hitting
	int enemyHit = rand()%4;
	
	//Assigns Random Damage For Each Move
	assignDamage(Ally,Enemy);
	//Assigns random interger from 1-9 to determine what attack the enemy will use
	int enemyAttack = rand()%8+1;

	refreshScreen(Ally,Enemy);
	getAnswer(Ally,Enemy,answer);

	if(answer=='4'){
		refreshScreen(Ally,Enemy);
		itemBag(Ally,Enemy);
	}
	if(answer!='4'){
		
		//=========== Ally Attack ================================
		attack(Ally,Enemy,answer);
	}

	//===== Determine if enemy is still alive ============
	 if(Enemy.health<=0){
		cout<<"\n\nYou Have Slain "<<Enemy.name<<"!\n\n\n           ";
		Sleep(3000);
		string def("VICTORY!");
		for(int i=0;i<def.size();i++){
			cout<<def[i];
		}Sleep(3000);
		system("CLS"); 
		return;
	}

	//=========== Enemy Attack ================================
	refreshScreen(Ally,Enemy);

	if(invisibility.size()>1){
		enemyHit=3;
	}

	cout<<Enemy.name<<" Attacks with ";
	if(enemyAttack<4){
		cout<<Enemy.att1N;
	}
	else if(enemyAttack<7){ 
		cout<<Enemy.att2N;
	}
	else if(enemyAttack>=7){
		cout<< Enemy.att3N;
	}
	dots();

	//If the enemy's attack hit
	if(enemyHit<3){
		if(enemyAttack<4){
			if(Ally.name=="Aragorn the Swordsman"){
				if(Ally.armor>=Enemy.att1){
					Ally.armor -= Enemy.att1;
				}else if(Ally.armor<Enemy.att1){
					Ally.armor -= Enemy.att1;
					for(int i = 0;i>Ally.armor;i--){
						Ally.health--;
					}
					Ally.armor=0;
				}else{
				Ally.health -= Enemy.att1;
				}
			}else{
				Ally.health -= Enemy.att1;
			}
			refreshScreen(Ally,Enemy);
			cout<<"His attack Hit! Damge Dealt: "<<Enemy.att1<<"\n\n";
			Sleep(3000);
		}else if(enemyAttack<7){
			if(Ally.name=="Aragorn the Swordsman"){
				if(Ally.armor>=Enemy.att2){
					Ally.armor -= Enemy.att2;
				}else if(Ally.armor<Enemy.att2){
					Ally.armor -= Enemy.att2;
					for(int i = 0;i>Ally.armor;i--){
						Ally.health--;
					}
					Ally.armor=0;
				}else{
				Ally.health -= Enemy.att2;
				}
			}else{
				Ally.health -= Enemy.att2;
			}
			refreshScreen(Ally,Enemy);
			cout<<"His attack Hit! Damge Dealt: "<<Enemy.att2<<"\n\n";
			Sleep(3000);
		}else if(enemyAttack>=7){
			if(Ally.name=="Aragorn the Swordsman"){
				if(Ally.armor>=Enemy.att3){
					Ally.armor -= Enemy.att3;
				}else if(Ally.armor<Enemy.att3){
					Ally.armor -= Enemy.att3;
					for(int i = 0;i>Ally.armor;i--){
						Ally.health--;
					}
					Ally.armor=0;
				}else{
				Ally.health -= Enemy.att3;
				}
			}else{
				Ally.health -= Enemy.att3;
			}
			refreshScreen(Ally,Enemy);
			cout<<"His attack Hit! Damge Dealt: "<<Enemy.att3<<"\n\n";
			Sleep(3000);
		}
	}else{
		refreshScreen(Ally,Enemy);
		cout<<"His attack missed!\n\n";
		Sleep(3000);
	}
	//Decrease Invisibility duration by 1
	if(invisibility.size()>1){
		invisibility.pop();
	}
	//If Invisibility is depleated, it notifies user
	if(invisibility.size()==1){
		refreshScreen(Ally,Enemy);
		cout<<"Invisibilty has worn off!";
		Sleep(3000);
		invisibility.pop();
	}

	//===== Determine if you are still alive ============
	if(Ally.health<=0){
		cout<<"You Have Been Slained by "<<Enemy.name<<"!\n\n\n           ";Sleep(3000);
		string def("DEFEATED!");
		for(int i=0;i<def.size();i++){
			cout<<def[i];
		}Sleep(3000);
		system("CLS"); 
		return;
	}
	//Start another round
	fightingPhase(Ally,Enemy);
}

/*================================ refreshScreen =========================================
	Purpose: This function refreshes the screen and updates different properties such
		     as Health, Mana, and Items
=========================================================================================*/
void refreshScreen(Hero&Ally,Hero&Enemy){
	system("CLS");

	if(Ally.health<0)Ally.health = 0;
	if(Enemy.health<0)Enemy.health = 0;
	if(Ally.mana<0)Ally.mana=0;

	cout<<endl;

	//========= Enemy's Bars =======================
	cout << "    -"<<Enemy.name<<"-\n"; 
	if(Enemy.health==800){
		cout << "        Health: "<<Enemy.health/8<<"% ";
		for(int i=0;i<Enemy.health/40;i++){
			cout<<"=";
		}
	}else if((Enemy.health<800)&&(Enemy.health>100)){
		cout << "        Health:  "<<Enemy.health/8<<"% ";
		for(int i=0;i<Enemy.health/40;i++){
			cout<<"=";
		}
	}else if((Enemy.health<100)&&(Enemy.health>=20)){
		cout << "        Health:  "<<Enemy.health/8<<"% ";
		for(int i=0;i<Enemy.health/40;i++){
			cout<<"=";
		}
	}else if(Enemy.health<20){
		cout << "        Health:   "<<Enemy.health/8<<"% ";
		for(int i=0;i<Enemy.health/40;i++){
			cout<<"=";
		}
	}
	cout << endl;
	//========= Your Bars =======================
	cout << "\n\n    -"<<Ally.name<<"-\n"; 

	if(Ally.name!="Aragorn the Swordsman"){
		if(Ally.health==200){
			cout << "        Health: "<<Ally.health/2<<"% ";
			for(int i=0;i<Ally.health/10;i++){
				cout<<"=";
			}
		}else if((Ally.health<200)&&(Ally.health>=20)){
			cout << "        Health:  "<<Ally.health/2<<"% ";
			for(int i=0;i<Ally.health/10;i++){
				cout<<"=";
			}
		}else if(Ally.health<20){
			cout << "        Health:   "<<Ally.health/2<<"% ";
			for(int i=0;i<Ally.health/10;i++){
				cout<<"=";
			}
		}
	}
	if(Ally.name=="Aragorn the Swordsman"){
		if(Ally.armor==200){
			cout << "         Armor: "<<Ally.armor/2<<"% ";
			for(int i=0;i<Ally.armor/10;i++){
				cout<<"=";
			}
		}else if((Ally.armor<200)&&(Ally.armor>=20)){
			cout << "         Armor:  "<<Ally.armor/2<<"% ";
			for(int i=0;i<Ally.armor/10;i++){
				cout<<"=";
			}
		}else if(Ally.armor<20){
			cout << "         Armor:   "<<Ally.armor/2<<"% ";
			for(int i=0;i<Ally.armor/10;i++){
				cout<<"=";
			}
		}cout<<endl;
		if(Ally.health==200){
			cout << "        Health: "<<Ally.health/2<<"% ";
			for(int i=0;i<Ally.health/10;i++){
				cout<<"=";
			}
		}else if((Ally.health<200)&&(Ally.health>=20)){
			cout << "        Health:  "<<Ally.health/2<<"% ";
			for(int i=0;i<Ally.health/10;i++){
				cout<<"=";
			}
		}else if(Ally.health<20){
			cout << "        Health:   "<<Ally.health/2<<"% ";
			for(int i=0;i<Ally.health/10;i++){
				cout<<"=";
			}
		}
	}
	if(Ally.name!="Aragorn the Swordsman"){
		cout<<endl;
		if(Ally.mana==100){
		cout << "          Mana: "<<Ally.mana<<"% ";
			for(int i=0;i<Ally.mana/5;i++){
				cout<<"=";
			}
		}else if((Ally.mana<100)&&(Ally.mana>=10)){
			cout << "          Mana:  "<<Ally.mana<<"% ";
			for(int i=0;i<Ally.mana/5;i++){
				cout<<"=";
			}
		}else if(0<Ally.mana<10){
			cout << "          Mana:   "<<Ally.mana<<"% ";
			for(int i=0;i<Ally.mana/5;i++){
				cout<<"=";
			}
		}
	}
	cout<<endl<<endl<<endl;
}
/*==================================== dots ============================================
	Purpose: This function outputes "..." with delay
=========================================================================================*/
void dots(){
	string dots("...");
	for (int i = 0; i < dots.size(); i++){
		cout << dots[i];
		Sleep(750);
	}
}
/*================================ Assign Damage =========================================
	Purpose: This function assigns random damages to each heros' attacks. If double damage
			 is active, it doubles the random number given.
=========================================================================================*/
void assignDamage(Hero&Ally,Hero&Enemy){
	if(doubleDamage.size()>0){
		if(Ally.name=="Aragorn the Swordsman"){
			Ally.att1 = (rand()%30+51)*2, Ally.att2=(rand()%20+41)*2, Ally.att3=(rand()%20+41)*2;}
		else if(Ally.name=="Legolas the Archer"){
			Ally.att1 = (rand()%30+21)*2, Ally.att2=(rand()%15+16)*2, Ally.att3=(rand()%10+51)*2;}
		else {Ally.att1 = (rand()%30+21)*2, Ally.att2=(rand()%90+71)*2, Ally.att3=(rand()%40+111)*2;}
	}else{
		if(Ally.name=="Aragorn the Swordsman"){
			Ally.att1 = rand()%30+51, Ally.att2=rand()%20+41; Ally.att3=rand()%20+41;}
		else if(Ally.name=="Legolas the Archer"){
			Ally.att1 = rand()%30+21, Ally.att2=rand()%15+16; Ally.att3=rand()%10+51;}
		else {Ally.att1 = rand()%30+21, Ally.att2=rand()%90+71; Ally.att3=rand()%40+111;}
	}
	Enemy.att1 = rand()%20+41, Enemy.att2=rand()%30+41; Enemy.att3=rand()%20+41;
}
/*=================================== Item Bag ===========================================
	Purpose: This functions prompts the user what item to use. Base on what item is chosen,
			 it executes what the items is supposed to do and returns to fighting phase
=========================================================================================*/
bool itemBag(Hero&Ally,Hero&Enemy){
	int i =0;
	char answer='0';
	
	refreshScreen(Ally,Enemy);
	cout<<"What item do you wish to use?\n\n";

	for (map<string,int>::iterator itemName=items.begin(); itemName!=items.end(); ++itemName){
		cout << "    " << itemName->first << " " << itemName->second << " Left" << endl;
		i++;
	}
	cout<<"    7.)Back\n\n";
	cin>>answer;

	while((answer!='1')&&(answer!='2')&&(answer!='3')&&(answer!='4')&&(answer!='5')&&(answer!='6')&&(answer!='7')){
		refreshScreen(Ally,Enemy);
		for (map<string,int>::iterator itemName=items.begin(); itemName!=items.end(); ++itemName){
			cout << "    " <<  itemName->first << " " << itemName->second << " Left" << endl;
			i++;
		}
		cout<<"    7.)Back\n\n Not a Valid Choice!\n\n";
		cin>>answer;
	}	
	//Using a Health Potion
	if(answer=='1'){
		if((answer=='1')&&(items["1.)Health Potion"]<1)){
			refreshScreen(Ally,Enemy);
			cout<<"You don't have any Health Potions!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else if((answer=='1')&&(Ally.health==200)){
			refreshScreen(Ally,Enemy);
			cout<<"Your Health is Already Full!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else{
			items["1.)Health Potion"]-=1;
			itemCount.pop();
			for(int i = Ally.health;i<=200;i+=20){
				Ally.health+=20;
				if(Ally.health>200){
					Ally.health=200;
				}
				refreshScreen(Ally,Enemy);
				Sleep(125);
			}cout<<"Your Health Has Been Restored!\n\n";
			Sleep(3000);
			return true;
		}
	}
	//Using a Mana Potion
	if(answer=='2'){
		if((answer=='2')&&(items["2.)Mana Potion  "]<1)){
			refreshScreen(Ally,Enemy);
			cout<<"You don't have any Mana Potions!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else if((answer=='2')&&(Ally.mana==100)){
			refreshScreen(Ally,Enemy);
			cout<<"Your Mana is Already Full!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else{
			items["2.)Mana Potion  "]-=1;
			itemCount.pop();
			for(int i = Ally.mana;i<=100;i+=10){
				Ally.mana+=10;
				if(Ally.mana>100){
					Ally.mana=100;
				}
				refreshScreen(Ally,Enemy);
				Sleep(125);
			}cout<<"Your Mana Has Been Restored!\n\n";
			Sleep(3000);
			return true;
		}
	}
	if(answer=='3'){
		if((answer=='3')&&(items["3.)Regeneration "]<1)){
		refreshScreen(Ally,Enemy);
		cout<<"You don't have any Health Potions!\n\n";
		Sleep(3000);
		itemBag(Ally,Enemy);
	}else if((answer=='3')&&(Ally.health==100)&&(Ally.mana==100)){
		refreshScreen(Ally,Enemy);
		cout<<"Your Health/Mana Are Already Full!\n\n";
		Sleep(3000);
		itemBag(Ally,Enemy);
	}else{
		items["3.)Regeneration"]-=1;
		itemCount.pop();
		for(int i = Ally.health;i<=200;i+=20){
			Ally.health+=20;
			if(Ally.health>200){
				Ally.health=200;
			}
			refreshScreen(Ally,Enemy);
			Sleep(125);
		}
		for(int i = Ally.mana;i<=100;i+=10){
			Ally.mana+=10;
			if(Ally.mana>100){
				Ally.mana=100;
			}
			refreshScreen(Ally,Enemy);
			Sleep(125);
		}cout<<"Your Health/Mana Have Been Restored!\n\n";
		Sleep(3000);
		return true;
		}
	}
	//Using a Double Damage
	if(answer=='4'){
		if((answer=='4')&&(items["4.)Double Damage"]<1)){
			refreshScreen(Ally,Enemy);
			cout<<"You don't have any Double Damages!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else if(doubleDamage.size()>0){
			refreshScreen(Ally,Enemy);
			cout<<"Double Damage is already Activated!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else{
			items["4.)Double Damage"]-=1;
			itemCount.pop();
			doubleDamage.push(1);
			doubleDamage.push(1);
			doubleDamage.push(1);
			doubleDamage.push(1);
			refreshScreen(Ally,Enemy);
			cout<<"Double Damage Has Been Activated for your next 3 Attacks!\n\n";
			Sleep(3000);
			return true;
		}
	}
	//Using a Invisibility
	if(answer=='5'){
		if((answer=='5')&&(items["5.)Invisibility "]<1)){
			refreshScreen(Ally,Enemy);
			cout<<"You don't have any Invisibilities!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else if(invisibility.size()>0){
			refreshScreen(Ally,Enemy);
			cout<<"Invisibility is already Activated!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else{
			items["5.)Invisibility "]-=1;
			itemCount.pop();
			invisibility.push(1);
			invisibility.push(1);
			invisibility.push(1);
			invisibility.push(1);
			refreshScreen(Ally,Enemy);
			cout<<"Invisibility Has Been Activated for the Enemy's next 3 Attacks!\n\n";
			Sleep(3000);
			return true;
		}
	}
	if(answer=='6'){
		if((answer=='6')&&(items["6.)Haste        "]<1)){
			refreshScreen(Ally,Enemy);
			cout<<"You don't have any Haste!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else if(haste.size()>0){
			refreshScreen(Ally,Enemy);
			cout<<"Haste is already Activated!\n\n";
			Sleep(3000);
			itemBag(Ally,Enemy);
		}else{
			items["6.)Haste        "]-=1;
			itemCount.pop();
			haste.push(1);
			haste.push(1);
			haste.push(1);
			haste.push(1);
			refreshScreen(Ally,Enemy);
			cout<<"Haste Has Been Activated for your next 3 Attacks!\n\n";
			Sleep(3000);
			return true;
		}
	}
	//Quit Item Bag
	if(answer=='7'){
		fightingPhase(Ally,Enemy);
	}
}
/*================================== Get Answer ===========================================
	Purpose: This function asks and validates what the user what they want to do. 
=========================================================================================*/
void getAnswer(Hero&Ally,Hero&Enemy,char&answer){
	cout<<"What do you wish to do?\n\n";
	if(Ally.name!="Aragorn the Swordsman"){
		if(Ally.name=="Gandalf the Wizard"){
			cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<" (-"<<Ally.att2M<<"% Mana)"<<endl
				<<setw(7)<<"3.)"<<Ally.att3N<<" (-"<<Ally.att3M<<"% Mana)"<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
		}else{
			cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<" (-"<<Ally.att2M<<"% Mana)"<<endl
				<<setw(7)<<"3.)"<<Ally.att3N<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
		}
	}else{
		cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<endl
			<<setw(7)<<"3.)"<<Ally.att3N<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
	}
	cin>>answer;

	//If mana is lower than desired move mana cost
	while(((answer=='2')&&(Ally.mana<Ally.att2M))||((Ally.name=="Gandalf the Wizard")&&(answer=='3')&&(Ally.mana<Ally.att3M))){
		refreshScreen(Ally,Enemy);
			cout<<"What do you wish to do?\n\n";
			if(Ally.name!="Aragorn the Swordsman"){
				if(Ally.name=="Gandalf the Wizard"){
					cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<" (-"<<Ally.att2M<<"% Mana)"<<endl
						<<setw(7)<<"3.)"<<Ally.att3N<<" (-"<<Ally.att3M<<"% Mana)"<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
				}else{
					cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<" (-"<<Ally.att2M<<"% Mana)"<<endl
						<<setw(7)<<"3.)"<<Ally.att3N<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
				}
			}else{
				cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<endl
					<<setw(7)<<"3.)"<<Ally.att3N<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
			}
			cout<<"You do not have enough Mana..\n\n";
			cin>>answer;
		if((Ally.name=="Gandalf the Wizard")&&(answer=='3')&&(Ally.mana<Ally.att3M)){
		refreshScreen(Ally,Enemy);
		cout<<"What do you wish to do?\n\n";
		cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<" (-"<<Ally.att2M<<"% Mana)"<<endl
		<<setw(7)<<"3.)"<<Ally.att3N<<" (-"<<Ally.att3M<<"% Mana)"<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
		cout<<"You do not have enough Mana..\n\n";
		cin>>answer;
		}
	}
	//If incorrect move is input
	while((answer!='1')&&(answer!='2')&&(answer!='3')&&(toupper(answer!='4'))){
		refreshScreen(Ally,Enemy);
		cout<<"What do you wish to do?\n\n";
		if(Ally.name!="Aragorn the Swordsman"){
			if(Ally.name=="Gandalf the Wizard"){
				cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<" (-"<<Ally.att2M<<"% Mana)"<<endl
					<<setw(7)<<"3.)"<<Ally.att3N<<" (-"<<Ally.att3M<<"% Mana)"<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
			}else{
				cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<endl
					<<setw(7)<<"3.)"<<Ally.att3N<<endl<<"    4.)Item Bag ("<<Ally.items<<" Items)\n\n";
			}
		}else{
			cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<endl
				<<setw(7)<<"3.)"<<Ally.att3N<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
		}
		cout<<"Invalid choice..\n\n";
		cin>>answer;
	}
	//If you choose item bag and you dont have any items
	while((answer=='4')&&(itemCount.empty())){
		refreshScreen(Ally,Enemy);
		cout<<"What do you wish to do?\n\n";
		if(Ally.name!="Aragorn the Swordsman"){
			cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<" (-"<<Ally.att2M<<" Mana)"<<endl
				<<setw(7)<<"3.)"<<Ally.att3N;if(Ally.name=="Gandalf the Wizard"){cout<<" (-"<<Ally.att3M<<" Mana)";}
			cout<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
		}else{
			cout<<setw(7)<<"1.)"<<Ally.att1N<<endl<<setw(7)<<"2.)"<<Ally.att2N<<endl
				<<setw(7)<<"3.)"<<Ally.att3N<<endl<<"    4.)Item Bag ("<<itemCount.size()<<" Items)\n\n";
		}
		cout<<"You do not have any items!\n\n";
		cin>>answer;
	}
}
/*================================ This function =========================================
	Purpose: This fucntion initiates specific attacks based on what the user wanted. 
			 After completing this function, if double damage and haste duration is decrease
			 by 1 if they are active.
=========================================================================================*/
void attack(Hero&Ally,Hero&Enemy,char answer){
	
	//Sets 25% chance of missing
	int youHit = rand()%4;
	//Sets 25% of being too slow for Aragorn
	int slowHit = rand()%4;
	//Sets random number to be used for Legolas Multiple hits
	int count = rand()%100+1;

	refreshScreen(Ally,Enemy);
	//Display what move you chose
	switch(answer){
		case '1':cout<<"You chose to attack with "<<Ally.att1N;break;
		case '2':cout<<"You chose to attack with "<<Ally.att2N;break;
		case '3':cout<<"You chose to attack with "<<Ally.att3N;break;
	}
	dots();
	system("CLS");

	if(answer!='4'){
		if(youHit<3){
				if((Ally.name=="Aragorn the Swordsman")&&(slowHit>2)){
					refreshScreen(Ally,Enemy);
					cout<<"Your Attack Was Too Slow!";
					Sleep(3000);
				}else{
				switch(toupper(answer)){
					case '1': 
						Enemy.health -= Ally.att1;
						refreshScreen(Ally,Enemy);
						cout<<"Your Attack Hit! Damage Dealt: "<<Ally.att1;
						break;
					case '2': 
						if(Ally.name=="Legolas the Archer"){
							Ally.mana -= Ally.att2M;
							int tDmg = 0;
							stack<int> times;
							stack<int> totalDmg;				
							if(count>0){
								times.push(1);
								totalDmg.push(Ally.att2);
								tDmg += totalDmg.top();
								Enemy.health -= Ally.att2;
								refreshScreen(Ally,Enemy);
								cout<<"Your Attack Hit "<<times.size()<<" Times! Damage Dealt: "<<Ally.att2<<" Total Damage: "<<tDmg;
								Sleep(1500);
							}if(30<count<=60){
								assignDamage(Ally,Enemy);
								times.push(1);
								totalDmg.push(Ally.att2);
								tDmg += totalDmg.top();
								Enemy.health -= Ally.att2;
								refreshScreen(Ally,Enemy);
								cout<<"Your Attack Hit "<<times.size()<<" Times! Damage Dealt: "<<Ally.att2<<" Total Damage: "<<tDmg;
								Sleep(1500);
							}if(60<count<=80){
								assignDamage(Ally,Enemy);
								times.push(1);
								totalDmg.push(Ally.att2);
								tDmg += totalDmg.top();
								Enemy.health -= Ally.att2;
								refreshScreen(Ally,Enemy);
								cout<<"Your Attack Hit "<<times.size()<<" Times! Damage Dealt: "<<Ally.att2<<" Total Damage: "<<tDmg;
								Sleep(1500);
							}if(80<count<=90){
								assignDamage(Ally,Enemy);
								times.push(1);
								totalDmg.push(Ally.att2);
								tDmg += totalDmg.top();
								Enemy.health -= Ally.att2;
								refreshScreen(Ally,Enemy);
								cout<<"Your Attack Hit "<<times.size()<<" Times! Damage Dealt: "<<Ally.att2<<" Total Damage: "<<tDmg;
								Sleep(1500);
							}if(count>90){
								assignDamage(Ally,Enemy);
								times.push(1);
								totalDmg.push(Ally.att2);
								tDmg += totalDmg.top();
								Enemy.health -= Ally.att2;
								refreshScreen(Ally,Enemy);
								cout<<"Your Attack Hit "<<times.size()<<" Times! Damage Dealt: "<<Ally.att2<<" Total Damage: "<<tDmg;
								Sleep(1500);
							}
						}else{
							Enemy.health -= Ally.att2;Ally.mana-=Ally.att2M;
							refreshScreen(Ally,Enemy);
							cout<<"Your Attack Hit! Damage Dealt: "<<Ally.att2;
						}
						break;
					case '3': 
							Enemy.health -= Ally.att3;
							if(Ally.name=="Gandalf the Wizard"){
								Ally.mana-=Ally.att3M;
							}
							refreshScreen(Ally,Enemy);
							cout<<"Your Attack Hit! Damage Dealt: "<<Ally.att3;
							break;
						}
						if((Ally.name=="Legolas the Archer")&&(answer=='2')){
							Sleep(1500);
						}else{
							Sleep(3000);
						}
					}
				}else{
				switch(toupper(answer)){
						case '2': 
							Ally.mana-=Ally.att2M;
							break;
						case '3': 
							if(Ally.name=="Gandalf the Wizard"){
							Ally.mana-=Ally.att3M;
						}
				}
			refreshScreen(Ally,Enemy);
			if((Ally.name=="Aragorn the Swordsman")&&(slowHit>2)){
				refreshScreen(Ally,Enemy);
				cout<<"Your Attack Was Too Slow!";
				Sleep(3000);
			}else{
				cout<<"Your Attack Missed!";
			Sleep(3000);
			}
		}
	}
	//If active, Reduces double damage duration by 1
	if(doubleDamage.size()>1){doubleDamage.pop();}
	//Notifies users that DD wore off
	if(doubleDamage.size()==1){
		refreshScreen(Ally,Enemy);
		cout<<"Double Damage has worn off!";
		Sleep(3000);
		doubleDamage.pop();
	}


	//If active, Reduces haste duration by 1
	if(haste.size()>1){haste.pop();}

	//Re-attacks if haste is active
	while(haste.size()>1){
		if(Ally.mana==0){
			answer = '1';
		}
		attack(Ally,Enemy,answer);
	}
	//Notifies users that haste wore off
	if(haste.size()==1){
		refreshScreen(Ally,Enemy);
		cout<<"Haste has worn off!";
		Sleep(3000);
		haste.pop();
	}
}
