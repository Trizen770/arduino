import serial
import time 
import simpleaudio as sa
from AppOpener import open
from AppOpener import close

# simple audio for playing audio 
# https://pypi.org/project/appopener/

filename = "vine-boom.wav"
wave_obj = sa.WaveObject.from_wave_file(filename)

# make sure the 'COM#' is set according the Windows Device Manager
ser = serial.Serial('COM4', 115200, timeout=1)
time.sleep(2)

while(True):
    line = ser.readline()   # read a byte
    if line:
        string = line.decode()  # convert the byte string to a unicode string
        print(string); 
        if ("POWER BUTTON" in string.upper()):
            play_obj = wave_obj.play()
            play_obj.wait_done()  # Wait until sound has finished playing
        if ("FFB" in string.upper()):
            ser.close()
            break; 

        # Button one open minecrafty  
        if ("1" in string.upper()):
            open("minecraft", match_closest=True)

        # Button two open chrome
        if ("2" in string.upper()):
            open("chrome", match_closest=True)

        # Button three opens spotify
        if ("3" in string.upper()):
            open("spotify", match_closest=True)

        # button 4 closes minecraft 
        if ("4" in string.upper()):
            close("minecraft", match_closest=True)

        # button 5 closes chrome
        if ("5" in string.upper()):
            close("chrome", match_closest=True)

        # button 6 closes spotify
        if ("6" in string.upper()):
            close("spotify", match_closest=True)

        

        
        

ser.close()