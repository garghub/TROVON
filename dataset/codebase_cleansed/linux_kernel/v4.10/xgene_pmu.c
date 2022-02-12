static ssize_t xgene_pmu_format_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dev_ext_attribute *eattr;
eattr = container_of(attr, struct dev_ext_attribute, attr);
return sprintf(buf, "%s\n", (char *) eattr->var);
}
static ssize_t xgene_pmu_event_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct dev_ext_attribute *eattr;
eattr = container_of(attr, struct dev_ext_attribute, attr);
return sprintf(buf, "config=0x%lx\n", (unsigned long) eattr->var);
}
static ssize_t xgene_pmu_cpumask_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(dev_get_drvdata(dev));
return cpumap_print_to_pagebuf(true, buf, &pmu_dev->parent->cpu);
}
static int get_next_avail_cntr(struct xgene_pmu_dev *pmu_dev)
{
int cntr;
cntr = find_first_zero_bit(pmu_dev->cntr_assign_mask,
pmu_dev->max_counters);
if (cntr == pmu_dev->max_counters)
return -ENOSPC;
set_bit(cntr, pmu_dev->cntr_assign_mask);
return cntr;
}
static void clear_avail_cntr(struct xgene_pmu_dev *pmu_dev, int cntr)
{
clear_bit(cntr, pmu_dev->cntr_assign_mask);
}
static inline void xgene_pmu_mask_int(struct xgene_pmu *xgene_pmu)
{
writel(PCPPMU_INTENMASK, xgene_pmu->pcppmu_csr + PCPPMU_INTMASK_REG);
}
static inline void xgene_pmu_unmask_int(struct xgene_pmu *xgene_pmu)
{
writel(PCPPMU_INTCLRMASK, xgene_pmu->pcppmu_csr + PCPPMU_INTMASK_REG);
}
static inline u32 xgene_pmu_read_counter(struct xgene_pmu_dev *pmu_dev, int idx)
{
return readl(pmu_dev->inf->csr + PMU_PMEVCNTR0 + (4 * idx));
}
static inline void
xgene_pmu_write_counter(struct xgene_pmu_dev *pmu_dev, int idx, u32 val)
{
writel(val, pmu_dev->inf->csr + PMU_PMEVCNTR0 + (4 * idx));
}
static inline void
xgene_pmu_write_evttype(struct xgene_pmu_dev *pmu_dev, int idx, u32 val)
{
writel(val, pmu_dev->inf->csr + PMU_PMEVTYPER0 + (4 * idx));
}
static inline void
xgene_pmu_write_agentmsk(struct xgene_pmu_dev *pmu_dev, u32 val)
{
writel(val, pmu_dev->inf->csr + PMU_PMAMR0);
}
static inline void
xgene_pmu_write_agent1msk(struct xgene_pmu_dev *pmu_dev, u32 val)
{
writel(val, pmu_dev->inf->csr + PMU_PMAMR1);
}
static inline void
xgene_pmu_enable_counter(struct xgene_pmu_dev *pmu_dev, int idx)
{
u32 val;
val = readl(pmu_dev->inf->csr + PMU_PMCNTENSET);
val |= 1 << idx;
writel(val, pmu_dev->inf->csr + PMU_PMCNTENSET);
}
static inline void
xgene_pmu_disable_counter(struct xgene_pmu_dev *pmu_dev, int idx)
{
u32 val;
val = readl(pmu_dev->inf->csr + PMU_PMCNTENCLR);
val |= 1 << idx;
writel(val, pmu_dev->inf->csr + PMU_PMCNTENCLR);
}
static inline void
xgene_pmu_enable_counter_int(struct xgene_pmu_dev *pmu_dev, int idx)
{
u32 val;
val = readl(pmu_dev->inf->csr + PMU_PMINTENSET);
val |= 1 << idx;
writel(val, pmu_dev->inf->csr + PMU_PMINTENSET);
}
static inline void
xgene_pmu_disable_counter_int(struct xgene_pmu_dev *pmu_dev, int idx)
{
u32 val;
val = readl(pmu_dev->inf->csr + PMU_PMINTENCLR);
val |= 1 << idx;
writel(val, pmu_dev->inf->csr + PMU_PMINTENCLR);
}
static inline void xgene_pmu_reset_counters(struct xgene_pmu_dev *pmu_dev)
{
u32 val;
val = readl(pmu_dev->inf->csr + PMU_PMCR);
val |= PMU_PMCR_P;
writel(val, pmu_dev->inf->csr + PMU_PMCR);
}
static inline void xgene_pmu_start_counters(struct xgene_pmu_dev *pmu_dev)
{
u32 val;
val = readl(pmu_dev->inf->csr + PMU_PMCR);
val |= PMU_PMCR_E;
writel(val, pmu_dev->inf->csr + PMU_PMCR);
}
static inline void xgene_pmu_stop_counters(struct xgene_pmu_dev *pmu_dev)
{
u32 val;
val = readl(pmu_dev->inf->csr + PMU_PMCR);
val &= ~PMU_PMCR_E;
writel(val, pmu_dev->inf->csr + PMU_PMCR);
}
static void xgene_perf_pmu_enable(struct pmu *pmu)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(pmu);
int enabled = bitmap_weight(pmu_dev->cntr_assign_mask,
pmu_dev->max_counters);
if (!enabled)
return;
xgene_pmu_start_counters(pmu_dev);
}
static void xgene_perf_pmu_disable(struct pmu *pmu)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(pmu);
xgene_pmu_stop_counters(pmu_dev);
}
static int xgene_perf_event_init(struct perf_event *event)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(event->pmu);
struct hw_perf_event *hw = &event->hw;
struct perf_event *sibling;
if (event->attr.type != event->pmu->type)
return -ENOENT;
if (is_sampling_event(event) || event->attach_state & PERF_ATTACH_TASK)
return -EINVAL;
if (event->attr.exclude_user || event->attr.exclude_kernel ||
event->attr.exclude_host || event->attr.exclude_guest)
return -EINVAL;
if (event->cpu < 0)
return -EINVAL;
event->cpu = cpumask_first(&pmu_dev->parent->cpu);
hw->config = event->attr.config;
hw->config_base = event->attr.config1;
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
static void xgene_perf_enable_event(struct perf_event *event)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(event->pmu);
xgene_pmu_write_evttype(pmu_dev, GET_CNTR(event), GET_EVENTID(event));
xgene_pmu_write_agentmsk(pmu_dev, ~((u32)GET_AGENTID(event)));
if (pmu_dev->inf->type == PMU_TYPE_IOB)
xgene_pmu_write_agent1msk(pmu_dev, ~((u32)GET_AGENT1ID(event)));
xgene_pmu_enable_counter(pmu_dev, GET_CNTR(event));
xgene_pmu_enable_counter_int(pmu_dev, GET_CNTR(event));
}
static void xgene_perf_disable_event(struct perf_event *event)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(event->pmu);
xgene_pmu_disable_counter(pmu_dev, GET_CNTR(event));
xgene_pmu_disable_counter_int(pmu_dev, GET_CNTR(event));
}
static void xgene_perf_event_set_period(struct perf_event *event)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(event->pmu);
struct hw_perf_event *hw = &event->hw;
u64 val = 1ULL << 31;
local64_set(&hw->prev_count, val);
xgene_pmu_write_counter(pmu_dev, hw->idx, (u32) val);
}
static void xgene_perf_event_update(struct perf_event *event)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(event->pmu);
struct hw_perf_event *hw = &event->hw;
u64 delta, prev_raw_count, new_raw_count;
again:
prev_raw_count = local64_read(&hw->prev_count);
new_raw_count = xgene_pmu_read_counter(pmu_dev, GET_CNTR(event));
if (local64_cmpxchg(&hw->prev_count, prev_raw_count,
new_raw_count) != prev_raw_count)
goto again;
delta = (new_raw_count - prev_raw_count) & pmu_dev->max_period;
local64_add(delta, &event->count);
}
static void xgene_perf_read(struct perf_event *event)
{
xgene_perf_event_update(event);
}
static void xgene_perf_start(struct perf_event *event, int flags)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(event->pmu);
struct hw_perf_event *hw = &event->hw;
if (WARN_ON_ONCE(!(hw->state & PERF_HES_STOPPED)))
return;
WARN_ON_ONCE(!(hw->state & PERF_HES_UPTODATE));
hw->state = 0;
xgene_perf_event_set_period(event);
if (flags & PERF_EF_RELOAD) {
u64 prev_raw_count = local64_read(&hw->prev_count);
xgene_pmu_write_counter(pmu_dev, GET_CNTR(event),
(u32) prev_raw_count);
}
xgene_perf_enable_event(event);
perf_event_update_userpage(event);
}
static void xgene_perf_stop(struct perf_event *event, int flags)
{
struct hw_perf_event *hw = &event->hw;
u64 config;
if (hw->state & PERF_HES_UPTODATE)
return;
xgene_perf_disable_event(event);
WARN_ON_ONCE(hw->state & PERF_HES_STOPPED);
hw->state |= PERF_HES_STOPPED;
if (hw->state & PERF_HES_UPTODATE)
return;
config = hw->config;
xgene_perf_read(event);
hw->state |= PERF_HES_UPTODATE;
}
static int xgene_perf_add(struct perf_event *event, int flags)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(event->pmu);
struct hw_perf_event *hw = &event->hw;
hw->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
hw->idx = get_next_avail_cntr(pmu_dev);
if (hw->idx < 0)
return -EAGAIN;
pmu_dev->pmu_counter_event[hw->idx] = event;
if (flags & PERF_EF_START)
xgene_perf_start(event, PERF_EF_RELOAD);
return 0;
}
static void xgene_perf_del(struct perf_event *event, int flags)
{
struct xgene_pmu_dev *pmu_dev = to_pmu_dev(event->pmu);
struct hw_perf_event *hw = &event->hw;
xgene_perf_stop(event, PERF_EF_UPDATE);
clear_avail_cntr(pmu_dev, GET_CNTR(event));
perf_event_update_userpage(event);
pmu_dev->pmu_counter_event[hw->idx] = NULL;
}
static int xgene_init_perf(struct xgene_pmu_dev *pmu_dev, char *name)
{
struct xgene_pmu *xgene_pmu;
pmu_dev->max_period = PMU_CNT_MAX_PERIOD - 1;
xgene_pmu = pmu_dev->parent;
if (xgene_pmu->version == PCP_PMU_V1)
pmu_dev->max_counters = 1;
else
pmu_dev->max_counters = PMU_MAX_COUNTERS;
pmu_dev->pmu = (struct pmu) {
.attr_groups = pmu_dev->attr_groups,
.task_ctx_nr = perf_invalid_context,
.pmu_enable = xgene_perf_pmu_enable,
.pmu_disable = xgene_perf_pmu_disable,
.event_init = xgene_perf_event_init,
.add = xgene_perf_add,
.del = xgene_perf_del,
.start = xgene_perf_start,
.stop = xgene_perf_stop,
.read = xgene_perf_read,
};
xgene_pmu_stop_counters(pmu_dev);
xgene_pmu_reset_counters(pmu_dev);
return perf_pmu_register(&pmu_dev->pmu, name, -1);
}
static int
xgene_pmu_dev_add(struct xgene_pmu *xgene_pmu, struct xgene_pmu_dev_ctx *ctx)
{
struct device *dev = xgene_pmu->dev;
struct xgene_pmu_dev *pmu;
int rc;
pmu = devm_kzalloc(dev, sizeof(*pmu), GFP_KERNEL);
if (!pmu)
return -ENOMEM;
pmu->parent = xgene_pmu;
pmu->inf = &ctx->inf;
ctx->pmu_dev = pmu;
switch (pmu->inf->type) {
case PMU_TYPE_L3C:
pmu->attr_groups = l3c_pmu_attr_groups;
break;
case PMU_TYPE_IOB:
pmu->attr_groups = iob_pmu_attr_groups;
break;
case PMU_TYPE_MCB:
if (!(xgene_pmu->mcb_active_mask & pmu->inf->enable_mask))
goto dev_err;
pmu->attr_groups = mcb_pmu_attr_groups;
break;
case PMU_TYPE_MC:
if (!(xgene_pmu->mc_active_mask & pmu->inf->enable_mask))
goto dev_err;
pmu->attr_groups = mc_pmu_attr_groups;
break;
default:
return -EINVAL;
}
rc = xgene_init_perf(pmu, ctx->name);
if (rc) {
dev_err(dev, "%s PMU: Failed to init perf driver\n", ctx->name);
goto dev_err;
}
dev_info(dev, "%s PMU registered\n", ctx->name);
return rc;
dev_err:
devm_kfree(dev, pmu);
return -ENODEV;
}
static void _xgene_pmu_isr(int irq, struct xgene_pmu_dev *pmu_dev)
{
struct xgene_pmu *xgene_pmu = pmu_dev->parent;
u32 pmovsr;
int idx;
pmovsr = readl(pmu_dev->inf->csr + PMU_PMOVSR) & PMU_OVERFLOW_MASK;
if (!pmovsr)
return;
if (xgene_pmu->version == PCP_PMU_V1)
writel(0x0, pmu_dev->inf->csr + PMU_PMOVSR);
else
writel(pmovsr, pmu_dev->inf->csr + PMU_PMOVSR);
for (idx = 0; idx < PMU_MAX_COUNTERS; idx++) {
struct perf_event *event = pmu_dev->pmu_counter_event[idx];
int overflowed = pmovsr & BIT(idx);
if (!event || !overflowed)
continue;
xgene_perf_event_update(event);
xgene_perf_event_set_period(event);
}
}
static irqreturn_t xgene_pmu_isr(int irq, void *dev_id)
{
struct xgene_pmu_dev_ctx *ctx;
struct xgene_pmu *xgene_pmu = dev_id;
unsigned long flags;
u32 val;
raw_spin_lock_irqsave(&xgene_pmu->lock, flags);
val = readl(xgene_pmu->pcppmu_csr + PCPPMU_INTSTATUS_REG);
if (val & PCPPMU_INT_MCU) {
list_for_each_entry(ctx, &xgene_pmu->mcpmus, next) {
_xgene_pmu_isr(irq, ctx->pmu_dev);
}
}
if (val & PCPPMU_INT_MCB) {
list_for_each_entry(ctx, &xgene_pmu->mcbpmus, next) {
_xgene_pmu_isr(irq, ctx->pmu_dev);
}
}
if (val & PCPPMU_INT_L3C) {
list_for_each_entry(ctx, &xgene_pmu->l3cpmus, next) {
_xgene_pmu_isr(irq, ctx->pmu_dev);
}
}
if (val & PCPPMU_INT_IOB) {
list_for_each_entry(ctx, &xgene_pmu->iobpmus, next) {
_xgene_pmu_isr(irq, ctx->pmu_dev);
}
}
raw_spin_unlock_irqrestore(&xgene_pmu->lock, flags);
return IRQ_HANDLED;
}
static int acpi_pmu_probe_active_mcb_mcu(struct xgene_pmu *xgene_pmu,
struct platform_device *pdev)
{
void __iomem *csw_csr, *mcba_csr, *mcbb_csr;
struct resource *res;
unsigned int reg;
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
csw_csr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(csw_csr)) {
dev_err(&pdev->dev, "ioremap failed for CSW CSR resource\n");
return PTR_ERR(csw_csr);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 2);
mcba_csr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mcba_csr)) {
dev_err(&pdev->dev, "ioremap failed for MCBA CSR resource\n");
return PTR_ERR(mcba_csr);
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 3);
mcbb_csr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(mcbb_csr)) {
dev_err(&pdev->dev, "ioremap failed for MCBB CSR resource\n");
return PTR_ERR(mcbb_csr);
}
reg = readl(csw_csr + CSW_CSWCR);
if (reg & CSW_CSWCR_DUALMCB_MASK) {
xgene_pmu->mcb_active_mask = 0x3;
reg = readl(mcbb_csr + CSW_CSWCR);
xgene_pmu->mc_active_mask =
(reg & MCBADDRMR_DUALMCU_MODE_MASK) ? 0xF : 0x5;
} else {
xgene_pmu->mcb_active_mask = 0x1;
reg = readl(mcba_csr + CSW_CSWCR);
xgene_pmu->mc_active_mask =
(reg & MCBADDRMR_DUALMCU_MODE_MASK) ? 0x3 : 0x1;
}
return 0;
}
static int fdt_pmu_probe_active_mcb_mcu(struct xgene_pmu *xgene_pmu,
struct platform_device *pdev)
{
struct regmap *csw_map, *mcba_map, *mcbb_map;
struct device_node *np = pdev->dev.of_node;
unsigned int reg;
csw_map = syscon_regmap_lookup_by_phandle(np, "regmap-csw");
if (IS_ERR(csw_map)) {
dev_err(&pdev->dev, "unable to get syscon regmap csw\n");
return PTR_ERR(csw_map);
}
mcba_map = syscon_regmap_lookup_by_phandle(np, "regmap-mcba");
if (IS_ERR(mcba_map)) {
dev_err(&pdev->dev, "unable to get syscon regmap mcba\n");
return PTR_ERR(mcba_map);
}
mcbb_map = syscon_regmap_lookup_by_phandle(np, "regmap-mcbb");
if (IS_ERR(mcbb_map)) {
dev_err(&pdev->dev, "unable to get syscon regmap mcbb\n");
return PTR_ERR(mcbb_map);
}
if (regmap_read(csw_map, CSW_CSWCR, &reg))
return -EINVAL;
if (reg & CSW_CSWCR_DUALMCB_MASK) {
xgene_pmu->mcb_active_mask = 0x3;
if (regmap_read(mcbb_map, MCBADDRMR, &reg))
return 0;
xgene_pmu->mc_active_mask =
(reg & MCBADDRMR_DUALMCU_MODE_MASK) ? 0xF : 0x5;
} else {
xgene_pmu->mcb_active_mask = 0x1;
if (regmap_read(mcba_map, MCBADDRMR, &reg))
return 0;
xgene_pmu->mc_active_mask =
(reg & MCBADDRMR_DUALMCU_MODE_MASK) ? 0x3 : 0x1;
}
return 0;
}
static int xgene_pmu_probe_active_mcb_mcu(struct xgene_pmu *xgene_pmu,
struct platform_device *pdev)
{
if (has_acpi_companion(&pdev->dev))
return acpi_pmu_probe_active_mcb_mcu(xgene_pmu, pdev);
return fdt_pmu_probe_active_mcb_mcu(xgene_pmu, pdev);
}
static char *xgene_pmu_dev_name(struct device *dev, u32 type, int id)
{
switch (type) {
case PMU_TYPE_L3C:
return devm_kasprintf(dev, GFP_KERNEL, "l3c%d", id);
case PMU_TYPE_IOB:
return devm_kasprintf(dev, GFP_KERNEL, "iob%d", id);
case PMU_TYPE_MCB:
return devm_kasprintf(dev, GFP_KERNEL, "mcb%d", id);
case PMU_TYPE_MC:
return devm_kasprintf(dev, GFP_KERNEL, "mc%d", id);
default:
return devm_kasprintf(dev, GFP_KERNEL, "unknown");
}
}
static int acpi_pmu_dev_add_resource(struct acpi_resource *ares, void *data)
{
struct resource *res = data;
if (ares->type == ACPI_RESOURCE_TYPE_FIXED_MEMORY32)
acpi_dev_resource_memory(ares, res);
return 1;
}
static struct
xgene_pmu_dev_ctx *acpi_get_pmu_hw_inf(struct xgene_pmu *xgene_pmu,
struct acpi_device *adev, u32 type)
{
struct device *dev = xgene_pmu->dev;
struct list_head resource_list;
struct xgene_pmu_dev_ctx *ctx;
const union acpi_object *obj;
struct hw_pmu_info *inf;
void __iomem *dev_csr;
struct resource res;
int enable_bit;
int rc;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return NULL;
INIT_LIST_HEAD(&resource_list);
rc = acpi_dev_get_resources(adev, &resource_list,
acpi_pmu_dev_add_resource, &res);
acpi_dev_free_resource_list(&resource_list);
if (rc < 0) {
dev_err(dev, "PMU type %d: No resource address found\n", type);
goto err;
}
dev_csr = devm_ioremap_resource(dev, &res);
if (IS_ERR(dev_csr)) {
dev_err(dev, "PMU type %d: Fail to map resource\n", type);
goto err;
}
rc = acpi_dev_get_property(adev, "enable-bit-index",
ACPI_TYPE_INTEGER, &obj);
if (rc < 0)
enable_bit = 0;
else
enable_bit = (int) obj->integer.value;
ctx->name = xgene_pmu_dev_name(dev, type, enable_bit);
if (!ctx->name) {
dev_err(dev, "PMU type %d: Fail to get device name\n", type);
goto err;
}
inf = &ctx->inf;
inf->type = type;
inf->csr = dev_csr;
inf->enable_mask = 1 << enable_bit;
return ctx;
err:
devm_kfree(dev, ctx);
return NULL;
}
static acpi_status acpi_pmu_dev_add(acpi_handle handle, u32 level,
void *data, void **return_value)
{
struct xgene_pmu *xgene_pmu = data;
struct xgene_pmu_dev_ctx *ctx;
struct acpi_device *adev;
if (acpi_bus_get_device(handle, &adev))
return AE_OK;
if (acpi_bus_get_status(adev) || !adev->status.present)
return AE_OK;
if (!strcmp(acpi_device_hid(adev), "APMC0D5D"))
ctx = acpi_get_pmu_hw_inf(xgene_pmu, adev, PMU_TYPE_L3C);
else if (!strcmp(acpi_device_hid(adev), "APMC0D5E"))
ctx = acpi_get_pmu_hw_inf(xgene_pmu, adev, PMU_TYPE_IOB);
else if (!strcmp(acpi_device_hid(adev), "APMC0D5F"))
ctx = acpi_get_pmu_hw_inf(xgene_pmu, adev, PMU_TYPE_MCB);
else if (!strcmp(acpi_device_hid(adev), "APMC0D60"))
ctx = acpi_get_pmu_hw_inf(xgene_pmu, adev, PMU_TYPE_MC);
else
ctx = NULL;
if (!ctx)
return AE_OK;
if (xgene_pmu_dev_add(xgene_pmu, ctx)) {
devm_kfree(xgene_pmu->dev, ctx);
return AE_OK;
}
switch (ctx->inf.type) {
case PMU_TYPE_L3C:
list_add(&ctx->next, &xgene_pmu->l3cpmus);
break;
case PMU_TYPE_IOB:
list_add(&ctx->next, &xgene_pmu->iobpmus);
break;
case PMU_TYPE_MCB:
list_add(&ctx->next, &xgene_pmu->mcbpmus);
break;
case PMU_TYPE_MC:
list_add(&ctx->next, &xgene_pmu->mcpmus);
break;
}
return AE_OK;
}
static int acpi_pmu_probe_pmu_dev(struct xgene_pmu *xgene_pmu,
struct platform_device *pdev)
{
struct device *dev = xgene_pmu->dev;
acpi_handle handle;
acpi_status status;
handle = ACPI_HANDLE(dev);
if (!handle)
return -EINVAL;
status = acpi_walk_namespace(ACPI_TYPE_DEVICE, handle, 1,
acpi_pmu_dev_add, NULL, xgene_pmu, NULL);
if (ACPI_FAILURE(status)) {
dev_err(dev, "failed to probe PMU devices\n");
return -ENODEV;
}
return 0;
}
static int acpi_pmu_probe_pmu_dev(struct xgene_pmu *xgene_pmu,
struct platform_device *pdev)
{
return 0;
}
static struct
xgene_pmu_dev_ctx *fdt_get_pmu_hw_inf(struct xgene_pmu *xgene_pmu,
struct device_node *np, u32 type)
{
struct device *dev = xgene_pmu->dev;
struct xgene_pmu_dev_ctx *ctx;
struct hw_pmu_info *inf;
void __iomem *dev_csr;
struct resource res;
int enable_bit;
int rc;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return NULL;
rc = of_address_to_resource(np, 0, &res);
if (rc < 0) {
dev_err(dev, "PMU type %d: No resource address found\n", type);
goto err;
}
dev_csr = devm_ioremap_resource(dev, &res);
if (IS_ERR(dev_csr)) {
dev_err(dev, "PMU type %d: Fail to map resource\n", type);
goto err;
}
if (of_property_read_u32(np, "enable-bit-index", &enable_bit))
enable_bit = 0;
ctx->name = xgene_pmu_dev_name(dev, type, enable_bit);
if (!ctx->name) {
dev_err(dev, "PMU type %d: Fail to get device name\n", type);
goto err;
}
inf = &ctx->inf;
inf->type = type;
inf->csr = dev_csr;
inf->enable_mask = 1 << enable_bit;
return ctx;
err:
devm_kfree(dev, ctx);
return NULL;
}
static int fdt_pmu_probe_pmu_dev(struct xgene_pmu *xgene_pmu,
struct platform_device *pdev)
{
struct xgene_pmu_dev_ctx *ctx;
struct device_node *np;
for_each_child_of_node(pdev->dev.of_node, np) {
if (!of_device_is_available(np))
continue;
if (of_device_is_compatible(np, "apm,xgene-pmu-l3c"))
ctx = fdt_get_pmu_hw_inf(xgene_pmu, np, PMU_TYPE_L3C);
else if (of_device_is_compatible(np, "apm,xgene-pmu-iob"))
ctx = fdt_get_pmu_hw_inf(xgene_pmu, np, PMU_TYPE_IOB);
else if (of_device_is_compatible(np, "apm,xgene-pmu-mcb"))
ctx = fdt_get_pmu_hw_inf(xgene_pmu, np, PMU_TYPE_MCB);
else if (of_device_is_compatible(np, "apm,xgene-pmu-mc"))
ctx = fdt_get_pmu_hw_inf(xgene_pmu, np, PMU_TYPE_MC);
else
ctx = NULL;
if (!ctx)
continue;
if (xgene_pmu_dev_add(xgene_pmu, ctx)) {
devm_kfree(xgene_pmu->dev, ctx);
continue;
}
switch (ctx->inf.type) {
case PMU_TYPE_L3C:
list_add(&ctx->next, &xgene_pmu->l3cpmus);
break;
case PMU_TYPE_IOB:
list_add(&ctx->next, &xgene_pmu->iobpmus);
break;
case PMU_TYPE_MCB:
list_add(&ctx->next, &xgene_pmu->mcbpmus);
break;
case PMU_TYPE_MC:
list_add(&ctx->next, &xgene_pmu->mcpmus);
break;
}
}
return 0;
}
static int xgene_pmu_probe_pmu_dev(struct xgene_pmu *xgene_pmu,
struct platform_device *pdev)
{
if (has_acpi_companion(&pdev->dev))
return acpi_pmu_probe_pmu_dev(xgene_pmu, pdev);
return fdt_pmu_probe_pmu_dev(xgene_pmu, pdev);
}
static int xgene_pmu_probe(struct platform_device *pdev)
{
const struct xgene_pmu_data *dev_data;
const struct of_device_id *of_id;
struct xgene_pmu *xgene_pmu;
struct resource *res;
int irq, rc;
int version;
xgene_pmu = devm_kzalloc(&pdev->dev, sizeof(*xgene_pmu), GFP_KERNEL);
if (!xgene_pmu)
return -ENOMEM;
xgene_pmu->dev = &pdev->dev;
platform_set_drvdata(pdev, xgene_pmu);
version = -EINVAL;
of_id = of_match_device(xgene_pmu_of_match, &pdev->dev);
if (of_id) {
dev_data = (const struct xgene_pmu_data *) of_id->data;
version = dev_data->id;
}
#ifdef CONFIG_ACPI
if (ACPI_COMPANION(&pdev->dev)) {
const struct acpi_device_id *acpi_id;
acpi_id = acpi_match_device(xgene_pmu_acpi_match, &pdev->dev);
if (acpi_id)
version = (int) acpi_id->driver_data;
}
#endif
if (version < 0)
return -ENODEV;
INIT_LIST_HEAD(&xgene_pmu->l3cpmus);
INIT_LIST_HEAD(&xgene_pmu->iobpmus);
INIT_LIST_HEAD(&xgene_pmu->mcbpmus);
INIT_LIST_HEAD(&xgene_pmu->mcpmus);
xgene_pmu->version = version;
dev_info(&pdev->dev, "X-Gene PMU version %d\n", xgene_pmu->version);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
xgene_pmu->pcppmu_csr = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(xgene_pmu->pcppmu_csr)) {
dev_err(&pdev->dev, "ioremap failed for PCP PMU resource\n");
rc = PTR_ERR(xgene_pmu->pcppmu_csr);
goto err;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "No IRQ resource\n");
rc = -EINVAL;
goto err;
}
rc = devm_request_irq(&pdev->dev, irq, xgene_pmu_isr,
IRQF_NOBALANCING | IRQF_NO_THREAD,
dev_name(&pdev->dev), xgene_pmu);
if (rc) {
dev_err(&pdev->dev, "Could not request IRQ %d\n", irq);
goto err;
}
raw_spin_lock_init(&xgene_pmu->lock);
rc = xgene_pmu_probe_active_mcb_mcu(xgene_pmu, pdev);
if (rc) {
dev_warn(&pdev->dev, "Unknown MCB/MCU active status\n");
xgene_pmu->mcb_active_mask = 0x1;
xgene_pmu->mc_active_mask = 0x1;
}
cpumask_set_cpu(smp_processor_id(), &xgene_pmu->cpu);
rc = irq_set_affinity(irq, &xgene_pmu->cpu);
if (rc) {
dev_err(&pdev->dev, "Failed to set interrupt affinity!\n");
goto err;
}
rc = xgene_pmu_probe_pmu_dev(xgene_pmu, pdev);
if (rc) {
dev_err(&pdev->dev, "No PMU perf devices found!\n");
goto err;
}
xgene_pmu_unmask_int(xgene_pmu);
return 0;
err:
if (xgene_pmu->pcppmu_csr)
devm_iounmap(&pdev->dev, xgene_pmu->pcppmu_csr);
devm_kfree(&pdev->dev, xgene_pmu);
return rc;
}
static void
xgene_pmu_dev_cleanup(struct xgene_pmu *xgene_pmu, struct list_head *pmus)
{
struct xgene_pmu_dev_ctx *ctx;
struct device *dev = xgene_pmu->dev;
struct xgene_pmu_dev *pmu_dev;
list_for_each_entry(ctx, pmus, next) {
pmu_dev = ctx->pmu_dev;
if (pmu_dev->inf->csr)
devm_iounmap(dev, pmu_dev->inf->csr);
devm_kfree(dev, ctx);
devm_kfree(dev, pmu_dev);
}
}
static int xgene_pmu_remove(struct platform_device *pdev)
{
struct xgene_pmu *xgene_pmu = dev_get_drvdata(&pdev->dev);
xgene_pmu_dev_cleanup(xgene_pmu, &xgene_pmu->l3cpmus);
xgene_pmu_dev_cleanup(xgene_pmu, &xgene_pmu->iobpmus);
xgene_pmu_dev_cleanup(xgene_pmu, &xgene_pmu->mcbpmus);
xgene_pmu_dev_cleanup(xgene_pmu, &xgene_pmu->mcpmus);
if (xgene_pmu->pcppmu_csr)
devm_iounmap(&pdev->dev, xgene_pmu->pcppmu_csr);
devm_kfree(&pdev->dev, xgene_pmu);
return 0;
}
