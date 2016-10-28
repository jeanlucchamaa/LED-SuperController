var SerialPort = require("serialport");
var express = require('express');
var app = express();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var port = new SerialPort("COM3", {
    baudRate: 38400,
    parser : SerialPort.parsers.readline('\0')
});
//globals
hardware=1;
timerOn=1;
app.use(express.static('public'));
app.get('/', function(req, res){
});

port.on('data',function (data){
    comma1=data.indexOf(",");
    comma2=data.lastIndexOf(",");
    red=Number(data.slice(0,comma1))-1;
    green=Number(data.slice(comma1+1,comma2))-1;
    blue=Number(data.slice(comma2+1))-1;
    io.emit('supply',red,green,blue);
});

io.on('connection',function(socket){
    console.log('a user connected');
    socket.on('disconnect',function(){
        console.log('a user disconnected');
    });
    socket.on('apply',function(r,g,b,s){
        red=Math.min(Number(r)+1,255);
        green=Math.min(Number(g)+1,255)
        blue=Math.min(Number(b)+1,255);
        sendbit=Number(s)+1;
        const colorBuffer = Buffer.from([red,green,blue,sendbit]);
        console.log(colorBuffer);
        port.write(colorBuffer);
        port.write('\0');
    });
});

http.listen(5000, function(){
    console.log('Example app listening on port 5000!');
    hardware=true;
    timeron=true;
    global1=42;
});

