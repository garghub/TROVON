void doorbell_global_ipi(int cpu)
{
u32 tag = get_hard_smp_processor_id(cpu);
kvmppc_set_host_ipi(cpu, 1);
ppc_msgsnd_sync();
ppc_msgsnd(PPC_DBELL_MSGTYPE, 0, tag);
}
void doorbell_core_ipi(int cpu)
{
u32 tag = cpu_thread_in_core(cpu);
kvmppc_set_host_ipi(cpu, 1);
ppc_msgsnd_sync();
ppc_msgsnd(PPC_DBELL_MSGTYPE, 0, tag);
}
int doorbell_try_core_ipi(int cpu)
{
int this_cpu = get_cpu();
int ret = 0;
if (cpumask_test_cpu(cpu, cpu_sibling_mask(this_cpu))) {
doorbell_core_ipi(cpu);
ret = 1;
}
put_cpu();
return ret;
}
void doorbell_exception(struct pt_regs *regs)
{
struct pt_regs *old_regs = set_irq_regs(regs);
irq_enter();
ppc_msgsync();
may_hard_irq_enable();
kvmppc_set_host_ipi(smp_processor_id(), 0);
__this_cpu_inc(irq_stat.doorbell_irqs);
smp_ipi_demux_relaxed();
irq_exit();
set_irq_regs(old_regs);
}
void doorbell_exception(struct pt_regs *regs)
{
printk(KERN_WARNING "Received doorbell on non-smp system\n");
}
