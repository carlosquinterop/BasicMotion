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

#ifndef CAMERATHREAD_H
#define CAMERATHREAD_H

#include <qt5/QtCore/QObject>
#include <opencv2/opencv.hpp>
#include <QThread>
#include <iostream>

using namespace cv;
using namespace std;

class cameraThread : public QThread
{
    Q_OBJECT
    
    void run();
public:
    cameraThread();
    void setWorkingThread(bool workThread);
    void setCamId(int aCamId);
    
private:
    VideoCapture *stream1;
    bool work;
    int camId;    
};

#endif // CAMERATHREAD_H