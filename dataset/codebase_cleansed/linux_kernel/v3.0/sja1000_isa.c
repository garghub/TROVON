static u8 sja1000_isa_mem_read_reg(const struct sja1000_priv *priv, int reg)
{
return readb(priv->reg_base + reg);
}
static void sja1000_isa_mem_write_reg(const struct sja1000_priv *priv,
int reg, u8 val)
{
writeb(val, priv->reg_base + reg);
}
static u8 sja1000_isa_port_read_reg(const struct sja1000_priv *priv, int reg)
{
return inb((unsigned long)priv->reg_base + reg);
}
static void sja1000_isa_port_write_reg(const struct sja1000_priv *priv,
int reg, u8 val)
{
outb(val, (unsigned long)priv->reg_base + reg);
}
static u8 sja1000_isa_port_read_reg_indirect(const struct sja1000_priv *priv,
int reg)
{
unsigned long base = (unsigned long)priv->reg_base;
outb(reg, base);
return inb(base + 1);
}
static void sja1000_isa_port_write_reg_indirect(const struct sja1000_priv *priv,
int reg, u8 val)
{
unsigned long base = (unsigned long)priv->reg_base;
outb(reg, base);
outb(val, base + 1);
}
static int __devinit sja1000_isa_match(struct device *pdev, unsigned int idx)
{
if (port[idx] || mem[idx]) {
if (irq[idx])
return 1;
} else if (idx)
return 0;
dev_err(pdev, "insufficient parameters supplied\n");
return 0;
}
static int __devinit sja1000_isa_probe(struct device *pdev, unsigned int idx)
{
struct net_device *dev;
struct sja1000_priv *priv;
void __iomem *base = NULL;
int iosize = SJA1000_IOSIZE;
int err;
if (mem[idx]) {
if (!request_mem_region(mem[idx], iosize, DRV_NAME)) {
err = -EBUSY;
goto exit;
}
base = ioremap_nocache(mem[idx], iosize);
if (!base) {
err = -ENOMEM;
goto exit_release;
}
} else {
if (indirect[idx] > 0 ||
(indirect[idx] == -1 && indirect[0] > 0))
iosize = SJA1000_IOSIZE_INDIRECT;
if (!request_region(port[idx], iosize, DRV_NAME)) {
err = -EBUSY;
goto exit;
}
}
dev = alloc_sja1000dev(0);
if (!dev) {
err = -ENOMEM;
goto exit_unmap;
}
priv = netdev_priv(dev);
dev->irq = irq[idx];
priv->irq_flags = IRQF_SHARED;
if (mem[idx]) {
priv->reg_base = base;
dev->base_addr = mem[idx];
priv->read_reg = sja1000_isa_mem_read_reg;
priv->write_reg = sja1000_isa_mem_write_reg;
} else {
priv->reg_base = (void __iomem *)port[idx];
dev->base_addr = port[idx];
if (iosize == SJA1000_IOSIZE_INDIRECT) {
priv->read_reg = sja1000_isa_port_read_reg_indirect;
priv->write_reg = sja1000_isa_port_write_reg_indirect;
} else {
priv->read_reg = sja1000_isa_port_read_reg;
priv->write_reg = sja1000_isa_port_write_reg;
}
}
if (clk[idx])
priv->can.clock.freq = clk[idx] / 2;
else if (clk[0])
priv->can.clock.freq = clk[0] / 2;
else
priv->can.clock.freq = CLK_DEFAULT / 2;
if (ocr[idx] != -1)
priv->ocr = ocr[idx] & 0xff;
else if (ocr[0] != -1)
priv->ocr = ocr[0] & 0xff;
else
priv->ocr = OCR_DEFAULT;
if (cdr[idx] != -1)
priv->cdr = cdr[idx] & 0xff;
else if (cdr[0] != -1)
priv->cdr = cdr[0] & 0xff;
else
priv->cdr = CDR_DEFAULT;
dev_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, pdev);
err = register_sja1000dev(dev);
if (err) {
dev_err(pdev, "registering %s failed (err=%d)\n",
DRV_NAME, err);
goto exit_unmap;
}
dev_info(pdev, "%s device registered (reg_base=0x%p, irq=%d)\n",
DRV_NAME, priv->reg_base, dev->irq);
return 0;
exit_unmap:
if (mem[idx])
iounmap(base);
exit_release:
if (mem[idx])
release_mem_region(mem[idx], iosize);
else
release_region(port[idx], iosize);
exit:
return err;
}
static int __devexit sja1000_isa_remove(struct device *pdev, unsigned int idx)
{
struct net_device *dev = dev_get_drvdata(pdev);
struct sja1000_priv *priv = netdev_priv(dev);
unregister_sja1000dev(dev);
dev_set_drvdata(pdev, NULL);
if (mem[idx]) {
iounmap(priv->reg_base);
release_mem_region(mem[idx], SJA1000_IOSIZE);
} else {
if (priv->read_reg == sja1000_isa_port_read_reg_indirect)
release_region(port[idx], SJA1000_IOSIZE_INDIRECT);
else
release_region(port[idx], SJA1000_IOSIZE);
}
free_sja1000dev(dev);
return 0;
}
static int __init sja1000_isa_init(void)
{
int err = isa_register_driver(&sja1000_isa_driver, MAXDEV);
if (!err)
printk(KERN_INFO
"Legacy %s driver for max. %d devices registered\n",
DRV_NAME, MAXDEV);
return err;
}
static void __exit sja1000_isa_exit(void)
{
isa_unregister_driver(&sja1000_isa_driver);
}
