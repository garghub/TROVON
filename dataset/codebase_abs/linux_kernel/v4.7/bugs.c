void T_1 F_1 ( void )
{
T_2 V_1 ;
T_3 V_2 ;
if ( ! F_2 ( V_3 ) )
return;
V_1 = F_3 () ;
F_4 ( V_1 & ~ V_4 ) ;
F_5 () ;
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
F_6 () ;
F_4 ( V_1 ) ;
if ( V_2 ) {
F_7 ( & V_5 , V_6 ) ;
F_8 ( L_1 ) ;
}
}
