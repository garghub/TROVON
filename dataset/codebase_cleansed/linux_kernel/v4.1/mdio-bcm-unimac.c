static inline void unimac_mdio_start(struct unimac_mdio_priv *priv)
{
u32 reg;
reg = __raw_readl(priv->base + MDIO_CMD);
reg |= MDIO_START_BUSY;
__raw_writel(reg, priv->base + MDIO_CMD);
}
static inline unsigned int unimac_mdio_busy(struct unimac_mdio_priv *priv)
{
return __raw_readl(priv->base + MDIO_CMD) & MDIO_START_BUSY;
}
static int unimac_mdio_read(struct mii_bus *bus, int phy_id, int reg)
{
struct unimac_mdio_priv *priv = bus->priv;
unsigned int timeout = 1000;
u32 cmd;
cmd = MDIO_RD | (phy_id << MDIO_PMD_SHIFT) | (reg << MDIO_REG_SHIFT);
__raw_writel(cmd, priv->base + MDIO_CMD);
unimac_mdio_start(priv);
do {
if (!unimac_mdio_busy(priv))
break;
usleep_range(1000, 2000);
} while (timeout--);
if (!timeout)
return -ETIMEDOUT;
cmd = __raw_readl(priv->base + MDIO_CMD);
if (cmd & MDIO_READ_FAIL)
return -EIO;
return cmd & 0xffff;
}
static int unimac_mdio_write(struct mii_bus *bus, int phy_id,
int reg, u16 val)
{
struct unimac_mdio_priv *priv = bus->priv;
unsigned int timeout = 1000;
u32 cmd;
cmd = MDIO_WR | (phy_id << MDIO_PMD_SHIFT) |
(reg << MDIO_REG_SHIFT) | (0xffff & val);
__raw_writel(cmd, priv->base + MDIO_CMD);
unimac_mdio_start(priv);
do {
if (!unimac_mdio_busy(priv))
break;
usleep_range(1000, 2000);
} while (timeout--);
if (!timeout)
return -ETIMEDOUT;
return 0;
}
static int unimac_mdio_probe(struct platform_device *pdev)
{
struct unimac_mdio_priv *priv;
struct device_node *np;
struct mii_bus *bus;
struct resource *r;
int ret;
np = pdev->dev.of_node;
priv = devm_kzalloc(&pdev->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
r = platform_get_resource(pdev, IORESOURCE_MEM, 0);
priv->base = devm_ioremap(&pdev->dev, r->start, resource_size(r));
if (!priv->base) {
dev_err(&pdev->dev, "failed to remap register\n");
return -ENOMEM;
}
priv->mii_bus = mdiobus_alloc();
if (!priv->mii_bus)
return -ENOMEM;
bus = priv->mii_bus;
bus->priv = priv;
bus->name = "unimac MII bus";
bus->parent = &pdev->dev;
bus->read = unimac_mdio_read;
bus->write = unimac_mdio_write;
snprintf(bus->id, MII_BUS_ID_SIZE, "%s", pdev->name);
bus->irq = kcalloc(PHY_MAX_ADDR, sizeof(int), GFP_KERNEL);
if (!bus->irq) {
ret = -ENOMEM;
goto out_mdio_free;
}
ret = of_mdiobus_register(bus, np);
if (ret) {
dev_err(&pdev->dev, "MDIO bus registration failed\n");
goto out_mdio_irq;
}
platform_set_drvdata(pdev, priv);
dev_info(&pdev->dev, "Broadcom UniMAC MDIO bus at 0x%p\n", priv->base);
return 0;
out_mdio_irq:
kfree(bus->irq);
out_mdio_free:
mdiobus_free(bus);
return ret;
}
static int unimac_mdio_remove(struct platform_device *pdev)
{
struct unimac_mdio_priv *priv = platform_get_drvdata(pdev);
mdiobus_unregister(priv->mii_bus);
kfree(priv->mii_bus->irq);
mdiobus_free(priv->mii_bus);
return 0;
}
