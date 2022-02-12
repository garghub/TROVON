static int policy_to_aspm_state(struct pcie_link_state *link)
{
switch (aspm_policy) {
case POLICY_PERFORMANCE:
return 0;
case POLICY_POWERSAVE:
return (ASPM_STATE_L0S | ASPM_STATE_L1);
case POLICY_POWER_SUPERSAVE:
return ASPM_STATE_ALL;
case POLICY_DEFAULT:
return link->aspm_default;
}
return 0;
}
static int policy_to_clkpm_state(struct pcie_link_state *link)
{
switch (aspm_policy) {
case POLICY_PERFORMANCE:
return 0;
case POLICY_POWERSAVE:
case POLICY_POWER_SUPERSAVE:
return 1;
case POLICY_DEFAULT:
return link->clkpm_default;
}
return 0;
}
static void pcie_set_clkpm_nocheck(struct pcie_link_state *link, int enable)
{
struct pci_dev *child;
struct pci_bus *linkbus = link->pdev->subordinate;
u32 val = enable ? PCI_EXP_LNKCTL_CLKREQ_EN : 0;
list_for_each_entry(child, &linkbus->devices, bus_list)
pcie_capability_clear_and_set_word(child, PCI_EXP_LNKCTL,
PCI_EXP_LNKCTL_CLKREQ_EN,
val);
link->clkpm_enabled = !!enable;
}
static void pcie_set_clkpm(struct pcie_link_state *link, int enable)
{
if (!link->clkpm_capable)
enable = 0;
if (link->clkpm_enabled == enable)
return;
pcie_set_clkpm_nocheck(link, enable);
}
static void pcie_clkpm_cap_init(struct pcie_link_state *link, int blacklist)
{
int capable = 1, enabled = 1;
u32 reg32;
u16 reg16;
struct pci_dev *child;
struct pci_bus *linkbus = link->pdev->subordinate;
list_for_each_entry(child, &linkbus->devices, bus_list) {
pcie_capability_read_dword(child, PCI_EXP_LNKCAP, &reg32);
if (!(reg32 & PCI_EXP_LNKCAP_CLKPM)) {
capable = 0;
enabled = 0;
break;
}
pcie_capability_read_word(child, PCI_EXP_LNKCTL, &reg16);
if (!(reg16 & PCI_EXP_LNKCTL_CLKREQ_EN))
enabled = 0;
}
link->clkpm_enabled = enabled;
link->clkpm_default = enabled;
link->clkpm_capable = (blacklist) ? 0 : capable;
}
static void pcie_aspm_configure_common_clock(struct pcie_link_state *link)
{
int same_clock = 1;
u16 reg16, parent_reg, child_reg[8];
unsigned long start_jiffies;
struct pci_dev *child, *parent = link->pdev;
struct pci_bus *linkbus = parent->subordinate;
child = list_entry(linkbus->devices.next, struct pci_dev, bus_list);
BUG_ON(!pci_is_pcie(child));
pcie_capability_read_word(child, PCI_EXP_LNKSTA, &reg16);
if (!(reg16 & PCI_EXP_LNKSTA_SLC))
same_clock = 0;
pcie_capability_read_word(parent, PCI_EXP_LNKSTA, &reg16);
if (!(reg16 & PCI_EXP_LNKSTA_SLC))
same_clock = 0;
list_for_each_entry(child, &linkbus->devices, bus_list) {
pcie_capability_read_word(child, PCI_EXP_LNKCTL, &reg16);
child_reg[PCI_FUNC(child->devfn)] = reg16;
if (same_clock)
reg16 |= PCI_EXP_LNKCTL_CCC;
else
reg16 &= ~PCI_EXP_LNKCTL_CCC;
pcie_capability_write_word(child, PCI_EXP_LNKCTL, reg16);
}
pcie_capability_read_word(parent, PCI_EXP_LNKCTL, &reg16);
parent_reg = reg16;
if (same_clock)
reg16 |= PCI_EXP_LNKCTL_CCC;
else
reg16 &= ~PCI_EXP_LNKCTL_CCC;
pcie_capability_write_word(parent, PCI_EXP_LNKCTL, reg16);
reg16 |= PCI_EXP_LNKCTL_RL;
pcie_capability_write_word(parent, PCI_EXP_LNKCTL, reg16);
start_jiffies = jiffies;
for (;;) {
pcie_capability_read_word(parent, PCI_EXP_LNKSTA, &reg16);
if (!(reg16 & PCI_EXP_LNKSTA_LT))
break;
if (time_after(jiffies, start_jiffies + LINK_RETRAIN_TIMEOUT))
break;
msleep(1);
}
if (!(reg16 & PCI_EXP_LNKSTA_LT))
return;
dev_err(&parent->dev, "ASPM: Could not configure common clock\n");
list_for_each_entry(child, &linkbus->devices, bus_list)
pcie_capability_write_word(child, PCI_EXP_LNKCTL,
child_reg[PCI_FUNC(child->devfn)]);
pcie_capability_write_word(parent, PCI_EXP_LNKCTL, parent_reg);
}
static u32 calc_l0s_latency(u32 encoding)
{
if (encoding == 0x7)
return (5 * 1000);
return (64 << encoding);
}
static u32 calc_l0s_acceptable(u32 encoding)
{
if (encoding == 0x7)
return -1U;
return (64 << encoding);
}
static u32 calc_l1_latency(u32 encoding)
{
if (encoding == 0x7)
return (65 * 1000);
return (1000 << encoding);
}
static u32 calc_l1_acceptable(u32 encoding)
{
if (encoding == 0x7)
return -1U;
return (1000 << encoding);
}
static u32 calc_l1ss_pwron(struct pci_dev *pdev, u32 scale, u32 val)
{
switch (scale) {
case 0:
return val * 2;
case 1:
return val * 10;
case 2:
return val * 100;
}
dev_err(&pdev->dev, "%s: Invalid T_PwrOn scale: %u\n",
__func__, scale);
return 0;
}
static void pcie_get_aspm_reg(struct pci_dev *pdev,
struct aspm_register_info *info)
{
u16 reg16;
u32 reg32;
pcie_capability_read_dword(pdev, PCI_EXP_LNKCAP, &reg32);
info->support = (reg32 & PCI_EXP_LNKCAP_ASPMS) >> 10;
info->latency_encoding_l0s = (reg32 & PCI_EXP_LNKCAP_L0SEL) >> 12;
info->latency_encoding_l1 = (reg32 & PCI_EXP_LNKCAP_L1EL) >> 15;
pcie_capability_read_word(pdev, PCI_EXP_LNKCTL, &reg16);
info->enabled = reg16 & PCI_EXP_LNKCTL_ASPMC;
info->l1ss_cap = info->l1ss_ctl1 = info->l1ss_ctl2 = 0;
info->l1ss_cap_ptr = pci_find_ext_capability(pdev, PCI_EXT_CAP_ID_L1SS);
if (!info->l1ss_cap_ptr)
return;
pci_read_config_dword(pdev, info->l1ss_cap_ptr + PCI_L1SS_CAP,
&info->l1ss_cap);
if (!(info->l1ss_cap & PCI_L1SS_CAP_L1_PM_SS)) {
info->l1ss_cap = 0;
return;
}
pci_read_config_dword(pdev, info->l1ss_cap_ptr + PCI_L1SS_CTL1,
&info->l1ss_ctl1);
pci_read_config_dword(pdev, info->l1ss_cap_ptr + PCI_L1SS_CTL2,
&info->l1ss_ctl2);
}
static void pcie_aspm_check_latency(struct pci_dev *endpoint)
{
u32 latency, l1_switch_latency = 0;
struct aspm_latency *acceptable;
struct pcie_link_state *link;
if ((endpoint->current_state != PCI_D0) &&
(endpoint->current_state != PCI_UNKNOWN))
return;
link = endpoint->bus->self->link_state;
acceptable = &link->acceptable[PCI_FUNC(endpoint->devfn)];
while (link) {
if ((link->aspm_capable & ASPM_STATE_L0S_UP) &&
(link->latency_up.l0s > acceptable->l0s))
link->aspm_capable &= ~ASPM_STATE_L0S_UP;
if ((link->aspm_capable & ASPM_STATE_L0S_DW) &&
(link->latency_dw.l0s > acceptable->l0s))
link->aspm_capable &= ~ASPM_STATE_L0S_DW;
latency = max_t(u32, link->latency_up.l1, link->latency_dw.l1);
if ((link->aspm_capable & ASPM_STATE_L1) &&
(latency + l1_switch_latency > acceptable->l1))
link->aspm_capable &= ~ASPM_STATE_L1;
l1_switch_latency += 1000;
link = link->parent;
}
}
static struct pci_dev *pci_function_0(struct pci_bus *linkbus)
{
struct pci_dev *child;
list_for_each_entry(child, &linkbus->devices, bus_list)
if (PCI_FUNC(child->devfn) == 0)
return child;
return NULL;
}
static void aspm_calc_l1ss_info(struct pcie_link_state *link,
struct aspm_register_info *upreg,
struct aspm_register_info *dwreg)
{
u32 val1, val2, scale1, scale2;
link->l1ss.up_cap_ptr = upreg->l1ss_cap_ptr;
link->l1ss.dw_cap_ptr = dwreg->l1ss_cap_ptr;
link->l1ss.ctl1 = link->l1ss.ctl2 = 0;
if (!(link->aspm_support & ASPM_STATE_L1_2_MASK))
return;
val1 = (upreg->l1ss_cap >> 8) & 0xFF;
val2 = (upreg->l1ss_cap >> 8) & 0xFF;
if (val1 > val2)
link->l1ss.ctl1 |= val1 << 8;
else
link->l1ss.ctl1 |= val2 << 8;
link->l1ss.ctl1 |= LTR_L1_2_THRESHOLD_BITS;
val1 = (upreg->l1ss_cap >> 19) & 0x1F;
scale1 = (upreg->l1ss_cap >> 16) & 0x03;
val2 = (dwreg->l1ss_cap >> 19) & 0x1F;
scale2 = (dwreg->l1ss_cap >> 16) & 0x03;
if (calc_l1ss_pwron(link->pdev, scale1, val1) >
calc_l1ss_pwron(link->downstream, scale2, val2))
link->l1ss.ctl2 |= scale1 | (val1 << 3);
else
link->l1ss.ctl2 |= scale2 | (val2 << 3);
}
static void pcie_aspm_cap_init(struct pcie_link_state *link, int blacklist)
{
struct pci_dev *child = link->downstream, *parent = link->pdev;
struct pci_bus *linkbus = parent->subordinate;
struct aspm_register_info upreg, dwreg;
if (blacklist) {
link->aspm_enabled = ASPM_STATE_ALL;
link->aspm_disable = ASPM_STATE_ALL;
return;
}
pcie_get_aspm_reg(parent, &upreg);
pcie_get_aspm_reg(child, &dwreg);
if (!(upreg.support & dwreg.support))
return;
pcie_aspm_configure_common_clock(link);
pcie_get_aspm_reg(parent, &upreg);
pcie_get_aspm_reg(child, &dwreg);
if (dwreg.support & upreg.support & PCIE_LINK_STATE_L0S)
link->aspm_support |= ASPM_STATE_L0S;
if (dwreg.enabled & PCIE_LINK_STATE_L0S)
link->aspm_enabled |= ASPM_STATE_L0S_UP;
if (upreg.enabled & PCIE_LINK_STATE_L0S)
link->aspm_enabled |= ASPM_STATE_L0S_DW;
link->latency_up.l0s = calc_l0s_latency(upreg.latency_encoding_l0s);
link->latency_dw.l0s = calc_l0s_latency(dwreg.latency_encoding_l0s);
if (upreg.support & dwreg.support & PCIE_LINK_STATE_L1)
link->aspm_support |= ASPM_STATE_L1;
if (upreg.enabled & dwreg.enabled & PCIE_LINK_STATE_L1)
link->aspm_enabled |= ASPM_STATE_L1;
link->latency_up.l1 = calc_l1_latency(upreg.latency_encoding_l1);
link->latency_dw.l1 = calc_l1_latency(dwreg.latency_encoding_l1);
if (upreg.l1ss_cap & dwreg.l1ss_cap & PCI_L1SS_CAP_ASPM_L1_1)
link->aspm_support |= ASPM_STATE_L1_1;
if (upreg.l1ss_cap & dwreg.l1ss_cap & PCI_L1SS_CAP_ASPM_L1_2)
link->aspm_support |= ASPM_STATE_L1_2;
if (upreg.l1ss_cap & dwreg.l1ss_cap & PCI_L1SS_CAP_PCIPM_L1_1)
link->aspm_support |= ASPM_STATE_L1_1_PCIPM;
if (upreg.l1ss_cap & dwreg.l1ss_cap & PCI_L1SS_CAP_PCIPM_L1_2)
link->aspm_support |= ASPM_STATE_L1_2_PCIPM;
if (upreg.l1ss_ctl1 & dwreg.l1ss_ctl1 & PCI_L1SS_CTL1_ASPM_L1_1)
link->aspm_enabled |= ASPM_STATE_L1_1;
if (upreg.l1ss_ctl1 & dwreg.l1ss_ctl1 & PCI_L1SS_CTL1_ASPM_L1_2)
link->aspm_enabled |= ASPM_STATE_L1_2;
if (upreg.l1ss_ctl1 & dwreg.l1ss_ctl1 & PCI_L1SS_CTL1_PCIPM_L1_1)
link->aspm_enabled |= ASPM_STATE_L1_1_PCIPM;
if (upreg.l1ss_ctl1 & dwreg.l1ss_ctl1 & PCI_L1SS_CTL1_PCIPM_L1_2)
link->aspm_enabled |= ASPM_STATE_L1_2_PCIPM;
if (link->aspm_support & ASPM_STATE_L1SS)
aspm_calc_l1ss_info(link, &upreg, &dwreg);
link->aspm_default = link->aspm_enabled;
link->aspm_capable = link->aspm_support;
list_for_each_entry(child, &linkbus->devices, bus_list) {
if (pci_pcie_type(child) == PCI_EXP_TYPE_PCI_BRIDGE) {
link->aspm_disable = ASPM_STATE_ALL;
break;
}
}
list_for_each_entry(child, &linkbus->devices, bus_list) {
u32 reg32, encoding;
struct aspm_latency *acceptable =
&link->acceptable[PCI_FUNC(child->devfn)];
if (pci_pcie_type(child) != PCI_EXP_TYPE_ENDPOINT &&
pci_pcie_type(child) != PCI_EXP_TYPE_LEG_END)
continue;
pcie_capability_read_dword(child, PCI_EXP_DEVCAP, &reg32);
encoding = (reg32 & PCI_EXP_DEVCAP_L0S) >> 6;
acceptable->l0s = calc_l0s_acceptable(encoding);
encoding = (reg32 & PCI_EXP_DEVCAP_L1) >> 9;
acceptable->l1 = calc_l1_acceptable(encoding);
pcie_aspm_check_latency(child);
}
}
static void pci_clear_and_set_dword(struct pci_dev *pdev, int pos,
u32 clear, u32 set)
{
u32 val;
pci_read_config_dword(pdev, pos, &val);
val &= ~clear;
val |= set;
pci_write_config_dword(pdev, pos, val);
}
static void pcie_config_aspm_l1ss(struct pcie_link_state *link, u32 state)
{
u32 val, enable_req;
struct pci_dev *child = link->downstream, *parent = link->pdev;
u32 up_cap_ptr = link->l1ss.up_cap_ptr;
u32 dw_cap_ptr = link->l1ss.dw_cap_ptr;
enable_req = (link->aspm_enabled ^ state) & state;
pci_clear_and_set_dword(child, dw_cap_ptr + PCI_L1SS_CTL1,
PCI_L1SS_CTL1_L1SS_MASK, 0);
pci_clear_and_set_dword(parent, up_cap_ptr + PCI_L1SS_CTL1,
PCI_L1SS_CTL1_L1SS_MASK, 0);
if (enable_req & (ASPM_STATE_L1_1 | ASPM_STATE_L1_2)) {
pcie_capability_clear_and_set_word(child, PCI_EXP_LNKCTL,
PCI_EXP_LNKCTL_ASPM_L1, 0);
pcie_capability_clear_and_set_word(parent, PCI_EXP_LNKCTL,
PCI_EXP_LNKCTL_ASPM_L1, 0);
}
if (enable_req & ASPM_STATE_L1_2_MASK) {
pci_write_config_dword(parent, up_cap_ptr + PCI_L1SS_CTL2,
link->l1ss.ctl2);
pci_write_config_dword(child, dw_cap_ptr + PCI_L1SS_CTL2,
link->l1ss.ctl2);
pci_clear_and_set_dword(parent, up_cap_ptr + PCI_L1SS_CTL1,
0xFF00, link->l1ss.ctl1);
pci_clear_and_set_dword(parent, dw_cap_ptr + PCI_L1SS_CTL1,
0xE3FF0000, link->l1ss.ctl1);
pci_clear_and_set_dword(child, dw_cap_ptr + PCI_L1SS_CTL1,
0xE3FF0000, link->l1ss.ctl1);
}
val = 0;
if (state & ASPM_STATE_L1_1)
val |= PCI_L1SS_CTL1_ASPM_L1_1;
if (state & ASPM_STATE_L1_2)
val |= PCI_L1SS_CTL1_ASPM_L1_2;
if (state & ASPM_STATE_L1_1_PCIPM)
val |= PCI_L1SS_CTL1_PCIPM_L1_1;
if (state & ASPM_STATE_L1_2_PCIPM)
val |= PCI_L1SS_CTL1_PCIPM_L1_2;
pci_clear_and_set_dword(parent, up_cap_ptr + PCI_L1SS_CTL1,
PCI_L1SS_CAP_L1_PM_SS, val);
pci_clear_and_set_dword(child, dw_cap_ptr + PCI_L1SS_CTL1,
PCI_L1SS_CAP_L1_PM_SS, val);
}
static void pcie_config_aspm_dev(struct pci_dev *pdev, u32 val)
{
pcie_capability_clear_and_set_word(pdev, PCI_EXP_LNKCTL,
PCI_EXP_LNKCTL_ASPMC, val);
}
static void pcie_config_aspm_link(struct pcie_link_state *link, u32 state)
{
u32 upstream = 0, dwstream = 0;
struct pci_dev *child = link->downstream, *parent = link->pdev;
struct pci_bus *linkbus = parent->subordinate;
state &= (link->aspm_capable & ~link->aspm_disable);
if (!(state & ASPM_STATE_L1))
state &= ~ASPM_STATE_L1SS;
if (parent->current_state != PCI_D0 || child->current_state != PCI_D0) {
state &= ~ASPM_STATE_L1_SS_PCIPM;
state |= (link->aspm_enabled & ASPM_STATE_L1_SS_PCIPM);
}
if (link->aspm_enabled == state)
return;
if (state & ASPM_STATE_L0S_UP)
dwstream |= PCI_EXP_LNKCTL_ASPM_L0S;
if (state & ASPM_STATE_L0S_DW)
upstream |= PCI_EXP_LNKCTL_ASPM_L0S;
if (state & ASPM_STATE_L1) {
upstream |= PCI_EXP_LNKCTL_ASPM_L1;
dwstream |= PCI_EXP_LNKCTL_ASPM_L1;
}
if (link->aspm_capable & ASPM_STATE_L1SS)
pcie_config_aspm_l1ss(link, state);
if (state & ASPM_STATE_L1)
pcie_config_aspm_dev(parent, upstream);
list_for_each_entry(child, &linkbus->devices, bus_list)
pcie_config_aspm_dev(child, dwstream);
if (!(state & ASPM_STATE_L1))
pcie_config_aspm_dev(parent, upstream);
link->aspm_enabled = state;
}
static void pcie_config_aspm_path(struct pcie_link_state *link)
{
while (link) {
pcie_config_aspm_link(link, policy_to_aspm_state(link));
link = link->parent;
}
}
static void free_link_state(struct pcie_link_state *link)
{
link->pdev->link_state = NULL;
kfree(link);
}
static int pcie_aspm_sanity_check(struct pci_dev *pdev)
{
struct pci_dev *child;
u32 reg32;
list_for_each_entry(child, &pdev->subordinate->devices, bus_list) {
if (!pci_is_pcie(child))
return -EINVAL;
if (aspm_disabled)
continue;
pcie_capability_read_dword(child, PCI_EXP_DEVCAP, &reg32);
if (!(reg32 & PCI_EXP_DEVCAP_RBER) && !aspm_force) {
dev_info(&child->dev, "disabling ASPM on pre-1.1 PCIe device. You can enable it with 'pcie_aspm=force'\n");
return -EINVAL;
}
}
return 0;
}
static struct pcie_link_state *alloc_pcie_link_state(struct pci_dev *pdev)
{
struct pcie_link_state *link;
link = kzalloc(sizeof(*link), GFP_KERNEL);
if (!link)
return NULL;
INIT_LIST_HEAD(&link->sibling);
INIT_LIST_HEAD(&link->children);
INIT_LIST_HEAD(&link->link);
link->pdev = pdev;
link->downstream = pci_function_0(pdev->subordinate);
if (pci_pcie_type(pdev) == PCI_EXP_TYPE_ROOT_PORT ||
pci_pcie_type(pdev) == PCI_EXP_TYPE_PCIE_BRIDGE) {
link->root = link;
} else {
struct pcie_link_state *parent;
parent = pdev->bus->parent->self->link_state;
if (!parent) {
kfree(link);
return NULL;
}
link->parent = parent;
link->root = link->parent->root;
list_add(&link->link, &parent->children);
}
list_add(&link->sibling, &link_list);
pdev->link_state = link;
return link;
}
void pcie_aspm_init_link_state(struct pci_dev *pdev)
{
struct pcie_link_state *link;
int blacklist = !!pcie_aspm_sanity_check(pdev);
if (!aspm_support_enabled)
return;
if (pdev->link_state)
return;
if (!pdev->has_secondary_link)
return;
if (pci_pcie_type(pdev) == PCI_EXP_TYPE_ROOT_PORT &&
pdev->bus->self)
return;
down_read(&pci_bus_sem);
if (list_empty(&pdev->subordinate->devices))
goto out;
mutex_lock(&aspm_lock);
link = alloc_pcie_link_state(pdev);
if (!link)
goto unlock;
pcie_aspm_cap_init(link, blacklist);
pcie_clkpm_cap_init(link, blacklist);
if (aspm_policy != POLICY_POWERSAVE &&
aspm_policy != POLICY_POWER_SUPERSAVE) {
pcie_config_aspm_path(link);
pcie_set_clkpm(link, policy_to_clkpm_state(link));
}
unlock:
mutex_unlock(&aspm_lock);
out:
up_read(&pci_bus_sem);
}
static void pcie_update_aspm_capable(struct pcie_link_state *root)
{
struct pcie_link_state *link;
BUG_ON(root->parent);
list_for_each_entry(link, &link_list, sibling) {
if (link->root != root)
continue;
link->aspm_capable = link->aspm_support;
}
list_for_each_entry(link, &link_list, sibling) {
struct pci_dev *child;
struct pci_bus *linkbus = link->pdev->subordinate;
if (link->root != root)
continue;
list_for_each_entry(child, &linkbus->devices, bus_list) {
if ((pci_pcie_type(child) != PCI_EXP_TYPE_ENDPOINT) &&
(pci_pcie_type(child) != PCI_EXP_TYPE_LEG_END))
continue;
pcie_aspm_check_latency(child);
}
}
}
void pcie_aspm_exit_link_state(struct pci_dev *pdev)
{
struct pci_dev *parent = pdev->bus->self;
struct pcie_link_state *link, *root, *parent_link;
if (!parent || !parent->link_state)
return;
down_read(&pci_bus_sem);
mutex_lock(&aspm_lock);
if (!list_is_last(&pdev->bus_list, &parent->subordinate->devices))
goto out;
link = parent->link_state;
root = link->root;
parent_link = link->parent;
pcie_config_aspm_link(link, 0);
list_del(&link->sibling);
list_del(&link->link);
free_link_state(link);
if (parent_link) {
pcie_update_aspm_capable(root);
pcie_config_aspm_path(parent_link);
}
out:
mutex_unlock(&aspm_lock);
up_read(&pci_bus_sem);
}
void pcie_aspm_pm_state_change(struct pci_dev *pdev)
{
struct pcie_link_state *link = pdev->link_state;
if (aspm_disabled || !link)
return;
down_read(&pci_bus_sem);
mutex_lock(&aspm_lock);
pcie_update_aspm_capable(link->root);
pcie_config_aspm_path(link);
mutex_unlock(&aspm_lock);
up_read(&pci_bus_sem);
}
void pcie_aspm_powersave_config_link(struct pci_dev *pdev)
{
struct pcie_link_state *link = pdev->link_state;
if (aspm_disabled || !link)
return;
if (aspm_policy != POLICY_POWERSAVE &&
aspm_policy != POLICY_POWER_SUPERSAVE)
return;
down_read(&pci_bus_sem);
mutex_lock(&aspm_lock);
pcie_config_aspm_path(link);
pcie_set_clkpm(link, policy_to_clkpm_state(link));
mutex_unlock(&aspm_lock);
up_read(&pci_bus_sem);
}
static void __pci_disable_link_state(struct pci_dev *pdev, int state, bool sem)
{
struct pci_dev *parent = pdev->bus->self;
struct pcie_link_state *link;
if (!pci_is_pcie(pdev))
return;
if (pdev->has_secondary_link)
parent = pdev;
if (!parent || !parent->link_state)
return;
if (aspm_disabled) {
dev_warn(&pdev->dev, "can't disable ASPM; OS doesn't have ASPM control\n");
return;
}
if (sem)
down_read(&pci_bus_sem);
mutex_lock(&aspm_lock);
link = parent->link_state;
if (state & PCIE_LINK_STATE_L0S)
link->aspm_disable |= ASPM_STATE_L0S;
if (state & PCIE_LINK_STATE_L1)
link->aspm_disable |= ASPM_STATE_L1;
pcie_config_aspm_link(link, policy_to_aspm_state(link));
if (state & PCIE_LINK_STATE_CLKPM) {
link->clkpm_capable = 0;
pcie_set_clkpm(link, 0);
}
mutex_unlock(&aspm_lock);
if (sem)
up_read(&pci_bus_sem);
}
void pci_disable_link_state_locked(struct pci_dev *pdev, int state)
{
__pci_disable_link_state(pdev, state, false);
}
void pci_disable_link_state(struct pci_dev *pdev, int state)
{
__pci_disable_link_state(pdev, state, true);
}
static int pcie_aspm_set_policy(const char *val, struct kernel_param *kp)
{
int i;
struct pcie_link_state *link;
if (aspm_disabled)
return -EPERM;
for (i = 0; i < ARRAY_SIZE(policy_str); i++)
if (!strncmp(val, policy_str[i], strlen(policy_str[i])))
break;
if (i >= ARRAY_SIZE(policy_str))
return -EINVAL;
if (i == aspm_policy)
return 0;
down_read(&pci_bus_sem);
mutex_lock(&aspm_lock);
aspm_policy = i;
list_for_each_entry(link, &link_list, sibling) {
pcie_config_aspm_link(link, policy_to_aspm_state(link));
pcie_set_clkpm(link, policy_to_clkpm_state(link));
}
mutex_unlock(&aspm_lock);
up_read(&pci_bus_sem);
return 0;
}
static int pcie_aspm_get_policy(char *buffer, struct kernel_param *kp)
{
int i, cnt = 0;
for (i = 0; i < ARRAY_SIZE(policy_str); i++)
if (i == aspm_policy)
cnt += sprintf(buffer + cnt, "[%s] ", policy_str[i]);
else
cnt += sprintf(buffer + cnt, "%s ", policy_str[i]);
return cnt;
}
static ssize_t link_state_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct pci_dev *pci_device = to_pci_dev(dev);
struct pcie_link_state *link_state = pci_device->link_state;
return sprintf(buf, "%d\n", link_state->aspm_enabled);
}
static ssize_t link_state_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t n)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct pcie_link_state *link, *root = pdev->link_state->root;
u32 state;
if (aspm_disabled)
return -EPERM;
if (kstrtouint(buf, 10, &state))
return -EINVAL;
if ((state & ~ASPM_STATE_ALL) != 0)
return -EINVAL;
down_read(&pci_bus_sem);
mutex_lock(&aspm_lock);
list_for_each_entry(link, &link_list, sibling) {
if (link->root != root)
continue;
pcie_config_aspm_link(link, state);
}
mutex_unlock(&aspm_lock);
up_read(&pci_bus_sem);
return n;
}
static ssize_t clk_ctl_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct pci_dev *pci_device = to_pci_dev(dev);
struct pcie_link_state *link_state = pci_device->link_state;
return sprintf(buf, "%d\n", link_state->clkpm_enabled);
}
static ssize_t clk_ctl_store(struct device *dev,
struct device_attribute *attr,
const char *buf,
size_t n)
{
struct pci_dev *pdev = to_pci_dev(dev);
bool state;
if (strtobool(buf, &state))
return -EINVAL;
down_read(&pci_bus_sem);
mutex_lock(&aspm_lock);
pcie_set_clkpm_nocheck(pdev->link_state, state);
mutex_unlock(&aspm_lock);
up_read(&pci_bus_sem);
return n;
}
void pcie_aspm_create_sysfs_dev_files(struct pci_dev *pdev)
{
struct pcie_link_state *link_state = pdev->link_state;
if (!link_state)
return;
if (link_state->aspm_support)
sysfs_add_file_to_group(&pdev->dev.kobj,
&dev_attr_link_state.attr, power_group);
if (link_state->clkpm_capable)
sysfs_add_file_to_group(&pdev->dev.kobj,
&dev_attr_clk_ctl.attr, power_group);
}
void pcie_aspm_remove_sysfs_dev_files(struct pci_dev *pdev)
{
struct pcie_link_state *link_state = pdev->link_state;
if (!link_state)
return;
if (link_state->aspm_support)
sysfs_remove_file_from_group(&pdev->dev.kobj,
&dev_attr_link_state.attr, power_group);
if (link_state->clkpm_capable)
sysfs_remove_file_from_group(&pdev->dev.kobj,
&dev_attr_clk_ctl.attr, power_group);
}
static int __init pcie_aspm_disable(char *str)
{
if (!strcmp(str, "off")) {
aspm_policy = POLICY_DEFAULT;
aspm_disabled = 1;
aspm_support_enabled = false;
printk(KERN_INFO "PCIe ASPM is disabled\n");
} else if (!strcmp(str, "force")) {
aspm_force = 1;
printk(KERN_INFO "PCIe ASPM is forcibly enabled\n");
}
return 1;
}
void pcie_no_aspm(void)
{
if (!aspm_force) {
aspm_policy = POLICY_DEFAULT;
aspm_disabled = 1;
}
}
bool pcie_aspm_support_enabled(void)
{
return aspm_support_enabled;
}
