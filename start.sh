#!/bin/bash
echo "Starting turnuhboi..."

echo "Clearing temp directory..."

sudo rm -r ~/builds/UniChat/SC-API/src/snaps/turnuhboi/* 2>/dev/null || :
sudo rm -r ~/builds/UniChat/SC-API/src/stories/turnuhboi/* 2>/dev/null || :

echo "Adding new snaps and stories..."

sudo php ~/builds/UniChat/SC-API/tools/turnuhboi.php

echo "Sending responses to confirm reception, and updating story..."

echo "Backing up snaps...."

cp -r ~/builds/UniChat/SC-API/src/snaps/turnuhboi/* /home/shane/builds/UniChat/save/ 2>/dev/null || :

cp -r ~/builds/UniChat/SC-API/src/stories/turnuhboi/* /home/shane/builds/UniChat/save/ 2>/dev/null || :

echo "Complete!"
