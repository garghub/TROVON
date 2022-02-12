static inline struct ar2315_pci_ctrl *ar2315_pci_bus_to_apc(struct pci_bus *bus)
{
struct pci_controller *hose = bus->sysdata;
return container_of(hose, struct ar2315_pci_ctrl, pci_ctrl);
}
static inline u32 ar2315_pci_reg_read(struct ar2315_pci_ctrl *apc, u32 reg)
{
return __raw_readl(apc->mmr_mem + reg);
}
static inline void ar2315_pci_reg_write(struct ar2315_pci_ctrl *apc, u32 reg,
u32 val)
{
__raw_writel(val, apc->mmr_mem + reg);
}
static inline void ar2315_pci_reg_mask(struct ar2315_pci_ctrl *apc, u32 reg,
u32 mask, u32 val)
{
u32 ret = ar2315_pci_reg_read(apc, reg);
ret &= ~mask;
ret |= val;
ar2315_pci_reg_write(apc, reg, ret);
}
static int ar2315_pci_cfg_access(struct ar2315_pci_ctrl *apc, unsigned devfn,
int where, int size, u32 *ptr, bool write)
{
int func = PCI_FUNC(devfn);
int dev = PCI_SLOT(devfn);
u32 addr = (1 << (13 + dev)) | (func << 8) | (where & ~3);
u32 mask = 0xffffffff >> 8 * (4 - size);
u32 sh = (where & 3) * 8;
u32 value, isr;
if (addr >= AR2315_PCI_CFG_SIZE || dev > 18)
return PCIBIOS_DEVICE_NOT_FOUND;
ar2315_pci_reg_write(apc, AR2315_PCI_ISR, AR2315_PCI_INT_ABORT);
ar2315_pci_reg_mask(apc, AR2315_PCI_MISC_CONFIG, 0,
AR2315_PCIMISC_CFG_SEL);
mb();
value = __raw_readl(apc->cfg_mem + addr);
isr = ar2315_pci_reg_read(apc, AR2315_PCI_ISR);
if (isr & AR2315_PCI_INT_ABORT)
goto exit_err;
if (write) {
value = (value & ~(mask << sh)) | *ptr << sh;
__raw_writel(value, apc->cfg_mem + addr);
isr = ar2315_pci_reg_read(apc, AR2315_PCI_ISR);
if (isr & AR2315_PCI_INT_ABORT)
goto exit_err;
} else {
*ptr = (value >> sh) & mask;
}
goto exit;
exit_err:
ar2315_pci_reg_write(apc, AR2315_PCI_ISR, AR2315_PCI_INT_ABORT);
if (!write)
*ptr = 0xffffffff;
exit:
ar2315_pci_reg_mask(apc, AR2315_PCI_MISC_CONFIG, AR2315_PCIMISC_CFG_SEL,
0);
return isr & AR2315_PCI_INT_ABORT ? PCIBIOS_DEVICE_NOT_FOUND :
PCIBIOS_SUCCESSFUL;
}
static inline int ar2315_pci_local_cfg_rd(struct ar2315_pci_ctrl *apc,
unsigned devfn, int where, u32 *val)
{
return ar2315_pci_cfg_access(apc, devfn, where, sizeof(u32), val,
false);
}
static inline int ar2315_pci_local_cfg_wr(struct ar2315_pci_ctrl *apc,
unsigned devfn, int where, u32 val)
{
return ar2315_pci_cfg_access(apc, devfn, where, sizeof(u32), &val,
true);
}
static int ar2315_pci_cfg_read(struct pci_bus *bus, unsigned devfn, int where,
int size, u32 *value)
{
struct ar2315_pci_ctrl *apc = ar2315_pci_bus_to_apc(bus);
if (PCI_SLOT(devfn) == AR2315_PCI_HOST_SLOT)
return PCIBIOS_DEVICE_NOT_FOUND;
return ar2315_pci_cfg_access(apc, devfn, where, size, value, false);
}
static int ar2315_pci_cfg_write(struct pci_bus *bus, unsigned devfn, int where,
int size, u32 value)
{
struct ar2315_pci_ctrl *apc = ar2315_pci_bus_to_apc(bus);
if (PCI_SLOT(devfn) == AR2315_PCI_HOST_SLOT)
return PCIBIOS_DEVICE_NOT_FOUND;
return ar2315_pci_cfg_access(apc, devfn, where, size, &value, true);
}
static int ar2315_pci_host_setup(struct ar2315_pci_ctrl *apc)
{
unsigned devfn = PCI_DEVFN(AR2315_PCI_HOST_SLOT, 0);
int res;
u32 id;
res = ar2315_pci_local_cfg_rd(apc, devfn, PCI_VENDOR_ID, &id);
if (res != PCIBIOS_SUCCESSFUL || id != AR2315_PCI_HOST_DEVID)
return -ENODEV;
ar2315_pci_local_cfg_wr(apc, devfn, PCI_BASE_ADDRESS_0,
AR2315_PCI_HOST_MBAR0);
ar2315_pci_local_cfg_wr(apc, devfn, PCI_BASE_ADDRESS_1,
AR2315_PCI_HOST_MBAR1);
ar2315_pci_local_cfg_wr(apc, devfn, PCI_BASE_ADDRESS_2,
AR2315_PCI_HOST_MBAR2);
ar2315_pci_local_cfg_wr(apc, devfn, PCI_COMMAND, PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER | PCI_COMMAND_SPECIAL |
PCI_COMMAND_INVALIDATE | PCI_COMMAND_PARITY |
PCI_COMMAND_SERR | PCI_COMMAND_FAST_BACK);
return 0;
}
static void ar2315_pci_irq_handler(unsigned irq, struct irq_desc *desc)
{
struct ar2315_pci_ctrl *apc = irq_get_handler_data(irq);
u32 pending = ar2315_pci_reg_read(apc, AR2315_PCI_ISR) &
ar2315_pci_reg_read(apc, AR2315_PCI_IMR);
unsigned pci_irq = 0;
if (pending)
pci_irq = irq_find_mapping(apc->domain, __ffs(pending));
if (pci_irq)
generic_handle_irq(pci_irq);
else
spurious_interrupt();
}
static void ar2315_pci_irq_mask(struct irq_data *d)
{
struct ar2315_pci_ctrl *apc = irq_data_get_irq_chip_data(d);
ar2315_pci_reg_mask(apc, AR2315_PCI_IMR, BIT(d->hwirq), 0);
}
static void ar2315_pci_irq_mask_ack(struct irq_data *d)
{
struct ar2315_pci_ctrl *apc = irq_data_get_irq_chip_data(d);
u32 m = BIT(d->hwirq);
ar2315_pci_reg_mask(apc, AR2315_PCI_IMR, m, 0);
ar2315_pci_reg_write(apc, AR2315_PCI_ISR, m);
}
static void ar2315_pci_irq_unmask(struct irq_data *d)
{
struct ar2315_pci_ctrl *apc = irq_data_get_irq_chip_data(d);
ar2315_pci_reg_mask(apc, AR2315_PCI_IMR, 0, BIT(d->hwirq));
}
static int ar2315_pci_irq_map(struct irq_domain *d, unsigned irq,
irq_hw_number_t hw)
{
irq_set_chip_and_handler(irq, &ar2315_pci_irq_chip, handle_level_irq);
irq_set_chip_data(irq, d->host_data);
return 0;
}
static void ar2315_pci_irq_init(struct ar2315_pci_ctrl *apc)
{
ar2315_pci_reg_mask(apc, AR2315_PCI_IER, AR2315_PCI_IER_ENABLE, 0);
ar2315_pci_reg_mask(apc, AR2315_PCI_IMR, (AR2315_PCI_INT_ABORT |
AR2315_PCI_INT_EXT), 0);
apc->irq_ext = irq_create_mapping(apc->domain, AR2315_PCI_IRQ_EXT);
irq_set_chained_handler(apc->irq, ar2315_pci_irq_handler);
irq_set_handler_data(apc->irq, apc);
ar2315_pci_reg_write(apc, AR2315_PCI_ISR, AR2315_PCI_INT_ABORT |
AR2315_PCI_INT_EXT);
ar2315_pci_reg_mask(apc, AR2315_PCI_IER, 0, AR2315_PCI_IER_ENABLE);
}
static int ar2315_pci_probe(struct platform_device *pdev)
{
struct ar2315_pci_ctrl *apc;
struct device *dev = &pdev->dev;
struct resource *res;
int irq, err;
apc = devm_kzalloc(dev, sizeof(*apc), GFP_KERNEL);
if (!apc)
return -ENOMEM;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -EINVAL;
apc->irq = irq;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"ar2315-pci-ctrl");
apc->mmr_mem = devm_ioremap_resource(dev, res);
if (IS_ERR(apc->mmr_mem))
return PTR_ERR(apc->mmr_mem);
res = platform_get_resource_byname(pdev, IORESOURCE_MEM,
"ar2315-pci-ext");
if (!res)
return -EINVAL;
apc->mem_res.name = "AR2315 PCI mem space";
apc->mem_res.parent = res;
apc->mem_res.start = res->start;
apc->mem_res.end = res->end;
apc->mem_res.flags = IORESOURCE_MEM;
apc->cfg_mem = devm_ioremap_nocache(dev, res->start,
AR2315_PCI_CFG_SIZE);
if (!apc->cfg_mem) {
dev_err(dev, "failed to remap PCI config space\n");
return -ENOMEM;
}
ar2315_pci_reg_mask(apc, AR2315_PCI_MISC_CONFIG,
AR2315_PCIMISC_RST_MODE,
AR2315_PCIRST_LOW);
msleep(100);
ar2315_pci_reg_mask(apc, AR2315_PCI_MISC_CONFIG,
AR2315_PCIMISC_RST_MODE,
AR2315_PCIRST_HIGH | AR2315_PCICACHE_DIS | 0x8);
ar2315_pci_reg_write(apc, AR2315_PCI_UNCACHE_CFG,
0x1E |
(1 << 5) |
(0x2 << 30) );
ar2315_pci_reg_read(apc, AR2315_PCI_UNCACHE_CFG);
msleep(500);
err = ar2315_pci_host_setup(apc);
if (err)
return err;
apc->domain = irq_domain_add_linear(NULL, AR2315_PCI_IRQ_COUNT,
&ar2315_pci_irq_domain_ops, apc);
if (!apc->domain) {
dev_err(dev, "failed to add IRQ domain\n");
return -ENOMEM;
}
ar2315_pci_irq_init(apc);
apc->io_res.name = "AR2315 IO space";
apc->io_res.start = 0;
apc->io_res.end = 0;
apc->io_res.flags = IORESOURCE_IO,
apc->pci_ctrl.pci_ops = &ar2315_pci_ops;
apc->pci_ctrl.mem_resource = &apc->mem_res,
apc->pci_ctrl.io_resource = &apc->io_res,
register_pci_controller(&apc->pci_ctrl);
dev_info(dev, "register PCI controller\n");
return 0;
}
static int __init ar2315_pci_init(void)
{
return platform_driver_register(&ar2315_pci_driver);
}
int pcibios_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct ar2315_pci_ctrl *apc = ar2315_pci_bus_to_apc(dev->bus);
return slot ? 0 : apc->irq_ext;
}
int pcibios_plat_dev_init(struct pci_dev *dev)
{
return 0;
}
