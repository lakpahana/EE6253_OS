## EE6253 - Operating Systems and Network Programming
# Workshop 01 - Basic Linux Terminal Commands (Part 01)

1. Log in to the ubuntu.
2. Open the terminal.
    Shortcut Ctrl+Alt+T
3. Upgrade ubuntu.
    ```sudo apt-get upgrade```
4. Download and install gcc compiler.
    ```sudo apt-get install gcc```
5. Download and install build essentials.
    ```sudo apt-get install build-essential```	
6. Download and install gedit.
    ```sudo apt-get intall gedit```
7. Update ubuntu.
    ```sudo apt-get update```
8. Explain hostname and username in Linux.
    ````
    Hostname is the name of the computer and username is the name of the user who is currently logged in.
    eg. 
    username@hostname:~$
    ````
9. What is the syntax of displaying hostname and username in Linux
Terminal?
    ````
    username@hostname:~$
    ````

10. What is the meaning of ~ symbol?
    ````
    ~ symbol represents the home directory of the current user.
    ````

11. Go to the Desktop directory in Home.
    ````
    cd Desktop
    or
    cd ~/Desktop
    ````
12. Display the current working directory.
    ````
    pwd
    ````
13.Create the new folder in the Desktop with name Example1 and change the
current directory to Example1.
    
    ````
    mkdir Example1
    ````

14. Go back to the previous directory and rename Example1 as Folder1.
    ````
    cd      
    mv Example1 Folder1
    ````
15. List all files in Home directory.
    ````
    ls
    ````
16. List all files in Home directory with hidden files.
    ````
    ls -a
    ````
17. List all files in Home directory in long list format.
    ````
    ls -l
    
    drwxr-xr-x 2 user user 4096 Sep  6 12:00 Folder1

    1st character - d for directory, - for file	

    next 3 characters - owner
    next 3 characters - group
    next 3 characters - others
 
    r - read
    w - write
    x - execute

    order is rwx
  

    ````
18. Change directory to root directory and list all files. Visualize the    
root directory using GUI. Terminate the GUI using terminal.
    ````
    cd /
    ls
    nautilus
    ````
    Terminate the GUI using terminal.
    ````
    Ctrl+C
    or
    killall nautilus
    ````
19. Change directory back to Desktop using single command and delete
directory Folder1.
    ````
    cd ~/Desktop
    rmdir Folder1
    ````
20. Clear the screen of the terminal.
    ````
    clear
    ````