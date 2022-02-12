static int
cc2520_cmd_strobe(struct cc2520_private *priv, u8 cmd)
{
int ret;
u8 status = 0xff;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 0,
.tx_buf = priv->buf,
.rx_buf = priv->buf,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
mutex_lock(&priv->buffer_mutex);
priv->buf[xfer.len++] = cmd;
dev_vdbg(&priv->spi->dev,
"command strobe buf[0] = %02x\n",
priv->buf[0]);
ret = spi_sync(priv->spi, &msg);
if (!ret)
status = priv->buf[0];
dev_vdbg(&priv->spi->dev,
"buf[0] = %02x\n", priv->buf[0]);
mutex_unlock(&priv->buffer_mutex);
return ret;
}
static int
cc2520_get_status(struct cc2520_private *priv, u8 *status)
{
int ret;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 0,
.tx_buf = priv->buf,
.rx_buf = priv->buf,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
mutex_lock(&priv->buffer_mutex);
priv->buf[xfer.len++] = CC2520_CMD_SNOP;
dev_vdbg(&priv->spi->dev,
"get status command buf[0] = %02x\n", priv->buf[0]);
ret = spi_sync(priv->spi, &msg);
if (!ret)
*status = priv->buf[0];
dev_vdbg(&priv->spi->dev,
"buf[0] = %02x\n", priv->buf[0]);
mutex_unlock(&priv->buffer_mutex);
return ret;
}
static int
cc2520_write_register(struct cc2520_private *priv, u8 reg, u8 value)
{
int status;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 0,
.tx_buf = priv->buf,
.rx_buf = priv->buf,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
mutex_lock(&priv->buffer_mutex);
if (reg <= CC2520_FREG_MASK) {
priv->buf[xfer.len++] = CC2520_CMD_REGISTER_WRITE | reg;
priv->buf[xfer.len++] = value;
} else {
priv->buf[xfer.len++] = CC2520_CMD_MEMORY_WRITE;
priv->buf[xfer.len++] = reg;
priv->buf[xfer.len++] = value;
}
status = spi_sync(priv->spi, &msg);
if (msg.status)
status = msg.status;
mutex_unlock(&priv->buffer_mutex);
return status;
}
static int
cc2520_write_ram(struct cc2520_private *priv, u16 reg, u8 len, u8 *data)
{
int status;
struct spi_message msg;
struct spi_transfer xfer_head = {
.len = 0,
.tx_buf = priv->buf,
.rx_buf = priv->buf,
};
struct spi_transfer xfer_buf = {
.len = len,
.tx_buf = data,
};
mutex_lock(&priv->buffer_mutex);
priv->buf[xfer_head.len++] = (CC2520_CMD_MEMORY_WRITE |
((reg >> 8) & 0xff));
priv->buf[xfer_head.len++] = reg & 0xff;
spi_message_init(&msg);
spi_message_add_tail(&xfer_head, &msg);
spi_message_add_tail(&xfer_buf, &msg);
status = spi_sync(priv->spi, &msg);
dev_dbg(&priv->spi->dev, "spi status = %d\n", status);
if (msg.status)
status = msg.status;
mutex_unlock(&priv->buffer_mutex);
return status;
}
static int
cc2520_read_register(struct cc2520_private *priv, u8 reg, u8 *data)
{
int status;
struct spi_message msg;
struct spi_transfer xfer1 = {
.len = 0,
.tx_buf = priv->buf,
.rx_buf = priv->buf,
};
struct spi_transfer xfer2 = {
.len = 1,
.rx_buf = data,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer1, &msg);
spi_message_add_tail(&xfer2, &msg);
mutex_lock(&priv->buffer_mutex);
priv->buf[xfer1.len++] = CC2520_CMD_MEMORY_READ;
priv->buf[xfer1.len++] = reg;
status = spi_sync(priv->spi, &msg);
dev_dbg(&priv->spi->dev,
"spi status = %d\n", status);
if (msg.status)
status = msg.status;
mutex_unlock(&priv->buffer_mutex);
return status;
}
static int
cc2520_write_txfifo(struct cc2520_private *priv, u8 *data, u8 len)
{
int status;
int len_byte = len + 2;
struct spi_message msg;
struct spi_transfer xfer_head = {
.len = 0,
.tx_buf = priv->buf,
.rx_buf = priv->buf,
};
struct spi_transfer xfer_len = {
.len = 1,
.tx_buf = &len_byte,
};
struct spi_transfer xfer_buf = {
.len = len,
.tx_buf = data,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer_head, &msg);
spi_message_add_tail(&xfer_len, &msg);
spi_message_add_tail(&xfer_buf, &msg);
mutex_lock(&priv->buffer_mutex);
priv->buf[xfer_head.len++] = CC2520_CMD_TXBUF;
dev_vdbg(&priv->spi->dev,
"TX_FIFO cmd buf[0] = %02x\n", priv->buf[0]);
status = spi_sync(priv->spi, &msg);
dev_vdbg(&priv->spi->dev, "status = %d\n", status);
if (msg.status)
status = msg.status;
dev_vdbg(&priv->spi->dev, "status = %d\n", status);
dev_vdbg(&priv->spi->dev, "buf[0] = %02x\n", priv->buf[0]);
mutex_unlock(&priv->buffer_mutex);
return status;
}
static int
cc2520_read_rxfifo(struct cc2520_private *priv, u8 *data, u8 len, u8 *lqi)
{
int status;
struct spi_message msg;
struct spi_transfer xfer_head = {
.len = 0,
.tx_buf = priv->buf,
.rx_buf = priv->buf,
};
struct spi_transfer xfer_buf = {
.len = len,
.rx_buf = data,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer_head, &msg);
spi_message_add_tail(&xfer_buf, &msg);
mutex_lock(&priv->buffer_mutex);
priv->buf[xfer_head.len++] = CC2520_CMD_RXBUF;
dev_vdbg(&priv->spi->dev, "read rxfifo buf[0] = %02x\n", priv->buf[0]);
dev_vdbg(&priv->spi->dev, "buf[1] = %02x\n", priv->buf[1]);
status = spi_sync(priv->spi, &msg);
dev_vdbg(&priv->spi->dev, "status = %d\n", status);
if (msg.status)
status = msg.status;
dev_vdbg(&priv->spi->dev, "status = %d\n", status);
dev_vdbg(&priv->spi->dev,
"return status buf[0] = %02x\n", priv->buf[0]);
dev_vdbg(&priv->spi->dev, "length buf[1] = %02x\n", priv->buf[1]);
mutex_unlock(&priv->buffer_mutex);
return status;
}
static int cc2520_start(struct ieee802154_hw *hw)
{
return cc2520_cmd_strobe(hw->priv, CC2520_CMD_SRXON);
}
static void cc2520_stop(struct ieee802154_hw *hw)
{
cc2520_cmd_strobe(hw->priv, CC2520_CMD_SRFOFF);
}
static int
cc2520_tx(struct ieee802154_hw *hw, struct sk_buff *skb)
{
struct cc2520_private *priv = hw->priv;
unsigned long flags;
int rc;
u8 status = 0;
rc = cc2520_cmd_strobe(priv, CC2520_CMD_SFLUSHTX);
if (rc)
goto err_tx;
rc = cc2520_write_txfifo(priv, skb->data, skb->len);
if (rc)
goto err_tx;
rc = cc2520_get_status(priv, &status);
if (rc)
goto err_tx;
if (status & CC2520_STATUS_TX_UNDERFLOW) {
dev_err(&priv->spi->dev, "cc2520 tx underflow exception\n");
goto err_tx;
}
spin_lock_irqsave(&priv->lock, flags);
BUG_ON(priv->is_tx);
priv->is_tx = 1;
spin_unlock_irqrestore(&priv->lock, flags);
rc = cc2520_cmd_strobe(priv, CC2520_CMD_STXONCCA);
if (rc)
goto err;
rc = wait_for_completion_interruptible(&priv->tx_complete);
if (rc < 0)
goto err;
cc2520_cmd_strobe(priv, CC2520_CMD_SFLUSHTX);
cc2520_cmd_strobe(priv, CC2520_CMD_SRXON);
return rc;
err:
spin_lock_irqsave(&priv->lock, flags);
priv->is_tx = 0;
spin_unlock_irqrestore(&priv->lock, flags);
err_tx:
return rc;
}
static int cc2520_rx(struct cc2520_private *priv)
{
u8 len = 0, lqi = 0, bytes = 1;
struct sk_buff *skb;
cc2520_read_rxfifo(priv, &len, bytes, &lqi);
if (len < 2 || len > IEEE802154_MTU)
return -EINVAL;
skb = dev_alloc_skb(len);
if (!skb)
return -ENOMEM;
if (cc2520_read_rxfifo(priv, skb_put(skb, len), len, &lqi)) {
dev_dbg(&priv->spi->dev, "frame reception failed\n");
kfree_skb(skb);
return -EINVAL;
}
skb_trim(skb, skb->len - 2);
ieee802154_rx_irqsafe(priv->hw, skb, lqi);
dev_vdbg(&priv->spi->dev, "RXFIFO: %x %x\n", len, lqi);
return 0;
}
static int
cc2520_ed(struct ieee802154_hw *hw, u8 *level)
{
struct cc2520_private *priv = hw->priv;
u8 status = 0xff;
u8 rssi;
int ret;
ret = cc2520_read_register(priv, CC2520_RSSISTAT, &status);
if (ret)
return ret;
if (status != RSSI_VALID)
return -EINVAL;
ret = cc2520_read_register(priv, CC2520_RSSI, &rssi);
if (ret)
return ret;
*level = rssi - RSSI_OFFSET;
return 0;
}
static int
cc2520_set_channel(struct ieee802154_hw *hw, u8 page, u8 channel)
{
struct cc2520_private *priv = hw->priv;
int ret;
dev_dbg(&priv->spi->dev, "trying to set channel\n");
BUG_ON(page != 0);
BUG_ON(channel < CC2520_MINCHANNEL);
BUG_ON(channel > CC2520_MAXCHANNEL);
ret = cc2520_write_register(priv, CC2520_FREQCTRL,
11 + 5*(channel - 11));
return ret;
}
static int
cc2520_filter(struct ieee802154_hw *hw,
struct ieee802154_hw_addr_filt *filt, unsigned long changed)
{
struct cc2520_private *priv = hw->priv;
if (changed & IEEE802154_AFILT_PANID_CHANGED) {
u16 panid = le16_to_cpu(filt->pan_id);
dev_vdbg(&priv->spi->dev,
"cc2520_filter called for pan id\n");
cc2520_write_ram(priv, CC2520RAM_PANID,
sizeof(panid), (u8 *)&panid);
}
if (changed & IEEE802154_AFILT_IEEEADDR_CHANGED) {
dev_vdbg(&priv->spi->dev,
"cc2520_filter called for IEEE addr\n");
cc2520_write_ram(priv, CC2520RAM_IEEEADDR,
sizeof(filt->ieee_addr),
(u8 *)&filt->ieee_addr);
}
if (changed & IEEE802154_AFILT_SADDR_CHANGED) {
u16 addr = le16_to_cpu(filt->short_addr);
dev_vdbg(&priv->spi->dev,
"cc2520_filter called for saddr\n");
cc2520_write_ram(priv, CC2520RAM_SHORTADDR,
sizeof(addr), (u8 *)&addr);
}
if (changed & IEEE802154_AFILT_PANC_CHANGED) {
dev_vdbg(&priv->spi->dev,
"cc2520_filter called for panc change\n");
if (filt->pan_coord)
cc2520_write_register(priv, CC2520_FRMFILT0, 0x02);
else
cc2520_write_register(priv, CC2520_FRMFILT0, 0x00);
}
return 0;
}
static int cc2520_register(struct cc2520_private *priv)
{
int ret = -ENOMEM;
priv->hw = ieee802154_alloc_hw(sizeof(*priv), &cc2520_ops);
if (!priv->hw)
goto err_ret;
priv->hw->priv = priv;
priv->hw->parent = &priv->spi->dev;
priv->hw->extra_tx_headroom = 0;
priv->hw->vif_data_size = sizeof(*priv);
ieee802154_random_extended_addr(&priv->hw->phy->perm_extended_addr);
priv->hw->phy->channels_supported[0] = 0x7FFF800;
priv->hw->flags = IEEE802154_HW_OMIT_CKSUM | IEEE802154_HW_AACK |
IEEE802154_HW_AFILT;
dev_vdbg(&priv->spi->dev, "registered cc2520\n");
ret = ieee802154_register_hw(priv->hw);
if (ret)
goto err_free_device;
return 0;
err_free_device:
ieee802154_free_hw(priv->hw);
err_ret:
return ret;
}
static void cc2520_fifop_irqwork(struct work_struct *work)
{
struct cc2520_private *priv
= container_of(work, struct cc2520_private, fifop_irqwork);
dev_dbg(&priv->spi->dev, "fifop interrupt received\n");
if (gpio_get_value(priv->fifo_pin))
cc2520_rx(priv);
else
dev_dbg(&priv->spi->dev, "rxfifo overflow\n");
cc2520_cmd_strobe(priv, CC2520_CMD_SFLUSHRX);
cc2520_cmd_strobe(priv, CC2520_CMD_SFLUSHRX);
}
static irqreturn_t cc2520_fifop_isr(int irq, void *data)
{
struct cc2520_private *priv = data;
schedule_work(&priv->fifop_irqwork);
return IRQ_HANDLED;
}
static irqreturn_t cc2520_sfd_isr(int irq, void *data)
{
struct cc2520_private *priv = data;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (priv->is_tx) {
priv->is_tx = 0;
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&priv->spi->dev, "SFD for TX\n");
complete(&priv->tx_complete);
} else {
spin_unlock_irqrestore(&priv->lock, flags);
dev_dbg(&priv->spi->dev, "SFD for RX\n");
}
return IRQ_HANDLED;
}
static int cc2520_get_platform_data(struct spi_device *spi,
struct cc2520_platform_data *pdata)
{
struct device_node *np = spi->dev.of_node;
struct cc2520_private *priv = spi_get_drvdata(spi);
if (!np) {
struct cc2520_platform_data *spi_pdata = spi->dev.platform_data;
if (!spi_pdata)
return -ENOENT;
*pdata = *spi_pdata;
return 0;
}
pdata->fifo = of_get_named_gpio(np, "fifo-gpio", 0);
priv->fifo_pin = pdata->fifo;
pdata->fifop = of_get_named_gpio(np, "fifop-gpio", 0);
pdata->sfd = of_get_named_gpio(np, "sfd-gpio", 0);
pdata->cca = of_get_named_gpio(np, "cca-gpio", 0);
pdata->vreg = of_get_named_gpio(np, "vreg-gpio", 0);
pdata->reset = of_get_named_gpio(np, "reset-gpio", 0);
pdata->amplified = of_property_read_bool(np, "amplified");
return 0;
}
static int cc2520_hw_init(struct cc2520_private *priv)
{
u8 status = 0, state = 0xff;
int ret;
int timeout = 100;
struct cc2520_platform_data pdata;
ret = cc2520_get_platform_data(priv->spi, &pdata);
if (ret)
goto err_ret;
ret = cc2520_read_register(priv, CC2520_FSMSTAT1, &state);
if (ret)
goto err_ret;
if (state != STATE_IDLE)
return -EINVAL;
do {
ret = cc2520_get_status(priv, &status);
if (ret)
goto err_ret;
if (timeout-- <= 0) {
dev_err(&priv->spi->dev, "oscillator start failed!\n");
return ret;
}
udelay(1);
} while (!(status & CC2520_STATUS_XOSC32M_STABLE));
dev_vdbg(&priv->spi->dev, "oscillator brought up\n");
if (pdata.amplified) {
ret = cc2520_write_register(priv, CC2520_TXPOWER, 0xF9);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_AGCCTRL1, 0x16);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_GPIOCTRL0, 0x46);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_GPIOCTRL5, 0x47);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_GPIOPOLARITY, 0x1e);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_TXCTRL, 0xc1);
if (ret)
goto err_ret;
} else {
ret = cc2520_write_register(priv, CC2520_TXPOWER, 0xF7);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_AGCCTRL1, 0x11);
if (ret)
goto err_ret;
}
ret = cc2520_write_register(priv, CC2520_CCACTRL0, 0x1A);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_MDMCTRL0, 0x85);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_MDMCTRL1, 0x14);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_RXCTRL, 0x3f);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_FSCTRL, 0x5a);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_FSCAL1, 0x2b);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_ADCTEST0, 0x10);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_ADCTEST1, 0x0e);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_ADCTEST2, 0x03);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_FRMCTRL0, 0x60);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_FRMCTRL1, 0x03);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_FRMFILT0, 0x00);
if (ret)
goto err_ret;
ret = cc2520_write_register(priv, CC2520_FIFOPCTRL, 127);
if (ret)
goto err_ret;
return 0;
err_ret:
return ret;
}
static int cc2520_probe(struct spi_device *spi)
{
struct cc2520_private *priv;
struct cc2520_platform_data pdata;
int ret;
priv = devm_kzalloc(&spi->dev, sizeof(*priv), GFP_KERNEL);
if (!priv)
return -ENOMEM;
spi_set_drvdata(spi, priv);
ret = cc2520_get_platform_data(spi, &pdata);
if (ret < 0) {
dev_err(&spi->dev, "no platform data\n");
return -EINVAL;
}
priv->spi = spi;
priv->buf = devm_kzalloc(&spi->dev,
SPI_COMMAND_BUFFER, GFP_KERNEL);
if (!priv->buf)
return -ENOMEM;
mutex_init(&priv->buffer_mutex);
INIT_WORK(&priv->fifop_irqwork, cc2520_fifop_irqwork);
spin_lock_init(&priv->lock);
init_completion(&priv->tx_complete);
if (!gpio_is_valid(pdata.fifo)) {
dev_err(&spi->dev, "fifo gpio is not valid\n");
ret = -EINVAL;
goto err_hw_init;
}
ret = devm_gpio_request_one(&spi->dev, pdata.fifo,
GPIOF_IN, "fifo");
if (ret)
goto err_hw_init;
if (!gpio_is_valid(pdata.cca)) {
dev_err(&spi->dev, "cca gpio is not valid\n");
ret = -EINVAL;
goto err_hw_init;
}
ret = devm_gpio_request_one(&spi->dev, pdata.cca,
GPIOF_IN, "cca");
if (ret)
goto err_hw_init;
if (!gpio_is_valid(pdata.fifop)) {
dev_err(&spi->dev, "fifop gpio is not valid\n");
ret = -EINVAL;
goto err_hw_init;
}
ret = devm_gpio_request_one(&spi->dev, pdata.fifop,
GPIOF_IN, "fifop");
if (ret)
goto err_hw_init;
if (!gpio_is_valid(pdata.sfd)) {
dev_err(&spi->dev, "sfd gpio is not valid\n");
ret = -EINVAL;
goto err_hw_init;
}
ret = devm_gpio_request_one(&spi->dev, pdata.sfd,
GPIOF_IN, "sfd");
if (ret)
goto err_hw_init;
if (!gpio_is_valid(pdata.reset)) {
dev_err(&spi->dev, "reset gpio is not valid\n");
ret = -EINVAL;
goto err_hw_init;
}
ret = devm_gpio_request_one(&spi->dev, pdata.reset,
GPIOF_OUT_INIT_LOW, "reset");
if (ret)
goto err_hw_init;
if (!gpio_is_valid(pdata.vreg)) {
dev_err(&spi->dev, "vreg gpio is not valid\n");
ret = -EINVAL;
goto err_hw_init;
}
ret = devm_gpio_request_one(&spi->dev, pdata.vreg,
GPIOF_OUT_INIT_LOW, "vreg");
if (ret)
goto err_hw_init;
gpio_set_value(pdata.vreg, HIGH);
usleep_range(100, 150);
gpio_set_value(pdata.reset, HIGH);
usleep_range(200, 250);
ret = cc2520_hw_init(priv);
if (ret)
goto err_hw_init;
ret = devm_request_irq(&spi->dev,
gpio_to_irq(pdata.fifop),
cc2520_fifop_isr,
IRQF_TRIGGER_RISING,
dev_name(&spi->dev),
priv);
if (ret) {
dev_err(&spi->dev, "could not get fifop irq\n");
goto err_hw_init;
}
ret = devm_request_irq(&spi->dev,
gpio_to_irq(pdata.sfd),
cc2520_sfd_isr,
IRQF_TRIGGER_FALLING,
dev_name(&spi->dev),
priv);
if (ret) {
dev_err(&spi->dev, "could not get sfd irq\n");
goto err_hw_init;
}
ret = cc2520_register(priv);
if (ret)
goto err_hw_init;
return 0;
err_hw_init:
mutex_destroy(&priv->buffer_mutex);
flush_work(&priv->fifop_irqwork);
return ret;
}
static int cc2520_remove(struct spi_device *spi)
{
struct cc2520_private *priv = spi_get_drvdata(spi);
mutex_destroy(&priv->buffer_mutex);
flush_work(&priv->fifop_irqwork);
ieee802154_unregister_hw(priv->hw);
ieee802154_free_hw(priv->hw);
return 0;
}
