static int xgmac_wait_until_free(struct device *dev,
struct tgec_mdio_controller __iomem *regs)
{
unsigned int timeout;
timeout = TIMEOUT;
while ((ioread32be(&regs->mdio_stat) & MDIO_STAT_BSY) && timeout) {
cpu_relax();
timeout--;
}
if (!timeout) {
dev_err(dev, "timeout waiting for bus to be free\n");
return -ETIMEDOUT;
}
return 0;
}
static int xgmac_wait_until_done(struct device *dev,
struct tgec_mdio_controller __iomem *regs)
{
unsigned int timeout;
timeout = TIMEOUT;
while ((ioread32be(&regs->mdio_data) & MDIO_DATA_BSY) && timeout) {
cpu_relax();
timeout--;
}
if (!timeout) {
dev_err(dev, "timeout waiting for operation to complete\n");
return -ETIMEDOUT;
}
return 0;
}
static int xgmac_mdio_write(struct mii_bus *bus, int phy_id, int regnum, u16 value)
{
struct tgec_mdio_controller __iomem *regs = bus->priv;
uint16_t dev_addr;
u32 mdio_ctl, mdio_stat;
int ret;
mdio_stat = ioread32be(&regs->mdio_stat);
if (regnum & MII_ADDR_C45) {
dev_addr = (regnum >> 16) & 0x1f;
mdio_stat |= MDIO_STAT_ENC;
} else {
dev_addr = regnum & 0x1f;
mdio_stat &= ~MDIO_STAT_ENC;
}
iowrite32be(mdio_stat, &regs->mdio_stat);
ret = xgmac_wait_until_free(&bus->dev, regs);
if (ret)
return ret;
mdio_ctl = MDIO_CTL_PORT_ADDR(phy_id) | MDIO_CTL_DEV_ADDR(dev_addr);
iowrite32be(mdio_ctl, &regs->mdio_ctl);
if (regnum & MII_ADDR_C45) {
iowrite32be(regnum & 0xffff, &regs->mdio_addr);
ret = xgmac_wait_until_free(&bus->dev, regs);
if (ret)
return ret;
}
iowrite32be(MDIO_DATA(value), &regs->mdio_data);
ret = xgmac_wait_until_done(&bus->dev, regs);
if (ret)
return ret;
return 0;
}
static int xgmac_mdio_read(struct mii_bus *bus, int phy_id, int regnum)
{
struct tgec_mdio_controller __iomem *regs = bus->priv;
uint16_t dev_addr;
uint32_t mdio_stat;
uint32_t mdio_ctl;
uint16_t value;
int ret;
mdio_stat = ioread32be(&regs->mdio_stat);
if (regnum & MII_ADDR_C45) {
dev_addr = (regnum >> 16) & 0x1f;
mdio_stat |= MDIO_STAT_ENC;
} else {
dev_addr = regnum & 0x1f;
mdio_stat &= ~MDIO_STAT_ENC;
}
iowrite32be(mdio_stat, &regs->mdio_stat);
ret = xgmac_wait_until_free(&bus->dev, regs);
if (ret)
return ret;
mdio_ctl = MDIO_CTL_PORT_ADDR(phy_id) | MDIO_CTL_DEV_ADDR(dev_addr);
iowrite32be(mdio_ctl, &regs->mdio_ctl);
if (regnum & MII_ADDR_C45) {
iowrite32be(regnum & 0xffff, &regs->mdio_addr);
ret = xgmac_wait_until_free(&bus->dev, regs);
if (ret)
return ret;
}
iowrite32be(mdio_ctl | MDIO_CTL_READ, &regs->mdio_ctl);
ret = xgmac_wait_until_done(&bus->dev, regs);
if (ret)
return ret;
if (ioread32be(&regs->mdio_stat) & MDIO_STAT_RD_ER) {
dev_err(&bus->dev,
"Error while reading PHY%d reg at %d.%hhu\n",
phy_id, dev_addr, regnum);
return 0xffff;
}
value = ioread32be(&regs->mdio_data) & 0xffff;
dev_dbg(&bus->dev, "read %04x\n", value);
return value;
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
bus = mdiobus_alloc();
if (!bus)
return -ENOMEM;
bus->name = "Freescale XGMAC MDIO Bus";
bus->read = xgmac_mdio_read;
bus->write = xgmac_mdio_write;
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
