int trig1 = 11;                                            //declaring trigger and echo pins
int echo1=10;
int trig2 = 9;
int echo2=8;

float d1=0,d2=0;                                          //declaring variables to be used in calculation and decision making
float newd=0;
float duration=0;
unsigned long int temp=0;
int left=0;

void dist(void);                                          //function declaration to calculate distance

void setup() {
  // put your setup code here, to run once:
pinMode(trig1,OUTPUT);                                    //declaring status of trigger and echo pins
pinMode(echo1,INPUT);
pinMode(trig2,OUTPUT);
pinMode(echo2,INPUT);
delay(1000);                                             //wait for 1 second to stabilise and start serial communication
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  dist();                                               //First calculate the distance by calling the function and get left and right sensor distances
  if(d2>=5 && d2<=45){                                  //If the right sensor detects your hand then its true
    temp=millis();                                     //millis gives the time since the code has been uploaded. 
    while(millis()<=(temp+400)){                       //Now if the hand is still there even after 400 microseconds it becomes true in later condition
      dist();                                          // oh ok, the hand is still there, so calculate the distance again and get the distnaces
      if(d2>=5 && d2<=45){                             //if the hand is still there in the region
        newd=d2;                                       //get the distance so that we can compare it with next value
        while(d2>=3 && d2<=50){                        //if we move our hand towards or away from sensor this will help
          dist();                                      // now get the distance and if the new distance is greater or smaller than before distance
          if((newd+5)<d2){                             // if the hand is moved away from the sensor and is greater than 5cm(for calibration) from original position that means its moving away
            if((d2-newd)>15){                         //if this distance difference is far greater i.e when you remove your hand(distance is far greater) and put it back, then break out
              break;
            }
            else{                                     // if the distance gap is not that high i.e. when you are sliding your hand back and forth then the command is Volume up
              Serial.println("Vup");//Away
            }
          }
          else if ((newd-5)>d2){                    //if the hand is moved towards the sensor and is closer than 5cm from our original postition that means its moving toward
            if((newd-d2)>15){
              break;
            }
            else{                                   //same as previous case when the distance gap is not that high
              Serial.println("Vdec");//Toward
            }
          }
        }
      }
      else {                                           //if the hand was there but removed after 400us i.e a swipe gesture, the play/pause the video
        Serial.println("Play/Pause");
      }
    }
  }
  else if(d1>=5 && d1<=45){                          //if the hand is there in front of the left sensor
    temp=millis();
    while(millis()<=(temp+400)){                     //check the position of hand after 400us this can be changed to your response time
      dist();                                       //get the distances now
      if(d2>=5 && d2<=45){                          //if your hand is there infront of right sensor i.e the hand was moved from left to right, it becomes true 
        Serial.println("Forward");                 //Forward message is printed
        left=1;                                    //make left as 1 so that we cannot use it later on further decision making                  
        break;
      }
    }
    if(left==0){                                    //if the left is 0 i.e. your hand moved only infront of left sensor, print rewind
      Serial.println("Rewind");
      dist();                                       //as we use if here we need to get the distance again in the bigger loop, and make left as 0 so that it can be used again in the loop 
    }
    left=0;//make left true
  }
  
}

void dist(){                                 //function to get the distance from left and right sensors
  
  digitalWrite(trig1,HIGH);                  //make trigger of right sensor high for 10us
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);                  //make it low for right sesnor low for 2us
  delayMicroseconds(2);
  duration=pulseIn(echo1,HIGH);             //get the time from echopin which is high, by using the ultrasonic sensor logic(8 pulses....)
  d2=(duration/20000)*340;                  //to calculate the distance in terms of cm using d=v*t
  
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  duration=pulseIn(echo2,HIGH);
  d1=(duration/20000)*340;

  if(d1>65 || d2>65){                  //if the distance measured in very high, then make them 0. This can be obtained directly by using pulsein(echo1,HIGH,5000) which only gets the distance in that time. if this is exceeded it gives 0.
    d1=0;
    d2=0;
  }
  //Serial.println(d1);            //while calibrating
  //Serial.print(d2);
  delay(100);
  
}
