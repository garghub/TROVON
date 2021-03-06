static int
perf_event_set_period(struct hw_perf_event *hwc, u64 min, u64 max, u64 *hw_period)
{
s64 left = local64_read(&hwc->period_left);
s64 period = hwc->sample_period;
int overflow = 0;
if (unlikely(left <= -period)) {
left = period;
local64_set(&hwc->period_left, left);
hwc->last_period = period;
overflow = 1;
}
if (unlikely(left < (s64)min)) {
left += period;
local64_set(&hwc->period_left, left);
hwc->last_period = period;
overflow = 1;
}
if (left > max) {
left -= max;
if (left > max)
left = max;
else if (left < min)
left = min;
}
*hw_period = (u64)left;
return overflow;
}
static int
perf_event_try_update(struct perf_event *event, u64 new_raw_count, int width)
{
struct hw_perf_event *hwc = &event->hw;
int shift = 64 - width;
u64 prev_raw_count;
u64 delta;
prev_raw_count = local64_read(&hwc->prev_count);
if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count)
return 0;
delta = (new_raw_count << shift) - (prev_raw_count << shift);
delta >>= shift;
local64_add(delta, &event->count);
local64_sub(delta, &hwc->period_left);
return 1;
}
static struct perf_ibs *get_ibs_pmu(int type)
{
if (perf_ibs_fetch.pmu.type == type)
return &perf_ibs_fetch;
if (perf_ibs_op.pmu.type == type)
return &perf_ibs_op;
return NULL;
}
static int perf_ibs_precise_event(struct perf_event *event, u64 *config)
{
switch (event->attr.precise_ip) {
case 0:
return -ENOENT;
case 1:
case 2:
break;
default:
return -EOPNOTSUPP;
}
switch (event->attr.type) {
case PERF_TYPE_HARDWARE:
switch (event->attr.config) {
case PERF_COUNT_HW_CPU_CYCLES:
*config = 0;
return 0;
}
break;
case PERF_TYPE_RAW:
switch (event->attr.config) {
case 0x0076:
*config = 0;
return 0;
case 0x00C1:
*config = IBS_OP_CNT_CTL;
return 0;
}
break;
default:
return -ENOENT;
}
return -EOPNOTSUPP;
}
static int perf_ibs_init(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct perf_ibs *perf_ibs;
u64 max_cnt, config;
int ret;
perf_ibs = get_ibs_pmu(event->attr.type);
if (perf_ibs) {
config = event->attr.config;
} else {
perf_ibs = &perf_ibs_op;
ret = perf_ibs_precise_event(event, &config);
if (ret)
return ret;
}
if (event->pmu != &perf_ibs->pmu)
return -ENOENT;
if (perf_flags(&event->attr) & perf_flags(&ibs_notsupp))
return -EINVAL;
if (config & ~perf_ibs->config_mask)
return -EINVAL;
if (hwc->sample_period) {
if (config & perf_ibs->cnt_mask)
return -EINVAL;
if (!event->attr.sample_freq && hwc->sample_period & 0x0f)
return -EINVAL;
hwc->sample_period &= ~0x0FULL;
if (!hwc->sample_period)
hwc->sample_period = 0x10;
} else {
max_cnt = config & perf_ibs->cnt_mask;
config &= ~perf_ibs->cnt_mask;
event->attr.sample_period = max_cnt << 4;
hwc->sample_period = event->attr.sample_period;
}
if (!hwc->sample_period)
return -EINVAL;
hwc->last_period = hwc->sample_period;
local64_set(&hwc->period_left, hwc->sample_period);
hwc->config_base = perf_ibs->msr;
hwc->config = config;
return 0;
}
static int perf_ibs_set_period(struct perf_ibs *perf_ibs,
struct hw_perf_event *hwc, u64 *period)
{
int overflow;
overflow = perf_event_set_period(hwc, 1<<4, perf_ibs->max_period, period);
local64_set(&hwc->prev_count, 0);
return overflow;
}
static u64 get_ibs_fetch_count(u64 config)
{
return (config & IBS_FETCH_CNT) >> 12;
}
static u64 get_ibs_op_count(u64 config)
{
u64 count = 0;
if (config & IBS_OP_VAL)
count += (config & IBS_OP_MAX_CNT) << 4;
if (ibs_caps & IBS_CAPS_RDWROPCNT)
count += (config & IBS_OP_CUR_CNT) >> 32;
return count;
}
static void
perf_ibs_event_update(struct perf_ibs *perf_ibs, struct perf_event *event,
u64 *config)
{
u64 count = perf_ibs->get_count(*config);
while (!perf_event_try_update(event, count, 64)) {
rdmsrl(event->hw.config_base, *config);
count = perf_ibs->get_count(*config);
}
}
static inline void perf_ibs_enable_event(struct perf_ibs *perf_ibs,
struct hw_perf_event *hwc, u64 config)
{
wrmsrl(hwc->config_base, hwc->config | config | perf_ibs->enable_mask);
}
static inline void perf_ibs_disable_event(struct perf_ibs *perf_ibs,
struct hw_perf_event *hwc, u64 config)
{
config &= ~perf_ibs->cnt_mask;
wrmsrl(hwc->config_base, config);
config &= ~perf_ibs->enable_mask;
wrmsrl(hwc->config_base, config);
}
static void perf_ibs_start(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
struct perf_ibs *perf_ibs = container_of(event->pmu, struct perf_ibs, pmu);
struct cpu_perf_ibs *pcpu = this_cpu_ptr(perf_ibs->pcpu);
u64 period;
if (WARN_ON_ONCE(!(hwc->state & PERF_HES_STOPPED)))
return;
WARN_ON_ONCE(!(hwc->state & PERF_HES_UPTODATE));
hwc->state = 0;
perf_ibs_set_period(perf_ibs, hwc, &period);
set_bit(IBS_STARTED, pcpu->state);
perf_ibs_enable_event(perf_ibs, hwc, period >> 4);
perf_event_update_userpage(event);
}
static void perf_ibs_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
struct perf_ibs *perf_ibs = container_of(event->pmu, struct perf_ibs, pmu);
struct cpu_perf_ibs *pcpu = this_cpu_ptr(perf_ibs->pcpu);
u64 config;
int stopping;
stopping = test_and_clear_bit(IBS_STARTED, pcpu->state);
if (!stopping && (hwc->state & PERF_HES_UPTODATE))
return;
rdmsrl(hwc->config_base, config);
if (stopping) {
set_bit(IBS_STOPPING, pcpu->state);
perf_ibs_disable_event(perf_ibs, hwc, config);
WARN_ON_ONCE(hwc->state & PERF_HES_STOPPED);
hwc->state |= PERF_HES_STOPPED;
}
if (hwc->state & PERF_HES_UPTODATE)
return;
config &= ~perf_ibs->valid_mask;
perf_ibs_event_update(perf_ibs, event, &config);
hwc->state |= PERF_HES_UPTODATE;
}
static int perf_ibs_add(struct perf_event *event, int flags)
{
struct perf_ibs *perf_ibs = container_of(event->pmu, struct perf_ibs, pmu);
struct cpu_perf_ibs *pcpu = this_cpu_ptr(perf_ibs->pcpu);
if (test_and_set_bit(IBS_ENABLED, pcpu->state))
return -ENOSPC;
event->hw.state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
pcpu->event = event;
if (flags & PERF_EF_START)
perf_ibs_start(event, PERF_EF_RELOAD);
return 0;
}
static void perf_ibs_del(struct perf_event *event, int flags)
{
struct perf_ibs *perf_ibs = container_of(event->pmu, struct perf_ibs, pmu);
struct cpu_perf_ibs *pcpu = this_cpu_ptr(perf_ibs->pcpu);
if (!test_and_clear_bit(IBS_ENABLED, pcpu->state))
return;
perf_ibs_stop(event, PERF_EF_UPDATE);
pcpu->event = NULL;
perf_event_update_userpage(event);
}
static void perf_ibs_read(struct perf_event *event) { }
static int perf_ibs_handle_irq(struct perf_ibs *perf_ibs, struct pt_regs *iregs)
{
struct cpu_perf_ibs *pcpu = this_cpu_ptr(perf_ibs->pcpu);
struct perf_event *event = pcpu->event;
struct hw_perf_event *hwc = &event->hw;
struct perf_sample_data data;
struct perf_raw_record raw;
struct pt_regs regs;
struct perf_ibs_data ibs_data;
int offset, size, check_rip, offset_max, throttle = 0;
unsigned int msr;
u64 *buf, *config, period;
if (!test_bit(IBS_STARTED, pcpu->state)) {
return test_and_clear_bit(IBS_STOPPING, pcpu->state) ? 1 : 0;
}
msr = hwc->config_base;
buf = ibs_data.regs;
rdmsrl(msr, *buf);
if (!(*buf++ & perf_ibs->valid_mask))
return 0;
config = &ibs_data.regs[0];
perf_ibs_event_update(perf_ibs, event, config);
perf_sample_data_init(&data, 0, hwc->last_period);
if (!perf_ibs_set_period(perf_ibs, hwc, &period))
goto out;
ibs_data.caps = ibs_caps;
size = 1;
offset = 1;
check_rip = (perf_ibs == &perf_ibs_op && (ibs_caps & IBS_CAPS_RIPINVALIDCHK));
if (event->attr.sample_type & PERF_SAMPLE_RAW)
offset_max = perf_ibs->offset_max;
else if (check_rip)
offset_max = 2;
else
offset_max = 1;
do {
rdmsrl(msr + offset, *buf++);
size++;
offset = find_next_bit(perf_ibs->offset_mask,
perf_ibs->offset_max,
offset + 1);
} while (offset < offset_max);
ibs_data.size = sizeof(u64) * size;
regs = *iregs;
if (check_rip && (ibs_data.regs[2] & IBS_RIP_INVALID)) {
regs.flags &= ~PERF_EFLAGS_EXACT;
} else {
set_linear_ip(&regs, ibs_data.regs[1]);
regs.flags |= PERF_EFLAGS_EXACT;
}
if (event->attr.sample_type & PERF_SAMPLE_RAW) {
raw.size = sizeof(u32) + ibs_data.size;
raw.data = ibs_data.data;
data.raw = &raw;
}
throttle = perf_event_overflow(event, &data, &regs);
out:
if (throttle)
perf_ibs_disable_event(perf_ibs, hwc, *config);
else
perf_ibs_enable_event(perf_ibs, hwc, period >> 4);
perf_event_update_userpage(event);
return 1;
}
static int __kprobes
perf_ibs_nmi_handler(unsigned int cmd, struct pt_regs *regs)
{
int handled = 0;
handled += perf_ibs_handle_irq(&perf_ibs_fetch, regs);
handled += perf_ibs_handle_irq(&perf_ibs_op, regs);
if (handled)
inc_irq_stat(apic_perf_irqs);
return handled;
}
static __init int perf_ibs_pmu_init(struct perf_ibs *perf_ibs, char *name)
{
struct cpu_perf_ibs __percpu *pcpu;
int ret;
pcpu = alloc_percpu(struct cpu_perf_ibs);
if (!pcpu)
return -ENOMEM;
perf_ibs->pcpu = pcpu;
if (perf_ibs->format_attrs[0]) {
memset(&perf_ibs->format_group, 0, sizeof(perf_ibs->format_group));
perf_ibs->format_group.name = "format";
perf_ibs->format_group.attrs = perf_ibs->format_attrs;
memset(&perf_ibs->attr_groups, 0, sizeof(perf_ibs->attr_groups));
perf_ibs->attr_groups[0] = &perf_ibs->format_group;
perf_ibs->pmu.attr_groups = perf_ibs->attr_groups;
}
ret = perf_pmu_register(&perf_ibs->pmu, name, -1);
if (ret) {
perf_ibs->pcpu = NULL;
free_percpu(pcpu);
}
return ret;
}
static __init int perf_event_ibs_init(void)
{
struct attribute **attr = ibs_op_format_attrs;
if (!ibs_caps)
return -ENODEV;
perf_ibs_pmu_init(&perf_ibs_fetch, "ibs_fetch");
if (ibs_caps & IBS_CAPS_OPCNT) {
perf_ibs_op.config_mask |= IBS_OP_CNT_CTL;
*attr++ = &format_attr_cnt_ctl.attr;
}
perf_ibs_pmu_init(&perf_ibs_op, "ibs_op");
register_nmi_handler(NMI_LOCAL, perf_ibs_nmi_handler, 0, "perf_ibs");
printk(KERN_INFO "perf: AMD IBS detected (0x%08x)\n", ibs_caps);
return 0;
}
static __init int perf_event_ibs_init(void) { return 0; }
static __init u32 __get_ibs_caps(void)
{
u32 caps;
unsigned int max_level;
if (!boot_cpu_has(X86_FEATURE_IBS))
return 0;
max_level = cpuid_eax(0x80000000);
if (max_level < IBS_CPUID_FEATURES)
return IBS_CAPS_DEFAULT;
caps = cpuid_eax(IBS_CPUID_FEATURES);
if (!(caps & IBS_CAPS_AVAIL))
return IBS_CAPS_DEFAULT;
return caps;
}
u32 get_ibs_caps(void)
{
return ibs_caps;
}
static inline int get_eilvt(int offset)
{
return !setup_APIC_eilvt(offset, 0, APIC_EILVT_MSG_NMI, 1);
}
static inline int put_eilvt(int offset)
{
return !setup_APIC_eilvt(offset, 0, 0, 1);
}
static inline int ibs_eilvt_valid(void)
{
int offset;
u64 val;
int valid = 0;
preempt_disable();
rdmsrl(MSR_AMD64_IBSCTL, val);
offset = val & IBSCTL_LVT_OFFSET_MASK;
if (!(val & IBSCTL_LVT_OFFSET_VALID)) {
pr_err(FW_BUG "cpu %d, invalid IBS interrupt offset %d (MSR%08X=0x%016llx)\n",
smp_processor_id(), offset, MSR_AMD64_IBSCTL, val);
goto out;
}
if (!get_eilvt(offset)) {
pr_err(FW_BUG "cpu %d, IBS interrupt offset %d not available (MSR%08X=0x%016llx)\n",
smp_processor_id(), offset, MSR_AMD64_IBSCTL, val);
goto out;
}
valid = 1;
out:
preempt_enable();
return valid;
}
static int setup_ibs_ctl(int ibs_eilvt_off)
{
struct pci_dev *cpu_cfg;
int nodes;
u32 value = 0;
nodes = 0;
cpu_cfg = NULL;
do {
cpu_cfg = pci_get_device(PCI_VENDOR_ID_AMD,
PCI_DEVICE_ID_AMD_10H_NB_MISC,
cpu_cfg);
if (!cpu_cfg)
break;
++nodes;
pci_write_config_dword(cpu_cfg, IBSCTL, ibs_eilvt_off
| IBSCTL_LVT_OFFSET_VALID);
pci_read_config_dword(cpu_cfg, IBSCTL, &value);
if (value != (ibs_eilvt_off | IBSCTL_LVT_OFFSET_VALID)) {
pci_dev_put(cpu_cfg);
printk(KERN_DEBUG "Failed to setup IBS LVT offset, "
"IBSCTL = 0x%08x\n", value);
return -EINVAL;
}
} while (1);
if (!nodes) {
printk(KERN_DEBUG "No CPU node configured for IBS\n");
return -ENODEV;
}
return 0;
}
static int force_ibs_eilvt_setup(void)
{
int offset;
int ret;
preempt_disable();
for (offset = 1; offset < APIC_EILVT_NR_MAX; offset++) {
if (get_eilvt(offset))
break;
}
preempt_enable();
if (offset == APIC_EILVT_NR_MAX) {
printk(KERN_DEBUG "No EILVT entry available\n");
return -EBUSY;
}
ret = setup_ibs_ctl(offset);
if (ret)
goto out;
if (!ibs_eilvt_valid()) {
ret = -EFAULT;
goto out;
}
pr_info("IBS: LVT offset %d assigned\n", offset);
return 0;
out:
preempt_disable();
put_eilvt(offset);
preempt_enable();
return ret;
}
static void ibs_eilvt_setup(void)
{
if (boot_cpu_data.x86 == 0x10)
force_ibs_eilvt_setup();
}
static inline int get_ibs_lvt_offset(void)
{
u64 val;
rdmsrl(MSR_AMD64_IBSCTL, val);
if (!(val & IBSCTL_LVT_OFFSET_VALID))
return -EINVAL;
return val & IBSCTL_LVT_OFFSET_MASK;
}
static void setup_APIC_ibs(void *dummy)
{
int offset;
offset = get_ibs_lvt_offset();
if (offset < 0)
goto failed;
if (!setup_APIC_eilvt(offset, 0, APIC_EILVT_MSG_NMI, 0))
return;
failed:
pr_warn("perf: IBS APIC setup failed on cpu #%d\n",
smp_processor_id());
}
static void clear_APIC_ibs(void *dummy)
{
int offset;
offset = get_ibs_lvt_offset();
if (offset >= 0)
setup_APIC_eilvt(offset, 0, APIC_EILVT_MSG_FIX, 1);
}
static int perf_ibs_suspend(void)
{
clear_APIC_ibs(NULL);
return 0;
}
static void perf_ibs_resume(void)
{
ibs_eilvt_setup();
setup_APIC_ibs(NULL);
}
static void perf_ibs_pm_init(void)
{
register_syscore_ops(&perf_ibs_syscore_ops);
}
static inline void perf_ibs_pm_init(void) { }
static int
perf_ibs_cpu_notifier(struct notifier_block *self, unsigned long action, void *hcpu)
{
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_STARTING:
setup_APIC_ibs(NULL);
break;
case CPU_DYING:
clear_APIC_ibs(NULL);
break;
default:
break;
}
return NOTIFY_OK;
}
static __init int amd_ibs_init(void)
{
u32 caps;
int ret = -EINVAL;
caps = __get_ibs_caps();
if (!caps)
return -ENODEV;
ibs_eilvt_setup();
if (!ibs_eilvt_valid())
goto out;
perf_ibs_pm_init();
get_online_cpus();
ibs_caps = caps;
smp_mb();
perf_cpu_notifier(perf_ibs_cpu_notifier);
smp_call_function(setup_APIC_ibs, NULL, 1);
put_online_cpus();
ret = perf_event_ibs_init();
out:
if (ret)
pr_err("Failed to setup IBS, %d\n", ret);
return ret;
}
