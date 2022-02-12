static int hip04_mdio_wait_ready(struct mii_bus *bus)
{
struct hip04_mdio_priv *priv = bus->priv;
int i;
for (i = 0; readl_relaxed(priv->base + MDIO_CMD_REG) & MDIO_START; i++) {
if (i == WAIT_TIMEOUT)
return -ETIMEDOUT;
msleep(20);
}
return 0;
}
static int hip04_mdio_read(struct mii_bus *bus, int mii_id, int regnum)
{
struct hip04_mdio_priv *priv = bus->priv;
u32 val;
int ret;
ret = hip04_mdio_wait_ready(bus);
if (ret < 0)
goto out;
val = regnum | (mii_id << 5) | MDIO_READ;
writel_relaxed(val, priv->base + MDIO_CMD_REG);
ret = hip04_mdio_wait_ready(bus);
if (ret < 0)
goto out;
val = readl_relaxed(priv->base + MDIO_STA_REG);
if (val & MDIO_R_VALID) {
dev_err(bus->parent, "SMI bus read not valid\n");
ret = -ENODEV;
goto out;
}
val = readl_relaxed(priv->base + MDIO_RDATA_REG);
ret = val & 0xFFFF;
out:
return ret;
}
static int hip04_mdio_write(struct mii_bus *bus, int mii_id,
int regnum, u16 value)
{
struct hip04_mdio_priv *priv = bus->priv;
u32 val;
int ret;
ret = hip04_mdio_wait_ready(bus);
if (ret < 0)
goto out;
writel_relaxed(value, priv->base + MDIO_WDATA_REG);
val = regnum | (mii_id << 5) | MDIO_WRITE;
writel_relaxed(val, priv->base + MDIO_CMD_REG);
out:
return ret;
}
static int hip04_mdio_reset(struct mii_bus *bus)
{
int temp, i;
for (i = 0; i < PHY_MAX_ADDR; i++) {
hip04_mdio_write(bus, i, 22, 0);
temp = hip04_mdio_read(bus, i, MII_BMCR);
if (temp < 0)
continue;
temp |= BMCR_RESET;
if (hip04_mdio_write(bus, i, MII_BMCR, temp) < 0)
continue;
}
mdelay(500);
return 0;
}
static int hip04_mdio_probe(struct platform_device *pdev)
{
struct resource *r;
struct mii_bus *bus;
struct hip04_mdio_priv *priv;
int ret;
bus = mdiobus_alloc_size(sizeof(struct hip04_mdio_priv));
if (!bus) {
dev_err(&pdev->dev, "Cannot allocate MDIO bus\n");
return -ENOMEM;
}
bus->name = "hip04_mdio_bus";
bus->read = hip04_mdio_read;
bus->write = hip04_mdio_write;
bus->reset = hip04_mdio_reset;
snprintf(bus->id, MII_BUS_ID_SIZE, "%s-mii", dev_name(&pdev->dev));
bus->parent = &pdev->dev;
priv = bus->priv;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap_resource(&pdev->dev, r);
if (IS_ERR(priv->base)) {
ret = PTR_ERR(priv->base);
goto out_mdio;
}
ret = of_mdiobus_register(bus, pdev->dev.of_node);
if (ret < 0) {
dev_err(&pdev->dev, "Cannot register MDIO bus (%d)\n", ret);
goto out_mdio;
}
platform_set_drvdata(pdev, bus);
return 0;
out_mdio:
mdiobus_free(bus);
return ret;
}
static int hip04_mdio_remove(struct platform_device *pdev)
{
struct mii_bus *bus = platform_get_drvdata(pdev);
mdiobus_unregister(bus);
mdiobus_free(bus);
return 0;
}
