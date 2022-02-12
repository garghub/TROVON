static bool is_duplicate_irq(int irq, int *irqs, int nr_irqs)
{
int i;
for (i = 0; i < nr_irqs; i++)
if (irq == irqs[i])
return true;
return false;
}
static int probe_cci_revision(void)
{
int rev;
rev = readl_relaxed(cci_ctrl_base + CCI_PID2) & CCI_PID2_REV_MASK;
rev >>= CCI_PID2_REV_SHIFT;
if (rev < CCI_REV_R1_PX)
return CCI_REV_R0;
else
return CCI_REV_R1;
}
static struct pmu_port_event_ranges *port_range_by_rev(void)
{
int rev = probe_cci_revision();
return &port_event_range[rev];
}
static int pmu_is_valid_slave_event(u8 ev_code)
{
return pmu->port_ranges->slave_min <= ev_code &&
ev_code <= pmu->port_ranges->slave_max;
}
static int pmu_is_valid_master_event(u8 ev_code)
{
return pmu->port_ranges->master_min <= ev_code &&
ev_code <= pmu->port_ranges->master_max;
}
static int pmu_validate_hw_event(u8 hw_event)
{
u8 ev_source = CCI_PMU_EVENT_SOURCE(hw_event);
u8 ev_code = CCI_PMU_EVENT_CODE(hw_event);
switch (ev_source) {
case CCI_PORT_S0:
case CCI_PORT_S1:
case CCI_PORT_S2:
case CCI_PORT_S3:
case CCI_PORT_S4:
if (pmu_is_valid_slave_event(ev_code))
return hw_event;
break;
case CCI_PORT_M0:
case CCI_PORT_M1:
case CCI_PORT_M2:
if (pmu_is_valid_master_event(ev_code))
return hw_event;
break;
}
return -ENOENT;
}
static int pmu_is_valid_counter(struct cci_pmu *cci_pmu, int idx)
{
return CCI_PMU_CYCLE_CNTR_IDX <= idx &&
idx <= CCI_PMU_CNTR_LAST(cci_pmu);
}
static u32 pmu_read_register(int idx, unsigned int offset)
{
return readl_relaxed(pmu->base + CCI_PMU_CNTR_BASE(idx) + offset);
}
static void pmu_write_register(u32 value, int idx, unsigned int offset)
{
return writel_relaxed(value, pmu->base + CCI_PMU_CNTR_BASE(idx) + offset);
}
static void pmu_disable_counter(int idx)
{
pmu_write_register(0, idx, CCI_PMU_CNTR_CTRL);
}
static void pmu_enable_counter(int idx)
{
pmu_write_register(1, idx, CCI_PMU_CNTR_CTRL);
}
static void pmu_set_event(int idx, unsigned long event)
{
event &= CCI_PMU_EVENT_MASK;
pmu_write_register(event, idx, CCI_PMU_EVT_SEL);
}
static u32 pmu_get_max_counters(void)
{
u32 n_cnts = (readl_relaxed(cci_ctrl_base + CCI_PMCR) &
CCI_PMCR_NCNT_MASK) >> CCI_PMCR_NCNT_SHIFT;
return n_cnts + 1;
}
static int pmu_get_event_idx(struct cci_pmu_hw_events *hw, struct perf_event *event)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
struct hw_perf_event *hw_event = &event->hw;
unsigned long cci_event = hw_event->config_base & CCI_PMU_EVENT_MASK;
int idx;
if (cci_event == CCI_PMU_CYCLES) {
if (test_and_set_bit(CCI_PMU_CYCLE_CNTR_IDX, hw->used_mask))
return -EAGAIN;
return CCI_PMU_CYCLE_CNTR_IDX;
}
for (idx = CCI_PMU_CNTR0_IDX; idx <= CCI_PMU_CNTR_LAST(cci_pmu); ++idx)
if (!test_and_set_bit(idx, hw->used_mask))
return idx;
return -EAGAIN;
}
static int pmu_map_event(struct perf_event *event)
{
int mapping;
u8 config = event->attr.config & CCI_PMU_EVENT_MASK;
if (event->attr.type < PERF_TYPE_MAX)
return -ENOENT;
if (config == CCI_PMU_CYCLES)
mapping = config;
else
mapping = pmu_validate_hw_event(config);
return mapping;
}
static int pmu_request_irq(struct cci_pmu *cci_pmu, irq_handler_t handler)
{
int i;
struct platform_device *pmu_device = cci_pmu->plat_device;
if (unlikely(!pmu_device))
return -ENODEV;
if (pmu->nr_irqs < 1) {
dev_err(&pmu_device->dev, "no irqs for CCI PMUs defined\n");
return -ENODEV;
}
for (i = 0; i < pmu->nr_irqs; i++) {
int err = request_irq(pmu->irqs[i], handler, IRQF_SHARED,
"arm-cci-pmu", cci_pmu);
if (err) {
dev_err(&pmu_device->dev, "unable to request IRQ%d for ARM CCI PMU counters\n",
pmu->irqs[i]);
return err;
}
set_bit(i, &pmu->active_irqs);
}
return 0;
}
static void pmu_free_irq(struct cci_pmu *cci_pmu)
{
int i;
for (i = 0; i < pmu->nr_irqs; i++) {
if (!test_and_clear_bit(i, &pmu->active_irqs))
continue;
free_irq(pmu->irqs[i], cci_pmu);
}
}
static u32 pmu_read_counter(struct perf_event *event)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
struct hw_perf_event *hw_counter = &event->hw;
int idx = hw_counter->idx;
u32 value;
if (unlikely(!pmu_is_valid_counter(cci_pmu, idx))) {
dev_err(&cci_pmu->plat_device->dev, "Invalid CCI PMU counter %d\n", idx);
return 0;
}
value = pmu_read_register(idx, CCI_PMU_CNTR);
return value;
}
static void pmu_write_counter(struct perf_event *event, u32 value)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
struct hw_perf_event *hw_counter = &event->hw;
int idx = hw_counter->idx;
if (unlikely(!pmu_is_valid_counter(cci_pmu, idx)))
dev_err(&cci_pmu->plat_device->dev, "Invalid CCI PMU counter %d\n", idx);
else
pmu_write_register(value, idx, CCI_PMU_CNTR);
}
static u64 pmu_event_update(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
u64 delta, prev_raw_count, new_raw_count;
do {
prev_raw_count = local64_read(&hwc->prev_count);
new_raw_count = pmu_read_counter(event);
} while (local64_cmpxchg(&hwc->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count);
delta = (new_raw_count - prev_raw_count) & CCI_PMU_CNTR_MASK;
local64_add(delta, &event->count);
return new_raw_count;
}
static void pmu_read(struct perf_event *event)
{
pmu_event_update(event);
}
void pmu_event_set_period(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
u64 val = 1ULL << 31;
local64_set(&hwc->prev_count, val);
pmu_write_counter(event, val);
}
static irqreturn_t pmu_handle_irq(int irq_num, void *dev)
{
unsigned long flags;
struct cci_pmu *cci_pmu = dev;
struct cci_pmu_hw_events *events = &pmu->hw_events;
int idx, handled = IRQ_NONE;
raw_spin_lock_irqsave(&events->pmu_lock, flags);
for (idx = CCI_PMU_CYCLE_CNTR_IDX; idx <= CCI_PMU_CNTR_LAST(cci_pmu); idx++) {
struct perf_event *event = events->events[idx];
struct hw_perf_event *hw_counter;
if (!event)
continue;
hw_counter = &event->hw;
if (!(pmu_read_register(idx, CCI_PMU_OVRFLW) &
CCI_PMU_OVRFLW_FLAG))
continue;
pmu_write_register(CCI_PMU_OVRFLW_FLAG, idx, CCI_PMU_OVRFLW);
pmu_event_update(event);
pmu_event_set_period(event);
handled = IRQ_HANDLED;
}
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
return IRQ_RETVAL(handled);
}
static int cci_pmu_get_hw(struct cci_pmu *cci_pmu)
{
int ret = pmu_request_irq(cci_pmu, pmu_handle_irq);
if (ret) {
pmu_free_irq(cci_pmu);
return ret;
}
return 0;
}
static void cci_pmu_put_hw(struct cci_pmu *cci_pmu)
{
pmu_free_irq(cci_pmu);
}
static void hw_perf_event_destroy(struct perf_event *event)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
atomic_t *active_events = &cci_pmu->active_events;
struct mutex *reserve_mutex = &cci_pmu->reserve_mutex;
if (atomic_dec_and_mutex_lock(active_events, reserve_mutex)) {
cci_pmu_put_hw(cci_pmu);
mutex_unlock(reserve_mutex);
}
}
static void cci_pmu_enable(struct pmu *pmu)
{
struct cci_pmu *cci_pmu = to_cci_pmu(pmu);
struct cci_pmu_hw_events *hw_events = &cci_pmu->hw_events;
int enabled = bitmap_weight(hw_events->used_mask, cci_pmu->num_events);
unsigned long flags;
u32 val;
if (!enabled)
return;
raw_spin_lock_irqsave(&hw_events->pmu_lock, flags);
val = readl_relaxed(cci_ctrl_base + CCI_PMCR) | CCI_PMCR_CEN;
writel(val, cci_ctrl_base + CCI_PMCR);
raw_spin_unlock_irqrestore(&hw_events->pmu_lock, flags);
}
static void cci_pmu_disable(struct pmu *pmu)
{
struct cci_pmu *cci_pmu = to_cci_pmu(pmu);
struct cci_pmu_hw_events *hw_events = &cci_pmu->hw_events;
unsigned long flags;
u32 val;
raw_spin_lock_irqsave(&hw_events->pmu_lock, flags);
val = readl_relaxed(cci_ctrl_base + CCI_PMCR) & ~CCI_PMCR_CEN;
writel(val, cci_ctrl_base + CCI_PMCR);
raw_spin_unlock_irqrestore(&hw_events->pmu_lock, flags);
}
static void cci_pmu_start(struct perf_event *event, int pmu_flags)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
struct cci_pmu_hw_events *hw_events = &cci_pmu->hw_events;
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
unsigned long flags;
if (pmu_flags & PERF_EF_RELOAD)
WARN_ON_ONCE(!(hwc->state & PERF_HES_UPTODATE));
hwc->state = 0;
if (unlikely(!pmu_is_valid_counter(cci_pmu, idx))) {
dev_err(&cci_pmu->plat_device->dev, "Invalid CCI PMU counter %d\n", idx);
return;
}
raw_spin_lock_irqsave(&hw_events->pmu_lock, flags);
if (idx != CCI_PMU_CYCLE_CNTR_IDX)
pmu_set_event(idx, hwc->config_base);
pmu_event_set_period(event);
pmu_enable_counter(idx);
raw_spin_unlock_irqrestore(&hw_events->pmu_lock, flags);
}
static void cci_pmu_stop(struct perf_event *event, int pmu_flags)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
if (hwc->state & PERF_HES_STOPPED)
return;
if (unlikely(!pmu_is_valid_counter(cci_pmu, idx))) {
dev_err(&cci_pmu->plat_device->dev, "Invalid CCI PMU counter %d\n", idx);
return;
}
pmu_disable_counter(idx);
pmu_event_update(event);
hwc->state |= PERF_HES_STOPPED | PERF_HES_UPTODATE;
}
static int cci_pmu_add(struct perf_event *event, int flags)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
struct cci_pmu_hw_events *hw_events = &cci_pmu->hw_events;
struct hw_perf_event *hwc = &event->hw;
int idx;
int err = 0;
perf_pmu_disable(event->pmu);
idx = pmu_get_event_idx(hw_events, event);
if (idx < 0) {
err = idx;
goto out;
}
event->hw.idx = idx;
hw_events->events[idx] = event;
hwc->state = PERF_HES_STOPPED | PERF_HES_UPTODATE;
if (flags & PERF_EF_START)
cci_pmu_start(event, PERF_EF_RELOAD);
perf_event_update_userpage(event);
out:
perf_pmu_enable(event->pmu);
return err;
}
static void cci_pmu_del(struct perf_event *event, int flags)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
struct cci_pmu_hw_events *hw_events = &cci_pmu->hw_events;
struct hw_perf_event *hwc = &event->hw;
int idx = hwc->idx;
cci_pmu_stop(event, PERF_EF_UPDATE);
hw_events->events[idx] = NULL;
clear_bit(idx, hw_events->used_mask);
perf_event_update_userpage(event);
}
static int
validate_event(struct cci_pmu_hw_events *hw_events,
struct perf_event *event)
{
if (is_software_event(event))
return 1;
if (event->state < PERF_EVENT_STATE_OFF)
return 1;
if (event->state == PERF_EVENT_STATE_OFF && !event->attr.enable_on_exec)
return 1;
return pmu_get_event_idx(hw_events, event) >= 0;
}
static int
validate_group(struct perf_event *event)
{
struct perf_event *sibling, *leader = event->group_leader;
struct cci_pmu_hw_events fake_pmu = {
.used_mask = CPU_BITS_NONE,
};
if (!validate_event(&fake_pmu, leader))
return -EINVAL;
list_for_each_entry(sibling, &leader->sibling_list, group_entry) {
if (!validate_event(&fake_pmu, sibling))
return -EINVAL;
}
if (!validate_event(&fake_pmu, event))
return -EINVAL;
return 0;
}
static int
__hw_perf_event_init(struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
int mapping;
mapping = pmu_map_event(event);
if (mapping < 0) {
pr_debug("event %x:%llx not supported\n", event->attr.type,
event->attr.config);
return mapping;
}
hwc->idx = -1;
hwc->config_base = 0;
hwc->config = 0;
hwc->event_base = 0;
hwc->config_base |= (unsigned long)mapping;
hwc->sample_period = CCI_PMU_CNTR_MASK >> 1;
hwc->last_period = hwc->sample_period;
local64_set(&hwc->period_left, hwc->sample_period);
if (event->group_leader != event) {
if (validate_group(event) != 0)
return -EINVAL;
}
return 0;
}
static int cci_pmu_event_init(struct perf_event *event)
{
struct cci_pmu *cci_pmu = to_cci_pmu(event->pmu);
atomic_t *active_events = &cci_pmu->active_events;
int err = 0;
int cpu;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (is_sampling_event(event) || event->attach_state & PERF_ATTACH_TASK)
return -EOPNOTSUPP;
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest)
return -EINVAL;
cpu = cpumask_first(&cci_pmu->cpus);
if (event->cpu < 0 || cpu < 0)
return -EINVAL;
event->cpu = cpu;
event->destroy = hw_perf_event_destroy;
if (!atomic_inc_not_zero(active_events)) {
mutex_lock(&cci_pmu->reserve_mutex);
if (atomic_read(active_events) == 0)
err = cci_pmu_get_hw(cci_pmu);
if (!err)
atomic_inc(active_events);
mutex_unlock(&cci_pmu->reserve_mutex);
}
if (err)
return err;
err = __hw_perf_event_init(event);
if (err)
hw_perf_event_destroy(event);
return err;
}
static ssize_t pmu_attr_cpumask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
int n = cpulist_scnprintf(buf, PAGE_SIZE - 2, &pmu->cpus);
buf[n++] = '\n';
buf[n] = '\0';
return n;
}
static int cci_pmu_init(struct cci_pmu *cci_pmu, struct platform_device *pdev)
{
char *name = pmu_names[probe_cci_revision()];
cci_pmu->pmu = (struct pmu) {
.name = pmu_names[probe_cci_revision()],
.task_ctx_nr = perf_invalid_context,
.pmu_enable = cci_pmu_enable,
.pmu_disable = cci_pmu_disable,
.event_init = cci_pmu_event_init,
.add = cci_pmu_add,
.del = cci_pmu_del,
.start = cci_pmu_start,
.stop = cci_pmu_stop,
.read = pmu_read,
.attr_groups = pmu_attr_groups,
};
cci_pmu->plat_device = pdev;
cci_pmu->num_events = pmu_get_max_counters();
return perf_pmu_register(&cci_pmu->pmu, name, -1);
}
static int cci_pmu_cpu_notifier(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (long)hcpu;
unsigned int target;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_PREPARE:
if (!cpumask_test_and_clear_cpu(cpu, &pmu->cpus))
break;
target = cpumask_any_but(cpu_online_mask, cpu);
if (target < 0)
break;
cpumask_set_cpu(target, &pmu->cpus);
default:
break;
}
return NOTIFY_OK;
}
static int cci_pmu_probe(struct platform_device *pdev)
{
struct resource *res;
int i, ret, irq;
pmu = devm_kzalloc(&pdev->dev, sizeof(*pmu), GFP_KERNEL);
if (!pmu)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
pmu->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(pmu->base))
return -ENOMEM;
pmu->nr_irqs = 0;
for (i = 0; i < CCI_PMU_MAX_HW_EVENTS; i++) {
irq = platform_get_irq(pdev, i);
if (irq < 0)
break;
if (is_duplicate_irq(irq, pmu->irqs, pmu->nr_irqs))
continue;
pmu->irqs[pmu->nr_irqs++] = irq;
}
if (i < CCI_PMU_MAX_HW_EVENTS) {
dev_warn(&pdev->dev, "In-correct number of interrupts: %d, should be %d\n",
i, CCI_PMU_MAX_HW_EVENTS);
return -EINVAL;
}
pmu->port_ranges = port_range_by_rev();
if (!pmu->port_ranges) {
dev_warn(&pdev->dev, "CCI PMU version not supported\n");
return -EINVAL;
}
raw_spin_lock_init(&pmu->hw_events.pmu_lock);
mutex_init(&pmu->reserve_mutex);
atomic_set(&pmu->active_events, 0);
cpumask_set_cpu(smp_processor_id(), &pmu->cpus);
ret = register_cpu_notifier(&cci_pmu_cpu_nb);
if (ret)
return ret;
ret = cci_pmu_init(pmu, pdev);
if (ret)
return ret;
return 0;
}
static int cci_platform_probe(struct platform_device *pdev)
{
if (!cci_probed())
return -ENODEV;
return of_platform_populate(pdev->dev.of_node, NULL, NULL, &pdev->dev);
}
static inline void init_cpu_port(struct cpu_port *port, u32 index, u64 mpidr)
{
port->port = PORT_VALID | index;
port->mpidr = mpidr;
}
static inline bool cpu_port_is_valid(struct cpu_port *port)
{
return !!(port->port & PORT_VALID);
}
static inline bool cpu_port_match(struct cpu_port *port, u64 mpidr)
{
return port->mpidr == (mpidr & MPIDR_HWID_BITMASK);
}
static int __cci_ace_get_port(struct device_node *dn, int type)
{
int i;
bool ace_match;
struct device_node *cci_portn;
cci_portn = of_parse_phandle(dn, "cci-control-port", 0);
for (i = 0; i < nb_cci_ports; i++) {
ace_match = ports[i].type == type;
if (ace_match && cci_portn == ports[i].dn)
return i;
}
return -ENODEV;
}
int cci_ace_get_port(struct device_node *dn)
{
return __cci_ace_get_port(dn, ACE_LITE_PORT);
}
static void cci_ace_init_ports(void)
{
int port, cpu;
struct device_node *cpun;
for_each_possible_cpu(cpu) {
cpun = of_get_cpu_node(cpu, NULL);
if (WARN(!cpun, "Missing cpu device node\n"))
continue;
port = __cci_ace_get_port(cpun, ACE_PORT);
if (port < 0)
continue;
init_cpu_port(&cpu_port[cpu], port, cpu_logical_map(cpu));
}
for_each_possible_cpu(cpu) {
WARN(!cpu_port_is_valid(&cpu_port[cpu]),
"CPU %u does not have an associated CCI port\n",
cpu);
}
}
static void notrace cci_port_control(unsigned int port, bool enable)
{
void __iomem *base = ports[port].base;
writel_relaxed(enable ? CCI_ENABLE_REQ : 0, base + CCI_PORT_CTRL);
while (readl_relaxed(cci_ctrl_base + CCI_CTRL_STATUS) & 0x1)
;
}
int notrace cci_disable_port_by_cpu(u64 mpidr)
{
int cpu;
bool is_valid;
for (cpu = 0; cpu < nr_cpu_ids; cpu++) {
is_valid = cpu_port_is_valid(&cpu_port[cpu]);
if (is_valid && cpu_port_match(&cpu_port[cpu], mpidr)) {
cci_port_control(cpu_port[cpu].port, false);
return 0;
}
}
return -ENODEV;
}
asmlinkage void __naked cci_enable_port_for_self(void)
{
asm volatile ("\n"
" .arch armv7-a\n"
" mrc p15, 0, r0, c0, c0, 5 @ get MPIDR value \n"
" and r0, r0, #"__stringify(MPIDR_HWID_BITMASK)" \n"
" adr r1, 5f \n"
" ldr r2, [r1] \n"
" add r1, r1, r2 @ &cpu_port \n"
" add ip, r1, %[sizeof_cpu_port] \n"
"1: ldr r2, [r1, %[offsetof_cpu_port_mpidr_lsb]] \n"
" cmp r2, r0 @ compare MPIDR \n"
" bne 2f \n"
" ldr r3, [r1, %[offsetof_cpu_port_port]] \n"
" tst r3, #"__stringify(PORT_VALID)" \n"
" bne 3f \n"
"2: add r1, r1, %[sizeof_struct_cpu_port] \n"
" cmp r1, ip @ done? \n"
" blo 1b \n"
"cci_port_not_found: \n"
" wfi \n"
" wfe \n"
" b cci_port_not_found \n"
"3: bic r3, r3, #"__stringify(PORT_VALID)" \n"
" adr r0, 6f \n"
" ldmia r0, {r1, r2} \n"
" sub r1, r1, r0 @ virt - phys \n"
" ldr r0, [r0, r2] @ *(&ports) \n"
" mov r2, %[sizeof_struct_ace_port] \n"
" mla r0, r2, r3, r0 @ &ports[index] \n"
" sub r0, r0, r1 @ virt_to_phys() \n"
" ldr r0, [r0, %[offsetof_port_phys]] \n"
" mov r3, %[cci_enable_req]\n"
" str r3, [r0, #"__stringify(CCI_PORT_CTRL)"] \n"
" adr r1, 7f \n"
" ldr r0, [r1] \n"
" ldr r0, [r0, r1] @ cci_ctrl_base \n"
"4: ldr r1, [r0, #"__stringify(CCI_CTRL_STATUS)"] \n"
" tst r1, %[cci_control_status_bits] \n"
" bne 4b \n"
" mov r0, #0 \n"
" bx lr \n"
" .align 2 \n"
"5: .word cpu_port - . \n"
"6: .word . \n"
" .word ports - 6b \n"
"7: .word cci_ctrl_phys - . \n"
: :
[sizeof_cpu_port] "i" (sizeof(cpu_port)),
[cci_enable_req] "i" cpu_to_le32(CCI_ENABLE_REQ),
[cci_control_status_bits] "i" cpu_to_le32(1),
#ifndef __ARMEB__
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)),
#else
[offsetof_cpu_port_mpidr_lsb] "i" (offsetof(struct cpu_port, mpidr)+4),
#endif
[offsetof_cpu_port_port] "i" (offsetof(struct cpu_port, port)),
[sizeof_struct_cpu_port] "i" (sizeof(struct cpu_port)),
[sizeof_struct_ace_port] "i" (sizeof(struct cci_ace_port)),
[offsetof_port_phys] "i" (offsetof(struct cci_ace_port, phys)) );
unreachable();
}
int notrace __cci_control_port_by_device(struct device_node *dn, bool enable)
{
int port;
if (!dn)
return -ENODEV;
port = __cci_ace_get_port(dn, ACE_LITE_PORT);
if (WARN_ONCE(port < 0, "node %s ACE lite port look-up failure\n",
dn->full_name))
return -ENODEV;
cci_port_control(port, enable);
return 0;
}
int notrace __cci_control_port_by_index(u32 port, bool enable)
{
if (port >= nb_cci_ports || ports[port].type == ACE_INVALID_PORT)
return -ENODEV;
if (ports[port].type == ACE_PORT)
return -EPERM;
cci_port_control(port, enable);
return 0;
}
static int cci_probe(void)
{
struct cci_nb_ports const *cci_config;
int ret, i, nb_ace = 0, nb_ace_lite = 0;
struct device_node *np, *cp;
struct resource res;
const char *match_str;
bool is_ace;
np = of_find_matching_node(NULL, arm_cci_matches);
if (!np)
return -ENODEV;
if (!of_device_is_available(np))
return -ENODEV;
cci_config = of_match_node(arm_cci_matches, np)->data;
if (!cci_config)
return -ENODEV;
nb_cci_ports = cci_config->nb_ace + cci_config->nb_ace_lite;
ports = kcalloc(nb_cci_ports, sizeof(*ports), GFP_KERNEL);
if (!ports)
return -ENOMEM;
ret = of_address_to_resource(np, 0, &res);
if (!ret) {
cci_ctrl_base = ioremap(res.start, resource_size(&res));
cci_ctrl_phys = res.start;
}
if (ret || !cci_ctrl_base) {
WARN(1, "unable to ioremap CCI ctrl\n");
ret = -ENXIO;
goto memalloc_err;
}
for_each_child_of_node(np, cp) {
if (!of_match_node(arm_cci_ctrl_if_matches, cp))
continue;
i = nb_ace + nb_ace_lite;
if (i >= nb_cci_ports)
break;
if (of_property_read_string(cp, "interface-type",
&match_str)) {
WARN(1, "node %s missing interface-type property\n",
cp->full_name);
continue;
}
is_ace = strcmp(match_str, "ace") == 0;
if (!is_ace && strcmp(match_str, "ace-lite")) {
WARN(1, "node %s containing invalid interface-type property, skipping it\n",
cp->full_name);
continue;
}
ret = of_address_to_resource(cp, 0, &res);
if (!ret) {
ports[i].base = ioremap(res.start, resource_size(&res));
ports[i].phys = res.start;
}
if (ret || !ports[i].base) {
WARN(1, "unable to ioremap CCI port %d\n", i);
continue;
}
if (is_ace) {
if (WARN_ON(nb_ace >= cci_config->nb_ace))
continue;
ports[i].type = ACE_PORT;
++nb_ace;
} else {
if (WARN_ON(nb_ace_lite >= cci_config->nb_ace_lite))
continue;
ports[i].type = ACE_LITE_PORT;
++nb_ace_lite;
}
ports[i].dn = cp;
}
cci_ace_init_ports();
sync_cache_w(&cci_ctrl_base);
sync_cache_w(&cci_ctrl_phys);
sync_cache_w(&ports);
sync_cache_w(&cpu_port);
__sync_cache_range_w(ports, sizeof(*ports) * nb_cci_ports);
pr_info("ARM CCI driver probed\n");
return 0;
memalloc_err:
kfree(ports);
return ret;
}
static int cci_init(void)
{
if (cci_init_status != -EAGAIN)
return cci_init_status;
mutex_lock(&cci_probing);
if (cci_init_status == -EAGAIN)
cci_init_status = cci_probe();
mutex_unlock(&cci_probing);
return cci_init_status;
}
static int __init cci_platform_init(void)
{
int ret;
ret = platform_driver_register(&cci_pmu_driver);
if (ret)
return ret;
return platform_driver_register(&cci_platform_driver);
}
static int __init cci_platform_init(void)
{
return 0;
}
bool cci_probed(void)
{
return cci_init() == 0;
}
