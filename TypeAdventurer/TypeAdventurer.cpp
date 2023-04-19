#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<random>
#include<ctime>
#include<conio.h>
using namespace std;
int hpBoss=70,dmgBoss=8;
int hp2=50,dmg2,hp=50,ult=1,chest,lvl=1,dmg=2;
int hp1=50,dmg1=5,dmgPl=5,heal=10,playerhp=50,luck,ultdmg=25,ultdmg1=25,manaPl,manaCost=5,manaFull=24;
char *name;
clock_t start;
clock_t elapsed;
clock_t period;

#include"mechanics.hpp"

#include"victory.hpp"                                                                //foloseste programul victory.hpp


int StartCd(){
start=clock();                                                                      //starts ultimate cooldown
}


int cooldown(int seconds)                                                           //calculate ultimate cooldown
{   
    period = seconds * CLOCKS_PER_SEC;
    elapsed = clock() - start;
    if(elapsed>=period)return 1;
    else return 0;
}


#include"battle.hpp"                                                                //foloseste programul battle.hpp


int main(){
srand((unsigned)time(NULL));    
mt19937 gen(rand()); 
name=new char[20];
cout<<"Please enter your name:";cin.getline(name,20,'\n');
cout<<'\n';

while(hp1>0){
    
    while(!Game()){
        Game();
    }

    manaPl=manaFull;

    if(gg==1){
    cout<<name<<"'s stats:"<<dmgPl+20<<" max damage, "<<playerhp<<" health, "<<heal+14<<" max healing power\n";
    cout<<"Computer stats:"<<dmg+16<<" max damage, "<<hp<<" health \n";
    cout<<"Welcome to level "<<lvl<<"! ";
    }

    if(gg==2){
    cout<<name<<"'s stats:"<<dmgPl+20<<" max damage, "<<playerhp<<" health, "<<heal+14<<" max healing power\n";
    cout<<"Enemy's stats: max damage(unknown), "<<hpBoss<<" health \n";
    }

    cout<<"Press any key to continue.. \n";
    getch();
    cout<<'\n';

    if(ult==0){
        ult=cooldown(55);
        ultdmg1=ultdmg;
    }
    bool n=false;
    battle(n);

    if(hp2<=0){
        switch(gg){
            case 1:
                cout<<"You passed level "<<lvl<<'!'<<'\n';
                break;
            case 2:
                printf("You defeated the Guardian of the temple, claim your prize...\n");
                break;
        }
        Victory();
        lvl++;
        manaFull=manaFull+3;
        if(lvl%2==1)ultdmg=ultdmg+9;
    }

}

delete name;
if(hp1<=0)cout<<"Computer victory! ;p\n";
system("Pause");
return 0;
}