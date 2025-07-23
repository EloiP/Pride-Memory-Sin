#!/bin/sh

# Ititialization

mainmenu () {
  echo "Press 1 to make a fa mem error"
  echo "Press 2 to make a 02 mem error"
  echo "Press x to exit the script"
  read -n 1 -p "Input Selection:" mainmenuinput
  if [ "$mainmenuinput" = "1" ]; then
            make
        elif [ "$mainmenuinput" = "2" ]; then
            make
        elif [ "$mainmenuinput" = "x" ];then
            quitprogram
        elif [ "$mainmenuinput" = "X" ];then
            quitprogram
        else
            echo "You have entered an invallid selection!"
            echo "Please try again!"
            echo ""
            echo "Press any key to continue..."
            read -n 1
            clear
            mainmenu
        fi
}

mainmenu
