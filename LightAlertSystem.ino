// تعريف البنات
const int ldrPin = A0;                   // حساس الضوء
const int greenLedPin = 2;               // الليد الأخضر (في الضوء)
const int warningLeds[] = {3, 4, 5, 6, 7}; // الليدات التحذيرية
const int buzzer = 8;                    // البازار

void setup() {
  pinMode(greenLedPin, OUTPUT);         // الليد الأخضر

  // تهيئة الليدات التحذيرية
  for (int i = 0; i < 5; i++) {
    pinMode(warningLeds[i], OUTPUT);
  }

  pinMode(buzzer, OUTPUT);              // تهيئة البازار
  Serial.begin(9600);                   // للمراقبة عبر السيريل
}

void loop() {
  int sensorValue = analogRead(ldrPin);  // قراءة من حساس الضوء
  int darkness = map(sensorValue, 1023, 0, 0, 100);  // تحويلها لنسبة مئوية

  Serial.print("Darkness: ");
  Serial.print(darkness);
  Serial.println("%");

  // لو في نور كفاية (نسبة الظلام أقل من 30%)
  if (darkness < 30) {
    digitalWrite(greenLedPin, HIGH); // شغل الليد الأخضر
    // اطفي باقي الليدات والبازار
    for (int i = 0; i < 5; i++) {
      digitalWrite(warningLeds[i], LOW);
    }
    digitalWrite(buzzer, LOW);
  } 
  else {
    digitalWrite(greenLedPin, LOW); // طفي الليد الأخضر

    // عدد الليدات اللي تنور حسب نسبة الظلام
    int ledsToLight = 0;
    if (darkness >= 70) {
      ledsToLight = 5;
      digitalWrite(buzzer, HIGH);  // شغل البازار
    } else {
      ledsToLight = (darkness - 30) / 10 + 1; // كل 10% تزود ليد
      digitalWrite(buzzer, LOW);
    }

    // شغل العدد المطلوب من الليدات
    for (int i = 0; i < 5; i++) {
      if (i < ledsToLight) {
        digitalWrite(warningLeds[i], HIGH);
      } else {
        digitalWrite(warningLeds[i], LOW);
      }
    }
  }

  delay(200); // تأخير بسيط
}
