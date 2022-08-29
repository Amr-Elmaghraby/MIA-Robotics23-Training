
int motor1 =12;  //connect first motor at pin 12
int motor2 =13;  //connect secod one at pin 13 
int swt =6;     //SPST switch
int a =2;       //channel A for encoder 1 (Interrupt pin)
int b =4;       //channel B for encoder 1
int a2 =3;      //channel A for encoder 2 (Interrupt pin)
int b2 =5;      //channel b for encoder 2
long long count=0;    //counter for the first encoder
long long count2=0;   //counter for the second one
int d60,d300,d90,d270; // 4 variables with the right values to stop at the right degrees 
float angle1,angle2;   //angles to get the motors angles
void co_a(){                  //Interrupt fn for counting for first motor
  if(digitalRead(a)!= digitalRead(b)){
  count ++;                    //increasing if not equal ( CW )
  }
  else{count --;}              //decreasing if equal     ( CCW )
  }
  
void co_a2(){                //Interrupt fn for counting for the second motor
  if(digitalRead(a2)!= digitalRead(b2)){   //increasing if not equal( CW )
  count2 ++;
  }
  else{count2 --;}   //decreasing if equal     ( CCW )
  }

void setup() {
  // put your setup code here, to run once:
  pinMode(motor1,OUTPUT);   //Setting first,second motor as output
  pinMode(motor2,OUTPUT);
  pinMode(swt,INPUT);       //switch as input
  pinMode(a,INPUT_PULLUP);  //four channels for both encoders as input_pullup
  pinMode(b,INPUT_PULLUP);
  pinMode(a2,INPUT_PULLUP);
  pinMode(b2,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(a),co_a,CHANGE); //Interrupt for first encoder
  attachInterrupt(digitalPinToInterrupt(a2),co_a2,CHANGE);//Interrupt for second encoder
  d60 = 400; //((2400/360)*60)   60 degree for first motor
  d90 = 600; //((2400/360)*90)   90 degree for second motor
  d300 = -2000;//-((2400/360)*300)60 degree for first motor if it is CCCW
  d270 = -1800;//-((2400/360)*270)60 degree for second motor if it is CCW
 Serial.begin(9600); //begin serial

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(swt)==LOW){       //check the state of the switch to be low
    
  if(count>=d60||count<=d300)      //stopping the first motor when reaching the wanted angle
    {
    digitalWrite(motor1,LOW);
    
    }else{digitalWrite(motor1,HIGH);}
 }

    if(digitalRead(swt)==HIGH){   //check the state of the switch to be high
      
    if(count>= d60||count<=d300 )  //stopping the first motor at 60 or -300
    {
      digitalWrite(motor1,LOW);
    }else{digitalWrite(motor1,HIGH);}
    if(count2>=d90||count2<=d270){  //stopping the second motor at 90 or -270 degree
      digitalWrite(motor2,LOW);
    }else{digitalWrite(motor2,HIGH);}
 }
 angle1=(360*count/2400);  //angle1=(float)(360.0*count/2400) --> to get angle1 as float
 angle2=(360*count2/2400); //angle2=(float)(360.0*count2/2400) --> to get angle2 as float
  Serial.print(angle1);             
  Serial.print("\t");
  Serial.println(angle2);
 
}
