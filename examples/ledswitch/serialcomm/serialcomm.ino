unsigned long time;

char *request;
String response;

int led = 13;

void setup() {
  Serial.setTimeout(20);
  Serial.begin(9600);
  
  time = millis();
  request = "";
  response = "";

  pinMode(led, OUTPUT);
}

void doAction(String& _response) {
  if (_response == "ledon") {
    digitalWrite(led, HIGH);
  } else if (_response == "ledoff") {
    digitalWrite(led, LOW);
  }
}

void loop()
{

  if ((millis() - time) > 1000) {
    Serial.write("Hello hi!\n");
    time = millis();
  }
          
  if (Serial.available()) {
    char ch = (char)Serial.read();
     
    if (ch == '\n') {
      doAction(response);
      response = "";
    } else {
      response += ch;
    }
  }
}

