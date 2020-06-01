;Please set BAUDRATE and FREQUENCY in main:
; .equ BAUDRATE = 9600
; .equ FREQUENCY = 16000000

;Data accepted at r20

;uses r31, r30, r29, r25

;Port setup
.equ SERPORT	= PORTD
.equ SERCONF	= DDRD
.equ SERNUM	= 2

/*
 * -----------------------------
 *	Include section
*/
.ifndef FREQUENCY
.message "No Frequency specified"
.endif

.include "Time.inc"

.if FREQUENCY == 16000000
.include "SerialTime16MHz.inc"
.endif

.if FREQUENCY == 9600000
.include "SerialTime9.6MHz.inc"
.endif

.if FREQUENCY == 4800000
.include "SerialTime4.8MHz.inc"
.endif

/*
 * --------------------------
 *	Subs
*/
ser_init:
	sbi SERCONF, SERNUM
	ret

ser_out:
	mov r25, r20	;Copy Data

	;Start Bit
	rcall bit_l

	sbrs r25,0
	rcall bit_l
	sbrc r25,0
	rcall bit_h

	sbrs r25,1
	rcall bit_l
	sbrc r25,1
	rcall bit_h

	sbrs r25,2
	rcall bit_l
	sbrc r25,2
	rcall bit_h

	sbrs r25,3
	rcall bit_l
	sbrc r25,3
	rcall bit_h

	sbrs r25,4
	rcall bit_l
	sbrc r25,4
	rcall bit_h

	sbrs r25,5
	rcall bit_l
	sbrc r25,5
	rcall bit_h

	sbrs r25,6
	rcall bit_l
	sbrc r25,6
	rcall bit_h

	sbrs r25,7
	rcall bit_l
	sbrc r25,7
	rcall bit_h

	;Parity (immer 1)
	rcall bit_h

	;Stop bit
	sbi SERPORT, SERNUM
	ret

bit_h:
	sbi SERPORT, SERNUM
	rcall baud
	ret

bit_l:
	cbi SERPORT, SERNUM
	rcall baud
	ret
