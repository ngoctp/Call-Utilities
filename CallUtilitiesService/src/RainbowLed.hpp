/*
 * RainbowLed.h
 *
 *  Created on: Aug 14, 2014
 *      Author: NgocTP
 */

#ifndef RAINBOWLED_H_
#define RAINBOWLED_H_

#include <QObject>
#include <QThread>

#include <bb/device/Led>
#include <bb/device/LedColor>

namespace bb {
    namespace device {
        class Led;
        class LedColor;
    }
}

class RainbowLed: public QThread
{
    Q_OBJECT
public:
    RainbowLed(QObject * parent = 0);
    virtual ~RainbowLed();
    void run();
    void stop();
    void setColor(bb::device::LedColor::Type);

private:
    bb::device::Led * led;
    bb::device::LedColor::Type _ledColor;

};

#endif /* RAINBOWLED_H_ */
