static int cyttsp_spi_xfer(struct cyttsp *ts,
u8 op, u8 reg, u8 *buf, int length)
{
struct spi_device *spi = to_spi_device(ts->dev);
struct spi_message msg;
struct spi_transfer xfer[2];
u8 *wr_buf = &ts->xfer_buf[0];
u8 *rd_buf = &ts->xfer_buf[CY_SPI_DATA_BUF_SIZE];
int retval;
int i;
if (length > CY_SPI_DATA_SIZE) {
dev_err(ts->dev, "%s: length %d is too big.\n",
__func__, length);
return -EINVAL;
}
memset(wr_buf, 0, CY_SPI_DATA_BUF_SIZE);
memset(rd_buf, 0, CY_SPI_DATA_BUF_SIZE);
wr_buf[0] = 0x00;
wr_buf[1] = 0xFF;
wr_buf[2] = reg;
wr_buf[3] = op;
if (op == CY_SPI_WR_OP)
memcpy(wr_buf + CY_SPI_CMD_BYTES, buf, length);
memset(xfer, 0, sizeof(xfer));
spi_message_init(&msg);
xfer[0].tx_buf = wr_buf;
xfer[0].rx_buf = rd_buf;
switch (op) {
case CY_SPI_WR_OP:
xfer[0].len = length + CY_SPI_CMD_BYTES;
spi_message_add_tail(&xfer[0], &msg);
break;
case CY_SPI_RD_OP:
xfer[0].len = CY_SPI_CMD_BYTES;
spi_message_add_tail(&xfer[0], &msg);
xfer[1].rx_buf = buf;
xfer[1].len = length;
spi_message_add_tail(&xfer[1], &msg);
break;
default:
dev_err(ts->dev, "%s: bad operation code=%d\n", __func__, op);
return -EINVAL;
}
retval = spi_sync(spi, &msg);
if (retval < 0) {
dev_dbg(ts->dev, "%s: spi_sync() error %d, len=%d, op=%d\n",
__func__, retval, xfer[1].len, op);
}
if (rd_buf[CY_SPI_SYNC_BYTE] != CY_SPI_SYNC_ACK1 ||
rd_buf[CY_SPI_SYNC_BYTE + 1] != CY_SPI_SYNC_ACK2) {
dev_dbg(ts->dev, "%s: operation %d failed\n", __func__, op);
for (i = 0; i < CY_SPI_CMD_BYTES; i++)
dev_dbg(ts->dev, "%s: test rd_buf[%d]:0x%02x\n",
__func__, i, rd_buf[i]);
for (i = 0; i < length; i++)
dev_dbg(ts->dev, "%s: test buf[%d]:0x%02x\n",
__func__, i, buf[i]);
return -EIO;
}
return 0;
}
static int cyttsp_spi_read_block_data(struct cyttsp *ts,
u8 addr, u8 length, void *data)
{
return cyttsp_spi_xfer(ts, CY_SPI_RD_OP, addr, data, length);
}
static int cyttsp_spi_write_block_data(struct cyttsp *ts,
u8 addr, u8 length, const void *data)
{
return cyttsp_spi_xfer(ts, CY_SPI_WR_OP, addr, (void *)data, length);
}
static int cyttsp_spi_probe(struct spi_device *spi)
{
struct cyttsp *ts;
int error;
spi->bits_per_word = CY_SPI_BITS_PER_WORD;
spi->mode = SPI_MODE_0;
error = spi_setup(spi);
if (error < 0) {
dev_err(&spi->dev, "%s: SPI setup error %d\n",
__func__, error);
return error;
}
ts = cyttsp_probe(&cyttsp_spi_bus_ops, &spi->dev, spi->irq,
CY_SPI_DATA_BUF_SIZE * 2);
if (IS_ERR(ts))
return PTR_ERR(ts);
spi_set_drvdata(spi, ts);
return 0;
}
static int cyttsp_spi_remove(struct spi_device *spi)
{
struct cyttsp *ts = spi_get_drvdata(spi);
cyttsp_remove(ts);
return 0;
}
