static int grpci2_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
struct grpci2_priv *priv = dev->bus->sysdata;
int irq_group;
irq_group = slot & 0x3;
pin = ((pin - 1) + irq_group) & 0x3;
return priv->irq_map[pin];
}
static int grpci2_cfg_r32(struct grpci2_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 *val)
{
unsigned int *pci_conf;
unsigned long flags;
u32 tmp;
if (where & 0x3)
return -EINVAL;
if (bus == 0) {
devfn += (0x8 * 6);
} else if (bus == TGT) {
bus = 0;
devfn = 0;
}
spin_lock_irqsave(&grpci2_dev_lock, flags);
REGSTORE(priv->regs->ctrl, (REGLOAD(priv->regs->ctrl) & ~(0xff << 16)) |
(bus << 16));
spin_unlock_irqrestore(&grpci2_dev_lock, flags);
REGSTORE(priv->regs->sts_cap, (STS_CFGERR | STS_CFGERRVALID));
pci_conf = (unsigned int *) (priv->pci_conf |
(devfn << 8) | (where & 0xfc));
tmp = LEON3_BYPASS_LOAD_PA(pci_conf);
while ((REGLOAD(priv->regs->sts_cap) & STS_CFGERRVALID) == 0)
;
if (REGLOAD(priv->regs->sts_cap) & STS_CFGERR) {
*val = 0xffffffff;
} else {
*val = swab32(tmp);
}
return 0;
}
static int grpci2_cfg_r16(struct grpci2_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 *val)
{
u32 v;
int ret;
if (where & 0x1)
return -EINVAL;
ret = grpci2_cfg_r32(priv, bus, devfn, where & ~0x3, &v);
*val = 0xffff & (v >> (8 * (where & 0x3)));
return ret;
}
static int grpci2_cfg_r8(struct grpci2_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 *val)
{
u32 v;
int ret;
ret = grpci2_cfg_r32(priv, bus, devfn, where & ~0x3, &v);
*val = 0xff & (v >> (8 * (where & 3)));
return ret;
}
static int grpci2_cfg_w32(struct grpci2_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 val)
{
unsigned int *pci_conf;
unsigned long flags;
if (where & 0x3)
return -EINVAL;
if (bus == 0) {
devfn += (0x8 * 6);
} else if (bus == TGT) {
bus = 0;
devfn = 0;
}
spin_lock_irqsave(&grpci2_dev_lock, flags);
REGSTORE(priv->regs->ctrl, (REGLOAD(priv->regs->ctrl) & ~(0xff << 16)) |
(bus << 16));
spin_unlock_irqrestore(&grpci2_dev_lock, flags);
REGSTORE(priv->regs->sts_cap, (STS_CFGERR | STS_CFGERRVALID));
pci_conf = (unsigned int *) (priv->pci_conf |
(devfn << 8) | (where & 0xfc));
LEON3_BYPASS_STORE_PA(pci_conf, swab32(val));
while ((REGLOAD(priv->regs->sts_cap) & STS_CFGERRVALID) == 0)
;
return 0;
}
static int grpci2_cfg_w16(struct grpci2_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 val)
{
int ret;
u32 v;
if (where & 0x1)
return -EINVAL;
ret = grpci2_cfg_r32(priv, bus, devfn, where&~3, &v);
if (ret)
return ret;
v = (v & ~(0xffff << (8 * (where & 0x3)))) |
((0xffff & val) << (8 * (where & 0x3)));
return grpci2_cfg_w32(priv, bus, devfn, where & ~0x3, v);
}
static int grpci2_cfg_w8(struct grpci2_priv *priv, unsigned int bus,
unsigned int devfn, int where, u32 val)
{
int ret;
u32 v;
ret = grpci2_cfg_r32(priv, bus, devfn, where & ~0x3, &v);
if (ret != 0)
return ret;
v = (v & ~(0xff << (8 * (where & 0x3)))) |
((0xff & val) << (8 * (where & 0x3)));
return grpci2_cfg_w32(priv, bus, devfn, where & ~0x3, v);
}
static int grpci2_read_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 *val)
{
struct grpci2_priv *priv = grpci2priv;
unsigned int busno = bus->number;
int ret;
if (PCI_SLOT(devfn) > 15 || busno > 255) {
*val = ~0;
return 0;
}
switch (size) {
case 1:
ret = grpci2_cfg_r8(priv, busno, devfn, where, val);
break;
case 2:
ret = grpci2_cfg_r16(priv, busno, devfn, where, val);
break;
case 4:
ret = grpci2_cfg_r32(priv, busno, devfn, where, val);
break;
default:
ret = -EINVAL;
break;
}
#ifdef GRPCI2_DEBUG_CFGACCESS
printk(KERN_INFO "grpci2_read_config: [%02x:%02x:%x] ofs=%d val=%x "
"size=%d\n", busno, PCI_SLOT(devfn), PCI_FUNC(devfn), where,
*val, size);
#endif
return ret;
}
static int grpci2_write_config(struct pci_bus *bus, unsigned int devfn,
int where, int size, u32 val)
{
struct grpci2_priv *priv = grpci2priv;
unsigned int busno = bus->number;
if (PCI_SLOT(devfn) > 15 || busno > 255)
return 0;
#ifdef GRPCI2_DEBUG_CFGACCESS
printk(KERN_INFO "grpci2_write_config: [%02x:%02x:%x] ofs=%d size=%d "
"val=%x\n", busno, PCI_SLOT(devfn), PCI_FUNC(devfn),
where, size, val);
#endif
switch (size) {
default:
return -EINVAL;
case 1:
return grpci2_cfg_w8(priv, busno, devfn, where, val);
case 2:
return grpci2_cfg_w16(priv, busno, devfn, where, val);
case 4:
return grpci2_cfg_w32(priv, busno, devfn, where, val);
}
}
static void grpci2_mask_irq(struct irq_data *data)
{
unsigned long flags;
unsigned int irqidx;
struct grpci2_priv *priv = grpci2priv;
irqidx = (unsigned int)data->chip_data - 1;
if (irqidx > 3)
return;
spin_lock_irqsave(&grpci2_dev_lock, flags);
REGSTORE(priv->regs->ctrl, REGLOAD(priv->regs->ctrl) & ~(1 << irqidx));
spin_unlock_irqrestore(&grpci2_dev_lock, flags);
}
static void grpci2_unmask_irq(struct irq_data *data)
{
unsigned long flags;
unsigned int irqidx;
struct grpci2_priv *priv = grpci2priv;
irqidx = (unsigned int)data->chip_data - 1;
if (irqidx > 3)
return;
spin_lock_irqsave(&grpci2_dev_lock, flags);
REGSTORE(priv->regs->ctrl, REGLOAD(priv->regs->ctrl) | (1 << irqidx));
spin_unlock_irqrestore(&grpci2_dev_lock, flags);
}
static unsigned int grpci2_startup_irq(struct irq_data *data)
{
grpci2_unmask_irq(data);
return 0;
}
static void grpci2_shutdown_irq(struct irq_data *data)
{
grpci2_mask_irq(data);
}
static void grpci2_pci_flow_irq(struct irq_desc *desc)
{
struct grpci2_priv *priv = grpci2priv;
int i, ack = 0;
unsigned int ctrl, sts_cap, pci_ints;
ctrl = REGLOAD(priv->regs->ctrl);
sts_cap = REGLOAD(priv->regs->sts_cap);
if (sts_cap & STS_ERR_IRQ) {
generic_handle_irq(priv->virq_err);
ack = 1;
}
pci_ints = ((~sts_cap) >> STS_INTSTS_BIT) & ctrl & CTRL_HOSTINT;
if (pci_ints) {
for (i = 0; i < 4; i++) {
if (pci_ints & (1 << i))
generic_handle_irq(priv->irq_map[i]);
}
ack = 1;
}
if ((priv->irq_mode == 0) && (sts_cap & (STS_IDMA | STS_IDMAERR))) {
generic_handle_irq(priv->virq_dma);
ack = 1;
}
if (ack)
desc->irq_data.chip->irq_eoi(&desc->irq_data);
}
static unsigned int grpci2_build_device_irq(unsigned int irq)
{
unsigned int virq = 0, pil;
pil = 1 << 8;
virq = irq_alloc(irq, pil);
if (virq == 0)
goto out;
irq_set_chip_and_handler_name(virq, &grpci2_irq, handle_simple_irq,
"pcilvl");
irq_set_chip_data(virq, (void *)irq);
out:
return virq;
}
static void grpci2_hw_init(struct grpci2_priv *priv)
{
u32 ahbadr, pciadr, bar_sz, capptr, io_map, data;
struct grpci2_regs __iomem *regs = priv->regs;
int i;
struct grpci2_barcfg *barcfg = priv->tgtbars;
if (priv->do_reset) {
printk(KERN_INFO "GRPCI2: Resetting PCI bus\n");
REGSTORE(regs->ctrl, CTRL_RESET);
ssleep(1);
}
REGSTORE(regs->ctrl, 0);
REGSTORE(regs->sts_cap, ~0);
REGSTORE(regs->dma_ctrl, 0);
REGSTORE(regs->dma_bdbase, 0);
REGSTORE(regs->io_map, REGLOAD(regs->io_map) & 0x0000ffff);
for (i = 0; i < 16; i++)
REGSTORE(regs->ahbmst_map[i], priv->pci_area);
grpci2_cfg_r32(priv, TGT, 0, PCI_VENDOR_ID, &priv->pciid);
grpci2_cfg_r8(priv, TGT, 0, PCI_CAPABILITY_LIST, &capptr);
grpci2_cfg_r32(priv, TGT, 0, capptr+CAP9_IOMAP_OFS, &io_map);
io_map = (io_map & ~0x1) | (priv->bt_enabled ? 1 : 0);
grpci2_cfg_w32(priv, TGT, 0, capptr+CAP9_IOMAP_OFS, io_map);
for (i = 0; i < 6; i++) {
if (barcfg[i].pciadr != ~0 && barcfg[i].ahbadr != ~0) {
ahbadr = barcfg[i].ahbadr;
pciadr = barcfg[i].pciadr;
bar_sz = ((pciadr - 1) & ~pciadr) + 1;
} else {
if (i == 0) {
bar_sz = 0xf0000008;
ahbadr = 0xf0000000 & (u32)__pa(PAGE_ALIGN(
(unsigned long) &_end));
pciadr = ahbadr;
} else {
bar_sz = 0;
ahbadr = 0;
pciadr = 0;
}
}
grpci2_cfg_w32(priv, TGT, 0, capptr+CAP9_BARSIZE_OFS+i*4,
bar_sz);
grpci2_cfg_w32(priv, TGT, 0, PCI_BASE_ADDRESS_0+i*4, pciadr);
grpci2_cfg_w32(priv, TGT, 0, capptr+CAP9_BAR_OFS+i*4, ahbadr);
printk(KERN_INFO " TGT BAR[%d]: 0x%08x (PCI)-> 0x%08x\n",
i, pciadr, ahbadr);
}
grpci2_cfg_r32(priv, TGT, 0, PCI_COMMAND, &data);
data |= (PCI_COMMAND_MEMORY | PCI_COMMAND_MASTER);
grpci2_cfg_w32(priv, TGT, 0, PCI_COMMAND, data);
REGSTORE(regs->ctrl, CTRL_ER | CTRL_PE);
}
static irqreturn_t grpci2_jump_interrupt(int irq, void *arg)
{
printk(KERN_ERR "GRPCI2: Jump IRQ happened\n");
return IRQ_NONE;
}
static irqreturn_t grpci2_err_interrupt(int irq, void *arg)
{
struct grpci2_priv *priv = arg;
struct grpci2_regs __iomem *regs = priv->regs;
unsigned int status;
status = REGLOAD(regs->sts_cap);
if ((status & STS_ERR_IRQ) == 0)
return IRQ_NONE;
if (status & STS_IPARERR)
printk(KERN_ERR "GRPCI2: Parity Error\n");
if (status & STS_ITGTABRT)
printk(KERN_ERR "GRPCI2: Target Abort\n");
if (status & STS_IMSTABRT)
printk(KERN_ERR "GRPCI2: Master Abort\n");
if (status & STS_ISYSERR)
printk(KERN_ERR "GRPCI2: System Error\n");
REGSTORE(regs->sts_cap, status & STS_ERR_IRQ);
return IRQ_HANDLED;
}
static int grpci2_of_probe(struct platform_device *ofdev)
{
struct grpci2_regs __iomem *regs;
struct grpci2_priv *priv;
int err, i, len;
const int *tmp;
unsigned int capability;
if (grpci2priv) {
printk(KERN_ERR "GRPCI2: only one GRPCI2 core supported\n");
return -ENODEV;
}
if (ofdev->num_resources < 3) {
printk(KERN_ERR "GRPCI2: not enough APB/AHB resources\n");
return -EIO;
}
regs = of_ioremap(&ofdev->resource[0], 0,
resource_size(&ofdev->resource[0]),
"grlib-grpci2 regs");
if (regs == NULL) {
printk(KERN_ERR "GRPCI2: ioremap failed\n");
return -EIO;
}
capability = REGLOAD(regs->sts_cap);
if ((capability & STS_HOST) || !(capability & STS_MST)) {
printk(KERN_INFO "GRPCI2: not in host system slot\n");
err = -EIO;
goto err1;
}
priv = grpci2priv = kzalloc(sizeof(struct grpci2_priv), GFP_KERNEL);
if (grpci2priv == NULL) {
err = -ENOMEM;
goto err1;
}
priv->regs = regs;
priv->irq = ofdev->archdata.irqs[0];
priv->irq_mode = (capability & STS_IRQMODE) >> STS_IRQMODE_BIT;
printk(KERN_INFO "GRPCI2: host found at %p, irq%d\n", regs, priv->irq);
priv->bt_enabled = 1;
tmp = of_get_property(ofdev->dev.of_node, "barcfg", &len);
if (tmp && (len == 2*4*6))
memcpy(priv->tgtbars, tmp, 2*4*6);
else
memset(priv->tgtbars, -1, 2*4*6);
tmp = of_get_property(ofdev->dev.of_node, "irq_mask", &len);
if (tmp && (len == 4))
priv->do_reset = *tmp;
else
priv->irq_mask = 0xf;
tmp = of_get_property(ofdev->dev.of_node, "reset", &len);
if (tmp && (len == 4))
priv->do_reset = *tmp;
else
priv->do_reset = 0;
priv->pci_area = ofdev->resource[1].start;
priv->pci_area_end = ofdev->resource[1].end+1;
priv->pci_io = ofdev->resource[2].start;
priv->pci_conf = ofdev->resource[2].start + 0x10000;
priv->pci_conf_end = priv->pci_conf + 0x10000;
priv->pci_io_va = (unsigned long)ioremap(priv->pci_io, 0x10000);
if (!priv->pci_io_va) {
err = -EIO;
goto err2;
}
printk(KERN_INFO
"GRPCI2: MEMORY SPACE [0x%08lx - 0x%08lx]\n"
" I/O SPACE [0x%08lx - 0x%08lx]\n"
" CONFIG SPACE [0x%08lx - 0x%08lx]\n",
priv->pci_area, priv->pci_area_end-1,
priv->pci_io, priv->pci_conf-1,
priv->pci_conf, priv->pci_conf_end-1);
memset(&priv->info.io_space, 0, sizeof(struct resource));
priv->info.io_space.name = "GRPCI2 PCI I/O Space";
priv->info.io_space.start = priv->pci_io_va + 0x1000;
priv->info.io_space.end = priv->pci_io_va + 0x10000 - 1;
priv->info.io_space.flags = IORESOURCE_IO;
memset(&priv->info.mem_space, 0, sizeof(struct resource));
priv->info.mem_space.name = "GRPCI2 PCI MEM Space";
priv->info.mem_space.start = priv->pci_area;
priv->info.mem_space.end = priv->pci_area_end - 1;
priv->info.mem_space.flags = IORESOURCE_MEM;
if (request_resource(&iomem_resource, &priv->info.mem_space) < 0)
goto err3;
if (request_resource(&ioport_resource, &priv->info.io_space) < 0)
goto err4;
priv->info.busn.name = "GRPCI2 busn";
priv->info.busn.start = 0;
priv->info.busn.end = 255;
grpci2_hw_init(priv);
if (priv->irq_mode < 2) {
leon_update_virq_handling(priv->irq, grpci2_pci_flow_irq,
"pcilvl", 0);
priv->irq_map[0] = grpci2_build_device_irq(1);
priv->irq_map[1] = grpci2_build_device_irq(2);
priv->irq_map[2] = grpci2_build_device_irq(3);
priv->irq_map[3] = grpci2_build_device_irq(4);
priv->virq_err = grpci2_build_device_irq(5);
if (priv->irq_mode & 1)
priv->virq_dma = ofdev->archdata.irqs[1];
else
priv->virq_dma = grpci2_build_device_irq(6);
err = request_irq(priv->irq, grpci2_jump_interrupt, 0,
"GRPCI2_JUMP", priv);
if (err)
printk(KERN_ERR "GRPCI2: ERR IRQ request failed\n");
} else {
for (i = 0; i < 4; i++) {
leon_update_virq_handling(ofdev->archdata.irqs[i],
handle_fasteoi_irq, "pcilvl",
1);
priv->irq_map[i] = ofdev->archdata.irqs[i];
}
priv->virq_err = priv->irq_map[0];
if (priv->irq_mode & 1)
priv->virq_dma = ofdev->archdata.irqs[4];
else
priv->virq_dma = priv->irq_map[0];
REGSTORE(regs->ctrl, REGLOAD(regs->ctrl)|(priv->irq_mask&0xf));
}
err = request_irq(priv->virq_err, grpci2_err_interrupt, IRQF_SHARED,
"GRPCI2_ERR", priv);
if (err) {
printk(KERN_DEBUG "GRPCI2: ERR VIRQ request failed: %d\n", err);
goto err5;
}
REGSTORE(regs->ctrl, REGLOAD(regs->ctrl) | CTRL_EI | CTRL_SI);
priv->info.ops = &grpci2_ops;
priv->info.map_irq = grpci2_map_irq;
leon_pci_init(ofdev, &priv->info);
return 0;
err5:
release_resource(&priv->info.io_space);
err4:
release_resource(&priv->info.mem_space);
err3:
err = -ENOMEM;
iounmap((void __iomem *)priv->pci_io_va);
err2:
kfree(priv);
err1:
of_iounmap(&ofdev->resource[0], regs,
resource_size(&ofdev->resource[0]));
return err;
}
static int __init grpci2_init(void)
{
return platform_driver_register(&grpci2_of_driver);
}
