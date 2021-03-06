static inline int eeti_ts_irq_active(struct eeti_ts_priv *priv)
{
return gpio_get_value(priv->irq_gpio) == priv->irq_active_high;
}
static void eeti_ts_read(struct work_struct *work)
{
char buf[6];
unsigned int x, y, res, pressed, to = 100;
struct eeti_ts_priv *priv =
container_of(work, struct eeti_ts_priv, work);
mutex_lock(&priv->mutex);
while (eeti_ts_irq_active(priv) && --to)
i2c_master_recv(priv->client, buf, sizeof(buf));
if (!to) {
dev_err(&priv->client->dev,
"unable to clear IRQ - line stuck?\n");
goto out;
}
if (!(buf[0] & 0x80))
goto out;
pressed = buf[0] & REPORT_BIT_PRESSED;
res = REPORT_RES_BITS(buf[0] & (REPORT_BIT_AD0 | REPORT_BIT_AD1));
x = buf[2] | (buf[1] << 8);
y = buf[4] | (buf[3] << 8);
x >>= res - EETI_TS_BITDEPTH;
y >>= res - EETI_TS_BITDEPTH;
if (flip_x)
x = EETI_MAXVAL - x;
if (flip_y)
y = EETI_MAXVAL - y;
if (buf[0] & REPORT_BIT_HAS_PRESSURE)
input_report_abs(priv->input, ABS_PRESSURE, buf[5]);
input_report_abs(priv->input, ABS_X, x);
input_report_abs(priv->input, ABS_Y, y);
input_report_key(priv->input, BTN_TOUCH, !!pressed);
input_sync(priv->input);
out:
mutex_unlock(&priv->mutex);
}
static irqreturn_t eeti_ts_isr(int irq, void *dev_id)
{
struct eeti_ts_priv *priv = dev_id;
schedule_work(&priv->work);
return IRQ_HANDLED;
}
static void eeti_ts_start(struct eeti_ts_priv *priv)
{
enable_irq(priv->irq);
eeti_ts_read(&priv->work);
}
static void eeti_ts_stop(struct eeti_ts_priv *priv)
{
disable_irq(priv->irq);
cancel_work_sync(&priv->work);
}
static int eeti_ts_open(struct input_dev *dev)
{
struct eeti_ts_priv *priv = input_get_drvdata(dev);
eeti_ts_start(priv);
return 0;
}
static void eeti_ts_close(struct input_dev *dev)
{
struct eeti_ts_priv *priv = input_get_drvdata(dev);
eeti_ts_stop(priv);
}
static int eeti_ts_probe(struct i2c_client *client,
const struct i2c_device_id *idp)
{
struct eeti_ts_platform_data *pdata = client->dev.platform_data;
struct eeti_ts_priv *priv;
struct input_dev *input;
unsigned int irq_flags;
int err = -ENOMEM;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
dev_err(&client->dev, "failed to allocate driver data\n");
goto err0;
}
mutex_init(&priv->mutex);
input = input_allocate_device();
if (!input) {
dev_err(&client->dev, "Failed to allocate input device.\n");
goto err1;
}
input->evbit[0] = BIT_MASK(EV_KEY) | BIT_MASK(EV_ABS);
input->keybit[BIT_WORD(BTN_TOUCH)] = BIT_MASK(BTN_TOUCH);
input_set_abs_params(input, ABS_X, 0, EETI_MAXVAL, 0, 0);
input_set_abs_params(input, ABS_Y, 0, EETI_MAXVAL, 0, 0);
input_set_abs_params(input, ABS_PRESSURE, 0, 0xff, 0, 0);
input->name = client->name;
input->id.bustype = BUS_I2C;
input->dev.parent = &client->dev;
input->open = eeti_ts_open;
input->close = eeti_ts_close;
priv->client = client;
priv->input = input;
priv->irq_gpio = pdata->irq_gpio;
priv->irq = gpio_to_irq(pdata->irq_gpio);
err = gpio_request_one(pdata->irq_gpio, GPIOF_IN, client->name);
if (err < 0)
goto err1;
priv->irq_active_high = pdata->irq_active_high;
irq_flags = priv->irq_active_high ?
IRQF_TRIGGER_RISING : IRQF_TRIGGER_FALLING;
INIT_WORK(&priv->work, eeti_ts_read);
i2c_set_clientdata(client, priv);
input_set_drvdata(input, priv);
err = input_register_device(input);
if (err)
goto err2;
err = request_irq(priv->irq, eeti_ts_isr, irq_flags,
client->name, priv);
if (err) {
dev_err(&client->dev, "Unable to request touchscreen IRQ.\n");
goto err3;
}
eeti_ts_stop(priv);
device_init_wakeup(&client->dev, 0);
return 0;
err3:
input_unregister_device(input);
input = NULL;
err2:
gpio_free(pdata->irq_gpio);
err1:
input_free_device(input);
kfree(priv);
err0:
return err;
}
static int eeti_ts_remove(struct i2c_client *client)
{
struct eeti_ts_priv *priv = i2c_get_clientdata(client);
free_irq(priv->irq, priv);
enable_irq(priv->irq);
input_unregister_device(priv->input);
kfree(priv);
return 0;
}
static int eeti_ts_suspend(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct eeti_ts_priv *priv = i2c_get_clientdata(client);
struct input_dev *input_dev = priv->input;
mutex_lock(&input_dev->mutex);
if (input_dev->users)
eeti_ts_stop(priv);
mutex_unlock(&input_dev->mutex);
if (device_may_wakeup(&client->dev))
enable_irq_wake(priv->irq);
return 0;
}
static int eeti_ts_resume(struct device *dev)
{
struct i2c_client *client = to_i2c_client(dev);
struct eeti_ts_priv *priv = i2c_get_clientdata(client);
struct input_dev *input_dev = priv->input;
if (device_may_wakeup(&client->dev))
disable_irq_wake(priv->irq);
mutex_lock(&input_dev->mutex);
if (input_dev->users)
eeti_ts_start(priv);
mutex_unlock(&input_dev->mutex);
return 0;
}
