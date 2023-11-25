# FITVICTORY
## INTEGRANTES

FELIPE BRENO SUGISAWA ALTRAN – 94170

LUCAS VINICIUS OLIVEIRA GALINDO – 95177

MARCUS VINICIUS DAGOSTINI – 94279

THIAGO RIBEIRO DA COSTA – 92800

## Descrição
O projeto tem como objetivo ajudar as pessoas a monitorar a temperatura em tempo real e fazer parte de um aplicativo maior que visa promover um estilo de vida saudável. O projeto consiste em um dashboard que exibe a temperatura atual e o valor do potenciômetro. Essas informações são coletadas por meio de um ESP32, que utiliza um sensor DHT22 para medir a temperatura e um potenciômetro para obter um valor variável.

Além disso, o projeto está integrado a um aplicativo que notifica os usuários sobre as condições climáticas. Ao ter acesso à temperatura atual, os usuários podem planejar suas atividades diárias de forma mais eficiente e tomar medidas para garantir seu bem-estar.

## Tecnologias Utilizadas
<ul>
  <li>ESP32</li>
  <li>DHT22</li>
  <li>Potenciômetro</li>
  <li>Node-RED</li>
  <li>MQTT</li>
  <li>Plataforma Wokwi</li>
</ul>

## Uso

Para utilizar este projeto e monitorar a temperatura em tempo real, siga as etapas abaixo:

1. Faça o upload do código fornecido para o seu ESP32 utilizando a sua IDE de desenvolvimento Arduino.

2. Abra o arquivo `secrets.h` no seu editor de código e preencha as informações de rede Wi-Fi. Certifique-se de fornecer o nome da rede (SSID) e a senha corretamente.

3. Certifique-se de ter instalado as bibliotecas necessárias para este projeto. Você pode utilizar a biblioteca Manager da Arduino IDE para instalá-las. As bibliotecas necessárias são:
   - WiFi
   - DHT
   - PubSubClient

4. Conecte o ESP32 a uma fonte de energia e aguarde até que a conexão Wi-Fi seja estabelecida. O LED conectado ao pino 2 do ESP32 deve acender para indicar a conexão bem-sucedida.

5. O ESP32 começará a ler a temperatura e a umidade do sensor DHT22, bem como o valor do potenciômetro conectado ao pino 34.

6. Os valores lidos serão publicados em tópicos MQTT ("/ThinkIOT/temp", "/ThinkIOT/hum", "/ThinkIOT/pot") para que possam ser consumidos por outros dispositivos ou aplicativos.

7. Para receber os dados publicados pelo ESP32, você pode se inscrever nos tópicos MQTT correspondentes utilizando um cliente MQTT de sua escolha.

8. Utilize os valores publicados para monitorar a temperatura em tempo real e tomar as medidas necessárias com base nos dados recebidos.

Certifique-se de configurar corretamente as informações de rede Wi-Fi e MQTT no código antes de fazer o upload para o ESP32.


Link video funcionamento
https://youtu.be/vz1C5ZZAmUI


