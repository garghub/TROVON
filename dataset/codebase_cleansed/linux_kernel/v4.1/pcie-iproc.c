static inline struct iproc_pcie *sys_to_pcie(struct pci_sys_data *sys)
{
return sys->private_data;
}
static void __iomem *iproc_pcie_map_cfg_bus(struct pci_bus *bus,
unsigned int devfn,
int where)
{
struct pci_sys_data *sys = bus->sysdata;
struct iproc_pcie *pcie = sys_to_pcie(sys);
unsigned slot = PCI_SLOT(devfn);
unsigned fn = PCI_FUNC(devfn);
unsigned busno = bus->number;
u32 val;
if (busno == 0) {
if (slot >= 1)
return NULL;
writel(where & CFG_IND_ADDR_MASK,
pcie->base + CFG_IND_ADDR_OFFSET);
return (pcie->base + CFG_IND_DATA_OFFSET);
}
if (fn > 1)
return NULL;
val = (busno << CFG_ADDR_BUS_NUM_SHIFT) |
(slot << CFG_ADDR_DEV_NUM_SHIFT) |
(fn << CFG_ADDR_FUNC_NUM_SHIFT) |
(where & CFG_ADDR_REG_NUM_MASK) |
(1 & CFG_ADDR_CFG_TYPE_MASK);
writel(val, pcie->base + CFG_ADDR_OFFSET);
return (pcie->base + CFG_DATA_OFFSET);
}
static void iproc_pcie_reset(struct iproc_pcie *pcie)
{
u32 val;
val = EP_MODE_SURVIVE_PERST | RC_PCIE_RST_OUTPUT;
writel(val, pcie->base + CLK_CONTROL_OFFSET);
udelay(250);
val &= ~EP_MODE_SURVIVE_PERST;
writel(val, pcie->base + CLK_CONTROL_OFFSET);
msleep(250);
}
static int iproc_pcie_check_link(struct iproc_pcie *pcie, struct pci_bus *bus)
{
u8 hdr_type;
u32 link_ctrl;
u16 pos, link_status;
int link_is_active = 0;
pci_bus_read_config_byte(bus, 0, PCI_HEADER_TYPE, &hdr_type);
if ((hdr_type & 0x7f) != PCI_HEADER_TYPE_BRIDGE) {
dev_err(pcie->dev, "in EP mode, hdr=%#02x\n", hdr_type);
return -EFAULT;
}
pci_bus_write_config_word(bus, 0, PCI_CLASS_DEVICE,
PCI_CLASS_BRIDGE_PCI);
pos = pci_bus_find_capability(bus, 0, PCI_CAP_ID_EXP);
pci_bus_read_config_word(bus, 0, pos + PCI_EXP_LNKSTA, &link_status);
if (link_status & PCI_EXP_LNKSTA_NLW)
link_is_active = 1;
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
link_is_active = 1;
}
}
dev_info(pcie->dev, "link: %s\n", link_is_active ? "UP" : "DOWN");
return link_is_active ? 0 : -ENODEV;
}
static void iproc_pcie_enable(struct iproc_pcie *pcie)
{
writel(SYS_RC_INTX_MASK, pcie->base + SYS_RC_INTX_EN);
}
int iproc_pcie_setup(struct iproc_pcie *pcie)
{
int ret;
struct pci_bus *bus;
if (!pcie || !pcie->dev || !pcie->base)
return -EINVAL;
if (pcie->phy) {
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
}
iproc_pcie_reset(pcie);
pcie->sysdata.private_data = pcie;
bus = pci_create_root_bus(pcie->dev, 0, &iproc_pcie_ops,
&pcie->sysdata, pcie->resources);
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
pci_scan_child_bus(bus);
pci_assign_unassigned_bus_resources(bus);
pci_fixup_irqs(pci_common_swizzle, of_irq_parse_and_map_pci);
pci_bus_add_devices(bus);
return 0;
err_rm_root_bus:
pci_stop_root_bus(bus);
pci_remove_root_bus(bus);
err_power_off_phy:
if (pcie->phy)
phy_power_off(pcie->phy);
err_exit_phy:
if (pcie->phy)
phy_exit(pcie->phy);
return ret;
}
int iproc_pcie_remove(struct iproc_pcie *pcie)
{
pci_stop_root_bus(pcie->root_bus);
pci_remove_root_bus(pcie->root_bus);
if (pcie->phy) {
phy_power_off(pcie->phy);
phy_exit(pcie->phy);
}
return 0;
}
