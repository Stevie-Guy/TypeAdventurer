int battle(bool in_fight){
int a,b, *dmgMax;
dmgMax=new int;

if(gg==1){
    if(in_fight==false)hp2=hp;
    dmg2=dmg;
    *dmgMax=17;
}

if(gg==2){
    if(in_fight==false)hp2=hpBoss;
    dmg2=dmgBoss;
    *dmgMax=16;
}

if(in_fight==false)
    switch (fortune){
        case 1:
            cout<<"Fortune: You deal reduced damage this round\n\n";
            dmg1=dmg1-5;
            break;

        case 2:
            cout<<"Fortune:You have 50% more hp this round\n\n";
            hp1=hp1+hp1/2;
            break;

        case 3:
            cout<<"Fortune:You start with half your hp this round\n\n";
            hp1=hp1/2;
            break;
                
        case 4:
            cout<<"Fortune:The enemy deals 50% less damage this round\n\n";
            dmg2=dmg2/2;
            *dmgMax/=2;
            break;

        case 5:
            printf("Fortune:Your ultimate was restored\n\n");
            ult=1;
            break;

        default:
            break;
    }

in_fight=true;
mt19937 gen(rand()); 
while(hp1>0 && hp2>0){

    cout<<name<<"'s turn \n";
    cout<<"1 Attack \n";
    if(manaPl>=manaCost)printf("2 Heal (%d mana) \n",manaPl);
    if(ult==1)cout<< "3 Ultimate("<<ultdmg1<<" damage)\n";
    cin>>b;
    cout<<endl;

    if(b==2 && hp1>=playerhp){
        cout<<"Your health is already full! Attack casted instead. \n\n";
        b=1;
    }

    if(ult==0 && b==3){
        cout<<"Your Ultimate is not ready! \n\n";
        battle(in_fight);
    }

    if(manaPl<manaCost && b==2){
        cout<<"You are out of mana, cannot use heal \n\n";
        battle(in_fight);
    }

    if(b==1){
        uniform_int_distribution<> distrib(dmg1, dmg1+20);                          //player attack
        a=distrib(gen);
        cout<<name<<" attacks for "<<a<<"hp ";
        if(a>dmg1+15)cout<<" Critical hit";
        cout<<endl;
        hp2=hp2-a;

        if(gg==1) printf("Computer has %i hp left\n\n",hp2);

        if(gg==2) printf("Enemy has %i hp left\n\n",hp2);
    }

    if(manaPl>=manaCost && b==2){
        uniform_int_distribution<> distrib(heal, heal+14);                           //player heal
        a=distrib(gen);
        cout<<name<<" heals for "<<a<<"hp \n";
        hp1=hp1+a;
        manaPl=manaPl-manaCost;
        if(hp1>playerhp)hp1=playerhp;
        cout<<name<<" has "<<hp1<<"hp \n\n";
    }

    if(ult==1 && b==3){                                                                 //player use Ultimate
        ult=0;
        StartCd();
        cout<<name<<" used Ultimate, "<<ultdmg1<<" damage \n";
        hp2=hp2-ultdmg1;
        if(gg==1) printf("Computer has %i hp left\n\n",hp2);
        if(gg==2) printf("Enemy has %i hp left\n\n",hp2);
    }

    if(hp2<=0)break;

    switch (gg){
        
    case 1:
        printf("Computer's turn \n");                                                               //computer attacks
        a=dmg2+rand()%*dmgMax;
        cout<<"Computer attacks for "<<a<<"hp ";
        if(a>dmg2+11)cout<<" Critical hit";
        printf("\n");
        hp1=hp1-a;
        printf("%s has %ihp left\n\n",name,hp1);
        break;
    
    case 2:
        printf("The enemy doesn't flinch, he is scary \n");                                          //temple enemy attacks
        a=dmg2+rand()%*dmgMax;
        printf("The enemy attacks you recklessly, -%ihp\n",a);
        hp1=hp1-a;
        printf("%s has %ihp left\n\n",name,hp1);
        break;
    }


    if(manaPl<manaFull && b!=2){
        manaPl=manaPl+6;
    }
    if(manaPl>manaFull){
        manaPl=manaFull;
    }

    if(ult==0){                                                                       //check for ult
        ult=cooldown(55);
        ultdmg1=ultdmg;
    }

}
in_fight=false;
delete dmgMax;
}