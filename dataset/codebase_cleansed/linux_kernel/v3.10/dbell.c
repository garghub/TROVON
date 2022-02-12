void doorbell_setup_this_cpu(void)
{
unsigned long tag = mfspr(SPRN_DOORBELL_CPUTAG) & PPC_DBELL_TAG_MASK;
smp_muxed_ipi_set_data(smp_processor_id(), tag);
}
void doorbell_cause_ipi(int cpu, unsigned long data)
{
mb();
ppc_msgsnd(PPC_DBELL_MSGTYPE, 0, data);
}
void doorbell_exception(struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
irq_enter();
may_hard_irq_enable();
__get_cpu_var(irq_stat).doorbell_irqs++;
smp_ipi_demux();
irq_exit();
set_irq_regs(old_regs);
}
void doorbell_exception(struct pt_regs *regs)
{
printk(KERN_WARNING "Received doorbell on non-smp system\n");
}
