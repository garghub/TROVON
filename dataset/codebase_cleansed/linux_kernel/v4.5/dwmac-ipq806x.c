static int get_clk_div_sgmii(struct ipq806x_gmac *gmac, unsigned int speed)
{
struct device *dev = &gmac->pdev->dev;
int div;
switch (speed) {
case SPEED_1000:
div = NSS_COMMON_CLK_DIV_SGMII_1000;
break;
case SPEED_100:
div = NSS_COMMON_CLK_DIV_SGMII_100;
break;
case SPEED_10:
div = NSS_COMMON_CLK_DIV_SGMII_10;
break;
default:
dev_err(dev, "Speed %dMbps not supported in SGMII\n", speed);
return -EINVAL;
}
return div;
}
static int get_clk_div_rgmii(struct ipq806x_gmac *gmac, unsigned int speed)
{
struct device *dev = &gmac->pdev->dev;
int div;
switch (speed) {
case SPEED_1000:
div = NSS_COMMON_CLK_DIV_RGMII_1000;
break;
case SPEED_100:
div = NSS_COMMON_CLK_DIV_RGMII_100;
break;
case SPEED_10:
div = NSS_COMMON_CLK_DIV_RGMII_10;
break;
default:
dev_err(dev, "Speed %dMbps not supported in RGMII\n", speed);
return -EINVAL;
}
return div;
}
static int ipq806x_gmac_set_speed(struct ipq806x_gmac *gmac, unsigned int speed)
{
uint32_t clk_bits, val;
int div;
switch (gmac->phy_mode) {
case PHY_INTERFACE_MODE_RGMII:
div = get_clk_div_rgmii(gmac, speed);
clk_bits = NSS_COMMON_CLK_GATE_RGMII_RX_EN(gmac->id) |
NSS_COMMON_CLK_GATE_RGMII_TX_EN(gmac->id);
break;
case PHY_INTERFACE_MODE_SGMII:
div = get_clk_div_sgmii(gmac, speed);
clk_bits = NSS_COMMON_CLK_GATE_GMII_RX_EN(gmac->id) |
NSS_COMMON_CLK_GATE_GMII_TX_EN(gmac->id);
break;
default:
dev_err(&gmac->pdev->dev, "Unsupported PHY mode: \"%s\"\n",
phy_modes(gmac->phy_mode));
return -EINVAL;
}
regmap_read(gmac->nss_common, NSS_COMMON_CLK_GATE, &val);
val &= ~clk_bits;
regmap_write(gmac->nss_common, NSS_COMMON_CLK_GATE, val);
regmap_read(gmac->nss_common, NSS_COMMON_CLK_DIV0, &val);
val &= ~(NSS_COMMON_CLK_DIV_MASK
<< NSS_COMMON_CLK_DIV_OFFSET(gmac->id));
val |= div << NSS_COMMON_CLK_DIV_OFFSET(gmac->id);
regmap_write(gmac->nss_common, NSS_COMMON_CLK_DIV0, val);
regmap_read(gmac->nss_common, NSS_COMMON_CLK_GATE, &val);
val |= clk_bits;
regmap_write(gmac->nss_common, NSS_COMMON_CLK_GATE, val);
return 0;
}
static int ipq806x_gmac_of_parse(struct ipq806x_gmac *gmac)
{
struct device *dev = &gmac->pdev->dev;
gmac->phy_mode = of_get_phy_mode(dev->of_node);
if (gmac->phy_mode < 0) {
dev_err(dev, "missing phy mode property\n");
return -EINVAL;
}
if (of_property_read_u32(dev->of_node, "qcom,id", &gmac->id) < 0) {
dev_err(dev, "missing qcom id property\n");
return -EINVAL;
}
if (gmac->id < 0 || gmac->id > 3) {
dev_err(dev, "invalid gmac id\n");
return -EINVAL;
}
gmac->core_clk = devm_clk_get(dev, "stmmaceth");
if (IS_ERR(gmac->core_clk)) {
dev_err(dev, "missing stmmaceth clk property\n");
return PTR_ERR(gmac->core_clk);
}
clk_set_rate(gmac->core_clk, 266000000);
gmac->nss_common = syscon_regmap_lookup_by_phandle(dev->of_node,
"qcom,nss-common");
if (IS_ERR(gmac->nss_common)) {
dev_err(dev, "missing nss-common node\n");
return PTR_ERR(gmac->nss_common);
}
gmac->qsgmii_csr = syscon_regmap_lookup_by_phandle(dev->of_node,
"qcom,qsgmii-csr");
if (IS_ERR(gmac->qsgmii_csr))
dev_err(dev, "missing qsgmii-csr node\n");
return PTR_ERR_OR_ZERO(gmac->qsgmii_csr);
}
static void ipq806x_gmac_fix_mac_speed(void *priv, unsigned int speed)
{
struct ipq806x_gmac *gmac = priv;
ipq806x_gmac_set_speed(gmac, speed);
}
static int ipq806x_gmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct device *dev = &pdev->dev;
struct ipq806x_gmac *gmac;
int val;
int err;
val = stmmac_get_platform_resources(pdev, &stmmac_res);
if (val)
return val;
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
gmac = devm_kzalloc(dev, sizeof(*gmac), GFP_KERNEL);
if (!gmac)
return -ENOMEM;
gmac->pdev = pdev;
err = ipq806x_gmac_of_parse(gmac);
if (err) {
dev_err(dev, "device tree parsing error\n");
return err;
}
regmap_write(gmac->qsgmii_csr, QSGMII_PCS_CAL_LCKDT_CTL,
QSGMII_PCS_CAL_LCKDT_CTL_RST);
val = 12 << NSS_COMMON_GMAC_CTL_IFG_OFFSET |
12 << NSS_COMMON_GMAC_CTL_IFG_LIMIT_OFFSET;
val |= NSS_COMMON_GMAC_CTL_CSYS_REQ;
switch (gmac->phy_mode) {
case PHY_INTERFACE_MODE_RGMII:
val |= NSS_COMMON_GMAC_CTL_PHY_IFACE_SEL;
break;
case PHY_INTERFACE_MODE_SGMII:
val &= ~NSS_COMMON_GMAC_CTL_PHY_IFACE_SEL;
break;
default:
dev_err(&pdev->dev, "Unsupported PHY mode: \"%s\"\n",
phy_modes(gmac->phy_mode));
return -EINVAL;
}
regmap_write(gmac->nss_common, NSS_COMMON_GMAC_CTL(gmac->id), val);
regmap_read(gmac->nss_common, NSS_COMMON_CLK_SRC_CTRL, &val);
val &= ~(1 << NSS_COMMON_CLK_SRC_CTRL_OFFSET(gmac->id));
switch (gmac->phy_mode) {
case PHY_INTERFACE_MODE_RGMII:
val |= NSS_COMMON_CLK_SRC_CTRL_RGMII(gmac->id) <<
NSS_COMMON_CLK_SRC_CTRL_OFFSET(gmac->id);
break;
case PHY_INTERFACE_MODE_SGMII:
val |= NSS_COMMON_CLK_SRC_CTRL_SGMII(gmac->id) <<
NSS_COMMON_CLK_SRC_CTRL_OFFSET(gmac->id);
break;
default:
dev_err(&pdev->dev, "Unsupported PHY mode: \"%s\"\n",
phy_modes(gmac->phy_mode));
return -EINVAL;
}
regmap_write(gmac->nss_common, NSS_COMMON_CLK_SRC_CTRL, val);
regmap_read(gmac->nss_common, NSS_COMMON_CLK_GATE, &val);
val |= NSS_COMMON_CLK_GATE_PTP_EN(gmac->id);
regmap_write(gmac->nss_common, NSS_COMMON_CLK_GATE, val);
if (gmac->phy_mode == PHY_INTERFACE_MODE_SGMII) {
regmap_write(gmac->qsgmii_csr, QSGMII_PHY_SGMII_CTL(gmac->id),
QSGMII_PHY_CDR_EN |
QSGMII_PHY_RX_FRONT_EN |
QSGMII_PHY_RX_SIGNAL_DETECT_EN |
QSGMII_PHY_TX_DRIVER_EN |
QSGMII_PHY_QSGMII_EN |
0x4ul << QSGMII_PHY_PHASE_LOOP_GAIN_OFFSET |
0x3ul << QSGMII_PHY_RX_DC_BIAS_OFFSET |
0x1ul << QSGMII_PHY_RX_INPUT_EQU_OFFSET |
0x2ul << QSGMII_PHY_CDR_PI_SLEW_OFFSET |
0xCul << QSGMII_PHY_TX_DRV_AMP_OFFSET);
}
plat_dat->has_gmac = true;
plat_dat->bsp_priv = gmac;
plat_dat->fix_mac_speed = ipq806x_gmac_fix_mac_speed;
return stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
}
