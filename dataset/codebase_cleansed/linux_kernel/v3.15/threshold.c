static void default_threshold_interrupt(void)
{
printk(KERN_ERR "Unexpected threshold interrupt at vector %x\n",
THRESHOLD_APIC_VECTOR);
}
static inline void __smp_threshold_interrupt(void)
{
inc_irq_stat(irq_threshold_count);
mce_threshold_vector();
}
asmlinkage __visible void smp_threshold_interrupt(void)
{
entering_irq();
__smp_threshold_interrupt();
exiting_ack_irq();
}
asmlinkage __visible void smp_trace_threshold_interrupt(void)
{
entering_irq();
trace_threshold_apic_entry(THRESHOLD_APIC_VECTOR);
__smp_threshold_interrupt();
trace_threshold_apic_exit(THRESHOLD_APIC_VECTOR);
exiting_ack_irq();
}
