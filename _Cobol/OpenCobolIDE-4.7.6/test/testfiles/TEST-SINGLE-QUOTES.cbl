      *******************************************************************
      **=================================================================
      ** Ce programme teste le module VIRTUAL-PRINTER
      **
      ** Auteurs: Colin Duquesnoy, Thomas Bertels
      ** Date: Mai 2013
      *******************************************************************
       IDENTIFICATION DIVISION.
      **************************************
       PROGRAM-ID. TEST-PRINTER.
      **
       ENVIRONMENT DIVISION.
      **************************************
      **
       INPUT-OUTPUT SECTION.
      **-*-*-*-*-*-*-*-*-*-*-*-*-*
      **
       DATA DIVISION.
      **************************************
       FILE SECTION.
      **-*-*-*-*-*-*-*-*-*-*-*-*-*
      **
       WORKING-STORAGE SECTION.
      **-*-*-*-*-*-*-*-*-*-*-*-*-*
       01 PRINTER-PARAM.
           02 PA-RESET         PIC X       VALUE "N"       .
           02 PA-BUFFER        PIC X(80)   VALUE SPACES    .
           02 PA-WHEN          PIC X(6)    VALUE "AFTER"   .
           02 PA-WHAT          PIC X(5)    VALUE "LINES"   .
           02 PA-HOWMANY       PIC 99      VALUE 1         .
      **
       PROCEDURE DIVISION.
      **************************************
       MAIN-PROCEDURE.
           DISPLAY "Proj UF31: Test virtual printer"

           MOVE "O"        TO PA-RESET
           CALL 'VIRTUAL-PRINTER' USING PRINTER-PARAM

           MOVE "Bonjour"  TO PA-BUFFER
           CALL 'VIRTUAL-PRINTER' USING PRINTER-PARAM

           MOVE "La vie est dure et pleine de confiture" to PA-BUFFER
           MOVE "LINES"    TO PA-WHAT
           MOVE "BEFORE"   TO PA-WHEN
           MOVE 5          TO PA-HOWMANY
           CALL 'VIRTUAL-PRINTER' USING PRINTER-PARAM

           MOVE "Bonjour"  TO PA-BUFFER
           MOVE "PAGE"    TO PA-WHAT
           MOVE "BEFORE"   TO PA-WHEN
           CALL 'VIRTUAL-PRINTER' USING PRINTER-PARAM

           MOVE "Bye bye"  TO PA-BUFFER
           CALL 'VIRTUAL-PRINTER' USING PRINTER-PARAM

           DISPLAY "End"
           STOP RUN.
       HELLO-WORLD.
           DISPLAY "Hello World!!".
       END PROGRAM TEST-PRINTER.
