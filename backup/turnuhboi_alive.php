<?php

require_once("../src/snapchat.php");

//////////// CONFIG ////////////                                       
$username       = "turnuhboi"; // Your snapchat username        
$password       = "turntoi1738"; // Your snapchat password             
$gEmail         = "unichat10@gmail.com"; // Gmail account
$gPasswd        = "Irish1027"; // Gmail account password               
$casperKey      = "cf487d25a9d9232f5e10f6ca2533114b"; // Casper API Key
$casperSecret   = "b9f4251c079a162bfbcc585939432e2e"; // Casper API Secret      
$debug = false; // Set this to true if you want to see all outgoing requests and responses from server
////////////////////////////////     

// $snapchat->openAppEvent();
$snapchat = new Snapchat($username, $gEmail, $gPasswd, $casperKey, $casperSecret, $debug);

$snapchat->login($password);

$snapchat->getSnaps(true);
$snapchat->getSnaps();

// $snapchat->getStoriesByUsername("meg_hunt", true);

$dir = "/home/shane/builds/UniChat/vendor/mgp25/SC-API/src/";          
                                                                       
foreach (glob($dir ."snaps/turnuhboi/*/*.jpg") as $files) {           
    $snapchat->setStory($files, 8);                                    
    echo "$files size " . filesize($files) . "\n";                
}      

$snapchat->sendMessage("ryan.shane", "I've updated my story!");   

$snapchat->closeAppEvent();

?>
