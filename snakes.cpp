#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include<windows.h>
#include<iostream>
#include<string>
#include "mainmenu.h"


#define MAX_INPUT_LEN 80
#define Debug printf("HERE");

char inputbuf[MAX_INPUT_LEN];
char inputbuf2[MAX_INPUT_LEN];
int input_pos = 0;
int input_pos2 = 0;



using namespace std;

bool gameOver;
int width = 1180;
int height = 560;
int x, y, x1, y1, i, j, k, score, fruitx, fruity, dir, d, d2, dirP2;
int tailx[1000], taily[1000], tailx1[5], taily1[5];
int ntail;

void setup()
{
    srand(time(0));
    gameOver = false;
    dirP2 = 0;
    dir=0;
    d=0;
    d2=0;
    ntail=0;
    x = width/2;
    y = height/2;
    x1 = (width/2)+100;
    y1 = (height/2)+100;
    fruitx = (190+rand()%(width-190));
    fruity = (10+rand()%(height-10));
    score=0;
}

void draw()
{
    // Resetting the screen
    setfillstyle(1,15);
    bar(180,10,width-10,height-10);
    setfillstyle(1,0);
    bar(180,height-10,width+10,height+10); // Debugger reset bar
    setfillstyle(1,0);
    bar(0,0,10,10); // Debugger reset bar 2

    // Boundaries
    setfillstyle(1,8);
    bar(180,0,width,10); // top bar
    bar(180,0,190,height); // left bar
    bar(180,height,width,height-10); // bottom bar
    bar(width-10,10,width,height); // right bar

    // fruit
    if((fruitx>=x && fruitx<=x+10) && (fruity>=y && fruity<=y+10) || (fruitx+7>=x && fruitx+7<=x+10) && (fruity+7>=y && fruity+7<=y+10))
    {

        ntail++;
        setfillstyle(1,15);
        bar(fruitx, fruity, fruitx+7, fruity+7);

        do
        {
            fruitx = (190+rand()%(width-190));
            fruity = (10+rand()%(height-10));
        }
        while(getpixel(fruitx,fruity)!=15 && fruitx>190 && fruity>10);
        fruitx=fruitx/10;
        fruitx=fruitx*10;
        fruity=fruity/10;
        fruity=fruity*10;

    }
    else if((fruitx>=x1 && fruitx<=x1+10) && (fruity>=y1 && fruity<=y1+10) || (fruitx+7>=x1 && fruitx+7<=x1+10) && (fruity+7>=y1 && fruity+7<=y1+10))
    {
        score=score+1;
        setfillstyle(1,15);
        bar(fruitx, fruity, fruitx+7, fruity+7);

        do
        {
            fruitx = (190+rand()%(width-190));
            fruity = (10+rand()%(height-10));
        }
        while(getpixel(fruitx,fruity)!=15 && fruitx>190 && fruity>10);
        fruitx=fruitx/10;
        fruitx=fruitx*10;
        fruity=fruity/10;
        fruity=fruity*10;
    }
    setfillstyle(1,0);
    bar(fruitx, fruity, fruitx+7, fruity+7);

}

void input()
{
    // Movement
    if(GetAsyncKeyState(VK_RIGHT))
    {
        if(d==2)
        {
            d=2;

        }
        else
        {
            d=1;
        }

    }
    else if(GetAsyncKeyState(VK_LEFT))
    {
        if(d==1)
        {
            d=1;

        }
        else
        {
            d=2;
        }

    }
    else if(GetAsyncKeyState(VK_UP))
    {
        if(d==4)
        {
            d=4;

        }
        else
        {
            d=3;
        }

    }
    else if(GetAsyncKeyState(VK_DOWN))
    {
        if(d==3)
        {
            d=3;

        }
        else
        {
            d=4;
        }

    }

}

void logic()
{
    // Body coordinates
    int prevx = tailx[0];
    int prevy = taily[0];
    int prevtempx, prevtempy;
    tailx[0] = x;
    taily[0] = y;
    for(i=1; i<ntail; i++)
    {
        prevtempx = prevx;
        prevtempy = prevy;
        prevx = tailx[i];
        prevy = taily[i];
        tailx[i] = prevtempx;
        taily[i] = prevtempy;
    }

    // Directions
    switch(d)
    {
    case 0:
        if(dir==1)
        {
            x=x+10;
        }
        else if(dir==2)
        {
            x=x-10;
        }
        else if(dir==3)
        {
            y=y-10;
        }
        else if(dir==4)
        {
            y=y+10;
        }
        else
        {
            d=0;
        }
        break;
    case 1:
        if(dir==2)
        {
            break;
        }
        x=x+10;
        dir=1;
        break;
    case 2:
        if(dir==1)
        {
            break;
        }
        x= x-10;
        dir=2;
        break;
    case 3:
        if(dir==4)
        {
            break;
        }
        dir=3;
        y=y-10;
        break;
    case 4:
        if(dir==3)
        {
            break;
        }
        dir=4;
        y= y+10;
        break;
    }
    setfillstyle(1,8); // Head color
    bar(x,y,x+10,y+10); // Head

    // Body color and drawing
    for(k=0; k<ntail; k++)
    {
        setfillstyle(1,10);
        bar(tailx[k],taily[k], tailx[k]+10, taily[k]+10);
    }
    // delay(100);

    // boundary check
    if(x<190)
    {
        x=width-20;
    }
    else if(x>=width-10)
    {
        x=180;
    }
    if(y<10)
    {
        y=height-10;
    }
    else if(y>=height-10)
    {
        y=10;
    }

    // Game over condition
    for(i=0; i<ntail; i++)
    {
        if(tailx[i]==x && taily[i]==y)
        {
            ntail=1;
        }
    }

}


void input2()
{
    //Second movement
    if(GetAsyncKeyState(0x44))
    {
        if(d2==2)
        {
            d2=2;

        }
        else
        {
            d2=1;
        }

    }
    else if(GetAsyncKeyState(0x41))
    {
        if(d2==1)
        {
            d2=1;

        }
        else
        {
            d2=2;
        }

    }
    else if(GetAsyncKeyState(0x57))
    {
        if(d2==4)
        {
            d2=4;

        }
        else
        {
            d2=3;
        }

    }
    else if(GetAsyncKeyState(0x53))
    {
        if(d2==3)
        {
            d2=3;

        }
        else
        {
            d2=4;
        }

    }
}


void logic2()
{
    //second
    int prevx2 = tailx1[0];
    int prevy2 = taily1[0];
    int prevtempx1, prevtempy1;
    tailx1[0] = x1;
    taily1[0] = y1;
    for(i=1; i<4; i++)
    {
        prevtempx1 = prevx2;
        prevtempy1 = prevy2;
        prevx2 = tailx1[i];
        prevy2 = taily1[i];
        tailx1[i] = prevtempx1;
        taily1[i] = prevtempy1;
    }

    switch(d2)
    {
    case 0:
        if(dirP2==1)
        {
            x1=x1+10;
        }
        else if(dirP2==2)
        {
            x1=x1-10;
        }
        else if(dirP2==3)
        {
            y1=y1-10;
        }
        else if(dirP2==4)
        {
            y1=y1+10;
        }
        else
        {
            d2=0;
        }
        break;
    case 1:
        if(dirP2==2)
        {
            break;
        }
        x1=x1+10;
        dirP2=1;
        break;
    case 2:
        if(dirP2==1)
        {
            break;
        }
        x1= x1-10;
        dirP2=2;
        break;
    case 3:
        if(dirP2==4)
        {
            break;
        }
        dirP2=3;
        y1=y1-10;
        break;
    case 4:
        if(dirP2==3)
        {
            break;
        }
        dirP2=4;
        y1= y1+10;
        break;
    }
    setfillstyle(1,8);
    bar(x1,y1,x1+10,y1+10);
    for(k=0; k<2; k++)
    {
        setfillstyle(1,12);
        bar(tailx1[k],taily1[k], tailx1[k]+10, taily1[k]+10);
    }
    delay(60);



    // boundary check
    if(x1<190)
    {
        x1=width-20;
    }
    else if(x1>=width-10)
    {
        x1=180;
    }
    if(y1<10)
    {
        y1=height-10;
    }
    else if(y1>=height-10)
    {
        y1=10;
    }



    // GameOver Conditions [Collision mechanics]
    for(i=0; i<ntail; i++)
    {
        if((tailx[i]==x1 && taily[i]==y1) || (x==x1 && y==y1))
        {
            gameOver=true;
        }
    }

    for(i=0; i<2; i++)
    {
        if ((tailx1[i]==x && taily1[i]==y) || (x==x1 && y==y1))
        {
            gameOver=true;
        }
    }
}


void displayScore()
{
    char a[100];
    sprintf(a, "SCORE: %d", score);
    settextstyle(3,0,8);
    outtextxy(500, 600, a);
}


void displayScore2()
{
    char a[100];
    sprintf(a, "SCORE: %d", score);
    settextstyle(3,0,8);
    outtextxy(700, 600, a);
}


void midRound()
{
    char a[100];
    sprintf(a, "End Of Round 1!");
    settextstyle(3,0,8);
    outtextxy(390, 100, a);

    sprintf(a, "TARGET: %d", score+1);
    settextstyle(3,0,8);
    outtextxy(450, 300, a);

    sprintf(a, "Press SPACE to start second round");
    settextstyle(3,0,8);
    outtextxy(150, 500, a);
}


void inputR2()
{
    // Movement
    if(GetAsyncKeyState(0x44))
    {
        if(d==2)
        {
            d=2;

        }
        else
        {
            d=1;
        }

    }
    else if(GetAsyncKeyState(0x41))
    {
        if(d==1)
        {
            d=1;

        }
        else
        {
            d=2;
        }

    }
    else if(GetAsyncKeyState(0x57))
    {
        if(d==4)
        {
            d=4;

        }
        else
        {
            d=3;
        }

    }
    else if(GetAsyncKeyState(0x53))
    {
        if(d==3)
        {
            d=3;

        }
        else
        {
            d=4;
        }

    }

}


void input2R2()
{
    //Second movement
    if(GetAsyncKeyState(VK_RIGHT))
    {
        if(d2==2)
        {
            d2=2;

        }
        else
        {
            d2=1;
        }

    }
    else if(GetAsyncKeyState(VK_LEFT))
    {
        if(d2==1)
        {
            d2=1;

        }
        else
        {
            d2=2;
        }

    }
    else if(GetAsyncKeyState(VK_UP))
    {
        if(d2==4)
        {
            d2=4;

        }
        else
        {
            d2=3;
        }

    }
    else if(GetAsyncKeyState(VK_DOWN))
    {
        if(d2==3)
        {
            d2=3;

        }
        else
        {
            d2=4;
        }

    }
}

void profile()
{
    int the_end = 0;
do
{


    settextstyle(3,0,6);
    outtextxy ((1366/2)-450,(768/2)-200, "Player 1 (Arrows) Name: ");
    settextstyle(3, 0, 6);
   outtextxy ((1366/2)+140,(768/2)-200, inputbuf);
char   c = getch();
   switch (c)
   {
        case 8: /* backspace */
          if (input_pos)
          {
             input_pos--;
             inputbuf[input_pos]='_';

             //inputbuf[input_pos] = 0;
          }
          break;
        case 13: /* return */
          the_end = 1;
          break;
        case 27: /* Escape = Abort */
          inputbuf[0] = 0;
          the_end = 1;
          break;
        default:
          if (input_pos < MAX_INPUT_LEN-1 && c >= ' ' && c <= '~')
          {
             inputbuf[input_pos] = c;
             input_pos++;
             //inputbuf[input_pos] = 0;
          }
   }
} while (!the_end);
printf("%s", inputbuf);


int the_end2 = 0;
do
{
    settextstyle(3,0,6);
    outtextxy ((1366/2)-450,(768/2), "Player 2 (ASDW) Name: ");
    settextstyle(3, 0, 6);
   outtextxy ((1366/2)+140,(768/2), inputbuf2);
char   c = getch();
   switch (c)
   {
        case 8: /* backspace */
          if (input_pos2)
          {
             input_pos2--;
             inputbuf2[input_pos2]='_';

             //inputbuf2[input_pos2] = 0;
          }
          break;
        case 13: /* return */
          the_end2 = 1;
          break;
        case 27: /* Escape = Abort */
          inputbuf2[0] = 0;
          the_end2 = 1;
          break;
        default:
          if (input_pos2 < MAX_INPUT_LEN-1 && c >= ' ' && c <= '~')
          {
             inputbuf2[input_pos2] = c;
             input_pos2++;
             //inputbuf2[input_pos2] = 0;
          }
   }
} while (!the_end2);
printf("%s", inputbuf2);



}

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    // Full screen game play
    DWORD screenWidth = GetSystemMetrics(SM_CXSCREEN);
    DWORD screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "", -3, -3);


    int check = control_menu(), page;
    if(check==1)
    {
        cleardevice();
        page=0;

        profile();
        // Round 1
        setup();
        while(!gameOver)
        {
            // Double buffer pt.1
            setactivepage(page);
            setvisualpage(1-page);

            draw();
            input2();
            input();
            logic();
            logic2();
            displayScore();

            // Endgame condition
            if(GetAsyncKeyState(VK_ESCAPE))
            {
                return 0;
            }


            // Double buffer pt.2
            page=1-page;
        }


            // Mid-round UI
            delay(400);
            page=0;
            while(!GetAsyncKeyState(VK_SPACE))
            {
                setactivepage(page);
                setvisualpage(1-page);

                setfillstyle(1,15);
                bar(0,0,1366,768);
                midRound();
                delay(100);

                page=1-page;
            }


            // Setting the target
            int target=score+1;


            // Round 2
            page=0;
            setup();
            while(!gameOver)
            {
                // Double buffer pt.1
                setactivepage(page);
                setvisualpage(1-page);

                cleardevice();
                draw();
                input2R2();
                inputR2();
                logic();
                logic2();
                displayScore2();
                char a[100];
                sprintf(a, "TARGET: %d", target);
                settextstyle(3,0,8);
                outtextxy(225, 600, a);

                // Endgame condition
                if(GetAsyncKeyState(VK_ESCAPE))
                {
                    return 0;
                }

                if(score==target)
                {
                    gameOver=true;
                }


                // Double buffer pt.2
                page=1-page;

            }


            // Match Verdict
            if(score==target)
            {
                delay(250);
                page=0;
                while(!GetAsyncKeyState(VK_ESCAPE))
                {
                    setactivepage(page);
                    setvisualpage(1-page);

                    setfillstyle(1,15);
                    bar(0,0,1366,768);
                    char b[100];
                    sprintf(b, "%s wins!", inputbuf); //Player 1 wins
                    settextstyle(3,0,10);
                    outtextxy(375, 275, b);
                    delay(100);

                    page=1-page;
                }
                //printf("Player 1 wins!");

            }
            else if(score==target-1)
            {
                delay(275);
                page=0;
                while(!GetAsyncKeyState(VK_ESCAPE))
                {
                    setactivepage(page);
                    setvisualpage(1-page);

                    setfillstyle(1,15);
                    bar(0,0,1366,768);
                    char b[100];
                    sprintf(b, "Match tied!");
                    settextstyle(3,0,10);
                    outtextxy(375, 275, b);
                    delay(100);

                    page=1-page;
                }
                //printf("Match tied!");

            }
            else
            {
                delay(250);
                page=0;
                while(!GetAsyncKeyState(VK_ESCAPE))
                {
                    setactivepage(page);
                    setvisualpage(1-page);

                    setfillstyle(1,15);
                    bar(0,0,1366,768);
                    char b[100];
                    sprintf(b, "%s wins!", inputbuf2); // Player 2 wins
                    settextstyle(3,0,10);
                    outtextxy(375, 250, b);
                    delay(100);

                    page=1-page;
                }
                // printf("Player 2 wins!");
            }
    }
    else if(check==5)
    {
        return 0;
    }

    closegraph();

}
