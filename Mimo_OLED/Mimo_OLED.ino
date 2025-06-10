#include <U8g2lib.h>
#include <WiFi.h>              // ESP32 Wi-Fi library
#include <Wire.h>              // I2C communication

int q = -15, r = 0, y = 0, z = 0;
volatile int skip = 1;
unsigned long PrevTime1 = 0, PrevTime2 = 0;
unsigned long CurrentTime1, CurrentTime2;
unsigned long CurrentTime3, PrevTime3 = 0;

// OLED setup
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);



// Wi-Fi Access Point credentials
const char *ssid = "Mimo_WiFi";
const char *password = "mimo1234";
WiFiServer server(80);

String getEmotion(String message) {
  message.toLowerCase();  // Convert to lowercase for case-insensitive comparison
  if (message.indexOf("happy") != -1 || message.indexOf("joy") != -1) return "happy";
  if (message.indexOf("sad") != -1 || message.indexOf("cry") != -1) return "sad";
  if (message.indexOf("angry") != -1 || message.indexOf("mad") != -1) return "angry";
 // if (message.indexOf("hey") != -1 || message.indexOf("how are you") != -1) return "hey";
  if (message.indexOf("blink") != -1 || message.indexOf("focus") != -1) return "focus";
  if (message.indexOf("upset") != -1 || message.indexOf("hurt") != -1) return "upset";
  if (message.indexOf("wonder") != -1 || message.indexOf("wow") != -1) return "wonder";
  //if (message.indexOf("cute") != -1 || message.indexOf("nice") != -1) return "cute";
  if (message.indexOf("you") != -1 || message.indexOf("mimo") != -1 || message.indexOf("what is your name") != -1 || message.indexOf("hi") != -1 || message.indexOf("hii") != -1) return "questioned";
  if (message.indexOf("owner") != -1 || message.indexOf("creator") != -1) return "Interogated";
  if (message.indexOf("suspicious") != -1 || message.indexOf("trust") != -1) return "suspicious";
 // if (message.indexOf("down") != -1 || message.indexOf("look down") != -1) return "down";
  //if (message.indexOf("look") != -1 || message.indexOf("look here") != -1) return "lool";
  //if (message.indexOf("left") != -1 || message.indexOf("look left") != -1) return "left";
  //if (message.indexOf("up") != -1 || message.indexOf("look up") != -1) return "up";
  return "empty";
}

String urlDecode(String message) {
  String decoded = "";
  for (unsigned int i = 0; i < message.length(); i++) {
    if (message.charAt(i) == '%') {
      String hex = message.substring(i + 1, i + 3);
      decoded += (char)strtol(hex.c_str(), NULL, 16);
      i += 2;
    } else if (message.charAt(i) == '+') {
      decoded += ' ';
    } else {
      decoded += message.charAt(i);
    }
  }
  return decoded;
}

//merging expression code 

// eye close expression


void sleepy();

// normal expression 
void normal(){
    u8g2.clearBuffer();    
  u8g2.drawRBox(8,12,50,35, 9);         
  u8g2.drawRBox(70,12,50,35,9);
    u8g2.sendBuffer();
}

void sad(){   
  for(int i=0;i<=15;i+=3){
    u8g2.clearBuffer();
        
    u8g2.drawRBox(8,18,50,29, 9);         
    u8g2.drawRBox(70,18,50,29,9);    
      u8g2.setDrawColor(0);    
   //                    14             25
    u8g2.drawTriangle(3, 14, 64, 14, 3, 21+i);    
    u8g2.drawTriangle(68, 14, 124, 21+i, 124, 14);  
  //                               25        
      u8g2.setDrawColor(1);
             
    u8g2.sendBuffer();    
        }
}

// upset expression 
void upset(){
//    if(!happy_state){
   u8g2.clearBuffer();
    
  u8g2.drawRBox(8,12,50,35, 9);         
  u8g2.drawRBox(70,12,50,35,9);    
   u8g2.setDrawColor(0); 
     
  u8g2.drawBox(8,q,50,35);         
  u8g2.drawBox(70,q,50,35); 
    u8g2.setDrawColor(1); 
    
    u8g2.sendBuffer();
// to make the smoth animation
//    if(q<=-7){  q+=3;  }
 //  }
}


// wonder expression with smoth animation
void wonder(){   
    while(1){
      u8g2.drawRBox(8,12,50,35, 9);         
  u8g2.drawRBox(70,12,50,35,9);
        
    for(int i=1;i<=10*skip;i+=4){
      u8g2.clearBuffer();
  u8g2.drawRBox(8,12+i,50,35-i, 9);         
  u8g2.drawRBox(70,12,50,35,9);
    u8g2.sendBuffer(); 
       }       
    delay(1600);
    
   for(int i=1;i<=10*skip;i+=4){
     u8g2.clearBuffer();
  u8g2.drawRBox(8,22-i,50,25+i, 9);         
  u8g2.drawRBox(70,12+i,50,35-i,9);    
    u8g2.sendBuffer();
    }
     delay(1600);
    }
}

void start_boot(){  
  u8g2.drawStr(1, 60, "He is such a great person");
  u8g2.drawRBox(8,12,50,35, 9);         
  u8g2.drawRBox(70,12,50,35,9);
        
    for(int i=1;i<=10*skip;i+=4){
      u8g2.clearBuffer();
      u8g2.drawStr(1, 60, "He is such a great person");
  u8g2.drawRBox(8,12+i,50,35-i, 9);         
  u8g2.drawRBox(70,12,50,35,9);
    u8g2.sendBuffer(); 
       }       
    delay(1600);
    
   for(int i=1;i<=10*skip;i+=4){
     u8g2.clearBuffer();
     u8g2.drawStr(1, 60, "He is such a great person");
  u8g2.drawRBox(8,22-i,50,25+i, 9);         
  u8g2.drawRBox(70,12+i,50,35-i,9);    
    u8g2.sendBuffer();
    }
     delay(1600);

    }

// happy expression with smoth animation 
void happy(){
  for(int i=62;i>58;i-=3){
    u8g2.clearBuffer();
    
  u8g2.drawRBox(8,12,50,35, 11);
  u8g2.drawRBox(70,12,50,35,11);
   u8g2.setDrawColor(0); 
      
    u8g2.drawDisc(33, i, 38, U8G2_DRAW_ALL);
//                33  62 38   draw all    
    u8g2.drawDisc(95, i, 38, U8G2_DRAW_ALL);     
    
  u8g2.setDrawColor(1);
  
    u8g2.sendBuffer();
   }
    //happy_state=true;
}

// angry expression
void angry(){
    for(int i=0;i<=15;i+=3){
    u8g2.clearBuffer();
  u8g2.drawRBox(8,18,50,29, 9);         
  u8g2.drawRBox(70,18,50,29,9);
    u8g2.setDrawColor(0);    
    u8g2.drawTriangle(3, 14, 64, 18+i, 124, 14);
    u8g2.setDrawColor(1);     
    u8g2.sendBuffer(); 
        }   
}
// string expression
void you(){    
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.drawStr(5, 15, "My name is Mimo");
    u8g2.drawStr(5, 30, "Nice to meet you :)");
    
    u8g2.sendBuffer();
}

// string expression
void youmademe(){

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB08_tf); 
    u8g2.drawStr(1, 15, "Are you interogaing me");
    u8g2.drawStr(1, 30, "The person who made me is");
    u8g2.drawStr(1, 45, "Granth Sidhant :) ");
    u8g2.drawStr(1, 60, "He is such a great person");
    u8g2.sendBuffer();

}

void blink();


void suspicious(){
    for(int i=0;i<=10;i+=3){
    u8g2.clearBuffer();
    u8g2.drawRBox(8,12,50,20, 9);         
    u8g2.drawRBox(70,12,50,20,9);    
    u8g2.setDrawColor(0);    
    u8g2.drawTriangle(12, 12, 64, 12+i, 107, 12);          
    u8g2.setDrawColor(1);     
    u8g2.sendBuffer();     
        }   
}

void down();

void left();

void empty(){
  u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_helvB08_tf); 
    u8g2.drawStr(1, 15, "Oh no, you got me!");
    u8g2.drawStr(1, 30, "I don't know that yet,");
    u8g2.drawStr(1, 45, "but I am always");
    u8g2.drawStr(1, 60, " learning!");
    u8g2.sendBuffer();
};

void noBlink(){
  while(1){
    u8g2.clearBuffer();    
  u8g2.drawRBox(8,12,50,35, 9);         
  u8g2.drawRBox(70,12,50,35,9);
  u8g2.sendBuffer();
  delay(3000);
  u8g2.drawRBox(0,0,0,0,0);         
  u8g2.drawRBox(0,0,0,0,0);   
  delay(1500);
  };
}



void drawFace(String emotion) {
  u8g2.clearBuffer();

  // Draw eyes
  //u8g2.drawCircle(32, 32, 8);  // Left eye
  //u8g2.drawCircle(96, 32, 8);  // Right eye

  // Pupils (centered for now, you can animate them later)
  //u8g2.drawDisc(32, 32, 3); // Left pupil
  //u8g2.drawDisc(96, 32, 3); // Right pupil

   if (emotion == "normal") {
    normal(); //
  } 
  // else if (emotion == "blink") {
  //   blink();
  // }
   else if (emotion == "sad") {
    sad(); 
  }
  else if (emotion == "upset") {
    upset(); 
  }
  else if (emotion == "wonder") {
    wonder(); 
  }
  else if (emotion == "happy") {
    happy(); 
  }
  else if (emotion == "focus") {
    normal(); // Surprised mouth (circle)
  }
  else if (emotion == "angry") {
    angry(); // Surprised mouth (circle)
  }
  else if (emotion == "questioned") {
    you(); // Surprised mouth (circle)
  }
  else if (emotion == "Interogated") {
    youmademe(); // Surprised mouth (circle)
  }
  else if (emotion == "suspicious") {
    suspicious(); // Surprised mouth (circle)
  }
  // else if (emotion == "down") {
  //   down(); // Surprised mouth (circle)
  // }
  // else if (emotion == "look") {
  //   look(); // Surprised mouth (circle)
  // }
  // else if (emotion == "left") {
  //   left(); // Surprised mouth (circle)
  // }
  // else if (emotion == "up") {
  //   up(); // Surprised mouth (circle)
  // }
   else {
    empty();
  }

  // Send the buffer to the display
  u8g2.sendBuffer();
}


void setup() {
  u8g2.begin();
  // Start serial communication
  Serial.begin(115200);
  // Set up Wi-Fi Access Point
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP Address: ");
  Serial.println(IP);

  // // Display Wi-Fi details on OLED
  // display.setTextSize(1);
  // display.setTextColor(SSD1306_WHITE);
  // display.setCursor(0, 0);
  // display.println("WiFi: Mimo_WiFi");
  // display.print("IP: ");
  // display.println(IP);
  // display.display();
  // delay(2000);
  // Start the server
  //start_boot();
  server.begin();
}



void loop() {
  // Check for client connection
  WiFiClient client = server.available();
  if (client) {
    String request = client.readString();
    Serial.println("Request: " + request);

    if (request.indexOf("POST /send") != -1) {
      // Extract POST body data
      int bodyStart = request.indexOf("\r\n\r\n") + 4;
      String body = request.substring(bodyStart);
      int messageStart = body.indexOf("message=") + 8;
      String message = body.substring(messageStart);
      message = urlDecode(message);

      String emotion = getEmotion(message);
      Serial.println("Message: " + message);
      Serial.println("Emotion: " + emotion);

      // Send response
      client.println("HTTP/1.1 200 OK");
      client.println("Content-type:text/html");
      client.println();
      client.println("<!DOCTYPE html>");
      client.println("<html>");
      client.println("<head><title>Mimo Response</title>");
      client.println("<style>");
      client.println("body { font-family: Arial, sans-serif; margin: 0; padding: 0; background-color: #f4f4f9; justify-content: center; align-items: flex-start; height: 100vh; }");
      client.println("h1 { text-align: center; color: #333; margin-top: 20px; }");
      client.println("a { display: block; text-align: center; margin-top: 20px; font-size: 18px; text-decoration: none; color: #0066cc; }");
      client.println("a:hover { color: #003366; }");
      client.println("</style>");
      client.println("</head>");
      client.println("<body>");
      client.println("<h1>Mimo is feeling " + emotion + "!</h1><br>");
      client.println("<br><a href='/emotions'>See Emotions</a><br>");
      client.println("<br><a href='/'>Go Back</a>");
      client.println("</body>");
      client.println("</html>");
      client.println();
      client.stop();

      // Update OLED display
      drawFace(emotion);
    } else if (request.indexOf("GET /emotions") != -1) {
      // Serve the page with buttons for each emotion
      client.println("HTTP/1.1 200 OK");
      client.println("Content-type:text/html");
      client.println();
      client.println("<!DOCTYPE html>");
      client.println("<html>");
      client.println("<head><title>Select Emotion</title>");
      client.println("<style>");
      client.println("body { font-family: Arial, sans-serif; background-color: #f4f4f9; color: #333; margin: 0; padding: 0; display: flex; justify-content: center; align-items: flex-start; height: 100vh; flex-direction: column; }");
      client.println("h1 { text-align: center; color: #0066cc; margin-bottom: 20px; }");
      client.println("button { padding: 15px 25px; font-size: 18px; background-color: #0066cc; color: white; border: none; cursor: pointer; margin: 10px 0; border-radius: 5px; width: 250px; }");
      client.println("button:hover { background-color: #003366; }");
      client.println("a { text-align: center; margin-top: 30px; font-size: 18px; text-decoration: none; color: #0066cc; }");
      client.println("a:hover { color: #003366; }");
      client.println("</style>");
      client.println("</head>");
      client.println("<body>");
      client.println("<h1>Wonder how Mimo reacts</h1>");
      client.println("<form action='/send' method='POST'>");
      client.println("<button type='submit' name='message' value='happy'>Happy</button>");
      client.println("<button type='submit' name='message' value='sad'>Sad</button>");
      client.println("<button type='submit' name='message' value='angry'>Angry</button>");
      client.println("<button type='submit' name='message' value='upset'>Upset</button>");
      client.println("<button type='submit' name='message' value='wonder'>Wonder</button>");
      //client.println("<button type='submit' name='message' value='cute'>Cute</button>");
      client.println("<button type='submit' name='message' value='you'>Who are you?</button>");
      client.println("<button type='submit' name='message' value='creator'>Who made you?</button>");
      client.println("<button type='submit' name='message' value='suspicious'>Suspicious</button>");
      client.println("</form>");
      client.println("<a href='/'>Back to Home</a>");
      //client.println("<button onclick="goBack()">Go Back</button>");
      //client.printlnclient.println("<script>function goBack() {window.history.back();}</script>");
      client.println("</body>");
      client.println("</html>");
      client.println();
      client.stop();
    } else {
      // Serve the home page
      client.println("HTTP/1.1 200 OK");
      client.println("Content-type:text/html");
      client.println();
      client.println("<!DOCTYPE html>");
      client.println("<html>");
      client.println("<head><title>Mimo</title>");
      client.println("<style>");
      client.println("body { font-family: Arial, sans-serif; background-color: #f4f4f9; color: #333; margin: 0; padding: 0; display: flex; justify-content: center;height: 100vh; flex-direction: column; }");
      client.println("h1 { text-align: center; color: #0066cc; margin-bottom: 20px; }");
      client.println("form { display: flex; justify-content: center; flex-direction: column; margin-top: 20px; align-items: center; }");
      client.println("input[type='text'] { padding: 12px; font-size: 18px; margin-right: 10px; width: 80%; max-width: 400px; border-radius: 5px; border: 1px solid #ccc; }");
      client.println("input[type='submit'] { padding: 12px 25px; font-size: 18px; background-color: #0066cc; color: white; border: none; cursor: pointer; border-radius: 5px; }");
      client.println("input[type='submit']:hover { background-color: #003366; }");
      client.println("a { display: block; text-align: center; margin-top: 20px; font-size: 18px; text-decoration: none; color: #0066cc; }");
      client.println("a:hover { color: #003366; }");
      client.println("</style>");
      client.println("</head>");
      client.println("<body>");
      client.println("<h1>Chat with Mimo here :)</h1>");
      client.println("<form action='/send' method='POST'>");
      client.println("Message: <input type='text' name='message'><br>");
      client.println("<input type='submit' value='Send'>");
      client.println("</form>");
      client.println("<br><a href='/emotions'>See Emotions</a>");
      client.println("</body>");
      client.println("</html>");
      client.println();
      client.stop();
    }
  }
}
