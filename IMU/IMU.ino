#include <Event.h>  
#include <Timer.h>   //include libraries for timer  
Timer mytime;        //create object from timer

#include <Wire.h>   //include wire for I2C  
#define IMU_ADD 0x68    // IMU address
#define PWR_M  0x6B     // power address
#define GYRO_CON 0x1B   // Gyroscope address
#define z_Dir 0x47      // Register address for Z direction
#define Samples 2500    // number of samples for calibration 
#define SDA   A5   //I2C SDA
#define SCL   A4   //I2C SCL
int16_t z_offset=0; // variable to store gyroscope offset in
int16_t Value;      // the output value

  
void setup() {
  // put your setup code here, to run once:
  Wire.begin();    //begin comm
  Serial.begin(9600); //start serial with botrat 9600
  pinMode(SDA,OUTPUT); // define SDA, SCL as output
  pinMode(SCL,OUTPUT);
  MPU_init();          //fn to initialize mpu
  MPU_GYRO_CON();      //fn to configuration
  MPU_Calib();         //fn for calibration
  mytime.every(1000,z_out); //updating serial every 1000 ms 

}

void z_out(){                        //fn to out the value in the serial 
  Serial.print("Yaw anlge:  ");
  Serial.println(Value);
  }
  
void loop() {             
  // put your main code here, to run repeatedly:
  Value=MPU_Read() - z_offset;      //subtacting offset from the data 
  map(Value,-32786,32785,-1000,1000); //mapping the value to the full cale range
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
