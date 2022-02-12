static int xgmac_wait_until_free(struct device *dev,
struct tgec_mdio_controller __iomem *regs)
{
uint32_t status;
status = spin_event_timeout(
!((in_be32(&regs->mdio_stat)) & MDIO_STAT_BSY), TIMEOUT, 0);
if (!status) {
dev_err(dev, "timeout waiting for bus to be free\n");
return -ETIMEDOUT;
}
return 0;
}
static int xgmac_wait_until_done(struct device *dev,
struct tgec_mdio_controller __iomem *regs)
{
uint32_t status;
status = spin_event_timeout(
!((in_be32(&regs->mdio_data)) & MDIO_DATA_BSY), TIMEOUT, 0);
if (!status) {
dev_err(dev, "timeout waiting for operation to complete\n");
return -ETIMEDOUT;
}
return 0;
}
static int xgmac_mdio_write(struct mii_bus *bus, int phy_id, int regnum, u16 value)
{
struct tgec_mdio_controller __iomem *regs = bus->priv;
uint16_t dev_addr = regnum >> 16;
int ret;
out_be32(&regs->mdio_stat, MDIO_STAT_CLKDIV(100));
ret = xgmac_wait_until_free(&bus->dev, regs);
if (ret)
return ret;
out_be32(&regs->mdio_ctl,
MDIO_CTL_PORT_ADDR(phy_id) | MDIO_CTL_DEV_ADDR(dev_addr));
out_be32(&regs->mdio_addr, regnum & 0xffff);
ret = xgmac_wait_until_free(&bus->dev, regs);
if (ret)
return ret;
out_be32(&regs->mdio_data, MDIO_DATA(value));
ret = xgmac_wait_until_done(&bus->dev, regs);
if (ret)
return ret;
return 0;
}
static int xgmac_mdio_read(struct mii_bus *bus, int phy_id, int regnum)
{
struct tgec_mdio_controller __iomem *regs = bus->priv;
uint16_t dev_addr = regnum >> 16;
uint32_t mdio_ctl;
uint16_t value;
int ret;
out_be32(&regs->mdio_stat, MDIO_STAT_CLKDIV(100));
ret = xgmac_wait_until_free(&bus->dev, regs);
if (ret)
return ret;
mdio_ctl = MDIO_CTL_PORT_ADDR(phy_id) | MDIO_CTL_DEV_ADDR(dev_addr);
out_be32(&regs->mdio_ctl, mdio_ctl);
out_be32(&regs->mdio_addr, regnum & 0xffff);
ret = xgmac_wait_until_free(&bus->dev, regs);
if (ret)
return ret;
out_be32(&regs->mdio_ctl, mdio_ctl | MDIO_CTL_READ);
ret = xgmac_wait_until_done(&bus->dev, regs);
if (ret)
return ret;
if (in_be32(&regs->mdio_stat) & MDIO_STAT_RD_ER) {
dev_err(&bus->dev,
"Error while reading PHY%d reg at %d.%d\n",
phy_id, dev_addr, regnum);
return 0xffff;
}
value = in_be32(&regs->mdio_data) & 0xffff;
dev_dbg(&bus->dev, "read %04x\n", value);
return value;
}
static int xgmac_mdio_reset(struct mii_bus *bus)
{
struct tgec_mdio_controller __iomem *regs = bus->priv;
int ret;
mutex_lock(&bus->mdio_lock);
out_be32(&regs->mdio_stat, MDIO_STAT_CLKDIV(100));
ret = xgmac_wait_until_free(&bus->dev, regs);
mutex_unlock(&bus->mdio_lock);
return ret;
}
static int xgmac_mdio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mii_bus *bus;
struct resource res;
int ret;
ret = of_address_to_resource(np, 0, &res);
if (ret) {
dev_err(&pdev->dev, "could not obtain address\n");
return ret;
}
bus = mdiobus_alloc_size(PHY_MAX_ADDR * sizeof(int));
if (!bus)
return -ENOMEM;
bus->name = "Freescale XGMAC MDIO Bus";
bus->read = xgmac_mdio_read;
bus->write = xgmac_mdio_write;
bus->reset = xgmac_mdio_reset;
bus->irq = bus->priv;
bus->parent = &pdev->dev;
snprintf(bus->id, MII_BUS_ID_SIZE, "%llx", (unsigned long long)res.start);
bus->priv = of_iomap(np, 0);
if (!bus->priv) {
ret = -ENOMEM;
goto err_ioremap;
}
ret = of_mdiobus_register(bus, np);
if (ret) {
dev_err(&pdev->dev, "cannot register MDIO bus\n");
goto err_registration;
}
platform_set_drvdata(pdev, bus);
return 0;
err_registration:
iounmap(bus->priv);
err_ioremap:
mdiobus_free(bus);
return ret;
}
static int xgmac_mdio_remove(struct platform_device *pdev)
{
struct mii_bus *bus = platform_get_drvdata(pdev);
mdiobus_unregister(bus);
iounmap(bus->priv);
mdiobus_free(bus);
return 0;
}
