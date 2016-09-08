import time
import datetime
import serial
import re

connected = False


arduUNO = '/dev/ttyACM1'
mySer = serial.Serial(arduUNO,9600)
#while True:
 #   print(ser.readline())
    #time.sleep(1)
while not connected:
    mySerIn = mySer.read()
    # print(mySerIn)
    connected = True 

for i in range(2):
    myHElp=mySer.readline()
    print(type(myHElp))
    #myDat = re('b','',myHElp)
    #myDat = filter(lambda ch: ch not in " ?.!/;:", mySer.readline())
    # mySplit = myDat.split();
    # if i>0:
    #     print(mySplit)


# global last_received
# print(ser.read(ser.inWaiting())
# buffer_string = ''
# while True:
#     buffer_string = buffer_string + ser.read(ser.inWaiting())
#     if '\n' in buffer_string:
#         lines = buffer_string.split('\n') # Guaranteed to have at least 2 entries
#         last_received = lines[-2]
#         #If the Arduino sends lots of empty lines, you'll lose the
#         #last filled line, so you could make the above statement conditional
#         #like so: if lines[-2]: last_received = lines[-2]
#         buffer_string = lines[-1]







## 
# from threading import Thread
# import time
# import serial

# last_received = ''
# def receiving(ser):
#     global last_received
#     buffer = ''
#     while True:
#         buffer = buffer + ser.read(ser.inWaiting())
#         if '\n' in buffer:
#             lines = buffer.split('\n') # Guaranteed to have at least 2 entries
#             last_received = lines[-2]
#             #If the Arduino sends lots of empty lines, you'll lose the
#             #last filled line, so you could make the above statement conditional
#             #like so: if lines[-2]: last_received = lines[-2]
#             buffer = lines[-1]


# class SerialData(object):
#     def __init__(self, init=50):
#         try:
#             self.ser = ser = serial.Serial(
#                 port='/dev/ttyACM1',
#                 baudrate=9600,
#                 bytesize=serial.EIGHTBITS,
#                 parity=serial.PARITY_NONE,
#                 stopbits=serial.STOPBITS_ONE,
#                 timeout=0.1,
#                 xonxoff=0,
#                 rtscts=0,
#                 interCharTimeout=None
#             )
#         except serial.serialutil.SerialException:
#             #no serial connection
#             self.ser = None
#         else:
#             Thread(target=receiving, args=(self.ser,)).start()
        
#     def next(self):
#         if not self.ser:
#             return 100 #return anything so we can test when Arduino isn't connected
#         #return a float value or try a few times until we get one
#         for i in range(40):
#             raw_line = last_received
#             try:
#                 return float(raw_line.strip())
#             except ValueError:
#                 print('bogus data',raw_line)
#                 time.sleep(.005)
#         return 0.
#     def __del__(self):
#         if self.ser:
#             self.ser.close()

# if __name__=='__main__':
#     s = SerialData()
#     for i in range(500):
#         time.sleep(.015)
# print(s.next())
