static int smsc_phy_config_intr(struct phy_device *phydev)
{
int rc = phy_write (phydev, MII_LAN83C185_IM,
((PHY_INTERRUPT_ENABLED == phydev->interrupts)
? MII_LAN83C185_ISF_INT_PHYLIB_EVENTS
: 0));
return rc < 0 ? rc : 0;
}
static int smsc_phy_ack_interrupt(struct phy_device *phydev)
{
int rc = phy_read (phydev, MII_LAN83C185_ISF);
return rc < 0 ? rc : 0;
}
static int smsc_phy_config_init(struct phy_device *phydev)
{
struct smsc_phy_priv *priv = phydev->priv;
int rc = phy_read(phydev, MII_LAN83C185_CTRL_STATUS);
if (rc < 0)
return rc;
if (priv->energy_enable) {
rc = phy_write(phydev, MII_LAN83C185_CTRL_STATUS,
rc | MII_LAN83C185_EDPWRDOWN);
if (rc < 0)
return rc;
}
return smsc_phy_ack_interrupt(phydev);
}
static int smsc_phy_reset(struct phy_device *phydev)
{
int rc = phy_read(phydev, MII_LAN83C185_SPECIAL_MODES);
if (rc < 0)
return rc;
if ((rc & MII_LAN83C185_MODE_MASK) == MII_LAN83C185_MODE_POWERDOWN) {
rc |= MII_LAN83C185_MODE_ALL;
phy_write(phydev, MII_LAN83C185_SPECIAL_MODES, rc);
}
return genphy_soft_reset(phydev);
}
static int lan911x_config_init(struct phy_device *phydev)
{
return smsc_phy_ack_interrupt(phydev);
}
static int lan87xx_read_status(struct phy_device *phydev)
{
struct smsc_phy_priv *priv = phydev->priv;
int err = genphy_read_status(phydev);
if (!phydev->link && priv->energy_enable) {
int i;
int rc = phy_read(phydev, MII_LAN83C185_CTRL_STATUS);
if (rc < 0)
return rc;
rc = phy_write(phydev, MII_LAN83C185_CTRL_STATUS,
rc & ~MII_LAN83C185_EDPWRDOWN);
if (rc < 0)
return rc;
for (i = 0; i < 64; i++) {
msleep(10);
rc = phy_read(phydev, MII_LAN83C185_CTRL_STATUS);
if (rc < 0)
return rc;
if (rc & MII_LAN83C185_ENERGYON)
break;
}
rc = phy_read(phydev, MII_LAN83C185_CTRL_STATUS);
if (rc < 0)
return rc;
rc = phy_write(phydev, MII_LAN83C185_CTRL_STATUS,
rc | MII_LAN83C185_EDPWRDOWN);
if (rc < 0)
return rc;
}
return err;
}
static int smsc_phy_probe(struct phy_device *phydev)
{
struct device *dev = &phydev->mdio.dev;
struct device_node *of_node = dev->of_node;
struct smsc_phy_priv *priv;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->energy_enable = true;
if (of_property_read_bool(of_node, "smsc,disable-energy-detect"))
priv->energy_enable = false;
phydev->priv = priv;
return 0;
}
