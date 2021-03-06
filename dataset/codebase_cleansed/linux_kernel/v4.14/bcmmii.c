void bcmgenet_mii_setup(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct phy_device *phydev = priv->phydev;
u32 reg, cmd_bits = 0;
bool status_changed = false;
if (priv->old_link != phydev->link) {
status_changed = true;
priv->old_link = phydev->link;
}
if (phydev->link) {
if (priv->old_speed != phydev->speed) {
status_changed = true;
priv->old_speed = phydev->speed;
}
if (priv->old_duplex != phydev->duplex) {
status_changed = true;
priv->old_duplex = phydev->duplex;
}
if (priv->old_pause != phydev->pause) {
status_changed = true;
priv->old_pause = phydev->pause;
}
if (!status_changed)
return;
if (phydev->speed == SPEED_1000)
cmd_bits = UMAC_SPEED_1000;
else if (phydev->speed == SPEED_100)
cmd_bits = UMAC_SPEED_100;
else
cmd_bits = UMAC_SPEED_10;
cmd_bits <<= CMD_SPEED_SHIFT;
if (phydev->duplex != DUPLEX_FULL)
cmd_bits |= CMD_HD_EN;
if (!phydev->pause)
cmd_bits |= CMD_RX_PAUSE_IGNORE | CMD_TX_PAUSE_IGNORE;
reg = bcmgenet_ext_readl(priv, EXT_RGMII_OOB_CTRL);
reg &= ~OOB_DISABLE;
reg |= RGMII_LINK;
bcmgenet_ext_writel(priv, reg, EXT_RGMII_OOB_CTRL);
reg = bcmgenet_umac_readl(priv, UMAC_CMD);
reg &= ~((CMD_SPEED_MASK << CMD_SPEED_SHIFT) |
CMD_HD_EN |
CMD_RX_PAUSE_IGNORE | CMD_TX_PAUSE_IGNORE);
reg |= cmd_bits;
bcmgenet_umac_writel(priv, reg, UMAC_CMD);
} else {
if (!status_changed)
return;
netif_carrier_off(dev);
}
phy_print_status(phydev);
}
static int bcmgenet_fixed_phy_link_update(struct net_device *dev,
struct fixed_phy_status *status)
{
if (dev && dev->phydev && status)
status->link = dev->phydev->link;
return 0;
}
void bcmgenet_mii_reset(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
if (GENET_IS_V4(priv))
return;
if (priv->phydev) {
phy_init_hw(priv->phydev);
phy_start_aneg(priv->phydev);
}
}
void bcmgenet_phy_power_set(struct net_device *dev, bool enable)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
u32 reg = 0;
if (GENET_IS_V4(priv)) {
reg = bcmgenet_ext_readl(priv, EXT_GPHY_CTRL);
if (enable) {
reg &= ~EXT_CK25_DIS;
bcmgenet_ext_writel(priv, reg, EXT_GPHY_CTRL);
mdelay(1);
reg &= ~(EXT_CFG_IDDQ_BIAS | EXT_CFG_PWR_DOWN);
reg |= EXT_GPHY_RESET;
bcmgenet_ext_writel(priv, reg, EXT_GPHY_CTRL);
mdelay(1);
reg &= ~EXT_GPHY_RESET;
} else {
reg |= EXT_CFG_IDDQ_BIAS | EXT_CFG_PWR_DOWN |
EXT_GPHY_RESET;
bcmgenet_ext_writel(priv, reg, EXT_GPHY_CTRL);
mdelay(1);
reg |= EXT_CK25_DIS;
}
bcmgenet_ext_writel(priv, reg, EXT_GPHY_CTRL);
udelay(60);
} else {
mdelay(1);
}
}
static void bcmgenet_moca_phy_setup(struct bcmgenet_priv *priv)
{
u32 reg;
if (!GENET_IS_V5(priv)) {
reg = bcmgenet_sys_readl(priv, SYS_PORT_CTRL);
reg |= LED_ACT_SOURCE_MAC;
bcmgenet_sys_writel(priv, reg, SYS_PORT_CTRL);
}
if (priv->hw_params->flags & GENET_HAS_MOCA_LINK_DET)
fixed_phy_set_link_update(priv->phydev,
bcmgenet_fixed_phy_link_update);
}
int bcmgenet_mii_config(struct net_device *dev, bool init)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct phy_device *phydev = priv->phydev;
struct device *kdev = &priv->pdev->dev;
const char *phy_name = NULL;
u32 id_mode_dis = 0;
u32 port_ctrl;
u32 reg;
priv->ext_phy = !priv->internal_phy &&
(priv->phy_interface != PHY_INTERFACE_MODE_MOCA);
switch (priv->phy_interface) {
case PHY_INTERFACE_MODE_INTERNAL:
case PHY_INTERFACE_MODE_MOCA:
if (GENET_IS_V4(priv))
port_ctrl = PORT_MODE_INT_GPHY;
else
port_ctrl = PORT_MODE_INT_EPHY;
bcmgenet_sys_writel(priv, port_ctrl, SYS_PORT_CTRL);
if (priv->internal_phy) {
phy_name = "internal PHY";
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
bcmgenet_sys_writel(priv,
PORT_MODE_EXT_GPHY, SYS_PORT_CTRL);
break;
default:
dev_err(kdev, "unknown phy mode: %d\n", priv->phy_interface);
return -EINVAL;
}
if (priv->ext_phy) {
reg = bcmgenet_ext_readl(priv, EXT_RGMII_OOB_CTRL);
reg |= RGMII_MODE_EN | id_mode_dis;
bcmgenet_ext_writel(priv, reg, EXT_RGMII_OOB_CTRL);
}
if (init)
dev_info(kdev, "configuring instance for %s\n", phy_name);
return 0;
}
int bcmgenet_mii_probe(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct device_node *dn = priv->pdev->dev.of_node;
struct phy_device *phydev;
u32 phy_flags;
int ret;
phy_flags = priv->gphy_rev;
priv->old_link = -1;
priv->old_speed = -1;
priv->old_duplex = -1;
priv->old_pause = -1;
if (dn) {
phydev = of_phy_connect(dev, priv->phy_dn, bcmgenet_mii_setup,
phy_flags, priv->phy_interface);
if (!phydev) {
pr_err("could not attach to PHY\n");
return -ENODEV;
}
} else {
phydev = priv->phydev;
phydev->dev_flags = phy_flags;
ret = phy_connect_direct(dev, phydev, bcmgenet_mii_setup,
priv->phy_interface);
if (ret) {
pr_err("could not attach to PHY\n");
return -ENODEV;
}
}
priv->phydev = phydev;
ret = bcmgenet_mii_config(dev, true);
if (ret) {
phy_disconnect(priv->phydev);
return ret;
}
phydev->advertising = phydev->supported;
if (priv->internal_phy)
priv->phydev->irq = PHY_IGNORE_INTERRUPT;
return 0;
}
static struct device_node *bcmgenet_mii_of_find_mdio(struct bcmgenet_priv *priv)
{
struct device_node *dn = priv->pdev->dev.of_node;
struct device *kdev = &priv->pdev->dev;
char *compat;
compat = kasprintf(GFP_KERNEL, "brcm,genet-mdio-v%d", priv->version);
if (!compat)
return NULL;
priv->mdio_dn = of_find_compatible_node(dn, NULL, compat);
kfree(compat);
if (!priv->mdio_dn) {
dev_err(kdev, "unable to find MDIO bus node\n");
return NULL;
}
return priv->mdio_dn;
}
static void bcmgenet_mii_pdata_init(struct bcmgenet_priv *priv,
struct unimac_mdio_pdata *ppd)
{
struct device *kdev = &priv->pdev->dev;
struct bcmgenet_platform_data *pd = kdev->platform_data;
if (pd->phy_interface != PHY_INTERFACE_MODE_MOCA && pd->mdio_enabled) {
if (pd->phy_address >= 0 && pd->phy_address < PHY_MAX_ADDR)
ppd->phy_mask = 1 << pd->phy_address;
else
ppd->phy_mask = 0;
}
}
static int bcmgenet_mii_wait(void *wait_func_data)
{
struct bcmgenet_priv *priv = wait_func_data;
wait_event_timeout(priv->wq,
!(bcmgenet_umac_readl(priv, UMAC_MDIO_CMD)
& MDIO_START_BUSY),
HZ / 100);
return 0;
}
static int bcmgenet_mii_register(struct bcmgenet_priv *priv)
{
struct platform_device *pdev = priv->pdev;
struct bcmgenet_platform_data *pdata = pdev->dev.platform_data;
struct device_node *dn = pdev->dev.of_node;
struct unimac_mdio_pdata ppd;
struct platform_device *ppdev;
struct resource *pres, res;
int id, ret;
pres = platform_get_resource(pdev, IORESOURCE_MEM, 0);
memset(&res, 0, sizeof(res));
memset(&ppd, 0, sizeof(ppd));
ppd.wait_func = bcmgenet_mii_wait;
ppd.wait_func_data = priv;
ppd.bus_name = "bcmgenet MII bus";
res.start = pres->start + GENET_UMAC_OFF + UMAC_MDIO_CMD;
res.end = res.start + 8;
res.flags = IORESOURCE_MEM;
if (dn)
id = of_alias_get_id(dn, "eth");
else
id = pdev->id;
ppdev = platform_device_alloc(UNIMAC_MDIO_DRV_NAME, id);
if (!ppdev)
return -ENOMEM;
priv->mii_pdev = ppdev;
ppdev->dev.parent = &pdev->dev;
ppdev->dev.of_node = bcmgenet_mii_of_find_mdio(priv);
if (pdata)
bcmgenet_mii_pdata_init(priv, &ppd);
ret = platform_device_add_resources(ppdev, &res, 1);
if (ret)
goto out;
ret = platform_device_add_data(ppdev, &ppd, sizeof(ppd));
if (ret)
goto out;
ret = platform_device_add(ppdev);
if (ret)
goto out;
return 0;
out:
platform_device_put(ppdev);
return ret;
}
static int bcmgenet_mii_of_init(struct bcmgenet_priv *priv)
{
struct device_node *dn = priv->pdev->dev.of_node;
struct device *kdev = &priv->pdev->dev;
struct phy_device *phydev;
int phy_mode;
int ret;
priv->phy_dn = of_parse_phandle(dn, "phy-handle", 0);
if (!priv->phy_dn && of_phy_is_fixed_link(dn)) {
ret = of_phy_register_fixed_link(dn);
if (ret)
return ret;
priv->phy_dn = of_node_get(dn);
}
phy_mode = of_get_phy_mode(dn);
if (phy_mode < 0) {
dev_err(kdev, "invalid PHY mode property\n");
return phy_mode;
}
priv->phy_interface = phy_mode;
if (priv->phy_interface == PHY_INTERFACE_MODE_INTERNAL)
priv->internal_phy = true;
if (phy_mode == PHY_INTERFACE_MODE_MOCA) {
phydev = of_phy_find_device(dn);
if (phydev) {
phydev->link = 0;
put_device(&phydev->mdio.dev);
}
}
return 0;
}
static int bcmgenet_mii_pd_init(struct bcmgenet_priv *priv)
{
struct device *kdev = &priv->pdev->dev;
struct bcmgenet_platform_data *pd = kdev->platform_data;
char phy_name[MII_BUS_ID_SIZE + 3];
char mdio_bus_id[MII_BUS_ID_SIZE];
struct phy_device *phydev;
snprintf(mdio_bus_id, MII_BUS_ID_SIZE, "%s-%d",
UNIMAC_MDIO_DRV_NAME, priv->pdev->id);
if (pd->phy_interface != PHY_INTERFACE_MODE_MOCA && pd->mdio_enabled) {
snprintf(phy_name, MII_BUS_ID_SIZE, PHY_ID_FMT,
mdio_bus_id, pd->phy_address);
phydev = phy_attach(priv->dev, phy_name, pd->phy_interface);
if (!phydev) {
dev_err(kdev, "failed to register PHY device\n");
return -ENODEV;
}
} else {
struct fixed_phy_status fphy_status = {
.link = 1,
.speed = pd->phy_speed,
.duplex = pd->phy_duplex,
.pause = 0,
.asym_pause = 0,
};
phydev = fixed_phy_register(PHY_POLL, &fphy_status, -1, NULL);
if (!phydev || IS_ERR(phydev)) {
dev_err(kdev, "failed to register fixed PHY device\n");
return -ENODEV;
}
phydev->link = 0;
}
priv->phydev = phydev;
priv->phy_interface = pd->phy_interface;
return 0;
}
static int bcmgenet_mii_bus_init(struct bcmgenet_priv *priv)
{
struct device_node *dn = priv->pdev->dev.of_node;
if (dn)
return bcmgenet_mii_of_init(priv);
else
return bcmgenet_mii_pd_init(priv);
}
int bcmgenet_mii_init(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
int ret;
ret = bcmgenet_mii_register(priv);
if (ret)
return ret;
ret = bcmgenet_mii_bus_init(priv);
if (ret)
goto out;
return 0;
out:
bcmgenet_mii_exit(dev);
return ret;
}
void bcmgenet_mii_exit(struct net_device *dev)
{
struct bcmgenet_priv *priv = netdev_priv(dev);
struct device_node *dn = priv->pdev->dev.of_node;
if (of_phy_is_fixed_link(dn))
of_phy_deregister_fixed_link(dn);
of_node_put(priv->phy_dn);
platform_device_unregister(priv->mii_pdev);
platform_device_put(priv->mii_pdev);
}
