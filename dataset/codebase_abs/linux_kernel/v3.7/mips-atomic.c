T_1 void F_1 ( void )
{
F_2 () ;
__asm__ __volatile__(
"arch_local_irq_disable"
:
:
: "memory");
F_3 () ;
}
T_1 unsigned long F_4 ( void )
{
unsigned long V_1 ;
F_2 () ;
asm volatile("arch_local_irq_save\t%0"
: "=r" (flags)
:
: "memory");
F_3 () ;
return V_1 ;
}
T_1 void F_5 ( unsigned long V_1 )
{
unsigned long V_2 ;
#ifdef F_6
if ( F_7 ( ! ( V_1 & 0x0400 ) ) )
F_8 () ;
#endif
F_2 () ;
__asm__ __volatile__(
"arch_local_irq_restore\t%0"
: "=r" (__tmp1)
: "0" (flags)
: "memory");
F_3 () ;
}
T_1 void F_9 ( unsigned long V_1 )
{
unsigned long V_2 ;
F_2 () ;
__asm__ __volatile__(
"arch_local_irq_restore\t%0"
: "=r" (__tmp1)
: "0" (flags)
: "memory");
F_3 () ;
}
