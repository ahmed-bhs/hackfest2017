<?php

function print_flag() {
        print file_get_contents('flag.txt');
}

class Hackfest
{
   public $hook;

   

   function __toString()
   { /*var_dump($this->hook);*/
      if (isset($this->hook)) eval($this->hook);
   }
}



$user_data = unserialize($_GET['msg']);
print($user_data);
