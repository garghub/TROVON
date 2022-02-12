static struct p4_event_bind *p4_config_get_bind(u64 config)
{
unsigned int evnt = p4_config_unpack_event(config);
struct p4_event_bind *bind = NULL;
if (evnt < ARRAY_SIZE(p4_event_bind_map))
bind = &p4_event_bind_map[evnt];
return bind;
}
static u64 p4_pmu_event_map(int hw_event)
{
struct p4_event_bind *bind;
unsigned int esel;
u64 config;
config = p4_general_events[hw_event];
bind = p4_config_get_bind(config);
esel = P4_OPCODE_ESEL(bind->opcode);
config |= p4_config_pack_cccr(P4_CCCR_ESEL(esel));
return config;
}
static bool p4_event_match_cpu_model(unsigned int event_idx)
{
if (event_idx == P4_EVENT_INSTR_COMPLETED) {
if (boot_cpu_data.x86_model != 3 &&
boot_cpu_data.x86_model != 4 &&
boot_cpu_data.x86_model != 6)
return false;
}
return true;
}
static int p4_validate_raw_event(struct perf_event *event)
{
unsigned int v, emask;
v = p4_config_unpack_event(event->attr.config);
if (v >= ARRAY_SIZE(p4_event_bind_map))
return -EINVAL;
if (!p4_event_match_cpu_model(v))
return -EINVAL;
if (p4_ht_active() && p4_event_bind_map[v].shared) {
if (perf_paranoid_cpu() && !capable(CAP_SYS_ADMIN))
return -EACCES;
}
emask = p4_config_unpack_escr(event->attr.config) & P4_ESCR_EVENTMASK_MASK;
if (emask & ~p4_event_bind_map[v].escr_emask)
return -EINVAL;
if (p4_config_pebs_has(event->attr.config, P4_PEBS_CONFIG_ENABLE))
return -EINVAL;
v = p4_config_unpack_metric(event->attr.config);
if (v >= ARRAY_SIZE(p4_pebs_bind_map))
return -EINVAL;
return 0;
}
static int p4_hw_config(struct perf_event *event)
{
int cpu = get_cpu();
int rc = 0;
u32 escr, cccr;
cccr = p4_default_cccr_conf(cpu);
escr = p4_default_escr_conf(cpu, event->attr.exclude_kernel,
event->attr.exclude_user);
event->hw.config = p4_config_pack_escr(escr) |
p4_config_pack_cccr(cccr);
if (p4_ht_active() && p4_ht_thread(cpu))
event->hw.config = p4_set_ht_bit(event->hw.config);
if (event->attr.type == PERF_TYPE_RAW) {
struct p4_event_bind *bind;
unsigned int esel;
event->attr.config &= P4_CONFIG_MASK;
rc = p4_validate_raw_event(event);
if (rc)
goto out;
event->hw.config |= event->attr.config;
bind = p4_config_get_bind(event->attr.config);
if (!bind) {
rc = -EINVAL;
goto out;
}
esel = P4_OPCODE_ESEL(bind->opcode);
event->hw.config |= p4_config_pack_cccr(P4_CCCR_ESEL(esel));
}
rc = x86_setup_perfctr(event);
out:
put_cpu();
return rc;
}
static inline int p4_pmu_clear_cccr_ovf(struct hw_perf_event *hwc)
{
u64 v;
rdmsrl(hwc->config_base, v);
if (v & P4_CCCR_OVF) {
wrmsrl(hwc->config_base, v & ~P4_CCCR_OVF);
return 1;
}
rdmsrl(hwc->event_base, v);
if (!(v & ARCH_P4_UNFLAGGED_BIT))
return 1;
return 0;
}
static void p4_pmu_disable_pebs(void)
{
}
static inline void p4_pmu_disable_event(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
(void)checking_wrmsrl(hwc->config_base,
(u64)(p4_config_unpack_cccr(hwc->config)) &
~P4_CCCR_ENABLE & ~P4_CCCR_OVF & ~P4_CCCR_RESERVED);
}
static void p4_pmu_disable_all(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
int idx;
for (idx = 0; idx < x86_pmu.num_counters; idx++) {
struct perf_event *event = cpuc->events[idx];
if (!test_bit(idx, cpuc->active_mask))
continue;
p4_pmu_disable_event(event);
}
p4_pmu_disable_pebs();
}
static void p4_pmu_enable_pebs(u64 config)
{
struct p4_pebs_bind *bind;
unsigned int idx;
BUILD_BUG_ON(P4_PEBS_METRIC__max > P4_PEBS_CONFIG_METRIC_MASK);
idx = p4_config_unpack_metric(config);
if (idx == P4_PEBS_METRIC__none)
return;
bind = &p4_pebs_bind_map[idx];
(void)checking_wrmsrl(MSR_IA32_PEBS_ENABLE, (u64)bind->metric_pebs);
(void)checking_wrmsrl(MSR_P4_PEBS_MATRIX_VERT, (u64)bind->metric_vert);
}
static void p4_pmu_enable_event(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
int thread = p4_ht_config_thread(hwc->config);
u64 escr_conf = p4_config_unpack_escr(p4_clear_ht_bit(hwc->config));
unsigned int idx = p4_config_unpack_event(hwc->config);
struct p4_event_bind *bind;
u64 escr_addr, cccr;
bind = &p4_event_bind_map[idx];
escr_addr = (u64)bind->escr_msr[thread];
WARN_ON_ONCE(p4_is_event_cascaded(hwc->config));
WARN_ON_ONCE(hwc->idx == 1);
escr_conf &= ~P4_ESCR_EVENT_MASK;
escr_conf |= P4_ESCR_EVENT(P4_OPCODE_EVNT(bind->opcode));
cccr = p4_config_unpack_cccr(hwc->config);
p4_pmu_enable_pebs(hwc->config);
(void)checking_wrmsrl(escr_addr, escr_conf);
(void)checking_wrmsrl(hwc->config_base,
(cccr & ~P4_CCCR_RESERVED) | P4_CCCR_ENABLE);
}
static void p4_pmu_enable_all(int added)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
int idx;
for (idx = 0; idx < x86_pmu.num_counters; idx++) {
struct perf_event *event = cpuc->events[idx];
if (!test_bit(idx, cpuc->active_mask))
continue;
p4_pmu_enable_event(event);
}
}
static int p4_pmu_handle_irq(struct pt_regs *regs)
{
struct perf_sample_data data;
struct cpu_hw_events *cpuc;
struct perf_event *event;
struct hw_perf_event *hwc;
int idx, handled = 0;
u64 val;
perf_sample_data_init(&data, 0);
cpuc = &__get_cpu_var(cpu_hw_events);
for (idx = 0; idx < x86_pmu.num_counters; idx++) {
int overflow;
if (!test_bit(idx, cpuc->active_mask)) {
if (__test_and_clear_bit(idx, cpuc->running))
handled++;
continue;
}
event = cpuc->events[idx];
hwc = &event->hw;
WARN_ON_ONCE(hwc->idx != idx);
overflow = p4_pmu_clear_cccr_ovf(hwc);
val = x86_perf_event_update(event);
if (!overflow && (val & (1ULL << (x86_pmu.cntval_bits - 1))))
continue;
handled += overflow;
data.period = event->hw.last_period;
if (!x86_perf_event_set_period(event))
continue;
if (perf_event_overflow(event, 1, &data, regs))
x86_pmu_stop(event, 0);
}
if (handled)
inc_irq_stat(apic_perf_irqs);
apic_write(APIC_LVTPC, APIC_DM_NMI);
return handled;
}
static void p4_pmu_swap_config_ts(struct hw_perf_event *hwc, int cpu)
{
u32 escr, cccr;
if (!p4_should_swap_ts(hwc->config, cpu))
return;
escr = p4_config_unpack_escr(hwc->config);
cccr = p4_config_unpack_cccr(hwc->config);
if (p4_ht_thread(cpu)) {
cccr &= ~P4_CCCR_OVF_PMI_T0;
cccr |= P4_CCCR_OVF_PMI_T1;
if (escr & P4_ESCR_T0_OS) {
escr &= ~P4_ESCR_T0_OS;
escr |= P4_ESCR_T1_OS;
}
if (escr & P4_ESCR_T0_USR) {
escr &= ~P4_ESCR_T0_USR;
escr |= P4_ESCR_T1_USR;
}
hwc->config = p4_config_pack_escr(escr);
hwc->config |= p4_config_pack_cccr(cccr);
hwc->config |= P4_CONFIG_HT;
} else {
cccr &= ~P4_CCCR_OVF_PMI_T1;
cccr |= P4_CCCR_OVF_PMI_T0;
if (escr & P4_ESCR_T1_OS) {
escr &= ~P4_ESCR_T1_OS;
escr |= P4_ESCR_T0_OS;
}
if (escr & P4_ESCR_T1_USR) {
escr &= ~P4_ESCR_T1_USR;
escr |= P4_ESCR_T0_USR;
}
hwc->config = p4_config_pack_escr(escr);
hwc->config |= p4_config_pack_cccr(cccr);
hwc->config &= ~P4_CONFIG_HT;
}
}
static int p4_get_escr_idx(unsigned int addr)
{
unsigned int idx = P4_ESCR_MSR_IDX(addr);
if (unlikely(idx >= P4_ESCR_MSR_TABLE_SIZE ||
!p4_escr_table[idx] ||
p4_escr_table[idx] != addr)) {
WARN_ONCE(1, "P4 PMU: Wrong address passed: %x\n", addr);
return -1;
}
return idx;
}
static int p4_next_cntr(int thread, unsigned long *used_mask,
struct p4_event_bind *bind)
{
int i, j;
for (i = 0; i < P4_CNTR_LIMIT; i++) {
j = bind->cntr[thread][i];
if (j != -1 && !test_bit(j, used_mask))
return j;
}
return -1;
}
static int p4_pmu_schedule_events(struct cpu_hw_events *cpuc, int n, int *assign)
{
unsigned long used_mask[BITS_TO_LONGS(X86_PMC_IDX_MAX)];
unsigned long escr_mask[BITS_TO_LONGS(P4_ESCR_MSR_TABLE_SIZE)];
int cpu = smp_processor_id();
struct hw_perf_event *hwc;
struct p4_event_bind *bind;
unsigned int i, thread, num;
int cntr_idx, escr_idx;
bitmap_zero(used_mask, X86_PMC_IDX_MAX);
bitmap_zero(escr_mask, P4_ESCR_MSR_TABLE_SIZE);
for (i = 0, num = n; i < n; i++, num--) {
hwc = &cpuc->event_list[i]->hw;
thread = p4_ht_thread(cpu);
bind = p4_config_get_bind(hwc->config);
escr_idx = p4_get_escr_idx(bind->escr_msr[thread]);
if (unlikely(escr_idx == -1))
goto done;
if (hwc->idx != -1 && !p4_should_swap_ts(hwc->config, cpu)) {
cntr_idx = hwc->idx;
if (assign)
assign[i] = hwc->idx;
goto reserve;
}
cntr_idx = p4_next_cntr(thread, used_mask, bind);
if (cntr_idx == -1 || test_bit(escr_idx, escr_mask))
goto done;
p4_pmu_swap_config_ts(hwc, cpu);
if (assign)
assign[i] = cntr_idx;
reserve:
set_bit(cntr_idx, used_mask);
set_bit(escr_idx, escr_mask);
}
done:
return num ? -ENOSPC : 0;
}
static __init int p4_pmu_init(void)
{
unsigned int low, high;
BUILD_BUG_ON(ARCH_P4_MAX_CCCR > X86_PMC_MAX_GENERIC);
rdmsr(MSR_IA32_MISC_ENABLE, low, high);
if (!(low & (1 << 7))) {
pr_cont("unsupported Netburst CPU model %d ",
boot_cpu_data.x86_model);
return -ENODEV;
}
memcpy(hw_cache_event_ids, p4_hw_cache_event_ids,
sizeof(hw_cache_event_ids));
pr_cont("Netburst events, ");
x86_pmu = p4_pmu;
return 0;
}
