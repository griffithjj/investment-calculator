#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QChartView>
#include <QLabel>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setup();
    QChartView* setupGraph();

public slots:
    void calculateInvestment();
    void resetForm();

private:

    QLineEdit* m_InitialEdit;
    QLineEdit* m_InterestEdit;
    QLineEdit* m_PeriodEdit;
    QLineEdit* m_ContributionEdit;
    QLineEdit* m_ContributionIncreaseEdit;
    QPushButton* m_CalculateButton;
    QPushButton* m_ResetButton;
    QLabel* m_SummaryLabel;
};
#endif // MAINWINDOW_H
