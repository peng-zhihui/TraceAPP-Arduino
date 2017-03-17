/*******************************************
一个个人小项目，配套APP下载以及相关教程见
http://pengzhihui.xyz/2016/05/05/trace/
*******************************************/

#include <TraceApp.h>

SoftwareSerial mySerial(10, 11); // RX为D10, TX为D11，可以自己任意修改
TraceApp obj((SoftwareSerial&)mySerial, 9600);  //实例化检测对象

void setup()
{
  obj.begin();      //初始化
  Serial.begin(9600);  //硬件串口用于调试
}

void loop()
{
  obj.routine();    //尽可能让这一句频繁运行

  if (obj.valid())  //检测的物体是否有效
  {
    Serial.print("Obj detected at:");
    Serial.print(obj.getX());  //x坐标
    Serial.print(",");
    Serial.print(obj.getY());  //y坐标
    Serial.print("  with size of:");
    Serial.println(obj.getT()); //物体大小
  }
  else
    Serial.println("No obj or too many detected");

  delay(100);
}