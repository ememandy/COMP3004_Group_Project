#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <string>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)

{


//UI Creation
    ui->setupUi(this);
    QPixmap mainmenu(":/rec/pics/mainmenu.png");
    QPixmap power(":/rec/pics/power.png");
    QPixmap up(":/rec/pics/uparrow.png");
    QPixmap back(":/rec/pics/back.png");
    QPixmap right,left,down;

    QMatrix r,l,d;
    r.rotate(90);
    l.rotate(270);
    d.rotate(180);
    right = up.transformed(r);
    left = up.transformed(l);
    down = up.transformed(d);

    ui->uparrow->setIcon(up);
    ui->rightarrow->setIcon(right);
    ui->leftarrow->setIcon(left);
    ui->downarrow->setIcon(down);
    ui->power->setIcon(power);
    ui->mainmenu->setIcon(mainmenu);
    ui->back->setIcon(back);

    ui->menu_screen->addItem("PROGRAMS");
    ui->menu_screen->addItem("FREQUENCY");
    ui->menu_screen->addItem("MED");
    ui->menu_screen->addItem("SCREENING");
    ui->menu_screen->addItem("CHILDREN");
    ui->menu_screen->addItem("SETTINGS");
    ui->menu_screen->addItem("DRAIN BATTERY");

    ui->programs_screen->addItem("ALLERGY");
    ui->programs_screen->addItem("PAIN");
    ui->programs_screen->addItem("INT.PAIN");
    ui->programs_screen->addItem("BLOATING");
    ui->programs_screen->addItem("DYSTONIA");
    ui->programs_screen->addItem("GYN. PAIN");
    ui->programs_screen->addItem("GYNECOLOGY");
    ui->programs_screen->addItem("HYPERTENISON");
    ui->programs_screen->addItem("HEAD");
    ui->programs_screen->addItem("THROAT");
    ui->programs_screen->addItem("TEST 1");
    ui->programs_screen->addItem("TEST 2");
    ui->programs_screen->hide();

    ui->freq_screen->addItem("1.0-9.9 Hz");
    ui->freq_screen->addItem("10 Hz");
    ui->freq_screen->addItem("20 Hz");
    ui->freq_screen->addItem("60 Hz");
    ui->freq_screen->addItem("77 Hz");
    ui->freq_screen->addItem("125 Hz");
    ui->freq_screen->addItem("140 Hz");
    ui->freq_screen->addItem("200 Hz");
    ui->freq_screen->addItem("7710");
    ui->freq_screen->addItem("7720");
    ui->freq_screen->addItem("77AM");
    ui->freq_screen->hide();

    ui->electrode->setEnabled(false);
    ui->uparrow->setEnabled(false);
    ui->rightarrow->setEnabled(false);
    ui->leftarrow->setEnabled(false);
    ui->downarrow->setEnabled(false);
    ui->ok->setEnabled(false);
    ui->mainmenu->setEnabled(false);
    ui->back->setEnabled(false);

    //This number represents the rate at which the battery drains (the bigger the number the slower it is)
    inital_power_rate = 15000;
    current_power_rate = inital_power_rate;

    //signal and slots
    connect(ui->power, SIGNAL (released()), this, SLOT (handlePowerButton()));

    power_rate = new QTimer(this);
    connect(power_rate,SIGNAL(timeout()),this,SLOT(battery_level()));

    session = new QTimer(this);
    connect(session,SIGNAL(timeout()),this,SLOT(freq_therapy_session()));
    connect(session,SIGNAL(timeout()),this,SLOT(therapy_session()));



    //key for states: 0=menu_screen; 1=programs_screen; 2=freq_screen; 3=power_screen; 4=freq_power_screen; 5=session_screen;
    current_state.push(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Function for POWER button
void MainWindow::handlePowerButton()
 {
    if(ui->electrode->isEnabled()){
        close();
    }else{
        // enable all buttons
        ui->electrode->setEnabled(!ui->electrode->isEnabled());
        ui->uparrow->setEnabled(!ui->uparrow->isEnabled());
        ui->rightarrow->setEnabled(!ui->rightarrow->isEnabled());
        ui->leftarrow->setEnabled(!ui->leftarrow->isEnabled());
        ui->downarrow->setEnabled(!ui->downarrow->isEnabled());
        ui->ok->setEnabled(!ui->ok->isEnabled());
        ui->mainmenu->setEnabled(!ui->mainmenu->isEnabled());
        ui->back->setEnabled(!ui->back->isEnabled());

        //change color of widget background from black to white
        ui->menu_screen->setStyleSheet("background: white""");

        //start depleting the battery
        power_rate->start(current_power_rate);

    }
 }

//Functionality for UP arrow button
//Using a finite state machine the button will only work on the screen which is currently on top of the stack
void MainWindow::on_uparrow_clicked()
{

    if(current_state.top()==0){
        ui->menu_screen->setCurrentRow(ui->menu_screen->currentRow()-1);
    }

    if(current_state.top()==1){
         ui->programs_screen->setCurrentRow(ui->programs_screen->currentRow()-1);
    }

    if (current_state.top()==2){
          ui->freq_screen->setCurrentRow(ui->freq_screen->currentRow()-1);
    }
}

//Functionality for DOWN arrow button
//Using a finite state machine the button will only work on the screen which is currently on top of the stack
void MainWindow::on_downarrow_clicked()
{
    if(current_state.top()==0){
        ui->menu_screen->setCurrentRow(ui->menu_screen->currentRow()+1);
    }

    if(current_state.top()==1){
         ui->programs_screen->setCurrentRow(ui->programs_screen->currentRow()+1);
    }

    if (current_state.top()==2){
         ui->freq_screen->setCurrentRow(ui->freq_screen->currentRow()+1);
    }

}

//Functionality for OK button
//Using a finite state machine the button will only work on the screen which is currently on top of the stack
void MainWindow::on_ok_clicked()
{

    if(current_state.top()==0){
            if(ui->menu_screen->currentItem()==nullptr){
                qDebug()<<"null";
                ui->menu_screen->setCurrentRow(0);
            }
            qDebug()<<ui->menu_screen->currentItem()->text();
            const QString& s = ui->menu_screen->currentItem()->text();
            menu_selection(s);
    }
    else if(current_state.top()==1){
        if(ui->programs_screen->currentItem()==nullptr){
            qDebug()<<"null";
            ui->programs_screen->setCurrentRow(0);
        }
        qDebug()<<ui->programs_screen->currentItem()->text();
        const QString& p = ui->programs_screen->currentItem()->text();
        menu_selection(p);
    }
    else if(current_state.top()==2){
        if(ui->freq_screen->currentItem()==nullptr){
            qDebug()<<"null";
            ui->freq_screen->setCurrentRow(0);
        }
         const QString& f = ui->freq_screen->currentItem()->text();
         menu_selection(f);
         current_state.push(4);
    }
    else if (current_state.top()==3){
                //the rate a which the battery depletes depending on the power level
                current_power_rate -= 100*ui->power_level->value();
                power_rate->start(current_power_rate);
                //Setting the screen display
                ui->session_screen->show();
                ui->session_screen->raise();
                ui->current_freq->show();
                ui->current_freq->raise();
                ui->session_time->raise();
                ui->power_level->raise();

                ui->power_screen->hide();
                ui->freq_power_screen->hide();
                ui->freq_screen->hide();

                ui->power_level->move(25,25);
                session->start(1000);
                qDebug()<<ui->session_screen->isVisible();
                current_state.push(5);
    }
    else if (current_state.top()==4){
                //the rate a which the battery depletes depending on the power level
                current_power_rate -= 100*ui->power_level->value();
                power_rate->start(current_power_rate);
                f_time.setHMS(00,00,00);
                //Setting the screen display
                ui->session_screen->show();
                ui->session_screen->raise();
                ui->current_freq->show();
                ui->current_freq->raise();
                ui->freq_session->raise();
                ui->power_level->raise();

                ui->freq_screen->hide();
                ui->power_screen->hide();
                ui->freq_power_screen->hide();

                ui->power_level->move(25,25);

                session->start(1000);
                current_state.push(5);
    }
}



//Functionality for MAIN MENU button
void MainWindow::on_mainmenu_clicked()
{
    //Button returns menu screen to top of stack, while hiding all other widgets that may have been open and returns power rate to normal
    ui->menu_screen->show();
    ui->menu_screen->raise();
    ui->programs_screen->hide();
    ui->freq_screen->hide();
    ui->power_screen->hide();
    ui->freq_power_screen->hide();
    ui->session_screen->hide();
    ui->next_freq->hide();
    ui->current_freq->hide();
    current_power_rate = inital_power_rate;
    power_rate->start(current_power_rate);
    ui->power_level->move(110,70);
    session->stop();
    while(current_state.top()!=0){
        qDebug()<<current_state.top();
        current_state.pop();
    }
}

//Functionality for BACK button
void MainWindow::on_back_clicked()
{
    //Depending on which screen is on top of the stack will determine which screen will show when button is pressed
    ui->menu_screen->show();
    ui->menu_screen->raise();
    ui->programs_screen->hide();
    ui->freq_screen->hide();

    ui->power_level->move(110,70);
    switch(current_state.top()) {
        case 0 : break;
        case 1 : ui->programs_screen->hide();
                ui->menu_screen->show();
                ui->menu_screen->raise();
                current_state.pop();
                break;
        case 2 : ui->freq_screen->hide();
                ui->menu_screen->show();
                ui->menu_screen->raise();
                current_state.pop();
                break;
        case 3 : ui->power_screen->hide();
                ui->power_level->move(110,70);
                ui->programs_screen->show();
                ui->programs_screen->raise();
                current_state.pop();
                break;
        case 4 : ui->freq_power_screen->hide();
                ui->power_level->move(110,70);
                ui->freq_screen->show();
                ui->freq_screen->raise();
                current_state.pop();
                break;
        case 5 : qDebug()<< '5';
                ui->session_screen->hide();
                ui->next_freq->hide();
                ui->current_freq->hide();
                current_power_rate = inital_power_rate;
                power_rate->start(current_power_rate);
                ui->power_level->move(110,70);
                session->stop();
                current_state.pop();
                qDebug()<< current_state.top();
                if(current_state.top()==3){
                    if(ui->current_freq->text()=="Current Freq: 75Hz"){
                        countdown.setHMS(00, 15,00);
                    }else if(ui->current_freq->text()=="Current Freq: 140Hz"){
                        countdown.setHMS(00, 05,10);
                    }else if(ui->current_freq->text()=="Current Freq: 60Hz"){
                        countdown.setHMS(00, 00,10);
                    }else {
                        countdown.setHMS(00, 10,00);
                    }
                    ui->power_screen->show();
                    ui->power_screen->raise();
                }else{
                    ui->freq_power_screen->show();
                    ui->freq_power_screen->raise();
                }
                ui->power_level->show();
                ui->power_level->raise();
                ui->power_label->raise();
                break;
        default: break;
    }
}

//Functionality for RIGHT arrow button
void MainWindow::on_rightarrow_clicked()
{
    //Button enabled during power selection and therapy session screens, increases power level, while also increasing the rate of battery depletion
    if(current_state.top()>=3 && ui->power_level->value()<100){
        ui->power_level->setValue(ui->power_level->value()+1);
        if(current_state.top()==5){
            qDebug()<<"before";
            qDebug()<<current_power_rate;
            current_power_rate = inital_power_rate - 100*ui->power_level->value();
            qDebug()<<"after";
            qDebug()<<current_power_rate;
            power_rate->start(current_power_rate);
        }
    }

}

//Functionality for LEFT arrow button
void MainWindow::on_leftarrow_clicked()
{
    //Button enabled during power selection and therapy session screens, decreases power level, while also decreasing the rate of battery depletion
    if(current_state.top()>=3 && ui->power_level->value()>0){
        ui->power_level->setValue(ui->power_level->value()-1);
        if(current_state.top()==5){
            qDebug()<<"before";
            qDebug()<<current_power_rate;
            current_power_rate = inital_power_rate - 100*ui->power_level->value();
            qDebug()<<"after";
            qDebug()<<current_power_rate;
            power_rate->start(current_power_rate);
        }
    }

}

//HELPER FUNCTIONS

//Helper function used when ok button is pressed
void MainWindow::menu_selection(QString s)
{

    //displays programs screen
    if(s == "PROGRAMS"){
        ui->programs_screen->show();
        ui->programs_screen->raise();
        ui->menu_screen->hide();
        current_state.push(1);
    }

    //displays frequency screen
    if(s == "FREQUENCY"){
        ui->freq_screen->show();
        ui->freq_screen->raise();
        ui->menu_screen->hide();
        current_state.push(2);
    }

    //drains battery at a rate of 0.1 seconds
    if(s == "DRAIN BATTERY"){
        power_rate->start(100);
    }

    //in the programs screen displays a power level screen with certain time/freq differences depending on the program
    if (s == "PAIN" || s== "ALLERGY" || s == "BLOATING" || s== "TEST 1" || s== "TEST 2"){
        ui->power_screen->show();
        ui->power_screen->raise();
        ui->power_level->show();
        ui->power_level->raise();
        ui->power_label->raise();
        ui->programs_screen->hide();
        current_state.push(3);

        if (s == "PAIN"){
            countdown.setHMS(00, 15,00);
            ui->current_freq->setText("Current Freq: 75Hz");
            ui->next_freq->setText("Current Freq: 135Hz");
            ui->next_freq->hide();
            ui->current_freq->hide();

        } else if (s == "BLOATING"){
            countdown.setHMS(00, 10,00);
            ui->current_freq->setText("Current Freq: 7710");
            ui->next_freq->setText("Current Freq: 125Hz");
            ui->next_freq->hide();
            ui->current_freq->hide();

        } else if (s == "ALLERGY"){
             countdown.setHMS(00, 10,00);
             ui->current_freq->setText("Current Freq: 7710");
             ui->next_freq->setText("Current Freq: 3.8Hz");
             ui->next_freq->hide();
             ui->current_freq->hide();

        }  else if (s == "TEST 1"){
            countdown.setHMS(00, 05,10);
            ui->current_freq->setText("Current Freq: 140Hz");
            ui->next_freq->setText("Current Freq: 77Hz");
            ui->next_freq->hide();
            ui->current_freq->hide();

       }  else if (s == "TEST 2"){
            countdown.setHMS(00, 00,10);
            ui->current_freq->setText("Current Freq: 60Hz");
            ui->next_freq->setText("Current Freq: 20Hz");
            ui->next_freq->hide();
            ui->current_freq->hide();
       }
    }

    //Displays power level screen
    if (s.endsWith("Hz") == true || s == "7710" || s == "7720" || s == "77AM"){
        ui->current_freq->setText("Current Freq: " + s);
        ui->freq_power_screen->show();
        ui->freq_power_screen->raise();
        ui->power_level->show();
        ui->power_level->raise();
        ui->power_label->raise();
        ui->freq_screen->hide();
        ui->power_screen->hide();
    }

}



//Function that depletes battery power
void MainWindow::battery_level()
{
  //if the batery level is at 50% color changes
  ui->battery->setValue(ui->battery->value()-1);
  if(ui->battery->value() <= 50 && ui->battery->value() > 20){
      ui->battery->setStyleSheet("QProgressBar::chunk {background: yellow}");
  }

  //if the battery is at 20% change the color again
  if(ui->battery->value() <= 20){
      ui->battery->setStyleSheet("QProgressBar::chunk {background: red}");

  }
  //close the app if it reaches 0%
  if(ui->battery->value() == 0){
      close();
  }
}

//Function that conducts the therapy session with a program
void MainWindow:: therapy_session()
{
    //function waits and checks if checkbox is checked, if it is start the timer, else pause it
    if (ui->electrode->isChecked() == true){
        countdown = countdown.addSecs(-1.00);
        ui->session_time->setText(countdown.toString("mm : ss"));


    }else{
        ui->session_time->setText(countdown.toString("mm : ss"));
        return;
    }

    //If time reaches 5mins change the current frequency (as seen in denas manual)
    if(ui->session_time->text() == "05 : 00"){
        ui->current_freq->hide();
        ui->next_freq->raise();
        ui->next_freq->show();

    }

    //when timer finished send user back to main menu
    if(ui->session_time->text() == "00 : 00"){
        ui->power_level->move(110,70);
        ui->menu_screen->raise();
        ui->menu_screen->show();
        session->stop();
        while(current_state.top()!=0){
            qDebug()<<current_state.top();
            current_state.pop();
        }
    }

}

//Function that conducts the therapy session with a chosen frequency
void MainWindow:: freq_therapy_session(){
    if (ui->electrode->isChecked() == true){
        f_time = f_time.addSecs(1.00);
        ui->freq_session->setText(f_time.toString("mm : ss"));

    }else{
        ui->freq_session->setText(f_time.toString("mm : ss"));
        return;
    }
}


