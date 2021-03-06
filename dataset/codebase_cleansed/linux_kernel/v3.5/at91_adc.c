static irqreturn_t at91_adc_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *idev = pf->indio_dev;
struct at91_adc_state *st = iio_priv(idev);
struct iio_buffer *buffer = idev->buffer;
int i, j = 0;
for (i = 0; i < idev->masklength; i++) {
if (!test_bit(i, idev->active_scan_mask))
continue;
st->buffer[j] = at91_adc_readl(st, AT91_ADC_CHAN(st, i));
j++;
}
if (idev->scan_timestamp) {
s64 *timestamp = (s64 *)((u8 *)st->buffer +
ALIGN(j, sizeof(s64)));
*timestamp = pf->timestamp;
}
buffer->access->store_to(buffer, (u8 *)st->buffer, pf->timestamp);
iio_trigger_notify_done(idev->trig);
st->irq_enabled = true;
at91_adc_readl(st, AT91_ADC_LCDR);
enable_irq(st->irq);
return IRQ_HANDLED;
}
static irqreturn_t at91_adc_eoc_trigger(int irq, void *private)
{
struct iio_dev *idev = private;
struct at91_adc_state *st = iio_priv(idev);
u32 status = at91_adc_readl(st, st->registers->status_register);
if (!(status & st->registers->drdy_mask))
return IRQ_HANDLED;
if (iio_buffer_enabled(idev)) {
disable_irq_nosync(irq);
st->irq_enabled = false;
iio_trigger_poll(idev->trig, iio_get_time_ns());
} else {
st->last_value = at91_adc_readl(st, AT91_ADC_LCDR);
st->done = true;
wake_up_interruptible(&st->wq_data_avail);
}
return IRQ_HANDLED;
}
static int at91_adc_channel_init(struct iio_dev *idev)
{
struct at91_adc_state *st = iio_priv(idev);
struct iio_chan_spec *chan_array, *timestamp;
int bit, idx = 0;
idev->num_channels = bitmap_weight(&st->channels_mask,
st->num_channels) + 1;
chan_array = devm_kzalloc(&idev->dev,
((idev->num_channels + 1) *
sizeof(struct iio_chan_spec)),
GFP_KERNEL);
if (!chan_array)
return -ENOMEM;
for_each_set_bit(bit, &st->channels_mask, st->num_channels) {
struct iio_chan_spec *chan = chan_array + idx;
chan->type = IIO_VOLTAGE;
chan->indexed = 1;
chan->channel = bit;
chan->scan_index = idx;
chan->scan_type.sign = 'u';
chan->scan_type.realbits = 10;
chan->scan_type.storagebits = 16;
chan->info_mask = IIO_CHAN_INFO_SCALE_SHARED_BIT |
IIO_CHAN_INFO_RAW_SEPARATE_BIT;
idx++;
}
timestamp = chan_array + idx;
timestamp->type = IIO_TIMESTAMP;
timestamp->channel = -1;
timestamp->scan_index = idx;
timestamp->scan_type.sign = 's';
timestamp->scan_type.realbits = 64;
timestamp->scan_type.storagebits = 64;
idev->channels = chan_array;
return idev->num_channels;
}
static u8 at91_adc_get_trigger_value_by_name(struct iio_dev *idev,
struct at91_adc_trigger *triggers,
const char *trigger_name)
{
struct at91_adc_state *st = iio_priv(idev);
u8 value = 0;
int i;
for (i = 0; i < st->trigger_number; i++) {
char *name = kasprintf(GFP_KERNEL,
"%s-dev%d-%s",
idev->name,
idev->id,
triggers[i].name);
if (!name)
return -ENOMEM;
if (strcmp(trigger_name, name) == 0) {
value = triggers[i].value;
kfree(name);
break;
}
kfree(name);
}
return value;
}
static int at91_adc_configure_trigger(struct iio_trigger *trig, bool state)
{
struct iio_dev *idev = trig->private_data;
struct at91_adc_state *st = iio_priv(idev);
struct iio_buffer *buffer = idev->buffer;
struct at91_adc_reg_desc *reg = st->registers;
u32 status = at91_adc_readl(st, reg->trigger_register);
u8 value;
u8 bit;
value = at91_adc_get_trigger_value_by_name(idev,
st->trigger_list,
idev->trig->name);
if (value == 0)
return -EINVAL;
if (state) {
st->buffer = kmalloc(idev->scan_bytes, GFP_KERNEL);
if (st->buffer == NULL)
return -ENOMEM;
at91_adc_writel(st, reg->trigger_register,
status | value);
for_each_set_bit(bit, buffer->scan_mask,
st->num_channels) {
struct iio_chan_spec const *chan = idev->channels + bit;
at91_adc_writel(st, AT91_ADC_CHER,
AT91_ADC_CH(chan->channel));
}
at91_adc_writel(st, AT91_ADC_IER, reg->drdy_mask);
} else {
at91_adc_writel(st, AT91_ADC_IDR, reg->drdy_mask);
at91_adc_writel(st, reg->trigger_register,
status & ~value);
for_each_set_bit(bit, buffer->scan_mask,
st->num_channels) {
struct iio_chan_spec const *chan = idev->channels + bit;
at91_adc_writel(st, AT91_ADC_CHDR,
AT91_ADC_CH(chan->channel));
}
kfree(st->buffer);
}
return 0;
}
static struct iio_trigger *at91_adc_allocate_trigger(struct iio_dev *idev,
struct at91_adc_trigger *trigger)
{
struct iio_trigger *trig;
int ret;
trig = iio_trigger_alloc("%s-dev%d-%s", idev->name,
idev->id, trigger->name);
if (trig == NULL)
return NULL;
trig->dev.parent = idev->dev.parent;
trig->private_data = idev;
trig->ops = &at91_adc_trigger_ops;
ret = iio_trigger_register(trig);
if (ret)
return NULL;
return trig;
}
static int at91_adc_trigger_init(struct iio_dev *idev)
{
struct at91_adc_state *st = iio_priv(idev);
int i, ret;
st->trig = devm_kzalloc(&idev->dev,
st->trigger_number * sizeof(st->trig),
GFP_KERNEL);
if (st->trig == NULL) {
ret = -ENOMEM;
goto error_ret;
}
for (i = 0; i < st->trigger_number; i++) {
if (st->trigger_list[i].is_external && !(st->use_external))
continue;
st->trig[i] = at91_adc_allocate_trigger(idev,
st->trigger_list + i);
if (st->trig[i] == NULL) {
dev_err(&idev->dev,
"Could not allocate trigger %d\n", i);
ret = -ENOMEM;
goto error_trigger;
}
}
return 0;
error_trigger:
for (i--; i >= 0; i--) {
iio_trigger_unregister(st->trig[i]);
iio_trigger_free(st->trig[i]);
}
error_ret:
return ret;
}
static void at91_adc_trigger_remove(struct iio_dev *idev)
{
struct at91_adc_state *st = iio_priv(idev);
int i;
for (i = 0; i < st->trigger_number; i++) {
iio_trigger_unregister(st->trig[i]);
iio_trigger_free(st->trig[i]);
}
}
static int at91_adc_buffer_init(struct iio_dev *idev)
{
int ret;
idev->buffer = iio_kfifo_allocate(idev);
if (!idev->buffer) {
ret = -ENOMEM;
goto error_ret;
}
idev->pollfunc = iio_alloc_pollfunc(&iio_pollfunc_store_time,
&at91_adc_trigger_handler,
IRQF_ONESHOT,
idev,
"%s-consumer%d",
idev->name,
idev->id);
if (idev->pollfunc == NULL) {
ret = -ENOMEM;
goto error_pollfunc;
}
idev->setup_ops = &at91_adc_buffer_ops;
idev->modes |= INDIO_BUFFER_TRIGGERED;
ret = iio_buffer_register(idev,
idev->channels,
idev->num_channels);
if (ret)
goto error_register;
return 0;
error_register:
iio_dealloc_pollfunc(idev->pollfunc);
error_pollfunc:
iio_kfifo_free(idev->buffer);
error_ret:
return ret;
}
static void at91_adc_buffer_remove(struct iio_dev *idev)
{
iio_buffer_unregister(idev);
iio_dealloc_pollfunc(idev->pollfunc);
iio_kfifo_free(idev->buffer);
}
static int at91_adc_read_raw(struct iio_dev *idev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct at91_adc_state *st = iio_priv(idev);
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&st->lock);
at91_adc_writel(st, AT91_ADC_CHER,
AT91_ADC_CH(chan->channel));
at91_adc_writel(st, AT91_ADC_IER, st->registers->drdy_mask);
at91_adc_writel(st, AT91_ADC_CR, AT91_ADC_START);
ret = wait_event_interruptible_timeout(st->wq_data_avail,
st->done,
msecs_to_jiffies(1000));
if (ret == 0)
return -ETIMEDOUT;
else if (ret < 0)
return ret;
*val = st->last_value;
at91_adc_writel(st, AT91_ADC_CHDR,
AT91_ADC_CH(chan->channel));
at91_adc_writel(st, AT91_ADC_IDR, st->registers->drdy_mask);
st->last_value = 0;
st->done = false;
mutex_unlock(&st->lock);
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = (st->vref_mv * 1000) >> chan->scan_type.realbits;
*val2 = 0;
return IIO_VAL_INT_PLUS_MICRO;
default:
break;
}
return -EINVAL;
}
static int at91_adc_probe_dt(struct at91_adc_state *st,
struct platform_device *pdev)
{
struct iio_dev *idev = iio_priv_to_dev(st);
struct device_node *node = pdev->dev.of_node;
struct device_node *trig_node;
int i = 0, ret;
u32 prop;
if (!node)
return -EINVAL;
st->use_external = of_property_read_bool(node, "atmel,adc-use-external-triggers");
if (of_property_read_u32(node, "atmel,adc-channels-used", &prop)) {
dev_err(&idev->dev, "Missing adc-channels-used property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
st->channels_mask = prop;
if (of_property_read_u32(node, "atmel,adc-num-channels", &prop)) {
dev_err(&idev->dev, "Missing adc-num-channels property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
st->num_channels = prop;
if (of_property_read_u32(node, "atmel,adc-startup-time", &prop)) {
dev_err(&idev->dev, "Missing adc-startup-time property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
st->startup_time = prop;
if (of_property_read_u32(node, "atmel,adc-vref", &prop)) {
dev_err(&idev->dev, "Missing adc-vref property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
st->vref_mv = prop;
st->registers = devm_kzalloc(&idev->dev,
sizeof(struct at91_adc_reg_desc),
GFP_KERNEL);
if (!st->registers) {
dev_err(&idev->dev, "Could not allocate register memory.\n");
ret = -ENOMEM;
goto error_ret;
}
if (of_property_read_u32(node, "atmel,adc-channel-base", &prop)) {
dev_err(&idev->dev, "Missing adc-channel-base property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
st->registers->channel_base = prop;
if (of_property_read_u32(node, "atmel,adc-drdy-mask", &prop)) {
dev_err(&idev->dev, "Missing adc-drdy-mask property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
st->registers->drdy_mask = prop;
if (of_property_read_u32(node, "atmel,adc-status-register", &prop)) {
dev_err(&idev->dev, "Missing adc-status-register property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
st->registers->status_register = prop;
if (of_property_read_u32(node, "atmel,adc-trigger-register", &prop)) {
dev_err(&idev->dev, "Missing adc-trigger-register property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
st->registers->trigger_register = prop;
st->trigger_number = of_get_child_count(node);
st->trigger_list = devm_kzalloc(&idev->dev, st->trigger_number *
sizeof(struct at91_adc_trigger),
GFP_KERNEL);
if (!st->trigger_list) {
dev_err(&idev->dev, "Could not allocate trigger list memory.\n");
ret = -ENOMEM;
goto error_ret;
}
for_each_child_of_node(node, trig_node) {
struct at91_adc_trigger *trig = st->trigger_list + i;
const char *name;
if (of_property_read_string(trig_node, "trigger-name", &name)) {
dev_err(&idev->dev, "Missing trigger-name property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
trig->name = name;
if (of_property_read_u32(trig_node, "trigger-value", &prop)) {
dev_err(&idev->dev, "Missing trigger-value property in the DT.\n");
ret = -EINVAL;
goto error_ret;
}
trig->value = prop;
trig->is_external = of_property_read_bool(trig_node, "trigger-external");
i++;
}
return 0;
error_ret:
return ret;
}
static int at91_adc_probe_pdata(struct at91_adc_state *st,
struct platform_device *pdev)
{
struct at91_adc_data *pdata = pdev->dev.platform_data;
if (!pdata)
return -EINVAL;
st->use_external = pdata->use_external_triggers;
st->vref_mv = pdata->vref;
st->channels_mask = pdata->channels_used;
st->num_channels = pdata->num_channels;
st->startup_time = pdata->startup_time;
st->trigger_number = pdata->trigger_number;
st->trigger_list = pdata->trigger_list;
st->registers = pdata->registers;
return 0;
}
static int __devinit at91_adc_probe(struct platform_device *pdev)
{
unsigned int prsc, mstrclk, ticks, adc_clk;
int ret;
struct iio_dev *idev;
struct at91_adc_state *st;
struct resource *res;
idev = iio_device_alloc(sizeof(struct at91_adc_state));
if (idev == NULL) {
ret = -ENOMEM;
goto error_ret;
}
st = iio_priv(idev);
if (pdev->dev.of_node)
ret = at91_adc_probe_dt(st, pdev);
else
ret = at91_adc_probe_pdata(st, pdev);
if (ret) {
dev_err(&pdev->dev, "No platform data available.\n");
ret = -EINVAL;
goto error_free_device;
}
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!res) {
dev_err(&pdev->dev, "No resource defined\n");
ret = -ENXIO;
goto error_ret;
}
platform_set_drvdata(pdev, idev);
idev->dev.parent = &pdev->dev;
idev->name = dev_name(&pdev->dev);
idev->modes = INDIO_DIRECT_MODE;
idev->info = &at91_adc_info;
st->irq = platform_get_irq(pdev, 0);
if (st->irq < 0) {
dev_err(&pdev->dev, "No IRQ ID is designated\n");
ret = -ENODEV;
goto error_free_device;
}
if (!request_mem_region(res->start, resource_size(res),
"AT91 adc registers")) {
dev_err(&pdev->dev, "Resources are unavailable.\n");
ret = -EBUSY;
goto error_free_device;
}
st->reg_base = ioremap(res->start, resource_size(res));
if (!st->reg_base) {
dev_err(&pdev->dev, "Failed to map registers.\n");
ret = -ENOMEM;
goto error_release_mem;
}
at91_adc_writel(st, AT91_ADC_CR, AT91_ADC_SWRST);
at91_adc_writel(st, AT91_ADC_IDR, 0xFFFFFFFF);
ret = request_irq(st->irq,
at91_adc_eoc_trigger,
0,
pdev->dev.driver->name,
idev);
if (ret) {
dev_err(&pdev->dev, "Failed to allocate IRQ.\n");
goto error_unmap_reg;
}
st->clk = clk_get(&pdev->dev, "adc_clk");
if (IS_ERR(st->clk)) {
dev_err(&pdev->dev, "Failed to get the clock.\n");
ret = PTR_ERR(st->clk);
goto error_free_irq;
}
ret = clk_prepare(st->clk);
if (ret) {
dev_err(&pdev->dev, "Could not prepare the clock.\n");
goto error_free_clk;
}
ret = clk_enable(st->clk);
if (ret) {
dev_err(&pdev->dev, "Could not enable the clock.\n");
goto error_unprepare_clk;
}
st->adc_clk = clk_get(&pdev->dev, "adc_op_clk");
if (IS_ERR(st->adc_clk)) {
dev_err(&pdev->dev, "Failed to get the ADC clock.\n");
ret = PTR_ERR(st->clk);
goto error_disable_clk;
}
ret = clk_prepare(st->adc_clk);
if (ret) {
dev_err(&pdev->dev, "Could not prepare the ADC clock.\n");
goto error_free_adc_clk;
}
ret = clk_enable(st->adc_clk);
if (ret) {
dev_err(&pdev->dev, "Could not enable the ADC clock.\n");
goto error_unprepare_adc_clk;
}
mstrclk = clk_get_rate(st->clk);
adc_clk = clk_get_rate(st->adc_clk);
prsc = (mstrclk / (2 * adc_clk)) - 1;
if (!st->startup_time) {
dev_err(&pdev->dev, "No startup time available.\n");
ret = -EINVAL;
goto error_disable_adc_clk;
}
ticks = round_up((st->startup_time * adc_clk /
1000000) - 1, 8) / 8;
at91_adc_writel(st, AT91_ADC_MR,
(AT91_ADC_PRESCAL_(prsc) & AT91_ADC_PRESCAL) |
(AT91_ADC_STARTUP_(ticks) & AT91_ADC_STARTUP));
ret = at91_adc_channel_init(idev);
if (ret < 0) {
dev_err(&pdev->dev, "Couldn't initialize the channels.\n");
goto error_disable_adc_clk;
}
init_waitqueue_head(&st->wq_data_avail);
mutex_init(&st->lock);
ret = at91_adc_buffer_init(idev);
if (ret < 0) {
dev_err(&pdev->dev, "Couldn't initialize the buffer.\n");
goto error_disable_adc_clk;
}
ret = at91_adc_trigger_init(idev);
if (ret < 0) {
dev_err(&pdev->dev, "Couldn't setup the triggers.\n");
goto error_unregister_buffer;
}
ret = iio_device_register(idev);
if (ret < 0) {
dev_err(&pdev->dev, "Couldn't register the device.\n");
goto error_remove_triggers;
}
return 0;
error_remove_triggers:
at91_adc_trigger_remove(idev);
error_unregister_buffer:
at91_adc_buffer_remove(idev);
error_disable_adc_clk:
clk_disable(st->adc_clk);
error_unprepare_adc_clk:
clk_unprepare(st->adc_clk);
error_free_adc_clk:
clk_put(st->adc_clk);
error_disable_clk:
clk_disable(st->clk);
error_unprepare_clk:
clk_unprepare(st->clk);
error_free_clk:
clk_put(st->clk);
error_free_irq:
free_irq(st->irq, idev);
error_unmap_reg:
iounmap(st->reg_base);
error_release_mem:
release_mem_region(res->start, resource_size(res));
error_free_device:
iio_device_free(idev);
error_ret:
return ret;
}
static int __devexit at91_adc_remove(struct platform_device *pdev)
{
struct iio_dev *idev = platform_get_drvdata(pdev);
struct resource *res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
struct at91_adc_state *st = iio_priv(idev);
iio_device_unregister(idev);
at91_adc_trigger_remove(idev);
at91_adc_buffer_remove(idev);
clk_disable_unprepare(st->adc_clk);
clk_put(st->adc_clk);
clk_disable(st->clk);
clk_unprepare(st->clk);
clk_put(st->clk);
free_irq(st->irq, idev);
iounmap(st->reg_base);
release_mem_region(res->start, resource_size(res));
iio_device_free(idev);
return 0;
}
