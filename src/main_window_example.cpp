/**
 * @file main_window_example.cpp
 * @author Linming Pan
 * @date 6.11.2018
 * @brief Example code
 *
 */
#include <ui_q_test.h>
#include "main_window_example.hpp"
#include <QDebug>


MainWindowExample::MainWindowExample(QWidget *parent) 
    : QMainWindow(parent)
{
    // Setup ui from file q_test.ui
    ui_.setupUi(this);
    setWindowTitle("QMainWindow Example");

    // connect RUN button to a method
    connect(ui_.pushButton, &QPushButton::released, this, &MainWindowExample::onRunClicked);

    // Another method to connect button using lambda
    connect(ui_.pushButton_2, &QPushButton::released, [=](){ 
        ui_.plainTextEdit->appendPlainText("TEST");
    });

    // connect button next to spinbox
    connect(ui_.pushButton_3, &QPushButton::released, this, &MainWindowExample::onSpinboxButtonClicked);

    // connect spinbox value change with int or QString parameter
    connect(
        ui_.spinBox, static_cast<void(QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this, &MainWindowExample::onValueChanged
    );
    //connect(ui_.spinBox, static_cast<void(QSpinBox::*)(const QString &text)>(&QSpinBox::valueChanged), this, &MainWindowExample::onValueChanged);
}

void MainWindowExample::onRunClicked()
{
    // Add text to text field in UI.
    ui_.plainTextEdit->appendPlainText("RUN");
}

void MainWindowExample::onSpinboxButtonClicked()
{
    // Add text to text field in UI.
    QString value = QString::number(ui_.spinBox->value());
    ui_.plainTextEdit->appendPlainText("Value: "+ value);
}

void MainWindowExample::onValueChanged(int i)
{
    qDebug() << "change to:" << i ;
}