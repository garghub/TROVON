static void cmp_init_secondary(void)
{
struct cpuinfo_mips *c __maybe_unused = &current_cpu_data;
change_c0_status(ST0_IM, STATUSF_IP3 | STATUSF_IP4 | STATUSF_IP6 |
STATUSF_IP7);
#if defined(CONFIG_MIPS_MT_SMP) || defined(CONFIG_MIPS_MT_SMTC)
if (cpu_has_mipsmt)
c->vpe_id = (read_c0_tcbind() >> TCBIND_CURVPE_SHIFT) &
TCBIND_CURVPE;
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
unsigned int nvpe = 1;
#ifdef CONFIG_MIPS_MT_SMP
unsigned int mvpconf0 = read_c0_mvpconf0();
nvpe = ((mvpconf0 & MVPCONF0_PVPE) >> MVPCONF0_PVPE_SHIFT) + 1;
#elif defined(CONFIG_MIPS_MT_SMTC)
unsigned int mvpconf0 = read_c0_mvpconf0();
nvpe = ((mvpconf0 & MVPCONF0_PTC) >> MVPCONF0_PTC_SHIFT) + 1;
#endif
smp_num_siblings = nvpe;
}
pr_info("Detected %i available secondary CPU(s)\n", ncpu);
}
void __init cmp_prepare_cpus(unsigned int max_cpus)
{
pr_debug("SMPCMP: CPU%d: %s max_cpus=%d\n",
smp_processor_id(), __func__, max_cpus);
#ifdef CONFIG_MIPS_MT
mips_mt_set_cpuoptions();
#endif
}
