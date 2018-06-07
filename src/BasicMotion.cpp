#include "BasicMotion.h"

BasicMotion::BasicMotion(int camId)
{
    //Widget constructors
    /////////////////////
    PClayout = new QGridLayout();
    controllerLayout = new QGridLayout();
    mainLayout = new QGridLayout();
    
    PCrobotId = new QComboBox();
    controller1RobotId = new QComboBox();
    controller2RobotId = new QComboBox();
    
    pcControl = new QCheckBox("PC Control");
    wirelessControl = new QCheckBox("Remote Control");
    
    rightWheelVel = new QLineEdit("0");
    leftWheelVel = new QLineEdit("0");
    
    moveButton = new QPushButton("Move");
    stopButton = new QPushButton("Stop");
    connectButton = new QPushButton("Serial Connection");
    synchButtonControllers = new QPushButton("Synch");
    startJoystickController = new QPushButton("Start");
    closeButton = new QPushButton("Close");
    
    steeringDial = new QDial();
    
    speedSlider = new QSlider();
    
    QWidget *window = new QWidget();
    
    //Other objects
    myThread = new workerThread();
    remoteConnectionController1 = new QProcess();
    sendCommandsTimer = new QTimer();
    showCommandsTimer = new QTimer();
    ///////////////////////////////////////
    
    
    //Add widgets
    //////////////////////////////////////
    
    //Add widgets to main layout
    mainLayout->addWidget(connectButton, 0, 0);
    mainLayout->addWidget(closeButton, 0, 1);
    mainLayout->addLayout(PClayout, 1, 0);
    mainLayout->addLayout(controllerLayout, 1, 1);
    
    //Add widgets to PC layout
    PClayout->addWidget(pcControl, 0, 0);
    PClayout->addWidget(new QLabel("Robot ID"), 1, 0);
    PClayout->addWidget(PCrobotId, 1, 1);
    PClayout->addWidget(new QLabel("Left Wheel"), 2, 0);
    PClayout->addWidget(new QLabel("Right Wheel"), 2, 1);  
    PClayout->addWidget(leftWheelVel, 3, 0);
    PClayout->addWidget(rightWheelVel, 3, 1);
    PClayout->addWidget(moveButton, 4, 0);
    PClayout->addWidget(stopButton, 4, 1);
    PClayout->addWidget(steeringDial, 5, 0);
    PClayout->addWidget(speedSlider, 5, 1);
    
    //Add widgets to Controllers layout
    controllerLayout->addWidget(wirelessControl, 0, 0);
    controllerLayout->addWidget(synchButtonControllers, 1, 0);
    controllerLayout->addWidget(startJoystickController, 2, 0);
    controllerLayout->addWidget(new QLabel("Controller 1"), 3, 0);
    controllerLayout->addWidget(new QLabel("Robot ID"), 4, 0);
    controllerLayout->addWidget(controller1RobotId, 4, 1);
    
    controllerLayout->addWidget(new QLabel("Controller 2"), 5, 0);
    controllerLayout->addWidget(new QLabel("Robot ID"), 6, 0);
    controllerLayout->addWidget(controller2RobotId, 6, 1);
    /////////////////////////////////////
    
    
    //Widget initializations   
    PCrobotId->addItem("0");
    PCrobotId->addItem("1");
    PCrobotId->addItem("2");
    PCrobotId->addItem("3");
    PCrobotId->addItem("4");
    PCrobotId->setCurrentIndex(1);
    
    controller1RobotId->addItem("0");
    controller1RobotId->addItem("1");
    controller1RobotId->addItem("2");
    controller1RobotId->addItem("3");
    controller1RobotId->addItem("4");
    controller1RobotId->setCurrentIndex(1);
    
    controller2RobotId->addItem("0");
    controller2RobotId->addItem("1");
    controller2RobotId->addItem("2");
    controller2RobotId->addItem("3");
    controller2RobotId->addItem("4");
    controller2RobotId->setCurrentIndex(4);
        
    leftWheelVel->setEnabled(false);
    rightWheelVel->setEnabled(false);
    moveButton->setEnabled(false);
    stopButton->setEnabled(false);
    connectButton->setEnabled(true);
    startJoystickController->setEnabled(false);
    
    pcControl->setChecked(false);
    wirelessControl->setChecked(true);
    steeringDial->setRange(-50, 50);
    steeringDial->setValue(0);
    
    speedSlider->setRange(-100, 100);
    speedSlider->setValue(0);
    steeringDial->setEnabled(false);
    speedSlider->setEnabled(false);
    
    speedController1 = 0;
    steeringController1 = 0;
    speedController2 = 0;
    steeringController2 = 0;
    nJoysticksConnected = 0;
    controllerSynch = false;
    
    window->setLayout(mainLayout);

    setCentralWidget(window);
    
    
    serialConnection = false;
    
    QObject::connect(moveButton, SIGNAL(clicked(bool)), this, SLOT(wheelMove()));
    QObject::connect(stopButton, SIGNAL(clicked(bool)), this, SLOT(stop()));
    QObject::connect(steeringDial, SIGNAL(valueChanged(int)), this, SLOT(robotMove()));
    QObject::connect(speedSlider, SIGNAL(valueChanged(int)), this, SLOT(robotMove()));
    QObject::connect(pcControl, SIGNAL(stateChanged(int)), this, SLOT(PCCheckBoxState(int)));
    QObject::connect(wirelessControl, SIGNAL(stateChanged(int)), this, SLOT(WirelessCheckBoxState(int)));
    QObject::connect(connectButton, SIGNAL(clicked()), this, SLOT(clickedConnectButton()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(clickedClosedButton()));
    QObject::connect(synchButtonControllers, SIGNAL(clicked()), this, SLOT(SynchButton()));
    QObject::connect(remoteConnectionController1, SIGNAL(started()), this, SLOT(processStarted()));
    QObject::connect(remoteConnectionController1, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(processEnded(int, QProcess::ExitStatus)));
    QObject::connect(remoteConnectionController1, SIGNAL(readyReadStandardOutput()),this, SLOT(readyReadStandardOutput1()));
    QObject::connect(startJoystickController,SIGNAL(clicked()),this,SLOT(startJoystickSlot()));
    QObject::connect(myThread,SIGNAL(updateJoystickAction(int, int*)),this, SLOT(updateControllerCommands(int, int*)));
    QObject::connect(sendCommandsTimer,SIGNAL(timeout()),this, SLOT(sendControllerCommands()));
    QObject::connect(showCommandsTimer,SIGNAL(timeout()),this, SLOT(showControllerCommands()));
    
    /*camThread = new cameraThread();
    camThread->setWorkingThread(true);
    camThread->setCamId(camId);
    camThread->start();
    namedWindow("Real time video", WINDOW_NORMAL);   
    */
    
    myThread->start();
}

BasicMotion::~BasicMotion()
{
    
}

void BasicMotion::closeEvent(QCloseEvent* event)
{
    if(serialPort->isOpen())
    {
	serialPort->write(buildAllRobotsStopPacket());
        serialPort->close();
	serialConnection = false;
    }
    if (controllerSynch)
      remoteConnectionController1->kill();
    myThread->exit();
    QWidget::closeEvent(event);
    //camThread->setWorkingThread(false);
    //destroyWindow("Real time video");
    //camThread->exit();
}


int BasicMotion::openSerialPort(QString port)
{
    serialPort->setPortName(port);
    serialPort->setBaudRate(QSerialPort::Baud19200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    if(serialPort->open(QIODevice::ReadWrite)) 
    {
      serialConnection = true;
      cout << "Connected to Serial Hub" << endl;
       return 0;
    } 
    else 
    {
        QMessageBox msgBox;
	msgBox.setText(QString("Error openning %1").arg(port));
	msgBox.setIcon(QMessageBox::Critical);
	msgBox.exec();
	return 1;
    }
}

QByteArray BasicMotion::buildAllRobotsStopPacket()
{
    QByteArray data;
    data[0] = 0x00;
    for(int i=1; i<11; i++)
	data[i] = 0x7F;
    data[11] = 0x00;
    return data;
}

void BasicMotion::sendRobotVelMultipleRobots(int *id, int *rightVel, int *leftVel)
{
    for (int i = 0; i < 2; i++)
    {
      if(id[i] != -1)
      {
	data[(2*id[i])+1] = rightVel[i];
	data[(2*id[i])+2] = leftVel[i];
      }
    }
    if(serialPort->isOpen())
      serialPort->write(data);
}

void BasicMotion::sendRobotVelOneRobot(int id, int rightVel, int leftVel)
{
    data[(2*id)+1] = rightVel;
    data[(2*id)+2] = leftVel;
    if(serialPort->isOpen())
      serialPort->write(data);
}

float* BasicMotion::robotInverseKinematic(float v, float w)
{
    float *wheelVels = (float*)(malloc(sizeof(float)*2));;
    float L = 0.1;
    float R = 0.025;
    float K = 3.175;
    wheelVels[0] = (int)(((2*v + w*L)/(2*R))*K);
    wheelVels[1] = (int)(((2*v - w*L)/(2*R))*K);
    return wheelVels;
}

void BasicMotion::wheelMove()
{
   int right = rightWheelVel->text().toInt();
   if(right > 127)
       right = 127;
   else if(right < -127)
       right = -127;
   int left = leftWheelVel->text().toInt();
   if(left > 127)
       left = 127;
   else if(left < -127)
       left = -127;
   sendRobotVelOneRobot(PCrobotId->currentIndex(), right+0x7F, left+0x7F);
}

void BasicMotion::stop()
{
    data = buildAllRobotsStopPacket();
    if(serialPort->isOpen())
      serialPort->write(data);
}

void BasicMotion::robotMove()
{	
    float v = (float)(speedSlider->value())/100;
    float w = (float)(steeringDial->value())*(3*M_PI_4)/50;
    float *wheelVels = robotInverseKinematic(v, w);
    sendRobotVelOneRobot(PCrobotId->currentIndex(), (int)(wheelVels[0])+0x7F, (int)(wheelVels[1])+0x7F);
}

void BasicMotion::robotMove2()
{
    int leftVels[2], rightVels[2];
    int activeId[2];
    memset(activeId, -1, sizeof(int)*2);
    nJoysticksConnected = myThread->getnActiveJoysticks();
    if (nJoysticksConnected > 0)
    {
	float v = (float)(speedController1)/70000;
	float w = (float)(steeringController1)*(3*M_PI_4)/70000;
	float *wheelVels = robotInverseKinematic(v, w);
	leftVels[0] = (int)(wheelVels[1]) + 0x7F;
	rightVels[0] = (int)(wheelVels[0]) + 0x7F;
	activeId[0] = controller1RobotId->currentIndex();
    }
    
    if (nJoysticksConnected > 1)
    {
	float v = (float)(speedController2)/60000;
	float w = (float)(steeringController2)*(3*M_PI_4)/60000;
	float *wheelVels = robotInverseKinematic(v, w);
	leftVels[1] = (int)(wheelVels[1]) + 0x7F;
	rightVels[1] = (int)(wheelVels[0]) + 0x7F;
	activeId[1] = controller2RobotId->currentIndex();
    }
    if (nJoysticksConnected > 0)
      sendRobotVelMultipleRobots(activeId, rightVels, leftVels);
}

void BasicMotion::PCCheckBoxState(int state)
{
  if(pcControl->isChecked())
  {
      wirelessControl->setChecked(false);
      leftWheelVel->setEnabled(true);
      rightWheelVel->setEnabled(true);
      moveButton->setEnabled(true);
      stopButton->setEnabled(true);
      steeringDial->setEnabled(true);
      speedSlider->setEnabled(true);
      synchButtonControllers->setEnabled(false);
  }
  else
  {
      wirelessControl->setChecked(true);
      leftWheelVel->setEnabled(false);
      rightWheelVel->setEnabled(false);
      moveButton->setEnabled(false);
      stopButton->setEnabled(false);
      steeringDial->setEnabled(false);
      speedSlider->setEnabled(false);
      synchButtonControllers->setEnabled(true);
  }
}

void BasicMotion::WirelessCheckBoxState(int state)
{
  if(!wirelessControl->isChecked())
  {
      pcControl->setChecked(true);
      leftWheelVel->setEnabled(true);
      rightWheelVel->setEnabled(true);
      moveButton->setEnabled(true);
      stopButton->setEnabled(true);
      steeringDial->setEnabled(true);
      speedSlider->setEnabled(true);
      synchButtonControllers->setEnabled(false);
  }
  else
  {
      pcControl->setChecked(false);
      leftWheelVel->setEnabled(false);
      rightWheelVel->setEnabled(false);
      moveButton->setEnabled(false);
      stopButton->setEnabled(false);
      steeringDial->setEnabled(false);
      speedSlider->setEnabled(false);
      synchButtonControllers->setEnabled(true);
  }
}

void BasicMotion::clickedConnectButton()
{
    if (connectButton->text() == "Serial Connection")
    {
      serialPort = new QSerialPort();
      if (!openSerialPort("ttyUSB0"))
      {
	connectButton->setText("Disconnect");
	data = buildAllRobotsStopPacket();
      }
    }
    else if (connectButton->text() == "Disconnect")
    {
      if(serialPort->isOpen())
      {
	serialPort->write(buildAllRobotsStopPacket());
        serialPort->close();
	connectButton->setText("Serial Connection");
	serialConnection = false;
      } 
    }
}

void BasicMotion::SynchButton()
{
    if(synchButtonControllers->text() == "Synch")
      remoteConnectionController1->start("ds4drv");
    else if (synchButtonControllers->text() == "Stop synch")
      remoteConnectionController1->kill();
      
}

void BasicMotion::processStarted()
{
    cout << "Process ds4drv Started" << endl;
    synchButtonControllers->setText("Stop synch");
    controllerSynch = true;
    startJoystickController->setEnabled(true);
}

void BasicMotion::processEnded(int exitCode, QProcess::ExitStatus ExitStatus)
{
    cout << "Process ds4drv ended" << endl;
    synchButtonControllers->setText("Synch");
    controllerSynch = false;
    if (startJoystickController->text() == "Stop")
    {
	myThread->setStarted(false);
	startJoystickController->setText("Start");
	sendCommandsTimer->stop();
	
    }
    startJoystickController->setEnabled(false);
}

void BasicMotion::readyReadStandardOutput1()
{
    mOutputString1 = remoteConnectionController1->readAllStandardOutput();
    cout << mOutputString1.toStdString() << endl;
}

void BasicMotion::startJoystickSlot()
{
    if (serialConnection)
    {
      if(startJoystickController->text() == "Start")
      {
	  myThread->setStarted(true);
	  //myThread->start();
	  startJoystickController->setText("Stop");
	  sendCommandsTimer->start(sendCommandsTime);
      }
      else if (startJoystickController->text() == "Stop")
      {
	  myThread->setStarted(false);
	  //myThread->exit();
	  startJoystickController->setText("Start");
	  sendCommandsTimer->stop();
      }
    }
    else
    {
	if(startJoystickController->text() == "Start")
	{
	    myThread->setStarted(true);
	    //myThread->start();
	    startJoystickController->setText("Stop");
	    showCommandsTimer->start(showCommandsTime);
	}
	else if (startJoystickController->text() == "Stop")
	{
	    myThread->setStarted(false);
	    //myThread->exit();
	    startJoystickController->setText("Start");
	    showCommandsTimer->stop();
	}
    }
}


void BasicMotion::updateControllerCommands(int controllerId, int* controllerAxes)
{
    if (controllerId == 0)
    {
	speedController1 = (int)(-1*controllerAxes[5]);
	steeringController1 = (int)(-1*controllerAxes[0]);
    }
    else if (controllerId == 1)
    {
	speedController2 = (int)(-1*controllerAxes[5]);
	steeringController2 = (int)(-1*controllerAxes[0]);
    }
    else
    {
	cout << "Controller ID not valid" << endl;
    }    
}

void BasicMotion::sendControllerCommands()
{
    robotMove2();
}

void BasicMotion::showControllerCommands()
{
    cout << "(" << speedController1 << ", " << steeringController1 << ")" << endl;
    cout << "(" << speedController2 << ", " << steeringController2 << ")" << endl;
}


void BasicMotion::clickedClosedButton()
{
    myThread->exit();
    if(serialPort->isOpen())
    {
	serialPort->write(buildAllRobotsStopPacket());
        serialPort->close();
	serialConnection = false;
    }
    if(controllerSynch)
      remoteConnectionController1->kill();
    //camThread->setWorkingThread(false);
    //destroyWindow("Real time video");
    //camThread->exit();
}