;Software Serial 16MHz Mikrocontroller (Pin 2)

.equ BAUDRATE	= 4800			;Baud
.equ FREQUENCY	= 16000000		;Hz

jmp start

;Platz für ISR

.include "SoftSerial.inc"

start:

call ser_init

ldi r20, 'A'

loop:
	call ser_out
	inc r20
	rcall sek
	rjmp loop