static int ads7871_read_reg8(struct spi_device *spi, int reg)
{
int ret;
reg = reg | INST_READ_BM;
ret = spi_w8r8(spi, reg);
return ret;
}
static int ads7871_read_reg16(struct spi_device *spi, int reg)
{
int ret;
reg = reg | INST_READ_BM | INST_16BIT_BM;
ret = spi_w8r16(spi, reg);
return ret;
}
static int ads7871_write_reg8(struct spi_device *spi, int reg, u8 val)
{
u8 tmp[2] = {reg, val};
return spi_write(spi, tmp, sizeof(tmp));
}
static ssize_t show_voltage(struct device *dev,
struct device_attribute *da, char *buf)
{
struct ads7871_data *pdata = dev_get_drvdata(dev);
struct spi_device *spi = pdata->spi;
struct sensor_device_attribute *attr = to_sensor_dev_attr(da);
int ret, val, i = 0;
uint8_t channel, mux_cnv;
channel = attr->index;
ads7871_write_reg8(spi, REG_GAIN_MUX,
(MUX_CNV_BM | MUX_M3_BM | channel));
ret = ads7871_read_reg8(spi, REG_GAIN_MUX);
mux_cnv = ((ret & MUX_CNV_BM) >> MUX_CNV_BV);
while ((i < 2) && mux_cnv) {
i++;
ret = ads7871_read_reg8(spi, REG_GAIN_MUX);
mux_cnv = ((ret & MUX_CNV_BM) >> MUX_CNV_BV);
msleep_interruptible(1);
}
if (mux_cnv == 0) {
val = ads7871_read_reg16(spi, REG_LS_BYTE);
val = ((val >> 2) * 25000) / 8192;
return sprintf(buf, "%d\n", val);
} else {
return -1;
}
}
static int ads7871_probe(struct spi_device *spi)
{
struct device *dev = &spi->dev;
int ret;
uint8_t val;
struct ads7871_data *pdata;
struct device *hwmon_dev;
spi->mode = (SPI_MODE_0);
spi->bits_per_word = 8;
spi_setup(spi);
ads7871_write_reg8(spi, REG_SER_CONTROL, 0);
ads7871_write_reg8(spi, REG_AD_CONTROL, 0);
val = (OSC_OSCR_BM | OSC_OSCE_BM | OSC_REFE_BM | OSC_BUFE_BM);
ads7871_write_reg8(spi, REG_OSC_CONTROL, val);
ret = ads7871_read_reg8(spi, REG_OSC_CONTROL);
dev_dbg(dev, "REG_OSC_CONTROL write:%x, read:%x\n", val, ret);
if (val != ret)
return -ENODEV;
pdata = devm_kzalloc(dev, sizeof(struct ads7871_data), GFP_KERNEL);
if (!pdata)
return -ENOMEM;
pdata->spi = spi;
hwmon_dev = devm_hwmon_device_register_with_groups(dev, spi->modalias,
pdata,
ads7871_groups);
return PTR_ERR_OR_ZERO(hwmon_dev);
}
