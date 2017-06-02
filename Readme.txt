Current compilation is done under Ubuntu 16.04


Compile using bluetooth !! -lbluetooth  eg gcc -o server server.c -lbluetooth


hciconfig hci0 piscan


hciconfig hci1 piscan


// to enable the scanning availaible for other devices man hciconfig 
//



hcitool scan man hci tool



hcitool cc <deice addr>
  
// to get devive address