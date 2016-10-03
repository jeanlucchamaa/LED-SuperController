import serial, time
from flask import Flask, render_template, request

app = Flask(__name__)
@app.route("/")
def hello():
    global ser
    ser = serial.Serial('/dev/ttyS2', 38400);
    return render_template('ui.html')

@app.route("/apply")
def application():
    red=int(request.args.get('r'))
    green=int(request.args.get('g'))
    blue=int(request.args.get('b'))
    sendbit=int(request.args.get('s'))
    ba=bytearray()
    ba[0:3]=[red,green,blue,sendbit]
    ser.write(ba)
    ser.write('\r')
    return('potato')

if __name__ == "__main__":
    app.run()
