static void snb_uncore_msr_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (hwc->idx < UNCORE_PMC_IDX_FIXED)
wrmsrl(hwc->config_base, hwc->config | SNB_UNC_CTL_EN);
else
wrmsrl(hwc->config_base, SNB_UNC_CTL_EN);
}
static void snb_uncore_msr_disable_event(struct intel_uncore_box *box, struct perf_event *event)
{
wrmsrl(event->hw.config_base, 0);
}
static void snb_uncore_msr_init_box(struct intel_uncore_box *box)
{
if (box->pmu->pmu_idx == 0) {
wrmsrl(SNB_UNC_PERF_GLOBAL_CTL,
SNB_UNC_GLOBAL_CTL_EN | SNB_UNC_GLOBAL_CTL_CORE_ALL);
}
}
void snb_uncore_cpu_init(void)
{
uncore_msr_uncores = snb_msr_uncores;
if (snb_uncore_cbox.num_boxes > boot_cpu_data.x86_max_cores)
snb_uncore_cbox.num_boxes = boot_cpu_data.x86_max_cores;
}
static void snb_uncore_imc_init_box(struct intel_uncore_box *box)
{
struct pci_dev *pdev = box->pci_dev;
int where = SNB_UNCORE_PCI_IMC_BAR_OFFSET;
resource_size_t addr;
u32 pci_dword;
pci_read_config_dword(pdev, where, &pci_dword);
addr = pci_dword;
#ifdef CONFIG_PHYS_ADDR_T_64BIT
pci_read_config_dword(pdev, where + 4, &pci_dword);
addr |= ((resource_size_t)pci_dword << 32);
#endif
addr &= ~(PAGE_SIZE - 1);
box->io_addr = ioremap(addr, SNB_UNCORE_PCI_IMC_MAP_SIZE);
box->hrtimer_duration = UNCORE_SNB_IMC_HRTIMER_INTERVAL;
}
static void snb_uncore_imc_enable_box(struct intel_uncore_box *box)
{}
static void snb_uncore_imc_disable_box(struct intel_uncore_box *box)
{}
static void snb_uncore_imc_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{}
static void snb_uncore_imc_disable_event(struct intel_uncore_box *box, struct perf_event *event)
{}
static u64 snb_uncore_imc_read_counter(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
return (u64)*(unsigned int *)(box->io_addr + hwc->event_base);
}
static int snb_uncore_imc_event_init(struct perf_event *event)
{
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
struct hw_perf_event *hwc = &event->hw;
u64 cfg = event->attr.config & SNB_UNCORE_PCI_IMC_EVENT_MASK;
int idx, base;
if (event->attr.type != event->pmu->type)
return -ENOENT;
pmu = uncore_event_to_pmu(event);
if (pmu->func_id < 0)
return -ENOENT;
if (hwc->sample_period)
return -EINVAL;
if (event->attr.exclude_user ||
event->attr.exclude_kernel ||
event->attr.exclude_hv ||
event->attr.exclude_idle ||
event->attr.exclude_host ||
event->attr.exclude_guest ||
event->attr.sample_period)
return -EINVAL;
if (event->cpu < 0)
return -EINVAL;
if (event->attr.config & ~SNB_UNCORE_PCI_IMC_EVENT_MASK)
return -EINVAL;
box = uncore_pmu_to_box(pmu, event->cpu);
if (!box || box->cpu < 0)
return -EINVAL;
event->cpu = box->cpu;
event->hw.idx = -1;
event->hw.last_tag = ~0ULL;
event->hw.extra_reg.idx = EXTRA_REG_NONE;
event->hw.branch_reg.idx = EXTRA_REG_NONE;
switch (cfg) {
case SNB_UNCORE_PCI_IMC_DATA_READS:
base = SNB_UNCORE_PCI_IMC_DATA_READS_BASE;
idx = UNCORE_PMC_IDX_FIXED;
break;
case SNB_UNCORE_PCI_IMC_DATA_WRITES:
base = SNB_UNCORE_PCI_IMC_DATA_WRITES_BASE;
idx = UNCORE_PMC_IDX_FIXED + 1;
break;
default:
return -EINVAL;
}
event->hw.event_base = base;
event->hw.config = cfg;
event->hw.idx = idx;
return 0;
}
static int snb_uncore_imc_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
return 0;
}
static void snb_uncore_imc_event_start(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
u64 count;
if (WARN_ON_ONCE(!(event->hw.state & PERF_HES_STOPPED)))
return;
event->hw.state = 0;
box->n_active++;
list_add_tail(&event->active_entry, &box->active_list);
count = snb_uncore_imc_read_counter(box, event);
local64_set(&event->hw.prev_count, count);
if (box->n_active == 1)
uncore_pmu_start_hrtimer(box);
}
static void snb_uncore_imc_event_stop(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
struct hw_perf_event *hwc = &event->hw;
if (!(hwc->state & PERF_HES_STOPPED)) {
box->n_active--;
WARN_ON_ONCE(hwc->state & PERF_HES_STOPPED);
hwc->state |= PERF_HES_STOPPED;
list_del(&event->active_entry);
if (box->n_active == 0)
uncore_pmu_cancel_hrtimer(box);
}
if ((flags & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
uncore_perf_event_update(box, event);
hwc->state |= PERF_HES_UPTODATE;
}
}
static int snb_uncore_imc_event_add(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
struct hw_perf_event *hwc = &event->hw;
if (!box)
return -ENODEV;
hwc->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
if (!(flags & PERF_EF_START))
hwc->state |= PERF_HES_ARCH;
snb_uncore_imc_event_start(event, 0);
box->n_events++;
return 0;
}
static void snb_uncore_imc_event_del(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
int i;
snb_uncore_imc_event_stop(event, PERF_EF_UPDATE);
for (i = 0; i < box->n_events; i++) {
if (event == box->event_list[i]) {
--box->n_events;
break;
}
}
}
static int snb_pci2phy_map_init(int devid)
{
struct pci_dev *dev = NULL;
int bus;
dev = pci_get_device(PCI_VENDOR_ID_INTEL, devid, dev);
if (!dev)
return -ENOTTY;
bus = dev->bus->number;
uncore_pcibus_to_physid[bus] = 0;
pci_dev_put(dev);
return 0;
}
static struct pci_driver *imc_uncore_find_dev(void)
{
const struct imc_uncore_pci_dev *p;
int ret;
for_each_imc_pci_id(p, desktop_imc_pci_ids) {
ret = snb_pci2phy_map_init(p->pci_id);
if (ret == 0)
return p->driver;
}
return NULL;
}
static int imc_uncore_pci_init(void)
{
struct pci_driver *imc_drv = imc_uncore_find_dev();
if (!imc_drv)
return -ENODEV;
uncore_pci_uncores = snb_pci_uncores;
uncore_pci_driver = imc_drv;
return 0;
}
int snb_uncore_pci_init(void)
{
return imc_uncore_pci_init();
}
int ivb_uncore_pci_init(void)
{
return imc_uncore_pci_init();
}
int hsw_uncore_pci_init(void)
{
return imc_uncore_pci_init();
}
static void nhm_uncore_msr_disable_box(struct intel_uncore_box *box)
{
wrmsrl(NHM_UNC_PERF_GLOBAL_CTL, 0);
}
static void nhm_uncore_msr_enable_box(struct intel_uncore_box *box)
{
wrmsrl(NHM_UNC_PERF_GLOBAL_CTL, NHM_UNC_GLOBAL_CTL_EN_PC_ALL | NHM_UNC_GLOBAL_CTL_EN_FC);
}
static void nhm_uncore_msr_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (hwc->idx < UNCORE_PMC_IDX_FIXED)
wrmsrl(hwc->config_base, hwc->config | SNB_UNC_CTL_EN);
else
wrmsrl(hwc->config_base, NHM_UNC_FIXED_CTR_CTL_EN);
}
void nhm_uncore_cpu_init(void)
{
uncore_msr_uncores = nhm_msr_uncores;
}
