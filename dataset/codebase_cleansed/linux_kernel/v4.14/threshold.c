static void default_threshold_interrupt(void)
{
pr_err("Unexpected threshold interrupt at vector %x\n",
THRESHOLD_APIC_VECTOR);
}
asmlinkage __visible void __irq_entry smp_threshold_interrupt(void)
{
entering_irq();
trace_threshold_apic_entry(THRESHOLD_APIC_VECTOR);
inc_irq_stat(irq_threshold_count);
mce_threshold_vector();
trace_threshold_apic_exit(THRESHOLD_APIC_VECTOR);
exiting_ack_irq();
}
