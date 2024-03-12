#ifndef STUDENTMENU_H
#define STUDENTMENU_H

#include <QDialog>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

namespace Ui {
class StudentMenu;
}

class StudentMenu : public QDialog
{
    Q_OBJECT

public:
    explicit StudentMenu(QWidget *parent = nullptr);
    ~StudentMenu();

    void setUsername(const QString &newUsername);

    void setWebToken(const QByteArray &newWebToken);

private slots:
    void on_btnInfo_clicked();
    void infoSlot(QNetworkReply *reply);

private:
    Ui::StudentMenu *ui;
    QString username;
    QByteArray webToken;

    QNetworkAccessManager *infoManager;
    QNetworkReply *reply;
    QByteArray response_data;
};

#endif // STUDENTMENU_H
