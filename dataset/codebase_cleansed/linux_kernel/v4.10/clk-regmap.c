int clk_is_enabled_regmap(struct clk_hw *hw)
{
struct clk_regmap *rclk = to_clk_regmap(hw);
unsigned int val;
int ret;
ret = regmap_read(rclk->regmap, rclk->enable_reg, &val);
if (ret != 0)
return ret;
if (rclk->enable_is_inverted)
return (val & rclk->enable_mask) == 0;
else
return (val & rclk->enable_mask) != 0;
}
int clk_enable_regmap(struct clk_hw *hw)
{
struct clk_regmap *rclk = to_clk_regmap(hw);
unsigned int val;
if (rclk->enable_is_inverted)
val = 0;
else
val = rclk->enable_mask;
return regmap_update_bits(rclk->regmap, rclk->enable_reg,
rclk->enable_mask, val);
}
void clk_disable_regmap(struct clk_hw *hw)
{
struct clk_regmap *rclk = to_clk_regmap(hw);
unsigned int val;
if (rclk->enable_is_inverted)
val = rclk->enable_mask;
else
val = 0;
regmap_update_bits(rclk->regmap, rclk->enable_reg, rclk->enable_mask,
val);
}
int devm_clk_register_regmap(struct device *dev, struct clk_regmap *rclk)
{
if (dev && dev_get_regmap(dev, NULL))
rclk->regmap = dev_get_regmap(dev, NULL);
else if (dev && dev->parent)
rclk->regmap = dev_get_regmap(dev->parent, NULL);
return devm_clk_hw_register(dev, &rclk->hw);
}
