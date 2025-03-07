#include "mainwindow.h"
#include "headers.h"


//void decode(_word1, _word2,_data1, _data2){}
/*
void decode(_word1, _word2,_data1, _data2)
{
    uint8_t speed=0x07 & _data1;
    // 000/ 001/010/011/100/101/110/111 RH /RH /RY
    switch (speed)
    {
    case 0:
        //writeln( "");
        //printf("0 speed");
        _word1->speed=0;
        break;
    case 1:
        //printf("V1 speed (RH=1 RF=0 RY=0)");
        _word1->speed=1;
        break;
    case 2:
        //printf("V2 speed (RH=0 RF=1 RY=0)");
        //MainWindow::ui->label;
        _word1->speed=2;
        break;
    case 3:
        //printf("V3 speed (RH=1 RF=1 RY=0)");
        _word1->speed=3;
        break;
    case 4:
        //printf("V4 speed (RH=0 RF=0 RY=1)");
        _word1->speed=4;
        break;
    case 5:
        //printf("V5 speed (RH=1 RF=0 RY=1)");
        _word1->speed=5;
        break;
    case 6:
        //printf("V6 speed (RH=0 RF=1 RY=1)");
        _word1->speed=6;
        break;
    case 7:
        //printf("V7 speed (RH=1 RF=1 RY=1)");
        _word1->speed=7;
        break;
    default:
        //printf("not correct speed");
        break;
    }
    if((0x08 & _data1)>0)
        _word1->forwrd=1;
    if((0x10 & _data1)>0)
        _word1->reverse=1;
    if(_word1->forwrd==1)
        //printf("\nGo to up");
    if(_word1->forwrd==1)
        //printf("\nGo to down");
    if(_word1->forwrd==1 && _word1->reverse==1)
        //printf("\nEror direction");

    if((0x20 & _data1)>0)
        {
        _word1->ready=1;
        //printf("\nContactor on");
                          }
    else
    {
        //printf("\nContactor off");
        _word1->ready=0;}

    if((0x40 & _data1)>0){
        _word1->fren=1;
        //printf("\nFren on");
    }
    else
    {//printf("\nFren off");
        _word1->fren=0;}

    if((0x80 & _data1)>0){
        _word1->ptc=1;
        //printf("\nPTC ok");
    }
    else
    {//printf("\nPTC error");
        _word1->ptc=0;}
    //printf("\n");
    if((0x01 & _data2)>0)
    {_word2->inspect=1;
        //printf("\nInspection is On");
    }
    else
    {//printf("\nInspection is Off");
        _word2->inspect=0;}

    if((0x02 & _data2)>0)
    {
        _word2->up=1;
        //printf("\nInspection move up");
    }
    else
    {_word2->up=0;}

    if((0x04 & _data2)>0)
    {_word2->down=1;
        //printf("\nInspection move down");
    }
    else
    {_word2->down=0;}
    if(_word2->up==1 && _word2->down==1)
        //printf("\nInspection move eror");

    if((0x08 & _data2)>0)
    {
    _word2->ml1=1;
        //printf("\nML1 is on");
    }
    else
    {
    _word2->ml1=0;
        //printf("\nML1 is off");
    }

    if((0x10 & _data2)>0)
    {_word2->ml2=1;
        //printf("\nML2 is on");
    }
    else
    {_word2->ml2=0;
        //printf("\nML2 is off");
    }
    if(_word2->ml1==1 && _word2->ml2 ==1)
        //printf("\nIn floor");
    //else
    if(_word2->ml1==1 && _word2->ml2 ==0)
     {
    //printf("\n up to down");
     }
    //else
    if(_word2->ml1==0 && _word2->ml2 ==1)
    {
    //printf("\n down to up");
    }

    if((0x20 & _data2)>0)
    {_word2->comand_door=1;
        //printf("\nDoor closed");
    }
    else
    {_word2->comand_door=0;
        //printf("\nDoor opened");
    }

    if((0x40 & _data2)>0)
    {
     _word2->top_floor=1;
        //printf("\nIn Top level");
    }
    else
    {
     _word2->top_floor=0;
        //printf("\nNot top level");
    }
    if((0x80 & _data2)>0)
    {
     _word2->down_floor=1;
        //printf("\nIn Down level");
    }
    else
    {_word2->down_floor=0;
        //printf("\nNot down level");
    }
    //if(_word2->top_floor==1 && _word2->down_floor==1)
        //printf("\nEror level position");


}
*/
