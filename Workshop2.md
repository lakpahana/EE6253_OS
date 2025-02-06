1. Create a folder name folder1 and move it to Home/user directory?
``mkdir folder1``
``mv folder1 /home/user``
2. Open gedit and save file as txt1.txt in Desktop.
``gedit``
``mv txt1.txt /home/user/Desktop``
3. Create an exact copy of txt1.txt as txt2.txt in the same directory.
``cp txt1.txt txt2.txt``	
4. Go back to the home/user directory and copy Desktop directory to a
directory known as directory1. List the home/user directory to verify.
``cd /home/user``
``cp -r Desktop directory1``
``ls``
5. Delete directory1 and list the home directory to verify. Go to Desktop
directory and observe privileges of file txt2.txt.
``rm -r directory1``
``ls``
``cd Desktop``
``ls -l txt2.txt``
6. Remove the write privilege of the user for txt2.text and add execute
privilege to users in File's group. Observe the privileges of txt2.txt to
verify.Open txt2.txt in gedit and try to edit the file.
``chmod u-w txt2.txt``
``chmod g+x txt2.txt``
``ls -l txt2.txt``
``gedit txt2.txt``
7. Create a directory name mydir in desktop and create 3 empty text files
as Doc1.txt, Doc2.txt and Doc3.txt inside mydir using touch command.
``mkdir mydir``
``cd mydir``
``touch Doc1.txt Doc2.txt Doc3.txt``
8. Observe the statistics of Doc1.txt.
``stat Doc1.txt``
9. Change the access time of Doc1.txt and observe statistics.
``touch -a Doc1.txt``
``stat Doc1.txt``
10. Change the modification time of Doc1.txt and observe statistics.
``touch -m Doc1.txt``
``stat Doc1.txt``
11. Open Doc2.txt in gedit and write text "Hello, I am in document 2" and
save and close. Display this text in terminal.
``gedit Doc2.txt``
``cat Doc2.txt``
12. Create a directory named mydir2 in desktop and create two empty text
files as Doc1.txt, Doc2.txt inside mydir using cat command.
``mkdir mydir2``
``cd mydir2``
``cat > Doc1.txt``
``cat > Doc2.txt``
13. Write content "Hello I'm text in document 1" into Doc1.txt and "Hello
I'm text in document 2" into Doc2.txt using gedit.Display the written
content on both files Doc1.txt and Doc2.txt on terminal using single
command.
``gedit Doc1.txt``
``gedit Doc2.txt``
``cat Doc1.txt Doc2.txt``
14. Append content of Doc1.txt to Doc2.txt and display Doc2.txt.
``cat Doc1.txt >> Doc2.txt``
``cat Doc2.txt``
15. Copy the content of Doc1.txt to Doc2.txt and display Doc2.txt.
``cp Doc1.txt Doc2.txt``
``cat Doc2.txt``
16. Log out user session using the terminal.
``exit``
17. Shoutdown Ubuntu using the terminal.
``sudo shutdown now``
18. Restart Ubuntu using the terminal.
``sudo reboot``
19. Create a new user account using the terminal.
``sudo adduser user2``