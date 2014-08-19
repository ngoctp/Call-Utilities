/*
 * Copyright (c) 2013-2014 BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "service.hpp"

#include <bb/Application>
#include <bb/system/phone/Phone>
#include <bb/system/phone/Call>
#include <bb/system/phone/CallType>
#include <bb/system/phone/CallState>
#include <bb/device/VibrationController>

#include <QTimer>
#include <QDebug>
#include <QSettings>
#include <QMetaObject>

using namespace bb::system;
using namespace bb::system::phone;
using namespace bb::device;

const QString Service::sAuthor = "Mission";
const QString Service::sApp = "CallUtilities";

const QString Service::sIncomingDisconnectedVibrate = "IncomingDisconnectedVibrate";
const QString Service::sIncomingFlashLed = "IncomingFlashLed";
const QString Service::sIncomingFlashLedColor = "IncomingFlashLedColor";
const QString Service::sOutgoingConnectedVibrate = "OutgoingConnectedVibrate";
const QString Service::sOutgoingDisconnectedVibrate = "OutgoingDisconnectedVibrate";

Service::Service() :
        QObject(),
        rainbowLed(new RainbowLed(this))
{
    QMetaObject::invokeMethod(this, "init", Qt::QueuedConnection);
    Phone * phone = new Phone(this);
    connect(phone, SIGNAL(callUpdated(const bb::system::phone::Call &)), this, SLOT(onCallUpdated(const bb::system::phone::Call &)));
}

void Service::init() {
    QSettings settings(sAuthor, sApp);
    if (!settings.contains(sIncomingDisconnectedVibrate)) {
        settings.setValue(sIncomingDisconnectedVibrate, true);
    }
    if (!settings.contains(sIncomingFlashLed)) {
        settings.setValue(sIncomingFlashLed, true);
    }
    if (!settings.contains(sIncomingFlashLedColor)) {
        settings.setValue(sIncomingFlashLedColor, LedColor::None);
    }
    if (!settings.contains(sOutgoingConnectedVibrate)) {
        settings.setValue(sOutgoingConnectedVibrate, true);
    }
    if (!settings.contains(sOutgoingDisconnectedVibrate)) {
        settings.setValue(sOutgoingDisconnectedVibrate, true);
    }
    settings.sync();
}

void Service::onCallUpdated(const bb::system::phone::Call & call) {
    CallType::Type type = call.callType();
    CallState::Type state = call.callState();

    if (type == CallType::Incoming) {
        if (state == CallState::Incoming) {
            onIncoming();
        }
        else if (state == CallState::Connected) {
            onIncomingConnect();
        }
        else if (state == CallState::Disconnected) {
            onIncomingDisconnect();
        }
    }
    else if (type == CallType::Outgoing) {
        if (state == CallState::Connected) {
            onOutgoingConnect();
        }
        else if (state == CallState::Disconnected) {
            onOutgoingDisconnect();
        }
    }

}

void Service::onIncoming() {
    QSettings settings(sAuthor, sApp);
    if (settings.value(sIncomingFlashLed).toBool()) {
        LedColor::Type ledColor = static_cast<LedColor::Type>(settings.value(sIncomingFlashLedColor).toInt());
        rainbowLed.setColor(ledColor);
        rainbowLed.start();
    }
}

void Service::onIncomingConnect() {
    // stop flashing Led
    rainbowLed.stop();
}

void Service::onIncomingDisconnect() {
    QSettings settings(sAuthor, sApp);
    if (settings.value(sIncomingDisconnectedVibrate).toBool()) {
        VibrationController vibration;
        vibration.start(100, 200);
    }

    // stop flashing Led
    rainbowLed.stop();

}

void Service::onOutgoingConnect() {
    QSettings settings(sAuthor, sApp);
    if (settings.value(sOutgoingConnectedVibrate).toBool()) {
        VibrationController vibration;
        vibration.start(100, 200);
    }

    // for testing
//    rainbowLed.setColor(LedColor::None);
//    rainbowLed.start();
}

void Service::onOutgoingDisconnect() {
    QSettings settings(sAuthor, sApp);
    if (settings.value(sOutgoingDisconnectedVibrate).toBool()) {
        VibrationController vibration;
        vibration.start(100, 200);
    }

    // for testing
//    rainbowLed.stop();
}

