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

#include "cameraThread.h"

cameraThread::cameraThread()
{
  work = false;
}

void cameraThread::setWorkingThread(bool workThread)
{
    work = workThread;
}

void cameraThread::setCamId(int aCamId)
{
    camId = aCamId;
}

void cameraThread::run()
{
    Mat capturedImage;
    stream1 = new VideoCapture(camId);
    
    while(work)
    {
	*stream1 >> capturedImage;
	imshow("Real time video", capturedImage);
	resizeWindow("Real time video", 1500, 1000);
    }
    delete stream1;
}