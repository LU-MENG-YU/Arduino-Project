int sensorValue;				// 土壤溼度數值
int sensorPin = A0; 		// 設定土壤溼度檢測器腳位
int redLED = 8;					// 設定LED腳位
int buzzer = 7;					// 設定蜂鳴器腳位

void setup() {
  pinMode(sensorPin, INPUT);	// 設定土壤溼度檢測器為輸入
  pinMode(redLED, OUTPUT);		// 設定LED為輸出
  pinMode(buzzer, OUTPUT);		// 設定蜂鳴器為輸出
  
  // 開啟序列通訊
  Serial.begin(9600); 
}

void loop() {
  sensorValue = analogRead(sensorPin); 	// 讀取感測器回傳值
  Serial.print("value : ");							// 輸出字串"value : "
  Serial.println(sensorValue);					// 輸出數值(越高越乾，越低越濕)

  while(sensorValue>500){								// 當濕度過低則進入while迴圈
    digitalWrite(redLED, HIGH);					// LED亮
    tone(buzzer, 1000);									// 蜂鳴器出聲
    delay(100);													// 延遲
    digitalWrite(redLED, LOW);					// LED暗
    noTone(buzzer);											// 蜂鳴器停止
    delay(100);													// 延遲(不然就會直接很快地跑回LED開那邊)
    
    sensorValue = analogRead(sensorPin);	// 重新檢測數值
    Serial.print("value : ");
    Serial.println(sensorValue);
  }

  digitalWrite(redLED, LOW);	// 當濕度恢復正常則脫離迴圈關閉LED
  noTone(buzzer);							// 關閉蜂鳴器
  delay(100);									// 短暫延遲避免頻繁刷新
}
