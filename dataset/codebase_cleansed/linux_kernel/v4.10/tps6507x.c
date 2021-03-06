static int tps6507x_i2c_read_device(struct tps6507x_dev *tps6507x, char reg,
int bytes, void *dest)
{
struct i2c_client *i2c = tps6507x->i2c_client;
struct i2c_msg xfer[2];
int ret;
xfer[0].addr = i2c->addr;
xfer[0].flags = 0;
xfer[0].len = 1;
xfer[0].buf = &reg;
xfer[1].addr = i2c->addr;
xfer[1].flags = I2C_M_RD;
xfer[1].len = bytes;
xfer[1].buf = dest;
ret = i2c_transfer(i2c->adapter, xfer, 2);
if (ret == 2)
ret = 0;
else if (ret >= 0)
ret = -EIO;
return ret;
}
static int tps6507x_i2c_write_device(struct tps6507x_dev *tps6507x, char reg,
int bytes, void *src)
{
struct i2c_client *i2c = tps6507x->i2c_client;
u8 msg[TPS6507X_MAX_REGISTER + 1];
int ret;
if (bytes > TPS6507X_MAX_REGISTER)
return -EINVAL;
msg[0] = reg;
memcpy(&msg[1], src, bytes);
ret = i2c_master_send(i2c, msg, bytes + 1);
if (ret < 0)
return ret;
if (ret != bytes + 1)
return -EIO;
return 0;
}
static int tps6507x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct tps6507x_dev *tps6507x;
tps6507x = devm_kzalloc(&i2c->dev, sizeof(struct tps6507x_dev),
GFP_KERNEL);
if (tps6507x == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, tps6507x);
tps6507x->dev = &i2c->dev;
tps6507x->i2c_client = i2c;
tps6507x->read_dev = tps6507x_i2c_read_device;
tps6507x->write_dev = tps6507x_i2c_write_device;
return devm_mfd_add_devices(tps6507x->dev, -1, tps6507x_devs,
ARRAY_SIZE(tps6507x_devs), NULL, 0, NULL);
}
static int __init tps6507x_i2c_init(void)
{
return i2c_add_driver(&tps6507x_i2c_driver);
}
static void __exit tps6507x_i2c_exit(void)
{
i2c_del_driver(&tps6507x_i2c_driver);
}
