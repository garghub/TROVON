static int isl29028_set_proxim_sampling(struct isl29028_chip *chip,
unsigned int sampling)
{
struct device *dev = regmap_get_device(chip->regmap);
static unsigned int prox_period[] = {800, 400, 200, 100, 75, 50, 12, 0};
unsigned int period = DIV_ROUND_UP(1000, sampling);
int sel, ret;
for (sel = 0; sel < ARRAY_SIZE(prox_period); ++sel) {
if (period >= prox_period[sel])
break;
}
ret = regmap_update_bits(chip->regmap, ISL29028_REG_CONFIGURE,
ISL29028_CONF_PROX_SLP_MASK,
sel << ISL29028_CONF_PROX_SLP_SH);
if (ret < 0) {
dev_err(dev, "%s(): Error %d setting the proximity sampling\n",
__func__, ret);
return ret;
}
chip->prox_sampling = sampling;
return ret;
}
static int isl29028_enable_proximity(struct isl29028_chip *chip)
{
int ret;
ret = isl29028_set_proxim_sampling(chip, chip->prox_sampling);
if (ret < 0)
return ret;
ret = regmap_update_bits(chip->regmap, ISL29028_REG_CONFIGURE,
ISL29028_CONF_PROX_EN_MASK,
ISL29028_CONF_PROX_EN);
if (ret < 0)
return ret;
mdelay(DIV_ROUND_UP(1000, chip->prox_sampling));
return 0;
}
static int isl29028_set_als_scale(struct isl29028_chip *chip, int lux_scale)
{
struct device *dev = regmap_get_device(chip->regmap);
int val = (lux_scale == 2000) ? ISL29028_CONF_ALS_RANGE_HIGH_LUX :
ISL29028_CONF_ALS_RANGE_LOW_LUX;
int ret;
ret = regmap_update_bits(chip->regmap, ISL29028_REG_CONFIGURE,
ISL29028_CONF_ALS_RANGE_MASK, val);
if (ret < 0) {
dev_err(dev, "%s(): Error %d setting the ALS scale\n", __func__,
ret);
return ret;
}
chip->lux_scale = lux_scale;
return ret;
}
static int isl29028_set_als_ir_mode(struct isl29028_chip *chip,
enum isl29028_als_ir_mode mode)
{
int ret;
if (chip->als_ir_mode == mode)
return 0;
ret = isl29028_set_als_scale(chip, chip->lux_scale);
if (ret < 0)
return ret;
switch (mode) {
case ISL29028_MODE_ALS:
ret = regmap_update_bits(chip->regmap, ISL29028_REG_CONFIGURE,
ISL29028_CONF_ALS_IR_MODE_MASK,
ISL29028_CONF_ALS_IR_MODE_ALS);
if (ret < 0)
return ret;
ret = regmap_update_bits(chip->regmap, ISL29028_REG_CONFIGURE,
ISL29028_CONF_ALS_RANGE_MASK,
ISL29028_CONF_ALS_RANGE_HIGH_LUX);
break;
case ISL29028_MODE_IR:
ret = regmap_update_bits(chip->regmap, ISL29028_REG_CONFIGURE,
ISL29028_CONF_ALS_IR_MODE_MASK,
ISL29028_CONF_ALS_IR_MODE_IR);
break;
case ISL29028_MODE_NONE:
return regmap_update_bits(chip->regmap, ISL29028_REG_CONFIGURE,
ISL29028_CONF_ALS_EN_MASK,
ISL29028_CONF_ALS_DIS);
}
if (ret < 0)
return ret;
ret = regmap_update_bits(chip->regmap, ISL29028_REG_CONFIGURE,
ISL29028_CONF_ALS_EN_MASK,
ISL29028_CONF_ALS_EN);
if (ret < 0)
return ret;
mdelay(ISL29028_CONV_TIME_MS);
chip->als_ir_mode = mode;
return 0;
}
static int isl29028_read_als_ir(struct isl29028_chip *chip, int *als_ir)
{
struct device *dev = regmap_get_device(chip->regmap);
unsigned int lsb;
unsigned int msb;
int ret;
ret = regmap_read(chip->regmap, ISL29028_REG_ALSIR_L, &lsb);
if (ret < 0) {
dev_err(dev,
"%s(): Error %d reading register ALSIR_L\n",
__func__, ret);
return ret;
}
ret = regmap_read(chip->regmap, ISL29028_REG_ALSIR_U, &msb);
if (ret < 0) {
dev_err(dev,
"%s(): Error %d reading register ALSIR_U\n",
__func__, ret);
return ret;
}
*als_ir = ((msb & 0xF) << 8) | (lsb & 0xFF);
return 0;
}
static int isl29028_read_proxim(struct isl29028_chip *chip, int *prox)
{
struct device *dev = regmap_get_device(chip->regmap);
unsigned int data;
int ret;
if (!chip->enable_prox) {
ret = isl29028_enable_proximity(chip);
if (ret < 0)
return ret;
chip->enable_prox = true;
}
ret = regmap_read(chip->regmap, ISL29028_REG_PROX_DATA, &data);
if (ret < 0) {
dev_err(dev, "%s(): Error %d reading register PROX_DATA\n",
__func__, ret);
return ret;
}
*prox = data;
return 0;
}
static int isl29028_als_get(struct isl29028_chip *chip, int *als_data)
{
struct device *dev = regmap_get_device(chip->regmap);
int ret;
int als_ir_data;
ret = isl29028_set_als_ir_mode(chip, ISL29028_MODE_ALS);
if (ret < 0) {
dev_err(dev, "%s(): Error %d enabling ALS mode\n", __func__,
ret);
return ret;
}
ret = isl29028_read_als_ir(chip, &als_ir_data);
if (ret < 0)
return ret;
if (chip->lux_scale == 125)
als_ir_data = (als_ir_data * 31) / 1000;
else
als_ir_data = (als_ir_data * 49) / 100;
*als_data = als_ir_data;
return 0;
}
static int isl29028_ir_get(struct isl29028_chip *chip, int *ir_data)
{
struct device *dev = regmap_get_device(chip->regmap);
int ret;
ret = isl29028_set_als_ir_mode(chip, ISL29028_MODE_IR);
if (ret < 0) {
dev_err(dev, "%s(): Error %d enabling IR mode\n", __func__,
ret);
return ret;
}
return isl29028_read_als_ir(chip, ir_data);
}
static int isl29028_set_pm_runtime_busy(struct isl29028_chip *chip, bool on)
{
struct device *dev = regmap_get_device(chip->regmap);
int ret;
if (on) {
ret = pm_runtime_get_sync(dev);
if (ret < 0)
pm_runtime_put_noidle(dev);
} else {
pm_runtime_mark_last_busy(dev);
ret = pm_runtime_put_autosuspend(dev);
}
return ret;
}
static int isl29028_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct isl29028_chip *chip = iio_priv(indio_dev);
struct device *dev = regmap_get_device(chip->regmap);
int ret;
ret = isl29028_set_pm_runtime_busy(chip, true);
if (ret < 0)
return ret;
mutex_lock(&chip->lock);
ret = -EINVAL;
switch (chan->type) {
case IIO_PROXIMITY:
if (mask != IIO_CHAN_INFO_SAMP_FREQ) {
dev_err(dev,
"%s(): proximity: Mask value 0x%08lx is not supported\n",
__func__, mask);
break;
}
if (val < 1 || val > 100) {
dev_err(dev,
"%s(): proximity: Sampling frequency %d is not in the range [1:100]\n",
__func__, val);
break;
}
ret = isl29028_set_proxim_sampling(chip, val);
break;
case IIO_LIGHT:
if (mask != IIO_CHAN_INFO_SCALE) {
dev_err(dev,
"%s(): light: Mask value 0x%08lx is not supported\n",
__func__, mask);
break;
}
if (val != 125 && val != 2000) {
dev_err(dev,
"%s(): light: Lux scale %d is not in the set {125, 2000}\n",
__func__, val);
break;
}
ret = isl29028_set_als_scale(chip, val);
break;
default:
dev_err(dev, "%s(): Unsupported channel type %x\n",
__func__, chan->type);
break;
}
mutex_unlock(&chip->lock);
if (ret < 0)
return ret;
ret = isl29028_set_pm_runtime_busy(chip, false);
if (ret < 0)
return ret;
return ret;
}
static int isl29028_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
struct isl29028_chip *chip = iio_priv(indio_dev);
struct device *dev = regmap_get_device(chip->regmap);
int ret, pm_ret;
ret = isl29028_set_pm_runtime_busy(chip, true);
if (ret < 0)
return ret;
mutex_lock(&chip->lock);
ret = -EINVAL;
switch (mask) {
case IIO_CHAN_INFO_RAW:
case IIO_CHAN_INFO_PROCESSED:
switch (chan->type) {
case IIO_LIGHT:
ret = isl29028_als_get(chip, val);
break;
case IIO_INTENSITY:
ret = isl29028_ir_get(chip, val);
break;
case IIO_PROXIMITY:
ret = isl29028_read_proxim(chip, val);
break;
default:
break;
}
if (ret < 0)
break;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SAMP_FREQ:
if (chan->type != IIO_PROXIMITY)
break;
*val = chip->prox_sampling;
ret = IIO_VAL_INT;
break;
case IIO_CHAN_INFO_SCALE:
if (chan->type != IIO_LIGHT)
break;
*val = chip->lux_scale;
ret = IIO_VAL_INT;
break;
default:
dev_err(dev, "%s(): mask value 0x%08lx is not supported\n",
__func__, mask);
break;
}
mutex_unlock(&chip->lock);
if (ret < 0)
return ret;
pm_ret = isl29028_set_pm_runtime_busy(chip, false);
if (pm_ret < 0)
return pm_ret;
return ret;
}
static int isl29028_clear_configure_reg(struct isl29028_chip *chip)
{
struct device *dev = regmap_get_device(chip->regmap);
int ret;
ret = regmap_write(chip->regmap, ISL29028_REG_CONFIGURE, 0x0);
if (ret < 0)
dev_err(dev, "%s(): Error %d clearing the CONFIGURE register\n",
__func__, ret);
chip->als_ir_mode = ISL29028_MODE_NONE;
chip->enable_prox = false;
return ret;
}
static bool isl29028_is_volatile_reg(struct device *dev, unsigned int reg)
{
switch (reg) {
case ISL29028_REG_INTERRUPT:
case ISL29028_REG_PROX_DATA:
case ISL29028_REG_ALSIR_L:
case ISL29028_REG_ALSIR_U:
return true;
default:
return false;
}
}
static int isl29028_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct isl29028_chip *chip;
struct iio_dev *indio_dev;
int ret;
indio_dev = devm_iio_device_alloc(&client->dev, sizeof(*chip));
if (!indio_dev)
return -ENOMEM;
chip = iio_priv(indio_dev);
i2c_set_clientdata(client, indio_dev);
mutex_init(&chip->lock);
chip->regmap = devm_regmap_init_i2c(client, &isl29028_regmap_config);
if (IS_ERR(chip->regmap)) {
ret = PTR_ERR(chip->regmap);
dev_err(&client->dev, "%s: Error %d initializing regmap\n",
__func__, ret);
return ret;
}
chip->enable_prox = false;
chip->prox_sampling = 20;
chip->lux_scale = 2000;
ret = regmap_write(chip->regmap, ISL29028_REG_TEST1_MODE, 0x0);
if (ret < 0) {
dev_err(&client->dev,
"%s(): Error %d writing to TEST1_MODE register\n",
__func__, ret);
return ret;
}
ret = regmap_write(chip->regmap, ISL29028_REG_TEST2_MODE, 0x0);
if (ret < 0) {
dev_err(&client->dev,
"%s(): Error %d writing to TEST2_MODE register\n",
__func__, ret);
return ret;
}
ret = isl29028_clear_configure_reg(chip);
if (ret < 0)
return ret;
indio_dev->info = &isl29028_info;
indio_dev->channels = isl29028_channels;
indio_dev->num_channels = ARRAY_SIZE(isl29028_channels);
indio_dev->name = id->name;
indio_dev->dev.parent = &client->dev;
indio_dev->modes = INDIO_DIRECT_MODE;
pm_runtime_enable(&client->dev);
pm_runtime_set_autosuspend_delay(&client->dev,
ISL29028_POWER_OFF_DELAY_MS);
pm_runtime_use_autosuspend(&client->dev);
ret = devm_iio_device_register(indio_dev->dev.parent, indio_dev);
if (ret < 0) {
dev_err(&client->dev,
"%s(): iio registration failed with error %d\n",
__func__, ret);
return ret;
}
return 0;
}
static int isl29028_remove(struct i2c_client *client)
{
struct iio_dev *indio_dev = i2c_get_clientdata(client);
struct isl29028_chip *chip = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
pm_runtime_disable(&client->dev);
pm_runtime_set_suspended(&client->dev);
pm_runtime_put_noidle(&client->dev);
return isl29028_clear_configure_reg(chip);
}
static int __maybe_unused isl29028_suspend(struct device *dev)
{
struct iio_dev *indio_dev = i2c_get_clientdata(to_i2c_client(dev));
struct isl29028_chip *chip = iio_priv(indio_dev);
int ret;
mutex_lock(&chip->lock);
ret = isl29028_clear_configure_reg(chip);
mutex_unlock(&chip->lock);
return ret;
}
static int __maybe_unused isl29028_resume(struct device *dev)
{
return 0;
}
