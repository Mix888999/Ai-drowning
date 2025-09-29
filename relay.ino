// --- GPIO LED ---
const int greenPin = 27;
const int orangePin = 14;
const int redPin = 12;
const int buzzerPin = 13;

void setup() {
  Serial.begin(115200); // ต้องตรงกับ Python
  pinMode(greenPin, OUTPUT);
  pinMode(orangePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // ปิดทุก LED/Buzzer ตอนเริ่ม
  digitalWrite(greenPin, 1);
  digitalWrite(orangePin, 1);
  digitalWrite(redPin, 1);
  digitalWrite(buzzerPin, 1);

  Serial.println("รอรับค่าจาก Python (0=เขียว,1=ส้ม,2=แดง+บัซเซอร์)");
}

void loop() {
  if (Serial.available()) {
    int state = Serial.parseInt(); // อ่านเป็นตัวเลข
    Serial.print("State ที่รับมา: ");
    Serial.println(state);
    
    // เปิด LED ตาม state
    if (state == 0) {
      digitalWrite(greenPin, 0);
      digitalWrite(orangePin, 1);
      digitalWrite(redPin, 1);
      digitalWrite(buzzerPin, 1);
    }
    else if (state == 1) {
      digitalWrite(greenPin, 1);
      digitalWrite(orangePin, 0);
      digitalWrite(redPin, 1);
      digitalWrite(buzzerPin, 1);
    }
    else if (state == 2) {
      digitalWrite(greenPin, 1);
      digitalWrite(orangePin, 1);
      digitalWrite(redPin, 0);
      digitalWrite(buzzerPin, 0);
    }
    else if (state == 4) {
      digitalWrite(greenPin, 1);
      digitalWrite(orangePin, 1);
      digitalWrite(redPin, 1);
      digitalWrite(buzzerPin, 1);
    }
  }
}
