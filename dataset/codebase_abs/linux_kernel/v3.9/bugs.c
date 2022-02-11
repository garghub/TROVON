static int T_1 F_1 ( char * V_1 )
{
V_2 . V_3 = 0 ;
F_2 ( V_4 | V_5 | V_6 | F_3 () ) ;
return 1 ;
}
static void T_1 F_4 ( void )
{
T_2 V_7 ;
if ( ! V_2 . V_3 ) {
#ifndef F_5
F_6 ( L_1 ) ;
F_6 ( L_2 ) ;
for (; ; ) ;
#endif
return;
}
F_7 () ;
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
F_8 () ;
V_2 . V_7 = V_7 ;
if ( V_2 . V_7 )
F_9 ( L_3 ) ;
}
static void T_1 F_10 ( void )
{
if ( V_2 . V_8 < 4 )
F_11 ( L_4 ) ;
}
void T_1 F_12 ( void )
{
F_13 () ;
#ifndef F_14
F_15 ( L_5 ) ;
F_16 ( & V_2 ) ;
#endif
F_10 () ;
F_17 () -> V_9 [ 1 ] =
'0' + ( V_2 . V_8 > 6 ? 6 : V_2 . V_8 ) ;
F_18 () ;
F_4 () ;
}
