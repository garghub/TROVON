static int kxtj9_i2c_read(struct kxtj9_data *tj9, u8 addr, u8 *data, int len)
{
struct i2c_msg msgs[] = {
{
.addr = tj9->client->addr,
.flags = tj9->client->flags,
.len = 1,
.buf = &addr,
},
{
.addr = tj9->client->addr,
.flags = tj9->client->flags | I2C_M_RD,
.len = len,
.buf = data,
},
};
return i2c_transfer(tj9->client->adapter, msgs, 2);
}
static void kxtj9_report_acceleration_data(struct kxtj9_data *tj9)
{
s16 acc_data[3];
s16 x, y, z;
int err;
err = kxtj9_i2c_read(tj9, XOUT_L, (u8 *)acc_data, 6);
if (err < 0)
dev_err(&tj9->client->dev, "accelerometer data read failed\n");
x = le16_to_cpu(acc_data[tj9->pdata.axis_map_x]) >> tj9->shift;
y = le16_to_cpu(acc_data[tj9->pdata.axis_map_y]) >> tj9->shift;
z = le16_to_cpu(acc_data[tj9->pdata.axis_map_z]) >> tj9->shift;
input_report_abs(tj9->input_dev, ABS_X, tj9->pdata.negate_x ? -x : x);
input_report_abs(tj9->input_dev, ABS_Y, tj9->pdata.negate_y ? -y : y);
input_report_abs(tj9->input_dev, ABS_Z, tj9->pdata.negate_z ? -z : z);
input_sync(tj9->input_dev);
}
static irqreturn_t kxtj9_isr(int irq, void *dev)
{
struct kxtj9_data *tj9 = dev;
int err;
kxtj9_report_acceleration_data(tj9);
err = i2c_smbus_read_byte_data(tj9->client, INT_REL);
if (err < 0)
dev_err(&tj9->client->dev,
"error clearing interrupt status: %d\n", err);
return IRQ_HANDLED;
}
static int kxtj9_update_g_range(struct kxtj9_data *tj9, u8 new_g_range)
{
switch (new_g_range) {
case KXTJ9_G_2G:
tj9->shift = 4;
break;
case KXTJ9_G_4G:
tj9->shift = 3;
break;
case KXTJ9_G_8G:
tj9->shift = 2;
break;
default:
return -EINVAL;
}
tj9->ctrl_reg1 &= 0xe7;
tj9->ctrl_reg1 |= new_g_range;
return 0;
}
static int kxtj9_update_odr(struct kxtj9_data *tj9, unsigned int poll_interval)
{
int err;
int i;
for (i = 0; i < ARRAY_SIZE(kxtj9_odr_table); i++) {
tj9->data_ctrl = kxtj9_odr_table[i].mask;
if (poll_interval < kxtj9_odr_table[i].cutoff)
break;
}
err = i2c_smbus_write_byte_data(tj9->client, CTRL_REG1, 0);
if (err < 0)
return err;
err = i2c_smbus_write_byte_data(tj9->client, DATA_CTRL, tj9->data_ctrl);
if (err < 0)
return err;
err = i2c_smbus_write_byte_data(tj9->client, CTRL_REG1, tj9->ctrl_reg1);
if (err < 0)
return err;
return 0;
}
static int kxtj9_device_power_on(struct kxtj9_data *tj9)
{
if (tj9->pdata.power_on)
return tj9->pdata.power_on();
return 0;
}
static void kxtj9_device_power_off(struct kxtj9_data *tj9)
{
int err;
tj9->ctrl_reg1 &= PC1_OFF;
err = i2c_smbus_write_byte_data(tj9->client, CTRL_REG1, tj9->ctrl_reg1);
if (err < 0)
dev_err(&tj9->client->dev, "soft power off failed\n");
if (tj9->pdata.power_off)
tj9->pdata.power_off();
}
static int kxtj9_enable(struct kxtj9_data *tj9)
{
int err;
err = kxtj9_device_power_on(tj9);
if (err < 0)
return err;
err = i2c_smbus_write_byte_data(tj9->client, CTRL_REG1, 0);
if (err < 0)
return err;
if (tj9->client->irq) {
err = i2c_smbus_write_byte_data(tj9->client,
INT_CTRL1, tj9->int_ctrl);
if (err < 0)
return err;
}
err = kxtj9_update_g_range(tj9, tj9->pdata.g_range);
if (err < 0)
return err;
tj9->ctrl_reg1 |= PC1_ON;
err = i2c_smbus_write_byte_data(tj9->client, CTRL_REG1, tj9->ctrl_reg1);
if (err < 0)
return err;
err = kxtj9_update_odr(tj9, tj9->last_poll_interval);
if (err < 0)
return err;
if (tj9->client->irq) {
err = i2c_smbus_read_byte_data(tj9->client, INT_REL);
if (err < 0) {
dev_err(&tj9->client->dev,
"error clearing interrupt: %d\n", err);
goto fail;
}
}
return 0;
fail:
kxtj9_device_power_off(tj9);
return err;
}
static void kxtj9_disable(struct kxtj9_data *tj9)
{
kxtj9_device_power_off(tj9);
}
static int kxtj9_input_open(struct input_dev *input)
{
struct kxtj9_data *tj9 = input_get_drvdata(input);
return kxtj9_enable(tj9);
}
static void kxtj9_input_close(struct input_dev *dev)
{
struct kxtj9_data *tj9 = input_get_drvdata(dev);
kxtj9_disable(tj9);
}
static void __devinit kxtj9_init_input_device(struct kxtj9_data *tj9,
struct input_dev *input_dev)
{
__set_bit(EV_ABS, input_dev->evbit);
input_set_abs_params(input_dev, ABS_X, -G_MAX, G_MAX, FUZZ, FLAT);
input_set_abs_params(input_dev, ABS_Y, -G_MAX, G_MAX, FUZZ, FLAT);
input_set_abs_params(input_dev, ABS_Z, -G_MAX, G_MAX, FUZZ, FLAT);
input_dev->name = "kxtj9_accel";
input_dev->id.bustype = BUS_I2C;
input_dev->dev.parent = &tj9->client->dev;
}
static int __devinit kxtj9_setup_input_device(struct kxtj9_data *tj9)
{
struct input_dev *input_dev;
int err;
input_dev = input_allocate_device();
if (!input_dev) {
dev_err(&tj9->client->dev, "input device allocate failed\n");
return -ENOMEM;
}
tj9->input_dev = input_dev;
input_dev->open = kxtj9_input_open;
input_dev->close = kxtj9_input_close;
input_set_drvdata(input_dev, tj9);
kxtj9_init_input_device(tj9, input_dev);
err = input_register_device(tj9->input_dev);
if (err) {
dev_err(&tj9->client->dev,
"unable to register input polled device %s: %d\n",
tj9->input_dev->name, err);
input_free_device(tj9->input_dev);
return err;
}
return 0;
}
static ssize_t kxtj9_get_poll(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct i2c_client *client = to_i2c_client(dev);
struct kxtj9_data *tj9 = i2c_get_clientdata(client);
return sprintf(buf, "%d\n", tj9->last_poll_interval);
}
static ssize_t kxtj9_set_poll(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct i2c_client *client = to_i2c_client(dev);
struct kxtj9_data *tj9 = i2c_get_clientdata(client);
struct input_dev *input_dev = tj9->input_dev;
unsigned int interval;
int error;
error = kstrtouint(buf, 10, &interval);
if (error < 0)
return error;
mutex_lock(&input_dev->mutex);
disable_irq(client->irq);
tj9->last_poll_interval = max(interval, tj9->pdata.min_interval);
kxtj9_update_odr(tj9, tj9->last_poll_interval);
enable_irq(client->irq);
mutex_unlock(&input_dev->mutex);
return count;
}
static void kxtj9_poll(struct input_polled_dev *dev)
{
struct kxtj9_data *tj9 = dev->private;
unsigned int poll_interval = dev->poll_interval;
kxtj9_report_acceleration_data(tj9);
if (poll_interval != tj9->last_poll_interval) {
kxtj9_update_odr(tj9, poll_interval);
tj9->last_poll_interval = poll_interval;
}
}
static void kxtj9_polled_input_open(struct input_polled_dev *dev)
{
struct kxtj9_data *tj9 = dev->private;
kxtj9_enable(tj9);
}
static void kxtj9_polled_input_close(struct input_polled_dev *dev)
{
struct kxtj9_data *tj9 = dev->private;
kxtj9_disable(tj9);
}
static int __devinit kxtj9_setup_polled_device(struct kxtj9_data *tj9)
{
int err;
struct input_polled_dev *poll_dev;
poll_dev = input_allocate_polled_device();
if (!poll_dev) {
dev_err(&tj9->client->dev,
"Failed to allocate polled device\n");
return -ENOMEM;
}
tj9->poll_dev = poll_dev;
tj9->input_dev = poll_dev->input;
poll_dev->private = tj9;
poll_dev->poll = kxtj9_poll;
poll_dev->open = kxtj9_polled_input_open;
poll_dev->close = kxtj9_polled_input_close;
kxtj9_init_input_device(tj9, poll_dev->input);
err = input_register_polled_device(poll_dev);
if (err) {
dev_err(&tj9->client->dev,
"Unable to register polled device, err=%d\n", err);
input_free_polled_device(poll_dev);
return err;
}
return 0;
}
static void __devexit kxtj9_teardown_polled_device(struct kxtj9_data *tj9)
{
input_unregister_polled_device(tj9->poll_dev);
input_free_polled_device(tj9->poll_dev);
}
static inline int kxtj9_setup_polled_device(struct kxtj9_data *tj9)
{
return -ENOSYS;
}
static inline void kxtj9_teardown_polled_device(struct kxtj9_data *tj9)
{
}
static int __devinit kxtj9_verify(struct kxtj9_data *tj9)
{
int retval;
retval = kxtj9_device_power_on(tj9);
if (retval < 0)
return retval;
retval = i2c_smbus_read_byte_data(tj9->client, WHO_AM_I);
if (retval < 0) {
dev_err(&tj9->client->dev, "read err int source\n");
goto out;
}
retval = retval != 0x06 ? -EIO : 0;
out:
kxtj9_device_power_off(tj9);
return retval;
}
static int __devinit kxtj9_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const struct kxtj9_platform_data *pdata = client->dev.platform_data;
struct kxtj9_data *tj9;
int err;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_I2C | I2C_FUNC_SMBUS_BYTE_DATA)) {
dev_err(&client->dev, "client is not i2c capable\n");
return -ENXIO;
}
if (!pdata) {
dev_err(&client->dev, "platform data is NULL; exiting\n");
return -EINVAL;
}
tj9 = kzalloc(sizeof(*tj9), GFP_KERNEL);
if (!tj9) {
dev_err(&client->dev,
"failed to allocate memory for module data\n");
return -ENOMEM;
}
tj9->client = client;
tj9->pdata = *pdata;
if (pdata->init) {
err = pdata->init();
if (err < 0)
goto err_free_mem;
}
err = kxtj9_verify(tj9);
if (err < 0) {
dev_err(&client->dev, "device not recognized\n");
goto err_pdata_exit;
}
i2c_set_clientdata(client, tj9);
tj9->ctrl_reg1 = tj9->pdata.res_12bit | tj9->pdata.g_range;
tj9->data_ctrl = tj9->pdata.data_odr_init;
if (client->irq) {
tj9->int_ctrl |= KXTJ9_IEN | KXTJ9_IEA | KXTJ9_IEL;
tj9->ctrl_reg1 |= DRDYE;
err = kxtj9_setup_input_device(tj9);
if (err)
goto err_pdata_exit;
err = request_threaded_irq(client->irq, NULL, kxtj9_isr,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"kxtj9-irq", tj9);
if (err) {
dev_err(&client->dev, "request irq failed: %d\n", err);
goto err_destroy_input;
}
err = sysfs_create_group(&client->dev.kobj, &kxtj9_attribute_group);
if (err) {
dev_err(&client->dev, "sysfs create failed: %d\n", err);
goto err_free_irq;
}
} else {
err = kxtj9_setup_polled_device(tj9);
if (err)
goto err_pdata_exit;
}
return 0;
err_free_irq:
free_irq(client->irq, tj9);
err_destroy_input:
input_unregister_device(tj9->input_dev);
err_pdata_exit:
if (tj9->pdata.exit)
tj9->pdata.exit();
err_free_mem:
kfree(tj9);
return err;
}
static int __devexit kxtj9_remove(struct i2c_client *client)
{
struct kxtj9_data *tj9 = i2c_get_clientdata(client);
if (client->irq) {
sysfs_remove_group(&client->dev.kobj, &kxtj9_attribute_group);
free_irq(client->irq, tj9);
input_unregister_device(tj9->input_dev);
} else {
kxtj9_teardown_polled_device(tj9);
}
if (tj9->pdata.exit)
tj9->pdata.exit();
kfree(tj9);
return 0;
}
static int kxtj9_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct kxtj9_data *tj9 = i2c_get_clientdata(client);
struct input_dev *input_dev = tj9->input_dev;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
kxtj9_disable(tj9);
mutex_unlock(&input_dev->mutex);
return 0;
}
static int kxtj9_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct kxtj9_data *tj9 = i2c_get_clientdata(client);
struct input_dev *input_dev = tj9->input_dev;
int retval = 0;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
kxtj9_enable(tj9);
mutex_unlock(&input_dev->mutex);
return retval;
}
static int __init kxtj9_init(void)
{
return i2c_add_driver(&kxtj9_driver);
}
static void __exit kxtj9_exit(void)
{
i2c_del_driver(&kxtj9_driver);
}
