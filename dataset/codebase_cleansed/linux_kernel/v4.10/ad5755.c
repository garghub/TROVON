static int ad5755_write_unlocked(struct iio_dev *indio_dev,
unsigned int reg, unsigned int val)
{
struct ad5755_state *st = iio_priv(indio_dev);
st->data[0].d32 = cpu_to_be32((reg << 16) | val);
return spi_write(st->spi, &st->data[0].d8[1], 3);
}
static int ad5755_write_ctrl_unlocked(struct iio_dev *indio_dev,
unsigned int channel, unsigned int reg, unsigned int val)
{
return ad5755_write_unlocked(indio_dev,
AD5755_WRITE_REG_CTRL(channel), (reg << 13) | val);
}
static int ad5755_write(struct iio_dev *indio_dev, unsigned int reg,
unsigned int val)
{
int ret;
mutex_lock(&indio_dev->mlock);
ret = ad5755_write_unlocked(indio_dev, reg, val);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad5755_write_ctrl(struct iio_dev *indio_dev, unsigned int channel,
unsigned int reg, unsigned int val)
{
int ret;
mutex_lock(&indio_dev->mlock);
ret = ad5755_write_ctrl_unlocked(indio_dev, channel, reg, val);
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad5755_read(struct iio_dev *indio_dev, unsigned int addr)
{
struct ad5755_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer t[] = {
{
.tx_buf = &st->data[0].d8[1],
.len = 3,
.cs_change = 1,
}, {
.tx_buf = &st->data[1].d8[1],
.rx_buf = &st->data[1].d8[1],
.len = 3,
},
};
mutex_lock(&indio_dev->mlock);
st->data[0].d32 = cpu_to_be32(AD5755_READ_FLAG | (addr << 16));
st->data[1].d32 = cpu_to_be32(AD5755_NOOP);
ret = spi_sync_transfer(st->spi, t, ARRAY_SIZE(t));
if (ret >= 0)
ret = be32_to_cpu(st->data[1].d32) & 0xffff;
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad5755_update_dac_ctrl(struct iio_dev *indio_dev,
unsigned int channel, unsigned int set, unsigned int clr)
{
struct ad5755_state *st = iio_priv(indio_dev);
int ret;
st->ctrl[channel] |= set;
st->ctrl[channel] &= ~clr;
ret = ad5755_write_ctrl_unlocked(indio_dev, channel,
AD5755_CTRL_REG_DAC, st->ctrl[channel]);
return ret;
}
static int ad5755_set_channel_pwr_down(struct iio_dev *indio_dev,
unsigned int channel, bool pwr_down)
{
struct ad5755_state *st = iio_priv(indio_dev);
unsigned int mask = BIT(channel);
mutex_lock(&indio_dev->mlock);
if ((bool)(st->pwr_down & mask) == pwr_down)
goto out_unlock;
if (!pwr_down) {
st->pwr_down &= ~mask;
ad5755_update_dac_ctrl(indio_dev, channel,
AD5755_DAC_INT_EN | AD5755_DAC_DC_DC_EN, 0);
udelay(200);
ad5755_update_dac_ctrl(indio_dev, channel,
AD5755_DAC_OUT_EN, 0);
} else {
st->pwr_down |= mask;
ad5755_update_dac_ctrl(indio_dev, channel,
0, AD5755_DAC_INT_EN | AD5755_DAC_OUT_EN |
AD5755_DAC_DC_DC_EN);
}
out_unlock:
mutex_unlock(&indio_dev->mlock);
return 0;
}
static void ad5755_get_min_max(struct ad5755_state *st,
struct iio_chan_spec const *chan, int *min, int *max)
{
enum ad5755_mode mode = st->ctrl[chan->channel] & 7;
*min = ad5755_min_max_table[mode][0];
*max = ad5755_min_max_table[mode][1];
}
static inline int ad5755_get_offset(struct ad5755_state *st,
struct iio_chan_spec const *chan)
{
int min, max;
ad5755_get_min_max(st, chan, &min, &max);
return (min * (1 << chan->scan_type.realbits)) / (max - min);
}
static int ad5755_chan_reg_info(struct ad5755_state *st,
struct iio_chan_spec const *chan, long info, bool write,
unsigned int *reg, unsigned int *shift, unsigned int *offset)
{
switch (info) {
case IIO_CHAN_INFO_RAW:
if (write)
*reg = AD5755_WRITE_REG_DATA(chan->address);
else
*reg = AD5755_READ_REG_DATA(chan->address);
*shift = chan->scan_type.shift;
*offset = 0;
break;
case IIO_CHAN_INFO_CALIBBIAS:
if (write)
*reg = AD5755_WRITE_REG_OFFSET(chan->address);
else
*reg = AD5755_READ_REG_OFFSET(chan->address);
*shift = st->chip_info->calib_shift;
*offset = 32768;
break;
case IIO_CHAN_INFO_CALIBSCALE:
if (write)
*reg = AD5755_WRITE_REG_GAIN(chan->address);
else
*reg = AD5755_READ_REG_GAIN(chan->address);
*shift = st->chip_info->calib_shift;
*offset = 0;
break;
default:
return -EINVAL;
}
return 0;
}
static int ad5755_read_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int *val, int *val2, long info)
{
struct ad5755_state *st = iio_priv(indio_dev);
unsigned int reg, shift, offset;
int min, max;
int ret;
switch (info) {
case IIO_CHAN_INFO_SCALE:
ad5755_get_min_max(st, chan, &min, &max);
*val = max - min;
*val2 = chan->scan_type.realbits;
return IIO_VAL_FRACTIONAL_LOG2;
case IIO_CHAN_INFO_OFFSET:
*val = ad5755_get_offset(st, chan);
return IIO_VAL_INT;
default:
ret = ad5755_chan_reg_info(st, chan, info, false,
&reg, &shift, &offset);
if (ret)
return ret;
ret = ad5755_read(indio_dev, reg);
if (ret < 0)
return ret;
*val = (ret - offset) >> shift;
return IIO_VAL_INT;
}
return -EINVAL;
}
static int ad5755_write_raw(struct iio_dev *indio_dev,
const struct iio_chan_spec *chan, int val, int val2, long info)
{
struct ad5755_state *st = iio_priv(indio_dev);
unsigned int shift, reg, offset;
int ret;
ret = ad5755_chan_reg_info(st, chan, info, true,
&reg, &shift, &offset);
if (ret)
return ret;
val <<= shift;
val += offset;
if (val < 0 || val > 0xffff)
return -EINVAL;
return ad5755_write(indio_dev, reg, val);
}
static ssize_t ad5755_read_powerdown(struct iio_dev *indio_dev, uintptr_t priv,
const struct iio_chan_spec *chan, char *buf)
{
struct ad5755_state *st = iio_priv(indio_dev);
return sprintf(buf, "%d\n",
(bool)(st->pwr_down & (1 << chan->channel)));
}
static ssize_t ad5755_write_powerdown(struct iio_dev *indio_dev, uintptr_t priv,
struct iio_chan_spec const *chan, const char *buf, size_t len)
{
bool pwr_down;
int ret;
ret = strtobool(buf, &pwr_down);
if (ret)
return ret;
ret = ad5755_set_channel_pwr_down(indio_dev, chan->channel, pwr_down);
return ret ? ret : len;
}
static bool ad5755_is_valid_mode(struct ad5755_state *st, enum ad5755_mode mode)
{
switch (mode) {
case AD5755_MODE_VOLTAGE_0V_5V:
case AD5755_MODE_VOLTAGE_0V_10V:
case AD5755_MODE_VOLTAGE_PLUSMINUS_5V:
case AD5755_MODE_VOLTAGE_PLUSMINUS_10V:
return st->chip_info->has_voltage_out;
case AD5755_MODE_CURRENT_4mA_20mA:
case AD5755_MODE_CURRENT_0mA_20mA:
case AD5755_MODE_CURRENT_0mA_24mA:
return true;
default:
return false;
}
}
static int ad5755_setup_pdata(struct iio_dev *indio_dev,
const struct ad5755_platform_data *pdata)
{
struct ad5755_state *st = iio_priv(indio_dev);
unsigned int val;
unsigned int i;
int ret;
if (pdata->dc_dc_phase > AD5755_DC_DC_PHASE_90_DEGREE ||
pdata->dc_dc_freq > AD5755_DC_DC_FREQ_650kHZ ||
pdata->dc_dc_maxv > AD5755_DC_DC_MAXV_29V5)
return -EINVAL;
val = pdata->dc_dc_maxv << AD5755_DC_DC_MAXV;
val |= pdata->dc_dc_freq << AD5755_DC_DC_FREQ_SHIFT;
val |= pdata->dc_dc_phase << AD5755_DC_DC_PHASE_SHIFT;
if (pdata->ext_dc_dc_compenstation_resistor)
val |= AD5755_EXT_DC_DC_COMP_RES;
ret = ad5755_write_ctrl(indio_dev, 0, AD5755_CTRL_REG_DC_DC, val);
if (ret < 0)
return ret;
for (i = 0; i < ARRAY_SIZE(pdata->dac); ++i) {
val = pdata->dac[i].slew.step_size <<
AD5755_SLEW_STEP_SIZE_SHIFT;
val |= pdata->dac[i].slew.rate <<
AD5755_SLEW_RATE_SHIFT;
if (pdata->dac[i].slew.enable)
val |= AD5755_SLEW_ENABLE;
ret = ad5755_write_ctrl(indio_dev, i,
AD5755_CTRL_REG_SLEW, val);
if (ret < 0)
return ret;
}
for (i = 0; i < ARRAY_SIZE(pdata->dac); ++i) {
if (!ad5755_is_valid_mode(st, pdata->dac[i].mode))
return -EINVAL;
val = 0;
if (!pdata->dac[i].ext_current_sense_resistor)
val |= AD5755_DAC_INT_CURRENT_SENSE_RESISTOR;
if (pdata->dac[i].enable_voltage_overrange)
val |= AD5755_DAC_VOLTAGE_OVERRANGE_EN;
val |= pdata->dac[i].mode;
ret = ad5755_update_dac_ctrl(indio_dev, i, val, 0);
if (ret < 0)
return ret;
}
return 0;
}
static bool ad5755_is_voltage_mode(enum ad5755_mode mode)
{
switch (mode) {
case AD5755_MODE_VOLTAGE_0V_5V:
case AD5755_MODE_VOLTAGE_0V_10V:
case AD5755_MODE_VOLTAGE_PLUSMINUS_5V:
case AD5755_MODE_VOLTAGE_PLUSMINUS_10V:
return true;
default:
return false;
}
}
static int ad5755_init_channels(struct iio_dev *indio_dev,
const struct ad5755_platform_data *pdata)
{
struct ad5755_state *st = iio_priv(indio_dev);
struct iio_chan_spec *channels = st->channels;
unsigned int i;
for (i = 0; i < AD5755_NUM_CHANNELS; ++i) {
channels[i] = st->chip_info->channel_template;
channels[i].channel = i;
channels[i].address = i;
if (pdata && ad5755_is_voltage_mode(pdata->dac[i].mode))
channels[i].type = IIO_VOLTAGE;
else
channels[i].type = IIO_CURRENT;
}
indio_dev->channels = channels;
return 0;
}
static struct ad5755_platform_data *ad5755_parse_dt(struct device *dev)
{
struct device_node *np = dev->of_node;
struct device_node *pp;
struct ad5755_platform_data *pdata;
unsigned int tmp;
unsigned int tmparray[3];
int devnr, i;
pdata = devm_kzalloc(dev, sizeof(*pdata), GFP_KERNEL);
if (!pdata)
return NULL;
pdata->ext_dc_dc_compenstation_resistor =
of_property_read_bool(np, "adi,ext-dc-dc-compenstation-resistor");
if (!of_property_read_u32(np, "adi,dc-dc-phase", &tmp))
pdata->dc_dc_phase = tmp;
else
pdata->dc_dc_phase = AD5755_DC_DC_PHASE_ALL_SAME_EDGE;
pdata->dc_dc_freq = AD5755_DC_DC_FREQ_410kHZ;
if (!of_property_read_u32(np, "adi,dc-dc-freq-hz", &tmp)) {
for (i = 0; i < ARRAY_SIZE(ad5755_dcdc_freq_table); i++) {
if (tmp == ad5755_dcdc_freq_table[i][0]) {
pdata->dc_dc_freq = ad5755_dcdc_freq_table[i][1];
break;
}
}
if (i == ARRAY_SIZE(ad5755_dcdc_freq_table)) {
dev_err(dev,
"adi,dc-dc-freq out of range selecting 410kHz");
}
}
pdata->dc_dc_maxv = AD5755_DC_DC_MAXV_23V;
if (!of_property_read_u32(np, "adi,dc-dc-max-microvolt", &tmp)) {
for (i = 0; i < ARRAY_SIZE(ad5755_dcdc_maxv_table); i++) {
if (tmp == ad5755_dcdc_maxv_table[i][0]) {
pdata->dc_dc_maxv = ad5755_dcdc_maxv_table[i][1];
break;
}
}
if (i == ARRAY_SIZE(ad5755_dcdc_maxv_table)) {
dev_err(dev,
"adi,dc-dc-maxv out of range selecting 23V");
}
}
devnr = 0;
for_each_child_of_node(np, pp) {
if (devnr >= AD5755_NUM_CHANNELS) {
dev_err(dev,
"There is to many channels defined in DT\n");
goto error_out;
}
if (!of_property_read_u32(pp, "adi,mode", &tmp))
pdata->dac[devnr].mode = tmp;
else
pdata->dac[devnr].mode = AD5755_MODE_CURRENT_4mA_20mA;
pdata->dac[devnr].ext_current_sense_resistor =
of_property_read_bool(pp, "adi,ext-current-sense-resistor");
pdata->dac[devnr].enable_voltage_overrange =
of_property_read_bool(pp, "adi,enable-voltage-overrange");
if (!of_property_read_u32_array(pp, "adi,slew", tmparray, 3)) {
pdata->dac[devnr].slew.enable = tmparray[0];
pdata->dac[devnr].slew.rate = AD5755_SLEW_RATE_64k;
for (i = 0; i < ARRAY_SIZE(ad5755_slew_rate_table); i++) {
if (tmparray[1] == ad5755_slew_rate_table[i][0]) {
pdata->dac[devnr].slew.rate =
ad5755_slew_rate_table[i][1];
break;
}
}
if (i == ARRAY_SIZE(ad5755_slew_rate_table)) {
dev_err(dev,
"channel %d slew rate out of range selecting 64kHz",
devnr);
}
pdata->dac[devnr].slew.step_size = AD5755_SLEW_STEP_SIZE_1;
for (i = 0; i < ARRAY_SIZE(ad5755_slew_step_table); i++) {
if (tmparray[2] == ad5755_slew_step_table[i][0]) {
pdata->dac[devnr].slew.step_size =
ad5755_slew_step_table[i][1];
break;
}
}
if (i == ARRAY_SIZE(ad5755_slew_step_table)) {
dev_err(dev,
"channel %d slew step size out of range selecting 1 LSB",
devnr);
}
} else {
pdata->dac[devnr].slew.enable = false;
pdata->dac[devnr].slew.rate = AD5755_SLEW_RATE_64k;
pdata->dac[devnr].slew.step_size =
AD5755_SLEW_STEP_SIZE_1;
}
devnr++;
}
return pdata;
error_out:
devm_kfree(dev, pdata);
return NULL;
}
static
struct ad5755_platform_data *ad5755_parse_dt(struct device *dev)
{
return NULL;
}
static int ad5755_probe(struct spi_device *spi)
{
enum ad5755_type type = spi_get_device_id(spi)->driver_data;
const struct ad5755_platform_data *pdata = dev_get_platdata(&spi->dev);
struct iio_dev *indio_dev;
struct ad5755_state *st;
int ret;
indio_dev = devm_iio_device_alloc(&spi->dev, sizeof(*st));
if (indio_dev == NULL) {
dev_err(&spi->dev, "Failed to allocate iio device\n");
return -ENOMEM;
}
st = iio_priv(indio_dev);
spi_set_drvdata(spi, indio_dev);
st->chip_info = &ad5755_chip_info_tbl[type];
st->spi = spi;
st->pwr_down = 0xf;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = spi_get_device_id(spi)->name;
indio_dev->info = &ad5755_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->num_channels = AD5755_NUM_CHANNELS;
if (spi->dev.of_node)
pdata = ad5755_parse_dt(&spi->dev);
else
pdata = spi->dev.platform_data;
if (!pdata) {
dev_warn(&spi->dev, "no platform data? using default\n");
pdata = &ad5755_default_pdata;
}
ret = ad5755_init_channels(indio_dev, pdata);
if (ret)
return ret;
ret = ad5755_setup_pdata(indio_dev, pdata);
if (ret)
return ret;
return devm_iio_device_register(&spi->dev, indio_dev);
}
