//Libraries Used
#include <Wire.h> //communication with i2c devices
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

//Declare Sensor Object for I2C
Adafruit_LIS3DH accelSensor = Adafruit_LIS3DH();

//Class motion: derives data and caluclations related to motion from acclerometer
//  - Contains XYZ vectors of:
//        - acceleration  : a(t) (m/s^2)
//        - velocity      : v(t) (m/s)
//        - position      : x(t) (m)
//
//  - Derives the following from XYZ acceleration vectors
//        - XYZ vectors of velocity
//        - XYZ vectors of position
//
//  - Calculates the total magnitude
//        - accerlation
//        - velocity
//        - position

class motion{
  public:
    motion(); //constructor
    ~motion(); //destructor
    
    //Class Function Declarations
    void readData(); //takes data f
    double totalMagAccel(double); //Marleen code this
    double totalMagVel(double); //this 
    double totalMagPos(double); //and this

    //Get Functions: return individual xyz motion vectors
    double getXMagAccel() {return xAccel;}
    double getYMagAccel() {return yAccel;}
    double getZMagAccel() {return zAccel;}
    
    double getxVel() {return xVel;}
    double getyVel() {return yVel;}
    double getzVel() {return zVel;}
    
    double getxPos() {return xPos;}
    double getyPos() {return yPos;}
    double getzPos() {return zPos;}
    
  private:
  //Magnitude of Acceleration X Y Z
    double xAccel;
    double yAccel;
    double zAccel;
  //Magnitude of Velocity X Y Z
    double xVel;
    double yVel;
    double zVel;
  //Magnitude of Position X Y Z
    double xPos;
    double yPos;
    double zPos;
};

//Constructor: initializes accel vectors
motion::motion(){
    xAccel = 0;
    yAccel = 0;
    zAccel = 0;
}

//Function: void readData()
//    - reads the XYZ acceleration from accelerometer
void motion::readData(){
    
    accelSensor.read(); //read xyz vectors from sensor

    xAccel = accelSensor.x;
    yAccel = accelSensor.y;
    zAccel = accelSensor.z;

    return;
}

//Function: double totalMagAccel()
//  paramters : 
//             double initA : initial total acceleration
//
//    - returns the total magnitude acceleration

double motion::totalMagAccel(double initA)
{

}

//Function: double totalMagVel()
//  paramters : 
//             double initV : initial total velocity 
//
//    - modifies indivudal XYZ velocity vectors using XYZ acceleration
//    - returns the total magnitude velocity

double motion::totalMagVel(double initV)
{

}

//Function: double totalMagPos()
//  paramters : 
//             double initP : initial total velocity 
//
//    - modifies indivudal XYZ position vectors using XYZ velocity
//    - returns the total magnitude position

double motion::totalMagPos(double initP)
{

}

//*******Don't code anything under this line*********
void setup() {
  //initializes arduino parameters

}

void loop() {
  //main code here, to run repeatedly:

}
