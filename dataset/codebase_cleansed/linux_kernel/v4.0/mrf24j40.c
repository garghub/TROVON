static int write_short_reg(struct mrf24j40 *devrec, u8 reg, u8 value)
{
int ret;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 2,
.tx_buf = devrec->buf,
.rx_buf = devrec->buf,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
mutex_lock(&devrec->buffer_mutex);
devrec->buf[0] = MRF24J40_WRITESHORT(reg);
devrec->buf[1] = value;
ret = spi_sync(devrec->spi, &msg);
if (ret)
dev_err(printdev(devrec),
"SPI write Failed for short register 0x%hhx\n", reg);
mutex_unlock(&devrec->buffer_mutex);
return ret;
}
static int read_short_reg(struct mrf24j40 *devrec, u8 reg, u8 *val)
{
int ret = -1;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 2,
.tx_buf = devrec->buf,
.rx_buf = devrec->buf,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
mutex_lock(&devrec->buffer_mutex);
devrec->buf[0] = MRF24J40_READSHORT(reg);
devrec->buf[1] = 0;
ret = spi_sync(devrec->spi, &msg);
if (ret)
dev_err(printdev(devrec),
"SPI read Failed for short register 0x%hhx\n", reg);
else
*val = devrec->buf[1];
mutex_unlock(&devrec->buffer_mutex);
return ret;
}
static int read_long_reg(struct mrf24j40 *devrec, u16 reg, u8 *value)
{
int ret;
u16 cmd;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 3,
.tx_buf = devrec->buf,
.rx_buf = devrec->buf,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
cmd = MRF24J40_READLONG(reg);
mutex_lock(&devrec->buffer_mutex);
devrec->buf[0] = cmd >> 8 & 0xff;
devrec->buf[1] = cmd & 0xff;
devrec->buf[2] = 0;
ret = spi_sync(devrec->spi, &msg);
if (ret)
dev_err(printdev(devrec),
"SPI read Failed for long register 0x%hx\n", reg);
else
*value = devrec->buf[2];
mutex_unlock(&devrec->buffer_mutex);
return ret;
}
static int write_long_reg(struct mrf24j40 *devrec, u16 reg, u8 val)
{
int ret;
u16 cmd;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 3,
.tx_buf = devrec->buf,
.rx_buf = devrec->buf,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
cmd = MRF24J40_WRITELONG(reg);
mutex_lock(&devrec->buffer_mutex);
devrec->buf[0] = cmd >> 8 & 0xff;
devrec->buf[1] = cmd & 0xff;
devrec->buf[2] = val;
ret = spi_sync(devrec->spi, &msg);
if (ret)
dev_err(printdev(devrec),
"SPI write Failed for long register 0x%hx\n", reg);
mutex_unlock(&devrec->buffer_mutex);
return ret;
}
static int write_tx_buf(struct mrf24j40 *devrec, u16 reg,
const u8 *data, size_t length)
{
int ret;
u16 cmd;
u8 lengths[2];
struct spi_message msg;
struct spi_transfer addr_xfer = {
.len = 2,
.tx_buf = devrec->buf,
};
struct spi_transfer lengths_xfer = {
.len = 2,
.tx_buf = &lengths,
};
struct spi_transfer data_xfer = {
.len = length,
.tx_buf = data,
};
if (length > TX_FIFO_SIZE-2) {
dev_err(printdev(devrec), "write_tx_buf() was passed too large a buffer. Performing short write.\n");
length = TX_FIFO_SIZE-2;
}
spi_message_init(&msg);
spi_message_add_tail(&addr_xfer, &msg);
spi_message_add_tail(&lengths_xfer, &msg);
spi_message_add_tail(&data_xfer, &msg);
cmd = MRF24J40_WRITELONG(reg);
mutex_lock(&devrec->buffer_mutex);
devrec->buf[0] = cmd >> 8 & 0xff;
devrec->buf[1] = cmd & 0xff;
lengths[0] = 0x0;
lengths[1] = length;
ret = spi_sync(devrec->spi, &msg);
if (ret)
dev_err(printdev(devrec), "SPI write Failed for TX buf\n");
mutex_unlock(&devrec->buffer_mutex);
return ret;
}
static int mrf24j40_read_rx_buf(struct mrf24j40 *devrec,
u8 *data, u8 *len, u8 *lqi)
{
u8 rx_len;
u8 addr[2];
u8 lqi_rssi[2];
u16 cmd;
int ret;
struct spi_message msg;
struct spi_transfer addr_xfer = {
.len = 2,
.tx_buf = &addr,
};
struct spi_transfer data_xfer = {
.len = 0x0,
.rx_buf = data,
};
struct spi_transfer status_xfer = {
.len = 2,
.rx_buf = &lqi_rssi,
};
ret = read_long_reg(devrec, REG_RX_FIFO, &rx_len);
if (ret)
goto out;
if (rx_len > RX_FIFO_SIZE-1) {
dev_err(printdev(devrec), "Invalid length read from device. Performing short read.\n");
rx_len = RX_FIFO_SIZE-1;
}
if (rx_len > *len) {
dev_err(printdev(devrec), "Buffer not big enough. Performing short read\n");
rx_len = *len;
}
cmd = MRF24J40_READLONG(REG_RX_FIFO+1);
addr[0] = cmd >> 8 & 0xff;
addr[1] = cmd & 0xff;
data_xfer.len = rx_len;
spi_message_init(&msg);
spi_message_add_tail(&addr_xfer, &msg);
spi_message_add_tail(&data_xfer, &msg);
spi_message_add_tail(&status_xfer, &msg);
ret = spi_sync(devrec->spi, &msg);
if (ret) {
dev_err(printdev(devrec), "SPI RX Buffer Read Failed.\n");
goto out;
}
*lqi = lqi_rssi[0];
*len = rx_len;
#ifdef DEBUG
print_hex_dump(KERN_DEBUG, "mrf24j40 rx: ",
DUMP_PREFIX_OFFSET, 16, 1, data, *len, 0);
pr_debug("mrf24j40 rx: lqi: %02hhx rssi: %02hhx\n",
lqi_rssi[0], lqi_rssi[1]);
#endif
out:
return ret;
}
static int mrf24j40_tx(struct ieee802154_hw *hw, struct sk_buff *skb)
{
struct mrf24j40 *devrec = hw->priv;
u8 val;
int ret = 0;
dev_dbg(printdev(devrec), "tx packet of %d bytes\n", skb->len);
ret = write_tx_buf(devrec, 0x000, skb->data, skb->len);
if (ret)
goto err;
reinit_completion(&devrec->tx_complete);
ret = read_short_reg(devrec, REG_TXNCON, &val);
if (ret)
goto err;
val |= 0x1;
if (skb->data[0] & IEEE802154_FC_ACK_REQ)
val |= 0x4;
write_short_reg(devrec, REG_TXNCON, val);
ret = wait_for_completion_interruptible_timeout(
&devrec->tx_complete,
5 * HZ);
if (ret == -ERESTARTSYS)
goto err;
if (ret == 0) {
dev_warn(printdev(devrec), "Timeout waiting for TX interrupt\n");
ret = -ETIMEDOUT;
goto err;
}
ret = read_short_reg(devrec, REG_TXSTAT, &val);
if (ret)
goto err;
if (val & 0x1) {
dev_dbg(printdev(devrec), "Error Sending. Retry count exceeded\n");
ret = -ECOMM;
} else
dev_dbg(printdev(devrec), "Packet Sent\n");
err:
return ret;
}
static int mrf24j40_ed(struct ieee802154_hw *hw, u8 *level)
{
pr_warn("mrf24j40: ed not implemented\n");
*level = 0;
return 0;
}
static int mrf24j40_start(struct ieee802154_hw *hw)
{
struct mrf24j40 *devrec = hw->priv;
u8 val;
int ret;
dev_dbg(printdev(devrec), "start\n");
ret = read_short_reg(devrec, REG_INTCON, &val);
if (ret)
return ret;
val &= ~(0x1|0x8);
write_short_reg(devrec, REG_INTCON, val);
return 0;
}
static void mrf24j40_stop(struct ieee802154_hw *hw)
{
struct mrf24j40 *devrec = hw->priv;
u8 val;
int ret;
dev_dbg(printdev(devrec), "stop\n");
ret = read_short_reg(devrec, REG_INTCON, &val);
if (ret)
return;
val |= 0x1|0x8;
write_short_reg(devrec, REG_INTCON, val);
}
static int mrf24j40_set_channel(struct ieee802154_hw *hw, u8 page, u8 channel)
{
struct mrf24j40 *devrec = hw->priv;
u8 val;
int ret;
dev_dbg(printdev(devrec), "Set Channel %d\n", channel);
WARN_ON(page != 0);
WARN_ON(channel < MRF24J40_CHAN_MIN);
WARN_ON(channel > MRF24J40_CHAN_MAX);
val = (channel-11) << 4 | 0x03;
write_long_reg(devrec, REG_RFCON0, val);
ret = read_short_reg(devrec, REG_RFCTL, &val);
if (ret)
return ret;
val |= 0x04;
write_short_reg(devrec, REG_RFCTL, val);
val &= ~0x04;
write_short_reg(devrec, REG_RFCTL, val);
udelay(SET_CHANNEL_DELAY_US);
return 0;
}
static int mrf24j40_filter(struct ieee802154_hw *hw,
struct ieee802154_hw_addr_filt *filt,
unsigned long changed)
{
struct mrf24j40 *devrec = hw->priv;
dev_dbg(printdev(devrec), "filter\n");
if (changed & IEEE802154_AFILT_SADDR_CHANGED) {
u8 addrh, addrl;
addrh = le16_to_cpu(filt->short_addr) >> 8 & 0xff;
addrl = le16_to_cpu(filt->short_addr) & 0xff;
write_short_reg(devrec, REG_SADRH, addrh);
write_short_reg(devrec, REG_SADRL, addrl);
dev_dbg(printdev(devrec),
"Set short addr to %04hx\n", filt->short_addr);
}
if (changed & IEEE802154_AFILT_IEEEADDR_CHANGED) {
u8 i, addr[8];
memcpy(addr, &filt->ieee_addr, 8);
for (i = 0; i < 8; i++)
write_short_reg(devrec, REG_EADR0 + i, addr[i]);
#ifdef DEBUG
pr_debug("Set long addr to: ");
for (i = 0; i < 8; i++)
pr_debug("%02hhx ", addr[7 - i]);
pr_debug("\n");
#endif
}
if (changed & IEEE802154_AFILT_PANID_CHANGED) {
u8 panidl, panidh;
panidh = le16_to_cpu(filt->pan_id) >> 8 & 0xff;
panidl = le16_to_cpu(filt->pan_id) & 0xff;
write_short_reg(devrec, REG_PANIDH, panidh);
write_short_reg(devrec, REG_PANIDL, panidl);
dev_dbg(printdev(devrec), "Set PANID to %04hx\n", filt->pan_id);
}
if (changed & IEEE802154_AFILT_PANC_CHANGED) {
u8 val;
int ret;
ret = read_short_reg(devrec, REG_RXMCR, &val);
if (ret)
return ret;
if (filt->pan_coord)
val |= 0x8;
else
val &= ~0x8;
write_short_reg(devrec, REG_RXMCR, val);
dev_dbg(printdev(devrec), "Set Pan Coord to %s\n",
filt->pan_coord ? "on" : "off");
}
return 0;
}
static int mrf24j40_handle_rx(struct mrf24j40 *devrec)
{
u8 len = RX_FIFO_SIZE;
u8 lqi = 0;
u8 val;
int ret = 0;
struct sk_buff *skb;
ret = read_short_reg(devrec, REG_BBREG1, &val);
if (ret)
goto out;
val |= 4;
write_short_reg(devrec, REG_BBREG1, val);
skb = dev_alloc_skb(len);
if (!skb) {
ret = -ENOMEM;
goto out;
}
ret = mrf24j40_read_rx_buf(devrec, skb_put(skb, len), &len, &lqi);
if (ret < 0) {
dev_err(printdev(devrec), "Failure reading RX FIFO\n");
kfree_skb(skb);
ret = -EINVAL;
goto out;
}
skb_trim(skb, len-2);
ieee802154_rx_irqsafe(devrec->hw, skb, lqi);
dev_dbg(printdev(devrec), "RX Handled\n");
out:
ret = read_short_reg(devrec, REG_BBREG1, &val);
if (ret)
return ret;
val &= ~0x4;
write_short_reg(devrec, REG_BBREG1, val);
return ret;
}
static irqreturn_t mrf24j40_isr(int irq, void *data)
{
struct mrf24j40 *devrec = data;
u8 intstat;
int ret;
ret = read_short_reg(devrec, REG_INTSTAT, &intstat);
if (ret)
goto out;
if (intstat & 0x1)
complete(&devrec->tx_complete);
if (intstat & 0x8)
mrf24j40_handle_rx(devrec);
out:
return IRQ_HANDLED;
}
static int mrf24j40_hw_init(struct mrf24j40 *devrec)
{
int ret;
u8 val;
ret = write_short_reg(devrec, REG_SOFTRST, 0x07);
if (ret)
goto err_ret;
ret = write_short_reg(devrec, REG_PACON2, 0x98);
if (ret)
goto err_ret;
ret = write_short_reg(devrec, REG_TXSTBL, 0x95);
if (ret)
goto err_ret;
ret = write_long_reg(devrec, REG_RFCON0, 0x03);
if (ret)
goto err_ret;
ret = write_long_reg(devrec, REG_RFCON1, 0x01);
if (ret)
goto err_ret;
ret = write_long_reg(devrec, REG_RFCON2, 0x80);
if (ret)
goto err_ret;
ret = write_long_reg(devrec, REG_RFCON6, 0x90);
if (ret)
goto err_ret;
ret = write_long_reg(devrec, REG_RFCON7, 0x80);
if (ret)
goto err_ret;
ret = write_long_reg(devrec, REG_RFCON8, 0x10);
if (ret)
goto err_ret;
ret = write_long_reg(devrec, REG_SLPCON1, 0x21);
if (ret)
goto err_ret;
ret = write_short_reg(devrec, REG_BBREG2, 0x80);
if (ret)
goto err_ret;
ret = write_short_reg(devrec, REG_CCAEDTH, 0x60);
if (ret)
goto err_ret;
ret = write_short_reg(devrec, REG_BBREG6, 0x40);
if (ret)
goto err_ret;
ret = write_short_reg(devrec, REG_RFCTL, 0x04);
if (ret)
goto err_ret;
ret = write_short_reg(devrec, REG_RFCTL, 0x0);
if (ret)
goto err_ret;
udelay(192);
ret = read_short_reg(devrec, REG_RXMCR, &val);
if (ret)
goto err_ret;
val &= ~0x3;
ret = write_short_reg(devrec, REG_RXMCR, val);
if (ret)
goto err_ret;
if (spi_get_device_id(devrec->spi)->driver_data == MRF24J40MC) {
read_long_reg(devrec, REG_TESTMODE, &val);
val |= 0x7;
write_long_reg(devrec, REG_TESTMODE, val);
read_short_reg(devrec, REG_TRISGPIO, &val);
val |= 0x8;
write_short_reg(devrec, REG_TRISGPIO, val);
read_short_reg(devrec, REG_GPIO, &val);
val |= 0x8;
write_short_reg(devrec, REG_GPIO, val);
write_long_reg(devrec, REG_RFCON3, 0x28);
}
return 0;
err_ret:
return ret;
}
static int mrf24j40_probe(struct spi_device *spi)
{
int ret = -ENOMEM;
struct mrf24j40 *devrec;
dev_info(&spi->dev, "probe(). IRQ: %d\n", spi->irq);
devrec = devm_kzalloc(&spi->dev, sizeof(struct mrf24j40), GFP_KERNEL);
if (!devrec)
goto err_ret;
devrec->buf = devm_kzalloc(&spi->dev, 3, GFP_KERNEL);
if (!devrec->buf)
goto err_ret;
spi->mode = SPI_MODE_0;
if (spi->max_speed_hz > MAX_SPI_SPEED_HZ)
spi->max_speed_hz = MAX_SPI_SPEED_HZ;
mutex_init(&devrec->buffer_mutex);
init_completion(&devrec->tx_complete);
devrec->spi = spi;
spi_set_drvdata(spi, devrec);
devrec->hw = ieee802154_alloc_hw(0, &mrf24j40_ops);
if (!devrec->hw)
goto err_ret;
devrec->hw->priv = devrec;
devrec->hw->parent = &devrec->spi->dev;
devrec->hw->phy->channels_supported[0] = CHANNEL_MASK;
devrec->hw->flags = IEEE802154_HW_OMIT_CKSUM | IEEE802154_HW_AACK |
IEEE802154_HW_AFILT;
dev_dbg(printdev(devrec), "registered mrf24j40\n");
ret = ieee802154_register_hw(devrec->hw);
if (ret)
goto err_register_device;
ret = mrf24j40_hw_init(devrec);
if (ret)
goto err_hw_init;
ret = devm_request_threaded_irq(&spi->dev,
spi->irq,
NULL,
mrf24j40_isr,
IRQF_TRIGGER_LOW|IRQF_ONESHOT,
dev_name(&spi->dev),
devrec);
if (ret) {
dev_err(printdev(devrec), "Unable to get IRQ");
goto err_irq;
}
return 0;
err_irq:
err_hw_init:
ieee802154_unregister_hw(devrec->hw);
err_register_device:
ieee802154_free_hw(devrec->hw);
err_ret:
return ret;
}
static int mrf24j40_remove(struct spi_device *spi)
{
struct mrf24j40 *devrec = spi_get_drvdata(spi);
dev_dbg(printdev(devrec), "remove\n");
ieee802154_unregister_hw(devrec->hw);
ieee802154_free_hw(devrec->hw);
return 0;
}
