static int ab8500_regulator_enable(struct regulator_dev *rdev)
{
int ret;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
ret = abx500_mask_and_set_register_interruptible(info->dev,
info->update_bank, info->update_reg,
info->update_mask, info->update_val);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't set enable bits for regulator\n");
return ret;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-enable (bank, reg, mask, value): 0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->update_bank, info->update_reg,
info->update_mask, info->update_val);
return ret;
}
static int ab8500_regulator_disable(struct regulator_dev *rdev)
{
int ret;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
ret = abx500_mask_and_set_register_interruptible(info->dev,
info->update_bank, info->update_reg,
info->update_mask, 0x0);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't set disable bits for regulator\n");
return ret;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-disable (bank, reg, mask, value): 0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->update_bank, info->update_reg,
info->update_mask, 0x0);
return ret;
}
static int ab8500_regulator_is_enabled(struct regulator_dev *rdev)
{
int ret;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
ret = abx500_get_register_interruptible(info->dev,
info->update_bank, info->update_reg, &regval);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't read 0x%x register\n", info->update_reg);
return ret;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-is_enabled (bank, reg, mask, value): 0x%x, 0x%x, 0x%x,"
" 0x%x\n",
info->desc.name, info->update_bank, info->update_reg,
info->update_mask, regval);
if (regval & info->update_mask)
return 1;
else
return 0;
}
static unsigned int ab8500_regulator_get_optimum_mode(
struct regulator_dev *rdev, int input_uV,
int output_uV, int load_uA)
{
unsigned int mode;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
if (load_uA <= info->load_lp_uA)
mode = REGULATOR_MODE_IDLE;
else
mode = REGULATOR_MODE_NORMAL;
return mode;
}
static int ab8500_regulator_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
int ret = 0;
u8 bank, reg, mask, val;
bool lp_mode_req = false;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
if (info->mode_mask) {
bank = info->mode_bank;
reg = info->mode_reg;
mask = info->mode_mask;
} else {
bank = info->update_bank;
reg = info->update_reg;
mask = info->update_mask;
}
if (info->shared_mode)
mutex_lock(&shared_mode_mutex);
switch (mode) {
case REGULATOR_MODE_NORMAL:
if (info->shared_mode)
lp_mode_req = false;
if (info->mode_mask)
val = info->mode_val_normal;
else
val = info->update_val_normal;
break;
case REGULATOR_MODE_IDLE:
if (info->shared_mode) {
struct ab8500_regulator_info *shared_regulator;
shared_regulator = info->shared_mode->shared_regulator;
if (!shared_regulator->shared_mode->lp_mode_req) {
info->shared_mode->lp_mode_req = true;
goto out_unlock;
}
lp_mode_req = true;
}
if (info->mode_mask)
val = info->mode_val_idle;
else
val = info->update_val_idle;
break;
default:
ret = -EINVAL;
goto out_unlock;
}
if (info->mode_mask || ab8500_regulator_is_enabled(rdev)) {
ret = abx500_mask_and_set_register_interruptible(info->dev,
bank, reg, mask, val);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't set regulator mode\n");
goto out_unlock;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-set_mode (bank, reg, mask, value): "
"0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, bank, reg,
mask, val);
}
if (!info->mode_mask)
info->update_val = val;
if (info->shared_mode)
info->shared_mode->lp_mode_req = lp_mode_req;
out_unlock:
if (info->shared_mode)
mutex_unlock(&shared_mode_mutex);
return ret;
}
static unsigned int ab8500_regulator_get_mode(struct regulator_dev *rdev)
{
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
int ret;
u8 val;
u8 val_normal;
u8 val_idle;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
if (info->shared_mode) {
if (info->shared_mode->lp_mode_req)
return REGULATOR_MODE_IDLE;
else
return REGULATOR_MODE_NORMAL;
}
if (info->mode_mask) {
ret = abx500_get_register_interruptible(info->dev,
info->mode_bank, info->mode_reg, &val);
val = val & info->mode_mask;
val_normal = info->mode_val_normal;
val_idle = info->mode_val_idle;
} else {
val = info->update_val;
val_normal = info->update_val_normal;
val_idle = info->update_val_idle;
}
if (val == val_normal)
ret = REGULATOR_MODE_NORMAL;
else if (val == val_idle)
ret = REGULATOR_MODE_IDLE;
else
ret = -EINVAL;
return ret;
}
static int ab8500_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
int ret, voltage_shift;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
voltage_shift = ffs(info->voltage_mask) - 1;
ret = abx500_get_register_interruptible(info->dev,
info->voltage_bank, info->voltage_reg, &regval);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't read voltage reg for regulator\n");
return ret;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-get_voltage (bank, reg, mask, shift, value): "
"0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->voltage_bank,
info->voltage_reg, info->voltage_mask,
voltage_shift, regval);
return (regval & info->voltage_mask) >> voltage_shift;
}
static int ab8540_aux3_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
int ret, voltage_shift;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval, regval_expand;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
ret = abx500_get_register_interruptible(info->dev,
info->expand_register.voltage_bank,
info->expand_register.voltage_reg, &regval_expand);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't read voltage expand reg for regulator\n");
return ret;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-get_voltage expand (bank, reg, mask, value): 0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->expand_register.voltage_bank,
info->expand_register.voltage_reg,
info->expand_register.voltage_mask, regval_expand);
if (regval_expand & info->expand_register.voltage_mask)
return info->expand_register.voltage_limit;
ret = abx500_get_register_interruptible(info->dev,
info->voltage_bank, info->voltage_reg, &regval);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't read voltage reg for regulator\n");
return ret;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-get_voltage (bank, reg, mask, value): 0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->voltage_bank, info->voltage_reg,
info->voltage_mask, regval);
voltage_shift = ffs(info->voltage_mask) - 1;
return (regval & info->voltage_mask) >> voltage_shift;
}
static int ab8500_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
int ret, voltage_shift;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
voltage_shift = ffs(info->voltage_mask) - 1;
regval = (u8)selector << voltage_shift;
ret = abx500_mask_and_set_register_interruptible(info->dev,
info->voltage_bank, info->voltage_reg,
info->voltage_mask, regval);
if (ret < 0)
dev_err(rdev_get_dev(rdev),
"couldn't set voltage reg for regulator\n");
dev_vdbg(rdev_get_dev(rdev),
"%s-set_voltage (bank, reg, mask, value): 0x%x, 0x%x, 0x%x,"
" 0x%x\n",
info->desc.name, info->voltage_bank, info->voltage_reg,
info->voltage_mask, regval);
return ret;
}
static int ab8540_aux3_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
int ret;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval, regval_expand;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
if (selector < info->expand_register.voltage_limit) {
int voltage_shift = ffs(info->voltage_mask) - 1;
regval = (u8)selector << voltage_shift;
ret = abx500_mask_and_set_register_interruptible(info->dev,
info->voltage_bank, info->voltage_reg,
info->voltage_mask, regval);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't set voltage reg for regulator\n");
return ret;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-set_voltage (bank, reg, mask, value): 0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->voltage_bank, info->voltage_reg,
info->voltage_mask, regval);
regval_expand = 0;
} else {
regval_expand = info->expand_register.voltage_mask;
}
ret = abx500_mask_and_set_register_interruptible(info->dev,
info->expand_register.voltage_bank,
info->expand_register.voltage_reg,
info->expand_register.voltage_mask,
regval_expand);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"couldn't set expand voltage reg for regulator\n");
return ret;
}
dev_vdbg(rdev_get_dev(rdev),
"%s-set_voltage expand (bank, reg, mask, value): 0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->expand_register.voltage_bank,
info->expand_register.voltage_reg,
info->expand_register.voltage_mask, regval_expand);
return 0;
}
static void abx500_get_regulator_info(struct ab8500 *ab8500)
{
if (is_ab9540(ab8500)) {
abx500_regulator.info = ab9540_regulator_info;
abx500_regulator.info_size = ARRAY_SIZE(ab9540_regulator_info);
abx500_regulator.init = ab9540_reg_init;
abx500_regulator.init_size = AB9540_NUM_REGULATOR_REGISTERS;
abx500_regulator.match = ab9540_regulator_match;
abx500_regulator.match_size = ARRAY_SIZE(ab9540_regulator_match);
} else if (is_ab8505(ab8500)) {
abx500_regulator.info = ab8505_regulator_info;
abx500_regulator.info_size = ARRAY_SIZE(ab8505_regulator_info);
abx500_regulator.init = ab8505_reg_init;
abx500_regulator.init_size = AB8505_NUM_REGULATOR_REGISTERS;
abx500_regulator.match = ab8505_regulator_match;
abx500_regulator.match_size = ARRAY_SIZE(ab8505_regulator_match);
} else if (is_ab8540(ab8500)) {
abx500_regulator.info = ab8540_regulator_info;
abx500_regulator.info_size = ARRAY_SIZE(ab8540_regulator_info);
abx500_regulator.init = ab8540_reg_init;
abx500_regulator.init_size = AB8540_NUM_REGULATOR_REGISTERS;
abx500_regulator.match = ab8540_regulator_match;
abx500_regulator.match_size = ARRAY_SIZE(ab8540_regulator_match);
} else {
abx500_regulator.info = ab8500_regulator_info;
abx500_regulator.info_size = ARRAY_SIZE(ab8500_regulator_info);
abx500_regulator.init = ab8500_reg_init;
abx500_regulator.init_size = AB8500_NUM_REGULATOR_REGISTERS;
abx500_regulator.match = ab8500_regulator_match;
abx500_regulator.match_size = ARRAY_SIZE(ab8500_regulator_match);
}
}
static int ab8500_regulator_register(struct platform_device *pdev,
struct regulator_init_data *init_data,
int id, struct device_node *np)
{
struct ab8500 *ab8500 = dev_get_drvdata(pdev->dev.parent);
struct ab8500_regulator_info *info = NULL;
struct regulator_config config = { };
info = &abx500_regulator.info[id];
info->dev = &pdev->dev;
config.dev = &pdev->dev;
config.init_data = init_data;
config.driver_data = info;
config.of_node = np;
if (is_ab8500_1p1_or_earlier(ab8500)) {
if (info->desc.id == AB8500_LDO_AUX3) {
info->desc.n_voltages =
ARRAY_SIZE(ldo_vauxn_voltages);
info->desc.volt_table = ldo_vauxn_voltages;
info->voltage_mask = 0xf;
}
}
info->regulator = devm_regulator_register(&pdev->dev, &info->desc,
&config);
if (IS_ERR(info->regulator)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
info->desc.name);
return PTR_ERR(info->regulator);
}
return 0;
}
static int ab8500_regulator_probe(struct platform_device *pdev)
{
struct ab8500 *ab8500 = dev_get_drvdata(pdev->dev.parent);
struct device_node *np = pdev->dev.of_node;
struct of_regulator_match *match;
int err, i;
if (!ab8500) {
dev_err(&pdev->dev, "null mfd parent\n");
return -EINVAL;
}
abx500_get_regulator_info(ab8500);
err = of_regulator_match(&pdev->dev, np,
abx500_regulator.match,
abx500_regulator.match_size);
if (err < 0) {
dev_err(&pdev->dev,
"Error parsing regulator init data: %d\n", err);
return err;
}
match = abx500_regulator.match;
for (i = 0; i < abx500_regulator.info_size; i++) {
err = ab8500_regulator_register(pdev, match[i].init_data, i,
match[i].of_node);
if (err)
return err;
}
return 0;
}
static int __init ab8500_regulator_init(void)
{
int ret;
ret = platform_driver_register(&ab8500_regulator_driver);
if (ret != 0)
pr_err("Failed to register ab8500 regulator: %d\n", ret);
return ret;
}
static void __exit ab8500_regulator_exit(void)
{
platform_driver_unregister(&ab8500_regulator_driver);
}
