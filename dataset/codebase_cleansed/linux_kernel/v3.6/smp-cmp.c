static void ipi_call_function(unsigned int cpu)
{
pr_debug("CPU%d: %s cpu %d status %08x\n",
smp_processor_id(), __func__, cpu, read_c0_status());
gic_send_ipi(plat_ipi_call_int_xlate(cpu));
}
static void ipi_resched(unsigned int cpu)
{
pr_debug("CPU%d: %s cpu %d status %08x\n",
smp_processor_id(), __func__, cpu, read_c0_status());
gic_send_ipi(plat_ipi_resched_int_xlate(cpu));
}
void cmp_send_ipi_single(int cpu, unsigned int action)
{
unsigned long flags;
local_irq_save(flags);
switch (action) {
case SMP_CALL_FUNCTION:
ipi_call_function(cpu);
break;
case SMP_RESCHEDULE_YOURSELF:
ipi_resched(cpu);
break;
}
local_irq_restore(flags);
}
static void cmp_send_ipi_mask(const struct cpumask *mask, unsigned int action)
{
unsigned int i;
for_each_cpu(i, mask)
cmp_send_ipi_single(i, action);
}
static void cmp_init_secondary(void)
{
struct cpuinfo_mips *c = &current_cpu_data;
change_c0_status(ST0_IM, STATUSF_IP3 | STATUSF_IP4 | STATUSF_IP6 |
STATUSF_IP7);
c->core = (read_c0_ebase() >> 1) & 0xff;
#if defined(CONFIG_MIPS_MT_SMP) || defined(CONFIG_MIPS_MT_SMTC)
c->vpe_id = (read_c0_tcbind() >> TCBIND_CURVPE_SHIFT) & TCBIND_CURVPE;
#endif
#ifdef CONFIG_MIPS_MT_SMTC
c->tc_id = (read_c0_tcbind() & TCBIND_CURTC) >> TCBIND_CURTC_SHIFT;
#endif
}
static void cmp_smp_finish(void)
{
pr_debug("SMPCMP: CPU%d: %s\n", smp_processor_id(), __func__);
write_c0_compare(read_c0_count() + (8 * mips_hpt_frequency / HZ));
#ifdef CONFIG_MIPS_MT_FPAFF
if (cpu_has_fpu)
cpu_set(smp_processor_id(), mt_fpu_cpumask);
#endif
local_irq_enable();
}
static void cmp_cpus_done(void)
{
pr_debug("SMPCMP: CPU%d: %s\n", smp_processor_id(), __func__);
}
static void cmp_boot_secondary(int cpu, struct task_struct *idle)
{
struct thread_info *gp = task_thread_info(idle);
unsigned long sp = __KSTK_TOS(idle);
unsigned long pc = (unsigned long)&smp_bootstrap;
unsigned long a0 = 0;
pr_debug("SMPCMP: CPU%d: %s cpu %d\n", smp_processor_id(),
__func__, cpu);
#if 0
flush_icache_range((unsigned long)gp,
(unsigned long)(gp + sizeof(struct thread_info)));
#endif
amon_cpu_start(cpu, pc, sp, (unsigned long)gp, a0);
}
void __init cmp_smp_setup(void)
{
int i;
int ncpu = 0;
pr_debug("SMPCMP: CPU%d: %s\n", smp_processor_id(), __func__);
#ifdef CONFIG_MIPS_MT_FPAFF
if (cpu_has_fpu)
cpu_set(0, mt_fpu_cpumask);
#endif
for (i = 1; i < NR_CPUS; i++) {
if (amon_cpu_avail(i)) {
set_cpu_possible(i, true);
__cpu_number_map[i] = ++ncpu;
__cpu_logical_map[ncpu] = i;
}
}
if (cpu_has_mipsmt) {
unsigned int nvpe, mvpconf0 = read_c0_mvpconf0();
nvpe = ((mvpconf0 & MVPCONF0_PTC) >> MVPCONF0_PTC_SHIFT) + 1;
smp_num_siblings = nvpe;
}
pr_info("Detected %i available secondary CPU(s)\n", ncpu);
}
void __init cmp_prepare_cpus(unsigned int max_cpus)
{
pr_debug("SMPCMP: CPU%d: %s max_cpus=%d\n",
smp_processor_id(), __func__, max_cpus);
mips_mt_set_cpuoptions();
}
