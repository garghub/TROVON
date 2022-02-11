void T_1 F_1 ( void )
{
T_2 V_1 ;
if ( ! F_2 ( V_2 ) )
return;
F_3 () ;
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
F_4 () ;
if ( V_1 ) {
F_5 ( & V_3 , V_4 ) ;
F_6 ( L_1 ) ;
}
}
