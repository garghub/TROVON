void T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 , V_3 ;
if ( V_1 == V_4 ) {
__asm__ __volatile__ (
"stc sr, %0\n\t"
"or #0xf0, %0\n\t"
"ldc %0, sr\n\t"
: "=&z" (__dummy0)
:
: "memory"
);
} else {
__asm__ __volatile__ (
"stc sr, %0\n\t"
"and %1, %0\n\t"
#ifdef F_2
"stc r6_bank, %1\n\t"
"or %1, %0\n\t"
#endif
"ldc %0, sr\n\t"
: "=&r" (__dummy0), "=r" (__dummy1)
: "1" (~ARCH_IRQ_DISABLED)
: "memory"
);
}
}
unsigned long T_1 F_3 ( void )
{
unsigned long V_1 ;
__asm__ __volatile__ (
"stc sr, %0\n\t"
"and #0xf0, %0\n\t"
: "=&z" (flags)
:
: "memory"
);
return V_1 ;
}
