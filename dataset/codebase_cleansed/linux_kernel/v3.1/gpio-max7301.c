static int max7301_spi_write(struct device *dev, unsigned int reg,
unsigned int val)
{
struct spi_device *spi = to_spi_device(dev);
u16 word = ((reg & 0x7F) << 8) | (val & 0xFF);
return spi_write(spi, (const u8 *)&word, sizeof(word));
}
static int max7301_spi_read(struct device *dev, unsigned int reg)
{
int ret;
u16 word;
struct spi_device *spi = to_spi_device(dev);
word = 0x8000 | (reg << 8);
ret = spi_write(spi, (const u8 *)&word, sizeof(word));
if (ret)
return ret;
ret = spi_read(spi, (u8 *)&word, sizeof(word));
if (ret)
return ret;
return word & 0xff;
}
static int __devinit max7301_probe(struct spi_device *spi)
{
struct max7301 *ts;
int ret;
spi->bits_per_word = 16;
ret = spi_setup(spi);
if (ret < 0)
return ret;
ts = kzalloc(sizeof(struct max7301), GFP_KERNEL);
if (!ts)
return -ENOMEM;
ts->read = max7301_spi_read;
ts->write = max7301_spi_write;
ts->dev = &spi->dev;
ret = __max730x_probe(ts);
if (ret)
kfree(ts);
return ret;
}
static int __devexit max7301_remove(struct spi_device *spi)
{
return __max730x_remove(&spi->dev);
}
static int __init max7301_init(void)
{
return spi_register_driver(&max7301_driver);
}
static void __exit max7301_exit(void)
{
spi_unregister_driver(&max7301_driver);
}
