static int postprocess_read(u32 data, int where, unsigned int size)
{
u32 ret;
ret = 0;
switch (size) {
case 1:
ret = (data >> ((where & 3) << 3)) & 0xff;
break;
case 2:
ret = (data >> ((where & 3) << 3)) & 0xffff;
break;
case 4:
ret = data;
break;
}
return ret;
}
static int preprocess_write(u32 orig_data, u32 val, int where,
unsigned int size)
{
u32 ret;
ret = 0;
switch (size) {
case 1:
ret = (orig_data & ~(0xff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
break;
case 2:
ret = (orig_data & ~(0xffff << ((where & 3) << 3))) |
(val << ((where & 3) << 3));
break;
case 4:
ret = val;
break;
}
return ret;
}
static int bcm63xx_setup_cfg_access(int type, unsigned int busn,
unsigned int devfn, int where)
{
unsigned int slot, func, reg;
u32 val;
slot = PCI_SLOT(devfn);
func = PCI_FUNC(devfn);
reg = where >> 2;
if (slot > (MPI_L2PCFG_DEVNUM_MASK >> MPI_L2PCFG_DEVNUM_SHIFT))
return 1;
if (func > (MPI_L2PCFG_FUNC_MASK >> MPI_L2PCFG_FUNC_SHIFT))
return 1;
if (reg > (MPI_L2PCFG_REG_MASK >> MPI_L2PCFG_REG_SHIFT))
return 1;
val = (reg << MPI_L2PCFG_REG_SHIFT);
val |= (func << MPI_L2PCFG_FUNC_SHIFT);
val |= (slot << MPI_L2PCFG_DEVNUM_SHIFT);
val |= MPI_L2PCFG_CFG_USEREG_MASK;
val |= MPI_L2PCFG_CFG_SEL_MASK;
if (type != 0) {
val |= (1 << MPI_L2PCFG_CFG_TYPE_SHIFT);
}
bcm_mpi_writel(val, MPI_L2PCFG_REG);
return 0;
}
static int bcm63xx_do_cfg_read(int type, unsigned int busn,
unsigned int devfn, int where, int size,
u32 *val)
{
u32 data;
if (bcm63xx_setup_cfg_access(type, busn, devfn, where))
return PCIBIOS_DEVICE_NOT_FOUND;
iob();
data = le32_to_cpu(__raw_readl(pci_iospace_start));
bcm_mpi_writel(0, MPI_L2PCFG_REG);
*val = postprocess_read(data, where, size);
return PCIBIOS_SUCCESSFUL;
}
static int bcm63xx_do_cfg_write(int type, unsigned int busn,
unsigned int devfn, int where, int size,
u32 val)
{
u32 data;
if (bcm63xx_setup_cfg_access(type, busn, devfn, where))
return PCIBIOS_DEVICE_NOT_FOUND;
iob();
data = le32_to_cpu(__raw_readl(pci_iospace_start));
data = preprocess_write(data, val, where, size);
__raw_writel(cpu_to_le32(data), pci_iospace_start);
wmb();
udelay(500);
bcm_mpi_writel(0, MPI_L2PCFG_REG);
return PCIBIOS_SUCCESSFUL;
}
static int bcm63xx_pci_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
int type;
type = bus->parent ? 1 : 0;
if (type == 0 && PCI_SLOT(devfn) == CARDBUS_PCI_IDSEL)
return PCIBIOS_DEVICE_NOT_FOUND;
return bcm63xx_do_cfg_read(type, bus->number, devfn,
where, size, val);
}
static int bcm63xx_pci_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
int type;
type = bus->parent ? 1 : 0;
if (type == 0 && PCI_SLOT(devfn) == CARDBUS_PCI_IDSEL)
return PCIBIOS_DEVICE_NOT_FOUND;
return bcm63xx_do_cfg_write(type, bus->number, devfn,
where, size, val);
}
static int fake_cb_bridge_read(int where, int size, u32 *val)
{
unsigned int reg;
u32 data;
data = 0;
reg = where >> 2;
switch (reg) {
case (PCI_VENDOR_ID >> 2):
case (PCI_CB_SUBSYSTEM_VENDOR_ID >> 2):
data = (bcm63xx_get_cpu_id() << 16) | PCI_VENDOR_ID_BROADCOM;
break;
case (PCI_COMMAND >> 2):
data = (PCI_STATUS_DEVSEL_SLOW << 16);
data |= fake_cb_bridge_regs.pci_command;
break;
case (PCI_CLASS_REVISION >> 2):
data = (PCI_CLASS_BRIDGE_CARDBUS << 16);
break;
case (PCI_CACHE_LINE_SIZE >> 2):
data = (PCI_HEADER_TYPE_CARDBUS << 16);
break;
case (PCI_INTERRUPT_LINE >> 2):
data = (fake_cb_bridge_regs.bridge_control << 16);
data |= (0x1 << 8) | 0xff;
break;
case (PCI_CB_PRIMARY_BUS >> 2):
data = (fake_cb_bridge_regs.cb_latency << 24);
data |= (fake_cb_bridge_regs.subordinate_busn << 16);
data |= (fake_cb_bridge_regs.cardbus_busn << 8);
data |= fake_cb_bridge_regs.pci_busn;
break;
case (PCI_CB_MEMORY_BASE_0 >> 2):
data = fake_cb_bridge_regs.mem_base0;
break;
case (PCI_CB_MEMORY_LIMIT_0 >> 2):
data = fake_cb_bridge_regs.mem_limit0;
break;
case (PCI_CB_MEMORY_BASE_1 >> 2):
data = fake_cb_bridge_regs.mem_base1;
break;
case (PCI_CB_MEMORY_LIMIT_1 >> 2):
data = fake_cb_bridge_regs.mem_limit1;
break;
case (PCI_CB_IO_BASE_0 >> 2):
data = fake_cb_bridge_regs.io_base0 | 0x1;
break;
case (PCI_CB_IO_LIMIT_0 >> 2):
data = fake_cb_bridge_regs.io_limit0;
break;
case (PCI_CB_IO_BASE_1 >> 2):
data = fake_cb_bridge_regs.io_base1 | 0x1;
break;
case (PCI_CB_IO_LIMIT_1 >> 2):
data = fake_cb_bridge_regs.io_limit1;
break;
}
*val = postprocess_read(data, where, size);
return PCIBIOS_SUCCESSFUL;
}
static int fake_cb_bridge_write(int where, int size, u32 val)
{
unsigned int reg;
u32 data, tmp;
int ret;
ret = fake_cb_bridge_read((where & ~0x3), 4, &data);
if (ret != PCIBIOS_SUCCESSFUL)
return ret;
data = preprocess_write(data, val, where, size);
reg = where >> 2;
switch (reg) {
case (PCI_COMMAND >> 2):
fake_cb_bridge_regs.pci_command = (data & 0xffff);
break;
case (PCI_CB_PRIMARY_BUS >> 2):
fake_cb_bridge_regs.cb_latency = (data >> 24) & 0xff;
fake_cb_bridge_regs.subordinate_busn = (data >> 16) & 0xff;
fake_cb_bridge_regs.cardbus_busn = (data >> 8) & 0xff;
fake_cb_bridge_regs.pci_busn = data & 0xff;
if (fake_cb_bridge_regs.cardbus_busn)
fake_cb_bridge_regs.bus_assigned = 1;
break;
case (PCI_INTERRUPT_LINE >> 2):
tmp = (data >> 16) & 0xffff;
tmp &= ~PCI_CB_BRIDGE_CTL_PREFETCH_MEM0;
tmp &= ~PCI_CB_BRIDGE_CTL_PREFETCH_MEM1;
fake_cb_bridge_regs.bridge_control = tmp;
break;
case (PCI_CB_MEMORY_BASE_0 >> 2):
fake_cb_bridge_regs.mem_base0 = data;
break;
case (PCI_CB_MEMORY_LIMIT_0 >> 2):
fake_cb_bridge_regs.mem_limit0 = data;
break;
case (PCI_CB_MEMORY_BASE_1 >> 2):
fake_cb_bridge_regs.mem_base1 = data;
break;
case (PCI_CB_MEMORY_LIMIT_1 >> 2):
fake_cb_bridge_regs.mem_limit1 = data;
break;
case (PCI_CB_IO_BASE_0 >> 2):
fake_cb_bridge_regs.io_base0 = data;
break;
case (PCI_CB_IO_LIMIT_0 >> 2):
fake_cb_bridge_regs.io_limit0 = data;
break;
case (PCI_CB_IO_BASE_1 >> 2):
fake_cb_bridge_regs.io_base1 = data;
break;
case (PCI_CB_IO_LIMIT_1 >> 2):
fake_cb_bridge_regs.io_limit1 = data;
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int bcm63xx_cb_read(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
if (!bus->parent && PCI_SLOT(devfn) == FAKE_CB_BRIDGE_SLOT) {
fake_cb_bridge_bus_number = bus->number;
return fake_cb_bridge_read(where, size, val);
}
if (fake_cb_bridge_regs.bus_assigned &&
bus->number == fake_cb_bridge_regs.cardbus_busn &&
PCI_SLOT(devfn) == 0)
return bcm63xx_do_cfg_read(0, 0,
PCI_DEVFN(CARDBUS_PCI_IDSEL, 0),
where, size, val);
return PCIBIOS_DEVICE_NOT_FOUND;
}
static int bcm63xx_cb_write(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
if (!bus->parent && PCI_SLOT(devfn) == FAKE_CB_BRIDGE_SLOT) {
fake_cb_bridge_bus_number = bus->number;
return fake_cb_bridge_write(where, size, val);
}
if (fake_cb_bridge_regs.bus_assigned &&
bus->number == fake_cb_bridge_regs.cardbus_busn &&
PCI_SLOT(devfn) == 0)
return bcm63xx_do_cfg_write(0, 0,
PCI_DEVFN(CARDBUS_PCI_IDSEL, 0),
where, size, val);
return PCIBIOS_DEVICE_NOT_FOUND;
}
static void bcm63xx_fixup(struct pci_dev *dev)
{
static int io_window = -1;
int i, found, new_io_window;
u32 val;
found = 0;
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
if (pci_resource_flags(dev, i) & IORESOURCE_IO) {
found = 1;
break;
}
}
if (!found)
return;
if (dev->bus->number == fake_cb_bridge_bus_number)
return;
if (fake_cb_bridge_regs.bus_assigned &&
dev->bus->number == fake_cb_bridge_regs.cardbus_busn &&
PCI_SLOT(dev->devfn) == 0)
new_io_window = 1;
else
new_io_window = 0;
if (new_io_window == io_window)
return;
if (io_window != -1) {
printk(KERN_ERR "bcm63xx: both PCI and cardbus devices "
"need IO, which hardware cannot do\n");
return;
}
printk(KERN_INFO "bcm63xx: PCI IO window assigned to %s\n",
(new_io_window == 0) ? "PCI" : "cardbus");
val = bcm_mpi_readl(MPI_L2PIOREMAP_REG);
if (io_window)
val |= MPI_L2PREMAP_IS_CARDBUS_MASK;
else
val &= ~MPI_L2PREMAP_IS_CARDBUS_MASK;
bcm_mpi_writel(val, MPI_L2PIOREMAP_REG);
io_window = new_io_window;
}
