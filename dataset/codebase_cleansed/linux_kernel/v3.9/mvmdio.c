static int orion_mdio_wait_ready(struct mii_bus *bus)
{
struct orion_mdio_dev *dev = bus->priv;
int count;
u32 val;
count = 0;
while (1) {
val = readl(dev->smireg);
if (!(val & MVMDIO_SMI_BUSY))
break;
if (count > 100) {
dev_err(bus->parent, "Timeout: SMI busy for too long\n");
return -ETIMEDOUT;
}
udelay(10);
count++;
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
dev->smireg);
count = 0;
while (1) {
val = readl(dev->smireg);
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
dev->smireg);
mutex_unlock(&dev->lock);
return 0;
}
static int orion_mdio_reset(struct mii_bus *bus)
{
return 0;
}
static int orion_mdio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mii_bus *bus;
struct orion_mdio_dev *dev;
int i, ret;
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
dev->smireg = of_iomap(pdev->dev.of_node, 0);
if (!dev->smireg) {
dev_err(&pdev->dev, "No SMI register address given in DT\n");
kfree(bus->irq);
mdiobus_free(bus);
return -ENODEV;
}
mutex_init(&dev->lock);
ret = of_mdiobus_register(bus, np);
if (ret < 0) {
dev_err(&pdev->dev, "Cannot register MDIO bus (%d)\n", ret);
iounmap(dev->smireg);
kfree(bus->irq);
mdiobus_free(bus);
return ret;
}
platform_set_drvdata(pdev, bus);
return 0;
}
static int orion_mdio_remove(struct platform_device *pdev)
{
struct mii_bus *bus = platform_get_drvdata(pdev);
mdiobus_unregister(bus);
kfree(bus->irq);
mdiobus_free(bus);
return 0;
}
