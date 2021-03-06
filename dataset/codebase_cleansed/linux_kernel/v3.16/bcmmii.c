static int bcmgenet_mii_read(struct mii_bus *bus, int phy_id, int location)
{
int ret;
struct net_device *dev = bus->priv;
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 reg;
bcmgenet_umac_writel(priv, (MDIO_RD | (phy_id << MDIO_PMD_SHIFT) |
(location << MDIO_REG_SHIFT)), UMAC_MDIO_CMD);
reg = bcmgenet_umac_readl(priv, UMAC_MDIO_CMD);
reg |= MDIO_START_BUSY;
bcmgenet_umac_writel(priv, reg, UMAC_MDIO_CMD);
wait_event_timeout(priv->wq,
!(bcmgenet_umac_readl(priv, UMAC_MDIO_CMD)
& MDIO_START_BUSY),
HZ / 100);
ret = bcmgenet_umac_readl(priv, UMAC_MDIO_CMD);
if (ret & MDIO_READ_FAIL)
return -EIO;
return ret & 0xffff;
}
static int bcmgenet_mii_write(struct mii_bus *bus, int phy_id,
int location, u16 val)
{
struct net_device *dev = bus->priv;
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 reg;
bcmgenet_umac_writel(priv, (MDIO_WR | (phy_id << MDIO_PMD_SHIFT) |
(location << MDIO_REG_SHIFT) | (0xffff & val)),
UMAC_MDIO_CMD);
reg = bcmgenet_umac_readl(priv, UMAC_MDIO_CMD);
reg |= MDIO_START_BUSY;
bcmgenet_umac_writel(priv, reg, UMAC_MDIO_CMD);
wait_event_timeout(priv->wq,
!(bcmgenet_umac_readl(priv, UMAC_MDIO_CMD) &
MDIO_START_BUSY),
HZ / 100);
return 0;
}
static void bcmgenet_mii_setup(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct phy_device *phydev = priv->phydev;
u32 reg, cmd_bits = 0;
unsigned int status_changed = 0;
if (priv->old_link != phydev->link) {
status_changed = 1;
priv->old_link = phydev->link;
}
if (phydev->link) {
reg = bcmgenet_ext_readl(priv, EXT_RGMII_OOB_CTRL);
reg &= ~OOB_DISABLE;
reg |= RGMII_LINK;
bcmgenet_ext_writel(priv, reg, EXT_RGMII_OOB_CTRL);
if (phydev->speed == SPEED_1000)
cmd_bits = UMAC_SPEED_1000;
else if (phydev->speed == SPEED_100)
cmd_bits = UMAC_SPEED_100;
else
cmd_bits = UMAC_SPEED_10;
cmd_bits <<= CMD_SPEED_SHIFT;
if (priv->old_duplex != phydev->duplex) {
status_changed = 1;
priv->old_duplex = phydev->duplex;
}
if (phydev->duplex != DUPLEX_FULL)
cmd_bits |= CMD_HD_EN;
if (priv->old_pause != phydev->pause) {
status_changed = 1;
priv->old_pause = phydev->pause;
}
if (!phydev->pause)
cmd_bits |= CMD_RX_PAUSE_IGNORE | CMD_TX_PAUSE_IGNORE;
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
reg &= ~((CMD_SPEED_MASK << CMD_SPEED_SHIFT) |
CMD_HD_EN |
CMD_RX_PAUSE_IGNORE | CMD_TX_PAUSE_IGNORE);
reg |= cmd_bits;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
}
if (status_changed)
phy_print_status(phydev);
}
void bcmgenet_mii_reset(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
if (priv->phydev) {
phy_init_hw(priv->phydev);
phy_start_aneg(priv->phydev);
}
}
static void bcmgenet_ephy_power_up(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 reg = 0;
if (!GENET_IS_V4(priv))
return;
reg = bcmgenet_ext_readl(priv, EXT_GPHY_CTRL);
reg &= ~(EXT_CFG_IDDQ_BIAS | EXT_CFG_PWR_DOWN);
reg |= EXT_GPHY_RESET;
bcmgenet_ext_writel(priv, reg, EXT_GPHY_CTRL);
mdelay(2);
reg &= ~EXT_GPHY_RESET;
bcmgenet_ext_writel(priv, reg, EXT_GPHY_CTRL);
udelay(20);
}
static void bcmgenet_internal_phy_setup(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 reg;
bcmgenet_ephy_power_up(dev);
reg = bcmgenet_ext_readl(priv, EXT_EXT_PWR_MGMT);
reg |= EXT_PWR_DN_EN_LD;
bcmgenet_ext_writel(priv, reg, EXT_EXT_PWR_MGMT);
bcmgenet_mii_reset(dev);
}
static void bcmgenet_moca_phy_setup(struct bcmgenet_priv *priv)
{
u32 reg;
reg = bcmgenet_sys_readl(priv, SYS_PORT_CTRL);
reg |= LED_ACT_SOURCE_MAC;
bcmgenet_sys_writel(priv, reg, SYS_PORT_CTRL);
}
int bcmgenet_mii_config(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct phy_device *phydev = priv->phydev;
struct device *kdev = &priv->pdev->dev;
const char *phy_name = NULL;
u32 id_mode_dis = 0;
u32 port_ctrl;
u32 reg;
priv->ext_phy = !phy_is_internal(priv->phydev) &&
(priv->phy_interface != PHY_INTERFACE_MODE_MOCA);
if (phy_is_internal(priv->phydev))
priv->phy_interface = PHY_INTERFACE_MODE_NA;
switch (priv->phy_interface) {
case PHY_INTERFACE_MODE_NA:
case PHY_INTERFACE_MODE_MOCA:
if (GENET_IS_V4(priv))
port_ctrl = PORT_MODE_INT_GPHY;
else
port_ctrl = PORT_MODE_INT_EPHY;
bcmgenet_sys_writel(priv, port_ctrl, SYS_PORT_CTRL);
if (phy_is_internal(priv->phydev)) {
phy_name = "internal PHY";
bcmgenet_internal_phy_setup(dev);
} else if (priv->phy_interface == PHY_INTERFACE_MODE_MOCA) {
phy_name = "MoCA";
bcmgenet_moca_phy_setup(priv);
}
break;
case PHY_INTERFACE_MODE_MII:
phy_name = "external MII";
phydev->supported &= PHY_BASIC_FEATURES;
bcmgenet_sys_writel(priv,
PORT_MODE_EXT_EPHY, SYS_PORT_CTRL);
break;
case PHY_INTERFACE_MODE_REVMII:
phy_name = "external RvMII";
if ((priv->phydev->supported & PHY_BASIC_FEATURES) ==
PHY_BASIC_FEATURES)
port_ctrl = PORT_MODE_EXT_RVMII_25;
else
port_ctrl = PORT_MODE_EXT_RVMII_50;
bcmgenet_sys_writel(priv, port_ctrl, SYS_PORT_CTRL);
break;
case PHY_INTERFACE_MODE_RGMII:
id_mode_dis = BIT(16);
case PHY_INTERFACE_MODE_RGMII_TXID:
if (id_mode_dis)
phy_name = "external RGMII (no delay)";
else
phy_name = "external RGMII (TX delay)";
reg = bcmgenet_ext_readl(priv, EXT_RGMII_OOB_CTRL);
reg |= RGMII_MODE_EN | id_mode_dis;
bcmgenet_ext_writel(priv, reg, EXT_RGMII_OOB_CTRL);
bcmgenet_sys_writel(priv,
PORT_MODE_EXT_GPHY, SYS_PORT_CTRL);
break;
default:
dev_err(kdev, "unknown phy mode: %d\n", priv->phy_interface);
return -EINVAL;
}
dev_info(kdev, "configuring instance for %s\n", phy_name);
return 0;
}
static int bcmgenet_mii_probe(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct device_node *dn = priv->pdev->dev.of_node;
struct phy_device *phydev;
unsigned int phy_flags;
int ret;
if (priv->phydev) {
pr_info("PHY already attached\n");
return 0;
}
if (of_phy_is_fixed_link(dn)) {
ret = of_phy_register_fixed_link(dn);
if (ret)
return ret;
priv->phy_dn = dn;
}
phydev = of_phy_connect(dev, priv->phy_dn, bcmgenet_mii_setup, 0,
priv->phy_interface);
if (!phydev) {
pr_err("could not attach to PHY\n");
return -ENODEV;
}
priv->old_link = -1;
priv->old_duplex = -1;
priv->old_pause = -1;
priv->phydev = phydev;
ret = bcmgenet_mii_config(dev);
if (ret) {
phy_disconnect(priv->phydev);
return ret;
}
phy_flags = PHY_BRCM_100MBPS_WAR;
if ((phydev->supported & PHY_GBIT_FEATURES) || GENET_IS_V1(priv))
phy_flags = 0;
phydev->dev_flags |= phy_flags;
phydev->advertising = phydev->supported;
if (phy_is_internal(priv->phydev))
priv->mii_bus->irq[phydev->addr] = PHY_IGNORE_INTERRUPT;
else
priv->mii_bus->irq[phydev->addr] = PHY_POLL;
pr_info("attached PHY at address %d [%s]\n",
phydev->addr, phydev->drv->name);
return 0;
}
static int bcmgenet_mii_alloc(struct bcmgenet_priv *priv)
{
struct mii_bus *bus;
if (priv->mii_bus)
return 0;
priv->mii_bus = mdiobus_alloc();
if (!priv->mii_bus) {
pr_err("failed to allocate\n");
return -ENOMEM;
}
bus = priv->mii_bus;
bus->priv = priv->dev;
bus->name = "bcmgenet MII bus";
bus->parent = &priv->pdev->dev;
bus->read = bcmgenet_mii_read;
bus->write = bcmgenet_mii_write;
snprintf(bus->id, MII_BUS_ID_SIZE, "%s-%d",
priv->pdev->name, priv->pdev->id);
bus->irq = kzalloc(sizeof(int) * PHY_MAX_ADDR, GFP_KERNEL);
if (!bus->irq) {
mdiobus_free(priv->mii_bus);
return -ENOMEM;
}
return 0;
}
static int bcmgenet_mii_of_init(struct bcmgenet_priv *priv)
{
struct device_node *dn = priv->pdev->dev.of_node;
struct device *kdev = &priv->pdev->dev;
struct device_node *mdio_dn;
char *compat;
int ret;
compat = kasprintf(GFP_KERNEL, "brcm,genet-mdio-v%d", priv->version);
if (!compat)
return -ENOMEM;
mdio_dn = of_find_compatible_node(dn, NULL, compat);
kfree(compat);
if (!mdio_dn) {
dev_err(kdev, "unable to find MDIO bus node\n");
return -ENODEV;
}
ret = of_mdiobus_register(priv->mii_bus, mdio_dn);
if (ret) {
dev_err(kdev, "failed to register MDIO bus\n");
return ret;
}
priv->phy_dn = of_parse_phandle(dn, "phy-handle", 0);
priv->phy_interface = of_get_phy_mode(dn);
return 0;
}
int bcmgenet_mii_init(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
int ret;
ret = bcmgenet_mii_alloc(priv);
if (ret)
return ret;
ret = bcmgenet_mii_of_init(priv);
if (ret)
goto out_free;
ret = bcmgenet_mii_probe(dev);
if (ret)
goto out;
return 0;
out:
mdiobus_unregister(priv->mii_bus);
out_free:
kfree(priv->mii_bus->irq);
mdiobus_free(priv->mii_bus);
return ret;
}
void bcmgenet_mii_exit(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
mdiobus_unregister(priv->mii_bus);
kfree(priv->mii_bus->irq);
mdiobus_free(priv->mii_bus);
}
