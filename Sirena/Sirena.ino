int blu = 2;
int rosso = 3;

void setup() {
 pinMode (blu, OUTPUT); 
 pinMode (rosso, OUTPUT); 
}

void loop() {
 digitalWrite (rosso, HIGH);
 digitalWrite (4, HIGH);
 delay (500);
 digitalWrite (rosso, LOW);
 digitalWrite (4, LOW);
 delay (50);
 digitalWrite (blu, HIGH);
 digitalWrite (4, HIGH);
 delay (500);
 digitalWrite (blu, LOW);
 digitalWrite (4, LOW);
}
