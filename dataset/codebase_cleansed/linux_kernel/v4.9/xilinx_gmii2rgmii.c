static int xgmiitorgmii_read_status(struct phy_device *phydev)
{
struct gmii2rgmii *priv = phydev->priv;
u16 val = 0;
priv->phy_drv->read_status(phydev);
val = mdiobus_read(phydev->mdio.bus, priv->addr, XILINX_GMII2RGMII_REG);
val &= XILINX_GMII2RGMII_SPEED_MASK;
if (phydev->speed == SPEED_1000)
val |= BMCR_SPEED1000;
else if (phydev->speed == SPEED_100)
val |= BMCR_SPEED100;
else
val |= BMCR_SPEED10;
mdiobus_write(phydev->mdio.bus, priv->addr, XILINX_GMII2RGMII_REG, val);
return 0;
}
static int xgmiitorgmii_probe(struct mdio_device *mdiodev)
{
struct device *dev = &mdiodev->dev;
struct device_node *np = dev->of_node, *phy_node;
struct gmii2rgmii *priv;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
phy_node = of_parse_phandle(np, "phy-handle", 0);
if (!phy_node) {
dev_err(dev, "Couldn't parse phy-handle\n");
return -ENODEV;
}
priv->phy_dev = of_phy_find_device(phy_node);
of_node_put(phy_node);
if (!priv->phy_dev) {
dev_info(dev, "Couldn't find phydev\n");
return -EPROBE_DEFER;
}
priv->addr = mdiodev->addr;
priv->phy_drv = priv->phy_dev->drv;
memcpy(&priv->conv_phy_drv, priv->phy_dev->drv,
sizeof(struct phy_driver));
priv->conv_phy_drv.read_status = xgmiitorgmii_read_status;
priv->phy_dev->priv = priv;
priv->phy_dev->drv = &priv->conv_phy_drv;
return 0;
}
