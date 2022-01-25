// #include "defs.h"

// FirebaseData fbdo;

// FirebaseAuth auth;
// FirebaseConfig config;

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// DHT dht(DHTPIN, DHTTYPE);

// AsyncWebServer server(SRV_PORT);

// String readDHTTemperature()
// {
//   float t = dht.readTemperature();

//   if (isnan(t))
//   {
//     Serial.println("Falha ao ler temperatura, entre em contato no WhatsApp (41)99799-2514");
//     return "--";
//   }
//   else
//   {
//     Serial.println(t);
//     return String(t);
//   }
// }

// String readDHTHumidity()
// {
//   float h = dht.readHumidity();
//   if (isnan(h))
//   {
//     Serial.println("Falha ao ler umidade relativa, entre em contato no WhatsApp (41)99799-2514");
//     return "--";
//   }
//   else
//   {
//     Serial.println(h);
//     return String(h);
//   }
// }

// String readAlarmStatus(){
//   int a = digitalRead(14);
//   return String(a);
// }

// const char index_html[] PROGMEM = R"rawliteral(
// <!DOCTYPE HTML><html>
// <head>
//   <meta name="viewport" content="width=device-width, initial-scale=1">
//   <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" integrity="sha384-fnmOCqbTlWIlj8LyTjo7mOUStjsKC4pOpQbqyi7RrhN7udi9RwhKkMHpvLbHG9Sr" crossorigin="anonymous">
//   <style>
//     html {
//      font-family: Arial;
//      display: inline-block;
//      margin: 0px auto;
//      text-align: center;
//     }
//     h2 { font-size: 3.0rem; }
//     p { font-size: 3.0rem; }
//     .units { font-size: 1.2rem; }
//     .dht-labels{
//       font-size: 1.5rem;
//       vertical-align:middle;
//       padding-bottom: 15px;
//     }
//   </style>
// </head>
// <body>
//   <h2>RiseTech CPD Care</h2>
//   <p>
//     <i class="fas fa-thermometer-half" style="color:#059e8a;"></i> 
//     <span class="dht-labels">Temperatura</span> 
//     <span id="temperature">%TEMPERATURE%</span>
//     <sup class="units">&deg;C</sup>
//   </p>
//   <p>
//     <i class="fas fa-tint" style="color:#00add6;"></i> 
//     <span class="dht-labels">Umidade</span>
//     <span id="humidity">%HUMIDITY%</span>
//     <sup class="units">&percnt;</sup>
//     <p>
//     <i class="fas fa-fire-alt" style="color:red;"></i> 
//     <span class="dht-labels">Alarme</span>
//     <span id="alarm">%ALARM%</span>
//   </p></p>
// </body>
// <script>
// setInterval(function ( ) {
//   var xhttp = new XMLHttpRequest();
//   xhttp.onreadystatechange = function() {
//     if (this.readyState == 4 && this.status == 200) {
//       document.getElementById("temperature").innerHTML = this.responseText;
//     }
//   };
//   xhttp.open("GET", "/temperature", true);
//   xhttp.send();
// }, 5000 ) ;

// setInterval(function ( ) {
//   var xhttp = new XMLHttpRequest();
//   xhttp.onreadystatechange = function() {
//     if (this.readyState == 4 && this.status == 200) {
//       document.getElementById("humidity").innerHTML = this.responseText;
//     }
//   };
//   xhttp.open("GET", "/humidity", true);
//   xhttp.send();
// }, 5000 ) ;

// setInterval(function ( ) {
//   var xhttp = new XMLHttpRequest();
//   xhttp.onreadystatechange = function() {
//     if (this.readyState == 4 && this.status == 200) {
//       document.getElementById("alarm").innerHTML = this.responseText;
//     }
//   };
//   xhttp.open("GET", "/alarm", true);
//   xhttp.send();
// }, 5000 ) ;
// </script>
// </html>)rawliteral";

// String processor(const String &var)
// {
//   if (var == "TEMPERATURE")
//   {
//     return readDHTTemperature();
//   }
//   else if (var == "HUMIDITY")
//   {
//     return readDHTHumidity();
//   }
//   else if (var == "ALARM")
//   {
//     return readAlarmStatus();
//   }
//   return String();
// }

// WiFiManager wifiManager; //Objeto de manipulação do wi-fi

// //callback que indica que o ESP entrou no modo AP
// void configModeCallback(WiFiManager *myWiFiManager)
// {
//   Serial.println("Entrou no modo de configuração");
//   Serial.println(WiFi.softAPIP());                      //imprime o IP do AP
//   Serial.println(myWiFiManager->getConfigPortalSSID()); //imprime o SSID criado da rede
// }

// //Callback que indica que salvamos uma nova rede para se conectar (modo estação)
// void saveConfigCallback()
// {
//   Serial.println("Configuração salva");
// }

// void setup()
// {

//   Serial.begin(115200);

//   dht.begin();

//   if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
//   {
//     Serial.println(F("SSD1306 não localizado"));
//     for (;;);
//   }
//   display.clearDisplay();
//   display.setTextColor(WHITE);

//   //Definição dos pinos
//   pinMode(13, INPUT);
//   pinMode(2, OUTPUT);
//   pinMode(32, OUTPUT);

//   //LEDs apagados
//   digitalWrite(2, LOW);
//   digitalWrite(32, LOW);

//   //callback para quando entra em modo de configuração AP
//   wifiManager.setAPCallback(configModeCallback);
//   //callback para quando se conecta em uma rede, ou seja, quando passa a trabalhar em modo estação
//   wifiManager.setSaveConfigCallback(saveConfigCallback);

//   server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
//             { request->send_P(200, "text/html", index_html, processor); });

//   server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request)
//             { request->send_P(200, "text/html", readDHTTemperature().c_str()); });

//   server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request)
//             { request->send_P(200, "text/html", readDHTHumidity().c_str()); });

//   server.on("/alarm", HTTP_GET, [](AsyncWebServerRequest *request){
//       request->send_P(200, "text/html", readAlarmStatus().c_str()); });
  
// }

// void showDHTInfo(){

//   float t = dht.readTemperature();
//   float h = dht.readHumidity();

//     display.drawRoundRect(0,16,60,35,2, WHITE);
//     display.setCursor(3, 20);
//     display.setTextSize(1);
//     display.print("Temp(");
//     display.cp437(true);
//     display.write(167);
//     display.print("C)");
//     display.setTextSize(2);
//     display.setCursor(3, 34);
//     if(!isnan(t)){
//       display.print(t,1);
//     } else {
//       display.print("-- ");
//     };
//     //Umidade
//     display.drawRoundRect(68,16,60,35,2, WHITE);

//     display.setCursor(71, 20);
//     display.setTextSize(1);
//     display.print("UR(%)");
//     display.setTextSize(2);
//     display.setCursor(71,34);
//     if(!isnan(h)){
//       display.print(h,1);
//     } else {
//       display.print("--");
//     };
//     display.display();
// }

// void showAPMode(){
//   display.clearDisplay();
//   display.setCursor(23, 0);
//   display.setTextSize(2);
//   display.print("MODO AP");
//   display.setTextSize(1);
//   display.setCursor(0,20);
//   display.print("SSID: RT-CPD CARE");
//   display.setCursor(0,32);
//   display.print("Senha: 12345678");
//   display.setCursor(0,44);
//   display.print("IP: 192.168.4.1");
//   display.display();
// }

// void showConnected(){
//   display.clearDisplay();
//   display.setCursor(10, 0);
//   display.setTextSize(2);
//   display.print("CONECTADO!");
//   display.setTextSize(1);
//   display.setCursor(0,32);
//   display.print("REINICIANDO...");

//   display.display();
// }

// void showAlarm(){
  
//   display.clearDisplay();
//   display.setCursor(28, 1);
//   display.invertDisplay(1);
//   display.setTextSize(2);
//   display.print("ALARME");
//   //display.setTextSize(1);
//   display.setCursor(17,35);
//   display.print("INCENDIO");
//   display.invertDisplay(1);
//   delay(1000);
//   display.invertDisplay(0);
//   delay(1000);
//   display.display();
// }

// void initDisplay(){
//   display.clearDisplay();
//     display.setCursor(0, 0);
//     display.setTextSize(1);
//     display.print(WiFi.localIP());
//     display.print(":");
//     display.print(SRV_PORT);
//     //Temperatura
//     showDHTInfo();
// }

// void loop()
// {

//   if (digitalRead(ALARMPIN) == LOW){
//     digitalWrite(2, HIGH);
//     Serial.println("ALARME DISPARADO!");
//     showAlarm();
//   } else {
//     digitalWrite(2, LOW);
//     display.invertDisplay(0);
    

//   if (WiFi.status() == WL_CONNECTED)
//   { //Se conectado na rede
//     server.begin();
//     initDisplay();
//     }
//   else
//   {                       //se não conectado na rede
//     digitalWrite(2, LOW); //Apaga LED AZUL

//     display.clearDisplay();
//     display.setCursor(23, 0);
//     display.setTextSize(2);
//     display.print("OFFLINE");
//     //Temperatura
//     showDHTInfo();

//     wifiManager.autoConnect(); //Função para se autoconectar na rede
//   }
//   }
  
//   //Se o botão for pressionado
//   if (digitalRead(APMODEPIN) == LOW)
//   {
//     //digitalWrite(2, HIGH);
//     showAPMode();
//     wifiManager.resetSettings();       //Apaga rede salva anteriormente
//     if (!wifiManager.startConfigPortal("RT-CPD CARE", "12345678"))
//     {                                      //Nome da Rede e Senha gerada pela ESP
//       Serial.println("Falha ao conectar"); //Se caso não conectar na rede mostra mensagem de falha
//       delay(2000);
//       ESP.restart(); //Reinicia ESP após não conseguir conexão na rede
//     }
//     else
//     { //Se caso conectar
//       showConnected();
//       Serial.print("Conectado na rede: ");
//       Serial.println(wifiManager.getSSID());
//       ESP.restart(); //Reinicia ESP após conseguir conexão na rede
//     }
//   }
// }
