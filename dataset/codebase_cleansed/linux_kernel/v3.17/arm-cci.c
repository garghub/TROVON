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
static int pmu_is_valid_counter(struct arm_pmu *cci_pmu, int idx)
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
static struct pmu_hw_events *pmu_get_hw_events(void)
{
return &pmu->hw_events;
}
static int pmu_get_event_idx(struct pmu_hw_events *hw, struct perf_event *event)
{
struct arm_pmu *cci_pmu = to_arm_pmu(event->pmu);
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
static int pmu_request_irq(struct arm_pmu *cci_pmu, irq_handler_t handler)
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
static irqreturn_t pmu_handle_irq(int irq_num, void *dev)
{
unsigned long flags;
struct arm_pmu *cci_pmu = (struct arm_pmu *)dev;
struct pmu_hw_events *events = cci_pmu->get_hw_events();
struct perf_sample_data data;
struct pt_regs *regs;
int idx, handled = IRQ_NONE;
raw_spin_lock_irqsave(&events->pmu_lock, flags);
regs = get_irq_regs();
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
handled = IRQ_HANDLED;
armpmu_event_update(event);
perf_sample_data_init(&data, 0, hw_counter->last_period);
if (!armpmu_event_set_period(event))
continue;
if (perf_event_overflow(event, &data, regs))
cci_pmu->disable(event);
}
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
return IRQ_RETVAL(handled);
}
static void pmu_free_irq(struct arm_pmu *cci_pmu)
{
int i;
for (i = 0; i < pmu->nr_irqs; i++) {
if (!test_and_clear_bit(i, &pmu->active_irqs))
continue;
free_irq(pmu->irqs[i], cci_pmu);
}
}
static void pmu_enable_event(struct perf_event *event)
{
unsigned long flags;
struct arm_pmu *cci_pmu = to_arm_pmu(event->pmu);
struct pmu_hw_events *events = cci_pmu->get_hw_events();
struct hw_perf_event *hw_counter = &event->hw;
int idx = hw_counter->idx;
if (unlikely(!pmu_is_valid_counter(cci_pmu, idx))) {
dev_err(&cci_pmu->plat_device->dev, "Invalid CCI PMU counter %d\n", idx);
return;
}
raw_spin_lock_irqsave(&events->pmu_lock, flags);
if (idx != CCI_PMU_CYCLE_CNTR_IDX)
pmu_set_event(idx, hw_counter->config_base);
pmu_enable_counter(idx);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void pmu_disable_event(struct perf_event *event)
{
struct arm_pmu *cci_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hw_counter = &event->hw;
int idx = hw_counter->idx;
if (unlikely(!pmu_is_valid_counter(cci_pmu, idx))) {
dev_err(&cci_pmu->plat_device->dev, "Invalid CCI PMU counter %d\n", idx);
return;
}
pmu_disable_counter(idx);
}
static void pmu_start(struct arm_pmu *cci_pmu)
{
u32 val;
unsigned long flags;
struct pmu_hw_events *events = cci_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = readl_relaxed(cci_ctrl_base + CCI_PMCR) | CCI_PMCR_CEN;
writel(val, cci_ctrl_base + CCI_PMCR);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static void pmu_stop(struct arm_pmu *cci_pmu)
{
u32 val;
unsigned long flags;
struct pmu_hw_events *events = cci_pmu->get_hw_events();
raw_spin_lock_irqsave(&events->pmu_lock, flags);
val = readl_relaxed(cci_ctrl_base + CCI_PMCR) & ~CCI_PMCR_CEN;
writel(val, cci_ctrl_base + CCI_PMCR);
raw_spin_unlock_irqrestore(&events->pmu_lock, flags);
}
static u32 pmu_read_counter(struct perf_event *event)
{
struct arm_pmu *cci_pmu = to_arm_pmu(event->pmu);
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
struct arm_pmu *cci_pmu = to_arm_pmu(event->pmu);
struct hw_perf_event *hw_counter = &event->hw;
int idx = hw_counter->idx;
if (unlikely(!pmu_is_valid_counter(cci_pmu, idx)))
dev_err(&cci_pmu->plat_device->dev, "Invalid CCI PMU counter %d\n", idx);
else
pmu_write_register(value, idx, CCI_PMU_CNTR);
}
static int cci_pmu_init(struct arm_pmu *cci_pmu, struct platform_device *pdev)
{
*cci_pmu = (struct arm_pmu){
.name = pmu_names[probe_cci_revision()],
.max_period = (1LLU << 32) - 1,
.get_hw_events = pmu_get_hw_events,
.get_event_idx = pmu_get_event_idx,
.map_event = pmu_map_event,
.request_irq = pmu_request_irq,
.handle_irq = pmu_handle_irq,
.free_irq = pmu_free_irq,
.enable = pmu_enable_event,
.disable = pmu_disable_event,
.start = pmu_start,
.stop = pmu_stop,
.read_counter = pmu_read_counter,
.write_counter = pmu_write_counter,
};
cci_pmu->plat_device = pdev;
cci_pmu->num_events = pmu_get_max_counters();
return armpmu_register(cci_pmu, -1);
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
pmu->cci_pmu = devm_kzalloc(&pdev->dev, sizeof(*(pmu->cci_pmu)), GFP_KERNEL);
if (!pmu->cci_pmu)
return -ENOMEM;
pmu->hw_events.events = pmu->events;
pmu->hw_events.used_mask = pmu->used_mask;
raw_spin_lock_init(&pmu->hw_events.pmu_lock);
ret = cci_pmu_init(pmu->cci_pmu, pdev);
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
