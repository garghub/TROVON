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
static void rk805_device_shutdown(void)
{
int ret;
struct rk808 *rk808 = i2c_get_clientdata(rk808_i2c_client);
if (!rk808) {
dev_warn(&rk808_i2c_client->dev,
"have no rk805, so do nothing here\n");
return;
}
ret = regmap_update_bits(rk808->regmap,
RK805_DEV_CTRL_REG,
DEV_OFF, DEV_OFF);
if (ret)
dev_err(&rk808_i2c_client->dev, "power off error!\n");
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
static void rk818_device_shutdown(void)
{
int ret;
struct rk808 *rk808 = i2c_get_clientdata(rk808_i2c_client);
if (!rk808) {
dev_warn(&rk808_i2c_client->dev,
"have no rk818, so do nothing here\n");
return;
}
ret = regmap_update_bits(rk808->regmap,
RK818_DEVCTRL_REG,
DEV_OFF, DEV_OFF);
if (ret)
dev_err(&rk808_i2c_client->dev, "power off error!\n");
}
static int rk808_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device_node *np = client->dev.of_node;
struct rk808 *rk808;
const struct rk808_reg_data *pre_init_reg;
const struct mfd_cell *cells;
void (*pm_pwroff_fn)(void);
int nr_pre_init_regs;
int nr_cells;
int pm_off = 0, msb, lsb;
int ret;
int i;
rk808 = devm_kzalloc(&client->dev, sizeof(*rk808), GFP_KERNEL);
if (!rk808)
return -ENOMEM;
msb = i2c_smbus_read_byte_data(client, RK808_ID_MSB);
if (msb < 0) {
dev_err(&client->dev, "failed to read the chip id at 0x%x\n",
RK808_ID_MSB);
return msb;
}
lsb = i2c_smbus_read_byte_data(client, RK808_ID_LSB);
if (lsb < 0) {
dev_err(&client->dev, "failed to read the chip id at 0x%x\n",
RK808_ID_LSB);
return lsb;
}
rk808->variant = ((msb << 8) | lsb) & RK8XX_ID_MSK;
dev_info(&client->dev, "chip id: 0x%x\n", (unsigned int)rk808->variant);
switch (rk808->variant) {
case RK805_ID:
rk808->regmap_cfg = &rk805_regmap_config;
rk808->regmap_irq_chip = &rk805_irq_chip;
pre_init_reg = rk805_pre_init_reg;
nr_pre_init_regs = ARRAY_SIZE(rk805_pre_init_reg);
cells = rk805s;
nr_cells = ARRAY_SIZE(rk805s);
pm_pwroff_fn = rk805_device_shutdown;
break;
case RK808_ID:
rk808->regmap_cfg = &rk808_regmap_config;
rk808->regmap_irq_chip = &rk808_irq_chip;
pre_init_reg = rk808_pre_init_reg;
nr_pre_init_regs = ARRAY_SIZE(rk808_pre_init_reg);
cells = rk808s;
nr_cells = ARRAY_SIZE(rk808s);
pm_pwroff_fn = rk808_device_shutdown;
break;
case RK818_ID:
rk808->regmap_cfg = &rk818_regmap_config;
rk808->regmap_irq_chip = &rk818_irq_chip;
pre_init_reg = rk818_pre_init_reg;
nr_pre_init_regs = ARRAY_SIZE(rk818_pre_init_reg);
cells = rk818s;
nr_cells = ARRAY_SIZE(rk818s);
pm_pwroff_fn = rk818_device_shutdown;
break;
default:
dev_err(&client->dev, "Unsupported RK8XX ID %lu\n",
rk808->variant);
return -EINVAL;
}
rk808->i2c = client;
i2c_set_clientdata(client, rk808);
rk808->regmap = devm_regmap_init_i2c(client, rk808->regmap_cfg);
if (IS_ERR(rk808->regmap)) {
dev_err(&client->dev, "regmap initialization failed\n");
return PTR_ERR(rk808->regmap);
}
if (!client->irq) {
dev_err(&client->dev, "No interrupt support, no core IRQ\n");
return -EINVAL;
}
ret = regmap_add_irq_chip(rk808->regmap, client->irq,
IRQF_ONESHOT, -1,
rk808->regmap_irq_chip, &rk808->irq_data);
if (ret) {
dev_err(&client->dev, "Failed to add irq_chip %d\n", ret);
return ret;
}
for (i = 0; i < nr_pre_init_regs; i++) {
ret = regmap_update_bits(rk808->regmap,
pre_init_reg[i].addr,
pre_init_reg[i].mask,
pre_init_reg[i].value);
if (ret) {
dev_err(&client->dev,
"0x%x write err\n",
pre_init_reg[i].addr);
return ret;
}
}
ret = devm_mfd_add_devices(&client->dev, PLATFORM_DEVID_NONE,
cells, nr_cells, NULL, 0,
regmap_irq_get_domain(rk808->irq_data));
if (ret) {
dev_err(&client->dev, "failed to add MFD devices %d\n", ret);
goto err_irq;
}
pm_off = of_property_read_bool(np,
"rockchip,system-power-controller");
if (pm_off && !pm_power_off) {
rk808_i2c_client = client;
pm_power_off = pm_pwroff_fn;
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
