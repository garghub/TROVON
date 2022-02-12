static void at803x_context_save(struct phy_device *phydev,
struct at803x_context *context)
{
context->bmcr = phy_read(phydev, MII_BMCR);
context->advertise = phy_read(phydev, MII_ADVERTISE);
context->control1000 = phy_read(phydev, MII_CTRL1000);
context->int_enable = phy_read(phydev, AT803X_INTR_ENABLE);
context->smart_speed = phy_read(phydev, AT803X_SMART_SPEED);
context->led_control = phy_read(phydev, AT803X_LED_CONTROL);
}
static void at803x_context_restore(struct phy_device *phydev,
const struct at803x_context *context)
{
phy_write(phydev, MII_BMCR, context->bmcr);
phy_write(phydev, MII_ADVERTISE, context->advertise);
phy_write(phydev, MII_CTRL1000, context->control1000);
phy_write(phydev, AT803X_INTR_ENABLE, context->int_enable);
phy_write(phydev, AT803X_SMART_SPEED, context->smart_speed);
phy_write(phydev, AT803X_LED_CONTROL, context->led_control);
}
static int at803x_set_wol(struct phy_device *phydev,
struct ethtool_wolinfo *wol)
{
struct net_device *ndev = phydev->attached_dev;
const u8 *mac;
int ret;
u32 value;
unsigned int i, offsets[] = {
AT803X_LOC_MAC_ADDR_32_47_OFFSET,
AT803X_LOC_MAC_ADDR_16_31_OFFSET,
AT803X_LOC_MAC_ADDR_0_15_OFFSET,
};
if (!ndev)
return -ENODEV;
if (wol->wolopts & WAKE_MAGIC) {
mac = (const u8 *) ndev->dev_addr;
if (!is_valid_ether_addr(mac))
return -EFAULT;
for (i = 0; i < 3; i++) {
phy_write(phydev, AT803X_MMD_ACCESS_CONTROL,
AT803X_DEVICE_ADDR);
phy_write(phydev, AT803X_MMD_ACCESS_CONTROL_DATA,
offsets[i]);
phy_write(phydev, AT803X_MMD_ACCESS_CONTROL,
AT803X_FUNC_DATA);
phy_write(phydev, AT803X_MMD_ACCESS_CONTROL_DATA,
mac[(i * 2) + 1] | (mac[(i * 2)] << 8));
}
value = phy_read(phydev, AT803X_INTR_ENABLE);
value |= AT803X_WOL_ENABLE;
ret = phy_write(phydev, AT803X_INTR_ENABLE, value);
if (ret)
return ret;
value = phy_read(phydev, AT803X_INTR_STATUS);
} else {
value = phy_read(phydev, AT803X_INTR_ENABLE);
value &= (~AT803X_WOL_ENABLE);
ret = phy_write(phydev, AT803X_INTR_ENABLE, value);
if (ret)
return ret;
value = phy_read(phydev, AT803X_INTR_STATUS);
}
return ret;
}
static void at803x_get_wol(struct phy_device *phydev,
struct ethtool_wolinfo *wol)
{
u32 value;
wol->supported = WAKE_MAGIC;
wol->wolopts = 0;
value = phy_read(phydev, AT803X_INTR_ENABLE);
if (value & AT803X_WOL_ENABLE)
wol->wolopts |= WAKE_MAGIC;
}
static int at803x_suspend(struct phy_device *phydev)
{
int value;
int wol_enabled;
mutex_lock(&phydev->lock);
value = phy_read(phydev, AT803X_INTR_ENABLE);
wol_enabled = value & AT803X_WOL_ENABLE;
value = phy_read(phydev, MII_BMCR);
if (wol_enabled)
value |= BMCR_ISOLATE;
else
value |= BMCR_PDOWN;
phy_write(phydev, MII_BMCR, value);
mutex_unlock(&phydev->lock);
return 0;
}
static int at803x_resume(struct phy_device *phydev)
{
int value;
mutex_lock(&phydev->lock);
value = phy_read(phydev, MII_BMCR);
value &= ~(BMCR_PDOWN | BMCR_ISOLATE);
phy_write(phydev, MII_BMCR, value);
mutex_unlock(&phydev->lock);
return 0;
}
static int at803x_probe(struct phy_device *phydev)
{
struct device *dev = &phydev->dev;
struct at803x_priv *priv;
priv = devm_kzalloc(dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
priv->gpiod_reset = devm_gpiod_get(dev, "reset");
if (IS_ERR(priv->gpiod_reset))
priv->gpiod_reset = NULL;
else
gpiod_direction_output(priv->gpiod_reset, 1);
phydev->priv = priv;
return 0;
}
static int at803x_config_init(struct phy_device *phydev)
{
int ret;
ret = genphy_config_init(phydev);
if (ret < 0)
return ret;
if (phydev->interface == PHY_INTERFACE_MODE_RGMII_TXID) {
ret = phy_write(phydev, AT803X_DEBUG_ADDR,
AT803X_DEBUG_SYSTEM_MODE_CTRL);
if (ret)
return ret;
ret = phy_write(phydev, AT803X_DEBUG_DATA,
AT803X_DEBUG_RGMII_TX_CLK_DLY);
if (ret)
return ret;
}
return 0;
}
static int at803x_ack_interrupt(struct phy_device *phydev)
{
int err;
err = phy_read(phydev, AT803X_INSR);
return (err < 0) ? err : 0;
}
static int at803x_config_intr(struct phy_device *phydev)
{
int err;
int value;
value = phy_read(phydev, AT803X_INER);
if (phydev->interrupts == PHY_INTERRUPT_ENABLED)
err = phy_write(phydev, AT803X_INER,
value | AT803X_INER_INIT);
else
err = phy_write(phydev, AT803X_INER, 0);
return err;
}
static void at803x_link_change_notify(struct phy_device *phydev)
{
struct at803x_priv *priv = phydev->priv;
if (phydev->drv->phy_id == ATH8030_PHY_ID) {
if (phydev->state == PHY_NOLINK) {
if (priv->gpiod_reset && !priv->phy_reset) {
struct at803x_context context;
at803x_context_save(phydev, &context);
gpiod_set_value(priv->gpiod_reset, 0);
msleep(1);
gpiod_set_value(priv->gpiod_reset, 1);
msleep(1);
at803x_context_restore(phydev, &context);
dev_dbg(&phydev->dev, "%s(): phy was reset\n",
__func__);
priv->phy_reset = true;
}
} else {
priv->phy_reset = false;
}
}
}
