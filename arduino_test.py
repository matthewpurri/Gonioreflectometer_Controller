import serial  # you need to install the pySerial :pyserial.sourceforge.net
import time
# your Serial port should be different!
arduino = serial.Serial('/dev/cu.usbmodem1423101', 19200)


def onOffFunction():
    command = input("Type something (A_r/ A_l/ A_s/ B_r/ B_l/ B_s/ bye ): ")
    if command == "R":
        print("Arm right")
        time.sleep(1)
        arduino.write(b'R')
        onOffFunction()
    elif command == "L":
        print("Arm left")
        time.sleep(1)
        arduino.write(b'L')
        onOffFunction()
    elif command == "S":
        print("Arm stop")
        time.sleep(1)
        arduino.write(b'S')
        onOffFunction()
    elif command == "G":
        print("Arm go")
        time.sleep(1)
        arduino.write(b'G')
        onOffFunction()
    elif command == "r":
        print("Base right")
        time.sleep(1)
        arduino.write(b'r')
        onOffFunction()
    elif command == "l":
        print("Base left")
        time.sleep(1)
        arduino.write(b'l')
        onOffFunction()
    elif command == "s":
        print("Base stop")
        time.sleep(1)
        arduino.write(b's')
        onOffFunction()
    elif command == "g":
        print("Base Go")
        time.sleep(1)
        arduino.write(b'g')
        onOffFunction()
    elif command == "bye":
        print("See You!...")
        time.sleep(1)
        arduino.close()
    else:
        print("Sorry..type another thing..!")
        onOffFunction()


time.sleep(2)  # waiting the initialization...

onOffFunction()
