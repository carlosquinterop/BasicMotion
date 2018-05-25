#ifndef BasicMotion_H
#define BasicMotion_H

#include <QMainWindow>
#include <QCheckBox>
#include <QGridLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QSlider>
#include <QDial>
#include <QProcess>
#include <QtSerialPort/QSerialPort>
#include <QtWidgets/QMessageBox>
#include "workerThread.h"
#include <QTextEdit>
#include <QTimer>
#include "jscontroller.h"
#include "cameraThread.h"

#define sendCommandsTime 50


class BasicMotion : public QMainWindow
{
    Q_OBJECT

public:
    BasicMotion();
    virtual ~BasicMotion();
    QGridLayout *PClayout, *controllerLayout;
    QGridLayout *mainLayout;
    QComboBox *PCrobotId, *controller1RobotId, *controller2RobotId;
    QLineEdit *rightWheelVel;
    QLineEdit *leftWheelVel;
    QPushButton *moveButton;
    QPushButton *stopButton;
    QPushButton *connectButton;
    QPushButton *synchButtonController1, *synchButtonController2;
    QPushButton *startJoystickController1, *startJoystickController2;
    QDial *steeringDial;
    QSlider *speedSlider;
    QCheckBox *pcControl, *wirelessControl;
    QTextEdit *remoteState;
    QProcess *remoteConnectionController1, *remoteConnectionController2;
    virtual void closeEvent ( QCloseEvent * event );
    
private:
    QSerialPort *serialPort;
    int openSerialPort(QString port);
    QByteArray data;
    QByteArray buildAllRobotsStopPacket();
    void sendRobotVel(int id, int rightVel, int leftVel);
    float* robotInverseKinematic(float v, float w);
    workerThread *myThread1, *myThread2;
    QString mOutputString1, mOutputString2;
    int speedController1, steeringController1, speedController2, steeringController2;
    bool serialConnection;
    QTimer *sendCommandsTimer1, *sendCommandsTimer2;
    JsController *joystick[2];
    int nJoystickConnected, joystick1, joystick2;
    cameraThread *camThread;
    
public slots:
    void wheelMove();
    void stop();
    void robotMove();
    void robotMove2(int controller);
    void PCCheckBoxState(int state);
    void WirelessCheckBoxState(int state);
    void clickedConnectButton();
    void SynchButton1();
    void SynchButton2();
    void processStarted1();
    void processStarted2();
    void readyReadStandardOutput1();
    void readyReadStandardOutput2();
    void startJoystickSlot1();
    void startJoystickSlot2();
    void updateControllerCommands(int controllerId, int* controllerAxes);
    void sendControllerCommands1();
    void sendControllerCommands2();
};

#endif // BasicMotion_H