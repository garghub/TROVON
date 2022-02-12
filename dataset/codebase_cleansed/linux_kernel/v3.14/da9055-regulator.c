static unsigned int da9055_buck_get_mode(struct regulator_dev *rdev)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
int ret, mode = 0;
ret = da9055_reg_read(regulator->da9055, info->mode.reg);
if (ret < 0)
return ret;
switch ((ret & info->mode.mask) >> info->mode.shift) {
case DA9055_BUCK_MODE_SYNC:
mode = REGULATOR_MODE_FAST;
break;
case DA9055_BUCK_MODE_AUTO:
mode = REGULATOR_MODE_NORMAL;
break;
case DA9055_BUCK_MODE_SLEEP:
mode = REGULATOR_MODE_STANDBY;
break;
}
return mode;
}
static int da9055_buck_set_mode(struct regulator_dev *rdev,
unsigned int mode)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
int val = 0;
switch (mode) {
case REGULATOR_MODE_FAST:
val = DA9055_BUCK_MODE_SYNC << info->mode.shift;
break;
case REGULATOR_MODE_NORMAL:
val = DA9055_BUCK_MODE_AUTO << info->mode.shift;
break;
case REGULATOR_MODE_STANDBY:
val = DA9055_BUCK_MODE_SLEEP << info->mode.shift;
break;
}
return da9055_reg_update(regulator->da9055, info->mode.reg,
info->mode.mask, val);
}
static unsigned int da9055_ldo_get_mode(struct regulator_dev *rdev)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
int ret;
ret = da9055_reg_read(regulator->da9055, info->volt.reg_b);
if (ret < 0)
return ret;
if (ret >> info->volt.sl_shift)
return REGULATOR_MODE_STANDBY;
else
return REGULATOR_MODE_NORMAL;
}
static int da9055_ldo_set_mode(struct regulator_dev *rdev, unsigned int mode)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
struct da9055_volt_reg volt = info->volt;
int val = 0;
switch (mode) {
case REGULATOR_MODE_NORMAL:
case REGULATOR_MODE_FAST:
val = DA9055_LDO_MODE_SYNC;
break;
case REGULATOR_MODE_STANDBY:
val = DA9055_LDO_MODE_SLEEP;
break;
}
return da9055_reg_update(regulator->da9055, volt.reg_b,
1 << volt.sl_shift,
val << volt.sl_shift);
}
static int da9055_buck_get_current_limit(struct regulator_dev *rdev)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
int ret;
ret = da9055_reg_read(regulator->da9055, DA9055_REG_BUCK_LIM);
if (ret < 0)
return ret;
ret &= info->mode.mask;
return da9055_current_limits[ret >> info->mode.shift];
}
static int da9055_buck_set_current_limit(struct regulator_dev *rdev, int min_uA,
int max_uA)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
int i;
for (i = ARRAY_SIZE(da9055_current_limits) - 1; i >= 0; i--) {
if ((min_uA <= da9055_current_limits[i]) &&
(da9055_current_limits[i] <= max_uA))
return da9055_reg_update(regulator->da9055,
DA9055_REG_BUCK_LIM,
info->mode.mask,
i << info->mode.shift);
}
return -EINVAL;
}
static int da9055_regulator_get_voltage_sel(struct regulator_dev *rdev)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
struct da9055_volt_reg volt = info->volt;
int ret, sel;
ret = da9055_reg_read(regulator->da9055, info->conf.reg);
if (ret < 0)
return ret;
ret &= info->conf.sel_mask;
if (ret == DA9055_REGUALTOR_SET_A)
ret = da9055_reg_read(regulator->da9055, volt.reg_a);
else
ret = da9055_reg_read(regulator->da9055, volt.reg_b);
if (ret < 0)
return ret;
sel = (ret & volt.v_mask);
return sel;
}
static int da9055_regulator_set_voltage_sel(struct regulator_dev *rdev,
unsigned int selector)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
int ret;
if (regulator->reg_rselect == NO_GPIO) {
ret = da9055_reg_update(regulator->da9055, info->conf.reg,
info->conf.sel_mask, DA9055_SEL_REG_A);
if (ret < 0)
return ret;
return da9055_reg_update(regulator->da9055, info->volt.reg_a,
info->volt.v_mask, selector);
}
ret = da9055_reg_read(regulator->da9055, info->conf.reg);
if (ret < 0)
return ret;
ret &= info->conf.sel_mask;
if (ret == DA9055_REGUALTOR_SET_A)
return da9055_reg_update(regulator->da9055, info->volt.reg_a,
info->volt.v_mask, selector);
else
return da9055_reg_update(regulator->da9055, info->volt.reg_b,
info->volt.v_mask, selector);
}
static int da9055_regulator_set_suspend_voltage(struct regulator_dev *rdev,
int uV)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
int ret;
if (regulator->reg_rselect == NO_GPIO) {
ret = da9055_reg_update(regulator->da9055, info->conf.reg,
info->conf.sel_mask, DA9055_SEL_REG_B);
if (ret < 0)
return ret;
}
ret = regulator_map_voltage_linear(rdev, uV, uV);
if (ret < 0)
return ret;
return da9055_reg_update(regulator->da9055, info->volt.reg_b,
info->volt.v_mask, ret);
}
static int da9055_suspend_enable(struct regulator_dev *rdev)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
if (regulator->reg_rselect == NO_GPIO)
return da9055_reg_update(regulator->da9055, info->conf.reg,
info->conf.sel_mask, DA9055_SEL_REG_B);
else
return 0;
}
static int da9055_suspend_disable(struct regulator_dev *rdev)
{
struct da9055_regulator *regulator = rdev_get_drvdata(rdev);
struct da9055_regulator_info *info = regulator->info;
if (regulator->reg_rselect == NO_GPIO)
return da9055_reg_update(regulator->da9055, info->conf.reg,
info->conf.sel_mask, DA9055_SEL_REG_A);
else
return 0;
}
static int da9055_gpio_init(struct da9055_regulator *regulator,
struct regulator_config *config,
struct da9055_pdata *pdata, int id)
{
struct da9055_regulator_info *info = regulator->info;
int ret = 0;
if (pdata->gpio_ren && pdata->gpio_ren[id]) {
char name[18];
int gpio_mux = pdata->gpio_ren[id];
config->ena_gpio = pdata->ena_gpio[id];
config->ena_gpio_flags = GPIOF_OUT_INIT_HIGH;
config->ena_gpio_invert = 1;
sprintf(name, "DA9055 GPI %d", gpio_mux);
ret = devm_gpio_request_one(config->dev, gpio_mux, GPIOF_DIR_IN,
name);
if (ret < 0)
goto err;
ret = da9055_reg_update(regulator->da9055, info->conf.reg,
DA9055_E_GPI_MASK,
pdata->reg_ren[id]
<< DA9055_E_GPI_SHIFT);
if (ret < 0)
goto err;
}
if (pdata->gpio_rsel && pdata->gpio_rsel[id]) {
char name[18];
int gpio_mux = pdata->gpio_rsel[id];
regulator->reg_rselect = pdata->reg_rsel[id];
sprintf(name, "DA9055 GPI %d", gpio_mux);
ret = devm_gpio_request_one(config->dev, gpio_mux, GPIOF_DIR_IN,
name);
if (ret < 0)
goto err;
ret = da9055_reg_update(regulator->da9055, info->conf.reg,
DA9055_V_GPI_MASK,
pdata->reg_rsel[id]
<< DA9055_V_GPI_SHIFT);
}
err:
return ret;
}
static irqreturn_t da9055_ldo5_6_oc_irq(int irq, void *data)
{
struct da9055_regulator *regulator = data;
regulator_notifier_call_chain(regulator->rdev,
REGULATOR_EVENT_OVER_CURRENT, NULL);
return IRQ_HANDLED;
}
static inline struct da9055_regulator_info *find_regulator_info(int id)
{
struct da9055_regulator_info *info;
int i;
for (i = 0; i < ARRAY_SIZE(da9055_regulator_info); i++) {
info = &da9055_regulator_info[i];
if (info->reg_desc.id == id)
return info;
}
return NULL;
}
static int da9055_regulator_probe(struct platform_device *pdev)
{
struct regulator_config config = { };
struct da9055_regulator *regulator;
struct da9055 *da9055 = dev_get_drvdata(pdev->dev.parent);
struct da9055_pdata *pdata = dev_get_platdata(da9055->dev);
int ret, irq;
if (pdata == NULL || pdata->regulators[pdev->id] == NULL)
return -ENODEV;
regulator = devm_kzalloc(&pdev->dev, sizeof(struct da9055_regulator),
GFP_KERNEL);
if (!regulator)
return -ENOMEM;
regulator->info = find_regulator_info(pdev->id);
if (regulator->info == NULL) {
dev_err(&pdev->dev, "invalid regulator ID specified\n");
return -EINVAL;
}
regulator->da9055 = da9055;
config.dev = &pdev->dev;
config.driver_data = regulator;
config.regmap = da9055->regmap;
if (pdata && pdata->regulators)
config.init_data = pdata->regulators[pdev->id];
ret = da9055_gpio_init(regulator, &config, pdata, pdev->id);
if (ret < 0)
return ret;
regulator->rdev = devm_regulator_register(&pdev->dev,
&regulator->info->reg_desc,
&config);
if (IS_ERR(regulator->rdev)) {
dev_err(&pdev->dev, "Failed to register regulator %s\n",
regulator->info->reg_desc.name);
return PTR_ERR(regulator->rdev);
}
if (pdev->id == DA9055_ID_LDO5 || pdev->id == DA9055_ID_LDO6) {
irq = platform_get_irq_byname(pdev, "REGULATOR");
if (irq < 0)
return irq;
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
da9055_ldo5_6_oc_irq,
IRQF_TRIGGER_HIGH |
IRQF_ONESHOT |
IRQF_PROBE_SHARED,
pdev->name, regulator);
if (ret != 0) {
if (ret != -EBUSY) {
dev_err(&pdev->dev,
"Failed to request Regulator IRQ %d: %d\n",
irq, ret);
return ret;
}
}
}
platform_set_drvdata(pdev, regulator);
return 0;
}
static int __init da9055_regulator_init(void)
{
return platform_driver_register(&da9055_regulator_driver);
}
static void __exit da9055_regulator_exit(void)
{
platform_driver_unregister(&da9055_regulator_driver);
}
