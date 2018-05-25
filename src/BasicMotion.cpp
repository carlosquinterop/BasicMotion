#include "BasicMotion.h"

BasicMotion::BasicMotion()
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
    synchButtonController1 = new QPushButton("Synch");
    synchButtonController2 = new QPushButton("Synch");
    remoteState = new QTextEdit("Remote");
    startJoystickController1 = new QPushButton("Start");
    startJoystickController2 = new QPushButton("Start");
    
    steeringDial = new QDial();
    
    speedSlider = new QSlider();
    
    QWidget *window = new QWidget();
    
    //Other objects
    myThread1 = new workerThread();
    myThread2 = new workerThread();
    remoteConnectionController1 = new QProcess();
    remoteConnectionController2 = new QProcess();
    sendCommandsTimer1 = new QTimer();
    sendCommandsTimer2 = new QTimer();
    ///////////////////////////////////////
    
    
    //Add widgets
    //////////////////////////////////////
    
    //Add widgets to main layout
    mainLayout->addWidget(connectButton, 0, 0);
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
    controllerLayout->addWidget(new QLabel("Controller 1"), 1, 0);
    controllerLayout->addWidget(new QLabel("Robot ID"), 2, 0);
    controllerLayout->addWidget(controller1RobotId, 2, 1);
    controllerLayout->addWidget(synchButtonController1, 3, 0);
    controllerLayout->addWidget(startJoystickController1, 4, 0);
    
    controllerLayout->addWidget(new QLabel("Controller 2"), 5, 0);
    controllerLayout->addWidget(new QLabel("Robot ID"), 6, 0);
    controllerLayout->addWidget(controller2RobotId, 6, 1);
    controllerLayout->addWidget(synchButtonController2, 7, 0);
    controllerLayout->addWidget(startJoystickController2, 8, 0);
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
    controller2RobotId->setCurrentIndex(1);
        
    leftWheelVel->setEnabled(false);
    rightWheelVel->setEnabled(false);
    moveButton->setEnabled(false);
    stopButton->setEnabled(false);
    connectButton->setEnabled(true);
    
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
    nJoystickConnected = 0;
    joystick1 = -1;
    joystick2 = -1;
    
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
    
    QObject::connect(synchButtonController1, SIGNAL(clicked()), this, SLOT(SynchButton1()));
    QObject::connect(synchButtonController2, SIGNAL(clicked()), this, SLOT(SynchButton2()));

    QObject::connect(remoteConnectionController1, SIGNAL(started()), this, SLOT(processStarted1()));
    QObject::connect(remoteConnectionController2, SIGNAL(started()), this, SLOT(processStarted2()));
    
    QObject::connect(remoteConnectionController1,SIGNAL(readyReadStandardOutput()),this, SLOT(readyReadStandardOutput1()));
    QObject::connect(remoteConnectionController2,SIGNAL(readyReadStandardOutput()),this, SLOT(readyReadStandardOutput2()));
    
    QObject::connect(startJoystickController1,SIGNAL(clicked()),this,SLOT(startJoystickSlot1()));
    QObject::connect(startJoystickController2,SIGNAL(clicked()),this,SLOT(startJoystickSlot2()));
    
    QObject::connect(myThread1,SIGNAL(updateJoystickAction(int, int*)),this, SLOT(updateControllerCommands(int, int*)));
    QObject::connect(myThread2,SIGNAL(updateJoystickAction(int, int*)),this, SLOT(updateControllerCommands(int, int*)));
    
    QObject::connect(sendCommandsTimer1,SIGNAL(timeout()),this, SLOT(sendControllerCommands1()));
    QObject::connect(sendCommandsTimer2,SIGNAL(timeout()),this, SLOT(sendControllerCommands2()));
    
    camThread = new cameraThread();
    camThread->setWorkingThread(true);
    camThread->start();
    namedWindow("Real time video", WINDOW_NORMAL);
    //setWindowProperty("Real time video", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
    
    //namedWindow("Real time video", WINDOW_AUTOSIZE );
    
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
    QWidget::closeEvent(event);
    remoteConnectionController1->terminate();
    remoteConnectionController2->terminate();
    myThread1->exit();
    myThread2->exit();
    camThread->setWorkingThread(false);
    destroyWindow("Real time video");
    camThread->exit();
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

void BasicMotion::sendRobotVel(int id, int rightVel, int leftVel)
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
   sendRobotVel(PCrobotId->currentIndex(), right+0x7F, left+0x7F);
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
    sendRobotVel(PCrobotId->currentIndex(), (int)(wheelVels[0])+0x7F, (int)(wheelVels[1])+0x7F);
}

void BasicMotion::robotMove2(int controller)
{	
    if (controller == joystick1)
    {
	float v = (float)(speedController1)/32767;
	float w = (float)(steeringController1)*(3*M_PI_4)/32767;
	float *wheelVels = robotInverseKinematic(v, w);
	sendRobotVel(controller1RobotId->currentIndex(), (int)(wheelVels[0])+0x7F, (int)(wheelVels[1])+0x7F);
    }
    else if (controller == joystick2)
    {
	float v = (float)(speedController2)/32767;
	float w = (float)(steeringController2)*(3*M_PI_4)/32767;
	float *wheelVels = robotInverseKinematic(v, w);
	sendRobotVel(controller2RobotId->currentIndex(), (int)(wheelVels[0])+0x7F, (int)(wheelVels[1])+0x7F);
    }
    else 
    {
	cout << "Controller ID not valid in robotMove2()" << endl;
    }
}

void BasicMotion::PCCheckBoxState(int state)
{
  if(pcControl->isChecked())
  {
      wirelessControl->setChecked(false);
      remoteState->setText("");
      leftWheelVel->setEnabled(true);
      rightWheelVel->setEnabled(true);
      moveButton->setEnabled(true);
      stopButton->setEnabled(true);
      steeringDial->setEnabled(true);
      speedSlider->setEnabled(true);
      synchButtonController1->setEnabled(false);
      synchButtonController2->setEnabled(false);
  }
  else
  {
      wirelessControl->setChecked(true);
      remoteState->setText("Remote");
      leftWheelVel->setEnabled(false);
      rightWheelVel->setEnabled(false);
      moveButton->setEnabled(false);
      stopButton->setEnabled(false);
      steeringDial->setEnabled(false);
      speedSlider->setEnabled(false);
      synchButtonController1->setEnabled(true);
      synchButtonController2->setEnabled(true);
  }
}

void BasicMotion::WirelessCheckBoxState(int state)
{
  if(!wirelessControl->isChecked())
  {
      pcControl->setChecked(true);
      remoteState->setText("");
      leftWheelVel->setEnabled(true);
      rightWheelVel->setEnabled(true);
      moveButton->setEnabled(true);
      stopButton->setEnabled(true);
      steeringDial->setEnabled(true);
      speedSlider->setEnabled(true);
      synchButtonController1->setEnabled(false);
      synchButtonController2->setEnabled(false);
  }
  else
  {
      pcControl->setChecked(false);
      remoteState->setText("Remote");
      leftWheelVel->setEnabled(false);
      rightWheelVel->setEnabled(false);
      moveButton->setEnabled(false);
      stopButton->setEnabled(false);
      steeringDial->setEnabled(false);
      speedSlider->setEnabled(false);
      synchButtonController1->setEnabled(true);
      synchButtonController2->setEnabled(true);
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
      } 
    }
}

void BasicMotion::SynchButton1()
{
    remoteConnectionController1->start("ds4drv");
}

void BasicMotion::SynchButton2()
{
    remoteConnectionController2->start("ds4drv");
}

void BasicMotion::processStarted1()
{
    cout << "Process 1 Started" << endl;
    synchButtonController1->setEnabled(false);
}

void BasicMotion::processStarted2()
{
    cout << "Process 2 Started" << endl;
    synchButtonController2->setEnabled(false);
}

void BasicMotion::readyReadStandardOutput1()
{
    mOutputString1 = remoteConnectionController1->readAllStandardOutput();
    cout << mOutputString1.toStdString() << endl;
}

void BasicMotion::readyReadStandardOutput2()
{  
    mOutputString2 = remoteConnectionController2->readAllStandardOutput();
    cout << mOutputString2.toStdString() << endl;
}

void BasicMotion::startJoystickSlot1()
{
    //Lanzar el hilo
    if (nJoystickConnected == 0  && joystick1 == -1)
    {
	joystick1 = 0;
	nJoystickConnected++;
    }
    else if (nJoystickConnected == 1 && joystick1 == -1)
    {
	joystick1 = 1;
	nJoystickConnected++;
    }
    
    if(startJoystickController1->text() == "Start")
    {
	myThread1->start();
	startJoystickController1->setText("Stop");
	sendCommandsTimer1->start(sendCommandsTime);
    }
    else if (startJoystickController1->text() == "Stop")
    {
	myThread1->exit();
	startJoystickController1->setText("Start");
	myThread1->setStarted(false);
	sendCommandsTimer1->stop();
    }
}

void BasicMotion::startJoystickSlot2()
{
  
    if (nJoystickConnected == 0 && joystick2 == -1)
    {
	joystick2 = 0;
	nJoystickConnected++;
    }
    else if (nJoystickConnected == 1 && joystick2 == -1)
    {
	joystick2 = 1;
	nJoystickConnected++;
    }
    
    
    //Lanzar el hilo
    if(startJoystickController2->text() == "Start")
    {
	myThread2->start();
	startJoystickController2->setText("Stop");
	sendCommandsTimer2->start(sendCommandsTime);
    }
    else if (startJoystickController2->text() == "Stop")
    {
	myThread2->exit();
	startJoystickController2->setText("Start");
	myThread2->setStarted(false);
	sendCommandsTimer2->stop();
    }
}

void BasicMotion::updateControllerCommands(int controllerId, int* controllerAxes)
{
    if (controllerId == joystick1)
    {
	speedController1 = (int)(-1*controllerAxes[5]);
	steeringController1 = (int)(-1*controllerAxes[0]);
    }
    else if (controllerId == joystick2)
    {
	speedController2 = (int)(-1*controllerAxes[5]);
	steeringController2 = (int)(-1*controllerAxes[0]);
    }
    else
    {
	cout << "Controller ID not valid" << endl;
    }    
}

void BasicMotion::sendControllerCommands1()
{
    robotMove2(joystick1);
}

void BasicMotion::sendControllerCommands2()
{
    robotMove2(joystick2);
}