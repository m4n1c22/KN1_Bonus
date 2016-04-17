###Execution Steps

* For compiling the source code use the command `gcc hamming_code.c -o hamming_code.out` in the linux terminal.
  
  *Note: Ensure the latest version of GCC is installed.* 

* After compiling run the output binary file in the following format in the terminal: 
`./hamming_code.out 10001 110101`
  * The first parameter is the binary number which will be padded with parity bits to form the hamming code.
  * The second parameter is a received hamming code which will be verified for errors with the principle of hamming code.
  
  *Note : Ensure to pass parameter as per the size regulations mentioned in the source code which is somewhere near 32.* 
