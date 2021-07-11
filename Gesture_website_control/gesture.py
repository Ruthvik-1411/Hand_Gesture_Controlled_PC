import serial
import pyautogui

Arduino_Serial=serial.Serial('com5',9600)

while 1:
    coming_data=str(Arduino_Serial.readline())
    print(coming_data)

    if 'Swipe' in coming_data:
        pyautogui.hotkey('ctrl','pgdn')

    if 'Previous' in coming_data:
        pyautogui.hotkey('ctrl','pgup')

    if 'Away' in coming_data:
        pyautogui.press('down')
        #pyautogui.scroll(-100)

    if 'Toward' in coming_data:
        pyautogui.press('up')
        #pyautogui.scroll(100)

    if 'Change' in coming_data:
        pyautogui.keyDown('alt')
        pyautogui.press('tab')
        pyautogui.keyUp('alt')

    coming_data="";
#use only in pyserial-3.5 folder    
#https://pyautogui.readthedocs.io/en/latest/keyboard.html
