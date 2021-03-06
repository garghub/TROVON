static int adt7316_spi_multi_read(void *client, u8 reg, u8 count, u8 *data)
{
struct spi_device *spi_dev = client;
u8 cmd[2];
int ret = 0;
if (count > ADT7316_REG_MAX_ADDR)
count = ADT7316_REG_MAX_ADDR;
cmd[0] = ADT7316_SPI_CMD_WRITE;
cmd[1] = reg;
ret = spi_write(spi_dev, cmd, 2);
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI fail to select reg\n");
return ret;
}
cmd[0] = ADT7316_SPI_CMD_READ;
ret = spi_write_then_read(spi_dev, cmd, 1, data, count);
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI read data error\n");
return ret;
}
return 0;
}
static int adt7316_spi_multi_write(void *client, u8 reg, u8 count, u8 *data)
{
struct spi_device *spi_dev = client;
u8 buf[ADT7316_REG_MAX_ADDR + 2];
int i, ret = 0;
if (count > ADT7316_REG_MAX_ADDR)
count = ADT7316_REG_MAX_ADDR;
buf[0] = ADT7316_SPI_CMD_WRITE;
buf[1] = reg;
for (i = 0; i < count; i++)
buf[i + 2] = data[i];
ret = spi_write(spi_dev, buf, count + 2);
if (ret < 0) {
dev_err(&spi_dev->dev, "SPI write error\n");
return ret;
}
return ret;
}
static int adt7316_spi_read(void *client, u8 reg, u8 *data)
{
return adt7316_spi_multi_read(client, reg, 1, data);
}
static int adt7316_spi_write(void *client, u8 reg, u8 val)
{
return adt7316_spi_multi_write(client, reg, 1, &val);
}
static int __devinit adt7316_spi_probe(struct spi_device *spi_dev)
{
struct adt7316_bus bus = {
.client = spi_dev,
.irq = spi_dev->irq,
.irq_flags = IRQF_TRIGGER_LOW,
.read = adt7316_spi_read,
.write = adt7316_spi_write,
.multi_read = adt7316_spi_multi_read,
.multi_write = adt7316_spi_multi_write,
};
if (spi_dev->max_speed_hz > ADT7316_SPI_MAX_FREQ_HZ) {
dev_err(&spi_dev->dev, "SPI CLK %d Hz?\n",
spi_dev->max_speed_hz);
return -EINVAL;
}
adt7316_spi_write(spi_dev, 0, 0);
adt7316_spi_write(spi_dev, 0, 0);
adt7316_spi_write(spi_dev, 0, 0);
return adt7316_probe(&spi_dev->dev, &bus, spi_dev->modalias);
}
static int __devexit adt7316_spi_remove(struct spi_device *spi_dev)
{
return adt7316_remove(&spi_dev->dev);
}
static int adt7316_spi_suspend(struct spi_device *spi_dev, pm_message_t message)
{
return adt7316_disable(&spi_dev->dev);
}
static int adt7316_spi_resume(struct spi_device *spi_dev)
{
return adt7316_enable(&spi_dev->dev);
}
