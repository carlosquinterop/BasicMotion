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

#include "workerThread.h"

workerThread::workerThread()
{
  started = false;
  nActiveJoysticks = 0;
}

void workerThread::run()
{
  started = true;
  for (int i = 0; i < NMAXCONTROLLERS; i++)
  {
    joystick[i] = new JsController();
    joystick[i]->setId(i);
    joystick[i]->connectJs();
  }
          
  getnActiveJoysticks();
  
  while(started)
  {
    for (int i = 0; i < NMAXCONTROLLERS; i++)
    {
      if (joystick[i]->isActive)
      {
	if (joystick[i]->readJs() != -1)
	   emit updateJoystickAction(i, joystick[i]->axes);
      }
    }
  }
  for (int i = 0; i < NMAXCONTROLLERS; i++)
    joystick[i]->closeJs();
}


void workerThread::setStarted(bool aStarted)
{
    started = aStarted;
}

bool workerThread::getStarted()
{
    return started;
}

bool workerThread::isActive(int joystickIndex)
{
    if ((joystick[joystickIndex]->isActive) && (joystick[joystickIndex]->readJs() != -1))
      return true;
    else
      return false;
}

int workerThread::getnActiveJoysticks()
{
  nActiveJoysticks = 0;
  for (int i = 0;i < NMAXCONTROLLERS;i++)
  {
      if(joystick[i]->isActive)
	nActiveJoysticks++;
  }
  
  return nActiveJoysticks;
}
