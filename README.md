# Dynamic List

## Introduction

Once in the C language there isn't a native Dynamic Array, this is a code that create one.

## Requirements

You must have a C compiler installed in your device. For Windows Users, I may sugest the CygWin compiler, which you can find [here](https://cygwin.com/install.html)

## Some Observations About It's Functionality

### The Comment In The Head Of List.c File

There is options at the head of the **list.c** file, where you choose how will your data be appended or removed from the list.
This choice is made by entering an **x** below the arrow and in front of the method you prefer.

To exemplify, check the image below:

![image](https://user-images.githubusercontent.com/58968791/122441403-e54ab800-cf73-11eb-9150-17e1e906cbe0.png)

By inserting the **x** in the:

Green Area (Default): the items will be appended in the beginning of the list;<br />
Red Area: the items will be appended in the list in an organized way, from the smallest to the largest one;<br />
Blue Area: the items will be appended in the end of the list;<br />

Yellow Area (Default): the items will be removed from the beginning;<br />
Orange Area: the user selects an element to be removed, if there is so;<br />
Pink Area: the items will be removed from the end;<br />

### The Menu() Method

Is the method that interacts with the all other methods.<br />
It has a switch case which organizes the user interaction. Inside this switch case, in the **Append** area, there is a logic responsible to insert only positive numbers in the list (entering a negative number you'll stop filling the list), that I'm using just to be an easy way to fill the list.

Once you download this code, feel free to adapt this Menu() method the way you seem fit.




