#!/usr/bin/python
import os

choice = int(input("Team 5 PCTF Code\nPlease choose from the menu\n1: Scan Victim\n"))

if(choice == 1):
	os.system("python scripts/portscan.py")	#keep adding choices for new files
else:
	print("Invalid choice")
