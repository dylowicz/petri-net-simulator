#include "transition.h"
#include "ui_transition.h"
#include <QMenu>
#include "matejkocanvas.h"

int Transition::count = 0;

Transition::Transition(QPoint &origin, QWidget *parent) :
    Element(origin, parent),
    ui(new Ui::Transition)
{
    ui->setupUi(this);
    this->setGeometry(origin.x() - this->width()/2, origin.y() - this->height()/2, this->width(), this->height());
    this->setChildrenClickable(false);

    this->letter = "T";
    this->basicStyleSheet = this->styleSheet();

    ++Transition::count;
    this->setNumber(Transition::count);

    this->show();
}

Transition::~Transition() {
    delete ui;
    --Transition::count;
}

void Transition::updateNumber() {
    ui->nameLabel->setText(this->letter + QString::number(this->number()));
}
