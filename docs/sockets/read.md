# ClientSock function: read

this function reads reads messages sent by the server with a maximum length of the value passed in


## parameters
|name|type|description|
|----|----|-----------|
|size|int| specifies the maximum length of the returning string|

## example
the following reads from a message from a server
```
ClientSock sock("localhost",8080);
sock.write("CREATE MODEL name{chris:NUM;}\n\a");
```