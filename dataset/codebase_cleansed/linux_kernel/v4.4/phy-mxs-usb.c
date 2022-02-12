static inline bool is_imx6q_phy(struct mxs_phy *mxs_phy)
{
return mxs_phy->data == &imx6q_phy_data;
}
static inline bool is_imx6sl_phy(struct mxs_phy *mxs_phy)
{
return mxs_phy->data == &imx6sl_phy_data;
}
static void mxs_phy_clock_switch_delay(void)
{
usleep_range(300, 400);
}
static int mxs_phy_hw_init(struct mxs_phy *mxs_phy)
{
int ret;
void __iomem *base = mxs_phy->phy.io_priv;
ret = stmp_reset_block(base + HW_USBPHY_CTRL);
if (ret)
return ret;
writel(0, base + HW_USBPHY_PWD);
writel(BM_USBPHY_CTRL_ENAUTOSET_USBCLKS |
BM_USBPHY_CTRL_ENAUTOCLR_USBCLKGATE |
BM_USBPHY_CTRL_ENAUTOCLR_PHY_PWD |
BM_USBPHY_CTRL_ENAUTOCLR_CLKGATE |
BM_USBPHY_CTRL_ENAUTO_PWRON_PLL |
BM_USBPHY_CTRL_ENUTMILEVEL2 |
BM_USBPHY_CTRL_ENUTMILEVEL3,
base + HW_USBPHY_CTRL_SET);
if (mxs_phy->data->flags & MXS_PHY_NEED_IP_FIX)
writel(BM_USBPHY_IP_FIX, base + HW_USBPHY_IP_SET);
return 0;
}
static bool mxs_phy_get_vbus_status(struct mxs_phy *mxs_phy)
{
unsigned int vbus_value;
if (!mxs_phy->regmap_anatop)
return false;
if (mxs_phy->port_id == 0)
regmap_read(mxs_phy->regmap_anatop,
ANADIG_USB1_VBUS_DET_STAT,
&vbus_value);
else if (mxs_phy->port_id == 1)
regmap_read(mxs_phy->regmap_anatop,
ANADIG_USB2_VBUS_DET_STAT,
&vbus_value);
if (vbus_value & BM_ANADIG_USB1_VBUS_DET_STAT_VBUS_VALID)
return true;
else
return false;
}
static void __mxs_phy_disconnect_line(struct mxs_phy *mxs_phy, bool disconnect)
{
void __iomem *base = mxs_phy->phy.io_priv;
u32 reg;
if (disconnect)
writel_relaxed(BM_USBPHY_DEBUG_CLKGATE,
base + HW_USBPHY_DEBUG_CLR);
if (mxs_phy->port_id == 0) {
reg = disconnect ? ANADIG_USB1_LOOPBACK_SET
: ANADIG_USB1_LOOPBACK_CLR;
regmap_write(mxs_phy->regmap_anatop, reg,
BM_ANADIG_USB1_LOOPBACK_UTMI_DIG_TST1 |
BM_ANADIG_USB1_LOOPBACK_TSTI_TX_EN);
} else if (mxs_phy->port_id == 1) {
reg = disconnect ? ANADIG_USB2_LOOPBACK_SET
: ANADIG_USB2_LOOPBACK_CLR;
regmap_write(mxs_phy->regmap_anatop, reg,
BM_ANADIG_USB2_LOOPBACK_UTMI_DIG_TST1 |
BM_ANADIG_USB2_LOOPBACK_TSTI_TX_EN);
}
if (!disconnect)
writel_relaxed(BM_USBPHY_DEBUG_CLKGATE,
base + HW_USBPHY_DEBUG_SET);
if (disconnect)
usleep_range(500, 1000);
}
static bool mxs_phy_is_otg_host(struct mxs_phy *mxs_phy)
{
void __iomem *base = mxs_phy->phy.io_priv;
u32 phyctrl = readl(base + HW_USBPHY_CTRL);
if (IS_ENABLED(CONFIG_USB_OTG) &&
!(phyctrl & BM_USBPHY_CTRL_OTG_ID_VALUE))
return true;
return false;
}
static void mxs_phy_disconnect_line(struct mxs_phy *mxs_phy, bool on)
{
bool vbus_is_on = false;
if (!(mxs_phy->data->flags & MXS_PHY_DISCONNECT_LINE_WITHOUT_VBUS))
return;
if (!mxs_phy->regmap_anatop)
return;
vbus_is_on = mxs_phy_get_vbus_status(mxs_phy);
if (on && !vbus_is_on && !mxs_phy_is_otg_host(mxs_phy))
__mxs_phy_disconnect_line(mxs_phy, true);
else
__mxs_phy_disconnect_line(mxs_phy, false);
}
static int mxs_phy_init(struct usb_phy *phy)
{
int ret;
struct mxs_phy *mxs_phy = to_mxs_phy(phy);
mxs_phy_clock_switch_delay();
ret = clk_prepare_enable(mxs_phy->clk);
if (ret)
return ret;
return mxs_phy_hw_init(mxs_phy);
}
static void mxs_phy_shutdown(struct usb_phy *phy)
{
struct mxs_phy *mxs_phy = to_mxs_phy(phy);
u32 value = BM_USBPHY_CTRL_ENVBUSCHG_WKUP |
BM_USBPHY_CTRL_ENDPDMCHG_WKUP |
BM_USBPHY_CTRL_ENIDCHG_WKUP |
BM_USBPHY_CTRL_ENAUTOSET_USBCLKS |
BM_USBPHY_CTRL_ENAUTOCLR_USBCLKGATE |
BM_USBPHY_CTRL_ENAUTOCLR_PHY_PWD |
BM_USBPHY_CTRL_ENAUTOCLR_CLKGATE |
BM_USBPHY_CTRL_ENAUTO_PWRON_PLL;
writel(value, phy->io_priv + HW_USBPHY_CTRL_CLR);
writel(0xffffffff, phy->io_priv + HW_USBPHY_PWD);
writel(BM_USBPHY_CTRL_CLKGATE,
phy->io_priv + HW_USBPHY_CTRL_SET);
clk_disable_unprepare(mxs_phy->clk);
}
static bool mxs_phy_is_low_speed_connection(struct mxs_phy *mxs_phy)
{
unsigned int line_state;
unsigned int dp_bit = BM_ANADIG_USB1_MISC_RX_VPIN_FS,
dm_bit = BM_ANADIG_USB1_MISC_RX_VMIN_FS;
unsigned int reg = ANADIG_USB1_MISC;
if (!mxs_phy->regmap_anatop)
return false;
if (mxs_phy->port_id == 0)
reg = ANADIG_USB1_MISC;
else if (mxs_phy->port_id == 1)
reg = ANADIG_USB2_MISC;
regmap_read(mxs_phy->regmap_anatop, reg, &line_state);
if ((line_state & (dp_bit | dm_bit)) == dm_bit)
return true;
else
return false;
}
static int mxs_phy_suspend(struct usb_phy *x, int suspend)
{
int ret;
struct mxs_phy *mxs_phy = to_mxs_phy(x);
bool low_speed_connection, vbus_is_on;
low_speed_connection = mxs_phy_is_low_speed_connection(mxs_phy);
vbus_is_on = mxs_phy_get_vbus_status(mxs_phy);
if (suspend) {
if (low_speed_connection & vbus_is_on) {
mxs_phy_clock_switch_delay();
writel(0xffbfffff, x->io_priv + HW_USBPHY_PWD);
} else {
writel(0xffffffff, x->io_priv + HW_USBPHY_PWD);
}
writel(BM_USBPHY_CTRL_CLKGATE,
x->io_priv + HW_USBPHY_CTRL_SET);
clk_disable_unprepare(mxs_phy->clk);
} else {
mxs_phy_clock_switch_delay();
ret = clk_prepare_enable(mxs_phy->clk);
if (ret)
return ret;
writel(BM_USBPHY_CTRL_CLKGATE,
x->io_priv + HW_USBPHY_CTRL_CLR);
writel(0, x->io_priv + HW_USBPHY_PWD);
}
return 0;
}
static int mxs_phy_set_wakeup(struct usb_phy *x, bool enabled)
{
struct mxs_phy *mxs_phy = to_mxs_phy(x);
u32 value = BM_USBPHY_CTRL_ENVBUSCHG_WKUP |
BM_USBPHY_CTRL_ENDPDMCHG_WKUP |
BM_USBPHY_CTRL_ENIDCHG_WKUP;
if (enabled) {
mxs_phy_disconnect_line(mxs_phy, true);
writel_relaxed(value, x->io_priv + HW_USBPHY_CTRL_SET);
} else {
writel_relaxed(value, x->io_priv + HW_USBPHY_CTRL_CLR);
mxs_phy_disconnect_line(mxs_phy, false);
}
return 0;
}
static int mxs_phy_on_connect(struct usb_phy *phy,
enum usb_device_speed speed)
{
dev_dbg(phy->dev, "%s device has connected\n",
(speed == USB_SPEED_HIGH) ? "HS" : "FS/LS");
if (speed == USB_SPEED_HIGH)
writel(BM_USBPHY_CTRL_ENHOSTDISCONDETECT,
phy->io_priv + HW_USBPHY_CTRL_SET);
return 0;
}
static int mxs_phy_on_disconnect(struct usb_phy *phy,
enum usb_device_speed speed)
{
dev_dbg(phy->dev, "%s device has disconnected\n",
(speed == USB_SPEED_HIGH) ? "HS" : "FS/LS");
if (readl(phy->io_priv + HW_USBPHY_CTRL) &
BM_USBPHY_CTRL_ENHOSTDISCONDETECT)
writel(BM_USBPHY_CTRL_ENHOSTDISCONDETECT,
phy->io_priv + HW_USBPHY_CTRL_CLR);
return 0;
}
static int mxs_phy_probe(struct platform_device *pdev)
{
struct resource *res;
void __iomem *base;
struct clk *clk;
struct mxs_phy *mxs_phy;
int ret;
const struct of_device_id *of_id;
struct device_node *np = pdev->dev.of_node;
of_id = of_match_device(mxs_phy_dt_ids, &pdev->dev);
if (!of_id)
return -ENODEV;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
base = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
clk = devm_clk_get(&pdev->dev, NULL);
if (IS_ERR(clk)) {
dev_err(&pdev->dev,
"can't get the clock, err=%ld", PTR_ERR(clk));
return PTR_ERR(clk);
}
mxs_phy = devm_kzalloc(&pdev->dev, sizeof(*mxs_phy), GFP_KERNEL);
if (!mxs_phy)
return -ENOMEM;
if (of_get_property(np, "fsl,anatop", NULL)) {
mxs_phy->regmap_anatop = syscon_regmap_lookup_by_phandle
(np, "fsl,anatop");
if (IS_ERR(mxs_phy->regmap_anatop)) {
dev_dbg(&pdev->dev,
"failed to find regmap for anatop\n");
return PTR_ERR(mxs_phy->regmap_anatop);
}
}
ret = of_alias_get_id(np, "usbphy");
if (ret < 0)
dev_dbg(&pdev->dev, "failed to get alias id, errno %d\n", ret);
mxs_phy->port_id = ret;
mxs_phy->phy.io_priv = base;
mxs_phy->phy.dev = &pdev->dev;
mxs_phy->phy.label = DRIVER_NAME;
mxs_phy->phy.init = mxs_phy_init;
mxs_phy->phy.shutdown = mxs_phy_shutdown;
mxs_phy->phy.set_suspend = mxs_phy_suspend;
mxs_phy->phy.notify_connect = mxs_phy_on_connect;
mxs_phy->phy.notify_disconnect = mxs_phy_on_disconnect;
mxs_phy->phy.type = USB_PHY_TYPE_USB2;
mxs_phy->phy.set_wakeup = mxs_phy_set_wakeup;
mxs_phy->clk = clk;
mxs_phy->data = of_id->data;
platform_set_drvdata(pdev, mxs_phy);
device_set_wakeup_capable(&pdev->dev, true);
return usb_add_phy_dev(&mxs_phy->phy);
}
static int mxs_phy_remove(struct platform_device *pdev)
{
struct mxs_phy *mxs_phy = platform_get_drvdata(pdev);
usb_remove_phy(&mxs_phy->phy);
return 0;
}
static void mxs_phy_enable_ldo_in_suspend(struct mxs_phy *mxs_phy, bool on)
{
unsigned int reg = on ? ANADIG_ANA_MISC0_SET : ANADIG_ANA_MISC0_CLR;
if (!mxs_phy->regmap_anatop)
return;
if (is_imx6q_phy(mxs_phy))
regmap_write(mxs_phy->regmap_anatop, reg,
BM_ANADIG_ANA_MISC0_STOP_MODE_CONFIG);
else if (is_imx6sl_phy(mxs_phy))
regmap_write(mxs_phy->regmap_anatop,
reg, BM_ANADIG_ANA_MISC0_STOP_MODE_CONFIG_SL);
}
static int mxs_phy_system_suspend(struct device *dev)
{
struct mxs_phy *mxs_phy = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
mxs_phy_enable_ldo_in_suspend(mxs_phy, true);
return 0;
}
static int mxs_phy_system_resume(struct device *dev)
{
struct mxs_phy *mxs_phy = dev_get_drvdata(dev);
if (device_may_wakeup(dev))
mxs_phy_enable_ldo_in_suspend(mxs_phy, false);
return 0;
}
static int __init mxs_phy_module_init(void)
{
return platform_driver_register(&mxs_phy_driver);
}
static void __exit mxs_phy_module_exit(void)
{
platform_driver_unregister(&mxs_phy_driver);
}
