# Writeup

1. Execute on shell "strings exec-me".  
   Then you can get a string "flag{HINT_INPUT_TO_NUMBER> SHOW_CODE".

2. Execute binary then you'll be asked to enter a number.

3. Type "SHOW_CODE" and Return, a file named "code" will be appeared into the directory.

4. It is written in a simplified version of the decision part of the game.  
   It shows the answer is date multiplied by -1 (ex. 6/30 → -30, 7/5 → -5)

5. Since the decision logic casts and compares 64-bit signed integers to 32-bit signed integers,  
   It is obvious that an overflow will occur if a large value is entered.
   
6. Therefore, the date is multiplied by -1 and expressed as a 32-bit signed integer,  
   and the decimal number as the unsigned integer indicates the correct value.  
   (ex. -30 → 4294967267, -5 -> 4294967291)
   
7. Enter that then you can get the flag!!!!

flag is "flag{y0u_g0t_th1s_flag}"
