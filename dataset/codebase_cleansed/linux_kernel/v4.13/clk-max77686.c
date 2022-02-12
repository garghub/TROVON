static struct max77686_clk_init_data *to_max77686_clk_init_data(
struct clk_hw *hw)
{
return container_of(hw, struct max77686_clk_init_data, hw);
}
static int max77686_clk_prepare(struct clk_hw *hw)
{
struct max77686_clk_init_data *max77686 = to_max77686_clk_init_data(hw);
return regmap_update_bits(max77686->regmap, max77686->clk_info->clk_reg,
max77686->clk_info->clk_enable_mask,
max77686->clk_info->clk_enable_mask);
}
static void max77686_clk_unprepare(struct clk_hw *hw)
{
struct max77686_clk_init_data *max77686 = to_max77686_clk_init_data(hw);
regmap_update_bits(max77686->regmap, max77686->clk_info->clk_reg,
max77686->clk_info->clk_enable_mask,
~max77686->clk_info->clk_enable_mask);
}
static int max77686_clk_is_prepared(struct clk_hw *hw)
{
struct max77686_clk_init_data *max77686 = to_max77686_clk_init_data(hw);
int ret;
u32 val;
ret = regmap_read(max77686->regmap, max77686->clk_info->clk_reg, &val);
if (ret < 0)
return -EINVAL;
return val & max77686->clk_info->clk_enable_mask;
}
static unsigned long max77686_recalc_rate(struct clk_hw *hw,
unsigned long parent_rate)
{
return 32768;
}
static struct clk_hw *
of_clk_max77686_get(struct of_phandle_args *clkspec, void *data)
{
struct max77686_clk_driver_data *drv_data = data;
unsigned int idx = clkspec->args[0];
if (idx >= drv_data->num_clks) {
pr_err("%s: invalid index %u\n", __func__, idx);
return ERR_PTR(-EINVAL);
}
return &drv_data->max_clk_data[idx].hw;
}
static int max77686_clk_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device *parent = dev->parent;
const struct platform_device_id *id = platform_get_device_id(pdev);
struct max77686_clk_driver_data *drv_data;
const struct max77686_hw_clk_info *hw_clks;
struct regmap *regmap;
int i, ret, num_clks;
drv_data = devm_kzalloc(dev, sizeof(*drv_data), GFP_KERNEL);
if (!drv_data)
return -ENOMEM;
regmap = dev_get_regmap(parent, NULL);
if (!regmap) {
dev_err(dev, "Failed to get rtc regmap\n");
return -ENODEV;
}
drv_data->chip = id->driver_data;
switch (drv_data->chip) {
case CHIP_MAX77686:
num_clks = MAX77686_CLKS_NUM;
hw_clks = max77686_hw_clks_info;
break;
case CHIP_MAX77802:
num_clks = MAX77802_CLKS_NUM;
hw_clks = max77802_hw_clks_info;
break;
case CHIP_MAX77620:
num_clks = MAX77620_CLKS_NUM;
hw_clks = max77620_hw_clks_info;
break;
default:
dev_err(dev, "Unknown Chip ID\n");
return -EINVAL;
}
drv_data->num_clks = num_clks;
drv_data->max_clk_data = devm_kcalloc(dev, num_clks,
sizeof(*drv_data->max_clk_data),
GFP_KERNEL);
if (!drv_data->max_clk_data)
return -ENOMEM;
for (i = 0; i < num_clks; i++) {
struct max77686_clk_init_data *max_clk_data;
const char *clk_name;
max_clk_data = &drv_data->max_clk_data[i];
max_clk_data->regmap = regmap;
max_clk_data->clk_info = &hw_clks[i];
max_clk_data->clk_idata.flags = hw_clks[i].flags;
max_clk_data->clk_idata.ops = &max77686_clk_ops;
if (parent->of_node &&
!of_property_read_string_index(parent->of_node,
"clock-output-names",
i, &clk_name))
max_clk_data->clk_idata.name = clk_name;
else
max_clk_data->clk_idata.name = hw_clks[i].name;
max_clk_data->hw.init = &max_clk_data->clk_idata;
ret = devm_clk_hw_register(dev, &max_clk_data->hw);
if (ret) {
dev_err(dev, "Failed to clock register: %d\n", ret);
return ret;
}
ret = clk_hw_register_clkdev(&max_clk_data->hw,
max_clk_data->clk_idata.name, NULL);
if (ret < 0) {
dev_err(dev, "Failed to clkdev register: %d\n", ret);
return ret;
}
}
if (parent->of_node) {
ret = of_clk_add_hw_provider(parent->of_node, of_clk_max77686_get,
drv_data);
if (ret < 0) {
dev_err(dev, "Failed to register OF clock provider: %d\n",
ret);
return ret;
}
}
if (drv_data->chip == CHIP_MAX77802) {
ret = regmap_update_bits(regmap, MAX77802_REG_32KHZ,
1 << MAX77802_CLOCK_LOW_JITTER_SHIFT,
1 << MAX77802_CLOCK_LOW_JITTER_SHIFT);
if (ret < 0) {
dev_err(dev, "Failed to config low-jitter: %d\n", ret);
goto remove_of_clk_provider;
}
}
return 0;
remove_of_clk_provider:
if (parent->of_node)
of_clk_del_provider(parent->of_node);
return ret;
}
static int max77686_clk_remove(struct platform_device *pdev)
{
struct device *parent = pdev->dev.parent;
if (parent->of_node)
of_clk_del_provider(parent->of_node);
return 0;
}
