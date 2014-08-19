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

import bb.cascades 1.2
import bb.device 1.2

Page {
    titleBar: TitleBar {
        title: "Call utilities"
    
    }
    Container {
        Label {
            text: "Incomming calls"
            textStyle.fontWeight: FontWeight.Bold
            horizontalAlignment: HorizontalAlignment.Center
            textFit.minFontSizeValue: 10.0
            textFit.maxFontSizeValue: 15.0
        
        }
        
        Container {
            horizontalAlignment: HorizontalAlignment.Fill
            rightPadding: 10.0
            leftPadding: 10.0
            Container {
                layout: DockLayout {
                
                }
                horizontalAlignment: HorizontalAlignment.Fill
                Label {
                    id: lblVibrateOnIncomingDisconnect
                    text: "Vibrate on disconnect"
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Left
                
                }
                ToggleButton {
                    horizontalAlignment: HorizontalAlignment.Right
                    onCheckedChanged: {
                        app.setSetting("IncomingDisconnectedVibrate", checked)
                    }

                    verticalAlignment: VerticalAlignment.Center
                    checked: app.getSetting("IncomingDisconnectedVibrate").toString()
                    accessibility.labelledBy: lblVibrateOnIncomingDisconnect

                }

            }
            Container {
                layout: DockLayout {

                }
                horizontalAlignment: HorizontalAlignment.Fill
                topMargin: 10.0
                Label {
                    id: lblFlashLedOnIncoming
                    text: "Flash LED"
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Left

                }
                ToggleButton {
                    horizontalAlignment: HorizontalAlignment.Right
                    onCheckedChanged: {
                        app.setSetting("IncomingFlashLed", checked)
                        ddbFlashLedColor.enabled = checked
                    }

                    verticalAlignment: VerticalAlignment.Center
                    checked: app.getSetting("IncomingFlashLed").toString()
                    topMargin: 10.0
                    accessibility.labelledBy: lblFlashLedOnIncoming

                }

            }
            Container {
                layout: DockLayout {

                }
                horizontalAlignment: HorizontalAlignment.Fill
                topMargin: 10.0
                DropDown {
                    id: ddbFlashLedColor
                    horizontalAlignment: HorizontalAlignment.Right
                    preferredWidth: 500.0
                    title: "Color"
                    onSelectedIndexChanged: {
                        app.setSetting("IncomingFlashLedColor", selectedValue)
                    }
                    enabled: app.getSetting("IncomingFlashLed").toString()
                    onCreationCompleted: {
                        var ledColor = app.getSetting("IncomingFlashLedColor");
                        var i, numOptions = count();
                        for (i = 0; i < numOptions; i++) {
                            if (options[i].value == ledColor) {
                                options[i].selected = true;
                                break;
                            }
                        }
                    }
                    Option {
                        text: "Rainbow"
                        value: LedColor.None
                        imageSource: "asset:///images/rainbow.png"
                        selected: true

                    }
                    Option {
                        text: "Red"
                        value: LedColor.Red
                        imageSource: "asset:///images/red.png"

                    }
                    Option {
                        text: "Green"
                        value: LedColor.Green
                        imageSource: "asset:///images/green.png"

                    }
                    Option {
                        text: "Blue"
                        value: LedColor.Blue
                        imageSource: "asset:///images/blue.png"

                    }
                    Option {
                        text: "Yellow"
                        value: LedColor.Yellow
                        imageSource: "asset:///images/yellow.png"

                    }
                    Option {
                        text: "Cyan"
                        value: LedColor.Cyan
                        imageSource: "asset:///images/cyan.png"

                    }
                    Option {
                        text: "Magenta"
                        value: LedColor.Magenta
                        imageSource: "asset:///images/magenta.png"

                    }
                    Option {
                        text: "White"
                        value: LedColor.White
                        imageSource: "asset:///images/white.png"

                    }

                }

            }

        }

        Divider {
            accessibility.name: "TODO: Add property content"

        }
        Label {
            text: "Outgoing calls"
            textStyle.fontWeight: FontWeight.Bold
            horizontalAlignment: HorizontalAlignment.Center
            textFit.minFontSizeValue: 10.0
            textFit.maxFontSizeValue: 15.0

        }

        Container {
            horizontalAlignment: HorizontalAlignment.Fill
            rightPadding: 10.0
            leftPadding: 10.0
            Container {
                horizontalAlignment: HorizontalAlignment.Fill
                layout: DockLayout {

                }
                Label {
                    id: lblVibrateOnOutgoingConnect
                    text: "Vibrate on connect"
                    verticalAlignment: VerticalAlignment.Center

                }
                ToggleButton {
                    horizontalAlignment: HorizontalAlignment.Right
                    onCheckedChanged: {
                        app.setSetting("OutgoingConnectedVibrate", checked)
                    }
                    verticalAlignment: VerticalAlignment.Center
                    checked: app.getSetting("OutgoingConnectedVibrate").toString()
                    accessibility.labelledBy: lblVibrateOnOutgoingConnect

                }

            }
            Container {
                layout: DockLayout {

                }
                horizontalAlignment: HorizontalAlignment.Fill
                topMargin: 10.0
                Label {
                    id: lblVibrateOnOutgoingDisconnect
                    text: "Vibrate on disconnect"
                    verticalAlignment: VerticalAlignment.Center

                }
                ToggleButton {
                    horizontalAlignment: HorizontalAlignment.Right
                    onCheckedChanged: {
                        app.setSetting("OutgoingDisconnectedVibrate", checked)
                    }
                    verticalAlignment: VerticalAlignment.Center
                    checked: app.getSetting("OutgoingDisconnectedVibrate").toString()
                    accessibility.labelledBy: lblVibrateOnOutgoingDisconnect

                }

            }

        }
        Divider {
            accessibility.name: "TODO: Add property content"

        }
        Button {
            text: "Close"
            horizontalAlignment: HorizontalAlignment.Center
            onClicked: {

            }
            visible: false

        }
    }
}
