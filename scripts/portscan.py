#!/usr/bin/python
import nmap

print('Scanning...')
nm = nmap.PortScanner()
nm.scan('10.0.2.0/24')	#change based on machine IP Address

for host in nm.all_hosts():
	print('IP Address: %s, Hostname: %s' %(host, nm[host].hostname()))
	print('State: %s\n' % nm[host].state())
	for protocol in nm[host].all_protocols():
		print('Protocol: %s' % protocol)
		ports = nm[host][protocol].keys()
		ports.sort()
		for port in ports:
			print('port: %s\tstate: %s' % (port, nm[host][protocol][port]['state']))
