#include <Event.h>  
#include <Timer.h>   //include libraries for timer 
Timer mytime;        //create object from timer
#include <Wire.h>   //include wire for I2C  
#define IMU_ADD 0x68    // IMU address
#define PWR_M  0x6B     // power address
#define GYRO_CON 0x1B   // Gyroscope address
#define z_Dir 0x47      // Register address for Z direction
#define Samples 2500    // number of samples for calibration 
int16_t z_offset=0; // variable to store gyroscope offset in
int16_t Value=0;    // the output value in degree/second
float Act_Value=0;       // and the actual value in degree 

int mot_Dir = 4;   //set cyton motor direction to the pin number 4 
int mot_Speed = 5;  // set the motor speed to pin 5 (PWM pin) 
float Error=0, time_1=0, time_2=0, d_t=0;  // -> variables to be used for PID control   
float d_Error=0,o_Error=0 ,Der=0 , Error_Area=0, PID_Value=0;
float Target = 100 ;  // let it to be 100 (for ex)
float KP=100 , KD=10 , DI=20 ; // setting the PID constants   
  
void setup() {
  // put your setup code here, to run once:
  Wire.begin();    //start i2c comm
  Serial.begin(9600); //start serial with baud rat 9600
  MPU_init();          //fn to initialize mpu
  MPU_GYRO_CON();      //fn to configuration
  MPU_Calib();         //fn for calibration
  mytime.every(1000,z_out); //updating serial every 1s 
  time_2=millis();     //get the time of start executing

}

void z_out(){                        //fn to out the value in the serial 
  Serial.print("Yaw anlge:  ");
  Serial.println(Value);
  }
  
void loop() {             
  // put your main code here, to run repeatedly:
  Value=MPU_Read() - z_offset;      //subtacting offset from the data 
  Value=Value*1000/32786; //mapping the value to the full scale range
  time_1 = time_2;          //get the second time at the last loop as the first time of next loop
  time_2 = millis();        // get th new time  
  d_t = (time_2 - time_1)/1000 ;   // calculating the dt from subtracting the new time from the last one
  
  Act_Value = Value * d_t + Act_Value;      // set the value to be in degree
  
  Error= Target - Value;      //calculating the error value

  d_Error = Error - o_Error ;   // get the change in the error
  Der = d_Error / d_t;          // calculate the de/dt (change in error by the change in time)

  Error_Area = Error_Area + Error * d_t ; // get the area of integration

  PID_Value = KP * Error + KD * Der + DI * Error_Area;  // the vlaue to be given to the motor

  
  if (PID_Value <0)                 //check if the value is negative to change the motor direction
  { 
    digitalWrite(mot_Dir, HIGH);    //set the motor in the counter clockwise direction (CCW) if the value is less than one 
    if(PID_Value <-255){
    PID_Value = 255; // set to the max value
    analogWrite(mot_Speed,PID_Value);  // write the value to the motor
    }  else{
    PID_Value = - PID_Value;           // make the PID value a positive value to be in the PWM range 
    analogWrite(mot_Speed,PID_Value);  // write the value to the motor
         }
  }
    else{
    digitalWrite(mot_Dir, LOW);    //set the motor in the counter clockwise direction (CW)
     if (PID_Value > 255){
      PID_Value = 255;               // check value to be given to analogWrite to be within it's range
      analogWrite(mot_Speed,PID_Value);  // write the value to the motor
    }  else{
        analogWrite(mot_Speed,PID_Value);  // write the value to the motor
           }
    }

  o_Error = Error;     //variable to contain the value of the last error 
  mytime.update();                  //update timer
}

void MPU_init(){               //Beginning comm with the mpu
  
  Wire.beginTransmission(IMU_ADD);    //begin transmission with mpu address
  Wire.write(PWR_M);                 //power register address
  Wire.write(0x00);                  //00 in hex (0000,0000)
  Wire.endTransmission();            //end transmission
  }
void MPU_GYRO_CON(){                //config gyroscope 
  Wire.beginTransmission(IMU_ADD);  //begin transmission with mpu address
  Wire.write(GYRO_CON);             // gyroscope register address
  Wire.write(0x10);                 //10 in hex(0001,0000) -> scale +- 1000
  Wire.endTransmission();           //end transmission
  } 
int16_t MPU_Read(){                 //fn for reading the data from mpu
  int16_t inf=0;                    //declare variable inf as 2 bytes to store data
  Wire.beginTransmission(IMU_ADD);  //begin transmission
  Wire.write(z_Dir);                //z-direction h register
  Wire.endTransmission();           //end transmission 
  Wire.requestFrom(IMU_ADD,2);      //reading data (2 bytes)
  while(Wire.available()<2);        //waiting until reading the 2 bytes
  inf = Wire.read() << 8 ;          //take first byte and shifting it 8 bits
  inf = inf |Wire.read();           // or to take the 2 bytes (it could be done with normal addig)
  return inf;                       // Returnnig data 
}
void MPU_Calib(){                    //mpu calibration fn 
  for (int i=0; i< Samples;i ++){    //for loop with the samples
    z_offset = z_offset + MPU_Read();  // add offsets
    }
    z_offset /= Samples;      // divide the number of samples
  }
