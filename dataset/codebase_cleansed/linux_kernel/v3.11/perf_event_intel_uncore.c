static u64 uncore_msr_read_counter(struct intel_uncore_box *box, struct perf_event *event)
{
u64 count;
rdmsrl(event->hw.event_base, count);
return count;
}
static struct event_constraint *
uncore_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct intel_uncore_extra_reg *er;
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct hw_perf_event_extra *reg2 = &event->hw.branch_reg;
unsigned long flags;
bool ok = false;
if (reg1->idx == EXTRA_REG_NONE ||
(!uncore_box_is_fake(box) && reg1->alloc))
return NULL;
er = &box->shared_regs[reg1->idx];
raw_spin_lock_irqsave(&er->lock, flags);
if (!atomic_read(&er->ref) ||
(er->config1 == reg1->config && er->config2 == reg2->config)) {
atomic_inc(&er->ref);
er->config1 = reg1->config;
er->config2 = reg2->config;
ok = true;
}
raw_spin_unlock_irqrestore(&er->lock, flags);
if (ok) {
if (!uncore_box_is_fake(box))
reg1->alloc = 1;
return NULL;
}
return &constraint_empty;
}
static void uncore_put_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct intel_uncore_extra_reg *er;
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
if (uncore_box_is_fake(box) || !reg1->alloc)
return;
er = &box->shared_regs[reg1->idx];
atomic_dec(&er->ref);
reg1->alloc = 0;
}
static u64 uncore_shared_reg_config(struct intel_uncore_box *box, int idx)
{
struct intel_uncore_extra_reg *er;
unsigned long flags;
u64 config;
er = &box->shared_regs[idx];
raw_spin_lock_irqsave(&er->lock, flags);
config = er->config;
raw_spin_unlock_irqrestore(&er->lock, flags);
return config;
}
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
return &constraint_empty;
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
return &constraint_empty;
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
reg1->config = event->attr.config1 & (0xff << reg1->idx);
}
return 0;
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
pcibus_to_physid[bus] = i;
break;
}
}
}
if (ubox_dev)
pci_dev_put(ubox_dev);
return err ? pcibios_err_to_errno(err) : 0;
}
static void ivt_uncore_msr_init_box(struct intel_uncore_box *box)
{
unsigned msr = uncore_msr_box_ctl(box);
if (msr)
wrmsrl(msr, IVT_PMON_BOX_CTL_INT);
}
static void ivt_uncore_pci_init_box(struct intel_uncore_box *box)
{
struct pci_dev *pdev = box->pci_dev;
pci_write_config_dword(pdev, SNBEP_PCI_PMON_BOX_CTL, IVT_PMON_BOX_CTL_INT);
}
static u64 ivt_cbox_filter_mask(int fields)
{
u64 mask = 0;
if (fields & 0x1)
mask |= IVT_CB0_MSR_PMON_BOX_FILTER_TID;
if (fields & 0x2)
mask |= IVT_CB0_MSR_PMON_BOX_FILTER_LINK;
if (fields & 0x4)
mask |= IVT_CB0_MSR_PMON_BOX_FILTER_STATE;
if (fields & 0x8)
mask |= IVT_CB0_MSR_PMON_BOX_FILTER_NID;
if (fields & 0x10)
mask |= IVT_CB0_MSR_PMON_BOX_FILTER_OPC;
return mask;
}
static struct event_constraint *
ivt_cbox_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
return __snbep_cbox_get_constraint(box, event, ivt_cbox_filter_mask);
}
static int ivt_cbox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct extra_reg *er;
int idx = 0;
for (er = ivt_uncore_cbox_extra_regs; er->msr; er++) {
if (er->event != (event->hw.config & er->config_mask))
continue;
idx |= er->idx;
}
if (idx) {
reg1->reg = SNBEP_C0_MSR_PMON_BOX_FILTER +
SNBEP_CBO_MSR_OFFSET * box->pmu->pmu_idx;
reg1->config = event->attr.config1 & ivt_cbox_filter_mask(idx);
reg1->idx = idx;
}
return 0;
}
static void ivt_cbox_enable_event(struct intel_uncore_box *box, struct perf_event *event)
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
static void nhmex_uncore_msr_init_box(struct intel_uncore_box *box)
{
wrmsrl(NHMEX_U_MSR_PMON_GLOBAL_CTL, NHMEX_U_PMON_GLOBAL_EN_ALL);
}
static void nhmex_uncore_msr_disable_box(struct intel_uncore_box *box)
{
unsigned msr = uncore_msr_box_ctl(box);
u64 config;
if (msr) {
rdmsrl(msr, config);
config &= ~((1ULL << uncore_num_counters(box)) - 1);
if (uncore_msr_fixed_ctl(box))
config &= ~NHMEX_W_PMON_GLOBAL_FIXED_EN;
wrmsrl(msr, config);
}
}
static void nhmex_uncore_msr_enable_box(struct intel_uncore_box *box)
{
unsigned msr = uncore_msr_box_ctl(box);
u64 config;
if (msr) {
rdmsrl(msr, config);
config |= (1ULL << uncore_num_counters(box)) - 1;
if (uncore_msr_fixed_ctl(box))
config |= NHMEX_W_PMON_GLOBAL_FIXED_EN;
wrmsrl(msr, config);
}
}
static void nhmex_uncore_msr_disable_event(struct intel_uncore_box *box, struct perf_event *event)
{
wrmsrl(event->hw.config_base, 0);
}
static void nhmex_uncore_msr_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
if (hwc->idx >= UNCORE_PMC_IDX_FIXED)
wrmsrl(hwc->config_base, NHMEX_PMON_CTL_EN_BIT0);
else if (box->pmu->type->event_mask & NHMEX_PMON_CTL_EN_BIT0)
wrmsrl(hwc->config_base, hwc->config | NHMEX_PMON_CTL_EN_BIT22);
else
wrmsrl(hwc->config_base, hwc->config | NHMEX_PMON_CTL_EN_BIT0);
}
static int nhmex_bbox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
int ctr, ev_sel;
ctr = (hwc->config & NHMEX_B_PMON_CTR_MASK) >>
NHMEX_B_PMON_CTR_SHIFT;
ev_sel = (hwc->config & NHMEX_B_PMON_CTL_EV_SEL_MASK) >>
NHMEX_B_PMON_CTL_EV_SEL_SHIFT;
if ((ctr == 0 && ev_sel > 0x3) || (ctr == 1 && ev_sel > 0x6) ||
(ctr == 2 && ev_sel != 0x4) || ctr == 3)
return 0;
if (box->pmu->pmu_idx == 0)
reg1->reg = NHMEX_B0_MSR_MATCH;
else
reg1->reg = NHMEX_B1_MSR_MATCH;
reg1->idx = 0;
reg1->config = event->attr.config1;
reg2->config = event->attr.config2;
return 0;
}
static void nhmex_bbox_msr_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
if (reg1->idx != EXTRA_REG_NONE) {
wrmsrl(reg1->reg, reg1->config);
wrmsrl(reg1->reg + 1, reg2->config);
}
wrmsrl(hwc->config_base, NHMEX_PMON_CTL_EN_BIT0 |
(hwc->config & NHMEX_B_PMON_CTL_EV_SEL_MASK));
}
static int nhmex_sbox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
if ((hwc->config & NHMEX_PMON_CTL_EV_SEL_MASK) !=
NHMEX_S_EVENT_TO_R_PROG_EV)
return 0;
if (box->pmu->pmu_idx == 0)
reg1->reg = NHMEX_S0_MSR_MM_CFG;
else
reg1->reg = NHMEX_S1_MSR_MM_CFG;
reg1->idx = 0;
reg1->config = event->attr.config1;
reg2->config = event->attr.config2;
return 0;
}
static void nhmex_sbox_msr_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
if (reg1->idx != EXTRA_REG_NONE) {
wrmsrl(reg1->reg, 0);
wrmsrl(reg1->reg + 1, reg1->config);
wrmsrl(reg1->reg + 2, reg2->config);
wrmsrl(reg1->reg, NHMEX_S_PMON_MM_CFG_EN);
}
wrmsrl(hwc->config_base, hwc->config | NHMEX_PMON_CTL_EN_BIT22);
}
static bool nhmex_mbox_get_shared_reg(struct intel_uncore_box *box, int idx, u64 config)
{
struct intel_uncore_extra_reg *er;
unsigned long flags;
bool ret = false;
u64 mask;
if (idx < EXTRA_REG_NHMEX_M_ZDP_CTL_FVC) {
er = &box->shared_regs[idx];
raw_spin_lock_irqsave(&er->lock, flags);
if (!atomic_read(&er->ref) || er->config == config) {
atomic_inc(&er->ref);
er->config = config;
ret = true;
}
raw_spin_unlock_irqrestore(&er->lock, flags);
return ret;
}
idx -= EXTRA_REG_NHMEX_M_ZDP_CTL_FVC;
if (WARN_ON_ONCE(idx >= 4))
return false;
if (uncore_nhmex)
mask = NHMEX_M_PMON_ZDP_CTL_FVC_MASK;
else
mask = WSMEX_M_PMON_ZDP_CTL_FVC_MASK;
er = &box->shared_regs[EXTRA_REG_NHMEX_M_ZDP_CTL_FVC];
raw_spin_lock_irqsave(&er->lock, flags);
if (__BITS_VALUE(atomic_read(&er->ref), idx, 8)) {
if (uncore_nhmex)
mask |= NHMEX_M_PMON_ZDP_CTL_FVC_EVENT_MASK(idx);
else
mask |= WSMEX_M_PMON_ZDP_CTL_FVC_EVENT_MASK(idx);
}
if (!atomic_read(&er->ref) || !((er->config ^ config) & mask)) {
atomic_add(1 << (idx * 8), &er->ref);
if (uncore_nhmex)
mask = NHMEX_M_PMON_ZDP_CTL_FVC_MASK |
NHMEX_M_PMON_ZDP_CTL_FVC_EVENT_MASK(idx);
else
mask = WSMEX_M_PMON_ZDP_CTL_FVC_MASK |
WSMEX_M_PMON_ZDP_CTL_FVC_EVENT_MASK(idx);
er->config &= ~mask;
er->config |= (config & mask);
ret = true;
}
raw_spin_unlock_irqrestore(&er->lock, flags);
return ret;
}
static void nhmex_mbox_put_shared_reg(struct intel_uncore_box *box, int idx)
{
struct intel_uncore_extra_reg *er;
if (idx < EXTRA_REG_NHMEX_M_ZDP_CTL_FVC) {
er = &box->shared_regs[idx];
atomic_dec(&er->ref);
return;
}
idx -= EXTRA_REG_NHMEX_M_ZDP_CTL_FVC;
er = &box->shared_regs[EXTRA_REG_NHMEX_M_ZDP_CTL_FVC];
atomic_sub(1 << (idx * 8), &er->ref);
}
static u64 nhmex_mbox_alter_er(struct perf_event *event, int new_idx, bool modify)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
u64 idx, orig_idx = __BITS_VALUE(reg1->idx, 0, 8);
u64 config = reg1->config;
idx = orig_idx - EXTRA_REG_NHMEX_M_ZDP_CTL_FVC;
if (uncore_nhmex)
config &= NHMEX_M_PMON_ZDP_CTL_FVC_EVENT_MASK(idx);
else
config &= WSMEX_M_PMON_ZDP_CTL_FVC_EVENT_MASK(idx);
if (new_idx > orig_idx) {
idx = new_idx - orig_idx;
config <<= 3 * idx;
} else {
idx = orig_idx - new_idx;
config >>= 3 * idx;
}
if (uncore_nhmex)
config |= NHMEX_M_PMON_ZDP_CTL_FVC_MASK & reg1->config;
else
config |= WSMEX_M_PMON_ZDP_CTL_FVC_MASK & reg1->config;
config |= NHMEX_M_PMON_ZDP_CTL_FVC_MASK & reg1->config;
if (modify) {
if (new_idx > orig_idx)
hwc->config += idx << NHMEX_M_PMON_CTL_INC_SEL_SHIFT;
else
hwc->config -= idx << NHMEX_M_PMON_CTL_INC_SEL_SHIFT;
reg1->config = config;
reg1->idx = ~0xff | new_idx;
}
return config;
}
static struct event_constraint *
nhmex_mbox_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct hw_perf_event_extra *reg2 = &event->hw.branch_reg;
int i, idx[2], alloc = 0;
u64 config1 = reg1->config;
idx[0] = __BITS_VALUE(reg1->idx, 0, 8);
idx[1] = __BITS_VALUE(reg1->idx, 1, 8);
again:
for (i = 0; i < 2; i++) {
if (!uncore_box_is_fake(box) && (reg1->alloc & (0x1 << i)))
idx[i] = 0xff;
if (idx[i] == 0xff)
continue;
if (!nhmex_mbox_get_shared_reg(box, idx[i],
__BITS_VALUE(config1, i, 32)))
goto fail;
alloc |= (0x1 << i);
}
if (reg2->idx != EXTRA_REG_NONE &&
(uncore_box_is_fake(box) || !reg2->alloc) &&
!nhmex_mbox_get_shared_reg(box, reg2->idx, reg2->config))
goto fail;
if (!uncore_box_is_fake(box)) {
if (idx[0] != 0xff && idx[0] != __BITS_VALUE(reg1->idx, 0, 8))
nhmex_mbox_alter_er(event, idx[0], true);
reg1->alloc |= alloc;
if (reg2->idx != EXTRA_REG_NONE)
reg2->alloc = 1;
}
return NULL;
fail:
if (idx[0] != 0xff && !(alloc & 0x1) &&
idx[0] >= EXTRA_REG_NHMEX_M_ZDP_CTL_FVC) {
BUG_ON(__BITS_VALUE(reg1->idx, 1, 8) != 0xff);
idx[0] -= EXTRA_REG_NHMEX_M_ZDP_CTL_FVC;
idx[0] = (idx[0] + 1) % 4;
idx[0] += EXTRA_REG_NHMEX_M_ZDP_CTL_FVC;
if (idx[0] != __BITS_VALUE(reg1->idx, 0, 8)) {
config1 = nhmex_mbox_alter_er(event, idx[0], false);
goto again;
}
}
if (alloc & 0x1)
nhmex_mbox_put_shared_reg(box, idx[0]);
if (alloc & 0x2)
nhmex_mbox_put_shared_reg(box, idx[1]);
return &constraint_empty;
}
static void nhmex_mbox_put_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct hw_perf_event_extra *reg2 = &event->hw.branch_reg;
if (uncore_box_is_fake(box))
return;
if (reg1->alloc & 0x1)
nhmex_mbox_put_shared_reg(box, __BITS_VALUE(reg1->idx, 0, 8));
if (reg1->alloc & 0x2)
nhmex_mbox_put_shared_reg(box, __BITS_VALUE(reg1->idx, 1, 8));
reg1->alloc = 0;
if (reg2->alloc) {
nhmex_mbox_put_shared_reg(box, reg2->idx);
reg2->alloc = 0;
}
}
static int nhmex_mbox_extra_reg_idx(struct extra_reg *er)
{
if (er->idx < EXTRA_REG_NHMEX_M_ZDP_CTL_FVC)
return er->idx;
return er->idx + (er->event >> NHMEX_M_PMON_CTL_INC_SEL_SHIFT) - 0xd;
}
static int nhmex_mbox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct intel_uncore_type *type = box->pmu->type;
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct hw_perf_event_extra *reg2 = &event->hw.branch_reg;
struct extra_reg *er;
unsigned msr;
int reg_idx = 0;
for (er = nhmex_uncore_mbox_extra_regs; er->msr; er++) {
if (er->event != (event->hw.config & er->config_mask))
continue;
if (event->attr.config1 & ~er->valid_mask)
return -EINVAL;
msr = er->msr + type->msr_offset * box->pmu->pmu_idx;
if (WARN_ON_ONCE(msr >= 0xffff || er->idx >= 0xff))
return -EINVAL;
if (er->idx == EXTRA_REG_NHMEX_M_PLD)
reg_idx = 1;
else if (WARN_ON_ONCE(reg_idx > 0))
return -EINVAL;
reg1->idx &= ~(0xff << (reg_idx * 8));
reg1->reg &= ~(0xffff << (reg_idx * 16));
reg1->idx |= nhmex_mbox_extra_reg_idx(er) << (reg_idx * 8);
reg1->reg |= msr << (reg_idx * 16);
reg1->config = event->attr.config1;
reg_idx++;
}
if (reg_idx == 2) {
reg2->idx = EXTRA_REG_NHMEX_M_FILTER;
if (event->attr.config2 & NHMEX_M_PMON_MM_CFG_EN)
reg2->config = event->attr.config2;
else
reg2->config = ~0ULL;
if (box->pmu->pmu_idx == 0)
reg2->reg = NHMEX_M0_MSR_PMU_MM_CFG;
else
reg2->reg = NHMEX_M1_MSR_PMU_MM_CFG;
}
return 0;
}
static u64 nhmex_mbox_shared_reg_config(struct intel_uncore_box *box, int idx)
{
struct intel_uncore_extra_reg *er;
unsigned long flags;
u64 config;
if (idx < EXTRA_REG_NHMEX_M_ZDP_CTL_FVC)
return box->shared_regs[idx].config;
er = &box->shared_regs[EXTRA_REG_NHMEX_M_ZDP_CTL_FVC];
raw_spin_lock_irqsave(&er->lock, flags);
config = er->config;
raw_spin_unlock_irqrestore(&er->lock, flags);
return config;
}
static void nhmex_mbox_msr_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
int idx;
idx = __BITS_VALUE(reg1->idx, 0, 8);
if (idx != 0xff)
wrmsrl(__BITS_VALUE(reg1->reg, 0, 16),
nhmex_mbox_shared_reg_config(box, idx));
idx = __BITS_VALUE(reg1->idx, 1, 8);
if (idx != 0xff)
wrmsrl(__BITS_VALUE(reg1->reg, 1, 16),
nhmex_mbox_shared_reg_config(box, idx));
if (reg2->idx != EXTRA_REG_NONE) {
wrmsrl(reg2->reg, 0);
if (reg2->config != ~0ULL) {
wrmsrl(reg2->reg + 1,
reg2->config & NHMEX_M_PMON_ADDR_MATCH_MASK);
wrmsrl(reg2->reg + 2, NHMEX_M_PMON_ADDR_MASK_MASK &
(reg2->config >> NHMEX_M_PMON_ADDR_MASK_SHIFT));
wrmsrl(reg2->reg, NHMEX_M_PMON_MM_CFG_EN);
}
}
wrmsrl(hwc->config_base, hwc->config | NHMEX_PMON_CTL_EN_BIT0);
}
static void nhmex_rbox_alter_er(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
if (reg1->idx % 2) {
reg1->idx--;
hwc->config -= 1 << NHMEX_R_PMON_CTL_EV_SEL_SHIFT;
} else {
reg1->idx++;
hwc->config += 1 << NHMEX_R_PMON_CTL_EV_SEL_SHIFT;
}
switch (reg1->idx % 6) {
case 2:
reg1->config >>= 8;
break;
case 3:
reg1->config <<= 8;
break;
};
}
static struct event_constraint *
nhmex_rbox_get_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
struct intel_uncore_extra_reg *er;
unsigned long flags;
int idx, er_idx;
u64 config1;
bool ok = false;
if (!uncore_box_is_fake(box) && reg1->alloc)
return NULL;
idx = reg1->idx % 6;
config1 = reg1->config;
again:
er_idx = idx;
if (er_idx > 2)
er_idx--;
er_idx += (reg1->idx / 6) * 5;
er = &box->shared_regs[er_idx];
raw_spin_lock_irqsave(&er->lock, flags);
if (idx < 2) {
if (!atomic_read(&er->ref) || er->config == reg1->config) {
atomic_inc(&er->ref);
er->config = reg1->config;
ok = true;
}
} else if (idx == 2 || idx == 3) {
u64 mask = 0xff << ((idx - 2) * 8);
if (!__BITS_VALUE(atomic_read(&er->ref), idx - 2, 8) ||
!((er->config ^ config1) & mask)) {
atomic_add(1 << ((idx - 2) * 8), &er->ref);
er->config &= ~mask;
er->config |= config1 & mask;
ok = true;
}
} else {
if (!atomic_read(&er->ref) ||
(er->config == (hwc->config >> 32) &&
er->config1 == reg1->config &&
er->config2 == reg2->config)) {
atomic_inc(&er->ref);
er->config = (hwc->config >> 32);
er->config1 = reg1->config;
er->config2 = reg2->config;
ok = true;
}
}
raw_spin_unlock_irqrestore(&er->lock, flags);
if (!ok) {
if (idx % 2)
idx--;
else
idx++;
if (idx != reg1->idx % 6) {
if (idx == 2)
config1 >>= 8;
else if (idx == 3)
config1 <<= 8;
goto again;
}
} else {
if (!uncore_box_is_fake(box)) {
if (idx != reg1->idx % 6)
nhmex_rbox_alter_er(box, event);
reg1->alloc = 1;
}
return NULL;
}
return &constraint_empty;
}
static void nhmex_rbox_put_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct intel_uncore_extra_reg *er;
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
int idx, er_idx;
if (uncore_box_is_fake(box) || !reg1->alloc)
return;
idx = reg1->idx % 6;
er_idx = idx;
if (er_idx > 2)
er_idx--;
er_idx += (reg1->idx / 6) * 5;
er = &box->shared_regs[er_idx];
if (idx == 2 || idx == 3)
atomic_sub(1 << ((idx - 2) * 8), &er->ref);
else
atomic_dec(&er->ref);
reg1->alloc = 0;
}
static int nhmex_rbox_hw_config(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &event->hw.extra_reg;
struct hw_perf_event_extra *reg2 = &event->hw.branch_reg;
int idx;
idx = (event->hw.config & NHMEX_R_PMON_CTL_EV_SEL_MASK) >>
NHMEX_R_PMON_CTL_EV_SEL_SHIFT;
if (idx >= 0x18)
return -EINVAL;
reg1->idx = idx;
reg1->config = event->attr.config1;
switch (idx % 6) {
case 4:
case 5:
hwc->config |= event->attr.config & (~0ULL << 32);
reg2->config = event->attr.config2;
break;
};
return 0;
}
static void nhmex_rbox_msr_enable_event(struct intel_uncore_box *box, struct perf_event *event)
{
struct hw_perf_event *hwc = &event->hw;
struct hw_perf_event_extra *reg1 = &hwc->extra_reg;
struct hw_perf_event_extra *reg2 = &hwc->branch_reg;
int idx, port;
idx = reg1->idx;
port = idx / 6 + box->pmu->pmu_idx * 4;
switch (idx % 6) {
case 0:
wrmsrl(NHMEX_R_MSR_PORTN_IPERF_CFG0(port), reg1->config);
break;
case 1:
wrmsrl(NHMEX_R_MSR_PORTN_IPERF_CFG1(port), reg1->config);
break;
case 2:
case 3:
wrmsrl(NHMEX_R_MSR_PORTN_QLX_CFG(port),
uncore_shared_reg_config(box, 2 + (idx / 6) * 5));
break;
case 4:
wrmsrl(NHMEX_R_MSR_PORTN_XBR_SET1_MM_CFG(port),
hwc->config >> 32);
wrmsrl(NHMEX_R_MSR_PORTN_XBR_SET1_MATCH(port), reg1->config);
wrmsrl(NHMEX_R_MSR_PORTN_XBR_SET1_MASK(port), reg2->config);
break;
case 5:
wrmsrl(NHMEX_R_MSR_PORTN_XBR_SET2_MM_CFG(port),
hwc->config >> 32);
wrmsrl(NHMEX_R_MSR_PORTN_XBR_SET2_MATCH(port), reg1->config);
wrmsrl(NHMEX_R_MSR_PORTN_XBR_SET2_MASK(port), reg2->config);
break;
};
wrmsrl(hwc->config_base, NHMEX_PMON_CTL_EN_BIT0 |
(hwc->config & NHMEX_R_PMON_CTL_EV_SEL_MASK));
}
static void uncore_assign_hw_event(struct intel_uncore_box *box, struct perf_event *event, int idx)
{
struct hw_perf_event *hwc = &event->hw;
hwc->idx = idx;
hwc->last_tag = ++box->tags[idx];
if (hwc->idx == UNCORE_PMC_IDX_FIXED) {
hwc->event_base = uncore_fixed_ctr(box);
hwc->config_base = uncore_fixed_ctl(box);
return;
}
hwc->config_base = uncore_event_ctl(box, hwc->idx);
hwc->event_base = uncore_perf_ctr(box, hwc->idx);
}
static void uncore_perf_event_update(struct intel_uncore_box *box, struct perf_event *event)
{
u64 prev_count, new_count, delta;
int shift;
if (event->hw.idx >= UNCORE_PMC_IDX_FIXED)
shift = 64 - uncore_fixed_ctr_bits(box);
else
shift = 64 - uncore_perf_ctr_bits(box);
again:
prev_count = local64_read(&event->hw.prev_count);
new_count = uncore_read_counter(box, event);
if (local64_xchg(&event->hw.prev_count, new_count) != prev_count)
goto again;
delta = (new_count << shift) - (prev_count << shift);
delta >>= shift;
local64_add(delta, &event->count);
}
static enum hrtimer_restart uncore_pmu_hrtimer(struct hrtimer *hrtimer)
{
struct intel_uncore_box *box;
unsigned long flags;
int bit;
box = container_of(hrtimer, struct intel_uncore_box, hrtimer);
if (!box->n_active || box->cpu != smp_processor_id())
return HRTIMER_NORESTART;
local_irq_save(flags);
for_each_set_bit(bit, box->active_mask, UNCORE_PMC_IDX_MAX)
uncore_perf_event_update(box, box->events[bit]);
local_irq_restore(flags);
hrtimer_forward_now(hrtimer, ns_to_ktime(UNCORE_PMU_HRTIMER_INTERVAL));
return HRTIMER_RESTART;
}
static void uncore_pmu_start_hrtimer(struct intel_uncore_box *box)
{
__hrtimer_start_range_ns(&box->hrtimer,
ns_to_ktime(UNCORE_PMU_HRTIMER_INTERVAL), 0,
HRTIMER_MODE_REL_PINNED, 0);
}
static void uncore_pmu_cancel_hrtimer(struct intel_uncore_box *box)
{
hrtimer_cancel(&box->hrtimer);
}
static void uncore_pmu_init_hrtimer(struct intel_uncore_box *box)
{
hrtimer_init(&box->hrtimer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
box->hrtimer.function = uncore_pmu_hrtimer;
}
struct intel_uncore_box *uncore_alloc_box(struct intel_uncore_type *type, int cpu)
{
struct intel_uncore_box *box;
int i, size;
size = sizeof(*box) + type->num_shared_regs * sizeof(struct intel_uncore_extra_reg);
box = kmalloc_node(size, GFP_KERNEL | __GFP_ZERO, cpu_to_node(cpu));
if (!box)
return NULL;
for (i = 0; i < type->num_shared_regs; i++)
raw_spin_lock_init(&box->shared_regs[i].lock);
uncore_pmu_init_hrtimer(box);
atomic_set(&box->refcnt, 1);
box->cpu = -1;
box->phys_id = -1;
return box;
}
static struct intel_uncore_box *
uncore_pmu_to_box(struct intel_uncore_pmu *pmu, int cpu)
{
struct intel_uncore_box *box;
box = *per_cpu_ptr(pmu->box, cpu);
if (box)
return box;
raw_spin_lock(&uncore_box_lock);
list_for_each_entry(box, &pmu->box_list, list) {
if (box->phys_id == topology_physical_package_id(cpu)) {
atomic_inc(&box->refcnt);
*per_cpu_ptr(pmu->box, cpu) = box;
break;
}
}
raw_spin_unlock(&uncore_box_lock);
return *per_cpu_ptr(pmu->box, cpu);
}
static struct intel_uncore_pmu *uncore_event_to_pmu(struct perf_event *event)
{
return container_of(event->pmu, struct intel_uncore_pmu, pmu);
}
static struct intel_uncore_box *uncore_event_to_box(struct perf_event *event)
{
return uncore_pmu_to_box(uncore_event_to_pmu(event), smp_processor_id());
}
static int
uncore_collect_events(struct intel_uncore_box *box, struct perf_event *leader, bool dogrp)
{
struct perf_event *event;
int n, max_count;
max_count = box->pmu->type->num_counters;
if (box->pmu->type->fixed_ctl)
max_count++;
if (box->n_events >= max_count)
return -EINVAL;
n = box->n_events;
box->event_list[n] = leader;
n++;
if (!dogrp)
return n;
list_for_each_entry(event, &leader->sibling_list, group_entry) {
if (event->state <= PERF_EVENT_STATE_OFF)
continue;
if (n >= max_count)
return -EINVAL;
box->event_list[n] = event;
n++;
}
return n;
}
static struct event_constraint *
uncore_get_event_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
struct intel_uncore_type *type = box->pmu->type;
struct event_constraint *c;
if (type->ops->get_constraint) {
c = type->ops->get_constraint(box, event);
if (c)
return c;
}
if (event->hw.config == ~0ULL)
return &constraint_fixed;
if (type->constraints) {
for_each_event_constraint(c, type->constraints) {
if ((event->hw.config & c->cmask) == c->code)
return c;
}
}
return &type->unconstrainted;
}
static void uncore_put_event_constraint(struct intel_uncore_box *box, struct perf_event *event)
{
if (box->pmu->type->ops->put_constraint)
box->pmu->type->ops->put_constraint(box, event);
}
static int uncore_assign_events(struct intel_uncore_box *box, int assign[], int n)
{
unsigned long used_mask[BITS_TO_LONGS(UNCORE_PMC_IDX_MAX)];
struct event_constraint *c;
int i, wmin, wmax, ret = 0;
struct hw_perf_event *hwc;
bitmap_zero(used_mask, UNCORE_PMC_IDX_MAX);
for (i = 0, wmin = UNCORE_PMC_IDX_MAX, wmax = 0; i < n; i++) {
hwc = &box->event_list[i]->hw;
c = uncore_get_event_constraint(box, box->event_list[i]);
hwc->constraint = c;
wmin = min(wmin, c->weight);
wmax = max(wmax, c->weight);
}
for (i = 0; i < n; i++) {
hwc = &box->event_list[i]->hw;
c = hwc->constraint;
if (hwc->idx == -1)
break;
if (!test_bit(hwc->idx, c->idxmsk))
break;
if (test_bit(hwc->idx, used_mask))
break;
__set_bit(hwc->idx, used_mask);
if (assign)
assign[i] = hwc->idx;
}
if (i != n)
ret = perf_assign_events(box->event_list, n,
wmin, wmax, assign);
if (!assign || ret) {
for (i = 0; i < n; i++)
uncore_put_event_constraint(box, box->event_list[i]);
}
return ret ? -EINVAL : 0;
}
static void uncore_pmu_event_start(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
int idx = event->hw.idx;
if (WARN_ON_ONCE(!(event->hw.state & PERF_HES_STOPPED)))
return;
if (WARN_ON_ONCE(idx == -1 || idx >= UNCORE_PMC_IDX_MAX))
return;
event->hw.state = 0;
box->events[idx] = event;
box->n_active++;
__set_bit(idx, box->active_mask);
local64_set(&event->hw.prev_count, uncore_read_counter(box, event));
uncore_enable_event(box, event);
if (box->n_active == 1) {
uncore_enable_box(box);
uncore_pmu_start_hrtimer(box);
}
}
static void uncore_pmu_event_stop(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
struct hw_perf_event *hwc = &event->hw;
if (__test_and_clear_bit(hwc->idx, box->active_mask)) {
uncore_disable_event(box, event);
box->n_active--;
box->events[hwc->idx] = NULL;
WARN_ON_ONCE(hwc->state & PERF_HES_STOPPED);
hwc->state |= PERF_HES_STOPPED;
if (box->n_active == 0) {
uncore_disable_box(box);
uncore_pmu_cancel_hrtimer(box);
}
}
if ((flags & PERF_EF_UPDATE) && !(hwc->state & PERF_HES_UPTODATE)) {
uncore_perf_event_update(box, event);
hwc->state |= PERF_HES_UPTODATE;
}
}
static int uncore_pmu_event_add(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
struct hw_perf_event *hwc = &event->hw;
int assign[UNCORE_PMC_IDX_MAX];
int i, n, ret;
if (!box)
return -ENODEV;
ret = n = uncore_collect_events(box, event, false);
if (ret < 0)
return ret;
hwc->state = PERF_HES_UPTODATE | PERF_HES_STOPPED;
if (!(flags & PERF_EF_START))
hwc->state |= PERF_HES_ARCH;
ret = uncore_assign_events(box, assign, n);
if (ret)
return ret;
for (i = 0; i < box->n_events; i++) {
event = box->event_list[i];
hwc = &event->hw;
if (hwc->idx == assign[i] &&
hwc->last_tag == box->tags[assign[i]])
continue;
if (hwc->state & PERF_HES_STOPPED)
hwc->state |= PERF_HES_ARCH;
uncore_pmu_event_stop(event, PERF_EF_UPDATE);
}
for (i = 0; i < n; i++) {
event = box->event_list[i];
hwc = &event->hw;
if (hwc->idx != assign[i] ||
hwc->last_tag != box->tags[assign[i]])
uncore_assign_hw_event(box, event, assign[i]);
else if (i < box->n_events)
continue;
if (hwc->state & PERF_HES_ARCH)
continue;
uncore_pmu_event_start(event, 0);
}
box->n_events = n;
return 0;
}
static void uncore_pmu_event_del(struct perf_event *event, int flags)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
int i;
uncore_pmu_event_stop(event, PERF_EF_UPDATE);
for (i = 0; i < box->n_events; i++) {
if (event == box->event_list[i]) {
uncore_put_event_constraint(box, event);
while (++i < box->n_events)
box->event_list[i - 1] = box->event_list[i];
--box->n_events;
break;
}
}
event->hw.idx = -1;
event->hw.last_tag = ~0ULL;
}
static void uncore_pmu_event_read(struct perf_event *event)
{
struct intel_uncore_box *box = uncore_event_to_box(event);
uncore_perf_event_update(box, event);
}
static int uncore_validate_group(struct intel_uncore_pmu *pmu,
struct perf_event *event)
{
struct perf_event *leader = event->group_leader;
struct intel_uncore_box *fake_box;
int ret = -EINVAL, n;
fake_box = uncore_alloc_box(pmu->type, smp_processor_id());
if (!fake_box)
return -ENOMEM;
fake_box->pmu = pmu;
n = uncore_collect_events(fake_box, leader, true);
if (n < 0)
goto out;
fake_box->n_events = n;
n = uncore_collect_events(fake_box, event, false);
if (n < 0)
goto out;
fake_box->n_events = n;
ret = uncore_assign_events(fake_box, NULL, n);
out:
kfree(fake_box);
return ret;
}
static int uncore_pmu_event_init(struct perf_event *event)
{
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
struct hw_perf_event *hwc = &event->hw;
int ret;
if (event->attr.type != event->pmu->type)
return -ENOENT;
pmu = uncore_event_to_pmu(event);
if (pmu->func_id < 0)
return -ENOENT;
if (event->attr.exclude_user || event->attr.exclude_kernel ||
event->attr.exclude_hv || event->attr.exclude_idle)
return -EINVAL;
if (hwc->sample_period)
return -EINVAL;
if (event->cpu < 0)
return -EINVAL;
box = uncore_pmu_to_box(pmu, event->cpu);
if (!box || box->cpu < 0)
return -EINVAL;
event->cpu = box->cpu;
event->hw.idx = -1;
event->hw.last_tag = ~0ULL;
event->hw.extra_reg.idx = EXTRA_REG_NONE;
event->hw.branch_reg.idx = EXTRA_REG_NONE;
if (event->attr.config == UNCORE_FIXED_EVENT) {
if (!pmu->type->fixed_ctl)
return -EINVAL;
if (pmu->type->single_fixed && pmu->pmu_idx > 0)
return -EINVAL;
hwc->config = ~0ULL;
} else {
hwc->config = event->attr.config & pmu->type->event_mask;
if (pmu->type->ops->hw_config) {
ret = pmu->type->ops->hw_config(box, event);
if (ret)
return ret;
}
}
if (event->group_leader != event)
ret = uncore_validate_group(pmu, event);
else
ret = 0;
return ret;
}
static ssize_t uncore_get_attr_cpumask(struct device *dev,
struct device_attribute *attr, char *buf)
{
int n = cpulist_scnprintf(buf, PAGE_SIZE - 2, &uncore_cpu_mask);
buf[n++] = '\n';
buf[n] = '\0';
return n;
}
static int __init uncore_pmu_register(struct intel_uncore_pmu *pmu)
{
int ret;
pmu->pmu = (struct pmu) {
.attr_groups = pmu->type->attr_groups,
.task_ctx_nr = perf_invalid_context,
.event_init = uncore_pmu_event_init,
.add = uncore_pmu_event_add,
.del = uncore_pmu_event_del,
.start = uncore_pmu_event_start,
.stop = uncore_pmu_event_stop,
.read = uncore_pmu_event_read,
};
if (pmu->type->num_boxes == 1) {
if (strlen(pmu->type->name) > 0)
sprintf(pmu->name, "uncore_%s", pmu->type->name);
else
sprintf(pmu->name, "uncore");
} else {
sprintf(pmu->name, "uncore_%s_%d", pmu->type->name,
pmu->pmu_idx);
}
ret = perf_pmu_register(&pmu->pmu, pmu->name, -1);
return ret;
}
static void __init uncore_type_exit(struct intel_uncore_type *type)
{
int i;
for (i = 0; i < type->num_boxes; i++)
free_percpu(type->pmus[i].box);
kfree(type->pmus);
type->pmus = NULL;
kfree(type->events_group);
type->events_group = NULL;
}
static void __init uncore_types_exit(struct intel_uncore_type **types)
{
int i;
for (i = 0; types[i]; i++)
uncore_type_exit(types[i]);
}
static int __init uncore_type_init(struct intel_uncore_type *type)
{
struct intel_uncore_pmu *pmus;
struct attribute_group *attr_group;
struct attribute **attrs;
int i, j;
pmus = kzalloc(sizeof(*pmus) * type->num_boxes, GFP_KERNEL);
if (!pmus)
return -ENOMEM;
type->unconstrainted = (struct event_constraint)
__EVENT_CONSTRAINT(0, (1ULL << type->num_counters) - 1,
0, type->num_counters, 0, 0);
for (i = 0; i < type->num_boxes; i++) {
pmus[i].func_id = -1;
pmus[i].pmu_idx = i;
pmus[i].type = type;
INIT_LIST_HEAD(&pmus[i].box_list);
pmus[i].box = alloc_percpu(struct intel_uncore_box *);
if (!pmus[i].box)
goto fail;
}
if (type->event_descs) {
i = 0;
while (type->event_descs[i].attr.attr.name)
i++;
attr_group = kzalloc(sizeof(struct attribute *) * (i + 1) +
sizeof(*attr_group), GFP_KERNEL);
if (!attr_group)
goto fail;
attrs = (struct attribute **)(attr_group + 1);
attr_group->name = "events";
attr_group->attrs = attrs;
for (j = 0; j < i; j++)
attrs[j] = &type->event_descs[j].attr.attr;
type->events_group = attr_group;
}
type->pmu_group = &uncore_pmu_attr_group;
type->pmus = pmus;
return 0;
fail:
uncore_type_exit(type);
return -ENOMEM;
}
static int __init uncore_types_init(struct intel_uncore_type **types)
{
int i, ret;
for (i = 0; types[i]; i++) {
ret = uncore_type_init(types[i]);
if (ret)
goto fail;
}
return 0;
fail:
while (--i >= 0)
uncore_type_exit(types[i]);
return ret;
}
static int uncore_pci_add(struct intel_uncore_type *type, struct pci_dev *pdev)
{
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
int i, phys_id;
phys_id = pcibus_to_physid[pdev->bus->number];
if (phys_id < 0)
return -ENODEV;
box = uncore_alloc_box(type, 0);
if (!box)
return -ENOMEM;
for (i = 0; i < type->num_boxes; i++) {
pmu = &type->pmus[i];
if (pmu->func_id == pdev->devfn)
break;
if (pmu->func_id < 0) {
pmu->func_id = pdev->devfn;
break;
}
pmu = NULL;
}
if (!pmu) {
kfree(box);
return -EINVAL;
}
box->phys_id = phys_id;
box->pci_dev = pdev;
box->pmu = pmu;
uncore_box_init(box);
pci_set_drvdata(pdev, box);
raw_spin_lock(&uncore_box_lock);
list_add_tail(&box->list, &pmu->box_list);
raw_spin_unlock(&uncore_box_lock);
return 0;
}
static void uncore_pci_remove(struct pci_dev *pdev)
{
struct intel_uncore_box *box = pci_get_drvdata(pdev);
struct intel_uncore_pmu *pmu = box->pmu;
int cpu, phys_id = pcibus_to_physid[pdev->bus->number];
if (WARN_ON_ONCE(phys_id != box->phys_id))
return;
pci_set_drvdata(pdev, NULL);
raw_spin_lock(&uncore_box_lock);
list_del(&box->list);
raw_spin_unlock(&uncore_box_lock);
for_each_possible_cpu(cpu) {
if (*per_cpu_ptr(pmu->box, cpu) == box) {
*per_cpu_ptr(pmu->box, cpu) = NULL;
atomic_dec(&box->refcnt);
}
}
WARN_ON_ONCE(atomic_read(&box->refcnt) != 1);
kfree(box);
}
static int uncore_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
return uncore_pci_add(pci_uncores[id->driver_data], pdev);
}
static int __init uncore_pci_init(void)
{
int ret;
switch (boot_cpu_data.x86_model) {
case 45:
ret = snbep_pci2phy_map_init(0x3ce0);
if (ret)
return ret;
pci_uncores = snbep_pci_uncores;
uncore_pci_driver = &snbep_uncore_pci_driver;
break;
case 62:
ret = snbep_pci2phy_map_init(0x0e1e);
if (ret)
return ret;
pci_uncores = ivt_pci_uncores;
uncore_pci_driver = &ivt_uncore_pci_driver;
break;
default:
return 0;
}
ret = uncore_types_init(pci_uncores);
if (ret)
return ret;
uncore_pci_driver->probe = uncore_pci_probe;
uncore_pci_driver->remove = uncore_pci_remove;
ret = pci_register_driver(uncore_pci_driver);
if (ret == 0)
pcidrv_registered = true;
else
uncore_types_exit(pci_uncores);
return ret;
}
static void __init uncore_pci_exit(void)
{
if (pcidrv_registered) {
pcidrv_registered = false;
pci_unregister_driver(uncore_pci_driver);
uncore_types_exit(pci_uncores);
}
}
static void uncore_kfree_boxes(void)
{
struct intel_uncore_box *box;
while (!list_empty(&boxes_to_free)) {
box = list_entry(boxes_to_free.next,
struct intel_uncore_box, list);
list_del(&box->list);
kfree(box);
}
}
static void uncore_cpu_dying(int cpu)
{
struct intel_uncore_type *type;
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
int i, j;
for (i = 0; msr_uncores[i]; i++) {
type = msr_uncores[i];
for (j = 0; j < type->num_boxes; j++) {
pmu = &type->pmus[j];
box = *per_cpu_ptr(pmu->box, cpu);
*per_cpu_ptr(pmu->box, cpu) = NULL;
if (box && atomic_dec_and_test(&box->refcnt))
list_add(&box->list, &boxes_to_free);
}
}
}
static int uncore_cpu_starting(int cpu)
{
struct intel_uncore_type *type;
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box, *exist;
int i, j, k, phys_id;
phys_id = topology_physical_package_id(cpu);
for (i = 0; msr_uncores[i]; i++) {
type = msr_uncores[i];
for (j = 0; j < type->num_boxes; j++) {
pmu = &type->pmus[j];
box = *per_cpu_ptr(pmu->box, cpu);
if (box && box->phys_id >= 0) {
uncore_box_init(box);
continue;
}
for_each_online_cpu(k) {
exist = *per_cpu_ptr(pmu->box, k);
if (exist && exist->phys_id == phys_id) {
atomic_inc(&exist->refcnt);
*per_cpu_ptr(pmu->box, cpu) = exist;
if (box) {
list_add(&box->list,
&boxes_to_free);
box = NULL;
}
break;
}
}
if (box) {
box->phys_id = phys_id;
uncore_box_init(box);
}
}
}
return 0;
}
static int uncore_cpu_prepare(int cpu, int phys_id)
{
struct intel_uncore_type *type;
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
int i, j;
for (i = 0; msr_uncores[i]; i++) {
type = msr_uncores[i];
for (j = 0; j < type->num_boxes; j++) {
pmu = &type->pmus[j];
if (pmu->func_id < 0)
pmu->func_id = j;
box = uncore_alloc_box(type, cpu);
if (!box)
return -ENOMEM;
box->pmu = pmu;
box->phys_id = phys_id;
*per_cpu_ptr(pmu->box, cpu) = box;
}
}
return 0;
}
static void
uncore_change_context(struct intel_uncore_type **uncores, int old_cpu, int new_cpu)
{
struct intel_uncore_type *type;
struct intel_uncore_pmu *pmu;
struct intel_uncore_box *box;
int i, j;
for (i = 0; uncores[i]; i++) {
type = uncores[i];
for (j = 0; j < type->num_boxes; j++) {
pmu = &type->pmus[j];
if (old_cpu < 0)
box = uncore_pmu_to_box(pmu, new_cpu);
else
box = uncore_pmu_to_box(pmu, old_cpu);
if (!box)
continue;
if (old_cpu < 0) {
WARN_ON_ONCE(box->cpu != -1);
box->cpu = new_cpu;
continue;
}
WARN_ON_ONCE(box->cpu != old_cpu);
if (new_cpu >= 0) {
uncore_pmu_cancel_hrtimer(box);
perf_pmu_migrate_context(&pmu->pmu,
old_cpu, new_cpu);
box->cpu = new_cpu;
} else {
box->cpu = -1;
}
}
}
}
static void uncore_event_exit_cpu(int cpu)
{
int i, phys_id, target;
if (!cpumask_test_and_clear_cpu(cpu, &uncore_cpu_mask))
return;
phys_id = topology_physical_package_id(cpu);
target = -1;
for_each_online_cpu(i) {
if (i == cpu)
continue;
if (phys_id == topology_physical_package_id(i)) {
target = i;
break;
}
}
if (target >= 0)
cpumask_set_cpu(target, &uncore_cpu_mask);
uncore_change_context(msr_uncores, cpu, target);
uncore_change_context(pci_uncores, cpu, target);
}
static void uncore_event_init_cpu(int cpu)
{
int i, phys_id;
phys_id = topology_physical_package_id(cpu);
for_each_cpu(i, &uncore_cpu_mask) {
if (phys_id == topology_physical_package_id(i))
return;
}
cpumask_set_cpu(cpu, &uncore_cpu_mask);
uncore_change_context(msr_uncores, -1, cpu);
uncore_change_context(pci_uncores, -1, cpu);
}
static int uncore_cpu_notifier(struct notifier_block *self,
unsigned long action, void *hcpu)
{
unsigned int cpu = (long)hcpu;
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_UP_PREPARE:
uncore_cpu_prepare(cpu, -1);
break;
case CPU_STARTING:
uncore_cpu_starting(cpu);
break;
case CPU_UP_CANCELED:
case CPU_DYING:
uncore_cpu_dying(cpu);
break;
case CPU_ONLINE:
case CPU_DEAD:
uncore_kfree_boxes();
break;
default:
break;
}
switch (action & ~CPU_TASKS_FROZEN) {
case CPU_DOWN_FAILED:
case CPU_STARTING:
uncore_event_init_cpu(cpu);
break;
case CPU_DOWN_PREPARE:
uncore_event_exit_cpu(cpu);
break;
default:
break;
}
return NOTIFY_OK;
}
static void __init uncore_cpu_setup(void *dummy)
{
uncore_cpu_starting(smp_processor_id());
}
static int __init uncore_cpu_init(void)
{
int ret, cpu, max_cores;
max_cores = boot_cpu_data.x86_max_cores;
switch (boot_cpu_data.x86_model) {
case 26:
case 30:
case 37:
case 44:
msr_uncores = nhm_msr_uncores;
break;
case 42:
case 58:
if (snb_uncore_cbox.num_boxes > max_cores)
snb_uncore_cbox.num_boxes = max_cores;
msr_uncores = snb_msr_uncores;
break;
case 45:
if (snbep_uncore_cbox.num_boxes > max_cores)
snbep_uncore_cbox.num_boxes = max_cores;
msr_uncores = snbep_msr_uncores;
break;
case 46:
uncore_nhmex = true;
case 47:
if (!uncore_nhmex)
nhmex_uncore_mbox.event_descs = wsmex_uncore_mbox_events;
if (nhmex_uncore_cbox.num_boxes > max_cores)
nhmex_uncore_cbox.num_boxes = max_cores;
msr_uncores = nhmex_msr_uncores;
break;
case 62:
if (ivt_uncore_cbox.num_boxes > max_cores)
ivt_uncore_cbox.num_boxes = max_cores;
msr_uncores = ivt_msr_uncores;
break;
default:
return 0;
}
ret = uncore_types_init(msr_uncores);
if (ret)
return ret;
get_online_cpus();
for_each_online_cpu(cpu) {
int i, phys_id = topology_physical_package_id(cpu);
for_each_cpu(i, &uncore_cpu_mask) {
if (phys_id == topology_physical_package_id(i)) {
phys_id = -1;
break;
}
}
if (phys_id < 0)
continue;
uncore_cpu_prepare(cpu, phys_id);
uncore_event_init_cpu(cpu);
}
on_each_cpu(uncore_cpu_setup, NULL, 1);
register_cpu_notifier(&uncore_cpu_nb);
put_online_cpus();
return 0;
}
static int __init uncore_pmus_register(void)
{
struct intel_uncore_pmu *pmu;
struct intel_uncore_type *type;
int i, j;
for (i = 0; msr_uncores[i]; i++) {
type = msr_uncores[i];
for (j = 0; j < type->num_boxes; j++) {
pmu = &type->pmus[j];
uncore_pmu_register(pmu);
}
}
for (i = 0; pci_uncores[i]; i++) {
type = pci_uncores[i];
for (j = 0; j < type->num_boxes; j++) {
pmu = &type->pmus[j];
uncore_pmu_register(pmu);
}
}
return 0;
}
static int __init intel_uncore_init(void)
{
int ret;
if (boot_cpu_data.x86_vendor != X86_VENDOR_INTEL)
return -ENODEV;
if (cpu_has_hypervisor)
return -ENODEV;
ret = uncore_pci_init();
if (ret)
goto fail;
ret = uncore_cpu_init();
if (ret) {
uncore_pci_exit();
goto fail;
}
uncore_pmus_register();
return 0;
fail:
return ret;
}
