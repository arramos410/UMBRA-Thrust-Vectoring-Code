const int sensorPin = A0;

//kman vars
float measError =0.03901145;  //measurement error determined through variance function in Excel


//Step 1: guess on process value until responds fast enough and doesn't bounch as high
//Step 2. recalculate measurement value
//Step 3. Repeat steps 1 and 2 until barely change

float varProcess = 1e-3; //start out with assumption, then adjust later after experimentation (they pulled this out of their ass)
//varProcess notes:
//high value = faster but less accurate
//low value = slower but more accurate
float estError = 0.0;
float K = 0.0;  //Kalman Gain
float P = 1.0;
float Xp = 0.0;
float Zp = 0.0;
float Xe = 0.0;


void setup() {
  Serial.begin(9600);

}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = sensorVal * 5.0 / 1023.0;

  //kman process
  estError = P + varProcess;
  K = estError / (estError + measError);
  P = (1-K)*estError;

  Xp = Xe;
  Zp = Xp;
  Xe = Xp + K*(voltage - Zp);

  //Xp = Estimate_t-1
  //Xe = Estimate_t
  //voltage = Measurement
  //Zp = Estimate_t-1

  //Serial.print("voltage: ");
  //Serial.println(voltage);
  
  //Serial.print("Xe: ");

  Serial.print(voltage);
  Serial.print(",");
  Serial.println(Xe);
  
  delay(20);
  
}
