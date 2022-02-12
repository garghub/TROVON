static int rockchip_usb_phy_power(struct rockchip_usb_phy *phy,
bool siddq)
{
return regmap_write(phy->base->reg_base, phy->reg_offset,
SIDDQ_WRITE_ENA | (siddq ? SIDDQ_ON : SIDDQ_OFF));
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
return (val & SIDDQ_ON) ? 0 : 1;
}
static int rockchip_usb_phy_power_off(struct phy *_phy)
{
struct rockchip_usb_phy *phy = phy_get_drvdata(_phy);
clk_disable_unprepare(phy->clk480m);
return 0;
}
static int rockchip_usb_phy_power_on(struct phy *_phy)
{
struct rockchip_usb_phy *phy = phy_get_drvdata(_phy);
return clk_prepare_enable(phy->clk480m);
}
static void rockchip_usb_phy_action(void *data)
{
struct rockchip_usb_phy *rk_phy = data;
of_clk_del_provider(rk_phy->np);
clk_unregister(rk_phy->clk480m);
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
err = devm_add_action(base->dev, rockchip_usb_phy_action, rk_phy);
if (err)
goto err_devm_action;
rk_phy->phy = devm_phy_create(base->dev, child, &ops);
if (IS_ERR(rk_phy->phy)) {
dev_err(base->dev, "failed to create PHY\n");
return PTR_ERR(rk_phy->phy);
}
phy_set_drvdata(rk_phy->phy, rk_phy);
return rockchip_usb_phy_power(rk_phy, 1);
err_devm_action:
of_clk_del_provider(child);
err_clk_prov:
clk_unregister(rk_phy->clk480m);
err_clk:
if (rk_phy->clk)
clk_put(rk_phy->clk);
return err;
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
