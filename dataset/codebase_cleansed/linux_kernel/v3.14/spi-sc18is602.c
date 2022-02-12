static int sc18is602_wait_ready(struct sc18is602 *hw, int len)
{
int i, err;
int usecs = 1000000 * len / hw->speed + 1;
u8 dummy[1];
for (i = 0; i < 10; i++) {
err = i2c_master_recv(hw->client, dummy, 1);
if (err >= 0)
return 0;
usleep_range(usecs, usecs * 2);
}
return -ETIMEDOUT;
}
static int sc18is602_txrx(struct sc18is602 *hw, struct spi_message *msg,
struct spi_transfer *t, bool do_transfer)
{
unsigned int len = t->len;
int ret;
if (hw->tlen == 0) {
hw->buffer[0] = 1 << msg->spi->chip_select;
hw->tlen = 1;
hw->rindex = 0;
}
if (t->tx_buf) {
memcpy(&hw->buffer[hw->tlen], t->tx_buf, len);
hw->tlen += len;
if (t->rx_buf)
do_transfer = true;
else
hw->rindex = hw->tlen - 1;
} else if (t->rx_buf) {
hw->rindex = hw->tlen - 1;
memset(&hw->buffer[hw->tlen], 0, len);
hw->tlen += len;
do_transfer = true;
}
if (do_transfer && hw->tlen > 1) {
ret = sc18is602_wait_ready(hw, SC18IS602_BUFSIZ);
if (ret < 0)
return ret;
ret = i2c_master_send(hw->client, hw->buffer, hw->tlen);
if (ret < 0)
return ret;
if (ret != hw->tlen)
return -EIO;
if (t->rx_buf) {
int rlen = hw->rindex + len;
ret = sc18is602_wait_ready(hw, hw->tlen);
if (ret < 0)
return ret;
ret = i2c_master_recv(hw->client, hw->buffer, rlen);
if (ret < 0)
return ret;
if (ret != rlen)
return -EIO;
memcpy(t->rx_buf, &hw->buffer[hw->rindex], len);
}
hw->tlen = 0;
}
return len;
}
static int sc18is602_setup_transfer(struct sc18is602 *hw, u32 hz, u8 mode)
{
u8 ctrl = 0;
int ret;
if (mode & SPI_CPHA)
ctrl |= SC18IS602_MODE_CPHA;
if (mode & SPI_CPOL)
ctrl |= SC18IS602_MODE_CPOL;
if (mode & SPI_LSB_FIRST)
ctrl |= SC18IS602_MODE_LSB_FIRST;
if (hz >= hw->freq / 4) {
ctrl |= SC18IS602_MODE_CLOCK_DIV_4;
hw->speed = hw->freq / 4;
} else if (hz >= hw->freq / 16) {
ctrl |= SC18IS602_MODE_CLOCK_DIV_16;
hw->speed = hw->freq / 16;
} else if (hz >= hw->freq / 64) {
ctrl |= SC18IS602_MODE_CLOCK_DIV_64;
hw->speed = hw->freq / 64;
} else {
ctrl |= SC18IS602_MODE_CLOCK_DIV_128;
hw->speed = hw->freq / 128;
}
if (ctrl == hw->ctrl)
return 0;
ret = i2c_smbus_write_byte_data(hw->client, 0xf0, ctrl);
if (ret < 0)
return ret;
hw->ctrl = ctrl;
return 0;
}
static int sc18is602_check_transfer(struct spi_device *spi,
struct spi_transfer *t, int tlen)
{
uint32_t hz;
if (t && t->len + tlen > SC18IS602_BUFSIZ)
return -EINVAL;
hz = spi->max_speed_hz;
if (t && t->speed_hz)
hz = t->speed_hz;
if (hz == 0)
return -EINVAL;
return 0;
}
static int sc18is602_transfer_one(struct spi_master *master,
struct spi_message *m)
{
struct sc18is602 *hw = spi_master_get_devdata(master);
struct spi_device *spi = m->spi;
struct spi_transfer *t;
int status = 0;
if (hw->id == sc18is602 && spi->chip_select == 2) {
status = -ENXIO;
goto error;
}
hw->tlen = 0;
list_for_each_entry(t, &m->transfers, transfer_list) {
u32 hz = t->speed_hz ? : spi->max_speed_hz;
bool do_transfer;
status = sc18is602_check_transfer(spi, t, hw->tlen);
if (status < 0)
break;
status = sc18is602_setup_transfer(hw, hz, spi->mode);
if (status < 0)
break;
do_transfer = t->cs_change || list_is_last(&t->transfer_list,
&m->transfers);
if (t->len) {
status = sc18is602_txrx(hw, m, t, do_transfer);
if (status < 0)
break;
m->actual_length += status;
}
status = 0;
if (t->delay_usecs)
udelay(t->delay_usecs);
}
error:
m->status = status;
spi_finalize_current_message(master);
return status;
}
static int sc18is602_setup(struct spi_device *spi)
{
if (spi->mode & ~(SPI_CPHA | SPI_CPOL | SPI_LSB_FIRST))
return -EINVAL;
return sc18is602_check_transfer(spi, NULL, 0);
}
static int sc18is602_probe(struct i2c_client *client,
const struct i2c_device_id *id)
{
struct device *dev = &client->dev;
struct device_node *np = dev->of_node;
struct sc18is602_platform_data *pdata = dev_get_platdata(dev);
struct sc18is602 *hw;
struct spi_master *master;
int error;
if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C |
I2C_FUNC_SMBUS_WRITE_BYTE_DATA))
return -EINVAL;
master = spi_alloc_master(dev, sizeof(struct sc18is602));
if (!master)
return -ENOMEM;
hw = spi_master_get_devdata(master);
i2c_set_clientdata(client, hw);
hw->master = master;
hw->client = client;
hw->dev = dev;
hw->ctrl = 0xff;
hw->id = id->driver_data;
switch (hw->id) {
case sc18is602:
case sc18is602b:
master->num_chipselect = 4;
hw->freq = SC18IS602_CLOCK;
break;
case sc18is603:
master->num_chipselect = 2;
if (pdata) {
hw->freq = pdata->clock_frequency;
} else {
const __be32 *val;
int len;
val = of_get_property(np, "clock-frequency", &len);
if (val && len >= sizeof(__be32))
hw->freq = be32_to_cpup(val);
}
if (!hw->freq)
hw->freq = SC18IS602_CLOCK;
break;
}
master->bus_num = client->adapter->nr;
master->mode_bits = SPI_CPHA | SPI_CPOL | SPI_LSB_FIRST;
master->bits_per_word_mask = SPI_BPW_MASK(8);
master->setup = sc18is602_setup;
master->transfer_one_message = sc18is602_transfer_one;
master->dev.of_node = np;
error = devm_spi_register_master(dev, master);
if (error)
goto error_reg;
return 0;
error_reg:
spi_master_put(master);
return error;
}
