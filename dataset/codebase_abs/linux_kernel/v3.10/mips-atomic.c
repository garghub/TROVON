T_1 void F_1 ( void )
{
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noat \n"
#ifdef F_3
" mfc0 $1, $2, 1 \n"
" ori $1, 0x400 \n"
" .set noreorder \n"
" mtc0 $1, $2, 1 \n"
#elif F_4 ( V_1 )
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
F_5 () ;
}
T_1 unsigned long F_6 ( void )
{
unsigned long V_2 ;
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set reorder \n"
" .set noat \n"
#ifdef F_3
" mfc0 %[flags], $2, 1 \n"
" ori $1, %[flags], 0x400 \n"
" .set noreorder \n"
" mtc0 $1, $2, 1 \n"
" andi %[flags], %[flags], 0x400 \n"
#elif F_4 ( V_1 )
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
F_5 () ;
return V_2 ;
}
T_1 void F_7 ( unsigned long V_2 )
{
unsigned long V_3 ;
#ifdef F_3
if ( F_8 ( ! ( V_2 & 0x0400 ) ) )
F_9 () ;
#endif
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noreorder \n"
" .set noat \n"
#ifdef F_3
" mfc0 $1, $2, 1 \n"
" andi %[flags], 0x400 \n"
" ori $1, 0x400 \n"
" xori $1, 0x400 \n"
" or %[flags], $1 \n"
" mtc0 %[flags], $2, 1 \n"
#elif F_4 ( V_1 ) && F_4 ( V_4 )
#elif F_4 ( V_1 )
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
F_5 () ;
}
T_1 void F_10 ( unsigned long V_2 )
{
unsigned long V_3 ;
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noreorder \n"
" .set noat \n"
#ifdef F_3
" mfc0 $1, $2, 1 \n"
" andi %[flags], 0x400 \n"
" ori $1, 0x400 \n"
" xori $1, 0x400 \n"
" or %[flags], $1 \n"
" mtc0 %[flags], $2, 1 \n"
#elif F_4 ( V_1 ) && F_4 ( V_4 )
#elif F_4 ( V_1 )
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
F_5 () ;
}
