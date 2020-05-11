#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QListWidget>
#include <QTime>
#include <stack>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ok_clicked();

    void on_uparrow_clicked();

    void on_downarrow_clicked();

    void menu_selection(QString);

    void on_mainmenu_clicked();

    void battery_level();

    void handlePowerButton();


    void on_rightarrow_clicked();

    void on_leftarrow_clicked();

    void freq_therapy_session();

    void therapy_session();

    void on_back_clicked();





private:
    Ui::MainWindow *ui;
    QTimer *power_rate;
    QTimer *session;
    QTime countdown;
    QTime f_time;
    int current_power_rate;
    int temp;
    int inital_power_rate;
    std::stack<int> current_state;


};

#endif // MAINWINDOW_H
