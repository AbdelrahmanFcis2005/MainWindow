#include "mainwindow.h"
#include <qscrollarea.h>
#include <QIcon>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    this->setWindowTitle("Digital Wallet");
    this->setWindowIcon(QIcon("icon.png"));
    QScrollArea* scrollarea = new QScrollArea(this);
    scrollarea->setWidgetResizable(true);
    toggleBtn = new QPushButton;
    toggleBtn->setCheckable(true);
    toggleBtn->setFixedSize(35, 35);
    toggleBtn->setIcon(QIcon("light.svg"));
    toggleBtn->setIconSize(QSize(30, 30));
    toggleBtn->setStyleSheet("background-color: white; border:none;");
    QHBoxLayout* topBarLayout = new QHBoxLayout;
    topBarLayout->addWidget(toggleBtn);

    QFormLayout* formLayout = new QFormLayout;

    QLabel* logoLabel = new QLabel;
    QPixmap logoPixmap("ASUPAL.png");
    logoPixmap = logoPixmap.scaledToWidth(185, Qt::SmoothTransformation);
    logoLabel->setPixmap(logoPixmap);

    nameLineEdit = new QLineEdit;
    nameLineEdit->setPlaceholderText("Full Name");

    emailLineEdit = new QLineEdit;
    emailLineEdit->setPlaceholderText("Email");

    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    
    nameLineEdit->setStyleSheet("border: 1.2px solid #ccc; border-radius: 4px; padding: 6px; height: 40px;margin:15px");
    emailLineEdit->setStyleSheet("border: 1.2px solid #ccc; border-radius: 4px; padding: 6px; height: 40px;margin:15px");
    passwordLineEdit->setStyleSheet("border: 1.2px solid #ccc; border-radius: 4px; padding: 6px; height: 40px;margin:15px");

    formLayout->addWidget(nameLineEdit);
    formLayout->addWidget(emailLineEdit);
    formLayout->addWidget(passwordLineEdit);

    loginButton = new QPushButton("Log In");
    loginButton->setStyleSheet("background-color: #0078D7; font:20px;border: 1.2px solid #0078D7; color: white; padding: 8px 6px; border-radius: 15px; margin:auto; margin-bottom:5px");
    
    QPushButton* signButton = new QPushButton("Sign In");
    signButton->setStyleSheet("background-color: white; font:20px; color: #0078D7; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px; margin:auto; margin-top:5px");

    QLabel* orLabel = new QLabel("-----------------( or )-----------------");
    orLabel->setStyleSheet("color: #666; font-size: 26px;border: 1.2px solid white;");

    formLayout->addWidget(loginButton);
    formLayout->addWidget(orLabel);
    formLayout->addWidget(signButton);

    QWidget* formContainer = new QWidget;
    formContainer->setLayout(formLayout);
    formContainer->setFixedWidth(500);
    formContainer->setStyleSheet("background-color: white;border: 1.2px solid #ccc; border-radius: 12px; padding: 25px;");

    QVBoxLayout* loginLayout = new QVBoxLayout;
    loginLayout->addWidget(logoLabel, 0, Qt::AlignHCenter);
    loginLayout->addSpacing(10);
    loginLayout->addWidget(formContainer, 0, Qt::AlignHCenter);
    loginLayout->addStretch();

    QWidget* loginPage = new QWidget;
    loginPage->setLayout(loginLayout);

    pagesWidget = new QStackedWidget;
    pagesWidget->addWidget(loginPage); 
    pagesWidget->setCurrentWidget(loginPage);

    QVBoxLayout* mainLayoutGlobal = new QVBoxLayout;
    mainLayoutGlobal->addLayout(topBarLayout, Qt::AlignHCenter);
    mainLayoutGlobal->addWidget(pagesWidget);
    
    QWidget* centralWidget = new QWidget;
    centralWidget->setLayout(mainLayoutGlobal);
    centralWidget->setStyleSheet("background-color: white");
    scrollarea->setWidget(centralWidget);
    this->setCentralWidget(scrollarea);

    connect(toggleBtn, &QPushButton::toggled, scrollarea, [=](bool checked) {
        if (pagesWidget->currentWidget() == loginPage) {
            if (checked) {
                toggleBtn->setIcon(QIcon("dark.svg"));
                toggleBtn->setStyleSheet("background-color: #2c2c2c; border:none");
                centralWidget->setStyleSheet("background-color: #2c2c2c");
                formContainer->setStyleSheet("background-color: #2c2c2c;border: 1.2px solid #0078D7; border-radius: 12px; padding: 25px;");
                nameLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px;margin:15px");
                emailLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px;margin:15px");
                passwordLineEdit->setStyleSheet("border: 1.2px solid #0078D7; border-radius: 4px; padding: 6px; height: 40px;margin:15px");
                signButton->setStyleSheet("background-color: #2c2c2c; font:20px; color: #0078D7; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px; margin:auto; margin-top:5px");
                orLabel->setStyleSheet("color: #666; font-size: 26px;border: 1.2px solid #2c2c2c;");
            }
            else {
                toggleBtn->setIcon(QIcon("light.svg"));
                toggleBtn->setStyleSheet("background-color: white; color: #333; border:none");
                centralWidget->setStyleSheet("background-color: white; color: #333;");
                formContainer->setStyleSheet("background-color: white;border: 1.2px solid #ccc; border-radius: 12px; padding: 25px;");
                nameLineEdit->setStyleSheet("border: 1.2px solid #ccc; border-radius: 4px; padding: 6px; height: 40px;margin:15px");
                emailLineEdit->setStyleSheet("border: 1.2px solid #ccc; border-radius: 4px; padding: 6px; height: 40px;margin:15px");
                passwordLineEdit->setStyleSheet("border: 1.2px solid #ccc; border-radius: 4px; padding: 6px; height: 40px;margin:15px");
                signButton->setStyleSheet("background-color: white; font:20px; color: #0078D7; border: 1.2px solid #0078D7; padding: 8px 6px; border-radius: 15px; margin:auto; margin-top:5px");
                orLabel->setStyleSheet("color: #666; font-size: 26px;border: 1.2px solid white;");
            }
        }
        });

    connect(loginButton, &QPushButton::clicked, scrollarea, [=]() {
        showHomePage();
        });
}

void MainWindow::showHomePage() {
    QWidget* homePage = new QWidget;
    QLabel* welcomeLabel = new QLabel("Welcome to Home Page!");
    welcomeLabel->setStyleSheet("font-size: 24px; color: #0078D7;");
    QVBoxLayout* layout = new QVBoxLayout(homePage);
    layout->addWidget(welcomeLabel, 0, Qt::AlignCenter);
    homePage->setLayout(layout);
    pagesWidget->addWidget(homePage);
    pagesWidget->setCurrentWidget(homePage);
}
MainWindow::~MainWindow()
{

}
//void MainWindow::readFromFile(User &user)
//{
//    User::readFromFile("user.txt", user);
//	QMessageBox msgBox;
//	msgBox.setText("User data read from file:");
//	msgBox.setInformativeText("Name: " + user.getName() + "\nEmail: " + user.getEmail() + "\nPassword: " + user.getPassword());
//	msgBox.setStandardButtons(QMessageBox::Ok);
//    msgBox.setWindowIcon(QIcon("icon.png"));
// 
//    msgBox.exec();
//}

//void MainWindow::showHomePage()
//{
//    QWidget* oldCentral = this->centralWidget();
//    if (oldCentral) {
//        oldCentral->deleteLater();
//    }
//
//    QWidget* homeWidget = new QWidget(this);
//    QVBoxLayout* layout = new QVBoxLayout(homeWidget);
//
//    QLabel* welcomeLabel = new QLabel("Welcome, " + user.getName());
//    welcomeLabel->setStyleSheet("font-size: 24px; color: #0078D7;");
//    layout->addWidget(welcomeLabel, 0, Qt::AlignCenter);
//
//    QPushButton* logoutButton = new QPushButton("Log out");
//    logoutButton->setStyleSheet("padding: 10px 20px; font-size: 16px;");
//    layout->addWidget(logoutButton, 0, Qt::AlignCenter);
//
//    connect(logoutButton, &QPushButton::clicked, this, [this]() {
//        QMessageBox::information(this, "Logout", "Logged out successfully!");
//        qApp->exit();
//        });
//    this->setCentralWidget(homeWidget);
//
//}