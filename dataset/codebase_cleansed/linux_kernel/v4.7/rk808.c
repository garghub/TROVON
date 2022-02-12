static bool rk808_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case RK808_SECONDS_REG ... RK808_WEEKS_REG:
case RK808_RTC_STATUS_REG:
case RK808_VB_MON_REG:
case RK808_THERMAL_REG:
case RK808_DCDC_UV_STS_REG:
case RK808_LDO_UV_STS_REG:
case RK808_DCDC_PG_REG:
case RK808_LDO_PG_REG:
case RK808_DEVCTRL_REG:
case RK808_INT_STS_REG1:
case RK808_INT_STS_REG2:
return true;
}
return false;
}
static void rk808_device_shutdown(void)
{
int ret;
struct rk808 *rk808 = i2c_get_clientdata(rk808_i2c_client);
if (!rk808) {
dev_warn(&rk808_i2c_client->dev,
"have no rk808, so do nothing here\n");
return;
}
ret = regmap_update_bits(rk808->regmap,
RK808_DEVCTRL_REG,
DEV_OFF_RST, DEV_OFF_RST);
if (ret)
dev_err(&rk808_i2c_client->dev, "power off error!\n");
}
static int rk808_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *np = client->dev.of_node;
struct rk808 *rk808;
int pm_off = 0;
int ret;
int i;
if (!client->irq) {
dev_err(&client->dev, "No interrupt support, no core IRQ\n");
return -EINVAL;
}
rk808 = devm_kzalloc(&client->dev, sizeof(*rk808), GFP_KERNEL);
if (!rk808)
return -ENOMEM;
rk808->regmap = devm_regmap_init_i2c(client, &rk808_regmap_config);
if (IS_ERR(rk808->regmap)) {
dev_err(&client->dev, "regmap initialization failed\n");
return PTR_ERR(rk808->regmap);
}
for (i = 0; i < ARRAY_SIZE(pre_init_reg); i++) {
ret = regmap_update_bits(rk808->regmap, pre_init_reg[i].addr,
pre_init_reg[i].mask,
pre_init_reg[i].value);
if (ret) {
dev_err(&client->dev,
"0x%x write err\n", pre_init_reg[i].addr);
return ret;
}
}
ret = regmap_add_irq_chip(rk808->regmap, client->irq,
IRQF_ONESHOT, -1,
&rk808_irq_chip, &rk808->irq_data);
if (ret) {
dev_err(&client->dev, "Failed to add irq_chip %d\n", ret);
return ret;
}
rk808->i2c = client;
i2c_set_clientdata(client, rk808);
ret = devm_mfd_add_devices(&client->dev, -1,
rk808s, ARRAY_SIZE(rk808s), NULL, 0,
regmap_irq_get_domain(rk808->irq_data));
if (ret) {
dev_err(&client->dev, "failed to add MFD devices %d\n", ret);
goto err_irq;
}
pm_off = of_property_read_bool(np,
"rockchip,system-power-controller");
if (pm_off && !pm_power_off) {
rk808_i2c_client = client;
pm_power_off = rk808_device_shutdown;
}
return 0;
err_irq:
regmap_del_irq_chip(client->irq, rk808->irq_data);
return ret;
}
static int rk808_remove(struct i2c_client *client)
{
struct rk808 *rk808 = i2c_get_clientdata(client);
regmap_del_irq_chip(client->irq, rk808->irq_data);
pm_power_off = NULL;
return 0;
}
