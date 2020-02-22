#!/bin/bash

echo "[*]"
echo "[*] Welcome to the configuration saver!"
echo "[*]"

MODE=""
while [ "$MODE" != "q" ]
do
	echo "[*] Do you wish to (v)iew the configuration, (d)efine a variable, (s)tore the configuration,"
	echo "[*] (l)oad the configuration, or (q)uit?"
	echo -n "> "

	read MODE
	case $MODE in
		v*)
			echo "[*] The current configuration is:"
			for VARIABLE in $(compgen -v CONFIG_)
			do
				echo "- $VARIABLE: $(eval echo \$$VARIABLE)"
			done
			;;
		d*)
			echo "[*] Please enter the name of the configuration parameter:"
			echo -n "> "
			read NAME
			echo "[*] Please enter the value of the configuration parameter:"
			echo -n "> "
			read VALUE
			declare CONFIG_$NAME=$VALUE
			;;
		s*)
			FILENAME=$(mktemp -p ../rw config_XXXXXX)
			echo "[*] Saving configuration to $(basename $FILENAME)!"
			for VARIABLE in $(compgen -v CONFIG_)
			do
				echo "$VARIABLE=$(eval echo \$$VARIABLE)" >> $FILENAME
			done
			;;
		l*)
			echo "[*] Please enter the name of the configuration file:"
			echo -n "> "
			read FILENAME
			if ! echo $FILENAME | grep -qE "config_\w\w\w\w\w\w"
			then
				echo "[!] INVALID FILENAME. Must be of the form: config_XXXXXX."
				continue
			fi
			echo "[*] Loading configuration from $(basename $FILENAME)!"
			source ../rw/$FILENAME

			if [ -n "$CONFIG_PASSWORD" ]
			then
				echo "[!] THIS CONFIG FILE IS PASSWORD-PROTECTED."
				echo "[!] Enter password:"
				echo -n "> "
				read PASSWORD
				if [ "$PASSWORD" != "$CONFIG_PASSWORD" ]
				then
					echo "[!] INCORRECT PASSWORD."
					break
				fi
			fi
			;;
		q*)
			break
			;;
		*)
			echo "[!] INVALID MODE!"
			;;
	esac
done
