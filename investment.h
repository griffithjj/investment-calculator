#ifndef INVESTMENT_H
#define INVESTMENT_H

#include <QObject>

class Investment : public QObject
{
    Q_OBJECT
public:
    explicit Investment(QObject *parent = nullptr);

signals:

private:

    double m_Initial;
    double m_InterestEarned;
    double m_Principal;
    double m_InterestRate;
    double m_Contribution;
    double m_Increase;
};

#endif // INVESTMENT_H
