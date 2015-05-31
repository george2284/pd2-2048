#include "form.h"
#include "ui_form.h"
#include <stdlib.h>
#include <ctime>
#include <string>
#include <QKeyEvent>
#include <QTimer>
using namespace std;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    srand(time(NULL));
    ui->setupUi(this);
}
//*Cubes=new QLabel[16];
Form::~Form()
{
    delete ui;
}
void Form::time_count(){
    int tmp=Form::label_2->text().toInt();
    tmp++;
    Form::label_2->setText(QString::number(tmp));
}
//QLabel* Form::Cubes=new QLabel[16];
//bool Form::new_game=0;
void Form::on_pushButton_clicked()
{
    Form::count_push=0;
    QFont f("FrankRuehl",30);
    int side=105;
    //int Form::count_zero=0;
    Form::new_game=1;
    //QLabel *tmp=Form::Cubes;
    Form::Cubes=new QLabel[16];
    Form::label_2=new QLabel;
    Form::label_3=new QLabel;
    Form::game_over=new QLabel;
    //QLabel *l=new QLabel;

    //Cube cube[16];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            Form::Cubes[4*i+j].setParent(this);
            Form::Cubes[4*i+j].setGeometry((30+(side+5)*j),(70+(side+5)*i),side,side);
            Form::Cubes[4*i+j].setFont(f);
            //Cubes[4*i+j]->size(side,side);
            if((i==1 && j==1)||(i==3 && j==3))Form::Cubes[4*i+j].setText("2");
            else Form::Cubes[4*i+j].setText("0");
            Form::Cubes[4*i+j].setFocusPolicy(Qt::NoFocus);
            Form::Cubes[4*i+j].show();
        }
    }
    Form::label_2->setParent(this);
    Form::label_2->setGeometry(120,50,90,40);
    Form::label_2->setFont(f);
    Form::label_2->setText("0");
    Form::label_2->setFocusPolicy(Qt::NoFocus);
    Form::label_2->show();
    Form::label_3->setParent(this);
    Form::label_3->setGeometry(370,50,90,40);
    Form::label_3->setFont(f);
    Form::label_3->setText("0");
    Form::label_3->setFocusPolicy(Qt::NoFocus);
    Form::label_3->show();
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(time_count()));
    timer->start(1000);
    //clock_t start,count;
}

void Form::on_pushButton_2_clicked()
{
    QApplication::quit();
}

void Form::keyPressEvent(QKeyEvent *event){
    QFont f("FrankRuehl",30);
    if(Form::new_game==1){
        switch (event->key()) {
        case Qt::Key_Down:{
            Form::count_push++;Form::label_3->setText(QString::number(Form::count_push));
            //Form::lcdNumber_2.intValue()=Form::count_push;
            //Form::lcdNumber_2.intValue()++;
            for(int j=3;j>=0;j--){
                for(int i=3;i>=0;i--){
                    for(int up=i-1;up>=0;up--){
                        if(Form::Cubes[4*i+j].text().compare(Form::Cubes[4*up+j].text())==0){
                            Form::Cubes[4*i+j].setText(QString::number(Form::Cubes[4*i+j].text().toInt()+Form::Cubes[4*up+j].text().toInt()));
                            Form::Cubes[4*up+j].setText("0");
                            //Form::Cubes[4*i+j].show();Form::Cubes[4*up+j].show();

                        }
                        else if(Form::Cubes[4*i+j].text().compare("0")==0 && Form::Cubes[4*up+j].text().compare("0")!=0){
                            Form::Cubes[4*i+j].setText(Form::Cubes[4*up+j].text());
                            Form::Cubes[4*up+j].setText("0");
                            //Form::Cubes[4*i+j].show();Form::Cubes[4*up+j].show();
                        }
                        else if(Form::Cubes[4*i+j].text().compare("0")!=0 && Form::Cubes[4*up+j].text().compare("0")!=0)break;
                    }
                }
            }
        }
            break;
        case Qt::Key_Up:{
            Form::count_push++;Form::label_3->setText(QString::number(Form::count_push));
            for(int j=0;j<4;j++){
                for(int i=0;i<4;i++){
                    for(int up=i+1;up<4;up++){
                        if(Form::Cubes[4*i+j].text().compare(Form::Cubes[4*up+j].text())==0){
                            Form::Cubes[4*i+j].setText(QString::number(Form::Cubes[4*i+j].text().toInt()+Form::Cubes[4*up+j].text().toInt()));
                            Form::Cubes[4*up+j].setText("0");
                        }
                        else if(Form::Cubes[4*i+j].text().compare("0")==0 && Form::Cubes[4*up+j].text().compare("0")!=0){
                            Form::Cubes[4*i+j].setText(Form::Cubes[4*up+j].text());
                            Form::Cubes[4*up+j].setText("0");
                        }
                        else if(Form::Cubes[4*i+j].text().compare("0")!=0 && Form::Cubes[4*up+j].text().compare("0")!=0)break;
                    }
                }
            }}
            break;
        case Qt::Key_Left:{
            Form::count_push++;Form::label_3->setText(QString::number(Form::count_push));
            for(int i=0;i<4;i++){
                for(int j=0;j<4;j++){
                    for(int up=j+1;up<4;up++){
                        if(Form::Cubes[4*i+j].text().compare(Form::Cubes[4*i+up].text())==0){
                            Form::Cubes[4*i+j].setText(QString::number(Form::Cubes[4*i+j].text().toInt()+Form::Cubes[4*i+up].text().toInt()));
                            Form::Cubes[4*i+up].setText("0");
                        }
                        else if(Form::Cubes[4*i+j].text().compare("0")==0 && Form::Cubes[4*i+up].text().compare("0")!=0){
                            Form::Cubes[4*i+j].setText(Form::Cubes[4*i+up].text());
                            Form::Cubes[4*i+up].setText("0");
                        }
                        else if(Form::Cubes[4*i+j].text().compare("0")!=0 && Form::Cubes[4*i+up].text().compare("0")!=0)break;
                    }
                    //if(Form::Cubes[4*i+j].text().compare("0")==0)count_zero++;
                }
            }
        }break;
        case Qt::Key_Right:{
            Form::count_push++;Form::label_3->setText(QString::number(Form::count_push));
            for(int i=0;i<4;i++){
                for(int j=3;j>=0;j--){
                    for(int up=j-1;up>=0;up--){
                        if(Form::Cubes[4*i+j].text().compare(Form::Cubes[4*i+up].text())==0){
                            Form::Cubes[4*i+j].setText(QString::number(Form::Cubes[4*i+j].text().toInt()+Form::Cubes[4*i+up].text().toInt()));
                            Form::Cubes[4*i+up].setText("0");
                        }
                        else if(Form::Cubes[4*i+j].text().compare("0")==0 && Form::Cubes[4*i+up].text().compare("0")!=0){
                            Form::Cubes[4*i+j].setText(Form::Cubes[4*i+up].text());
                            Form::Cubes[4*i+up].setText("0");
                        }
                        else if(Form::Cubes[4*i+j].text().compare("0")!=0 && Form::Cubes[4*i+up].text().compare("0")!=0)break;
                    }
                }
            }
        }break;
        default:
            break;
        }
    }
        int count_zero=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                if(Form::Cubes[4*i+j].text().compare("0")==0)count_zero++;
                else if(Form::Cubes[4*i+j].text().compare("2048")==0){
                    Form::new_game=0;
                    Form::game_over->setParent(this);
                    Form::game_over->setGeometry(200,500,200,80);
                    Form::game_over->setFont(f);
                    Form::game_over->setText("2048!!");
                    Form::game_over->show();
        }}}
            if(count_zero==0){
                Form::new_game=0;
                Form::game_over->setParent(this);
                Form::game_over->setGeometry(200,500,200,80);
                Form::game_over->setFont(f);
                Form::game_over->setText("Game Over");
            }
            else{
            int r=rand()%count_zero;
            int d=r%2;
            int i=0;
            for(int j=0;j<16;j++){
                if(Form::Cubes[j].text().compare("0")==0){
                    if(r==i){
                        if(d==0)Form::Cubes[j].setText("2");
                        else Form::Cubes[j].setText("4");
                        //Form::Cubes[i].show();
                        break;
                    }
                    else i++;
                }
            }
            }
}
