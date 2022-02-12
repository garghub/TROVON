static int write8(void *client, u8 val)
{
u8 data = val;
return spi_write(client, &data, 1);
}
static int write16(void *client, u8 reg, u8 val)
{
u8 data[2] = {reg, val};
return spi_write(client, data, 2);
}
static int write24(void *client, u8 reg, u16 val)
{
u8 data[3] = {reg, val >> 8, val};
return spi_write(client, data, 3);
}
static int read8(void *client)
{
int ret;
u8 data;
ret = spi_read(client, &data, 1);
if (ret < 0)
return ret;
return data;
}
static int read16(void *client, u8 reg)
{
int ret;
u8 buf_rx[2];
write16(client, reg, 0);
ret = spi_read(client, buf_rx, 2);
if (ret < 0)
return ret;
return (buf_rx[0] << 8) | buf_rx[1];
}
static int read24(void *client, u8 reg)
{
int ret;
u8 buf_rx[3];
write24(client, reg, 0);
ret = spi_read(client, buf_rx, 3);
if (ret < 0)
return ret;
return (buf_rx[1] << 8) | buf_rx[2];
}
static int __devinit ad_dpot_spi_probe(struct spi_device *spi)
{
struct ad_dpot_bus_data bdata = {
.client = spi,
.bops = &bops,
};
return ad_dpot_probe(&spi->dev, &bdata,
spi_get_device_id(spi)->driver_data,
spi_get_device_id(spi)->name);
}
static int __devexit ad_dpot_spi_remove(struct spi_device *spi)
{
return ad_dpot_remove(&spi->dev);
}
