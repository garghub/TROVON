static int ad9523_read(struct iio_dev *indio_dev, unsigned addr)
{
struct ad9523_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer t[] = {
{
.tx_buf = &st->data[0].d8[2],
.len = 2,
}, {
.rx_buf = &st->data[1].d8[4 - AD9523_TRANSF_LEN(addr)],
.len = AD9523_TRANSF_LEN(addr),
},
};
st->data[0].d32 = cpu_to_be32(AD9523_READ |
AD9523_CNT(AD9523_TRANSF_LEN(addr)) |
AD9523_ADDR(addr));
ret = spi_sync_transfer(st->spi, t, ARRAY_SIZE(t));
if (ret < 0)
dev_err(&indio_dev->dev, "read failed (%d)", ret);
else
ret = be32_to_cpu(st->data[1].d32) & (0xFFFFFF >>
(8 * (3 - AD9523_TRANSF_LEN(addr))));
return ret;
}
static int ad9523_write(struct iio_dev *indio_dev, unsigned addr, unsigned val)
{
struct ad9523_state *st = iio_priv(indio_dev);
int ret;
struct spi_transfer t[] = {
{
.tx_buf = &st->data[0].d8[2],
.len = 2,
}, {
.tx_buf = &st->data[1].d8[4 - AD9523_TRANSF_LEN(addr)],
.len = AD9523_TRANSF_LEN(addr),
},
};
st->data[0].d32 = cpu_to_be32(AD9523_WRITE |
AD9523_CNT(AD9523_TRANSF_LEN(addr)) |
AD9523_ADDR(addr));
st->data[1].d32 = cpu_to_be32(val);
ret = spi_sync_transfer(st->spi, t, ARRAY_SIZE(t));
if (ret < 0)
dev_err(&indio_dev->dev, "write failed (%d)", ret);
return ret;
}
static int ad9523_io_update(struct iio_dev *indio_dev)
{
return ad9523_write(indio_dev, AD9523_IO_UPDATE, AD9523_IO_UPDATE_EN);
}
static int ad9523_vco_out_map(struct iio_dev *indio_dev,
unsigned ch, unsigned out)
{
struct ad9523_state *st = iio_priv(indio_dev);
int ret;
unsigned mask;
switch (ch) {
case 0 ... 3:
ret = ad9523_read(indio_dev, AD9523_PLL1_OUTPUT_CHANNEL_CTRL);
if (ret < 0)
break;
mask = AD9523_PLL1_OUTP_CH_CTRL_VCXO_SRC_SEL_CH0 << ch;
if (out) {
ret |= mask;
out = 2;
} else {
ret &= ~mask;
}
ret = ad9523_write(indio_dev,
AD9523_PLL1_OUTPUT_CHANNEL_CTRL, ret);
break;
case 4 ... 6:
ret = ad9523_read(indio_dev, AD9523_PLL1_OUTPUT_CTRL);
if (ret < 0)
break;
mask = AD9523_PLL1_OUTP_CTRL_VCO_DIV_SEL_CH4_M2 << (ch - 4);
if (out)
ret |= mask;
else
ret &= ~mask;
ret = ad9523_write(indio_dev, AD9523_PLL1_OUTPUT_CTRL, ret);
break;
case 7 ... 9:
ret = ad9523_read(indio_dev, AD9523_PLL1_OUTPUT_CHANNEL_CTRL);
if (ret < 0)
break;
mask = AD9523_PLL1_OUTP_CH_CTRL_VCO_DIV_SEL_CH7_M2 << (ch - 7);
if (out)
ret |= mask;
else
ret &= ~mask;
ret = ad9523_write(indio_dev,
AD9523_PLL1_OUTPUT_CHANNEL_CTRL, ret);
break;
default:
return 0;
}
st->vco_out_map[ch] = out;
return ret;
}
static int ad9523_set_clock_provider(struct iio_dev *indio_dev,
unsigned ch, unsigned long freq)
{
struct ad9523_state *st = iio_priv(indio_dev);
long tmp1, tmp2;
bool use_alt_clk_src;
switch (ch) {
case 0 ... 3:
use_alt_clk_src = (freq == st->vco_out_freq[AD9523_VCXO]);
break;
case 4 ... 9:
tmp1 = st->vco_out_freq[AD9523_VCO1] / freq;
tmp2 = st->vco_out_freq[AD9523_VCO2] / freq;
tmp1 *= freq;
tmp2 *= freq;
use_alt_clk_src = (abs(tmp1 - freq) > abs(tmp2 - freq));
break;
default:
return 0;
}
return ad9523_vco_out_map(indio_dev, ch, use_alt_clk_src);
}
static int ad9523_store_eeprom(struct iio_dev *indio_dev)
{
int ret, tmp;
ret = ad9523_write(indio_dev, AD9523_EEPROM_CTRL1,
AD9523_EEPROM_CTRL1_EEPROM_WRITE_PROT_DIS);
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_EEPROM_CTRL2,
AD9523_EEPROM_CTRL2_REG2EEPROM);
if (ret < 0)
return ret;
tmp = 4;
do {
msleep(16);
ret = ad9523_read(indio_dev,
AD9523_EEPROM_DATA_XFER_STATUS);
if (ret < 0)
return ret;
} while ((ret & AD9523_EEPROM_DATA_XFER_IN_PROGRESS) && tmp--);
ret = ad9523_write(indio_dev, AD9523_EEPROM_CTRL1, 0);
if (ret < 0)
return ret;
ret = ad9523_read(indio_dev, AD9523_EEPROM_ERROR_READBACK);
if (ret < 0)
return ret;
if (ret & AD9523_EEPROM_ERROR_READBACK_FAIL) {
dev_err(&indio_dev->dev, "Verify EEPROM failed");
ret = -EIO;
}
return ret;
}
static int ad9523_sync(struct iio_dev *indio_dev)
{
int ret, tmp;
ret = ad9523_read(indio_dev, AD9523_STATUS_SIGNALS);
if (ret < 0)
return ret;
tmp = ret;
tmp |= AD9523_STATUS_SIGNALS_SYNC_MAN_CTRL;
ret = ad9523_write(indio_dev, AD9523_STATUS_SIGNALS, tmp);
if (ret < 0)
return ret;
ad9523_io_update(indio_dev);
tmp &= ~AD9523_STATUS_SIGNALS_SYNC_MAN_CTRL;
ret = ad9523_write(indio_dev, AD9523_STATUS_SIGNALS, tmp);
if (ret < 0)
return ret;
return ad9523_io_update(indio_dev);
}
static ssize_t ad9523_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t len)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
bool state;
int ret;
ret = strtobool(buf, &state);
if (ret < 0)
return ret;
if (!state)
return 0;
mutex_lock(&indio_dev->mlock);
switch ((u32)this_attr->address) {
case AD9523_SYNC:
ret = ad9523_sync(indio_dev);
break;
case AD9523_EEPROM:
ret = ad9523_store_eeprom(indio_dev);
break;
default:
ret = -ENODEV;
}
mutex_unlock(&indio_dev->mlock);
return ret ? ret : len;
}
static ssize_t ad9523_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct iio_dev *indio_dev = dev_to_iio_dev(dev);
struct iio_dev_attr *this_attr = to_iio_dev_attr(attr);
int ret;
mutex_lock(&indio_dev->mlock);
ret = ad9523_read(indio_dev, AD9523_READBACK_0);
if (ret >= 0) {
ret = sprintf(buf, "%d\n", !!(ret & (1 <<
(u32)this_attr->address)));
}
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad9523_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val,
int *val2,
long m)
{
struct ad9523_state *st = iio_priv(indio_dev);
unsigned code;
int ret;
mutex_lock(&indio_dev->mlock);
ret = ad9523_read(indio_dev, AD9523_CHANNEL_CLOCK_DIST(chan->channel));
mutex_unlock(&indio_dev->mlock);
if (ret < 0)
return ret;
switch (m) {
case IIO_CHAN_INFO_RAW:
*val = !(ret & AD9523_CLK_DIST_PWR_DOWN_EN);
return IIO_VAL_INT;
case IIO_CHAN_INFO_FREQUENCY:
*val = st->vco_out_freq[st->vco_out_map[chan->channel]] /
AD9523_CLK_DIST_DIV_REV(ret);
return IIO_VAL_INT;
case IIO_CHAN_INFO_PHASE:
code = (AD9523_CLK_DIST_DIV_PHASE_REV(ret) * 3141592) /
AD9523_CLK_DIST_DIV_REV(ret);
*val = code / 1000000;
*val2 = (code % 1000000) * 10;
return IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
}
static int ad9523_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val,
int val2,
long mask)
{
struct ad9523_state *st = iio_priv(indio_dev);
unsigned reg;
int ret, tmp, code;
mutex_lock(&indio_dev->mlock);
ret = ad9523_read(indio_dev, AD9523_CHANNEL_CLOCK_DIST(chan->channel));
if (ret < 0)
goto out;
reg = ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
if (val)
reg &= ~AD9523_CLK_DIST_PWR_DOWN_EN;
else
reg |= AD9523_CLK_DIST_PWR_DOWN_EN;
break;
case IIO_CHAN_INFO_FREQUENCY:
if (val <= 0) {
ret = -EINVAL;
goto out;
}
ret = ad9523_set_clock_provider(indio_dev, chan->channel, val);
if (ret < 0)
goto out;
tmp = st->vco_out_freq[st->vco_out_map[chan->channel]] / val;
tmp = clamp(tmp, 1, 1024);
reg &= ~(0x3FF << 8);
reg |= AD9523_CLK_DIST_DIV(tmp);
break;
case IIO_CHAN_INFO_PHASE:
code = val * 1000000 + val2 % 1000000;
tmp = (code * AD9523_CLK_DIST_DIV_REV(ret)) / 3141592;
tmp = clamp(tmp, 0, 63);
reg &= ~AD9523_CLK_DIST_DIV_PHASE(~0);
reg |= AD9523_CLK_DIST_DIV_PHASE(tmp);
break;
default:
ret = -EINVAL;
goto out;
}
ret = ad9523_write(indio_dev, AD9523_CHANNEL_CLOCK_DIST(chan->channel),
reg);
if (ret < 0)
goto out;
ad9523_io_update(indio_dev);
out:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad9523_reg_access(struct iio_dev *indio_dev,
unsigned reg, unsigned writeval,
unsigned *readval)
{
int ret;
mutex_lock(&indio_dev->mlock);
if (readval == NULL) {
ret = ad9523_write(indio_dev, reg | AD9523_R1B, writeval);
ad9523_io_update(indio_dev);
} else {
ret = ad9523_read(indio_dev, reg | AD9523_R1B);
if (ret < 0)
goto out_unlock;
*readval = ret;
ret = 0;
}
out_unlock:
mutex_unlock(&indio_dev->mlock);
return ret;
}
static int ad9523_setup(struct iio_dev *indio_dev)
{
struct ad9523_state *st = iio_priv(indio_dev);
struct ad9523_platform_data *pdata = st->pdata;
struct ad9523_channel_spec *chan;
unsigned long active_mask = 0;
int ret, i;
ret = ad9523_write(indio_dev, AD9523_SERIAL_PORT_CONFIG,
AD9523_SER_CONF_SOFT_RESET |
(st->spi->mode & SPI_3WIRE ? 0 :
AD9523_SER_CONF_SDO_ACTIVE));
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_READBACK_CTRL,
AD9523_READBACK_CTRL_READ_BUFFERED);
if (ret < 0)
return ret;
ret = ad9523_io_update(indio_dev);
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL1_REF_A_DIVIDER,
pdata->refa_r_div);
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL1_REF_B_DIVIDER,
pdata->refb_r_div);
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL1_FEEDBACK_DIVIDER,
pdata->pll1_feedback_div);
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL1_CHARGE_PUMP_CTRL,
AD9523_PLL1_CHARGE_PUMP_CURRENT_nA(pdata->
pll1_charge_pump_current_nA) |
AD9523_PLL1_CHARGE_PUMP_MODE_NORMAL |
AD9523_PLL1_BACKLASH_PW_MIN);
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL1_INPUT_RECEIVERS_CTRL,
AD_IF(refa_diff_rcv_en, AD9523_PLL1_REFA_RCV_EN) |
AD_IF(refb_diff_rcv_en, AD9523_PLL1_REFB_RCV_EN) |
AD_IF(osc_in_diff_en, AD9523_PLL1_OSC_IN_DIFF_EN) |
AD_IF(osc_in_cmos_neg_inp_en,
AD9523_PLL1_OSC_IN_CMOS_NEG_INP_EN) |
AD_IF(refa_diff_rcv_en, AD9523_PLL1_REFA_DIFF_RCV_EN) |
AD_IF(refb_diff_rcv_en, AD9523_PLL1_REFB_DIFF_RCV_EN));
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL1_REF_CTRL,
AD_IF(zd_in_diff_en, AD9523_PLL1_ZD_IN_DIFF_EN) |
AD_IF(zd_in_cmos_neg_inp_en,
AD9523_PLL1_ZD_IN_CMOS_NEG_INP_EN) |
AD_IF(zero_delay_mode_internal_en,
AD9523_PLL1_ZERO_DELAY_MODE_INT) |
AD_IF(osc_in_feedback_en, AD9523_PLL1_OSC_IN_PLL_FEEDBACK_EN) |
AD_IF(refa_cmos_neg_inp_en, AD9523_PLL1_REFA_CMOS_NEG_INP_EN) |
AD_IF(refb_cmos_neg_inp_en, AD9523_PLL1_REFB_CMOS_NEG_INP_EN));
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL1_MISC_CTRL,
AD9523_PLL1_REFB_INDEP_DIV_CTRL_EN |
AD9523_PLL1_REF_MODE(pdata->ref_mode));
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL1_LOOP_FILTER_CTRL,
AD9523_PLL1_LOOP_FILTER_RZERO(pdata->pll1_loop_filter_rzero));
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL2_CHARGE_PUMP,
AD9523_PLL2_CHARGE_PUMP_CURRENT_nA(pdata->
pll2_charge_pump_current_nA));
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL2_FEEDBACK_DIVIDER_AB,
AD9523_PLL2_FB_NDIV_A_CNT(pdata->pll2_ndiv_a_cnt) |
AD9523_PLL2_FB_NDIV_B_CNT(pdata->pll2_ndiv_b_cnt));
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL2_CTRL,
AD9523_PLL2_CHARGE_PUMP_MODE_NORMAL |
AD9523_PLL2_BACKLASH_CTRL_EN |
AD_IF(pll2_freq_doubler_en, AD9523_PLL2_FREQ_DOUBLER_EN));
if (ret < 0)
return ret;
st->vco_freq = (pdata->vcxo_freq * (pdata->pll2_freq_doubler_en ? 2 : 1)
/ pdata->pll2_r2_div) * AD9523_PLL2_FB_NDIV(pdata->
pll2_ndiv_a_cnt, pdata->pll2_ndiv_b_cnt);
ret = ad9523_write(indio_dev, AD9523_PLL2_VCO_CTRL,
AD9523_PLL2_VCO_CALIBRATE);
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL2_VCO_DIVIDER,
AD9523_PLL2_VCO_DIV_M1(pdata->pll2_vco_diff_m1) |
AD9523_PLL2_VCO_DIV_M2(pdata->pll2_vco_diff_m2) |
AD_IFE(pll2_vco_diff_m1, 0,
AD9523_PLL2_VCO_DIV_M1_PWR_DOWN_EN) |
AD_IFE(pll2_vco_diff_m2, 0,
AD9523_PLL2_VCO_DIV_M2_PWR_DOWN_EN));
if (ret < 0)
return ret;
if (pdata->pll2_vco_diff_m1)
st->vco_out_freq[AD9523_VCO1] =
st->vco_freq / pdata->pll2_vco_diff_m1;
if (pdata->pll2_vco_diff_m2)
st->vco_out_freq[AD9523_VCO2] =
st->vco_freq / pdata->pll2_vco_diff_m2;
st->vco_out_freq[AD9523_VCXO] = pdata->vcxo_freq;
ret = ad9523_write(indio_dev, AD9523_PLL2_R2_DIVIDER,
AD9523_PLL2_R2_DIVIDER_VAL(pdata->pll2_r2_div));
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_PLL2_LOOP_FILTER_CTRL,
AD9523_PLL2_LOOP_FILTER_CPOLE1(pdata->cpole1) |
AD9523_PLL2_LOOP_FILTER_RZERO(pdata->rzero) |
AD9523_PLL2_LOOP_FILTER_RPOLE2(pdata->rpole2) |
AD_IF(rzero_bypass_en,
AD9523_PLL2_LOOP_FILTER_RZERO_BYPASS_EN));
if (ret < 0)
return ret;
for (i = 0; i < pdata->num_channels; i++) {
chan = &pdata->channels[i];
if (chan->channel_num < AD9523_NUM_CHAN) {
__set_bit(chan->channel_num, &active_mask);
ret = ad9523_write(indio_dev,
AD9523_CHANNEL_CLOCK_DIST(chan->channel_num),
AD9523_CLK_DIST_DRIVER_MODE(chan->driver_mode) |
AD9523_CLK_DIST_DIV(chan->channel_divider) |
AD9523_CLK_DIST_DIV_PHASE(chan->divider_phase) |
(chan->sync_ignore_en ?
AD9523_CLK_DIST_IGNORE_SYNC_EN : 0) |
(chan->divider_output_invert_en ?
AD9523_CLK_DIST_INV_DIV_OUTPUT_EN : 0) |
(chan->low_power_mode_en ?
AD9523_CLK_DIST_LOW_PWR_MODE_EN : 0) |
(chan->output_dis ?
AD9523_CLK_DIST_PWR_DOWN_EN : 0));
if (ret < 0)
return ret;
ret = ad9523_vco_out_map(indio_dev, chan->channel_num,
chan->use_alt_clock_src);
if (ret < 0)
return ret;
st->ad9523_channels[i].type = IIO_ALTVOLTAGE;
st->ad9523_channels[i].output = 1;
st->ad9523_channels[i].indexed = 1;
st->ad9523_channels[i].channel = chan->channel_num;
st->ad9523_channels[i].extend_name =
chan->extended_name;
st->ad9523_channels[i].info_mask =
IIO_CHAN_INFO_RAW_SEPARATE_BIT |
IIO_CHAN_INFO_PHASE_SEPARATE_BIT |
IIO_CHAN_INFO_FREQUENCY_SEPARATE_BIT;
}
}
for_each_clear_bit(i, &active_mask, AD9523_NUM_CHAN)
ad9523_write(indio_dev,
AD9523_CHANNEL_CLOCK_DIST(i),
AD9523_CLK_DIST_DRIVER_MODE(TRISTATE) |
AD9523_CLK_DIST_PWR_DOWN_EN);
ret = ad9523_write(indio_dev, AD9523_POWER_DOWN_CTRL, 0);
if (ret < 0)
return ret;
ret = ad9523_write(indio_dev, AD9523_STATUS_SIGNALS,
AD9523_STATUS_MONITOR_01_PLL12_LOCKED);
if (ret < 0)
return ret;
ret = ad9523_io_update(indio_dev);
if (ret < 0)
return ret;
return 0;
}
static int ad9523_probe(struct spi_device *spi)
{
struct ad9523_platform_data *pdata = spi->dev.platform_data;
struct iio_dev *indio_dev;
struct ad9523_state *st;
int ret;
if (!pdata) {
dev_err(&spi->dev, "no platform data?\n");
return -EINVAL;
}
indio_dev = iio_device_alloc(sizeof(*st));
if (indio_dev == NULL)
return -ENOMEM;
st = iio_priv(indio_dev);
st->reg = regulator_get(&spi->dev, "vcc");
if (!IS_ERR(st->reg)) {
ret = regulator_enable(st->reg);
if (ret)
goto error_put_reg;
}
spi_set_drvdata(spi, indio_dev);
st->spi = spi;
st->pdata = pdata;
indio_dev->dev.parent = &spi->dev;
indio_dev->name = (pdata->name[0] != 0) ? pdata->name :
spi_get_device_id(spi)->name;
indio_dev->info = &ad9523_info;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->channels = st->ad9523_channels;
indio_dev->num_channels = pdata->num_channels;
ret = ad9523_setup(indio_dev);
if (ret < 0)
goto error_disable_reg;
ret = iio_device_register(indio_dev);
if (ret)
goto error_disable_reg;
dev_info(&spi->dev, "probed %s\n", indio_dev->name);
return 0;
error_disable_reg:
if (!IS_ERR(st->reg))
regulator_disable(st->reg);
error_put_reg:
if (!IS_ERR(st->reg))
regulator_put(st->reg);
iio_device_free(indio_dev);
return ret;
}
static int ad9523_remove(struct spi_device *spi)
{
struct iio_dev *indio_dev = spi_get_drvdata(spi);
struct ad9523_state *st = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
if (!IS_ERR(st->reg)) {
regulator_disable(st->reg);
regulator_put(st->reg);
}
iio_device_free(indio_dev);
return 0;
}
