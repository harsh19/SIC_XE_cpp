//test case
PROBA    START   1000
FIRST    LDX    #0
         LDT    #32
         LDS    #4
         LDA    #0
LOOP     +TD      INDEV
         JEQ     LOOP
         RD      INDEV
         COMPR   A,T
         JEQ     OUT
         COMPR   A,S
         JEQ     OUT
         LDA    #1
         ADDR    A,X
         LDA    #0
         J       LOOP
OUT      RMO     X,ATMP
         LDS    #0
INDEV    BYTE    X'F33232FABCDE23'
         :STR      RESB    100
         END     FIRST
