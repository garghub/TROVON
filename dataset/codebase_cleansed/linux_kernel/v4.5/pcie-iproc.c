static inline struct iproc_pcie *iproc_data(struct pci_bus *bus)
{
struct iproc_pcie *pcie;
#ifdef CONFIG_ARM
struct pci_sys_data *sys = bus->sysdata;
pcie = sys->private_data;
#else
pcie = bus->sysdata;
#endif
return pcie;
}
static inline bool iproc_pcie_reg_is_invalid(u16 reg_offset)
{
return !!(reg_offset == IPROC_PCIE_REG_INVALID);
}
static inline u16 iproc_pcie_reg_offset(struct iproc_pcie *pcie,
enum iproc_pcie_reg reg)
{
return pcie->reg_offsets[reg];
}
static inline u32 iproc_pcie_read_reg(struct iproc_pcie *pcie,
enum iproc_pcie_reg reg)
{
u16 offset = iproc_pcie_reg_offset(pcie, reg);
if (iproc_pcie_reg_is_invalid(offset))
return 0;
return readl(pcie->base + offset);
}
static inline void iproc_pcie_write_reg(struct iproc_pcie *pcie,
enum iproc_pcie_reg reg, u32 val)
{
u16 offset = iproc_pcie_reg_offset(pcie, reg);
if (iproc_pcie_reg_is_invalid(offset))
return;
writel(val, pcie->base + offset);
}
static inline void iproc_pcie_ob_write(struct iproc_pcie *pcie,
enum iproc_pcie_reg reg,
unsigned window, u32 val)
{
u16 offset = iproc_pcie_reg_offset(pcie, reg);
if (iproc_pcie_reg_is_invalid(offset))
return;
writel(val, pcie->base + offset + (window * 8));
}
static void __iomem *iproc_pcie_map_cfg_bus(struct pci_bus *bus,
unsigned int devfn,
int where)
{
struct iproc_pcie *pcie = iproc_data(bus);
unsigned slot = PCI_SLOT(devfn);
unsigned fn = PCI_FUNC(devfn);
unsigned busno = bus->number;
u32 val;
u16 offset;
if (busno == 0) {
if (slot > 0 || fn > 0)
return NULL;
iproc_pcie_write_reg(pcie, IPROC_PCIE_CFG_IND_ADDR,
where & CFG_IND_ADDR_MASK);
offset = iproc_pcie_reg_offset(pcie, IPROC_PCIE_CFG_IND_DATA);
if (iproc_pcie_reg_is_invalid(offset))
return NULL;
else
return (pcie->base + offset);
}
if (pcie->type == IPROC_PCIE_PAXC)
if (slot > 0)
return NULL;
val = (busno << CFG_ADDR_BUS_NUM_SHIFT) |
(slot << CFG_ADDR_DEV_NUM_SHIFT) |
(fn << CFG_ADDR_FUNC_NUM_SHIFT) |
(where & CFG_ADDR_REG_NUM_MASK) |
(1 & CFG_ADDR_CFG_TYPE_MASK);
iproc_pcie_write_reg(pcie, IPROC_PCIE_CFG_ADDR, val);
offset = iproc_pcie_reg_offset(pcie, IPROC_PCIE_CFG_DATA);
if (iproc_pcie_reg_is_invalid(offset))
return NULL;
else
return (pcie->base + offset);
}
static void iproc_pcie_reset(struct iproc_pcie *pcie)
{
u32 val;
if (pcie->type == IPROC_PCIE_PAXC) {
val = iproc_pcie_read_reg(pcie, IPROC_PCIE_CLK_CTRL);
val &= ~PAXC_RESET_MASK;
iproc_pcie_write_reg(pcie, IPROC_PCIE_CLK_CTRL, val);
udelay(100);
val |= PAXC_RESET_MASK;
iproc_pcie_write_reg(pcie, IPROC_PCIE_CLK_CTRL, val);
udelay(100);
return;
}
val = iproc_pcie_read_reg(pcie, IPROC_PCIE_CLK_CTRL);
val &= ~EP_PERST_SOURCE_SELECT & ~EP_MODE_SURVIVE_PERST &
~RC_PCIE_RST_OUTPUT;
iproc_pcie_write_reg(pcie, IPROC_PCIE_CLK_CTRL, val);
udelay(250);
val |= RC_PCIE_RST_OUTPUT;
iproc_pcie_write_reg(pcie, IPROC_PCIE_CLK_CTRL, val);
msleep(100);
}
static int iproc_pcie_check_link(struct iproc_pcie *pcie, struct pci_bus *bus)
{
u8 hdr_type;
u32 link_ctrl, class, val;
u16 pos, link_status;
bool link_is_active = false;
if (pcie->type == IPROC_PCIE_PAXC)
return 0;
val = iproc_pcie_read_reg(pcie, IPROC_PCIE_LINK_STATUS);
if (!(val & PCIE_PHYLINKUP) || !(val & PCIE_DL_ACTIVE)) {
dev_err(pcie->dev, "PHY or data link is INACTIVE!\n");
return -ENODEV;
}
pci_bus_read_config_byte(bus, 0, PCI_HEADER_TYPE, &hdr_type);
if ((hdr_type & 0x7f) != PCI_HEADER_TYPE_BRIDGE) {
dev_err(pcie->dev, "in EP mode, hdr=%#02x\n", hdr_type);
return -EFAULT;
}
#define PCI_BRIDGE_CTRL_REG_OFFSET 0x43c
#define PCI_CLASS_BRIDGE_MASK 0xffff00
#define PCI_CLASS_BRIDGE_SHIFT 8
pci_bus_read_config_dword(bus, 0, PCI_BRIDGE_CTRL_REG_OFFSET, &class);
class &= ~PCI_CLASS_BRIDGE_MASK;
class |= (PCI_CLASS_BRIDGE_PCI << PCI_CLASS_BRIDGE_SHIFT);
pci_bus_write_config_dword(bus, 0, PCI_BRIDGE_CTRL_REG_OFFSET, class);
pos = pci_bus_find_capability(bus, 0, PCI_CAP_ID_EXP);
pci_bus_read_config_word(bus, 0, pos + PCI_EXP_LNKSTA, &link_status);
if (link_status & PCI_EXP_LNKSTA_NLW)
link_is_active = true;
if (!link_is_active) {
#define PCI_LINK_STATUS_CTRL_2_OFFSET 0x0dc
#define PCI_TARGET_LINK_SPEED_MASK 0xf
#define PCI_TARGET_LINK_SPEED_GEN2 0x2
#define PCI_TARGET_LINK_SPEED_GEN1 0x1
pci_bus_read_config_dword(bus, 0,
PCI_LINK_STATUS_CTRL_2_OFFSET,
&link_ctrl);
if ((link_ctrl & PCI_TARGET_LINK_SPEED_MASK) ==
PCI_TARGET_LINK_SPEED_GEN2) {
link_ctrl &= ~PCI_TARGET_LINK_SPEED_MASK;
link_ctrl |= PCI_TARGET_LINK_SPEED_GEN1;
pci_bus_write_config_dword(bus, 0,
PCI_LINK_STATUS_CTRL_2_OFFSET,
link_ctrl);
msleep(100);
pos = pci_bus_find_capability(bus, 0, PCI_CAP_ID_EXP);
pci_bus_read_config_word(bus, 0, pos + PCI_EXP_LNKSTA,
&link_status);
if (link_status & PCI_EXP_LNKSTA_NLW)
link_is_active = true;
}
}
dev_info(pcie->dev, "link: %s\n", link_is_active ? "UP" : "DOWN");
return link_is_active ? 0 : -ENODEV;
}
static void iproc_pcie_enable(struct iproc_pcie *pcie)
{
iproc_pcie_write_reg(pcie, IPROC_PCIE_INTX_EN, SYS_RC_INTX_MASK);
}
static int iproc_pcie_setup_ob(struct iproc_pcie *pcie, u64 axi_addr,
u64 pci_addr, resource_size_t size)
{
struct iproc_pcie_ob *ob = &pcie->ob;
unsigned i;
u64 max_size = (u64)ob->window_size * MAX_NUM_OB_WINDOWS;
u64 remainder;
if (size > max_size) {
dev_err(pcie->dev,
"res size %pap exceeds max supported size 0x%llx\n",
&size, max_size);
return -EINVAL;
}
div64_u64_rem(size, ob->window_size, &remainder);
if (remainder) {
dev_err(pcie->dev,
"res size %pap needs to be multiple of window size %pap\n",
&size, &ob->window_size);
return -EINVAL;
}
if (axi_addr < ob->axi_offset) {
dev_err(pcie->dev,
"axi address %pap less than offset %pap\n",
&axi_addr, &ob->axi_offset);
return -EINVAL;
}
axi_addr -= ob->axi_offset;
for (i = 0; i < MAX_NUM_OB_WINDOWS; i++) {
iproc_pcie_ob_write(pcie, IPROC_PCIE_OARR_LO, i,
lower_32_bits(axi_addr) | OARR_VALID |
(ob->set_oarr_size ? 1 : 0));
iproc_pcie_ob_write(pcie, IPROC_PCIE_OARR_HI, i,
upper_32_bits(axi_addr));
iproc_pcie_ob_write(pcie, IPROC_PCIE_OMAP_LO, i,
lower_32_bits(pci_addr));
iproc_pcie_ob_write(pcie, IPROC_PCIE_OMAP_HI, i,
upper_32_bits(pci_addr));
size -= ob->window_size;
if (size == 0)
break;
axi_addr += ob->window_size;
pci_addr += ob->window_size;
}
return 0;
}
static int iproc_pcie_map_ranges(struct iproc_pcie *pcie,
struct list_head *resources)
{
struct resource_entry *window;
int ret;
resource_list_for_each_entry(window, resources) {
struct resource *res = window->res;
u64 res_type = resource_type(res);
switch (res_type) {
case IORESOURCE_IO:
case IORESOURCE_BUS:
break;
case IORESOURCE_MEM:
ret = iproc_pcie_setup_ob(pcie, res->start,
res->start - window->offset,
resource_size(res));
if (ret)
return ret;
break;
default:
dev_err(pcie->dev, "invalid resource %pR\n", res);
return -EINVAL;
}
}
return 0;
}
static int iproc_pcie_msi_enable(struct iproc_pcie *pcie)
{
struct device_node *msi_node;
msi_node = of_parse_phandle(pcie->dev->of_node, "msi-parent", 0);
if (!msi_node)
return -ENODEV;
return iproc_msi_init(pcie, msi_node);
}
static void iproc_pcie_msi_disable(struct iproc_pcie *pcie)
{
iproc_msi_exit(pcie);
}
int iproc_pcie_setup(struct iproc_pcie *pcie, struct list_head *res)
{
int ret;
void *sysdata;
struct pci_bus *bus;
if (!pcie || !pcie->dev || !pcie->base)
return -EINVAL;
ret = phy_init(pcie->phy);
if (ret) {
dev_err(pcie->dev, "unable to initialize PCIe PHY\n");
return ret;
}
ret = phy_power_on(pcie->phy);
if (ret) {
dev_err(pcie->dev, "unable to power on PCIe PHY\n");
goto err_exit_phy;
}
switch (pcie->type) {
case IPROC_PCIE_PAXB:
pcie->reg_offsets = iproc_pcie_reg_paxb;
break;
case IPROC_PCIE_PAXC:
pcie->reg_offsets = iproc_pcie_reg_paxc;
break;
default:
dev_err(pcie->dev, "incompatible iProc PCIe interface\n");
ret = -EINVAL;
goto err_power_off_phy;
}
iproc_pcie_reset(pcie);
if (pcie->need_ob_cfg) {
ret = iproc_pcie_map_ranges(pcie, res);
if (ret) {
dev_err(pcie->dev, "map failed\n");
goto err_power_off_phy;
}
}
#ifdef CONFIG_ARM
pcie->sysdata.private_data = pcie;
sysdata = &pcie->sysdata;
#else
sysdata = pcie;
#endif
bus = pci_create_root_bus(pcie->dev, 0, &iproc_pcie_ops, sysdata, res);
if (!bus) {
dev_err(pcie->dev, "unable to create PCI root bus\n");
ret = -ENOMEM;
goto err_power_off_phy;
}
pcie->root_bus = bus;
ret = iproc_pcie_check_link(pcie, bus);
if (ret) {
dev_err(pcie->dev, "no PCIe EP device detected\n");
goto err_rm_root_bus;
}
iproc_pcie_enable(pcie);
if (IS_ENABLED(CONFIG_PCI_MSI))
if (iproc_pcie_msi_enable(pcie))
dev_info(pcie->dev, "not using iProc MSI\n");
pci_scan_child_bus(bus);
pci_assign_unassigned_bus_resources(bus);
pci_fixup_irqs(pci_common_swizzle, pcie->map_irq);
pci_bus_add_devices(bus);
return 0;
err_rm_root_bus:
pci_stop_root_bus(bus);
pci_remove_root_bus(bus);
err_power_off_phy:
phy_power_off(pcie->phy);
err_exit_phy:
phy_exit(pcie->phy);
return ret;
}
int iproc_pcie_remove(struct iproc_pcie *pcie)
{
pci_stop_root_bus(pcie->root_bus);
pci_remove_root_bus(pcie->root_bus);
iproc_pcie_msi_disable(pcie);
phy_power_off(pcie->phy);
phy_exit(pcie->phy);
return 0;
}
