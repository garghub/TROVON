notrace void arch_local_irq_disable(void)
{
preempt_disable();
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
preempt_enable();
}
notrace unsigned long arch_local_irq_save(void)
{
unsigned long flags;
preempt_disable();
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
preempt_enable();
return flags;
}
notrace void arch_local_irq_restore(unsigned long flags)
{
unsigned long __tmp1;
preempt_disable();
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
preempt_enable();
}
notrace void __arch_local_irq_restore(unsigned long flags)
{
unsigned long __tmp1;
preempt_disable();
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
preempt_enable();
}
