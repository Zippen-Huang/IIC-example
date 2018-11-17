#include <Wire.h>

char *c;
char cstr[20];//临时用于储存的字符数组
float tf_data[3]={-8.20,-0.35,-3.67};//需要通过IIC传输的数组
void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);
}

void loop() {
  delay(200);
//  c=arr_tf(tf_data,3);
//   arr_tf(tf_data,3,cstr);
//  Serial.println(strlen(c));
//  Serial.println("****");
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  char* s = arr_tf(tf_data,3);
  Wire.write(s,strlen(s)); 
//  delay(2);
//  delayMicroseconds(100);
}

char* arr_tf(float arr[],int n)//浮点数数组转字符数组
{
  int i;
  //char *_cstr = new char[20];
  cstr[20]="";
  for(i=0;i<n;i++)
  {
    char intel_char[]="";
    dtostrf(arr[i],2,2,intel_char);
    if(i==0)
    {
      strcpy(cstr,intel_char);
      }
     else{
      strcat(cstr,intel_char);
     }
     strcat(cstr,"X");
 //    delayMicroseconds(5);
  }
  Serial.println(cstr);
  return cstr;
}
