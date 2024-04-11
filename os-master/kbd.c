#include "i8259.h"
#include "printf.h"
#include "x86.h"

static char sc[] = {' ', ' ',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
    '`', ' ',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']',
    ' ', ' ',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '"', ' ', ' ', ' ',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
    ' ', ' ', ' ', 'a'};

/* scancode to ascii */
void
sctoa(char scod)
{
    if (scod >= 0 && scod <= 0x39) {
        printf("%c", sc[scod]);
    } else if ((scod - 0x80) <= 0x39) {
    }
}

/* keyboard interrupt service handler */
void
kbd_isr()
{
	eoi(PIC1_CTLR);
	sctoa(inb(0x60));
}
