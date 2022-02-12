static int orion_mdio_smi_is_done(struct orion_mdio_dev *dev)
{
return !(readl(dev->regs) & MVMDIO_SMI_BUSY);
}
static int orion_mdio_wait_ready(struct mii_bus *bus)
{
struct orion_mdio_dev *dev = bus->priv;
int count;
if (dev->err_interrupt <= 0) {
count = 0;
while (1) {
if (orion_mdio_smi_is_done(dev))
break;
if (count > 100) {
dev_err(bus->parent,
"Timeout: SMI busy for too long\n");
return -ETIMEDOUT;
}
udelay(10);
count++;
}
} else {
if (!orion_mdio_smi_is_done(dev)) {
wait_event_timeout(dev->smi_busy_wait,
orion_mdio_smi_is_done(dev),
msecs_to_jiffies(100));
if (!orion_mdio_smi_is_done(dev))
return -ETIMEDOUT;
}
}
return 0;
}
static int orion_mdio_read(struct mii_bus *bus, int mii_id,
int regnum)
{
struct orion_mdio_dev *dev = bus->priv;
int count;
u32 val;
int ret;
mutex_lock(&dev->lock);
ret = orion_mdio_wait_ready(bus);
if (ret < 0) {
mutex_unlock(&dev->lock);
return ret;
}
writel(((mii_id << MVMDIO_SMI_PHY_ADDR_SHIFT) |
(regnum << MVMDIO_SMI_PHY_REG_SHIFT) |
MVMDIO_SMI_READ_OPERATION),
dev->regs);
count = 0;
while (1) {
val = readl(dev->regs);
if (val & MVMDIO_SMI_READ_VALID)
break;
if (count > 100) {
dev_err(bus->parent, "Timeout when reading PHY\n");
mutex_unlock(&dev->lock);
return -ETIMEDOUT;
}
udelay(10);
count++;
}
mutex_unlock(&dev->lock);
return val & 0xFFFF;
}
static int orion_mdio_write(struct mii_bus *bus, int mii_id,
int regnum, u16 value)
{
struct orion_mdio_dev *dev = bus->priv;
int ret;
mutex_lock(&dev->lock);
ret = orion_mdio_wait_ready(bus);
if (ret < 0) {
mutex_unlock(&dev->lock);
return ret;
}
writel(((mii_id << MVMDIO_SMI_PHY_ADDR_SHIFT) |
(regnum << MVMDIO_SMI_PHY_REG_SHIFT) |
MVMDIO_SMI_WRITE_OPERATION |
(value << MVMDIO_SMI_DATA_SHIFT)),
dev->regs);
mutex_unlock(&dev->lock);
return 0;
}
static int orion_mdio_reset(struct mii_bus *bus)
{
return 0;
}
static irqreturn_t orion_mdio_err_irq(int irq, void *dev_id)
{
struct orion_mdio_dev *dev = dev_id;
if (readl(dev->regs + MVMDIO_ERR_INT_CAUSE) &
MVMDIO_ERR_INT_SMI_DONE) {
writel(~MVMDIO_ERR_INT_SMI_DONE,
dev->regs + MVMDIO_ERR_INT_CAUSE);
wake_up(&dev->smi_busy_wait);
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int orion_mdio_probe(struct platform_device *pdev)
{
struct resource *r;
struct mii_bus *bus;
struct orion_mdio_dev *dev;
int i, ret;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!r) {
dev_err(&pdev->dev, "No SMI register address given\n");
return -ENODEV;
}
bus = mdiobus_alloc_size(sizeof(struct orion_mdio_dev));
if (!bus) {
dev_err(&pdev->dev, "Cannot allocate MDIO bus\n");
return -ENOMEM;
}
bus->name = "orion_mdio_bus";
bus->read = orion_mdio_read;
bus->write = orion_mdio_write;
bus->reset = orion_mdio_reset;
snprintf(bus->id, MII_BUS_ID_SIZE, "%s-mii",
dev_name(&pdev->dev));
bus->parent = &pdev->dev;
bus->irq = kmalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!bus->irq) {
mdiobus_free(bus);
return -ENOMEM;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
bus->irq[i] = PHY_POLL;
dev = bus->priv;
dev->regs = devm_ioremap(&pdev->dev, r->start, resource_size(r));
if (!dev->regs) {
dev_err(&pdev->dev, "Unable to remap SMI register\n");
ret = -ENODEV;
goto out_mdio;
}
init_waitqueue_head(&dev->smi_busy_wait);
dev->clk = devm_clk_get(&pdev->dev, NULL);
if (!IS_ERR(dev->clk))
clk_prepare_enable(dev->clk);
dev->err_interrupt = platform_get_irq(pdev, 0);
if (dev->err_interrupt != -ENXIO) {
ret = devm_request_irq(&pdev->dev, dev->err_interrupt,
orion_mdio_err_irq,
IRQF_SHARED, pdev->name, dev);
if (ret)
goto out_mdio;
writel(MVMDIO_ERR_INT_SMI_DONE,
dev->regs + MVMDIO_ERR_INT_MASK);
}
mutex_init(&dev->lock);
if (pdev->dev.of_node)
ret = of_mdiobus_register(bus, pdev->dev.of_node);
else
ret = mdiobus_register(bus);
if (ret < 0) {
dev_err(&pdev->dev, "Cannot register MDIO bus (%d)\n", ret);
goto out_mdio;
}
platform_set_drvdata(pdev, bus);
return 0;
out_mdio:
if (!IS_ERR(dev->clk))
clk_disable_unprepare(dev->clk);
kfree(bus->irq);
mdiobus_free(bus);
return ret;
}
static int orion_mdio_remove(struct platform_device *pdev)
{
struct mii_bus *bus = platform_get_drvdata(pdev);
struct orion_mdio_dev *dev = bus->priv;
writel(0, dev->regs + MVMDIO_ERR_INT_MASK);
mdiobus_unregister(bus);
kfree(bus->irq);
mdiobus_free(bus);
if (!IS_ERR(dev->clk))
clk_disable_unprepare(dev->clk);
return 0;
}
