#include <SoftwareSerial.h>
#define _HBAUD 9600 //硬件串口波特率
#define _SBAUD 9600 //软件串口波特率
#define _Terminator '\n' //硬件串口终止符
#define _TerminatorSS "\r\n" //软件串口终止符(连接的模块所使用的终止符)
SoftwareSerial SSerial(2, 3);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(_HBAUD);
  SSerial.begin(_SBAUD);
  delay(50);
  Serial.println("START");
}

void loop() {
  // put your main code here, to run repeatedly:
  ReceiveSerialData();
  ReceiveSoftwareSerialData();
}


/**
  接收串口通信数据
*/
void ReceiveSerialData() {
  String temp_s = "";
  char temp_c;

  if (Serial.available() <= 0)
    return;
  while (Serial.available() > 0)
  {
    temp_c = char(Serial.read()); //单字节读取串口数据
    if (temp_c == _Terminator) { //判断是否为终止符
      break;
    } else {
      temp_s += temp_c;
    }
    delay(2);
  }
  SSerial.print(temp_s);
  SSerial.print(_TerminatorSS);
}

/**
  接收软串口通信数据
*/
void ReceiveSoftwareSerialData() {
  String temp_s = "";
  char temp_c;

  if (SSerial.available() > 0) {
    Serial.print("[SSerial-BEGIN]\n\t|");
    while (SSerial.available() > 0)
    {
      temp_c = SSerial.read();
      temp_s += temp_c;
      delay(2);
    }
    temp_s.replace("\n\n", "\n");
    temp_s.replace("\n", "\n\t|");
    Serial.print(temp_s);
    Serial.print(_Terminator);
    Serial.print("[SSerial-END]");
    Serial.print(_Terminator);
  }
}
