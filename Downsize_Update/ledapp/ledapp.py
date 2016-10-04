import serial, time
from flask import Flask, render_template, request
app = Flask(__name__)
@app.route("/")
def hello():
    if 'ser' not in locals():
        global ser
        ser = serial.Serial('/dev/ttyS2', 38400)
        return render_template('ui.html')

@app.route("/apply")
def application():
    red=int(request.args.get('r'))
    green=int(request.args.get('g'))
    blue=int(request.args.get('b'))
    sendbit=int(request.args.get('s'))
    ba=bytearray()
    ba[0:3]=[red,green,blue,sendbit]
    for index,value in enumerate(ba):
        ba[index]=min(255,value+1)
    ser.write(ba)
    ser.write('\0')
    return('potato')

if __name__ == "__main__":
    app.run()
