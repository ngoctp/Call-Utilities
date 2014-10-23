/*
 * RainbowLed.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: NgocTP
 */

#include <src/RainbowLed.hpp>

#include <QDebug>

using namespace bb::device;

RainbowLed::RainbowLed(QObject * parent)
    : QThread(parent),
      led()
{
}

RainbowLed::~RainbowLed()
{
}

void RainbowLed::run() {
    if (led == NULL) {
        led = new Led();
    }
    // rainbow
    if (_ledColor == LedColor::None) {
        QVector<LedColor::Type> * ledColors = new QVector<LedColor::Type>();
        ledColors->append(LedColor::Red);
        ledColors->append(LedColor::Green);
        ledColors->append(LedColor::Blue);
        ledColors->append(LedColor::Yellow);
        ledColors->append(LedColor::Cyan);
        ledColors->append(LedColor::Magenta);
        ledColors->append(LedColor::White);
        int max = ledColors->size();
        int i = -1;
        do {
            i++;
            if (i == max) {
                i = 0;
            }
            led->setColor(ledColors->at(i));
            led->flash();
            msleep(200);

        }
        while (led->isActive());
    }
    // specific color
    else {
        led->setColor(_ledColor);
        led->flash();
    }
}

void RainbowLed::setColor(LedColor::Type ledColor) {
    _ledColor = ledColor;
}

void RainbowLed::stop() {
    led->setColor(LedColor::None);
}
