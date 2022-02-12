static int hw_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
int ret;
if (!snd_soc_codec_volatile_register(codec, reg) &&
reg < codec->driver->reg_cache_size &&
!codec->cache_bypass) {
ret = snd_soc_cache_write(codec, reg, value);
if (ret < 0)
return -1;
}
if (codec->cache_only) {
codec->cache_sync = 1;
return 0;
}
return regmap_write(codec->control_data, reg, value);
}
static unsigned int hw_read(struct snd_soc_codec *codec, unsigned int reg)
{
int ret;
unsigned int val;
if (reg >= codec->driver->reg_cache_size ||
snd_soc_codec_volatile_register(codec, reg) ||
codec->cache_bypass) {
if (codec->cache_only)
return -1;
ret = regmap_read(codec->control_data, reg, &val);
if (ret == 0)
return val;
else
return -1;
}
ret = snd_soc_cache_read(codec, reg, &val);
if (ret < 0)
return -1;
return val;
}
static int snd_soc_hw_bulk_write_raw(struct snd_soc_codec *codec,
unsigned int reg,
const void *data, size_t len)
{
if (!codec->cache_bypass
&& !snd_soc_codec_volatile_register(codec, reg)
&& reg < codec->driver->reg_cache_size)
return -EINVAL;
return regmap_raw_write(codec->control_data, reg, data, len);
}
int snd_soc_codec_set_cache_io(struct snd_soc_codec *codec,
int addr_bits, int data_bits,
enum snd_soc_control_type control)
{
struct regmap_config config;
int ret;
memset(&config, 0, sizeof(config));
codec->write = hw_write;
codec->read = hw_read;
codec->bulk_write_raw = snd_soc_hw_bulk_write_raw;
config.reg_bits = addr_bits;
config.val_bits = data_bits;
switch (control) {
#if defined(CONFIG_REGMAP_I2C) || defined(CONFIG_REGMAP_I2C_MODULE)
case SND_SOC_I2C:
codec->control_data = regmap_init_i2c(to_i2c_client(codec->dev),
&config);
break;
#endif
#if defined(CONFIG_REGMAP_SPI) || defined(CONFIG_REGMAP_SPI_MODULE)
case SND_SOC_SPI:
codec->control_data = regmap_init_spi(to_spi_device(codec->dev),
&config);
break;
#endif
case SND_SOC_REGMAP:
codec->using_regmap = true;
if (!codec->control_data)
codec->control_data = dev_get_regmap(codec->dev, NULL);
if (codec->control_data) {
ret = regmap_get_val_bytes(codec->control_data);
if (ret > 0)
codec->val_bytes = ret;
}
break;
default:
return -EINVAL;
}
if (IS_ERR(codec->control_data))
return PTR_ERR(codec->control_data);
return 0;
}
int snd_soc_codec_set_cache_io(struct snd_soc_codec *codec,
int addr_bits, int data_bits,
enum snd_soc_control_type control)
{
return -ENOTSUPP;
}
