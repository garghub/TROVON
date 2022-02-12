static u64 intel_pmu_event_map(int hw_event)
{
return intel_perfmon_event_map[hw_event];
}
static void intel_pmu_disable_all(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
wrmsrl(MSR_CORE_PERF_GLOBAL_CTRL, 0);
if (test_bit(X86_PMC_IDX_FIXED_BTS, cpuc->active_mask))
intel_pmu_disable_bts();
intel_pmu_pebs_disable_all();
intel_pmu_lbr_disable_all();
}
static void intel_pmu_enable_all(int added)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
intel_pmu_pebs_enable_all();
intel_pmu_lbr_enable_all();
wrmsrl(MSR_CORE_PERF_GLOBAL_CTRL, x86_pmu.intel_ctrl);
if (test_bit(X86_PMC_IDX_FIXED_BTS, cpuc->active_mask)) {
struct perf_event *event =
cpuc->events[X86_PMC_IDX_FIXED_BTS];
if (WARN_ON_ONCE(!event))
return;
intel_pmu_enable_bts(event->hw.config);
}
}
static void intel_pmu_nhm_workaround(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
static const unsigned long nhm_magic[4] = {
0x4300B5,
0x4300D2,
0x4300B1,
0x4300B1
};
struct perf_event *event;
int i;
for (i = 0; i < 4; i++) {
event = cpuc->events[i];
if (event)
x86_perf_event_update(event);
}
for (i = 0; i < 4; i++) {
wrmsrl(MSR_ARCH_PERFMON_EVENTSEL0 + i, nhm_magic[i]);
wrmsrl(MSR_ARCH_PERFMON_PERFCTR0 + i, 0x0);
}
wrmsrl(MSR_CORE_PERF_GLOBAL_CTRL, 0xf);
wrmsrl(MSR_CORE_PERF_GLOBAL_CTRL, 0x0);
for (i = 0; i < 4; i++) {
event = cpuc->events[i];
if (event) {
x86_perf_event_set_period(event);
__x86_pmu_enable_event(&event->hw,
ARCH_PERFMON_EVENTSEL_ENABLE);
} else
wrmsrl(MSR_ARCH_PERFMON_EVENTSEL0 + i, 0x0);
}
}
static void intel_pmu_nhm_enable_all(int added)
{
if (added)
intel_pmu_nhm_workaround();
intel_pmu_enable_all(added);
}
static inline u64 intel_pmu_get_status(void)
{
u64 status;
rdmsrl(MSR_CORE_PERF_GLOBAL_STATUS, status);
return status;
}
static inline void intel_pmu_ack_status(u64 ack)
{
wrmsrl(MSR_CORE_PERF_GLOBAL_OVF_CTRL, ack);
}
static void intel_pmu_disable_fixed(struct hw_perf_event *hwc)
{
int idx = hwc->idx - X86_PMC_IDX_FIXED;
u64 ctrl_val, mask;
mask = 0xfULL << (idx * 4);
rdmsrl(hwc->config_base, ctrl_val);
ctrl_val &= ~mask;
wrmsrl(hwc->config_base, ctrl_val);
}
static void intel_pmu_disable_event(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (unlikely(hwc->idx == X86_PMC_IDX_FIXED_BTS)) {
intel_pmu_disable_bts();
intel_pmu_drain_bts_buffer();
return;
}
if (unlikely(hwc->config_base == MSR_ARCH_PERFMON_FIXED_CTR_CTRL)) {
intel_pmu_disable_fixed(hwc);
return;
}
x86_pmu_disable_event(event);
if (unlikely(event->attr.precise_ip))
intel_pmu_pebs_disable(event);
}
static void intel_pmu_enable_fixed(struct hw_perf_event *hwc)
{
int idx = hwc->idx - X86_PMC_IDX_FIXED;
u64 ctrl_val, bits, mask;
bits = 0x8ULL;
if (hwc->config & ARCH_PERFMON_EVENTSEL_USR)
bits |= 0x2;
if (hwc->config & ARCH_PERFMON_EVENTSEL_OS)
bits |= 0x1;
if (x86_pmu.version > 2 && hwc->config & ARCH_PERFMON_EVENTSEL_ANY)
bits |= 0x4;
bits <<= (idx * 4);
mask = 0xfULL << (idx * 4);
rdmsrl(hwc->config_base, ctrl_val);
ctrl_val &= ~mask;
ctrl_val |= bits;
wrmsrl(hwc->config_base, ctrl_val);
}
static void intel_pmu_enable_event(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (unlikely(hwc->idx == X86_PMC_IDX_FIXED_BTS)) {
if (!__this_cpu_read(cpu_hw_events.enabled))
return;
intel_pmu_enable_bts(hwc->config);
return;
}
if (unlikely(hwc->config_base == MSR_ARCH_PERFMON_FIXED_CTR_CTRL)) {
intel_pmu_enable_fixed(hwc);
return;
}
if (unlikely(event->attr.precise_ip))
intel_pmu_pebs_enable(event);
__x86_pmu_enable_event(hwc, ARCH_PERFMON_EVENTSEL_ENABLE);
}
static int intel_pmu_save_and_restart(struct perf_event *event)
{
x86_perf_event_update(event);
return x86_perf_event_set_period(event);
}
static void intel_pmu_reset(void)
{
struct debug_store *ds = __this_cpu_read(cpu_hw_events.ds);
unsigned long flags;
int idx;
if (!x86_pmu.num_counters)
return;
local_irq_save(flags);
printk("clearing PMU state on CPU#%d\n", smp_processor_id());
for (idx = 0; idx < x86_pmu.num_counters; idx++) {
checking_wrmsrl(x86_pmu_config_addr(idx), 0ull);
checking_wrmsrl(x86_pmu_event_addr(idx), 0ull);
}
for (idx = 0; idx < x86_pmu.num_counters_fixed; idx++)
checking_wrmsrl(MSR_ARCH_PERFMON_FIXED_CTR0 + idx, 0ull);
if (ds)
ds->bts_index = ds->bts_buffer_base;
local_irq_restore(flags);
}
static int intel_pmu_handle_irq(struct pt_regs *regs)
{
struct perf_sample_data data;
struct cpu_hw_events *cpuc;
int bit, loops;
u64 status;
int handled;
perf_sample_data_init(&data, 0);
cpuc = &__get_cpu_var(cpu_hw_events);
apic_write(APIC_LVTPC, APIC_DM_NMI);
intel_pmu_disable_all();
handled = intel_pmu_drain_bts_buffer();
status = intel_pmu_get_status();
if (!status) {
intel_pmu_enable_all(0);
return handled;
}
loops = 0;
again:
intel_pmu_ack_status(status);
if (++loops > 100) {
WARN_ONCE(1, "perfevents: irq loop stuck!\n");
perf_event_print_debug();
intel_pmu_reset();
goto done;
}
inc_irq_stat(apic_perf_irqs);
intel_pmu_lbr_read();
if (__test_and_clear_bit(62, (unsigned long *)&status)) {
handled++;
x86_pmu.drain_pebs(regs);
}
for_each_set_bit(bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct perf_event *event = cpuc->events[bit];
handled++;
if (!test_bit(bit, cpuc->active_mask))
continue;
if (!intel_pmu_save_and_restart(event))
continue;
data.period = event->hw.last_period;
if (perf_event_overflow(event, 1, &data, regs))
x86_pmu_stop(event, 0);
}
status = intel_pmu_get_status();
if (status)
goto again;
done:
intel_pmu_enable_all(0);
return handled;
}
static struct event_constraint *
intel_bts_constraints(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
unsigned int hw_event, bts_event;
if (event->attr.freq)
return NULL;
hw_event = hwc->config & INTEL_ARCH_EVENT_MASK;
bts_event = x86_pmu.event_map(PERF_COUNT_HW_BRANCH_INSTRUCTIONS);
if (unlikely(hw_event == bts_event && hwc->sample_period == 1))
return &bts_constraint;
return NULL;
}
static struct event_constraint *
intel_percore_constraints(struct cpu_hw_events *cpuc, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
unsigned int e = hwc->config & ARCH_PERFMON_EVENTSEL_EVENT;
struct event_constraint *c;
struct intel_percore *pc;
struct er_account *era;
int i;
int free_slot;
int found;
if (!x86_pmu.percore_constraints || hwc->extra_alloc)
return NULL;
for (c = x86_pmu.percore_constraints; c->cmask; c++) {
if (e != c->code)
continue;
pc = cpuc->per_core;
if (!pc)
break;
c = &emptyconstraint;
raw_spin_lock(&pc->lock);
free_slot = -1;
found = 0;
for (i = 0; i < MAX_EXTRA_REGS; i++) {
era = &pc->regs[i];
if (era->ref > 0 && hwc->extra_reg == era->extra_reg) {
if (hwc->extra_config == era->extra_config) {
era->ref++;
cpuc->percore_used = 1;
hwc->extra_alloc = 1;
c = NULL;
}
found = 1;
break;
} else if (era->ref == 0 && free_slot == -1)
free_slot = i;
}
if (!found && free_slot != -1) {
era = &pc->regs[free_slot];
era->ref = 1;
era->extra_reg = hwc->extra_reg;
era->extra_config = hwc->extra_config;
cpuc->percore_used = 1;
hwc->extra_alloc = 1;
c = NULL;
}
raw_spin_unlock(&pc->lock);
return c;
}
return NULL;
}
static struct event_constraint *
intel_get_event_constraints(struct cpu_hw_events *cpuc, struct perf_event *event)
{
struct event_constraint *c;
c = intel_bts_constraints(event);
if (c)
return c;
c = intel_pebs_constraints(event);
if (c)
return c;
c = intel_percore_constraints(cpuc, event);
if (c)
return c;
return x86_get_event_constraints(cpuc, event);
}
static void intel_put_event_constraints(struct cpu_hw_events *cpuc,
struct perf_event *event)
{
struct extra_reg *er;
struct intel_percore *pc;
struct er_account *era;
struct hw_perf_event *hwc = &event->hw;
int i, allref;
if (!cpuc->percore_used)
return;
for (er = x86_pmu.extra_regs; er->msr; er++) {
if (er->event != (hwc->config & er->config_mask))
continue;
pc = cpuc->per_core;
raw_spin_lock(&pc->lock);
for (i = 0; i < MAX_EXTRA_REGS; i++) {
era = &pc->regs[i];
if (era->ref > 0 &&
era->extra_config == hwc->extra_config &&
era->extra_reg == er->msr) {
era->ref--;
hwc->extra_alloc = 0;
break;
}
}
allref = 0;
for (i = 0; i < MAX_EXTRA_REGS; i++)
allref += pc->regs[i].ref;
if (allref == 0)
cpuc->percore_used = 0;
raw_spin_unlock(&pc->lock);
break;
}
}
static int intel_pmu_hw_config(struct perf_event *event)
{
int ret = x86_pmu_hw_config(event);
if (ret)
return ret;
if (event->attr.precise_ip &&
(event->hw.config & X86_RAW_EVENT_MASK) == 0x003c) {
u64 alt_config = 0x108000c0;
alt_config |= (event->hw.config & ~X86_RAW_EVENT_MASK);
event->hw.config = alt_config;
}
if (event->attr.type != PERF_TYPE_RAW)
return 0;
if (!(event->attr.config & ARCH_PERFMON_EVENTSEL_ANY))
return 0;
if (x86_pmu.version < 3)
return -EINVAL;
if (perf_paranoid_cpu() && !capable(CAP_SYS_ADMIN))
return -EACCES;
event->hw.config |= ARCH_PERFMON_EVENTSEL_ANY;
return 0;
}
static int intel_pmu_cpu_prepare(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
if (!cpu_has_ht_siblings())
return NOTIFY_OK;
cpuc->per_core = kzalloc_node(sizeof(struct intel_percore),
GFP_KERNEL, cpu_to_node(cpu));
if (!cpuc->per_core)
return NOTIFY_BAD;
raw_spin_lock_init(&cpuc->per_core->lock);
cpuc->per_core->core_id = -1;
return NOTIFY_OK;
}
static void intel_pmu_cpu_starting(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
int core_id = topology_core_id(cpu);
int i;
init_debug_store_on_cpu(cpu);
intel_pmu_lbr_reset();
if (!cpu_has_ht_siblings())
return;
for_each_cpu(i, topology_thread_cpumask(cpu)) {
struct intel_percore *pc = per_cpu(cpu_hw_events, i).per_core;
if (pc && pc->core_id == core_id) {
kfree(cpuc->per_core);
cpuc->per_core = pc;
break;
}
}
cpuc->per_core->core_id = core_id;
cpuc->per_core->refcnt++;
}
static void intel_pmu_cpu_dying(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
struct intel_percore *pc = cpuc->per_core;
if (pc) {
if (pc->core_id == -1 || --pc->refcnt == 0)
kfree(pc);
cpuc->per_core = NULL;
}
fini_debug_store_on_cpu(cpu);
}
static void intel_clovertown_quirks(void)
{
printk(KERN_WARNING "PEBS disabled due to CPU errata.\n");
x86_pmu.pebs = 0;
x86_pmu.pebs_constraints = NULL;
}
static __init int intel_pmu_init(void)
{
union cpuid10_edx edx;
union cpuid10_eax eax;
unsigned int unused;
unsigned int ebx;
int version;
if (!cpu_has(&boot_cpu_data, X86_FEATURE_ARCH_PERFMON)) {
switch (boot_cpu_data.x86) {
case 0x6:
return p6_pmu_init();
case 0xf:
return p4_pmu_init();
}
return -ENODEV;
}
cpuid(10, &eax.full, &ebx, &unused, &edx.full);
if (eax.split.mask_length <= ARCH_PERFMON_BRANCH_MISSES_RETIRED)
return -ENODEV;
version = eax.split.version_id;
if (version < 2)
x86_pmu = core_pmu;
else
x86_pmu = intel_pmu;
x86_pmu.version = version;
x86_pmu.num_counters = eax.split.num_counters;
x86_pmu.cntval_bits = eax.split.bit_width;
x86_pmu.cntval_mask = (1ULL << eax.split.bit_width) - 1;
if (version > 1)
x86_pmu.num_counters_fixed = max((int)edx.split.num_counters_fixed, 3);
if (version > 1) {
u64 capabilities;
rdmsrl(MSR_IA32_PERF_CAPABILITIES, capabilities);
x86_pmu.intel_cap.capabilities = capabilities;
}
intel_ds_init();
switch (boot_cpu_data.x86_model) {
case 14:
pr_cont("Core events, ");
break;
case 15:
x86_pmu.quirks = intel_clovertown_quirks;
case 22:
case 23:
case 29:
memcpy(hw_cache_event_ids, core2_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
intel_pmu_lbr_init_core();
x86_pmu.event_constraints = intel_core2_event_constraints;
x86_pmu.pebs_constraints = intel_core2_pebs_event_constraints;
pr_cont("Core2 events, ");
break;
case 26:
case 30:
case 46:
memcpy(hw_cache_event_ids, nehalem_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
memcpy(hw_cache_extra_regs, nehalem_hw_cache_extra_regs,
sizeof(hw_cache_extra_regs));
intel_pmu_lbr_init_nhm();
x86_pmu.event_constraints = intel_nehalem_event_constraints;
x86_pmu.pebs_constraints = intel_nehalem_pebs_event_constraints;
x86_pmu.percore_constraints = intel_nehalem_percore_constraints;
x86_pmu.enable_all = intel_pmu_nhm_enable_all;
x86_pmu.extra_regs = intel_nehalem_extra_regs;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_FRONTEND] = 0x180010e;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_BACKEND] = 0x1803fb1;
if (ebx & 0x40) {
intel_perfmon_event_map[PERF_COUNT_HW_BRANCH_MISSES] = 0x7f89;
pr_cont("erratum AAJ80 worked around, ");
}
pr_cont("Nehalem events, ");
break;
case 28:
memcpy(hw_cache_event_ids, atom_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
intel_pmu_lbr_init_atom();
x86_pmu.event_constraints = intel_gen_event_constraints;
x86_pmu.pebs_constraints = intel_atom_pebs_event_constraints;
pr_cont("Atom events, ");
break;
case 37:
case 44:
case 47:
memcpy(hw_cache_event_ids, westmere_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
memcpy(hw_cache_extra_regs, nehalem_hw_cache_extra_regs,
sizeof(hw_cache_extra_regs));
intel_pmu_lbr_init_nhm();
x86_pmu.event_constraints = intel_westmere_event_constraints;
x86_pmu.percore_constraints = intel_westmere_percore_constraints;
x86_pmu.enable_all = intel_pmu_nhm_enable_all;
x86_pmu.pebs_constraints = intel_westmere_pebs_event_constraints;
x86_pmu.extra_regs = intel_westmere_extra_regs;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_FRONTEND] = 0x180010e;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_BACKEND] = 0x1803fb1;
pr_cont("Westmere events, ");
break;
case 42:
memcpy(hw_cache_event_ids, snb_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
intel_pmu_lbr_init_nhm();
x86_pmu.event_constraints = intel_snb_event_constraints;
x86_pmu.pebs_constraints = intel_snb_pebs_events;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_FRONTEND] = 0x180010e;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_BACKEND] = 0x18001b1;
pr_cont("SandyBridge events, ");
break;
default:
x86_pmu.event_constraints = intel_gen_event_constraints;
pr_cont("generic architected perfmon, ");
}
return 0;
}
static int intel_pmu_init(void)
{
return 0;
}
