static int T_1 F_1 ( char * V_1 )
{
F_2 ( 1 , L_1 ) ;
V_2 . V_3 = 0 ;
return 1 ;
}
static int T_1 F_3 ( char * V_1 )
{
V_2 . V_4 = 0 ;
F_4 ( V_5 | V_6 | V_7 | F_5 () ) ;
return 1 ;
}
static void T_1 F_6 ( void )
{
T_2 V_8 ;
if ( ! V_2 . V_4 ) {
#ifndef F_7
F_8 ( L_2 ) ;
F_8 ( L_3 ) ;
for (; ; ) ;
#endif
return;
}
F_9 () ;
__asm__("fninit\n\t"
"fldl %1\n\t"
"fdivl %2\n\t"
"fmull %2\n\t"
"fldl %1\n\t"
"fsubp %%st,%%st(1)\n\t"
"fistpl %0\n\t"
"fwait\n\t"
"fninit"
: "=m" (*&fdiv_bug)
: "m" (*&x), "m" (*&y));
F_10 () ;
V_2 . V_8 = V_8 ;
if ( V_2 . V_8 )
F_11 ( L_4 ) ;
}
static void T_1 F_12 ( void )
{
if ( V_2 . V_9 >= 5 || F_13 () )
return;
F_14 ( L_5 ) ;
if ( ! V_2 . V_3 ) {
F_15 ( L_6 ) ;
return;
}
F_16 () ;
F_16 () ;
F_16 () ;
F_16 () ;
F_15 ( L_7 ) ;
}
static void T_1 F_17 ( void )
{
#ifndef F_18
int V_10 , V_11 = ( int ) & V_10 ;
F_14 ( L_8 ) ;
__asm__ __volatile__(
"movl $12345678,%%eax; movl $0,%%edi; pusha; popa; movl (%%edx,%%edi),%%ecx "
: "=&a" (res)
: "d" (inp)
: "ecx", "edi");
if ( V_10 != 12345678 )
F_15 ( L_9 ) ;
else
F_15 ( L_7 ) ;
#endif
}
static void T_1 F_19 ( void )
{
#if F_20 ( V_12 ) || F_20 ( V_13 ) || \
F_20 ( V_14 )
if ( V_2 . V_9 == 3 )
F_21 ( L_10 ) ;
#endif
}
void T_1 F_22 ( void )
{
F_23 () ;
#ifndef F_24
F_14 ( L_11 ) ;
F_25 ( & V_2 ) ;
#endif
F_19 () ;
F_12 () ;
F_17 () ;
F_26 () -> V_15 [ 1 ] =
'0' + ( V_2 . V_9 > 6 ? 6 : V_2 . V_9 ) ;
F_27 () ;
F_6 () ;
}
