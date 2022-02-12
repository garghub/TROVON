static int mma8450_read(struct mma8450 *m, unsigned off)
{
struct i2c_client *c = m->client;
int ret;
ret = i2c_smbus_read_byte_data(c, off);
if (ret < 0)
dev_err(&c->dev,
"failed to read register 0x%02x, error %d\n",
off, ret);
return ret;
}
static int mma8450_write(struct mma8450 *m, unsigned off, u8 v)
{
struct i2c_client *c = m->client;
int error;
error = i2c_smbus_write_byte_data(c, off, v);
if (error < 0) {
dev_err(&c->dev,
"failed to write to register 0x%02x, error %d\n",
off, error);
return error;
}
return 0;
}
static int mma8450_read_block(struct mma8450 *m, unsigned off,
u8 *buf, size_t size)
{
struct i2c_client *c = m->client;
int err;
err = i2c_smbus_read_i2c_block_data(c, off, size, buf);
if (err < 0) {
dev_err(&c->dev,
"failed to read block data at 0x%02x, error %d\n",
MMA8450_OUT_X_LSB, err);
return err;
}
return 0;
}
static void mma8450_poll(struct input_polled_dev *dev)
{
struct mma8450 *m = dev->private;
int x, y, z;
int ret;
u8 buf[6];
ret = mma8450_read(m, MMA8450_STATUS);
if (ret < 0)
return;
if (!(ret & MMA8450_STATUS_ZXYDR))
return;
ret = mma8450_read_block(m, MMA8450_OUT_X_LSB, buf, sizeof(buf));
if (ret < 0)
return;
x = ((int)(s8)buf[1] << 4) | (buf[0] & 0xf);
y = ((int)(s8)buf[3] << 4) | (buf[2] & 0xf);
z = ((int)(s8)buf[5] << 4) | (buf[4] & 0xf);
input_report_abs(dev->input, ABS_X, x);
input_report_abs(dev->input, ABS_Y, y);
input_report_abs(dev->input, ABS_Z, z);
input_sync(dev->input);
}
static void mma8450_open(struct input_polled_dev *dev)
{
struct mma8450 *m = dev->private;
int err;
err = mma8450_write(m, MMA8450_XYZ_DATA_CFG, 0x07);
if (err)
return;
err = mma8450_write(m, MMA8450_CTRL_REG1, 0x01);
if (err < 0)
return;
msleep(MODE_CHANGE_DELAY_MS);
}
static void mma8450_close(struct input_polled_dev *dev)
{
struct mma8450 *m = dev->private;
mma8450_write(m, MMA8450_CTRL_REG1, 0x00);
mma8450_write(m, MMA8450_CTRL_REG2, 0x01);
}
static int mma8450_probe(struct i2c_client *c,
const struct i2c_device_id *id)
{
struct input_polled_dev *idev;
struct mma8450 *m;
int err;
m = kzalloc(sizeof(struct mma8450), GFP_KERNEL);
idev = input_allocate_polled_device();
if (!m || !idev) {
err = -ENOMEM;
goto err_free_mem;
}
m->client = c;
m->idev = idev;
idev->private = m;
idev->input->name = MMA8450_DRV_NAME;
idev->input->id.bustype = BUS_I2C;
idev->input->dev.parent = &c->dev;
idev->poll = mma8450_poll;
idev->poll_interval = POLL_INTERVAL;
idev->poll_interval_max = POLL_INTERVAL_MAX;
idev->open = mma8450_open;
idev->close = mma8450_close;
__set_bit(EV_ABS, idev->input->evbit);
input_set_abs_params(idev->input, ABS_X, -2048, 2047, 32, 32);
input_set_abs_params(idev->input, ABS_Y, -2048, 2047, 32, 32);
input_set_abs_params(idev->input, ABS_Z, -2048, 2047, 32, 32);
err = input_register_polled_device(idev);
if (err) {
dev_err(&c->dev, "failed to register polled input device\n");
goto err_free_mem;
}
i2c_set_clientdata(c, m);
return 0;
err_free_mem:
input_free_polled_device(idev);
kfree(m);
return err;
}
static int mma8450_remove(struct i2c_client *c)
{
struct mma8450 *m = i2c_get_clientdata(c);
struct input_polled_dev *idev = m->idev;
input_unregister_polled_device(idev);
input_free_polled_device(idev);
kfree(m);
return 0;
}
