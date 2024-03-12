#include "environment.h"
#include "grades.h"
#include "studentinfo.h"
#include "studentmenu.h"
#include "ui_studentmenu.h"

StudentMenu::StudentMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StudentMenu)
{
    ui->setupUi(this);
}

StudentMenu::~StudentMenu()
{
    delete ui;
}

void StudentMenu::setUsername(const QString &newUsername)
{
    username = newUsername;
    ui->labelInfo->setText(username);
}

void StudentMenu::setWebToken(const QByteArray &newWebToken)
{
    webToken = newWebToken;
    qDebug()<<webToken;
}

void StudentMenu::on_btnInfo_clicked()
{
    QString site_url=Environment::getBaseUrl()+"/student/"+username;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webToken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    infoManager = new QNetworkAccessManager(this);

    connect(infoManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(infoSlot(QNetworkReply*)));

    reply = infoManager->get(request);
}

void StudentMenu::infoSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    //qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonObject json_obj = json_doc.object();
    StudentInfo *objecStudentInfo=new StudentInfo(this);
    objecStudentInfo->setFname(json_obj["fname"].toString());
    objecStudentInfo->setLname(json_obj["lname"].toString());
    objecStudentInfo->setEmail(json_obj["email"].toString());
    objecStudentInfo->show();
    reply->deleteLater();
    infoManager->deleteLater();
}


void StudentMenu::on_btnGrades_clicked()
{
    Grades *objectGrades=new Grades(this);
    objectGrades->setUsername(username);
    objectGrades->setWebtoken(webToken);
    objectGrades->show();
}

