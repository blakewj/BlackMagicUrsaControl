# BlackMagicUrsaControl
BlackMagic Arduino Ursa Control (BMA)

Current ip: is 192.169.10.180

Installation :
-Install the BMA Near the camera

-Plug In SDI From SDI Out On The BMA(Which is the one nearest the centre)

-Power BMA Via The 9-12V dc port On the Black Magic Arduino Shield(Not The One Directly Attached to The Arduino Itself )

-Attach Network Cable (RJ45) to Ethernet Shield On The BMA
-Once Powered Continue On


Instructions:


-Type In (192.168.10.180) to your browser of choice, BMA has been tested with Chrome and safari.

-Once logged on You Should Now Have Control,

-when sending slider values you select your current Value Which is displayed Below The Slider then press the Button above the slider which will send the current command to the BMA

-When you have sent your first request a second webpage will pop up and will look identical to the previous,** note that the second page has a open connection to the BMA and will no open up any more pages when used to send commands,**this is due to a unresolved BUG**
 
Please Refer To Source Code For More In-depth details.

All commands must be structured in the following manner 
                         
192.168.10.180?COMMAND&
{Arduino shield}(start command){your command}(End of command)

End of command is &
Start of command is ?

Push buttons -

	Auto appeture —— ?APP&
	Auto focus — ?AF&

Slider value or relative valuables

Same command structure with and append value 


192.168.10.180?COMMAND&VAL%
{Arduino shield}(start command){your command}(End of command){val}(End of Value)

End of command is &
Start of command is ?

Slider values 


Exposure —— ?EXP&%
Value range integer 0-n

White balance —?MWB&%
Value range integer 3200-7600
icrement 100

F-stop —— ?FS&%
Value Range Floating Point -1.0 — -16.0
Sensor Gain ——- ?SG&%
Value range integer 1-16

	



