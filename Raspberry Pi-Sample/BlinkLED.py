import time
import RPi.GPIO as GPIO

ledPin=11


def main():
   GPIO.setmode(GPIO.BOARD)
   GPIO.setup(ledPin,GPIO.OUT)

while True:
    GPIO.output(ledPin,GPIO.LOW)
    time.sleep(1)
    GPIO.output(ledPin,GPIO.HIGH)
    time.sleep(1)
    GPIO.output(ledPin,0)
    time.sleep(1)
    GPIO.output(ledPin,1)
    time.sleep(1)