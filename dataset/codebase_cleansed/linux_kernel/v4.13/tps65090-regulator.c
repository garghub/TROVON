static int tps65090_reg_set_overcurrent_wait(struct tps65090_regulator *ri,
struct regulator_dev *rdev)
{
int ret;
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
MAX_OVERCURRENT_WAIT << CTRL_WT_BIT,
ri->overcurrent_wait << CTRL_WT_BIT);
if (ret) {
dev_err(&rdev->dev, "Error updating overcurrent wait %#x\n",
rdev->desc->enable_reg);
}
return ret;
}
static int tps65090_try_enable_fet(struct regulator_dev *rdev)
{
unsigned int control;
int ret, i;
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask,
rdev->desc->enable_mask);
if (ret < 0) {
dev_err(&rdev->dev, "Error in updating reg %#x\n",
rdev->desc->enable_reg);
return ret;
}
for (i = 0; i < MAX_CTRL_READ_TRIES; i++) {
ret = regmap_read(rdev->regmap, rdev->desc->enable_reg,
&control);
if (ret < 0)
return ret;
if (!(control & BIT(CTRL_TO_BIT)))
break;
usleep_range(1000, 1500);
}
if (!(control & BIT(CTRL_PG_BIT)))
return -ENOTRECOVERABLE;
return 0;
}
static int tps65090_fet_enable(struct regulator_dev *rdev)
{
int ret, tries;
tries = 0;
while (true) {
ret = tps65090_try_enable_fet(rdev);
if (!ret)
break;
if (ret != -ENOTRECOVERABLE || tries == MAX_FET_ENABLE_TRIES)
goto err;
ret = regmap_update_bits(rdev->regmap, rdev->desc->enable_reg,
rdev->desc->enable_mask, 0);
if (ret)
goto err;
tries++;
}
if (tries)
dev_warn(&rdev->dev, "reg %#x enable ok after %d tries\n",
rdev->desc->enable_reg, tries);
return 0;
err:
dev_warn(&rdev->dev, "reg %#x enable failed\n", rdev->desc->enable_reg);
WARN_ON(1);
return ret;
}
static inline bool is_dcdc(int id)
{
switch (id) {
case TPS65090_REGULATOR_DCDC1:
case TPS65090_REGULATOR_DCDC2:
case TPS65090_REGULATOR_DCDC3:
return true;
default:
return false;
}
}
static int tps65090_config_ext_control(
struct tps65090_regulator *ri, bool enable)
{
int ret;
struct device *parent = ri->dev->parent;
unsigned int reg_en_reg = ri->desc->enable_reg;
if (enable)
ret = tps65090_set_bits(parent, reg_en_reg, 1);
else
ret = tps65090_clr_bits(parent, reg_en_reg, 1);
if (ret < 0)
dev_err(ri->dev, "Error in updating reg 0x%x\n", reg_en_reg);
return ret;
}
static int tps65090_regulator_disable_ext_control(
struct tps65090_regulator *ri,
struct tps65090_regulator_plat_data *tps_pdata)
{
int ret = 0;
struct device *parent = ri->dev->parent;
unsigned int reg_en_reg = ri->desc->enable_reg;
if (tps_pdata->reg_init_data->constraints.always_on ||
tps_pdata->reg_init_data->constraints.boot_on) {
ret = tps65090_set_bits(parent, reg_en_reg, 0);
if (ret < 0) {
dev_err(ri->dev, "Error in set reg 0x%x\n", reg_en_reg);
return ret;
}
}
return tps65090_config_ext_control(ri, false);
}
static void tps65090_configure_regulator_config(
struct tps65090_regulator_plat_data *tps_pdata,
struct regulator_config *config)
{
if (gpio_is_valid(tps_pdata->gpio)) {
int gpio_flag = GPIOF_OUT_INIT_LOW;
if (tps_pdata->reg_init_data->constraints.always_on ||
tps_pdata->reg_init_data->constraints.boot_on)
gpio_flag = GPIOF_OUT_INIT_HIGH;
config->ena_gpio = tps_pdata->gpio;
config->ena_gpio_initialized = true;
config->ena_gpio_flags = gpio_flag;
} else {
config->ena_gpio = -EINVAL;
config->ena_gpio_initialized = false;
}
}
static struct tps65090_platform_data *tps65090_parse_dt_reg_data(
struct platform_device *pdev,
struct of_regulator_match **tps65090_reg_matches)
{
struct tps65090_platform_data *tps65090_pdata;
struct device_node *np = pdev->dev.parent->of_node;
struct device_node *regulators;
int idx = 0, ret;
struct tps65090_regulator_plat_data *reg_pdata;
tps65090_pdata = devm_kzalloc(&pdev->dev, sizeof(*tps65090_pdata),
GFP_KERNEL);
if (!tps65090_pdata)
return ERR_PTR(-ENOMEM);
reg_pdata = devm_kzalloc(&pdev->dev, TPS65090_REGULATOR_MAX *
sizeof(*reg_pdata), GFP_KERNEL);
if (!reg_pdata)
return ERR_PTR(-ENOMEM);
regulators = of_get_child_by_name(np, "regulators");
if (!regulators) {
dev_err(&pdev->dev, "regulator node not found\n");
return ERR_PTR(-ENODEV);
}
ret = of_regulator_match(&pdev->dev, regulators, tps65090_matches,
ARRAY_SIZE(tps65090_matches));
of_node_put(regulators);
if (ret < 0) {
dev_err(&pdev->dev,
"Error parsing regulator init data: %d\n", ret);
return ERR_PTR(ret);
}
*tps65090_reg_matches = tps65090_matches;
for (idx = 0; idx < ARRAY_SIZE(tps65090_matches); idx++) {
struct regulator_init_data *ri_data;
struct tps65090_regulator_plat_data *rpdata;
rpdata = &reg_pdata[idx];
ri_data = tps65090_matches[idx].init_data;
if (!ri_data || !tps65090_matches[idx].of_node)
continue;
rpdata->reg_init_data = ri_data;
rpdata->enable_ext_control = of_property_read_bool(
tps65090_matches[idx].of_node,
"ti,enable-ext-control");
if (rpdata->enable_ext_control)
rpdata->gpio = of_get_named_gpio(np,
"dcdc-ext-control-gpios", 0);
if (of_property_read_u32(tps65090_matches[idx].of_node,
"ti,overcurrent-wait",
&rpdata->overcurrent_wait) == 0)
rpdata->overcurrent_wait_valid = true;
tps65090_pdata->reg_pdata[idx] = rpdata;
}
return tps65090_pdata;
}
static inline struct tps65090_platform_data *tps65090_parse_dt_reg_data(
struct platform_device *pdev,
struct of_regulator_match **tps65090_reg_matches)
{
*tps65090_reg_matches = NULL;
return NULL;
}
static int tps65090_regulator_probe(struct platform_device *pdev)
{
struct tps65090 *tps65090_mfd = dev_get_drvdata(pdev->dev.parent);
struct tps65090_regulator *ri = NULL;
struct regulator_config config = { };
struct regulator_dev *rdev;
struct tps65090_regulator_plat_data *tps_pdata;
struct tps65090_regulator *pmic;
struct tps65090_platform_data *tps65090_pdata;
struct of_regulator_match *tps65090_reg_matches = NULL;
int num;
int ret;
dev_dbg(&pdev->dev, "Probing regulator\n");
tps65090_pdata = dev_get_platdata(pdev->dev.parent);
if (!tps65090_pdata && tps65090_mfd->dev->of_node)
tps65090_pdata = tps65090_parse_dt_reg_data(pdev,
&tps65090_reg_matches);
if (IS_ERR_OR_NULL(tps65090_pdata)) {
dev_err(&pdev->dev, "Platform data missing\n");
return tps65090_pdata ? PTR_ERR(tps65090_pdata) : -EINVAL;
}
pmic = devm_kzalloc(&pdev->dev, TPS65090_REGULATOR_MAX * sizeof(*pmic),
GFP_KERNEL);
if (!pmic)
return -ENOMEM;
for (num = 0; num < TPS65090_REGULATOR_MAX; num++) {
tps_pdata = tps65090_pdata->reg_pdata[num];
ri = &pmic[num];
ri->dev = &pdev->dev;
ri->desc = &tps65090_regulator_desc[num];
if (tps_pdata) {
ri->overcurrent_wait_valid =
tps_pdata->overcurrent_wait_valid;
ri->overcurrent_wait = tps_pdata->overcurrent_wait;
}
if (tps_pdata && is_dcdc(num) && tps_pdata->reg_init_data) {
if (tps_pdata->enable_ext_control) {
tps65090_configure_regulator_config(
tps_pdata, &config);
ri->desc->ops = &tps65090_ext_control_ops;
} else {
ret = tps65090_regulator_disable_ext_control(
ri, tps_pdata);
if (ret < 0) {
dev_err(&pdev->dev,
"failed disable ext control\n");
return ret;
}
}
}
config.dev = pdev->dev.parent;
config.driver_data = ri;
config.regmap = tps65090_mfd->rmap;
if (tps_pdata)
config.init_data = tps_pdata->reg_init_data;
else
config.init_data = NULL;
if (tps65090_reg_matches)
config.of_node = tps65090_reg_matches[num].of_node;
else
config.of_node = NULL;
rdev = devm_regulator_register(&pdev->dev, ri->desc, &config);
if (IS_ERR(rdev)) {
dev_err(&pdev->dev, "failed to register regulator %s\n",
ri->desc->name);
return PTR_ERR(rdev);
}
ri->rdev = rdev;
if (ri->overcurrent_wait_valid) {
ret = tps65090_reg_set_overcurrent_wait(ri, rdev);
if (ret < 0)
return ret;
}
if (tps_pdata && is_dcdc(num) && tps_pdata->reg_init_data &&
tps_pdata->enable_ext_control) {
ret = tps65090_config_ext_control(ri, true);
if (ret < 0)
return ret;
}
}
platform_set_drvdata(pdev, pmic);
return 0;
}
static int __init tps65090_regulator_init(void)
{
return platform_driver_register(&tps65090_regulator_driver);
}
static void __exit tps65090_regulator_exit(void)
{
platform_driver_unregister(&tps65090_regulator_driver);
}
