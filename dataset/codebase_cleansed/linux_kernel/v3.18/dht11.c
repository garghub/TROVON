static unsigned char dht11_decode_byte(int *timing, int threshold)
{
unsigned char ret = 0;
int i;
for (i = 0; i < 8; ++i) {
ret <<= 1;
if (timing[i] >= threshold)
++ret;
}
return ret;
}
static int dht11_decode(struct dht11 *dht11, int offset)
{
int i, t, timing[DHT11_BITS_PER_READ], threshold,
timeres = DHT11_SENSOR_RESPONSE;
unsigned char temp_int, temp_dec, hum_int, hum_dec, checksum;
for (i = 0; i < dht11->num_edges; ++i) {
t = dht11->edges[i].ts - dht11->edges[i-1].ts;
if (t > 0 && t < timeres)
timeres = t;
}
if (2*timeres > DHT11_DATA_BIT_HIGH) {
pr_err("dht11: timeresolution %d too bad for decoding\n",
timeres);
return -EIO;
}
threshold = DHT11_DATA_BIT_HIGH / timeres;
if (DHT11_DATA_BIT_LOW/timeres + 1 >= threshold)
pr_err("dht11: WARNING: decoding ambiguous\n");
for (i = 0; i < DHT11_BITS_PER_READ; ++i) {
t = dht11->edges[offset + 2*i + 2].ts -
dht11->edges[offset + 2*i + 1].ts;
if (!dht11->edges[offset + 2*i + 1].value)
return -EIO;
timing[i] = t / timeres;
}
hum_int = dht11_decode_byte(timing, threshold);
hum_dec = dht11_decode_byte(&timing[8], threshold);
temp_int = dht11_decode_byte(&timing[16], threshold);
temp_dec = dht11_decode_byte(&timing[24], threshold);
checksum = dht11_decode_byte(&timing[32], threshold);
if (((hum_int + hum_dec + temp_int + temp_dec) & 0xff) != checksum)
return -EIO;
dht11->timestamp = iio_get_time_ns();
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
static int dht11_read_raw(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long m)
{
struct dht11 *dht11 = iio_priv(iio_dev);
int ret;
if (dht11->timestamp + DHT11_DATA_VALID_TIME < iio_get_time_ns()) {
reinit_completion(&dht11->completion);
dht11->num_edges = 0;
ret = gpio_direction_output(dht11->gpio, 0);
if (ret)
goto err;
msleep(DHT11_START_TRANSMISSION);
ret = gpio_direction_input(dht11->gpio);
if (ret)
goto err;
ret = wait_for_completion_killable_timeout(&dht11->completion,
HZ);
if (ret == 0 && dht11->num_edges < DHT11_EDGES_PER_READ - 1) {
dev_err(&iio_dev->dev,
"Only %d signal edges detected\n",
dht11->num_edges);
ret = -ETIMEDOUT;
}
if (ret < 0)
goto err;
ret = dht11_decode(dht11,
dht11->num_edges == DHT11_EDGES_PER_READ ?
DHT11_EDGES_PREAMBLE :
DHT11_EDGES_PREAMBLE - 2);
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
return ret;
}
static irqreturn_t dht11_handle_irq(int irq, void *data)
{
struct iio_dev *iio = data;
struct dht11 *dht11 = iio_priv(iio);
if (dht11->num_edges < DHT11_EDGES_PER_READ && dht11->num_edges >= 0) {
dht11->edges[dht11->num_edges].ts = iio_get_time_ns();
dht11->edges[dht11->num_edges++].value =
gpio_get_value(dht11->gpio);
if (dht11->num_edges >= DHT11_EDGES_PER_READ)
complete(&dht11->completion);
}
return IRQ_HANDLED;
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
dht11->gpio = ret = of_get_gpio(node, 0);
if (ret < 0)
return ret;
ret = devm_gpio_request_one(dev, dht11->gpio, GPIOF_IN, pdev->name);
if (ret)
return ret;
dht11->irq = gpio_to_irq(dht11->gpio);
if (dht11->irq < 0) {
dev_err(dev, "GPIO %d has no interrupt\n", dht11->gpio);
return -EINVAL;
}
ret = devm_request_irq(dev, dht11->irq, dht11_handle_irq,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING,
pdev->name, iio);
if (ret)
return ret;
dht11->timestamp = iio_get_time_ns() - DHT11_DATA_VALID_TIME - 1;
dht11->num_edges = -1;
platform_set_drvdata(pdev, iio);
init_completion(&dht11->completion);
iio->name = pdev->name;
iio->dev.parent = &pdev->dev;
iio->info = &dht11_iio_info;
iio->modes = INDIO_DIRECT_MODE;
iio->channels = dht11_chan_spec;
iio->num_channels = ARRAY_SIZE(dht11_chan_spec);
return devm_iio_device_register(dev, iio);
}
