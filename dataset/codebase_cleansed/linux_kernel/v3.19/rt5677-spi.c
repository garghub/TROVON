int rt5677_spi_write(u8 *txbuf, size_t len)
{
int status;
status = spi_write(g_spi, txbuf, len);
if (status)
dev_err(&g_spi->dev, "rt5677_spi_write error %d\n", status);
return status;
}
int rt5677_spi_burst_write(u32 addr, const struct firmware *fw)
{
u8 spi_cmd = RT5677_SPI_CMD_BURST_WRITE;
u8 *write_buf;
unsigned int i, end, offset = 0;
write_buf = kmalloc(RT5677_SPI_BUF_LEN + 6, GFP_KERNEL);
if (write_buf == NULL)
return -ENOMEM;
while (offset < fw->size) {
if (offset + RT5677_SPI_BUF_LEN <= fw->size)
end = RT5677_SPI_BUF_LEN;
else
end = fw->size % RT5677_SPI_BUF_LEN;
write_buf[0] = spi_cmd;
write_buf[1] = ((addr + offset) & 0xff000000) >> 24;
write_buf[2] = ((addr + offset) & 0x00ff0000) >> 16;
write_buf[3] = ((addr + offset) & 0x0000ff00) >> 8;
write_buf[4] = ((addr + offset) & 0x000000ff) >> 0;
for (i = 0; i < end; i += 8) {
write_buf[i + 12] = fw->data[offset + i + 0];
write_buf[i + 11] = fw->data[offset + i + 1];
write_buf[i + 10] = fw->data[offset + i + 2];
write_buf[i + 9] = fw->data[offset + i + 3];
write_buf[i + 8] = fw->data[offset + i + 4];
write_buf[i + 7] = fw->data[offset + i + 5];
write_buf[i + 6] = fw->data[offset + i + 6];
write_buf[i + 5] = fw->data[offset + i + 7];
}
write_buf[end + 5] = spi_cmd;
rt5677_spi_write(write_buf, end + 6);
offset += RT5677_SPI_BUF_LEN;
}
kfree(write_buf);
return 0;
}
static int rt5677_spi_probe(struct spi_device *spi)
{
g_spi = spi;
return 0;
}
