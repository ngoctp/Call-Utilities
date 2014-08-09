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

#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>

#include <QSettings>

using namespace bb::cascades;

const QString ApplicationUI::sAuthor = "Mission";
const QString ApplicationUI::sApp = "CallUtilities";

const QString ApplicationUI::sIncomingDisconnectedVibrate = "IncomingDisconnectedVibrate";
const QString ApplicationUI::sOutgoingConnectedVibrate = "OutgoingConnectedVibrate";
const QString ApplicationUI::sOutgoingDisconnectedVibrate = "OutgoingDisconnectedVibrate";

ApplicationUI::ApplicationUI() :
        QObject()
{
    // Create scene document from main.qml asset, the parent is set
    // to ensure the document gets destroyed properly at shut down.
    QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    // Make app available to the qml.
    qml->setContextProperty("app", this);

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();

    // Set created root object as the application scene
    Application::instance()->setScene(root);
}

QVariant ApplicationUI::getSetting(const QString & key)
{
    QSettings settings(sAuthor, sApp);
    return settings.value(key);
}

void ApplicationUI::setSetting(const QString & key, const QVariant & value)
{
    QSettings settings(sAuthor, sApp);
    settings.setValue(key, value);
}

