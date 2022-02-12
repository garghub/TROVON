static int envelope_detector_comp_latch(struct envelope *env)
{
int comp;
spin_lock_irq(&env->comp_lock);
comp = env->comp;
env->comp = 0;
spin_unlock_irq(&env->comp_lock);
if (!comp)
return 0;
enable_irq(env->comp_irq);
synchronize_irq(env->comp_irq);
spin_lock_irq(&env->comp_lock);
comp = env->comp;
env->comp = 0;
spin_unlock_irq(&env->comp_lock);
if (comp)
enable_irq(env->comp_irq);
return 1;
}
static irqreturn_t envelope_detector_comp_isr(int irq, void *ctx)
{
struct envelope *env = ctx;
spin_lock(&env->comp_lock);
env->comp = 1;
disable_irq_nosync(env->comp_irq);
spin_unlock(&env->comp_lock);
return IRQ_HANDLED;
}
static void envelope_detector_setup_compare(struct envelope *env)
{
int ret;
env->level = (env->high + env->low + !env->invert) / 2;
if (env->high == env->low + 1) {
complete(&env->done);
return;
}
ret = iio_write_channel_raw(env->dac, env->invert ? 0 : env->dac_max);
if (ret < 0)
goto err;
envelope_detector_comp_latch(env);
ret = iio_write_channel_raw(env->dac, env->level);
if (ret < 0)
goto err;
schedule_delayed_work(&env->comp_timeout,
msecs_to_jiffies(env->comp_interval));
return;
err:
env->level = ret;
complete(&env->done);
}
static void envelope_detector_timeout(struct work_struct *work)
{
struct envelope *env = container_of(work, struct envelope,
comp_timeout.work);
if (!envelope_detector_comp_latch(env) ^ !env->invert)
env->low = env->level;
else
env->high = env->level;
envelope_detector_setup_compare(env);
}
static int envelope_detector_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct envelope *env = iio_priv(indio_dev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&env->read_lock);
env->high = env->dac_max + env->invert;
env->low = -1 + env->invert;
envelope_detector_setup_compare(env);
wait_for_completion(&env->done);
if (env->level < 0) {
ret = env->level;
goto err_unlock;
}
*val = env->invert ? env->dac_max - env->level : env->level;
mutex_unlock(&env->read_lock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
return iio_read_channel_scale(env->dac, val, val2);
}
return -EINVAL;
err_unlock:
mutex_unlock(&env->read_lock);
return ret;
}
static ssize_t envelope_show_invert(struct iio_dev *indio_dev,
uintptr_t private,
struct iio_chan_spec const *ch, char *buf)
{
struct envelope *env = iio_priv(indio_dev);
return sprintf(buf, "%u\n", env->invert);
}
static ssize_t envelope_store_invert(struct iio_dev *indio_dev,
uintptr_t private,
struct iio_chan_spec const *ch,
const char *buf, size_t len)
{
struct envelope *env = iio_priv(indio_dev);
unsigned long invert;
int ret;
u32 trigger;
ret = kstrtoul(buf, 0, &invert);
if (ret < 0)
return ret;
if (invert > 1)
return -EINVAL;
trigger = invert ? env->comp_irq_trigger_inv : env->comp_irq_trigger;
mutex_lock(&env->read_lock);
if (invert != env->invert)
ret = irq_set_irq_type(env->comp_irq, trigger);
if (!ret) {
env->invert = invert;
ret = len;
}
mutex_unlock(&env->read_lock);
return ret;
}
static ssize_t envelope_show_comp_interval(struct iio_dev *indio_dev,
uintptr_t private,
struct iio_chan_spec const *ch,
char *buf)
{
struct envelope *env = iio_priv(indio_dev);
return sprintf(buf, "%u\n", env->comp_interval);
}
static ssize_t envelope_store_comp_interval(struct iio_dev *indio_dev,
uintptr_t private,
struct iio_chan_spec const *ch,
const char *buf, size_t len)
{
struct envelope *env = iio_priv(indio_dev);
unsigned long interval;
int ret;
ret = kstrtoul(buf, 0, &interval);
if (ret < 0)
return ret;
if (interval > 1000)
return -EINVAL;
mutex_lock(&env->read_lock);
env->comp_interval = interval;
mutex_unlock(&env->read_lock);
return len;
}
static int envelope_detector_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct iio_dev *indio_dev;
struct envelope *env;
enum iio_chan_type type;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*env));
if (!indio_dev)
return -ENOMEM;
platform_set_drvdata(pdev, indio_dev);
env = iio_priv(indio_dev);
env->comp_interval = 50;
spin_lock_init(&env->comp_lock);
mutex_init(&env->read_lock);
init_completion(&env->done);
INIT_DELAYED_WORK(&env->comp_timeout, envelope_detector_timeout);
indio_dev->name = dev_name(dev);
indio_dev->dev.parent = dev;
indio_dev->dev.of_node = dev->of_node;
indio_dev->info = &envelope_detector_info;
indio_dev->channels = &envelope_detector_iio_channel;
indio_dev->num_channels = 1;
env->dac = devm_iio_channel_get(dev, "dac");
if (IS_ERR(env->dac)) {
if (PTR_ERR(env->dac) != -EPROBE_DEFER)
dev_err(dev, "failed to get dac input channel\n");
return PTR_ERR(env->dac);
}
env->comp_irq = platform_get_irq_byname(pdev, "comp");
if (env->comp_irq < 0) {
if (env->comp_irq != -EPROBE_DEFER)
dev_err(dev, "failed to get compare interrupt\n");
return env->comp_irq;
}
ret = devm_request_irq(dev, env->comp_irq, envelope_detector_comp_isr,
0, "envelope-detector", env);
if (ret) {
if (ret != -EPROBE_DEFER)
dev_err(dev, "failed to request interrupt\n");
return ret;
}
env->comp_irq_trigger = irq_get_trigger_type(env->comp_irq);
if (env->comp_irq_trigger & IRQF_TRIGGER_RISING)
env->comp_irq_trigger_inv |= IRQF_TRIGGER_FALLING;
if (env->comp_irq_trigger & IRQF_TRIGGER_FALLING)
env->comp_irq_trigger_inv |= IRQF_TRIGGER_RISING;
if (env->comp_irq_trigger & IRQF_TRIGGER_HIGH)
env->comp_irq_trigger_inv |= IRQF_TRIGGER_LOW;
if (env->comp_irq_trigger & IRQF_TRIGGER_LOW)
env->comp_irq_trigger_inv |= IRQF_TRIGGER_HIGH;
ret = iio_get_channel_type(env->dac, &type);
if (ret < 0)
return ret;
if (type != IIO_VOLTAGE) {
dev_err(dev, "dac is of the wrong type\n");
return -EINVAL;
}
ret = iio_read_max_channel_raw(env->dac, &env->dac_max);
if (ret < 0) {
dev_err(dev, "dac does not indicate its raw maximum value\n");
return ret;
}
return devm_iio_device_register(dev, indio_dev);
}
