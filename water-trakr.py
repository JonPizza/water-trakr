import serial
import subprocess

ser = serial.Serial('/dev/ttyACM1', 9600)

def main():
	prev_line = b'b'
	times_drank = 0
	while True:
		line = ser.read()
		if line != prev_line:
			prev_line = line
			if line == b'a':
				times_drank += 1
				if times_drank % 10 == 0:
					subprocess.Popen(['notify-send', 'Drinking Trakr', f'You have drank {times_drank} times today!'])
		
if __name__ == '__main__':
	main()
