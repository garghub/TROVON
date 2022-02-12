static irqreturn_t srf04_handle_irq(int irq, void *dev_id)
{
struct iio_dev *indio_dev = dev_id;
struct srf04_data *data = iio_priv(indio_dev);
ktime_t now = ktime_get();
if (gpiod_get_value(data->gpiod_echo)) {
data->ts_rising = now;
complete(&data->rising);
} else {
data->ts_falling = now;
complete(&data->falling);
}
return IRQ_HANDLED;
}
static int srf04_read(struct srf04_data *data)
{
int ret;
ktime_t ktime_dt;
u64 dt_ns;
u32 time_ns, distance_mm;
mutex_lock(&data->lock);
reinit_completion(&data->rising);
reinit_completion(&data->falling);
gpiod_set_value(data->gpiod_trig, 1);
udelay(10);
gpiod_set_value(data->gpiod_trig, 0);
ret = wait_for_completion_killable_timeout(&data->rising, HZ/50);
if (ret < 0) {
mutex_unlock(&data->lock);
return ret;
} else if (ret == 0) {
mutex_unlock(&data->lock);
return -ETIMEDOUT;
}
ret = wait_for_completion_killable_timeout(&data->falling, HZ/50);
if (ret < 0) {
mutex_unlock(&data->lock);
return ret;
} else if (ret == 0) {
mutex_unlock(&data->lock);
return -ETIMEDOUT;
}
ktime_dt = ktime_sub(data->ts_falling, data->ts_rising);
mutex_unlock(&data->lock);
dt_ns = ktime_to_ns(ktime_dt);
if (dt_ns > 9404389)
return -EIO;
time_ns = dt_ns;
distance_mm = time_ns * 343 / 2000000;
return distance_mm;
}
static int srf04_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *channel, int *val,
int *val2, long info)
{
struct srf04_data *data = iio_priv(indio_dev);
int ret;
if (channel->type != IIO_DISTANCE)
return -EINVAL;
switch (info) {
case IIO_CHAN_INFO_RAW:
ret = srf04_read(data);
if (ret < 0)
return ret;
*val = ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
*val2 = 1000;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int srf04_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct srf04_data *data;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(struct srf04_data));
if (!indio_dev) {
dev_err(dev, "failed to allocate IIO device\n");
return -ENOMEM;
}
data = iio_priv(indio_dev);
data->dev = dev;
mutex_init(&data->lock);
init_completion(&data->rising);
init_completion(&data->falling);
data->gpiod_trig = devm_gpiod_get(dev, "trig", GPIOD_OUT_LOW);
if (IS_ERR(data->gpiod_trig)) {
dev_err(dev, "failed to get trig-gpios: err=%ld\n",
PTR_ERR(data->gpiod_trig));
return PTR_ERR(data->gpiod_trig);
}
data->gpiod_echo = devm_gpiod_get(dev, "echo", GPIOD_IN);
if (IS_ERR(data->gpiod_echo)) {
dev_err(dev, "failed to get echo-gpios: err=%ld\n",
PTR_ERR(data->gpiod_echo));
return PTR_ERR(data->gpiod_echo);
}
if (gpiod_cansleep(data->gpiod_echo)) {
dev_err(data->dev, "cansleep-GPIOs not supported\n");
return -ENODEV;
}
data->irqnr = gpiod_to_irq(data->gpiod_echo);
if (data->irqnr < 0) {
dev_err(data->dev, "gpiod_to_irq: %d\n", data->irqnr);
return data->irqnr;
}
ret = devm_request_irq(dev, data->irqnr, srf04_handle_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
pdev->name, indio_dev);
if (ret < 0) {
dev_err(data->dev, "request_irq: %d\n", ret);
return ret;
}
platform_set_drvdata(pdev, indio_dev);
indio_dev->name = "srf04";
indio_dev->dev.parent = &pdev->dev;
indio_dev->info = &srf04_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = srf04_chan_spec;
indio_dev->num_channels = ARRAY_SIZE(srf04_chan_spec);
return devm_iio_device_register(dev, indio_dev);
}
