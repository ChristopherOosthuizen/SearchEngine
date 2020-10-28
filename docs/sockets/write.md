# ClientSock function : write
write message to the connected server 

## parameters
|name|type|description|
|----|----|-----------|
|str| string| the message sent to the server|

## example

this example writes a message to the server

```
ClientSock sock("localhost",8080);
sock.write("CREATE MODEL name{chris:NUM;}\n\a");
```
