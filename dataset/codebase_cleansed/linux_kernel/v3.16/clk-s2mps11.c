static struct s2mps11_clk *to_s2mps11_clk(struct clk_hw *hw)
{
return container_of(hw, struct s2mps11_clk, hw);
}
static int s2mps11_clk_prepare(struct clk_hw *hw)
{
struct s2mps11_clk *s2mps11 = to_s2mps11_clk(hw);
int ret;
ret = regmap_update_bits(s2mps11->iodev->regmap_pmic,
s2mps11->reg,
s2mps11->mask, s2mps11->mask);
if (!ret)
s2mps11->enabled = true;
return ret;
}
static void s2mps11_clk_unprepare(struct clk_hw *hw)
{
struct s2mps11_clk *s2mps11 = to_s2mps11_clk(hw);
int ret;
ret = regmap_update_bits(s2mps11->iodev->regmap_pmic, s2mps11->reg,
s2mps11->mask, ~s2mps11->mask);
if (!ret)
s2mps11->enabled = false;
}
static int s2mps11_clk_is_enabled(struct clk_hw *hw)
{
struct s2mps11_clk *s2mps11 = to_s2mps11_clk(hw);
return s2mps11->enabled;
}
static unsigned long s2mps11_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
struct s2mps11_clk *s2mps11 = to_s2mps11_clk(hw);
if (s2mps11->enabled)
return 32768;
else
return 0;
}
static struct device_node *s2mps11_clk_parse_dt(struct platform_device *pdev,
struct clk_init_data *clks_init)
{
struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct device_node *clk_np;
int i;
if (!iodev->dev->of_node)
return ERR_PTR(-EINVAL);
clk_np = of_get_child_by_name(iodev->dev->of_node, "clocks");
if (!clk_np) {
dev_err(&pdev->dev, "could not find clock sub-node\n");
return ERR_PTR(-EINVAL);
}
for (i = 0; i < S2MPS11_CLKS_NUM; i++) {
if (!clks_init[i].name)
continue;
of_property_read_string_index(clk_np, "clock-output-names", i,
&clks_init[i].name);
}
return clk_np;
}
static int s2mps11_clk_probe(struct platform_device *pdev)
{
struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct s2mps11_clk *s2mps11_clks, *s2mps11_clk;
unsigned int s2mps11_reg;
struct clk_init_data *clks_init;
int i, ret = 0;
u32 val;
s2mps11_clks = devm_kzalloc(&pdev->dev, sizeof(*s2mps11_clk) *
S2MPS11_CLKS_NUM, GFP_KERNEL);
if (!s2mps11_clks)
return -ENOMEM;
s2mps11_clk = s2mps11_clks;
clk_table = devm_kzalloc(&pdev->dev, sizeof(struct clk *) *
S2MPS11_CLKS_NUM, GFP_KERNEL);
if (!clk_table)
return -ENOMEM;
switch(platform_get_device_id(pdev)->driver_data) {
case S2MPS11X:
s2mps11_reg = S2MPS11_REG_RTC_CTRL;
clks_init = s2mps11_clks_init;
break;
case S2MPS14X:
s2mps11_reg = S2MPS14_REG_RTCCTRL;
clks_init = s2mps14_clks_init;
break;
case S5M8767X:
s2mps11_reg = S5M8767_REG_CTRL1;
clks_init = s2mps11_clks_init;
break;
default:
dev_err(&pdev->dev, "Invalid device type\n");
return -EINVAL;
};
s2mps11_clks->clk_np = s2mps11_clk_parse_dt(pdev, clks_init);
if (IS_ERR(s2mps11_clks->clk_np))
return PTR_ERR(s2mps11_clks->clk_np);
for (i = 0; i < S2MPS11_CLKS_NUM; i++, s2mps11_clk++) {
if (!clks_init[i].name)
continue;
s2mps11_clk->iodev = iodev;
s2mps11_clk->hw.init = &clks_init[i];
s2mps11_clk->mask = 1 << i;
s2mps11_clk->reg = s2mps11_reg;
ret = regmap_read(s2mps11_clk->iodev->regmap_pmic,
s2mps11_clk->reg, &val);
if (ret < 0)
goto err_reg;
s2mps11_clk->enabled = val & s2mps11_clk->mask;
s2mps11_clk->clk = devm_clk_register(&pdev->dev,
&s2mps11_clk->hw);
if (IS_ERR(s2mps11_clk->clk)) {
dev_err(&pdev->dev, "Fail to register : %s\n",
s2mps11_name(s2mps11_clk));
ret = PTR_ERR(s2mps11_clk->clk);
goto err_reg;
}
s2mps11_clk->lookup = clkdev_alloc(s2mps11_clk->clk,
s2mps11_name(s2mps11_clk), NULL);
if (!s2mps11_clk->lookup) {
ret = -ENOMEM;
goto err_lup;
}
clkdev_add(s2mps11_clk->lookup);
}
for (i = 0; i < S2MPS11_CLKS_NUM; i++) {
if (!clks_init[i].name)
continue;
clk_table[i] = s2mps11_clks[i].clk;
}
clk_data.clks = clk_table;
clk_data.clk_num = S2MPS11_CLKS_NUM;
of_clk_add_provider(s2mps11_clks->clk_np, of_clk_src_onecell_get,
&clk_data);
platform_set_drvdata(pdev, s2mps11_clks);
return ret;
err_lup:
devm_clk_unregister(&pdev->dev, s2mps11_clk->clk);
err_reg:
while (s2mps11_clk > s2mps11_clks) {
if (s2mps11_clk->lookup) {
clkdev_drop(s2mps11_clk->lookup);
devm_clk_unregister(&pdev->dev, s2mps11_clk->clk);
}
s2mps11_clk--;
}
return ret;
}
static int s2mps11_clk_remove(struct platform_device *pdev)
{
struct s2mps11_clk *s2mps11_clks = platform_get_drvdata(pdev);
int i;
of_clk_del_provider(s2mps11_clks[0].clk_np);
of_node_put(s2mps11_clks[0].clk_np);
for (i = 0; i < S2MPS11_CLKS_NUM; i++) {
if (!s2mps11_clks[i].lookup)
continue;
clkdev_drop(s2mps11_clks[i].lookup);
}
return 0;
}
static int __init s2mps11_clk_init(void)
{
return platform_driver_register(&s2mps11_clk_driver);
}
static void __init s2mps11_clk_cleanup(void)
{
platform_driver_unregister(&s2mps11_clk_driver);
}
