//======================================================================//
//  This software is free: you can redistribute it and/or modify        //
//  it under the terms of the GNU General Public License Version 3,     //
//  as published by the Free Software Foundation.                       //
//  This software is distributed in the hope that it will be useful,    //
//  but WITHOUT ANY WARRANTY; without even the implied warranty of      //
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE..  See the      //
//  GNU General Public License for more details.                        //
//  You should have received a copy of the GNU General Public License   //
//  Version 3 in the file COPYING that came with this distribution.     //
//  If not, see <http://www.gnu.org/licenses/>                          //
//======================================================================//
//                                                                      //
//      Copyright (c) 2015 STOx's Small Size League RoboCup Team        //             
//      Universidad Santo Tomas - Bogota, Colombia                      //
//      http://www.stoxs.org/                                           //
//      small-size@stoxs.org                                            //
//                                                                      //
//======================================================================//

#ifndef JSCONTROLLER_H
#define JSCONTROLLER_H

#include <string>
using namespace std;

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "linux/joystick.h"
#include "sys/ioctl.h"

#include <QWidget>

class JsController
{
public:
   JsController();
   void setId(int id);
   void connectJs();
   int getNumAxes();
   int getNumButtons();
   string getName();
   int readJs();
   void antiRebound();
   void rumble(int strong, int weak, int duration);
   void closeJs();

   bool isActive;
   int inactiveCount;
   int axes[30];
   char rawButtons[20];
   char buttons[20];

private:
   struct js_event js;
   int newId;
   char jsConn;
   char jsEvent;
   string nameJoystick;
   int numAxes;
   int numButtons;
   char _buttons[20]; 
};

#endif // JSCONTROLLER_H