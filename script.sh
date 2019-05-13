#!/bin/bash
programName=$1
ls
frac ${programName}.fcr ${programName}.tts
make ${programName}
~/Documents/tina-3.4.4/bin/tina ${programName}.tts ${programName}.ktz
~/Documents/tina-3.4.4/bin/ktzio ${programName}.ktz ${programName}.txt