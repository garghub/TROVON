static int arm_ccn_node_to_xp(int node)
{
return node / CCN_NUM_XP_PORTS;
}
static int arm_ccn_node_to_xp_port(int node)
{
return node % CCN_NUM_XP_PORTS;
}
static void arm_ccn_pmu_config_set(u64 *config, u32 node_xp, u32 type, u32 port)
{
*config &= ~((0xff << 0) | (0xff << 8) | (0x3 << 24));
*config |= (node_xp << 0) | (type << 8) | (port << 24);
}
static ssize_t arm_ccn_pmu_format_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dev_ext_attribute *ea = container_of(attr,
struct dev_ext_attribute, attr);
return snprintf(buf, PAGE_SIZE, "%s\n", (char *)ea->var);
}
static ssize_t arm_ccn_pmu_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(dev_get_drvdata(dev));
struct arm_ccn_pmu_event *event = container_of(attr,
struct arm_ccn_pmu_event, attr);
ssize_t res;
res = snprintf(buf, PAGE_SIZE, "type=0x%x", event->type);
if (event->event)
res += snprintf(buf + res, PAGE_SIZE - res, ",event=0x%x",
event->event);
if (event->def)
res += snprintf(buf + res, PAGE_SIZE - res, ",%s",
event->def);
if (event->mask)
res += snprintf(buf + res, PAGE_SIZE - res, ",mask=0x%x",
event->mask);
switch (event->type) {
case CCN_TYPE_CYCLES:
break;
case CCN_TYPE_XP:
res += snprintf(buf + res, PAGE_SIZE - res,
",xp=?,vc=?");
if (event->event == CCN_EVENT_WATCHPOINT)
res += snprintf(buf + res, PAGE_SIZE - res,
",port=?,dir=?,cmp_l=?,cmp_h=?,mask=?");
else
res += snprintf(buf + res, PAGE_SIZE - res,
",bus=?");
break;
case CCN_TYPE_MN:
res += snprintf(buf + res, PAGE_SIZE - res, ",node=%d", ccn->mn_id);
break;
default:
res += snprintf(buf + res, PAGE_SIZE - res, ",node=?");
break;
}
res += snprintf(buf + res, PAGE_SIZE - res, "\n");
return res;
}
static umode_t arm_ccn_pmu_events_is_visible(struct kobject *kobj,
struct attribute *attr, int index)
{
struct device *dev = kobj_to_dev(kobj);
struct arm_ccn *ccn = pmu_to_arm_ccn(dev_get_drvdata(dev));
struct device_attribute *dev_attr = container_of(attr,
struct device_attribute, attr);
struct arm_ccn_pmu_event *event = container_of(dev_attr,
struct arm_ccn_pmu_event, attr);
if (event->type == CCN_TYPE_SBAS && !ccn->sbas_present)
return 0;
if (event->type == CCN_TYPE_SBSX && !ccn->sbsx_present)
return 0;
return attr->mode;
}
static u64 *arm_ccn_pmu_get_cmp_mask(struct arm_ccn *ccn, const char *name)
{
unsigned long i;
if (WARN_ON(!name || !name[0] || !isxdigit(name[0]) || !name[1]))
return NULL;
i = isdigit(name[0]) ? name[0] - '0' : 0xa + tolower(name[0]) - 'a';
switch (name[1]) {
case 'l':
return &ccn->dt.cmp_mask[i].l;
case 'h':
return &ccn->dt.cmp_mask[i].h;
default:
return NULL;
}
}
static ssize_t arm_ccn_pmu_cmp_mask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(dev_get_drvdata(dev));
u64 *mask = arm_ccn_pmu_get_cmp_mask(ccn, attr->attr.name);
return mask ? snprintf(buf, PAGE_SIZE, "0x%016llx\n", *mask) : -EINVAL;
}
static ssize_t arm_ccn_pmu_cmp_mask_store(struct device *dev,
struct device_attribute *attr, const char *buf, size_t count)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(dev_get_drvdata(dev));
u64 *mask = arm_ccn_pmu_get_cmp_mask(ccn, attr->attr.name);
int err = -EINVAL;
if (mask)
err = kstrtoull(buf, 0, mask);
return err ? err : count;
}
static ssize_t arm_ccn_pmu_cpumask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(dev_get_drvdata(dev));
return cpumap_print_to_pagebuf(true, buf, &ccn->dt.cpu);
}
static ktime_t arm_ccn_pmu_timer_period(void)
{
return ns_to_ktime((u64)arm_ccn_pmu_poll_period_us * 1000);
}
static int arm_ccn_pmu_alloc_bit(unsigned long *bitmap, unsigned long size)
{
int bit;
do {
bit = find_first_zero_bit(bitmap, size);
if (bit >= size)
return -EAGAIN;
} while (test_and_set_bit(bit, bitmap));
return bit;
}
static int arm_ccn_pmu_type_eq(u32 a, u32 b)
{
if (a == b)
return 1;
switch (a) {
case CCN_TYPE_RNI_1P:
case CCN_TYPE_RNI_2P:
case CCN_TYPE_RNI_3P:
case CCN_TYPE_RND_1P:
case CCN_TYPE_RND_2P:
case CCN_TYPE_RND_3P:
switch (b) {
case CCN_TYPE_RNI_1P:
case CCN_TYPE_RNI_2P:
case CCN_TYPE_RNI_3P:
case CCN_TYPE_RND_1P:
case CCN_TYPE_RND_2P:
case CCN_TYPE_RND_3P:
return 1;
}
break;
}
return 0;
}
static int arm_ccn_pmu_event_alloc(struct perf_event *event)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
u32 node_xp, type, event_id;
struct arm_ccn_component *source;
int bit;
node_xp = CCN_CONFIG_NODE(event->attr.config);
type = CCN_CONFIG_TYPE(event->attr.config);
event_id = CCN_CONFIG_EVENT(event->attr.config);
if (type == CCN_TYPE_CYCLES) {
if (test_and_set_bit(CCN_IDX_PMU_CYCLE_COUNTER,
ccn->dt.pmu_counters_mask))
return -EAGAIN;
hw->idx = CCN_IDX_PMU_CYCLE_COUNTER;
ccn->dt.pmu_counters[CCN_IDX_PMU_CYCLE_COUNTER].event = event;
return 0;
}
hw->idx = arm_ccn_pmu_alloc_bit(ccn->dt.pmu_counters_mask,
CCN_NUM_PMU_EVENT_COUNTERS);
if (hw->idx < 0) {
dev_dbg(ccn->dev, "No more counters available!\n");
return -EAGAIN;
}
if (type == CCN_TYPE_XP)
source = &ccn->xp[node_xp];
else
source = &ccn->node[node_xp];
ccn->dt.pmu_counters[hw->idx].source = source;
if (type == CCN_TYPE_XP && event_id == CCN_EVENT_WATCHPOINT)
bit = arm_ccn_pmu_alloc_bit(source->xp.dt_cmp_mask,
CCN_NUM_XP_WATCHPOINTS);
else
bit = arm_ccn_pmu_alloc_bit(source->pmu_events_mask,
CCN_NUM_PMU_EVENTS);
if (bit < 0) {
dev_dbg(ccn->dev, "No more event sources/watchpoints on node/XP %d!\n",
node_xp);
clear_bit(hw->idx, ccn->dt.pmu_counters_mask);
return -EAGAIN;
}
hw->config_base = bit;
ccn->dt.pmu_counters[hw->idx].event = event;
return 0;
}
static void arm_ccn_pmu_event_release(struct perf_event *event)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
if (hw->idx == CCN_IDX_PMU_CYCLE_COUNTER) {
clear_bit(CCN_IDX_PMU_CYCLE_COUNTER, ccn->dt.pmu_counters_mask);
} else {
struct arm_ccn_component *source =
ccn->dt.pmu_counters[hw->idx].source;
if (CCN_CONFIG_TYPE(event->attr.config) == CCN_TYPE_XP &&
CCN_CONFIG_EVENT(event->attr.config) ==
CCN_EVENT_WATCHPOINT)
clear_bit(hw->config_base, source->xp.dt_cmp_mask);
else
clear_bit(hw->config_base, source->pmu_events_mask);
clear_bit(hw->idx, ccn->dt.pmu_counters_mask);
}
ccn->dt.pmu_counters[hw->idx].source = NULL;
ccn->dt.pmu_counters[hw->idx].event = NULL;
}
static int arm_ccn_pmu_event_init(struct perf_event *event)
{
struct arm_ccn *ccn;
struct hw_perf_event *hw = &event->hw;
u32 node_xp, type, event_id;
int valid;
int i;
struct perf_event *sibling;
if (event->attr.type != event->pmu->type)
return -ENOENT;
ccn = pmu_to_arm_ccn(event->pmu);
if (hw->sample_period) {
dev_warn(ccn->dev, "Sampling not supported!\n");
return -EOPNOTSUPP;
}
if (has_branch_stack(event) || event->attr.exclude_user ||
event->attr.exclude_kernel || event->attr.exclude_hv ||
event->attr.exclude_idle || event->attr.exclude_host ||
event->attr.exclude_guest) {
dev_warn(ccn->dev, "Can't exclude execution levels!\n");
return -EINVAL;
}
if (event->cpu < 0) {
dev_warn(ccn->dev, "Can't provide per-task data!\n");
return -EOPNOTSUPP;
}
event->cpu = cpumask_first(&ccn->dt.cpu);
node_xp = CCN_CONFIG_NODE(event->attr.config);
type = CCN_CONFIG_TYPE(event->attr.config);
event_id = CCN_CONFIG_EVENT(event->attr.config);
switch (type) {
case CCN_TYPE_MN:
if (node_xp != ccn->mn_id) {
dev_warn(ccn->dev, "Invalid MN ID %d!\n", node_xp);
return -EINVAL;
}
break;
case CCN_TYPE_XP:
if (node_xp >= ccn->num_xps) {
dev_warn(ccn->dev, "Invalid XP ID %d!\n", node_xp);
return -EINVAL;
}
break;
case CCN_TYPE_CYCLES:
break;
default:
if (node_xp >= ccn->num_nodes) {
dev_warn(ccn->dev, "Invalid node ID %d!\n", node_xp);
return -EINVAL;
}
if (!arm_ccn_pmu_type_eq(type, ccn->node[node_xp].type)) {
dev_warn(ccn->dev, "Invalid type 0x%x for node %d!\n",
type, node_xp);
return -EINVAL;
}
break;
}
for (i = 0, valid = 0; i < ARRAY_SIZE(arm_ccn_pmu_events) && !valid;
i++) {
struct arm_ccn_pmu_event *e = &arm_ccn_pmu_events[i];
u32 port = CCN_CONFIG_PORT(event->attr.config);
u32 vc = CCN_CONFIG_VC(event->attr.config);
if (!arm_ccn_pmu_type_eq(type, e->type))
continue;
if (event_id != e->event)
continue;
if (e->num_ports && port >= e->num_ports) {
dev_warn(ccn->dev, "Invalid port %d for node/XP %d!\n",
port, node_xp);
return -EINVAL;
}
if (e->num_vcs && vc >= e->num_vcs) {
dev_warn(ccn->dev, "Invalid vc %d for node/XP %d!\n",
vc, node_xp);
return -EINVAL;
}
valid = 1;
}
if (!valid) {
dev_warn(ccn->dev, "Invalid event 0x%x for node/XP %d!\n",
event_id, node_xp);
return -EINVAL;
}
if (event_id == CCN_EVENT_WATCHPOINT && type != CCN_TYPE_XP) {
u32 port;
type = CCN_TYPE_XP;
port = arm_ccn_node_to_xp_port(node_xp);
node_xp = arm_ccn_node_to_xp(node_xp);
arm_ccn_pmu_config_set(&event->attr.config,
node_xp, type, port);
}
if (event->group_leader->pmu != event->pmu &&
!is_software_event(event->group_leader))
return -EINVAL;
list_for_each_entry(sibling, &event->group_leader->sibling_list,
group_entry)
if (sibling->pmu != event->pmu &&
!is_software_event(sibling))
return -EINVAL;
return 0;
}
static u64 arm_ccn_pmu_read_counter(struct arm_ccn *ccn, int idx)
{
u64 res;
if (idx == CCN_IDX_PMU_CYCLE_COUNTER) {
#ifdef readq
res = readq(ccn->dt.base + CCN_DT_PMCCNTR);
#else
writel(0x1, ccn->dt.base + CCN_DT_PMSR_REQ);
while (!(readl(ccn->dt.base + CCN_DT_PMSR) & 0x1))
;
writel(0x1, ccn->dt.base + CCN_DT_PMSR_CLR);
res = readl(ccn->dt.base + CCN_DT_PMCCNTRSR + 4) & 0xff;
res <<= 32;
res |= readl(ccn->dt.base + CCN_DT_PMCCNTRSR);
#endif
} else {
res = readl(ccn->dt.base + CCN_DT_PMEVCNT(idx));
}
return res;
}
static void arm_ccn_pmu_event_update(struct perf_event *event)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
u64 prev_count, new_count, mask;
do {
prev_count = local64_read(&hw->prev_count);
new_count = arm_ccn_pmu_read_counter(ccn, hw->idx);
} while (local64_xchg(&hw->prev_count, new_count) != prev_count);
mask = (1LLU << (hw->idx == CCN_IDX_PMU_CYCLE_COUNTER ? 40 : 32)) - 1;
local64_add((new_count - prev_count) & mask, &event->count);
}
static void arm_ccn_pmu_xp_dt_config(struct perf_event *event, int enable)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
struct arm_ccn_component *xp;
u32 val, dt_cfg;
if (hw->idx == CCN_IDX_PMU_CYCLE_COUNTER)
return;
if (CCN_CONFIG_TYPE(event->attr.config) == CCN_TYPE_XP)
xp = &ccn->xp[CCN_CONFIG_XP(event->attr.config)];
else
xp = &ccn->xp[arm_ccn_node_to_xp(
CCN_CONFIG_NODE(event->attr.config))];
if (enable)
dt_cfg = hw->event_base;
else
dt_cfg = CCN_XP_DT_CONFIG__DT_CFG__PASS_THROUGH;
spin_lock(&ccn->dt.config_lock);
val = readl(xp->base + CCN_XP_DT_CONFIG);
val &= ~(CCN_XP_DT_CONFIG__DT_CFG__MASK <<
CCN_XP_DT_CONFIG__DT_CFG__SHIFT(hw->idx));
val |= dt_cfg << CCN_XP_DT_CONFIG__DT_CFG__SHIFT(hw->idx);
writel(val, xp->base + CCN_XP_DT_CONFIG);
spin_unlock(&ccn->dt.config_lock);
}
static void arm_ccn_pmu_event_start(struct perf_event *event, int flags)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
local64_set(&event->hw.prev_count,
arm_ccn_pmu_read_counter(ccn, hw->idx));
hw->state = 0;
arm_ccn_pmu_xp_dt_config(event, 1);
}
static void arm_ccn_pmu_event_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hw = &event->hw;
arm_ccn_pmu_xp_dt_config(event, 0);
if (flags & PERF_EF_UPDATE)
arm_ccn_pmu_event_update(event);
hw->state |= PERF_HES_STOPPED;
}
static void arm_ccn_pmu_xp_watchpoint_config(struct perf_event *event)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
struct arm_ccn_component *source =
ccn->dt.pmu_counters[hw->idx].source;
unsigned long wp = hw->config_base;
u32 val;
u64 cmp_l = event->attr.config1;
u64 cmp_h = event->attr.config2;
u64 mask_l = ccn->dt.cmp_mask[CCN_CONFIG_MASK(event->attr.config)].l;
u64 mask_h = ccn->dt.cmp_mask[CCN_CONFIG_MASK(event->attr.config)].h;
hw->event_base = CCN_XP_DT_CONFIG__DT_CFG__WATCHPOINT(wp);
val = readl(source->base + CCN_XP_DT_INTERFACE_SEL);
val &= ~(CCN_XP_DT_INTERFACE_SEL__DT_IO_SEL__MASK <<
CCN_XP_DT_INTERFACE_SEL__DT_IO_SEL__SHIFT(wp));
val |= CCN_CONFIG_DIR(event->attr.config) <<
CCN_XP_DT_INTERFACE_SEL__DT_IO_SEL__SHIFT(wp);
val &= ~(CCN_XP_DT_INTERFACE_SEL__DT_DEV_SEL__MASK <<
CCN_XP_DT_INTERFACE_SEL__DT_DEV_SEL__SHIFT(wp));
val |= CCN_CONFIG_PORT(event->attr.config) <<
CCN_XP_DT_INTERFACE_SEL__DT_DEV_SEL__SHIFT(wp);
val &= ~(CCN_XP_DT_INTERFACE_SEL__DT_VC_SEL__MASK <<
CCN_XP_DT_INTERFACE_SEL__DT_VC_SEL__SHIFT(wp));
val |= CCN_CONFIG_VC(event->attr.config) <<
CCN_XP_DT_INTERFACE_SEL__DT_VC_SEL__SHIFT(wp);
writel(val, source->base + CCN_XP_DT_INTERFACE_SEL);
writel(cmp_l & 0xffffffff, source->base + CCN_XP_DT_CMP_VAL_L(wp));
writel((cmp_l >> 32) & 0x7fffffff,
source->base + CCN_XP_DT_CMP_VAL_L(wp) + 4);
writel(cmp_h & 0xffffffff, source->base + CCN_XP_DT_CMP_VAL_H(wp));
writel((cmp_h >> 32) & 0x0fffffff,
source->base + CCN_XP_DT_CMP_VAL_H(wp) + 4);
writel(mask_l & 0xffffffff, source->base + CCN_XP_DT_CMP_MASK_L(wp));
writel((mask_l >> 32) & 0x7fffffff,
source->base + CCN_XP_DT_CMP_MASK_L(wp) + 4);
writel(mask_h & 0xffffffff, source->base + CCN_XP_DT_CMP_MASK_H(wp));
writel((mask_h >> 32) & 0x0fffffff,
source->base + CCN_XP_DT_CMP_MASK_H(wp) + 4);
}
static void arm_ccn_pmu_xp_event_config(struct perf_event *event)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
struct arm_ccn_component *source =
ccn->dt.pmu_counters[hw->idx].source;
u32 val, id;
hw->event_base = CCN_XP_DT_CONFIG__DT_CFG__XP_PMU_EVENT(hw->config_base);
id = (CCN_CONFIG_VC(event->attr.config) << 4) |
(CCN_CONFIG_BUS(event->attr.config) << 3) |
(CCN_CONFIG_EVENT(event->attr.config) << 0);
val = readl(source->base + CCN_XP_PMU_EVENT_SEL);
val &= ~(CCN_XP_PMU_EVENT_SEL__ID__MASK <<
CCN_XP_PMU_EVENT_SEL__ID__SHIFT(hw->config_base));
val |= id << CCN_XP_PMU_EVENT_SEL__ID__SHIFT(hw->config_base);
writel(val, source->base + CCN_XP_PMU_EVENT_SEL);
}
static void arm_ccn_pmu_node_event_config(struct perf_event *event)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
struct arm_ccn_component *source =
ccn->dt.pmu_counters[hw->idx].source;
u32 type = CCN_CONFIG_TYPE(event->attr.config);
u32 val, port;
port = arm_ccn_node_to_xp_port(CCN_CONFIG_NODE(event->attr.config));
hw->event_base = CCN_XP_DT_CONFIG__DT_CFG__DEVICE_PMU_EVENT(port,
hw->config_base);
BUILD_BUG_ON(CCN_HNF_PMU_EVENT_SEL != CCN_SBAS_PMU_EVENT_SEL);
BUILD_BUG_ON(CCN_SBAS_PMU_EVENT_SEL != CCN_RNI_PMU_EVENT_SEL);
BUILD_BUG_ON(CCN_HNF_PMU_EVENT_SEL__ID__SHIFT(1) !=
CCN_SBAS_PMU_EVENT_SEL__ID__SHIFT(1));
BUILD_BUG_ON(CCN_SBAS_PMU_EVENT_SEL__ID__SHIFT(1) !=
CCN_RNI_PMU_EVENT_SEL__ID__SHIFT(1));
BUILD_BUG_ON(CCN_HNF_PMU_EVENT_SEL__ID__MASK !=
CCN_SBAS_PMU_EVENT_SEL__ID__MASK);
BUILD_BUG_ON(CCN_SBAS_PMU_EVENT_SEL__ID__MASK !=
CCN_RNI_PMU_EVENT_SEL__ID__MASK);
if (WARN_ON(type != CCN_TYPE_HNF && type != CCN_TYPE_SBAS &&
!arm_ccn_pmu_type_eq(type, CCN_TYPE_RNI_3P)))
return;
val = readl(source->base + CCN_HNF_PMU_EVENT_SEL);
val &= ~(CCN_HNF_PMU_EVENT_SEL__ID__MASK <<
CCN_HNF_PMU_EVENT_SEL__ID__SHIFT(hw->config_base));
val |= CCN_CONFIG_EVENT(event->attr.config) <<
CCN_HNF_PMU_EVENT_SEL__ID__SHIFT(hw->config_base);
writel(val, source->base + CCN_HNF_PMU_EVENT_SEL);
}
static void arm_ccn_pmu_event_config(struct perf_event *event)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
struct hw_perf_event *hw = &event->hw;
u32 xp, offset, val;
if (hw->idx == CCN_IDX_PMU_CYCLE_COUNTER)
return;
if (CCN_CONFIG_TYPE(event->attr.config) == CCN_TYPE_XP)
xp = CCN_CONFIG_XP(event->attr.config);
else
xp = arm_ccn_node_to_xp(CCN_CONFIG_NODE(event->attr.config));
spin_lock(&ccn->dt.config_lock);
offset = (hw->idx / 4) * 4;
val = readl(ccn->dt.base + CCN_DT_ACTIVE_DSM + offset);
val &= ~(CCN_DT_ACTIVE_DSM__DSM_ID__MASK <<
CCN_DT_ACTIVE_DSM__DSM_ID__SHIFT(hw->idx % 4));
val |= xp << CCN_DT_ACTIVE_DSM__DSM_ID__SHIFT(hw->idx % 4);
writel(val, ccn->dt.base + CCN_DT_ACTIVE_DSM + offset);
if (CCN_CONFIG_TYPE(event->attr.config) == CCN_TYPE_XP) {
if (CCN_CONFIG_EVENT(event->attr.config) ==
CCN_EVENT_WATCHPOINT)
arm_ccn_pmu_xp_watchpoint_config(event);
else
arm_ccn_pmu_xp_event_config(event);
} else {
arm_ccn_pmu_node_event_config(event);
}
spin_unlock(&ccn->dt.config_lock);
}
static int arm_ccn_pmu_active_counters(struct arm_ccn *ccn)
{
return bitmap_weight(ccn->dt.pmu_counters_mask,
CCN_NUM_PMU_EVENT_COUNTERS + 1);
}
static int arm_ccn_pmu_event_add(struct perf_event *event, int flags)
{
int err;
struct hw_perf_event *hw = &event->hw;
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
err = arm_ccn_pmu_event_alloc(event);
if (err)
return err;
if (!ccn->irq && arm_ccn_pmu_active_counters(ccn) == 1)
hrtimer_start(&ccn->dt.hrtimer, arm_ccn_pmu_timer_period(),
HRTIMER_MODE_REL_PINNED);
arm_ccn_pmu_event_config(event);
hw->state = PERF_HES_STOPPED;
if (flags & PERF_EF_START)
arm_ccn_pmu_event_start(event, PERF_EF_UPDATE);
return 0;
}
static void arm_ccn_pmu_event_del(struct perf_event *event, int flags)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(event->pmu);
arm_ccn_pmu_event_stop(event, PERF_EF_UPDATE);
arm_ccn_pmu_event_release(event);
if (!ccn->irq && arm_ccn_pmu_active_counters(ccn) == 0)
hrtimer_cancel(&ccn->dt.hrtimer);
}
static void arm_ccn_pmu_event_read(struct perf_event *event)
{
arm_ccn_pmu_event_update(event);
}
static void arm_ccn_pmu_enable(struct pmu *pmu)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(pmu);
u32 val = readl(ccn->dt.base + CCN_DT_PMCR);
val |= CCN_DT_PMCR__PMU_EN;
writel(val, ccn->dt.base + CCN_DT_PMCR);
}
static void arm_ccn_pmu_disable(struct pmu *pmu)
{
struct arm_ccn *ccn = pmu_to_arm_ccn(pmu);
u32 val = readl(ccn->dt.base + CCN_DT_PMCR);
val &= ~CCN_DT_PMCR__PMU_EN;
writel(val, ccn->dt.base + CCN_DT_PMCR);
}
static irqreturn_t arm_ccn_pmu_overflow_handler(struct arm_ccn_dt *dt)
{
u32 pmovsr = readl(dt->base + CCN_DT_PMOVSR);
int idx;
if (!pmovsr)
return IRQ_NONE;
writel(pmovsr, dt->base + CCN_DT_PMOVSR_CLR);
BUILD_BUG_ON(CCN_IDX_PMU_CYCLE_COUNTER != CCN_NUM_PMU_EVENT_COUNTERS);
for (idx = 0; idx < CCN_NUM_PMU_EVENT_COUNTERS + 1; idx++) {
struct perf_event *event = dt->pmu_counters[idx].event;
int overflowed = pmovsr & BIT(idx);
WARN_ON_ONCE(overflowed && !event &&
idx != CCN_IDX_PMU_CYCLE_COUNTER);
if (!event || !overflowed)
continue;
arm_ccn_pmu_event_update(event);
}
return IRQ_HANDLED;
}
static enum hrtimer_restart arm_ccn_pmu_timer_handler(struct hrtimer *hrtimer)
{
struct arm_ccn_dt *dt = container_of(hrtimer, struct arm_ccn_dt,
hrtimer);
unsigned long flags;
local_irq_save(flags);
arm_ccn_pmu_overflow_handler(dt);
local_irq_restore(flags);
hrtimer_forward_now(hrtimer, arm_ccn_pmu_timer_period());
return HRTIMER_RESTART;
}
static int arm_ccn_pmu_offline_cpu(unsigned int cpu)
{
struct arm_ccn_dt *dt;
unsigned int target;
mutex_lock(&arm_ccn_mutex);
list_for_each_entry(dt, &arm_ccn_list, entry) {
struct arm_ccn *ccn = container_of(dt, struct arm_ccn, dt);
if (!cpumask_test_and_clear_cpu(cpu, &dt->cpu))
continue;
target = cpumask_any_but(cpu_online_mask, cpu);
if (target >= nr_cpu_ids)
continue;
perf_pmu_migrate_context(&dt->pmu, cpu, target);
cpumask_set_cpu(target, &dt->cpu);
if (ccn->irq)
WARN_ON(irq_set_affinity_hint(ccn->irq, &dt->cpu) != 0);
}
mutex_unlock(&arm_ccn_mutex);
return 0;
}
static int arm_ccn_pmu_init(struct arm_ccn *ccn)
{
int i;
char *name;
int err;
ccn->dt.base = ccn->base + CCN_REGION_SIZE;
spin_lock_init(&ccn->dt.config_lock);
writel(CCN_DT_PMOVSR_CLR__MASK, ccn->dt.base + CCN_DT_PMOVSR_CLR);
writel(CCN_DT_CTL__DT_EN, ccn->dt.base + CCN_DT_CTL);
writel(CCN_DT_PMCR__OVFL_INTR_EN | CCN_DT_PMCR__PMU_EN,
ccn->dt.base + CCN_DT_PMCR);
writel(0x1, ccn->dt.base + CCN_DT_PMSR_CLR);
for (i = 0; i < ccn->num_xps; i++) {
writel(0, ccn->xp[i].base + CCN_XP_DT_CONFIG);
writel((CCN_XP_DT_CONTROL__WP_ARM_SEL__ALWAYS <<
CCN_XP_DT_CONTROL__WP_ARM_SEL__SHIFT(0)) |
(CCN_XP_DT_CONTROL__WP_ARM_SEL__ALWAYS <<
CCN_XP_DT_CONTROL__WP_ARM_SEL__SHIFT(1)) |
CCN_XP_DT_CONTROL__DT_ENABLE,
ccn->xp[i].base + CCN_XP_DT_CONTROL);
}
ccn->dt.cmp_mask[CCN_IDX_MASK_ANY].l = ~0;
ccn->dt.cmp_mask[CCN_IDX_MASK_ANY].h = ~0;
ccn->dt.cmp_mask[CCN_IDX_MASK_EXACT].l = 0;
ccn->dt.cmp_mask[CCN_IDX_MASK_EXACT].h = 0;
ccn->dt.cmp_mask[CCN_IDX_MASK_ORDER].l = ~0;
ccn->dt.cmp_mask[CCN_IDX_MASK_ORDER].h = ~(0x1 << 15);
ccn->dt.cmp_mask[CCN_IDX_MASK_OPCODE].l = ~0;
ccn->dt.cmp_mask[CCN_IDX_MASK_OPCODE].h = ~(0x1f << 9);
ccn->dt.id = ida_simple_get(&arm_ccn_pmu_ida, 0, 0, GFP_KERNEL);
if (ccn->dt.id == 0) {
name = "ccn";
} else {
int len = snprintf(NULL, 0, "ccn_%d", ccn->dt.id);
name = devm_kzalloc(ccn->dev, len + 1, GFP_KERNEL);
snprintf(name, len + 1, "ccn_%d", ccn->dt.id);
}
ccn->dt.pmu = (struct pmu) {
.attr_groups = arm_ccn_pmu_attr_groups,
.task_ctx_nr = perf_invalid_context,
.event_init = arm_ccn_pmu_event_init,
.add = arm_ccn_pmu_event_add,
.del = arm_ccn_pmu_event_del,
.start = arm_ccn_pmu_event_start,
.stop = arm_ccn_pmu_event_stop,
.read = arm_ccn_pmu_event_read,
.pmu_enable = arm_ccn_pmu_enable,
.pmu_disable = arm_ccn_pmu_disable,
};
if (!ccn->irq) {
dev_info(ccn->dev, "No access to interrupts, using timer.\n");
hrtimer_init(&ccn->dt.hrtimer, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
ccn->dt.hrtimer.function = arm_ccn_pmu_timer_handler;
}
cpumask_set_cpu(smp_processor_id(), &ccn->dt.cpu);
if (ccn->irq) {
err = irq_set_affinity_hint(ccn->irq, &ccn->dt.cpu);
if (err) {
dev_err(ccn->dev, "Failed to set interrupt affinity!\n");
goto error_set_affinity;
}
}
err = perf_pmu_register(&ccn->dt.pmu, name, -1);
if (err)
goto error_pmu_register;
mutex_lock(&arm_ccn_mutex);
list_add(&ccn->dt.entry, &arm_ccn_list);
mutex_unlock(&arm_ccn_mutex);
return 0;
error_pmu_register:
error_set_affinity:
ida_simple_remove(&arm_ccn_pmu_ida, ccn->dt.id);
for (i = 0; i < ccn->num_xps; i++)
writel(0, ccn->xp[i].base + CCN_XP_DT_CONTROL);
writel(0, ccn->dt.base + CCN_DT_PMCR);
return err;
}
static void arm_ccn_pmu_cleanup(struct arm_ccn *ccn)
{
int i;
mutex_lock(&arm_ccn_mutex);
list_del(&ccn->dt.entry);
mutex_unlock(&arm_ccn_mutex);
if (ccn->irq)
irq_set_affinity_hint(ccn->irq, NULL);
for (i = 0; i < ccn->num_xps; i++)
writel(0, ccn->xp[i].base + CCN_XP_DT_CONTROL);
writel(0, ccn->dt.base + CCN_DT_PMCR);
perf_pmu_unregister(&ccn->dt.pmu);
ida_simple_remove(&arm_ccn_pmu_ida, ccn->dt.id);
}
static int arm_ccn_for_each_valid_region(struct arm_ccn *ccn,
int (*callback)(struct arm_ccn *ccn, int region,
void __iomem *base, u32 type, u32 id))
{
int region;
for (region = 0; region < CCN_NUM_REGIONS; region++) {
u32 val, type, id;
void __iomem *base;
int err;
val = readl(ccn->base + CCN_MN_OLY_COMP_LIST_63_0 +
4 * (region / 32));
if (!(val & (1 << (region % 32))))
continue;
base = ccn->base + region * CCN_REGION_SIZE;
val = readl(base + CCN_ALL_OLY_ID);
type = (val >> CCN_ALL_OLY_ID__OLY_ID__SHIFT) &
CCN_ALL_OLY_ID__OLY_ID__MASK;
id = (val >> CCN_ALL_OLY_ID__NODE_ID__SHIFT) &
CCN_ALL_OLY_ID__NODE_ID__MASK;
err = callback(ccn, region, base, type, id);
if (err)
return err;
}
return 0;
}
static int arm_ccn_get_nodes_num(struct arm_ccn *ccn, int region,
void __iomem *base, u32 type, u32 id)
{
if (type == CCN_TYPE_XP && id >= ccn->num_xps)
ccn->num_xps = id + 1;
else if (id >= ccn->num_nodes)
ccn->num_nodes = id + 1;
return 0;
}
static int arm_ccn_init_nodes(struct arm_ccn *ccn, int region,
void __iomem *base, u32 type, u32 id)
{
struct arm_ccn_component *component;
dev_dbg(ccn->dev, "Region %d: id=%u, type=0x%02x\n", region, id, type);
switch (type) {
case CCN_TYPE_MN:
ccn->mn_id = id;
return 0;
case CCN_TYPE_DT:
return 0;
case CCN_TYPE_XP:
component = &ccn->xp[id];
break;
case CCN_TYPE_SBSX:
ccn->sbsx_present = 1;
component = &ccn->node[id];
break;
case CCN_TYPE_SBAS:
ccn->sbas_present = 1;
default:
component = &ccn->node[id];
break;
}
component->base = base;
component->type = type;
return 0;
}
static irqreturn_t arm_ccn_error_handler(struct arm_ccn *ccn,
const u32 *err_sig_val)
{
dev_err(ccn->dev, "Error reported in %08x%08x%08x%08x%08x%08x.\n",
err_sig_val[5], err_sig_val[4], err_sig_val[3],
err_sig_val[2], err_sig_val[1], err_sig_val[0]);
dev_err(ccn->dev, "Disabling interrupt generation for all errors.\n");
writel(CCN_MN_ERRINT_STATUS__ALL_ERRORS__DISABLE,
ccn->base + CCN_MN_ERRINT_STATUS);
return IRQ_HANDLED;
}
static irqreturn_t arm_ccn_irq_handler(int irq, void *dev_id)
{
irqreturn_t res = IRQ_NONE;
struct arm_ccn *ccn = dev_id;
u32 err_sig_val[6];
u32 err_or;
int i;
err_or = err_sig_val[0] = readl(ccn->base + CCN_MN_ERR_SIG_VAL_63_0);
if (err_or & CCN_MN_ERR_SIG_VAL_63_0__DT) {
err_or &= ~CCN_MN_ERR_SIG_VAL_63_0__DT;
res = arm_ccn_pmu_overflow_handler(&ccn->dt);
}
for (i = 1; i < ARRAY_SIZE(err_sig_val); i++) {
err_sig_val[i] = readl(ccn->base +
CCN_MN_ERR_SIG_VAL_63_0 + i * 4);
err_or |= err_sig_val[i];
}
if (err_or)
res |= arm_ccn_error_handler(ccn, err_sig_val);
if (res != IRQ_NONE)
writel(CCN_MN_ERRINT_STATUS__INTREQ__DESSERT,
ccn->base + CCN_MN_ERRINT_STATUS);
return res;
}
static int arm_ccn_probe(struct platform_device *pdev)
{
struct arm_ccn *ccn;
struct resource *res;
unsigned int irq;
int err;
ccn = devm_kzalloc(&pdev->dev, sizeof(*ccn), GFP_KERNEL);
if (!ccn)
return -ENOMEM;
ccn->dev = &pdev->dev;
platform_set_drvdata(pdev, ccn);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res)
return -EINVAL;
if (!devm_request_mem_region(ccn->dev, res->start,
resource_size(res), pdev->name))
return -EBUSY;
ccn->base = devm_ioremap(ccn->dev, res->start,
resource_size(res));
if (!ccn->base)
return -EFAULT;
res = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (!res)
return -EINVAL;
irq = res->start;
writel(CCN_MN_ERRINT_STATUS__PMU_EVENTS__DISABLE,
ccn->base + CCN_MN_ERRINT_STATUS);
if (readl(ccn->base + CCN_MN_ERRINT_STATUS) &
CCN_MN_ERRINT_STATUS__PMU_EVENTS__DISABLED) {
writel(CCN_MN_ERRINT_STATUS__PMU_EVENTS__ENABLE,
ccn->base + CCN_MN_ERRINT_STATUS);
err = devm_request_irq(ccn->dev, irq, arm_ccn_irq_handler,
IRQF_NOBALANCING | IRQF_NO_THREAD,
dev_name(ccn->dev), ccn);
if (err)
return err;
ccn->irq = irq;
}
err = arm_ccn_for_each_valid_region(ccn, arm_ccn_get_nodes_num);
if (err)
return err;
ccn->node = devm_kzalloc(ccn->dev, sizeof(*ccn->node) * ccn->num_nodes,
GFP_KERNEL);
ccn->xp = devm_kzalloc(ccn->dev, sizeof(*ccn->node) * ccn->num_xps,
GFP_KERNEL);
if (!ccn->node || !ccn->xp)
return -ENOMEM;
err = arm_ccn_for_each_valid_region(ccn, arm_ccn_init_nodes);
if (err)
return err;
return arm_ccn_pmu_init(ccn);
}
static int arm_ccn_remove(struct platform_device *pdev)
{
struct arm_ccn *ccn = platform_get_drvdata(pdev);
arm_ccn_pmu_cleanup(ccn);
return 0;
}
static int __init arm_ccn_init(void)
{
int i, ret;
ret = cpuhp_setup_state_nocalls(CPUHP_AP_PERF_ARM_CCN_ONLINE,
"AP_PERF_ARM_CCN_ONLINE", NULL,
arm_ccn_pmu_offline_cpu);
if (ret)
return ret;
for (i = 0; i < ARRAY_SIZE(arm_ccn_pmu_events); i++)
arm_ccn_pmu_events_attrs[i] = &arm_ccn_pmu_events[i].attr.attr;
return platform_driver_register(&arm_ccn_driver);
}
static void __exit arm_ccn_exit(void)
{
cpuhp_remove_state_nocalls(CPUHP_AP_PERF_ARM_CCN_ONLINE);
platform_driver_unregister(&arm_ccn_driver);
}
