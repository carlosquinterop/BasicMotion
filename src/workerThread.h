/*
 * Copyright 2018 Carlos Quintero <quintero.carlos@uniandes.edu.co>
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <qt5/QtCore/QObject>
#include <QThread>
#include <iostream>
#include <QProcess>
#include "jscontroller.h"

#define NMAXCONTROLLERS 5

using namespace std;

class workerThread : public QThread
{
    Q_OBJECT
    
    void run();
public:
    workerThread();
    void setStarted(bool aStarted);
    bool getStarted();
    bool isActive(int joystickIndex);
    int getnActiveJoysticks();
private:
    JsController *joystick[NMAXCONTROLLERS];
    bool started;
    int nActiveJoysticks;
signals:
    void updateJoystickAction(int i, int* axes);
};

#endif // WORKERTHREAD_H