# README #

compile with:

```
#!bash

g++ main.cpp SerialLink.cpp WebsocketLink.cpp -o bin/main -I /home/darevish/code/cpp/websocketpp/ -L /usr/lib/x86_64-linux-gnu/ -lboost_system
```

for testing serial comm:

```
#!bash

socat -d -d pty,raw,echo=0,b9600 pty,raw,echo=0,b9600

```
