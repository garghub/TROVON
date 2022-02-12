static ssize_t _iommu_event_show(struct kobject *kobj,
struct kobj_attribute *attr, char *buf)
{
struct amd_iommu_event_desc *event =
container_of(attr, struct amd_iommu_event_desc, attr);
return sprintf(buf, "%s\n", event->event);
}
static ssize_t _iommu_cpumask_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
int n = cpulist_scnprintf(buf, PAGE_SIZE - 2, &iommu_cpumask);
buf[n++] = '\n';
buf[n] = '\0';
return n;
}
static int get_next_avail_iommu_bnk_cntr(struct perf_amd_iommu *perf_iommu)
{
unsigned long flags;
int shift, bank, cntr, retval;
int max_banks = perf_iommu->max_banks;
int max_cntrs = perf_iommu->max_counters;
raw_spin_lock_irqsave(&perf_iommu->lock, flags);
for (bank = 0, shift = 0; bank < max_banks; bank++) {
for (cntr = 0; cntr < max_cntrs; cntr++) {
shift = bank + (bank*3) + cntr;
if (perf_iommu->cntr_assign_mask & (1ULL<<shift)) {
continue;
} else {
perf_iommu->cntr_assign_mask |= (1ULL<<shift);
retval = ((u16)((u16)bank<<8) | (u8)(cntr));
goto out;
}
}
}
retval = -ENOSPC;
out:
raw_spin_unlock_irqrestore(&perf_iommu->lock, flags);
return retval;
}
static int clear_avail_iommu_bnk_cntr(struct perf_amd_iommu *perf_iommu,
u8 bank, u8 cntr)
{
unsigned long flags;
int max_banks, max_cntrs;
int shift = 0;
max_banks = perf_iommu->max_banks;
max_cntrs = perf_iommu->max_counters;
if ((bank > max_banks) || (cntr > max_cntrs))
return -EINVAL;
shift = bank + cntr + (bank*3);
raw_spin_lock_irqsave(&perf_iommu->lock, flags);
perf_iommu->cntr_assign_mask &= ~(1ULL<<shift);
raw_spin_unlock_irqrestore(&perf_iommu->lock, flags);
return 0;
}
static int perf_iommu_event_init(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct perf_amd_iommu *perf_iommu;
u64 config, config1;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (is_sampling_event(event) || event->attach_state & PERF_ATTACH_TASK)
return -EINVAL;
if (event->attr.exclude_user || event->attr.exclude_kernel ||
event->attr.exclude_host || event->attr.exclude_guest)
return -EINVAL;
if (event->cpu < 0)
return -EINVAL;
perf_iommu = &__perf_iommu;
if (event->pmu != &perf_iommu->pmu)
return -ENOENT;
if (perf_iommu) {
config = event->attr.config;
config1 = event->attr.config1;
} else {
return -EINVAL;
}
perf_iommu->max_banks =
amd_iommu_pc_get_max_banks(IOMMU_BASE_DEVID);
perf_iommu->max_counters =
amd_iommu_pc_get_max_counters(IOMMU_BASE_DEVID);
if ((perf_iommu->max_banks == 0) || (perf_iommu->max_counters == 0))
return -EINVAL;
hwc->config = config;
hwc->extra_reg.config = config1;
return 0;
}
static void perf_iommu_enable_event(struct perf_event *ev)
{
u8 csource = _GET_CSOURCE(ev);
u16 devid = _GET_DEVID(ev);
u64 reg = 0ULL;
reg = csource;
amd_iommu_pc_get_set_reg_val(devid,
_GET_BANK(ev), _GET_CNTR(ev) ,
IOMMU_PC_COUNTER_SRC_REG, &reg, true);
reg = 0ULL | devid | (_GET_DEVID_MASK(ev) << 32);
if (reg)
reg |= (1UL << 31);
amd_iommu_pc_get_set_reg_val(devid,
_GET_BANK(ev), _GET_CNTR(ev) ,
IOMMU_PC_DEVID_MATCH_REG, &reg, true);
reg = 0ULL | _GET_PASID(ev) | (_GET_PASID_MASK(ev) << 32);
if (reg)
reg |= (1UL << 31);
amd_iommu_pc_get_set_reg_val(devid,
_GET_BANK(ev), _GET_CNTR(ev) ,
IOMMU_PC_PASID_MATCH_REG, &reg, true);
reg = 0ULL | _GET_DOMID(ev) | (_GET_DOMID_MASK(ev) << 32);
if (reg)
reg |= (1UL << 31);
amd_iommu_pc_get_set_reg_val(devid,
_GET_BANK(ev), _GET_CNTR(ev) ,
IOMMU_PC_DOMID_MATCH_REG, &reg, true);
}
static void perf_iommu_disable_event(struct perf_event *event)
{
u64 reg = 0ULL;
amd_iommu_pc_get_set_reg_val(_GET_DEVID(event),
_GET_BANK(event), _GET_CNTR(event),
IOMMU_PC_COUNTER_SRC_REG, &reg, true);
}
static void perf_iommu_start(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
pr_debug("perf: amd_iommu:perf_iommu_start\n");
if (WARN_ON_ONCE(!(hwc->state & PERF_HES_STOPPED)))
return;
WARN_ON_ONCE(!(hwc->state & PERF_HES_UPTODATE));
hwc->state = 0;
if (flags & PERF_EF_RELOAD) {
u64 prev_raw_count = local64_read(&hwc->prev_count);
amd_iommu_pc_get_set_reg_val(_GET_DEVID(event),
_GET_BANK(event), _GET_CNTR(event),
IOMMU_PC_COUNTER_REG, &prev_raw_count, true);
}
perf_iommu_enable_event(event);
perf_event_update_userpage(event);
}
static void perf_iommu_read(struct perf_event *event)
{
u64 count = 0ULL;
u64 prev_raw_count = 0ULL;
u64 delta = 0ULL;
struct hw_perf_event *hwc = &event->hw;
pr_debug("perf: amd_iommu:perf_iommu_read\n");
amd_iommu_pc_get_set_reg_val(_GET_DEVID(event),
_GET_BANK(event), _GET_CNTR(event),
IOMMU_PC_COUNTER_REG, &count, false);
count &= 0xFFFFFFFFFFFFULL;
prev_raw_count = local64_read(&hwc->prev_count);
if (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
count) != prev_raw_count)
return;
delta = (count << COUNTER_SHIFT) - (prev_raw_count << COUNTER_SHIFT);
delta >>= COUNTER_SHIFT;
local64_add(delta, &event->count);
}
static void perf_iommu_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hwc = &event->hw;
u64 config;
pr_debug("perf: amd_iommu:perf_iommu_stop\n");
if (hwc->state & PERF_HES_UPTODATE)
return;
perf_iommu_disable_event(event);
WARN_ON_ONCE(hwc->state & PERF_HES_STOPPED);
hwc->state |= PERF_HES_STOPPED;
if (hwc->state & PERF_HES_UPTODATE)
return;
config = hwc->config;
perf_iommu_read(event);
hwc->state |= PERF_HES_UPTODATE;
}
static int perf_iommu_add(struct perf_event *event, int flags)
{
int retval;
struct perf_amd_iommu *perf_iommu =
container_of(event->pmu, struct perf_amd_iommu, pmu);
pr_debug("perf: amd_iommu:perf_iommu_add\n");
event->hw.state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
retval = get_next_avail_iommu_bnk_cntr(perf_iommu);
if (retval != -ENOSPC)
event->hw.extra_reg.reg = (u16)retval;
else
return retval;
if (flags & PERF_EF_START)
perf_iommu_start(event, PERF_EF_RELOAD);
return 0;
}
static void perf_iommu_del(struct perf_event *event, int flags)
{
struct perf_amd_iommu *perf_iommu =
container_of(event->pmu, struct perf_amd_iommu, pmu);
pr_debug("perf: amd_iommu:perf_iommu_del\n");
perf_iommu_stop(event, PERF_EF_UPDATE);
clear_avail_iommu_bnk_cntr(perf_iommu,
_GET_BANK(event),
_GET_CNTR(event));
perf_event_update_userpage(event);
}
static __init int _init_events_attrs(struct perf_amd_iommu *perf_iommu)
{
struct attribute **attrs;
struct attribute_group *attr_group;
int i = 0, j;
while (amd_iommu_v2_event_descs[i].attr.attr.name)
i++;
attr_group = kzalloc(sizeof(struct attribute *)
* (i + 1) + sizeof(*attr_group), GFP_KERNEL);
if (!attr_group)
return -ENOMEM;
attrs = (struct attribute **)(attr_group + 1);
for (j = 0; j < i; j++)
attrs[j] = &amd_iommu_v2_event_descs[j].attr.attr;
attr_group->name = "events";
attr_group->attrs = attrs;
perf_iommu->events_group = attr_group;
return 0;
}
static __init void amd_iommu_pc_exit(void)
{
if (__perf_iommu.events_group != NULL) {
kfree(__perf_iommu.events_group);
__perf_iommu.events_group = NULL;
}
}
static __init int _init_perf_amd_iommu(
struct perf_amd_iommu *perf_iommu, char *name)
{
int ret;
raw_spin_lock_init(&perf_iommu->lock);
perf_iommu->format_group = &amd_iommu_format_group;
cpumask_set_cpu(0, &iommu_cpumask);
perf_iommu->cpumask_group = &amd_iommu_cpumask_group;
if (_init_events_attrs(perf_iommu) != 0)
pr_err("perf: amd_iommu: Only support raw events.\n");
perf_iommu->null_group = NULL;
perf_iommu->pmu.attr_groups = perf_iommu->attr_groups;
ret = perf_pmu_register(&perf_iommu->pmu, name, -1);
if (ret) {
pr_err("perf: amd_iommu: Failed to initialized.\n");
amd_iommu_pc_exit();
} else {
pr_info("perf: amd_iommu: Detected. (%d banks, %d counters/bank)\n",
amd_iommu_pc_get_max_banks(IOMMU_BASE_DEVID),
amd_iommu_pc_get_max_counters(IOMMU_BASE_DEVID));
}
return ret;
}
static __init int amd_iommu_pc_init(void)
{
if (!amd_iommu_pc_supported())
return -ENODEV;
_init_perf_amd_iommu(&__perf_iommu, "amd_iommu");
return 0;
}
