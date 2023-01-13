void setup() {           	 
 
  // Motor_1 control pin initiate;
  pinMode(9, OUTPUT); // Speed control
  pinMode(8, OUTPUT); // dir
 
  // Motor_2 control pin initiate;   
  pinMode(11, OUTPUT);  // Speed control
  pinMode(13, OUTPUT); // dir
 
  //Enable the Motor Shield output;  
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);  

  // sensor inputs
  int l_sensor = 1; // left sensor
  int r_sensor = 3; // right sensor
  Serial.begin(9600);
  pinMode(l_sensor, INPUT);  // input sensors
  Serial.begin(9600);
  pinMode(r_sensor, INPUT);
}

void loop() {   
 
  int median = 375; // middle sensor value between white and black (white ~ 50, black ~ 700)
  int l_sensor = 1;
  int r_sensor = 3;
  int l_s = analogRead(l_sensor);  //Reading the value of each sensor
  Serial.println(l_s);
  int r_s = analogRead(r_sensor);
  Serial.println(r_s);

  if(l_s > median && r_s > median)  // if both left sensor and right sensor detect black, turn 180 degrees
  {
	stop(); // stop for 2 seconds once it reaches an endpoint
	delay(2000);  
	left(100);
	delay(2000);
  }
  else if(l_s > median) // if left sensor detects black, move left
  {
	left(200);
	delay(50);
  }
  else if(r_s > median) // if right sensor detects black, move right
  {
	right(200);
	delay(50);
  }

  else  // if both sensors detect white, move forward
  {

	forward(25);  // slower speed
	delay(50);
  }

  stop();   
 
}

void forward(int speed)
{
  analogWrite(9, speed);  // Set the speed of motor_1
  digitalWrite(8, LOW);  // Set the rotation of motor_1
  analogWrite(11, speed);  // Set the speed of motor_2
  digitalWrite(13, HIGH);  // Set the rotation of motor_2
}

void backward(int speed)
{
  analogWrite(9, speed);  // Set the speed of motor_1
  digitalWrite(8, HIGH);  // Set the rotation of motor_1
  analogWrite(11, speed);  // Set the speed of motor_2
  digitalWrite(13, LOW);  // Set the rotation of motor_2
}

void stop()
{
  analogWrite(9, 0);  // Set the speed of motor_1
  analogWrite(11, 0);  // Set the speed of motor_2
}

void left(int speed)
{
  analogWrite(9, speed);  // Set the speed of motor_1
  digitalWrite(8, HIGH);  // Set the rotation of motor_1
  analogWrite(11, speed);  // Set the speed of motor_2
  digitalWrite(13, HIGH);  // Set the rotation of motor_2
}

void right(int speed)
{
  analogWrite(9, speed);  // Set the speed of motor_1
  digitalWrite(8, LOW);  // Set the rotation of motor_1
  analogWrite(11, speed);  // Set the speed of motor_2
  digitalWrite(13, LOW);  // Set the rotation of motor_2
}
