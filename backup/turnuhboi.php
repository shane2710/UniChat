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


$imagePath = "/home/shane/builds/UniChat/pic.jpeg"; // URL or local path to a media file (image or video)
// $sendTo = array("actionjaxon195", "ceuell14", "cmward1996", "ian.gaus", "jdisser", "jkrivda", "mattrrrr", "meg_hunt", "petethemeat", "phealings", "ryan.shane", "jjbyrne1414", "onesgnation");
$sendTo = array("ryan.shane");

$snapchat = new Snapchat($username, $gEmail, $gPasswd, $casperKey, $casperSecret, $debug);

// $snapchat->openAppEvent();
// $snapchat->addFriend($sendTo);

//Login to Snapchat with your username and password
$snapchat->login($password);

$snapchat->addFriend("petethemeat");

// Get friends in an array
$friends = $snapchat->getFriends();

echo "My friends: ";
print_r($friends);

// Send snap adding text to your image and 10 seconds
// $snapchat->send($imagePath, $sendTo, "turn sloich", 10);

// Set a story
// $snapchat->setStory($imagePath);

// Set a story adding text to the image and 5 seconds
// $snapchat->setStory($imagePath, 5, "This is my turntoi story");


// Automatically downloads Snaps and store it in 'Snaps' folder
// Store data received to interpret later on
$receivedData = $snapchat->getSnaps(true);
print_r($receivedData);

// save the senders in an array
for ($i = 0; $i < count($receivedData); $i++) {
    $receivedUsers[$i] = $receivedData[$i]->sender; 
}
print_r($receivedUsers);

$dir = "/home/shane/builds/UniChat/vendor/mgp25/SC-API/src/";          
                                                                       
foreach (glob($dir ."snaps/turnuhboi/*/*.jpg") as $files) {            
    // $snapchat->setStory($files, 8);                                 
    $snapchat->send($files, "ryan.shane");
    echo "$files size " . filesize($files) . "\n";                     
} 
                                                                       
foreach (glob($dir ."stories/*/*/*") as $files) {            
    // $snapchat->setStory($files, 8);                              
    $snapchat->send($files, "ryan.shane");
    echo "$files size " . filesize($files) . "\n";                     
} 

// Download stories for a specific username
$snapchat->getStoriesByUsername("meg_hunt, ryan.shane", true);

// Send chat message to shane to ensure server is updating
$snapchat->sendMessage($sendTo, "Story updated." . " turn sloich!");

// send message to users who submitted snaps to confirm
// $snapchat->sendMessage($receivedUsers, "I put your snap up on my story." . $phrases[rand()]);

$snapchat->closeAppEvent();

?>
