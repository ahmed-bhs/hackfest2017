The task gave us an executable .exe malware , 
All we need to do is to run the malware in virtual machine (exp windows xp) and monitor the generated traffic to identify what server needs the connection
so to displays all connections  and listening ports and the the owning process ID associated with each connection .
just type <code> netstat -ano </code> 
you will see 193.95.68.245:81 in the list below .
Flag is : hackfest{193.95.68.245:81}
