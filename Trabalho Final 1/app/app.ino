// Biblioteca
#include <ESP8266WiFi.h>

// Configurando as credenciais do Wi-Fi
const char* ssid     = "REPKATAPULTA 2.4G"; //nome da rede
const char* password = "ced030797l"; //senha

//Configura o servidor web para a porta 80
WiFiServer server(80);

String header;

// Variaveis auxiliares para armazenar o estado dos leds
String output5State = "off";
String output4State = "off";

// Portas GPIO que vão ser utilizadas
const int output5 = D5; //LUZ do quarto
const int output4 = D4; //Luminaria

unsigned long currentTime = millis();
unsigned long previousTime = 0; 
const long timeoutTime = 2000;

//A função setup é rodada uma vez só no código
void setup() {
  //Configurando a comunicação serial
  Serial.begin(115200);
  // Definindo as portas GPIO como saidas
  pinMode(output5, OUTPUT);
  pinMode(output4, OUTPUT);
  // As portas vão sempre iniciar no estado LOW: desligado
  digitalWrite(output5, LOW);
  digitalWrite(output4, LOW);

  //Conexão ao Wi-Fi, se a conexão for bem sucedida ele imprime o IP do servidor 
  Serial.print("Conectado ao");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print do IP do servidor local
  Serial.println("");
  Serial.println("WiFi conectado.");
  Serial.println("Endereço de IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

//Loop é a função que vai ficar rodando enquanto o dispositivo estiver ligado
void loop(){
  WiFiClient client = server.available();   // Leitura do Cliente que entra no servidor
// Se uma nova conexão ocorrer,
  if (client) {                             
    Serial.println("Novo Usuario"); 
    String currentLine = "";
    currentTime = millis();
    previousTime = currentTime;
    while (client.connected() && currentTime - previousTime <= timeoutTime) {
      currentTime = millis();         
      if (client.available()) {             
        char c = client.read();             
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (currentLine.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();
            
            // Verifica qual botão é pressionado e indica o estado atual da porta
            if (header.indexOf("GET /5/on") >= 0) {
              Serial.println("GPIO 5 on");
              output5State = "on";
              digitalWrite(output5, HIGH);
            } else if (header.indexOf("GET /5/off") >= 0) {
              Serial.println("GPIO 5 off");
              output5State = "off";
              digitalWrite(output5, LOW);
            } else if (header.indexOf("GET /4/on") >= 0) {
              Serial.println("GPIO 4 on");
              output4State = "on";
              digitalWrite(output4, HIGH);
            } else if (header.indexOf("GET /4/off") >= 0) {
              Serial.println("GPIO 4 off");
              output4State = "off";
              digitalWrite(output4, LOW);
            }
            
            // Gerando a pagina do servidor web
            client.println("<!DOCTYPE html><html>"); //mostra que esta sendo enviado um html
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">"); //tornando a pagina responsiva
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // Estilo da pagina, configurando o tamanho dos botões e etc
            client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: #a1ba23; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: #c22e1d;}</style></head>");           
            // Titulo da pagina
            client.println("<body><h1>IOT COM WEB SERVER E ESP8266</h1>");
            //Mostra o estado da porta D5 
            client.println("<p>LUZ QUARTO - Estado " + output5State + "</p>");      
            if (output5State=="off") {
              client.println("<p><a href=\"/5/on\"><button class=\"button\">LIGAR</button></a></p>");
            } else {
              client.println("<p><a href=\"/5/off\"><button class=\"button button2\">DESLIGAR</button></a></p>");
            } 
               
            //Mostra o estado da porta D4  
            client.println("<p>LUMINARIA - Estado " + output4State + "</p>");       
            if (output4State=="off") {
              client.println("<p><a href=\"/4/on\"><button class=\"button\">LIGAR</button></a></p>");
            } else {
              client.println("<p><a href=\"/4/off\"><button class=\"button button2\">DESLIGAR</button></a></p>");
            }
            client.println("</body></html>");
        
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
      }
    }
    // Limpando a variavel
    header = "";
    // Encerrando conexão
    client.stop();
    Serial.println("Conexão encerrada");
    Serial.println("");
  }
}
