static enum bmi160_sensor_type bmi160_to_sensor(enum iio_chan_type iio_type)
{
switch (iio_type) {
case IIO_ACCEL:
return BMI160_ACCEL;
case IIO_ANGL_VEL:
return BMI160_GYRO;
default:
return -EINVAL;
}
}
static
int bmi160_set_mode(struct bmi160_data *data, enum bmi160_sensor_type t,
bool mode)
{
int ret;
u8 cmd;
if (mode)
cmd = bmi160_regs[t].pmu_cmd_normal;
else
cmd = bmi160_regs[t].pmu_cmd_suspend;
ret = regmap_write(data->regmap, BMI160_REG_CMD, cmd);
if (ret < 0)
return ret;
usleep_range(bmi160_pmu_time[t].min, bmi160_pmu_time[t].max);
return 0;
}
static
int bmi160_set_scale(struct bmi160_data *data, enum bmi160_sensor_type t,
int uscale)
{
int i;
for (i = 0; i < bmi160_scale_table[t].num; i++)
if (bmi160_scale_table[t].tbl[i].uscale == uscale)
break;
if (i == bmi160_scale_table[t].num)
return -EINVAL;
return regmap_write(data->regmap, bmi160_regs[t].range,
bmi160_scale_table[t].tbl[i].bits);
}
static
int bmi160_get_scale(struct bmi160_data *data, enum bmi160_sensor_type t,
int *uscale)
{
int i, ret, val;
ret = regmap_read(data->regmap, bmi160_regs[t].range, &val);
if (ret < 0)
return ret;
for (i = 0; i < bmi160_scale_table[t].num; i++)
if (bmi160_scale_table[t].tbl[i].bits == val) {
*uscale = bmi160_scale_table[t].tbl[i].uscale;
return 0;
}
return -EINVAL;
}
static int bmi160_get_data(struct bmi160_data *data, int chan_type,
int axis, int *val)
{
u8 reg;
int ret;
__le16 sample;
enum bmi160_sensor_type t = bmi160_to_sensor(chan_type);
reg = bmi160_regs[t].data + (axis - IIO_MOD_X) * sizeof(__le16);
ret = regmap_bulk_read(data->regmap, reg, &sample, sizeof(__le16));
if (ret < 0)
return ret;
*val = sign_extend32(le16_to_cpu(sample), 15);
return 0;
}
static
int bmi160_set_odr(struct bmi160_data *data, enum bmi160_sensor_type t,
int odr, int uodr)
{
int i;
for (i = 0; i < bmi160_odr_table[t].num; i++)
if (bmi160_odr_table[t].tbl[i].odr == odr &&
bmi160_odr_table[t].tbl[i].uodr == uodr)
break;
if (i >= bmi160_odr_table[t].num)
return -EINVAL;
return regmap_update_bits(data->regmap,
bmi160_regs[t].config,
bmi160_regs[t].config_odr_mask,
bmi160_odr_table[t].tbl[i].bits);
}
static int bmi160_get_odr(struct bmi160_data *data, enum bmi160_sensor_type t,
int *odr, int *uodr)
{
int i, val, ret;
ret = regmap_read(data->regmap, bmi160_regs[t].config, &val);
if (ret < 0)
return ret;
val &= bmi160_regs[t].config_odr_mask;
for (i = 0; i < bmi160_odr_table[t].num; i++)
if (val == bmi160_odr_table[t].tbl[i].bits)
break;
if (i >= bmi160_odr_table[t].num)
return -EINVAL;
*odr = bmi160_odr_table[t].tbl[i].odr;
*uodr = bmi160_odr_table[t].tbl[i].uodr;
return 0;
}
static irqreturn_t bmi160_trigger_handler(int irq, void *p)
{
struct iio_poll_func *pf = p;
struct iio_dev *indio_dev = pf->indio_dev;
struct bmi160_data *data = iio_priv(indio_dev);
s16 buf[16];
int i, ret, j = 0, base = BMI160_REG_DATA_MAGN_XOUT_L;
__le16 sample;
for_each_set_bit(i, indio_dev->active_scan_mask,
indio_dev->masklength) {
ret = regmap_bulk_read(data->regmap, base + i * sizeof(__le16),
&sample, sizeof(__le16));
if (ret < 0)
goto done;
buf[j++] = sample;
}
iio_push_to_buffers_with_timestamp(indio_dev, buf,
iio_get_time_ns(indio_dev));
done:
iio_trigger_notify_done(indio_dev->trig);
return IRQ_HANDLED;
}
static int bmi160_read_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int *val, int *val2, long mask)
{
int ret;
struct bmi160_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_RAW:
ret = bmi160_get_data(data, chan->type, chan->channel2, val);
if (ret < 0)
return ret;
return IIO_VAL_INT;
case IIO_CHAN_INFO_SCALE:
*val = 0;
ret = bmi160_get_scale(data,
bmi160_to_sensor(chan->type), val2);
return ret < 0 ? ret : IIO_VAL_INT_PLUS_MICRO;
case IIO_CHAN_INFO_SAMP_FREQ:
ret = bmi160_get_odr(data, bmi160_to_sensor(chan->type),
val, val2);
return ret < 0 ? ret : IIO_VAL_INT_PLUS_MICRO;
default:
return -EINVAL;
}
return 0;
}
static int bmi160_write_raw(struct iio_dev *indio_dev,
struct iio_chan_spec const *chan,
int val, int val2, long mask)
{
struct bmi160_data *data = iio_priv(indio_dev);
switch (mask) {
case IIO_CHAN_INFO_SCALE:
return bmi160_set_scale(data,
bmi160_to_sensor(chan->type), val2);
break;
case IIO_CHAN_INFO_SAMP_FREQ:
return bmi160_set_odr(data, bmi160_to_sensor(chan->type),
val, val2);
default:
return -EINVAL;
}
return 0;
}
static const char *bmi160_match_acpi_device(struct device *dev)
{
const struct acpi_device_id *id;
id = acpi_match_device(dev->driver->acpi_match_table, dev);
if (!id)
return NULL;
return dev_name(dev);
}
static int bmi160_chip_init(struct bmi160_data *data, bool use_spi)
{
int ret;
unsigned int val;
struct device *dev = regmap_get_device(data->regmap);
ret = regmap_write(data->regmap, BMI160_REG_CMD, BMI160_CMD_SOFTRESET);
if (ret < 0)
return ret;
usleep_range(BMI160_SOFTRESET_USLEEP, BMI160_SOFTRESET_USLEEP + 1);
if (use_spi) {
ret = regmap_read(data->regmap, BMI160_REG_DUMMY, &val);
if (ret < 0)
return ret;
}
ret = regmap_read(data->regmap, BMI160_REG_CHIP_ID, &val);
if (ret < 0) {
dev_err(dev, "Error reading chip id\n");
return ret;
}
if (val != BMI160_CHIP_ID_VAL) {
dev_err(dev, "Wrong chip id, got %x expected %x\n",
val, BMI160_CHIP_ID_VAL);
return -ENODEV;
}
ret = bmi160_set_mode(data, BMI160_ACCEL, true);
if (ret < 0)
return ret;
ret = bmi160_set_mode(data, BMI160_GYRO, true);
if (ret < 0)
return ret;
return 0;
}
static void bmi160_chip_uninit(struct bmi160_data *data)
{
bmi160_set_mode(data, BMI160_GYRO, false);
bmi160_set_mode(data, BMI160_ACCEL, false);
}
int bmi160_core_probe(struct device *dev, struct regmap *regmap,
const char *name, bool use_spi)
{
struct iio_dev *indio_dev;
struct bmi160_data *data;
int ret;
indio_dev = devm_iio_device_alloc(dev, sizeof(*data));
if (!indio_dev)
return -ENOMEM;
data = iio_priv(indio_dev);
dev_set_drvdata(dev, indio_dev);
data->regmap = regmap;
ret = bmi160_chip_init(data, use_spi);
if (ret < 0)
return ret;
if (!name && ACPI_HANDLE(dev))
name = bmi160_match_acpi_device(dev);
indio_dev->dev.parent = dev;
indio_dev->channels = bmi160_channels;
indio_dev->num_channels = ARRAY_SIZE(bmi160_channels);
indio_dev->name = name;
indio_dev->modes = INDIO_DIRECT_MODE;
indio_dev->info = &bmi160_info;
ret = iio_triggered_buffer_setup(indio_dev, NULL,
bmi160_trigger_handler, NULL);
if (ret < 0)
goto uninit;
ret = iio_device_register(indio_dev);
if (ret < 0)
goto buffer_cleanup;
return 0;
buffer_cleanup:
iio_triggered_buffer_cleanup(indio_dev);
uninit:
bmi160_chip_uninit(data);
return ret;
}
void bmi160_core_remove(struct device *dev)
{
struct iio_dev *indio_dev = dev_get_drvdata(dev);
struct bmi160_data *data = iio_priv(indio_dev);
iio_device_unregister(indio_dev);
iio_triggered_buffer_cleanup(indio_dev);
bmi160_chip_uninit(data);
}
