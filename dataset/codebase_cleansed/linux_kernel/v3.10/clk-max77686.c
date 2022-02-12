static struct max77686_clk *to_max77686_clk(struct clk_hw *hw)
{
return container_of(hw, struct max77686_clk, hw);
}
static int max77686_clk_prepare(struct clk_hw *hw)
{
struct max77686_clk *max77686 = to_max77686_clk(hw);
return regmap_update_bits(max77686->iodev->regmap,
MAX77686_REG_32KHZ, max77686->mask,
max77686->mask);
}
static void max77686_clk_unprepare(struct clk_hw *hw)
{
struct max77686_clk *max77686 = to_max77686_clk(hw);
regmap_update_bits(max77686->iodev->regmap,
MAX77686_REG_32KHZ, max77686->mask, ~max77686->mask);
}
static int max77686_clk_is_enabled(struct clk_hw *hw)
{
struct max77686_clk *max77686 = to_max77686_clk(hw);
int ret;
u32 val;
ret = regmap_read(max77686->iodev->regmap,
MAX77686_REG_32KHZ, &val);
if (ret < 0)
return -EINVAL;
return val & max77686->mask;
}
static int max77686_clk_register(struct device *dev,
struct max77686_clk *max77686)
{
struct clk *clk;
struct clk_hw *hw = &max77686->hw;
clk = clk_register(dev, hw);
if (IS_ERR(clk))
return -ENOMEM;
max77686->lookup = kzalloc(sizeof(struct clk_lookup), GFP_KERNEL);
if (!max77686->lookup)
return -ENOMEM;
max77686->lookup->con_id = hw->init->name;
max77686->lookup->clk = clk;
clkdev_add(max77686->lookup);
return 0;
}
static int max77686_clk_probe(struct platform_device *pdev)
{
struct max77686_dev *iodev = dev_get_drvdata(pdev->dev.parent);
struct max77686_clk **max77686_clks;
int i, ret;
max77686_clks = devm_kzalloc(&pdev->dev, sizeof(struct max77686_clk *)
* MAX77686_CLKS_NUM, GFP_KERNEL);
if (!max77686_clks)
return -ENOMEM;
for (i = 0; i < MAX77686_CLKS_NUM; i++) {
max77686_clks[i] = devm_kzalloc(&pdev->dev,
sizeof(struct max77686_clk), GFP_KERNEL);
if (!max77686_clks[i])
return -ENOMEM;
}
for (i = 0; i < MAX77686_CLKS_NUM; i++) {
max77686_clks[i]->iodev = iodev;
max77686_clks[i]->mask = 1 << i;
max77686_clks[i]->hw.init = &max77686_clks_init[i];
ret = max77686_clk_register(&pdev->dev, max77686_clks[i]);
if (ret) {
switch (i) {
case MAX77686_CLK_AP:
dev_err(&pdev->dev, "Fail to register CLK_AP\n");
goto err_clk_ap;
break;
case MAX77686_CLK_CP:
dev_err(&pdev->dev, "Fail to register CLK_CP\n");
goto err_clk_cp;
break;
case MAX77686_CLK_PMIC:
dev_err(&pdev->dev, "Fail to register CLK_PMIC\n");
goto err_clk_pmic;
}
}
}
platform_set_drvdata(pdev, max77686_clks);
goto out;
err_clk_pmic:
clkdev_drop(max77686_clks[MAX77686_CLK_CP]->lookup);
kfree(max77686_clks[MAX77686_CLK_CP]->hw.clk);
err_clk_cp:
clkdev_drop(max77686_clks[MAX77686_CLK_AP]->lookup);
kfree(max77686_clks[MAX77686_CLK_AP]->hw.clk);
err_clk_ap:
out:
return ret;
}
static int max77686_clk_remove(struct platform_device *pdev)
{
struct max77686_clk **max77686_clks = platform_get_drvdata(pdev);
int i;
for (i = 0; i < MAX77686_CLKS_NUM; i++) {
clkdev_drop(max77686_clks[i]->lookup);
kfree(max77686_clks[i]->hw.clk);
}
return 0;
}
static int __init max77686_clk_init(void)
{
return platform_driver_register(&max77686_clk_driver);
}
static void __init max77686_clk_cleanup(void)
{
platform_driver_unregister(&max77686_clk_driver);
}
