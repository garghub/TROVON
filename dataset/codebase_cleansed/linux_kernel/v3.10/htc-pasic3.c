void pasic3_write_register(struct device *dev, u32 reg, u8 val)
{
struct pasic3_data *asic = dev_get_drvdata(dev);
int bus_shift = asic->bus_shift;
void __iomem *addr = asic->mapping + (REG_ADDR << bus_shift);
void __iomem *data = asic->mapping + (REG_DATA << bus_shift);
__raw_writeb(~READ_MODE & reg, addr);
__raw_writeb(val, data);
}
u8 pasic3_read_register(struct device *dev, u32 reg)
{
struct pasic3_data *asic = dev_get_drvdata(dev);
int bus_shift = asic->bus_shift;
void __iomem *addr = asic->mapping + (REG_ADDR << bus_shift);
void __iomem *data = asic->mapping + (REG_DATA << bus_shift);
__raw_writeb(READ_MODE | reg, addr);
return __raw_readb(data);
}
static int ds1wm_enable(struct platform_device *pdev)
{
struct device *dev = pdev->dev.parent;
int c;
c = pasic3_read_register(dev, 0x28);
pasic3_write_register(dev, 0x28, c & 0x7f);
dev_dbg(dev, "DS1WM OWM_EN low (active) %02x\n", c & 0x7f);
return 0;
}
static int ds1wm_disable(struct platform_device *pdev)
{
struct device *dev = pdev->dev.parent;
int c;
c = pasic3_read_register(dev, 0x28);
pasic3_write_register(dev, 0x28, c | 0x80);
dev_dbg(dev, "DS1WM OWM_EN high (inactive) %02x\n", c | 0x80);
return 0;
}
static int __init pasic3_probe(struct platform_device *pdev)
{
struct pasic3_platform_data *pdata = pdev->dev.platform_data;
struct device *dev = &pdev->dev;
struct pasic3_data *asic;
struct resource *r;
int ret;
int irq = 0;
r = platform_get_resource(pdev, IORESOURCE_IRQ, 0);
if (r) {
ds1wm_resources[1].flags = IORESOURCE_IRQ | (r->flags &
(IORESOURCE_IRQ_HIGHEDGE | IORESOURCE_IRQ_LOWEDGE));
irq = r->start;
}
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r)
return -ENXIO;
if (!request_mem_region(r->start, resource_size(r), "pasic3"))
return -EBUSY;
asic = kzalloc(sizeof(struct pasic3_data), GFP_KERNEL);
if (!asic)
return -ENOMEM;
platform_set_drvdata(pdev, asic);
asic->mapping = ioremap(r->start, resource_size(r));
if (!asic->mapping) {
dev_err(dev, "couldn't ioremap PASIC3\n");
kfree(asic);
return -ENOMEM;
}
asic->bus_shift = (resource_size(r) - 5) >> 3;
if (pdata && pdata->clock_rate) {
ds1wm_pdata.clock_rate = pdata->clock_rate;
ds1wm_resources[0].end = (5 << asic->bus_shift) - 1;
ret = mfd_add_devices(&pdev->dev, pdev->id,
&ds1wm_cell, 1, r, irq, NULL);
if (ret < 0)
dev_warn(dev, "failed to register DS1WM\n");
}
if (pdata && pdata->led_pdata) {
led_cell.platform_data = pdata->led_pdata;
led_cell.pdata_size = sizeof(struct pasic3_leds_machinfo);
ret = mfd_add_devices(&pdev->dev, pdev->id, &led_cell, 1, r,
0, NULL);
if (ret < 0)
dev_warn(dev, "failed to register LED device\n");
}
return 0;
}
static int pasic3_remove(struct platform_device *pdev)
{
struct pasic3_data *asic = platform_get_drvdata(pdev);
struct resource *r;
mfd_remove_devices(&pdev->dev);
iounmap(asic->mapping);
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
release_mem_region(r->start, resource_size(r));
kfree(asic);
return 0;
}
