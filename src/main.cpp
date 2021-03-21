#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QtDebug>
#include <QVBoxLayout>
#include <QComboBox>
#include <windows.h>

#include "game.h"
#include "Dikstra.h"
#include "Gui.h"
#include "ComboBox.h"

Game *game;
Dikstra *dikstra;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QWidget* widget=new QWidget();
    QGridLayout* grid = new QGridLayout();

    QVBoxLayout* vBoxLayout = new QVBoxLayout;

    QComboBox *comboBox=new QComboBox();
    QStringList list=(QStringList()<<"dikstra"<<"A*"<<"depth");
    comboBox->addItems(list);
    vBoxLayout->addWidget(comboBox);

    game = new Game();
    game->displayMainMenu();

    vBoxLayout->addWidget(game);
    QFrame *line =  new QFrame();
    line->setFrameShape(QFrame::HLine);
    line->setFrameShadow(QFrame::Sunken);
    vBoxLayout->addWidget(line);



    widget->setLayout(vBoxLayout);

    grid->addWidget(widget,0,0,1,1);
    widget->setLayout(grid);

    QMainWindow *window = new GUI();
    window->setCentralWidget(widget);
    window->showMaximized();



//    game->showMaximized();
    return a.exec();
}
