int trig1 = 11;
int echo1=10;
int trig2 = 9;
int echo2=8;

float d1=0,d2=0;
float newd=0;
float duration=0;
unsigned long int temp=0;
int left=0;

void dist(void);

void setup() {
  // put your setup code here, to run once:
pinMode(trig1,OUTPUT);
pinMode(echo1,INPUT);
pinMode(trig2,OUTPUT);
pinMode(echo2,INPUT);
delay(1000);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  dist();
  if(d2>=5 && d2<=45){
    temp=millis();
    while(millis()<=(temp+400)){
      dist();
      if(d2>=5 && d2<=45){
        newd=d2;
        while(d2>=3 && d2<=50){
          dist();
          if((newd+5)<d2){
            if((d2-newd)>15){
              break;
            }
            else{
              Serial.println("Away");
            }
          }
          else if ((newd-5)>d2){
            if((newd-d2)>15){
              break;
            }
            else{
              Serial.println("Toward");
            }
          }
        }
      }
      else {
        Serial.println("Swipe");
      }
    }
  }
  else if(d1>=5 && d1<=45){
    temp=millis();
    while(millis()<=(temp+400)){
      dist();
      if(d2>=5 && d2<=45){
        Serial.println("Change");
        left=1;//make left false
        break;
      }
    }
    if(left==0){
      Serial.println("Previous");
      dist();
    }
    left=0;//make left true
  }
  
}

void dist(){
  
  digitalWrite(trig1,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig1,LOW);
  delayMicroseconds(2);
  duration=pulseIn(echo1,HIGH);
  d2=(duration/20000)*340;
  
  digitalWrite(trig2,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig2,LOW);
  delayMicroseconds(2);
  duration=pulseIn(echo2,HIGH);
  d1=(duration/20000)*340;

  if(d1>65 || d2>65){
    d1=0;
    d2=0;
  }
  //Serial.println(d1);
  //Serial.print(d2);
  delay(100);
  
}
