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
static int sja1000_isa_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct sja1000_priv *priv;
void __iomem *base = NULL;
int iosize = SJA1000_IOSIZE;
int idx = pdev->id;
int err;
dev_dbg(&pdev->dev, "probing idx=%d: port=%#lx, mem=%#lx, irq=%d\n",
idx, port[idx], mem[idx], irq[idx]);
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
if (ocr[idx] != 0xff)
priv->ocr = ocr[idx];
else if (ocr[0] != 0xff)
priv->ocr = ocr[0];
else
priv->ocr = OCR_DEFAULT;
if (cdr[idx] != 0xff)
priv->cdr = cdr[idx];
else if (cdr[0] != 0xff)
priv->cdr = cdr[0];
else
priv->cdr = CDR_DEFAULT;
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_sja1000dev(dev);
if (err) {
dev_err(&pdev->dev, "registering %s failed (err=%d)\n",
DRV_NAME, err);
goto exit_unmap;
}
dev_info(&pdev->dev, "%s device registered (reg_base=0x%p, irq=%d)\n",
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
static int sja1000_isa_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct sja1000_priv *priv = netdev_priv(dev);
int idx = pdev->id;
unregister_sja1000dev(dev);
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
int idx, err;
for (idx = 0; idx < MAXDEV; idx++) {
if ((port[idx] || mem[idx]) && irq[idx]) {
sja1000_isa_devs[idx] =
platform_device_alloc(DRV_NAME, idx);
if (!sja1000_isa_devs[idx]) {
err = -ENOMEM;
goto exit_free_devices;
}
err = platform_device_add(sja1000_isa_devs[idx]);
if (err) {
platform_device_put(sja1000_isa_devs[idx]);
goto exit_free_devices;
}
pr_debug("%s: platform device %d: port=%#lx, mem=%#lx, "
"irq=%d\n",
DRV_NAME, idx, port[idx], mem[idx], irq[idx]);
} else if (idx == 0 || port[idx] || mem[idx]) {
pr_err("%s: insufficient parameters supplied\n",
DRV_NAME);
err = -EINVAL;
goto exit_free_devices;
}
}
err = platform_driver_register(&sja1000_isa_driver);
if (err)
goto exit_free_devices;
pr_info("Legacy %s driver for max. %d devices registered\n",
DRV_NAME, MAXDEV);
return 0;
exit_free_devices:
while (--idx >= 0) {
if (sja1000_isa_devs[idx])
platform_device_unregister(sja1000_isa_devs[idx]);
}
return err;
}
static void __exit sja1000_isa_exit(void)
{
int idx;
platform_driver_unregister(&sja1000_isa_driver);
for (idx = 0; idx < MAXDEV; idx++) {
if (sja1000_isa_devs[idx])
platform_device_unregister(sja1000_isa_devs[idx]);
}
}
