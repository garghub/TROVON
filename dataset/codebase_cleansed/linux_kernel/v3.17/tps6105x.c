int tps6105x_set(struct tps6105x *tps6105x, u8 reg, u8 value)
{
int ret;
ret = mutex_lock_interruptible(&tps6105x->lock);
if (ret)
return ret;
ret = i2c_smbus_write_byte_data(tps6105x->client, reg, value);
mutex_unlock(&tps6105x->lock);
if (ret < 0)
return ret;
return 0;
}
int tps6105x_get(struct tps6105x *tps6105x, u8 reg, u8 *buf)
{
int ret;
ret = mutex_lock_interruptible(&tps6105x->lock);
if (ret)
return ret;
ret = i2c_smbus_read_byte_data(tps6105x->client, reg);
mutex_unlock(&tps6105x->lock);
if (ret < 0)
return ret;
*buf = ret;
return 0;
}
int tps6105x_mask_and_set(struct tps6105x *tps6105x, u8 reg,
u8 bitmask, u8 bitvalues)
{
int ret;
u8 regval;
ret = mutex_lock_interruptible(&tps6105x->lock);
if (ret)
return ret;
ret = i2c_smbus_read_byte_data(tps6105x->client, reg);
if (ret < 0)
goto fail;
regval = ret;
regval = (~bitmask & regval) | (bitmask & bitvalues);
ret = i2c_smbus_write_byte_data(tps6105x->client, reg, regval);
fail:
mutex_unlock(&tps6105x->lock);
if (ret < 0)
return ret;
return 0;
}
static int tps6105x_startup(struct tps6105x *tps6105x)
{
int ret;
u8 regval;
ret = tps6105x_get(tps6105x, TPS6105X_REG_0, &regval);
if (ret)
return ret;
switch (regval >> TPS6105X_REG0_MODE_SHIFT) {
case TPS6105X_REG0_MODE_SHUTDOWN:
dev_info(&tps6105x->client->dev,
"TPS6105x found in SHUTDOWN mode\n");
break;
case TPS6105X_REG0_MODE_TORCH:
dev_info(&tps6105x->client->dev,
"TPS6105x found in TORCH mode\n");
break;
case TPS6105X_REG0_MODE_TORCH_FLASH:
dev_info(&tps6105x->client->dev,
"TPS6105x found in FLASH mode\n");
break;
case TPS6105X_REG0_MODE_VOLTAGE:
dev_info(&tps6105x->client->dev,
"TPS6105x found in VOLTAGE mode\n");
break;
default:
break;
}
return ret;
}
static int tps6105x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct tps6105x *tps6105x;
struct tps6105x_platform_data *pdata;
int ret;
int i;
tps6105x = devm_kmalloc(&client->dev, sizeof(*tps6105x), GFP_KERNEL);
if (!tps6105x)
return -ENOMEM;
i2c_set_clientdata(client, tps6105x);
tps6105x->client = client;
pdata = dev_get_platdata(&client->dev);
tps6105x->pdata = pdata;
mutex_init(&tps6105x->lock);
ret = tps6105x_startup(tps6105x);
if (ret) {
dev_err(&client->dev, "chip initialization failed\n");
return ret;
}
switch (pdata->mode) {
case TPS6105X_MODE_SHUTDOWN:
dev_info(&client->dev,
"present, not used for anything, only GPIO\n");
break;
case TPS6105X_MODE_TORCH:
tps6105x_cells[0].name = "tps6105x-leds";
dev_warn(&client->dev,
"torch mode is unsupported\n");
break;
case TPS6105X_MODE_TORCH_FLASH:
tps6105x_cells[0].name = "tps6105x-flash";
dev_warn(&client->dev,
"flash mode is unsupported\n");
break;
case TPS6105X_MODE_VOLTAGE:
tps6105x_cells[0].name ="tps6105x-regulator";
break;
default:
break;
}
for (i = 0; i < ARRAY_SIZE(tps6105x_cells); i++) {
tps6105x_cells[i].platform_data = tps6105x;
tps6105x_cells[i].pdata_size = sizeof(*tps6105x);
}
return mfd_add_devices(&client->dev, 0, tps6105x_cells,
ARRAY_SIZE(tps6105x_cells), NULL, 0, NULL);
}
static int tps6105x_remove(struct i2c_client *client)
{
struct tps6105x *tps6105x = i2c_get_clientdata(client);
mfd_remove_devices(&client->dev);
tps6105x_mask_and_set(tps6105x, TPS6105X_REG_0,
TPS6105X_REG0_MODE_MASK,
TPS6105X_MODE_SHUTDOWN << TPS6105X_REG0_MODE_SHIFT);
return 0;
}
static int __init tps6105x_init(void)
{
return i2c_add_driver(&tps6105x_driver);
}
static void __exit tps6105x_exit(void)
{
i2c_del_driver(&tps6105x_driver);
}
