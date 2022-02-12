static void tcphy_cfg_24m(struct rockchip_typec_phy *tcphy)
{
u32 i, rdata;
writel(0x830, tcphy->base + PMA_CMN_CTRL1);
for (i = 0; i < 4; i++) {
writel(0x90, tcphy->base + XCVR_DIAG_LANE_FCM_EN_MGN(i));
writel(0x960, tcphy->base + TX_RCVDET_EN_TMR(i));
writel(0x30, tcphy->base + TX_RCVDET_ST_TMR(i));
}
rdata = readl(tcphy->base + CMN_DIAG_HSCLK_SEL);
rdata &= ~CLK_PLL_MASK;
rdata |= CLK_PLL_CONFIG;
writel(rdata, tcphy->base + CMN_DIAG_HSCLK_SEL);
}
static void tcphy_cfg_usb3_pll(struct rockchip_typec_phy *tcphy)
{
u32 i;
for (i = 0; i < ARRAY_SIZE(usb3_pll_cfg); i++)
writel(usb3_pll_cfg[i].value,
tcphy->base + usb3_pll_cfg[i].addr);
}
static void tcphy_cfg_dp_pll(struct rockchip_typec_phy *tcphy)
{
u32 i;
writel(DP_PLL_CLOCK_ENABLE | DP_PLL_ENABLE | DP_PLL_DATA_RATE_RBR,
tcphy->base + DP_CLK_CTL);
for (i = 0; i < ARRAY_SIZE(dp_pll_cfg); i++)
writel(dp_pll_cfg[i].value, tcphy->base + dp_pll_cfg[i].addr);
}
static void tcphy_tx_usb3_cfg_lane(struct rockchip_typec_phy *tcphy, u32 lane)
{
writel(0x7799, tcphy->base + TX_PSC_A0(lane));
writel(0x7798, tcphy->base + TX_PSC_A1(lane));
writel(0x5098, tcphy->base + TX_PSC_A2(lane));
writel(0x5098, tcphy->base + TX_PSC_A3(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_000(lane));
writel(0xbf, tcphy->base + XCVR_DIAG_BIDI_CTRL(lane));
}
static void tcphy_rx_usb3_cfg_lane(struct rockchip_typec_phy *tcphy, u32 lane)
{
writel(0xa6fd, tcphy->base + RX_PSC_A0(lane));
writel(0xa6fd, tcphy->base + RX_PSC_A1(lane));
writel(0xa410, tcphy->base + RX_PSC_A2(lane));
writel(0x2410, tcphy->base + RX_PSC_A3(lane));
writel(0x23ff, tcphy->base + RX_PSC_CAL(lane));
writel(0x13, tcphy->base + RX_SIGDET_HL_FILT_TMR(lane));
writel(0x03e7, tcphy->base + RX_REE_CTRL_DATA_MASK(lane));
writel(0x1004, tcphy->base + RX_DIAG_SIGDET_TUNE(lane));
writel(0x2010, tcphy->base + RX_PSC_RDY(lane));
writel(0xfb, tcphy->base + XCVR_DIAG_BIDI_CTRL(lane));
}
static void tcphy_dp_cfg_lane(struct rockchip_typec_phy *tcphy, u32 lane)
{
u16 rdata;
writel(0xbefc, tcphy->base + XCVR_PSM_RCTRL(lane));
writel(0x6799, tcphy->base + TX_PSC_A0(lane));
writel(0x6798, tcphy->base + TX_PSC_A1(lane));
writel(0x98, tcphy->base + TX_PSC_A2(lane));
writel(0x98, tcphy->base + TX_PSC_A3(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_000(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_001(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_010(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_011(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_100(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_101(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_110(lane));
writel(0, tcphy->base + TX_TXCC_MGNFS_MULT_111(lane));
writel(0, tcphy->base + TX_TXCC_CPOST_MULT_10(lane));
writel(0, tcphy->base + TX_TXCC_CPOST_MULT_01(lane));
writel(0, tcphy->base + TX_TXCC_CPOST_MULT_00(lane));
writel(0, tcphy->base + TX_TXCC_CPOST_MULT_11(lane));
writel(0x128, tcphy->base + TX_TXCC_CAL_SCLR_MULT(lane));
writel(0x400, tcphy->base + TX_DIAG_TX_DRV(lane));
rdata = readl(tcphy->base + XCVR_DIAG_PLLDRC_CTRL(lane));
rdata = (rdata & 0x8fff) | 0x6000;
writel(rdata, tcphy->base + XCVR_DIAG_PLLDRC_CTRL(lane));
}
static inline int property_enable(struct rockchip_typec_phy *tcphy,
const struct usb3phy_reg *reg, bool en)
{
u32 mask = 1 << reg->write_enable;
u32 val = en << reg->enable_bit;
return regmap_write(tcphy->grf_regs, reg->offset, val | mask);
}
static void tcphy_dp_aux_calibration(struct rockchip_typec_phy *tcphy)
{
u16 rdata, rdata2, val;
rdata = readl(tcphy->base + TX_ANA_CTRL_REG_1);
val = rdata & 0xdfff;
writel(val, tcphy->base + TX_ANA_CTRL_REG_1);
rdata = readl(tcphy->base + TX_DIG_CTRL_REG_2);
rdata = rdata & 0xffc0;
rdata2 = readl(tcphy->base + CMN_TXPUCAL_CTRL);
rdata2 = rdata2 & 0x3f;
val = rdata | rdata2;
writel(val, tcphy->base + TX_DIG_CTRL_REG_2);
usleep_range(1000, 1050);
rdata = readl(tcphy->base + TX_ANA_CTRL_REG_1);
val = rdata | 0x2000;
writel(val, tcphy->base + TX_ANA_CTRL_REG_1);
usleep_range(150, 200);
writel(0, tcphy->base + PHY_DP_TX_CTL);
writel(0x100, tcphy->base + TX_ANA_CTRL_REG_2);
writel(0x300, tcphy->base + TX_ANA_CTRL_REG_2);
writel(0x2008, tcphy->base + TX_ANA_CTRL_REG_1);
writel(0x2018, tcphy->base + TX_ANA_CTRL_REG_1);
writel(0, tcphy->base + TX_ANA_CTRL_REG_5);
writel(0x1001, tcphy->base + TX_ANA_CTRL_REG_4);
writel(0x2098, tcphy->base + TX_ANA_CTRL_REG_1);
writel(0x2198, tcphy->base + TX_ANA_CTRL_REG_1);
writel(0x301, tcphy->base + TX_ANA_CTRL_REG_2);
writel(0x303, tcphy->base + TX_ANA_CTRL_REG_2);
val = 0xa078;
if (!tcphy->flip)
val |= BIT(12);
writel(val, tcphy->base + TX_ANA_CTRL_REG_1);
writel(0, tcphy->base + TX_ANA_CTRL_REG_3);
writel(0, tcphy->base + TX_ANA_CTRL_REG_4);
writel(0, tcphy->base + TX_ANA_CTRL_REG_5);
writel(4, tcphy->base + TXDA_COEFF_CALC_CTRL);
writel(0, tcphy->base + TXDA_CYA_AUXDA_CYA);
val = readl(tcphy->base + TX_DIG_CTRL_REG_2);
val |= BIT(15);
writel(val, tcphy->base + TX_DIG_CTRL_REG_2);
}
static int tcphy_phy_init(struct rockchip_typec_phy *tcphy, u8 mode)
{
struct rockchip_usb3phy_port_cfg *cfg = &tcphy->port_cfgs;
int ret, i;
u32 val;
ret = clk_prepare_enable(tcphy->clk_core);
if (ret) {
dev_err(tcphy->dev, "Failed to prepare_enable core clock\n");
return ret;
}
ret = clk_prepare_enable(tcphy->clk_ref);
if (ret) {
dev_err(tcphy->dev, "Failed to prepare_enable ref clock\n");
goto err_clk_core;
}
reset_control_deassert(tcphy->tcphy_rst);
property_enable(tcphy, &cfg->typec_conn_dir, tcphy->flip);
tcphy_cfg_24m(tcphy);
if (mode == MODE_DFP_DP) {
tcphy_cfg_dp_pll(tcphy);
for (i = 0; i < 4; i++)
tcphy_dp_cfg_lane(tcphy, i);
writel(PIN_ASSIGN_C_E, tcphy->base + PMA_LANE_CFG);
} else {
tcphy_cfg_usb3_pll(tcphy);
tcphy_cfg_dp_pll(tcphy);
if (tcphy->flip) {
tcphy_tx_usb3_cfg_lane(tcphy, 3);
tcphy_rx_usb3_cfg_lane(tcphy, 2);
tcphy_dp_cfg_lane(tcphy, 0);
tcphy_dp_cfg_lane(tcphy, 1);
} else {
tcphy_tx_usb3_cfg_lane(tcphy, 0);
tcphy_rx_usb3_cfg_lane(tcphy, 1);
tcphy_dp_cfg_lane(tcphy, 2);
tcphy_dp_cfg_lane(tcphy, 3);
}
writel(PIN_ASSIGN_D_F, tcphy->base + PMA_LANE_CFG);
}
writel(DP_MODE_ENTER_A2, tcphy->base + DP_MODE_CTL);
reset_control_deassert(tcphy->uphy_rst);
ret = readx_poll_timeout(readl, tcphy->base + PMA_CMN_CTRL1,
val, val & CMN_READY, 10,
PHY_MODE_SET_TIMEOUT);
if (ret < 0) {
dev_err(tcphy->dev, "wait pma ready timeout\n");
ret = -ETIMEDOUT;
goto err_wait_pma;
}
reset_control_deassert(tcphy->pipe_rst);
return 0;
err_wait_pma:
reset_control_assert(tcphy->uphy_rst);
reset_control_assert(tcphy->tcphy_rst);
clk_disable_unprepare(tcphy->clk_ref);
err_clk_core:
clk_disable_unprepare(tcphy->clk_core);
return ret;
}
static void tcphy_phy_deinit(struct rockchip_typec_phy *tcphy)
{
reset_control_assert(tcphy->tcphy_rst);
reset_control_assert(tcphy->uphy_rst);
reset_control_assert(tcphy->pipe_rst);
clk_disable_unprepare(tcphy->clk_core);
clk_disable_unprepare(tcphy->clk_ref);
}
static int tcphy_get_mode(struct rockchip_typec_phy *tcphy)
{
struct extcon_dev *edev = tcphy->extcon;
union extcon_property_value property;
unsigned int id;
bool dfp, ufp, dp;
u8 mode;
int ret;
ufp = extcon_get_state(edev, EXTCON_USB);
dfp = extcon_get_state(edev, EXTCON_USB_HOST);
dp = extcon_get_state(edev, EXTCON_DISP_DP);
mode = MODE_DFP_USB;
id = EXTCON_USB_HOST;
if (ufp) {
mode = MODE_UFP_USB;
id = EXTCON_USB;
} else if (dp) {
mode = MODE_DFP_DP;
id = EXTCON_DISP_DP;
ret = extcon_get_property(edev, id, EXTCON_PROP_USB_SS,
&property);
if (ret) {
dev_err(tcphy->dev, "get superspeed property failed\n");
return ret;
}
if (property.intval)
mode |= MODE_DFP_USB;
}
ret = extcon_get_property(edev, id, EXTCON_PROP_USB_TYPEC_POLARITY,
&property);
if (ret) {
dev_err(tcphy->dev, "get polarity property failed\n");
return ret;
}
tcphy->flip = property.intval ? 1 : 0;
return mode;
}
static int rockchip_usb3_phy_power_on(struct phy *phy)
{
struct rockchip_typec_phy *tcphy = phy_get_drvdata(phy);
struct rockchip_usb3phy_port_cfg *cfg = &tcphy->port_cfgs;
const struct usb3phy_reg *reg = &cfg->pipe_status;
int timeout, new_mode, ret = 0;
u32 val;
mutex_lock(&tcphy->lock);
new_mode = tcphy_get_mode(tcphy);
if (new_mode < 0) {
ret = new_mode;
goto unlock_ret;
}
if (!(new_mode & (MODE_DFP_USB | MODE_UFP_USB)))
goto unlock_ret;
if (tcphy->mode == new_mode)
goto unlock_ret;
if (tcphy->mode == MODE_DISCONNECT)
tcphy_phy_init(tcphy, new_mode);
for (timeout = 0; timeout < 100; timeout++) {
regmap_read(tcphy->grf_regs, reg->offset, &val);
if (!(val & BIT(reg->enable_bit))) {
tcphy->mode |= new_mode & (MODE_DFP_USB | MODE_UFP_USB);
goto unlock_ret;
}
usleep_range(10, 20);
}
if (tcphy->mode == MODE_DISCONNECT)
tcphy_phy_deinit(tcphy);
ret = -ETIMEDOUT;
unlock_ret:
mutex_unlock(&tcphy->lock);
return ret;
}
static int rockchip_usb3_phy_power_off(struct phy *phy)
{
struct rockchip_typec_phy *tcphy = phy_get_drvdata(phy);
mutex_lock(&tcphy->lock);
if (tcphy->mode == MODE_DISCONNECT)
goto unlock;
tcphy->mode &= ~(MODE_UFP_USB | MODE_DFP_USB);
if (tcphy->mode == MODE_DISCONNECT)
tcphy_phy_deinit(tcphy);
unlock:
mutex_unlock(&tcphy->lock);
return 0;
}
static int rockchip_dp_phy_power_on(struct phy *phy)
{
struct rockchip_typec_phy *tcphy = phy_get_drvdata(phy);
int new_mode, ret = 0;
u32 val;
mutex_lock(&tcphy->lock);
new_mode = tcphy_get_mode(tcphy);
if (new_mode < 0) {
ret = new_mode;
goto unlock_ret;
}
if (!(new_mode & MODE_DFP_DP)) {
ret = -ENODEV;
goto unlock_ret;
}
if (tcphy->mode == new_mode)
goto unlock_ret;
if (new_mode == MODE_DFP_DP && tcphy->mode != MODE_DISCONNECT) {
tcphy_phy_deinit(tcphy);
tcphy_phy_init(tcphy, new_mode);
} else if (tcphy->mode == MODE_DISCONNECT) {
tcphy_phy_init(tcphy, new_mode);
}
ret = readx_poll_timeout(readl, tcphy->base + DP_MODE_CTL,
val, val & DP_MODE_A2, 1000,
PHY_MODE_SET_TIMEOUT);
if (ret < 0) {
dev_err(tcphy->dev, "failed to wait TCPHY enter A2\n");
goto power_on_finish;
}
tcphy_dp_aux_calibration(tcphy);
writel(DP_MODE_ENTER_A0, tcphy->base + DP_MODE_CTL);
ret = readx_poll_timeout(readl, tcphy->base + DP_MODE_CTL,
val, val & DP_MODE_A0, 1000,
PHY_MODE_SET_TIMEOUT);
if (ret < 0) {
writel(DP_MODE_ENTER_A2, tcphy->base + DP_MODE_CTL);
dev_err(tcphy->dev, "failed to wait TCPHY enter A0\n");
goto power_on_finish;
}
tcphy->mode |= MODE_DFP_DP;
power_on_finish:
if (tcphy->mode == MODE_DISCONNECT)
tcphy_phy_deinit(tcphy);
unlock_ret:
mutex_unlock(&tcphy->lock);
return ret;
}
static int rockchip_dp_phy_power_off(struct phy *phy)
{
struct rockchip_typec_phy *tcphy = phy_get_drvdata(phy);
mutex_lock(&tcphy->lock);
if (tcphy->mode == MODE_DISCONNECT)
goto unlock;
tcphy->mode &= ~MODE_DFP_DP;
writel(DP_MODE_ENTER_A2, tcphy->base + DP_MODE_CTL);
if (tcphy->mode == MODE_DISCONNECT)
tcphy_phy_deinit(tcphy);
unlock:
mutex_unlock(&tcphy->lock);
return 0;
}
static int tcphy_get_param(struct device *dev,
struct usb3phy_reg *reg,
const char *name)
{
u32 buffer[3];
int ret;
ret = of_property_read_u32_array(dev->of_node, name, buffer, 3);
if (ret) {
dev_err(dev, "Can not parse %s\n", name);
return ret;
}
reg->offset = buffer[0];
reg->enable_bit = buffer[1];
reg->write_enable = buffer[2];
return 0;
}
static int tcphy_parse_dt(struct rockchip_typec_phy *tcphy,
struct device *dev)
{
struct rockchip_usb3phy_port_cfg *cfg = &tcphy->port_cfgs;
int ret;
ret = tcphy_get_param(dev, &cfg->typec_conn_dir,
"rockchip,typec-conn-dir");
if (ret)
return ret;
ret = tcphy_get_param(dev, &cfg->usb3tousb2_en,
"rockchip,usb3tousb2-en");
if (ret)
return ret;
ret = tcphy_get_param(dev, &cfg->external_psm,
"rockchip,external-psm");
if (ret)
return ret;
ret = tcphy_get_param(dev, &cfg->pipe_status,
"rockchip,pipe-status");
if (ret)
return ret;
tcphy->grf_regs = syscon_regmap_lookup_by_phandle(dev->of_node,
"rockchip,grf");
if (IS_ERR(tcphy->grf_regs)) {
dev_err(dev, "could not find grf dt node\n");
return PTR_ERR(tcphy->grf_regs);
}
tcphy->clk_core = devm_clk_get(dev, "tcpdcore");
if (IS_ERR(tcphy->clk_core)) {
dev_err(dev, "could not get uphy core clock\n");
return PTR_ERR(tcphy->clk_core);
}
tcphy->clk_ref = devm_clk_get(dev, "tcpdphy-ref");
if (IS_ERR(tcphy->clk_ref)) {
dev_err(dev, "could not get uphy ref clock\n");
return PTR_ERR(tcphy->clk_ref);
}
tcphy->uphy_rst = devm_reset_control_get(dev, "uphy");
if (IS_ERR(tcphy->uphy_rst)) {
dev_err(dev, "no uphy_rst reset control found\n");
return PTR_ERR(tcphy->uphy_rst);
}
tcphy->pipe_rst = devm_reset_control_get(dev, "uphy-pipe");
if (IS_ERR(tcphy->pipe_rst)) {
dev_err(dev, "no pipe_rst reset control found\n");
return PTR_ERR(tcphy->pipe_rst);
}
tcphy->tcphy_rst = devm_reset_control_get(dev, "uphy-tcphy");
if (IS_ERR(tcphy->tcphy_rst)) {
dev_err(dev, "no tcphy_rst reset control found\n");
return PTR_ERR(tcphy->tcphy_rst);
}
return 0;
}
static void typec_phy_pre_init(struct rockchip_typec_phy *tcphy)
{
struct rockchip_usb3phy_port_cfg *cfg = &tcphy->port_cfgs;
reset_control_assert(tcphy->tcphy_rst);
reset_control_assert(tcphy->uphy_rst);
reset_control_assert(tcphy->pipe_rst);
property_enable(tcphy, &cfg->external_psm, 1);
property_enable(tcphy, &cfg->usb3tousb2_en, 0);
tcphy->mode = MODE_DISCONNECT;
}
static int rockchip_typec_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct device_node *child_np;
struct rockchip_typec_phy *tcphy;
struct phy_provider *phy_provider;
struct resource *res;
int ret;
tcphy = devm_kzalloc(dev, sizeof(*tcphy), GFP_KERNEL);
if (!tcphy)
return -ENOMEM;
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
tcphy->base = devm_ioremap_resource(dev, res);
if (IS_ERR(tcphy->base))
return PTR_ERR(tcphy->base);
ret = tcphy_parse_dt(tcphy, dev);
if (ret)
return ret;
tcphy->dev = dev;
platform_set_drvdata(pdev, tcphy);
mutex_init(&tcphy->lock);
typec_phy_pre_init(tcphy);
tcphy->extcon = extcon_get_edev_by_phandle(dev, 0);
if (IS_ERR(tcphy->extcon)) {
if (PTR_ERR(tcphy->extcon) != -EPROBE_DEFER)
dev_err(dev, "Invalid or missing extcon\n");
return PTR_ERR(tcphy->extcon);
}
pm_runtime_enable(dev);
for_each_available_child_of_node(np, child_np) {
struct phy *phy;
if (!of_node_cmp(child_np->name, "dp-port"))
phy = devm_phy_create(dev, child_np,
&rockchip_dp_phy_ops);
else if (!of_node_cmp(child_np->name, "usb3-port"))
phy = devm_phy_create(dev, child_np,
&rockchip_usb3_phy_ops);
else
continue;
if (IS_ERR(phy)) {
dev_err(dev, "failed to create phy: %s\n",
child_np->name);
return PTR_ERR(phy);
}
phy_set_drvdata(phy, tcphy);
}
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
if (IS_ERR(phy_provider)) {
dev_err(dev, "Failed to register phy provider\n");
return PTR_ERR(phy_provider);
}
return 0;
}
static int rockchip_typec_phy_remove(struct platform_device *pdev)
{
pm_runtime_disable(&pdev->dev);
return 0;
}
