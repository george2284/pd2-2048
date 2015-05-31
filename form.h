#ifndef FORM_H
#define FORM_H
#include "form.h"
#include "ui_form.h"

namespace Ui {
class Form;
}
class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();

private slots:
    void time_count();
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void keyPressEvent(QKeyEvent *event);
private:
    Ui::Form *ui;
    bool new_game;
    QLabel* Cubes;
    QLabel *game_over;
    int count_push;
    QLabel* label_2,*label_3;
};

#endif // FORM_H
