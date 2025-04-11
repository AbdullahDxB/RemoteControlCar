#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
//#include <Servo.h>

#define SIGNAL_TIMEOUT 500  // This is signal timeout in milli seconds. We will reset the data if no signal

const uint64_t pipeIn = 0xF9E8F0F0E1LL;
RF24 radio(8, 9); 
unsigned long lastRecvTime = 0;
int lx,ly,lpot,switch1;
struct PacketData
{
  byte lxAxisValue;
  byte lyAxisValue;
  
  byte lPotValue;  
    
  byte switch1Value;

};
PacketData receiverData;


//Assign default input received values
void setInputDefaultValues()
{
  // The middle position for joystick. (254/2=127)
  receiverData.lxAxisValue = 127;
  receiverData.lyAxisValue = 127;

  receiverData.lPotValue = 0;  
  
  receiverData.switch1Value = LOW;

}

void mapAndWriteValues()
{
    lx=receiverData.lxAxisValue;
  ly=receiverData.lyAxisValue;
  lpot=receiverData.lPotValue;
  switch1=receiverData.switch1Value;

  analogWrite(2,lpot);
  analogWrite(7,lpot);
  
  if(lx<120)
  {
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW); 
  }
  else if(lx>130)
  {
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH); 
  }
  else if(ly<120)
  {

  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW); 
  }
  else if(ly>130)
  {

  digitalWrite(10,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH); 
  }
  else
  {

  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW); 
  }
  
}

void setup()
{
  radio.begin();
  radio.setDataRate(RF24_250KBPS);
  radio.openReadingPipe(1,pipeIn);
  radio.startListening(); //start the radio receiver 


  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT);      

  setInputDefaultValues();
  mapAndWriteValues();
  
}

void loop()
{
  // Check if RF is connected and packet is available 
  if(radio.isChipConnected() && radio.available())
  {
    radio.read(&receiverData, sizeof(PacketData)); 
    lastRecvTime = millis(); 
  }
  else
  {
    //Check Signal lost.
    unsigned long now = millis();
    if ( now - lastRecvTime > SIGNAL_TIMEOUT ) 
    {
      setInputDefaultValues();
      
    }
  }
  mapAndWriteValues();         
}
