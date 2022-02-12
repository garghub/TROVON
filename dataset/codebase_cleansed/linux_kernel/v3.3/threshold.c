static void default_threshold_interrupt(void)
{
printk(KERN_ERR "Unexpected threshold interrupt at vector %x\n",
THRESHOLD_APIC_VECTOR);
}
asmlinkage void smp_threshold_interrupt(void)
{
irq_enter();
exit_idle();
inc_irq_stat(irq_threshold_count);
mce_threshold_vector();
irq_exit();
ack_APIC_irq();
}
