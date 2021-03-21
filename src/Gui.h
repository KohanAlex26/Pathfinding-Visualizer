#ifndef GUI_H
#define GUI_H
#include <QMainWindow>

class GUI : public QMainWindow
{

    Q_OBJECT
public:
    explicit GUI(QWidget *parent = nullptr);
};

#endif // GUI_H
