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

using namespace bb::system;
using namespace bb::system::phone;
using namespace bb::device;

Service::Service() :
        QObject()
{
    Phone * phone = new Phone(this);
    connect(phone, SIGNAL(callUpdated(const bb::system::phone::Call &)), this, SLOT(onCallUpdated(const bb::system::phone::Call &)));
}

void Service::onCallUpdated(const bb::system::phone::Call & call) {
    CallType::Type type = call.callType();
    CallState::Type state = call.callState();

    qDebug() << "call updated: callId=" << call.callId() << " callType=" << type << " callState=" << state;

    if (type == CallType::Incoming) {
        if (state == CallState::Disconnected) {
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

void Service::onIncomingDisconnect() {
    VibrationController vibration;
    vibration.start(100, 200);
}

void Service::onOutgoingConnect() {
    VibrationController vibration;
    vibration.start(100, 200);
}

void Service::onOutgoingDisconnect() {
    VibrationController vibration;
    vibration.start(100, 200);
}

