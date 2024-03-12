#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QDialog>

namespace Ui {
class StudentInfo;
}

class StudentInfo : public QDialog
{
    Q_OBJECT

public:
    explicit StudentInfo(QWidget *parent = nullptr);
    ~StudentInfo();

    void setFname(const QString &newFname);

    void setLname(const QString &newLname);

    void setEmail(const QString &newEmail);

private:
    Ui::StudentInfo *ui;
    QString fname;
    QString lname;
    QString email;
};

#endif // STUDENTINFO_H
