141,144c141,146
< Error: TOO_FEW_TAB          (line:  85, col:  22):	Missing tabs for indent level
< Error: TOO_MANY_INSTR       (line:  85, col:  22):	Too many instructions on a single line
< Error: EXP_NEWLINE          (line:  85, col:  32):	Expected newline after control structure
< Error: TOO_MANY_LINES       (line:  92, col:   1):	Function has more than 25 lines
---
> Error: TOO_FEW_TAB          (line:  83, col:  22):	Missing tabs for indent level
> Error: TOO_MANY_INSTR       (line:  83, col:  22):	Too many instructions on a single line
> Error: EXP_NEWLINE          (line:  83, col:  32):	Expected newline after control structure
> Error: TOO_MANY_LINES       (line:  90, col:   1):	Function has more than 25 lines
> Error: CONSECUTIVE_NEWLINES (line: 112, col:   1):	Consecutive newlines
> Error: CONSECUTIVE_NEWLINES (line: 113, col:   1):	Consecutive newlines
196,198c198
< Error: CONSECUTIVE_NEWLINES (line: 165, col:   1):	Consecutive newlines
< Error: CONSECUTIVE_NEWLINES (line: 166, col:   1):	Consecutive newlines
< Error: EMPTY_LINE_EOF       (line: 191, col:   1):	Empty line at end of file
---
> Error: EMPTY_LINE_EOF       (line: 189, col:   1):	Empty line at end of file
263c263
< [37mfiles/42_with_nl: [32m1.OK [31m2.KO [31m3.KO [31mLEAKS.KO [0x7f8466e04260 : 44] [0m
---
> [37mfiles/42_with_nl: [32m1.OK [31m2.KO [31m3.KO [31mLEAKS.KO [0x7fbcab804260 : 44] [0m
385c385
< Failed tests: gnlTester, fsoares
---
> Failed tests: fsoares, gnlTester
