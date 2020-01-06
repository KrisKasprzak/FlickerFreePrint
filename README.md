<b><h2><center>FlickerFreePrint Library</center></h1></b>

This library will let programmers paint data to TFT LCD's without first having to draw a fillRec to hide old text. This is because a red filled rectangle is first being drawn to erase the previous number. This is a very common approch for clearing old data with fonts that are porportional (character widths are NOT fixed). If using non-proportional fonts this library is not needed as the .setFontColor(ForeColor, BackColor) can be used to automatically clear non drawn areas. This library intelligently paints changed text in background color before painting new text.

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
  5. this libary was not tested with LCD (20x4 type)
  
  <br>
<br>

The image below can't show the reuslts in a static image, but in the "Crude Repaint" you will see 25 flicker during each redraw. The yellow text is drawn with FlickerFreePrint and wil not flicker. Same for the blue and green data. Note that the data types for the text is int, float and char.

![header image](https://raw.github.com/KrisKasprzak/FlickerFreePrint/master/FFPrint.jpg)
