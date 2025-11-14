void TurnMotor(int Speed){
  FLeftSpeed = Speed-0;
  FRightSpeed = Speed-0;
  BLeftSpeed = Speed-0;
  BRightSpeed = Speed-0;
}
void Forward(int Speed, int Time){
  TurnMotor(Speed);
  motor(1, FLeftSpeed);
  motor(2, FRightSpeed);
  motor(3, BLeftSpeed);
  motor(4, BRightSpeed);
  delay(Time);
  AO();
}
void Backward(int Speed, int Time){
  TurnMotor(-Speed);
  motor(1, FLeftSpeed);
  motor(2, FRightSpeed);
  motor(3, BLeftSpeed);
  motor(4, BRightSpeed);
  delay(Time);
  AO();
}
void mecanum(int Speed) {
    int speedFL = Speed;  
    int speedRL = -Speed; 
    int speedFR = -Speed; 
    int speedRR = Speed;  
    // v -100 || 100 speed
    speedFL = constrain(speedFL, -100, 100);
    speedRL = constrain(speedRL, -100, 100);
    speedFR = constrain(speedFR, -100, 100);
    speedRR = constrain(speedRR, -100, 100);

    motor(1, speedFL);  
    motor(2, speedRL);  
    motor(3, speedFR);  
    motor(4, speedRR);  
}
void DapLeft(int Speed,int Time){
  TurnMotor(Speed);
  motor(1, -FLeftSpeed);
  motor(2, FRightSpeed);
  motor(3, BLeftSpeed);
  motor(4, -BRightSpeed);
  delay(Time);
  AO();
}
void DapRight(int Speed,int Time){
  TurnMotor(Speed);
  motor(1, FLeftSpeed);
  motor(2, -FRightSpeed);
  motor(3, -BLeftSpeed);
  motor(4, BRightSpeed);
  delay(Time);
  AO();
}
void Dap_on_Left(int Speed,int Time){
  TurnMotor(Speed);
  motor(1, 0);
  motor(2, FRightSpeed);
  motor(3, BLeftSpeed);
  motor(4, 0);
  delay(Time);
  AO();
}
void Dap_on_Right(int Speed,int Time){
  TurnMotor(Speed);
  motor(1, FLeftSpeed);
  motor(2, 0);
  motor(3, 0);
  motor(4, BRightSpeed);
  delay(Time);
  AO();
}
void Dap_down_Right(int Speed,int Time){
  TurnMotor(Speed);
  motor(1, 0);
  motor(2, -FRightSpeed);
  motor(3, -BLeftSpeed);
  motor(4, 0);
  delay(Time);
  AO();
}
void Dap_down_Left(int Speed,int Time){
  TurnMotor(Speed);
  motor(1, -FLeftSpeed);
  motor(2, 0);
  motor(3, 0);
  motor(4, -BRightSpeed);
  delay(Time);
  AO();
}
void TureRight(int Speed,int Time){
  TurnMotor(Speed - 20);
  motor(1, FLeftSpeed);
  motor(2, FRightSpeed);
  motor(3, -BLeftSpeed);
  motor(4, -BRightSpeed);
  delay(Time);
  AO();
}
void TureLeft(int Speed,int Time){
  TurnMotor(Speed - 20);
  motor(1, -FLeftSpeed);
  motor(2, -FRightSpeed);
  motor(3, BLeftSpeed);
  motor(4, BRightSpeed);
  delay(Time);
  AO();
}

