/**
 * @file main.cpp
 * @author Linming Pan
 * @date 6.11.2018
 * @brief Example code to run simple QT
 *
 */


#include <QApplication>
#include "main_window_example.hpp"


int main(int argc, char *argv[])
{
    // Start QT Application
    QApplication app(argc, argv);

    // Setup out example class
    MainWindowExample *win = new MainWindowExample();
    win->show();
    return app.exec();
}
