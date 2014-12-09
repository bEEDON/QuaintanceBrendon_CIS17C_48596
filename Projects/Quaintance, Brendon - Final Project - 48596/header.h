//header.h
#ifndef HEADER_H
#define HEADER_H

# include <iostream>
# include <cstdlib>
using namespace std;


//========================================== HERO CLASS ================================================
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
//=======================================================================================================

//Node Declaration
struct node
{
    int info;
    struct node *left;
    struct node *right;
}*root;
 
//Tree Class Declaration
class Tree
{
    public: 
        void insert(node *,node *);
        void preorder(node *);
        void inorder(node *);
        void postorder(node *);
        void display(node *, int);
        Tree()
        {
            root = NULL;
        }
};

//Inserting Element into the Tree
void Tree::insert(node *tree, node *newnode)
{
    if (root == NULL)
    {
        root = new node;
        root->info = newnode->info;
        root->left = NULL;
        root->right = NULL;
        //cout<<"Root Node is Added"<<endl;
        return;
    }
    if (tree->info == newnode->info)
    {
        //cout<<"Element already in the tree"<<endl;
        return;
    }
    if (tree->info > newnode->info)
    {
        if (tree->left != NULL)
        {
            insert(tree->left, newnode);	
	}
	else
	{
            tree->left = newnode;
            (tree->left)->left = NULL;
            (tree->left)->right = NULL;
            //cout<<"Node Added To Left"<<endl;
            return;
        }
    }
    else
    {
        if (tree->right != NULL)
        {
            insert(tree->right, newnode);
        }
        else
        {
            tree->right = newnode;
            (tree->right)->left = NULL;
            (tree->right)->right = NULL;
           // cout<<"Node Added To Right"<<endl;
            return;
        }	
    }
}

//Pre Order Traversal
void Tree::preorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        cout<<ptr->info<<"  ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

//In Order Traversal
void Tree::inorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        inorder(ptr->left);
        cout<<ptr->info<<"  ";
        inorder(ptr->right);
    }
} 

//Postorder Traversal
void Tree::postorder(node *ptr)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if (ptr != NULL)
    {
        postorder(ptr->left);
        postorder(ptr->right);
        cout<<ptr->info<<"  ";
    }
}
 
//Display Tree Structure
void Tree::display(node *ptr, int level)
{
    int i;
    if (ptr != NULL)
    {
        display(ptr->right, level+1);
        cout<<endl;
        if (ptr == root)
            cout<<"Root->:  ";
        else
        {
            for (i = 0;i < level;i++)
                cout<<"       ";
	}
        cout<<ptr->info;
        display(ptr->left, level+1);
    }
}

//=============================== HASH TABLE ============================================
//data structure to hold id and data, our data-structure we want to use
struct data1 {
public:
        int id; //to hold a unique id for each element
        int data; //the data for each element, I used a simple int
};
 
class hasher {
        data1 dt[51]; //the table to hold hashed data structs
        int numel; //number of elements in table, to check if it's full
public:
        hasher();
		void clear();
        int hash(int &id);
        int rehash(int &id);
        int add(data1 &d);
        void output(char answer);
};


int hasher::hash(int &id) {
        return (id%51);

}

int hasher::rehash(int &id) {
        return ((id+1)%51);

}
 

hasher::hasher() {
        //create an array of data structure
        int i;

        for(i=0;i<=50;i++) {
                dt[i].id = -1; //set all ids to -1 to show they're empty
                dt[i].data = 0; //set all data values to 0, which is default
        }
        numel = 0;
}

void hasher::clear(){
        //create an array of data structure
        int i;

        for(i=0;i<=50;i++) {
                dt[i].id = -1; //set all ids to -1 to show they're empty
                dt[i].data = 0; //set all data values to 0, which is default
        }
        numel = 0;

}

 
int hasher::add(data1 &d) {
        if(numel < 51) {
                //table has empty places...
                int hashed = hash(d.id);
                if(hashed >= 0 && hashed <= 50 && dt[hashed].id == -1) {
                        //slot is empty, assign new data
                        dt[hashed].id = d.id;
                        dt[hashed].data = d.data;
                        return 0;
                } else {
                       //need to rehash the id
            int i=0;

            //try every place in table to find an empty place
            while(i<=50) {
                            hashed = rehash(hashed);
                            if(dt[hashed].id == -1) {
                                    dt[hashed].id = d.id;
                                    dt[hashed].data = d.data;
                                    return 0;
                            } else if(i==50) {
                                    //couldn't find the empty place
                                    return -1; //terminate function with error
                            }
                i++; //update value of i
					}
             }

        } else {
                //table is full
                return (-1);
        }
}

void hasher::output(char answer) {
	/*Weak Hits  (0-49 Damage)
	Average Hits (50-99 Damage)
	Good Hits   (100-149 Damage)
	Strong Hits (150-199 Damage)
	Beast Hits   (200+ Damage)*/

	//DISPLAYS SPECIFIC RANGES IN HASH TABLE
	if(answer=='1'){
				cout<<"\nWeak Hits (0-49 Damage):\n";
				for(int i=0;i<10;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}
			}else if(answer=='2'){
				cout<<"\nAverage Hits (50-99 Damage):\n";
				for(int i=10;i<20;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}				
			}else if(answer=='3'){
				cout<<"\nGood Hits (100-149 Damage):\n";
				for(int i=20;i<30;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}				
			}else if(answer=='4'){
				cout<<"\nStrong Hits (150-199 Damage):\n";
				for(int i=30;i<40;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}
			}else if(answer=='5'){
				cout<<"\nBeast Hits (200+ Damage):\n";
				for(int i=40;i<50;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}
				
			}else if(answer=='6'){
				//DISPLAYS ENTIRE HASH TABLE
				cout<<"\nAll Hits:\n";
				cout<<"\nWeak Hits (0-49 Damage):\n";
				for(int i=0;i<10;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}
				cout<<"\nAverage Hits (50-99 Damage):\n";
				for(int i=10;i<20;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}
				cout<<"\nGood Hits (100-149 Damage):\n";
				for(int i=20;i<30;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}
				cout<<"\nStrong Hits (150-199 Damage):\n";
				for(int i=30;i<40;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}
				cout<<"\nBeast Hits (200+ Damage):\n";
				for(int i=40;i<50;i++) {
					if(dt[i].id != -1){
							cout<<"     "<<dt[i].data<<endl;
					}
				}
			}
			cout<<"\n\nPress any key to go back . . .";
			cout<<"\n\n________________________________________________________________________________\n\n";
			cin>>answer;
}
#endif

