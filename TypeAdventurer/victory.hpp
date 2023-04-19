int Victory(){
dmg=dmg+2;                                                                         //computer power-up
hp=hp+4;

if(lvl%4==0){
    dmgBoss+=10;
    hpBoss+=20;
}

mt19937 gen(rand()); 

cout<<'\n';

if(gg==1){
    uniform_int_distribution<> distrib(1,5); 
    chest=distrib(gen);

       if(chest==1 || chest==2){                                                                            //player found armor => more health
            uniform_int_distribution<> distrib(1,10);
            luck=distrib(gen);

            if(lvl%10==0)luck=6;

            if(luck>=3 && luck<=5){
                playerhp=playerhp+3;
                cout<<"You found a Common Armor! Max hp increased to "<<playerhp<<endl;
            }
            if(luck>=7 && luck<=10){
                playerhp=playerhp+5;
                cout<<"You found a Rare Armor! Max hp increased to "<<playerhp<<endl;
            }
            if(luck>=1 && luck<=2){
                playerhp=playerhp+7;
                cout<<"You found an Epic Armor! Max hp increased to "<<playerhp<<endl;
            }
            if(luck==6){
                playerhp=playerhp+10;
                cout<<"You found a Legendary Armor! Max hp increased to "<<playerhp<<endl;
            }
        }

        if(chest==3 || chest==4){                                                                             //player found a sword => more damage
            uniform_int_distribution<> distrib(1,10);
            luck=distrib(gen);

            if(lvl%10==0)luck=10;

            if(luck>=1 && luck<=3){
                dmgPl=dmgPl+1;
                cout<<"You found a Common Sword! Max damage increased to "<<dmgPl+20<<endl;
            }
            if(luck>=6 && luck<=9){
                dmgPl=dmgPl+2;
                cout<<"You found a Rare Sword! Max damage increased to "<<dmgPl+20<<endl;
            }
            if(luck>=4 && luck<=5){
                dmgPl=dmgPl+3;
                cout<<"You found an Epic Sword! Max damage increased to "<<dmgPl+20<<endl;
            }
            if(luck==10){
                dmgPl=dmgPl+5;
                cout<<"You found a Legendary Sword! Max damage increased to "<<dmgPl+20<<endl;
            }
        }

        if(chest==5){                                                                               //player found a health potion => more healing
            uniform_int_distribution<> distrib(1,10);
            luck=distrib(gen);

            if(lvl%10==0)luck=8;

            if(luck>=5 && luck<=7){
                heal=heal+5;
                cout<<"You found a Common Potion! Heal ability improved!"<<endl;
            }
            if(luck>=1 && luck<=4){
                heal=heal+7;
                cout<<"You found a Rare Potion! Heal ability improved!"<<endl;
            }
            if(luck>=9 && luck<=10){
                heal=heal+9;
                cout<<"You found an Epic Potion! Heal ability improved!"<<endl;
            }
            if(luck==8){
                heal=heal+11;
                cout<<"You found a Legendary Potion! Heal ability improved!"<<endl;
            }

        }
}
if(gg==2){                                                                                                       //survived the temple
        uniform_int_distribution<>distrib(1,3); 
        chest=distrib(gen);
        switch(chest){
            case 1:
                playerhp=playerhp+15;
                cout<<"You found an Mythic Armor! Max hp increased to "<<playerhp<<'\n';
                break;
            case 2:
                dmgPl=dmgPl+8;
                cout<<"You found an Mythic Sword! Max damage increased to "<<dmgPl+20<<'\n';
                break;
            case 3:
                heal=heal+15;
                cout<<"You found an Mythic Potion! Heal ability improved!"<<'\n';
                break;
        }

}

printf("Continue your adventure...");
getch();
hp1=playerhp;
dmg1=dmgPl;
cout<<'\n';
}