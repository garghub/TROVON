T_1 void F_1 ( void )
{
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noat \n"
" mfc0 $1,$12 \n"
" ori $1,0x1f \n"
" xori $1,0x1f \n"
" .set noreorder \n"
" mtc0 $1,$12 \n"
" " __stringify(__irq_disable_hazard) " \n"
" .set pop \n"
:
:
: "memory");
F_3 () ;
}
T_1 unsigned long F_4 ( void )
{
unsigned long V_1 ;
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set reorder \n"
" .set noat \n"
" mfc0 %[flags], $12 \n"
" ori $1, %[flags], 0x1f \n"
" xori $1, 0x1f \n"
" .set noreorder \n"
" mtc0 $1, $12 \n"
" " __stringify(__irq_disable_hazard) " \n"
" .set pop \n"
: [flags] "=r" (flags)
:
: "memory");
F_3 () ;
return V_1 ;
}
T_1 void F_5 ( unsigned long V_1 )
{
unsigned long V_2 ;
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noreorder \n"
" .set noat \n"
" mfc0 $1, $12 \n"
" andi %[flags], 1 \n"
" ori $1, 0x1f \n"
" xori $1, 0x1f \n"
" or %[flags], $1 \n"
" mtc0 %[flags], $12 \n"
" " __stringify(__irq_disable_hazard) " \n"
" .set pop \n"
: [flags] "=r" (__tmp1)
: "0" (flags)
: "memory");
F_3 () ;
}
T_1 void F_6 ( unsigned long V_1 )
{
unsigned long V_2 ;
F_2 () ;
__asm__ __volatile__(
" .set push \n"
" .set noreorder \n"
" .set noat \n"
" mfc0 $1, $12 \n"
" andi %[flags], 1 \n"
" ori $1, 0x1f \n"
" xori $1, 0x1f \n"
" or %[flags], $1 \n"
" mtc0 %[flags], $12 \n"
" " __stringify(__irq_disable_hazard) " \n"
" .set pop \n"
: [flags] "=r" (__tmp1)
: "0" (flags)
: "memory");
F_3 () ;
}
