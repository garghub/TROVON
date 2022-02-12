static void init_debug_store_on_cpu(int cpu)
{
struct debug_store *ds = per_cpu(cpu_hw_events, cpu).ds;
if (!ds)
return;
wrmsr_on_cpu(cpu, MSR_IA32_DS_AREA,
(u32)((u64)(unsigned long)ds),
(u32)((u64)(unsigned long)ds >> 32));
}
static void fini_debug_store_on_cpu(int cpu)
{
if (!per_cpu(cpu_hw_events, cpu).ds)
return;
wrmsr_on_cpu(cpu, MSR_IA32_DS_AREA, 0, 0);
}
static int alloc_pebs_buffer(int cpu)
{
struct debug_store *ds = per_cpu(cpu_hw_events, cpu).ds;
int node = cpu_to_node(cpu);
int max, thresh = 1;
void *buffer;
if (!x86_pmu.pebs)
return 0;
buffer = kmalloc_node(PEBS_BUFFER_SIZE, GFP_KERNEL | __GFP_ZERO, node);
if (unlikely(!buffer))
return -ENOMEM;
max = PEBS_BUFFER_SIZE / x86_pmu.pebs_record_size;
ds->pebs_buffer_base = (u64)(unsigned long)buffer;
ds->pebs_index = ds->pebs_buffer_base;
ds->pebs_absolute_maximum = ds->pebs_buffer_base +
max * x86_pmu.pebs_record_size;
ds->pebs_interrupt_threshold = ds->pebs_buffer_base +
thresh * x86_pmu.pebs_record_size;
return 0;
}
static void release_pebs_buffer(int cpu)
{
struct debug_store *ds = per_cpu(cpu_hw_events, cpu).ds;
if (!ds || !x86_pmu.pebs)
return;
kfree((void *)(unsigned long)ds->pebs_buffer_base);
ds->pebs_buffer_base = 0;
}
static int alloc_bts_buffer(int cpu)
{
struct debug_store *ds = per_cpu(cpu_hw_events, cpu).ds;
int node = cpu_to_node(cpu);
int max, thresh;
void *buffer;
if (!x86_pmu.bts)
return 0;
buffer = kmalloc_node(BTS_BUFFER_SIZE, GFP_KERNEL | __GFP_ZERO, node);
if (unlikely(!buffer))
return -ENOMEM;
max = BTS_BUFFER_SIZE / BTS_RECORD_SIZE;
thresh = max / 16;
ds->bts_buffer_base = (u64)(unsigned long)buffer;
ds->bts_index = ds->bts_buffer_base;
ds->bts_absolute_maximum = ds->bts_buffer_base +
max * BTS_RECORD_SIZE;
ds->bts_interrupt_threshold = ds->bts_absolute_maximum -
thresh * BTS_RECORD_SIZE;
return 0;
}
static void release_bts_buffer(int cpu)
{
struct debug_store *ds = per_cpu(cpu_hw_events, cpu).ds;
if (!ds || !x86_pmu.bts)
return;
kfree((void *)(unsigned long)ds->bts_buffer_base);
ds->bts_buffer_base = 0;
}
static int alloc_ds_buffer(int cpu)
{
int node = cpu_to_node(cpu);
struct debug_store *ds;
ds = kmalloc_node(sizeof(*ds), GFP_KERNEL | __GFP_ZERO, node);
if (unlikely(!ds))
return -ENOMEM;
per_cpu(cpu_hw_events, cpu).ds = ds;
return 0;
}
static void release_ds_buffer(int cpu)
{
struct debug_store *ds = per_cpu(cpu_hw_events, cpu).ds;
if (!ds)
return;
per_cpu(cpu_hw_events, cpu).ds = NULL;
kfree(ds);
}
static void release_ds_buffers(void)
{
int cpu;
if (!x86_pmu.bts && !x86_pmu.pebs)
return;
get_online_cpus();
for_each_online_cpu(cpu)
fini_debug_store_on_cpu(cpu);
for_each_possible_cpu(cpu) {
release_pebs_buffer(cpu);
release_bts_buffer(cpu);
release_ds_buffer(cpu);
}
put_online_cpus();
}
static void reserve_ds_buffers(void)
{
int bts_err = 0, pebs_err = 0;
int cpu;
x86_pmu.bts_active = 0;
x86_pmu.pebs_active = 0;
if (!x86_pmu.bts && !x86_pmu.pebs)
return;
if (!x86_pmu.bts)
bts_err = 1;
if (!x86_pmu.pebs)
pebs_err = 1;
get_online_cpus();
for_each_possible_cpu(cpu) {
if (alloc_ds_buffer(cpu)) {
bts_err = 1;
pebs_err = 1;
}
if (!bts_err && alloc_bts_buffer(cpu))
bts_err = 1;
if (!pebs_err && alloc_pebs_buffer(cpu))
pebs_err = 1;
if (bts_err && pebs_err)
break;
}
if (bts_err) {
for_each_possible_cpu(cpu)
release_bts_buffer(cpu);
}
if (pebs_err) {
for_each_possible_cpu(cpu)
release_pebs_buffer(cpu);
}
if (bts_err && pebs_err) {
for_each_possible_cpu(cpu)
release_ds_buffer(cpu);
} else {
if (x86_pmu.bts && !bts_err)
x86_pmu.bts_active = 1;
if (x86_pmu.pebs && !pebs_err)
x86_pmu.pebs_active = 1;
for_each_online_cpu(cpu)
init_debug_store_on_cpu(cpu);
}
put_online_cpus();
}
static void intel_pmu_enable_bts(u64 config)
{
unsigned long debugctlmsr;
debugctlmsr = get_debugctlmsr();
debugctlmsr |= DEBUGCTLMSR_TR;
debugctlmsr |= DEBUGCTLMSR_BTS;
debugctlmsr |= DEBUGCTLMSR_BTINT;
if (!(config & ARCH_PERFMON_EVENTSEL_OS))
debugctlmsr |= DEBUGCTLMSR_BTS_OFF_OS;
if (!(config & ARCH_PERFMON_EVENTSEL_USR))
debugctlmsr |= DEBUGCTLMSR_BTS_OFF_USR;
update_debugctlmsr(debugctlmsr);
}
static void intel_pmu_disable_bts(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
unsigned long debugctlmsr;
if (!cpuc->ds)
return;
debugctlmsr = get_debugctlmsr();
debugctlmsr &=
~(DEBUGCTLMSR_TR | DEBUGCTLMSR_BTS | DEBUGCTLMSR_BTINT |
DEBUGCTLMSR_BTS_OFF_OS | DEBUGCTLMSR_BTS_OFF_USR);
update_debugctlmsr(debugctlmsr);
}
static int intel_pmu_drain_bts_buffer(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
struct debug_store *ds = cpuc->ds;
struct bts_record {
u64 from;
u64 to;
u64 flags;
};
struct perf_event *event = cpuc->events[X86_PMC_IDX_FIXED_BTS];
struct bts_record *at, *top;
struct perf_output_handle handle;
struct perf_event_header header;
struct perf_sample_data data;
struct pt_regs regs;
if (!event)
return 0;
if (!x86_pmu.bts_active)
return 0;
at = (struct bts_record *)(unsigned long)ds->bts_buffer_base;
top = (struct bts_record *)(unsigned long)ds->bts_index;
if (top <= at)
return 0;
ds->bts_index = ds->bts_buffer_base;
perf_sample_data_init(&data, 0);
data.period = event->hw.last_period;
regs.ip = 0;
perf_prepare_sample(&header, &data, event, &regs);
if (perf_output_begin(&handle, event, header.size * (top - at)))
return 1;
for (; at < top; at++) {
data.ip = at->from;
data.addr = at->to;
perf_output_sample(&handle, &header, &data, event);
}
perf_output_end(&handle);
event->hw.interrupts++;
event->pending_kill = POLL_IN;
return 1;
}
static struct event_constraint *
intel_pebs_constraints(struct perf_event *event)
{
struct event_constraint *c;
if (!event->attr.precise_ip)
return NULL;
if (x86_pmu.pebs_constraints) {
for_each_event_constraint(c, x86_pmu.pebs_constraints) {
if ((event->hw.config & c->cmask) == c->code)
return c;
}
}
return &emptyconstraint;
}
static void intel_pmu_pebs_enable(struct perf_event *event)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
hwc->config &= ~ARCH_PERFMON_EVENTSEL_INT;
cpuc->pebs_enabled |= 1ULL << hwc->idx;
WARN_ON_ONCE(cpuc->enabled);
if (x86_pmu.intel_cap.pebs_trap && event->attr.precise_ip > 1)
intel_pmu_lbr_enable(event);
}
static void intel_pmu_pebs_disable(struct perf_event *event)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
struct hw_perf_event *hwc = &event->hw;
cpuc->pebs_enabled &= ~(1ULL << hwc->idx);
if (cpuc->enabled)
wrmsrl(MSR_IA32_PEBS_ENABLE, cpuc->pebs_enabled);
hwc->config |= ARCH_PERFMON_EVENTSEL_INT;
if (x86_pmu.intel_cap.pebs_trap && event->attr.precise_ip > 1)
intel_pmu_lbr_disable(event);
}
static void intel_pmu_pebs_enable_all(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
if (cpuc->pebs_enabled)
wrmsrl(MSR_IA32_PEBS_ENABLE, cpuc->pebs_enabled);
}
static void intel_pmu_pebs_disable_all(void)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
if (cpuc->pebs_enabled)
wrmsrl(MSR_IA32_PEBS_ENABLE, 0);
}
static inline bool kernel_ip(unsigned long ip)
{
#ifdef CONFIG_X86_32
return ip > PAGE_OFFSET;
#else
return (long)ip < 0;
#endif
}
static int intel_pmu_pebs_fixup_ip(struct pt_regs *regs)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
unsigned long from = cpuc->lbr_entries[0].from;
unsigned long old_to, to = cpuc->lbr_entries[0].to;
unsigned long ip = regs->ip;
if (!x86_pmu.intel_cap.pebs_trap)
return 1;
if (!cpuc->lbr_stack.nr || !from || !to)
return 0;
if (kernel_ip(ip) != kernel_ip(to))
return 0;
if ((ip - to) > PAGE_SIZE)
return 0;
if (ip == to) {
regs->ip = from;
return 1;
}
do {
struct insn insn;
u8 buf[MAX_INSN_SIZE];
void *kaddr;
old_to = to;
if (!kernel_ip(ip)) {
int bytes, size = MAX_INSN_SIZE;
bytes = copy_from_user_nmi(buf, (void __user *)to, size);
if (bytes != size)
return 0;
kaddr = buf;
} else
kaddr = (void *)to;
kernel_insn_init(&insn, kaddr);
insn_get_length(&insn);
to += insn.length;
} while (to < ip);
if (to == ip) {
regs->ip = old_to;
return 1;
}
return 0;
}
static void __intel_pmu_pebs_event(struct perf_event *event,
struct pt_regs *iregs, void *__pebs)
{
struct pebs_record_core *pebs = __pebs;
struct perf_sample_data data;
struct pt_regs regs;
if (!intel_pmu_save_and_restart(event))
return;
perf_sample_data_init(&data, 0);
data.period = event->hw.last_period;
regs = *iregs;
regs.ip = pebs->ip;
regs.bp = pebs->bp;
regs.sp = pebs->sp;
if (event->attr.precise_ip > 1 && intel_pmu_pebs_fixup_ip(&regs))
regs.flags |= PERF_EFLAGS_EXACT;
else
regs.flags &= ~PERF_EFLAGS_EXACT;
if (perf_event_overflow(event, &data, &regs))
x86_pmu_stop(event, 0);
}
static void intel_pmu_drain_pebs_core(struct pt_regs *iregs)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
struct debug_store *ds = cpuc->ds;
struct perf_event *event = cpuc->events[0];
struct pebs_record_core *at, *top;
int n;
if (!x86_pmu.pebs_active)
return;
at = (struct pebs_record_core *)(unsigned long)ds->pebs_buffer_base;
top = (struct pebs_record_core *)(unsigned long)ds->pebs_index;
ds->pebs_index = ds->pebs_buffer_base;
if (!test_bit(0, cpuc->active_mask))
return;
WARN_ON_ONCE(!event);
if (!event->attr.precise_ip)
return;
n = top - at;
if (n <= 0)
return;
WARN_ON_ONCE(n > 1);
at += n - 1;
__intel_pmu_pebs_event(event, iregs, at);
}
static void intel_pmu_drain_pebs_nhm(struct pt_regs *iregs)
{
struct cpu_hw_events *cpuc = &__get_cpu_var(cpu_hw_events);
struct debug_store *ds = cpuc->ds;
struct pebs_record_nhm *at, *top;
struct perf_event *event = NULL;
u64 status = 0;
int bit, n;
if (!x86_pmu.pebs_active)
return;
at = (struct pebs_record_nhm *)(unsigned long)ds->pebs_buffer_base;
top = (struct pebs_record_nhm *)(unsigned long)ds->pebs_index;
ds->pebs_index = ds->pebs_buffer_base;
n = top - at;
if (n <= 0)
return;
WARN_ON_ONCE(n > MAX_PEBS_EVENTS);
for ( ; at < top; at++) {
for_each_set_bit(bit, (unsigned long *)&at->status, MAX_PEBS_EVENTS) {
event = cpuc->events[bit];
if (!test_bit(bit, cpuc->active_mask))
continue;
WARN_ON_ONCE(!event);
if (!event->attr.precise_ip)
continue;
if (__test_and_set_bit(bit, (unsigned long *)&status))
continue;
break;
}
if (!event || bit >= MAX_PEBS_EVENTS)
continue;
__intel_pmu_pebs_event(event, iregs, at);
}
}
static void intel_ds_init(void)
{
if (!boot_cpu_has(X86_FEATURE_DTES64))
return;
x86_pmu.bts = boot_cpu_has(X86_FEATURE_BTS);
x86_pmu.pebs = boot_cpu_has(X86_FEATURE_PEBS);
if (x86_pmu.pebs) {
char pebs_type = x86_pmu.intel_cap.pebs_trap ? '+' : '-';
int format = x86_pmu.intel_cap.pebs_format;
switch (format) {
case 0:
printk(KERN_CONT "PEBS fmt0%c, ", pebs_type);
x86_pmu.pebs_record_size = sizeof(struct pebs_record_core);
x86_pmu.drain_pebs = intel_pmu_drain_pebs_core;
break;
case 1:
printk(KERN_CONT "PEBS fmt1%c, ", pebs_type);
x86_pmu.pebs_record_size = sizeof(struct pebs_record_nhm);
x86_pmu.drain_pebs = intel_pmu_drain_pebs_nhm;
break;
default:
printk(KERN_CONT "no PEBS fmt%d%c, ", format, pebs_type);
x86_pmu.pebs = 0;
}
}
}
static void reserve_ds_buffers(void)
{
}
static void release_ds_buffers(void)
{
}
