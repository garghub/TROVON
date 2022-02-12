static int sun4i_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct sun4i_mdio_data *data = bus->priv;
unsigned long timeout_jiffies;
int value;
writel((mii_id << 8) | regnum, data->membase + EMAC_MAC_MADR_REG);
writel(0x1, data->membase + EMAC_MAC_MCMD_REG);
timeout_jiffies = jiffies + MDIO_TIMEOUT;
while (readl(data->membase + EMAC_MAC_MIND_REG) & 0x1) {
if (time_is_before_jiffies(timeout_jiffies))
return -ETIMEDOUT;
msleep(1);
}
writel(0x0, data->membase + EMAC_MAC_MCMD_REG);
value = readl(data->membase + EMAC_MAC_MRDD_REG);
return value;
}
static int sun4i_mdio_write(struct mii_bus *bus, int mii_id, int regnum,
u16 value)
{
struct sun4i_mdio_data *data = bus->priv;
unsigned long timeout_jiffies;
writel((mii_id << 8) | regnum, data->membase + EMAC_MAC_MADR_REG);
writel(0x1, data->membase + EMAC_MAC_MCMD_REG);
timeout_jiffies = jiffies + MDIO_TIMEOUT;
while (readl(data->membase + EMAC_MAC_MIND_REG) & 0x1) {
if (time_is_before_jiffies(timeout_jiffies))
return -ETIMEDOUT;
msleep(1);
}
writel(0x0, data->membase + EMAC_MAC_MCMD_REG);
writel(value, data->membase + EMAC_MAC_MWTD_REG);
return 0;
}
static int sun4i_mdio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mii_bus *bus;
struct sun4i_mdio_data *data;
struct resource *res;
int ret, i;
bus = mdiobus_alloc_size(sizeof(*data));
if (!bus)
return -ENOMEM;
bus->name = "sun4i_mii_bus";
bus->read = &sun4i_mdio_read;
bus->write = &sun4i_mdio_write;
snprintf(bus->id, MII_BUS_ID_SIZE, "%s-mii", dev_name(&pdev->dev));
bus->parent = &pdev->dev;
bus->irq = devm_kzalloc(&pdev->dev, sizeof(int) * PHY_MAX_ADDR,
GFP_KERNEL);
if (!bus->irq) {
ret = -ENOMEM;
goto err_out_free_mdiobus;
}
for (i = 0; i < PHY_MAX_ADDR; i++)
bus->irq[i] = PHY_POLL;
data = bus->priv;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
data->membase = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(data->membase)) {
ret = PTR_ERR(data->membase);
goto err_out_free_mdiobus;
}
data->regulator = devm_regulator_get(&pdev->dev, "phy");
if (IS_ERR(data->regulator)) {
if (PTR_ERR(data->regulator) == -EPROBE_DEFER)
return -EPROBE_DEFER;
dev_info(&pdev->dev, "no regulator found\n");
} else {
ret = regulator_enable(data->regulator);
if (ret)
goto err_out_free_mdiobus;
}
ret = of_mdiobus_register(bus, np);
if (ret < 0)
goto err_out_disable_regulator;
platform_set_drvdata(pdev, bus);
return 0;
err_out_disable_regulator:
regulator_disable(data->regulator);
err_out_free_mdiobus:
mdiobus_free(bus);
return ret;
}
static int sun4i_mdio_remove(struct platform_device *pdev)
{
struct mii_bus *bus = platform_get_drvdata(pdev);
mdiobus_unregister(bus);
mdiobus_free(bus);
return 0;
}
