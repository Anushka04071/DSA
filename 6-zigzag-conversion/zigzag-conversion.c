#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows) {
    if (numRows == 1 || strlen(s) <= numRows) {
        return s;
    }
    
    int len = strlen(s);
    char* result = (char*)malloc(sizeof(char) * (len + 1));
    int resIndex = 0;
    
    int cycleLen = 2 * (numRows - 1);
    
    for (int i = 0; i < numRows; i++) {
        for (int j = i; j < len; j += cycleLen) {
            // Add character for the current row
            result[resIndex++] = s[j];
            
            // Add diagonal character for middle rows
            if (i > 0 && i < numRows - 1) {
                int diagonalIndex = j + cycleLen - 2 * i;
                if (diagonalIndex < len) {
                    result[resIndex++] = s[diagonalIndex];
                }
            }
        }
    }
    
    result[resIndex] = '\0';
    return result;
}
