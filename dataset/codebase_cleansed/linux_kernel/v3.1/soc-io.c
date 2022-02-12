static int do_spi_write(void *control, const char *data, int len)
{
struct spi_device *spi = control;
int ret;
ret = spi_write(spi, data, len);
if (ret < 0)
return ret;
return len;
}
static int do_hw_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value, const void *data, int len)
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
ret = codec->hw_write(codec->control_data, data, len);
if (ret == len)
return 0;
if (ret < 0)
return ret;
else
return -EIO;
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
BUG_ON(!codec->hw_read);
return codec->hw_read(codec, reg);
}
ret = snd_soc_cache_read(codec, reg, &val);
if (ret < 0)
return -1;
return val;
}
static int snd_soc_4_12_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u16 data;
data = cpu_to_be16((reg << 12) | (value & 0xffffff));
return do_hw_write(codec, reg, value, &data, 2);
}
static int snd_soc_7_9_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u16 data;
data = cpu_to_be16((reg << 9) | (value & 0x1ff));
return do_hw_write(codec, reg, value, &data, 2);
}
static int snd_soc_8_8_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[2];
reg &= 0xff;
data[0] = reg;
data[1] = value & 0xff;
return do_hw_write(codec, reg, value, data, 2);
}
static int snd_soc_8_16_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[3];
u16 val = cpu_to_be16(value);
data[0] = reg;
memcpy(&data[1], &val, sizeof(val));
return do_hw_write(codec, reg, value, data, 3);
}
static unsigned int do_i2c_read(struct snd_soc_codec *codec,
void *reg, int reglen,
void *data, int datalen)
{
struct i2c_msg xfer[2];
int ret;
struct i2c_client *client = codec->control_data;
xfer[0].addr = client->addr;
xfer[0].flags = 0;
xfer[0].len = reglen;
xfer[0].buf = reg;
xfer[1].addr = client->addr;
xfer[1].flags = I2C_M_RD;
xfer[1].len = datalen;
xfer[1].buf = data;
ret = i2c_transfer(client->adapter, xfer, 2);
if (ret == 2)
return 0;
else if (ret < 0)
return ret;
else
return -EIO;
}
static unsigned int snd_soc_8_8_read_i2c(struct snd_soc_codec *codec,
unsigned int r)
{
u8 reg = r;
u8 data;
int ret;
ret = do_i2c_read(codec, &reg, 1, &data, 1);
if (ret < 0)
return 0;
return data;
}
static unsigned int snd_soc_8_16_read_i2c(struct snd_soc_codec *codec,
unsigned int r)
{
u8 reg = r;
u16 data;
int ret;
ret = do_i2c_read(codec, &reg, 1, &data, 2);
if (ret < 0)
return 0;
return (data >> 8) | ((data & 0xff) << 8);
}
static unsigned int snd_soc_16_8_read_i2c(struct snd_soc_codec *codec,
unsigned int r)
{
u16 reg = r;
u8 data;
int ret;
ret = do_i2c_read(codec, &reg, 2, &data, 1);
if (ret < 0)
return 0;
return data;
}
static unsigned int snd_soc_16_8_read_spi(struct snd_soc_codec *codec,
unsigned int r)
{
struct spi_device *spi = codec->control_data;
const u16 reg = cpu_to_be16(r | 0x100);
u8 data;
int ret;
ret = spi_write_then_read(spi, &reg, 2, &data, 1);
if (ret < 0)
return 0;
return data;
}
static int snd_soc_16_8_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u8 data[3];
u16 rval = cpu_to_be16(reg);
memcpy(data, &rval, sizeof(rval));
data[2] = value;
return do_hw_write(codec, reg, value, data, 3);
}
static unsigned int snd_soc_16_16_read_i2c(struct snd_soc_codec *codec,
unsigned int r)
{
u16 reg = cpu_to_be16(r);
u16 data;
int ret;
ret = do_i2c_read(codec, &reg, 2, &data, 2);
if (ret < 0)
return 0;
return be16_to_cpu(data);
}
static int snd_soc_16_16_write(struct snd_soc_codec *codec, unsigned int reg,
unsigned int value)
{
u16 data[2];
data[0] = cpu_to_be16(reg);
data[1] = cpu_to_be16(value);
return do_hw_write(codec, reg, value, data, sizeof(data));
}
static int snd_soc_hw_bulk_write_raw(struct snd_soc_codec *codec, unsigned int reg,
const void *data, size_t len)
{
int ret;
if (!codec->cache_bypass
&& !snd_soc_codec_volatile_register(codec, reg)
&& reg < codec->driver->reg_cache_size)
return -EINVAL;
switch (codec->control_type) {
#if defined(CONFIG_I2C) || (defined(CONFIG_I2C_MODULE) && defined(MODULE))
case SND_SOC_I2C:
ret = i2c_master_send(to_i2c_client(codec->dev), data, len);
break;
#endif
#if defined(CONFIG_SPI_MASTER)
case SND_SOC_SPI:
ret = spi_write(to_spi_device(codec->dev), data, len);
break;
#endif
default:
BUG();
}
if (ret == len)
return 0;
if (ret < 0)
return ret;
else
return -EIO;
}
int snd_soc_codec_set_cache_io(struct snd_soc_codec *codec,
int addr_bits, int data_bits,
enum snd_soc_control_type control)
{
int i;
for (i = 0; i < ARRAY_SIZE(io_types); i++)
if (io_types[i].addr_bits == addr_bits &&
io_types[i].data_bits == data_bits)
break;
if (i == ARRAY_SIZE(io_types)) {
printk(KERN_ERR
"No I/O functions for %d bit address %d bit data\n",
addr_bits, data_bits);
return -EINVAL;
}
codec->write = io_types[i].write;
codec->read = hw_read;
codec->bulk_write_raw = snd_soc_hw_bulk_write_raw;
switch (control) {
case SND_SOC_I2C:
#if defined(CONFIG_I2C) || (defined(CONFIG_I2C_MODULE) && defined(MODULE))
codec->hw_write = (hw_write_t)i2c_master_send;
#endif
if (io_types[i].i2c_read)
codec->hw_read = io_types[i].i2c_read;
codec->control_data = container_of(codec->dev,
struct i2c_client,
dev);
break;
case SND_SOC_SPI:
#ifdef CONFIG_SPI_MASTER
codec->hw_write = do_spi_write;
#endif
if (io_types[i].spi_read)
codec->hw_read = io_types[i].spi_read;
codec->control_data = container_of(codec->dev,
struct spi_device,
dev);
break;
}
return 0;
}
