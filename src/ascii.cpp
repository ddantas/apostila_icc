/* Programa que imprime os 128 caracteres da tabela ASCII.
*/

# include <stdio.h>

#define NUMCOL  4
#define MAXCHAR 127

main()
{
    const char* arrName[] = {"NUL", "STX", "SOT", "ETX", "EOT", "ENQ", "ACK", "BEL", "BS", "HT", "LF", "VT", "FF", "CR", "SO", "SI", "DLE", "DC1", "DC2", "DC3", "DC4", "NAK", "SYN", "ETB", "CAN", "EM", "SUB", "ESC", "FS", "GS", "RS", "US"}; 
    const int arrNameSize = 32;

    for(int i = 0; i < (MAXCHAR + 1) / NUMCOL; i++)
    {
        for(int j = 0; j < NUMCOL; j++)
        {
            int c = j * ((MAXCHAR + 1) / NUMCOL) + i;
            if (c < arrNameSize)
            {
                printf("| %3d 0x%02X %3s ", c, c, arrName[c]);
            }
            else
            {
                printf("| %3d 0x%02X %3c ", c, c, c);
            }
        }
        printf("|\n");
    }
}
