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

#include "jscontroller.h"

JsController::JsController()
{
    isActive = false;
    inactiveCount = 0;
    memset(_buttons, 0, sizeof(_buttons));
    memset(buttons, 0, sizeof(buttons));
}

void JsController::setId(int id)
{
    newId = id;
}

void JsController::connectJs()
{
    char jsPath[16];
    snprintf(jsPath, sizeof(jsPath), "/dev/input/js%d", newId);
    jsConn = open(jsPath, O_NONBLOCK);
    if(jsConn != -1)
    {
	ioctl(jsConn, JSIOCGAXES, &numAxes);
	ioctl(jsConn, JSIOCGBUTTONS, &numButtons);
	ioctl(jsConn, JSIOCGNAME(80), nameJoystick.c_str());
	isActive = true;
	memset(_buttons, 0, sizeof(_buttons));
	memset(buttons, 0, sizeof(buttons));
    }
}

int JsController::getNumAxes()
{
    return numAxes;
}

int JsController::getNumButtons()
{
    return numButtons;
}

string JsController::getName()
{
    return nameJoystick;
}

int JsController::readJs()
{
    int readOk;
    readOk = read(jsConn, &js, 8);
    if(readOk != -1)
    {
        switch(js.type & ~JS_EVENT_INIT)
        {
            case JS_EVENT_AXIS:
                axes[js.number] = js.value;
                break;
            case JS_EVENT_BUTTON:
                rawButtons[js.number] = js.value;
                break;
        }
        antiRebound();
        inactiveCount = 0;
    }
    else
    {
	inactiveCount++;
    }
    return readOk;
}

void JsController::antiRebound()
{
    for(int i=0; i<20; i++)
    {
	if((_buttons[i] == 0) && (rawButtons[i] == 0))
	{
	    _buttons[i] = 0;
	    buttons[i] = 0;
	}
	else if((_buttons[i] == 0) && (rawButtons[i] == 1))
	{
	    _buttons[i] = 1;
	    buttons[i] = 0;
	}
	else if((_buttons[i] == 1) && (rawButtons[i] == 1))
	{
	    _buttons[i] = 2;
	    buttons[i] = 0;
	}
	else if((_buttons[i] == 2) && (rawButtons[i] == 0))
	{
	    _buttons[i] = 3;
	    buttons[i] = 1;
	}
	else if(_buttons[i] == 3)
	{
	    _buttons[i] = 0;
	    buttons[i] = 0;
	}
    }
}

void JsController::rumble(int strong, int weak, int duration)
{
    static struct ff_effect effects;
    static struct input_event play;
    char path[20];
    snprintf(path, sizeof(path), "/dev/input/event%d", 17+newId);
    jsEvent = open(path, O_RDWR);
    effects.type = FF_RUMBLE;
    effects.u.rumble.strong_magnitude = strong*65535/100;
    effects.u.rumble.weak_magnitude = weak*65535/100;
    effects.replay.length = duration;
    effects.replay.delay = 0;
    effects.id = -1;	/* ID must be set to -1 for every new effect */

    play.type = EV_FF;
    play.code = effects.id;
    play.value = 1;
    
    /* Effect intesity limits. */
    if (effects.u.rumble.strong_magnitude < 0)
	    effects.u.rumble.strong_magnitude=0;

    if (effects.u.rumble.strong_magnitude > 65535)
	    effects.u.rumble.strong_magnitude=65535;

    if (effects.u.rumble.weak_magnitude < 0)
	    effects.u.rumble.weak_magnitude=0;

    if (effects.u.rumble.weak_magnitude > 65535)
	    effects.u.rumble.weak_magnitude=65535;


    /* Send the effect to the driver */
    ioctl(jsEvent, EVIOCSFF, &effects);

    /* Play the effect */
    play.code = effects.id;

    write(jsEvent, (const void*) &play, sizeof(play));
    
    close(jsEvent);
}


void JsController::closeJs()
{
    fflush(stdout);
    close(jsConn);
    isActive = false;
}