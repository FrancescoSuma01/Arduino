void setup() {
  pinMode(2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int stocazzo = analogRead(A0);
  Serial.println(stocazzo);
  delay (1000);
  digitalWrite(2,LOW);

  if (stocazzo < 10) {
    digitalWrite(2,HIGH);
  }
}
