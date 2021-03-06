int pm860x_reg_read(struct i2c_client *i2c, int reg)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
struct regmap *map = (i2c == chip->client) ? chip->regmap
: chip->regmap_companion;
unsigned int data;
int ret;
ret = regmap_read(map, reg, &data);
if (ret < 0)
return ret;
else
return (int)data;
}
int pm860x_reg_write(struct i2c_client *i2c, int reg,
unsigned char data)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
struct regmap *map = (i2c == chip->client) ? chip->regmap
: chip->regmap_companion;
int ret;
ret = regmap_write(map, reg, data);
return ret;
}
int pm860x_bulk_read(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
struct regmap *map = (i2c == chip->client) ? chip->regmap
: chip->regmap_companion;
int ret;
ret = regmap_raw_read(map, reg, buf, count);
return ret;
}
int pm860x_bulk_write(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
struct regmap *map = (i2c == chip->client) ? chip->regmap
: chip->regmap_companion;
int ret;
ret = regmap_raw_write(map, reg, buf, count);
return ret;
}
int pm860x_set_bits(struct i2c_client *i2c, int reg,
unsigned char mask, unsigned char data)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
struct regmap *map = (i2c == chip->client) ? chip->regmap
: chip->regmap_companion;
int ret;
ret = regmap_update_bits(map, reg, mask, data);
return ret;
}
static int read_device(struct i2c_client *i2c, int reg,
int bytes, void *dest)
{
unsigned char msgbuf0[I2C_SMBUS_BLOCK_MAX + 3];
unsigned char msgbuf1[I2C_SMBUS_BLOCK_MAX + 2];
struct i2c_adapter *adap = i2c->adapter;
struct i2c_msg msg[2] = {{i2c->addr, 0, 1, msgbuf0},
{i2c->addr, I2C_M_RD, 0, msgbuf1},
};
int num = 1, ret = 0;
if (dest == NULL)
return -EINVAL;
msgbuf0[0] = (unsigned char)reg;
msg[1].len = bytes;
if (bytes > 0)
num = 2;
ret = adap->algo->master_xfer(adap, msg, num);
memcpy(dest, msgbuf1, bytes);
if (ret < 0)
return ret;
return 0;
}
static int write_device(struct i2c_client *i2c, int reg,
int bytes, void *src)
{
unsigned char buf[bytes + 1];
struct i2c_adapter *adap = i2c->adapter;
struct i2c_msg msg;
int ret;
buf[0] = (unsigned char)reg;
memcpy(&buf[1], src, bytes);
msg.addr = i2c->addr;
msg.flags = 0;
msg.len = bytes + 1;
msg.buf = buf;
ret = adap->algo->master_xfer(adap, &msg, 1);
if (ret < 0)
return ret;
return 0;
}
int pm860x_page_reg_read(struct i2c_client *i2c, int reg)
{
unsigned char zero = 0;
unsigned char data;
int ret;
i2c_lock_adapter(i2c->adapter);
read_device(i2c, 0xFA, 0, &zero);
read_device(i2c, 0xFB, 0, &zero);
read_device(i2c, 0xFF, 0, &zero);
ret = read_device(i2c, reg, 1, &data);
if (ret >= 0)
ret = (int)data;
read_device(i2c, 0xFE, 0, &zero);
read_device(i2c, 0xFC, 0, &zero);
i2c_unlock_adapter(i2c->adapter);
return ret;
}
int pm860x_page_reg_write(struct i2c_client *i2c, int reg,
unsigned char data)
{
unsigned char zero;
int ret;
i2c_lock_adapter(i2c->adapter);
read_device(i2c, 0xFA, 0, &zero);
read_device(i2c, 0xFB, 0, &zero);
read_device(i2c, 0xFF, 0, &zero);
ret = write_device(i2c, reg, 1, &data);
read_device(i2c, 0xFE, 0, &zero);
read_device(i2c, 0xFC, 0, &zero);
i2c_unlock_adapter(i2c->adapter);
return ret;
}
int pm860x_page_bulk_read(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
unsigned char zero = 0;
int ret;
i2c_lock_adapter(i2c->adapter);
read_device(i2c, 0xfa, 0, &zero);
read_device(i2c, 0xfb, 0, &zero);
read_device(i2c, 0xff, 0, &zero);
ret = read_device(i2c, reg, count, buf);
read_device(i2c, 0xFE, 0, &zero);
read_device(i2c, 0xFC, 0, &zero);
i2c_unlock_adapter(i2c->adapter);
return ret;
}
int pm860x_page_bulk_write(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
unsigned char zero = 0;
int ret;
i2c_lock_adapter(i2c->adapter);
read_device(i2c, 0xFA, 0, &zero);
read_device(i2c, 0xFB, 0, &zero);
read_device(i2c, 0xFF, 0, &zero);
ret = write_device(i2c, reg, count, buf);
read_device(i2c, 0xFE, 0, &zero);
read_device(i2c, 0xFC, 0, &zero);
i2c_unlock_adapter(i2c->adapter);
i2c_unlock_adapter(i2c->adapter);
return ret;
}
int pm860x_page_set_bits(struct i2c_client *i2c, int reg,
unsigned char mask, unsigned char data)
{
unsigned char zero;
unsigned char value;
int ret;
i2c_lock_adapter(i2c->adapter);
read_device(i2c, 0xFA, 0, &zero);
read_device(i2c, 0xFB, 0, &zero);
read_device(i2c, 0xFF, 0, &zero);
ret = read_device(i2c, reg, 1, &value);
if (ret < 0)
goto out;
value &= ~mask;
value |= data;
ret = write_device(i2c, reg, 1, &value);
out:
read_device(i2c, 0xFE, 0, &zero);
read_device(i2c, 0xFC, 0, &zero);
i2c_unlock_adapter(i2c->adapter);
return ret;
}
static int verify_addr(struct i2c_client *i2c)
{
unsigned short addr_8607[] = {0x30, 0x34};
unsigned short addr_8606[] = {0x10, 0x11};
int size, i;
if (i2c == NULL)
return 0;
size = ARRAY_SIZE(addr_8606);
for (i = 0; i < size; i++) {
if (i2c->addr == *(addr_8606 + i))
return CHIP_PM8606;
}
size = ARRAY_SIZE(addr_8607);
for (i = 0; i < size; i++) {
if (i2c->addr == *(addr_8607 + i))
return CHIP_PM8607;
}
return 0;
}
static int __devinit pm860x_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct pm860x_platform_data *pdata = client->dev.platform_data;
struct pm860x_chip *chip;
int ret;
if (!pdata) {
pr_info("No platform data in %s!\n", __func__);
return -EINVAL;
}
chip = kzalloc(sizeof(struct pm860x_chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
chip->id = verify_addr(client);
chip->regmap = regmap_init_i2c(client, &pm860x_regmap_config);
if (IS_ERR(chip->regmap)) {
ret = PTR_ERR(chip->regmap);
dev_err(&client->dev, "Failed to allocate register map: %d\n",
ret);
kfree(chip);
return ret;
}
chip->client = client;
i2c_set_clientdata(client, chip);
chip->dev = &client->dev;
dev_set_drvdata(chip->dev, chip);
if (pdata->companion_addr && (pdata->companion_addr != client->addr)) {
chip->companion_addr = pdata->companion_addr;
chip->companion = i2c_new_dummy(chip->client->adapter,
chip->companion_addr);
chip->regmap_companion = regmap_init_i2c(chip->companion,
&pm860x_regmap_config);
if (IS_ERR(chip->regmap_companion)) {
ret = PTR_ERR(chip->regmap_companion);
dev_err(&chip->companion->dev,
"Failed to allocate register map: %d\n", ret);
return ret;
}
i2c_set_clientdata(chip->companion, chip);
}
pm860x_device_init(chip, pdata);
return 0;
}
static int __devexit pm860x_remove(struct i2c_client *client)
{
struct pm860x_chip *chip = i2c_get_clientdata(client);
pm860x_device_exit(chip);
if (chip->companion) {
regmap_exit(chip->regmap_companion);
i2c_unregister_device(chip->companion);
}
regmap_exit(chip->regmap);
kfree(chip);
return 0;
}
static int pm860x_suspend(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct pm860x_chip *chip = i2c_get_clientdata(client);
if (device_may_wakeup(dev) && chip->wakeup_flag)
enable_irq_wake(chip->core_irq);
return 0;
}
static int pm860x_resume(struct device *dev)
{
struct i2c_client *client = container_of(dev, struct i2c_client, dev);
struct pm860x_chip *chip = i2c_get_clientdata(client);
if (device_may_wakeup(dev) && chip->wakeup_flag)
disable_irq_wake(chip->core_irq);
return 0;
}
static int __init pm860x_i2c_init(void)
{
int ret;
ret = i2c_add_driver(&pm860x_driver);
if (ret != 0)
pr_err("Failed to register 88PM860x I2C driver: %d\n", ret);
return ret;
}
static void __exit pm860x_i2c_exit(void)
{
i2c_del_driver(&pm860x_driver);
}
