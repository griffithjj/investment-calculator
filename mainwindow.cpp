#include "mainwindow.h"
#include <QLabel>
#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    m_InitialEdit(new QLineEdit),
    m_InterestEdit(new QLineEdit),
    m_PeriodEdit(new QLineEdit),
    m_ContributionEdit(new QLineEdit),
    m_ContributionIncreaseEdit(new QLineEdit),
    m_CalculateButton(new QPushButton("Calculate")),
    m_ResetButton(new QPushButton("Reset"))
{
    setup();
}

void MainWindow::setup(){

    QLabel* initialInvestmentLabel{new QLabel("Intitial Investment")};
    QLabel* interestLabel{new QLabel("Interest Rate")};
    QLabel* periodLabel{new QLabel("Investement Period (months)")};
    QLabel* contributionLabel{new QLabel("Monthly Contribution")};
    QLabel* contributionIncreaseLabel{new QLabel("Contribution Increase")};

    QWidget* centralWidget{new QWidget};
    QGridLayout* layout{new QGridLayout(this)};

    layout->addWidget(initialInvestmentLabel, 0,0);
    layout->addWidget(m_InitialEdit,1,0);
    layout->addWidget(interestLabel, 2,0);
    layout->addWidget(m_InterestEdit, 3,0);
    layout->addWidget(periodLabel,4,0);
    layout->addWidget(m_PeriodEdit, 5, 0);
    layout->addWidget(contributionLabel,6,0);
    layout->addWidget(m_ContributionEdit, 7, 0);
    layout->addWidget(contributionIncreaseLabel, 8, 0);
    layout->addWidget(m_ContributionIncreaseEdit, 9, 0);
    layout->addWidget(m_CalculateButton, 11, 0);
    layout->addWidget(m_ResetButton, 12, 0);

    centralWidget->setLayout(layout);

    this->setCentralWidget(centralWidget);
    this->adjustSize();
}

MainWindow::~MainWindow() {}
