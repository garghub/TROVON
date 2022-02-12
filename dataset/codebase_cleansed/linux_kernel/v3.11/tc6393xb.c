static int tc6393xb_nand_enable(struct platform_device *nand)
{
struct platform_device *dev = to_platform_device(nand->dev.parent);
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&tc6393xb->lock, flags);
dev_dbg(&dev->dev, "SMD buffer on\n");
tmio_iowrite8(0xff, tc6393xb->scr + SCR_GPI_BCR(1));
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
static int tc6393xb_ohci_enable(struct platform_device *dev)
{
struct tc6393xb *tc6393xb = dev_get_drvdata(dev->dev.parent);
unsigned long flags;
u16 ccr;
u8 fer;
spin_lock_irqsave(&tc6393xb->lock, flags);
ccr = tmio_ioread16(tc6393xb->scr + SCR_CCR);
ccr |= SCR_CCR_USBCK;
tmio_iowrite16(ccr, tc6393xb->scr + SCR_CCR);
fer = tmio_ioread8(tc6393xb->scr + SCR_FER);
fer |= SCR_FER_USBEN;
tmio_iowrite8(fer, tc6393xb->scr + SCR_FER);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
static int tc6393xb_ohci_disable(struct platform_device *dev)
{
struct tc6393xb *tc6393xb = dev_get_drvdata(dev->dev.parent);
unsigned long flags;
u16 ccr;
u8 fer;
spin_lock_irqsave(&tc6393xb->lock, flags);
fer = tmio_ioread8(tc6393xb->scr + SCR_FER);
fer &= ~SCR_FER_USBEN;
tmio_iowrite8(fer, tc6393xb->scr + SCR_FER);
ccr = tmio_ioread16(tc6393xb->scr + SCR_CCR);
ccr &= ~SCR_CCR_USBCK;
tmio_iowrite16(ccr, tc6393xb->scr + SCR_CCR);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
static int tc6393xb_fb_enable(struct platform_device *dev)
{
struct tc6393xb *tc6393xb = dev_get_drvdata(dev->dev.parent);
unsigned long flags;
u16 ccr;
spin_lock_irqsave(&tc6393xb->lock, flags);
ccr = tmio_ioread16(tc6393xb->scr + SCR_CCR);
ccr &= ~SCR_CCR_MCLK_MASK;
ccr |= SCR_CCR_MCLK_48;
tmio_iowrite16(ccr, tc6393xb->scr + SCR_CCR);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
static int tc6393xb_fb_disable(struct platform_device *dev)
{
struct tc6393xb *tc6393xb = dev_get_drvdata(dev->dev.parent);
unsigned long flags;
u16 ccr;
spin_lock_irqsave(&tc6393xb->lock, flags);
ccr = tmio_ioread16(tc6393xb->scr + SCR_CCR);
ccr &= ~SCR_CCR_MCLK_MASK;
ccr |= SCR_CCR_MCLK_OFF;
tmio_iowrite16(ccr, tc6393xb->scr + SCR_CCR);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
int tc6393xb_lcd_set_power(struct platform_device *fb, bool on)
{
struct platform_device *dev = to_platform_device(fb->dev.parent);
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
u8 fer;
unsigned long flags;
spin_lock_irqsave(&tc6393xb->lock, flags);
fer = ioread8(tc6393xb->scr + SCR_FER);
if (on)
fer |= SCR_FER_SLCDEN;
else
fer &= ~SCR_FER_SLCDEN;
iowrite8(fer, tc6393xb->scr + SCR_FER);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
int tc6393xb_lcd_mode(struct platform_device *fb,
const struct fb_videomode *mode) {
struct platform_device *dev = to_platform_device(fb->dev.parent);
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
unsigned long flags;
spin_lock_irqsave(&tc6393xb->lock, flags);
iowrite16(mode->pixclock, tc6393xb->scr + SCR_PLL1CR + 0);
iowrite16(mode->pixclock >> 16, tc6393xb->scr + SCR_PLL1CR + 2);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
static int tc6393xb_mmc_enable(struct platform_device *mmc)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
tmio_core_mmc_enable(tc6393xb->scr + 0x200, 0,
tc6393xb_mmc_resources[0].start & 0xfffe);
return 0;
}
static int tc6393xb_mmc_resume(struct platform_device *mmc)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
tmio_core_mmc_resume(tc6393xb->scr + 0x200, 0,
tc6393xb_mmc_resources[0].start & 0xfffe);
return 0;
}
static void tc6393xb_mmc_pwr(struct platform_device *mmc, int state)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
tmio_core_mmc_pwr(tc6393xb->scr + 0x200, 0, state);
}
static void tc6393xb_mmc_clk_div(struct platform_device *mmc, int state)
{
struct platform_device *dev = to_platform_device(mmc->dev.parent);
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
tmio_core_mmc_clk_div(tc6393xb->scr + 0x200, 0, state);
}
static int tc6393xb_gpio_get(struct gpio_chip *chip,
unsigned offset)
{
struct tc6393xb *tc6393xb = container_of(chip, struct tc6393xb, gpio);
return tmio_ioread8(tc6393xb->scr + SCR_GPO_DSR(offset / 8))
& TC_GPIO_BIT(offset);
}
static void __tc6393xb_gpio_set(struct gpio_chip *chip,
unsigned offset, int value)
{
struct tc6393xb *tc6393xb = container_of(chip, struct tc6393xb, gpio);
u8 dsr;
dsr = tmio_ioread8(tc6393xb->scr + SCR_GPO_DSR(offset / 8));
if (value)
dsr |= TC_GPIO_BIT(offset);
else
dsr &= ~TC_GPIO_BIT(offset);
tmio_iowrite8(dsr, tc6393xb->scr + SCR_GPO_DSR(offset / 8));
}
static void tc6393xb_gpio_set(struct gpio_chip *chip,
unsigned offset, int value)
{
struct tc6393xb *tc6393xb = container_of(chip, struct tc6393xb, gpio);
unsigned long flags;
spin_lock_irqsave(&tc6393xb->lock, flags);
__tc6393xb_gpio_set(chip, offset, value);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
}
static int tc6393xb_gpio_direction_input(struct gpio_chip *chip,
unsigned offset)
{
struct tc6393xb *tc6393xb = container_of(chip, struct tc6393xb, gpio);
unsigned long flags;
u8 doecr;
spin_lock_irqsave(&tc6393xb->lock, flags);
doecr = tmio_ioread8(tc6393xb->scr + SCR_GPO_DOECR(offset / 8));
doecr &= ~TC_GPIO_BIT(offset);
tmio_iowrite8(doecr, tc6393xb->scr + SCR_GPO_DOECR(offset / 8));
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
static int tc6393xb_gpio_direction_output(struct gpio_chip *chip,
unsigned offset, int value)
{
struct tc6393xb *tc6393xb = container_of(chip, struct tc6393xb, gpio);
unsigned long flags;
u8 doecr;
spin_lock_irqsave(&tc6393xb->lock, flags);
__tc6393xb_gpio_set(chip, offset, value);
doecr = tmio_ioread8(tc6393xb->scr + SCR_GPO_DOECR(offset / 8));
doecr |= TC_GPIO_BIT(offset);
tmio_iowrite8(doecr, tc6393xb->scr + SCR_GPO_DOECR(offset / 8));
spin_unlock_irqrestore(&tc6393xb->lock, flags);
return 0;
}
static int tc6393xb_register_gpio(struct tc6393xb *tc6393xb, int gpio_base)
{
tc6393xb->gpio.label = "tc6393xb";
tc6393xb->gpio.base = gpio_base;
tc6393xb->gpio.ngpio = 16;
tc6393xb->gpio.set = tc6393xb_gpio_set;
tc6393xb->gpio.get = tc6393xb_gpio_get;
tc6393xb->gpio.direction_input = tc6393xb_gpio_direction_input;
tc6393xb->gpio.direction_output = tc6393xb_gpio_direction_output;
return gpiochip_add(&tc6393xb->gpio);
}
static void
tc6393xb_irq(unsigned int irq, struct irq_desc *desc)
{
struct tc6393xb *tc6393xb = irq_get_handler_data(irq);
unsigned int isr;
unsigned int i, irq_base;
irq_base = tc6393xb->irq_base;
while ((isr = tmio_ioread8(tc6393xb->scr + SCR_ISR) &
~tmio_ioread8(tc6393xb->scr + SCR_IMR)))
for (i = 0; i < TC6393XB_NR_IRQS; i++) {
if (isr & (1 << i))
generic_handle_irq(irq_base + i);
}
}
static void tc6393xb_irq_ack(struct irq_data *data)
{
}
static void tc6393xb_irq_mask(struct irq_data *data)
{
struct tc6393xb *tc6393xb = irq_data_get_irq_chip_data(data);
unsigned long flags;
u8 imr;
spin_lock_irqsave(&tc6393xb->lock, flags);
imr = tmio_ioread8(tc6393xb->scr + SCR_IMR);
imr |= 1 << (data->irq - tc6393xb->irq_base);
tmio_iowrite8(imr, tc6393xb->scr + SCR_IMR);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
}
static void tc6393xb_irq_unmask(struct irq_data *data)
{
struct tc6393xb *tc6393xb = irq_data_get_irq_chip_data(data);
unsigned long flags;
u8 imr;
spin_lock_irqsave(&tc6393xb->lock, flags);
imr = tmio_ioread8(tc6393xb->scr + SCR_IMR);
imr &= ~(1 << (data->irq - tc6393xb->irq_base));
tmio_iowrite8(imr, tc6393xb->scr + SCR_IMR);
spin_unlock_irqrestore(&tc6393xb->lock, flags);
}
static void tc6393xb_attach_irq(struct platform_device *dev)
{
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
unsigned int irq, irq_base;
irq_base = tc6393xb->irq_base;
for (irq = irq_base; irq < irq_base + TC6393XB_NR_IRQS; irq++) {
irq_set_chip_and_handler(irq, &tc6393xb_chip, handle_edge_irq);
irq_set_chip_data(irq, tc6393xb);
set_irq_flags(irq, IRQF_VALID | IRQF_PROBE);
}
irq_set_irq_type(tc6393xb->irq, IRQ_TYPE_EDGE_FALLING);
irq_set_handler_data(tc6393xb->irq, tc6393xb);
irq_set_chained_handler(tc6393xb->irq, tc6393xb_irq);
}
static void tc6393xb_detach_irq(struct platform_device *dev)
{
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
unsigned int irq, irq_base;
irq_set_chained_handler(tc6393xb->irq, NULL);
irq_set_handler_data(tc6393xb->irq, NULL);
irq_base = tc6393xb->irq_base;
for (irq = irq_base; irq < irq_base + TC6393XB_NR_IRQS; irq++) {
set_irq_flags(irq, 0);
irq_set_chip(irq, NULL);
irq_set_chip_data(irq, NULL);
}
}
static int tc6393xb_probe(struct platform_device *dev)
{
struct tc6393xb_platform_data *tcpd = dev->dev.platform_data;
struct tc6393xb *tc6393xb;
struct resource *iomem, *rscr;
int ret, temp;
iomem = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!iomem)
return -EINVAL;
tc6393xb = kzalloc(sizeof *tc6393xb, GFP_KERNEL);
if (!tc6393xb) {
ret = -ENOMEM;
goto err_kzalloc;
}
spin_lock_init(&tc6393xb->lock);
platform_set_drvdata(dev, tc6393xb);
ret = platform_get_irq(dev, 0);
if (ret >= 0)
tc6393xb->irq = ret;
else
goto err_noirq;
tc6393xb->iomem = iomem;
tc6393xb->irq_base = tcpd->irq_base;
tc6393xb->clk = clk_get(&dev->dev, "CLK_CK3P6MI");
if (IS_ERR(tc6393xb->clk)) {
ret = PTR_ERR(tc6393xb->clk);
goto err_clk_get;
}
rscr = &tc6393xb->rscr;
rscr->name = "tc6393xb-core";
rscr->start = iomem->start;
rscr->end = iomem->start + 0xff;
rscr->flags = IORESOURCE_MEM;
ret = request_resource(iomem, rscr);
if (ret)
goto err_request_scr;
tc6393xb->scr = ioremap(rscr->start, resource_size(rscr));
if (!tc6393xb->scr) {
ret = -ENOMEM;
goto err_ioremap;
}
ret = clk_enable(tc6393xb->clk);
if (ret)
goto err_clk_enable;
ret = tcpd->enable(dev);
if (ret)
goto err_enable;
iowrite8(0, tc6393xb->scr + SCR_FER);
iowrite16(tcpd->scr_pll2cr, tc6393xb->scr + SCR_PLL2CR);
iowrite16(SCR_CCR_UNK1 | SCR_CCR_HCLK_48,
tc6393xb->scr + SCR_CCR);
iowrite16(SCR_MCR_RDY_OPENDRAIN | SCR_MCR_RDY_UNK | SCR_MCR_RDY_EN |
SCR_MCR_INT_OPENDRAIN | SCR_MCR_INT_UNK | SCR_MCR_INT_EN |
BIT(15), tc6393xb->scr + SCR_MCR);
iowrite16(tcpd->scr_gper, tc6393xb->scr + SCR_GPER);
iowrite8(0, tc6393xb->scr + SCR_IRR);
iowrite8(0xbf, tc6393xb->scr + SCR_IMR);
printk(KERN_INFO "Toshiba tc6393xb revision %d at 0x%08lx, irq %d\n",
tmio_ioread8(tc6393xb->scr + SCR_REVID),
(unsigned long) iomem->start, tc6393xb->irq);
tc6393xb->gpio.base = -1;
if (tcpd->gpio_base >= 0) {
ret = tc6393xb_register_gpio(tc6393xb, tcpd->gpio_base);
if (ret)
goto err_gpio_add;
}
tc6393xb_attach_irq(dev);
if (tcpd->setup) {
ret = tcpd->setup(dev);
if (ret)
goto err_setup;
}
tc6393xb_cells[TC6393XB_CELL_NAND].platform_data = tcpd->nand_data;
tc6393xb_cells[TC6393XB_CELL_NAND].pdata_size =
sizeof(*tcpd->nand_data);
tc6393xb_cells[TC6393XB_CELL_FB].platform_data = tcpd->fb_data;
tc6393xb_cells[TC6393XB_CELL_FB].pdata_size = sizeof(*tcpd->fb_data);
ret = mfd_add_devices(&dev->dev, dev->id,
tc6393xb_cells, ARRAY_SIZE(tc6393xb_cells),
iomem, tcpd->irq_base, NULL);
if (!ret)
return 0;
if (tcpd->teardown)
tcpd->teardown(dev);
err_setup:
tc6393xb_detach_irq(dev);
err_gpio_add:
if (tc6393xb->gpio.base != -1)
temp = gpiochip_remove(&tc6393xb->gpio);
tcpd->disable(dev);
err_enable:
clk_disable(tc6393xb->clk);
err_clk_enable:
iounmap(tc6393xb->scr);
err_ioremap:
release_resource(&tc6393xb->rscr);
err_request_scr:
clk_put(tc6393xb->clk);
err_noirq:
err_clk_get:
kfree(tc6393xb);
err_kzalloc:
return ret;
}
static int tc6393xb_remove(struct platform_device *dev)
{
struct tc6393xb_platform_data *tcpd = dev->dev.platform_data;
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
int ret;
mfd_remove_devices(&dev->dev);
if (tcpd->teardown)
tcpd->teardown(dev);
tc6393xb_detach_irq(dev);
if (tc6393xb->gpio.base != -1) {
ret = gpiochip_remove(&tc6393xb->gpio);
if (ret) {
dev_err(&dev->dev, "Can't remove gpio chip: %d\n", ret);
return ret;
}
}
ret = tcpd->disable(dev);
clk_disable(tc6393xb->clk);
iounmap(tc6393xb->scr);
release_resource(&tc6393xb->rscr);
clk_put(tc6393xb->clk);
kfree(tc6393xb);
return ret;
}
static int tc6393xb_suspend(struct platform_device *dev, pm_message_t state)
{
struct tc6393xb_platform_data *tcpd = dev->dev.platform_data;
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
int i, ret;
tc6393xb->suspend_state.ccr = ioread16(tc6393xb->scr + SCR_CCR);
tc6393xb->suspend_state.fer = ioread8(tc6393xb->scr + SCR_FER);
for (i = 0; i < 3; i++) {
tc6393xb->suspend_state.gpo_dsr[i] =
ioread8(tc6393xb->scr + SCR_GPO_DSR(i));
tc6393xb->suspend_state.gpo_doecr[i] =
ioread8(tc6393xb->scr + SCR_GPO_DOECR(i));
tc6393xb->suspend_state.gpi_bcr[i] =
ioread8(tc6393xb->scr + SCR_GPI_BCR(i));
}
ret = tcpd->suspend(dev);
clk_disable(tc6393xb->clk);
return ret;
}
static int tc6393xb_resume(struct platform_device *dev)
{
struct tc6393xb_platform_data *tcpd = dev->dev.platform_data;
struct tc6393xb *tc6393xb = platform_get_drvdata(dev);
int ret;
int i;
clk_enable(tc6393xb->clk);
ret = tcpd->resume(dev);
if (ret)
return ret;
if (!tcpd->resume_restore)
return 0;
iowrite8(tc6393xb->suspend_state.fer, tc6393xb->scr + SCR_FER);
iowrite16(tcpd->scr_pll2cr, tc6393xb->scr + SCR_PLL2CR);
iowrite16(tc6393xb->suspend_state.ccr, tc6393xb->scr + SCR_CCR);
iowrite16(SCR_MCR_RDY_OPENDRAIN | SCR_MCR_RDY_UNK | SCR_MCR_RDY_EN |
SCR_MCR_INT_OPENDRAIN | SCR_MCR_INT_UNK | SCR_MCR_INT_EN |
BIT(15), tc6393xb->scr + SCR_MCR);
iowrite16(tcpd->scr_gper, tc6393xb->scr + SCR_GPER);
iowrite8(0, tc6393xb->scr + SCR_IRR);
iowrite8(0xbf, tc6393xb->scr + SCR_IMR);
for (i = 0; i < 3; i++) {
iowrite8(tc6393xb->suspend_state.gpo_dsr[i],
tc6393xb->scr + SCR_GPO_DSR(i));
iowrite8(tc6393xb->suspend_state.gpo_doecr[i],
tc6393xb->scr + SCR_GPO_DOECR(i));
iowrite8(tc6393xb->suspend_state.gpi_bcr[i],
tc6393xb->scr + SCR_GPI_BCR(i));
}
return 0;
}
static int __init tc6393xb_init(void)
{
return platform_driver_register(&tc6393xb_driver);
}
static void __exit tc6393xb_exit(void)
{
platform_driver_unregister(&tc6393xb_driver);
}
