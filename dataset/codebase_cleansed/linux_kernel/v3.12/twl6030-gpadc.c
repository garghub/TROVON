static inline int twl6030_gpadc_write(u8 reg, u8 val)
{
return twl_i2c_write_u8(TWL6030_MODULE_GPADC, val, reg);
}
static inline int twl6030_gpadc_read(u8 reg, u8 *val)
{
return twl_i2c_read(TWL6030_MODULE_GPADC, val, reg, 2);
}
static int twl6030_gpadc_enable_irq(u8 mask)
{
int ret;
ret = twl6030_interrupt_unmask(mask, REG_INT_MSK_LINE_B);
if (ret < 0)
return ret;
ret = twl6030_interrupt_unmask(mask, REG_INT_MSK_STS_B);
return ret;
}
static void twl6030_gpadc_disable_irq(u8 mask)
{
twl6030_interrupt_mask(mask, REG_INT_MSK_LINE_B);
twl6030_interrupt_mask(mask, REG_INT_MSK_STS_B);
}
static irqreturn_t twl6030_gpadc_irq_handler(int irq, void *indio_dev)
{
struct twl6030_gpadc_data *gpadc = iio_priv(indio_dev);
complete(&gpadc->irq_complete);
return IRQ_HANDLED;
}
static int twl6030_start_conversion(int channel)
{
return twl6030_gpadc_write(TWL6030_GPADC_CTRL_P1,
TWL6030_GPADC_CTRL_P1_SP1);
}
static int twl6032_start_conversion(int channel)
{
int ret;
ret = twl6030_gpadc_write(TWL6032_GPADC_GPSELECT_ISB, channel);
if (ret)
return ret;
return twl6030_gpadc_write(TWL6032_GPADC_CTRL_P1,
TWL6030_GPADC_CTRL_P1_SP1);
}
static u8 twl6030_channel_to_reg(int channel)
{
return TWL6030_GPADC_GPCH0_LSB + 2 * channel;
}
static u8 twl6032_channel_to_reg(int channel)
{
return TWL6032_GPADC_GPCH0_LSB;
}
static int twl6030_gpadc_lookup(const struct twl6030_ideal_code *ideal,
int channel, int size)
{
int i;
for (i = 0; i < size; i++)
if (ideal[i].channel == channel)
break;
return i;
}
static int twl6030_channel_calibrated(const struct twl6030_gpadc_platform_data
*pdata, int channel)
{
const struct twl6030_ideal_code *ideal = pdata->ideal;
int i;
i = twl6030_gpadc_lookup(ideal, channel, pdata->nchannels);
return pdata->ideal[i].code2;
}
static int twl6030_gpadc_make_correction(struct twl6030_gpadc_data *gpadc,
int channel, int raw_code)
{
const struct twl6030_ideal_code *ideal = gpadc->pdata->ideal;
int corrected_code;
int i;
i = twl6030_gpadc_lookup(ideal, channel, gpadc->pdata->nchannels);
corrected_code = ((raw_code * 1000) -
gpadc->twl6030_cal_tbl[i].offset_error) /
gpadc->twl6030_cal_tbl[i].gain_error;
return corrected_code;
}
static int twl6030_gpadc_get_raw(struct twl6030_gpadc_data *gpadc,
int channel, int *res)
{
u8 reg = gpadc->pdata->channel_to_reg(channel);
__le16 val;
int raw_code;
int ret;
ret = twl6030_gpadc_read(reg, (u8 *)&val);
if (ret) {
dev_dbg(gpadc->dev, "unable to read register 0x%X\n", reg);
return ret;
}
raw_code = le16_to_cpu(val);
dev_dbg(gpadc->dev, "GPADC raw code: %d", raw_code);
if (twl6030_channel_calibrated(gpadc->pdata, channel))
*res = twl6030_gpadc_make_correction(gpadc, channel, raw_code);
else
*res = raw_code;
return ret;
}
static int twl6030_gpadc_get_processed(struct twl6030_gpadc_data *gpadc,
int channel, int *val)
{
const struct twl6030_ideal_code *ideal = gpadc->pdata->ideal;
int corrected_code;
int channel_value;
int i;
int ret;
ret = twl6030_gpadc_get_raw(gpadc, channel, &corrected_code);
if (ret)
return ret;
i = twl6030_gpadc_lookup(ideal, channel, gpadc->pdata->nchannels);
channel_value = corrected_code *
gpadc->twl6030_cal_tbl[i].gain;
channel_value /= 1000;
dev_dbg(gpadc->dev, "GPADC corrected code: %d", corrected_code);
dev_dbg(gpadc->dev, "GPADC value: %d", channel_value);
*val = channel_value;
return ret;
}
static int twl6030_gpadc_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan,
int *val, int *val2, long mask)
{
struct twl6030_gpadc_data *gpadc = iio_priv(indio_dev);
int ret;
long timeout;
mutex_lock(&gpadc->lock);
ret = gpadc->pdata->start_conversion(chan->channel);
if (ret) {
dev_err(gpadc->dev, "failed to start conversion\n");
goto err;
}
timeout = wait_for_completion_interruptible_timeout(
&gpadc->irq_complete, msecs_to_jiffies(5000));
if (timeout == 0) {
ret = -ETIMEDOUT;
goto err;
} else if (timeout < 0) {
ret = -EINTR;
goto err;
}
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = twl6030_gpadc_get_raw(gpadc, chan->channel, val);
ret = ret ? -EIO : IIO_VAL_INT;
break;
case IIO_CHAN_INFO_PROCESSED:
ret = twl6030_gpadc_get_processed(gpadc, chan->channel, val);
ret = ret ? -EIO : IIO_VAL_INT;
break;
default:
break;
}
err:
mutex_unlock(&gpadc->lock);
return ret;
}
static void twl6030_calibrate_channel(struct twl6030_gpadc_data *gpadc,
int channel, int d1, int d2)
{
int b, k, gain, x1, x2, i;
const struct twl6030_ideal_code *ideal = gpadc->pdata->ideal;
i = twl6030_gpadc_lookup(ideal, channel, gpadc->pdata->nchannels);
gain = ((ideal[i].volt2 - ideal[i].volt1) * 1000) /
(ideal[i].code2 - ideal[i].code1);
x1 = ideal[i].code1;
x2 = ideal[i].code2;
k = 1000 + (((d2 - d1) * 1000) / (x2 - x1));
b = (d1 * 1000) - (k - 1000) * x1;
gpadc->twl6030_cal_tbl[i].gain = gain;
gpadc->twl6030_cal_tbl[i].gain_error = k;
gpadc->twl6030_cal_tbl[i].offset_error = b;
dev_dbg(gpadc->dev, "GPADC d1 for Chn: %d = %d\n", channel, d1);
dev_dbg(gpadc->dev, "GPADC d2 for Chn: %d = %d\n", channel, d2);
dev_dbg(gpadc->dev, "GPADC x1 for Chn: %d = %d\n", channel, x1);
dev_dbg(gpadc->dev, "GPADC x2 for Chn: %d = %d\n", channel, x2);
dev_dbg(gpadc->dev, "GPADC Gain for Chn: %d = %d\n", channel, gain);
dev_dbg(gpadc->dev, "GPADC k for Chn: %d = %d\n", channel, k);
dev_dbg(gpadc->dev, "GPADC b for Chn: %d = %d\n", channel, b);
}
static inline int twl6030_gpadc_get_trim_offset(s8 d)
{
__u32 temp = ((d & 0x7f) >> 1) | ((d & 1) << 6);
return sign_extend32(temp, 6);
}
static int twl6030_calibration(struct twl6030_gpadc_data *gpadc)
{
int ret;
int chn;
u8 trim_regs[TWL6030_GPADC_NUM_TRIM_REGS];
s8 d1, d2;
ret = twl_i2c_read(TWL6030_MODULE_ID2, trim_regs,
TWL6030_GPADC_TRIM1, TWL6030_GPADC_NUM_TRIM_REGS);
if (ret < 0) {
dev_err(gpadc->dev, "calibration failed\n");
return ret;
}
for (chn = 0; chn < TWL6030_GPADC_MAX_CHANNELS; chn++) {
switch (chn) {
case 0:
d1 = trim_regs[0];
d2 = trim_regs[1];
break;
case 1:
case 3:
case 4:
case 5:
case 6:
d1 = trim_regs[4];
d2 = trim_regs[5];
break;
case 2:
d1 = trim_regs[12];
d2 = trim_regs[13];
break;
case 7:
d1 = trim_regs[6];
d2 = trim_regs[7];
break;
case 8:
d1 = trim_regs[2];
d2 = trim_regs[3];
break;
case 9:
d1 = trim_regs[8];
d2 = trim_regs[9];
break;
case 10:
d1 = trim_regs[10];
d2 = trim_regs[11];
break;
case 14:
d1 = trim_regs[14];
d2 = trim_regs[15];
break;
default:
continue;
}
d1 = twl6030_gpadc_get_trim_offset(d1);
d2 = twl6030_gpadc_get_trim_offset(d2);
twl6030_calibrate_channel(gpadc, chn, d1, d2);
}
return 0;
}
static int twl6032_get_trim_value(u8 *trim_regs, unsigned int reg0,
unsigned int reg1, unsigned int mask0, unsigned int mask1,
unsigned int shift0)
{
int val;
val = (trim_regs[reg0] & mask0) << shift0;
val |= (trim_regs[reg1] & mask1) >> 1;
if (trim_regs[reg1] & 0x01)
val = -val;
return val;
}
static int twl6032_calibration(struct twl6030_gpadc_data *gpadc)
{
int chn, d1 = 0, d2 = 0, temp;
u8 trim_regs[TWL6030_GPADC_NUM_TRIM_REGS];
int ret;
ret = twl_i2c_read(TWL6030_MODULE_ID2, trim_regs,
TWL6030_GPADC_TRIM1, TWL6030_GPADC_NUM_TRIM_REGS);
if (ret < 0) {
dev_err(gpadc->dev, "calibration failed\n");
return ret;
}
for (chn = 0; chn < TWL6032_GPADC_MAX_CHANNELS; chn++) {
switch (chn) {
case 0:
case 1:
case 2:
case 3:
case 4:
case 5:
case 6:
case 11:
case 14:
d1 = twl6032_get_trim_value(trim_regs, 2, 0, 0x1f,
0x06, 2);
d2 = twl6032_get_trim_value(trim_regs, 3, 1, 0x3f,
0x06, 2);
break;
case 8:
temp = twl6032_get_trim_value(trim_regs, 2, 0, 0x1f,
0x06, 2);
d1 = temp + twl6032_get_trim_value(trim_regs, 7, 6,
0x18, 0x1E, 1);
temp = twl6032_get_trim_value(trim_regs, 3, 1, 0x3F,
0x06, 2);
d2 = temp + twl6032_get_trim_value(trim_regs, 9, 7,
0x1F, 0x06, 2);
break;
case 9:
temp = twl6032_get_trim_value(trim_regs, 2, 0, 0x1f,
0x06, 2);
d1 = temp + twl6032_get_trim_value(trim_regs, 13, 11,
0x18, 0x1E, 1);
temp = twl6032_get_trim_value(trim_regs, 3, 1, 0x3f,
0x06, 2);
d2 = temp + twl6032_get_trim_value(trim_regs, 15, 13,
0x1F, 0x06, 1);
break;
case 10:
d1 = twl6032_get_trim_value(trim_regs, 10, 8, 0x0f,
0x0E, 3);
d2 = twl6032_get_trim_value(trim_regs, 14, 12, 0x0f,
0x0E, 3);
break;
case 7:
case 18:
temp = twl6032_get_trim_value(trim_regs, 2, 0, 0x1f,
0x06, 2);
d1 = (trim_regs[4] & 0x7E) >> 1;
if (trim_regs[4] & 0x01)
d1 = -d1;
d1 += temp;
temp = twl6032_get_trim_value(trim_regs, 3, 1, 0x3f,
0x06, 2);
d2 = (trim_regs[5] & 0xFE) >> 1;
if (trim_regs[5] & 0x01)
d2 = -d2;
d2 += temp;
break;
default:
continue;
}
twl6030_calibrate_channel(gpadc, chn, d1, d2);
}
return 0;
}
static int twl6030_gpadc_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct twl6030_gpadc_data *gpadc;
const struct twl6030_gpadc_platform_data *pdata;
const struct of_device_id *match;
struct iio_dev *indio_dev;
int irq;
int ret;
match = of_match_device(of_match_ptr(of_twl6030_match_tbl), dev);
if (!match)
return -EINVAL;
pdata = match->data;
indio_dev = devm_iio_device_alloc(dev, sizeof(*gpadc));
if (!indio_dev)
return -ENOMEM;
gpadc = iio_priv(indio_dev);
gpadc->twl6030_cal_tbl = devm_kzalloc(dev,
sizeof(*gpadc->twl6030_cal_tbl) *
pdata->nchannels, GFP_KERNEL);
if (!gpadc->twl6030_cal_tbl)
return -ENOMEM;
gpadc->dev = dev;
gpadc->pdata = pdata;
platform_set_drvdata(pdev, indio_dev);
mutex_init(&gpadc->lock);
init_completion(&gpadc->irq_complete);
ret = pdata->calibrate(gpadc);
if (ret < 0) {
dev_err(&pdev->dev, "failed to read calibration registers\n");
return ret;
}
irq = platform_get_irq(pdev, 0);
if (irq < 0) {
dev_err(&pdev->dev, "failed to get irq\n");
return irq;
}
ret = devm_request_threaded_irq(dev, irq, NULL,
twl6030_gpadc_irq_handler,
IRQF_ONESHOT, "twl6030_gpadc", indio_dev);
ret = twl6030_gpadc_enable_irq(TWL6030_GPADC_RT_SW1_EOC_MASK);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable GPADC interrupt\n");
return ret;
}
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, TWL6030_GPADCS,
TWL6030_REG_TOGGLE1);
if (ret < 0) {
dev_err(&pdev->dev, "failed to enable GPADC module\n");
return ret;
}
indio_dev->name = DRIVER_NAME;
indio_dev->dev.parent = dev;
indio_dev->info = &twl6030_gpadc_iio_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = pdata->iio_channels;
indio_dev->num_channels = pdata->nchannels;
ret = iio_device_register(indio_dev);
return ret;
}
static int twl6030_gpadc_remove(struct platform_device *pdev)
{
struct iio_dev *indio_dev = platform_get_drvdata(pdev);
twl6030_gpadc_disable_irq(TWL6030_GPADC_RT_SW1_EOC_MASK);
iio_device_unregister(indio_dev);
return 0;
}
static int twl6030_gpadc_suspend(struct device *pdev)
{
int ret;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, TWL6030_GPADCR,
TWL6030_REG_TOGGLE1);
if (ret)
dev_err(pdev, "error reseting GPADC (%d)!\n", ret);
return 0;
}
static int twl6030_gpadc_resume(struct device *pdev)
{
int ret;
ret = twl_i2c_write_u8(TWL6030_MODULE_ID1, TWL6030_GPADCS,
TWL6030_REG_TOGGLE1);
if (ret)
dev_err(pdev, "error setting GPADC (%d)!\n", ret);
return 0;
}
