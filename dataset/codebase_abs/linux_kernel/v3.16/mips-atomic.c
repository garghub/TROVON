T_1 void F_1 ( void )
{
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noat \n"
#if F_3 ( V_1 )
#else
" mfc0 $1,$12 \n"
" ori $1,0x1f \n"
" xori $1,0x1f \n"
" .set noreorder \n"
" mtc0 $1,$12 \n"
#endif
" " __stringify(__irq_disable_hazard) " \n"
" .set pop \n"
:
:
: "memory");
F_4 () ;
}
T_1 unsigned long F_5 ( void )
{
unsigned long V_2 ;
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set reorder \n"
" .set noat \n"
#if F_3 ( V_1 )
#else
" mfc0 %[flags], $12 \n"
" ori $1, %[flags], 0x1f \n"
" xori $1, 0x1f \n"
" .set noreorder \n"
" mtc0 $1, $12 \n"
#endif
" " __stringify(__irq_disable_hazard) " \n"
" .set pop \n"
: [flags] "=r" (flags)
:
: "memory");
F_4 () ;
return V_2 ;
}
T_1 void F_6 ( unsigned long V_2 )
{
unsigned long V_3 ;
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noreorder \n"
" .set noat \n"
#if F_3 ( V_1 ) && F_3 ( V_4 )
#elif F_3 ( V_1 )
#else
" mfc0 $1, $12 \n"
" andi %[flags], 1 \n"
" ori $1, 0x1f \n"
" xori $1, 0x1f \n"
" or %[flags], $1 \n"
" mtc0 %[flags], $12 \n"
#endif
" " __stringify(__irq_disable_hazard) " \n"
" .set pop \n"
: [flags] "=r" (__tmp1)
: "0" (flags)
: "memory");
F_4 () ;
}
T_1 void F_7 ( unsigned long V_2 )
{
unsigned long V_3 ;
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noreorder \n"
" .set noat \n"
#if F_3 ( V_1 ) && F_3 ( V_4 )
#elif F_3 ( V_1 )
#else
" mfc0 $1, $12 \n"
" andi %[flags], 1 \n"
" ori $1, 0x1f \n"
" xori $1, 0x1f \n"
" or %[flags], $1 \n"
" mtc0 %[flags], $12 \n"
#endif
" " __stringify(__irq_disable_hazard) " \n"
" .set pop \n"
: [flags] "=r" (__tmp1)
: "0" (flags)
: "memory");
F_4 () ;
}
