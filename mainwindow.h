#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonFetch_clicked();
    void onNetworkReply(QNetworkReply *reply);
    void updateCurrentTime();

private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *networkManager;
    QTimer *timer; // Add the QTimer
};

#endif // MAINWINDOW_H
