#ifndef GRADES_H
#define GRADES_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class Grades;
}

class Grades : public QDialog
{
    Q_OBJECT

public:
    explicit Grades(QWidget *parent = nullptr);
    ~Grades();

    void setUsername(const QString &newUsername);

    void setWebtoken(const QByteArray &newWebtoken);

private slots:
    void on_btnShowGrades_clicked();
    void gradeSlot (QNetworkReply *reply);

private:
    Ui::Grades *ui;
    QString username;
    QByteArray webtoken;

    QNetworkAccessManager *getManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // GRADES_H
