static void
sa1111_irq_handler(unsigned int irq, struct irq_desc *desc)
{
unsigned int stat0, stat1, i;
struct sa1111 *sachip = irq_get_handler_data(irq);
void __iomem *mapbase = sachip->base + SA1111_INTC;
stat0 = sa1111_readl(mapbase + SA1111_INTSTATCLR0);
stat1 = sa1111_readl(mapbase + SA1111_INTSTATCLR1);
sa1111_writel(stat0, mapbase + SA1111_INTSTATCLR0);
desc->irq_data.chip->irq_ack(&desc->irq_data);
sa1111_writel(stat1, mapbase + SA1111_INTSTATCLR1);
if (stat0 == 0 && stat1 == 0) {
do_bad_IRQ(irq, desc);
return;
}
for (i = 0; stat0; i++, stat0 >>= 1)
if (stat0 & 1)
generic_handle_irq(i + sachip->irq_base);
for (i = 32; stat1; i++, stat1 >>= 1)
if (stat1 & 1)
generic_handle_irq(i + sachip->irq_base);
desc->irq_data.chip->irq_unmask(&desc->irq_data);
}
static void sa1111_ack_irq(struct irq_data *d)
{
}
static void sa1111_mask_lowirq(struct irq_data *d)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned long ie0;
ie0 = sa1111_readl(mapbase + SA1111_INTEN0);
ie0 &= ~SA1111_IRQMASK_LO(d->irq);
writel(ie0, mapbase + SA1111_INTEN0);
}
static void sa1111_unmask_lowirq(struct irq_data *d)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned long ie0;
ie0 = sa1111_readl(mapbase + SA1111_INTEN0);
ie0 |= SA1111_IRQMASK_LO(d->irq);
sa1111_writel(ie0, mapbase + SA1111_INTEN0);
}
static int sa1111_retrigger_lowirq(struct irq_data *d)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned int mask = SA1111_IRQMASK_LO(d->irq);
unsigned long ip0;
int i;
ip0 = sa1111_readl(mapbase + SA1111_INTPOL0);
for (i = 0; i < 8; i++) {
sa1111_writel(ip0 ^ mask, mapbase + SA1111_INTPOL0);
sa1111_writel(ip0, mapbase + SA1111_INTPOL0);
if (sa1111_readl(mapbase + SA1111_INTSTATCLR0) & mask)
break;
}
if (i == 8)
printk(KERN_ERR "Danger Will Robinson: failed to "
"re-trigger IRQ%d\n", d->irq);
return i == 8 ? -1 : 0;
}
static int sa1111_type_lowirq(struct irq_data *d, unsigned int flags)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned int mask = SA1111_IRQMASK_LO(d->irq);
unsigned long ip0;
if (flags == IRQ_TYPE_PROBE)
return 0;
if ((!(flags & IRQ_TYPE_EDGE_RISING) ^ !(flags & IRQ_TYPE_EDGE_FALLING)) == 0)
return -EINVAL;
ip0 = sa1111_readl(mapbase + SA1111_INTPOL0);
if (flags & IRQ_TYPE_EDGE_RISING)
ip0 &= ~mask;
else
ip0 |= mask;
sa1111_writel(ip0, mapbase + SA1111_INTPOL0);
sa1111_writel(ip0, mapbase + SA1111_WAKEPOL0);
return 0;
}
static int sa1111_wake_lowirq(struct irq_data *d, unsigned int on)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned int mask = SA1111_IRQMASK_LO(d->irq);
unsigned long we0;
we0 = sa1111_readl(mapbase + SA1111_WAKEEN0);
if (on)
we0 |= mask;
else
we0 &= ~mask;
sa1111_writel(we0, mapbase + SA1111_WAKEEN0);
return 0;
}
static void sa1111_mask_highirq(struct irq_data *d)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned long ie1;
ie1 = sa1111_readl(mapbase + SA1111_INTEN1);
ie1 &= ~SA1111_IRQMASK_HI(d->irq);
sa1111_writel(ie1, mapbase + SA1111_INTEN1);
}
static void sa1111_unmask_highirq(struct irq_data *d)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned long ie1;
ie1 = sa1111_readl(mapbase + SA1111_INTEN1);
ie1 |= SA1111_IRQMASK_HI(d->irq);
sa1111_writel(ie1, mapbase + SA1111_INTEN1);
}
static int sa1111_retrigger_highirq(struct irq_data *d)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned int mask = SA1111_IRQMASK_HI(d->irq);
unsigned long ip1;
int i;
ip1 = sa1111_readl(mapbase + SA1111_INTPOL1);
for (i = 0; i < 8; i++) {
sa1111_writel(ip1 ^ mask, mapbase + SA1111_INTPOL1);
sa1111_writel(ip1, mapbase + SA1111_INTPOL1);
if (sa1111_readl(mapbase + SA1111_INTSTATCLR1) & mask)
break;
}
if (i == 8)
printk(KERN_ERR "Danger Will Robinson: failed to "
"re-trigger IRQ%d\n", d->irq);
return i == 8 ? -1 : 0;
}
static int sa1111_type_highirq(struct irq_data *d, unsigned int flags)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned int mask = SA1111_IRQMASK_HI(d->irq);
unsigned long ip1;
if (flags == IRQ_TYPE_PROBE)
return 0;
if ((!(flags & IRQ_TYPE_EDGE_RISING) ^ !(flags & IRQ_TYPE_EDGE_FALLING)) == 0)
return -EINVAL;
ip1 = sa1111_readl(mapbase + SA1111_INTPOL1);
if (flags & IRQ_TYPE_EDGE_RISING)
ip1 &= ~mask;
else
ip1 |= mask;
sa1111_writel(ip1, mapbase + SA1111_INTPOL1);
sa1111_writel(ip1, mapbase + SA1111_WAKEPOL1);
return 0;
}
static int sa1111_wake_highirq(struct irq_data *d, unsigned int on)
{
struct sa1111 *sachip = irq_data_get_irq_chip_data(d);
void __iomem *mapbase = sachip->base + SA1111_INTC;
unsigned int mask = SA1111_IRQMASK_HI(d->irq);
unsigned long we1;
we1 = sa1111_readl(mapbase + SA1111_WAKEEN1);
if (on)
we1 |= mask;
else
we1 &= ~mask;
sa1111_writel(we1, mapbase + SA1111_WAKEEN1);
return 0;
}
static int sa1111_setup_irq(struct sa1111 *sachip, unsigned irq_base)
{
void __iomem *irqbase = sachip->base + SA1111_INTC;
unsigned i, irq;
int ret;
request_mem_region(sachip->phys + SA1111_INTC, 512, "irq");
ret = irq_alloc_descs(-1, irq_base, SA1111_IRQ_NR, -1);
if (ret <= 0) {
dev_err(sachip->dev, "unable to allocate %u irqs: %d\n",
SA1111_IRQ_NR, ret);
if (ret == 0)
ret = -EINVAL;
return ret;
}
sachip->irq_base = ret;
sa1111_writel(0, irqbase + SA1111_INTEN0);
sa1111_writel(0, irqbase + SA1111_INTEN1);
sa1111_writel(0, irqbase + SA1111_WAKEEN0);
sa1111_writel(0, irqbase + SA1111_WAKEEN1);
sa1111_writel(0, irqbase + SA1111_INTPOL0);
sa1111_writel(SA1111_IRQMASK_HI(IRQ_S0_READY_NINT) |
SA1111_IRQMASK_HI(IRQ_S1_READY_NINT),
irqbase + SA1111_INTPOL1);
sa1111_writel(~0, irqbase + SA1111_INTSTATCLR0);
sa1111_writel(~0, irqbase + SA1111_INTSTATCLR1);
for (i = IRQ_GPAIN0; i <= SSPROR; i++) {
irq = sachip->irq_base + i;
irq_set_chip_and_handler(irq, &sa1111_low_chip,
handle_edge_irq);
irq_set_chip_data(irq, sachip);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
for (i = AUDXMTDMADONEA; i <= IRQ_S1_BVD1_STSCHG; i++) {
irq = sachip->irq_base + i;
irq_set_chip_and_handler(irq, &sa1111_high_chip,
handle_edge_irq);
irq_set_chip_data(irq, sachip);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
irq_set_irq_type(sachip->irq, IRQ_TYPE_EDGE_RISING);
irq_set_handler_data(sachip->irq, sachip);
irq_set_chained_handler(sachip->irq, sa1111_irq_handler);
dev_info(sachip->dev, "Providing IRQ%u-%u\n",
sachip->irq_base, sachip->irq_base + SA1111_IRQ_NR - 1);
return 0;
}
static void sa1111_wake(struct sa1111 *sachip)
{
unsigned long flags, r;
spin_lock_irqsave(&sachip->lock, flags);
clk_enable(sachip->clk);
r = sa1111_readl(sachip->base + SA1111_SKCR);
r &= ~SKCR_VCO_OFF;
sa1111_writel(r, sachip->base + SA1111_SKCR);
r |= SKCR_PLL_BYPASS | SKCR_OE_EN;
sa1111_writel(r, sachip->base + SA1111_SKCR);
udelay(100);
r |= SKCR_RCLKEN | SKCR_RDYEN;
sa1111_writel(r, sachip->base + SA1111_SKCR);
udelay(1);
sa1111_writel(0, sachip->base + SA1111_SKPCR);
spin_unlock_irqrestore(&sachip->lock, flags);
}
void
sa1111_configure_smc(struct sa1111 *sachip, int sdram, unsigned int drac,
unsigned int cas_latency)
{
unsigned int smcr = SMCR_DTIM | SMCR_MBGE | FInsrt(drac, SMCR_DRAC);
if (cas_latency == 3)
smcr |= SMCR_CLAT;
sa1111_writel(smcr, sachip->base + SA1111_SMCR);
if (sachip->dev->dma_mask)
*sachip->dev->dma_mask &= sa1111_dma_mask[drac >> 2];
sachip->dev->coherent_dma_mask &= sa1111_dma_mask[drac >> 2];
}
static void sa1111_dev_release(struct device *_dev)
{
struct sa1111_dev *dev = SA1111_DEV(_dev);
kfree(dev);
}
static int
sa1111_init_one_child(struct sa1111 *sachip, struct resource *parent,
struct sa1111_dev_info *info)
{
struct sa1111_dev *dev;
unsigned i;
int ret;
dev = kzalloc(sizeof(struct sa1111_dev), GFP_KERNEL);
if (!dev) {
ret = -ENOMEM;
goto err_alloc;
}
device_initialize(&dev->dev);
dev_set_name(&dev->dev, "%4.4lx", info->offset);
dev->devid = info->devid;
dev->dev.parent = sachip->dev;
dev->dev.bus = &sa1111_bus_type;
dev->dev.release = sa1111_dev_release;
dev->res.start = sachip->phys + info->offset;
dev->res.end = dev->res.start + 511;
dev->res.name = dev_name(&dev->dev);
dev->res.flags = IORESOURCE_MEM;
dev->mapbase = sachip->base + info->offset;
dev->skpcr_mask = info->skpcr_mask;
for (i = 0; i < ARRAY_SIZE(info->irq); i++)
dev->irq[i] = sachip->irq_base + info->irq[i];
if (info->dma && sachip->dev->dma_mask) {
dev->dma_mask = *sachip->dev->dma_mask;
dev->dev.dma_mask = &dev->dma_mask;
dev->dev.coherent_dma_mask = sachip->dev->coherent_dma_mask;
}
ret = request_resource(parent, &dev->res);
if (ret) {
dev_err(sachip->dev, "failed to allocate resource for %s\n",
dev->res.name);
goto err_resource;
}
ret = device_add(&dev->dev);
if (ret)
goto err_add;
return 0;
err_add:
release_resource(&dev->res);
err_resource:
put_device(&dev->dev);
err_alloc:
return ret;
}
static int __sa1111_probe(struct device *me, struct resource *mem, int irq)
{
struct sa1111_platform_data *pd = me->platform_data;
struct sa1111 *sachip;
unsigned long id;
unsigned int has_devs;
int i, ret = -ENODEV;
if (!pd)
return -EINVAL;
sachip = kzalloc(sizeof(struct sa1111), GFP_KERNEL);
if (!sachip)
return -ENOMEM;
sachip->clk = clk_get(me, "SA1111_CLK");
if (IS_ERR(sachip->clk)) {
ret = PTR_ERR(sachip->clk);
goto err_free;
}
ret = clk_prepare(sachip->clk);
if (ret)
goto err_clkput;
spin_lock_init(&sachip->lock);
sachip->dev = me;
dev_set_drvdata(sachip->dev, sachip);
sachip->pdata = pd;
sachip->phys = mem->start;
sachip->irq = irq;
sachip->base = ioremap(mem->start, PAGE_SIZE * 2);
if (!sachip->base) {
ret = -ENOMEM;
goto err_clk_unprep;
}
id = sa1111_readl(sachip->base + SA1111_SKID);
if ((id & SKID_ID_MASK) != SKID_SA1111_ID) {
printk(KERN_DEBUG "SA1111 not detected: ID = %08lx\n", id);
ret = -ENODEV;
goto err_unmap;
}
printk(KERN_INFO "SA1111 Microprocessor Companion Chip: "
"silicon revision %lx, metal revision %lx\n",
(id & SKID_SIREV_MASK)>>4, (id & SKID_MTREV_MASK));
sa1111_wake(sachip);
if (sachip->irq != NO_IRQ) {
ret = sa1111_setup_irq(sachip, pd->irq_base);
if (ret)
goto err_unmap;
}
#ifdef CONFIG_ARCH_SA1100
{
unsigned int val;
sa1111_configure_smc(sachip, 1,
FExtr(MDCNFG, MDCNFG_SA1110_DRAC0),
FExtr(MDCNFG, MDCNFG_SA1110_TDL0));
val = sa1111_readl(sachip->base + SA1111_SKPCR);
sa1111_writel(val | SKPCR_DCLKEN, sachip->base + SA1111_SKPCR);
sa1110_mb_enable();
}
#endif
g_sa1111 = sachip;
has_devs = ~0;
if (pd)
has_devs &= ~pd->disable_devs;
for (i = 0; i < ARRAY_SIZE(sa1111_devices); i++)
if (sa1111_devices[i].devid & has_devs)
sa1111_init_one_child(sachip, mem, &sa1111_devices[i]);
return 0;
err_unmap:
iounmap(sachip->base);
err_clk_unprep:
clk_unprepare(sachip->clk);
err_clkput:
clk_put(sachip->clk);
err_free:
kfree(sachip);
return ret;
}
static int sa1111_remove_one(struct device *dev, void *data)
{
struct sa1111_dev *sadev = SA1111_DEV(dev);
device_del(&sadev->dev);
release_resource(&sadev->res);
put_device(&sadev->dev);
return 0;
}
static void __sa1111_remove(struct sa1111 *sachip)
{
void __iomem *irqbase = sachip->base + SA1111_INTC;
device_for_each_child(sachip->dev, NULL, sa1111_remove_one);
sa1111_writel(0, irqbase + SA1111_INTEN0);
sa1111_writel(0, irqbase + SA1111_INTEN1);
sa1111_writel(0, irqbase + SA1111_WAKEEN0);
sa1111_writel(0, irqbase + SA1111_WAKEEN1);
clk_disable(sachip->clk);
clk_unprepare(sachip->clk);
if (sachip->irq != NO_IRQ) {
irq_set_chained_handler(sachip->irq, NULL);
irq_set_handler_data(sachip->irq, NULL);
irq_free_descs(sachip->irq_base, SA1111_IRQ_NR);
release_mem_region(sachip->phys + SA1111_INTC, 512);
}
iounmap(sachip->base);
clk_put(sachip->clk);
kfree(sachip);
}
static int sa1111_suspend(struct platform_device *dev, pm_message_t state)
{
struct sa1111 *sachip = platform_get_drvdata(dev);
struct sa1111_save_data *save;
unsigned long flags;
unsigned int val;
void __iomem *base;
save = kmalloc(sizeof(struct sa1111_save_data), GFP_KERNEL);
if (!save)
return -ENOMEM;
sachip->saved_state = save;
spin_lock_irqsave(&sachip->lock, flags);
base = sachip->base;
save->skcr = sa1111_readl(base + SA1111_SKCR);
save->skpcr = sa1111_readl(base + SA1111_SKPCR);
save->skcdr = sa1111_readl(base + SA1111_SKCDR);
save->skaud = sa1111_readl(base + SA1111_SKAUD);
save->skpwm0 = sa1111_readl(base + SA1111_SKPWM0);
save->skpwm1 = sa1111_readl(base + SA1111_SKPWM1);
sa1111_writel(0, sachip->base + SA1111_SKPWM0);
sa1111_writel(0, sachip->base + SA1111_SKPWM1);
base = sachip->base + SA1111_INTC;
save->intpol0 = sa1111_readl(base + SA1111_INTPOL0);
save->intpol1 = sa1111_readl(base + SA1111_INTPOL1);
save->inten0 = sa1111_readl(base + SA1111_INTEN0);
save->inten1 = sa1111_readl(base + SA1111_INTEN1);
save->wakepol0 = sa1111_readl(base + SA1111_WAKEPOL0);
save->wakepol1 = sa1111_readl(base + SA1111_WAKEPOL1);
save->wakeen0 = sa1111_readl(base + SA1111_WAKEEN0);
save->wakeen1 = sa1111_readl(base + SA1111_WAKEEN1);
val = sa1111_readl(sachip->base + SA1111_SKCR);
sa1111_writel(val | SKCR_SLEEP, sachip->base + SA1111_SKCR);
clk_disable(sachip->clk);
spin_unlock_irqrestore(&sachip->lock, flags);
#ifdef CONFIG_ARCH_SA1100
sa1110_mb_disable();
#endif
return 0;
}
static int sa1111_resume(struct platform_device *dev)
{
struct sa1111 *sachip = platform_get_drvdata(dev);
struct sa1111_save_data *save;
unsigned long flags, id;
void __iomem *base;
save = sachip->saved_state;
if (!save)
return 0;
id = sa1111_readl(sachip->base + SA1111_SKID);
if ((id & SKID_ID_MASK) != SKID_SA1111_ID) {
__sa1111_remove(sachip);
platform_set_drvdata(dev, NULL);
kfree(save);
return 0;
}
sa1111_wake(sachip);
#ifdef CONFIG_ARCH_SA1100
sa1110_mb_enable();
#endif
spin_lock_irqsave(&sachip->lock, flags);
sa1111_writel(0, sachip->base + SA1111_INTC + SA1111_INTEN0);
sa1111_writel(0, sachip->base + SA1111_INTC + SA1111_INTEN1);
base = sachip->base;
sa1111_writel(save->skcr, base + SA1111_SKCR);
sa1111_writel(save->skpcr, base + SA1111_SKPCR);
sa1111_writel(save->skcdr, base + SA1111_SKCDR);
sa1111_writel(save->skaud, base + SA1111_SKAUD);
sa1111_writel(save->skpwm0, base + SA1111_SKPWM0);
sa1111_writel(save->skpwm1, base + SA1111_SKPWM1);
base = sachip->base + SA1111_INTC;
sa1111_writel(save->intpol0, base + SA1111_INTPOL0);
sa1111_writel(save->intpol1, base + SA1111_INTPOL1);
sa1111_writel(save->inten0, base + SA1111_INTEN0);
sa1111_writel(save->inten1, base + SA1111_INTEN1);
sa1111_writel(save->wakepol0, base + SA1111_WAKEPOL0);
sa1111_writel(save->wakepol1, base + SA1111_WAKEPOL1);
sa1111_writel(save->wakeen0, base + SA1111_WAKEEN0);
sa1111_writel(save->wakeen1, base + SA1111_WAKEEN1);
spin_unlock_irqrestore(&sachip->lock, flags);
sachip->saved_state = NULL;
kfree(save);
return 0;
}
static int sa1111_probe(struct platform_device *pdev)
{
struct resource *mem;
int irq;
mem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!mem)
return -EINVAL;
irq = platform_get_irq(pdev, 0);
if (irq < 0)
return -ENXIO;
return __sa1111_probe(&pdev->dev, mem, irq);
}
static int sa1111_remove(struct platform_device *pdev)
{
struct sa1111 *sachip = platform_get_drvdata(pdev);
if (sachip) {
#ifdef CONFIG_PM
kfree(sachip->saved_state);
sachip->saved_state = NULL;
#endif
__sa1111_remove(sachip);
platform_set_drvdata(pdev, NULL);
}
return 0;
}
static inline struct sa1111 *sa1111_chip_driver(struct sa1111_dev *sadev)
{
return (struct sa1111 *)dev_get_drvdata(sadev->dev.parent);
}
static unsigned int __sa1111_pll_clock(struct sa1111 *sachip)
{
unsigned int skcdr, fbdiv, ipdiv, opdiv;
skcdr = sa1111_readl(sachip->base + SA1111_SKCDR);
fbdiv = (skcdr & 0x007f) + 2;
ipdiv = ((skcdr & 0x0f80) >> 7) + 2;
opdiv = opdiv_table[(skcdr & 0x3000) >> 12];
return 3686400 * fbdiv / (ipdiv * opdiv);
}
unsigned int sa1111_pll_clock(struct sa1111_dev *sadev)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
return __sa1111_pll_clock(sachip);
}
void sa1111_select_audio_mode(struct sa1111_dev *sadev, int mode)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
unsigned long flags;
unsigned int val;
spin_lock_irqsave(&sachip->lock, flags);
val = sa1111_readl(sachip->base + SA1111_SKCR);
if (mode == SA1111_AUDIO_I2S) {
val &= ~SKCR_SELAC;
} else {
val |= SKCR_SELAC;
}
sa1111_writel(val, sachip->base + SA1111_SKCR);
spin_unlock_irqrestore(&sachip->lock, flags);
}
int sa1111_set_audio_rate(struct sa1111_dev *sadev, int rate)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
unsigned int div;
if (sadev->devid != SA1111_DEVID_SAC)
return -EINVAL;
div = (__sa1111_pll_clock(sachip) / 256 + rate / 2) / rate;
if (div == 0)
div = 1;
if (div > 128)
div = 128;
sa1111_writel(div - 1, sachip->base + SA1111_SKAUD);
return 0;
}
int sa1111_get_audio_rate(struct sa1111_dev *sadev)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
unsigned long div;
if (sadev->devid != SA1111_DEVID_SAC)
return -EINVAL;
div = sa1111_readl(sachip->base + SA1111_SKAUD) + 1;
return __sa1111_pll_clock(sachip) / (256 * div);
}
void sa1111_set_io_dir(struct sa1111_dev *sadev,
unsigned int bits, unsigned int dir,
unsigned int sleep_dir)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
unsigned long flags;
unsigned int val;
void __iomem *gpio = sachip->base + SA1111_GPIO;
#define MODIFY_BITS(port, mask, dir) \
if (mask) { \
val = sa1111_readl(port); \
val &= ~(mask); \
val |= (dir) & (mask); \
sa1111_writel(val, port); \
}
spin_lock_irqsave(&sachip->lock, flags);
MODIFY_BITS(gpio + SA1111_GPIO_PADDR, bits & 15, dir);
MODIFY_BITS(gpio + SA1111_GPIO_PBDDR, (bits >> 8) & 255, dir >> 8);
MODIFY_BITS(gpio + SA1111_GPIO_PCDDR, (bits >> 16) & 255, dir >> 16);
MODIFY_BITS(gpio + SA1111_GPIO_PASDR, bits & 15, sleep_dir);
MODIFY_BITS(gpio + SA1111_GPIO_PBSDR, (bits >> 8) & 255, sleep_dir >> 8);
MODIFY_BITS(gpio + SA1111_GPIO_PCSDR, (bits >> 16) & 255, sleep_dir >> 16);
spin_unlock_irqrestore(&sachip->lock, flags);
}
void sa1111_set_io(struct sa1111_dev *sadev, unsigned int bits, unsigned int v)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
unsigned long flags;
unsigned int val;
void __iomem *gpio = sachip->base + SA1111_GPIO;
spin_lock_irqsave(&sachip->lock, flags);
MODIFY_BITS(gpio + SA1111_GPIO_PADWR, bits & 15, v);
MODIFY_BITS(gpio + SA1111_GPIO_PBDWR, (bits >> 8) & 255, v >> 8);
MODIFY_BITS(gpio + SA1111_GPIO_PCDWR, (bits >> 16) & 255, v >> 16);
spin_unlock_irqrestore(&sachip->lock, flags);
}
void sa1111_set_sleep_io(struct sa1111_dev *sadev, unsigned int bits, unsigned int v)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
unsigned long flags;
unsigned int val;
void __iomem *gpio = sachip->base + SA1111_GPIO;
spin_lock_irqsave(&sachip->lock, flags);
MODIFY_BITS(gpio + SA1111_GPIO_PASSR, bits & 15, v);
MODIFY_BITS(gpio + SA1111_GPIO_PBSSR, (bits >> 8) & 255, v >> 8);
MODIFY_BITS(gpio + SA1111_GPIO_PCSSR, (bits >> 16) & 255, v >> 16);
spin_unlock_irqrestore(&sachip->lock, flags);
}
int sa1111_enable_device(struct sa1111_dev *sadev)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
unsigned long flags;
unsigned int val;
int ret = 0;
if (sachip->pdata && sachip->pdata->enable)
ret = sachip->pdata->enable(sachip->pdata->data, sadev->devid);
if (ret == 0) {
spin_lock_irqsave(&sachip->lock, flags);
val = sa1111_readl(sachip->base + SA1111_SKPCR);
sa1111_writel(val | sadev->skpcr_mask, sachip->base + SA1111_SKPCR);
spin_unlock_irqrestore(&sachip->lock, flags);
}
return ret;
}
void sa1111_disable_device(struct sa1111_dev *sadev)
{
struct sa1111 *sachip = sa1111_chip_driver(sadev);
unsigned long flags;
unsigned int val;
spin_lock_irqsave(&sachip->lock, flags);
val = sa1111_readl(sachip->base + SA1111_SKPCR);
sa1111_writel(val & ~sadev->skpcr_mask, sachip->base + SA1111_SKPCR);
spin_unlock_irqrestore(&sachip->lock, flags);
if (sachip->pdata && sachip->pdata->disable)
sachip->pdata->disable(sachip->pdata->data, sadev->devid);
}
static int sa1111_match(struct device *_dev, struct device_driver *_drv)
{
struct sa1111_dev *dev = SA1111_DEV(_dev);
struct sa1111_driver *drv = SA1111_DRV(_drv);
return dev->devid & drv->devid;
}
static int sa1111_bus_suspend(struct device *dev, pm_message_t state)
{
struct sa1111_dev *sadev = SA1111_DEV(dev);
struct sa1111_driver *drv = SA1111_DRV(dev->driver);
int ret = 0;
if (drv && drv->suspend)
ret = drv->suspend(sadev, state);
return ret;
}
static int sa1111_bus_resume(struct device *dev)
{
struct sa1111_dev *sadev = SA1111_DEV(dev);
struct sa1111_driver *drv = SA1111_DRV(dev->driver);
int ret = 0;
if (drv && drv->resume)
ret = drv->resume(sadev);
return ret;
}
static void sa1111_bus_shutdown(struct device *dev)
{
struct sa1111_driver *drv = SA1111_DRV(dev->driver);
if (drv && drv->shutdown)
drv->shutdown(SA1111_DEV(dev));
}
static int sa1111_bus_probe(struct device *dev)
{
struct sa1111_dev *sadev = SA1111_DEV(dev);
struct sa1111_driver *drv = SA1111_DRV(dev->driver);
int ret = -ENODEV;
if (drv->probe)
ret = drv->probe(sadev);
return ret;
}
static int sa1111_bus_remove(struct device *dev)
{
struct sa1111_dev *sadev = SA1111_DEV(dev);
struct sa1111_driver *drv = SA1111_DRV(dev->driver);
int ret = 0;
if (drv->remove)
ret = drv->remove(sadev);
return ret;
}
int sa1111_driver_register(struct sa1111_driver *driver)
{
driver->drv.bus = &sa1111_bus_type;
return driver_register(&driver->drv);
}
void sa1111_driver_unregister(struct sa1111_driver *driver)
{
driver_unregister(&driver->drv);
}
static int sa1111_needs_bounce(struct device *dev, dma_addr_t addr, size_t size)
{
return (machine_is_assabet() || machine_is_pfs168()) &&
(addr >= 0xc8000000 || (addr + size) >= 0xc8000000);
}
static int sa1111_notifier_call(struct notifier_block *n, unsigned long action,
void *data)
{
struct sa1111_dev *dev = SA1111_DEV(data);
switch (action) {
case BUS_NOTIFY_ADD_DEVICE:
if (dev->dev.dma_mask && dev->dma_mask < 0xffffffffUL) {
int ret = dmabounce_register_dev(&dev->dev, 1024, 4096,
sa1111_needs_bounce);
if (ret)
dev_err(&dev->dev, "failed to register with dmabounce: %d\n", ret);
}
break;
case BUS_NOTIFY_DEL_DEVICE:
if (dev->dev.dma_mask && dev->dma_mask < 0xffffffffUL)
dmabounce_unregister_dev(&dev->dev);
break;
}
return NOTIFY_OK;
}
static int __init sa1111_init(void)
{
int ret = bus_register(&sa1111_bus_type);
#ifdef CONFIG_DMABOUNCE
if (ret == 0)
bus_register_notifier(&sa1111_bus_type, &sa1111_bus_notifier);
#endif
if (ret == 0)
platform_driver_register(&sa1111_device_driver);
return ret;
}
static void __exit sa1111_exit(void)
{
platform_driver_unregister(&sa1111_device_driver);
#ifdef CONFIG_DMABOUNCE
bus_unregister_notifier(&sa1111_bus_type, &sa1111_bus_notifier);
#endif
bus_unregister(&sa1111_bus_type);
}
