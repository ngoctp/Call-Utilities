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

#include <QTimer>
#include <QDebug>

using namespace bb::system;
using namespace bb::system::phone;

Service::Service() :
        QObject()
{
    bb::system::phone::Phone *phone = new Phone(this);
    //phone->connect(phone, SIGNAL(callUpdatecallUpdated(bb::system::phone::Call)), this, SLOT(onCallUpdated(bb::system::phone::Call)));
    bool ok = connect(phone, SIGNAL(callUpdated(const bb::system::phone::Call &)), this, SLOT(onCallUpdated(const bb::system::phone::Call &)));
    qDebug() << "testttttttttttttttttttttttttttttttttttttttttt2 ";
    qDebug() << "testttttttttttttttttttttttttttttttttttttttttt3 " << ok;

}

void Service::onCallUpdated(const bb::system::phone::Call & call) {
    CallState::Type state = call.callState();
    qDebug() << "call updated: callId=" << call.callId() << " callState=" << state;
}

void Service::onIncomingDisconnect() {

}

void Service::onOutgoingConnect() {

}

void Service::onOutgoingDisconnect() {

}
