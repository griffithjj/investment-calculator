#include "mainwindow.h"
#include <QLabel>
#include <QGridLayout>
#include <QtCharts/QtCharts>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent),
    m_InitialEdit(new QLineEdit),
    m_InterestEdit(new QLineEdit),
    m_PeriodEdit(new QLineEdit),
    m_ContributionEdit(new QLineEdit),
    m_ContributionIncreaseEdit(new QLineEdit),
    m_CalculateButton(new QPushButton("Calculate")),
    m_ResetButton(new QPushButton("Reset")),
    m_SummaryLabel(new QLabel(""))
{
    setup();

    m_CalculateButton->setDefault(true);
    m_ResetButton->setAutoDefault(true);
    connect(m_CalculateButton, &QPushButton::clicked, this, &MainWindow::calculateInvestment);
    connect(m_ResetButton, &QPushButton::clicked, this, &MainWindow::resetForm);
}

void MainWindow::setup(){

    QLabel* initialInvestmentLabel{new QLabel("Intitial Investment")};
    QLabel* interestLabel{new QLabel("Interest Rate (%)")};
    QLabel* periodLabel{new QLabel("Investement Period (months)")};
    QLabel* contributionLabel{new QLabel("Monthly Contribution")};
    QLabel* contributionIncreaseLabel{new QLabel("Contribution Increase (%)")};

    QGridLayout* layout{new QGridLayout(this)};

    layout->addWidget(initialInvestmentLabel, 0,0,1,3);
    layout->addWidget(m_InitialEdit,1,0,1,3);
    layout->addWidget(interestLabel, 2,0,1,3);
    layout->addWidget(m_InterestEdit, 3,0,1,3);
    layout->addWidget(periodLabel,4,0,1,3);
    layout->addWidget(m_PeriodEdit, 5, 0,1,3);
    layout->addWidget(contributionLabel,6,0,1,3);
    layout->addWidget(m_ContributionEdit, 7, 0,1,3);
    layout->addWidget(contributionIncreaseLabel, 8, 0,1,3);
    layout->addWidget(m_ContributionIncreaseEdit, 9, 0,1,3);
    layout->addWidget(m_CalculateButton, 11, 0,1,3);
    layout->addWidget(m_ResetButton, 12, 0,1,3);

    layout->addWidget(setupGraph(), 0, 3, 6,6);
    layout->addWidget(m_SummaryLabel, 6, 3, 6, 6);

    this->setLayout(layout);
    this->adjustSize();
}

QChartView* MainWindow::setupGraph()
{
    // QBarSet* set1{new QBarSet("Investment")};
    auto set1 = new QBarSet("Investment");
    *set1 << 1 << 2 << 3 << 4 << 5 << 6;

    QBarSeries* series{new QBarSeries};
    series->append(set1);

    QChart* chart{new QChart};
    chart->addSeries(series);
    chart->setTitle("Simple bar chart");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories{"Jan", "Feb", "Mar", "Apr", "May", "Jun"};
    QBarCategoryAxis* axisX{new QBarCategoryAxis};
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis* axisY{new QValueAxis};
    axisY->setRange(0,15);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView* chartView{new QChartView(chart, this)};

    return chartView;
}

void MainWindow::calculateInvestment()
{
    double initial = m_InitialEdit->text().toDouble();
    double interestRate = m_InterestEdit->text().toDouble();
    int period = m_PeriodEdit->text().toInt();
    double contribution = m_ContributionEdit->text().toDouble();
    double increase = m_ContributionIncreaseEdit->text().toDouble();

    double totalContributions = initial;
    double investment = initial;

    for(int n = 0; n <= period; ++n){

        investment = (investment + contribution) * (1 + (interestRate*0.01)/12);
        totalContributions += contribution;

        if(n % 12 == 0){
            contribution = contribution * (1 + (increase*0.01));
        }
    }

    m_SummaryLabel->setText(QString::fromLatin1("You have contributed a total of %1, and your total investment is %2").arg(totalContributions).arg(investment));
}

void MainWindow::resetForm()
{
    m_InitialEdit->clear();
    m_InterestEdit->clear();
    m_PeriodEdit->clear();
    m_ContributionEdit->clear();
    m_ContributionIncreaseEdit->clear();
    m_SummaryLabel->clear();

    m_InitialEdit->setFocus();
}

MainWindow::~MainWindow() {}
