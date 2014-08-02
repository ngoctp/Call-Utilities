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
                    text: "Vibrate on disconnect"
                    verticalAlignment: VerticalAlignment.Center
                    horizontalAlignment: HorizontalAlignment.Left
                
                }
                ToggleButton {
                    id: tggVibrateOnIncomingDisconnect
                    horizontalAlignment: HorizontalAlignment.Right
                    onCheckedChanged: {
                    }
                    layoutProperties: StackLayoutProperties {
                    
                    }
                    verticalAlignment: VerticalAlignment.Center
                
                }
            
            }
        
        }
        
        Divider {
        
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
                    text: "Vibrate on connect"
                    verticalAlignment: VerticalAlignment.Center
                
                }
                ToggleButton {
                    id: tggVibrateOnOutgoingConnect
                    horizontalAlignment: HorizontalAlignment.Right
                    onCheckedChanged: {
                    }
                    verticalAlignment: VerticalAlignment.Center
                
                }
            
            }
            Container {
                layout: DockLayout {
                
                }
                horizontalAlignment: HorizontalAlignment.Fill
                topMargin: 10.0
                Label {
                    text: "Vibrate on disconnect"
                    verticalAlignment: VerticalAlignment.Center
                
                }
                ToggleButton {
                    id: tggVibrateOnOutgoingDisconnect
                    horizontalAlignment: HorizontalAlignment.Right
                    onCheckedChanged: {
                    }
                    verticalAlignment: VerticalAlignment.Center
                
                }
            
            }
        
        }
        Divider {
        
        }
        Button {
            text: "Close"
            horizontalAlignment: HorizontalAlignment.Center
        
        }
    }
}
