#!/usr/bin/python
import os

choice = int(input("Team 5 PCTF Code\nPlease choose from the menu\n1: Scan Victim\n2: Set Shellcode Env Variable\n3: Check for common buffer overflow C functions"))

if(choice == 1):
	os.system("python scripts/portscan.py")	#keep adding choices for new files
if(choice == 2):
	os.system("./shellcode_env.sh")
if(choice == 3):
	os.system("python scripts/c_check.py")
else:
	print("Invalid choice")
