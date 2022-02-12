static int ad7877_read(struct spi_device *spi, u16 reg)
{
struct ser_req *req;
int status, ret;
req = kzalloc(sizeof *req, GFP_KERNEL);
if (!req)
return -ENOMEM;
spi_message_init(&req->msg);
req->command = (u16) (AD7877_WRITEADD(AD7877_REG_CTRL1) |
AD7877_READADD(reg));
req->xfer[0].tx_buf = &req->command;
req->xfer[0].len = 2;
req->xfer[0].cs_change = 1;
req->xfer[1].rx_buf = &req->sample;
req->xfer[1].len = 2;
spi_message_add_tail(&req->xfer[0], &req->msg);
spi_message_add_tail(&req->xfer[1], &req->msg);
status = spi_sync(spi, &req->msg);
ret = status ? : req->sample;
kfree(req);
return ret;
}
static int ad7877_write(struct spi_device *spi, u16 reg, u16 val)
{
struct ser_req *req;
int status;
req = kzalloc(sizeof *req, GFP_KERNEL);
if (!req)
return -ENOMEM;
spi_message_init(&req->msg);
req->command = (u16) (AD7877_WRITEADD(reg) | (val & MAX_12BIT));
req->xfer[0].tx_buf = &req->command;
req->xfer[0].len = 2;
spi_message_add_tail(&req->xfer[0], &req->msg);
status = spi_sync(spi, &req->msg);
kfree(req);
return status;
}
static int ad7877_read_adc(struct spi_device *spi, unsigned command)
{
struct ad7877 *ts = spi_get_drvdata(spi);
struct ser_req *req;
int status;
int sample;
int i;
req = kzalloc(sizeof *req, GFP_KERNEL);
if (!req)
return -ENOMEM;
spi_message_init(&req->msg);
req->ref_on = AD7877_WRITEADD(AD7877_REG_CTRL2) |
AD7877_POL(ts->stopacq_polarity) |
AD7877_AVG(0) | AD7877_PM(2) | AD7877_TMR(0) |
AD7877_ACQ(ts->acquisition_time) | AD7877_FCD(0);
req->reset = AD7877_WRITEADD(AD7877_REG_CTRL1) | AD7877_MODE_NOC;
req->command = (u16) command;
req->xfer[0].tx_buf = &req->reset;
req->xfer[0].len = 2;
req->xfer[0].cs_change = 1;
req->xfer[1].tx_buf = &req->ref_on;
req->xfer[1].len = 2;
req->xfer[1].delay_usecs = ts->vref_delay_usecs;
req->xfer[1].cs_change = 1;
req->xfer[2].tx_buf = &req->command;
req->xfer[2].len = 2;
req->xfer[2].delay_usecs = ts->vref_delay_usecs;
req->xfer[2].cs_change = 1;
req->xfer[3].rx_buf = &req->sample;
req->xfer[3].len = 2;
req->xfer[3].cs_change = 1;
req->xfer[4].tx_buf = &ts->cmd_crtl2;
req->xfer[4].len = 2;
req->xfer[4].cs_change = 1;
req->xfer[5].tx_buf = &ts->cmd_crtl1;
req->xfer[5].len = 2;
for (i = 0; i < 6; i++)
spi_message_add_tail(&req->xfer[i], &req->msg);
status = spi_sync(spi, &req->msg);
sample = req->sample;
kfree(req);
return status ? : sample;
}
static int ad7877_process_data(struct ad7877 *ts)
{
struct input_dev *input_dev = ts->input;
unsigned Rt;
u16 x, y, z1, z2;
x = ts->conversion_data[AD7877_SEQ_XPOS] & MAX_12BIT;
y = ts->conversion_data[AD7877_SEQ_YPOS] & MAX_12BIT;
z1 = ts->conversion_data[AD7877_SEQ_Z1] & MAX_12BIT;
z2 = ts->conversion_data[AD7877_SEQ_Z2] & MAX_12BIT;
if (likely(x && z1)) {
Rt = (z2 - z1) * x * ts->x_plate_ohms;
Rt /= z1;
Rt = (Rt + 2047) >> 12;
if (Rt > ts->pressure_max)
return -EINVAL;
if (!timer_pending(&ts->timer))
input_report_key(input_dev, BTN_TOUCH, 1);
input_report_abs(input_dev, ABS_X, x);
input_report_abs(input_dev, ABS_Y, y);
input_report_abs(input_dev, ABS_PRESSURE, Rt);
input_sync(input_dev);
return 0;
}
return -EINVAL;
}
static inline void ad7877_ts_event_release(struct ad7877 *ts)
{
struct input_dev *input_dev = ts->input;
input_report_abs(input_dev, ABS_PRESSURE, 0);
input_report_key(input_dev, BTN_TOUCH, 0);
input_sync(input_dev);
}
static void ad7877_timer(unsigned long handle)
{
struct ad7877 *ts = (void *)handle;
unsigned long flags;
spin_lock_irqsave(&ts->lock, flags);
ad7877_ts_event_release(ts);
spin_unlock_irqrestore(&ts->lock, flags);
}
static irqreturn_t ad7877_irq(int irq, void *handle)
{
struct ad7877 *ts = handle;
unsigned long flags;
int error;
error = spi_sync(ts->spi, &ts->msg);
if (error) {
dev_err(&ts->spi->dev, "spi_sync --> %d\n", error);
goto out;
}
spin_lock_irqsave(&ts->lock, flags);
error = ad7877_process_data(ts);
if (!error)
mod_timer(&ts->timer, jiffies + TS_PEN_UP_TIMEOUT);
spin_unlock_irqrestore(&ts->lock, flags);
out:
return IRQ_HANDLED;
}
static void ad7877_disable(struct ad7877 *ts)
{
mutex_lock(&ts->mutex);
if (!ts->disabled) {
ts->disabled = true;
disable_irq(ts->spi->irq);
if (del_timer_sync(&ts->timer))
ad7877_ts_event_release(ts);
}
mutex_unlock(&ts->mutex);
}
static void ad7877_enable(struct ad7877 *ts)
{
mutex_lock(&ts->mutex);
if (ts->disabled) {
ts->disabled = false;
enable_irq(ts->spi->irq);
}
mutex_unlock(&ts->mutex);
}
static ssize_t ad7877_disable_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ad7877 *ts = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", ts->disabled);
}
static ssize_t ad7877_disable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ad7877 *ts = dev_get_drvdata(dev);
unsigned int val;
int error;
error = kstrtouint(buf, 10, &val);
if (error)
return error;
if (val)
ad7877_disable(ts);
else
ad7877_enable(ts);
return count;
}
static ssize_t ad7877_dac_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ad7877 *ts = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", ts->dac);
}
static ssize_t ad7877_dac_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ad7877 *ts = dev_get_drvdata(dev);
unsigned int val;
int error;
error = kstrtouint(buf, 10, &val);
if (error)
return error;
mutex_lock(&ts->mutex);
ts->dac = val & 0xFF;
ad7877_write(ts->spi, AD7877_REG_DAC, (ts->dac << 4) | AD7877_DAC_CONF);
mutex_unlock(&ts->mutex);
return count;
}
static ssize_t ad7877_gpio3_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ad7877 *ts = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", ts->gpio3);
}
static ssize_t ad7877_gpio3_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ad7877 *ts = dev_get_drvdata(dev);
unsigned int val;
int error;
error = kstrtouint(buf, 10, &val);
if (error)
return error;
mutex_lock(&ts->mutex);
ts->gpio3 = !!val;
ad7877_write(ts->spi, AD7877_REG_EXTWRITE, AD7877_EXTW_GPIO_DATA |
(ts->gpio4 << 4) | (ts->gpio3 << 5));
mutex_unlock(&ts->mutex);
return count;
}
static ssize_t ad7877_gpio4_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct ad7877 *ts = dev_get_drvdata(dev);
return sprintf(buf, "%u\n", ts->gpio4);
}
static ssize_t ad7877_gpio4_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ad7877 *ts = dev_get_drvdata(dev);
unsigned int val;
int error;
error = kstrtouint(buf, 10, &val);
if (error)
return error;
mutex_lock(&ts->mutex);
ts->gpio4 = !!val;
ad7877_write(ts->spi, AD7877_REG_EXTWRITE, AD7877_EXTW_GPIO_DATA |
(ts->gpio4 << 4) | (ts->gpio3 << 5));
mutex_unlock(&ts->mutex);
return count;
}
static umode_t ad7877_attr_is_visible(struct kobject *kobj,
struct attribute *attr, int n)
{
umode_t mode = attr->mode;
if (attr == &dev_attr_aux3.attr) {
if (gpio3)
mode = 0;
} else if (attr == &dev_attr_gpio3.attr) {
if (!gpio3)
mode = 0;
}
return mode;
}
static void ad7877_setup_ts_def_msg(struct spi_device *spi, struct ad7877 *ts)
{
struct spi_message *m;
int i;
ts->cmd_crtl2 = AD7877_WRITEADD(AD7877_REG_CTRL2) |
AD7877_POL(ts->stopacq_polarity) |
AD7877_AVG(ts->averaging) | AD7877_PM(1) |
AD7877_TMR(ts->pen_down_acc_interval) |
AD7877_ACQ(ts->acquisition_time) |
AD7877_FCD(ts->first_conversion_delay);
ad7877_write(spi, AD7877_REG_CTRL2, ts->cmd_crtl2);
ts->cmd_crtl1 = AD7877_WRITEADD(AD7877_REG_CTRL1) |
AD7877_READADD(AD7877_REG_XPLUS-1) |
AD7877_MODE_SEQ1 | AD7877_DFR;
ad7877_write(spi, AD7877_REG_CTRL1, ts->cmd_crtl1);
ts->cmd_dummy = 0;
m = &ts->msg;
spi_message_init(m);
m->context = ts;
ts->xfer[0].tx_buf = &ts->cmd_crtl1;
ts->xfer[0].len = 2;
ts->xfer[0].cs_change = 1;
spi_message_add_tail(&ts->xfer[0], m);
ts->xfer[1].tx_buf = &ts->cmd_dummy;
ts->xfer[1].len = 2;
ts->xfer[1].cs_change = 1;
spi_message_add_tail(&ts->xfer[1], m);
for (i = 0; i < AD7877_NR_SENSE; i++) {
ts->xfer[i + 2].rx_buf = &ts->conversion_data[AD7877_SEQ_YPOS + i];
ts->xfer[i + 2].len = 2;
if (i < (AD7877_NR_SENSE - 1))
ts->xfer[i + 2].cs_change = 1;
spi_message_add_tail(&ts->xfer[i + 2], m);
}
}
static int ad7877_probe(struct spi_device *spi)
{
struct ad7877 *ts;
struct input_dev *input_dev;
struct ad7877_platform_data *pdata = dev_get_platdata(&spi->dev);
int err;
u16 verify;
if (!spi->irq) {
dev_dbg(&spi->dev, "no IRQ?\n");
return -ENODEV;
}
if (!pdata) {
dev_dbg(&spi->dev, "no platform data?\n");
return -ENODEV;
}
if (spi->max_speed_hz > MAX_SPI_FREQ_HZ) {
dev_dbg(&spi->dev, "SPI CLK %d Hz?\n",spi->max_speed_hz);
return -EINVAL;
}
spi->bits_per_word = 16;
err = spi_setup(spi);
if (err) {
dev_dbg(&spi->dev, "spi master doesn't support 16 bits/word\n");
return err;
}
ts = kzalloc(sizeof(struct ad7877), GFP_KERNEL);
input_dev = input_allocate_device();
if (!ts || !input_dev) {
err = -ENOMEM;
goto err_free_mem;
}
spi_set_drvdata(spi, ts);
ts->spi = spi;
ts->input = input_dev;
setup_timer(&ts->timer, ad7877_timer, (unsigned long) ts);
mutex_init(&ts->mutex);
spin_lock_init(&ts->lock);
ts->model = pdata->model ? : 7877;
ts->vref_delay_usecs = pdata->vref_delay_usecs ? : 100;
ts->x_plate_ohms = pdata->x_plate_ohms ? : 400;
ts->pressure_max = pdata->pressure_max ? : ~0;
ts->stopacq_polarity = pdata->stopacq_polarity;
ts->first_conversion_delay = pdata->first_conversion_delay;
ts->acquisition_time = pdata->acquisition_time;
ts->averaging = pdata->averaging;
ts->pen_down_acc_interval = pdata->pen_down_acc_interval;
snprintf(ts->phys, sizeof(ts->phys), "%s/input0", dev_name(&spi->dev));
input_dev->name = "AD7877 Touchscreen";
input_dev->phys = ts->phys;
input_dev->dev.parent = &spi->dev;
__set_bit(EV_KEY, input_dev->evbit);
__set_bit(BTN_TOUCH, input_dev->keybit);
__set_bit(EV_ABS, input_dev->evbit);
__set_bit(ABS_X, input_dev->absbit);
__set_bit(ABS_Y, input_dev->absbit);
__set_bit(ABS_PRESSURE, input_dev->absbit);
input_set_abs_params(input_dev, ABS_X,
pdata->x_min ? : 0,
pdata->x_max ? : MAX_12BIT,
0, 0);
input_set_abs_params(input_dev, ABS_Y,
pdata->y_min ? : 0,
pdata->y_max ? : MAX_12BIT,
0, 0);
input_set_abs_params(input_dev, ABS_PRESSURE,
pdata->pressure_min, pdata->pressure_max, 0, 0);
ad7877_write(spi, AD7877_REG_SEQ1, AD7877_MM_SEQUENCE);
verify = ad7877_read(spi, AD7877_REG_SEQ1);
if (verify != AD7877_MM_SEQUENCE){
dev_err(&spi->dev, "%s: Failed to probe %s\n",
dev_name(&spi->dev), input_dev->name);
err = -ENODEV;
goto err_free_mem;
}
if (gpio3)
ad7877_write(spi, AD7877_REG_EXTWRITE, AD7877_EXTW_GPIO_3_CONF);
ad7877_setup_ts_def_msg(spi, ts);
err = request_threaded_irq(spi->irq, NULL, ad7877_irq,
IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
spi->dev.driver->name, ts);
if (err) {
dev_dbg(&spi->dev, "irq %d busy?\n", spi->irq);
goto err_free_mem;
}
err = sysfs_create_group(&spi->dev.kobj, &ad7877_attr_group);
if (err)
goto err_free_irq;
err = input_register_device(input_dev);
if (err)
goto err_remove_attr_group;
return 0;
err_remove_attr_group:
sysfs_remove_group(&spi->dev.kobj, &ad7877_attr_group);
err_free_irq:
free_irq(spi->irq, ts);
err_free_mem:
input_free_device(input_dev);
kfree(ts);
return err;
}
static int ad7877_remove(struct spi_device *spi)
{
struct ad7877 *ts = spi_get_drvdata(spi);
sysfs_remove_group(&spi->dev.kobj, &ad7877_attr_group);
ad7877_disable(ts);
free_irq(ts->spi->irq, ts);
input_unregister_device(ts->input);
kfree(ts);
dev_dbg(&spi->dev, "unregistered touchscreen\n");
return 0;
}
static int __maybe_unused ad7877_suspend(struct device *dev)
{
struct ad7877 *ts = dev_get_drvdata(dev);
ad7877_disable(ts);
return 0;
}
static int __maybe_unused ad7877_resume(struct device *dev)
{
struct ad7877 *ts = dev_get_drvdata(dev);
ad7877_enable(ts);
return 0;
}
