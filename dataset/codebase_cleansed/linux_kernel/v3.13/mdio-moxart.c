static int moxart_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct moxart_mdio_data *data = bus->priv;
u32 ctrl = 0;
unsigned int count = 5;
dev_dbg(&bus->dev, "%s\n", __func__);
ctrl |= MIIRD | ((mii_id << 16) & PHYAD_MASK) |
((regnum << 21) & REGAD_MASK);
writel(ctrl, data->base + REG_PHY_CTRL);
do {
ctrl = readl(data->base + REG_PHY_CTRL);
if (!(ctrl & MIIRD))
return ctrl & MIIRDATA_MASK;
mdelay(10);
count--;
} while (count > 0);
dev_dbg(&bus->dev, "%s timed out\n", __func__);
return -ETIMEDOUT;
}
static int moxart_mdio_write(struct mii_bus *bus, int mii_id,
int regnum, u16 value)
{
struct moxart_mdio_data *data = bus->priv;
u32 ctrl = 0;
unsigned int count = 5;
dev_dbg(&bus->dev, "%s\n", __func__);
ctrl |= MIIWR | ((mii_id << 16) & PHYAD_MASK) |
((regnum << 21) & REGAD_MASK);
value &= MIIWDATA_MASK;
writel(value, data->base + REG_PHY_WRITE_DATA);
writel(ctrl, data->base + REG_PHY_CTRL);
do {
ctrl = readl(data->base + REG_PHY_CTRL);
if (!(ctrl & MIIWR))
return 0;
mdelay(10);
count--;
} while (count > 0);
dev_dbg(&bus->dev, "%s timed out\n", __func__);
return -ETIMEDOUT;
}
static int moxart_mdio_reset(struct mii_bus *bus)
{
int data, i;
for (i = 0; i < PHY_MAX_ADDR; i++) {
data = moxart_mdio_read(bus, i, MII_BMCR);
if (data < 0)
continue;
data |= BMCR_RESET;
if (moxart_mdio_write(bus, i, MII_BMCR, data) < 0)
continue;
}
return 0;
}
static int moxart_mdio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mii_bus *bus;
struct moxart_mdio_data *data;
struct resource *res;
int ret, i;
bus = mdiobus_alloc_size(sizeof(*data));
if (!bus)
return -ENOMEM;
bus->name = "MOXA ART Ethernet MII";
bus->read = &moxart_mdio_read;
bus->write = &moxart_mdio_write;
bus->reset = &moxart_mdio_reset;
snprintf(bus->id, MII_BUS_ID_SIZE, "%s-%d-mii", pdev->name, pdev->id);
bus->parent = &pdev->dev;
bus->irq = devm_kzalloc(&pdev->dev, sizeof(int) * PHY_MAX_ADDR,
GFP_KERNEL);
if (!bus->irq) {
ret = -ENOMEM;
goto err_out_free_mdiobus;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
bus->irq[i] = PHY_IGNORE_INTERRUPT;
data = bus->priv;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->base)) {
ret = PTR_ERR(data->base);
goto err_out_free_mdiobus;
}
ret = of_mdiobus_register(bus, np);
if (ret < 0)
goto err_out_free_mdiobus;
platform_set_drvdata(pdev, bus);
return 0;
err_out_free_mdiobus:
mdiobus_free(bus);
return ret;
}
static int moxart_mdio_remove(struct platform_device *pdev)
{
struct mii_bus *bus = platform_get_drvdata(pdev);
mdiobus_unregister(bus);
mdiobus_free(bus);
return 0;
}
