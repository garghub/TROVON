static inline int pm860x_read_device(struct i2c_client *i2c,
int reg, int bytes, void *dest)
{
unsigned char data;
int ret;
data = (unsigned char)reg;
ret = i2c_master_send(i2c, &data, 1);
if (ret < 0)
return ret;
ret = i2c_master_recv(i2c, dest, bytes);
if (ret < 0)
return ret;
return 0;
}
static inline int pm860x_write_device(struct i2c_client *i2c,
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
int pm860x_reg_read(struct i2c_client *i2c, int reg)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
unsigned char data;
int ret;
mutex_lock(&chip->io_lock);
ret = pm860x_read_device(i2c, reg, 1, &data);
mutex_unlock(&chip->io_lock);
if (ret < 0)
return ret;
else
return (int)data;
}
int pm860x_reg_write(struct i2c_client *i2c, int reg,
unsigned char data)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
int ret;
mutex_lock(&chip->io_lock);
ret = pm860x_write_device(i2c, reg, 1, &data);
mutex_unlock(&chip->io_lock);
return ret;
}
int pm860x_bulk_read(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
int ret;
mutex_lock(&chip->io_lock);
ret = pm860x_read_device(i2c, reg, count, buf);
mutex_unlock(&chip->io_lock);
return ret;
}
int pm860x_bulk_write(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
int ret;
mutex_lock(&chip->io_lock);
ret = pm860x_write_device(i2c, reg, count, buf);
mutex_unlock(&chip->io_lock);
return ret;
}
int pm860x_set_bits(struct i2c_client *i2c, int reg,
unsigned char mask, unsigned char data)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
unsigned char value;
int ret;
mutex_lock(&chip->io_lock);
ret = pm860x_read_device(i2c, reg, 1, &value);
if (ret < 0)
goto out;
value &= ~mask;
value |= data;
ret = pm860x_write_device(i2c, reg, 1, &value);
out:
mutex_unlock(&chip->io_lock);
return ret;
}
int pm860x_page_reg_read(struct i2c_client *i2c, int reg)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
unsigned char zero = 0;
unsigned char data;
int ret;
mutex_lock(&chip->io_lock);
pm860x_write_device(i2c, 0xFA, 0, &zero);
pm860x_write_device(i2c, 0xFB, 0, &zero);
pm860x_write_device(i2c, 0xFF, 0, &zero);
ret = pm860x_read_device(i2c, reg, 1, &data);
if (ret >= 0)
ret = (int)data;
pm860x_write_device(i2c, 0xFE, 0, &zero);
pm860x_write_device(i2c, 0xFC, 0, &zero);
mutex_unlock(&chip->io_lock);
return ret;
}
int pm860x_page_reg_write(struct i2c_client *i2c, int reg,
unsigned char data)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
unsigned char zero;
int ret;
mutex_lock(&chip->io_lock);
pm860x_write_device(i2c, 0xFA, 0, &zero);
pm860x_write_device(i2c, 0xFB, 0, &zero);
pm860x_write_device(i2c, 0xFF, 0, &zero);
ret = pm860x_write_device(i2c, reg, 1, &data);
pm860x_write_device(i2c, 0xFE, 0, &zero);
pm860x_write_device(i2c, 0xFC, 0, &zero);
mutex_unlock(&chip->io_lock);
return ret;
}
int pm860x_page_bulk_read(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
unsigned char zero = 0;
int ret;
mutex_lock(&chip->io_lock);
pm860x_write_device(i2c, 0xFA, 0, &zero);
pm860x_write_device(i2c, 0xFB, 0, &zero);
pm860x_write_device(i2c, 0xFF, 0, &zero);
ret = pm860x_read_device(i2c, reg, count, buf);
pm860x_write_device(i2c, 0xFE, 0, &zero);
pm860x_write_device(i2c, 0xFC, 0, &zero);
mutex_unlock(&chip->io_lock);
return ret;
}
int pm860x_page_bulk_write(struct i2c_client *i2c, int reg,
int count, unsigned char *buf)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
unsigned char zero = 0;
int ret;
mutex_lock(&chip->io_lock);
pm860x_write_device(i2c, 0xFA, 0, &zero);
pm860x_write_device(i2c, 0xFB, 0, &zero);
pm860x_write_device(i2c, 0xFF, 0, &zero);
ret = pm860x_write_device(i2c, reg, count, buf);
pm860x_write_device(i2c, 0xFE, 0, &zero);
pm860x_write_device(i2c, 0xFC, 0, &zero);
mutex_unlock(&chip->io_lock);
return ret;
}
int pm860x_page_set_bits(struct i2c_client *i2c, int reg,
unsigned char mask, unsigned char data)
{
struct pm860x_chip *chip = i2c_get_clientdata(i2c);
unsigned char zero;
unsigned char value;
int ret;
mutex_lock(&chip->io_lock);
pm860x_write_device(i2c, 0xFA, 0, &zero);
pm860x_write_device(i2c, 0xFB, 0, &zero);
pm860x_write_device(i2c, 0xFF, 0, &zero);
ret = pm860x_read_device(i2c, reg, 1, &value);
if (ret < 0)
goto out;
value &= ~mask;
value |= data;
ret = pm860x_write_device(i2c, reg, 1, &value);
out:
pm860x_write_device(i2c, 0xFE, 0, &zero);
pm860x_write_device(i2c, 0xFC, 0, &zero);
mutex_unlock(&chip->io_lock);
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
if (!pdata) {
pr_info("No platform data in %s!\n", __func__);
return -EINVAL;
}
chip = kzalloc(sizeof(struct pm860x_chip), GFP_KERNEL);
if (chip == NULL)
return -ENOMEM;
chip->id = verify_addr(client);
chip->client = client;
i2c_set_clientdata(client, chip);
chip->dev = &client->dev;
mutex_init(&chip->io_lock);
dev_set_drvdata(chip->dev, chip);
if (pdata->companion_addr && (pdata->companion_addr != client->addr)) {
chip->companion_addr = pdata->companion_addr;
chip->companion = i2c_new_dummy(chip->client->adapter,
chip->companion_addr);
i2c_set_clientdata(chip->companion, chip);
}
pm860x_device_init(chip, pdata);
return 0;
}
static int __devexit pm860x_remove(struct i2c_client *client)
{
struct pm860x_chip *chip = i2c_get_clientdata(client);
pm860x_device_exit(chip);
i2c_unregister_device(chip->companion);
kfree(chip);
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
