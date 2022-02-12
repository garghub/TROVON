static int twl4030_madc_read(struct iio_dev *iio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long mask)
{
struct twl4030_madc_data *madc = iio_priv(iio_dev);
struct twl4030_madc_request req;
int ret;
req.method = madc->use_second_irq ? TWL4030_MADC_SW2 : TWL4030_MADC_SW1;
req.channels = BIT(chan->channel);
req.active = false;
req.func_cb = NULL;
req.type = TWL4030_MADC_WAIT;
req.raw = !(mask == IIO_CHAN_INFO_PROCESSED);
req.do_avg = (mask == IIO_CHAN_INFO_AVERAGE_RAW);
ret = twl4030_madc_conversion(&req);
if (ret < 0)
return ret;
*val = req.rbuf[chan->channel];
return IIO_VAL_INT;
}
static int twl4030_madc_channel_raw_read(struct twl4030_madc_data *madc, u8 reg)
{
u16 val;
int ret;
ret = twl_i2c_read_u16(TWL4030_MODULE_MADC, &val, reg);
if (ret) {
dev_err(madc->dev, "unable to read register 0x%X\n", reg);
return ret;
}
return (int)(val >> 6);
}
static int twl4030battery_temperature(int raw_volt)
{
u8 val;
int temp, curr, volt, res, ret;
volt = (raw_volt * TEMP_STEP_SIZE) / TEMP_PSR_R;
ret = twl_i2c_read_u8(TWL_MODULE_MAIN_CHARGE, &val,
REG_BCICTL2);
if (ret < 0)
return ret;
curr = ((val & TWL4030_BCI_ITHSENS) + 1) * 10;
res = volt * 1000 / curr;
for (temp = 58; temp >= 0; temp--) {
int actual = twl4030_therm_tbl[temp];
if ((actual - res) >= 0)
break;
}
return temp + 1;
}
static int twl4030battery_current(int raw_volt)
{
int ret;
u8 val;
ret = twl_i2c_read_u8(TWL_MODULE_MAIN_CHARGE, &val,
TWL4030_BCI_BCICTL1);
if (ret)
return ret;
if (val & TWL4030_BCI_CGAIN)
return (raw_volt * CURR_STEP_SIZE) / CURR_PSR_R1;
else
return (raw_volt * CURR_STEP_SIZE) / CURR_PSR_R2;
}
static int twl4030_madc_read_channels(struct twl4030_madc_data *madc,
u8 reg_base, unsigned
long channels, int *buf,
bool raw)
{
int count = 0;
int i;
u8 reg;
for_each_set_bit(i, &channels, TWL4030_MADC_MAX_CHANNELS) {
reg = reg_base + (2 * i);
buf[i] = twl4030_madc_channel_raw_read(madc, reg);
if (buf[i] < 0) {
dev_err(madc->dev, "Unable to read register 0x%X\n",
reg);
return buf[i];
}
if (raw) {
count++;
continue;
}
switch (i) {
case 10:
buf[i] = twl4030battery_current(buf[i]);
if (buf[i] < 0) {
dev_err(madc->dev, "err reading current\n");
return buf[i];
} else {
count++;
buf[i] = buf[i] - 750;
}
break;
case 1:
buf[i] = twl4030battery_temperature(buf[i]);
if (buf[i] < 0) {
dev_err(madc->dev, "err reading temperature\n");
return buf[i];
} else {
buf[i] -= 3;
count++;
}
break;
default:
count++;
buf[i] = (buf[i] * 3 * 1000 *
twl4030_divider_ratios[i].denominator)
/ (2 * 1023 *
twl4030_divider_ratios[i].numerator);
}
}
return count;
}
static int twl4030_madc_enable_irq(struct twl4030_madc_data *madc, u8 id)
{
u8 val;
int ret;
ret = twl_i2c_read_u8(TWL4030_MODULE_MADC, &val, madc->imr);
if (ret) {
dev_err(madc->dev, "unable to read imr register 0x%X\n",
madc->imr);
return ret;
}
val &= ~(1 << id);
ret = twl_i2c_write_u8(TWL4030_MODULE_MADC, val, madc->imr);
if (ret) {
dev_err(madc->dev,
"unable to write imr register 0x%X\n", madc->imr);
return ret;
}
return 0;
}
static int twl4030_madc_disable_irq(struct twl4030_madc_data *madc, u8 id)
{
u8 val;
int ret;
ret = twl_i2c_read_u8(TWL4030_MODULE_MADC, &val, madc->imr);
if (ret) {
dev_err(madc->dev, "unable to read imr register 0x%X\n",
madc->imr);
return ret;
}
val |= (1 << id);
ret = twl_i2c_write_u8(TWL4030_MODULE_MADC, val, madc->imr);
if (ret) {
dev_err(madc->dev,
"unable to write imr register 0x%X\n", madc->imr);
return ret;
}
return 0;
}
static irqreturn_t twl4030_madc_threaded_irq_handler(int irq, void *_madc)
{
struct twl4030_madc_data *madc = _madc;
const struct twl4030_madc_conversion_method *method;
u8 isr_val, imr_val;
int i, len, ret;
struct twl4030_madc_request *r;
mutex_lock(&madc->lock);
ret = twl_i2c_read_u8(TWL4030_MODULE_MADC, &isr_val, madc->isr);
if (ret) {
dev_err(madc->dev, "unable to read isr register 0x%X\n",
madc->isr);
goto err_i2c;
}
ret = twl_i2c_read_u8(TWL4030_MODULE_MADC, &imr_val, madc->imr);
if (ret) {
dev_err(madc->dev, "unable to read imr register 0x%X\n",
madc->imr);
goto err_i2c;
}
isr_val &= ~imr_val;
for (i = 0; i < TWL4030_MADC_NUM_METHODS; i++) {
if (!(isr_val & (1 << i)))
continue;
ret = twl4030_madc_disable_irq(madc, i);
if (ret < 0)
dev_dbg(madc->dev, "Disable interrupt failed %d\n", i);
madc->requests[i].result_pending = 1;
}
for (i = 0; i < TWL4030_MADC_NUM_METHODS; i++) {
r = &madc->requests[i];
if (!r->result_pending)
continue;
method = &twl4030_conversion_methods[r->method];
len = twl4030_madc_read_channels(madc, method->rbase,
r->channels, r->rbuf, r->raw);
if (r->func_cb != NULL) {
r->func_cb(len, r->channels, r->rbuf);
r->func_cb = NULL;
}
r->result_pending = 0;
r->active = 0;
}
mutex_unlock(&madc->lock);
return IRQ_HANDLED;
err_i2c:
for (i = 0; i < TWL4030_MADC_NUM_METHODS; i++) {
r = &madc->requests[i];
if (r->active == 0)
continue;
method = &twl4030_conversion_methods[r->method];
len = twl4030_madc_read_channels(madc, method->rbase,
r->channels, r->rbuf, r->raw);
if (r->func_cb != NULL) {
r->func_cb(len, r->channels, r->rbuf);
r->func_cb = NULL;
}
r->result_pending = 0;
r->active = 0;
}
mutex_unlock(&madc->lock);
return IRQ_HANDLED;
}
static int twl4030_madc_set_irq(struct twl4030_madc_data *madc,
struct twl4030_madc_request *req)
{
struct twl4030_madc_request *p;
int ret;
p = &madc->requests[req->method];
memcpy(p, req, sizeof(*req));
ret = twl4030_madc_enable_irq(madc, req->method);
if (ret < 0) {
dev_err(madc->dev, "enable irq failed!!\n");
return ret;
}
return 0;
}
static int twl4030_madc_start_conversion(struct twl4030_madc_data *madc,
int conv_method)
{
const struct twl4030_madc_conversion_method *method;
int ret = 0;
if (conv_method != TWL4030_MADC_SW1 && conv_method != TWL4030_MADC_SW2)
return -ENOTSUPP;
method = &twl4030_conversion_methods[conv_method];
ret = twl_i2c_write_u8(TWL4030_MODULE_MADC, TWL4030_MADC_SW_START,
method->ctrl);
if (ret) {
dev_err(madc->dev, "unable to write ctrl register 0x%X\n",
method->ctrl);
return ret;
}
return 0;
}
static int twl4030_madc_wait_conversion_ready(struct twl4030_madc_data *madc,
unsigned int timeout_ms,
u8 status_reg)
{
unsigned long timeout;
int ret;
timeout = jiffies + msecs_to_jiffies(timeout_ms);
do {
u8 reg;
ret = twl_i2c_read_u8(TWL4030_MODULE_MADC, &reg, status_reg);
if (ret) {
dev_err(madc->dev,
"unable to read status register 0x%X\n",
status_reg);
return ret;
}
if (!(reg & TWL4030_MADC_BUSY) && (reg & TWL4030_MADC_EOC_SW))
return 0;
usleep_range(500, 2000);
} while (!time_after(jiffies, timeout));
dev_err(madc->dev, "conversion timeout!\n");
return -EAGAIN;
}
int twl4030_madc_conversion(struct twl4030_madc_request *req)
{
const struct twl4030_madc_conversion_method *method;
int ret;
if (!req || !twl4030_madc)
return -EINVAL;
mutex_lock(&twl4030_madc->lock);
if (req->method < TWL4030_MADC_RT || req->method > TWL4030_MADC_SW2) {
ret = -EINVAL;
goto out;
}
if (twl4030_madc->requests[req->method].active) {
ret = -EBUSY;
goto out;
}
method = &twl4030_conversion_methods[req->method];
ret = twl_i2c_write_u16(TWL4030_MODULE_MADC, req->channels, method->sel);
if (ret) {
dev_err(twl4030_madc->dev,
"unable to write sel register 0x%X\n", method->sel);
goto out;
}
if (req->do_avg) {
ret = twl_i2c_write_u16(TWL4030_MODULE_MADC, req->channels,
method->avg);
if (ret) {
dev_err(twl4030_madc->dev,
"unable to write avg register 0x%X\n",
method->avg);
goto out;
}
}
if (req->type == TWL4030_MADC_IRQ_ONESHOT && req->func_cb != NULL) {
ret = twl4030_madc_set_irq(twl4030_madc, req);
if (ret < 0)
goto out;
ret = twl4030_madc_start_conversion(twl4030_madc, req->method);
if (ret < 0)
goto out;
twl4030_madc->requests[req->method].active = 1;
ret = 0;
goto out;
}
if (req->method == TWL4030_MADC_RT) {
ret = -EINVAL;
goto out;
}
ret = twl4030_madc_start_conversion(twl4030_madc, req->method);
if (ret < 0)
goto out;
twl4030_madc->requests[req->method].active = 1;
ret = twl4030_madc_wait_conversion_ready(twl4030_madc, 5, method->ctrl);
if (ret) {
twl4030_madc->requests[req->method].active = 0;
goto out;
}
ret = twl4030_madc_read_channels(twl4030_madc, method->rbase,
req->channels, req->rbuf, req->raw);
twl4030_madc->requests[req->method].active = 0;
out:
mutex_unlock(&twl4030_madc->lock);
return ret;
}
int twl4030_get_madc_conversion(int channel_no)
{
struct twl4030_madc_request req;
int temp = 0;
int ret;
req.channels = (1 << channel_no);
req.method = TWL4030_MADC_SW2;
req.active = 0;
req.raw = 0;
req.func_cb = NULL;
ret = twl4030_madc_conversion(&req);
if (ret < 0)
return ret;
if (req.rbuf[channel_no] > 0)
temp = req.rbuf[channel_no];
return temp;
}
static int twl4030_madc_set_current_generator(struct twl4030_madc_data *madc,
int chan, int on)
{
int ret;
int regmask;
u8 regval;
ret = twl_i2c_read_u8(TWL_MODULE_MAIN_CHARGE,
&regval, TWL4030_BCI_BCICTL1);
if (ret) {
dev_err(madc->dev, "unable to read BCICTL1 reg 0x%X",
TWL4030_BCI_BCICTL1);
return ret;
}
regmask = chan ? TWL4030_BCI_ITHEN : TWL4030_BCI_TYPEN;
if (on)
regval |= regmask;
else
regval &= ~regmask;
ret = twl_i2c_write_u8(TWL_MODULE_MAIN_CHARGE,
regval, TWL4030_BCI_BCICTL1);
if (ret) {
dev_err(madc->dev, "unable to write BCICTL1 reg 0x%X\n",
TWL4030_BCI_BCICTL1);
return ret;
}
return 0;
}
static int twl4030_madc_set_power(struct twl4030_madc_data *madc, int on)
{
u8 regval;
int ret;
ret = twl_i2c_read_u8(TWL_MODULE_MAIN_CHARGE,
&regval, TWL4030_MADC_CTRL1);
if (ret) {
dev_err(madc->dev, "unable to read madc ctrl1 reg 0x%X\n",
TWL4030_MADC_CTRL1);
return ret;
}
if (on)
regval |= TWL4030_MADC_MADCON;
else
regval &= ~TWL4030_MADC_MADCON;
ret = twl_i2c_write_u8(TWL4030_MODULE_MADC, regval, TWL4030_MADC_CTRL1);
if (ret) {
dev_err(madc->dev, "unable to write madc ctrl1 reg 0x%X\n",
TWL4030_MADC_CTRL1);
return ret;
}
return 0;
}
static int twl4030_madc_probe(struct platform_device *pdev)
{
struct twl4030_madc_data *madc;
struct twl4030_madc_platform_data *pdata = dev_get_platdata(&pdev->dev);
struct device_node *np = pdev->dev.of_node;
int irq, ret;
u8 regval;
struct iio_dev *iio_dev = NULL;
if (!pdata && !np) {
dev_err(&pdev->dev, "neither platform data nor Device Tree node available\n");
return -EINVAL;
}
iio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*madc));
if (!iio_dev) {
dev_err(&pdev->dev, "failed allocating iio device\n");
return -ENOMEM;
}
madc = iio_priv(iio_dev);
madc->dev = &pdev->dev;
iio_dev->name = dev_name(&pdev->dev);
iio_dev->dev.parent = &pdev->dev;
iio_dev->dev.of_node = pdev->dev.of_node;
iio_dev->info = &twl4030_madc_iio_info;
iio_dev->modes = INDIO_DIRECT_MODE;
iio_dev->channels = twl4030_madc_iio_channels;
iio_dev->num_channels = ARRAY_SIZE(twl4030_madc_iio_channels);
if (pdata)
madc->use_second_irq = (pdata->irq_line != 1);
else
madc->use_second_irq = of_property_read_bool(np,
"ti,system-uses-second-madc-irq");
madc->imr = madc->use_second_irq ? TWL4030_MADC_IMR2 :
TWL4030_MADC_IMR1;
madc->isr = madc->use_second_irq ? TWL4030_MADC_ISR2 :
TWL4030_MADC_ISR1;
ret = twl4030_madc_set_power(madc, 1);
if (ret < 0)
return ret;
ret = twl4030_madc_set_current_generator(madc, 0, 1);
if (ret < 0)
goto err_current_generator;
ret = twl_i2c_read_u8(TWL_MODULE_MAIN_CHARGE,
&regval, TWL4030_BCI_BCICTL1);
if (ret) {
dev_err(&pdev->dev, "unable to read reg BCI CTL1 0x%X\n",
TWL4030_BCI_BCICTL1);
goto err_i2c;
}
regval |= TWL4030_BCI_MESBAT;
ret = twl_i2c_write_u8(TWL_MODULE_MAIN_CHARGE,
regval, TWL4030_BCI_BCICTL1);
if (ret) {
dev_err(&pdev->dev, "unable to write reg BCI Ctl1 0x%X\n",
TWL4030_BCI_BCICTL1);
goto err_i2c;
}
ret = twl_i2c_read_u8(TWL4030_MODULE_INTBR, &regval, TWL4030_REG_GPBR1);
if (ret) {
dev_err(&pdev->dev, "unable to read reg GPBR1 0x%X\n",
TWL4030_REG_GPBR1);
goto err_i2c;
}
if (!(regval & TWL4030_GPBR1_MADC_HFCLK_EN)) {
dev_info(&pdev->dev, "clk disabled, enabling\n");
regval |= TWL4030_GPBR1_MADC_HFCLK_EN;
ret = twl_i2c_write_u8(TWL4030_MODULE_INTBR, regval,
TWL4030_REG_GPBR1);
if (ret) {
dev_err(&pdev->dev, "unable to write reg GPBR1 0x%X\n",
TWL4030_REG_GPBR1);
goto err_i2c;
}
}
platform_set_drvdata(pdev, iio_dev);
mutex_init(&madc->lock);
irq = platform_get_irq(pdev, 0);
ret = devm_request_threaded_irq(&pdev->dev, irq, NULL,
twl4030_madc_threaded_irq_handler,
IRQF_TRIGGER_RISING | IRQF_ONESHOT,
"twl4030_madc", madc);
if (ret) {
dev_err(&pdev->dev, "could not request irq\n");
goto err_i2c;
}
twl4030_madc = madc;
ret = twl_i2c_read_u8(TWL_MODULE_USB, &regval,
TWL4030_USB_CARKIT_ANA_CTRL);
if (ret) {
dev_err(&pdev->dev, "unable to read reg CARKIT_ANA_CTRL 0x%X\n",
TWL4030_USB_CARKIT_ANA_CTRL);
goto err_i2c;
}
regval |= TWL4030_USB_SEL_MADC_MCPC;
ret = twl_i2c_write_u8(TWL_MODULE_USB, regval,
TWL4030_USB_CARKIT_ANA_CTRL);
if (ret) {
dev_err(&pdev->dev, "unable to write reg CARKIT_ANA_CTRL 0x%X\n",
TWL4030_USB_CARKIT_ANA_CTRL);
goto err_i2c;
}
madc->usb3v1 = devm_regulator_get(madc->dev, "vusb3v1");
if (IS_ERR(madc->usb3v1))
return -ENODEV;
ret = regulator_enable(madc->usb3v1);
if (ret)
dev_err(madc->dev, "could not enable 3v1 bias regulator\n");
ret = iio_device_register(iio_dev);
if (ret) {
dev_err(&pdev->dev, "could not register iio device\n");
goto err_i2c;
}
return 0;
err_i2c:
twl4030_madc_set_current_generator(madc, 0, 0);
err_current_generator:
twl4030_madc_set_power(madc, 0);
return ret;
}
static int twl4030_madc_remove(struct platform_device *pdev)
{
struct iio_dev *iio_dev = platform_get_drvdata(pdev);
struct twl4030_madc_data *madc = iio_priv(iio_dev);
iio_device_unregister(iio_dev);
twl4030_madc_set_current_generator(madc, 0, 0);
twl4030_madc_set_power(madc, 0);
regulator_disable(madc->usb3v1);
return 0;
}
