static void setup_retime_src(struct sti_dwmac *dwmac, u32 spd)
{
u32 src = 0, freq = 0;
if (spd == SPEED_100) {
if (dwmac->interface == PHY_INTERFACE_MODE_MII ||
dwmac->interface == PHY_INTERFACE_MODE_GMII) {
src = TX_RETIME_SRC_TXCLK;
} else if (dwmac->interface == PHY_INTERFACE_MODE_RMII) {
if (dwmac->ext_phyclk) {
src = TX_RETIME_SRC_PHYCLK;
} else {
src = TX_RETIME_SRC_CLKGEN;
freq = 50000000;
}
} else if (IS_PHY_IF_MODE_RGMII(dwmac->interface)) {
src = TX_RETIME_SRC_CLKGEN;
freq = 25000000;
}
if (src == TX_RETIME_SRC_CLKGEN && dwmac->clk)
clk_set_rate(dwmac->clk, freq);
} else if (spd == SPEED_1000) {
if (dwmac->is_tx_retime_src_clk_125)
src = TX_RETIME_SRC_CLK_125;
else
src = TX_RETIME_SRC_TXCLK;
}
regmap_update_bits(dwmac->regmap, dwmac->reg,
TX_RETIME_SRC_MASK, tx_retime_val[src]);
}
static void sti_dwmac_exit(struct platform_device *pdev, void *priv)
{
struct sti_dwmac *dwmac = priv;
if (dwmac->clk)
clk_disable_unprepare(dwmac->clk);
}
static void sti_fix_mac_speed(void *priv, unsigned int spd)
{
struct sti_dwmac *dwmac = priv;
setup_retime_src(dwmac, spd);
return;
}
static int sti_dwmac_parse_data(struct sti_dwmac *dwmac,
struct platform_device *pdev)
{
struct resource *res;
struct device *dev = &pdev->dev;
struct device_node *np = dev->of_node;
struct regmap *regmap;
int err;
if (!np)
return -EINVAL;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "sti-ethconf");
if (!res)
return -ENODATA;
regmap = syscon_regmap_lookup_by_phandle(np, "st,syscon");
if (IS_ERR(regmap))
return PTR_ERR(regmap);
dwmac->dev = dev;
dwmac->interface = of_get_phy_mode(np);
dwmac->regmap = regmap;
dwmac->reg = res->start;
dwmac->ext_phyclk = of_property_read_bool(np, "st,ext-phyclk");
dwmac->is_tx_retime_src_clk_125 = false;
if (IS_PHY_IF_MODE_GBIT(dwmac->interface)) {
const char *rs;
err = of_property_read_string(np, "st,tx-retime-src", &rs);
if (err < 0) {
dev_err(dev, "st,tx-retime-src not specified\n");
return err;
}
if (!strcasecmp(rs, "clk_125"))
dwmac->is_tx_retime_src_clk_125 = true;
}
dwmac->clk = devm_clk_get(dev, "sti-ethclk");
if (IS_ERR(dwmac->clk))
dwmac->clk = NULL;
return 0;
}
static int sti_dwmac_init(struct platform_device *pdev, void *priv)
{
struct sti_dwmac *dwmac = priv;
struct regmap *regmap = dwmac->regmap;
int iface = dwmac->interface;
u32 reg = dwmac->reg;
u32 val, spd;
if (dwmac->clk)
clk_prepare_enable(dwmac->clk);
regmap_update_bits(regmap, reg, MII_PHY_SEL_MASK, phy_intf_sels[iface]);
val = (iface == PHY_INTERFACE_MODE_REVMII) ? 0 : ENMII;
regmap_update_bits(regmap, reg, ENMII_MASK, val);
if (IS_PHY_IF_MODE_GBIT(iface))
spd = SPEED_1000;
else
spd = SPEED_100;
setup_retime_src(dwmac, spd);
return 0;
}
static void *sti_dwmac_setup(struct platform_device *pdev)
{
struct sti_dwmac *dwmac;
int ret;
dwmac = devm_kzalloc(&pdev->dev, sizeof(*dwmac), GFP_KERNEL);
if (!dwmac)
return ERR_PTR(-ENOMEM);
ret = sti_dwmac_parse_data(dwmac, pdev);
if (ret) {
dev_err(&pdev->dev, "Unable to parse OF data\n");
return ERR_PTR(ret);
}
return dwmac;
}
