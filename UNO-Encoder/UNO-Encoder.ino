
int motor1 =12;  //connect first motor at pin 12
int motor2 =13;  //connect secod one at pin 13 
int swt =6;     //SPST switch
int a =2;       //channel A for encoder 1 (Interrupt pin)
int b =4;       //channel B for encoder 1
int a2 =3;      //channel A for encoder 2 (Interrupt pin)
int b2 =5;      //channel b for encoder 2
long long count=0;    //counter for the first encoder
long long count2=0;   //counter for the second one
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
  Serial.begin(9600); //begin serial

}

void loop() {
  // put your main code here, to run repeatedly:
   angle1=(360*count/2400);  //angle1=(float)(360.0*count/2400) --> to get angle1 as float
   angle2=(360*count2/2400); //angle2=(float)(360.0*count2/2400) --> to get angle2 as float
  if(digitalRead(swt)==LOW){       //check the state of the switch to be low
    
    if(angle1>=60||angle1<=-300)      //stopping the first motor when reaching the wanted angle
    {
      digitalWrite(motor1,LOW);
    
    }else{digitalWrite(motor1,HIGH);}
    if(5>=angle2||angle2<=-355){
      digitalWrite(motor2,LOW);
      }else{digitalWrite(motor2,HIGH);}
 }

    if(digitalRead(swt)==HIGH){   //check the state of the switch to be high
      
      if(angle1>= 60||angle1<=-300 )  //stopping the first motor at 60 or -300
    {
        digitalWrite(motor1,LOW);
    }     else{digitalWrite(motor1,HIGH);}
    if(angle2>=90||(angle2<=-270&&angle2>=-350)){  //stopping the second motor at 90 or -270 degree
      digitalWrite(motor2,LOW);
    }else{digitalWrite(motor2,HIGH);}
 }
 if(count>2400||count<-2400){count=0;} //return back to 0 when reaching 2400 (360 degree)
 if(count2>2400||count2<-2400){count2=0;}

  Serial.print(angle1);             //Diplaying the angle of each motor
  Serial.print("\t");
  Serial.println(angle2);
 
}
