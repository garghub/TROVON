static void T_1 F_1 ( void )
{
T_2 V_1 ;
F_2 () ;
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
F_3 () ;
if ( V_1 ) {
F_4 ( & V_2 , V_3 ) ;
F_5 ( L_1 ) ;
}
}
void T_1 F_6 ( void )
{
F_7 () ;
#ifndef F_8
F_9 ( L_2 ) ;
F_10 ( & V_2 ) ;
#endif
if ( V_2 . V_4 < 4 )
F_11 ( L_3 ) ;
F_12 () -> V_5 [ 1 ] =
'0' + ( V_2 . V_4 > 6 ? 6 : V_2 . V_4 ) ;
F_13 () ;
if ( V_6 )
F_1 () ;
}
