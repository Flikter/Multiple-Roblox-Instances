# Multiple Roblox Instances

This program allows you to launch multiple instances of the Roblox game client.
This program must be opened before you launch Roblox.
It's a C++ console program made with Microsoft Visual Studio.

# How it works

Each time Roblox is opened, a mutex is created which prevents multiple instances from being launched.
In order to achieve launching of multiple instances, this program creates the mutex before Roblox does.
The program then takes ownership of the mutex and Roblox can't create it. This allows us to launch multiple instances of Roblox.
When you close the program, Roblox can take ownership of the mutex again.
