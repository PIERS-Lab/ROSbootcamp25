# Linux (for Robotics) Cheatsheet

## Basic / most commonly-used commands

_Disclaimer: These are very basic descriptions meant to jog your memory about what each command does. Some explanations are oversimplified. If you're unsure about a command, in a generally precarious situation with your code, or need more information about a command, always look it up before using it. That said, don't be too afraid to get things wrong -- as long as you are very careful with `sudo` commands, mistakes are often recoverable._

`cd`
Change directory. `cd` by itself will take you to the home directory.

`pwd`
Print working directory. _("Where am I in the filesystem?")_

`mkdir`
Make a new directory.

`ls`
List everything in this folder.

`ls -la`
List everything in this folder -- this time with a lot more metadata (who owns the file, permissions, etc.).

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

`grep`
Search for something specific.

Tab completion: Use the tab key to autocomplete commands in the terminal.

Up arrow: View previous commands & command history.

## We also discussed...

- Basic text editors: vi, vim, emacs, nano.
- Commands for those editors ([vim cheatsheet](https://vim.rtorr.com/)).
- Git and github (briefly - we'll revisit this later).
- File permissions - you won't need to change permissions for C++ code because you'll make the cpp file readable and writeable and the compiler will take care of the permissions for you. If you write in python, you may need to deal with this.

## Learning checkpoint

By the end of this lesson, you should be able to:

1. Figure out where you are in your system (identify your directory).
2. Create, delete, copy, and move files.
