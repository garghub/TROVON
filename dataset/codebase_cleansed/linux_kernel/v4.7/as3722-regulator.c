static int as3722_current_to_index(int min_uA, int max_uA,
const int *curr_table, int n_currents)
{
int i;
for (i = n_currents - 1; i >= 0; i--) {
if ((min_uA <= curr_table[i]) && (curr_table[i] <= max_uA))
return i;
}
return -EINVAL;
}
static int as3722_ldo_get_current_limit(struct regulator_dev *rdev)
{
struct as3722_regulators *as3722_regs = rdev_get_drvdata(rdev);
struct as3722 *as3722 = as3722_regs->as3722;
int id = rdev_get_id(rdev);
u32 val;
int ret;
ret = as3722_read(as3722, as3722_reg_lookup[id].vsel_reg, &val);
if (ret < 0) {
dev_err(as3722_regs->dev, "Reg 0x%02x read failed: %d\n",
as3722_reg_lookup[id].vsel_reg, ret);
return ret;
}
if (val & AS3722_LDO_ILIMIT_MASK)
return 300000;
return 150000;
}
static int as3722_ldo_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
struct as3722_regulators *as3722_regs = rdev_get_drvdata(rdev);
struct as3722 *as3722 = as3722_regs->as3722;
int id = rdev_get_id(rdev);
int ret;
u32 reg = 0;
ret = as3722_current_to_index(min_uA, max_uA, as3722_ldo_current,
ARRAY_SIZE(as3722_ldo_current));
if (ret < 0) {
dev_err(as3722_regs->dev,
"Current range min:max = %d:%d does not support\n",
min_uA, max_uA);
return ret;
}
if (ret)
reg = AS3722_LDO_ILIMIT_BIT;
return as3722_update_bits(as3722, as3722_reg_lookup[id].vsel_reg,
AS3722_LDO_ILIMIT_MASK, reg);
}
static int as3722_ldo3_set_tracking_mode(struct as3722_regulators *as3722_reg,
int id, u8 mode)
{
struct as3722 *as3722 = as3722_reg->as3722;
switch (mode) {
case AS3722_LDO3_MODE_PMOS:
case AS3722_LDO3_MODE_PMOS_TRACKING:
case AS3722_LDO3_MODE_NMOS:
case AS3722_LDO3_MODE_SWITCH:
return as3722_update_bits(as3722,
as3722_reg_lookup[id].vsel_reg,
AS3722_LDO3_MODE_MASK, mode);
default:
return -EINVAL;
}
}
static int as3722_ldo3_get_current_limit(struct regulator_dev *rdev)
{
return 150000;
}
static unsigned int as3722_sd_get_mode(struct regulator_dev *rdev)
{
struct as3722_regulators *as3722_regs = rdev_get_drvdata(rdev);
struct as3722 *as3722 = as3722_regs->as3722;
int id = rdev_get_id(rdev);
u32 val;
int ret;
if (!as3722_reg_lookup[id].control_reg)
return -ENOTSUPP;
ret = as3722_read(as3722, as3722_reg_lookup[id].control_reg, &val);
if (ret < 0) {
dev_err(as3722_regs->dev, "Reg 0x%02x read failed: %d\n",
as3722_reg_lookup[id].control_reg, ret);
return ret;
}
if (val & as3722_reg_lookup[id].mode_mask)
return REGULATOR_MODE_FAST;
else
return REGULATOR_MODE_NORMAL;
}
static int as3722_sd_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct as3722_regulators *as3722_regs = rdev_get_drvdata(rdev);
struct as3722 *as3722 = as3722_regs->as3722;
u8 id = rdev_get_id(rdev);
u8 val = 0;
int ret;
if (!as3722_reg_lookup[id].control_reg)
return -ERANGE;
switch (mode) {
case REGULATOR_MODE_FAST:
val = as3722_reg_lookup[id].mode_mask;
case REGULATOR_MODE_NORMAL:
break;
default:
return -EINVAL;
}
ret = as3722_update_bits(as3722, as3722_reg_lookup[id].control_reg,
as3722_reg_lookup[id].mode_mask, val);
if (ret < 0) {
dev_err(as3722_regs->dev, "Reg 0x%02x update failed: %d\n",
as3722_reg_lookup[id].control_reg, ret);
return ret;
}
return ret;
}
static int as3722_sd016_get_current_limit(struct regulator_dev *rdev)
{
struct as3722_regulators *as3722_regs = rdev_get_drvdata(rdev);
struct as3722 *as3722 = as3722_regs->as3722;
int id = rdev_get_id(rdev);
u32 val, reg;
int mask;
int ret;
switch (id) {
case AS3722_REGULATOR_ID_SD0:
reg = AS3722_OVCURRENT_REG;
mask = AS3722_OVCURRENT_SD0_TRIP_MASK;
break;
case AS3722_REGULATOR_ID_SD1:
reg = AS3722_OVCURRENT_REG;
mask = AS3722_OVCURRENT_SD1_TRIP_MASK;
break;
case AS3722_REGULATOR_ID_SD6:
reg = AS3722_OVCURRENT_DEB_REG;
mask = AS3722_OVCURRENT_SD6_TRIP_MASK;
break;
default:
return -EINVAL;
}
ret = as3722_read(as3722, reg, &val);
if (ret < 0) {
dev_err(as3722_regs->dev, "Reg 0x%02x read failed: %d\n",
reg, ret);
return ret;
}
val &= mask;
val >>= ffs(mask) - 1;
if (val == 3)
return -EINVAL;
return as3722_sd016_current[val];
}
static int as3722_sd016_set_current_limit(struct regulator_dev *rdev,
int min_uA, int max_uA)
{
struct as3722_regulators *as3722_regs = rdev_get_drvdata(rdev);
struct as3722 *as3722 = as3722_regs->as3722;
int id = rdev_get_id(rdev);
int ret;
int val;
int mask;
u32 reg;
ret = as3722_current_to_index(min_uA, max_uA, as3722_sd016_current,
ARRAY_SIZE(as3722_sd016_current));
if (ret < 0) {
dev_err(as3722_regs->dev,
"Current range min:max = %d:%d does not support\n",
min_uA, max_uA);
return ret;
}
switch (id) {
case AS3722_REGULATOR_ID_SD0:
reg = AS3722_OVCURRENT_REG;
mask = AS3722_OVCURRENT_SD0_TRIP_MASK;
break;
case AS3722_REGULATOR_ID_SD1:
reg = AS3722_OVCURRENT_REG;
mask = AS3722_OVCURRENT_SD1_TRIP_MASK;
break;
case AS3722_REGULATOR_ID_SD6:
reg = AS3722_OVCURRENT_DEB_REG;
mask = AS3722_OVCURRENT_SD6_TRIP_MASK;
break;
default:
return -EINVAL;
}
ret <<= ffs(mask) - 1;
val = ret & mask;
return as3722_update_bits(as3722, reg, mask, val);
}
static bool as3722_sd0_is_low_voltage(struct as3722_regulators *as3722_regs)
{
int err;
unsigned val;
err = as3722_read(as3722_regs->as3722, AS3722_FUSE7_REG, &val);
if (err < 0) {
dev_err(as3722_regs->dev, "Reg 0x%02x read failed: %d\n",
AS3722_FUSE7_REG, err);
return false;
}
if (val & AS3722_FUSE7_SD0_LOW_VOLTAGE)
return true;
return false;
}
static int as3722_extreg_init(struct as3722_regulators *as3722_regs, int id,
int ext_pwr_ctrl)
{
int ret;
unsigned int val;
if ((ext_pwr_ctrl < AS3722_EXT_CONTROL_ENABLE1) ||
(ext_pwr_ctrl > AS3722_EXT_CONTROL_ENABLE3))
return -EINVAL;
val = ext_pwr_ctrl << (ffs(as3722_reg_lookup[id].sleep_ctrl_mask) - 1);
ret = as3722_update_bits(as3722_regs->as3722,
as3722_reg_lookup[id].sleep_ctrl_reg,
as3722_reg_lookup[id].sleep_ctrl_mask, val);
if (ret < 0)
dev_err(as3722_regs->dev, "Reg 0x%02x update failed: %d\n",
as3722_reg_lookup[id].sleep_ctrl_reg, ret);
return ret;
}
static int as3722_get_regulator_dt_data(struct platform_device *pdev,
struct as3722_regulators *as3722_regs)
{
struct device_node *np;
struct as3722_regulator_config_data *reg_config;
u32 prop;
int id;
int ret;
np = of_get_child_by_name(pdev->dev.parent->of_node, "regulators");
if (!np) {
dev_err(&pdev->dev, "Device is not having regulators node\n");
return -ENODEV;
}
pdev->dev.of_node = np;
ret = of_regulator_match(&pdev->dev, np, as3722_regulator_matches,
ARRAY_SIZE(as3722_regulator_matches));
of_node_put(np);
if (ret < 0) {
dev_err(&pdev->dev, "Parsing of regulator node failed: %d\n",
ret);
return ret;
}
for (id = 0; id < ARRAY_SIZE(as3722_regulator_matches); ++id) {
struct device_node *reg_node;
reg_config = &as3722_regs->reg_config_data[id];
reg_config->reg_init = as3722_regulator_matches[id].init_data;
reg_node = as3722_regulator_matches[id].of_node;
if (!reg_config->reg_init || !reg_node)
continue;
ret = of_property_read_u32(reg_node, "ams,ext-control", &prop);
if (!ret) {
if (prop < 3)
reg_config->ext_control = prop;
else
dev_warn(&pdev->dev,
"ext-control have invalid option: %u\n",
prop);
}
reg_config->enable_tracking =
of_property_read_bool(reg_node, "ams,enable-tracking");
}
return 0;
}
static int as3722_regulator_probe(struct platform_device *pdev)
{
struct as3722 *as3722 = dev_get_drvdata(pdev->dev.parent);
struct as3722_regulators *as3722_regs;
struct as3722_regulator_config_data *reg_config;
struct regulator_dev *rdev;
struct regulator_config config = { };
const struct regulator_ops *ops;
int id;
int ret;
as3722_regs = devm_kzalloc(&pdev->dev, sizeof(*as3722_regs),
GFP_KERNEL);
if (!as3722_regs)
return -ENOMEM;
as3722_regs->dev = &pdev->dev;
as3722_regs->as3722 = as3722;
platform_set_drvdata(pdev, as3722_regs);
ret = as3722_get_regulator_dt_data(pdev, as3722_regs);
if (ret < 0)
return ret;
config.dev = &pdev->dev;
config.driver_data = as3722_regs;
config.regmap = as3722->regmap;
for (id = 0; id < AS3722_REGULATOR_ID_MAX; id++) {
reg_config = &as3722_regs->reg_config_data[id];
as3722_regs->desc[id].name = as3722_reg_lookup[id].name;
as3722_regs->desc[id].supply_name = as3722_reg_lookup[id].sname;
as3722_regs->desc[id].id = as3722_reg_lookup[id].regulator_id;
as3722_regs->desc[id].n_voltages =
as3722_reg_lookup[id].n_voltages;
as3722_regs->desc[id].type = REGULATOR_VOLTAGE;
as3722_regs->desc[id].owner = THIS_MODULE;
as3722_regs->desc[id].enable_reg =
as3722_reg_lookup[id].enable_reg;
as3722_regs->desc[id].enable_mask =
as3722_reg_lookup[id].enable_mask;
as3722_regs->desc[id].vsel_reg = as3722_reg_lookup[id].vsel_reg;
as3722_regs->desc[id].vsel_mask =
as3722_reg_lookup[id].vsel_mask;
switch (id) {
case AS3722_REGULATOR_ID_LDO0:
if (reg_config->ext_control)
ops = &as3722_ldo0_extcntrl_ops;
else
ops = &as3722_ldo0_ops;
as3722_regs->desc[id].min_uV = 825000;
as3722_regs->desc[id].uV_step = 25000;
as3722_regs->desc[id].linear_min_sel = 1;
as3722_regs->desc[id].enable_time = 500;
break;
case AS3722_REGULATOR_ID_LDO3:
if (reg_config->ext_control)
ops = &as3722_ldo3_extcntrl_ops;
else
ops = &as3722_ldo3_ops;
as3722_regs->desc[id].min_uV = 620000;
as3722_regs->desc[id].uV_step = 20000;
as3722_regs->desc[id].linear_min_sel = 1;
as3722_regs->desc[id].enable_time = 500;
if (reg_config->enable_tracking) {
ret = as3722_ldo3_set_tracking_mode(as3722_regs,
id, AS3722_LDO3_MODE_PMOS_TRACKING);
if (ret < 0) {
dev_err(&pdev->dev,
"LDO3 tracking failed: %d\n",
ret);
return ret;
}
}
break;
case AS3722_REGULATOR_ID_LDO6:
if (reg_config->ext_control)
ops = &as3722_ldo6_extcntrl_ops;
else
ops = &as3722_ldo6_ops;
as3722_regs->desc[id].enable_time = 500;
as3722_regs->desc[id].bypass_reg =
AS3722_LDO6_VOLTAGE_REG;
as3722_regs->desc[id].bypass_mask =
AS3722_LDO_VSEL_MASK;
as3722_regs->desc[id].bypass_val_on =
AS3722_LDO6_VSEL_BYPASS;
as3722_regs->desc[id].bypass_val_off =
AS3722_LDO6_VSEL_BYPASS;
as3722_regs->desc[id].linear_ranges = as3722_ldo_ranges;
as3722_regs->desc[id].n_linear_ranges =
ARRAY_SIZE(as3722_ldo_ranges);
break;
case AS3722_REGULATOR_ID_SD0:
case AS3722_REGULATOR_ID_SD1:
case AS3722_REGULATOR_ID_SD6:
if (reg_config->ext_control)
ops = &as3722_sd016_extcntrl_ops;
else
ops = &as3722_sd016_ops;
if (id == AS3722_REGULATOR_ID_SD0 &&
as3722_sd0_is_low_voltage(as3722_regs)) {
as3722_regs->desc[id].n_voltages =
AS3722_SD0_VSEL_LOW_VOL_MAX + 1;
as3722_regs->desc[id].min_uV = 410000;
} else {
as3722_regs->desc[id].n_voltages =
AS3722_SD0_VSEL_MAX + 1,
as3722_regs->desc[id].min_uV = 610000;
}
as3722_regs->desc[id].uV_step = 10000;
as3722_regs->desc[id].linear_min_sel = 1;
as3722_regs->desc[id].enable_time = 600;
break;
case AS3722_REGULATOR_ID_SD2:
case AS3722_REGULATOR_ID_SD3:
case AS3722_REGULATOR_ID_SD4:
case AS3722_REGULATOR_ID_SD5:
if (reg_config->ext_control)
ops = &as3722_sd2345_extcntrl_ops;
else
ops = &as3722_sd2345_ops;
as3722_regs->desc[id].linear_ranges =
as3722_sd2345_ranges;
as3722_regs->desc[id].n_linear_ranges =
ARRAY_SIZE(as3722_sd2345_ranges);
break;
default:
if (reg_config->ext_control)
ops = &as3722_ldo_extcntrl_ops;
else
ops = &as3722_ldo_ops;
as3722_regs->desc[id].enable_time = 500;
as3722_regs->desc[id].linear_ranges = as3722_ldo_ranges;
as3722_regs->desc[id].n_linear_ranges =
ARRAY_SIZE(as3722_ldo_ranges);
break;
}
as3722_regs->desc[id].ops = ops;
config.init_data = reg_config->reg_init;
config.of_node = as3722_regulator_matches[id].of_node;
rdev = devm_regulator_register(&pdev->dev,
&as3722_regs->desc[id], &config);
if (IS_ERR(rdev)) {
ret = PTR_ERR(rdev);
dev_err(&pdev->dev, "regulator %d register failed %d\n",
id, ret);
return ret;
}
as3722_regs->rdevs[id] = rdev;
if (reg_config->ext_control) {
ret = regulator_enable_regmap(rdev);
if (ret < 0) {
dev_err(&pdev->dev,
"Regulator %d enable failed: %d\n",
id, ret);
return ret;
}
ret = as3722_extreg_init(as3722_regs, id,
reg_config->ext_control);
if (ret < 0) {
dev_err(&pdev->dev,
"AS3722 ext control failed: %d", ret);
return ret;
}
}
}
return 0;
}
