/**
 * @file main_window_example.hpp
 * @author Linming Pan
 * @date 6.11.2018
 * @brief Example code
 *
 */

#ifndef MAIN_WINDOW_EXAMPLE_HPP
#define MAIN_WINDOW_EXAMPLE_HPP

#include <QPushButton>
#include <QMainWindow>
#include <QMdiArea>

#include <ui_q_test.h>

class MainWindowExample : public QMainWindow
{
    //Q_OBJECT
public:
    MainWindowExample(QWidget *parent=0);

    void onRunClicked();

private:
    Ui::MainWindow ui_;
};

#endif