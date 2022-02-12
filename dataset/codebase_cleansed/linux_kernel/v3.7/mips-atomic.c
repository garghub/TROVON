notrace void arch_local_irq_disable(void)
{
preempt_disable();
__asm__ __volatile__(
"arch_local_irq_disable"
:
:
: "memory");
preempt_enable();
}
notrace unsigned long arch_local_irq_save(void)
{
unsigned long flags;
preempt_disable();
asm volatile("arch_local_irq_save\t%0"
: "=r" (flags)
:
: "memory");
preempt_enable();
return flags;
}
notrace void arch_local_irq_restore(unsigned long flags)
{
unsigned long __tmp1;
#ifdef CONFIG_MIPS_MT_SMTC
if (unlikely(!(flags & 0x0400)))
smtc_ipi_replay();
#endif
preempt_disable();
__asm__ __volatile__(
"arch_local_irq_restore\t%0"
: "=r" (__tmp1)
: "0" (flags)
: "memory");
preempt_enable();
}
notrace void __arch_local_irq_restore(unsigned long flags)
{
unsigned long __tmp1;
preempt_disable();
__asm__ __volatile__(
"arch_local_irq_restore\t%0"
: "=r" (__tmp1)
: "0" (flags)
: "memory");
preempt_enable();
}
