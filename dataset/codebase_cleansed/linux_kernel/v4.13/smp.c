static void pnv_smp_setup_cpu(int cpu)
{
if (xive_enabled())
xive_smp_setup_cpu();
else if (cpu != boot_cpuid)
xics_setup_cpu();
}
static int pnv_smp_kick_cpu(int nr)
{
unsigned int pcpu = get_hard_smp_processor_id(nr);
unsigned long start_here =
__pa(ppc_function_entry(generic_secondary_smp_init));
long rc;
uint8_t status;
if (nr < 0 || nr >= nr_cpu_ids)
return -EINVAL;
if (paca[nr].cpu_start || !firmware_has_feature(FW_FEATURE_OPAL))
goto kick;
rc = opal_query_cpu_status(pcpu, &status);
if (rc != OPAL_SUCCESS) {
pr_warn("OPAL Error %ld querying CPU %d state\n", rc, nr);
return -ENODEV;
}
if (status == OPAL_THREAD_STARTED)
goto kick;
if (status == OPAL_THREAD_INACTIVE) {
pr_devel("OPAL: Starting CPU %d (HW 0x%x)...\n", nr, pcpu);
rc = opal_start_cpu(pcpu, start_here);
if (rc != OPAL_SUCCESS) {
pr_warn("OPAL Error %ld starting CPU %d\n", rc, nr);
return -ENODEV;
}
} else {
pr_devel("OPAL: CPU %d (HW 0x%x) is unavailable"
" (status %d)...\n", nr, pcpu, status);
return -ENODEV;
}
kick:
return smp_generic_kick_cpu(nr);
}
static int pnv_smp_cpu_disable(void)
{
int cpu = smp_processor_id();
set_cpu_online(cpu, false);
vdso_data->processorCount--;
if (cpu == boot_cpuid)
boot_cpuid = cpumask_any(cpu_online_mask);
if (xive_enabled())
xive_smp_disable_cpu();
else
xics_migrate_irqs_away();
return 0;
}
static void pnv_smp_cpu_kill_self(void)
{
unsigned int cpu;
unsigned long srr1, wmask;
WARN_ON(irqs_disabled());
hard_irq_disable();
WARN_ON(lazy_irq_pending());
idle_task_exit();
current->active_mm = NULL;
cpu = smp_processor_id();
DBG("CPU%d offline\n", cpu);
generic_set_cpu_dead(cpu);
smp_wmb();
wmask = SRR1_WAKEMASK;
if (cpu_has_feature(CPU_FTR_ARCH_207S))
wmask = SRR1_WAKEMASK_P8;
mtspr(SPRN_LPCR, mfspr(SPRN_LPCR) & ~(u64)LPCR_PECE1);
while (!generic_check_cpu_restart(cpu)) {
kvmppc_set_host_ipi(cpu, 0);
srr1 = pnv_cpu_offline(cpu);
WARN_ON(lazy_irq_pending());
if (((srr1 & wmask) == SRR1_WAKEEE) ||
((srr1 & wmask) == SRR1_WAKEHVI)) {
if (cpu_has_feature(CPU_FTR_ARCH_300)) {
if (xive_enabled())
xive_flush_interrupt();
else
icp_opal_flush_interrupt();
} else
icp_native_flush_interrupt();
} else if ((srr1 & wmask) == SRR1_WAKEHDBELL) {
unsigned long msg = PPC_DBELL_TYPE(PPC_DBELL_SERVER);
asm volatile(PPC_MSGCLR(%0) : : "r" (msg));
}
smp_mb();
if (cpu_core_split_required())
continue;
if (srr1 && !generic_check_cpu_restart(cpu))
DBG("CPU%d Unexpected exit while offline srr1=%lx!\n",
cpu, srr1);
}
mtspr(SPRN_LPCR, mfspr(SPRN_LPCR) | LPCR_PECE1);
DBG("CPU%d coming online...\n", cpu);
}
static int pnv_cpu_bootable(unsigned int nr)
{
if (cpu_has_feature(CPU_FTR_ARCH_207S))
return 1;
return smp_generic_cpu_bootable(nr);
}
static int pnv_smp_prepare_cpu(int cpu)
{
if (xive_enabled())
return xive_smp_prepare_cpu(cpu);
return 0;
}
static void pnv_cause_ipi(int cpu)
{
if (doorbell_try_core_ipi(cpu))
return;
ic_cause_ipi(cpu);
}
static void pnv_p9_dd1_cause_ipi(int cpu)
{
int this_cpu = get_cpu();
if (cpumask_test_cpu(cpu, cpu_sibling_mask(this_cpu)))
doorbell_global_ipi(cpu);
else
ic_cause_ipi(cpu);
put_cpu();
}
static void __init pnv_smp_probe(void)
{
if (xive_enabled())
xive_smp_probe();
else
xics_smp_probe();
if (cpu_has_feature(CPU_FTR_DBELL)) {
ic_cause_ipi = smp_ops->cause_ipi;
WARN_ON(!ic_cause_ipi);
if (cpu_has_feature(CPU_FTR_ARCH_300)) {
if (cpu_has_feature(CPU_FTR_POWER9_DD1))
smp_ops->cause_ipi = pnv_p9_dd1_cause_ipi;
else
smp_ops->cause_ipi = doorbell_global_ipi;
} else {
smp_ops->cause_ipi = pnv_cause_ipi;
}
}
}
void __init pnv_smp_init(void)
{
smp_ops = &pnv_smp_ops;
#ifdef CONFIG_HOTPLUG_CPU
ppc_md.cpu_die = pnv_smp_cpu_kill_self;
#endif
}
