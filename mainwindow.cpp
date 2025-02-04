#include "mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_InitialEdit(new QLineEdit),
    m_InterestEdit(new QLineEdit),
    m_PeriodEdit(new QLineEdit),
    m_ContributionEdit(new QLineEdit),
    m_ContributionIncreaseEdit(new QLineEdit),
    m_CalculateButton(new QPushButton("Calculate")),
    m_ResetButton(new QPushButton("Reset"))
{}

void MainWindow::setup(){

    QLabel* initialInvestmentLabel{new QLabel("Intitial Investment")};
    QLabel* interestLabel{new QLabel("Interest Rate")};
    QLabel* periodLabel{new QLabel("Investement Period (months)")};
    QLabel* contributionLabel{new QLabel("Monthly Contribution")};
    QLabel* contributionIncreaseLabel{new QLabel("Contribution Increase")};
}

MainWindow::~MainWindow() {}
