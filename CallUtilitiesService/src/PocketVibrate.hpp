/*
 * PocketVibrate.h
 *
 *  Created on: Sep 13, 2014
 *      Author: NgocTP
 */

#ifndef POCKETVIBRATE_H_
#define POCKETVIBRATE_H_

#include <QObject>
#include <QThread>
#include <QDebug>

#include <QtSensors/QProximitySensor>
#include <QtSensors/QProximityReading>
#include <bb/device/VibrationController>

QTM_USE_NAMESPACE

namespace bb {
    namespace device {
        class VibrationController;
    }
}

using namespace bb::device;

class PocketVibrate: public QThread
{
    Q_OBJECT
public:
    PocketVibrate(QObject * parent = 0);
    virtual ~PocketVibrate();
    void run();
    void stop();

private slots:
    void proxReadingChanged();

private:
    bool enabled;
    QProximitySensor * senProx;
    VibrationController vibration;

};

#endif /* POCKETVIBRATE_H_ */
