/*
 * PocketVibrate.cpp
 *
 *  Created on: Sep 13, 2014
 *      Author: NgocTP
 */

#include <src/PocketVibrate.hpp>

using namespace bb::device;

PocketVibrate::PocketVibrate(QObject * parent)
    : QThread(parent),
      enabled(),
      senProx(new QProximitySensor(this))
{
    qDebug() << "start pocketvibrate";
    connect(senProx, SIGNAL(readingChanged()), this, SLOT(proxReadingChanged()));
    senProx->setAlwaysOn(true);
    senProx->setSkipDuplicates(true);
}

PocketVibrate::~PocketVibrate()
{
}

void PocketVibrate::run() {
    qDebug() << "senProx->start(): " << senProx->start();
}

void PocketVibrate::proxReadingChanged() {
    QProximityReading * reading = senProx->reading();
    if (reading->close()) {
        qDebug() << "closeeeeeeeeeeeee";
        senProx->stop();

        enabled = true;
        do {
            msleep(10);
            vibration.stop();
            qDebug() << "stoppedddddddddddddd";
            break;
            vibration.start(100, 750);
            msleep(1250);
        }
        while (enabled);
    }
}

void PocketVibrate::stop() {
    senProx->stop();
    vibration.stop();
    enabled = false;
}
