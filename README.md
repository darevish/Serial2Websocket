# README #

### !!!

This repo can exist beacause it is a time to learn some C++, so if you are looking for some production quiality stuff and got here by accident, then simply go away :) Although recommending me some tutorials (or books) - which were useful for you when you were learning the basics - would be highly appriciated. 

### Description

A tunnel with a serial port on one end and a websocket server on the other, so communication between a serial device (an arduino in my case) and a browser becomes easier.

**dependencies**
  * Boost
  * wxWidgets
  * [WebSocket++](http://www.zaphoyd.com/websocketpp)

**compile with:**

```
g++ -o bin/Serial2Websocket S2WApp.cpp S2WMain.cpp SerialLink.cpp WebsocketLink.cpp `wx-config --cppflags` `wx-config --libs` -I <path_to_websocketpp> -L <path_to_boost_headers> -lboost_system -lboost_filesystem -lboost_thread
```

**for testing serial comm:**

```
socat -d -d pty,raw,echo=0,b9600 pty,raw,echo=0,b9600

```
