# Portal cativo com ESP32

Projeto didático para criar um ponto de acesso Wi-Fi com um ESP32 e exibir uma página HTML hospedada no próprio dispositivo. O portal serve uma página local e não coleta credenciais nem fornece acesso à internet. Porém foi criado para um trabalho demonstrativo de Cybersegurança, com o objetivo de se passar por uma página de phising. Há algumas imagens no repositório do projeto, caso queira conferir.

## Requisitos

- Placa ESP32 compatível, como ESP32 Dev Module
- Arduino IDE 1.8.19 ou compatível
- Pacote de placas ESP32 instalado na Arduino IDE
- Bibliotecas `WiFi`, `DNSServer` e `WebServer` incluídas no pacote ESP32

## Configuração

1. Abra o arquivo `.ino` do projeto na Arduino IDE.
2. Altere a variável `ssid` para o nome desejado para o ponto de acesso.
3. Insira seu HTML no conteúdo armazenado em `pagina`, entre `R"HTML(` e `)HTML"`.
4. Selecione **ESP32 Dev Module** em **Ferramentas → Placa**.
5. Selecione a porta serial correta e carregue o programa no ESP32.

O HTML é armazenado na memória flash usando `PROGMEM`. Para manter o sketch simples, a página deve estar embutida no código. Imagens, estilos ou scripts externos podem não carregar quando o dispositivo cliente não tiver outra conexão à internet.

## Como usar

1. Ligue o ESP32.
2. No celular ou computador, conecte-se à rede Wi-Fi configurada em `ssid`.
3. Aguarde a notificação de portal cativo ou abra `http://192.168.4.1` no navegador.

O ESP32 responde às requisições DNS dos clientes com seu endereço local e exibe a página configurada. O portal funciona na rede local criada pelo ESP32; iniciar um ponto de acesso não compartilha automaticamente a internet.

## Segurança e privacidade

Use o projeto em dispositivos e redes sob sua responsabilidade.** Identifique a página como parte de um laboratório**, não imite páginas de serviços de terceiros e não solicite ou armazene senhas ou outros dados pessoais.

## Solução de problemas

- **Erro de tipo no SSID:** declare a variável como string, por exemplo `const char* ssid = "nome_da_wifI";`.
- **Página não aparece automaticamente:** alguns sistemas não abrem portais cativos automaticamente. Acesse `http://192.168.4.1` manualmente.
- **HTML não compila:** confira se os delimitadores `R"HTML(` e `)HTML"` estão presentes e se o delimitador `HTML` não aparece dentro do conteúdo da página.
- **Biblioteca `WiFi.h`:** use a fornecida pelo pacote de placas ESP32 selecionado na Arduino IDE.

  ~~~  by @phmunari 2026 ~~
