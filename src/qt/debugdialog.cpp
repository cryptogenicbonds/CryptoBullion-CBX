#include "debugdialog.h"
#include "ui_debugdialog.h"

DebugDialog::DebugDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DebugDialog)
{
    ui->setupUi(this);

    ui->textEdit->append("HELLO");
}

DebugDialog::~DebugDialog()
{
    delete ui;
}
