static void meson8b_dwmac_mask_bits(struct meson8b_dwmac *dwmac, u32 reg,
u32 mask, u32 value)
{
u32 data;
data = readl(dwmac->regs + reg);
data &= ~mask;
data |= (value & mask);
writel(data, dwmac->regs + reg);
}
static int meson8b_init_clk(struct meson8b_dwmac *dwmac)
{
struct clk_init_data init;
int i, ret;
struct device *dev = &dwmac->pdev->dev;
char clk_name[32];
const char *clk_div_parents[1];
const char *mux_parent_names[MUX_CLK_NUM_PARENTS];
static const struct clk_div_table clk_25m_div_table[] = {
{ .val = 0, .div = 5 },
{ .val = 1, .div = 10 },
{ },
};
for (i = 0; i < MUX_CLK_NUM_PARENTS; i++) {
char name[16];
snprintf(name, sizeof(name), "clkin%d", i);
dwmac->m250_mux_parent[i] = devm_clk_get(dev, name);
if (IS_ERR(dwmac->m250_mux_parent[i])) {
ret = PTR_ERR(dwmac->m250_mux_parent[i]);
if (ret != -EPROBE_DEFER)
dev_err(dev, "Missing clock %s\n", name);
return ret;
}
mux_parent_names[i] =
__clk_get_name(dwmac->m250_mux_parent[i]);
}
snprintf(clk_name, sizeof(clk_name), "%s#m250_sel", dev_name(dev));
init.name = clk_name;
init.ops = &clk_mux_ops;
init.flags = 0;
init.parent_names = mux_parent_names;
init.num_parents = MUX_CLK_NUM_PARENTS;
dwmac->m250_mux.reg = dwmac->regs + PRG_ETH0;
dwmac->m250_mux.shift = PRG_ETH0_CLK_M250_SEL_SHIFT;
dwmac->m250_mux.mask = PRG_ETH0_CLK_M250_SEL_MASK;
dwmac->m250_mux.flags = 0;
dwmac->m250_mux.table = NULL;
dwmac->m250_mux.hw.init = &init;
dwmac->m250_mux_clk = devm_clk_register(dev, &dwmac->m250_mux.hw);
if (WARN_ON(IS_ERR(dwmac->m250_mux_clk)))
return PTR_ERR(dwmac->m250_mux_clk);
snprintf(clk_name, sizeof(clk_name), "%s#m250_div", dev_name(dev));
init.name = devm_kstrdup(dev, clk_name, GFP_KERNEL);
init.ops = &clk_divider_ops;
init.flags = CLK_SET_RATE_PARENT;
clk_div_parents[0] = __clk_get_name(dwmac->m250_mux_clk);
init.parent_names = clk_div_parents;
init.num_parents = ARRAY_SIZE(clk_div_parents);
dwmac->m250_div.reg = dwmac->regs + PRG_ETH0;
dwmac->m250_div.shift = PRG_ETH0_CLK_M250_DIV_SHIFT;
dwmac->m250_div.width = PRG_ETH0_CLK_M250_DIV_WIDTH;
dwmac->m250_div.hw.init = &init;
dwmac->m250_div.flags = CLK_DIVIDER_ONE_BASED | CLK_DIVIDER_ALLOW_ZERO;
dwmac->m250_div_clk = devm_clk_register(dev, &dwmac->m250_div.hw);
if (WARN_ON(IS_ERR(dwmac->m250_div_clk)))
return PTR_ERR(dwmac->m250_div_clk);
snprintf(clk_name, sizeof(clk_name), "%s#m25_div", dev_name(dev));
init.name = devm_kstrdup(dev, clk_name, GFP_KERNEL);
init.ops = &clk_divider_ops;
init.flags = CLK_IS_BASIC | CLK_SET_RATE_PARENT;
clk_div_parents[0] = __clk_get_name(dwmac->m250_div_clk);
init.parent_names = clk_div_parents;
init.num_parents = ARRAY_SIZE(clk_div_parents);
dwmac->m25_div.reg = dwmac->regs + PRG_ETH0;
dwmac->m25_div.shift = PRG_ETH0_CLK_M25_DIV_SHIFT;
dwmac->m25_div.width = PRG_ETH0_CLK_M25_DIV_WIDTH;
dwmac->m25_div.table = clk_25m_div_table;
dwmac->m25_div.hw.init = &init;
dwmac->m25_div.flags = CLK_DIVIDER_ALLOW_ZERO;
dwmac->m25_div_clk = devm_clk_register(dev, &dwmac->m25_div.hw);
if (WARN_ON(IS_ERR(dwmac->m25_div_clk)))
return PTR_ERR(dwmac->m25_div_clk);
return 0;
}
static int meson8b_init_prg_eth(struct meson8b_dwmac *dwmac)
{
int ret;
unsigned long clk_rate;
u8 tx_dly_val = 0;
switch (dwmac->phy_mode) {
case PHY_INTERFACE_MODE_RGMII:
case PHY_INTERFACE_MODE_RGMII_RXID:
tx_dly_val = dwmac->tx_delay_ns >> 1;
case PHY_INTERFACE_MODE_RGMII_ID:
case PHY_INTERFACE_MODE_RGMII_TXID:
clk_rate = 25 * 1000 * 1000;
meson8b_dwmac_mask_bits(dwmac, PRG_ETH0, PRG_ETH0_RGMII_MODE,
PRG_ETH0_RGMII_MODE);
meson8b_dwmac_mask_bits(dwmac, PRG_ETH0,
PRG_ETH0_INVERTED_RMII_CLK, 0);
meson8b_dwmac_mask_bits(dwmac, PRG_ETH0, PRG_ETH0_TXDLY_MASK,
tx_dly_val << PRG_ETH0_TXDLY_SHIFT);
break;
case PHY_INTERFACE_MODE_RMII:
clk_rate = clk_get_rate(dwmac->m250_mux_clk);
meson8b_dwmac_mask_bits(dwmac, PRG_ETH0, PRG_ETH0_RGMII_MODE,
0);
meson8b_dwmac_mask_bits(dwmac, PRG_ETH0,
PRG_ETH0_INVERTED_RMII_CLK,
PRG_ETH0_INVERTED_RMII_CLK);
meson8b_dwmac_mask_bits(dwmac, PRG_ETH0, PRG_ETH0_TXDLY_MASK,
0);
break;
default:
dev_err(&dwmac->pdev->dev, "unsupported phy-mode %s\n",
phy_modes(dwmac->phy_mode));
return -EINVAL;
}
ret = clk_prepare_enable(dwmac->m25_div_clk);
if (ret) {
dev_err(&dwmac->pdev->dev, "failed to enable the PHY clock\n");
return ret;
}
ret = clk_set_rate(dwmac->m25_div_clk, clk_rate);
if (ret) {
clk_disable_unprepare(dwmac->m25_div_clk);
dev_err(&dwmac->pdev->dev, "failed to set PHY clock\n");
return ret;
}
meson8b_dwmac_mask_bits(dwmac, PRG_ETH0, PRG_ETH0_TX_AND_PHY_REF_CLK,
PRG_ETH0_TX_AND_PHY_REF_CLK);
return 0;
}
static int meson8b_dwmac_probe(struct platform_device *pdev)
{
struct plat_stmmacenet_data *plat_dat;
struct stmmac_resources stmmac_res;
struct resource *res;
struct meson8b_dwmac *dwmac;
int ret;
ret = stmmac_get_platform_resources(pdev, &stmmac_res);
if (ret)
return ret;
plat_dat = stmmac_probe_config_dt(pdev, &stmmac_res.mac);
if (IS_ERR(plat_dat))
return PTR_ERR(plat_dat);
dwmac = devm_kzalloc(&pdev->dev, sizeof(*dwmac), GFP_KERNEL);
if (!dwmac) {
ret = -ENOMEM;
goto err_remove_config_dt;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 1);
dwmac->regs = devm_ioremap_resource(&pdev->dev, res);
if (IS_ERR(dwmac->regs)) {
ret = PTR_ERR(dwmac->regs);
goto err_remove_config_dt;
}
dwmac->pdev = pdev;
dwmac->phy_mode = of_get_phy_mode(pdev->dev.of_node);
if (dwmac->phy_mode < 0) {
dev_err(&pdev->dev, "missing phy-mode property\n");
ret = -EINVAL;
goto err_remove_config_dt;
}
if (of_property_read_u32(pdev->dev.of_node, "amlogic,tx-delay-ns",
&dwmac->tx_delay_ns))
dwmac->tx_delay_ns = 2;
ret = meson8b_init_clk(dwmac);
if (ret)
goto err_remove_config_dt;
ret = meson8b_init_prg_eth(dwmac);
if (ret)
goto err_remove_config_dt;
plat_dat->bsp_priv = dwmac;
ret = stmmac_dvr_probe(&pdev->dev, plat_dat, &stmmac_res);
if (ret)
goto err_clk_disable;
return 0;
err_clk_disable:
clk_disable_unprepare(dwmac->m25_div_clk);
err_remove_config_dt:
stmmac_remove_config_dt(pdev, plat_dat);
return ret;
}
static int meson8b_dwmac_remove(struct platform_device *pdev)
{
struct meson8b_dwmac *dwmac = get_stmmac_bsp_priv(&pdev->dev);
clk_disable_unprepare(dwmac->m25_div_clk);
return stmmac_pltfr_remove(pdev);
}
