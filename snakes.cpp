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
int x, y, x1, y1, i, j, k, score, fruitx, fruity, dir, d, d2, dirP2;
int tailx[1000], taily[1000], tailx1[5], taily1[5];
int ntail;

void logic2();

void setup()
{
    //srand(time(0));
    gameOver = false;
    dirP2 = 0;
    dir=0;
    d=0;
    x = width/2;
    y = height/2;
    x1 = (width/2)+150;
    y1 = (height/2)+150;
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
    else if((fruitx>=x1 && fruitx<=x1+10) &&(fruity>=y1 && fruity<=y1+10))
    {
        score=score+1;
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
    setfillstyle(1,15); // Head color
    bar(x,y,x+10,y+10); // Head

    // Body color and drawing
    for(k=0; k<ntail; k++)
    {
        setfillstyle(1,7);
        bar(tailx[k],taily[k], tailx[k]+10, taily[k]+10);
    }
    // delay(100);

    // boundary check
    if(x<10)
    {
        x=width-10;
    }
    else if(x>=width-10)
    {
        x=10;
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
    setfillstyle(1,15);
    bar(x1,y1,x1+10,y1+10);
    for(k=0; k<2; k++)
    {
        setfillstyle(1,7);
        bar(tailx1[k],taily1[k], tailx1[k]+10, taily1[k]+10);
    }
    delay(60);



    // boundary check
    if(x1<10)
    {
        x1=width-10;
    }
    else if(x1>=width-10)
    {
        x1=10;
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


int main()
{
    int gdriver = DETECT, gmode;
    initgraph(&gdriver, &gmode, NULL);

    setup();
    while(!gameOver)
    {
        draw();
        input2();
        input();
        logic();
        logic2();

    }

}
