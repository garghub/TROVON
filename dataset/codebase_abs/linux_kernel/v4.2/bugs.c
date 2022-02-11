static void T_1 F_1 ( void )
{
T_2 V_1 ;
T_3 V_2 ;
V_1 = F_2 () ;
F_3 ( V_1 & ~ V_3 ) ;
F_4 () ;
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
F_5 () ;
F_3 ( V_1 ) ;
if ( V_2 ) {
F_6 ( & V_4 , V_5 ) ;
F_7 ( L_1 ) ;
}
}
void T_1 F_8 ( void )
{
if ( V_6 )
F_1 () ;
}
