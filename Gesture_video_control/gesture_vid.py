#make sure to run the code where the pyserial is downloaded, if it is same as where python is, then no problem
#pyserial allows us to read the data coming from your com port
#pyautogui allows us to perform keyboard and mouse actions by using some keywords
#visit https://pyautogui.readthedocs.io/en/latest/keyboard.html
#make sure to close serial monitor in arduino as the com port must be free while python is using it

import serial                                 #importing serial , use pip install pyserial to install the package
import pyautogui                             #importing pyautogui, use pip install pyautogui

Arduino_Serial=serial.Serial('com5',9600)     #telling the serial to read from com port 5 communicating at 9600 rate. Change accordingly

while 1:                                      #run for as long as it can
    coming_data=str(Arduino_Serial.readline())#reading the data from port
    print(coming_data)                        #printing the coming data

    if 'Vup' in coming_data:                 #if the command Vup is there then the command is ctrl+up
        pyautogui.hotkey('ctrl','up')

    if 'Vdec' in coming_data:                #if the command Vdec is there then the command is ctrl+down
        pyautogui.hotkey('ctrl','down')

    if 'Play/Pause' in coming_data:          #if the command Play/Pause is there then the command is space for 0.3s
        pyautogui.typewrite(['space'], 0.3)

    if 'Forward' in coming_data:             #if the command Forward is there then the command is ctrl+right
        pyautogui.hotkey('ctrl','right')

    if 'Rewind' in coming_data:              #if the command Rewind is there then the command is ctrl+left
        pyautogui.hotkey('ctrl','left')

    coming_data="";                          #re initialise the coming_data
