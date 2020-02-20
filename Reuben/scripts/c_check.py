#!/usr/bin/python
import os

choice = str(raw_input("Enter path of file to be scanned\n"))

os.system('grep "scanf" %s' % (choice))
os.system('grep "gets" %s' % (choice))
os.system('grep "strcpy" %s' % (choice))