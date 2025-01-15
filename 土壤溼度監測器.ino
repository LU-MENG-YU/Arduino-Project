int sensorValue;        // 土壤溼度數值
int sensorPin = A0; 		// 設定土壤溼度檢測器腳位
int blueLED = 9;				// 設定藍LED腳位
int redLED = 8;					// 設定紅LED腳位
int buzzer = 7;					// 設定蜂鳴器腳位

void setup() {
  pinMode(sensorPin, INPUT);	// 設定土壤溼度檢測器為輸入
  pinMode(redLED, OUTPUT);		// 設定紅LED為輸出
  pinMode(blueLED, OUTPUT);		// 設定藍LED為輸出
  pinMode(buzzer, OUTPUT);		// 設定蜂鳴器為輸出
  
  // 開啟序列通訊
  Serial.begin(9600); 
}

void loop() {
  sensorValue = analogRead(sensorPin); 	// 讀取感測器回傳值
  Serial.print("value : ");							// 輸出字串"value : "
  Serial.println(sensorValue);					// 輸出數值(越高越乾，越低越濕)

  if(sensorValue>500){
    digitalWrite(redLED, HIGH);					// 紅LED亮
    digitalWrite(blueLED, LOW);					// 藍LED暗
    tone(buzzer, 1000);									// 蜂鳴器出聲
  }else {
    digitalWrite(redLED, LOW);					// 紅LED暗
    digitalWrite(blueLED, HIGH);				// 藍LED亮
    noTone(buzzer);							        // 關閉蜂鳴器
  }

  delay(100);									// 短暫延遲避免頻繁刷新
}
