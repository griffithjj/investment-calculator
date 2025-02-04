#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setup();

private:

    QLineEdit* m_InitialEdit;
    QLineEdit* m_InterestEdit;
    QLineEdit* m_PeriodEdit;
    QLineEdit* m_ContributionEdit;
    QLineEdit* m_ContributionIncreaseEdit;
    QPushButton* m_CalculateButton;
    QPushButton* m_ResetButton;
};
#endif // MAINWINDOW_H
