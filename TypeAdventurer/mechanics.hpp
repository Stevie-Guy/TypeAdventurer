const int latime=25, inaltime=8;
int playerX,playerY,enemyX,enemyY,gg,boss[2];
int eventX,eventY,fortune;
enum Directie{STOP=0,UP,DOWN,LEFT,RIGHT};
Directie dir;


void Setup(){
    dir=STOP;
    fortune=0;
    playerX=rand()%latime;
    playerY=rand()%inaltime;
    do{
    enemyX=rand()%latime;
    enemyY=rand()%inaltime;
    }while(enemyX!=playerX && enemyY!=playerY);

    if(lvl%4==0){

        do{
            boss[0]=rand()%latime;
            boss[1]=rand()%inaltime;
        }while((boss[0]!=playerX && boss[0]!=enemyX) && (boss[1]!=playerY && boss[1]!=enemyY));

    }

    if(lvl%2==0){

        do{
            eventX=rand()%latime;
            eventY=rand()%inaltime;
        }while((eventX!=playerX && eventY!=playerY) && (eventX!=enemyX && eventY!=enemyY) && (eventX!=boss[0] && eventY!=boss[1]));

    }

    gg=0;
}


void Map(){
    system("cls");

    for(int i=0;i<=latime+1;i++)                    //tavan
        printf("-");
    
    printf("\n");

    for(int i=0;i<=inaltime;i++){

        for(int j=0;j<latime;j++){

            switch(j){
                case 0:
                    printf("|");                    //perete stanga
                    break;
                default:
                    break;
            }

            if(i==playerY && j==playerX)                         //arata player

                printf("%c",1);

            else if(i==enemyY && j==enemyX)

                printf("!");

            else if(i==boss[1] && j==boss[0] && lvl%4==0)

                printf("?");

            else if(i==eventY && j==eventX && lvl%2==0)

                cout<<'%';

            else 

                printf(" ");
                    
            switch(j){
                case latime-1:
                    printf("|");                    //perete dreapta
                    break;
                default:
                    break;
            }

        }

        printf("\n");

    }

    for(int i=0;i<=latime+1;i++)
        printf("-");                                      //podea


}


void Move(){

    switch (getch()){
        case 'w':
        case 'W':
            dir=UP;
            break;

        case 's':
        case 'S':                  
            dir=DOWN;
            break;

        case 'a':
        case 'A':
             dir=LEFT;
            break;

        case 'd':
        case 'D':
            dir=RIGHT;
            break;
        default:
            break;
        }

}


void Mecanici(){

    switch (dir){
        case UP:
            if(playerY>0)
                playerY--;
            break;

        case DOWN:
            if(playerY<inaltime)
                playerY++;
            break;

        case LEFT:
            if(playerX>0)
                playerX--;
            break;

        case RIGHT:
            if(playerX<latime-1)
                playerX++;
            break;
        
        default:
            break;
    }

    if(playerX==eventX && playerY==eventY){
        eventX=-1;
        eventY=-1;
        fortune=1+rand()%5;
    }      

    if(playerX==enemyX && playerY==enemyY)
        gg= 1;
    else if(playerX==boss[0] && playerY==boss[1] && lvl%4==0)
        gg= 2;
}


int Game(){
    srand((unsigned) time(NULL));
    rand();
    Setup();
    while(!gg){
    Map();
    Move();
    Mecanici();
    }
    system("cls");

    if(fortune!=0)
        printf("The  wheel of fortune was spinned! ;p\n");

    if(gg==1)
        printf("\nYou encountered and unexpected enemy! \n");
    
    if(gg==2)
        printf("\nYou entered in a mysterious temple and found a powerful enemy. \n");

    return 1;
}