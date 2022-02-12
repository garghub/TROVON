static int lan88xx_phy_config_intr(struct phy_device *phydev)
{
int rc;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
rc = phy_write(phydev, LAN88XX_INT_MASK, 0x7FFF);
rc = phy_read(phydev, LAN88XX_INT_STS);
rc = phy_write(phydev, LAN88XX_INT_MASK,
LAN88XX_INT_MASK_MDINTPIN_EN_ |
LAN88XX_INT_MASK_LINK_CHANGE_);
} else {
rc = phy_write(phydev, LAN88XX_INT_MASK, 0);
}
return rc < 0 ? rc : 0;
}
static int lan88xx_phy_ack_interrupt(struct phy_device *phydev)
{
int rc = phy_read(phydev, LAN88XX_INT_STS);
return rc < 0 ? rc : 0;
}
int lan88xx_suspend(struct phy_device *phydev)
{
struct lan88xx_priv *priv = phydev->priv;
if (!priv->wolopts)
genphy_suspend(phydev);
return 0;
}
static int lan88xx_probe(struct phy_device *phydev)
{
struct device *dev = &phydev->mdio.dev;
struct lan88xx_priv *priv;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->wolopts = 0;
priv->chip_id = phy_read_mmd_indirect(phydev, LAN88XX_MMD3_CHIP_ID, 3);
priv->chip_rev = phy_read_mmd_indirect(phydev, LAN88XX_MMD3_CHIP_REV,
3);
phydev->priv = priv;
return 0;
}
static void lan88xx_remove(struct phy_device *phydev)
{
struct device *dev = &phydev->mdio.dev;
struct lan88xx_priv *priv = phydev->priv;
if (priv)
devm_kfree(dev, priv);
}
static int lan88xx_set_wol(struct phy_device *phydev,
struct ethtool_wolinfo *wol)
{
struct lan88xx_priv *priv = phydev->priv;
priv->wolopts = wol->wolopts;
return 0;
}
