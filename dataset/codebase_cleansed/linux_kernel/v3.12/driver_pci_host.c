bool bcma_core_pci_is_in_hostmode(struct bcma_drv_pci *pc)
{
struct bcma_bus *bus = pc->core->bus;
u16 chipid_top;
u32 tmp;
chipid_top = (bus->chipinfo.id & 0xFF00);
if (chipid_top != 0x4700 &&
chipid_top != 0x5300)
return false;
bcma_core_enable(pc->core, 0);
return !mips_busprobe32(tmp, pc->core->io_addr);
}
static u32 bcma_pcie_read_config(struct bcma_drv_pci *pc, u32 address)
{
pcicore_write32(pc, BCMA_CORE_PCI_CONFIG_ADDR, address);
pcicore_read32(pc, BCMA_CORE_PCI_CONFIG_ADDR);
return pcicore_read32(pc, BCMA_CORE_PCI_CONFIG_DATA);
}
static void bcma_pcie_write_config(struct bcma_drv_pci *pc, u32 address,
u32 data)
{
pcicore_write32(pc, BCMA_CORE_PCI_CONFIG_ADDR, address);
pcicore_read32(pc, BCMA_CORE_PCI_CONFIG_ADDR);
pcicore_write32(pc, BCMA_CORE_PCI_CONFIG_DATA, data);
}
static u32 bcma_get_cfgspace_addr(struct bcma_drv_pci *pc, unsigned int dev,
unsigned int func, unsigned int off)
{
u32 addr = 0;
if (dev >= 2 || !(bcma_pcie_read(pc, BCMA_CORE_PCI_DLLP_LSREG)
& BCMA_CORE_PCI_DLLP_LSREG_LINKUP))
goto out;
pcicore_write32(pc, BCMA_CORE_PCI_SBTOPCI1, BCMA_CORE_PCI_SBTOPCI_CFG0);
addr = pc->host_controller->host_cfg_addr;
addr |= (dev << BCMA_CORE_PCI_CFG_SLOT_SHIFT);
addr |= (func << BCMA_CORE_PCI_CFG_FUN_SHIFT);
addr |= (off & ~3);
out:
return addr;
}
static int bcma_extpci_read_config(struct bcma_drv_pci *pc, unsigned int dev,
unsigned int func, unsigned int off,
void *buf, int len)
{
int err = -EINVAL;
u32 addr, val;
void __iomem *mmio = 0;
WARN_ON(!pc->hostmode);
if (unlikely(len != 1 && len != 2 && len != 4))
goto out;
if (dev == 0) {
if (func > 1)
goto out;
if (off >= PCI_CONFIG_SPACE_SIZE) {
addr = (func << 12);
addr |= (off & 0x0FFC);
val = bcma_pcie_read_config(pc, addr);
} else {
addr = BCMA_CORE_PCI_PCICFG0;
addr |= (func << 8);
addr |= (off & 0xFC);
val = pcicore_read32(pc, addr);
}
} else {
addr = bcma_get_cfgspace_addr(pc, dev, func, off);
if (unlikely(!addr))
goto out;
err = -ENOMEM;
mmio = ioremap_nocache(addr, sizeof(val));
if (!mmio)
goto out;
if (mips_busprobe32(val, mmio)) {
val = 0xFFFFFFFF;
goto unmap;
}
}
val >>= (8 * (off & 3));
switch (len) {
case 1:
*((u8 *)buf) = (u8)val;
break;
case 2:
*((u16 *)buf) = (u16)val;
break;
case 4:
*((u32 *)buf) = (u32)val;
break;
}
err = 0;
unmap:
if (mmio)
iounmap(mmio);
out:
return err;
}
static int bcma_extpci_write_config(struct bcma_drv_pci *pc, unsigned int dev,
unsigned int func, unsigned int off,
const void *buf, int len)
{
int err = -EINVAL;
u32 addr, val;
void __iomem *mmio = 0;
u16 chipid = pc->core->bus->chipinfo.id;
WARN_ON(!pc->hostmode);
if (unlikely(len != 1 && len != 2 && len != 4))
goto out;
if (dev == 0) {
if (func > 1)
goto out;
if (off >= PCI_CONFIG_SPACE_SIZE) {
addr = (func << 12);
addr |= (off & 0x0FFC);
val = bcma_pcie_read_config(pc, addr);
} else {
addr = BCMA_CORE_PCI_PCICFG0;
addr |= (func << 8);
addr |= (off & 0xFC);
val = pcicore_read32(pc, addr);
}
} else {
addr = bcma_get_cfgspace_addr(pc, dev, func, off);
if (unlikely(!addr))
goto out;
err = -ENOMEM;
mmio = ioremap_nocache(addr, sizeof(val));
if (!mmio)
goto out;
if (mips_busprobe32(val, mmio)) {
val = 0xFFFFFFFF;
goto unmap;
}
}
switch (len) {
case 1:
val &= ~(0xFF << (8 * (off & 3)));
val |= *((const u8 *)buf) << (8 * (off & 3));
break;
case 2:
val &= ~(0xFFFF << (8 * (off & 3)));
val |= *((const u16 *)buf) << (8 * (off & 3));
break;
case 4:
val = *((const u32 *)buf);
break;
}
if (dev == 0) {
if (off >= PCI_CONFIG_SPACE_SIZE)
bcma_pcie_write_config(pc, addr, val);
else
pcicore_write32(pc, addr, val);
} else {
writel(val, mmio);
if (chipid == BCMA_CHIP_ID_BCM4716 ||
chipid == BCMA_CHIP_ID_BCM4748)
readl(mmio);
}
err = 0;
unmap:
if (mmio)
iounmap(mmio);
out:
return err;
}
static int bcma_core_pci_hostmode_read_config(struct pci_bus *bus,
unsigned int devfn,
int reg, int size, u32 *val)
{
unsigned long flags;
int err;
struct bcma_drv_pci *pc;
struct bcma_drv_pci_host *pc_host;
pc_host = container_of(bus->ops, struct bcma_drv_pci_host, pci_ops);
pc = pc_host->pdev;
spin_lock_irqsave(&pc_host->cfgspace_lock, flags);
err = bcma_extpci_read_config(pc, PCI_SLOT(devfn),
PCI_FUNC(devfn), reg, val, size);
spin_unlock_irqrestore(&pc_host->cfgspace_lock, flags);
return err ? PCIBIOS_DEVICE_NOT_FOUND : PCIBIOS_SUCCESSFUL;
}
static int bcma_core_pci_hostmode_write_config(struct pci_bus *bus,
unsigned int devfn,
int reg, int size, u32 val)
{
unsigned long flags;
int err;
struct bcma_drv_pci *pc;
struct bcma_drv_pci_host *pc_host;
pc_host = container_of(bus->ops, struct bcma_drv_pci_host, pci_ops);
pc = pc_host->pdev;
spin_lock_irqsave(&pc_host->cfgspace_lock, flags);
err = bcma_extpci_write_config(pc, PCI_SLOT(devfn),
PCI_FUNC(devfn), reg, &val, size);
spin_unlock_irqrestore(&pc_host->cfgspace_lock, flags);
return err ? PCIBIOS_DEVICE_NOT_FOUND : PCIBIOS_SUCCESSFUL;
}
static u8 bcma_find_pci_capability(struct bcma_drv_pci *pc, unsigned int dev,
unsigned int func, u8 req_cap_id,
unsigned char *buf, u32 *buflen)
{
u8 cap_id;
u8 cap_ptr = 0;
u32 bufsize;
u8 byte_val;
bcma_extpci_read_config(pc, dev, func, PCI_HEADER_TYPE, &byte_val,
sizeof(u8));
if ((byte_val & 0x7F) != PCI_HEADER_TYPE_NORMAL)
return cap_ptr;
bcma_extpci_read_config(pc, dev, func, PCI_STATUS, &byte_val,
sizeof(u8));
if (!(byte_val & PCI_STATUS_CAP_LIST))
return cap_ptr;
bcma_extpci_read_config(pc, dev, func, PCI_CAPABILITY_LIST, &cap_ptr,
sizeof(u8));
if (cap_ptr == 0x00)
return cap_ptr;
bcma_extpci_read_config(pc, dev, func, cap_ptr, &cap_id, sizeof(u8));
while (cap_id != req_cap_id) {
bcma_extpci_read_config(pc, dev, func, cap_ptr + 1, &cap_ptr,
sizeof(u8));
if (cap_ptr == 0x00)
return cap_ptr;
bcma_extpci_read_config(pc, dev, func, cap_ptr, &cap_id,
sizeof(u8));
}
if ((buf != NULL) && (buflen != NULL)) {
u8 cap_data;
bufsize = *buflen;
if (!bufsize)
return cap_ptr;
*buflen = 0;
cap_data = cap_ptr + 2;
if ((bufsize + cap_data) > PCI_CONFIG_SPACE_SIZE)
bufsize = PCI_CONFIG_SPACE_SIZE - cap_data;
*buflen = bufsize;
while (bufsize--) {
bcma_extpci_read_config(pc, dev, func, cap_data, buf,
sizeof(u8));
cap_data++;
buf++;
}
}
return cap_ptr;
}
static void bcma_core_pci_enable_crs(struct bcma_drv_pci *pc)
{
struct bcma_bus *bus = pc->core->bus;
u8 cap_ptr, root_ctrl, root_cap, dev;
u16 val16;
int i;
cap_ptr = bcma_find_pci_capability(pc, 0, 0, PCI_CAP_ID_EXP, NULL,
NULL);
root_cap = cap_ptr + PCI_EXP_RTCAP;
bcma_extpci_read_config(pc, 0, 0, root_cap, &val16, sizeof(u16));
if (val16 & BCMA_CORE_PCI_RC_CRS_VISIBILITY) {
root_ctrl = cap_ptr + PCI_EXP_RTCTL;
val16 = PCI_EXP_RTCTL_CRSSVE;
bcma_extpci_read_config(pc, 0, 0, root_ctrl, &val16,
sizeof(u16));
for (dev = 1; dev < BCMA_PCI_SLOT_MAX; dev++) {
for (i = 0; i < 100000; i++) {
bcma_extpci_read_config(pc, dev, 0,
PCI_VENDOR_ID, &val16,
sizeof(val16));
if (val16 != 0x1)
break;
udelay(10);
}
if (val16 == 0x1)
bcma_err(bus, "PCI: Broken device in slot %d\n",
dev);
}
}
}
void bcma_core_pci_hostmode_init(struct bcma_drv_pci *pc)
{
struct bcma_bus *bus = pc->core->bus;
struct bcma_drv_pci_host *pc_host;
u32 tmp;
u32 pci_membase_1G;
unsigned long io_map_base;
bcma_info(bus, "PCIEcore in host mode found\n");
if (bus->sprom.boardflags_lo & BCMA_CORE_PCI_BFL_NOPCI) {
bcma_info(bus, "This PCIE core is disabled and not working\n");
return;
}
pc_host = kzalloc(sizeof(*pc_host), GFP_KERNEL);
if (!pc_host) {
bcma_err(bus, "can not allocate memory");
return;
}
spin_lock_init(&pc_host->cfgspace_lock);
pc->host_controller = pc_host;
pc_host->pci_controller.io_resource = &pc_host->io_resource;
pc_host->pci_controller.mem_resource = &pc_host->mem_resource;
pc_host->pci_controller.pci_ops = &pc_host->pci_ops;
pc_host->pdev = pc;
pci_membase_1G = BCMA_SOC_PCI_DMA;
pc_host->host_cfg_addr = BCMA_SOC_PCI_CFG;
pc_host->pci_ops.read = bcma_core_pci_hostmode_read_config;
pc_host->pci_ops.write = bcma_core_pci_hostmode_write_config;
pc_host->mem_resource.name = "BCMA PCIcore external memory",
pc_host->mem_resource.start = BCMA_SOC_PCI_DMA;
pc_host->mem_resource.end = BCMA_SOC_PCI_DMA + BCMA_SOC_PCI_DMA_SZ - 1;
pc_host->mem_resource.flags = IORESOURCE_MEM | IORESOURCE_PCI_FIXED;
pc_host->io_resource.name = "BCMA PCIcore external I/O",
pc_host->io_resource.start = 0x100;
pc_host->io_resource.end = 0x7FF;
pc_host->io_resource.flags = IORESOURCE_IO | IORESOURCE_PCI_FIXED;
usleep_range(3000, 5000);
pcicore_write32(pc, BCMA_CORE_PCI_CTL, BCMA_CORE_PCI_CTL_RST_OE);
msleep(50);
pcicore_write32(pc, BCMA_CORE_PCI_CTL, BCMA_CORE_PCI_CTL_RST |
BCMA_CORE_PCI_CTL_RST_OE);
if (bus->chipinfo.id == BCMA_CHIP_ID_BCM4716 ||
bus->chipinfo.id == BCMA_CHIP_ID_BCM4748) {
pc_host->mem_resource.start = BCMA_SOC_PCI_MEM;
pc_host->mem_resource.end = BCMA_SOC_PCI_MEM +
BCMA_SOC_PCI_MEM_SZ - 1;
pcicore_write32(pc, BCMA_CORE_PCI_SBTOPCI0,
BCMA_CORE_PCI_SBTOPCI_MEM | BCMA_SOC_PCI_MEM);
} else if (bus->chipinfo.id == BCMA_CHIP_ID_BCM4706) {
tmp = BCMA_CORE_PCI_SBTOPCI_MEM;
tmp |= BCMA_CORE_PCI_SBTOPCI_PREF;
tmp |= BCMA_CORE_PCI_SBTOPCI_BURST;
if (pc->core->core_unit == 0) {
pc_host->mem_resource.start = BCMA_SOC_PCI_MEM;
pc_host->mem_resource.end = BCMA_SOC_PCI_MEM +
BCMA_SOC_PCI_MEM_SZ - 1;
pc_host->io_resource.start = 0x100;
pc_host->io_resource.end = 0x47F;
pci_membase_1G = BCMA_SOC_PCIE_DMA_H32;
pcicore_write32(pc, BCMA_CORE_PCI_SBTOPCI0,
tmp | BCMA_SOC_PCI_MEM);
} else if (pc->core->core_unit == 1) {
pc_host->mem_resource.start = BCMA_SOC_PCI1_MEM;
pc_host->mem_resource.end = BCMA_SOC_PCI1_MEM +
BCMA_SOC_PCI_MEM_SZ - 1;
pc_host->io_resource.start = 0x480;
pc_host->io_resource.end = 0x7FF;
pci_membase_1G = BCMA_SOC_PCIE1_DMA_H32;
pc_host->host_cfg_addr = BCMA_SOC_PCI1_CFG;
pcicore_write32(pc, BCMA_CORE_PCI_SBTOPCI0,
tmp | BCMA_SOC_PCI1_MEM);
}
} else
pcicore_write32(pc, BCMA_CORE_PCI_SBTOPCI0,
BCMA_CORE_PCI_SBTOPCI_IO);
pcicore_write32(pc, BCMA_CORE_PCI_SBTOPCI1, BCMA_CORE_PCI_SBTOPCI_CFG0);
pcicore_write32(pc, BCMA_CORE_PCI_SBTOPCI2,
BCMA_CORE_PCI_SBTOPCI_MEM | pci_membase_1G);
msleep(100);
bcma_core_pci_enable_crs(pc);
if (bus->chipinfo.id == BCMA_CHIP_ID_BCM4706 ||
bus->chipinfo.id == BCMA_CHIP_ID_BCM4716) {
u16 val16;
bcma_extpci_read_config(pc, 0, 0, BCMA_CORE_PCI_CFG_DEVCTRL,
&val16, sizeof(val16));
val16 |= (2 << 5);
val16 |= (2 << 12);
bcma_extpci_write_config(pc, 0, 0, BCMA_CORE_PCI_CFG_DEVCTRL,
&val16, sizeof(val16));
}
tmp = PCI_COMMAND_MASTER | PCI_COMMAND_MEMORY;
bcma_extpci_write_config(pc, 0, 0, PCI_COMMAND, &tmp, sizeof(tmp));
pcicore_write32(pc, BCMA_CORE_PCI_IMASK, BCMA_CORE_PCI_IMASK_INTA);
io_map_base = (unsigned long)ioremap_nocache(pc_host->mem_resource.start,
resource_size(&pc_host->mem_resource));
pc_host->pci_controller.io_map_base = io_map_base;
set_io_port_base(pc_host->pci_controller.io_map_base);
usleep_range(10000, 15000);
register_pci_controller(&pc_host->pci_controller);
return;
}
static void bcma_core_pci_fixup_pcibridge(struct pci_dev *dev)
{
if (dev->bus->ops->read != bcma_core_pci_hostmode_read_config) {
return;
}
if (PCI_SLOT(dev->devfn) != 0)
return;
pr_info("PCI: Fixing up bridge %s\n", pci_name(dev));
pci_set_master(dev);
if (pcibios_enable_device(dev, ~0) < 0) {
pr_err("PCI: BCMA bridge enable failed\n");
return;
}
pci_write_config_dword(dev, BCMA_PCI_BAR1_CONTROL, 3);
}
static void bcma_core_pci_fixup_addresses(struct pci_dev *dev)
{
struct resource *res;
int pos, err;
if (dev->bus->ops->read != bcma_core_pci_hostmode_read_config) {
return;
}
if (PCI_SLOT(dev->devfn) == 0)
return;
pr_info("PCI: Fixing up addresses %s\n", pci_name(dev));
for (pos = 0; pos < 6; pos++) {
res = &dev->resource[pos];
if (res->flags & (IORESOURCE_IO | IORESOURCE_MEM)) {
err = pci_assign_resource(dev, pos);
if (err)
pr_err("PCI: Problem fixing up the addresses on %s\n",
pci_name(dev));
}
}
}
int bcma_core_pci_plat_dev_init(struct pci_dev *dev)
{
struct bcma_drv_pci_host *pc_host;
int readrq;
if (dev->bus->ops->read != bcma_core_pci_hostmode_read_config) {
return -ENODEV;
}
pc_host = container_of(dev->bus->ops, struct bcma_drv_pci_host,
pci_ops);
pr_info("PCI: Fixing up device %s\n", pci_name(dev));
dev->irq = bcma_core_irq(pc_host->pdev->core);
pci_write_config_byte(dev, PCI_INTERRUPT_LINE, dev->irq);
readrq = pcie_get_readrq(dev);
if (readrq > 128) {
pr_info("change PCIe max read request size from %i to 128\n", readrq);
pcie_set_readrq(dev, 128);
}
return 0;
}
int bcma_core_pci_pcibios_map_irq(const struct pci_dev *dev)
{
struct bcma_drv_pci_host *pc_host;
if (dev->bus->ops->read != bcma_core_pci_hostmode_read_config) {
return -ENODEV;
}
pc_host = container_of(dev->bus->ops, struct bcma_drv_pci_host,
pci_ops);
return bcma_core_irq(pc_host->pdev->core);
}
