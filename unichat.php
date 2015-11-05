<?php

require_once("./SC-API/src/snapchat.php");

//////////// CONFIG ////////////
$username       = " "; // Your snapchat username
$password       = " "; // Your snapchat password
$gEmail         = " "; // Gmail account
$gPasswd        = " "; // Gmail account password
$casperKey      = " "; // Casper API Key
$casperSecret   = " "; // Casper API Secret
$debug = false; // Set this to true if you want to see all outgoing requests and responses from server
////////////////////////////////


// $imagePath = "...pic.jpeg"; // URL or local path to a media file (image or video)
$sendTo = array("ryan.shane");

$snapchat = new Snapchat($username, $gEmail, $gPasswd, $casperKey, $casperSecret, $debug);

$snapchat->openAppEvent();
// $snapchat->addFriend($sendTo);

//Login to Snapchat with your username and password
//must use for first login!
//$snapchat->login($password);

// $snapchat->addFriend("wmorgenlander");

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

$dir = "/SC-API/src/";          
                                                                       
foreach (glob($dir ."snaps/*/*/*") as $files) {            
    $snapchat->setStory($files, 8);                                 
    // $snapchat->send($files, "ryan.shane");
    echo "$files size " . filesize($files) . "\n";                     
} 
                                                                       
foreach (glob($dir ."stories/*/*/*") as $files) {            
    // $snapchat->setStory($files, 8);                              
    // $snapchat->send($files, "ryan.shane");
    echo "$files size " . filesize($files) . "\n";                     
} 

// Download stories for a specific username
$snapchat->getStoriesByUsername("meg_hunt", true);

// Send chat message to shane to ensure server is updating
$snapchat->sendMessage($sendTo, "Story updated.");

// send message to users who submitted snaps to confirm
// $snapchat->sendMessage($receivedUsers, "I put your snap up on my story." . $phrases[rand()]);
$snapchat->sendMessage($receivedUsers, "I put your snap up on my story.");

$snapchat->clearFeed();

$snapchat->closeAppEvent();

?>
