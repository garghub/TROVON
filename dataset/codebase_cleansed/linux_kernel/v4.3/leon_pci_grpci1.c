static int grpci1_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct grpci1_priv *priv = dev->bus->sysdata;
int irq_group;
irq_group = slot & 0x3;
pin = ((pin - 1) + irq_group) & 0x3;
return priv->irq_map[pin];
}
static int grpci1_cfg_r32(struct grpci1_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 *val)
{
u32 *pci_conf, tmp, cfg;
if (where & 0x3)
return -EINVAL;
if (bus == 0) {
devfn += (0x8 * 6);
} else if (bus == TGT) {
bus = 0;
devfn = 0;
}
cfg = REGLOAD(priv->regs->cfg_stat);
REGSTORE(priv->regs->cfg_stat, (cfg & ~(0xf << 23)) | (bus << 23));
pci_conf = (u32 *) (priv->pci_conf | (devfn << 8) | (where & 0xfc));
tmp = LEON3_BYPASS_LOAD_PA(pci_conf);
if (REGLOAD(priv->regs->cfg_stat) & CFGSTAT_CTO) {
*val = 0xffffffff;
tmp = REGLOAD(priv->regs->stat_cmd);
grpci1_cfg_w32(priv, TGT, 0, PCI_COMMAND, tmp);
} else {
*val = swab32(tmp);
}
return 0;
}
static int grpci1_cfg_r16(struct grpci1_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 *val)
{
u32 v;
int ret;
if (where & 0x1)
return -EINVAL;
ret = grpci1_cfg_r32(priv, bus, devfn, where & ~0x3, &v);
*val = 0xffff & (v >> (8 * (where & 0x3)));
return ret;
}
static int grpci1_cfg_r8(struct grpci1_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 *val)
{
u32 v;
int ret;
ret = grpci1_cfg_r32(priv, bus, devfn, where & ~0x3, &v);
*val = 0xff & (v >> (8 * (where & 3)));
return ret;
}
static int grpci1_cfg_w32(struct grpci1_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 val)
{
unsigned int *pci_conf;
u32 cfg;
if (where & 0x3)
return -EINVAL;
if (bus == 0) {
devfn += (0x8 * 6);
} else if (bus == TGT) {
bus = 0;
devfn = 0;
}
cfg = REGLOAD(priv->regs->cfg_stat);
REGSTORE(priv->regs->cfg_stat, (cfg & ~(0xf << 23)) | (bus << 23));
pci_conf = (unsigned int *) (priv->pci_conf |
(devfn << 8) | (where & 0xfc));
LEON3_BYPASS_STORE_PA(pci_conf, swab32(val));
return 0;
}
static int grpci1_cfg_w16(struct grpci1_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 val)
{
int ret;
u32 v;
if (where & 0x1)
return -EINVAL;
ret = grpci1_cfg_r32(priv, bus, devfn, where&~3, &v);
if (ret)
return ret;
v = (v & ~(0xffff << (8 * (where & 0x3)))) |
((0xffff & val) << (8 * (where & 0x3)));
return grpci1_cfg_w32(priv, bus, devfn, where & ~0x3, v);
}
static int grpci1_cfg_w8(struct grpci1_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 val)
{
int ret;
u32 v;
ret = grpci1_cfg_r32(priv, bus, devfn, where & ~0x3, &v);
if (ret != 0)
return ret;
v = (v & ~(0xff << (8 * (where & 0x3)))) |
((0xff & val) << (8 * (where & 0x3)));
return grpci1_cfg_w32(priv, bus, devfn, where & ~0x3, v);
}
static int grpci1_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct grpci1_priv *priv = grpci1priv;
unsigned int busno = bus->number;
int ret;
if (PCI_SLOT(devfn) > 15 || busno > 15) {
*val = ~0;
return 0;
}
switch (size) {
case 1:
ret = grpci1_cfg_r8(priv, busno, devfn, where, val);
break;
case 2:
ret = grpci1_cfg_r16(priv, busno, devfn, where, val);
break;
case 4:
ret = grpci1_cfg_r32(priv, busno, devfn, where, val);
break;
default:
ret = -EINVAL;
break;
}
#ifdef GRPCI1_DEBUG_CFGACCESS
printk(KERN_INFO
"grpci1_read_config: [%02x:%02x:%x] ofs=%d val=%x size=%d\n",
busno, PCI_SLOT(devfn), PCI_FUNC(devfn), where, *val, size);
#endif
return ret;
}
static int grpci1_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct grpci1_priv *priv = grpci1priv;
unsigned int busno = bus->number;
if (PCI_SLOT(devfn) > 15 || busno > 15)
return 0;
#ifdef GRPCI1_DEBUG_CFGACCESS
printk(KERN_INFO
"grpci1_write_config: [%02x:%02x:%x] ofs=%d size=%d val=%x\n",
busno, PCI_SLOT(devfn), PCI_FUNC(devfn), where, size, val);
#endif
switch (size) {
default:
return -EINVAL;
case 1:
return grpci1_cfg_w8(priv, busno, devfn, where, val);
case 2:
return grpci1_cfg_w16(priv, busno, devfn, where, val);
case 4:
return grpci1_cfg_w32(priv, busno, devfn, where, val);
}
}
static void grpci1_mask_irq(struct irq_data *data)
{
u32 irqidx;
struct grpci1_priv *priv = grpci1priv;
irqidx = (u32)data->chip_data - 1;
if (irqidx > 3)
return;
irqidx += IRQ_MASK_BIT;
REGSTORE(priv->regs->irq, REGLOAD(priv->regs->irq) & ~(1 << irqidx));
}
static void grpci1_unmask_irq(struct irq_data *data)
{
u32 irqidx;
struct grpci1_priv *priv = grpci1priv;
irqidx = (u32)data->chip_data - 1;
if (irqidx > 3)
return;
irqidx += IRQ_MASK_BIT;
REGSTORE(priv->regs->irq, REGLOAD(priv->regs->irq) | (1 << irqidx));
}
static unsigned int grpci1_startup_irq(struct irq_data *data)
{
grpci1_unmask_irq(data);
return 0;
}
static void grpci1_shutdown_irq(struct irq_data *data)
{
grpci1_mask_irq(data);
}
static void grpci1_pci_flow_irq(struct irq_desc *desc)
{
struct grpci1_priv *priv = grpci1priv;
int i, ack = 0;
unsigned int irqreg;
irqreg = REGLOAD(priv->regs->irq);
irqreg = (irqreg >> IRQ_MASK_BIT) & irqreg;
if (irqreg & IRQ_ALL_ERRORS) {
generic_handle_irq(priv->irq_err);
ack = 1;
}
if (irqreg & IRQ_INTX) {
for (i = 0; i < 4; i++) {
if (irqreg & (1 << i))
generic_handle_irq(priv->irq_map[i]);
}
ack = 1;
}
if (ack)
desc->irq_data.chip->irq_eoi(&desc->irq_data);
}
static unsigned int grpci1_build_device_irq(unsigned int irq)
{
unsigned int virq = 0, pil;
pil = 1 << 8;
virq = irq_alloc(irq, pil);
if (virq == 0)
goto out;
irq_set_chip_and_handler_name(virq, &grpci1_irq, handle_simple_irq,
"pcilvl");
irq_set_chip_data(virq, (void *)irq);
out:
return virq;
}
static void grpci1_hw_init(struct grpci1_priv *priv)
{
u32 ahbadr, bar_sz, data, pciadr;
struct grpci1_regs __iomem *regs = priv->regs;
REGSTORE(regs->cfg_stat, priv->pci_area & 0xf0000000);
ahbadr = 0xf0000000 & (u32)__pa(PAGE_ALIGN((unsigned long) &_end));
REGSTORE(regs->page1, ahbadr);
REGSTORE(regs->iomap, REGLOAD(regs->iomap) & 0x0000ffff);
REGSTORE(regs->irq, 0);
grpci1_cfg_w32(priv, TGT, 0, PCI_BASE_ADDRESS_0, 0xffffffff);
grpci1_cfg_r32(priv, TGT, 0, PCI_BASE_ADDRESS_0, &bar_sz);
bar_sz = ~bar_sz + 1;
pciadr = priv->pci_area - bar_sz;
grpci1_cfg_w32(priv, TGT, 0, PCI_BASE_ADDRESS_0, pciadr);
grpci1_cfg_w32(priv, TGT, 0, PCI_BASE_ADDRESS_1, ahbadr);
grpci1_cfg_w8(priv, TGT, 0, PCI_CACHE_LINE_SIZE, 0xff);
grpci1_cfg_w8(priv, TGT, 0, PCI_LATENCY_TIMER, 0x40);
grpci1_cfg_r32(priv, TGT, 0, PCI_COMMAND, &data);
data |= (PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER);
grpci1_cfg_w32(priv, TGT, 0, PCI_COMMAND, data);
}
static irqreturn_t grpci1_jump_interrupt(int irq, void *arg)
{
struct grpci1_priv *priv = arg;
dev_err(priv->dev, "Jump IRQ happened\n");
return IRQ_NONE;
}
static irqreturn_t grpci1_err_interrupt(int irq, void *arg)
{
struct grpci1_priv *priv = arg;
u32 status;
grpci1_cfg_r16(priv, TGT, 0, PCI_STATUS, &status);
status &= priv->pci_err_mask;
if (status == 0)
return IRQ_NONE;
if (status & PCI_STATUS_PARITY)
dev_err(priv->dev, "Data Parity Error\n");
if (status & PCI_STATUS_SIG_TARGET_ABORT)
dev_err(priv->dev, "Signalled Target Abort\n");
if (status & PCI_STATUS_REC_TARGET_ABORT)
dev_err(priv->dev, "Received Target Abort\n");
if (status & PCI_STATUS_REC_MASTER_ABORT)
dev_err(priv->dev, "Received Master Abort\n");
if (status & PCI_STATUS_SIG_SYSTEM_ERROR)
dev_err(priv->dev, "Signalled System Error\n");
if (status & PCI_STATUS_DETECTED_PARITY)
dev_err(priv->dev, "Parity Error\n");
grpci1_cfg_w16(priv, TGT, 0, PCI_STATUS, status);
return IRQ_HANDLED;
}
static int grpci1_of_probe(struct platform_device *ofdev)
{
struct grpci1_regs __iomem *regs;
struct grpci1_priv *priv;
int err, len;
const int *tmp;
u32 cfg, size, err_mask;
struct resource *res;
if (grpci1priv) {
dev_err(&ofdev->dev, "only one GRPCI1 supported\n");
return -ENODEV;
}
if (ofdev->num_resources < 3) {
dev_err(&ofdev->dev, "not enough APB/AHB resources\n");
return -EIO;
}
priv = devm_kzalloc(&ofdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&ofdev->dev, "memory allocation failed\n");
return -ENOMEM;
}
platform_set_drvdata(ofdev, priv);
priv->dev = &ofdev->dev;
res = platform_get_resource(ofdev, IORESOURCE_MEM, 0);
regs = devm_ioremap_resource(&ofdev->dev, res);
if (IS_ERR(regs))
return PTR_ERR(regs);
cfg = REGLOAD(regs->cfg_stat);
if ((cfg & CFGSTAT_HOST) == 0) {
dev_err(&ofdev->dev, "not in host system slot\n");
return -EIO;
}
REGSTORE(regs->page1, 0xffffffff);
size = ~REGLOAD(regs->page1) + 1;
if (size < 0x10000000) {
dev_err(&ofdev->dev, "BAR1 must be at least 256MByte\n");
return -EIO;
}
if ((REGLOAD(regs->page0) & PAGE0_BTEN) == 0) {
dev_err(&ofdev->dev, "byte-twisting is required\n");
return -EIO;
}
priv->regs = regs;
priv->irq = irq_of_parse_and_map(ofdev->dev.of_node, 0);
dev_info(&ofdev->dev, "host found at 0x%p, irq%d\n", regs, priv->irq);
priv->pci_area = ofdev->resource[1].start;
priv->pci_area_end = ofdev->resource[1].end+1;
priv->pci_io = ofdev->resource[2].start;
priv->pci_conf = ofdev->resource[2].start + 0x10000;
priv->pci_conf_end = priv->pci_conf + 0x10000;
priv->pci_io_va = (unsigned long)ioremap(priv->pci_io, 0x10000);
if (!priv->pci_io_va) {
dev_err(&ofdev->dev, "unable to map PCI I/O area\n");
return -EIO;
}
printk(KERN_INFO
"GRPCI1: MEMORY SPACE [0x%08lx - 0x%08lx]\n"
" I/O SPACE [0x%08lx - 0x%08lx]\n"
" CONFIG SPACE [0x%08lx - 0x%08lx]\n",
priv->pci_area, priv->pci_area_end-1,
priv->pci_io, priv->pci_conf-1,
priv->pci_conf, priv->pci_conf_end-1);
priv->info.io_space.name = "GRPCI1 PCI I/O Space";
priv->info.io_space.start = priv->pci_io_va + 0x1000;
priv->info.io_space.end = priv->pci_io_va + 0x10000 - 1;
priv->info.io_space.flags = IORESOURCE_IO;
priv->info.mem_space.name = "GRPCI1 PCI MEM Space";
priv->info.mem_space.start = priv->pci_area;
priv->info.mem_space.end = priv->pci_area_end - 1;
priv->info.mem_space.flags = IORESOURCE_MEM;
if (request_resource(&iomem_resource, &priv->info.mem_space) < 0) {
dev_err(&ofdev->dev, "unable to request PCI memory area\n");
err = -ENOMEM;
goto err1;
}
if (request_resource(&ioport_resource, &priv->info.io_space) < 0) {
dev_err(&ofdev->dev, "unable to request PCI I/O area\n");
err = -ENOMEM;
goto err2;
}
priv->info.busn.name = "GRPCI1 busn";
priv->info.busn.start = 0;
priv->info.busn.end = 15;
grpci1priv = priv;
grpci1_hw_init(priv);
leon_update_virq_handling(priv->irq, grpci1_pci_flow_irq, "pcilvl", 0);
priv->irq_map[0] = grpci1_build_device_irq(1);
priv->irq_map[1] = grpci1_build_device_irq(2);
priv->irq_map[2] = grpci1_build_device_irq(3);
priv->irq_map[3] = grpci1_build_device_irq(4);
priv->irq_err = grpci1_build_device_irq(5);
printk(KERN_INFO " PCI INTA..D#: IRQ%d, IRQ%d, IRQ%d, IRQ%d\n",
priv->irq_map[0], priv->irq_map[1], priv->irq_map[2],
priv->irq_map[3]);
err = devm_request_irq(&ofdev->dev, priv->irq, grpci1_jump_interrupt, 0,
"GRPCI1_JUMP", priv);
if (err) {
dev_err(&ofdev->dev, "ERR IRQ request failed: %d\n", err);
goto err3;
}
err = devm_request_irq(&ofdev->dev, priv->irq_err,
grpci1_err_interrupt, IRQF_SHARED, "GRPCI1_ERR",
priv);
if (err) {
dev_err(&ofdev->dev, "ERR VIRQ request failed: %d\n", err);
goto err3;
}
tmp = of_get_property(ofdev->dev.of_node, "all_pci_errors", &len);
if (tmp && (len == 4)) {
priv->pci_err_mask = ALL_PCI_ERRORS;
err_mask = IRQ_ALL_ERRORS << IRQ_MASK_BIT;
} else {
priv->pci_err_mask = DEF_PCI_ERRORS;
err_mask = IRQ_DEF_ERRORS << IRQ_MASK_BIT;
}
REGSTORE(regs->irq, err_mask);
priv->info.ops = &grpci1_ops;
priv->info.map_irq = grpci1_map_irq;
leon_pci_init(ofdev, &priv->info);
return 0;
err3:
release_resource(&priv->info.io_space);
err2:
release_resource(&priv->info.mem_space);
err1:
iounmap((void __iomem *)priv->pci_io_va);
grpci1priv = NULL;
return err;
}
static int __init grpci1_init(void)
{
return platform_driver_register(&grpci1_of_driver);
}
