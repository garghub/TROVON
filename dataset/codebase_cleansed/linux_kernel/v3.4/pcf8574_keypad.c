static short read_state(struct kp_data *lp)
{
unsigned char x, y, a, b;
i2c_smbus_write_byte(lp->client, 240);
x = 0xF & (~(i2c_smbus_read_byte(lp->client) >> 4));
i2c_smbus_write_byte(lp->client, 15);
y = 0xF & (~i2c_smbus_read_byte(lp->client));
for (a = 0; x > 0; a++)
x = x >> 1;
for (b = 0; y > 0; b++)
y = y >> 1;
return ((a - 1) * 4) + b;
}
static irqreturn_t pcf8574_kp_irq_handler(int irq, void *dev_id)
{
struct kp_data *lp = dev_id;
unsigned char nextstate = read_state(lp);
if (lp->laststate != nextstate) {
int key_down = nextstate < ARRAY_SIZE(lp->btncode);
unsigned short keycode = key_down ?
lp->btncode[nextstate] : lp->btncode[lp->laststate];
input_report_key(lp->idev, keycode, key_down);
input_sync(lp->idev);
lp->laststate = nextstate;
}
return IRQ_HANDLED;
}
static int __devinit pcf8574_kp_probe(struct i2c_client *client, const struct i2c_device_id *id)
{
int i, ret;
struct input_dev *idev;
struct kp_data *lp;
if (i2c_smbus_write_byte(client, 240) < 0) {
dev_err(&client->dev, "probe: write fail\n");
return -ENODEV;
}
lp = kzalloc(sizeof(*lp), GFP_KERNEL);
if (!lp)
return -ENOMEM;
idev = input_allocate_device();
if (!idev) {
dev_err(&client->dev, "Can't allocate input device\n");
ret = -ENOMEM;
goto fail_allocate;
}
lp->idev = idev;
lp->client = client;
idev->evbit[0] = BIT_MASK(EV_KEY);
idev->keycode = lp->btncode;
idev->keycodesize = sizeof(lp->btncode[0]);
idev->keycodemax = ARRAY_SIZE(lp->btncode);
for (i = 0; i < ARRAY_SIZE(pcf8574_kp_btncode); i++) {
lp->btncode[i] = pcf8574_kp_btncode[i];
__set_bit(lp->btncode[i] & KEY_MAX, idev->keybit);
}
sprintf(lp->name, DRV_NAME);
sprintf(lp->phys, "kp_data/input0");
idev->name = lp->name;
idev->phys = lp->phys;
idev->id.bustype = BUS_I2C;
idev->id.vendor = 0x0001;
idev->id.product = 0x0001;
idev->id.version = 0x0100;
lp->laststate = read_state(lp);
ret = request_threaded_irq(client->irq, NULL, pcf8574_kp_irq_handler,
IRQF_TRIGGER_LOW | IRQF_ONESHOT,
DRV_NAME, lp);
if (ret) {
dev_err(&client->dev, "IRQ %d is not free\n", client->irq);
goto fail_free_device;
}
ret = input_register_device(idev);
if (ret) {
dev_err(&client->dev, "input_register_device() failed\n");
goto fail_free_irq;
}
i2c_set_clientdata(client, lp);
return 0;
fail_free_irq:
free_irq(client->irq, lp);
fail_free_device:
input_free_device(idev);
fail_allocate:
kfree(lp);
return ret;
}
static int __devexit pcf8574_kp_remove(struct i2c_client *client)
{
struct kp_data *lp = i2c_get_clientdata(client);
free_irq(client->irq, lp);
input_unregister_device(lp->idev);
kfree(lp);
return 0;
}
static int pcf8574_kp_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
enable_irq(client->irq);
return 0;
}
static int pcf8574_kp_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
disable_irq(client->irq);
return 0;
}
