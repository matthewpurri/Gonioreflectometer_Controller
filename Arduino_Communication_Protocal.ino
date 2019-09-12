int ARM_DIR = 2;  // 
int ARM_STOP = 3; // 
int TABLE_DIR = 4; //
int TABLE_STOP = 5; //

// Initialize input history 
char history = '1';
char data = '0';


void update_pins(char data){
  if (data == 'R'){
    digitalWrite(ARM_DIR, LOW);
  }
  else if (data == 'L'){
    digitalWrite(ARM_DIR, HIGH);
  }
  else if (data == 'S'){
    digitalWrite(ARM_STOP, LOW);
  }
  else if (data == 'G'){
    digitalWrite(ARM_STOP, HIGH);
  }
  else if (data == 'r'){
    digitalWrite(TABLE_DIR, HIGH);
  }
  else if (data == 'l'){
    digitalWrite(TABLE_DIR, LOW);
  }
  else if (data == 's'){
    digitalWrite(TABLE_STOP, LOW);
  }
  else if (data == 'g'){
    digitalWrite(TABLE_STOP, HIGH);
  }
}


void setup() {
  // Set up serial communication
  Serial.begin(19200);

  // Set-up pin functions
  pinMode(ARM_DIR, OUTPUT);
  pinMode(ARM_STOP, OUTPUT);
  pinMode(TABLE_DIR, OUTPUT);
  pinMode(TABLE_STOP, OUTPUT);

  // Initial conditions
  digitalWrite(ARM_DIR, LOW);
  digitalWrite(ARM_STOP, LOW);
  digitalWrite(TABLE_DIR, LOW);
  digitalWrite(TABLE_STOP, LOW);
}

void loop() {
  while (Serial.available()){
    data = Serial.read();
    if (data != history){
      update_pins(data);
    }
  }
}
