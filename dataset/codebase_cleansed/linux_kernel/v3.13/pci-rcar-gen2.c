static void __iomem *rcar_pci_cfg_base(struct pci_bus *bus, unsigned int devfn,
int where)
{
struct pci_sys_data *sys = bus->sysdata;
struct rcar_pci_priv *priv = sys->private_data;
int slot, val;
if (sys->busnr != bus->number || PCI_FUNC(devfn))
return NULL;
slot = PCI_SLOT(devfn);
if (slot > 2)
return NULL;
val = slot ? RCAR_AHBPCI_WIN1_DEVICE | RCAR_AHBPCI_WIN_CTR_CFG :
RCAR_AHBPCI_WIN1_HOST | RCAR_AHBPCI_WIN_CTR_CFG;
iowrite32(val, priv->reg + RCAR_AHBPCI_WIN1_CTR_REG);
return priv->reg + (slot >> 1) * 0x100 + where;
}
static int rcar_pci_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
void __iomem *reg = rcar_pci_cfg_base(bus, devfn, where);
if (!reg)
return PCIBIOS_DEVICE_NOT_FOUND;
switch (size) {
case 1:
*val = ioread8(reg);
break;
case 2:
*val = ioread16(reg);
break;
default:
*val = ioread32(reg);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int rcar_pci_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
void __iomem *reg = rcar_pci_cfg_base(bus, devfn, where);
if (!reg)
return PCIBIOS_DEVICE_NOT_FOUND;
switch (size) {
case 1:
iowrite8(val, reg);
break;
case 2:
iowrite16(val, reg);
break;
default:
iowrite32(val, reg);
break;
}
return PCIBIOS_SUCCESSFUL;
}
static int __init rcar_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct pci_sys_data *sys = dev->bus->sysdata;
struct rcar_pci_priv *priv = sys->private_data;
return priv->irq;
}
static int __init rcar_pci_setup(int nr, struct pci_sys_data *sys)
{
struct rcar_pci_priv *priv = sys->private_data;
void __iomem *reg = priv->reg;
u32 val;
val = ioread32(reg + RCAR_PCI_UNIT_REV_REG);
pr_info("PCI: bus%u revision %x\n", sys->busnr, val);
val = ioread32(reg + RCAR_USBCTR_REG) & ~RCAR_USBCTR_DIRPD;
val |= RCAR_USBCTR_USBH_RST | RCAR_USBCTR_PLL_RST;
iowrite32(val, reg + RCAR_USBCTR_REG);
udelay(4);
val &= ~(RCAR_USBCTR_PCIAHB_WIN1_MASK | RCAR_USBCTR_PCICLK_MASK |
RCAR_USBCTR_USBH_RST | RCAR_USBCTR_PLL_RST);
iowrite32(val | RCAR_USBCTR_PCIAHB_WIN1_1G, reg + RCAR_USBCTR_REG);
iowrite32(RCAR_AHB_BUS_MODE, reg + RCAR_AHB_BUS_CTR_REG);
val = ioread32(reg + RCAR_PCI_ARBITER_CTR_REG);
val |= RCAR_PCI_ARBITER_PCIREQ0 | RCAR_PCI_ARBITER_PCIREQ1 |
RCAR_PCI_ARBITER_PCIBP_MODE;
iowrite32(val, reg + RCAR_PCI_ARBITER_CTR_REG);
iowrite32(0x40000000 | RCAR_PCIAHB_PREFETCH16,
reg + RCAR_PCIAHB_WIN1_CTR_REG);
val = priv->mem_res.start | RCAR_AHBPCI_WIN_CTR_MEM;
iowrite32(val, reg + RCAR_AHBPCI_WIN2_CTR_REG);
iowrite32(RCAR_AHBPCI_WIN1_HOST | RCAR_AHBPCI_WIN_CTR_CFG,
reg + RCAR_AHBPCI_WIN1_CTR_REG);
iowrite32(0x40000000 | PCI_BASE_ADDRESS_MEM_PREFETCH,
reg + PCI_BASE_ADDRESS_1);
val = priv->cfg_res->start + RCAR_AHBPCI_PCICOM_OFFSET;
iowrite32(val, reg + PCI_BASE_ADDRESS_0);
val = ioread32(reg + PCI_COMMAND);
val |= PCI_COMMAND_SERR | PCI_COMMAND_PARITY |
PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER;
iowrite32(val, reg + PCI_COMMAND);
iowrite32(RCAR_PCI_INT_A | RCAR_PCI_INT_B | RCAR_PCI_INT_PME,
reg + RCAR_PCI_INT_ENABLE_REG);
pci_add_resource(&sys->resources, &priv->io_res);
pci_add_resource(&sys->resources, &priv->mem_res);
return 1;
}
static int __init rcar_pci_add_controller(struct rcar_pci_priv *priv)
{
void **private_data;
int count;
if (rcar_hw_pci.nr_controllers < rcar_pci_count)
goto add_priv;
count = rcar_pci_count + RCAR_PCI_NR_CONTROLLERS;
private_data = kzalloc(count * sizeof(void *), GFP_KERNEL);
if (!private_data)
return -ENOMEM;
rcar_pci_count = count;
if (rcar_hw_pci.private_data) {
memcpy(private_data, rcar_hw_pci.private_data,
rcar_hw_pci.nr_controllers * sizeof(void *));
kfree(rcar_hw_pci.private_data);
}
rcar_hw_pci.private_data = private_data;
add_priv:
rcar_hw_pci.private_data[rcar_hw_pci.nr_controllers++] = priv;
return 0;
}
static int __init rcar_pci_probe(struct platform_device *pdev)
{
struct resource *cfg_res, *mem_res;
struct rcar_pci_priv *priv;
void __iomem *reg;
cfg_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, cfg_res);
if (!reg)
return -ENODEV;
mem_res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
if (!mem_res || !mem_res->start)
return -ENODEV;
priv = devm_kzalloc(&pdev->dev,
sizeof(struct rcar_pci_priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->mem_res = *mem_res;
priv->io_res.start = priv->mem_res.start;
priv->io_res.end = priv->mem_res.end;
priv->io_res.flags = IORESOURCE_IO;
priv->cfg_res = cfg_res;
priv->irq = platform_get_irq(pdev, 0);
priv->reg = reg;
return rcar_pci_add_controller(priv);
}
static int __init rcar_pci_init(void)
{
int retval;
retval = platform_driver_probe(&rcar_pci_driver, rcar_pci_probe);
if (!retval)
pci_common_init(&rcar_hw_pci);
kfree(rcar_hw_pci.private_data);
rcar_hw_pci.private_data = NULL;
return retval;
}
