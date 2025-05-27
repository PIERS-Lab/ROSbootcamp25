# Linux (for Robotics) Cheatsheet

## Basic / most commonly-used commands

`cd`
Change directory. `cd` by itself will take you to the home directory.

`pwd`
Print working directory. *("Where am I in the filesystem?")*

`mkdir`
Make a new directory. 

`ls`
List everything in this folder.

`touch`
Usually used to make a file. If the file already exists, update the timestamp to now.

`..`
Go up one directory.

`~`
Shorthand for home.

`sudo`
Use administrator privileges. Be very careful with this! 

`rm`
Remove (followed by an argument - usually a file name).

`-r` 
Do something recursively (example: `rm -r` with a folder passed as an argument will delete everything inside that folder).

`mv`
Move a file (used as `mv arg1 arg2` where arg1 = source, arg2 = destination). If you use this command and there's already a file at the destination with the same name, it'll be overwritten by this command -- so use it with caution!

`cp`
Copy a file (really, copy that file's data into a destination). Similar usage as `mv`.


`top`
`htop`
`ps`

## We also discussed...
- basic text editors: vi, vim, emacs, nano
- commands for those editors: 
