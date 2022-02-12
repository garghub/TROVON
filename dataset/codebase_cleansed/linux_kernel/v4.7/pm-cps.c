bool cps_pm_support_state(enum cps_pm_state state)
{
return test_bit(state, state_support);
}
static void coupled_barrier(atomic_t *a, unsigned online)
{
if (!coupled_coherence)
return;
smp_mb__before_atomic();
atomic_inc(a);
while (atomic_read(a) < online)
cpu_relax();
if (atomic_inc_return(a) == online * 2) {
atomic_set(a, 0);
return;
}
while (atomic_read(a) > online)
cpu_relax();
}
int cps_pm_enter_state(enum cps_pm_state state)
{
unsigned cpu = smp_processor_id();
unsigned core = current_cpu_data.core;
unsigned online, left;
cpumask_t *coupled_mask = this_cpu_ptr(&online_coupled);
u32 *core_ready_count, *nc_core_ready_count;
void *nc_addr;
cps_nc_entry_fn entry;
struct core_boot_config *core_cfg;
struct vpe_boot_config *vpe_cfg;
entry = per_cpu(nc_asm_enter, core)[state];
if (!entry)
return -EINVAL;
#ifdef CONFIG_MIPS_MT
if (cpu_online(cpu)) {
cpumask_and(coupled_mask, cpu_online_mask,
&cpu_sibling_map[cpu]);
online = cpumask_weight(coupled_mask);
cpumask_clear_cpu(cpu, coupled_mask);
} else
#endif
{
cpumask_clear(coupled_mask);
online = 1;
}
if (config_enabled(CONFIG_CPU_PM) && state == CPS_PM_POWER_GATED) {
if (!mips_cps_smp_in_use())
return -EINVAL;
core_cfg = &mips_cps_core_bootcfg[core];
vpe_cfg = &core_cfg->vpe_config[cpu_vpe_id(&current_cpu_data)];
vpe_cfg->pc = (unsigned long)mips_cps_pm_restore;
vpe_cfg->gp = (unsigned long)current_thread_info();
vpe_cfg->sp = 0;
}
cpumask_clear_cpu(cpu, &cpu_coherent_mask);
smp_mb__after_atomic();
core_ready_count = per_cpu(ready_count, core);
nc_addr = kmap_noncoherent(virt_to_page(core_ready_count),
(unsigned long)core_ready_count);
nc_addr += ((unsigned long)core_ready_count & ~PAGE_MASK);
nc_core_ready_count = nc_addr;
ACCESS_ONCE(*nc_core_ready_count) = 0;
coupled_barrier(&per_cpu(pm_barrier, core), online);
left = entry(online, nc_core_ready_count);
kunmap_noncoherent();
cpumask_set_cpu(cpu, &cpu_coherent_mask);
if (coupled_coherence && (state == CPS_PM_NC_WAIT) && (left == online))
arch_send_call_function_ipi_mask(coupled_mask);
return 0;
}
static void __init cps_gen_cache_routine(u32 **pp, struct uasm_label **pl,
struct uasm_reloc **pr,
const struct cache_desc *cache,
unsigned op, int lbl)
{
unsigned cache_size = cache->ways << cache->waybit;
unsigned i;
const unsigned unroll_lines = 32;
if (cache->flags & MIPS_CACHE_NOT_PRESENT)
return;
UASM_i_LA(pp, t0, (long)CKSEG0);
if (cache_size < 0x8000)
uasm_i_addiu(pp, t1, t0, cache_size);
else
UASM_i_LA(pp, t1, (long)(CKSEG0 + cache_size));
uasm_build_label(pl, *pp, lbl);
for (i = 0; i < unroll_lines; i++) {
if (cpu_has_mips_r6) {
uasm_i_cache(pp, op, 0, t0);
uasm_i_addiu(pp, t0, t0, cache->linesz);
} else {
uasm_i_cache(pp, op, i * cache->linesz, t0);
}
}
if (!cpu_has_mips_r6)
uasm_i_addiu(pp, t0, t0, unroll_lines * cache->linesz);
uasm_il_bne(pp, pr, t0, t1, lbl);
uasm_i_nop(pp);
}
static int __init cps_gen_flush_fsb(u32 **pp, struct uasm_label **pl,
struct uasm_reloc **pr,
const struct cpuinfo_mips *cpu_info,
int lbl)
{
unsigned i, fsb_size = 8;
unsigned num_loads = (fsb_size * 3) / 2;
unsigned line_stride = 2;
unsigned line_size = cpu_info->dcache.linesz;
unsigned perf_counter, perf_event;
unsigned revision = cpu_info->processor_id & PRID_REV_MASK;
switch (__get_cpu_type(cpu_info->cputype)) {
case CPU_INTERAPTIV:
perf_counter = 1;
perf_event = 51;
break;
case CPU_PROAPTIV:
if (revision >= PRID_REV_ENCODE_332(1, 1, 0))
return 0;
return -1;
case CPU_P5600:
case CPU_I6400:
return 0;
default:
WARN_ONCE(1, "pm-cps: FSB flush unsupported for this CPU\n");
return -1;
}
uasm_i_mfc0(pp, t2, 25, (perf_counter * 2) + 0);
uasm_i_mfc0(pp, t3, 25, (perf_counter * 2) + 1);
uasm_i_addiu(pp, t0, zero, (perf_event << 5) | 0xf);
uasm_i_mtc0(pp, t0, 25, (perf_counter * 2) + 0);
uasm_i_ehb(pp);
uasm_i_mtc0(pp, zero, 25, (perf_counter * 2) + 1);
uasm_i_ehb(pp);
UASM_i_LA(pp, t0, (long)CKSEG0);
uasm_build_label(pl, *pp, lbl);
for (i = 0; i < num_loads; i++)
uasm_i_lw(pp, zero, i * line_size * line_stride, t0);
for (i = 0; i < num_loads; i++) {
uasm_i_cache(pp, Hit_Invalidate_D,
i * line_size * line_stride, t0);
uasm_i_cache(pp, Hit_Writeback_Inv_SD,
i * line_size * line_stride, t0);
}
uasm_i_sync(pp, stype_memory);
uasm_i_ehb(pp);
uasm_i_mfc0(pp, t1, 25, (perf_counter * 2) + 1);
uasm_il_beqz(pp, pr, t1, lbl);
uasm_i_nop(pp);
uasm_i_mtc0(pp, t2, 25, (perf_counter * 2) + 0);
uasm_i_ehb(pp);
uasm_i_mtc0(pp, t3, 25, (perf_counter * 2) + 1);
uasm_i_ehb(pp);
return 0;
}
static void __init cps_gen_set_top_bit(u32 **pp, struct uasm_label **pl,
struct uasm_reloc **pr,
unsigned r_addr, int lbl)
{
uasm_i_lui(pp, t0, uasm_rel_hi(0x80000000));
uasm_build_label(pl, *pp, lbl);
uasm_i_ll(pp, t1, 0, r_addr);
uasm_i_or(pp, t1, t1, t0);
uasm_i_sc(pp, t1, 0, r_addr);
uasm_il_beqz(pp, pr, t1, lbl);
uasm_i_nop(pp);
}
static void * __init cps_gen_entry_code(unsigned cpu, enum cps_pm_state state)
{
struct uasm_label *l = labels;
struct uasm_reloc *r = relocs;
u32 *buf, *p;
const unsigned r_online = a0;
const unsigned r_nc_count = a1;
const unsigned r_pcohctl = t7;
const unsigned max_instrs = 256;
unsigned cpc_cmd;
int err;
enum {
lbl_incready = 1,
lbl_poll_cont,
lbl_secondary_hang,
lbl_disable_coherence,
lbl_flush_fsb,
lbl_invicache,
lbl_flushdcache,
lbl_hang,
lbl_set_cont,
lbl_secondary_cont,
lbl_decready,
};
p = buf = kcalloc(max_instrs, sizeof(u32), GFP_KERNEL);
if (!buf)
return NULL;
memset(labels, 0, sizeof(labels));
memset(relocs, 0, sizeof(relocs));
if (config_enabled(CONFIG_CPU_PM) && state == CPS_PM_POWER_GATED) {
if (!mips_cps_smp_in_use())
goto out_err;
UASM_i_LA(&p, t0, (long)mips_cps_pm_save);
uasm_i_jalr(&p, v0, t0);
uasm_i_nop(&p);
}
UASM_i_LA(&p, r_pcohctl, (long)addr_gcr_cl_coherence());
if (coupled_coherence) {
uasm_i_sync(&p, stype_ordering);
uasm_build_label(&l, p, lbl_incready);
uasm_i_ll(&p, t1, 0, r_nc_count);
uasm_i_addiu(&p, t2, t1, 1);
uasm_i_sc(&p, t2, 0, r_nc_count);
uasm_il_beqz(&p, &r, t2, lbl_incready);
uasm_i_addiu(&p, t1, t1, 1);
uasm_i_sync(&p, stype_ordering);
uasm_il_beq(&p, &r, t1, r_online, lbl_disable_coherence);
uasm_i_nop(&p);
if (state < CPS_PM_POWER_GATED) {
uasm_i_addiu(&p, t1, zero, -1);
uasm_build_label(&l, p, lbl_poll_cont);
uasm_i_lw(&p, t0, 0, r_nc_count);
uasm_il_bltz(&p, &r, t0, lbl_secondary_cont);
uasm_i_ehb(&p);
uasm_i_yield(&p, zero, t1);
uasm_il_b(&p, &r, lbl_poll_cont);
uasm_i_nop(&p);
} else {
uasm_i_addiu(&p, t0, zero, TCHALT_H);
uasm_i_mtc0(&p, t0, 2, 4);
uasm_build_label(&l, p, lbl_secondary_hang);
uasm_il_b(&p, &r, lbl_secondary_hang);
uasm_i_nop(&p);
}
}
uasm_build_label(&l, p, lbl_disable_coherence);
cps_gen_cache_routine(&p, &l, &r, &cpu_data[cpu].icache,
Index_Invalidate_I, lbl_invicache);
cps_gen_cache_routine(&p, &l, &r, &cpu_data[cpu].dcache,
Index_Writeback_Inv_D, lbl_flushdcache);
uasm_i_sync(&p, stype_memory);
uasm_i_ehb(&p);
uasm_i_addiu(&p, t0, zero, 1 << cpu_data[cpu].core);
uasm_i_sw(&p, t0, 0, r_pcohctl);
uasm_i_lw(&p, t0, 0, r_pcohctl);
uasm_i_sync(&p, stype_intervention);
uasm_i_ehb(&p);
uasm_i_sw(&p, zero, 0, r_pcohctl);
uasm_i_lw(&p, t0, 0, r_pcohctl);
if (state >= CPS_PM_CLOCK_GATED) {
err = cps_gen_flush_fsb(&p, &l, &r, &cpu_data[cpu],
lbl_flush_fsb);
if (err)
goto out_err;
switch (state) {
case CPS_PM_CLOCK_GATED:
cpc_cmd = CPC_Cx_CMD_CLOCKOFF;
break;
case CPS_PM_POWER_GATED:
cpc_cmd = CPC_Cx_CMD_PWRDOWN;
break;
default:
BUG();
goto out_err;
}
UASM_i_LA(&p, t0, (long)addr_cpc_cl_cmd());
uasm_i_addiu(&p, t1, zero, cpc_cmd);
uasm_i_sw(&p, t1, 0, t0);
if (state == CPS_PM_POWER_GATED) {
uasm_build_label(&l, p, lbl_hang);
uasm_il_b(&p, &r, lbl_hang);
uasm_i_nop(&p);
goto gen_done;
}
uasm_i_sync(&p, stype_memory);
uasm_i_ehb(&p);
}
if (state == CPS_PM_NC_WAIT) {
if (coupled_coherence)
cps_gen_set_top_bit(&p, &l, &r, r_nc_count,
lbl_set_cont);
uasm_build_label(&l, p, lbl_secondary_cont);
uasm_i_wait(&p, 0);
}
uasm_i_addiu(&p, t0, zero, CM_GCR_Cx_COHERENCE_COHDOMAINEN_MSK);
uasm_i_sw(&p, t0, 0, r_pcohctl);
uasm_i_lw(&p, t0, 0, r_pcohctl);
uasm_i_sync(&p, stype_memory);
uasm_i_ehb(&p);
if (coupled_coherence && (state == CPS_PM_NC_WAIT)) {
uasm_build_label(&l, p, lbl_decready);
uasm_i_sync(&p, stype_ordering);
uasm_i_ll(&p, t1, 0, r_nc_count);
uasm_i_addiu(&p, t2, t1, -1);
uasm_i_sc(&p, t2, 0, r_nc_count);
uasm_il_beqz(&p, &r, t2, lbl_decready);
uasm_i_andi(&p, v0, t1, (1 << fls(smp_num_siblings)) - 1);
uasm_i_sync(&p, stype_ordering);
}
if (coupled_coherence && (state == CPS_PM_CLOCK_GATED)) {
cps_gen_set_top_bit(&p, &l, &r, r_nc_count, lbl_set_cont);
uasm_build_label(&l, p, lbl_secondary_cont);
uasm_i_sync(&p, stype_ordering);
}
uasm_i_jr(&p, ra);
uasm_i_nop(&p);
gen_done:
BUG_ON((p - buf) > max_instrs);
BUG_ON((l - labels) > ARRAY_SIZE(labels));
BUG_ON((r - relocs) > ARRAY_SIZE(relocs));
uasm_resolve_relocs(relocs, labels);
local_flush_icache_range((unsigned long)buf, (unsigned long)p);
return buf;
out_err:
kfree(buf);
return NULL;
}
static int __init cps_gen_core_entries(unsigned cpu)
{
enum cps_pm_state state;
unsigned core = cpu_data[cpu].core;
unsigned dlinesz = cpu_data[cpu].dcache.linesz;
void *entry_fn, *core_rc;
for (state = CPS_PM_NC_WAIT; state < CPS_PM_STATE_COUNT; state++) {
if (per_cpu(nc_asm_enter, core)[state])
continue;
if (!test_bit(state, state_support))
continue;
entry_fn = cps_gen_entry_code(cpu, state);
if (!entry_fn) {
pr_err("Failed to generate core %u state %u entry\n",
core, state);
clear_bit(state, state_support);
}
per_cpu(nc_asm_enter, core)[state] = entry_fn;
}
if (!per_cpu(ready_count, core)) {
core_rc = kmalloc(dlinesz * 2, GFP_KERNEL);
if (!core_rc) {
pr_err("Failed allocate core %u ready_count\n", core);
return -ENOMEM;
}
per_cpu(ready_count_alloc, core) = core_rc;
core_rc += dlinesz - 1;
core_rc = (void *)((unsigned long)core_rc & ~(dlinesz - 1));
per_cpu(ready_count, core) = core_rc;
}
return 0;
}
static int __init cps_pm_init(void)
{
unsigned cpu;
int err;
switch (current_cpu_data.cputype) {
case CPU_INTERAPTIV:
case CPU_PROAPTIV:
case CPU_M5150:
case CPU_P5600:
case CPU_I6400:
stype_intervention = 0x2;
stype_memory = 0x3;
stype_ordering = 0x10;
break;
default:
pr_warn("Power management is using heavyweight sync 0\n");
}
if (!mips_cm_present()) {
pr_warn("pm-cps: no CM, non-coherent states unavailable\n");
goto out;
}
if (cpu_wait == r4k_wait_irqoff)
set_bit(CPS_PM_NC_WAIT, state_support);
else
pr_warn("pm-cps: non-coherent wait unavailable\n");
if (mips_cpc_present()) {
if (read_cpc_cl_stat_conf() & CPC_Cx_STAT_CONF_CLKGAT_IMPL_MSK)
set_bit(CPS_PM_CLOCK_GATED, state_support);
else
pr_warn("pm-cps: CPC does not support clock gating\n");
if (mips_cps_smp_in_use())
set_bit(CPS_PM_POWER_GATED, state_support);
else
pr_warn("pm-cps: CPS SMP not in use, power gating unavailable\n");
} else {
pr_warn("pm-cps: no CPC, clock & power gating unavailable\n");
}
for_each_present_cpu(cpu) {
err = cps_gen_core_entries(cpu);
if (err)
return err;
}
out:
return 0;
}
