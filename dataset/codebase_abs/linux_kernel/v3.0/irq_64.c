void T_1 F_1 ( unsigned long V_1 )
{
unsigned long long V_2 ;
if ( V_1 == V_3 ) {
__asm__ __volatile__ (
"getcon " __SR ", %0\n\t"
"or %0, %1, %0\n\t"
"putcon %0, " __SR "\n\t"
: "=&r" (__dummy)
: "r" (ARCH_IRQ_DISABLED)
);
} else {
__asm__ __volatile__ (
"getcon " __SR ", %0\n\t"
"and %0, %1, %0\n\t"
"putcon %0, " __SR "\n\t"
: "=&r" (__dummy)
: "r" (~ARCH_IRQ_DISABLED)
);
}
}
unsigned long T_1 F_2 ( void )
{
unsigned long V_1 ;
__asm__ __volatile__ (
"getcon " __SR ", %0\n\t"
"and %0, %1, %0"
: "=&r" (flags)
: "r" (ARCH_IRQ_DISABLED)
);
return V_1 ;
}
