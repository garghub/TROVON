static inline int max8925_read_device(struct i2c_client *i2c,
int reg, int bytes, void *dest)
{
int ret;
if (bytes > 1)
ret = i2c_smbus_read_i2c_block_data(i2c, reg, bytes, dest);
else {
ret = i2c_smbus_read_byte_data(i2c, reg);
if (ret < 0)
return ret;
*(unsigned char *)dest = (unsigned char)ret;
}
return ret;
}
static inline int max8925_write_device(struct i2c_client *i2c,
int reg, int bytes, void *src)
{
unsigned char buf[bytes + 1];
int ret;
buf[0] = (unsigned char)reg;
memcpy(&buf[1], src, bytes);
ret = i2c_master_send(i2c, buf, bytes + 1);
if (ret < 0)
return ret;
return 0;
}
int max8925_reg_read(struct i2c_client *i2c, int reg)
{
struct max8925_chip *chip = i2c_get_clientdata(i2c);
unsigned char data = 0;
int ret;
mutex_lock(&chip->io_lock);
ret = max8925_read_device(i2c, reg, 1, &data);
mutex_unlock(&chip->io_lock);
if (ret < 0)
return ret;
else
return (int)data;
}
int max8925_reg_write(struct i2c_client *i2c, int reg,
unsigned char data)
{
struct max8925_chip *chip = i2c_get_clientdata(i2c);
int ret;
mutex_lock(&chip->io_lock);
ret = max8925_write_device(i2c, reg, 1, &data);
mutex_unlock(&chip->io_lock);
return ret;
}
int max8925_bulk_read(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
struct max8925_chip *chip = i2c_get_clientdata(i2c);
int ret;
mutex_lock(&chip->io_lock);
ret = max8925_read_device(i2c, reg, count, buf);
mutex_unlock(&chip->io_lock);
return ret;
}
int max8925_bulk_write(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
struct max8925_chip *chip = i2c_get_clientdata(i2c);
int ret;
mutex_lock(&chip->io_lock);
ret = max8925_write_device(i2c, reg, count, buf);
mutex_unlock(&chip->io_lock);
return ret;
}
int max8925_set_bits(struct i2c_client *i2c, int reg,
unsigned char mask, unsigned char data)
{
struct max8925_chip *chip = i2c_get_clientdata(i2c);
unsigned char value;
int ret;
mutex_lock(&chip->io_lock);
ret = max8925_read_device(i2c, reg, 1, &value);
if (ret < 0)
goto out;
value &= ~mask;
value |= data;
ret = max8925_write_device(i2c, reg, 1, &value);
out:
mutex_unlock(&chip->io_lock);
return ret;
}
static int __devinit max8925_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct max8925_platform_data *pdata = client->dev.platform_data;
static struct max8925_chip *chip;
if (!pdata) {
pr_info("%s: platform data is missing\n", __func__);
return -EINVAL;
}
chip = kzalloc(sizeof(struct max8925_chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
chip->i2c = client;
chip->dev = &client->dev;
i2c_set_clientdata(client, chip);
dev_set_drvdata(chip->dev, chip);
mutex_init(&chip->io_lock);
chip->rtc = i2c_new_dummy(chip->i2c->adapter, RTC_I2C_ADDR);
i2c_set_clientdata(chip->rtc, chip);
chip->adc = i2c_new_dummy(chip->i2c->adapter, ADC_I2C_ADDR);
i2c_set_clientdata(chip->adc, chip);
max8925_device_init(chip, pdata);
return 0;
}
static int __devexit max8925_remove(struct i2c_client *client)
{
struct max8925_chip *chip = i2c_get_clientdata(client);
max8925_device_exit(chip);
i2c_unregister_device(chip->adc);
i2c_unregister_device(chip->rtc);
kfree(chip);
return 0;
}
static int __init max8925_i2c_init(void)
{
int ret;
ret = i2c_add_driver(&max8925_driver);
if (ret != 0)
pr_err("Failed to register MAX8925 I2C driver: %d\n", ret);
return ret;
}
static void __exit max8925_i2c_exit(void)
{
i2c_del_driver(&max8925_driver);
}
