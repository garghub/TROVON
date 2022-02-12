static int ab8500_ext_regulator_enable(struct regulator_dev *rdev)
{
int ret;
struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
if (info->cfg && info->cfg->hwreq)
regval = info->update_val_hp;
else
regval = info->update_val;
ret = abx500_mask_and_set_register_interruptible(info->dev,
info->update_bank, info->update_reg,
info->update_mask, regval);
if (ret < 0) {
dev_err(rdev_get_dev(info->rdev),
"couldn't set enable bits for regulator\n");
return ret;
}
dev_dbg(rdev_get_dev(rdev),
"%s-enable (bank, reg, mask, value): 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
info->desc.name, info->update_bank, info->update_reg,
info->update_mask, regval);
return 0;
}
static int ab8500_ext_regulator_disable(struct regulator_dev *rdev)
{
int ret;
struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
if (info->cfg && info->cfg->hwreq)
regval = info->update_val_hw;
else
regval = 0;
ret = abx500_mask_and_set_register_interruptible(info->dev,
info->update_bank, info->update_reg,
info->update_mask, regval);
if (ret < 0) {
dev_err(rdev_get_dev(info->rdev),
"couldn't set disable bits for regulator\n");
return ret;
}
dev_dbg(rdev_get_dev(rdev), "%s-disable (bank, reg, mask, value):"
" 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
info->desc.name, info->update_bank, info->update_reg,
info->update_mask, regval);
return 0;
}
static int ab8500_ext_regulator_is_enabled(struct regulator_dev *rdev)
{
int ret;
struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
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
dev_dbg(rdev_get_dev(rdev), "%s-is_enabled (bank, reg, mask, value):"
" 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
info->desc.name, info->update_bank, info->update_reg,
info->update_mask, regval);
if (((regval & info->update_mask) == info->update_val_lp) ||
((regval & info->update_mask) == info->update_val_hp))
return 1;
else
return 0;
}
static int ab8500_ext_regulator_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
int ret = 0;
struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
switch (mode) {
case REGULATOR_MODE_NORMAL:
regval = info->update_val_hp;
break;
case REGULATOR_MODE_IDLE:
regval = info->update_val_lp;
break;
default:
return -EINVAL;
}
if (ab8500_ext_regulator_is_enabled(rdev) &&
!(info->cfg && info->cfg->hwreq)) {
ret = abx500_mask_and_set_register_interruptible(info->dev,
info->update_bank, info->update_reg,
info->update_mask, regval);
if (ret < 0) {
dev_err(rdev_get_dev(rdev),
"Could not set regulator mode.\n");
return ret;
}
dev_dbg(rdev_get_dev(rdev),
"%s-set_mode (bank, reg, mask, value): "
"0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->update_bank, info->update_reg,
info->update_mask, regval);
}
info->update_val = regval;
return 0;
}
static unsigned int ab8500_ext_regulator_get_mode(struct regulator_dev *rdev)
{
struct ab8500_ext_regulator_info *info = rdev_get_drvdata(rdev);
int ret;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
if (info->update_val == info->update_val_hp)
ret = REGULATOR_MODE_NORMAL;
else if (info->update_val == info->update_val_lp)
ret = REGULATOR_MODE_IDLE;
else
ret = -EINVAL;
return ret;
}
static int ab8500_ext_set_voltage(struct regulator_dev *rdev, int min_uV,
int max_uV, unsigned *selector)
{
struct regulation_constraints *regu_constraints = rdev->constraints;
if (!regu_constraints) {
dev_err(rdev_get_dev(rdev), "No regulator constraints\n");
return -EINVAL;
}
if (regu_constraints->min_uV == min_uV &&
regu_constraints->max_uV == max_uV)
return 0;
dev_err(rdev_get_dev(rdev),
"Requested min %duV max %duV != constrained min %duV max %duV\n",
min_uV, max_uV,
regu_constraints->min_uV, regu_constraints->max_uV);
return -EINVAL;
}
static int ab8500_ext_list_voltage(struct regulator_dev *rdev,
unsigned selector)
{
struct regulation_constraints *regu_constraints = rdev->constraints;
if (regu_constraints == NULL) {
dev_err(rdev_get_dev(rdev), "regulator constraints null pointer\n");
return -EINVAL;
}
if (regu_constraints->min_uV && regu_constraints->max_uV) {
if (regu_constraints->min_uV == regu_constraints->max_uV)
return regu_constraints->min_uV;
}
return -EINVAL;
}
static int ab8500_ext_regulator_probe(struct platform_device *pdev)
{
struct ab8500 *ab8500 = dev_get_drvdata(pdev->dev.parent);
struct ab8500_platform_data *ppdata;
struct ab8500_regulator_platform_data *pdata;
struct device_node *np = pdev->dev.of_node;
struct regulator_config config = { };
int i, err;
if (np) {
err = of_regulator_match(&pdev->dev, np,
ab8500_ext_regulator_match,
ARRAY_SIZE(ab8500_ext_regulator_match));
if (err < 0) {
dev_err(&pdev->dev,
"Error parsing regulator init data: %d\n", err);
return err;
}
}
if (!ab8500) {
dev_err(&pdev->dev, "null mfd parent\n");
return -EINVAL;
}
ppdata = dev_get_platdata(ab8500->dev);
if (!ppdata) {
dev_err(&pdev->dev, "null parent pdata\n");
return -EINVAL;
}
pdata = ppdata->regulator;
if (!pdata) {
dev_err(&pdev->dev, "null pdata\n");
return -EINVAL;
}
if (pdata->num_ext_regulator != ARRAY_SIZE(ab8500_ext_regulator_info)) {
dev_err(&pdev->dev, "Configuration error: size mismatch.\n");
return -EINVAL;
}
if (is_ab8500_2p0_or_earlier(ab8500)) {
struct ab8500_ext_regulator_info *info;
info = &ab8500_ext_regulator_info[AB8500_EXT_SUPPLY3];
info->update_val = 0x30;
info->update_val_hp = 0x30;
info->update_val_lp = 0x10;
}
for (i = 0; i < ARRAY_SIZE(ab8500_ext_regulator_info); i++) {
struct ab8500_ext_regulator_info *info = NULL;
info = &ab8500_ext_regulator_info[i];
info->dev = &pdev->dev;
info->cfg = (struct ab8500_ext_regulator_cfg *)
pdata->ext_regulator[i].driver_data;
config.dev = &pdev->dev;
config.driver_data = info;
config.of_node = ab8500_ext_regulator_match[i].of_node;
config.init_data = (np) ?
ab8500_ext_regulator_match[i].init_data :
&pdata->ext_regulator[i];
info->rdev = devm_regulator_register(&pdev->dev, &info->desc,
&config);
if (IS_ERR(info->rdev)) {
err = PTR_ERR(info->rdev);
dev_err(&pdev->dev, "failed to register regulator %s\n",
info->desc.name);
return err;
}
dev_dbg(rdev_get_dev(info->rdev),
"%s-probed\n", info->desc.name);
}
return 0;
}
static int __init ab8500_ext_regulator_init(void)
{
int ret;
ret = platform_driver_register(&ab8500_ext_regulator_driver);
if (ret)
pr_err("Failed to register ab8500 ext regulator: %d\n", ret);
return ret;
}
static void __exit ab8500_ext_regulator_exit(void)
{
platform_driver_unregister(&ab8500_ext_regulator_driver);
}
