# Hand_Gesture_Controlled_PC

Recently Gesture controlled PCs are becoming famous. They use something called <b>Leap Motion</b> which allows us to control certain functions in our PC by just waving our hands
infront of the screen. So I built a basic gesture controlled setup to control a VLC media player and toggle through a webpage using Arduino Uno and Python.<br>

<b>Components Used:</b><br>
<li>Arduino Uno  x 1
<li>HC-SR04 Ultrasonic Sensors  x 2
<li>Jumper wires
<li>Python Libraries:  pyserial and pyautogui
<li>PC with good USB ports
  
<b>Working:</b><br><br>
  The concept behind the working of this gesture controlled pc is simple. First we have two Ultrasonic sensors that are connected to the Arduino. The setup looks somewhat like this:<br> <img src="https://github.com/Ruthvik-1411/Hand_Gesture_Controlled_PC/blob/main/setup01.jpg" height="200px" width="250px">
 <img src="https://github.com/Ruthvik-1411/Hand_Gesture_Controlled_PC/blob/main/setup02.jpg" height="200px" width="250px"> <br>
  The Ultrasonic sensors constantly measure the distance in front of the screen. We define certain conditions in the arduino code which represent some common gestures like
  Swipe, Toward, Away etc in real life. Now when these conditions are true the corresponding messages gets printed in the serial port. We generally use the Serial Monitor that is 
  built in the arduino ide to see the data printed. But here we want the computer to read this data from arduino. So we use Python and its libraries to read the data from 
  serial port and perform the tasks in the pc.<br>
  First Library is the <b>pyserial</b> which can read the data coming from the assigned serial port. Now reading the data is not enough, we need to act on it. In order to use
  the keyboard and mouse by our application we use a Second Library that is <b>pyautogui</b>. Pyautogui allows us to control the keyboard and mouse from the code itself.
  More info about the control functions of pyautogui can be obtained <a href="https://pyautogui.readthedocs.io/en/latest/keyboard.html">here</a>.
  These libraries can be installed using pip and make sure to install them where the python and python shell is installed. After installing them make sure to test if they are 
  working. Try "import serial" in the prompt and if there is an error you can see it and try finding a solution in that case. Also the com port in use must be free i.e. no 
  other application must be using it when the python code is running. Even the Serial Monitor should not be used, it returns an error regarding the permissions.<br><br>
  <b>Implementation of Gesture control of Media Player: <a href="https://drive.google.com/file/d/1AZE8-nLWYzwQVdkUN1KVgpxVPQ5iPFc2/view?usp=sharing">Video 1</a> 
  <a href="https://drive.google.com/file/d/17EciASbOBDui6ReP7wv2gS3QmO3VXpb7/view?usp=sharing">Video 2</a><br>
  Implementation of Gesture control of website:   <a href="https://drive.google.com/file/d/1AW34u_MQN6PKMQwZ9DSG9JmbY9v08Xqi/view?usp=sharing">Video 1</a> 
  <a href="https://drive.google.com/file/d/1Jz_bTXDxn3Of84jhD-y2QymbRNYMa6Sv/view?usp=sharing">Video 2</a></b>
  
