#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QDebug>
#include <QDateTime>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , networkManager(new QNetworkAccessManager(this))
    , timer(new QTimer(this)) // Initialize the timer
{
    ui->setupUi(this);

    // Set Window Title Name
    setWindowTitle("Live Running Status of Train");

    // Remove icon from window title
    QPixmap transparentPixmap(1, 1);
    transparentPixmap.fill(Qt::transparent);
    setWindowIcon(QIcon(transparentPixmap));

    // Initialize QTableWidget
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setHorizontalHeaderLabels({"Station Name", "Distance", "Timing", "Delay", "Platform", "Halt", "Is Current Station"});

    // Connect signal and slot
    connect(ui->pushButtonFetch, &QPushButton::clicked, this, &MainWindow::on_pushButtonFetch_clicked);
    connect(networkManager, &QNetworkAccessManager::finished, this, &MainWindow::onNetworkReply);

    // Connect timer to the slot
    connect(timer, &QTimer::timeout, this, &MainWindow::updateCurrentTime);

    // Start the timer as stopped initially
    timer->stop();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonFetch_clicked()
{
    // Get the train number from the QLineEdit
    QString trainNumber = ui->lineEditTrainNumber->text().trimmed();

    // Check if train number is empty
    if (trainNumber.isEmpty()) {
        QMessageBox::critical(this, "Input Error", "Please enter a train number.");
        return;
    }

    // URL to fetch data from the API
    QString apiUrl = QString("https://rappid.in/apis/train.php?train_no=%1").arg(trainNumber);
    QUrl url(apiUrl);
    QNetworkRequest request(url);
    networkManager->get(request);

    // Display current date and time and start the timer
    updateCurrentTime(); // Update the time immediately
    timer->start(1000); // Start the timer to update every second
}

void MainWindow::onNetworkReply(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument jsonDoc = QJsonDocument::fromJson(responseData);
        if (jsonDoc.isNull() || !jsonDoc.isObject()) {
            QMessageBox::critical(this, "JSON Error", "Failed to parse JSON data.");
            timer->stop(); // Stop the timer if there's an error
            ui->labelCurrentDateTime->clear();  // Clear the label if there's an error
            return;
        }

        QJsonObject jsonObj = jsonDoc.object();
        if (!jsonObj["success"].toBool()) {
            QMessageBox::critical(this, "API Error", "API returned an error.");
            timer->stop(); // Stop the timer if there's an error
            ui->labelCurrentDateTime->clear();  // Clear the label if there's an error

            // Check for invalid train number and show a message box
            if (jsonObj.contains("error") && jsonObj["error"].toString().contains("Invalid Train Number", Qt::CaseInsensitive)) {
                QMessageBox::critical(this, "Invalid Train Number", "The entered train number is invalid. Please try again.");
            }
            return;
        }

        QString trainName = jsonObj["train_name"].toString();
        QString updatedTime = jsonObj["updated_time"].toString();
        QJsonArray dataArray = jsonObj["data"].toArray();

        // Clear previous data
        ui->tableWidget->setRowCount(0);

        // Populate table with new data
        for (const QJsonValue &value : dataArray) {
            QJsonObject obj = value.toObject();
            int row = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(row);

            ui->tableWidget->setItem(row, 0, new QTableWidgetItem(obj["station_name"].toString()));
            ui->tableWidget->setItem(row, 1, new QTableWidgetItem(obj["distance"].toString()));

            // Format the timing string to insert spaces
            QString timing = obj["timing"].toString();
            timing.insert(5, ' ');  // Add space between two timings at position 5
            ui->tableWidget->setItem(row, 2, new QTableWidgetItem(timing));

            ui->tableWidget->setItem(row, 3, new QTableWidgetItem(obj["delay"].toString()));
            ui->tableWidget->setItem(row, 4, new QTableWidgetItem(obj["platform"].toString()));
            ui->tableWidget->setItem(row, 5, new QTableWidgetItem(obj["halt"].toString()));
            ui->tableWidget->setItem(row, 6, new QTableWidgetItem(obj["is_current_station"].toBool() ? "Yes" : "No"));

            // Set the background color of the row to green if the train has reached the current station
            if (obj["is_current_station"].toBool()) {
                for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
                    ui->tableWidget->item(row, col)->setBackground(Qt::green);
                }
            }
        }

        // Adjust column width
        ui->tableWidget->resizeColumnsToContents();

        // Display additional information (train name and updated time)
        ui->labelTrainName->setText(trainName);
        ui->labelUpdatedTime->setText(updatedTime);

    } else {
        QMessageBox::critical(this, "Network Error", reply->errorString());
        timer->stop(); // Stop the timer if there's an error
        ui->labelCurrentDateTime->clear();  // Clear the label if there's an error
    }
    reply->deleteLater();
}

void MainWindow::updateCurrentTime()
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");
    ui->labelCurrentDateTime->setText("Current Date and Time: " + currentDateTime);
}
