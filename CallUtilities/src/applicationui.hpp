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

#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <QDebug>

/*!
 * @brief Application UI object
 *
 * Use this object to create and init app UI, to create context objects, to register the new meta types etc.
 */
class ApplicationUI: public QObject
{
    Q_OBJECT
public:
    ApplicationUI();
    virtual ~ApplicationUI() { }

    Q_INVOKABLE QVariant getSetting(const QString & key);
    Q_INVOKABLE void setSetting(const QString & key, const QVariant & value);
    Q_INVOKABLE void test();

private:
    static const QString sAuthor;
    static const QString sApp;

    static const QString sIncomingDisconnectedVibrate;
    static const QString sOutgoingConnectedVibrate;
    static const QString sOutgoingDisconnectedVibrate;

};

#endif /* ApplicationUI_HPP_ */
