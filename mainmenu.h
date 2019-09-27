#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <dos.h>
#include<graphics.h>

#define pixTOrc(x) (8*(x-1))
#define INC 7
#define ROW 40
#define COL 70
#define MAXITEM 4

typedef char option[15];

//Menu Global Item#define pixTOrc(x) (8*(x-1))  //convert pixel into row and col format#define INC 5  //Increment Distance Between Menu Items#define ROW 15 //Row Value for Menu Item#define COL 8 //Column Value for Menu Item#define MAXITEM 4 //Total menu items// To display the Inventory Main menu options
option mainMenu[]= {
  "START",
  "PROFILES",
 "HELP",
 "CLOSE"
};



// Function to displays all the menu prompt messages from the pointer array of option a[]void normalvideo(int x,int y,char *str)
void normalvideo(int x,int y,char *str)
{
    x=pixTOrc(x);
    y=pixTOrc(y);
    outtextxy(x,y,str);
}

// Function to move the cursor on the menu prompt with a reverse video color
void reversevideo(int x,int y,char *str)
{
    x=pixTOrc(x);
    y=pixTOrc(y);
    setcolor(LIGHTRED);  //Selected Item
    delay(100);
    outtextxy(x,y,str);
    setcolor(WHITE); //Unselected Item
    //sound(500);
    delay(100);
}

char menu()
{
    int i,done;
    settextstyle(3,HORIZ_DIR,5);
    setcolor(WHITE);  //Initial Menu Item Color
    for(i = 1; i < MAXITEM; i++)
      normalvideo(COL, (i*INC)+ROW, mainMenu[i]);

    reversevideo(COL,ROW, mainMenu[0]);
    i = done = 0;
    do
    {

        int key = getch();
        switch (key)
        {

            case 00:
                key = getch();
                switch (key)
                {
                    case 72:
                        normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
                        i--;
                        if (i == -1)
                            i = MAXITEM-1;
                        reversevideo(COL,(i*INC)+ROW,mainMenu[i]);
                        break;
                    case 80:
                        normalvideo(COL, (i*INC)+ROW, mainMenu[i]);
                        i++;
                        if (i == MAXITEM)
                            i = 0;
                        reversevideo(COL, (i*INC)+ROW, mainMenu[i]);
                        break;
                }
                break;
            case 13:
                done = 1;
        }
    }
    while (!done);
    return(i+49);
}

//void advertise(){
  //  setcolor(BLUE);
   // outtextxy(pixTOrc(30),pixTOrc(20),"Syntax-Example.com");
   // setcolor(LIGHTRED);
//}

/* The function is used to display the main menu*///Actual code for all the menu utility resides in this//Function...void control_menu()
int control_menu()
{
    setfillstyle(SOLID_FILL,WHITE);
    bar(0,0,1366,768);
    settextstyle(3,HORIZ_DIR,10);
    outtextxy((1366/2)-250, 120, "SNAKES");
     char choice;
    do
    {
        choice = menu();
        switch (choice)
        {
           case'1':    //Start
               return 1;
               // setcolor(BLUE);
                //outtextxy(pixTOrc(40),pixTOrc(75),"New");
                //advertise();
                getch();
                //setfillstyle(SOLID_FILL,LIGHTGRAY);
                //bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
                //advertise();
                //break;

           case'2':    //Help
               return 2;
                //setcolor(BLUE);
                //outtextxy(pixTOrc(40),pixTOrc(15),"Open");
                //advertise();
                //getch();
                //setfillstyle(SOLID_FILL,LIGHTGRAY);
                //bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
               // advertise();
               // break;

           case'3':    //Profiles
               return 3;
                //setcolor(BLUE);
                //outtextxy(pixTOrc(40),pixTOrc(15),"Save");
                //advertise();
                //getch();
                //setfillstyle(SOLID_FILL,LIGHTGRAY);
                //bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
                //advertise();
                //break;

           case'4':    //Modify the status of item in inventory
               /* setcolor(BLUE);
                outtextxy(pixTOrc(40),pixTOrc(15),"About Me");
                //advertise();
                getch();
                setfillstyle(SOLID_FILL,WHITE);
                bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
                advertise(); */
                //break;

           case'5':    //Close
               return 5;
               // setcolor(BLUE);
              //  outtextxy(pixTOrc(40),pixTOrc(15),"CLOSE");
               // advertise();
               // delay(1000);
               // setfillstyle(SOLID_FILL,LIGHTGRAY);
                //bar(pixTOrc(28),pixTOrc(14),pixTOrc(75),pixTOrc(50));
                //advertise();
                //goto out;
                //break;
       }
      } while (choice != MAXITEM);
       // out:
}

