# README #

compile with:

```
#!bash

g++ -o bin/guiMain S2WApp.cpp S2WMain.cpp SerialLink.cpp WebsocketLink.cpp `wx-config --cppflags` `wx-config --libs` -I /home/darevish/code/cpp/websocketpp/ -L /usr/lib/x86_64-linux-gnu/ -lboost_system -lboost_filesystem -lboost_thread
```

for testing serial comm:

```
#!bash

socat -d -d pty,raw,echo=0,b9600 pty,raw,echo=0,b9600

```
