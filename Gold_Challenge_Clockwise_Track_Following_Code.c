int leftIR1, rightIR1, leftIR2, rightIR2, obs_IR; // rightIR:0, leftIR:1, obs_IR:3 int rightf = 5,
rightb = 6;
int leftb = 7, leftf = 8;
int count = 0, flag = 1, pole = -1;
void setup()
{
for (int i = 5; i < 9; i++)
{


pinMode(i, OUTPUT);
}
serial.begin(9600);
stop();
}
void loop()
{
take_input(&rightIR1, &leftIR1); delay(5);
take_input(&rightIR2, &leftIR2);
if ((leftIR1 == leftIR2) && (rightIR1 == rightIR2))
{
if (rightIR1 == 1 && leftIR1 == 1)
{
forward();
if (pole == 0)
{
pole = 1;
}
}
else if (rightIR1 == 1 && leftIR1 == 0) left();
else if (rightIR1 == 0 && leftIR1 == 1) right();
else if (rightIR1 == 0 && leftIR1 == 0)
{
if (pole == -9)
{
stop();
Serial.print('X'); for (;;);

}



if (count == 9)
{
if (pole == 1) //Handling Parking Turn
left();
delay(500);
count = 0;
pole = -9;
}
else
{
right();
forward();
delay(50); pole = 0;
}
}
else if (count > 0) //Handling No Parking Turn
{
right();
forward();
delay(50);
}
else forward();
}
}
else
{
stop();



}
obstacle();
}
void obstacle()
{
obs_IR = analogRead(3);
(obs_IR > 10)

{
if (flag == 1)

{

count++;

stop();
delay(1000); flag = 0;
}

}

else

{
flag = 1;

}

}



void stop()
{
digitalWrite(rightf, LOW);
digitalWrite(rightb, LOW);
digitalWrite(leftf, LOW);
digitalWrite(leftb, LOW);
}
void forward()
{
digitalWrite(rightf, HIGH);
digitalWrite(rightb, LOW);
digitalWrite(leftf, HIGH);
digitalWrite(leftb, LOW); // delay(20);
}
void left()
digitalWrite(rightf, HIGH);
digitalWrite(rightb, LOW);
digitalWrite(leftf, LOW);
digitalWrite(leftb, HIGH); // delay(20);
}
void right()

{
digitalWrite(rightf, LOW);
digitalWrite(rightb, HIGH);
digitalWrite(leftf, HIGH);



digitalWrite(leftb, LOW); // delay(20);

}
void take_input(int *rightIR, int *leftIR)

{
*rightIR = analogRead(0);
*leftIR = analogRead(1); //serial_out(*rightIR,*leftIR);
mapping(rightIR, leftIR);

}
void serial_out(int rightIR, int leftIR)

{
Serial.print("rightIR : ");
Serial.println(rightIR);
Serial.print("leftIR : ");
Serial.println(leftIR); delay(500);

}
void mapping(int *rightIR, int *leftIR)

{
if (*rightIR < 10) *rightIR = 0;

else

*rightIR = 1; if (*leftIR < 10) *leftIR = 0;



else

*leftIR = 1;

}