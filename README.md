# Pixelated-Buddy
A desk buddy with two displays(Oled + TFT) which will have functions just as a time clock .It has a real time tracker mode ,animation mode , timelapse and even alarm mode on Oled.In TFT display it has an interactive Desk buddy UI which is interactive using Pushbuttons which can also play songs and act as a bluetooth speaker 
  
### Why i made this ??  
>Well i always adored the reels in Instagram and youtube showing deskbuddies but never got the chance to buy one so I thought why i don't make it this week to fill my inner child's dream 
>Well then here it is ..

## PROJECT SHOWCASE:
<img width="35%" height="1078" alt="image" src="https://github.com/user-attachments/assets/355932d6-0487-4175-9566-7a656bcae3f3" /> <img width="35%" height="898" alt="image" src="https://github.com/user-attachments/assets/858eedf7-fcb2-45a8-a4f7-3bcfd4733516" />  
<img width="35%" height="1078" alt="image" src="https://github.com/user-attachments/assets/6c5a927f-1a59-4ca0-8e3a-29394196f5f6" /><img width="35%" height="1078" alt="image" src="https://github.com/user-attachments/assets/5900b743-b302-4730-9314-1282cea5633c" />  

## Physical Specifications:

**PCB OUTLINE:** 78mm x 68mm  

**Mounting :** has 2 M3 screw holes  

**Microcontroller:** 2 Esp32-Wroom-32  

**Display :** One oled +One TFT  

**AUDIO :** 

-Uses smartelex-i2s-audio-breakout-max98357  
  
-A speaker of 2 Inch Mini Speaker Driver, 4 Ohm 3W

**Sensor:** USES 3 touch sensors for interacting with TFT deskbuddy UI and 3 push buttons to interact with OLED screen .   
  

**USER:** CAN Play songs when connected with ESp's bluetooth and can interact with the Deskbuddy UI 

## USER's instructions:  
  
>Let me guide you to how to use Pixelated Buddy
>  
>To interact with DeskBuddy's UI :  
>When pressed Upper lid's touch sensor you make the bot angry for few seconds.    
>When pressed the touch sensors of main lid , the upper when touched will make the bot go to sleep mode and to exit just touch the lower sensor of the side of main lid. 
>TO use Pixelated buddy as a Bluetooth speaker .Connect to Esp32's Bluetooth and play songs  
>To use the time clock 
>In default it will be in animation mode and When you press 1 it goes to showing time mode and if you again press Button 1 it exits showing time mode and returns to Animation Mode.  
>In default mode , If you press 2 then it will be open up a timelapse mode. Click 1 to start timelapse and 3 to stop it . When it is stopped it will automatically return to Animation mode.  
>In default mode , If you press 3 it goes to Alarm mode , Press 1 to select time for hour , press 2 to select for exact minute , press 3 to exit it  
> TO scroll in hour mode or minute mode Click 1 to go up by +1 and 3 to go down by -1 and 2 to confirm time .  
> when you exit It normally goes to alarm start mode and alarm starts if you have selected an time for alarm.  
>That's how it works Thanks for Reading.

## PCB Overview:  
  
<img width="35%" height="1067" alt="image" src="https://github.com/user-attachments/assets/65b9f175-213f-40bf-a017-49390f080a7a" /> <img width="35%" height="1077" alt="image" src="https://github.com/user-attachments/assets/fc1cb725-5a58-4012-81d0-f4d99d19afa3" />
<img width="35%" height="1077" alt="image" src="https://github.com/user-attachments/assets/af3d327a-619c-47f9-a26d-96eee6f92552" /> <img width="35%" height="1072" alt="image" src="https://github.com/user-attachments/assets/7930f891-b23d-47d4-a04b-6c97d9947fb1" />

## 3D part assembly :

>Place the main lid , glue the TFT and Oled and touch sensors from Inside and place the buttons in the hole it will fit without any glue
>After that Place the PCB secure it with M3 screws and place the top lid over main lid and secure it with M3 screws
>Place the Oled lid and secure it with M3 screws
>and then screw the speaker on the buttom of Main lid and place it
>After following this You should be good to go .

## License
This project is licensed under **CC BY-NC 4.0** (Creative Commons Attribution-NonCommercial). 
You are free to build and modify this board for personal use, but commercial production or selling of this project is strictly prohibited.
