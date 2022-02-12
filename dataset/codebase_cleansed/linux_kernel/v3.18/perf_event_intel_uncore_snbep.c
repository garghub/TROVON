static void snbep_uncore_pci_disable_box(struct intel_uncore_box *box)
{
struct pci_dev *pdev = box->pci_dev;
int box_ctl = uncore_pci_box_ctl(box);
u32 config = 0;
if (!pci_read_config_dword(pdev, box_ctl, &config)) {
config |= SNBEP_PMON_BOX_CTL_FRZ;
pci_write_config_dword(pdev, box_ctl, config);
}
}
static void snbep_uncore_pci_enable_box(struct intel_uncore_box *box)
{
struct pci_dev *pdev = box->pci_dev;
int box_ctl = uncore_pci_box_ctl(box);
u32 config = 0;
if (!pci_read_config_dword(pdev, box_ctl, &config)) {
config &= ~SNBEP_PMON_BOX_CTL_FRZ;
pci_write_config_dword(pdev, box_ctl, config);
}
}
static void snbep_uncore_pci_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct pci_dev *pdev = box->pci_dev;
struct hw_perf_event *hwc = &event->hw;
pci_write_config_dword(pdev, hwc->config_base, hwc->config | SNBEP_PMON_CTL_EN);
}
static void snbep_uncore_pci_disable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct pci_dev *pdev = box->pci_dev;
struct hw_perf_event *hwc = &event->hw;
pci_write_config_dword(pdev, hwc->config_base, hwc->config);
}
static u64 snbep_uncore_pci_read_counter(struct intel_uncore_box *box, struct perf_event *event)
{
struct pci_dev *pdev = box->pci_dev;
struct hw_perf_event *hwc = &event->hw;
u64 count = 0;
pci_read_config_dword(pdev, hwc->event_base, (u32 *)&count);
pci_read_config_dword(pdev, hwc->event_base + 4, (u32 *)&count + 1);
return count;
}
static void snbep_uncore_pci_init_box(struct intel_uncore_box *box)
{
struct pci_dev *pdev = box->pci_dev;
pci_write_config_dword(pdev, SNBEP_PCI_PMON_BOX_CTL, SNBEP_PMON_BOX_CTL_INT);
}
static void snbep_uncore_msr_disable_box(struct intel_uncore_box *box)
{
u64 config;
unsigned msr;
msr = uncore_msr_box_ctl(box);
if (msr) {
rdmsrl(msr, config);
config |= SNBEP_PMON_BOX_CTL_FRZ;
wrmsrl(msr, config);
}
}
static void snbep_uncore_msr_enable_box(struct intel_uncore_box *box)
{
u64 config;
unsigned msr;
msr = uncore_msr_box_ctl(box);
if (msr) {
rdmsrl(msr, config);
config &= ~SNBEP_PMON_BOX_CTL_FRZ;
wrmsrl(msr, config);
}
}
static void snbep_uncore_msr_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
if (reg1->idx != EXTRA_REG_NONE)
wrmsrl(reg1->reg, uncore_shared_reg_config(box, 0));
wrmsrl(hwc->config_base, hwc->config | SNBEP_PMON_CTL_EN);
}
static void snbep_uncore_msr_disable_event(struct intel_uncore_box *box,
struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
wrmsrl(hwc->config_base, hwc->config);
}
static void snbep_uncore_msr_init_box(struct intel_uncore_box *box)
{
unsigned msr = uncore_msr_box_ctl(box);
if (msr)
wrmsrl(msr, SNBEP_PMON_BOX_CTL_INT);
}
static void snbep_cbox_put_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct intel_uncore_extra_reg *er = &box->shared_regs[0];
int i;
if (uncore_box_is_fake(box))
return;
for (i = 0; i < 5; i++) {
if (reg1->alloc & (0x1 << i))
atomic_sub(1 << (i * 6), &er->ref);
}
reg1->alloc = 0;
}
static struct event_constraint *
__snbep_cbox_get_constraint(struct intel_uncore_box *box, struct perf_event *event,
u64 (*cbox_filter_mask)(int fields))
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct intel_uncore_extra_reg *er = &box->shared_regs[0];
int i, alloc = 0;
unsigned long flags;
u64 mask;
if (reg1->idx == EXTRA_REG_NONE)
return NULL;
raw_spin_lock_irqsave(&er->lock, flags);
for (i = 0; i < 5; i++) {
if (!(reg1->idx & (0x1 << i)))
continue;
if (!uncore_box_is_fake(box) && (reg1->alloc & (0x1 << i)))
continue;
mask = cbox_filter_mask(0x1 << i);
if (!__BITS_VALUE(atomic_read(&er->ref), i, 6) ||
!((reg1->config ^ er->config) & mask)) {
atomic_add(1 << (i * 6), &er->ref);
er->config &= ~mask;
er->config |= reg1->config & mask;
alloc |= (0x1 << i);
} else {
break;
}
}
raw_spin_unlock_irqrestore(&er->lock, flags);
if (i < 5)
goto fail;
if (!uncore_box_is_fake(box))
reg1->alloc |= alloc;
return NULL;
fail:
for (; i >= 0; i--) {
if (alloc & (0x1 << i))
atomic_sub(1 << (i * 6), &er->ref);
}
return &uncore_constraint_empty;
}
static u64 snbep_cbox_filter_mask(int fields)
{
u64 mask = 0;
if (fields & 0x1)
mask |= SNBEP_CB0_MSR_PMON_BOX_FILTER_TID;
if (fields & 0x2)
mask |= SNBEP_CB0_MSR_PMON_BOX_FILTER_NID;
if (fields & 0x4)
mask |= SNBEP_CB0_MSR_PMON_BOX_FILTER_STATE;
if (fields & 0x8)
mask |= SNBEP_CB0_MSR_PMON_BOX_FILTER_OPC;
return mask;
}
static struct event_constraint *
snbep_cbox_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
return __snbep_cbox_get_constraint(box, event, snbep_cbox_filter_mask);
}
static int snbep_cbox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct extra_reg *er;
int idx = 0;
for (er = snbep_uncore_cbox_extra_regs; er->msr; er++) {
if (er->event != (event->hw.config & er->config_mask))
continue;
idx |= er->idx;
}
if (idx) {
reg1->reg = SNBEP_C0_MSR_PMON_BOX_FILTER +
SNBEP_CBO_MSR_OFFSET * box->pmu->pmu_idx;
reg1->config = event->attr.config1 & snbep_cbox_filter_mask(idx);
reg1->idx = idx;
}
return 0;
}
static u64 snbep_pcu_alter_er(struct perf_event *event, int new_idx, bool modify)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
u64 config = reg1->config;
if (new_idx > reg1->idx)
config <<= 8 * (new_idx - reg1->idx);
else
config >>= 8 * (reg1->idx - new_idx);
if (modify) {
hwc->config += new_idx - reg1->idx;
reg1->config = config;
reg1->idx = new_idx;
}
return config;
}
static struct event_constraint *
snbep_pcu_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct intel_uncore_extra_reg *er = &box->shared_regs[0];
unsigned long flags;
int idx = reg1->idx;
u64 mask, config1 = reg1->config;
bool ok = false;
if (reg1->idx == EXTRA_REG_NONE ||
(!uncore_box_is_fake(box) && reg1->alloc))
return NULL;
again:
mask = 0xffULL << (idx * 8);
raw_spin_lock_irqsave(&er->lock, flags);
if (!__BITS_VALUE(atomic_read(&er->ref), idx, 8) ||
!((config1 ^ er->config) & mask)) {
atomic_add(1 << (idx * 8), &er->ref);
er->config &= ~mask;
er->config |= config1 & mask;
ok = true;
}
raw_spin_unlock_irqrestore(&er->lock, flags);
if (!ok) {
idx = (idx + 1) % 4;
if (idx != reg1->idx) {
config1 = snbep_pcu_alter_er(event, idx, false);
goto again;
}
return &uncore_constraint_empty;
}
if (!uncore_box_is_fake(box)) {
if (idx != reg1->idx)
snbep_pcu_alter_er(event, idx, true);
reg1->alloc = 1;
}
return NULL;
}
static void snbep_pcu_put_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct intel_uncore_extra_reg *er = &box->shared_regs[0];
if (uncore_box_is_fake(box) || !reg1->alloc)
return;
atomic_sub(1 << (reg1->idx * 8), &er->ref);
reg1->alloc = 0;
}
static int snbep_pcu_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
int ev_sel = hwc->config & SNBEP_PMON_CTL_EV_SEL_MASK;
if (ev_sel >= 0xb && ev_sel <= 0xe) {
reg1->reg = SNBEP_PCU_MSR_PMON_BOX_FILTER;
reg1->idx = ev_sel - 0xb;
reg1->config = event->attr.config1 & (0xff << (reg1->idx * 8));
}
return 0;
}
void snbep_uncore_cpu_init(void)
{
if (snbep_uncore_cbox.num_boxes > boot_cpu_data.x86_max_cores)
snbep_uncore_cbox.num_boxes = boot_cpu_data.x86_max_cores;
uncore_msr_uncores = snbep_msr_uncores;
}
static int snbep_qpi_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
if ((hwc->config & SNBEP_PMON_CTL_EV_SEL_MASK) == 0x38) {
reg1->idx = 0;
reg1->reg = SNBEP_Q_Py_PCI_PMON_PKT_MATCH0;
reg1->config = event->attr.config1;
reg2->reg = SNBEP_Q_Py_PCI_PMON_PKT_MASK0;
reg2->config = event->attr.config2;
}
return 0;
}
static void snbep_qpi_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct pci_dev *pdev = box->pci_dev;
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
if (reg1->idx != EXTRA_REG_NONE) {
int idx = box->pmu->pmu_idx + SNBEP_PCI_QPI_PORT0_FILTER;
struct pci_dev *filter_pdev = uncore_extra_pci_dev[box->phys_id][idx];
if (filter_pdev) {
pci_write_config_dword(filter_pdev, reg1->reg,
(u32)reg1->config);
pci_write_config_dword(filter_pdev, reg1->reg + 4,
(u32)(reg1->config >> 32));
pci_write_config_dword(filter_pdev, reg2->reg,
(u32)reg2->config);
pci_write_config_dword(filter_pdev, reg2->reg + 4,
(u32)(reg2->config >> 32));
}
}
pci_write_config_dword(pdev, hwc->config_base, hwc->config | SNBEP_PMON_CTL_EN);
}
static int snbep_pci2phy_map_init(int devid)
{
struct pci_dev *ubox_dev = NULL;
int i, bus, nodeid;
int err = 0;
u32 config = 0;
while (1) {
ubox_dev = pci_get_device(PCI_VENDOR_ID_INTEL, devid, ubox_dev);
if (!ubox_dev)
break;
bus = ubox_dev->bus->number;
err = pci_read_config_dword(ubox_dev, 0x40, &config);
if (err)
break;
nodeid = config;
err = pci_read_config_dword(ubox_dev, 0x54, &config);
if (err)
break;
for (i = 0; i < 8; i++) {
if (nodeid == ((config >> (3 * i)) & 0x7)) {
uncore_pcibus_to_physid[bus] = i;
break;
}
}
}
if (!err) {
i = -1;
for (bus = 255; bus >= 0; bus--) {
if (uncore_pcibus_to_physid[bus] >= 0)
i = uncore_pcibus_to_physid[bus];
else
uncore_pcibus_to_physid[bus] = i;
}
}
if (ubox_dev)
pci_dev_put(ubox_dev);
return err ? pcibios_err_to_errno(err) : 0;
}
int snbep_uncore_pci_init(void)
{
int ret = snbep_pci2phy_map_init(0x3ce0);
if (ret)
return ret;
uncore_pci_uncores = snbep_pci_uncores;
uncore_pci_driver = &snbep_uncore_pci_driver;
return 0;
}
static void ivbep_uncore_msr_init_box(struct intel_uncore_box *box)
{
unsigned msr = uncore_msr_box_ctl(box);
if (msr)
wrmsrl(msr, IVBEP_PMON_BOX_CTL_INT);
}
static void ivbep_uncore_pci_init_box(struct intel_uncore_box *box)
{
struct pci_dev *pdev = box->pci_dev;
pci_write_config_dword(pdev, SNBEP_PCI_PMON_BOX_CTL, IVBEP_PMON_BOX_CTL_INT);
}
static u64 ivbep_cbox_filter_mask(int fields)
{
u64 mask = 0;
if (fields & 0x1)
mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_TID;
if (fields & 0x2)
mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_LINK;
if (fields & 0x4)
mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_STATE;
if (fields & 0x8)
mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_NID;
if (fields & 0x10) {
mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_OPC;
mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_NC;
mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_C6;
mask |= IVBEP_CB0_MSR_PMON_BOX_FILTER_ISOC;
}
return mask;
}
static struct event_constraint *
ivbep_cbox_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
return __snbep_cbox_get_constraint(box, event, ivbep_cbox_filter_mask);
}
static int ivbep_cbox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct extra_reg *er;
int idx = 0;
for (er = ivbep_uncore_cbox_extra_regs; er->msr; er++) {
if (er->event != (event->hw.config & er->config_mask))
continue;
idx |= er->idx;
}
if (idx) {
reg1->reg = SNBEP_C0_MSR_PMON_BOX_FILTER +
SNBEP_CBO_MSR_OFFSET * box->pmu->pmu_idx;
reg1->config = event->attr.config1 & ivbep_cbox_filter_mask(idx);
reg1->idx = idx;
}
return 0;
}
static void ivbep_cbox_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
if (reg1->idx != EXTRA_REG_NONE) {
u64 filter = uncore_shared_reg_config(box, 0);
wrmsrl(reg1->reg, filter & 0xffffffff);
wrmsrl(reg1->reg + 6, filter >> 32);
}
wrmsrl(hwc->config_base, hwc->config | SNBEP_PMON_CTL_EN);
}
void ivbep_uncore_cpu_init(void)
{
if (ivbep_uncore_cbox.num_boxes > boot_cpu_data.x86_max_cores)
ivbep_uncore_cbox.num_boxes = boot_cpu_data.x86_max_cores;
uncore_msr_uncores = ivbep_msr_uncores;
}
static void ivbep_uncore_irp_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct pci_dev *pdev = box->pci_dev;
struct hw_perf_event *hwc = &event->hw;
pci_write_config_dword(pdev, ivbep_uncore_irp_ctls[hwc->idx],
hwc->config | SNBEP_PMON_CTL_EN);
}
static void ivbep_uncore_irp_disable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct pci_dev *pdev = box->pci_dev;
struct hw_perf_event *hwc = &event->hw;
pci_write_config_dword(pdev, ivbep_uncore_irp_ctls[hwc->idx], hwc->config);
}
static u64 ivbep_uncore_irp_read_counter(struct intel_uncore_box *box, struct perf_event *event)
{
struct pci_dev *pdev = box->pci_dev;
struct hw_perf_event *hwc = &event->hw;
u64 count = 0;
pci_read_config_dword(pdev, ivbep_uncore_irp_ctrs[hwc->idx], (u32 *)&count);
pci_read_config_dword(pdev, ivbep_uncore_irp_ctrs[hwc->idx] + 4, (u32 *)&count + 1);
return count;
}
int ivbep_uncore_pci_init(void)
{
int ret = snbep_pci2phy_map_init(0x0e1e);
if (ret)
return ret;
uncore_pci_uncores = ivbep_pci_uncores;
uncore_pci_driver = &ivbep_uncore_pci_driver;
return 0;
}
static int hswep_ubox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
reg1->reg = HSWEP_U_MSR_PMON_FILTER;
reg1->config = event->attr.config1 & HSWEP_U_MSR_PMON_BOX_FILTER_MASK;
reg1->idx = 0;
return 0;
}
static u64 hswep_cbox_filter_mask(int fields)
{
u64 mask = 0;
if (fields & 0x1)
mask |= HSWEP_CB0_MSR_PMON_BOX_FILTER_TID;
if (fields & 0x2)
mask |= HSWEP_CB0_MSR_PMON_BOX_FILTER_LINK;
if (fields & 0x4)
mask |= HSWEP_CB0_MSR_PMON_BOX_FILTER_STATE;
if (fields & 0x8)
mask |= HSWEP_CB0_MSR_PMON_BOX_FILTER_NID;
if (fields & 0x10) {
mask |= HSWEP_CB0_MSR_PMON_BOX_FILTER_OPC;
mask |= HSWEP_CB0_MSR_PMON_BOX_FILTER_NC;
mask |= HSWEP_CB0_MSR_PMON_BOX_FILTER_C6;
mask |= HSWEP_CB0_MSR_PMON_BOX_FILTER_ISOC;
}
return mask;
}
static struct event_constraint *
hswep_cbox_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
return __snbep_cbox_get_constraint(box, event, hswep_cbox_filter_mask);
}
static int hswep_cbox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct extra_reg *er;
int idx = 0;
for (er = hswep_uncore_cbox_extra_regs; er->msr; er++) {
if (er->event != (event->hw.config & er->config_mask))
continue;
idx |= er->idx;
}
if (idx) {
reg1->reg = HSWEP_C0_MSR_PMON_BOX_FILTER0 +
HSWEP_CBO_MSR_OFFSET * box->pmu->pmu_idx;
reg1->config = event->attr.config1 & hswep_cbox_filter_mask(idx);
reg1->idx = idx;
}
return 0;
}
static void hswep_cbox_enable_event(struct intel_uncore_box *box,
struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
if (reg1->idx != EXTRA_REG_NONE) {
u64 filter = uncore_shared_reg_config(box, 0);
wrmsrl(reg1->reg, filter & 0xffffffff);
wrmsrl(reg1->reg + 1, filter >> 32);
}
wrmsrl(hwc->config_base, hwc->config | SNBEP_PMON_CTL_EN);
}
static void hswep_uncore_sbox_msr_init_box(struct intel_uncore_box *box)
{
unsigned msr = uncore_msr_box_ctl(box);
if (msr) {
u64 init = SNBEP_PMON_BOX_CTL_INT;
u64 flags = 0;
int i;
for_each_set_bit(i, (unsigned long *)&init, 64) {
flags |= (1ULL << i);
wrmsrl(msr, flags);
}
}
}
static int hswep_pcu_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
int ev_sel = hwc->config & SNBEP_PMON_CTL_EV_SEL_MASK;
if (ev_sel >= 0xb && ev_sel <= 0xe) {
reg1->reg = HSWEP_PCU_MSR_PMON_BOX_FILTER;
reg1->idx = ev_sel - 0xb;
reg1->config = event->attr.config1 & (0xff << reg1->idx);
}
return 0;
}
void hswep_uncore_cpu_init(void)
{
if (hswep_uncore_cbox.num_boxes > boot_cpu_data.x86_max_cores)
hswep_uncore_cbox.num_boxes = boot_cpu_data.x86_max_cores;
uncore_msr_uncores = hswep_msr_uncores;
}
static u64 hswep_uncore_irp_read_counter(struct intel_uncore_box *box, struct perf_event *event)
{
struct pci_dev *pdev = box->pci_dev;
struct hw_perf_event *hwc = &event->hw;
u64 count = 0;
pci_read_config_dword(pdev, hswep_uncore_irp_ctrs[hwc->idx], (u32 *)&count);
pci_read_config_dword(pdev, hswep_uncore_irp_ctrs[hwc->idx] + 4, (u32 *)&count + 1);
return count;
}
int hswep_uncore_pci_init(void)
{
int ret = snbep_pci2phy_map_init(0x2f1e);
if (ret)
return ret;
uncore_pci_uncores = hswep_pci_uncores;
uncore_pci_driver = &hswep_uncore_pci_driver;
return 0;
}
