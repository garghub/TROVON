static int wm8350_i2c_read_device(struct wm8350 *wm8350, char reg,
int bytes, void *dest)
{
int ret;
ret = i2c_master_send(wm8350->i2c_client, &reg, 1);
if (ret < 0)
return ret;
ret = i2c_master_recv(wm8350->i2c_client, dest, bytes);
if (ret < 0)
return ret;
if (ret != bytes)
return -EIO;
return 0;
}
static int wm8350_i2c_write_device(struct wm8350 *wm8350, char reg,
int bytes, void *src)
{
u8 msg[(WM8350_MAX_REGISTER << 1) + 1];
int ret;
if (bytes > ((WM8350_MAX_REGISTER << 1) + 1))
return -EINVAL;
msg[0] = reg;
memcpy(&msg[1], src, bytes);
ret = i2c_master_send(wm8350->i2c_client, msg, bytes + 1);
if (ret < 0)
return ret;
if (ret != bytes + 1)
return -EIO;
return 0;
}
static int wm8350_i2c_probe(struct i2c_client *i2c,
const struct i2c_device_id *id)
{
struct wm8350 *wm8350;
int ret = 0;
wm8350 = devm_kzalloc(&i2c->dev, sizeof(struct wm8350), GFP_KERNEL);
if (wm8350 == NULL)
return -ENOMEM;
i2c_set_clientdata(i2c, wm8350);
wm8350->dev = &i2c->dev;
wm8350->i2c_client = i2c;
wm8350->read_dev = wm8350_i2c_read_device;
wm8350->write_dev = wm8350_i2c_write_device;
ret = wm8350_device_init(wm8350, i2c->irq, i2c->dev.platform_data);
if (ret < 0)
goto err;
return ret;
err:
return ret;
}
static int wm8350_i2c_remove(struct i2c_client *i2c)
{
struct wm8350 *wm8350 = i2c_get_clientdata(i2c);
wm8350_device_exit(wm8350);
return 0;
}
static int __init wm8350_i2c_init(void)
{
return i2c_add_driver(&wm8350_i2c_driver);
}
static void __exit wm8350_i2c_exit(void)
{
i2c_del_driver(&wm8350_i2c_driver);
}
