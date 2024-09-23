#define LED_PIN2 13
#define LED_PIN1 12
#define LED_PIN3 11
#define ITER_TIME 6000
#define SWITCHING_GREEN_DELAY 2000
#define SWITCHING_TIME 500

long int cycle_start = 0;
long int start_green_switching = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN1, OUTPUT);
  pinMode(LED_PIN2, OUTPUT);
  pinMode(LED_PIN3, OUTPUT);
  cycle_start = millis();
}

void loop() {
  switch_leds();
}

void switch_leds(){
  if(millis() >= ITER_TIME * 3 + cycle_start){
    cycle_start = millis();
    turn_off_green();
  }
  else if(millis() >= ITER_TIME * 2 + SWITCHING_GREEN_DELAY + cycle_start){
    switching_green();
  }
  else if(millis() >= ITER_TIME * 2 + cycle_start){
    turn_on_green();
    turn_off_orange();
  }
  else if(millis() >= ITER_TIME + cycle_start){
    turn_on_orange();
    turn_off_red();
  }
  else if(millis() >= cycle_start){
    turn_on_red();
  }
}

void turn_on_red(){
  digitalWrite(LED_PIN1, HIGH);
}

void turn_on_orange(){
  digitalWrite(LED_PIN2, HIGH);
}

void turn_on_green(){
  digitalWrite(LED_PIN3, HIGH);
}

void turn_off_green(){
  digitalWrite(LED_PIN3, LOW);
}

void turn_off_orange(){
  digitalWrite(LED_PIN2, LOW);
}

void turn_off_red(){
  digitalWrite(LED_PIN1, LOW);
}

void switching_green(){
  if(start_green_switching == 0){
    start_green_switching = millis();
  }
  else if (millis() <= start_green_switching + SWITCHING_TIME){
    turn_off_green();
  }
  else if (millis() <= start_green_switching + 2 * SWITCHING_TIME){
    turn_on_green();
  }
  else {
    start_green_switching = millis();
  }
}
