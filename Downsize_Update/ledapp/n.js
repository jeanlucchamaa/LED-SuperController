var express = require('express');
var app = express();
hardware=true;
timeron=true;
var global1;
app.use(express.static('public'));

app.get('/',function(req,res){
    res.send('Hellow World');
});

app.get('/apply',function(req,res){
    global1=req;
    console.log(hardware);
});

app.listen(8080, function(){
    console.log('Example app listening on port 8080!');
});

