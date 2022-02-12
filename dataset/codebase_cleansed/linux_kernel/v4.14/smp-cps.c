static int __init setup_nothreads(char *s)
{
threads_disabled = true;
return 0;
}
static unsigned core_vpe_count(unsigned int cluster, unsigned core)
{
if (threads_disabled)
return 1;
return mips_cps_numvps(cluster, core);
}
static void __init cps_smp_setup(void)
{
unsigned int nclusters, ncores, nvpes, core_vpes;
unsigned long core_entry;
int cl, c, v;
nvpes = 0;
nclusters = mips_cps_numclusters();
pr_info("%s topology ", cpu_has_mips_r6 ? "VP" : "VPE");
for (cl = 0; cl < nclusters; cl++) {
if (cl > 0)
pr_cont(",");
pr_cont("{");
ncores = mips_cps_numcores(cl);
for (c = 0; c < ncores; c++) {
core_vpes = core_vpe_count(cl, c);
if (c > 0)
pr_cont(",");
pr_cont("%u", core_vpes);
if (!cl && !c)
smp_num_siblings = core_vpes;
for (v = 0; v < min_t(int, core_vpes, NR_CPUS - nvpes); v++) {
cpu_set_cluster(&cpu_data[nvpes + v], cl);
cpu_set_core(&cpu_data[nvpes + v], c);
cpu_set_vpe_id(&cpu_data[nvpes + v], v);
}
nvpes += core_vpes;
}
pr_cont("}");
}
pr_cont(" total %u\n", nvpes);
for (v = 0; v < min_t(unsigned, nvpes, NR_CPUS); v++) {
set_cpu_possible(v, cpu_cluster(&cpu_data[v]) == 0);
set_cpu_present(v, cpu_cluster(&cpu_data[v]) == 0);
__cpu_number_map[v] = v;
__cpu_logical_map[v] = v;
}
change_c0_config(CONF_CM_CMASK, 0x5);
bitmap_set(core_power, 0, 1);
mips_cps_core_init();
write_gcr_cl_coherence(0xff);
if (mips_cm_revision() >= CM_REV_CM3) {
core_entry = CKSEG1ADDR((unsigned long)mips_cps_core_entry);
write_gcr_bev_base(core_entry);
}
#ifdef CONFIG_MIPS_MT_FPAFF
if (cpu_has_fpu)
cpumask_set_cpu(0, &mt_fpu_cpumask);
#endif
}
static void __init cps_prepare_cpus(unsigned int max_cpus)
{
unsigned ncores, core_vpes, c, cca;
bool cca_unsuitable, cores_limited;
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
cores_limited = false;
if (cca_unsuitable || cpu_has_dc_aliases) {
for_each_present_cpu(c) {
if (cpus_are_siblings(smp_processor_id(), c))
continue;
set_cpu_present(c, false);
cores_limited = true;
}
}
if (cores_limited)
pr_warn("Using only one core due to %s%s%s\n",
cca_unsuitable ? "unsuitable CCA" : "",
(cca_unsuitable && cpu_has_dc_aliases) ? " & " : "",
cpu_has_dc_aliases ? "dcache aliasing" : "");
entry_code = (u32 *)&mips_cps_core_entry;
uasm_i_addiu(&entry_code, 16, 0, cca);
blast_dcache_range((unsigned long)&mips_cps_core_entry,
(unsigned long)entry_code);
bc_wback_inv((unsigned long)&mips_cps_core_entry,
(void *)entry_code - (void *)&mips_cps_core_entry);
__sync();
ncores = mips_cps_numcores(0);
mips_cps_core_bootcfg = kcalloc(ncores, sizeof(*mips_cps_core_bootcfg),
GFP_KERNEL);
if (!mips_cps_core_bootcfg) {
pr_err("Failed to allocate boot config for %u cores\n", ncores);
goto err_out;
}
for (c = 0; c < ncores; c++) {
core_vpes = core_vpe_count(0, c);
mips_cps_core_bootcfg[c].vpe_config = kcalloc(core_vpes,
sizeof(*mips_cps_core_bootcfg[c].vpe_config),
GFP_KERNEL);
if (!mips_cps_core_bootcfg[c].vpe_config) {
pr_err("Failed to allocate %u VPE boot configs\n",
core_vpes);
goto err_out;
}
}
atomic_set(&mips_cps_core_bootcfg[cpu_core(&current_cpu_data)].vpe_mask,
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
static void boot_core(unsigned int core, unsigned int vpe_id)
{
u32 stat, seq_state;
unsigned timeout;
mips_cm_lock_other(0, core, 0, CM_GCR_Cx_OTHER_BLOCK_LOCAL);
write_gcr_co_reset_base(CKSEG1ADDR((unsigned long)mips_cps_core_entry));
write_gcr_co_coherence(0);
write_gcr_co_reset_ext_base(CM_GCR_Cx_RESET_EXT_BASE_UEB);
set_gcr_access(1 << core);
if (mips_cpc_present()) {
mips_cpc_lock_other(core);
if (mips_cm_revision() >= CM_REV_CM3) {
write_cpc_co_vp_stop(0xf);
write_cpc_co_vp_run(1 << vpe_id);
wmb();
}
write_cpc_co_cmd(CPC_Cx_CMD_RESET);
timeout = 100;
while (true) {
stat = read_cpc_co_stat_conf();
seq_state = stat & CPC_Cx_STAT_CONF_SEQSTATE;
seq_state >>= __ffs(CPC_Cx_STAT_CONF_SEQSTATE);
if (seq_state == CPC_Cx_STAT_CONF_SEQSTATE_U6)
break;
if (timeout) {
timeout--;
mdelay(10);
continue;
}
pr_warn("Waiting for core %u to start... STAT_CONF=0x%x\n",
core, stat);
mdelay(1000);
}
mips_cpc_unlock_other();
} else {
write_gcr_co_reset_release(0);
}
mips_cm_unlock_other();
bitmap_set(core_power, core, 1);
}
static void remote_vpe_boot(void *dummy)
{
unsigned core = cpu_core(&current_cpu_data);
struct core_boot_config *core_cfg = &mips_cps_core_bootcfg[core];
mips_cps_boot_vpes(core_cfg, cpu_vpe_id(&current_cpu_data));
}
static int cps_boot_secondary(int cpu, struct task_struct *idle)
{
unsigned core = cpu_core(&cpu_data[cpu]);
unsigned vpe_id = cpu_vpe_id(&cpu_data[cpu]);
struct core_boot_config *core_cfg = &mips_cps_core_bootcfg[core];
struct vpe_boot_config *vpe_cfg = &core_cfg->vpe_config[vpe_id];
unsigned long core_entry;
unsigned int remote;
int err;
if (cpu_cluster(&cpu_data[cpu]) != cpu_cluster(&raw_current_cpu_data))
return -ENOSYS;
vpe_cfg->pc = (unsigned long)&smp_bootstrap;
vpe_cfg->sp = __KSTK_TOS(idle);
vpe_cfg->gp = (unsigned long)task_thread_info(idle);
atomic_or(1 << cpu_vpe_id(&cpu_data[cpu]), &core_cfg->vpe_mask);
preempt_disable();
if (!test_bit(core, core_power)) {
boot_core(core, vpe_id);
goto out;
}
if (cpu_has_vp) {
mips_cm_lock_other(0, core, vpe_id, CM_GCR_Cx_OTHER_BLOCK_LOCAL);
core_entry = CKSEG1ADDR((unsigned long)mips_cps_core_entry);
write_gcr_co_reset_base(core_entry);
mips_cm_unlock_other();
}
if (!cpus_are_siblings(cpu, smp_processor_id())) {
for (remote = 0; remote < NR_CPUS; remote++) {
if (!cpus_are_siblings(cpu, remote))
continue;
if (cpu_online(remote))
break;
}
if (remote >= NR_CPUS) {
pr_crit("No online CPU in core %u to start CPU%d\n",
core, cpu);
goto out;
}
err = smp_call_function_single(remote, remote_vpe_boot,
NULL, 1);
if (err)
panic("Failed to call remote CPU\n");
goto out;
}
BUG_ON(!cpu_has_mipsmt && !cpu_has_vp);
mips_cps_boot_vpes(core_cfg, vpe_id);
out:
preempt_enable();
return 0;
}
static void cps_init_secondary(void)
{
if (cpu_has_mipsmt)
dmt();
if (mips_cm_revision() >= CM_REV_CM3) {
unsigned int ident = read_gic_vl_ident();
BUG_ON(ident != mips_cm_vp_id(smp_processor_id()));
}
if (cpu_has_veic)
clear_c0_status(ST0_IM);
else
change_c0_status(ST0_IM, STATUSF_IP2 | STATUSF_IP3 |
STATUSF_IP4 | STATUSF_IP5 |
STATUSF_IP6 | STATUSF_IP7);
}
static void cps_smp_finish(void)
{
write_c0_compare(read_c0_count() + (8 * mips_hpt_frequency / HZ));
#ifdef CONFIG_MIPS_MT_FPAFF
if (cpu_has_fpu)
cpumask_set_cpu(smp_processor_id(), &mt_fpu_cpumask);
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
core_cfg = &mips_cps_core_bootcfg[cpu_core(&current_cpu_data)];
atomic_sub(1 << cpu_vpe_id(&current_cpu_data), &core_cfg->vpe_mask);
smp_mb__after_atomic();
set_cpu_online(cpu, false);
calculate_cpu_foreign_map();
return 0;
}
void play_dead(void)
{
unsigned int cpu, core, vpe_id;
local_irq_disable();
idle_task_exit();
cpu = smp_processor_id();
core = cpu_core(&cpu_data[cpu]);
cpu_death = CPU_DEATH_POWER;
pr_debug("CPU%d going offline\n", cpu);
if (cpu_has_mipsmt || cpu_has_vp) {
core = cpu_core(&cpu_data[cpu]);
for_each_online_cpu(cpu_death_sibling) {
if (!cpus_are_siblings(cpu, cpu_death_sibling))
continue;
cpu_death = CPU_DEATH_HALT;
break;
}
}
(void)cpu_report_death();
if (cpu_death == CPU_DEATH_HALT) {
vpe_id = cpu_vpe_id(&cpu_data[cpu]);
pr_debug("Halting core %d VP%d\n", core, vpe_id);
if (cpu_has_mipsmt) {
write_c0_tchalt(TCHALT_H);
instruction_hazard();
} else if (cpu_has_vp) {
write_cpc_cl_vp_stop(1 << vpe_id);
wmb();
}
} else {
pr_debug("Gating power to core %d\n", core);
cps_pm_enter_state(CPS_PM_POWER_GATED);
}
panic("Failed to offline CPU %u", cpu);
}
static void wait_for_sibling_halt(void *ptr_cpu)
{
unsigned cpu = (unsigned long)ptr_cpu;
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
unsigned core = cpu_core(&cpu_data[cpu]);
unsigned int vpe_id = cpu_vpe_id(&cpu_data[cpu]);
ktime_t fail_time;
unsigned stat;
int err;
if (!cpu_wait_death(cpu, 5)) {
pr_err("CPU%u: didn't offline\n", cpu);
return;
}
if (cpu_death == CPU_DEATH_POWER) {
fail_time = ktime_add_ms(ktime_get(), 2000);
do {
mips_cm_lock_other(0, core, 0, CM_GCR_Cx_OTHER_BLOCK_LOCAL);
mips_cpc_lock_other(core);
stat = read_cpc_co_stat_conf();
stat &= CPC_Cx_STAT_CONF_SEQSTATE;
stat >>= __ffs(CPC_Cx_STAT_CONF_SEQSTATE);
mips_cpc_unlock_other();
mips_cm_unlock_other();
if (stat == CPC_Cx_STAT_CONF_SEQSTATE_D0 ||
stat == CPC_Cx_STAT_CONF_SEQSTATE_D2 ||
stat == CPC_Cx_STAT_CONF_SEQSTATE_U2)
break;
if (WARN(ktime_after(ktime_get(), fail_time),
"CPU%u hasn't powered down, seq. state %u\n",
cpu, stat))
break;
} while (1);
bitmap_clear(core_power, core, 1);
} else if (cpu_has_mipsmt) {
err = smp_call_function_single(cpu_death_sibling,
wait_for_sibling_halt,
(void *)(unsigned long)cpu, 1);
if (err)
panic("Failed to call remote sibling CPU\n");
} else if (cpu_has_vp) {
do {
mips_cm_lock_other(0, core, vpe_id, CM_GCR_Cx_OTHER_BLOCK_LOCAL);
stat = read_cpc_co_vp_running();
mips_cm_unlock_other();
} while (stat & (1 << vpe_id));
}
}
bool mips_cps_smp_in_use(void)
{
extern const struct plat_smp_ops *mp_ops;
return mp_ops == &cps_smp_ops;
}
int register_cps_smp_ops(void)
{
if (!mips_cm_present()) {
pr_warn("MIPS CPS SMP unable to proceed without a CM\n");
return -ENODEV;
}
if (!(read_gcr_gic_status() & CM_GCR_GIC_STATUS_EX)) {
pr_warn("MIPS CPS SMP unable to proceed without a GIC\n");
return -ENODEV;
}
register_smp_ops(&cps_smp_ops);
return 0;
}
