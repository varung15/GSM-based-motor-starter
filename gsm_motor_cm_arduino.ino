//----------------Program developed by varun------------//
 int LED = 8;
int stat = 2;
int motor = 9;
int temp = 0;
int i = 0;
char str[15];
void setup()
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(LED, OUTPUT);
  digitalWrite(motor, LOW);
  digitalWrite(LED, LOW);
  delay(15000);

  Serial.println("AT+CNMI=2,2,0,0,0");
  delay(1000);
  Serial.println("AT+CMGF=1");
  delay(500);
  Serial.println("AT+CMGS=\"+919370556445\"\r"); // Replace x with mobile number
  delay(1000);
  Serial.println("System is ready to receive commands.");// The SMS text you want to send
  delay(100);
  Serial.println((char)26); // ASCII code of CTRL+Z
  delay(1000);
}
void loop()
{
  if (temp == 1)
  {
    check();
    temp = 0;
    i = 0;
    delay(1000);
  }
}
void serialEvent()
{
  while (Serial.available())
  {
    if (Serial.find("*"))
    {
      delay(1000);
      while (Serial.available())
      {
        char inChar = Serial.read();
        str[i++] = inChar;
        if (inChar == '*')
        {
          temp = 1;
          return;
        }
      }
    }
  }
}
void check()
{
  if (!(strncmp(str, "on", 2)))
  {
    digitalWrite(motor, HIGH);
    digitalWrite(LED, HIGH);
    stat = 1 ;
    delay(1000);
    Serial.println("AT+CMGS=\"+919370556445\"\r"); // Replace x with mobile number
    delay(1000);
    Serial.println("Motor Activated");// The SMS text you want to send
    delay(100);
    Serial.println((char)26); // ASCII code of CTRL+Z
    delay(1000);
  }
  else if (!(strncmp(str, "off", 3)))
  {
    digitalWrite(motor, LOW);
    digitalWrite(LED, LOW);
    stat = 2 ;
    delay(1000);
    Serial.println("AT+CMGS=\"+919370556445\"\r"); // Replace x with mobile number
    delay(1000);
    Serial.println("Motor deactivated");// The SMS text you want to send
    delay(100);
    Serial.println((char)26); // ASCII code of CTRL+Z
    delay(1000);
  }
  else if (!(strncmp(str, "cm", 2))) {
    Serial.println("AT+CMGD=1,4\n\r"); 
    delay(100); 
    Serial.println("AT+CMGS=\"+919370556445\"\r"); // Replace x with mobile number
    delay(1000);
    Serial.println("All message deleted");// The SMS text you want to send
    delay(100);
    Serial.println((char)26); // ASCII code of CTRL+Z
    delay(1000);
  }
  else if (!(strncmp(str, "ts", 2)))
  {
    if (stat == 1)
    {
      Serial.println("AT+CMGS=\"+919370556445\"\r"); // Replace x with mobile number
      delay(1000);
      Serial.println("The System is Working AND Motor is ON.");// The SMS text you want to send
      delay(100);
      Serial.println((char)26); // ASCII code of CTRL+Z
      delay(1000);
    }
    else if (stat == 2)
    {
      Serial.println("AT+CMGS=\"+919370556445\"\r"); // Replace x with mobile number
      delay(1000);
      Serial.println("The System is Working AND Motor is OFF.");// The SMS text you want to send
      delay(100);
      Serial.println((char)26); // ASCII code of CTRL+Z
      delay(1000);
    }


  }
  delay(1000);
}
//----------------Program developed by Varun G------------//
