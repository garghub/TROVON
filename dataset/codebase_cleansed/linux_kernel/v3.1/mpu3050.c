static int mpu3050_xyz_read_reg(struct i2c_client *client,
u8 *buffer, int length)
{
char cmd = MPU3050_XOUT_H;
struct i2c_msg msg[] = {
{
.addr = client->addr,
.flags = 0,
.len = 1,
.buf = &cmd,
},
{
.addr = client->addr,
.flags = I2C_M_RD,
.len = length,
.buf = buffer,
},
};
return i2c_transfer(client->adapter, msg, 2);
}
static void mpu3050_read_xyz(struct i2c_client *client,
struct axis_data *coords)
{
u16 buffer[3];
mpu3050_xyz_read_reg(client, (u8 *)buffer, 6);
coords->x = be16_to_cpu(buffer[0]);
coords->y = be16_to_cpu(buffer[1]);
coords->z = be16_to_cpu(buffer[2]);
dev_dbg(&client->dev, "%s: x %d, y %d, z %d\n", __func__,
coords->x, coords->y, coords->z);
}
static void mpu3050_set_power_mode(struct i2c_client *client, u8 val)
{
u8 value;
value = i2c_smbus_read_byte_data(client, MPU3050_PWR_MGM);
value = (value & ~MPU3050_PWR_MGM_MASK) |
(((val << MPU3050_PWR_MGM_POS) & MPU3050_PWR_MGM_MASK) ^
MPU3050_PWR_MGM_MASK);
i2c_smbus_write_byte_data(client, MPU3050_PWR_MGM, value);
}
static int mpu3050_input_open(struct input_dev *input)
{
struct mpu3050_sensor *sensor = input_get_drvdata(input);
pm_runtime_get(sensor->dev);
return 0;
}
static void mpu3050_input_close(struct input_dev *input)
{
struct mpu3050_sensor *sensor = input_get_drvdata(input);
pm_runtime_put(sensor->dev);
}
static irqreturn_t mpu3050_interrupt_thread(int irq, void *data)
{
struct mpu3050_sensor *sensor = data;
struct axis_data axis;
mpu3050_read_xyz(sensor->client, &axis);
input_report_abs(sensor->idev, ABS_X, axis.x);
input_report_abs(sensor->idev, ABS_Y, axis.y);
input_report_abs(sensor->idev, ABS_Z, axis.z);
input_sync(sensor->idev);
return IRQ_HANDLED;
}
static int __devinit mpu3050_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct mpu3050_sensor *sensor;
struct input_dev *idev;
int ret;
int error;
sensor = kzalloc(sizeof(struct mpu3050_sensor), GFP_KERNEL);
idev = input_allocate_device();
if (!sensor || !idev) {
dev_err(&client->dev, "failed to allocate driver data\n");
error = -ENOMEM;
goto err_free_mem;
}
sensor->client = client;
sensor->dev = &client->dev;
sensor->idev = idev;
mpu3050_set_power_mode(client, 1);
msleep(10);
ret = i2c_smbus_read_byte_data(client, MPU3050_CHIP_ID_REG);
if (ret < 0) {
dev_err(&client->dev, "failed to detect device\n");
error = -ENXIO;
goto err_free_mem;
}
if (ret != MPU3050_CHIP_ID) {
dev_err(&client->dev, "unsupported chip id\n");
error = -ENXIO;
goto err_free_mem;
}
idev->name = "MPU3050";
idev->id.bustype = BUS_I2C;
idev->dev.parent = &client->dev;
idev->open = mpu3050_input_open;
idev->close = mpu3050_input_close;
__set_bit(EV_ABS, idev->evbit);
input_set_abs_params(idev, ABS_X,
MPU3050_MIN_VALUE, MPU3050_MAX_VALUE, 0, 0);
input_set_abs_params(idev, ABS_Y,
MPU3050_MIN_VALUE, MPU3050_MAX_VALUE, 0, 0);
input_set_abs_params(idev, ABS_Z,
MPU3050_MIN_VALUE, MPU3050_MAX_VALUE, 0, 0);
input_set_drvdata(idev, sensor);
pm_runtime_set_active(&client->dev);
error = request_threaded_irq(client->irq,
NULL, mpu3050_interrupt_thread,
IRQF_TRIGGER_RISING,
"mpu_int", sensor);
if (error) {
dev_err(&client->dev,
"can't get IRQ %d, error %d\n", client->irq, error);
goto err_pm_set_suspended;
}
error = input_register_device(idev);
if (error) {
dev_err(&client->dev, "failed to register input device\n");
goto err_free_irq;
}
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev, MPU3050_AUTO_DELAY);
return 0;
err_free_irq:
free_irq(client->irq, sensor);
err_pm_set_suspended:
pm_runtime_set_suspended(&client->dev);
err_free_mem:
input_free_device(idev);
kfree(sensor);
return error;
}
static int __devexit mpu3050_remove(struct i2c_client *client)
{
struct mpu3050_sensor *sensor = i2c_get_clientdata(client);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
free_irq(client->irq, sensor);
input_unregister_device(sensor->idev);
kfree(sensor);
return 0;
}
static int mpu3050_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
mpu3050_set_power_mode(client, 0);
return 0;
}
static int mpu3050_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
mpu3050_set_power_mode(client, 1);
msleep(100);
return 0;
}
static int __init mpu3050_init(void)
{
return i2c_add_driver(&mpu3050_i2c_driver);
}
static void __exit mpu3050_exit(void)
{
i2c_del_driver(&mpu3050_i2c_driver);
}
