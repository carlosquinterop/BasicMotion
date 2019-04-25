#include "BasicMotion.h"

BasicMotion::BasicMotion()
{
    QDesktopWidget dw;
    int x_window=dw.width()*0.55;
    int y_window=dw.height()*0.9;
    //Widget constructors
    /////////////////////
    mainLayout = new QGridLayout();
    PClayout = new QGridLayout();
    controllerLayout = new QGridLayout();
    buttonsLayout = new QGridLayout();
    controlLayout = new QGridLayout();
    controlSelectionlayout = new QGridLayout(); 
    robotMovement= new QGridLayout();
    robotRadio= new QGridLayout();
    
    gridGroupBox = new QGroupBox("Options");
    
    PCrobotId = new QComboBox();
    for (int i = 0;i < NMAXCONTROLLERS; i++)
      controllersRobotId[i] = new QComboBox();
    
    pcControl = new QCheckBox("PC Control");
    wirelessControl = new QCheckBox("Remote Control");
    
    rightWheelVel = new QLineEdit("0");
    leftWheelVel = new QLineEdit("0");
    
    moveButton = new QPushButton(DEFAULT_MOVEBUTTON_NAME);
    stopButton = new QPushButton(DEFAULT_STOPBUTTON_NAME);
    connectButton = new QPushButton(DEFAULT_SERIALBUTTON_NAME);
    synchButtonControllers = new QPushButton(DEFAULT_SYNCHBUTTON_NAME);
    startJoystickController = new QPushButton(DEFAULT_STARTBUTTON_NAME);
    closeButton = new QPushButton(DEFAULT_CLOSEBUTTON_NAME);
     
    steeringDial = new QDial();
    speedSlider = new QSlider();
    imagePixmap = new QPixmap();
    imageLabel = new QLabel();
    consoleTextEdit = new QPlainTextEdit();
    buttonBox = new QDialogButtonBox(Qt::Horizontal);
    
    movingForwardCheckBox= new QCheckBox("Forward");
    movingBackwardsCheckBox= new QCheckBox("Backwards");
    turningLeftCheckBox= new QCheckBox("Turn left");
    turningRightCheckBox= new QCheckBox("Turn right");
    
    forwardVel= new QLineEdit();
    rightAngularVel= new QLineEdit();
    
    
    linearVel= new QLineEdit();
    angularVel= new QLineEdit();
    linearMovementButton = new QPushButton(LINEAR_MOVEMENT_BUTTON_NAME);
    angularMovementButton= new QPushButton(ANGULAR_MOVEMENT_BUTTON_NAME);
    makeRadiusX= new QPushButton(MAKE_RADIUS_BUTTON); 
      
    appName = new QLabel("Basic Robot Motion");
    
    QWidget *window = new QWidget();
    
    //Other objects
    myThread = new workerThread();
    remoteConnectionController = new QProcess();
    sendCommandsTimer = new QTimer();
    showCommandsTimer = new QTimer();
    serialPort = new QSerialPort();
    ///////////////////////////////////////
    
    //Add widgets
    //////////////////////////////////////
    
    //Add widgets to main layout
    mainLayout->addWidget(appName, 0, 0);
    mainLayout->addWidget(imageLabel, 1, 0);
    mainLayout->addLayout(buttonsLayout, 2, 0);
    mainLayout->addLayout(controlSelectionlayout, 3, 0);
    mainLayout->addLayout(controlLayout, 4, 0);
    mainLayout->addWidget(consoleTextEdit, 5, 0);
    mainLayout->addLayout(robotMovement, 3, 1);
    mainLayout-> addLayout(robotRadio, 4,1);
    
    //Add widgets to buttonsLayout
    buttonsLayout->addWidget(connectButton, 0, 0);
    buttonsLayout->addWidget(closeButton, 0, 1);
    
    //Add layouts to controlLayout
    controlLayout->addLayout(PClayout, 0, 0);
    controlLayout->addLayout(controllerLayout, 0, 1);
        
    //Add widgets to controlSelectionlayout
    controlSelectionlayout->addWidget(pcControl, 0, 0, Qt::AlignCenter);
    controlSelectionlayout->addWidget(wirelessControl, 0, 1, Qt::AlignCenter);
    
    //Add widgets to PC layout
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
    controllerLayout->addWidget(synchButtonControllers, 1, 0);
    controllerLayout->addWidget(startJoystickController, 2, 0);
    controllerLayout->addWidget(new QLabel("Controller 0 Robot ID"), 3, 0);
    controllerLayout->addWidget(controllersRobotId[0], 3, 1);
    controllerLayout->addWidget(new QLabel("Controller 1 Robot ID"), 4, 0);
    controllerLayout->addWidget(controllersRobotId[1], 4, 1);
    controllerLayout->addWidget(new QLabel("Controller 2 Robot ID"), 5, 0);
    controllerLayout->addWidget(controllersRobotId[2], 5, 1);
    controllerLayout->addWidget(new QLabel("Controller 3 Robot ID"), 6, 0);
    controllerLayout->addWidget(controllersRobotId[3], 6, 1);
    controllerLayout->addWidget(new QLabel("Controller 4 Robot ID"), 7, 0);
    controllerLayout->addWidget(controllersRobotId[4], 7, 1);
    
    
    // Robot movement layout
     robotMovement->addWidget(new QLabel("Robot movement"), 1, 0);
     robotMovement-> addWidget(movingForwardCheckBox, 2,0);
     robotMovement->addWidget(forwardVel, 2,1);
     robotMovement->addWidget(new QLabel("Linear velocity (m/s)"),2,2);
     robotMovement-> addWidget(movingBackwardsCheckBox, 3,0);
     robotMovement-> addWidget(linearMovementButton,3,1);
     robotMovement-> addWidget(turningRightCheckBox, 4,0);
     robotMovement->addWidget(rightAngularVel,4,1);
     robotMovement->addWidget(new QLabel("Angular velocity (rad/s)"),4,2);
     robotMovement-> addWidget(turningLeftCheckBox, 5,0);
     robotMovement-> addWidget(angularMovementButton,5,1);
         
     
    //Radio robot
     robotRadio-> addWidget(new QLabel("Robot radio"), 0, 0);
     robotRadio-> addWidget(linearVel, 1,0);
     robotRadio->addWidget(new QLabel("Linear velocity (m/s)"),1,1);
     robotRadio-> addWidget(angularVel, 2,0);
     robotRadio->addWidget(new QLabel("Angular velocity (m/s)"),2,1);
     robotRadio-> addWidget(makeRadiusX,3,0);
     
    /////////////////////////////////////
     
     
    //Widget initializations   
    
    PCrobotId->addItem("0");
    PCrobotId->addItem("1");
    PCrobotId->addItem("2");
    PCrobotId->addItem("3");
    PCrobotId->addItem("4");
    PCrobotId->setCurrentIndex(1);
    
    for(int i = 0;i < NMAXCONTROLLERS;i++)
    {
      controllersRobotId[i]->addItem("0");
      controllersRobotId[i]->addItem("1");
      controllersRobotId[i]->addItem("2");
      controllersRobotId[i]->addItem("3");
      controllersRobotId[i]->addItem("4");
      controllersRobotId[i]->setCurrentIndex(i);      
    }
        
    leftWheelVel->setEnabled(false);
    rightWheelVel->setEnabled(false);
    moveButton->setEnabled(false);
    stopButton->setEnabled(false);
    QPalette pal = connectButton->palette( );
    pal.setColor(QPalette::Button, QColor(Qt::green));
    connectButton->setAutoFillBackground(true);
    connectButton->setPalette(pal);
    connectButton->update();
    connectButton->setEnabled(true);
    connectButton->setFixedSize(QSize(0.28*x_window, 0.1*y_window));
    QPalette palClose = closeButton->palette( );
    palClose.setColor(QPalette::Button, QColor(Qt::red));
    closeButton->setAutoFillBackground(true);
    closeButton->setPalette(palClose);
    closeButton->update();
    closeButton->setEnabled(true);
    closeButton->setFixedSize(QSize(0.28*x_window, 0.1*y_window));
    startJoystickController->setEnabled(false);
    PCrobotId->setEnabled(false);
    
    pcControl->setChecked(false);
    wirelessControl->setChecked(true);
    steeringDial->setRange(-50, 50);
    steeringDial->setValue(0);
    
    speedSlider->setRange(-100, 100);
    speedSlider->setValue(0);
    steeringDial->setEnabled(false);
    speedSlider->setEnabled(false);
    
    imagePixmap->load(IMG_PATH);
    imageLabel->setPixmap(*imagePixmap);
    imageLabel->setScaledContents(false);
    imageLabel->setAlignment(Qt::AlignCenter);

    QPalette p = consoleTextEdit->palette();
    p.setColor(QPalette::Base, QColor(0, 0, 0));
    p.setColor(QPalette::Text, Qt::white);
    consoleTextEdit->setPalette(p);
    consoleTextEdit->setEnabled(false);
    consoleTextEdit->setMaximumBlockCount(10);
    
    appName->setAlignment(Qt::AlignCenter);
    QFont f("Arial",16);
    QFontMetrics fm(f);
    appName->setFont(f);  
    
    memset(speedControllers, 0, sizeof(int)*NMAXCONTROLLERS);
    memset(steeringControllers, 0, sizeof(int)*NMAXCONTROLLERS);
    nJoysticksConnected = 0;
    controllerSynch = false;
    serialConnection = false;
    
    window->setLayout(mainLayout);
    setCentralWidget(window);
    window->setFixedSize(x_window,y_window);
    setWindowTitle("Basic Robot Motion Application");
    
    QObject::connect(moveButton, SIGNAL(clicked(bool)), this, SLOT(wheelMove()));
    QObject::connect(stopButton, SIGNAL(clicked(bool)), this, SLOT(stop()));
    QObject::connect(steeringDial, SIGNAL(valueChanged(int)), this, SLOT(robotMove()));
    QObject::connect(speedSlider, SIGNAL(valueChanged(int)), this, SLOT(robotMove()));
    QObject::connect(pcControl, SIGNAL(stateChanged(int)), this, SLOT(PCCheckBoxState(int)));
    QObject::connect(wirelessControl, SIGNAL(stateChanged(int)), this, SLOT(WirelessCheckBoxState(int)));
    QObject::connect(connectButton, SIGNAL(clicked()), this, SLOT(clickedConnectButton()));
    QObject::connect(closeButton, SIGNAL(clicked()), this, SLOT(clickedClosedButton()));
    QObject::connect(synchButtonControllers, SIGNAL(clicked()), this, SLOT(SynchButton()));
    QObject::connect(remoteConnectionController, SIGNAL(started()), this, SLOT(processStarted()));
    QObject::connect(remoteConnectionController, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(processEnded(int, QProcess::ExitStatus)));
    QObject::connect(remoteConnectionController, SIGNAL(readyReadStandardOutput()),this, SLOT(readyReadStandardOutput()));
    QObject::connect(startJoystickController,SIGNAL(clicked()),this,SLOT(startJoystickSlot()));
    QObject::connect(myThread,SIGNAL(updateJoystickAction(int, int*)),this, SLOT(updateControllerCommands(int, int*)));
    QObject::connect(sendCommandsTimer,SIGNAL(timeout()),this, SLOT(sendControllerCommands()));
    QObject::connect(showCommandsTimer,SIGNAL(timeout()),this, SLOT(showControllerCommands()));
    QObject::connect(movingForwardCheckBox, SIGNAL(stateChanged(int)), this, SLOT(movingForwardCheckBoxState(int)));
    QObject::connect(movingBackwardsCheckBox, SIGNAL(stateChanged(int)), this, SLOT(movingBackwardCheckBoxState(int)));
    QObject::connect(turningLeftCheckBox, SIGNAL(stateChanged(int)), this, SLOT(turningLeftCheckBoxState(int)));
    QObject::connect(turningRightCheckBox, SIGNAL(stateChanged(int)), this, SLOT(turningRightCheckBoxState(int)));
    QObject::connect(angularMovementButton, SIGNAL(clicked(bool)), this, SLOT(sendRobotAngularVelocity()));
    QObject::connect(linearMovementButton, SIGNAL (clicked(bool)), this, SLOT(sendRobotLinearVelocity()));
    QObject::connect(makeRadiusX, SIGNAL (clicked(bool)), this, SLOT(makeCircleOfRadiusX()));
    
    consoleTextEdit->setPlainText("Basic Robot Motion App started");
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
      remoteConnectionController->kill();
    myThread->exit();
    QWidget::closeEvent(event);
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
      consoleTextEdit->setPlainText("Successfully connected to serial hub");
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
    for (int i = 0; i < NMAXCONTROLLERS; i++)
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
    int leftVels[NMAXCONTROLLERS], rightVels[NMAXCONTROLLERS];
    int activeId[NMAXCONTROLLERS];
    memset(activeId, -1, sizeof(int)*NMAXCONTROLLERS);
    nJoysticksConnected = myThread->getnActiveJoysticks();
    
    for(int i = 0;i < NMAXCONTROLLERS; i++)
    {
	if (nJoysticksConnected > i)
	{
	  float v = (float)(speedControllers[i])/32768;
	  float w = (float)(steeringControllers[i])*(3*M_PI_4)/32768;
	  float *wheelVels = robotInverseKinematic(v, w);
	  leftVels[i] = (int)(wheelVels[1]) + 0x7F;
	  rightVels[i] = (int)(wheelVels[0]) + 0x7F;
	  activeId[i] = controllersRobotId[i]->currentIndex();
	}
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
      PCrobotId->setEnabled(true);
      for(int i=0;i < NMAXCONTROLLERS;i++)
	controllersRobotId[i]->setEnabled(false);
      synchButtonControllers->setEnabled(false);
      startJoystickController->setEnabled(false);
      if(controllerSynch)
      remoteConnectionController->kill();      
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
      PCrobotId->setEnabled(false);
      for(int i=0;i < NMAXCONTROLLERS;i++)
	controllersRobotId[i]->setEnabled(true);
      synchButtonControllers->setEnabled(true);
     startJoystickController->setEnabled(true);
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
      PCrobotId->setEnabled(true);
      for(int i=0;i < NMAXCONTROLLERS;i++)
	controllersRobotId[i]->setEnabled(false);
      synchButtonControllers->setEnabled(false);
      startJoystickController->setEnabled(false);
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
      PCrobotId->setEnabled(false);
      for(int i=0;i < NMAXCONTROLLERS;i++)
	controllersRobotId[i]->setEnabled(true);
      synchButtonControllers->setEnabled(true);
      startJoystickController->setEnabled(false);
  }
}

void BasicMotion::clickedConnectButton()
{
    if (connectButton->text() == DEFAULT_SERIALBUTTON_NAME)
    {
      serialPort = new QSerialPort();
      if (!openSerialPort("ttyUSB0"))
      {
	connectButton->setText(DISCONNECT_SERIALBUTTON_NAME);
	data = buildAllRobotsStopPacket();
      }
    }
    else if (connectButton->text() == DISCONNECT_SERIALBUTTON_NAME)
    {
      if(serialPort->isOpen())
      {
	serialPort->write(buildAllRobotsStopPacket());
        serialPort->close();
	connectButton->setText(DEFAULT_SERIALBUTTON_NAME);
	serialConnection = false;
      } 
    }
}

void BasicMotion::SynchButton()
{
    if(synchButtonControllers->text() == DEFAULT_SYNCHBUTTON_NAME)
      remoteConnectionController->start("ds4drv");
    else if (synchButtonControllers->text() == STOPSYNCH_SYNCHBUTTON_NAME)
      remoteConnectionController->kill();      
}

void BasicMotion::processStarted()
{
    consoleTextEdit->appendPlainText("Process ds4drv Started");
    synchButtonControllers->setText(STOPSYNCH_SYNCHBUTTON_NAME);
    controllerSynch = true;
    startJoystickController->setEnabled(true);
}

void BasicMotion::processEnded(int exitCode, QProcess::ExitStatus ExitStatus)
{
    consoleTextEdit->appendPlainText("Process ds4drv ended");
    synchButtonControllers->setText(DEFAULT_SYNCHBUTTON_NAME);
    controllerSynch = false;
    if (startJoystickController->text() == STOP_STARTBUTTON_NAME)
    {
	myThread->setStarted(false);
	startJoystickController->setText(DEFAULT_STARTBUTTON_NAME);
	sendCommandsTimer->stop();
    }
    startJoystickController->setEnabled(false);
}

void BasicMotion::readyReadStandardOutput()
{
    mOutputString1 = remoteConnectionController->readAllStandardOutput();
    consoleTextEdit->appendPlainText(mOutputString1);
}

void BasicMotion::startJoystickSlot()
{
    if (serialConnection)
    {
	if(startJoystickController->text() == DEFAULT_STARTBUTTON_NAME)
	{
	    myThread->start();
	    startJoystickController->setText(STOP_STARTBUTTON_NAME);
	    sendCommandsTimer->start(sendCommandsTime);
	}
	else if (startJoystickController->text() == STOP_STARTBUTTON_NAME)
	{
	    myThread->setStarted(false);
	    myThread->exit();
	    startJoystickController->setText(DEFAULT_STARTBUTTON_NAME);
	    sendCommandsTimer->stop();
	}
    }
    else
    {
	if(startJoystickController->text() == DEFAULT_STARTBUTTON_NAME)
	{
	    myThread->start();
	    startJoystickController->setText(STOP_STARTBUTTON_NAME);
	    showCommandsTimer->start(showCommandsTime);
	}
	else if (startJoystickController->text() == STOP_STARTBUTTON_NAME)
	{
	    myThread->setStarted(false);
	    myThread->exit();
	    startJoystickController->setText(DEFAULT_STARTBUTTON_NAME);
	    showCommandsTimer->stop();
	}
    }
}

void BasicMotion::updateControllerCommands(int controllerId, int* controllerAxes)
{
    for (int i = 0;i < NMAXCONTROLLERS;i++)
    {
	if (controllerId == i)
	{
	    speedControllers[i] = (int)((-1*controllerAxes[5])/2);
	    steeringControllers[i] = (int)((-1*controllerAxes[0])/2);
	}
	else
	{
	  consoleTextEdit->appendPlainText("Warning: Controller ID not valid");
	}
    }
}

void BasicMotion::sendControllerCommands()
{
    robotMove2();
    int nActiveJoysticks = myThread->getnActiveJoysticks();
    //consoleTextEdit->setPlainText("");
    for (int i = 0;i < nActiveJoysticks;i++)
    {
	//cout << "\033[2J\033[1;1H" << endl;
	//cout << i+1 << ": (" << speedControllers[i] << ", " << steeringControllers[i] << ")" << endl;
	consoleTextEdit->setPlainText(QString::number(i+1)+": ("+QString::number(speedControllers[i])+", "+QString::number(steeringControllers[i])+")");
    }
}

void BasicMotion::showControllerCommands()
{
    int nActiveJoysticks = myThread->getnActiveJoysticks();
    //consoleTextEdit->setPlainText("");
    for (int i = 0;i < nActiveJoysticks;i++)
    {
	consoleTextEdit->setPlainText(QString::number(i+1)+": ("+QString::number(speedControllers[i])+", "+QString::number(steeringControllers[i])+")");
   	//cout << "\033[2J\033[1;1H" << endl;
	//cout << i+1 << ": (" << speedControllers[i] << ", " << steeringControllers[i] << ")" << endl;
    }
}

void BasicMotion::clickedClosedButton()
{
    if (myThread->getStarted())
	myThread->exit();
    if(serialPort->isOpen())
    {
	serialPort->write(buildAllRobotsStopPacket());
        serialPort->close();
	serialConnection = false;
    }
    if(controllerSynch)
      remoteConnectionController->kill();
    this->close();
}

void BasicMotion::movingForwardCheckBoxState(int state)
{
  if (movingForwardCheckBox->isChecked())
     { 
       movingBackwardsCheckBox->setEnabled(false);
       turningLeftCheckBox->setEnabled(false);
       turningRightCheckBox->setEnabled(false);
       forwardVel->setReadOnly(false);
       rightAngularVel->setText("0");
       rightAngularVel->setReadOnly(true);
     }
     else 
     {
      movingBackwardsCheckBox->setEnabled(true);
      movingForwardCheckBox->setEnabled(true);
      turningLeftCheckBox->setEnabled(true);
      turningRightCheckBox->setEnabled(true);
      rightAngularVel->setText("");
       rightAngularVel->setReadOnly(false);
     } 
}
void BasicMotion::movingBackwardCheckBoxState(int state)
{
  if (movingBackwardsCheckBox->isChecked())
     { 
       movingForwardCheckBox->setEnabled(false);
       turningLeftCheckBox->setEnabled(false);
       turningRightCheckBox->setEnabled(false);
       rightAngularVel->setText("0");
       rightAngularVel->setReadOnly(true);
     }
      else 
     {
      movingBackwardsCheckBox->setEnabled(true);
      movingForwardCheckBox->setEnabled(true);
      turningLeftCheckBox->setEnabled(true);
      turningRightCheckBox->setEnabled(true);
      rightAngularVel->setText("");
       rightAngularVel->setReadOnly(false);
     } 
}


void BasicMotion::turningLeftCheckBoxState(int state)
{
  if (turningLeftCheckBox->isChecked())
     { 
       movingForwardCheckBox->setEnabled(false);
       turningRightCheckBox->setEnabled(false);
       movingBackwardsCheckBox->setEnabled(false);
       forwardVel->setText("0");
       forwardVel->setReadOnly(true);
     }
     else 
     {
      movingBackwardsCheckBox->setEnabled(true);
      movingForwardCheckBox->setEnabled(true);
      turningLeftCheckBox->setEnabled(true);
      turningRightCheckBox->setEnabled(true);
      forwardVel->setText("");
       forwardVel->setReadOnly(false);
     } 
	 
}

void BasicMotion::turningRightCheckBoxState(int state)
{
  if (turningRightCheckBox->isChecked())
     { 
      movingForwardCheckBox->setEnabled(false);
      movingBackwardsCheckBox->setEnabled(false);
      turningLeftCheckBox->setEnabled(false);
      forwardVel->setText("0");
      forwardVel->setReadOnly(true);
       
     }
     else 
     {
      movingBackwardsCheckBox->setEnabled(true);
      movingForwardCheckBox->setEnabled(true);
      turningLeftCheckBox->setEnabled(true);
      turningRightCheckBox->setEnabled(true);
      forwardVel->setText("");
      forwardVel->setReadOnly(true);
     } 
}

void BasicMotion::sendRobotLinearVelocity()
{
  if (movingForwardCheckBox->isChecked())
  {
    int v= forwardVel->text().toInt();  //rango de velocidades? 
    int w= rightAngularVel->text().toInt();
    float *linearVels = robotInverseKinematic(v, w);
    sendRobotVelOneRobot(PCrobotId->currentIndex(), (int)(linearVels[0])+0x7F, (int)(linearVels[1])+0x7F);   
  }
  else if (movingBackwardsCheckBox->isChecked())
  {
   int v= forwardVel->text().toInt();  //rango de velocidades? 
    int w= rightAngularVel->text().toInt();
    float *linearVels = robotInverseKinematic(v, w);
    sendRobotVelOneRobot(PCrobotId->currentIndex(), (int)(-linearVels[0])+0x7F, (int)(-linearVels[1])+0x7F);   
  }
  
}

void BasicMotion::sendRobotAngularVelocity()
{
  if (turningLeftCheckBox->isChecked())
  {
    int v= forwardVel->text().toInt();  //rango de velocidades? 
    int w= rightAngularVel->text().toInt();
    float *angularVels = robotInverseKinematic(v, w);
    sendRobotVelOneRobot(PCrobotId->currentIndex(), (int)(angularVels[0])+0x7F, (int)-(angularVels[1])+0x7F);   
  }
  else if(turningRightCheckBox->isChecked())
  {
    int v= forwardVel->text().toInt();  //rango de velocidades? 
    int w= rightAngularVel->text().toInt();
    float *angularVels = robotInverseKinematic(v, w);
    sendRobotVelOneRobot(PCrobotId->currentIndex(), (int)-(angularVels[0])+0x7F, (int)(angularVels[1])+0x7F); 
  }
}

void BasicMotion::makeCircleOfRadiusX()
{
  //Para que el robot de un círculo de radio x, determine cuál es la v y w para encontrar la velocidad vr y vl. 
  // r=v/w  
  //v=(R/2)(vr+vl)                   
  //w=(R/L)(vr-vl)
   float *wheelVelsRadiusX = (float*)(malloc(sizeof(float)*2));;
   int v= linearVel->text().toInt();
   int w= angularVel->text().toInt();
   float L = 0.1;
   float R = 0.025;
   wheelVelsRadiusX[0]=(2*v)/(R)-wheelVelsRadiusX[1];
   wheelVelsRadiusX[1]=wheelVelsRadiusX[0]-(w*L)/(R);
   sendRobotVelOneRobot(PCrobotId->currentIndex(), (int)(wheelVelsRadiusX[0])+0x7F, (int)(wheelVelsRadiusX[1])+0x7F);
}




