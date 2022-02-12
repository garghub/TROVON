int regulator_is_enabled_regmap(struct regulator_dev *rdev)
{
unsigned int val;
int ret;
ret = regmap_read(rdev->regmap, rdev->desc->enable_reg, &val);
if (ret != 0)
return ret;
val &= rdev->desc->enable_mask;
if (rdev->desc->enable_is_inverted) {
if (rdev->desc->enable_val)
return val != rdev->desc->enable_val;
return val == 0;
} else {
if (rdev->desc->enable_val)
return val == rdev->desc->enable_val;
return val != 0;
}
}
int regulator_enable_regmap(struct regulator_dev *rdev)
{
unsigned int val;
if (rdev->desc->enable_is_inverted) {
val = rdev->desc->disable_val;
} else {
val = rdev->desc->enable_val;
if (!val)
val = rdev->desc->enable_mask;
}
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val);
}
int regulator_disable_regmap(struct regulator_dev *rdev)
{
unsigned int val;
if (rdev->desc->enable_is_inverted) {
val = rdev->desc->enable_val;
if (!val)
val = rdev->desc->enable_mask;
} else {
val = rdev->desc->disable_val;
}
return regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, val);
}
int regulator_get_voltage_sel_regmap(struct regulator_dev *rdev)
{
unsigned int val;
int ret;
ret = regmap_read(rdev->regmap, rdev->desc->vsel_reg, &val);
if (ret != 0)
return ret;
val &= rdev->desc->vsel_mask;
val >>= ffs(rdev->desc->vsel_mask) - 1;
return val;
}
int regulator_set_voltage_sel_regmap(struct regulator_dev *rdev, unsigned sel)
{
int ret;
sel <<= ffs(rdev->desc->vsel_mask) - 1;
ret = regmap_update_bits(rdev->regmap, rdev->desc->vsel_reg,
rdev->desc->vsel_mask, sel);
if (ret)
return ret;
if (rdev->desc->apply_bit)
ret = regmap_update_bits(rdev->regmap, rdev->desc->apply_reg,
rdev->desc->apply_bit,
rdev->desc->apply_bit);
return ret;
}
int regulator_map_voltage_iterate(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int best_val = INT_MAX;
int selector = 0;
int i, ret;
for (i = 0; i < rdev->desc->n_voltages; i++) {
ret = rdev->desc->ops->list_voltage(rdev, i);
if (ret < 0)
continue;
if (ret < best_val && ret >= min_uV && ret <= max_uV) {
best_val = ret;
selector = i;
}
}
if (best_val != INT_MAX)
return selector;
else
return -EINVAL;
}
int regulator_map_voltage_ascend(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int i, ret;
for (i = 0; i < rdev->desc->n_voltages; i++) {
ret = rdev->desc->ops->list_voltage(rdev, i);
if (ret < 0)
continue;
if (ret > max_uV)
break;
if (ret >= min_uV && ret <= max_uV)
return i;
}
return -EINVAL;
}
int regulator_map_voltage_linear(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
int ret, voltage;
if (rdev->desc->n_voltages == 1 && rdev->desc->uV_step == 0) {
if (min_uV <= rdev->desc->min_uV && rdev->desc->min_uV <= max_uV)
return 0;
else
return -EINVAL;
}
if (!rdev->desc->uV_step) {
BUG_ON(!rdev->desc->uV_step);
return -EINVAL;
}
if (min_uV < rdev->desc->min_uV)
min_uV = rdev->desc->min_uV;
ret = DIV_ROUND_UP(min_uV - rdev->desc->min_uV, rdev->desc->uV_step);
if (ret < 0)
return ret;
ret += rdev->desc->linear_min_sel;
voltage = rdev->desc->ops->list_voltage(rdev, ret);
if (voltage < min_uV || voltage > max_uV)
return -EINVAL;
return ret;
}
int regulator_map_voltage_linear_range(struct regulator_dev *rdev,
int min_uV, int max_uV)
{
const struct regulator_linear_range *range;
int ret = -EINVAL;
int voltage, i;
if (!rdev->desc->n_linear_ranges) {
BUG_ON(!rdev->desc->n_linear_ranges);
return -EINVAL;
}
for (i = 0; i < rdev->desc->n_linear_ranges; i++) {
int linear_max_uV;
range = &rdev->desc->linear_ranges[i];
linear_max_uV = range->min_uV +
(range->max_sel - range->min_sel) * range->uV_step;
if (!(min_uV <= linear_max_uV && max_uV >= range->min_uV))
continue;
if (min_uV <= range->min_uV)
min_uV = range->min_uV;
if (range->uV_step == 0) {
ret = 0;
} else {
ret = DIV_ROUND_UP(min_uV - range->min_uV,
range->uV_step);
if (ret < 0)
return ret;
}
ret += range->min_sel;
break;
}
if (i == rdev->desc->n_linear_ranges)
return -EINVAL;
voltage = rdev->desc->ops->list_voltage(rdev, ret);
if (voltage < min_uV || voltage > max_uV)
return -EINVAL;
return ret;
}
int regulator_list_voltage_linear(struct regulator_dev *rdev,
unsigned int selector)
{
if (selector >= rdev->desc->n_voltages)
return -EINVAL;
if (selector < rdev->desc->linear_min_sel)
return 0;
selector -= rdev->desc->linear_min_sel;
return rdev->desc->min_uV + (rdev->desc->uV_step * selector);
}
int regulator_list_voltage_linear_range(struct regulator_dev *rdev,
unsigned int selector)
{
const struct regulator_linear_range *range;
int i;
if (!rdev->desc->n_linear_ranges) {
BUG_ON(!rdev->desc->n_linear_ranges);
return -EINVAL;
}
for (i = 0; i < rdev->desc->n_linear_ranges; i++) {
range = &rdev->desc->linear_ranges[i];
if (!(selector >= range->min_sel &&
selector <= range->max_sel))
continue;
selector -= range->min_sel;
return range->min_uV + (range->uV_step * selector);
}
return -EINVAL;
}
int regulator_list_voltage_table(struct regulator_dev *rdev,
unsigned int selector)
{
if (!rdev->desc->volt_table) {
BUG_ON(!rdev->desc->volt_table);
return -EINVAL;
}
if (selector >= rdev->desc->n_voltages)
return -EINVAL;
return rdev->desc->volt_table[selector];
}
int regulator_set_bypass_regmap(struct regulator_dev *rdev, bool enable)
{
unsigned int val;
if (enable) {
val = rdev->desc->bypass_val_on;
if (!val)
val = rdev->desc->bypass_mask;
} else {
val = rdev->desc->bypass_val_off;
}
return regmap_update_bits(rdev->regmap, rdev->desc->bypass_reg,
rdev->desc->bypass_mask, val);
}
int regulator_get_bypass_regmap(struct regulator_dev *rdev, bool *enable)
{
unsigned int val;
int ret;
ret = regmap_read(rdev->regmap, rdev->desc->bypass_reg, &val);
if (ret != 0)
return ret;
*enable = val & rdev->desc->bypass_mask;
return 0;
}
