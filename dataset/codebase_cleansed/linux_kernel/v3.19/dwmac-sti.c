static void stih4xx_fix_retime_src(void *priv, u32 spd)
{
struct sti_dwmac *dwmac = priv;
u32 src = dwmac->tx_retime_src;
u32 reg = dwmac->ctrl_reg;
u32 freq = 0;
if (dwmac->interface == PHY_INTERFACE_MODE_MII) {
src = TX_RETIME_SRC_TXCLK;
} else if (dwmac->interface == PHY_INTERFACE_MODE_RMII) {
if (dwmac->ext_phyclk) {
src = TX_RETIME_SRC_PHYCLK;
} else {
src = TX_RETIME_SRC_CLKGEN;
freq = DWMAC_50MHZ;
}
} else if (IS_PHY_IF_MODE_RGMII(dwmac->interface)) {
if (spd == SPEED_1000) {
freq = DWMAC_125MHZ;
} else {
src = TX_RETIME_SRC_CLKGEN;
if (spd == SPEED_100)
freq = DWMAC_25MHZ;
else if (spd == SPEED_10)
freq = DWMAC_2_5MHZ;
}
}
if (src == TX_RETIME_SRC_CLKGEN && dwmac->clk && freq)
clk_set_rate(dwmac->clk, freq);
regmap_update_bits(dwmac->regmap, reg, STIH4XX_RETIME_SRC_MASK,
stih4xx_tx_retime_val[src]);
}
static void stid127_fix_retime_src(void *priv, u32 spd)
{
struct sti_dwmac *dwmac = priv;
u32 reg = dwmac->ctrl_reg;
u32 freq = 0;
u32 val = 0;
if (dwmac->interface == PHY_INTERFACE_MODE_MII) {
val = STID127_ETH_SEL_INTERNAL_NOTEXT_TXCLK;
} else if (dwmac->interface == PHY_INTERFACE_MODE_RMII) {
if (!dwmac->ext_phyclk) {
val = STID127_ETH_SEL_INTERNAL_NOTEXT_PHYCLK;
freq = DWMAC_50MHZ;
}
} else if (IS_PHY_IF_MODE_RGMII(dwmac->interface)) {
val = STID127_ETH_SEL_INTERNAL_NOTEXT_TXCLK;
if (spd == SPEED_1000)
freq = DWMAC_125MHZ;
else if (spd == SPEED_100)
freq = DWMAC_25MHZ;
else if (spd == SPEED_10)
freq = DWMAC_2_5MHZ;
}
if (dwmac->clk && freq)
clk_set_rate(dwmac->clk, freq);
regmap_update_bits(dwmac->regmap, reg, STID127_RETIME_SRC_MASK, val);
}
static void sti_dwmac_ctrl_init(struct sti_dwmac *dwmac)
{
struct regmap *regmap = dwmac->regmap;
int iface = dwmac->interface;
struct device *dev = dwmac->dev;
struct device_node *np = dev->of_node;
u32 reg = dwmac->ctrl_reg;
u32 val;
if (dwmac->clk)
clk_prepare_enable(dwmac->clk);
if (of_property_read_bool(np, "st,gmac_en"))
regmap_update_bits(regmap, reg, EN_MASK, EN);
regmap_update_bits(regmap, reg, MII_PHY_SEL_MASK, phy_intf_sels[iface]);
val = (iface == PHY_INTERFACE_MODE_REVMII) ? 0 : ENMII;
regmap_update_bits(regmap, reg, ENMII_MASK, val);
}
static int stix4xx_init(struct platform_device *pdev, void *priv)
{
struct sti_dwmac *dwmac = priv;
u32 spd = dwmac->speed;
sti_dwmac_ctrl_init(dwmac);
stih4xx_fix_retime_src(priv, spd);
return 0;
}
static int stid127_init(struct platform_device *pdev, void *priv)
{
struct sti_dwmac *dwmac = priv;
u32 spd = dwmac->speed;
sti_dwmac_ctrl_init(dwmac);
stid127_fix_retime_src(priv, spd);
return 0;
}
static void sti_dwmac_exit(struct platform_device *pdev, void *priv)
{
struct sti_dwmac *dwmac = priv;
if (dwmac->clk)
clk_disable_unprepare(dwmac->clk);
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
dwmac->ctrl_reg = res->start;
dwmac->clk_sel_reg = -ENXIO;
res = platform_get_resource_byname(pdev, IORESOURCE_MEM, "sti-clkconf");
if (res)
dwmac->clk_sel_reg = res->start;
regmap = syscon_regmap_lookup_by_phandle(np, "st,syscon");
if (IS_ERR(regmap))
return PTR_ERR(regmap);
dwmac->dev = dev;
dwmac->interface = of_get_phy_mode(np);
dwmac->regmap = regmap;
dwmac->ext_phyclk = of_property_read_bool(np, "st,ext-phyclk");
dwmac->tx_retime_src = TX_RETIME_SRC_NA;
dwmac->speed = SPEED_100;
if (IS_PHY_IF_MODE_GBIT(dwmac->interface)) {
const char *rs;
err = of_property_read_string(np, "st,tx-retime-src", &rs);
if (err < 0) {
dev_warn(dev, "Use internal clock source\n");
dwmac->tx_retime_src = TX_RETIME_SRC_CLKGEN;
} else if (!strcasecmp(rs, "clk_125")) {
dwmac->tx_retime_src = TX_RETIME_SRC_CLK_125;
} else if (!strcasecmp(rs, "txclk")) {
dwmac->tx_retime_src = TX_RETIME_SRC_TXCLK;
}
dwmac->speed = SPEED_1000;
}
dwmac->clk = devm_clk_get(dev, "sti-ethclk");
if (IS_ERR(dwmac->clk)) {
dev_warn(dev, "No phy clock provided...\n");
dwmac->clk = NULL;
}
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
