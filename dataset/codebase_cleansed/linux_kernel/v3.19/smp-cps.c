static unsigned core_vpe_count(unsigned core)
{
unsigned cfg;
if (!config_enabled(CONFIG_MIPS_MT_SMP) || !cpu_has_mipsmt)
return 1;
write_gcr_cl_other(core << CM_GCR_Cx_OTHER_CORENUM_SHF);
cfg = read_gcr_co_config() & CM_GCR_Cx_CONFIG_PVPE_MSK;
return (cfg >> CM_GCR_Cx_CONFIG_PVPE_SHF) + 1;
}
static void __init cps_smp_setup(void)
{
unsigned int ncores, nvpes, core_vpes;
int c, v;
ncores = mips_cm_numcores();
pr_info("VPE topology ");
for (c = nvpes = 0; c < ncores; c++) {
core_vpes = core_vpe_count(c);
pr_cont("%c%u", c ? ',' : '{', core_vpes);
if (!c)
smp_num_siblings = core_vpes;
for (v = 0; v < min_t(int, core_vpes, NR_CPUS - nvpes); v++) {
cpu_data[nvpes + v].core = c;
#ifdef CONFIG_MIPS_MT_SMP
cpu_data[nvpes + v].vpe_id = v;
#endif
}
nvpes += core_vpes;
}
pr_cont("} total %u\n", nvpes);
for (v = 0; v < min_t(unsigned, nvpes, NR_CPUS); v++) {
set_cpu_possible(v, true);
set_cpu_present(v, true);
__cpu_number_map[v] = v;
__cpu_logical_map[v] = v;
}
change_c0_config(CONF_CM_CMASK, 0x5);
bitmap_set(core_power, 0, 1);
mips_cps_core_init();
write_gcr_cl_coherence(0xff);
}
static void __init cps_prepare_cpus(unsigned int max_cpus)
{
unsigned ncores, core_vpes, c, cca;
bool cca_unsuitable;
u32 *entry_code;
mips_mt_set_cpuoptions();
cca = read_c0_config() & CONF_CM_CMASK;
switch (cca) {
case 0x4:
case 0x5:
cca_unsuitable = false;
break;
default:
cca_unsuitable = true;
}
ncores = mips_cm_numcores();
if (cca_unsuitable && ncores > 1) {
pr_warn("Using only one core due to unsuitable CCA 0x%x\n",
cca);
for_each_present_cpu(c) {
if (cpu_data[c].core)
set_cpu_present(c, false);
}
}
entry_code = (u32 *)&mips_cps_core_entry;
UASM_i_LA(&entry_code, 3, (long)mips_cm_base);
uasm_i_addiu(&entry_code, 16, 0, cca);
blast_dcache_range((unsigned long)&mips_cps_core_entry,
(unsigned long)entry_code);
bc_wback_inv((unsigned long)&mips_cps_core_entry,
(void *)entry_code - (void *)&mips_cps_core_entry);
__sync();
mips_cps_core_bootcfg = kcalloc(ncores, sizeof(*mips_cps_core_bootcfg),
GFP_KERNEL);
if (!mips_cps_core_bootcfg) {
pr_err("Failed to allocate boot config for %u cores\n", ncores);
goto err_out;
}
for (c = 0; c < ncores; c++) {
core_vpes = core_vpe_count(c);
mips_cps_core_bootcfg[c].vpe_config = kcalloc(core_vpes,
sizeof(*mips_cps_core_bootcfg[c].vpe_config),
GFP_KERNEL);
if (!mips_cps_core_bootcfg[c].vpe_config) {
pr_err("Failed to allocate %u VPE boot configs\n",
core_vpes);
goto err_out;
}
}
atomic_set(&mips_cps_core_bootcfg[current_cpu_data.core].vpe_mask,
1 << cpu_vpe_id(&current_cpu_data));
return;
err_out:
if (mips_cps_core_bootcfg) {
for (c = 0; c < ncores; c++)
kfree(mips_cps_core_bootcfg[c].vpe_config);
kfree(mips_cps_core_bootcfg);
mips_cps_core_bootcfg = NULL;
}
for_each_possible_cpu(c) {
if (c == 0)
continue;
set_cpu_present(c, false);
}
}
static void boot_core(unsigned core)
{
u32 access;
write_gcr_cl_other(core << CM_GCR_Cx_OTHER_CORENUM_SHF);
write_gcr_co_reset_base(CKSEG1ADDR((unsigned long)mips_cps_core_entry));
write_gcr_co_coherence(0);
access = read_gcr_access();
access |= 1 << (CM_GCR_ACCESS_ACCESSEN_SHF + core);
write_gcr_access(access);
if (mips_cpc_present()) {
mips_cpc_lock_other(core);
write_cpc_co_cmd(CPC_Cx_CMD_RESET);
mips_cpc_unlock_other();
} else {
write_gcr_co_reset_release(0);
}
bitmap_set(core_power, core, 1);
}
static void remote_vpe_boot(void *dummy)
{
mips_cps_boot_vpes();
}
static void cps_boot_secondary(int cpu, struct task_struct *idle)
{
unsigned core = cpu_data[cpu].core;
unsigned vpe_id = cpu_vpe_id(&cpu_data[cpu]);
struct core_boot_config *core_cfg = &mips_cps_core_bootcfg[core];
struct vpe_boot_config *vpe_cfg = &core_cfg->vpe_config[vpe_id];
unsigned int remote;
int err;
vpe_cfg->pc = (unsigned long)&smp_bootstrap;
vpe_cfg->sp = __KSTK_TOS(idle);
vpe_cfg->gp = (unsigned long)task_thread_info(idle);
atomic_or(1 << cpu_vpe_id(&cpu_data[cpu]), &core_cfg->vpe_mask);
preempt_disable();
if (!test_bit(core, core_power)) {
boot_core(core);
goto out;
}
if (core != current_cpu_data.core) {
for (remote = 0; remote < NR_CPUS; remote++) {
if (cpu_data[remote].core != core)
continue;
if (cpu_online(remote))
break;
}
BUG_ON(remote >= NR_CPUS);
err = smp_call_function_single(remote, remote_vpe_boot,
NULL, 1);
if (err)
panic("Failed to call remote CPU\n");
goto out;
}
BUG_ON(!cpu_has_mipsmt);
mips_cps_boot_vpes();
out:
preempt_enable();
}
static void cps_init_secondary(void)
{
if (cpu_has_mipsmt)
dmt();
change_c0_status(ST0_IM, STATUSF_IP2 | STATUSF_IP3 | STATUSF_IP4 |
STATUSF_IP5 | STATUSF_IP6 | STATUSF_IP7);
}
static void cps_smp_finish(void)
{
write_c0_compare(read_c0_count() + (8 * mips_hpt_frequency / HZ));
#ifdef CONFIG_MIPS_MT_FPAFF
if (cpu_has_fpu)
cpu_set(smp_processor_id(), mt_fpu_cpumask);
#endif
local_irq_enable();
}
static int cps_cpu_disable(void)
{
unsigned cpu = smp_processor_id();
struct core_boot_config *core_cfg;
if (!cpu)
return -EBUSY;
if (!cps_pm_support_state(CPS_PM_POWER_GATED))
return -EINVAL;
core_cfg = &mips_cps_core_bootcfg[current_cpu_data.core];
atomic_sub(1 << cpu_vpe_id(&current_cpu_data), &core_cfg->vpe_mask);
smp_mb__after_atomic();
set_cpu_online(cpu, false);
cpu_clear(cpu, cpu_callin_map);
return 0;
}
void play_dead(void)
{
unsigned cpu, core;
local_irq_disable();
idle_task_exit();
cpu = smp_processor_id();
cpu_death = CPU_DEATH_POWER;
if (cpu_has_mipsmt) {
core = cpu_data[cpu].core;
for_each_online_cpu(cpu_death_sibling) {
if (cpu_data[cpu_death_sibling].core != core)
continue;
cpu_death = CPU_DEATH_HALT;
break;
}
}
complete(&cpu_death_chosen);
if (cpu_death == CPU_DEATH_HALT) {
write_c0_tchalt(TCHALT_H);
instruction_hazard();
} else {
cps_pm_enter_state(CPS_PM_POWER_GATED);
}
panic("Failed to offline CPU %u", cpu);
}
static void wait_for_sibling_halt(void *ptr_cpu)
{
unsigned cpu = (unsigned)ptr_cpu;
unsigned vpe_id = cpu_vpe_id(&cpu_data[cpu]);
unsigned halted;
unsigned long flags;
do {
local_irq_save(flags);
settc(vpe_id);
halted = read_tc_c0_tchalt();
local_irq_restore(flags);
} while (!(halted & TCHALT_H));
}
static void cps_cpu_die(unsigned int cpu)
{
unsigned core = cpu_data[cpu].core;
unsigned stat;
int err;
if (!wait_for_completion_timeout(&cpu_death_chosen,
msecs_to_jiffies(5000))) {
pr_err("CPU%u: didn't offline\n", cpu);
return;
}
if (cpu_death == CPU_DEATH_POWER) {
do {
mips_cpc_lock_other(core);
stat = read_cpc_co_stat_conf();
stat &= CPC_Cx_STAT_CONF_SEQSTATE_MSK;
mips_cpc_unlock_other();
} while (stat != CPC_Cx_STAT_CONF_SEQSTATE_D0 &&
stat != CPC_Cx_STAT_CONF_SEQSTATE_D2 &&
stat != CPC_Cx_STAT_CONF_SEQSTATE_U2);
bitmap_clear(core_power, core, 1);
} else if (cpu_has_mipsmt) {
err = smp_call_function_single(cpu_death_sibling,
wait_for_sibling_halt,
(void *)cpu, 1);
if (err)
panic("Failed to call remote sibling CPU\n");
}
}
bool mips_cps_smp_in_use(void)
{
extern struct plat_smp_ops *mp_ops;
return mp_ops == &cps_smp_ops;
}
int register_cps_smp_ops(void)
{
if (!mips_cm_present()) {
pr_warn("MIPS CPS SMP unable to proceed without a CM\n");
return -ENODEV;
}
if (!(read_gcr_gic_status() & CM_GCR_GIC_STATUS_EX_MSK)) {
pr_warn("MIPS CPS SMP unable to proceed without a GIC\n");
return -ENODEV;
}
register_smp_ops(&cps_smp_ops);
return 0;
}
