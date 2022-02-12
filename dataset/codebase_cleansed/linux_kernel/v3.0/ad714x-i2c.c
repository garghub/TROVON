static int ad714x_i2c_suspend(struct device *dev)
{
return ad714x_disable(i2c_get_clientdata(to_i2c_client(dev)));
}
static int ad714x_i2c_resume(struct device *dev)
{
return ad714x_enable(i2c_get_clientdata(to_i2c_client(dev)));
}
static int ad714x_i2c_write(struct device *dev, unsigned short reg,
unsigned short data)
{
struct i2c_client *client = to_i2c_client(dev);
int ret = 0;
u8 *_reg = (u8 *)&reg;
u8 *_data = (u8 *)&data;
u8 tx[4] = {
_reg[1],
_reg[0],
_data[1],
_data[0]
};
ret = i2c_master_send(client, tx, 4);
if (ret < 0)
dev_err(&client->dev, "I2C write error\n");
return ret;
}
static int ad714x_i2c_read(struct device *dev, unsigned short reg,
unsigned short *data)
{
struct i2c_client *client = to_i2c_client(dev);
int ret = 0;
u8 *_reg = (u8 *)&reg;
u8 *_data = (u8 *)data;
u8 tx[2] = {
_reg[1],
_reg[0]
};
u8 rx[2];
ret = i2c_master_send(client, tx, 2);
if (ret >= 0)
ret = i2c_master_recv(client, rx, 2);
if (unlikely(ret < 0)) {
dev_err(&client->dev, "I2C read error\n");
} else {
_data[0] = rx[1];
_data[1] = rx[0];
}
return ret;
}
static int __devinit ad714x_i2c_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct ad714x_chip *chip;
chip = ad714x_probe(&client->dev, BUS_I2C, client->irq,
ad714x_i2c_read, ad714x_i2c_write);
if (IS_ERR(chip))
return PTR_ERR(chip);
i2c_set_clientdata(client, chip);
return 0;
}
static int __devexit ad714x_i2c_remove(struct i2c_client *client)
{
struct ad714x_chip *chip = i2c_get_clientdata(client);
ad714x_remove(chip);
return 0;
}
static __init int ad714x_i2c_init(void)
{
return i2c_add_driver(&ad714x_i2c_driver);
}
static __exit void ad714x_i2c_exit(void)
{
i2c_del_driver(&ad714x_i2c_driver);
}
