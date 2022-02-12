static bool da9150_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case DA9150_PAGE_CON:
case DA9150_STATUS_A:
case DA9150_STATUS_B:
case DA9150_STATUS_C:
case DA9150_STATUS_D:
case DA9150_STATUS_E:
case DA9150_STATUS_F:
case DA9150_STATUS_G:
case DA9150_STATUS_H:
case DA9150_STATUS_I:
case DA9150_STATUS_J:
case DA9150_STATUS_K:
case DA9150_STATUS_L:
case DA9150_STATUS_N:
case DA9150_FAULT_LOG_A:
case DA9150_FAULT_LOG_B:
case DA9150_EVENT_E:
case DA9150_EVENT_F:
case DA9150_EVENT_G:
case DA9150_EVENT_H:
case DA9150_CONTROL_B:
case DA9150_CONTROL_C:
case DA9150_GPADC_MAN:
case DA9150_GPADC_RES_A:
case DA9150_GPADC_RES_B:
case DA9150_ADETVB_CFG_C:
case DA9150_ADETD_STAT:
case DA9150_ADET_CMPSTAT:
case DA9150_ADET_CTRL_A:
case DA9150_PPR_TCTR_B:
case DA9150_COREBTLD_STAT_A:
case DA9150_CORE_DATA_A:
case DA9150_CORE_DATA_B:
case DA9150_CORE_DATA_C:
case DA9150_CORE_DATA_D:
case DA9150_CORE2WIRE_STAT_A:
case DA9150_FW_CTRL_C:
case DA9150_FG_CTRL_B:
case DA9150_FW_CTRL_B:
case DA9150_GPADC_CMAN:
case DA9150_GPADC_CRES_A:
case DA9150_GPADC_CRES_B:
case DA9150_CC_ICHG_RES_A:
case DA9150_CC_ICHG_RES_B:
case DA9150_CC_IAVG_RES_A:
case DA9150_CC_IAVG_RES_B:
case DA9150_TAUX_CTRL_A:
case DA9150_TAUX_VALUE_H:
case DA9150_TAUX_VALUE_L:
case DA9150_TBAT_RES_A:
case DA9150_TBAT_RES_B:
return true;
default:
return false;
}
}
u8 da9150_reg_read(struct da9150 *da9150, u16 reg)
{
int val, ret;
ret = regmap_read(da9150->regmap, reg, &val);
if (ret)
dev_err(da9150->dev, "Failed to read from reg 0x%x: %d\n",
reg, ret);
return (u8) val;
}
void da9150_reg_write(struct da9150 *da9150, u16 reg, u8 val)
{
int ret;
ret = regmap_write(da9150->regmap, reg, val);
if (ret)
dev_err(da9150->dev, "Failed to write to reg 0x%x: %d\n",
reg, ret);
}
void da9150_set_bits(struct da9150 *da9150, u16 reg, u8 mask, u8 val)
{
int ret;
ret = regmap_update_bits(da9150->regmap, reg, mask, val);
if (ret)
dev_err(da9150->dev, "Failed to set bits in reg 0x%x: %d\n",
reg, ret);
}
void da9150_bulk_read(struct da9150 *da9150, u16 reg, int count, u8 *buf)
{
int ret;
ret = regmap_bulk_read(da9150->regmap, reg, buf, count);
if (ret)
dev_err(da9150->dev, "Failed to bulk read from reg 0x%x: %d\n",
reg, ret);
}
void da9150_bulk_write(struct da9150 *da9150, u16 reg, int count, const u8 *buf)
{
int ret;
ret = regmap_raw_write(da9150->regmap, reg, buf, count);
if (ret)
dev_err(da9150->dev, "Failed to bulk write to reg 0x%x %d\n",
reg, ret);
}
static int da9150_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct da9150 *da9150;
struct da9150_pdata *pdata = dev_get_platdata(&client->dev);
int ret;
da9150 = devm_kzalloc(&client->dev, sizeof(*da9150), GFP_KERNEL);
if (!da9150)
return -ENOMEM;
da9150->dev = &client->dev;
da9150->irq = client->irq;
i2c_set_clientdata(client, da9150);
da9150->regmap = devm_regmap_init_i2c(client, &da9150_regmap_config);
if (IS_ERR(da9150->regmap)) {
ret = PTR_ERR(da9150->regmap);
dev_err(da9150->dev, "Failed to allocate register map: %d\n",
ret);
return ret;
}
da9150->irq_base = pdata ? pdata->irq_base : -1;
ret = regmap_add_irq_chip(da9150->regmap, da9150->irq,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
da9150->irq_base, &da9150_regmap_irq_chip,
&da9150->regmap_irq_data);
if (ret)
return ret;
da9150->irq_base = regmap_irq_chip_get_base(da9150->regmap_irq_data);
enable_irq_wake(da9150->irq);
ret = mfd_add_devices(da9150->dev, -1, da9150_devs,
ARRAY_SIZE(da9150_devs), NULL,
da9150->irq_base, NULL);
if (ret) {
dev_err(da9150->dev, "Failed to add child devices: %d\n", ret);
regmap_del_irq_chip(da9150->irq, da9150->regmap_irq_data);
return ret;
}
return 0;
}
static int da9150_remove(struct i2c_client *client)
{
struct da9150 *da9150 = i2c_get_clientdata(client);
regmap_del_irq_chip(da9150->irq, da9150->regmap_irq_data);
mfd_remove_devices(da9150->dev);
return 0;
}
static void da9150_shutdown(struct i2c_client *client)
{
struct da9150 *da9150 = i2c_get_clientdata(client);
da9150_set_bits(da9150, DA9150_CONFIG_D,
DA9150_WKUP_PM_EN_MASK,
DA9150_WKUP_PM_EN_MASK);
da9150_set_bits(da9150, DA9150_CONTROL_C,
DA9150_DISABLE_MASK, DA9150_DISABLE_MASK);
}
