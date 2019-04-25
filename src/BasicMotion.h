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
#include <QDialogButtonBox>
#include <QDesktopWidget>
#include <QProcess>
#include <QtSerialPort/QSerialPort>
#include <QtWidgets/QMessageBox>
#include "workerThread.h"
#include <QPlainTextEdit>
#include <QGroupBox>
#include <QScrollBar>
#include <QTimer>
#include "jscontroller.h"

#define sendCommandsTime 30
#define showCommandsTime 500
#define NMAXCONTROLLERS 5
#define IMG_PATH "img/image.jpeg"
#define DEFAULT_MOVEBUTTON_NAME "Move"
#define DEFAULT_STOPBUTTON_NAME "Stop"
#define DEFAULT_SERIALBUTTON_NAME "Start Serial\n Connection"
#define DEFAULT_SYNCHBUTTON_NAME "Pair Controller"
#define DEFAULT_STARTBUTTON_NAME "Start"
#define DEFAULT_CLOSEBUTTON_NAME "Close"
#define DISCONNECT_SERIALBUTTON_NAME "Disconnect"
#define STOP_STARTBUTTON_NAME "Stop"
#define STOPSYNCH_SYNCHBUTTON_NAME "Stop Pairing"
#define LINEAR_MOVEMENT_BUTTON_NAME "Start v"
#define ANGULAR_MOVEMENT_BUTTON_NAME "Start w"
#define MAKE_RADIUS_BUTTON "Make circle"

class BasicMotion : public QMainWindow
{
    Q_OBJECT

public:
    BasicMotion();
    virtual ~BasicMotion();
    virtual void closeEvent ( QCloseEvent * event );
    int openSerialPort(QString port);
    QByteArray buildAllRobotsStopPacket();
    void sendRobotVelMultipleRobots(int *id, int *rightVel, int *leftVel);
    void sendRobotVelOneRobot(int id, int rightVel, int leftVel);
    float* robotInverseKinematic(float v, float w);
    
private:
    QSerialPort *serialPort;
    QByteArray data;
    QGridLayout *PClayout, *controllerLayout, *robotMovement, *robotRadio;
    QGridLayout *mainLayout, *buttonsLayout, *controlLayout, *controlSelectionlayout;
    QComboBox *PCrobotId, *controllersRobotId[NMAXCONTROLLERS];
    QLineEdit *rightWheelVel;
    QLineEdit *leftWheelVel;
    QPushButton *moveButton;
    QPushButton *stopButton;
    QPushButton *connectButton;
    QPushButton *synchButtonControllers;
    QPushButton *startJoystickController;
    QPushButton *closeButton;
    QDialogButtonBox *buttonBox;
    QDial *steeringDial;
    QSlider *speedSlider;
    QPixmap *imagePixmap;
    QLabel *imageLabel, *appName; 
    QLineEdit *forwardVel, *backwardVel, *rightAngularVel, *leftAngularVel;
    QLineEdit *linearVel, *angularVel;
    QCheckBox *pcControl, *wirelessControl, *movingForwardCheckBox, *movingBackwardsCheckBox, *turningRightCheckBox, *turningLeftCheckBox;
    QPushButton *linearMovementButton, *angularMovementButton, *makeRadiusX;
    QPlainTextEdit *consoleTextEdit;
    QGroupBox *gridGroupBox;
    QProcess *remoteConnectionController;
    workerThread *myThread;
    QString mOutputString1;
    int speedControllers[NMAXCONTROLLERS], steeringControllers[NMAXCONTROLLERS];
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
    void readyReadStandardOutput();
    void startJoystickSlot();
    void updateControllerCommands(int controllerId, int* controllerAxes);
    void sendControllerCommands();
    void showControllerCommands();
    void clickedClosedButton();
    void movingForwardCheckBoxState(int state );
    void movingBackwardCheckBoxState(int state);
    void turningLeftCheckBoxState(int state );
    void turningRightCheckBoxState(int state);
    void sendRobotAngularVelocity();
    void sendRobotLinearVelocity();
    void makeCircleOfRadiusX();
    void processEnded(int exitCode, QProcess::ExitStatus existStatus);
};

#endif // BasicMotion_H