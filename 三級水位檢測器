// 定義接腳
int sensorPin = A0;   // 水位感測器接腳
int redLED = 10;      // 低水位紅燈
int blueLED = 9;      // 中水位藍燈
int greenLED = 8;     // 高水位綠燈
int buzzer = 7;       // 蜂鳴器

// 初始化變數
int waterLevel = 0;          // 水位數值
String levelStatus = "";     // 水位等級
String lastLevelStatus = ""; // 上次的水位等級

void setup() {
  // 水位感測器接在A0為預設輸入腳位因此不用設定
  // 設定接腳為輸出
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // 開啟序列通訊
  Serial.begin(9600);
}

void loop() {
  // 讀取水位感測器值
  waterLevel = analogRead(sensorPin);

  // 將數值轉換為水位等級並設定燈亮與蜂鳴器
  if (waterLevel > 600) {         // 高水位
    levelStatus = "High";         // 設定水位等級"High"
    digitalWrite(greenLED, LOW);  // 綠燈亮 (用負極接腳位所以是LOW)
    digitalWrite(blueLED, HIGH);  // 藍燈暗
    digitalWrite(redLED, HIGH);   // 紅燈暗
    digitalWrite(buzzer, HIGH);   // 蜂鳴器不叫
    noTone(buzzer);
  } else if (waterLevel > 500) {  // 中水位 (其餘同上)
    levelStatus = "Medium";
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, LOW);   // 藍燈亮
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
    noTone(buzzer);
  } else {                        // 低水位 (其餘同上)
    levelStatus = "Low";
    digitalWrite(greenLED, HIGH);
    digitalWrite(blueLED, HIGH);
    digitalWrite(redLED, LOW);    // 紅燈亮
    tone(buzzer, 1000);           // 蜂鳴器警報
  }

  // 如果水位等級改變，才在序列監視器上顯示 (現在的等級不等於前一次紀錄的等級)
  if (levelStatus != lastLevelStatus) {
    if (levelStatus == "Low") {               // 如果是低水位就先彈出警告 (用來分隔)
      Serial.println("---!!!WARNING!!!---");
    }
    Serial.print("Water Level: ");    // 顯示字串"Water Level: "
    Serial.println(levelStatus);      // 顯示水位等級
    Serial.print("Sensor Value: ");   // 顯示字串"Sensor Value: "
    Serial.println(waterLevel);       // 顯示水位檢測器數值

    // 將現在的等級更新為上次顯示的水位等級 (紀錄)
    lastLevelStatus = levelStatus;
  }

  // 短暫延遲，避免頻繁刷新
  delay(100);
}
