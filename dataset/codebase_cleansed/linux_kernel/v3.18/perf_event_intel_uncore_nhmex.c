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
return &uncore_constraint_empty;
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
}
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
idx ^= 1;
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
return &uncore_constraint_empty;
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
}
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
}
wrmsrl(hwc->config_base, NHMEX_PMON_CTL_EN_BIT0 |
(hwc->config & NHMEX_R_PMON_CTL_EV_SEL_MASK));
}
void nhmex_uncore_cpu_init(void)
{
if (boot_cpu_data.x86_model == 46)
uncore_nhmex = true;
else
nhmex_uncore_mbox.event_descs = wsmex_uncore_mbox_events;
if (nhmex_uncore_cbox.num_boxes > boot_cpu_data.x86_max_cores)
nhmex_uncore_cbox.num_boxes = boot_cpu_data.x86_max_cores;
uncore_msr_uncores = nhmex_msr_uncores;
}
