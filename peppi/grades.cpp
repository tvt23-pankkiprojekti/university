#include "environment.h"
#include "grades.h"
#include "ui_grades.h"

Grades::Grades(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grades)
{
    ui->setupUi(this);
}

Grades::~Grades()
{
    delete ui;
}

void Grades::setUsername(const QString &newUsername)
{
    username = newUsername;
    ui->labelUsername->setText(username);
}

void Grades::setWebtoken(const QByteArray &newWebtoken)
{
    webtoken = newWebtoken;
}

void Grades::on_btnShowGrades_clicked()
{
    QString site_url=Environment::getBaseUrl()+"/studentgrade/"+username;
    QNetworkRequest request((site_url));
    //WEBTOKEN ALKU
    QByteArray myToken="Bearer "+webtoken;
    request.setRawHeader(QByteArray("Authorization"),(myToken));
    //WEBTOKEN LOPPU
    getManager = new QNetworkAccessManager(this);

    connect(getManager, SIGNAL(finished (QNetworkReply*)), this, SLOT(gradeSlot(QNetworkReply*)));

    reply = getManager->get(request);
}

void Grades::gradeSlot(QNetworkReply *reply)
{
    response_data=reply->readAll();
    qDebug()<<response_data;
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString grades;
    grades="Kurssi | opintopisteet | arvosana | suoritus pvm \r";
    foreach (const QJsonValue &value, json_array) {
        QJsonObject json_obj = value.toObject();
        grades+=json_obj["course_name"].toString()+" | ";
        grades+=QString::number(json_obj["gredit_points"].toInt())+" | ";
        grades+=QString::number(json_obj["grade"].toInt())+" | ";
        grades+=json_obj["grade_date"].toString();
        grades+="\r";
    }
    ui->textGrades->setText(grades);

    reply->deleteLater();
    getManager->deleteLater();
}

