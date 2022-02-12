static int berlin2_adc_read(struct iio_dev *indio_dev, int channel)
{
struct berlin2_adc_priv *priv = iio_priv(indio_dev);
int data, ret;
mutex_lock(&priv->lock);
regmap_update_bits(priv->regmap, BERLIN2_SM_CTRL,
BERLIN2_SM_CTRL_ADC_RESET | BERLIN2_SM_CTRL_ADC_SEL_MASK
| BERLIN2_SM_CTRL_ADC_START,
BERLIN2_SM_CTRL_ADC_SEL(channel) | BERLIN2_SM_CTRL_ADC_START);
ret = wait_event_interruptible_timeout(priv->wq, priv->data_available,
msecs_to_jiffies(1000));
regmap_update_bits(priv->regmap, BERLIN2_SM_ADC_STATUS,
BERLIN2_SM_ADC_STATUS_INT_EN(channel), 0);
if (ret == 0)
ret = -ETIMEDOUT;
if (ret < 0) {
mutex_unlock(&priv->lock);
return ret;
}
regmap_update_bits(priv->regmap, BERLIN2_SM_CTRL,
BERLIN2_SM_CTRL_ADC_START, 0);
data = priv->data;
priv->data_available = false;
mutex_unlock(&priv->lock);
return data;
}
static int berlin2_adc_tsen_read(struct iio_dev *indio_dev)
{
struct berlin2_adc_priv *priv = iio_priv(indio_dev);
int data, ret;
mutex_lock(&priv->lock);
regmap_update_bits(priv->regmap, BERLIN2_SM_CTRL,
BERLIN2_SM_CTRL_TSEN_RESET | BERLIN2_SM_CTRL_ADC_ROTATE,
BERLIN2_SM_CTRL_ADC_ROTATE);
regmap_update_bits(priv->regmap, BERLIN2_SM_TSEN_CTRL,
BERLIN2_SM_TSEN_CTRL_TRIM_MASK | BERLIN2_SM_TSEN_CTRL_SETTLING_MASK
| BERLIN2_SM_TSEN_CTRL_START,
BERLIN2_SM_TSEN_CTRL_TRIM(3) | BERLIN2_SM_TSEN_CTRL_SETTLING_12
| BERLIN2_SM_TSEN_CTRL_START);
ret = wait_event_interruptible_timeout(priv->wq, priv->data_available,
msecs_to_jiffies(1000));
regmap_update_bits(priv->regmap, BERLIN2_SM_TSEN_STATUS,
BERLIN2_SM_TSEN_STATUS_INT_EN, 0);
if (ret == 0)
ret = -ETIMEDOUT;
if (ret < 0) {
mutex_unlock(&priv->lock);
return ret;
}
regmap_update_bits(priv->regmap, BERLIN2_SM_TSEN_CTRL,
BERLIN2_SM_TSEN_CTRL_START, 0);
data = priv->data;
priv->data_available = false;
mutex_unlock(&priv->lock);
return data;
}
static int berlin2_adc_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan, int *val, int *val2,
long mask)
{
struct berlin2_adc_priv *priv = iio_priv(indio_dev);
int temp;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (chan->type != IIO_VOLTAGE)
return -EINVAL;
regmap_write(priv->regmap, BERLIN2_SM_ADC_STATUS,
BERLIN2_SM_ADC_STATUS_INT_EN(chan->channel));
*val = berlin2_adc_read(indio_dev, chan->channel);
if (*val < 0)
return *val;
return IIO_VAL_INT;
case IIO_CHAN_INFO_PROCESSED:
if (chan->type != IIO_TEMP)
return -EINVAL;
regmap_write(priv->regmap, BERLIN2_SM_TSEN_STATUS,
BERLIN2_SM_TSEN_STATUS_INT_EN);
temp = berlin2_adc_tsen_read(indio_dev);
if (temp < 0)
return temp;
if (temp > 2047)
temp = -(4096 - temp);
*val = ((temp * 100000) / 264 - 270000);
return IIO_VAL_INT;
default:
break;
}
return -EINVAL;
}
static irqreturn_t berlin2_adc_irq(int irq, void *private)
{
struct berlin2_adc_priv *priv = iio_priv(private);
unsigned val;
regmap_read(priv->regmap, BERLIN2_SM_ADC_STATUS, &val);
if (val & BERLIN2_SM_ADC_STATUS_DATA_RDY_MASK) {
regmap_read(priv->regmap, BERLIN2_SM_ADC_DATA, &priv->data);
priv->data &= BERLIN2_SM_ADC_MASK;
val &= ~BERLIN2_SM_ADC_STATUS_DATA_RDY_MASK;
regmap_write(priv->regmap, BERLIN2_SM_ADC_STATUS, val);
priv->data_available = true;
wake_up_interruptible(&priv->wq);
}
return IRQ_HANDLED;
}
static irqreturn_t berlin2_adc_tsen_irq(int irq, void *private)
{
struct berlin2_adc_priv *priv = iio_priv(private);
unsigned val;
regmap_read(priv->regmap, BERLIN2_SM_TSEN_STATUS, &val);
if (val & BERLIN2_SM_TSEN_STATUS_DATA_RDY) {
regmap_read(priv->regmap, BERLIN2_SM_TSEN_DATA, &priv->data);
priv->data &= BERLIN2_SM_TSEN_MASK;
val &= ~BERLIN2_SM_TSEN_STATUS_DATA_RDY;
regmap_write(priv->regmap, BERLIN2_SM_TSEN_STATUS, val);
priv->data_available = true;
wake_up_interruptible(&priv->wq);
}
return IRQ_HANDLED;
}
static int berlin2_adc_probe(struct platform_device *pdev)
{
struct iio_dev *indio_dev;
struct berlin2_adc_priv *priv;
struct device_node *parent_np = of_get_parent(pdev->dev.of_node);
int irq, tsen_irq;
int ret;
indio_dev = devm_iio_device_alloc(&pdev->dev,
sizeof(struct berlin2_adc_priv));
if (!indio_dev)
return -ENOMEM;
priv = iio_priv(indio_dev);
platform_set_drvdata(pdev, indio_dev);
priv->regmap = syscon_node_to_regmap(parent_np);
of_node_put(parent_np);
if (IS_ERR(priv->regmap))
return PTR_ERR(priv->regmap);
irq = platform_get_irq_byname(pdev, "adc");
if (irq < 0)
return -ENODEV;
tsen_irq = platform_get_irq_byname(pdev, "tsen");
if (tsen_irq < 0)
return -ENODEV;
ret = devm_request_irq(&pdev->dev, irq, berlin2_adc_irq, 0,
pdev->dev.driver->name, indio_dev);
if (ret)
return ret;
ret = devm_request_irq(&pdev->dev, tsen_irq, berlin2_adc_tsen_irq,
0, pdev->dev.driver->name, indio_dev);
if (ret)
return ret;
init_waitqueue_head(&priv->wq);
mutex_init(&priv->lock);
indio_dev->dev.parent = &pdev->dev;
indio_dev->name = dev_name(&pdev->dev);
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &berlin2_adc_info;
indio_dev->num_channels = BERLIN2_N_CHANNELS;
indio_dev->channels = berlin2_adc_channels;
regmap_update_bits(priv->regmap, BERLIN2_SM_CTRL,
BERLIN2_SM_CTRL_ADC_POWER, BERLIN2_SM_CTRL_ADC_POWER);
ret = iio_device_register(indio_dev);
if (ret) {
regmap_update_bits(priv->regmap, BERLIN2_SM_CTRL,
BERLIN2_SM_CTRL_ADC_POWER, 0);
return ret;
}
return 0;
}
static int berlin2_adc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
struct berlin2_adc_priv *priv = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
regmap_update_bits(priv->regmap, BERLIN2_SM_CTRL,
BERLIN2_SM_CTRL_ADC_POWER, 0);
return 0;
}
