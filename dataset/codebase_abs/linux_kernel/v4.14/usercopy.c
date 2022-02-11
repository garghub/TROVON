unsigned long F_1 ( void T_1 * V_1 , const void * V_2 ,
unsigned long V_3 )
{
register char T_1 * T_2 V_4 ( L_1 ) = V_1 ;
register const char * T_3 V_4 ( L_2 ) = V_2 ;
unsigned long V_5 = 0 ;
if ( V_3 == 0 )
return 0 ;
if ( ( unsigned long ) T_3 & 1 ) {
F_2 ( T_2 , T_3 , V_5 ) ;
V_3 -- ;
if ( V_5 )
return V_5 + V_3 ;
}
if ( ( unsigned long ) T_2 & 1 ) {
while ( V_3 > 0 ) {
F_2 ( T_2 , T_3 , V_5 ) ;
V_3 -- ;
if ( V_5 )
return V_5 + V_3 ;
}
}
if ( ( ( unsigned long ) T_3 & 2 ) && V_3 >= 2 ) {
F_3 ( T_2 , T_3 , V_5 ) ;
V_3 -= 2 ;
if ( V_5 )
return V_5 + V_3 ;
}
if ( ( unsigned long ) T_2 & 2 ) {
while ( V_3 >= 2 ) {
F_3 ( T_2 , T_3 , V_5 ) ;
V_3 -= 2 ;
if ( V_5 )
return V_5 + V_3 ;
}
}
#ifdef F_4
if ( ! ( ( ( unsigned long ) T_3 | ( V_6 unsigned long ) T_2 ) & 7 ) ) {
if ( V_3 >= V_7 ) {
F_5 ( T_2 , T_3 , V_5 ,
V_3 , L_3 ) ;
}
while ( V_3 >= 8 ) {
F_6 ( T_2 , T_3 , V_5 ) ;
V_3 -= 8 ;
if ( V_5 )
return V_5 + V_3 ;
}
}
if ( V_3 >= V_7 ) {
F_7 ( T_2 , T_3 , V_5 , V_3 , L_4 ) ;
}
#else
if ( ! ( ( ( unsigned long ) T_3 | ( V_6 unsigned long ) T_2 ) & 7 ) ) {
while ( V_3 >= 8 ) {
F_6 ( T_2 , T_3 , V_5 ) ;
V_3 -= 8 ;
if ( V_5 )
return V_5 + V_3 ;
}
}
#endif
while ( V_3 >= 16 ) {
F_8 ( T_2 , T_3 , V_5 ) ;
V_3 -= 16 ;
if ( V_5 )
return V_5 + V_3 ;
}
while ( V_3 >= 4 ) {
F_9 ( T_2 , T_3 , V_5 ) ;
V_3 -= 4 ;
if ( V_5 )
return V_5 + V_3 ;
}
switch ( V_3 ) {
case 0 :
break;
case 1 :
F_2 ( T_2 , T_3 , V_5 ) ;
break;
case 2 :
F_3 ( T_2 , T_3 , V_5 ) ;
break;
case 3 :
F_10 ( T_2 , T_3 , V_5 ) ;
break;
}
return V_5 ;
}
unsigned long F_11 ( void * V_1 , const void T_1 * V_2 ,
unsigned long V_3 )
{
register char * T_2 V_4 ( L_1 ) = V_1 ;
register const char T_1 * T_3 V_4 ( L_2 ) = V_2 ;
unsigned long V_5 = 0 ;
if ( V_3 == 0 )
return 0 ;
if ( ( unsigned long ) T_3 & 1 ) {
F_12 ( T_2 , T_3 , V_5 ) ;
V_3 -- ;
if ( V_5 )
return V_5 + V_3 ;
}
if ( ( unsigned long ) T_2 & 1 ) {
while ( V_3 > 0 ) {
F_12 ( T_2 , T_3 , V_5 ) ;
V_3 -- ;
if ( V_5 )
return V_5 + V_3 ;
}
}
if ( ( ( unsigned long ) T_3 & 2 ) && V_3 >= 2 ) {
F_13 ( T_2 , T_3 , V_5 ) ;
V_3 -= 2 ;
if ( V_5 )
return V_5 + V_3 ;
}
if ( ( unsigned long ) T_2 & 2 ) {
while ( V_3 >= 2 ) {
F_13 ( T_2 , T_3 , V_5 ) ;
V_3 -= 2 ;
if ( V_5 )
return V_5 + V_3 ;
}
}
#ifdef F_4
if ( ! ( ( ( unsigned long ) T_3 | ( unsigned long ) T_2 ) & 7 ) ) {
if ( V_3 >= V_7 ) {
F_14 ( T_2 , T_3 , V_5 ,
V_3 , L_5 ) ;
}
while ( V_3 >= 8 ) {
F_15 ( T_2 , T_3 , V_5 ) ;
V_3 -= 8 ;
if ( V_5 )
return V_5 + V_3 ;
}
}
if ( V_3 >= V_7 ) {
F_16 ( T_2 , T_3 , V_5 ,
V_3 , L_6 ) ;
}
#else
if ( ! ( ( ( unsigned long ) T_3 | ( unsigned long ) T_2 ) & 7 ) ) {
while ( V_3 >= 8 ) {
F_15 ( T_2 , T_3 , V_5 ) ;
V_3 -= 8 ;
if ( V_5 )
return V_5 + V_3 ;
}
}
#endif
while ( V_3 >= 4 ) {
F_17 ( T_2 , T_3 , V_5 ) ;
V_3 -= 4 ;
if ( V_5 )
return V_5 + V_3 ;
}
switch ( V_3 ) {
case 0 :
break;
case 1 :
F_12 ( T_2 , T_3 , V_5 ) ;
break;
case 2 :
F_13 ( T_2 , T_3 , V_5 ) ;
break;
case 3 :
F_18 ( T_2 , T_3 , V_5 ) ;
break;
}
return V_5 ;
}
unsigned long F_19 ( void T_1 * V_8 , unsigned long V_9 )
{
register char T_1 * T_2 V_4 ( L_7 ) = V_8 ;
register unsigned long V_3 V_4 ( L_8 ) = V_9 ;
register unsigned long V_5 V_4 ( L_9 ) = 0 ;
if ( ( unsigned long ) T_2 & 1 ) {
F_20 ( T_2 , V_5 ) ;
V_3 -- ;
}
if ( ( unsigned long ) T_2 & 2 ) {
F_21 ( T_2 , V_5 ) ;
V_3 -= 2 ;
}
if ( ! ( ( V_6 unsigned long ) T_2 & 7 ) ) {
while ( V_3 >= 8 ) {
F_22 ( T_2 , V_5 ) ;
V_3 -= 8 ;
}
}
while ( V_3 >= 16 ) {
F_23 ( T_2 , V_5 ) ;
V_3 -= 16 ;
}
while ( V_3 >= 4 ) {
F_24 ( T_2 , V_5 ) ;
V_3 -= 4 ;
}
switch ( V_3 ) {
case 0 :
break;
case 1 :
F_20 ( T_2 , V_5 ) ;
break;
case 2 :
F_21 ( T_2 , V_5 ) ;
break;
case 3 :
F_25 ( T_2 , V_5 ) ;
break;
}
return V_5 ;
}
unsigned char F_26 ( const void T_1 * V_10 , long * V_11 )
{
register unsigned char T_4 V_4 ( L_7 ) = 0 ;
asm volatile (
" GETB %0,[%2]\n"
"1:\n"
" GETB %0,[%2]\n"
"2:\n"
" .section .fixup,\"ax\"\n"
"3: MOV D0FrT,%3\n"
" SETD [%1],D0FrT\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,3b\n"
" .previous\n"
: "=r" (x)
: "r" (err), "r" (addr), "P" (-EFAULT)
: "D0FrT");
return T_4 ;
}
unsigned short F_27 ( const void T_1 * V_10 , long * V_11 )
{
register unsigned short T_4 V_4 ( L_7 ) = 0 ;
asm volatile (
" GETW %0,[%2]\n"
"1:\n"
" GETW %0,[%2]\n"
"2:\n"
" .section .fixup,\"ax\"\n"
"3: MOV D0FrT,%3\n"
" SETD [%1],D0FrT\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,3b\n"
" .previous\n"
: "=r" (x)
: "r" (err), "r" (addr), "P" (-EFAULT)
: "D0FrT");
return T_4 ;
}
unsigned int F_28 ( const void T_1 * V_10 , long * V_11 )
{
register unsigned int T_4 V_4 ( L_7 ) = 0 ;
asm volatile (
" GETD %0,[%2]\n"
"1:\n"
" GETD %0,[%2]\n"
"2:\n"
" .section .fixup,\"ax\"\n"
"3: MOV D0FrT,%3\n"
" SETD [%1],D0FrT\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,3b\n"
" .previous\n"
: "=r" (x)
: "r" (err), "r" (addr), "P" (-EFAULT)
: "D0FrT");
return T_4 ;
}
unsigned long long F_29 ( const void T_1 * V_10 , long * V_11 )
{
register unsigned long long T_4 V_4 ( L_7 ) = 0 ;
asm volatile (
" GETL %0,%t0,[%2]\n"
"1:\n"
" GETL %0,%t0,[%2]\n"
"2:\n"
" .section .fixup,\"ax\"\n"
"3: MOV D0FrT,%3\n"
" SETD [%1],D0FrT\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,3b\n"
" .previous\n"
: "=r" (x)
: "r" (err), "r" (addr), "P" (-EFAULT)
: "D0FrT");
return T_4 ;
}
long F_30 ( unsigned int T_4 , void T_1 * V_10 )
{
register unsigned int V_11 V_4 ( L_7 ) = 0 ;
asm volatile (
" MOV %0,#0\n"
" SETB [%2],%1\n"
"1:\n"
" SETB [%2],%1\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: MOV %0,%3\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .long 1b,3b\n"
".previous"
: "=r"(err)
: "d" (x), "a" (addr), "P"(-EFAULT)
: "D0FrT");
return V_11 ;
}
long F_31 ( unsigned int T_4 , void T_1 * V_10 )
{
register unsigned int V_11 V_4 ( L_7 ) = 0 ;
asm volatile (
" MOV %0,#0\n"
" SETW [%2],%1\n"
"1:\n"
" SETW [%2],%1\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: MOV %0,%3\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .long 1b,3b\n"
".previous"
: "=r"(err)
: "d" (x), "a" (addr), "P"(-EFAULT)
: "D0FrT");
return V_11 ;
}
long F_32 ( unsigned int T_4 , void T_1 * V_10 )
{
register unsigned int V_11 V_4 ( L_7 ) = 0 ;
asm volatile (
" MOV %0,#0\n"
" SETD [%2],%1\n"
"1:\n"
" SETD [%2],%1\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: MOV %0,%3\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .long 1b,3b\n"
".previous"
: "=r"(err)
: "d" (x), "a" (addr), "P"(-EFAULT)
: "D0FrT");
return V_11 ;
}
long F_33 ( unsigned long long T_4 , void T_1 * V_10 )
{
register unsigned int V_11 V_4 ( L_7 ) = 0 ;
asm volatile (
" MOV %0,#0\n"
" SETL [%2],%1,%t1\n"
"1:\n"
" SETL [%2],%1,%t1\n"
"2:\n"
".section .fixup,\"ax\"\n"
"3: MOV %0,%3\n"
" MOVT D0FrT,#HI(2b)\n"
" JUMP D0FrT,#LO(2b)\n"
".previous\n"
".section __ex_table,\"a\"\n"
" .long 1b,3b\n"
".previous"
: "=r"(err)
: "d" (x), "a" (addr), "P"(-EFAULT)
: "D0FrT");
return V_11 ;
}
long F_34 ( const char T_1 * T_3 , long V_12 )
{
long V_13 ;
if ( ! F_35 ( V_14 , T_3 , 0 ) )
return 0 ;
asm volatile (" MOV D0Ar4, %1\n"
" MOV D0Ar6, %2\n"
"0:\n"
" SUBS D0FrT, D0Ar6, #0\n"
" SUB D0Ar6, D0Ar6, #1\n"
" BLE 2f\n"
" GETB D0FrT, [D0Ar4+#1++]\n"
"1:\n"
" TST D0FrT, #255\n"
" BNE 0b\n"
"2:\n"
" SUB %0, %2, D0Ar6\n"
"3:\n"
" .section .fixup,\"ax\"\n"
"4:\n"
" MOV %0, #0\n"
" MOVT D0FrT,#HI(3b)\n"
" JUMP D0FrT,#LO(3b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 1b,4b\n"
" .previous\n"
: "=r" (res)
: "r" (src), "r" (count)
: "D0FrT", "D0Ar4", "D0Ar6", "cc");
return V_13 ;
}
long F_36 ( char * T_2 , const char T_1 * T_3 , long V_12 )
{
long V_13 ;
if ( V_12 == 0 )
return 0 ;
asm volatile (" MOV %0,%3\n"
"1:\n"
" GETB D0FrT,[%2++]\n"
"2:\n"
" CMP D0FrT,#0\n"
" SETB [%1++],D0FrT\n"
" BEQ 3f\n"
" SUBS %0,%0,#1\n"
" BNZ 1b\n"
"3:\n"
" SUB %0,%3,%0\n"
"4:\n"
" .section .fixup,\"ax\"\n"
"5:\n"
" MOV %0,%7\n"
" MOVT D0FrT,#HI(4b)\n"
" JUMP D0FrT,#LO(4b)\n"
" .previous\n"
" .section __ex_table,\"a\"\n"
" .long 2b,5b\n"
" .previous"
: "=r" (res), "=r" (dst), "=r" (src), "=r" (count)
: "3" (count), "1" (dst), "2" (src), "P" (-EFAULT)
: "D0FrT", "memory", "cc");
return V_13 ;
}
