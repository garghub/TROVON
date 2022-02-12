static void dht11_edges_print(struct dht11 *dht11)
{
int i;
dev_dbg(dht11->dev, "%d edges detected:\n", dht11->num_edges);
for (i = 1; i < dht11->num_edges; ++i) {
dev_dbg(dht11->dev, "%d: %lld ns %s\n", i,
dht11->edges[i].ts - dht11->edges[i - 1].ts,
dht11->edges[i - 1].value ? "high" : "low");
}
}
static unsigned char dht11_decode_byte(char *bits)
{
unsigned char ret = 0;
int i;
for (i = 0; i < 8; ++i) {
ret <<= 1;
if (bits[i])
++ret;
}
return ret;
}
static int dht11_decode(struct dht11 *dht11, int offset)
{
int i, t;
char bits[DHT11_BITS_PER_READ];
unsigned char temp_int, temp_dec, hum_int, hum_dec, checksum;
for (i = 0; i < DHT11_BITS_PER_READ; ++i) {
t = dht11->edges[offset + 2 * i + 2].ts -
dht11->edges[offset + 2 * i + 1].ts;
if (!dht11->edges[offset + 2 * i + 1].value) {
dev_dbg(dht11->dev,
"lost synchronisation at edge %d\n",
offset + 2 * i + 1);
return -EIO;
}
bits[i] = t > DHT11_THRESHOLD;
}
hum_int = dht11_decode_byte(bits);
hum_dec = dht11_decode_byte(&bits[8]);
temp_int = dht11_decode_byte(&bits[16]);
temp_dec = dht11_decode_byte(&bits[24]);
checksum = dht11_decode_byte(&bits[32]);
if (((hum_int + hum_dec + temp_int + temp_dec) & 0xff) != checksum) {
dev_dbg(dht11->dev, "invalid checksum\n");
return -EIO;
}
dht11->timestamp = ktime_get_boot_ns();
if (hum_int < 20) {
dht11->temperature = (((temp_int & 0x7f) << 8) + temp_dec) *
((temp_int & 0x80) ? -100 : 100);
dht11->humidity = ((hum_int << 8) + hum_dec) * 100;
} else if (temp_dec == 0 && hum_dec == 0) {
dht11->temperature = temp_int * 1000;
dht11->humidity = hum_int * 1000;
} else {
dev_err(dht11->dev,
"Don't know how to decode data: %d %d %d %d\n",
hum_int, hum_dec, temp_int, temp_dec);
return -EIO;
}
return 0;
}
static irqreturn_t dht11_handle_irq(int irq, void *data)
{
struct iio_dev *iio = data;
struct dht11 *dht11 = iio_priv(iio);
if (dht11->num_edges < DHT11_EDGES_PER_READ && dht11->num_edges >= 0) {
dht11->edges[dht11->num_edges].ts = ktime_get_boot_ns();
dht11->edges[dht11->num_edges++].value =
gpio_get_value(dht11->gpio);
if (dht11->num_edges >= DHT11_EDGES_PER_READ)
complete(&dht11->completion);
}
return IRQ_HANDLED;
}
static int dht11_read_raw(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long m)
{
struct dht11 *dht11 = iio_priv(iio_dev);
int ret, timeres, offset;
mutex_lock(&dht11->lock);
if (dht11->timestamp + DHT11_DATA_VALID_TIME < ktime_get_boot_ns()) {
timeres = ktime_get_resolution_ns();
dev_dbg(dht11->dev, "current timeresolution: %dns\n", timeres);
if (timeres > DHT11_MIN_TIMERES) {
dev_err(dht11->dev, "timeresolution %dns too low\n",
timeres);
ret = -EAGAIN;
goto err;
}
if (timeres > DHT11_AMBIG_LOW && timeres < DHT11_AMBIG_HIGH)
dev_warn(dht11->dev,
"timeresolution: %dns - decoding ambiguous\n",
timeres);
reinit_completion(&dht11->completion);
dht11->num_edges = 0;
ret = gpio_direction_output(dht11->gpio, 0);
if (ret)
goto err;
usleep_range(DHT11_START_TRANSMISSION_MIN,
DHT11_START_TRANSMISSION_MAX);
ret = gpio_direction_input(dht11->gpio);
if (ret)
goto err;
ret = request_irq(dht11->irq, dht11_handle_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
iio_dev->name, iio_dev);
if (ret)
goto err;
ret = wait_for_completion_killable_timeout(&dht11->completion,
HZ);
free_irq(dht11->irq, iio_dev);
#ifdef CONFIG_DYNAMIC_DEBUG
dht11_edges_print(dht11);
#endif
if (ret == 0 && dht11->num_edges < DHT11_EDGES_PER_READ - 1) {
dev_err(dht11->dev, "Only %d signal edges detected\n",
dht11->num_edges);
ret = -ETIMEDOUT;
}
if (ret < 0)
goto err;
offset = DHT11_EDGES_PREAMBLE +
dht11->num_edges - DHT11_EDGES_PER_READ;
for (; offset >= 0; --offset) {
ret = dht11_decode(dht11, offset);
if (!ret)
break;
}
if (ret)
goto err;
}
ret = IIO_VAL_INT;
if (chan->type == IIO_TEMP)
*val = dht11->temperature;
else if (chan->type == IIO_HUMIDITYRELATIVE)
*val = dht11->humidity;
else
ret = -EINVAL;
err:
dht11->num_edges = -1;
mutex_unlock(&dht11->lock);
return ret;
}
static int dht11_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct device_node *node = dev->of_node;
struct dht11 *dht11;
struct iio_dev *iio;
int ret;
iio = devm_iio_device_alloc(dev, sizeof(*dht11));
if (!iio) {
dev_err(dev, "Failed to allocate IIO device\n");
return -ENOMEM;
}
dht11 = iio_priv(iio);
dht11->dev = dev;
ret = of_get_gpio(node, 0);
if (ret < 0)
return ret;
dht11->gpio = ret;
ret = devm_gpio_request_one(dev, dht11->gpio, GPIOF_IN, pdev->name);
if (ret)
return ret;
dht11->irq = gpio_to_irq(dht11->gpio);
if (dht11->irq < 0) {
dev_err(dev, "GPIO %d has no interrupt\n", dht11->gpio);
return -EINVAL;
}
dht11->timestamp = ktime_get_boot_ns() - DHT11_DATA_VALID_TIME - 1;
dht11->num_edges = -1;
platform_set_drvdata(pdev, iio);
init_completion(&dht11->completion);
mutex_init(&dht11->lock);
iio->name = pdev->name;
iio->dev.parent = &pdev->dev;
iio->info = &dht11_iio_info;
iio->modes = INDIO_DIRECT_MODE;
iio->channels = dht11_chan_spec;
iio->num_channels = ARRAY_SIZE(dht11_chan_spec);
return devm_iio_device_register(dev, iio);
}
