static int emac_mdio_read(struct mii_bus *bus, int addr, int regnum)
{
struct emac_adapter *adpt = bus->priv;
u32 reg;
emac_reg_update32(adpt->base + EMAC_PHY_STS, PHY_ADDR_BMSK,
(addr << PHY_ADDR_SHFT));
reg = SUP_PREAMBLE |
((MDIO_CLK_25_4 << MDIO_CLK_SEL_SHFT) & MDIO_CLK_SEL_BMSK) |
((regnum << MDIO_REG_ADDR_SHFT) & MDIO_REG_ADDR_BMSK) |
MDIO_START | MDIO_RD_NWR;
writel(reg, adpt->base + EMAC_MDIO_CTRL);
if (readl_poll_timeout(adpt->base + EMAC_MDIO_CTRL, reg,
!(reg & (MDIO_START | MDIO_BUSY)),
100, MDIO_WAIT_TIMES * 100))
return -EIO;
return (reg >> MDIO_DATA_SHFT) & MDIO_DATA_BMSK;
}
static int emac_mdio_write(struct mii_bus *bus, int addr, int regnum, u16 val)
{
struct emac_adapter *adpt = bus->priv;
u32 reg;
emac_reg_update32(adpt->base + EMAC_PHY_STS, PHY_ADDR_BMSK,
(addr << PHY_ADDR_SHFT));
reg = SUP_PREAMBLE |
((MDIO_CLK_25_4 << MDIO_CLK_SEL_SHFT) & MDIO_CLK_SEL_BMSK) |
((regnum << MDIO_REG_ADDR_SHFT) & MDIO_REG_ADDR_BMSK) |
((val << MDIO_DATA_SHFT) & MDIO_DATA_BMSK) |
MDIO_START;
writel(reg, adpt->base + EMAC_MDIO_CTRL);
if (readl_poll_timeout(adpt->base + EMAC_MDIO_CTRL, reg,
!(reg & (MDIO_START | MDIO_BUSY)), 100,
MDIO_WAIT_TIMES * 100))
return -EIO;
return 0;
}
int emac_phy_config(struct platform_device *pdev, struct emac_adapter *adpt)
{
struct device_node *np = pdev->dev.of_node;
struct mii_bus *mii_bus;
int ret;
adpt->mii_bus = mii_bus = devm_mdiobus_alloc(&pdev->dev);
if (!mii_bus)
return -ENOMEM;
mii_bus->name = "emac-mdio";
snprintf(mii_bus->id, MII_BUS_ID_SIZE, "%s", pdev->name);
mii_bus->read = emac_mdio_read;
mii_bus->write = emac_mdio_write;
mii_bus->parent = &pdev->dev;
mii_bus->priv = adpt;
if (has_acpi_companion(&pdev->dev)) {
u32 phy_addr;
ret = mdiobus_register(mii_bus);
if (ret) {
dev_err(&pdev->dev, "could not register mdio bus\n");
return ret;
}
ret = device_property_read_u32(&pdev->dev, "phy-channel",
&phy_addr);
if (ret)
adpt->phydev = phy_find_first(mii_bus);
else
adpt->phydev = mdiobus_get_phy(mii_bus, phy_addr);
if (adpt->phydev)
get_device(&adpt->phydev->mdio.dev);
} else {
struct device_node *phy_np;
ret = of_mdiobus_register(mii_bus, np);
if (ret) {
dev_err(&pdev->dev, "could not register mdio bus\n");
return ret;
}
phy_np = of_parse_phandle(np, "phy-handle", 0);
adpt->phydev = of_phy_find_device(phy_np);
of_node_put(phy_np);
}
if (!adpt->phydev) {
dev_err(&pdev->dev, "could not find external phy\n");
mdiobus_unregister(mii_bus);
return -ENODEV;
}
return 0;
}
