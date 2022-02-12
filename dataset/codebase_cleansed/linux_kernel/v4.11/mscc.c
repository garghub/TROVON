static int vsc85xx_phy_page_set(struct phy_device *phydev, u8 page)
{
int rc;
rc = phy_write(phydev, MSCC_EXT_PAGE_ACCESS, page);
return rc;
}
static int vsc85xx_led_cntl_set(struct phy_device *phydev,
u8 led_num,
u8 mode)
{
int rc;
u16 reg_val;
mutex_lock(&phydev->lock);
reg_val = phy_read(phydev, MSCC_PHY_LED_MODE_SEL);
if (led_num) {
reg_val &= ~LED_1_MODE_SEL_MASK;
reg_val |= (((u16)mode << LED_1_MODE_SEL_POS) &
LED_1_MODE_SEL_MASK);
} else {
reg_val &= ~LED_0_MODE_SEL_MASK;
reg_val |= ((u16)mode & LED_0_MODE_SEL_MASK);
}
rc = phy_write(phydev, MSCC_PHY_LED_MODE_SEL, reg_val);
mutex_unlock(&phydev->lock);
return rc;
}
static int vsc85xx_mdix_get(struct phy_device *phydev, u8 *mdix)
{
u16 reg_val;
reg_val = phy_read(phydev, MSCC_PHY_DEV_AUX_CNTL);
if (reg_val & HP_AUTO_MDIX_X_OVER_IND_MASK)
*mdix = ETH_TP_MDI_X;
else
*mdix = ETH_TP_MDI;
return 0;
}
static int vsc85xx_mdix_set(struct phy_device *phydev, u8 mdix)
{
int rc;
u16 reg_val;
reg_val = phy_read(phydev, MSCC_PHY_BYPASS_CONTROL);
if ((mdix == ETH_TP_MDI) || (mdix == ETH_TP_MDI_X)) {
reg_val |= (DISABLE_PAIR_SWAP_CORR_MASK |
DISABLE_POLARITY_CORR_MASK |
DISABLE_HP_AUTO_MDIX_MASK);
} else {
reg_val &= ~(DISABLE_PAIR_SWAP_CORR_MASK |
DISABLE_POLARITY_CORR_MASK |
DISABLE_HP_AUTO_MDIX_MASK);
}
rc = phy_write(phydev, MSCC_PHY_BYPASS_CONTROL, reg_val);
if (rc != 0)
return rc;
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED);
if (rc != 0)
return rc;
reg_val = phy_read(phydev, MSCC_PHY_EXT_MODE_CNTL);
reg_val &= ~(FORCE_MDI_CROSSOVER_MASK);
if (mdix == ETH_TP_MDI)
reg_val |= FORCE_MDI_CROSSOVER_MDI;
else if (mdix == ETH_TP_MDI_X)
reg_val |= FORCE_MDI_CROSSOVER_MDIX;
rc = phy_write(phydev, MSCC_PHY_EXT_MODE_CNTL, reg_val);
if (rc != 0)
return rc;
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
if (rc != 0)
return rc;
return genphy_restart_aneg(phydev);
}
static int vsc85xx_downshift_get(struct phy_device *phydev, u8 *count)
{
int rc;
u16 reg_val;
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED);
if (rc != 0)
goto out;
reg_val = phy_read(phydev, MSCC_PHY_ACTIPHY_CNTL);
reg_val &= DOWNSHIFT_CNTL_MASK;
if (!(reg_val & DOWNSHIFT_EN))
*count = DOWNSHIFT_DEV_DISABLE;
else
*count = ((reg_val & ~DOWNSHIFT_EN) >> DOWNSHIFT_CNTL_POS) + 2;
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
out:
return rc;
}
static int vsc85xx_downshift_set(struct phy_device *phydev, u8 count)
{
int rc;
u16 reg_val;
if (count == DOWNSHIFT_DEV_DEFAULT_COUNT) {
count = ((1 << DOWNSHIFT_CNTL_POS) | DOWNSHIFT_EN);
} else if (count > DOWNSHIFT_COUNT_MAX || count == 1) {
phydev_err(phydev, "Downshift count should be 2,3,4 or 5\n");
return -ERANGE;
} else if (count) {
count = (((count - 2) << DOWNSHIFT_CNTL_POS) | DOWNSHIFT_EN);
}
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED);
if (rc != 0)
goto out;
reg_val = phy_read(phydev, MSCC_PHY_ACTIPHY_CNTL);
reg_val &= ~(DOWNSHIFT_CNTL_MASK);
reg_val |= count;
rc = phy_write(phydev, MSCC_PHY_ACTIPHY_CNTL, reg_val);
if (rc != 0)
goto out;
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
out:
return rc;
}
static int vsc85xx_wol_set(struct phy_device *phydev,
struct ethtool_wolinfo *wol)
{
int rc;
u16 reg_val;
u8 i;
u16 pwd[3] = {0, 0, 0};
struct ethtool_wolinfo *wol_conf = wol;
u8 *mac_addr = phydev->attached_dev->dev_addr;
mutex_lock(&phydev->lock);
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED_2);
if (rc != 0)
goto out_unlock;
if (wol->wolopts & WAKE_MAGIC) {
for (i = 0; i < ARRAY_SIZE(pwd); i++)
pwd[i] = mac_addr[5 - (i * 2 + 1)] << 8 |
mac_addr[5 - i * 2];
phy_write(phydev, MSCC_PHY_WOL_LOWER_MAC_ADDR, pwd[0]);
phy_write(phydev, MSCC_PHY_WOL_MID_MAC_ADDR, pwd[1]);
phy_write(phydev, MSCC_PHY_WOL_UPPER_MAC_ADDR, pwd[2]);
} else {
phy_write(phydev, MSCC_PHY_WOL_LOWER_MAC_ADDR, 0);
phy_write(phydev, MSCC_PHY_WOL_MID_MAC_ADDR, 0);
phy_write(phydev, MSCC_PHY_WOL_UPPER_MAC_ADDR, 0);
}
if (wol_conf->wolopts & WAKE_MAGICSECURE) {
for (i = 0; i < ARRAY_SIZE(pwd); i++)
pwd[i] = wol_conf->sopass[5 - (i * 2 + 1)] << 8 |
wol_conf->sopass[5 - i * 2];
phy_write(phydev, MSCC_PHY_WOL_LOWER_PASSWD, pwd[0]);
phy_write(phydev, MSCC_PHY_WOL_MID_PASSWD, pwd[1]);
phy_write(phydev, MSCC_PHY_WOL_UPPER_PASSWD, pwd[2]);
} else {
phy_write(phydev, MSCC_PHY_WOL_LOWER_PASSWD, 0);
phy_write(phydev, MSCC_PHY_WOL_MID_PASSWD, 0);
phy_write(phydev, MSCC_PHY_WOL_UPPER_PASSWD, 0);
}
reg_val = phy_read(phydev, MSCC_PHY_WOL_MAC_CONTROL);
if (wol_conf->wolopts & WAKE_MAGICSECURE)
reg_val |= SECURE_ON_ENABLE;
else
reg_val &= ~SECURE_ON_ENABLE;
phy_write(phydev, MSCC_PHY_WOL_MAC_CONTROL, reg_val);
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
if (rc != 0)
goto out_unlock;
if (wol->wolopts & WAKE_MAGIC) {
reg_val = phy_read(phydev, MII_VSC85XX_INT_MASK);
reg_val |= MII_VSC85XX_INT_MASK_WOL;
rc = phy_write(phydev, MII_VSC85XX_INT_MASK, reg_val);
if (rc != 0)
goto out_unlock;
} else {
reg_val = phy_read(phydev, MII_VSC85XX_INT_MASK);
reg_val &= (~MII_VSC85XX_INT_MASK_WOL);
rc = phy_write(phydev, MII_VSC85XX_INT_MASK, reg_val);
if (rc != 0)
goto out_unlock;
}
reg_val = phy_read(phydev, MII_VSC85XX_INT_STATUS);
out_unlock:
mutex_unlock(&phydev->lock);
return rc;
}
static void vsc85xx_wol_get(struct phy_device *phydev,
struct ethtool_wolinfo *wol)
{
int rc;
u16 reg_val;
u8 i;
u16 pwd[3] = {0, 0, 0};
struct ethtool_wolinfo *wol_conf = wol;
mutex_lock(&phydev->lock);
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED_2);
if (rc != 0)
goto out_unlock;
reg_val = phy_read(phydev, MSCC_PHY_WOL_MAC_CONTROL);
if (reg_val & SECURE_ON_ENABLE)
wol_conf->wolopts |= WAKE_MAGICSECURE;
if (wol_conf->wolopts & WAKE_MAGICSECURE) {
pwd[0] = phy_read(phydev, MSCC_PHY_WOL_LOWER_PASSWD);
pwd[1] = phy_read(phydev, MSCC_PHY_WOL_MID_PASSWD);
pwd[2] = phy_read(phydev, MSCC_PHY_WOL_UPPER_PASSWD);
for (i = 0; i < ARRAY_SIZE(pwd); i++) {
wol_conf->sopass[5 - i * 2] = pwd[i] & 0x00ff;
wol_conf->sopass[5 - (i * 2 + 1)] = (pwd[i] & 0xff00)
>> 8;
}
}
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
out_unlock:
mutex_unlock(&phydev->lock);
}
static int vsc85xx_edge_rate_magic_get(struct phy_device *phydev)
{
u8 sd;
u16 vdd;
int rc, i, j;
struct device *dev = &phydev->mdio.dev;
struct device_node *of_node = dev->of_node;
u8 sd_array_size = ARRAY_SIZE(edge_table[0].slowdown);
if (!of_node)
return -ENODEV;
rc = of_property_read_u16(of_node, "vsc8531,vddmac", &vdd);
if (rc != 0)
vdd = MSCC_VDDMAC_3300;
rc = of_property_read_u8(of_node, "vsc8531,edge-slowdown", &sd);
if (rc != 0)
sd = 0;
for (i = 0; i < ARRAY_SIZE(edge_table); i++)
if (edge_table[i].vddmac == vdd)
for (j = 0; j < sd_array_size; j++)
if (edge_table[i].slowdown[j] == sd)
return (sd_array_size - j - 1);
return -EINVAL;
}
static int vsc85xx_dt_led_mode_get(struct phy_device *phydev,
char *led,
u8 default_mode)
{
struct device *dev = &phydev->mdio.dev;
struct device_node *of_node = dev->of_node;
u8 led_mode;
int err;
if (!of_node)
return -ENODEV;
led_mode = default_mode;
err = of_property_read_u8(of_node, led, &led_mode);
if (!err && (led_mode > 15 || led_mode == 7 || led_mode == 11)) {
phydev_err(phydev, "DT %s invalid\n", led);
return -EINVAL;
}
return led_mode;
}
static int vsc85xx_edge_rate_magic_get(struct phy_device *phydev)
{
return 0;
}
static int vsc85xx_dt_led_mode_get(struct phy_device *phydev,
char *led,
u8 default_mode)
{
return default_mode;
}
static int vsc85xx_edge_rate_cntl_set(struct phy_device *phydev, u8 edge_rate)
{
int rc;
u16 reg_val;
mutex_lock(&phydev->lock);
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED_2);
if (rc != 0)
goto out_unlock;
reg_val = phy_read(phydev, MSCC_PHY_WOL_MAC_CONTROL);
reg_val &= ~(EDGE_RATE_CNTL_MASK);
reg_val |= (edge_rate << EDGE_RATE_CNTL_POS);
rc = phy_write(phydev, MSCC_PHY_WOL_MAC_CONTROL, reg_val);
if (rc != 0)
goto out_unlock;
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
out_unlock:
mutex_unlock(&phydev->lock);
return rc;
}
static int vsc85xx_mac_if_set(struct phy_device *phydev,
phy_interface_t interface)
{
int rc;
u16 reg_val;
mutex_lock(&phydev->lock);
reg_val = phy_read(phydev, MSCC_PHY_EXT_PHY_CNTL_1);
reg_val &= ~(MAC_IF_SELECTION_MASK);
switch (interface) {
case PHY_INTERFACE_MODE_RGMII:
reg_val |= (MAC_IF_SELECTION_RGMII << MAC_IF_SELECTION_POS);
break;
case PHY_INTERFACE_MODE_RMII:
reg_val |= (MAC_IF_SELECTION_RMII << MAC_IF_SELECTION_POS);
break;
case PHY_INTERFACE_MODE_MII:
case PHY_INTERFACE_MODE_GMII:
reg_val |= (MAC_IF_SELECTION_GMII << MAC_IF_SELECTION_POS);
break;
default:
rc = -EINVAL;
goto out_unlock;
}
rc = phy_write(phydev, MSCC_PHY_EXT_PHY_CNTL_1, reg_val);
if (rc != 0)
goto out_unlock;
rc = genphy_soft_reset(phydev);
out_unlock:
mutex_unlock(&phydev->lock);
return rc;
}
static int vsc85xx_default_config(struct phy_device *phydev)
{
int rc;
u16 reg_val;
phydev->mdix_ctrl = ETH_TP_MDI_AUTO;
mutex_lock(&phydev->lock);
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_EXTENDED_2);
if (rc != 0)
goto out_unlock;
reg_val = phy_read(phydev, MSCC_PHY_RGMII_CNTL);
reg_val &= ~(RGMII_RX_CLK_DELAY_MASK);
reg_val |= (RGMII_RX_CLK_DELAY_1_1_NS << RGMII_RX_CLK_DELAY_POS);
phy_write(phydev, MSCC_PHY_RGMII_CNTL, reg_val);
rc = vsc85xx_phy_page_set(phydev, MSCC_PHY_PAGE_STANDARD);
out_unlock:
mutex_unlock(&phydev->lock);
return rc;
}
static int vsc85xx_get_tunable(struct phy_device *phydev,
struct ethtool_tunable *tuna, void *data)
{
switch (tuna->id) {
case ETHTOOL_PHY_DOWNSHIFT:
return vsc85xx_downshift_get(phydev, (u8 *)data);
default:
return -EINVAL;
}
}
static int vsc85xx_set_tunable(struct phy_device *phydev,
struct ethtool_tunable *tuna,
const void *data)
{
switch (tuna->id) {
case ETHTOOL_PHY_DOWNSHIFT:
return vsc85xx_downshift_set(phydev, *(u8 *)data);
default:
return -EINVAL;
}
}
static int vsc85xx_config_init(struct phy_device *phydev)
{
int rc;
struct vsc8531_private *vsc8531 = phydev->priv;
rc = vsc85xx_default_config(phydev);
if (rc)
return rc;
rc = vsc85xx_mac_if_set(phydev, phydev->interface);
if (rc)
return rc;
rc = vsc85xx_edge_rate_cntl_set(phydev, vsc8531->rate_magic);
if (rc)
return rc;
rc = vsc85xx_led_cntl_set(phydev, 1, vsc8531->led_1_mode);
if (rc)
return rc;
rc = vsc85xx_led_cntl_set(phydev, 0, vsc8531->led_0_mode);
if (rc)
return rc;
rc = genphy_config_init(phydev);
return rc;
}
static int vsc85xx_ack_interrupt(struct phy_device *phydev)
{
int rc = 0;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
rc = phy_read(phydev, MII_VSC85XX_INT_STATUS);
return (rc < 0) ? rc : 0;
}
static int vsc85xx_config_intr(struct phy_device *phydev)
{
int rc;
if (phydev->interrupts == PHY_INTERRUPT_ENABLED) {
rc = phy_write(phydev, MII_VSC85XX_INT_MASK,
MII_VSC85XX_INT_MASK_MASK);
} else {
rc = phy_write(phydev, MII_VSC85XX_INT_MASK, 0);
if (rc < 0)
return rc;
rc = phy_read(phydev, MII_VSC85XX_INT_STATUS);
}
return rc;
}
static int vsc85xx_config_aneg(struct phy_device *phydev)
{
int rc;
rc = vsc85xx_mdix_set(phydev, phydev->mdix_ctrl);
if (rc < 0)
return rc;
return genphy_config_aneg(phydev);
}
static int vsc85xx_read_status(struct phy_device *phydev)
{
int rc;
rc = vsc85xx_mdix_get(phydev, &phydev->mdix);
if (rc < 0)
return rc;
return genphy_read_status(phydev);
}
static int vsc85xx_probe(struct phy_device *phydev)
{
struct vsc8531_private *vsc8531;
int rate_magic;
int led_mode;
rate_magic = vsc85xx_edge_rate_magic_get(phydev);
if (rate_magic < 0)
return rate_magic;
vsc8531 = devm_kzalloc(&phydev->mdio.dev, sizeof(*vsc8531), GFP_KERNEL);
if (!vsc8531)
return -ENOMEM;
phydev->priv = vsc8531;
vsc8531->rate_magic = rate_magic;
led_mode = vsc85xx_dt_led_mode_get(phydev, "vsc8531,led-0-mode",
VSC8531_LINK_1000_ACTIVITY);
if (led_mode < 0)
return led_mode;
vsc8531->led_0_mode = led_mode;
led_mode = vsc85xx_dt_led_mode_get(phydev, "vsc8531,led-1-mode",
VSC8531_LINK_100_ACTIVITY);
if (led_mode < 0)
return led_mode;
vsc8531->led_1_mode = led_mode;
return 0;
}
