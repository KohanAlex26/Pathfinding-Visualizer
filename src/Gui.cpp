#include "Gui.h"
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QDebug>
#include <QFileDialog>
#include <QIcon>
#include <QFrame>
#include <QAction>
#include <QMenuBar>
#include <QStatusBar>
#include "ComboBox.h"


GUI::GUI(QWidget *parent) : QMainWindow(parent)
{
    this->setWindowTitle("Main Window");
//    QMenu* fileMenu = this->menuBar()->addMenu("&File"); //mnemonics ALT+F
//    QComboBox *comboBox=new QComboBox();
//    QStringList list=(QStringList()<<"red"<<"yellow"<<"blue");
//    comboBox->addItems(list);
//    this->setCentralWidget(comboBox);
}

