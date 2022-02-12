static int rockchip_usb_phy_power(struct rockchip_usb_phy *phy,
bool siddq)
{
u32 val = HIWORD_UPDATE(siddq ? UOC_CON0_SIDDQ : 0, UOC_CON0_SIDDQ);
return regmap_write(phy->base->reg_base, phy->reg_offset, val);
}
static unsigned long rockchip_usb_phy480m_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return 480000000;
}
static void rockchip_usb_phy480m_disable(struct clk_hw *hw)
{
struct rockchip_usb_phy *phy = container_of(hw,
struct rockchip_usb_phy,
clk480m_hw);
rockchip_usb_phy_power(phy, 1);
}
static int rockchip_usb_phy480m_enable(struct clk_hw *hw)
{
struct rockchip_usb_phy *phy = container_of(hw,
struct rockchip_usb_phy,
clk480m_hw);
return rockchip_usb_phy_power(phy, 0);
}
static int rockchip_usb_phy480m_is_enabled(struct clk_hw *hw)
{
struct rockchip_usb_phy *phy = container_of(hw,
struct rockchip_usb_phy,
clk480m_hw);
int ret;
u32 val;
ret = regmap_read(phy->base->reg_base, phy->reg_offset, &val);
if (ret < 0)
return ret;
return (val & UOC_CON0_SIDDQ) ? 0 : 1;
}
static int rockchip_usb_phy_power_off(struct phy *_phy)
{
struct rockchip_usb_phy *phy = phy_get_drvdata(_phy);
if (phy->uart_enabled)
return -EBUSY;
clk_disable_unprepare(phy->clk480m);
return 0;
}
static int rockchip_usb_phy_power_on(struct phy *_phy)
{
struct rockchip_usb_phy *phy = phy_get_drvdata(_phy);
if (phy->uart_enabled)
return -EBUSY;
return clk_prepare_enable(phy->clk480m);
}
static void rockchip_usb_phy_action(void *data)
{
struct rockchip_usb_phy *rk_phy = data;
if (!rk_phy->uart_enabled) {
of_clk_del_provider(rk_phy->np);
clk_unregister(rk_phy->clk480m);
}
if (rk_phy->clk)
clk_put(rk_phy->clk);
}
static int rockchip_usb_phy_init(struct rockchip_usb_phy_base *base,
struct device_node *child)
{
struct rockchip_usb_phy *rk_phy;
unsigned int reg_offset;
const char *clk_name;
struct clk_init_data init;
int err, i;
rk_phy = devm_kzalloc(base->dev, sizeof(*rk_phy), GFP_KERNEL);
if (!rk_phy)
return -ENOMEM;
rk_phy->base = base;
rk_phy->np = child;
if (of_property_read_u32(child, "reg", &reg_offset)) {
dev_err(base->dev, "missing reg property in node %s\n",
child->name);
return -EINVAL;
}
rk_phy->reg_offset = reg_offset;
rk_phy->clk = of_clk_get_by_name(child, "phyclk");
if (IS_ERR(rk_phy->clk))
rk_phy->clk = NULL;
i = 0;
init.name = NULL;
while (base->pdata->phys[i].reg) {
if (base->pdata->phys[i].reg == reg_offset) {
init.name = base->pdata->phys[i].pll_name;
break;
}
i++;
}
if (!init.name) {
dev_err(base->dev, "phy data not found\n");
return -EINVAL;
}
if (enable_usb_uart && base->pdata->usb_uart_phy == i) {
dev_dbg(base->dev, "phy%d used as uart output\n", i);
rk_phy->uart_enabled = true;
} else {
if (rk_phy->clk) {
clk_name = __clk_get_name(rk_phy->clk);
init.flags = 0;
init.parent_names = &clk_name;
init.num_parents = 1;
} else {
init.flags = CLK_IS_ROOT;
init.parent_names = NULL;
init.num_parents = 0;
}
init.ops = &rockchip_usb_phy480m_ops;
rk_phy->clk480m_hw.init = &init;
rk_phy->clk480m = clk_register(base->dev, &rk_phy->clk480m_hw);
if (IS_ERR(rk_phy->clk480m)) {
err = PTR_ERR(rk_phy->clk480m);
goto err_clk;
}
err = of_clk_add_provider(child, of_clk_src_simple_get,
rk_phy->clk480m);
if (err < 0)
goto err_clk_prov;
}
err = devm_add_action(base->dev, rockchip_usb_phy_action, rk_phy);
if (err)
goto err_devm_action;
rk_phy->phy = devm_phy_create(base->dev, child, &ops);
if (IS_ERR(rk_phy->phy)) {
dev_err(base->dev, "failed to create PHY\n");
return PTR_ERR(rk_phy->phy);
}
phy_set_drvdata(rk_phy->phy, rk_phy);
if (rk_phy->uart_enabled)
return clk_prepare_enable(rk_phy->clk);
else
return rockchip_usb_phy_power(rk_phy, 1);
err_devm_action:
if (!rk_phy->uart_enabled)
of_clk_del_provider(child);
err_clk_prov:
if (!rk_phy->uart_enabled)
clk_unregister(rk_phy->clk480m);
err_clk:
if (rk_phy->clk)
clk_put(rk_phy->clk);
return err;
}
static int __init rk3288_init_usb_uart(struct regmap *grf)
{
u32 val;
int ret;
val = HIWORD_UPDATE(RK3288_UOC0_CON0_COMMON_ON_N
| RK3288_UOC0_CON0_DISABLE
| UOC_CON0_SIDDQ,
RK3288_UOC0_CON0_COMMON_ON_N
| RK3288_UOC0_CON0_DISABLE
| UOC_CON0_SIDDQ);
ret = regmap_write(grf, RK3288_UOC0_CON0, val);
if (ret)
return ret;
val = HIWORD_UPDATE(RK3288_UOC0_CON2_SOFT_CON_SEL,
RK3288_UOC0_CON2_SOFT_CON_SEL);
ret = regmap_write(grf, RK3288_UOC0_CON2, val);
if (ret)
return ret;
val = HIWORD_UPDATE(RK3288_UOC0_CON3_UTMI_OPMODE_NODRIVING
| RK3288_UOC0_CON3_UTMI_XCVRSEELCT_FSTRANSC
| RK3288_UOC0_CON3_UTMI_TERMSEL_FULLSPEED,
RK3288_UOC0_CON3_UTMI_SUSPENDN
| RK3288_UOC0_CON3_UTMI_OPMODE_MASK
| RK3288_UOC0_CON3_UTMI_XCVRSEELCT_MASK
| RK3288_UOC0_CON3_UTMI_TERMSEL_FULLSPEED);
ret = regmap_write(grf, RK3288_UOC0_CON3, val);
if (ret)
return ret;
val = HIWORD_UPDATE(RK3288_UOC0_CON3_BYPASSSEL
| RK3288_UOC0_CON3_BYPASSDMEN,
RK3288_UOC0_CON3_BYPASSSEL
| RK3288_UOC0_CON3_BYPASSDMEN);
ret = regmap_write(grf, RK3288_UOC0_CON3, val);
if (ret)
return ret;
return 0;
}
static int rockchip_usb_phy_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct rockchip_usb_phy_base *phy_base;
struct phy_provider *phy_provider;
const struct of_device_id *match;
struct device_node *child;
int err;
phy_base = devm_kzalloc(dev, sizeof(*phy_base), GFP_KERNEL);
if (!phy_base)
return -ENOMEM;
match = of_match_device(dev->driver->of_match_table, dev);
if (!match || !match->data) {
dev_err(dev, "missing phy data\n");
return -EINVAL;
}
phy_base->pdata = match->data;
phy_base->dev = dev;
phy_base->reg_base = syscon_regmap_lookup_by_phandle(dev->of_node,
"rockchip,grf");
if (IS_ERR(phy_base->reg_base)) {
dev_err(&pdev->dev, "Missing rockchip,grf property\n");
return PTR_ERR(phy_base->reg_base);
}
for_each_available_child_of_node(dev->of_node, child) {
err = rockchip_usb_phy_init(phy_base, child);
if (err) {
of_node_put(child);
return err;
}
}
phy_provider = devm_of_phy_provider_register(dev, of_phy_simple_xlate);
return PTR_ERR_OR_ZERO(phy_provider);
}
static int __init rockchip_init_usb_uart(void)
{
const struct of_device_id *match;
const struct rockchip_usb_phy_pdata *data;
struct device_node *np;
struct regmap *grf;
int ret;
if (!enable_usb_uart)
return 0;
np = of_find_matching_node_and_match(NULL, rockchip_usb_phy_dt_ids,
&match);
if (!np) {
pr_err("%s: failed to find usbphy node\n", __func__);
return -ENOTSUPP;
}
pr_debug("%s: using settings for %s\n", __func__, match->compatible);
data = match->data;
if (!data->init_usb_uart) {
pr_err("%s: usb-uart not available on %s\n",
__func__, match->compatible);
return -ENOTSUPP;
}
grf = syscon_regmap_lookup_by_phandle(np, "rockchip,grf");
if (IS_ERR(grf)) {
pr_err("%s: Missing rockchip,grf property, %lu\n",
__func__, PTR_ERR(grf));
return PTR_ERR(grf);
}
ret = data->init_usb_uart(grf);
if (ret) {
pr_err("%s: could not init usb_uart, %d\n", __func__, ret);
enable_usb_uart = 0;
return ret;
}
return 0;
}
static int __init rockchip_usb_uart(char *buf)
{
enable_usb_uart = true;
return 0;
}
