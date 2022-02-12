static int lis3_reg_ctrl(struct lis3lv02d *lis3, bool state)
{
int ret;
if (state == LIS3_REG_OFF) {
ret = regulator_bulk_disable(ARRAY_SIZE(lis3->regulators),
lis3->regulators);
} else {
ret = regulator_bulk_enable(ARRAY_SIZE(lis3->regulators),
lis3->regulators);
usleep_range(10000, 20000);
}
return ret;
}
static inline s32 lis3_i2c_write(struct lis3lv02d *lis3, int reg, u8 value)
{
struct i2c_client *c = lis3->bus_priv;
return i2c_smbus_write_byte_data(c, reg, value);
}
static inline s32 lis3_i2c_read(struct lis3lv02d *lis3, int reg, u8 *v)
{
struct i2c_client *c = lis3->bus_priv;
*v = i2c_smbus_read_byte_data(c, reg);
return 0;
}
static inline s32 lis3_i2c_blockread(struct lis3lv02d *lis3, int reg, int len,
u8 *v)
{
struct i2c_client *c = lis3->bus_priv;
reg |= (1 << 7);
return i2c_smbus_read_i2c_block_data(c, reg, len, v);
}
static int lis3_i2c_init(struct lis3lv02d *lis3)
{
u8 reg;
int ret;
lis3_reg_ctrl(lis3, LIS3_REG_ON);
lis3->read(lis3, WHO_AM_I, &reg);
if (reg != lis3->whoami)
printk(KERN_ERR "lis3: power on failure\n");
ret = lis3->read(lis3, CTRL_REG1, &reg);
if (ret < 0)
return ret;
if (lis3->whoami == WAI_3DLH)
reg |= CTRL1_PM0 | CTRL1_Xen | CTRL1_Yen | CTRL1_Zen;
else
reg |= CTRL1_PD0 | CTRL1_Xen | CTRL1_Yen | CTRL1_Zen;
return lis3->write(lis3, CTRL_REG1, reg);
}
static int lis3lv02d_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
int ret = 0;
struct lis3lv02d_platform_data *pdata = client->dev.platform_data;
#ifdef CONFIG_OF
if (of_match_device(lis3lv02d_i2c_dt_ids, &client->dev)) {
lis3_dev.of_node = client->dev.of_node;
ret = lis3lv02d_init_dt(&lis3_dev);
if (ret)
return ret;
pdata = lis3_dev.pdata;
}
#endif
if (pdata) {
if ((pdata->driver_features & LIS3_USE_BLOCK_READ) &&
(i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_I2C_BLOCK)))
lis3_dev.blkread = lis3_i2c_blockread;
if (pdata->axis_x)
lis3lv02d_axis_map.x = pdata->axis_x;
if (pdata->axis_y)
lis3lv02d_axis_map.y = pdata->axis_y;
if (pdata->axis_z)
lis3lv02d_axis_map.z = pdata->axis_z;
if (pdata->setup_resources)
ret = pdata->setup_resources();
if (ret)
goto fail;
}
lis3_dev.regulators[0].supply = reg_vdd;
lis3_dev.regulators[1].supply = reg_vdd_io;
ret = regulator_bulk_get(&client->dev,
ARRAY_SIZE(lis3_dev.regulators),
lis3_dev.regulators);
if (ret < 0)
goto fail;
lis3_dev.pdata = pdata;
lis3_dev.bus_priv = client;
lis3_dev.init = lis3_i2c_init;
lis3_dev.read = lis3_i2c_read;
lis3_dev.write = lis3_i2c_write;
lis3_dev.irq = client->irq;
lis3_dev.ac = lis3lv02d_axis_map;
lis3_dev.pm_dev = &client->dev;
i2c_set_clientdata(client, &lis3_dev);
lis3_reg_ctrl(&lis3_dev, LIS3_REG_ON);
ret = lis3lv02d_init_device(&lis3_dev);
lis3_reg_ctrl(&lis3_dev, LIS3_REG_OFF);
if (ret)
goto fail2;
return 0;
fail2:
regulator_bulk_free(ARRAY_SIZE(lis3_dev.regulators),
lis3_dev.regulators);
fail:
if (pdata && pdata->release_resources)
pdata->release_resources();
return ret;
}
static int lis3lv02d_i2c_remove(struct i2c_client *client)
{
struct lis3lv02d *lis3 = i2c_get_clientdata(client);
struct lis3lv02d_platform_data *pdata = client->dev.platform_data;
if (pdata && pdata->release_resources)
pdata->release_resources();
lis3lv02d_joystick_disable(lis3);
lis3lv02d_remove_fs(&lis3_dev);
regulator_bulk_free(ARRAY_SIZE(lis3->regulators),
lis3_dev.regulators);
return 0;
}
static int lis3lv02d_i2c_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lis3lv02d *lis3 = i2c_get_clientdata(client);
if (!lis3->pdata || !lis3->pdata->wakeup_flags)
lis3lv02d_poweroff(lis3);
return 0;
}
static int lis3lv02d_i2c_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lis3lv02d *lis3 = i2c_get_clientdata(client);
if (!lis3->pdata || !lis3->pdata->wakeup_flags ||
pm_runtime_suspended(dev))
lis3lv02d_poweron(lis3);
return 0;
}
static int lis3_i2c_runtime_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lis3lv02d *lis3 = i2c_get_clientdata(client);
lis3lv02d_poweroff(lis3);
return 0;
}
static int lis3_i2c_runtime_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct lis3lv02d *lis3 = i2c_get_clientdata(client);
lis3lv02d_poweron(lis3);
return 0;
}
