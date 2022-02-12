void doorbell_setup_this_cpu(void)
{
unsigned long tag = mfspr(SPRN_PIR) & 0x3fff;
smp_muxed_ipi_set_data(smp_processor_id(), tag);
}
void doorbell_cause_ipi(int cpu, unsigned long data)
{
ppc_msgsnd(PPC_DBELL, 0, data);
}
void doorbell_exception(struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
irq_enter();
may_hard_irq_enable();
smp_ipi_demux();
irq_exit();
set_irq_regs(old_regs);
}
void doorbell_exception(struct pt_regs *regs)
{
printk(KERN_WARNING "Received doorbell on non-smp system\n");
}
