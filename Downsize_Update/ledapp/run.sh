export FLASK_APP=ledapp
export FLASK_DEBUG=1
export PYTHONPATH=$PYTHONPATH:$(pwd)
flask run
