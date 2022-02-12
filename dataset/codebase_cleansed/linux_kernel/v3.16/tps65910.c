static int tps65910_irq_init(struct tps65910 *tps65910, int irq,
struct tps65910_platform_data *pdata)
{
int ret = 0;
static struct regmap_irq_chip *tps6591x_irqs_chip;
if (!irq) {
dev_warn(tps65910->dev, "No interrupt support, no core IRQ\n");
return -EINVAL;
}
if (!pdata) {
dev_warn(tps65910->dev, "No interrupt support, no pdata\n");
return -EINVAL;
}
switch (tps65910_chip_id(tps65910)) {
case TPS65910:
tps6591x_irqs_chip = &tps65910_irq_chip;
break;
case TPS65911:
tps6591x_irqs_chip = &tps65911_irq_chip;
break;
}
tps65910->chip_irq = irq;
ret = regmap_add_irq_chip(tps65910->regmap, tps65910->chip_irq,
IRQF_ONESHOT, pdata->irq_base,
tps6591x_irqs_chip, &tps65910->irq_data);
if (ret < 0) {
dev_warn(tps65910->dev, "Failed to add irq_chip %d\n", ret);
tps65910->chip_irq = 0;
}
return ret;
}
static int tps65910_irq_exit(struct tps65910 *tps65910)
{
if (tps65910->chip_irq > 0)
regmap_del_irq_chip(tps65910->chip_irq, tps65910->irq_data);
return 0;
}
static bool is_volatile_reg(struct device *dev, unsigned int reg)
{
struct tps65910 *tps65910 = dev_get_drvdata(dev);
if ((reg >= TPS65910_VIO) && (reg <= TPS65910_VDAC)) {
if (tps65910_chip_id(tps65910) == TPS65910)
if ((reg == TPS65911_VDDCTRL_OP) ||
(reg == TPS65911_VDDCTRL_SR))
return true;
return false;
}
return true;
}
static int tps65910_ck32k_init(struct tps65910 *tps65910,
struct tps65910_board *pmic_pdata)
{
int ret;
if (!pmic_pdata->en_ck32k_xtal)
return 0;
ret = tps65910_reg_clear_bits(tps65910, TPS65910_DEVCTRL,
DEVCTRL_CK32K_CTRL_MASK);
if (ret < 0) {
dev_err(tps65910->dev, "clear ck32k_ctrl failed: %d\n", ret);
return ret;
}
return 0;
}
static int tps65910_sleepinit(struct tps65910 *tps65910,
struct tps65910_board *pmic_pdata)
{
struct device *dev = NULL;
int ret = 0;
dev = tps65910->dev;
if (!pmic_pdata->en_dev_slp)
return 0;
ret = tps65910_reg_set_bits(tps65910, TPS65910_DEVCTRL,
DEVCTRL_DEV_SLP_MASK);
if (ret < 0) {
dev_err(dev, "set dev_slp failed: %d\n", ret);
goto err_sleep_init;
}
if (!pmic_pdata->slp_keepon)
return 0;
if (pmic_pdata->slp_keepon->therm_keepon) {
ret = tps65910_reg_set_bits(tps65910,
TPS65910_SLEEP_KEEP_RES_ON,
SLEEP_KEEP_RES_ON_THERM_KEEPON_MASK);
if (ret < 0) {
dev_err(dev, "set therm_keepon failed: %d\n", ret);
goto disable_dev_slp;
}
}
if (pmic_pdata->slp_keepon->clkout32k_keepon) {
ret = tps65910_reg_set_bits(tps65910,
TPS65910_SLEEP_KEEP_RES_ON,
SLEEP_KEEP_RES_ON_CLKOUT32K_KEEPON_MASK);
if (ret < 0) {
dev_err(dev, "set clkout32k_keepon failed: %d\n", ret);
goto disable_dev_slp;
}
}
if (pmic_pdata->slp_keepon->i2chs_keepon) {
ret = tps65910_reg_set_bits(tps65910,
TPS65910_SLEEP_KEEP_RES_ON,
SLEEP_KEEP_RES_ON_I2CHS_KEEPON_MASK);
if (ret < 0) {
dev_err(dev, "set i2chs_keepon failed: %d\n", ret);
goto disable_dev_slp;
}
}
return 0;
disable_dev_slp:
tps65910_reg_clear_bits(tps65910, TPS65910_DEVCTRL,
DEVCTRL_DEV_SLP_MASK);
err_sleep_init:
return ret;
}
static struct tps65910_board *tps65910_parse_dt(struct i2c_client *client,
int *chip_id)
{
struct device_node *np = client->dev.of_node;
struct tps65910_board *board_info;
unsigned int prop;
const struct of_device_id *match;
int ret = 0;
match = of_match_device(tps65910_of_match, &client->dev);
if (!match) {
dev_err(&client->dev, "Failed to find matching dt id\n");
return NULL;
}
*chip_id = (int)match->data;
board_info = devm_kzalloc(&client->dev, sizeof(*board_info),
GFP_KERNEL);
if (!board_info) {
dev_err(&client->dev, "Failed to allocate pdata\n");
return NULL;
}
ret = of_property_read_u32(np, "ti,vmbch-threshold", &prop);
if (!ret)
board_info->vmbch_threshold = prop;
ret = of_property_read_u32(np, "ti,vmbch2-threshold", &prop);
if (!ret)
board_info->vmbch2_threshold = prop;
prop = of_property_read_bool(np, "ti,en-ck32k-xtal");
board_info->en_ck32k_xtal = prop;
board_info->irq = client->irq;
board_info->irq_base = -1;
board_info->pm_off = of_property_read_bool(np,
"ti,system-power-controller");
return board_info;
}
static inline
struct tps65910_board *tps65910_parse_dt(struct i2c_client *client,
int *chip_id)
{
return NULL;
}
static void tps65910_power_off(void)
{
struct tps65910 *tps65910;
tps65910 = dev_get_drvdata(&tps65910_i2c_client->dev);
if (tps65910_reg_set_bits(tps65910, TPS65910_DEVCTRL,
DEVCTRL_PWR_OFF_MASK) < 0)
return;
tps65910_reg_clear_bits(tps65910, TPS65910_DEVCTRL,
DEVCTRL_DEV_ON_MASK);
}
static int tps65910_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct tps65910 *tps65910;
struct tps65910_board *pmic_plat_data;
struct tps65910_board *of_pmic_plat_data = NULL;
struct tps65910_platform_data *init_data;
int ret = 0;
int chip_id = id->driver_data;
pmic_plat_data = dev_get_platdata(&i2c->dev);
if (!pmic_plat_data && i2c->dev.of_node) {
pmic_plat_data = tps65910_parse_dt(i2c, &chip_id);
of_pmic_plat_data = pmic_plat_data;
}
if (!pmic_plat_data)
return -EINVAL;
init_data = devm_kzalloc(&i2c->dev, sizeof(*init_data), GFP_KERNEL);
if (init_data == NULL)
return -ENOMEM;
tps65910 = devm_kzalloc(&i2c->dev, sizeof(*tps65910), GFP_KERNEL);
if (tps65910 == NULL)
return -ENOMEM;
tps65910->of_plat_data = of_pmic_plat_data;
i2c_set_clientdata(i2c, tps65910);
tps65910->dev = &i2c->dev;
tps65910->i2c_client = i2c;
tps65910->id = chip_id;
tps65910->regmap = devm_regmap_init_i2c(i2c, &tps65910_regmap_config);
if (IS_ERR(tps65910->regmap)) {
ret = PTR_ERR(tps65910->regmap);
dev_err(&i2c->dev, "regmap initialization failed: %d\n", ret);
return ret;
}
init_data->irq = pmic_plat_data->irq;
init_data->irq_base = pmic_plat_data->irq_base;
tps65910_irq_init(tps65910, init_data->irq, init_data);
tps65910_ck32k_init(tps65910, pmic_plat_data);
tps65910_sleepinit(tps65910, pmic_plat_data);
if (pmic_plat_data->pm_off && !pm_power_off) {
tps65910_i2c_client = i2c;
pm_power_off = tps65910_power_off;
}
ret = mfd_add_devices(tps65910->dev, -1,
tps65910s, ARRAY_SIZE(tps65910s),
NULL, 0,
regmap_irq_get_domain(tps65910->irq_data));
if (ret < 0) {
dev_err(&i2c->dev, "mfd_add_devices failed: %d\n", ret);
tps65910_irq_exit(tps65910);
return ret;
}
return ret;
}
static int tps65910_i2c_remove(struct i2c_client *i2c)
{
struct tps65910 *tps65910 = i2c_get_clientdata(i2c);
tps65910_irq_exit(tps65910);
mfd_remove_devices(tps65910->dev);
return 0;
}
static int __init tps65910_i2c_init(void)
{
return i2c_add_driver(&tps65910_i2c_driver);
}
static void __exit tps65910_i2c_exit(void)
{
i2c_del_driver(&tps65910_i2c_driver);
}
