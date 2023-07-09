#include<graphics.h>//easyx图形库头文件
#include <iostream>
#include<conio.h>//_getch()所需要的
#define graphwidth 700
#define graphheight 379
#define peoplewidth 80
#define peopleheight 80
IMAGE bk;
IMAGE move;
int x, y;//人物位置
int n ;
int dir;//人物的方向，0向下，1往上，2往左，3往右
void initgame();
void drawgame();
void crolgame();
int main()
{
    dir = 0;
    x = y = 100;
    n = 0;
    initgame();
    while (1) 
    {
        drawgame();
        Sleep(150);
        crolgame();
        n++;
        if (n >= 3)
        {
            n = 0;
        }
    }
    return 0;
}
void initgame()
{
    //准备工作
    initgraph(graphwidth, graphheight,SHOWCONSOLE);//初始化图形界面窗口 700宽，400高
    //加载
    loadimage(&bk, "bk.jpg");
    loadimage(&move,"move.png");
}
void drawgame() 
{
    switch (dir)
    {
    case 0:
        putimage(0, 0, &bk);// 前面两个特征值为贴图在图形界面窗口的位置（x,y）
        putimage(x, y, peoplewidth, peopleheight, &move, n * peoplewidth, 0, SRCPAINT);
        break;
    case 1:
        putimage(0, 0, &bk);// 前面两个特征值为贴图在图形界面窗口的位置（x,y）
        putimage(x, y, peoplewidth, peopleheight, &move, n * peoplewidth, 3*peopleheight, SRCPAINT);
        break;
    case 2:
        putimage(0, 0, &bk);// 前面两个特征值为贴图在图形界面窗口的位置（x,y）
        putimage(x, y, peoplewidth, peopleheight, &move, n * peoplewidth, 1*peopleheight, SRCPAINT);
        break;
    case 3:
        putimage(0, 0, &bk);// 前面两个特征值为贴图在图形界面窗口的位置（x,y）
        putimage(x, y, peoplewidth, peopleheight, &move, n * peoplewidth, 2*peopleheight, SRCPAINT);
        break;
    }
}
void crolgame()
{   
    int ch = _getch();
    std::cout << "ch=" << ch << std::endl;
    switch (ch)
    {
    case 'A':
    case 'a':
        x -= 10;
        dir = 2;
        break;
    case 'D':
    case 'd':
        x += 10;
        dir = 3;
        break;
    case 'W':
    case 'w':
        y += 10;
        dir = 0;
        break;
    case 'S':
    case 's':
        y -= 10;
        dir = 1;
        break;
    }

}