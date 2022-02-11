void * memset ( void * V_1 , int V_2 , unsigned int V_3 )
{
register char * T_1 V_4 ( L_1 ) = V_1 ;
register int T_2 V_4 ( L_2 ) = V_3 ;
register int T_3 V_4 ( L_3 ) = V_2 ;
__asm__("movu.b %0,r13 \n\
lslq 8,r13 \n\
move.b %0,r13 \n\
move.d r13,%0 \n\
lslq 16,r13 \n\
or.d r13,%0"
: "=r" (lc)
: "0" (lc)
: "r13");
{
register char * T_4 V_4 ( L_4 ) = V_1 ;
if ( ( ( unsigned long ) V_1 & 3 ) != 0
&& T_2 >= 3 )
{
if ( ( unsigned long ) T_4 & 1 )
{
* T_4 = ( char ) T_3 ;
T_2 -- ;
T_4 ++ ;
}
if ( ( unsigned long ) T_4 & 2 )
{
* ( short * ) T_4 = T_3 ;
T_2 -= 2 ;
T_4 += 2 ;
}
}
if ( T_2 >= V_5 )
{
__asm__ volatile
("\
;; GCC does promise correct register allocations, but let's \n\
;; make sure it keeps its promises. \n\
.ifnc %0-%1-%4,$r13-$r12-$r11 \n\
.error \"GCC reg alloc bug: %0-%1-%4 != $r13-$r12-$r11\" \n\
.endif \n\
\n\
;; Save the registers we'll clobber in the movem process \n\
;; on the stack. Don't mention them to gcc, it will only be \n\
;; upset. \n\
subq 11*4,sp \n\
movem r10,[sp] \n\
\n\
move.d r11,r0 \n\
move.d r11,r1 \n\
move.d r11,r2 \n\
move.d r11,r3 \n\
move.d r11,r4 \n\
move.d r11,r5 \n\
move.d r11,r6 \n\
move.d r11,r7 \n\
move.d r11,r8 \n\
move.d r11,r9 \n\
move.d r11,r10 \n\
\n\
;; Now we've got this: \n\
;; r13 - dst \n\
;; r12 - n \n\
\n\
;; Update n for the first loop \n\
subq 12*4,r12 \n\
0: \n\
"
#ifdef F_1
" setf\n"
#endif
" subq 12*4,r12 \n\
bge 0b \n\
movem r11,[r13+] \n\
\n\
;; Compensate for last loop underflowing n. \n\
addq 12*4,r12 \n\
\n\
;; Restore registers from stack. \n\
movem [sp+],r10"
: "=r" (dst), "=r" (n)
: "0" (dst), "1" (n), "r" (lc));
}
while ( T_2 >= 16 )
{
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
T_2 -= 16 ;
}
switch ( T_2 )
{
case 0 :
break;
case 1 :
* T_4 = ( char ) T_3 ;
break;
case 2 :
* ( short * ) T_4 = ( short ) T_3 ;
break;
case 3 :
* ( short * ) T_4 = ( short ) T_3 ; T_4 += 2 ;
* T_4 = ( char ) T_3 ;
break;
case 4 :
* ( long * ) T_4 = T_3 ;
break;
case 5 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* T_4 = ( char ) T_3 ;
break;
case 6 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( short * ) T_4 = ( short ) T_3 ;
break;
case 7 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( short * ) T_4 = ( short ) T_3 ; T_4 += 2 ;
* T_4 = ( char ) T_3 ;
break;
case 8 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ;
break;
case 9 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* T_4 = ( char ) T_3 ;
break;
case 10 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( short * ) T_4 = ( short ) T_3 ;
break;
case 11 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( short * ) T_4 = ( short ) T_3 ; T_4 += 2 ;
* T_4 = ( char ) T_3 ;
break;
case 12 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ;
break;
case 13 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* T_4 = ( char ) T_3 ;
break;
case 14 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( short * ) T_4 = ( short ) T_3 ;
break;
case 15 :
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( long * ) T_4 = T_3 ; T_4 += 4 ;
* ( short * ) T_4 = ( short ) T_3 ; T_4 += 2 ;
* T_4 = ( char ) T_3 ;
break;
}
}
return T_1 ;
}
