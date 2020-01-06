<b><h2><center>FlickerFreePrint Library</center></h1></b>

This library will let programmers paint data to TFT LCD's without first having to draw a fillRec to hide old text. This library intelligently paints changed text in background color before painting new text.

<b><h3>General code usage</b></h3> 

1. #include the libraryCreate a slider object

2. create a FlickerFreePaint object for each data to be drawn

3. Print the data similar to the Print object except call print on the data object

<b><h3>Tips on usage</b></h3> 

  1. This library is template based so it should work with most display drivers provided
  the driver supports getCursorX() methods
  2. this linbrary will not paint correctly if a background gradient is used
  3. this library can work with int, float, char, and other data types
  4. this library has no capability to print DEX, HEX or Println() functions
  
  <br>
<br>

![header image](https://raw.github.com/KrisKasprzak/FlickerFreePrint/master/FFPrint.jpg)
