static struct s2mps11_clk *to_s2mps11_clk(struct clk_hw *hw)
{
return container_of(hw, struct s2mps11_clk, hw);
}
static int s2mps11_clk_prepare(struct clk_hw *hw)
{
struct s2mps11_clk *s2mps11 = to_s2mps11_clk(hw);
return regmap_update_bits(s2mps11->iodev->regmap_pmic,
s2mps11->reg,
s2mps11->mask, s2mps11->mask);
}
static void s2mps11_clk_unprepare(struct clk_hw *hw)
{
struct s2mps11_clk *s2mps11 = to_s2mps11_clk(hw);
regmap_update_bits(s2mps11->iodev->regmap_pmic, s2mps11->reg,
s2mps11->mask, ~s2mps11->mask);
}
static int s2mps11_clk_is_prepared(struct clk_hw *hw)
{
int ret;
u32 val;
struct s2mps11_clk *s2mps11 = to_s2mps11_clk(hw);
ret = regmap_read(s2mps11->iodev->regmap_pmic,
s2mps11->reg, &val);
if (ret < 0)
return -EINVAL;
return val & s2mps11->mask;
}
static unsigned long s2mps11_clk_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return 32768;
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
for (i = 0; i < S2MPS11_CLKS_NUM; i++)
of_property_read_string_index(clk_np, "clock-output-names", i,
&clks_init[i].name);
return clk_np;
}
static int s2mps11_clk_probe(struct platform_device *pdev)
{
struct sec_pmic_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct s2mps11_clk *s2mps11_clks;
struct clk_onecell_data *clk_data;
unsigned int s2mps11_reg;
int i, ret = 0;
enum sec_device_type hwid = platform_get_device_id(pdev)->driver_data;
s2mps11_clks = devm_kcalloc(&pdev->dev, S2MPS11_CLKS_NUM,
sizeof(*s2mps11_clks), GFP_KERNEL);
if (!s2mps11_clks)
return -ENOMEM;
clk_data = devm_kzalloc(&pdev->dev, sizeof(*clk_data), GFP_KERNEL);
if (!clk_data)
return -ENOMEM;
clk_data->clks = devm_kcalloc(&pdev->dev, S2MPS11_CLKS_NUM,
sizeof(struct clk *), GFP_KERNEL);
if (!clk_data->clks)
return -ENOMEM;
switch (hwid) {
case S2MPS11X:
s2mps11_reg = S2MPS11_REG_RTC_CTRL;
break;
case S2MPS13X:
s2mps11_reg = S2MPS13_REG_RTCCTRL;
break;
case S2MPS14X:
s2mps11_reg = S2MPS14_REG_RTCCTRL;
break;
case S5M8767X:
s2mps11_reg = S5M8767_REG_CTRL1;
break;
default:
dev_err(&pdev->dev, "Invalid device type\n");
return -EINVAL;
}
s2mps11_clks->clk_np = s2mps11_clk_parse_dt(pdev, s2mps11_clks_init);
if (IS_ERR(s2mps11_clks->clk_np))
return PTR_ERR(s2mps11_clks->clk_np);
for (i = 0; i < S2MPS11_CLKS_NUM; i++) {
if (i == S2MPS11_CLK_CP && hwid == S2MPS14X)
continue;
s2mps11_clks[i].iodev = iodev;
s2mps11_clks[i].hw.init = &s2mps11_clks_init[i];
s2mps11_clks[i].mask = 1 << i;
s2mps11_clks[i].reg = s2mps11_reg;
s2mps11_clks[i].clk = devm_clk_register(&pdev->dev,
&s2mps11_clks[i].hw);
if (IS_ERR(s2mps11_clks[i].clk)) {
dev_err(&pdev->dev, "Fail to register : %s\n",
s2mps11_clks_init[i].name);
ret = PTR_ERR(s2mps11_clks[i].clk);
goto err_reg;
}
s2mps11_clks[i].lookup = clkdev_create(s2mps11_clks[i].clk,
s2mps11_clks_init[i].name, NULL);
if (!s2mps11_clks[i].lookup) {
ret = -ENOMEM;
goto err_reg;
}
clk_data->clks[i] = s2mps11_clks[i].clk;
}
clk_data->clk_num = S2MPS11_CLKS_NUM;
of_clk_add_provider(s2mps11_clks->clk_np, of_clk_src_onecell_get,
clk_data);
platform_set_drvdata(pdev, s2mps11_clks);
return ret;
err_reg:
while (--i >= 0)
clkdev_drop(s2mps11_clks[i].lookup);
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
static void __exit s2mps11_clk_cleanup(void)
{
platform_driver_unregister(&s2mps11_clk_driver);
}
