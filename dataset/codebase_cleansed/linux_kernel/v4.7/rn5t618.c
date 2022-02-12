static bool rn5t618_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case RN5T618_WATCHDOGCNT:
case RN5T618_DCIRQ:
case RN5T618_ILIMDATAH ... RN5T618_AIN0DATAL:
case RN5T618_IR_ADC1 ... RN5T618_IR_ADC3:
case RN5T618_IR_GPR:
case RN5T618_IR_GPF:
case RN5T618_MON_IOIN:
case RN5T618_INTMON:
return true;
default:
return false;
}
}
static void rn5t618_power_off(void)
{
regmap_update_bits(rn5t618_pm_power_off->regmap, RN5T618_REPCNT,
RN5T618_REPCNT_REPWRON, 0);
regmap_update_bits(rn5t618_pm_power_off->regmap, RN5T618_SLPCNT,
RN5T618_SLPCNT_SWPWROFF, RN5T618_SLPCNT_SWPWROFF);
}
static int rn5t618_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct rn5t618 *priv;
int ret;
priv = devm_kzalloc(&i2c->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
i2c_set_clientdata(i2c, priv);
priv->regmap = devm_regmap_init_i2c(i2c, &rn5t618_regmap_config);
if (IS_ERR(priv->regmap)) {
ret = PTR_ERR(priv->regmap);
dev_err(&i2c->dev, "regmap init failed: %d\n", ret);
return ret;
}
ret = devm_mfd_add_devices(&i2c->dev, -1, rn5t618_cells,
ARRAY_SIZE(rn5t618_cells), NULL, 0, NULL);
if (ret) {
dev_err(&i2c->dev, "failed to add sub-devices: %d\n", ret);
return ret;
}
if (!pm_power_off) {
rn5t618_pm_power_off = priv;
pm_power_off = rn5t618_power_off;
}
return 0;
}
static int rn5t618_i2c_remove(struct i2c_client *i2c)
{
struct rn5t618 *priv = i2c_get_clientdata(i2c);
if (priv == rn5t618_pm_power_off) {
rn5t618_pm_power_off = NULL;
pm_power_off = NULL;
}
return 0;
}
