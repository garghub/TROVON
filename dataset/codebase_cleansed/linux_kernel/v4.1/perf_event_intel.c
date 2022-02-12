static u64 intel_pmu_event_map(int hw_event)
{
return intel_perfmon_event_map[hw_event];
}
static void __intel_pmu_disable_all(void)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
wrmsrl(MSR_CORE_PERF_GLOBAL_CTRL, 0);
if (test_bit(INTEL_PMC_IDX_FIXED_BTS, cpuc->active_mask))
intel_pmu_disable_bts();
else
intel_bts_disable_local();
intel_pmu_pebs_disable_all();
}
static void intel_pmu_disable_all(void)
{
__intel_pmu_disable_all();
intel_pmu_lbr_disable_all();
}
static void __intel_pmu_enable_all(int added, bool pmi)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
intel_pmu_pebs_enable_all();
intel_pmu_lbr_enable_all(pmi);
wrmsrl(MSR_CORE_PERF_GLOBAL_CTRL,
x86_pmu.intel_ctrl & ~cpuc->intel_ctrl_guest_mask);
if (test_bit(INTEL_PMC_IDX_FIXED_BTS, cpuc->active_mask)) {
struct perf_event *event =
cpuc->events[INTEL_PMC_IDX_FIXED_BTS];
if (WARN_ON_ONCE(!event))
return;
intel_pmu_enable_bts(event->hw.config);
} else
intel_bts_enable_local();
}
static void intel_pmu_enable_all(int added)
{
__intel_pmu_enable_all(added, false);
}
static void intel_pmu_nhm_workaround(void)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
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
int idx = hwc->idx - INTEL_PMC_IDX_FIXED;
u64 ctrl_val, mask;
mask = 0xfULL << (idx * 4);
rdmsrl(hwc->config_base, ctrl_val);
ctrl_val &= ~mask;
wrmsrl(hwc->config_base, ctrl_val);
}
static inline bool event_is_checkpointed(struct perf_event *event)
{
return (event->hw.config & HSW_IN_TX_CHECKPOINTED) != 0;
}
static void intel_pmu_disable_event(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
if (unlikely(hwc->idx == INTEL_PMC_IDX_FIXED_BTS)) {
intel_pmu_disable_bts();
intel_pmu_drain_bts_buffer();
return;
}
cpuc->intel_ctrl_guest_mask &= ~(1ull << hwc->idx);
cpuc->intel_ctrl_host_mask &= ~(1ull << hwc->idx);
cpuc->intel_cp_status &= ~(1ull << hwc->idx);
if (needs_branch_stack(event))
intel_pmu_lbr_disable(event);
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
int idx = hwc->idx - INTEL_PMC_IDX_FIXED;
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
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
if (unlikely(hwc->idx == INTEL_PMC_IDX_FIXED_BTS)) {
if (!__this_cpu_read(cpu_hw_events.enabled))
return;
intel_pmu_enable_bts(hwc->config);
return;
}
if (needs_branch_stack(event))
intel_pmu_lbr_enable(event);
if (event->attr.exclude_host)
cpuc->intel_ctrl_guest_mask |= (1ull << hwc->idx);
if (event->attr.exclude_guest)
cpuc->intel_ctrl_host_mask |= (1ull << hwc->idx);
if (unlikely(event_is_checkpointed(event)))
cpuc->intel_cp_status |= (1ull << hwc->idx);
if (unlikely(hwc->config_base == MSR_ARCH_PERFMON_FIXED_CTR_CTRL)) {
intel_pmu_enable_fixed(hwc);
return;
}
if (unlikely(event->attr.precise_ip))
intel_pmu_pebs_enable(event);
__x86_pmu_enable_event(hwc, ARCH_PERFMON_EVENTSEL_ENABLE);
}
int intel_pmu_save_and_restart(struct perf_event *event)
{
x86_perf_event_update(event);
if (unlikely(event_is_checkpointed(event))) {
wrmsrl(event->hw.event_base, 0);
local64_set(&event->hw.prev_count, 0);
}
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
pr_info("clearing PMU state on CPU#%d\n", smp_processor_id());
for (idx = 0; idx < x86_pmu.num_counters; idx++) {
wrmsrl_safe(x86_pmu_config_addr(idx), 0ull);
wrmsrl_safe(x86_pmu_event_addr(idx), 0ull);
}
for (idx = 0; idx < x86_pmu.num_counters_fixed; idx++)
wrmsrl_safe(MSR_ARCH_PERFMON_FIXED_CTR0 + idx, 0ull);
if (ds)
ds->bts_index = ds->bts_buffer_base;
if (x86_pmu.version >= 2) {
intel_pmu_ack_status(intel_pmu_get_status());
wrmsrl(MSR_CORE_PERF_GLOBAL_CTRL, 0);
}
if (x86_pmu.lbr_nr) {
update_debugctlmsr(get_debugctlmsr() &
~(DEBUGCTLMSR_FREEZE_LBRS_ON_PMI|DEBUGCTLMSR_LBR));
}
local_irq_restore(flags);
}
static int intel_pmu_handle_irq(struct pt_regs *regs)
{
struct perf_sample_data data;
struct cpu_hw_events *cpuc;
int bit, loops;
u64 status;
int handled;
cpuc = this_cpu_ptr(&cpu_hw_events);
if (!x86_pmu.late_ack)
apic_write(APIC_LVTPC, APIC_DM_NMI);
__intel_pmu_disable_all();
handled = intel_pmu_drain_bts_buffer();
handled += intel_bts_interrupt();
status = intel_pmu_get_status();
if (!status)
goto done;
loops = 0;
again:
intel_pmu_ack_status(status);
if (++loops > 100) {
static bool warned = false;
if (!warned) {
WARN(1, "perfevents: irq loop stuck!\n");
perf_event_print_debug();
warned = true;
}
intel_pmu_reset();
goto done;
}
inc_irq_stat(apic_perf_irqs);
intel_pmu_lbr_read();
if (__test_and_clear_bit(63, (unsigned long *)&status)) {
if (!status)
goto done;
}
if (__test_and_clear_bit(62, (unsigned long *)&status)) {
handled++;
x86_pmu.drain_pebs(regs);
}
if (__test_and_clear_bit(55, (unsigned long *)&status)) {
handled++;
intel_pt_interrupt();
}
status |= cpuc->intel_cp_status;
for_each_set_bit(bit, (unsigned long *)&status, X86_PMC_IDX_MAX) {
struct perf_event *event = cpuc->events[bit];
handled++;
if (!test_bit(bit, cpuc->active_mask))
continue;
if (!intel_pmu_save_and_restart(event))
continue;
perf_sample_data_init(&data, 0, event->hw.last_period);
if (has_branch_stack(event))
data.br_stack = &cpuc->lbr_stack;
if (perf_event_overflow(event, &data, regs))
x86_pmu_stop(event, 0);
}
status = intel_pmu_get_status();
if (status)
goto again;
done:
__intel_pmu_enable_all(0, true);
if (x86_pmu.late_ack)
apic_write(APIC_LVTPC, APIC_DM_NMI);
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
static int intel_alt_er(int idx)
{
if (!(x86_pmu.flags & PMU_FL_HAS_RSP_1))
return idx;
if (idx == EXTRA_REG_RSP_0)
return EXTRA_REG_RSP_1;
if (idx == EXTRA_REG_RSP_1)
return EXTRA_REG_RSP_0;
return idx;
}
static void intel_fixup_er(struct perf_event *event, int idx)
{
event->hw.extra_reg.idx = idx;
if (idx == EXTRA_REG_RSP_0) {
event->hw.config &= ~INTEL_ARCH_EVENT_MASK;
event->hw.config |= x86_pmu.extra_regs[EXTRA_REG_RSP_0].event;
event->hw.extra_reg.reg = MSR_OFFCORE_RSP_0;
} else if (idx == EXTRA_REG_RSP_1) {
event->hw.config &= ~INTEL_ARCH_EVENT_MASK;
event->hw.config |= x86_pmu.extra_regs[EXTRA_REG_RSP_1].event;
event->hw.extra_reg.reg = MSR_OFFCORE_RSP_1;
}
}
static struct event_constraint *
__intel_shared_reg_get_constraints(struct cpu_hw_events *cpuc,
struct perf_event *event,
struct hw_perf_event_extra *reg)
{
struct event_constraint *c = &emptyconstraint;
struct er_account *era;
unsigned long flags;
int idx = reg->idx;
if (reg->alloc && !cpuc->is_fake)
return NULL;
again:
era = &cpuc->shared_regs->regs[idx];
raw_spin_lock_irqsave(&era->lock, flags);
if (!atomic_read(&era->ref) || era->config == reg->config) {
if (!cpuc->is_fake) {
if (idx != reg->idx)
intel_fixup_er(event, idx);
reg->alloc = 1;
}
era->config = reg->config;
era->reg = reg->reg;
atomic_inc(&era->ref);
c = NULL;
} else {
idx = intel_alt_er(idx);
if (idx != reg->idx) {
raw_spin_unlock_irqrestore(&era->lock, flags);
goto again;
}
}
raw_spin_unlock_irqrestore(&era->lock, flags);
return c;
}
static void
__intel_shared_reg_put_constraints(struct cpu_hw_events *cpuc,
struct hw_perf_event_extra *reg)
{
struct er_account *era;
if (!reg->alloc || cpuc->is_fake)
return;
era = &cpuc->shared_regs->regs[reg->idx];
atomic_dec(&era->ref);
reg->alloc = 0;
}
static struct event_constraint *
intel_shared_regs_constraints(struct cpu_hw_events *cpuc,
struct perf_event *event)
{
struct event_constraint *c = NULL, *d;
struct hw_perf_event_extra *xreg, *breg;
xreg = &event->hw.extra_reg;
if (xreg->idx != EXTRA_REG_NONE) {
c = __intel_shared_reg_get_constraints(cpuc, event, xreg);
if (c == &emptyconstraint)
return c;
}
breg = &event->hw.branch_reg;
if (breg->idx != EXTRA_REG_NONE) {
d = __intel_shared_reg_get_constraints(cpuc, event, breg);
if (d == &emptyconstraint) {
__intel_shared_reg_put_constraints(cpuc, xreg);
c = d;
}
}
return c;
}
struct event_constraint *
x86_get_event_constraints(struct cpu_hw_events *cpuc, int idx,
struct perf_event *event)
{
struct event_constraint *c;
if (x86_pmu.event_constraints) {
for_each_event_constraint(c, x86_pmu.event_constraints) {
if ((event->hw.config & c->cmask) == c->code) {
event->hw.flags |= c->flags;
return c;
}
}
}
return &unconstrained;
}
static struct event_constraint *
__intel_get_event_constraints(struct cpu_hw_events *cpuc, int idx,
struct perf_event *event)
{
struct event_constraint *c;
c = intel_bts_constraints(event);
if (c)
return c;
c = intel_shared_regs_constraints(cpuc, event);
if (c)
return c;
c = intel_pebs_constraints(event);
if (c)
return c;
return x86_get_event_constraints(cpuc, idx, event);
}
static void
intel_start_scheduling(struct cpu_hw_events *cpuc)
{
struct intel_excl_cntrs *excl_cntrs = cpuc->excl_cntrs;
struct intel_excl_states *xl, *xlo;
int tid = cpuc->excl_thread_id;
int o_tid = 1 - tid;
if (cpuc->is_fake || !is_ht_workaround_enabled())
return;
if (!excl_cntrs)
return;
xlo = &excl_cntrs->states[o_tid];
xl = &excl_cntrs->states[tid];
xl->sched_started = true;
WARN_ON_ONCE(!irqs_disabled());
raw_spin_lock(&excl_cntrs->lock);
memcpy(xlo->init_state, xlo->state, sizeof(xlo->init_state));
}
static void
intel_stop_scheduling(struct cpu_hw_events *cpuc)
{
struct intel_excl_cntrs *excl_cntrs = cpuc->excl_cntrs;
struct intel_excl_states *xl, *xlo;
int tid = cpuc->excl_thread_id;
int o_tid = 1 - tid;
if (cpuc->is_fake || !is_ht_workaround_enabled())
return;
if (!excl_cntrs)
return;
xlo = &excl_cntrs->states[o_tid];
xl = &excl_cntrs->states[tid];
memcpy(xlo->state, xlo->init_state, sizeof(xlo->state));
xl->sched_started = false;
raw_spin_unlock(&excl_cntrs->lock);
}
static struct event_constraint *
intel_get_excl_constraints(struct cpu_hw_events *cpuc, struct perf_event *event,
int idx, struct event_constraint *c)
{
struct event_constraint *cx;
struct intel_excl_cntrs *excl_cntrs = cpuc->excl_cntrs;
struct intel_excl_states *xl, *xlo;
int is_excl, i;
int tid = cpuc->excl_thread_id;
int o_tid = 1 - tid;
if (cpuc->is_fake || !is_ht_workaround_enabled())
return c;
if (!excl_cntrs)
return c;
is_excl = c->flags & PERF_X86_EVENT_EXCL;
if (is_excl && !(event->hw.flags & PERF_X86_EVENT_EXCL_ACCT)) {
event->hw.flags |= PERF_X86_EVENT_EXCL_ACCT;
if (!cpuc->n_excl++)
WRITE_ONCE(excl_cntrs->has_exclusive[tid], 1);
}
xl = &excl_cntrs->states[tid];
xlo = &excl_cntrs->states[o_tid];
cx = c;
if (!(c->flags & PERF_X86_EVENT_DYNAMIC)) {
if (idx < 0)
return &emptyconstraint;
cx = &cpuc->constraint_list[idx];
memcpy(cx, c, sizeof(*cx));
cx->flags |= PERF_X86_EVENT_DYNAMIC;
}
for_each_set_bit(i, cx->idxmsk, X86_PMC_IDX_MAX) {
if (xl->state[i] == INTEL_EXCL_EXCLUSIVE)
__clear_bit(i, cx->idxmsk);
if (is_excl && xl->state[i] == INTEL_EXCL_SHARED)
__clear_bit(i, cx->idxmsk);
}
cx->weight = hweight64(cx->idxmsk64);
if (cx->weight == 0)
cx = &emptyconstraint;
return cx;
}
static struct event_constraint *
intel_get_event_constraints(struct cpu_hw_events *cpuc, int idx,
struct perf_event *event)
{
struct event_constraint *c1 = cpuc->event_constraint[idx];
struct event_constraint *c2;
c2 = __intel_get_event_constraints(cpuc, idx, event);
if (c1 && (c1->flags & PERF_X86_EVENT_DYNAMIC)) {
bitmap_copy(c1->idxmsk, c2->idxmsk, X86_PMC_IDX_MAX);
c1->weight = c2->weight;
c2 = c1;
}
if (cpuc->excl_cntrs)
return intel_get_excl_constraints(cpuc, event, idx, c2);
return c2;
}
static void intel_put_excl_constraints(struct cpu_hw_events *cpuc,
struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct intel_excl_cntrs *excl_cntrs = cpuc->excl_cntrs;
struct intel_excl_states *xlo, *xl;
unsigned long flags = 0;
int tid = cpuc->excl_thread_id;
int o_tid = 1 - tid;
if (cpuc->is_fake)
return;
WARN_ON_ONCE(!excl_cntrs);
if (!excl_cntrs)
return;
xl = &excl_cntrs->states[tid];
xlo = &excl_cntrs->states[o_tid];
if (hwc->flags & PERF_X86_EVENT_EXCL_ACCT) {
hwc->flags &= ~PERF_X86_EVENT_EXCL_ACCT;
if (!--cpuc->n_excl)
WRITE_ONCE(excl_cntrs->has_exclusive[tid], 0);
}
if (!xl->sched_started)
raw_spin_lock_irqsave(&excl_cntrs->lock, flags);
if (hwc->idx >= 0)
xlo->state[hwc->idx] = INTEL_EXCL_UNUSED;
if (!xl->sched_started)
raw_spin_unlock_irqrestore(&excl_cntrs->lock, flags);
}
static void
intel_put_shared_regs_event_constraints(struct cpu_hw_events *cpuc,
struct perf_event *event)
{
struct hw_perf_event_extra *reg;
reg = &event->hw.extra_reg;
if (reg->idx != EXTRA_REG_NONE)
__intel_shared_reg_put_constraints(cpuc, reg);
reg = &event->hw.branch_reg;
if (reg->idx != EXTRA_REG_NONE)
__intel_shared_reg_put_constraints(cpuc, reg);
}
static void intel_put_event_constraints(struct cpu_hw_events *cpuc,
struct perf_event *event)
{
intel_put_shared_regs_event_constraints(cpuc, event);
if (cpuc->excl_cntrs)
intel_put_excl_constraints(cpuc, event);
}
static void intel_commit_scheduling(struct cpu_hw_events *cpuc, int idx, int cntr)
{
struct intel_excl_cntrs *excl_cntrs = cpuc->excl_cntrs;
struct event_constraint *c = cpuc->event_constraint[idx];
struct intel_excl_states *xlo, *xl;
int tid = cpuc->excl_thread_id;
int o_tid = 1 - tid;
int is_excl;
if (cpuc->is_fake || !c)
return;
is_excl = c->flags & PERF_X86_EVENT_EXCL;
if (!(c->flags & PERF_X86_EVENT_DYNAMIC))
return;
WARN_ON_ONCE(!excl_cntrs);
if (!excl_cntrs)
return;
xl = &excl_cntrs->states[tid];
xlo = &excl_cntrs->states[o_tid];
WARN_ON_ONCE(!raw_spin_is_locked(&excl_cntrs->lock));
if (cntr >= 0) {
if (is_excl)
xlo->init_state[cntr] = INTEL_EXCL_EXCLUSIVE;
else
xlo->init_state[cntr] = INTEL_EXCL_SHARED;
}
}
static void intel_pebs_aliases_core2(struct perf_event *event)
{
if ((event->hw.config & X86_RAW_EVENT_MASK) == 0x003c) {
u64 alt_config = X86_CONFIG(.event=0xc0, .inv=1, .cmask=16);
alt_config |= (event->hw.config & ~X86_RAW_EVENT_MASK);
event->hw.config = alt_config;
}
}
static void intel_pebs_aliases_snb(struct perf_event *event)
{
if ((event->hw.config & X86_RAW_EVENT_MASK) == 0x003c) {
u64 alt_config = X86_CONFIG(.event=0xc2, .umask=0x01, .inv=1, .cmask=16);
alt_config |= (event->hw.config & ~X86_RAW_EVENT_MASK);
event->hw.config = alt_config;
}
}
static int intel_pmu_hw_config(struct perf_event *event)
{
int ret = x86_pmu_hw_config(event);
if (ret)
return ret;
if (event->attr.precise_ip && x86_pmu.pebs_aliases)
x86_pmu.pebs_aliases(event);
if (needs_branch_stack(event)) {
ret = intel_pmu_setup_lbr_filter(event);
if (ret)
return ret;
if (!intel_pmu_has_bts(event)) {
if (x86_add_exclusive(x86_lbr_exclusive_lbr))
return -EBUSY;
event->destroy = hw_perf_lbr_event_destroy;
}
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
struct perf_guest_switch_msr *perf_guest_get_msrs(int *nr)
{
if (x86_pmu.guest_get_msrs)
return x86_pmu.guest_get_msrs(nr);
*nr = 0;
return NULL;
}
static struct perf_guest_switch_msr *intel_guest_get_msrs(int *nr)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct perf_guest_switch_msr *arr = cpuc->guest_switch_msrs;
arr[0].msr = MSR_CORE_PERF_GLOBAL_CTRL;
arr[0].host = x86_pmu.intel_ctrl & ~cpuc->intel_ctrl_guest_mask;
arr[0].guest = x86_pmu.intel_ctrl & ~cpuc->intel_ctrl_host_mask;
arr[1].msr = MSR_IA32_PEBS_ENABLE;
arr[1].host = cpuc->pebs_enabled;
arr[1].guest = 0;
*nr = 2;
return arr;
}
static struct perf_guest_switch_msr *core_guest_get_msrs(int *nr)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
struct perf_guest_switch_msr *arr = cpuc->guest_switch_msrs;
int idx;
for (idx = 0; idx < x86_pmu.num_counters; idx++) {
struct perf_event *event = cpuc->events[idx];
arr[idx].msr = x86_pmu_config_addr(idx);
arr[idx].host = arr[idx].guest = 0;
if (!test_bit(idx, cpuc->active_mask))
continue;
arr[idx].host = arr[idx].guest =
event->hw.config | ARCH_PERFMON_EVENTSEL_ENABLE;
if (event->attr.exclude_host)
arr[idx].host &= ~ARCH_PERFMON_EVENTSEL_ENABLE;
else if (event->attr.exclude_guest)
arr[idx].guest &= ~ARCH_PERFMON_EVENTSEL_ENABLE;
}
*nr = x86_pmu.num_counters;
return arr;
}
static void core_pmu_enable_event(struct perf_event *event)
{
if (!event->attr.exclude_host)
x86_pmu_enable_event(event);
}
static void core_pmu_enable_all(int added)
{
struct cpu_hw_events *cpuc = this_cpu_ptr(&cpu_hw_events);
int idx;
for (idx = 0; idx < x86_pmu.num_counters; idx++) {
struct hw_perf_event *hwc = &cpuc->events[idx]->hw;
if (!test_bit(idx, cpuc->active_mask) ||
cpuc->events[idx]->attr.exclude_host)
continue;
__x86_pmu_enable_event(hwc, ARCH_PERFMON_EVENTSEL_ENABLE);
}
}
static int hsw_hw_config(struct perf_event *event)
{
int ret = intel_pmu_hw_config(event);
if (ret)
return ret;
if (!boot_cpu_has(X86_FEATURE_RTM) && !boot_cpu_has(X86_FEATURE_HLE))
return 0;
event->hw.config |= event->attr.config & (HSW_IN_TX|HSW_IN_TX_CHECKPOINTED);
if ((event->hw.config & (HSW_IN_TX|HSW_IN_TX_CHECKPOINTED)) &&
((event->hw.config & ARCH_PERFMON_EVENTSEL_ANY) ||
event->attr.precise_ip > 0))
return -EOPNOTSUPP;
if (event_is_checkpointed(event)) {
if (event->attr.sample_period > 0 &&
event->attr.sample_period < 0x7fffffff)
return -EOPNOTSUPP;
}
return 0;
}
static struct event_constraint *
hsw_get_event_constraints(struct cpu_hw_events *cpuc, int idx,
struct perf_event *event)
{
struct event_constraint *c;
c = intel_get_event_constraints(cpuc, idx, event);
if (event->hw.config & HSW_IN_TX_CHECKPOINTED) {
if (c->idxmsk64 & (1U << 2))
return &counter2_constraint;
return &emptyconstraint;
}
return c;
}
static unsigned bdw_limit_period(struct perf_event *event, unsigned left)
{
if ((event->hw.config & INTEL_ARCH_EVENT_MASK) ==
X86_CONFIG(.event=0xc0, .umask=0x01)) {
if (left < 128)
left = 128;
left &= ~0x3fu;
}
return left;
}
ssize_t intel_event_sysfs_show(char *page, u64 config)
{
u64 event = (config & ARCH_PERFMON_EVENTSEL_EVENT);
return x86_event_sysfs_show(page, config, event);
}
struct intel_shared_regs *allocate_shared_regs(int cpu)
{
struct intel_shared_regs *regs;
int i;
regs = kzalloc_node(sizeof(struct intel_shared_regs),
GFP_KERNEL, cpu_to_node(cpu));
if (regs) {
for (i = 0; i < EXTRA_REG_MAX; i++)
raw_spin_lock_init(&regs->regs[i].lock);
regs->core_id = -1;
}
return regs;
}
static struct intel_excl_cntrs *allocate_excl_cntrs(int cpu)
{
struct intel_excl_cntrs *c;
int i;
c = kzalloc_node(sizeof(struct intel_excl_cntrs),
GFP_KERNEL, cpu_to_node(cpu));
if (c) {
raw_spin_lock_init(&c->lock);
for (i = 0; i < X86_PMC_IDX_MAX; i++) {
c->states[0].state[i] = INTEL_EXCL_UNUSED;
c->states[0].init_state[i] = INTEL_EXCL_UNUSED;
c->states[1].state[i] = INTEL_EXCL_UNUSED;
c->states[1].init_state[i] = INTEL_EXCL_UNUSED;
}
c->core_id = -1;
}
return c;
}
static int intel_pmu_cpu_prepare(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
if (x86_pmu.extra_regs || x86_pmu.lbr_sel_map) {
cpuc->shared_regs = allocate_shared_regs(cpu);
if (!cpuc->shared_regs)
return NOTIFY_BAD;
}
if (x86_pmu.flags & PMU_FL_EXCL_CNTRS) {
size_t sz = X86_PMC_IDX_MAX * sizeof(struct event_constraint);
cpuc->constraint_list = kzalloc(sz, GFP_KERNEL);
if (!cpuc->constraint_list)
return NOTIFY_BAD;
cpuc->excl_cntrs = allocate_excl_cntrs(cpu);
if (!cpuc->excl_cntrs) {
kfree(cpuc->constraint_list);
kfree(cpuc->shared_regs);
return NOTIFY_BAD;
}
cpuc->excl_thread_id = 0;
}
return NOTIFY_OK;
}
static void intel_pmu_cpu_starting(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
int core_id = topology_core_id(cpu);
int i;
init_debug_store_on_cpu(cpu);
intel_pmu_lbr_reset();
cpuc->lbr_sel = NULL;
if (!cpuc->shared_regs)
return;
if (!(x86_pmu.flags & PMU_FL_NO_HT_SHARING)) {
void **onln = &cpuc->kfree_on_online[X86_PERF_KFREE_SHARED];
for_each_cpu(i, topology_thread_cpumask(cpu)) {
struct intel_shared_regs *pc;
pc = per_cpu(cpu_hw_events, i).shared_regs;
if (pc && pc->core_id == core_id) {
*onln = cpuc->shared_regs;
cpuc->shared_regs = pc;
break;
}
}
cpuc->shared_regs->core_id = core_id;
cpuc->shared_regs->refcnt++;
}
if (x86_pmu.lbr_sel_map)
cpuc->lbr_sel = &cpuc->shared_regs->regs[EXTRA_REG_LBR];
if (x86_pmu.flags & PMU_FL_EXCL_CNTRS) {
for_each_cpu(i, topology_thread_cpumask(cpu)) {
struct intel_excl_cntrs *c;
c = per_cpu(cpu_hw_events, i).excl_cntrs;
if (c && c->core_id == core_id) {
cpuc->kfree_on_online[1] = cpuc->excl_cntrs;
cpuc->excl_cntrs = c;
cpuc->excl_thread_id = 1;
break;
}
}
cpuc->excl_cntrs->core_id = core_id;
cpuc->excl_cntrs->refcnt++;
}
}
static void free_excl_cntrs(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
struct intel_excl_cntrs *c;
c = cpuc->excl_cntrs;
if (c) {
if (c->core_id == -1 || --c->refcnt == 0)
kfree(c);
cpuc->excl_cntrs = NULL;
kfree(cpuc->constraint_list);
cpuc->constraint_list = NULL;
}
}
static void intel_pmu_cpu_dying(int cpu)
{
struct cpu_hw_events *cpuc = &per_cpu(cpu_hw_events, cpu);
struct intel_shared_regs *pc;
pc = cpuc->shared_regs;
if (pc) {
if (pc->core_id == -1 || --pc->refcnt == 0)
kfree(pc);
cpuc->shared_regs = NULL;
}
free_excl_cntrs(cpu);
fini_debug_store_on_cpu(cpu);
}
static __init void intel_clovertown_quirk(void)
{
pr_warn("PEBS disabled due to CPU errata\n");
x86_pmu.pebs = 0;
x86_pmu.pebs_constraints = NULL;
}
static int intel_snb_pebs_broken(int cpu)
{
u32 rev = UINT_MAX;
switch (cpu_data(cpu).x86_model) {
case 42:
rev = 0x28;
break;
case 45:
switch (cpu_data(cpu).x86_mask) {
case 6: rev = 0x618; break;
case 7: rev = 0x70c; break;
}
}
return (cpu_data(cpu).microcode < rev);
}
static void intel_snb_check_microcode(void)
{
int pebs_broken = 0;
int cpu;
get_online_cpus();
for_each_online_cpu(cpu) {
if ((pebs_broken = intel_snb_pebs_broken(cpu)))
break;
}
put_online_cpus();
if (pebs_broken == x86_pmu.pebs_broken)
return;
if (x86_pmu.pebs_broken) {
pr_info("PEBS enabled due to microcode update\n");
x86_pmu.pebs_broken = 0;
} else {
pr_info("PEBS disabled due to CPU errata, please upgrade microcode\n");
x86_pmu.pebs_broken = 1;
}
}
static bool check_msr(unsigned long msr, u64 mask)
{
u64 val_old, val_new, val_tmp;
if (rdmsrl_safe(msr, &val_old))
return false;
val_tmp = val_old ^ mask;
if (wrmsrl_safe(msr, val_tmp) ||
rdmsrl_safe(msr, &val_new))
return false;
if (val_new != val_tmp)
return false;
wrmsrl(msr, val_old);
return true;
}
static __init void intel_sandybridge_quirk(void)
{
x86_pmu.check_microcode = intel_snb_check_microcode;
intel_snb_check_microcode();
}
static __init void intel_arch_events_quirk(void)
{
int bit;
for_each_set_bit(bit, x86_pmu.events_mask, ARRAY_SIZE(intel_arch_events_map)) {
intel_perfmon_event_map[intel_arch_events_map[bit].id] = 0;
pr_warn("CPUID marked event: \'%s\' unavailable\n",
intel_arch_events_map[bit].name);
}
}
static __init void intel_nehalem_quirk(void)
{
union cpuid10_ebx ebx;
ebx.full = x86_pmu.events_maskl;
if (ebx.split.no_branch_misses_retired) {
intel_perfmon_event_map[PERF_COUNT_HW_BRANCH_MISSES] = 0x7f89;
ebx.split.no_branch_misses_retired = 0;
x86_pmu.events_maskl = ebx.full;
pr_info("CPU erratum AAJ80 worked around\n");
}
}
static __init void intel_ht_bug(void)
{
x86_pmu.flags |= PMU_FL_EXCL_CNTRS | PMU_FL_EXCL_ENABLED;
x86_pmu.commit_scheduling = intel_commit_scheduling;
x86_pmu.start_scheduling = intel_start_scheduling;
x86_pmu.stop_scheduling = intel_stop_scheduling;
}
__init int intel_pmu_init(void)
{
union cpuid10_edx edx;
union cpuid10_eax eax;
union cpuid10_ebx ebx;
struct event_constraint *c;
unsigned int unused;
struct extra_reg *er;
int version, i;
if (!cpu_has(&boot_cpu_data, X86_FEATURE_ARCH_PERFMON)) {
switch (boot_cpu_data.x86) {
case 0x6:
return p6_pmu_init();
case 0xb:
return knc_pmu_init();
case 0xf:
return p4_pmu_init();
}
return -ENODEV;
}
cpuid(10, &eax.full, &ebx.full, &unused, &edx.full);
if (eax.split.mask_length < ARCH_PERFMON_EVENTS_COUNT)
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
x86_pmu.events_maskl = ebx.full;
x86_pmu.events_mask_len = eax.split.mask_length;
x86_pmu.max_pebs_events = min_t(unsigned, MAX_PEBS_EVENTS, x86_pmu.num_counters);
if (version > 1)
x86_pmu.num_counters_fixed = max((int)edx.split.num_counters_fixed, 3);
if (boot_cpu_has(X86_FEATURE_PDCM)) {
u64 capabilities;
rdmsrl(MSR_IA32_PERF_CAPABILITIES, capabilities);
x86_pmu.intel_cap.capabilities = capabilities;
}
intel_ds_init();
x86_add_quirk(intel_arch_events_quirk);
switch (boot_cpu_data.x86_model) {
case 14:
pr_cont("Core events, ");
break;
case 15:
x86_add_quirk(intel_clovertown_quirk);
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
case 30:
case 26:
case 46:
memcpy(hw_cache_event_ids, nehalem_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
memcpy(hw_cache_extra_regs, nehalem_hw_cache_extra_regs,
sizeof(hw_cache_extra_regs));
intel_pmu_lbr_init_nhm();
x86_pmu.event_constraints = intel_nehalem_event_constraints;
x86_pmu.pebs_constraints = intel_nehalem_pebs_event_constraints;
x86_pmu.enable_all = intel_pmu_nhm_enable_all;
x86_pmu.extra_regs = intel_nehalem_extra_regs;
x86_pmu.cpu_events = nhm_events_attrs;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_FRONTEND] =
X86_CONFIG(.event=0x0e, .umask=0x01, .inv=1, .cmask=1);
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_BACKEND] =
X86_CONFIG(.event=0xb1, .umask=0x3f, .inv=1, .cmask=1);
x86_add_quirk(intel_nehalem_quirk);
pr_cont("Nehalem events, ");
break;
case 28:
case 38:
case 39:
case 53:
case 54:
memcpy(hw_cache_event_ids, atom_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
intel_pmu_lbr_init_atom();
x86_pmu.event_constraints = intel_gen_event_constraints;
x86_pmu.pebs_constraints = intel_atom_pebs_event_constraints;
pr_cont("Atom events, ");
break;
case 55:
case 76:
case 77:
memcpy(hw_cache_event_ids, slm_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
memcpy(hw_cache_extra_regs, slm_hw_cache_extra_regs,
sizeof(hw_cache_extra_regs));
intel_pmu_lbr_init_atom();
x86_pmu.event_constraints = intel_slm_event_constraints;
x86_pmu.pebs_constraints = intel_slm_pebs_event_constraints;
x86_pmu.extra_regs = intel_slm_extra_regs;
x86_pmu.flags |= PMU_FL_HAS_RSP_1;
pr_cont("Silvermont events, ");
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
x86_pmu.enable_all = intel_pmu_nhm_enable_all;
x86_pmu.pebs_constraints = intel_westmere_pebs_event_constraints;
x86_pmu.extra_regs = intel_westmere_extra_regs;
x86_pmu.flags |= PMU_FL_HAS_RSP_1;
x86_pmu.cpu_events = nhm_events_attrs;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_FRONTEND] =
X86_CONFIG(.event=0x0e, .umask=0x01, .inv=1, .cmask=1);
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_BACKEND] =
X86_CONFIG(.event=0xb1, .umask=0x3f, .inv=1, .cmask=1);
pr_cont("Westmere events, ");
break;
case 42:
case 45:
x86_add_quirk(intel_sandybridge_quirk);
x86_add_quirk(intel_ht_bug);
memcpy(hw_cache_event_ids, snb_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
memcpy(hw_cache_extra_regs, snb_hw_cache_extra_regs,
sizeof(hw_cache_extra_regs));
intel_pmu_lbr_init_snb();
x86_pmu.event_constraints = intel_snb_event_constraints;
x86_pmu.pebs_constraints = intel_snb_pebs_event_constraints;
x86_pmu.pebs_aliases = intel_pebs_aliases_snb;
if (boot_cpu_data.x86_model == 45)
x86_pmu.extra_regs = intel_snbep_extra_regs;
else
x86_pmu.extra_regs = intel_snb_extra_regs;
x86_pmu.flags |= PMU_FL_HAS_RSP_1;
x86_pmu.flags |= PMU_FL_NO_HT_SHARING;
x86_pmu.cpu_events = snb_events_attrs;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_FRONTEND] =
X86_CONFIG(.event=0x0e, .umask=0x01, .inv=1, .cmask=1);
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_BACKEND] =
X86_CONFIG(.event=0xb1, .umask=0x01, .inv=1, .cmask=1);
pr_cont("SandyBridge events, ");
break;
case 58:
case 62:
x86_add_quirk(intel_ht_bug);
memcpy(hw_cache_event_ids, snb_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
hw_cache_event_ids[C(DTLB)][C(OP_READ)][C(RESULT_MISS)] = 0x8108;
memcpy(hw_cache_extra_regs, snb_hw_cache_extra_regs,
sizeof(hw_cache_extra_regs));
intel_pmu_lbr_init_snb();
x86_pmu.event_constraints = intel_ivb_event_constraints;
x86_pmu.pebs_constraints = intel_ivb_pebs_event_constraints;
x86_pmu.pebs_aliases = intel_pebs_aliases_snb;
if (boot_cpu_data.x86_model == 62)
x86_pmu.extra_regs = intel_snbep_extra_regs;
else
x86_pmu.extra_regs = intel_snb_extra_regs;
x86_pmu.flags |= PMU_FL_HAS_RSP_1;
x86_pmu.flags |= PMU_FL_NO_HT_SHARING;
x86_pmu.cpu_events = snb_events_attrs;
intel_perfmon_event_map[PERF_COUNT_HW_STALLED_CYCLES_FRONTEND] =
X86_CONFIG(.event=0x0e, .umask=0x01, .inv=1, .cmask=1);
pr_cont("IvyBridge events, ");
break;
case 60:
case 63:
case 69:
case 70:
x86_add_quirk(intel_ht_bug);
x86_pmu.late_ack = true;
memcpy(hw_cache_event_ids, hsw_hw_cache_event_ids, sizeof(hw_cache_event_ids));
memcpy(hw_cache_extra_regs, hsw_hw_cache_extra_regs, sizeof(hw_cache_extra_regs));
intel_pmu_lbr_init_hsw();
x86_pmu.event_constraints = intel_hsw_event_constraints;
x86_pmu.pebs_constraints = intel_hsw_pebs_event_constraints;
x86_pmu.extra_regs = intel_snbep_extra_regs;
x86_pmu.pebs_aliases = intel_pebs_aliases_snb;
x86_pmu.flags |= PMU_FL_HAS_RSP_1;
x86_pmu.flags |= PMU_FL_NO_HT_SHARING;
x86_pmu.hw_config = hsw_hw_config;
x86_pmu.get_event_constraints = hsw_get_event_constraints;
x86_pmu.cpu_events = hsw_events_attrs;
x86_pmu.lbr_double_abort = true;
pr_cont("Haswell events, ");
break;
case 61:
case 86:
x86_pmu.late_ack = true;
memcpy(hw_cache_event_ids, hsw_hw_cache_event_ids, sizeof(hw_cache_event_ids));
memcpy(hw_cache_extra_regs, hsw_hw_cache_extra_regs, sizeof(hw_cache_extra_regs));
hw_cache_extra_regs[C(LL)][C(OP_READ)][C(RESULT_MISS)] = HSW_DEMAND_READ |
BDW_L3_MISS|HSW_SNOOP_DRAM;
hw_cache_extra_regs[C(LL)][C(OP_WRITE)][C(RESULT_MISS)] = HSW_DEMAND_WRITE|BDW_L3_MISS|
HSW_SNOOP_DRAM;
hw_cache_extra_regs[C(NODE)][C(OP_READ)][C(RESULT_ACCESS)] = HSW_DEMAND_READ|
BDW_L3_MISS_LOCAL|HSW_SNOOP_DRAM;
hw_cache_extra_regs[C(NODE)][C(OP_WRITE)][C(RESULT_ACCESS)] = HSW_DEMAND_WRITE|
BDW_L3_MISS_LOCAL|HSW_SNOOP_DRAM;
intel_pmu_lbr_init_hsw();
x86_pmu.event_constraints = intel_bdw_event_constraints;
x86_pmu.pebs_constraints = intel_hsw_pebs_event_constraints;
x86_pmu.extra_regs = intel_snbep_extra_regs;
x86_pmu.pebs_aliases = intel_pebs_aliases_snb;
x86_pmu.flags |= PMU_FL_HAS_RSP_1;
x86_pmu.flags |= PMU_FL_NO_HT_SHARING;
x86_pmu.hw_config = hsw_hw_config;
x86_pmu.get_event_constraints = hsw_get_event_constraints;
x86_pmu.cpu_events = hsw_events_attrs;
x86_pmu.limit_period = bdw_limit_period;
pr_cont("Broadwell events, ");
break;
default:
switch (x86_pmu.version) {
case 1:
x86_pmu.event_constraints = intel_v1_event_constraints;
pr_cont("generic architected perfmon v1, ");
break;
default:
x86_pmu.event_constraints = intel_gen_event_constraints;
pr_cont("generic architected perfmon, ");
break;
}
}
if (x86_pmu.num_counters > INTEL_PMC_MAX_GENERIC) {
WARN(1, KERN_ERR "hw perf events %d > max(%d), clipping!",
x86_pmu.num_counters, INTEL_PMC_MAX_GENERIC);
x86_pmu.num_counters = INTEL_PMC_MAX_GENERIC;
}
x86_pmu.intel_ctrl = (1 << x86_pmu.num_counters) - 1;
if (x86_pmu.num_counters_fixed > INTEL_PMC_MAX_FIXED) {
WARN(1, KERN_ERR "hw perf events fixed %d > max(%d), clipping!",
x86_pmu.num_counters_fixed, INTEL_PMC_MAX_FIXED);
x86_pmu.num_counters_fixed = INTEL_PMC_MAX_FIXED;
}
x86_pmu.intel_ctrl |=
((1LL << x86_pmu.num_counters_fixed)-1) << INTEL_PMC_IDX_FIXED;
if (x86_pmu.event_constraints) {
for_each_event_constraint(c, x86_pmu.event_constraints) {
if (c->cmask != FIXED_EVENT_FLAGS
|| c->idxmsk64 == INTEL_PMC_MSK_FIXED_REF_CYCLES) {
continue;
}
c->idxmsk64 |= (1ULL << x86_pmu.num_counters) - 1;
c->weight += x86_pmu.num_counters;
}
}
if (x86_pmu.lbr_nr && !check_msr(x86_pmu.lbr_tos, 0x3UL))
x86_pmu.lbr_nr = 0;
for (i = 0; i < x86_pmu.lbr_nr; i++) {
if (!(check_msr(x86_pmu.lbr_from + i, 0xffffUL) &&
check_msr(x86_pmu.lbr_to + i, 0xffffUL)))
x86_pmu.lbr_nr = 0;
}
if (x86_pmu.extra_regs) {
for (er = x86_pmu.extra_regs; er->msr; er++) {
er->extra_msr_access = check_msr(er->msr, 0x1ffUL);
if ((er->idx == EXTRA_REG_LBR) && !er->extra_msr_access)
x86_pmu.lbr_sel_map = NULL;
}
}
if (x86_pmu.intel_cap.full_width_write) {
x86_pmu.max_period = x86_pmu.cntval_mask;
x86_pmu.perfctr = MSR_IA32_PMC0;
pr_cont("full-width counters, ");
}
return 0;
}
static __init int fixup_ht_bug(void)
{
int cpu = smp_processor_id();
int w, c;
if (!(x86_pmu.flags & PMU_FL_EXCL_ENABLED))
return 0;
w = cpumask_weight(topology_thread_cpumask(cpu));
if (w > 1) {
pr_info("PMU erratum BJ122, BV98, HSD29 worked around, HT is on\n");
return 0;
}
watchdog_nmi_disable_all();
x86_pmu.flags &= ~(PMU_FL_EXCL_CNTRS | PMU_FL_EXCL_ENABLED);
x86_pmu.commit_scheduling = NULL;
x86_pmu.start_scheduling = NULL;
x86_pmu.stop_scheduling = NULL;
watchdog_nmi_enable_all();
get_online_cpus();
for_each_online_cpu(c) {
free_excl_cntrs(c);
}
put_online_cpus();
pr_info("PMU erratum BJ122, BV98, HSD29 workaround disabled, HT off\n");
return 0;
}
