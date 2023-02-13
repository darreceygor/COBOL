"""
This module contains cobol keywords, functions and builtins names for use in
auto completion and syntax highlighting
"""

INTRINSICS = ['ABS', 'ACOS', 'ANNUITY', 'ASIN', 'ATAN', 'BOOLEAN-OF-INTEGER', 'BYTE-LENGTH', 'CHAR', 'CHAR-NATIONAL',
              'COMBINED-DATETIME', 'CONCATENATE', 'COS', 'CURRENCY-SYMBOL', 'CURRENT-DATE', 'DATE-OF-INTEGER',
              'DATE-TO-YYYYMMDD', 'DAY-OF-INTEGER', 'DAY-TO-YYYYDDD', 'DISPLAY-OF', 'E', 'EXCEPTION-FILE',
              'EXCEPTION-FILE-N', 'EXCEPTION-LOCATION', 'EXCEPTION-LOCATION-N', 'EXCEPTION-STATEMENT',
              'EXCEPTION-STATUS', 'EXP', 'EXP10', 'FACTORIAL', 'FORMATTED-CURRENT-DATE', 'FORMATTED-DATE',
              'FORMATTED-DATETIME', 'FORMATTED-TIME', 'FRACTION-PART', 'HIGHEST-ALGEBRAIC', 'INTEGER',
              'INTEGER-OF-BOOLEAN', 'INTEGER-OF-DATE', 'INTEGER-OF-DAY', 'INTEGER-OF-FORMATTED-DATE', 'INTEGER-PART',
              'LENGTH', 'LENGTH-AN', 'LOCALE-COMPARE', 'LOCALE-DATE', 'LOCALE-TIME', 'LOCALE-TIME-FROM-SECONDS', 'LOG',
              'LOG10', 'LOWER-CASE', 'LOWEST-ALGEBRAIC', 'MAX', 'MEAN', 'MEDIAN', 'MIDRANGE', 'MIN', 'MOD',
              'MODULE-CALLER-ID', 'MODULE-DATE', 'MODULE-FORMATTED-DATE', 'MODULE-ID', 'MODULE-PATH', 'MODULE-SOURCE',
              'MODULE-TIME', 'MONETARY-DECIMAL-POINT', 'MONETARY-THOUSANDS-SEPARATOR', 'NATIONAL-OF',
              'NUMERIC-DECIMAL-POINT', 'NUMERIC-THOUSANDS-SEPARATOR', 'NUMVAL', 'NUMVAL-C', 'NUMVAL-F', 'ORD',
              'ORD-MAX', 'ORD-MIN', 'PI', 'PRESENT-VALUE', 'RANDOM', 'RANGE', 'REM', 'REVERSE',
              'SECONDS-FROM-FORMATTED-TIME', 'SECONDS-PAST-MIDNIGHT', 'SIGN', 'SIN', 'SQRT', 'STANDARD-COMPARE',
              'STANDARD-DEVIATION', 'STORED-CHAR-LENGTH', 'SUBSTITUTE', 'SUBSTITUTE-CASE', 'SUM', 'TAN',
              'TEST-DATE-YYYYMMDD', 'TEST-DAY-YYYYDDD', 'TEST-FORMATTED-DATETIME', 'TEST-NUMVAL', 'TEST-NUMVAL-C',
              'TEST-NUMVAL-F', 'TRIM', 'UPPER-CASE', 'VARIANCE', 'WHEN-COMPILED', 'YEAR-TO-YYYY']

RESERVED = ['ACCEPT', 'ACCESS', 'ACTIVE-CLASS', 'ADD', 'ADDRESS', 'ADVANCING', 'AFTER', 'ALIGNED', 'ALL', 'ALLOCATE',
            'ALPHABET', 'ALPHABETIC', 'ALPHABETIC-LOWER', 'ALPHABETIC-UPPER', 'ALPHANUMERIC', 'ALPHANUMERIC-EDITED',
            'ALSO', 'ALTER', 'ALTERNATE', 'AND', 'ANY', 'ANYCASE', 'ARE', 'AREA', 'AREAS', 'ARGUMENT-NUMBER',
            'ARGUMENT-VALUE', 'ARITHMETIC', 'AS', 'ASCENDING', 'ASCII', 'ASSIGN', 'AT', 'ATTRIBUTE', 'AUTO',
            'AUTO-SKIP', 'AUTOMATIC', 'AUTOTERMINATE', 'AWAY-FROM-ZERO', 'B-AND', 'B-NOT', 'B-OR', 'B-XOR',
            'BACKGROUND-COLOR', 'BACKGROUND-COLOUR', 'BASED', 'BEEP', 'BEFORE', 'BELL', 'BINARY', 'BINARY-C-LONG',
            'BINARY-CHAR', 'BINARY-DOUBLE', 'BINARY-INT', 'BINARY-LONG', 'BINARY-LONG-LONG', 'BINARY-SHORT', 'BIT',
            'BLANK', 'BLINK', 'BLOCK', 'BOOLEAN', 'BOTTOM', 'BY', 'BYTE-LENGTH', 'CALL', 'CANCEL', 'CAPACITY',
            'CARD-PUNCH', 'CARD-READER', 'CASSETTE', 'CD', 'CENTER', 'CF', 'CH', 'CHAIN', 'CHAINING', 'CHARACTER',
            'CHARACTERS', 'CLASS', 'CLASS-ID', 'CLASSIFICATION', 'CLOSE', 'CODE', 'CODE-SET', 'COL', 'COLLATING',
            'COLOR', 'COLS', 'COLUMN', 'COLUMNS', 'COMMA', 'COMMAND-LINE', 'COMMIT', 'COMMON', 'COMMUNICATION', 'COMP',
            'COMP-1', 'COMP-2', 'COMP-3', 'COMP-4', 'COMP-5', 'COMP-6', 'COMP-X', 'COMPUTATIONAL', 'COMPUTATIONAL-1',
            'COMPUTATIONAL-2', 'COMPUTATIONAL-3', 'COMPUTATIONAL-4', 'COMPUTATIONAL-5', 'COMPUTATIONAL-X', 'COMPUTE',
            'CONDITION', 'CONFIGURATION', 'CONSTANT', 'CONTAINS', 'CONTENT', 'CONTINUE', 'CONTROL', 'CONTROLS',
            'CONVERSION', 'CONVERTING', 'COPY', 'CORR', 'CORRESPONDING', 'COUNT', 'CRT', 'CRT-UNDER', 'CURRENCY',
            'CURSOR', 'CYCLE', 'DATA', 'DATA-POINTER', 'DATE', 'DAY', 'DAY-OF-WEEK', 'DE', 'DEBUGGING', 'DECIMAL-POINT',
            'DECLARATIVES', 'DEFAULT', 'DELETE', 'DELIMITED', 'DELIMITER', 'DEPENDING', 'DESCENDING', 'DESTINATION',
            'DESTROY', 'DETAIL', 'DISABLE', 'DISC', 'DISK', 'DISPLAY', 'DIVIDE', 'DIVISION', 'DOWN', 'DUPLICATES',
            'DYNAMIC', 'EBCDIC', 'EC', 'ECHO', 'EGI', 'ELSE', 'EMI', 'EMPTY-CHECK', 'ENABLE', 'END', 'END-ACCEPT',
            'END-ADD', 'END-CALL', 'END-CHAIN', 'END-COMPUTE', 'END-DELETE', 'END-DISPLAY', 'END-DIVIDE',
            'END-EVALUATE', 'END-IF', 'END-MULTIPLY', 'END-OF-PAGE', 'END-PERFORM', 'END-READ', 'END-RECEIVE',
            'END-RETURN', 'END-REWRITE', 'END-SEARCH', 'END-START', 'END-STRING', 'END-SUBTRACT', 'END-UNSTRING',
            'END-WRITE', 'ENTRY', 'ENTRY-CONVENTION', 'ENVIRONMENT', 'ENVIRONMENT-NAME', 'ENVIRONMENT-VALUE', 'EO',
            'EOL', 'EOP', 'EOS', 'EQUAL', 'EQUALS', 'ERASE', 'ERROR', 'ESCAPE', 'ESI', 'EVALUATE', 'EXCEPTION',
            'EXCEPTION-OBJECT', 'EXCLUSIVE', 'EXIT', 'EXPANDS', 'EXTEND', 'EXTERNAL', 'F', 'FACTORY', 'FALSE', 'FD',
            'FILE', 'FILE-CONTROL', 'FILE-ID', 'FILLER', 'FINAL', 'FIRST', 'FIXED', 'FLOAT-BINARY-128',
            'FLOAT-BINARY-32', 'FLOAT-BINARY-64', 'FLOAT-DECIMAL-16', 'FLOAT-DECIMAL-34', 'FLOAT-EXTENDED',
            'FLOAT-INFINITY', 'FLOAT-LONG', 'FLOAT-NOT-A-NUMBER', 'FLOAT-SHORT', 'FOOTING', 'FOR', 'FOREGROUND-COLOR',
            'FOREGROUND-COLOUR', 'FOREVER', 'FORMAT', 'FREE', 'FROM', 'FULL', 'FUNCTION', 'FUNCTION-ID',
            'FUNCTION-POINTER', 'GENERATE', 'GET', 'GIVING', 'GLOBAL', 'GO', 'GOBACK', 'GREATER', 'GRID', 'GROUP',
            'GROUP-USAGE', 'HANDLE', 'HEADING', 'HIGH-VALUE', 'HIGH-VALUES', 'HIGHLIGHT', 'I-O', 'I-O-CONTROL', 'ID',
            'IDENTIFICATION', 'IF', 'IGNORE', 'IGNORING', 'IMPLEMENTS', 'IN', 'INDEX', 'INDEXED', 'INDICATE',
            'INHERITS', 'INITIAL', 'INITIALISE', 'INITIALISED', 'INITIALIZE', 'INITIALIZED', 'INITIATE', 'INPUT',
            'INPUT-OUTPUT', 'INSPECT', 'INTERFACE', 'INTERFACE-ID', 'INTERMEDIATE', 'INTO', 'INTRINSIC', 'INVALID',
            'INVOKE', 'IS', 'JUST', 'JUSTIFIED', 'KEPT', 'KEY', 'KEYBOARD', 'LABEL', 'LAST', 'LC_ALL', 'LC_COLLATE',
            'LC_CTYPE', 'LC_MESSAGES', 'LC_MONETARY', 'LC_NUMERIC', 'LC_TIME', 'LEADING', 'LEFT', 'LEFT-JUSTIFY',
            'LEFTLINE', 'LENGTH', 'LENGTH-CHECK', 'LESS', 'LIMIT', 'LIMITS', 'LINAGE', 'LINAGE-COUNTER', 'LINE',
            'LINE-COUNTER', 'LINES', 'LINKAGE', 'LOCAL-STORAGE', 'LOCALE', 'LOCK', 'LOW-VALUE', 'LOW-VALUES', 'LOWER',
            'LOWLIGHT', 'MAGNETIC-TAPE', 'MANUAL', 'MEMORY', 'MERGE', 'MESSAGE', 'METHOD', 'METHOD-ID', 'MINUS', 'MODE',
            'MOVE', 'MULTIPLE', 'MULTIPLY', 'NAME', 'NATIONAL', 'NATIONAL-EDITED', 'NATIVE', 'NEAREST-AWAY-FROM-ZERO',
            'NEAREST-EVEN', 'NEAREST-TOWARD-ZERO', 'NEGATIVE', 'NESTED', 'NEXT', 'NO', 'NO-ECHO', 'NONE', 'NORMAL',
            'NOT', 'NOTHING', 'NULL', 'NULLS', 'NUMBER', 'NUMBERS', 'NUMERIC', 'NUMERIC-EDITED', 'OBJECT',
            'OBJECT-COMPUTER', 'OBJECT-REFERENCE', 'OCCURS', 'OF', 'OFF', 'OMITTED', 'ON', 'ONLY', 'OPEN', 'OPTIONAL',
            'OPTIONS', 'OR', 'ORDER', 'ORGANISATION', 'ORGANIZATION', 'OTHER', 'OUTPUT', 'OVERFLOW', 'OVERLINE',
            'OVERRIDE', 'PACKED-DECIMAL', 'PADDING', 'PAGE', 'PAGE-COUNTER', 'PARAGRAPH', 'PERFORM', 'PF', 'PH', 'PIC',
            'PICTURE', 'PLUS', 'POINTER', 'POSITION', 'POSITIVE', 'PREFIXED', 'PRESENT', 'PREVIOUS', 'PRINT', 'PRINTER',
            'PRINTER-1', 'PRINTING', 'PROCEDURE', 'PROCEDURE-POINTER', 'PROCEDURES', 'PROCEED', 'PROGRAM', 'PROGRAM-ID',
            'PROGRAM-POINTER', 'PROHIBITED', 'PROMPT', 'PROPERTY', 'PROTECTED', 'PROTOTYPE', 'PURGE', 'QUEUE', 'QUOTE',
            'QUOTES', 'RAISE', 'RAISING', 'RANDOM', 'RD', 'READ', 'RECEIVE', 'RECORD', 'RECORDING', 'RECORDS',
            'RECURSIVE', 'REDEFINES', 'REEL', 'REFERENCE', 'REFERENCES', 'RELATION', 'RELATIVE', 'RELEASE', 'REMAINDER',
            'REMOVAL', 'RENAMES', 'REPLACE', 'REPLACING', 'REPORT', 'REPORTING', 'REPORTS', 'REPOSITORY', 'REQUIRED',
            'RESERVE', 'RESET', 'RESUME', 'RETRY', 'RETURN', 'RETURNING', 'REVERSE', 'REVERSE-VIDEO', 'REVERSED',
            'REWIND', 'REWRITE', 'RF', 'RH', 'RIGHT', 'RIGHT-JUSTIFY', 'ROLLBACK', 'ROUNDED', 'ROUNDING', 'RUN', 'S',
            'SAME', 'SCREEN', 'SCROLL', 'SD', 'SEARCH', 'SECONDS', 'SECTION', 'SECURE', 'SEGMENT', 'SEGMENT-LIMIT',
            'SELECT', 'SELF', 'SEND', 'SENTENCE', 'SEPARATE', 'SEQUENCE', 'SEQUENTIAL', 'SET', 'SHARING', 'SIGN',
            'SIGNED', 'SIGNED-INT', 'SIGNED-LONG', 'SIGNED-SHORT', 'SIZE', 'SORT', 'SORT-MERGE', 'SOURCE',
            'SOURCE-COMPUTER', 'SOURCES', 'SPACE', 'SPACE-FILL', 'SPACES', 'SPECIAL-NAMES', 'STANDARD', 'STANDARD-1',
            'STANDARD-2', 'STANDARD-BINARY', 'STANDARD-DECIMAL', 'START', 'STATEMENT', 'STATIC', 'STATUS', 'STDCALL',
            'STEP', 'STOP', 'STRING', 'STRONG', 'SUB-QUEUE-1', 'SUB-QUEUE-2', 'SUB-QUEUE-3', 'SUBTRACT', 'SUM', 'SUPER',
            'SUPPRESS', 'SYMBOL', 'SYMBOLIC', 'SYNC', 'SYNCHRONISED', 'SYNCHRONIZED', 'SYSTEM-DEFAULT', 'SYSTEM-OFFSET',
            'TAB', 'TABLE', 'TALLYING', 'TAPE', 'TERMINATE', 'TEST', 'TEXT', 'THAN', 'THREAD', 'THEN', 'THROUGH',
            'THRU', 'TIME', 'TIME-OUT', 'TIMEOUT', 'TIMES', 'TO', 'TOP', 'TOWARD-GREATER', 'TOWARD-LESSER', 'TRAILING',
            'TRAILING-SIGN', 'TRANSFORM', 'TRUE', 'TRUNCATION', 'TYPE', 'TYPEDEF', 'U', 'UCS-4', 'UNBOUNDED',
            'UNDERLINE', 'UNIT', 'UNIVERSAL', 'UNLOCK', 'UNSIGNED', 'UNSIGNED-INT', 'UNSIGNED-LONG', 'UNSIGNED-SHORT',
            'UNSTRING', 'UNTIL', 'UP', 'UPDATE', 'UPON', 'UPPER', 'USAGE', 'USE', 'USER', 'USER-DEFAULT', 'USING',
            'UTF-16', 'UTF-8', 'V', 'VAL-STATUS', 'VALID', 'VALIDATE', 'VALIDATE-STATUS', 'VALUE', 'VALUES', 'VARIABLE',
            'VARYING', 'WAIT', 'WHEN', 'WINDOW', 'WITH', 'WORDS', 'WORKING-STORAGE', 'WRITE', 'YYYYDDD', 'YYYYMMDD',
            'ZERO', 'ZERO-FILL', 'ZEROES', 'ZEROS', 'AUTHOR', 'DATE-COMPILED', 'DATE-MODIFIED', 'DATE-WRITTEN',
            'INSTALLATION', 'REMARKS', 'SECURITY', 'RETURN-CODE', 'SORT-RETURN', 'NUMBER-OF-CALL-PARAMETERS',
            'COB-CRT-STATUS', 'TALLY', 'LENGTH OF']

MNEMONICS = ['SYSIN', 'SYSIPT', 'STDIN', 'SYSOUT', 'SYSLIST', 'SYSLST', 'STDOUT', 'PRINT', 'PRINTER', 'PRINTER-1',
             'SYSERR', 'STDERR', 'CONSOLE', 'C01', 'C02', 'C03', 'C04', 'C05', 'C06', 'C07', 'C08', 'C09', 'C10', 'C11',
             'C12', 'CSP', 'FORMFEED', 'CALL-CONVENTION', 'SWITCH-0', 'SWITCH-1', 'SWITCH-2', 'SWITCH-3', 'SWITCH-4',
             'SWITCH-5', 'SWITCH-6', 'SWITCH-7', 'SWITCH-8', 'SWITCH-9', 'SWITCH-10', 'SWITCH-11', 'SWITCH-12',
             'SWITCH-13', 'SWITCH-14', 'SWITCH-15', 'SWITCH-16', 'SWITCH-17', 'SWITCH-18', 'SWITCH-19', 'SWITCH-20',
             'SWITCH-21', 'SWITCH-22', 'SWITCH-23', 'SWITCH-24', 'SWITCH-25', 'SWITCH-26', 'SWITCH-27', 'SWITCH-28',
             'SWITCH-29', 'SWITCH-30', 'SWITCH-31', 'SWITCH-32', 'SWITCH-33', 'SWITCH-34', 'SWITCH-35', 'SWITCH-36',
             'SW0', 'SW1', 'SW2', 'SW3', 'SW4', 'SW5', 'SW6', 'SW7', 'SW8', 'SW9', 'SW10', 'SW11', 'SW12', 'SW13',
             'SW14', 'SW15', 'SWITCH 0', 'SWITCH 1', 'SWITCH 2', 'SWITCH 3', 'SWITCH 4', 'SWITCH 5', 'SWITCH 6',
             'SWITCH 7', 'SWITCH 8', 'SWITCH 9', 'SWITCH 10', 'SWITCH 11', 'SWITCH 12', 'SWITCH 13', 'SWITCH 14',
             'SWITCH 15', 'SWITCH 16', 'SWITCH 17', 'SWITCH 18', 'SWITCH 19', 'SWITCH 20', 'SWITCH 21', 'SWITCH 22',
             'SWITCH 23', 'SWITCH 24', 'SWITCH 25', 'SWITCH 26', 'SWITCH A', 'SWITCH B', 'SWITCH C', 'SWITCH D',
             'SWITCH E', 'SWITCH F', 'SWITCH G', 'SWITCH H', 'SWITCH I', 'SWITCH J', 'SWITCH K', 'SWITCH L', 'SWITCH M',
             'SWITCH N', 'SWITCH O', 'SWITCH P', 'SWITCH Q', 'SWITCH R', 'SWITCH S', 'SWITCH T', 'SWITCH U', 'SWITCH V',
             'SWITCH W', 'SWITCH X', 'SWITCH Y', 'SWITCH Z']

SQL_COBOL_KEYWORDS = ['EXEC', 'SQL', 'END-EXEC', 'INSERT', 'INCLUDE']

ALL_KEYWORDS = INTRINSICS + RESERVED + MNEMONICS
