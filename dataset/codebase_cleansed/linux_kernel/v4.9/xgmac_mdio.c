static u32 xgmac_read32(void __iomem *regs,
bool is_little_endian)
{
if (is_little_endian)
return ioread32(regs);
else
return ioread32be(regs);
}
static void xgmac_write32(u32 value,
void __iomem *regs,
bool is_little_endian)
{
if (is_little_endian)
iowrite32(value, regs);
else
iowrite32be(value, regs);
}
static int xgmac_wait_until_free(struct device *dev,
struct tgec_mdio_controller __iomem *regs,
bool is_little_endian)
{
unsigned int timeout;
timeout = TIMEOUT;
while ((xgmac_read32(&regs->mdio_stat, is_little_endian) &
MDIO_STAT_BSY) && timeout) {
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
struct tgec_mdio_controller __iomem *regs,
bool is_little_endian)
{
unsigned int timeout;
timeout = TIMEOUT;
while ((xgmac_read32(&regs->mdio_stat, is_little_endian) &
MDIO_STAT_BSY) && timeout) {
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
struct mdio_fsl_priv *priv = (struct mdio_fsl_priv *)bus->priv;
struct tgec_mdio_controller __iomem *regs = priv->mdio_base;
uint16_t dev_addr;
u32 mdio_ctl, mdio_stat;
int ret;
bool endian = priv->is_little_endian;
mdio_stat = xgmac_read32(&regs->mdio_stat, endian);
if (regnum & MII_ADDR_C45) {
dev_addr = (regnum >> 16) & 0x1f;
mdio_stat |= MDIO_STAT_ENC;
} else {
dev_addr = regnum & 0x1f;
mdio_stat &= ~MDIO_STAT_ENC;
}
xgmac_write32(mdio_stat, &regs->mdio_stat, endian);
ret = xgmac_wait_until_free(&bus->dev, regs, endian);
if (ret)
return ret;
mdio_ctl = MDIO_CTL_PORT_ADDR(phy_id) | MDIO_CTL_DEV_ADDR(dev_addr);
xgmac_write32(mdio_ctl, &regs->mdio_ctl, endian);
if (regnum & MII_ADDR_C45) {
xgmac_write32(regnum & 0xffff, &regs->mdio_addr, endian);
ret = xgmac_wait_until_free(&bus->dev, regs, endian);
if (ret)
return ret;
}
xgmac_write32(MDIO_DATA(value), &regs->mdio_data, endian);
ret = xgmac_wait_until_done(&bus->dev, regs, endian);
if (ret)
return ret;
return 0;
}
static int xgmac_mdio_read(struct mii_bus *bus, int phy_id, int regnum)
{
struct mdio_fsl_priv *priv = (struct mdio_fsl_priv *)bus->priv;
struct tgec_mdio_controller __iomem *regs = priv->mdio_base;
uint16_t dev_addr;
uint32_t mdio_stat;
uint32_t mdio_ctl;
uint16_t value;
int ret;
bool endian = priv->is_little_endian;
mdio_stat = xgmac_read32(&regs->mdio_stat, endian);
if (regnum & MII_ADDR_C45) {
dev_addr = (regnum >> 16) & 0x1f;
mdio_stat |= MDIO_STAT_ENC;
} else {
dev_addr = regnum & 0x1f;
mdio_stat &= ~MDIO_STAT_ENC;
}
xgmac_write32(mdio_stat, &regs->mdio_stat, endian);
ret = xgmac_wait_until_free(&bus->dev, regs, endian);
if (ret)
return ret;
mdio_ctl = MDIO_CTL_PORT_ADDR(phy_id) | MDIO_CTL_DEV_ADDR(dev_addr);
xgmac_write32(mdio_ctl, &regs->mdio_ctl, endian);
if (regnum & MII_ADDR_C45) {
xgmac_write32(regnum & 0xffff, &regs->mdio_addr, endian);
ret = xgmac_wait_until_free(&bus->dev, regs, endian);
if (ret)
return ret;
}
xgmac_write32(mdio_ctl | MDIO_CTL_READ, &regs->mdio_ctl, endian);
ret = xgmac_wait_until_done(&bus->dev, regs, endian);
if (ret)
return ret;
if (xgmac_read32(&regs->mdio_stat, endian) & MDIO_STAT_RD_ER) {
dev_err(&bus->dev,
"Error while reading PHY%d reg at %d.%hhu\n",
phy_id, dev_addr, regnum);
return 0xffff;
}
value = xgmac_read32(&regs->mdio_data, endian) & 0xffff;
dev_dbg(&bus->dev, "read %04x\n", value);
return value;
}
static int xgmac_mdio_probe(struct platform_device *pdev)
{
struct device_node *np = pdev->dev.of_node;
struct mii_bus *bus;
struct resource res;
struct mdio_fsl_priv *priv;
int ret;
ret = of_address_to_resource(np, 0, &res);
if (ret) {
dev_err(&pdev->dev, "could not obtain address\n");
return ret;
}
bus = mdiobus_alloc_size(sizeof(struct mdio_fsl_priv));
if (!bus)
return -ENOMEM;
bus->name = "Freescale XGMAC MDIO Bus";
bus->read = xgmac_mdio_read;
bus->write = xgmac_mdio_write;
bus->parent = &pdev->dev;
snprintf(bus->id, MII_BUS_ID_SIZE, "%llx", (unsigned long long)res.start);
priv = bus->priv;
priv->mdio_base = of_iomap(np, 0);
if (!priv->mdio_base) {
ret = -ENOMEM;
goto err_ioremap;
}
priv->is_little_endian = of_property_read_bool(pdev->dev.of_node,
"little-endian");
ret = of_mdiobus_register(bus, np);
if (ret) {
dev_err(&pdev->dev, "cannot register MDIO bus\n");
goto err_registration;
}
platform_set_drvdata(pdev, bus);
return 0;
err_registration:
iounmap(priv->mdio_base);
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
