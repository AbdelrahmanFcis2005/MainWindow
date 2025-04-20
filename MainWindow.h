#pragma once
#include <QMainWindow>
#include <QFormLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include "User.h"
#include <QPixmap>
#include <QIcon>
#include <qmessagebox.h>
#include <QApplication>
#include <QStackedWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
	~MainWindow();
	//void readFromFile(User &user);
    void showHomePage();
	void showLoginPage();

private:
	User user;
    QLineEdit* nameLineEdit;
    QLineEdit* emailLineEdit;
    QLineEdit* passwordLineEdit;
    QPushButton* loginButton;
    QStackedWidget* pagesWidget;
    QPushButton* toggleBtn;

};