# ClientSock
> a class that can be used to connect to if_Net sockets

>in this context its being Used to connect to the database.

## constructor

|name|type|description|
|----|----|-----------|
|address|string| the address used for the socket ex: localhost, 27.0.0.1, www.google.com
|port| int| the port number for the connection ex: 8080|

## functions

|name|return value| description|
|---|-------|----------|
|read|string| read input from the server of a specific size|
|write|void| writes data to the server|

## example
> this code connects to a server and send "CREATE MODEL name{chris:NUM;}\n\a"

> then the code reads the server response with the max input being 100 characters
```
ClientSock sock("localhost",8080);
sock.write("CREATE MODEL name{chris:NUM;}\n\a");
cout<< sock.read(100);
``` 