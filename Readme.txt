//********************************
//Current compilation is done under Ubuntu 16.04
//********************************

System Requirements:
Linux kernel version 2.4.6 or more else BlueZ support
Bluetooth 2.0 supported hardware in-built/USB


//********************************
//Compile using bluetooth
//using bluetooth library -lbluetooth
//********************************
gcc -o server server.c -lbluetooth


//*********************************
//commands for setting up Bluetooth Dongles(v2.0)up
// to enable the scanning availaible for other devices 
//for  more info man hciconfig 
// make sure BlueZ is installed

hciconfig hci0 piscan


hciconfig hci1 piscan

//*********************************
// scan command
// more info man hci tool
//*********************************
hcitool scan

//*********************************
// to get devive address
//*********************************
hcitool cc <deice addr>
  
