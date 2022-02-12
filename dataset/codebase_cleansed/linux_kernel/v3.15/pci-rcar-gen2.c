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
if (slot == 0x0 && where >= 0x40)
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
static int rcar_pci_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct pci_sys_data *sys = dev->bus->sysdata;
struct rcar_pci_priv *priv = sys->private_data;
int irq;
irq = of_irq_parse_and_map_pci(dev, slot, pin);
if (!irq)
irq = priv->irq;
return irq;
}
static irqreturn_t rcar_pci_err_irq(int irq, void *pw)
{
struct rcar_pci_priv *priv = pw;
u32 status = ioread32(priv->reg + RCAR_PCI_INT_STATUS_REG);
if (status & RCAR_PCI_INT_ALLERRORS) {
dev_err(priv->dev, "error irq: status %08x\n", status);
iowrite32(status & RCAR_PCI_INT_ALLERRORS,
priv->reg + RCAR_PCI_INT_STATUS_REG);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void rcar_pci_setup_errirq(struct rcar_pci_priv *priv)
{
int ret;
u32 val;
ret = devm_request_irq(priv->dev, priv->irq, rcar_pci_err_irq,
IRQF_SHARED, "error irq", priv);
if (ret) {
dev_err(priv->dev, "cannot claim IRQ for error handling\n");
return;
}
val = ioread32(priv->reg + RCAR_PCI_INT_ENABLE_REG);
val |= RCAR_PCI_INT_ALLERRORS;
iowrite32(val, priv->reg + RCAR_PCI_INT_ENABLE_REG);
}
static inline void rcar_pci_setup_errirq(struct rcar_pci_priv *priv) { }
static int rcar_pci_setup(int nr, struct pci_sys_data *sys)
{
struct rcar_pci_priv *priv = sys->private_data;
void __iomem *reg = priv->reg;
u32 val;
pm_runtime_enable(priv->dev);
pm_runtime_get_sync(priv->dev);
val = ioread32(reg + RCAR_PCI_UNIT_REV_REG);
dev_info(priv->dev, "PCI: bus%u revision %x\n", sys->busnr, val);
val = ioread32(reg + RCAR_USBCTR_REG) & ~RCAR_USBCTR_DIRPD;
val |= RCAR_USBCTR_USBH_RST | RCAR_USBCTR_PLL_RST;
iowrite32(val, reg + RCAR_USBCTR_REG);
udelay(4);
val &= ~(RCAR_USBCTR_PCIAHB_WIN1_MASK | RCAR_USBCTR_PCICLK_MASK |
RCAR_USBCTR_USBH_RST | RCAR_USBCTR_PLL_RST);
switch (priv->window_size) {
case SZ_2G:
val |= RCAR_USBCTR_PCIAHB_WIN1_2G;
break;
case SZ_1G:
val |= RCAR_USBCTR_PCIAHB_WIN1_1G;
break;
case SZ_512M:
val |= RCAR_USBCTR_PCIAHB_WIN1_512M;
break;
default:
pr_warn("unknown window size %ld - defaulting to 256M\n",
priv->window_size);
priv->window_size = SZ_256M;
case SZ_256M:
val |= RCAR_USBCTR_PCIAHB_WIN1_256M;
break;
}
iowrite32(val, reg + RCAR_USBCTR_REG);
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
if (priv->irq > 0)
rcar_pci_setup_errirq(priv);
pci_add_resource(&sys->resources, &priv->io_res);
pci_add_resource(&sys->resources, &priv->mem_res);
sys->busnr = to_platform_device(priv->dev)->id;
return 1;
}
static int rcar_pci_probe(struct platform_device *pdev)
{
struct resource *cfg_res, *mem_res;
struct rcar_pci_priv *priv;
void __iomem *reg;
struct hw_pci hw;
void *hw_private[1];
cfg_res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
reg = devm_ioremap_resource(&pdev->dev, cfg_res);
if (IS_ERR(reg))
return PTR_ERR(reg);
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
priv->dev = &pdev->dev;
if (priv->irq < 0) {
dev_err(&pdev->dev, "no valid irq found\n");
return priv->irq;
}
priv->window_size = SZ_1G;
hw_private[0] = priv;
memset(&hw, 0, sizeof(hw));
hw.nr_controllers = ARRAY_SIZE(hw_private);
hw.private_data = hw_private;
hw.map_irq = rcar_pci_map_irq;
hw.ops = &rcar_pci_ops;
hw.setup = rcar_pci_setup;
pci_common_init_dev(&pdev->dev, &hw);
return 0;
}
