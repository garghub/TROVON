static u32 bcma_pcie_read(struct bcma_drv_pci *pc, u32 address)
{
pcicore_write32(pc, 0x130, address);
pcicore_read32(pc, 0x130);
return pcicore_read32(pc, 0x134);
}
static void bcma_pcie_mdio_set_phy(struct bcma_drv_pci *pc, u8 phy)
{
const u16 mdio_control = 0x128;
const u16 mdio_data = 0x12C;
u32 v;
int i;
v = (1 << 30);
v |= (1 << 28);
v |= (1 << 17);
v |= (0x1F << 18);
v |= (phy << 4);
pcicore_write32(pc, mdio_data, v);
udelay(10);
for (i = 0; i < 200; i++) {
v = pcicore_read32(pc, mdio_control);
if (v & 0x100 )
break;
msleep(1);
}
}
static u16 bcma_pcie_mdio_read(struct bcma_drv_pci *pc, u8 device, u8 address)
{
const u16 mdio_control = 0x128;
const u16 mdio_data = 0x12C;
int max_retries = 10;
u16 ret = 0;
u32 v;
int i;
v = 0x80;
v |= 0x2;
pcicore_write32(pc, mdio_control, v);
if (pc->core->id.rev >= 10) {
max_retries = 200;
bcma_pcie_mdio_set_phy(pc, device);
}
v = (1 << 30);
v |= (1 << 29);
v |= (1 << 17);
if (pc->core->id.rev < 10)
v |= (u32)device << 22;
v |= (u32)address << 18;
pcicore_write32(pc, mdio_data, v);
udelay(10);
for (i = 0; i < max_retries; i++) {
v = pcicore_read32(pc, mdio_control);
if (v & 0x100 ) {
udelay(10);
ret = pcicore_read32(pc, mdio_data);
break;
}
msleep(1);
}
pcicore_write32(pc, mdio_control, 0);
return ret;
}
static void bcma_pcie_mdio_write(struct bcma_drv_pci *pc, u8 device,
u8 address, u16 data)
{
const u16 mdio_control = 0x128;
const u16 mdio_data = 0x12C;
int max_retries = 10;
u32 v;
int i;
v = 0x80;
v |= 0x2;
pcicore_write32(pc, mdio_control, v);
if (pc->core->id.rev >= 10) {
max_retries = 200;
bcma_pcie_mdio_set_phy(pc, device);
}
v = (1 << 30);
v |= (1 << 28);
v |= (1 << 17);
if (pc->core->id.rev < 10)
v |= (u32)device << 22;
v |= (u32)address << 18;
v |= data;
pcicore_write32(pc, mdio_data, v);
udelay(10);
for (i = 0; i < max_retries; i++) {
v = pcicore_read32(pc, mdio_control);
if (v & 0x100 )
break;
msleep(1);
}
pcicore_write32(pc, mdio_control, 0);
}
static u8 bcma_pcicore_polarity_workaround(struct bcma_drv_pci *pc)
{
return (bcma_pcie_read(pc, 0x204) & 0x10) ? 0xC0 : 0x80;
}
static void bcma_pcicore_serdes_workaround(struct bcma_drv_pci *pc)
{
const u8 serdes_pll_device = 0x1D;
const u8 serdes_rx_device = 0x1F;
u16 tmp;
bcma_pcie_mdio_write(pc, serdes_rx_device, 1 ,
bcma_pcicore_polarity_workaround(pc));
tmp = bcma_pcie_mdio_read(pc, serdes_pll_device, 1 );
if (tmp & 0x4000)
bcma_pcie_mdio_write(pc, serdes_pll_device, 1, tmp & ~0x4000);
}
static void bcma_core_pci_clientmode_init(struct bcma_drv_pci *pc)
{
bcma_pcicore_serdes_workaround(pc);
}
static bool bcma_core_pci_is_in_hostmode(struct bcma_drv_pci *pc)
{
struct bcma_bus *bus = pc->core->bus;
u16 chipid_top;
chipid_top = (bus->chipinfo.id & 0xFF00);
if (chipid_top != 0x4700 &&
chipid_top != 0x5300)
return false;
#ifdef CONFIG_SSB_DRIVER_PCICORE
if (bus->sprom.boardflags_lo & SSB_BFL_NOPCI)
return false;
#endif
#if 0
u32 tmp;
return !mips_busprobe32(tmp, (bus->mmio +
(pc->core->core_index * BCMA_CORE_SIZE)));
#endif
return true;
}
void bcma_core_pci_init(struct bcma_drv_pci *pc)
{
if (pc->setup_done)
return;
if (bcma_core_pci_is_in_hostmode(pc)) {
#ifdef CONFIG_BCMA_DRIVER_PCI_HOSTMODE
bcma_core_pci_hostmode_init(pc);
#else
pr_err("Driver compiled without support for hostmode PCI\n");
#endif
} else {
bcma_core_pci_clientmode_init(pc);
}
pc->setup_done = true;
}
int bcma_core_pci_irq_ctl(struct bcma_drv_pci *pc, struct bcma_device *core,
bool enable)
{
struct pci_dev *pdev = pc->core->bus->host_pci;
u32 coremask, tmp;
int err = 0;
if (core->bus->hosttype != BCMA_HOSTTYPE_PCI) {
goto out;
}
err = pci_read_config_dword(pdev, BCMA_PCI_IRQMASK, &tmp);
if (err)
goto out;
coremask = BIT(core->core_index) << 8;
if (enable)
tmp |= coremask;
else
tmp &= ~coremask;
err = pci_write_config_dword(pdev, BCMA_PCI_IRQMASK, tmp);
out:
return err;
}
