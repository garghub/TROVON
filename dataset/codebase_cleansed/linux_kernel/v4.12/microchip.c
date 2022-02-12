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
static int lan88xx_suspend(struct phy_device *phydev)
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
priv->chip_id = phy_read_mmd(phydev, 3, LAN88XX_MMD3_CHIP_ID);
priv->chip_rev = phy_read_mmd(phydev, 3, LAN88XX_MMD3_CHIP_REV);
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
static void lan88xx_set_mdix(struct phy_device *phydev)
{
int buf;
int val;
switch (phydev->mdix_ctrl) {
case ETH_TP_MDI:
val = LAN88XX_EXT_MODE_CTRL_MDI_;
break;
case ETH_TP_MDI_X:
val = LAN88XX_EXT_MODE_CTRL_MDI_X_;
break;
case ETH_TP_MDI_AUTO:
val = LAN88XX_EXT_MODE_CTRL_AUTO_MDIX_;
break;
default:
return;
}
phy_write(phydev, LAN88XX_EXT_PAGE_ACCESS, LAN88XX_EXT_PAGE_SPACE_1);
buf = phy_read(phydev, LAN88XX_EXT_MODE_CTRL);
buf &= ~LAN88XX_EXT_MODE_CTRL_MDIX_MASK_;
buf |= val;
phy_write(phydev, LAN88XX_EXT_MODE_CTRL, buf);
phy_write(phydev, LAN88XX_EXT_PAGE_ACCESS, LAN88XX_EXT_PAGE_SPACE_0);
}
static int lan88xx_config_aneg(struct phy_device *phydev)
{
lan88xx_set_mdix(phydev);
return genphy_config_aneg(phydev);
}
