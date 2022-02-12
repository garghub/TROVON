static int max9611_read_single(struct max9611_dev *max9611,
enum max9611_conf_ids selector,
u16 *raw_val)
{
int ret;
u8 mux_conf = max9611_mux_conf[selector][0] & MAX9611_MUX_MASK;
u8 reg_addr = max9611_mux_conf[selector][1];
mutex_lock(&max9611->lock);
ret = i2c_smbus_write_byte_data(max9611->i2c_client,
MAX9611_REG_CTRL1, mux_conf);
if (ret) {
dev_err(max9611->dev, "i2c write byte failed: 0x%2x - 0x%2x\n",
MAX9611_REG_CTRL1, mux_conf);
mutex_unlock(&max9611->lock);
return ret;
}
usleep_range(1000, 2000);
ret = i2c_smbus_read_word_swapped(max9611->i2c_client, reg_addr);
if (ret < 0) {
dev_err(max9611->dev, "i2c read word from 0x%2x failed\n",
reg_addr);
mutex_unlock(&max9611->lock);
return ret;
}
*raw_val = ret;
mutex_unlock(&max9611->lock);
return 0;
}
static int max9611_read_csa_voltage(struct max9611_dev *max9611,
u16 *adc_raw,
enum max9611_csa_gain *csa_gain)
{
enum max9611_conf_ids gain_selectors[] = {
CONF_SENSE_1x,
CONF_SENSE_4x,
CONF_SENSE_8x
};
unsigned int i;
int ret;
for (i = 0; i < ARRAY_SIZE(gain_selectors); ++i) {
ret = max9611_read_single(max9611, gain_selectors[i], adc_raw);
if (ret)
return ret;
if (*adc_raw > 0) {
*csa_gain = gain_selectors[i];
return 0;
}
}
return -EIO;
}
static int max9611_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct max9611_dev *dev = iio_priv(indio_dev);
enum max9611_csa_gain gain_selector;
const unsigned int *csa_gain;
u16 adc_data;
int ret;
switch (mask) {
case IIO_CHAN_INFO_RAW:
switch (chan->address) {
case MAX9611_CHAN_TEMPERATURE:
ret = max9611_read_single(dev, CONF_TEMP,
&adc_data);
if (ret)
return -EINVAL;
*val = MAX9611_TEMP_RAW(adc_data);
return IIO_VAL_INT;
case MAX9611_CHAN_VOLTAGE_INPUT:
ret = max9611_read_single(dev, CONF_IN_VOLT,
&adc_data);
if (ret)
return -EINVAL;
*val = MAX9611_VOLTAGE_RAW(adc_data);
return IIO_VAL_INT;
}
break;
case IIO_CHAN_INFO_OFFSET:
*val = MAX9611_CIM_OFFSET_RAW;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
switch (chan->address) {
case MAX9611_CHAN_TEMPERATURE:
*val = MAX9611_TEMP_SCALE_NUM;
*val2 = MAX9611_TEMP_SCALE_DIV;
return IIO_VAL_FRACTIONAL;
case MAX9611_CHAN_VOLTAGE_INPUT:
*val = MAX9611_CIM_LSB_mV;
return IIO_VAL_INT;
}
break;
case IIO_CHAN_INFO_PROCESSED:
switch (chan->address) {
case MAX9611_CHAN_VOLTAGE_SENSE:
ret = max9611_read_csa_voltage(dev, &adc_data,
&gain_selector);
if (ret)
return -EINVAL;
csa_gain = max9611_gain_conf[gain_selector];
adc_data -= csa_gain[CSA_GAIN_OFFS_RAW];
*val = MAX9611_VOLTAGE_RAW(adc_data) *
csa_gain[CSA_GAIN_LSB_nV];
*val2 = 1000000;
return IIO_VAL_FRACTIONAL;
case MAX9611_CHAN_CURRENT_LOAD:
ret = max9611_read_csa_voltage(dev, &adc_data,
&gain_selector);
if (ret)
return -EINVAL;
csa_gain = max9611_gain_conf[gain_selector];
adc_data -= csa_gain[CSA_GAIN_OFFS_RAW];
*val = MAX9611_VOLTAGE_RAW(adc_data) *
csa_gain[CSA_GAIN_LSB_nV];
*val2 = dev->shunt_resistor_uohm;
return IIO_VAL_FRACTIONAL;
case MAX9611_CHAN_POWER_LOAD:
ret = max9611_read_single(dev, CONF_IN_VOLT,
&adc_data);
if (ret)
return -EINVAL;
adc_data -= MAX9611_CIM_OFFSET_RAW;
*val = MAX9611_VOLTAGE_RAW(adc_data) *
MAX9611_CIM_LSB_mV;
ret = max9611_read_csa_voltage(dev, &adc_data,
&gain_selector);
if (ret)
return -EINVAL;
csa_gain = max9611_gain_conf[gain_selector];
adc_data -= csa_gain[CSA_GAIN_OFFS_RAW];
*val *= MAX9611_VOLTAGE_RAW(adc_data) *
csa_gain[CSA_GAIN_LSB_nV] / 1000;
*val2 = dev->shunt_resistor_uohm;
return IIO_VAL_FRACTIONAL;
}
break;
}
return -EINVAL;
}
static ssize_t max9611_shunt_resistor_show(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct max9611_dev *max9611 = iio_priv(dev_to_iio_dev(dev));
unsigned int i, r;
i = max9611->shunt_resistor_uohm / 1000000;
r = max9611->shunt_resistor_uohm % 1000000;
return sprintf(buf, "%u.%06u\n", i, r);
}
static int max9611_init(struct max9611_dev *max9611)
{
struct i2c_client *client = max9611->i2c_client;
u16 regval;
int ret;
if (!i2c_check_functionality(client->adapter,
I2C_FUNC_SMBUS_WRITE_BYTE |
I2C_FUNC_SMBUS_READ_WORD_DATA)) {
dev_err(max9611->dev,
"I2c adapter does not support smbus write_byte or read_word functionalities: aborting probe.\n");
return -EINVAL;
}
ret = max9611_read_single(max9611, CONF_TEMP, &regval);
if (ret)
return ret;
regval = ret & MAX9611_TEMP_MASK;
if ((regval > MAX9611_TEMP_MAX_POS &&
regval < MAX9611_TEMP_MIN_NEG) ||
regval > MAX9611_TEMP_MAX_NEG) {
dev_err(max9611->dev,
"Invalid value received from ADC 0x%4x: aborting\n",
regval);
return -EIO;
}
ret = i2c_smbus_write_byte_data(max9611->i2c_client,
MAX9611_REG_CTRL1, 0);
if (ret) {
dev_err(max9611->dev, "i2c write byte failed: 0x%2x - 0x%2x\n",
MAX9611_REG_CTRL1, 0);
return ret;
}
ret = i2c_smbus_write_byte_data(max9611->i2c_client,
MAX9611_REG_CTRL2, 0);
if (ret) {
dev_err(max9611->dev, "i2c write byte failed: 0x%2x - 0x%2x\n",
MAX9611_REG_CTRL2, 0);
return ret;
}
usleep_range(1000, 2000);
return 0;
}
static int max9611_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
const char * const shunt_res_prop = "shunt-resistor-micro-ohms";
const struct device_node *of_node = client->dev.of_node;
const struct of_device_id *of_id =
of_match_device(max9611_of_table, &client->dev);
struct max9611_dev *max9611;
struct iio_dev *indio_dev;
unsigned int of_shunt;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*max9611));
if (!indio_dev)
return -ENOMEM;
i2c_set_clientdata(client, indio_dev);
max9611 = iio_priv(indio_dev);
max9611->dev = &client->dev;
max9611->i2c_client = client;
mutex_init(&max9611->lock);
ret = of_property_read_u32(of_node, shunt_res_prop, &of_shunt);
if (ret) {
dev_err(&client->dev,
"Missing %s property for %s node\n",
shunt_res_prop, of_node->full_name);
return ret;
}
max9611->shunt_resistor_uohm = of_shunt;
ret = max9611_init(max9611);
if (ret)
return ret;
indio_dev->dev.parent = &client->dev;
indio_dev->dev.of_node = client->dev.of_node;
indio_dev->name = of_id->data;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &indio_info;
indio_dev->channels = max9611_channels;
indio_dev->num_channels = ARRAY_SIZE(max9611_channels);
return devm_iio_device_register(&client->dev, indio_dev);
}
