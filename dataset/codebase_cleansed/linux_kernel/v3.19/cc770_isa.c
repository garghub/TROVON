static u8 cc770_isa_mem_read_reg(const struct cc770_priv *priv, int reg)
{
return readb(priv->reg_base + reg);
}
static void cc770_isa_mem_write_reg(const struct cc770_priv *priv,
int reg, u8 val)
{
writeb(val, priv->reg_base + reg);
}
static u8 cc770_isa_port_read_reg(const struct cc770_priv *priv, int reg)
{
return inb((unsigned long)priv->reg_base + reg);
}
static void cc770_isa_port_write_reg(const struct cc770_priv *priv,
int reg, u8 val)
{
outb(val, (unsigned long)priv->reg_base + reg);
}
static u8 cc770_isa_port_read_reg_indirect(const struct cc770_priv *priv,
int reg)
{
unsigned long base = (unsigned long)priv->reg_base;
unsigned long flags;
u8 val;
spin_lock_irqsave(&cc770_isa_port_lock, flags);
outb(reg, base);
val = inb(base + 1);
spin_unlock_irqrestore(&cc770_isa_port_lock, flags);
return val;
}
static void cc770_isa_port_write_reg_indirect(const struct cc770_priv *priv,
int reg, u8 val)
{
unsigned long base = (unsigned long)priv->reg_base;
unsigned long flags;
spin_lock_irqsave(&cc770_isa_port_lock, flags);
outb(reg, base);
outb(val, base + 1);
spin_unlock_irqrestore(&cc770_isa_port_lock, flags);
}
static int cc770_isa_probe(struct platform_device *pdev)
{
struct net_device *dev;
struct cc770_priv *priv;
void __iomem *base = NULL;
int iosize = CC770_IOSIZE;
int idx = pdev->id;
int err;
u32 clktmp;
dev_dbg(&pdev->dev, "probing idx=%d: port=%#lx, mem=%#lx, irq=%d\n",
idx, port[idx], mem[idx], irq[idx]);
if (mem[idx]) {
if (!request_mem_region(mem[idx], iosize, KBUILD_MODNAME)) {
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
iosize = CC770_IOSIZE_INDIRECT;
if (!request_region(port[idx], iosize, KBUILD_MODNAME)) {
err = -EBUSY;
goto exit;
}
}
dev = alloc_cc770dev(0);
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
priv->read_reg = cc770_isa_mem_read_reg;
priv->write_reg = cc770_isa_mem_write_reg;
} else {
priv->reg_base = (void __iomem *)port[idx];
dev->base_addr = port[idx];
if (iosize == CC770_IOSIZE_INDIRECT) {
priv->read_reg = cc770_isa_port_read_reg_indirect;
priv->write_reg = cc770_isa_port_write_reg_indirect;
} else {
priv->read_reg = cc770_isa_port_read_reg;
priv->write_reg = cc770_isa_port_write_reg;
}
}
if (clk[idx])
clktmp = clk[idx];
else if (clk[0])
clktmp = clk[0];
else
clktmp = CLK_DEFAULT;
priv->can.clock.freq = clktmp;
if (cir[idx] != 0xff) {
priv->cpu_interface = cir[idx];
} else if (cir[0] != 0xff) {
priv->cpu_interface = cir[0];
} else {
if (clktmp > 10000000) {
priv->cpu_interface |= CPUIF_DSC;
clktmp /= 2;
}
if (clktmp > 8000000)
priv->cpu_interface |= CPUIF_DMC;
}
if (priv->cpu_interface & CPUIF_DSC)
priv->can.clock.freq /= 2;
if (bcr[idx] != 0xff)
priv->bus_config = bcr[idx];
else if (bcr[0] != 0xff)
priv->bus_config = bcr[0];
else
priv->bus_config = BCR_DEFAULT;
if (cor[idx] != 0xff)
priv->clkout = cor[idx];
else if (cor[0] != 0xff)
priv->clkout = cor[0];
else
priv->clkout = COR_DEFAULT;
platform_set_drvdata(pdev, dev);
SET_NETDEV_DEV(dev, &pdev->dev);
err = register_cc770dev(dev);
if (err) {
dev_err(&pdev->dev,
"couldn't register device (err=%d)\n", err);
goto exit_unmap;
}
dev_info(&pdev->dev, "device registered (reg_base=0x%p, irq=%d)\n",
priv->reg_base, dev->irq);
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
static int cc770_isa_remove(struct platform_device *pdev)
{
struct net_device *dev = platform_get_drvdata(pdev);
struct cc770_priv *priv = netdev_priv(dev);
int idx = pdev->id;
unregister_cc770dev(dev);
if (mem[idx]) {
iounmap(priv->reg_base);
release_mem_region(mem[idx], CC770_IOSIZE);
} else {
if (priv->read_reg == cc770_isa_port_read_reg_indirect)
release_region(port[idx], CC770_IOSIZE_INDIRECT);
else
release_region(port[idx], CC770_IOSIZE);
}
free_cc770dev(dev);
return 0;
}
static int __init cc770_isa_init(void)
{
int idx, err;
for (idx = 0; idx < ARRAY_SIZE(cc770_isa_devs); idx++) {
if ((port[idx] || mem[idx]) && irq[idx]) {
cc770_isa_devs[idx] =
platform_device_alloc(KBUILD_MODNAME, idx);
if (!cc770_isa_devs[idx]) {
err = -ENOMEM;
goto exit_free_devices;
}
err = platform_device_add(cc770_isa_devs[idx]);
if (err) {
platform_device_put(cc770_isa_devs[idx]);
goto exit_free_devices;
}
pr_debug("platform device %d: port=%#lx, mem=%#lx, "
"irq=%d\n",
idx, port[idx], mem[idx], irq[idx]);
} else if (idx == 0 || port[idx] || mem[idx]) {
pr_err("insufficient parameters supplied\n");
err = -EINVAL;
goto exit_free_devices;
}
}
err = platform_driver_register(&cc770_isa_driver);
if (err)
goto exit_free_devices;
pr_info("driver for max. %d devices registered\n", MAXDEV);
return 0;
exit_free_devices:
while (--idx >= 0) {
if (cc770_isa_devs[idx])
platform_device_unregister(cc770_isa_devs[idx]);
}
return err;
}
static void __exit cc770_isa_exit(void)
{
int idx;
platform_driver_unregister(&cc770_isa_driver);
for (idx = 0; idx < ARRAY_SIZE(cc770_isa_devs); idx++) {
if (cc770_isa_devs[idx])
platform_device_unregister(cc770_isa_devs[idx]);
}
}
