static int wm831x_i2c_read_device(struct wm831x *wm831x, unsigned short reg,
int bytes, void *dest)
{
struct i2c_client *i2c = wm831x->control_data;
int ret;
u16 r = cpu_to_be16(reg);
ret = i2c_master_send(i2c, (unsigned char *)&r, 2);
if (ret < 0)
return ret;
if (ret != 2)
return -EIO;
ret = i2c_master_recv(i2c, dest, bytes);
if (ret < 0)
return ret;
if (ret != bytes)
return -EIO;
return 0;
}
static int wm831x_i2c_write_device(struct wm831x *wm831x, unsigned short reg,
int bytes, void *src)
{
struct i2c_client *i2c = wm831x->control_data;
struct i2c_msg xfer[2];
int ret;
reg = cpu_to_be16(reg);
xfer[0].addr = i2c->addr;
xfer[0].flags = 0;
xfer[0].len = 2;
xfer[0].buf = (char *)&reg;
xfer[1].addr = i2c->addr;
xfer[1].flags = I2C_M_NOSTART;
xfer[1].len = bytes;
xfer[1].buf = (char *)src;
ret = i2c_transfer(i2c->adapter, xfer, 2);
if (ret < 0)
return ret;
if (ret != 2)
return -EIO;
return 0;
}
static int wm831x_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm831x *wm831x;
wm831x = kzalloc(sizeof(struct wm831x), GFP_KERNEL);
if (wm831x == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm831x);
wm831x->dev = &i2c->dev;
wm831x->control_data = i2c;
wm831x->read_dev = wm831x_i2c_read_device;
wm831x->write_dev = wm831x_i2c_write_device;
return wm831x_device_init(wm831x, id->driver_data, i2c->irq);
}
static int wm831x_i2c_remove(struct i2c_client *i2c)
{
struct wm831x *wm831x = i2c_get_clientdata(i2c);
wm831x_device_exit(wm831x);
return 0;
}
static int wm831x_i2c_suspend(struct device *dev)
{
struct wm831x *wm831x = dev_get_drvdata(dev);
return wm831x_device_suspend(wm831x);
}
static int __init wm831x_i2c_init(void)
{
int ret;
ret = i2c_add_driver(&wm831x_i2c_driver);
if (ret != 0)
pr_err("Failed to register wm831x I2C driver: %d\n", ret);
return ret;
}
static void __exit wm831x_i2c_exit(void)
{
i2c_del_driver(&wm831x_i2c_driver);
}
