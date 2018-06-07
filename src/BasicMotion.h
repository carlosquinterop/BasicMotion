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

#define sendCommandsTime 50
#define showCommandsTime 500


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
    QPushButton *synchButtonControllers;
    QPushButton *startJoystickController;
    QPushButton *closeButton;
    QDial *steeringDial;
    QSlider *speedSlider;
    QCheckBox *pcControl, *wirelessControl;
    QProcess *remoteConnectionController1;
    virtual void closeEvent ( QCloseEvent * event );
    int openSerialPort(QString port);
    QByteArray buildAllRobotsStopPacket();
    void sendRobotVelMultipleRobots(int *id, int *rightVel, int *leftVel);
    void sendRobotVelOneRobot(int id, int rightVel, int leftVel);
    float* robotInverseKinematic(float v, float w);
    
private:
    QSerialPort *serialPort;
    QByteArray data;
    workerThread *myThread;
    QString mOutputString1, mOutputString2;
    int speedController1, steeringController1, speedController2, steeringController2;
    bool serialConnection;
    QTimer *sendCommandsTimer;
    QTimer *showCommandsTimer;
    int nJoysticksConnected;
    bool controllerSynch;
    
public slots:
    void wheelMove();
    void stop();
    void robotMove();
    void robotMove2();
    void PCCheckBoxState(int state);
    void WirelessCheckBoxState(int state);
    void clickedConnectButton();
    void SynchButton();
    void processStarted();
    void readyReadStandardOutput1();
    void startJoystickSlot();
    void updateControllerCommands(int controllerId, int* controllerAxes);
    void sendControllerCommands();
    void showControllerCommands();
    void clickedClosedButton();
    void processEnded(int exitCode, QProcess::ExitStatus existStatus);
};

#endif // BasicMotion_H