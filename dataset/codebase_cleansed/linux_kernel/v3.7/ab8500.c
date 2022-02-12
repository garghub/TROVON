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
info->update_mask, info->update_val_enable);
if (ret < 0)
dev_err(rdev_get_dev(rdev),
"couldn't set enable bits for regulator\n");
dev_vdbg(rdev_get_dev(rdev),
"%s-enable (bank, reg, mask, value): 0x%x, 0x%x, 0x%x, 0x%x\n",
info->desc.name, info->update_bank, info->update_reg,
info->update_mask, info->update_val_enable);
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
if (ret < 0)
dev_err(rdev_get_dev(rdev),
"couldn't set disable bits for regulator\n");
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
return true;
else
return false;
}
static int ab8500_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
int ret, val;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
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
info->voltage_shift, regval);
val = regval & info->voltage_mask;
return val >> info->voltage_shift;
}
static int ab8500_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned selector)
{
int ret;
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
u8 regval;
if (info == NULL) {
dev_err(rdev_get_dev(rdev), "regulator info null pointer\n");
return -EINVAL;
}
regval = (u8)selector << info->voltage_shift;
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
static int ab8500_regulator_set_voltage_time_sel(struct regulator_dev *rdev,
unsigned int old_sel,
unsigned int new_sel)
{
struct ab8500_regulator_info *info = rdev_get_drvdata(rdev);
return info->delay;
}
static __devinit int
ab8500_regulator_init_registers(struct platform_device *pdev, int id, int value)
{
int err;
if (value & ~ab8500_reg_init[id].mask) {
dev_err(&pdev->dev,
"Configuration error: value outside mask.\n");
return -EINVAL;
}
err = abx500_mask_and_set_register_interruptible(
&pdev->dev,
ab8500_reg_init[id].bank,
ab8500_reg_init[id].addr,
ab8500_reg_init[id].mask,
value);
if (err < 0) {
dev_err(&pdev->dev,
"Failed to initialize 0x%02x, 0x%02x.\n",
ab8500_reg_init[id].bank,
ab8500_reg_init[id].addr);
return err;
}
dev_vdbg(&pdev->dev,
"init: 0x%02x, 0x%02x, 0x%02x, 0x%02x\n",
ab8500_reg_init[id].bank,
ab8500_reg_init[id].addr,
ab8500_reg_init[id].mask,
value);
return 0;
}
static __devinit int ab8500_regulator_register(struct platform_device *pdev,
struct regulator_init_data *init_data,
int id,
struct device_node *np)
{
struct ab8500_regulator_info *info = NULL;
struct regulator_config config = { };
int err;
info = &ab8500_regulator_info[id];
info->dev = &pdev->dev;
config.dev = &pdev->dev;
config.init_data = init_data;
config.driver_data = info;
config.of_node = np;
if (abx500_get_chip_id(info->dev) < 0x20) {
if (info->desc.id == AB8500_LDO_AUX3) {
info->desc.n_voltages =
ARRAY_SIZE(ldo_vauxn_voltages);
info->desc.volt_table = ldo_vauxn_voltages;
info->voltage_mask = 0xf;
}
}
info->regulator = regulator_register(&info->desc, &config);
if (IS_ERR(info->regulator)) {
err = PTR_ERR(info->regulator);
dev_err(&pdev->dev, "failed to register regulator %s\n",
info->desc.name);
while (--id >= 0) {
info = &ab8500_regulator_info[id];
regulator_unregister(info->regulator);
}
return err;
}
return 0;
}
static __devinit int
ab8500_regulator_of_probe(struct platform_device *pdev, struct device_node *np)
{
int err, i;
for (i = 0; i < ARRAY_SIZE(ab8500_regulator_info); i++) {
err = ab8500_regulator_register(
pdev, ab8500_regulator_matches[i].init_data,
i, ab8500_regulator_matches[i].of_node);
if (err)
return err;
}
return 0;
}
static __devinit int ab8500_regulator_probe(struct platform_device *pdev)
{
struct ab8500 *ab8500 = dev_get_drvdata(pdev->dev.parent);
struct ab8500_platform_data *pdata;
struct device_node *np = pdev->dev.of_node;
int i, err;
if (np) {
err = of_regulator_match(&pdev->dev, np,
ab8500_regulator_matches,
ARRAY_SIZE(ab8500_regulator_matches));
if (err < 0) {
dev_err(&pdev->dev,
"Error parsing regulator init data: %d\n", err);
return err;
}
err = ab8500_regulator_of_probe(pdev, np);
return err;
}
if (!ab8500) {
dev_err(&pdev->dev, "null mfd parent\n");
return -EINVAL;
}
pdata = dev_get_platdata(ab8500->dev);
if (!pdata) {
dev_err(&pdev->dev, "null pdata\n");
return -EINVAL;
}
if (pdata->num_regulator != ARRAY_SIZE(ab8500_regulator_info)) {
dev_err(&pdev->dev, "Configuration error: size mismatch.\n");
return -EINVAL;
}
for (i = 0; i < pdata->num_regulator_reg_init; i++) {
int id, value;
id = pdata->regulator_reg_init[i].id;
value = pdata->regulator_reg_init[i].value;
if (id >= AB8500_NUM_REGULATOR_REGISTERS) {
dev_err(&pdev->dev,
"Configuration error: id outside range.\n");
return -EINVAL;
}
err = ab8500_regulator_init_registers(pdev, id, value);
if (err < 0)
return err;
}
for (i = 0; i < ARRAY_SIZE(ab8500_regulator_info); i++) {
err = ab8500_regulator_register(pdev, &pdata->regulator[i], i, NULL);
if (err < 0)
return err;
}
return 0;
}
static __devexit int ab8500_regulator_remove(struct platform_device *pdev)
{
int i;
for (i = 0; i < ARRAY_SIZE(ab8500_regulator_info); i++) {
struct ab8500_regulator_info *info = NULL;
info = &ab8500_regulator_info[i];
dev_vdbg(rdev_get_dev(info->regulator),
"%s-remove\n", info->desc.name);
regulator_unregister(info->regulator);
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
