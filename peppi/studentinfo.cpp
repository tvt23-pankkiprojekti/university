#include "studentinfo.h"
#include "ui_studentinfo.h"

StudentInfo::StudentInfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
}

StudentInfo::~StudentInfo()
{
    delete ui;
}

void StudentInfo::setFname(const QString &newFname)
{
    fname = newFname;
    ui->labelFname->setText(fname);

}

void StudentInfo::setLname(const QString &newLname)
{
    lname = newLname;
    ui->labelLname->setText(lname);
}

void StudentInfo::setEmail(const QString &newEmail)
{
    email = newEmail;
    ui->labelEmail->setText(email);
}
