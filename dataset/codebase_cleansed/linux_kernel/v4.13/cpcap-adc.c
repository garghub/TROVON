static irqreturn_t cpcap_adc_irq_thread(int irq, void *data)
{
struct iio_dev *indio_dev = data;
struct cpcap_adc *ddata = iio_priv(indio_dev);
int error;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ADTRIG_DIS,
CPCAP_BIT_ADTRIG_DIS);
if (error)
return IRQ_NONE;
ddata->done = true;
wake_up_interruptible(&ddata->wq_data_avail);
return IRQ_HANDLED;
}
static void cpcap_adc_setup_calibrate(struct cpcap_adc *ddata,
enum cpcap_adc_channel chan)
{
unsigned int value = 0;
unsigned long timeout = jiffies + msecs_to_jiffies(3000);
int error;
if ((chan != CPCAP_ADC_CHG_ISENSE) &&
(chan != CPCAP_ADC_BATTI))
return;
value |= CPCAP_BIT_CAL_MODE | CPCAP_BIT_RAND0;
value |= ((chan << 4) &
(CPCAP_BIT_ADA2 | CPCAP_BIT_ADA1 | CPCAP_BIT_ADA0));
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC1,
CPCAP_BIT_CAL_MODE | CPCAP_BIT_ATOX |
CPCAP_BIT_ATO3 | CPCAP_BIT_ATO2 |
CPCAP_BIT_ATO1 | CPCAP_BIT_ATO0 |
CPCAP_BIT_ADA2 | CPCAP_BIT_ADA1 |
CPCAP_BIT_ADA0 | CPCAP_BIT_AD_SEL1 |
CPCAP_BIT_RAND1 | CPCAP_BIT_RAND0,
value);
if (error)
return;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ATOX_PS_FACTOR |
CPCAP_BIT_ADC_PS_FACTOR1 |
CPCAP_BIT_ADC_PS_FACTOR0,
0);
if (error)
return;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ADTRIG_DIS,
CPCAP_BIT_ADTRIG_DIS);
if (error)
return;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ASC,
CPCAP_BIT_ASC);
if (error)
return;
do {
schedule_timeout_uninterruptible(1);
error = regmap_read(ddata->reg, CPCAP_REG_ADCC2, &value);
if (error)
return;
} while ((value & CPCAP_BIT_ASC) && time_before(jiffies, timeout));
if (value & CPCAP_BIT_ASC)
dev_err(ddata->dev,
"Timeout waiting for calibration to complete\n");
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC1,
CPCAP_BIT_CAL_MODE, 0);
if (error)
return;
}
static int cpcap_adc_calibrate_one(struct cpcap_adc *ddata,
int channel,
u16 calibration_register,
int lower_threshold,
int upper_threshold)
{
unsigned int calibration_data[2];
unsigned short cal_data_diff;
int i, error;
for (i = 0; i < CPCAP_ADC_MAX_RETRIES; i++) {
calibration_data[0] = 0;
calibration_data[1] = 0;
cal_data_diff = 0;
cpcap_adc_setup_calibrate(ddata, channel);
error = regmap_read(ddata->reg, calibration_register,
&calibration_data[0]);
if (error)
return error;
cpcap_adc_setup_calibrate(ddata, channel);
error = regmap_read(ddata->reg, calibration_register,
&calibration_data[1]);
if (error)
return error;
if (calibration_data[0] > calibration_data[1])
cal_data_diff =
calibration_data[0] - calibration_data[1];
else
cal_data_diff =
calibration_data[1] - calibration_data[0];
if (((calibration_data[1] >= lower_threshold) &&
(calibration_data[1] <= upper_threshold) &&
(cal_data_diff <= ST_ADC_CALIBRATE_DIFF_THRESHOLD)) ||
(ddata->vendor == CPCAP_VENDOR_TI)) {
bank_conversion[channel].cal_offset =
((short)calibration_data[1] * -1) + 512;
dev_dbg(ddata->dev, "ch%i calibration complete: %i\n",
channel, bank_conversion[channel].cal_offset);
break;
}
usleep_range(5000, 10000);
}
return 0;
}
static int cpcap_adc_calibrate(struct cpcap_adc *ddata)
{
int error;
error = cpcap_adc_calibrate_one(ddata, CPCAP_ADC_CHG_ISENSE,
CPCAP_REG_ADCAL1,
ST_ADC_CAL_CHRGI_LOW_THRESHOLD,
ST_ADC_CAL_CHRGI_HIGH_THRESHOLD);
if (error)
return error;
error = cpcap_adc_calibrate_one(ddata, CPCAP_ADC_BATTI,
CPCAP_REG_ADCAL2,
ST_ADC_CAL_BATTI_LOW_THRESHOLD,
ST_ADC_CAL_BATTI_HIGH_THRESHOLD);
if (error)
return error;
return 0;
}
static void cpcap_adc_setup_bank(struct cpcap_adc *ddata,
struct cpcap_adc_request *req)
{
const struct cpcap_adc_ato *ato = ddata->ato;
unsigned short value1 = 0;
unsigned short value2 = 0;
int error;
if (!ato)
return;
switch (req->channel) {
case CPCAP_ADC_AD0:
value2 |= CPCAP_BIT_THERMBIAS_EN;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_THERMBIAS_EN,
value2);
if (error)
return;
usleep_range(800, 1000);
break;
case CPCAP_ADC_AD8 ... CPCAP_ADC_TSY2_AD15:
value1 |= CPCAP_BIT_AD_SEL1;
break;
case CPCAP_ADC_BATTP_PI16 ... CPCAP_ADC_BATTI_PI17:
value1 |= CPCAP_BIT_RAND1;
default:
break;
}
switch (req->timing) {
case CPCAP_ADC_TIMING_IN:
value1 |= ato->ato_in;
value1 |= ato->atox_in;
value2 |= ato->adc_ps_factor_in;
value2 |= ato->atox_ps_factor_in;
break;
case CPCAP_ADC_TIMING_OUT:
value1 |= ato->ato_out;
value1 |= ato->atox_out;
value2 |= ato->adc_ps_factor_out;
value2 |= ato->atox_ps_factor_out;
break;
case CPCAP_ADC_TIMING_IMM:
default:
break;
}
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC1,
CPCAP_BIT_CAL_MODE | CPCAP_BIT_ATOX |
CPCAP_BIT_ATO3 | CPCAP_BIT_ATO2 |
CPCAP_BIT_ATO1 | CPCAP_BIT_ATO0 |
CPCAP_BIT_ADA2 | CPCAP_BIT_ADA1 |
CPCAP_BIT_ADA0 | CPCAP_BIT_AD_SEL1 |
CPCAP_BIT_RAND1 | CPCAP_BIT_RAND0,
value1);
if (error)
return;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ATOX_PS_FACTOR |
CPCAP_BIT_ADC_PS_FACTOR1 |
CPCAP_BIT_ADC_PS_FACTOR0 |
CPCAP_BIT_THERMBIAS_EN,
value2);
if (error)
return;
if (req->timing == CPCAP_ADC_TIMING_IMM) {
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ADTRIG_DIS,
CPCAP_BIT_ADTRIG_DIS);
if (error)
return;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ASC,
CPCAP_BIT_ASC);
if (error)
return;
} else {
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ADTRIG_ONESHOT,
CPCAP_BIT_ADTRIG_ONESHOT);
if (error)
return;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
CPCAP_BIT_ADTRIG_DIS, 0);
if (error)
return;
}
}
static int cpcap_adc_start_bank(struct cpcap_adc *ddata,
struct cpcap_adc_request *req)
{
int i, error;
req->timing = CPCAP_ADC_TIMING_IMM;
ddata->done = false;
for (i = 0; i < CPCAP_ADC_MAX_RETRIES; i++) {
cpcap_adc_setup_bank(ddata, req);
error = wait_event_interruptible_timeout(ddata->wq_data_avail,
ddata->done,
msecs_to_jiffies(50));
if (error > 0)
return 0;
if (error == 0) {
error = -ETIMEDOUT;
continue;
}
if (error < 0)
return error;
}
return error;
}
static int cpcap_adc_stop_bank(struct cpcap_adc *ddata)
{
int error;
error = regmap_update_bits(ddata->reg, CPCAP_REG_ADCC1,
0xffff,
CPCAP_REG_ADCC1_DEFAULTS);
if (error)
return error;
return regmap_update_bits(ddata->reg, CPCAP_REG_ADCC2,
0xffff,
CPCAP_REG_ADCC2_DEFAULTS);
}
static void cpcap_adc_phase(struct cpcap_adc_request *req)
{
const struct cpcap_adc_conversion_tbl *conv_tbl = req->conv_tbl;
const struct cpcap_adc_phasing_tbl *phase_tbl = req->phase_tbl;
int index = req->channel;
switch (req->channel) {
case CPCAP_ADC_BATTP:
case CPCAP_ADC_BATTP_PI16:
index = req->bank_index;
req->result -= phase_tbl[index].offset;
req->result -= CPCAP_FOUR_POINT_TWO_ADC;
req->result *= phase_tbl[index].multiplier;
if (phase_tbl[index].divider == 0)
return;
req->result /= phase_tbl[index].divider;
req->result += CPCAP_FOUR_POINT_TWO_ADC;
break;
case CPCAP_ADC_BATTI_PI17:
index = req->bank_index;
default:
req->result += conv_tbl[index].cal_offset;
req->result += conv_tbl[index].align_offset;
req->result *= phase_tbl[index].multiplier;
if (phase_tbl[index].divider == 0)
return;
req->result /= phase_tbl[index].divider;
req->result += phase_tbl[index].offset;
break;
}
if (req->result < phase_tbl[index].min)
req->result = phase_tbl[index].min;
else if (req->result > phase_tbl[index].max)
req->result = phase_tbl[index].max;
}
static int cpcap_adc_table_to_millicelcius(unsigned short value)
{
int i, result = 0, alpha;
if (value <= temp_map[CPCAP_MAX_TEMP_LVL - 1][0])
return temp_map[CPCAP_MAX_TEMP_LVL - 1][1];
if (value >= temp_map[0][0])
return temp_map[0][1];
for (i = 0; i < CPCAP_MAX_TEMP_LVL - 1; i++) {
if ((value <= temp_map[i][0]) &&
(value >= temp_map[i + 1][0])) {
if (value == temp_map[i][0]) {
result = temp_map[i][1];
} else if (value == temp_map[i + 1][0]) {
result = temp_map[i + 1][1];
} else {
alpha = ((value - temp_map[i][0]) * 1000) /
(temp_map[i + 1][0] - temp_map[i][0]);
result = temp_map[i][1] +
((alpha * (temp_map[i + 1][1] -
temp_map[i][1])) / 1000);
}
break;
}
}
return result;
}
static void cpcap_adc_convert(struct cpcap_adc_request *req)
{
const struct cpcap_adc_conversion_tbl *conv_tbl = req->conv_tbl;
int index = req->channel;
switch (req->channel) {
case CPCAP_ADC_BATTP_PI16:
index = CPCAP_ADC_BATTP;
break;
case CPCAP_ADC_BATTI_PI17:
index = CPCAP_ADC_BATTI;
break;
default:
break;
}
if (conv_tbl[index].conv_type == IIO_CHAN_INFO_RAW)
return;
if ((req->channel == CPCAP_ADC_AD0) ||
(req->channel == CPCAP_ADC_AD3)) {
req->result =
cpcap_adc_table_to_millicelcius(req->result);
return;
}
req->result *= conv_tbl[index].multiplier;
if (conv_tbl[index].divider == 0)
return;
req->result /= conv_tbl[index].divider;
req->result += conv_tbl[index].conv_offset;
}
static int cpcap_adc_read_bank_scaled(struct cpcap_adc *ddata,
struct cpcap_adc_request *req)
{
int calibration_data, error, addr;
if (ddata->vendor == CPCAP_VENDOR_TI) {
error = regmap_read(ddata->reg, CPCAP_REG_ADCAL1,
&calibration_data);
if (error)
return error;
bank_conversion[CPCAP_ADC_CHG_ISENSE].cal_offset =
((short)calibration_data * -1) + 512;
error = regmap_read(ddata->reg, CPCAP_REG_ADCAL2,
&calibration_data);
if (error)
return error;
bank_conversion[CPCAP_ADC_BATTI].cal_offset =
((short)calibration_data * -1) + 512;
}
addr = CPCAP_REG_ADCD0 + req->bank_index * 4;
error = regmap_read(ddata->reg, addr, &req->result);
if (error)
return error;
req->result &= 0x3ff;
cpcap_adc_phase(req);
cpcap_adc_convert(req);
return 0;
}
static int cpcap_adc_init_request(struct cpcap_adc_request *req,
int channel)
{
req->channel = channel;
req->phase_tbl = bank_phasing;
req->conv_tbl = bank_conversion;
switch (channel) {
case CPCAP_ADC_AD0 ... CPCAP_ADC_USB_ID:
req->bank_index = channel;
break;
case CPCAP_ADC_AD8 ... CPCAP_ADC_TSY2_AD15:
req->bank_index = channel - 8;
break;
case CPCAP_ADC_BATTP_PI16:
req->bank_index = CPCAP_ADC_BATTP;
break;
case CPCAP_ADC_BATTI_PI17:
req->bank_index = CPCAP_ADC_BATTI;
break;
default:
return -EINVAL;
}
return 0;
}
static int cpcap_adc_read_st_die_temp(struct cpcap_adc *ddata,
int addr, int *val)
{
int error;
error = regmap_read(ddata->reg, addr, val);
if (error)
return error;
*val -= 282;
*val *= 114;
*val += 25000;
return 0;
}
static int cpcap_adc_read(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct cpcap_adc *ddata = iio_priv(indio_dev);
struct cpcap_adc_request req;
int error;
error = cpcap_adc_init_request(&req, chan->channel);
if (error)
return error;
switch (mask) {
case IIO_CHAN_INFO_RAW:
mutex_lock(&ddata->lock);
error = cpcap_adc_start_bank(ddata, &req);
if (error)
goto err_unlock;
error = regmap_read(ddata->reg, chan->address, val);
if (error)
goto err_unlock;
error = cpcap_adc_stop_bank(ddata);
if (error)
goto err_unlock;
mutex_unlock(&ddata->lock);
break;
case IIO_CHAN_INFO_PROCESSED:
mutex_lock(&ddata->lock);
error = cpcap_adc_start_bank(ddata, &req);
if (error)
goto err_unlock;
if ((ddata->vendor == CPCAP_VENDOR_ST) &&
(chan->channel == CPCAP_ADC_AD3)) {
error = cpcap_adc_read_st_die_temp(ddata,
chan->address,
&req.result);
if (error)
goto err_unlock;
} else {
error = cpcap_adc_read_bank_scaled(ddata, &req);
if (error)
goto err_unlock;
}
error = cpcap_adc_stop_bank(ddata);
if (error)
goto err_unlock;
mutex_unlock(&ddata->lock);
*val = req.result;
break;
default:
return -EINVAL;
}
return IIO_VAL_INT;
err_unlock:
mutex_unlock(&ddata->lock);
dev_err(ddata->dev, "error reading ADC: %i\n", error);
return error;
}
static int cpcap_adc_probe(struct platform_device *pdev)
{
const struct of_device_id *match;
struct cpcap_adc *ddata;
struct iio_dev *indio_dev;
int error;
match = of_match_device(of_match_ptr(cpcap_adc_id_table),
&pdev->dev);
if (!match)
return -EINVAL;
if (!match->data) {
dev_err(&pdev->dev, "no configuration data found\n");
return -ENODEV;
}
indio_dev = devm_iio_device_alloc(&pdev->dev, sizeof(*ddata));
if (!indio_dev) {
dev_err(&pdev->dev, "failed to allocate iio device\n");
return -ENOMEM;
}
ddata = iio_priv(indio_dev);
ddata->ato = match->data;
ddata->dev = &pdev->dev;
mutex_init(&ddata->lock);
init_waitqueue_head(&ddata->wq_data_avail);
indio_dev->modes = INDIO_DIRECT_MODE | INDIO_BUFFER_SOFTWARE;
indio_dev->dev.parent = &pdev->dev;
indio_dev->dev.of_node = pdev->dev.of_node;
indio_dev->channels = cpcap_adc_channels;
indio_dev->num_channels = ARRAY_SIZE(cpcap_adc_channels);
indio_dev->name = dev_name(&pdev->dev);
indio_dev->info = &cpcap_adc_info;
ddata->reg = dev_get_regmap(pdev->dev.parent, NULL);
if (!ddata->reg)
return -ENODEV;
error = cpcap_get_vendor(ddata->dev, ddata->reg, &ddata->vendor);
if (error)
return error;
platform_set_drvdata(pdev, indio_dev);
ddata->irq = platform_get_irq_byname(pdev, "adcdone");
if (!ddata->irq)
return -ENODEV;
error = devm_request_threaded_irq(&pdev->dev, ddata->irq, NULL,
cpcap_adc_irq_thread,
IRQF_TRIGGER_NONE,
"cpcap-adc", indio_dev);
if (error) {
dev_err(&pdev->dev, "could not get irq: %i\n",
error);
return error;
}
error = cpcap_adc_calibrate(ddata);
if (error)
return error;
dev_info(&pdev->dev, "CPCAP ADC device probed\n");
return devm_iio_device_register(&pdev->dev, indio_dev);
}
