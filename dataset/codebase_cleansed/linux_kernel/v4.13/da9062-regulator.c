static int da9062_set_current_limit(struct regulator_dev *rdev,
int min_ua, int max_ua)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
const struct da9062_regulator_info *rinfo = regl->info;
int n, tval;
for (n = 0; n < rinfo->n_current_limits; n++) {
tval = rinfo->current_limits[n];
if (tval >= min_ua && tval <= max_ua)
return regmap_field_write(regl->ilimit, n);
}
return -EINVAL;
}
static int da9062_get_current_limit(struct regulator_dev *rdev)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
const struct da9062_regulator_info *rinfo = regl->info;
unsigned int sel;
int ret;
ret = regmap_field_read(regl->ilimit, &sel);
if (ret < 0)
return ret;
if (sel >= rinfo->n_current_limits)
sel = rinfo->n_current_limits - 1;
return rinfo->current_limits[sel];
}
static int da9062_buck_set_mode(struct regulator_dev *rdev, unsigned mode)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
unsigned val;
switch (mode) {
case REGULATOR_MODE_FAST:
val = BUCK_MODE_SYNC;
break;
case REGULATOR_MODE_NORMAL:
val = BUCK_MODE_AUTO;
break;
case REGULATOR_MODE_STANDBY:
val = BUCK_MODE_SLEEP;
break;
default:
return -EINVAL;
}
return regmap_field_write(regl->mode, val);
}
static unsigned da9062_buck_get_mode(struct regulator_dev *rdev)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
struct regmap_field *field;
unsigned int val, mode = 0;
int ret;
ret = regmap_field_read(regl->mode, &val);
if (ret < 0)
return ret;
switch (val) {
default:
case BUCK_MODE_MANUAL:
mode = REGULATOR_MODE_FAST | REGULATOR_MODE_STANDBY;
break;
case BUCK_MODE_SLEEP:
return REGULATOR_MODE_STANDBY;
case BUCK_MODE_SYNC:
return REGULATOR_MODE_FAST;
case BUCK_MODE_AUTO:
return REGULATOR_MODE_NORMAL;
}
ret = regmap_field_read(regl->suspend, &val);
if (ret < 0)
return 0;
if (val)
field = regl->suspend_sleep;
else
field = regl->sleep;
ret = regmap_field_read(field, &val);
if (ret < 0)
return 0;
if (val)
mode &= REGULATOR_MODE_STANDBY;
else
mode &= REGULATOR_MODE_NORMAL | REGULATOR_MODE_FAST;
return mode;
}
static int da9062_ldo_set_mode(struct regulator_dev *rdev, unsigned mode)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
unsigned val;
switch (mode) {
case REGULATOR_MODE_NORMAL:
val = 0;
break;
case REGULATOR_MODE_STANDBY:
val = 1;
break;
default:
return -EINVAL;
}
return regmap_field_write(regl->sleep, val);
}
static unsigned da9062_ldo_get_mode(struct regulator_dev *rdev)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
struct regmap_field *field;
int ret, val;
ret = regmap_field_read(regl->suspend, &val);
if (ret < 0)
return 0;
if (val)
field = regl->suspend_sleep;
else
field = regl->sleep;
ret = regmap_field_read(field, &val);
if (ret < 0)
return 0;
if (val)
return REGULATOR_MODE_STANDBY;
else
return REGULATOR_MODE_NORMAL;
}
static int da9062_buck_get_status(struct regulator_dev *rdev)
{
int ret = regulator_is_enabled_regmap(rdev);
if (ret == 0) {
ret = REGULATOR_STATUS_OFF;
} else if (ret > 0) {
ret = da9062_buck_get_mode(rdev);
if (ret > 0)
ret = regulator_mode_to_status(ret);
else if (ret == 0)
ret = -EIO;
}
return ret;
}
static int da9062_ldo_get_status(struct regulator_dev *rdev)
{
int ret = regulator_is_enabled_regmap(rdev);
if (ret == 0) {
ret = REGULATOR_STATUS_OFF;
} else if (ret > 0) {
ret = da9062_ldo_get_mode(rdev);
if (ret > 0)
ret = regulator_mode_to_status(ret);
else if (ret == 0)
ret = -EIO;
}
return ret;
}
static int da9062_set_suspend_voltage(struct regulator_dev *rdev, int uv)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
const struct da9062_regulator_info *rinfo = regl->info;
int ret, sel;
sel = regulator_map_voltage_linear(rdev, uv, uv);
if (sel < 0)
return sel;
sel <<= ffs(rdev->desc->vsel_mask) - 1;
ret = regmap_update_bits(regl->hw->regmap, rinfo->suspend_vsel_reg,
rdev->desc->vsel_mask, sel);
return ret;
}
static int da9062_suspend_enable(struct regulator_dev *rdev)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
return regmap_field_write(regl->suspend, 1);
}
static int da9062_suspend_disable(struct regulator_dev *rdev)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
return regmap_field_write(regl->suspend, 0);
}
static int da9062_buck_set_suspend_mode(struct regulator_dev *rdev,
unsigned mode)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
int val;
switch (mode) {
case REGULATOR_MODE_FAST:
val = BUCK_MODE_SYNC;
break;
case REGULATOR_MODE_NORMAL:
val = BUCK_MODE_AUTO;
break;
case REGULATOR_MODE_STANDBY:
val = BUCK_MODE_SLEEP;
break;
default:
return -EINVAL;
}
return regmap_field_write(regl->mode, val);
}
static int da9062_ldo_set_suspend_mode(struct regulator_dev *rdev,
unsigned mode)
{
struct da9062_regulator *regl = rdev_get_drvdata(rdev);
unsigned val;
switch (mode) {
case REGULATOR_MODE_NORMAL:
val = 0;
break;
case REGULATOR_MODE_STANDBY:
val = 1;
break;
default:
return -EINVAL;
}
return regmap_field_write(regl->suspend_sleep, val);
}
static irqreturn_t da9062_ldo_lim_event(int irq, void *data)
{
struct da9062_regulators *regulators = data;
struct da9062 *hw = regulators->regulator[0].hw;
struct da9062_regulator *regl;
int handled = IRQ_NONE;
int bits, i, ret;
ret = regmap_read(hw->regmap, DA9062AA_STATUS_D, &bits);
if (ret < 0) {
dev_err(hw->dev,
"Failed to read LDO overcurrent indicator\n");
goto ldo_lim_error;
}
for (i = regulators->n_regulators - 1; i >= 0; i--) {
regl = &regulators->regulator[i];
if (regl->info->oc_event.reg != DA9062AA_STATUS_D)
continue;
if (BIT(regl->info->oc_event.lsb) & bits) {
regulator_notifier_call_chain(regl->rdev,
REGULATOR_EVENT_OVER_CURRENT, NULL);
handled = IRQ_HANDLED;
}
}
ldo_lim_error:
return handled;
}
static int da9062_regulator_probe(struct platform_device *pdev)
{
struct da9062 *chip = dev_get_drvdata(pdev->dev.parent);
struct da9062_regulators *regulators;
struct da9062_regulator *regl;
struct regulator_config config = { };
const struct da9062_regulator_info *rinfo;
int irq, n, ret;
size_t size;
int max_regulators;
switch (chip->chip_type) {
case COMPAT_TYPE_DA9061:
max_regulators = DA9061_MAX_REGULATORS;
rinfo = local_da9061_regulator_info;
break;
case COMPAT_TYPE_DA9062:
max_regulators = DA9062_MAX_REGULATORS;
rinfo = local_da9062_regulator_info;
break;
default:
dev_err(chip->dev, "Unrecognised chip type\n");
return -ENODEV;
}
size = sizeof(struct da9062_regulators) +
max_regulators * sizeof(struct da9062_regulator);
regulators = devm_kzalloc(&pdev->dev, size, GFP_KERNEL);
if (!regulators)
return -ENOMEM;
regulators->n_regulators = max_regulators;
platform_set_drvdata(pdev, regulators);
n = 0;
while (n < regulators->n_regulators) {
regl = &regulators->regulator[n];
regl->hw = chip;
regl->info = &rinfo[n];
regl->desc = regl->info->desc;
regl->desc.type = REGULATOR_VOLTAGE;
regl->desc.owner = THIS_MODULE;
if (regl->info->mode.reg)
regl->mode = devm_regmap_field_alloc(
&pdev->dev,
chip->regmap,
regl->info->mode);
if (regl->info->suspend.reg)
regl->suspend = devm_regmap_field_alloc(
&pdev->dev,
chip->regmap,
regl->info->suspend);
if (regl->info->sleep.reg)
regl->sleep = devm_regmap_field_alloc(
&pdev->dev,
chip->regmap,
regl->info->sleep);
if (regl->info->suspend_sleep.reg)
regl->suspend_sleep = devm_regmap_field_alloc(
&pdev->dev,
chip->regmap,
regl->info->suspend_sleep);
if (regl->info->ilimit.reg)
regl->ilimit = devm_regmap_field_alloc(
&pdev->dev,
chip->regmap,
regl->info->ilimit);
memset(&config, 0, sizeof(config));
config.dev = chip->dev;
config.driver_data = regl;
config.regmap = chip->regmap;
regl->rdev = devm_regulator_register(&pdev->dev, &regl->desc,
&config);
if (IS_ERR(regl->rdev)) {
dev_err(&pdev->dev,
"Failed to register %s regulator\n",
regl->desc.name);
return PTR_ERR(regl->rdev);
}
n++;
}
irq = platform_get_irq_byname(pdev, "LDO_LIM");
if (irq < 0) {
dev_err(&pdev->dev, "Failed to get IRQ.\n");
return irq;
}
regulators->irq_ldo_lim = irq;
ret = devm_request_threaded_irq(&pdev->dev, irq,
NULL, da9062_ldo_lim_event,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
"LDO_LIM", regulators);
if (ret) {
dev_warn(&pdev->dev,
"Failed to request LDO_LIM IRQ.\n");
regulators->irq_ldo_lim = -ENXIO;
}
return 0;
}
static int __init da9062_regulator_init(void)
{
return platform_driver_register(&da9062_regulator_driver);
}
static void __exit da9062_regulator_cleanup(void)
{
platform_driver_unregister(&da9062_regulator_driver);
}
