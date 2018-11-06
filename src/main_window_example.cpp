/**
 * @file main_window_example.cpp
 * @author Linming Pan
 * @date 6.11.2018
 * @brief Example code
 *
 */
#include <ui_q_test.h>
#include "main_window_example.hpp"


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
}

void MainWindowExample::onRunClicked()
{
    // Add text to text field in UI.
    ui_.plainTextEdit->appendPlainText("RUN");
}