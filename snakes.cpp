#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>

using namespace std;

bool gameOver;
int width = 640;
int height = 480;
int x, y, i, j, k, score, fruitx, fruity, dir, d;
int tailx[1000], taily[1000];
int ntail;
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
enum eDirection dirP2;

void setup()
{
    //srand(time(0));
    gameOver = false;
    dirP2 = STOP;
    dir=0;
    d=0;
    x = width/2;
    y = height/2;
    fruitx = (rand()%(width-10));
    fruity = (rand()%(height-10));
    score=0;
}

void draw()
{
    // Resetting the screen
    setfillstyle(1,0);
    bar(10,10,630,470);

    // Boundaries
    setfillstyle(1,8);
    bar(0,0,640,10); // top bar
    bar(0,0,10,480); // left bar
    bar(0,480,640,470); // bottom bar
    bar(630,10,640,480); // right bar

    // fruit
    if((fruitx>=x && fruitx<=x+10) &&(fruity>=y && fruity<=y+10))
    {

        score=score+1;
        ntail++;
        setfillstyle(1,0);
        bar(fruitx, fruity, fruitx+7, fruity+7);

        do
        {
            fruitx = (rand()%(width-10));
            fruity = (rand()%(height-10));
        }
        while(getpixel(fruitx,fruity)!=0 && fruitx > 10 && fruity > 10);
        fruitx=fruitx/10;
        fruitx=fruitx*10;
        fruity=fruity/10;
        fruity=fruity*10;

    }
    setfillstyle(1,4);
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
    setfillstyle(1,15); //Head color
    bar(x,y,x+10,y+10); // Head
    
    // Body color and drawing
    for(k=0; k<ntail; k++)
    {
        setfillstyle(1,7);
        bar(tailx[k],taily[k], tailx[k]+10, taily[k]+10);
    }
    delay(100);

    // boundary check
    if(x<20)
    {
        x=width-20;
    }
    else if(x>=width-20)
    {
        x=20;
    }
    if(y<20)
    {
        y=height-20;
    }
    else if(y>=height-20)
    {
        y=20;
    }

    // Game over condition
    for(i=0; i<ntail; i++)
    {
        if(tailx[i]==x && taily[i]==y)
        {
            gameOver = true;
        }
    }

}

int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    setup();
    while(!gameOver)
    {
        draw();
        input();
        logic();

    }

}

