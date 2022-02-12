static int __init set_numcpus(char *str)
{
int newval;
if (get_option(&str, &newval)) {
if (newval < 1 || newval >= NR_CPUS)
goto bad;
numcpus = newval;
return 0;
}
bad:
return -EINVAL;
}
static void paravirt_smp_setup(void)
{
int id;
unsigned int cpunum = get_ebase_cpunum();
if (WARN_ON(cpunum >= NR_CPUS))
return;
for (id = 0; id < NR_CPUS; id++) {
set_cpu_possible(id, id == 0);
set_cpu_present(id, id == 0);
}
__cpu_number_map[cpunum] = 0;
__cpu_logical_map[0] = cpunum;
for (id = 0; id < numcpus; id++) {
set_cpu_possible(id, true);
set_cpu_present(id, true);
__cpu_number_map[id] = id;
__cpu_logical_map[id] = id;
}
}
static void paravirt_send_ipi_single(int cpu, unsigned int action)
{
irq_mbox_ipi(cpu, action);
}
static void paravirt_send_ipi_mask(const struct cpumask *mask, unsigned int action)
{
unsigned int cpu;
for_each_cpu(cpu, mask)
paravirt_send_ipi_single(cpu, action);
}
static void paravirt_init_secondary(void)
{
unsigned int sr;
sr = set_c0_status(ST0_BEV);
write_c0_ebase((u32)ebase);
sr |= STATUSF_IP2;
write_c0_status(sr);
irq_cpu_online();
}
static void paravirt_smp_finish(void)
{
write_c0_compare(read_c0_count() + mips_hpt_frequency / HZ);
local_irq_enable();
}
static int paravirt_boot_secondary(int cpu, struct task_struct *idle)
{
paravirt_smp_gp[cpu] = (unsigned long)task_thread_info(idle);
smp_wmb();
paravirt_smp_sp[cpu] = __KSTK_TOS(idle);
return 0;
}
static irqreturn_t paravirt_reched_interrupt(int irq, void *dev_id)
{
scheduler_ipi();
return IRQ_HANDLED;
}
static irqreturn_t paravirt_function_interrupt(int irq, void *dev_id)
{
generic_smp_call_function_interrupt();
return IRQ_HANDLED;
}
static void paravirt_prepare_cpus(unsigned int max_cpus)
{
if (request_irq(MIPS_IRQ_MBOX0, paravirt_reched_interrupt,
IRQF_PERCPU | IRQF_NO_THREAD, "Scheduler",
paravirt_reched_interrupt)) {
panic("Cannot request_irq for SchedulerIPI");
}
if (request_irq(MIPS_IRQ_MBOX1, paravirt_function_interrupt,
IRQF_PERCPU | IRQF_NO_THREAD, "SMP-Call",
paravirt_function_interrupt)) {
panic("Cannot request_irq for SMP-Call");
}
}
