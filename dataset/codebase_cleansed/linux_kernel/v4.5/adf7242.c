static int adf7242_status(struct adf7242_local *lp, u8 *stat)
{
int status;
mutex_lock(&lp->bmux);
status = spi_sync(lp->spi, &lp->stat_msg);
*stat = lp->buf_stat_rx;
mutex_unlock(&lp->bmux);
return status;
}
static int adf7242_wait_status(struct adf7242_local *lp, unsigned status,
unsigned mask, int line)
{
int cnt = 0, ret = 0;
u8 stat;
do {
adf7242_status(lp, &stat);
cnt++;
} while (((stat & mask) != status) && (cnt < MAX_POLL_LOOPS));
if (cnt >= MAX_POLL_LOOPS) {
ret = -ETIMEDOUT;
if (!(stat & STAT_RC_READY)) {
adf7242_soft_reset(lp, line);
adf7242_status(lp, &stat);
if ((stat & mask) == status)
ret = 0;
}
if (ret < 0)
dev_warn(&lp->spi->dev,
"%s:line %d Timeout status 0x%x (%d)\n",
__func__, line, stat, cnt);
}
dev_vdbg(&lp->spi->dev, "%s : loops=%d line %d\n", __func__, cnt, line);
return ret;
}
static int adf7242_wait_ready(struct adf7242_local *lp, int line)
{
return adf7242_wait_status(lp, STAT_RC_READY | STAT_SPI_READY,
STAT_RC_READY | STAT_SPI_READY, line);
}
static int adf7242_write_fbuf(struct adf7242_local *lp, u8 *data, u8 len)
{
u8 *buf = lp->buf;
int status;
struct spi_message msg;
struct spi_transfer xfer_head = {
.len = 2,
.tx_buf = buf,
};
struct spi_transfer xfer_buf = {
.len = len,
.tx_buf = data,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer_head, &msg);
spi_message_add_tail(&xfer_buf, &msg);
adf7242_wait_ready(lp, __LINE__);
mutex_lock(&lp->bmux);
buf[0] = CMD_SPI_PKT_WR;
buf[1] = len + 2;
status = spi_sync(lp->spi, &msg);
mutex_unlock(&lp->bmux);
return status;
}
static int adf7242_read_fbuf(struct adf7242_local *lp,
u8 *data, size_t len, bool packet_read)
{
u8 *buf = lp->buf;
int status;
struct spi_message msg;
struct spi_transfer xfer_head = {
.len = 3,
.tx_buf = buf,
.rx_buf = buf,
};
struct spi_transfer xfer_buf = {
.len = len,
.rx_buf = data,
};
spi_message_init(&msg);
spi_message_add_tail(&xfer_head, &msg);
spi_message_add_tail(&xfer_buf, &msg);
adf7242_wait_ready(lp, __LINE__);
mutex_lock(&lp->bmux);
if (packet_read) {
buf[0] = CMD_SPI_PKT_RD;
buf[1] = CMD_SPI_NOP;
buf[2] = 0;
} else {
buf[0] = CMD_SPI_PRAM_RD;
buf[1] = 0;
buf[2] = CMD_SPI_NOP;
}
status = spi_sync(lp->spi, &msg);
mutex_unlock(&lp->bmux);
return status;
}
static int adf7242_read_reg(struct adf7242_local *lp, u16 addr, u8 *data)
{
int status;
struct spi_message msg;
struct spi_transfer xfer = {
.len = 4,
.tx_buf = lp->buf_read_tx,
.rx_buf = lp->buf_read_rx,
};
adf7242_wait_ready(lp, __LINE__);
mutex_lock(&lp->bmux);
lp->buf_read_tx[0] = CMD_SPI_MEM_RD(addr);
lp->buf_read_tx[1] = addr;
lp->buf_read_tx[2] = CMD_SPI_NOP;
lp->buf_read_tx[3] = CMD_SPI_NOP;
spi_message_init(&msg);
spi_message_add_tail(&xfer, &msg);
status = spi_sync(lp->spi, &msg);
if (msg.status)
status = msg.status;
if (!status)
*data = lp->buf_read_rx[3];
mutex_unlock(&lp->bmux);
dev_vdbg(&lp->spi->dev, "%s : REG 0x%X, VAL 0x%X\n", __func__,
addr, *data);
return status;
}
static int adf7242_write_reg(struct adf7242_local *lp, u16 addr, u8 data)
{
int status;
adf7242_wait_ready(lp, __LINE__);
mutex_lock(&lp->bmux);
lp->buf_reg_tx[0] = CMD_SPI_MEM_WR(addr);
lp->buf_reg_tx[1] = addr;
lp->buf_reg_tx[2] = data;
status = spi_write(lp->spi, lp->buf_reg_tx, 3);
mutex_unlock(&lp->bmux);
dev_vdbg(&lp->spi->dev, "%s : REG 0x%X, VAL 0x%X\n",
__func__, addr, data);
return status;
}
static int adf7242_cmd(struct adf7242_local *lp, unsigned cmd)
{
int status;
dev_vdbg(&lp->spi->dev, "%s : CMD=0x%X\n", __func__, cmd);
if (cmd != CMD_RC_PC_RESET_NO_WAIT)
adf7242_wait_ready(lp, __LINE__);
mutex_lock(&lp->bmux);
lp->buf_cmd = cmd;
status = spi_write(lp->spi, &lp->buf_cmd, 1);
mutex_unlock(&lp->bmux);
return status;
}
static int adf7242_upload_firmware(struct adf7242_local *lp, u8 *data, u16 len)
{
struct spi_message msg;
struct spi_transfer xfer_buf = { };
int status, i, page = 0;
u8 *buf = lp->buf;
struct spi_transfer xfer_head = {
.len = 2,
.tx_buf = buf,
};
buf[0] = CMD_SPI_PRAM_WR;
buf[1] = 0;
spi_message_init(&msg);
spi_message_add_tail(&xfer_head, &msg);
spi_message_add_tail(&xfer_buf, &msg);
for (i = len; i >= 0; i -= PRAM_PAGESIZE) {
adf7242_write_reg(lp, REG_PRAMPG, page);
xfer_buf.len = (i >= PRAM_PAGESIZE) ? PRAM_PAGESIZE : i;
xfer_buf.tx_buf = &data[page * PRAM_PAGESIZE];
mutex_lock(&lp->bmux);
status = spi_sync(lp->spi, &msg);
mutex_unlock(&lp->bmux);
page++;
}
return status;
}
static int adf7242_verify_firmware(struct adf7242_local *lp,
const u8 *data, size_t len)
{
#ifdef DEBUG
int i, j;
unsigned int page;
u8 *buf = kmalloc(PRAM_PAGESIZE, GFP_KERNEL);
if (!buf)
return -ENOMEM;
for (page = 0, i = len; i >= 0; i -= PRAM_PAGESIZE, page++) {
size_t nb = (i >= PRAM_PAGESIZE) ? PRAM_PAGESIZE : i;
adf7242_write_reg(lp, REG_PRAMPG, page);
adf7242_read_fbuf(lp, buf, nb, false);
for (j = 0; j < nb; j++) {
if (buf[j] != data[page * PRAM_PAGESIZE + j]) {
kfree(buf);
return -EIO;
}
}
}
kfree(buf);
#endif
return 0;
}
static int adf7242_set_txpower(struct ieee802154_hw *hw, int mbm)
{
struct adf7242_local *lp = hw->priv;
u8 pwr, bias_ctrl, dbias, tmp;
int db = mbm / 100;
dev_vdbg(&lp->spi->dev, "%s : Power %d dB\n", __func__, db);
if (db > 5 || db < -26)
return -EINVAL;
db = DIV_ROUND_CLOSEST(db + 29, 2);
if (db > 15) {
dbias = PA_DBIAS_HIGH_POWER;
bias_ctrl = PA_BIAS_HIGH_POWER;
} else {
dbias = PA_DBIAS_LOW_POWER;
bias_ctrl = PA_BIAS_LOW_POWER;
}
pwr = clamp_t(u8, db, 3, 15);
adf7242_read_reg(lp, REG_PA_CFG, &tmp);
tmp &= ~PA_BRIDGE_DBIAS(~0);
tmp |= PA_BRIDGE_DBIAS(dbias);
adf7242_write_reg(lp, REG_PA_CFG, tmp);
adf7242_read_reg(lp, REG_PA_BIAS, &tmp);
tmp &= ~PA_BIAS_CTRL(~0);
tmp |= PA_BIAS_CTRL(bias_ctrl);
adf7242_write_reg(lp, REG_PA_BIAS, tmp);
adf7242_read_reg(lp, REG_EXTPA_MSC, &tmp);
tmp &= ~PA_PWR(~0);
tmp |= PA_PWR(pwr);
return adf7242_write_reg(lp, REG_EXTPA_MSC, tmp);
}
static int adf7242_set_csma_params(struct ieee802154_hw *hw, u8 min_be,
u8 max_be, u8 retries)
{
struct adf7242_local *lp = hw->priv;
int ret;
dev_vdbg(&lp->spi->dev, "%s : min_be=%d max_be=%d retries=%d\n",
__func__, min_be, max_be, retries);
if (min_be > max_be || max_be > 8 || retries > 5)
return -EINVAL;
ret = adf7242_write_reg(lp, REG_AUTO_TX1,
MAX_FRAME_RETRIES(lp->max_frame_retries) |
MAX_CCA_RETRIES(retries));
if (ret)
return ret;
lp->max_cca_retries = retries;
lp->max_be = max_be;
lp->min_be = min_be;
return adf7242_write_reg(lp, REG_AUTO_TX2, CSMA_MAX_BE(max_be) |
CSMA_MIN_BE(min_be));
}
static int adf7242_set_frame_retries(struct ieee802154_hw *hw, s8 retries)
{
struct adf7242_local *lp = hw->priv;
int ret = 0;
dev_vdbg(&lp->spi->dev, "%s : Retries = %d\n", __func__, retries);
if (retries < -1 || retries > 15)
return -EINVAL;
if (retries >= 0)
ret = adf7242_write_reg(lp, REG_AUTO_TX1,
MAX_FRAME_RETRIES(retries) |
MAX_CCA_RETRIES(lp->max_cca_retries));
lp->max_frame_retries = retries;
return ret;
}
static int adf7242_ed(struct ieee802154_hw *hw, u8 *level)
{
struct adf7242_local *lp = hw->priv;
*level = lp->rssi;
dev_vdbg(&lp->spi->dev, "%s :Exit level=%d\n",
__func__, *level);
return 0;
}
static int adf7242_start(struct ieee802154_hw *hw)
{
struct adf7242_local *lp = hw->priv;
adf7242_cmd(lp, CMD_RC_PHY_RDY);
adf7242_write_reg(lp, REG_IRQ1_SRC1, 0xFF);
enable_irq(lp->spi->irq);
set_bit(FLAG_START, &lp->flags);
return adf7242_cmd(lp, CMD_RC_RX);
}
static void adf7242_stop(struct ieee802154_hw *hw)
{
struct adf7242_local *lp = hw->priv;
adf7242_cmd(lp, CMD_RC_IDLE);
clear_bit(FLAG_START, &lp->flags);
disable_irq(lp->spi->irq);
adf7242_write_reg(lp, REG_IRQ1_SRC1, 0xFF);
}
static int adf7242_channel(struct ieee802154_hw *hw, u8 page, u8 channel)
{
struct adf7242_local *lp = hw->priv;
unsigned long freq;
dev_dbg(&lp->spi->dev, "%s :Channel=%d\n", __func__, channel);
might_sleep();
WARN_ON(page != 0);
WARN_ON(channel < 11);
WARN_ON(channel > 26);
freq = (2405 + 5 * (channel - 11)) * 100;
adf7242_cmd(lp, CMD_RC_PHY_RDY);
adf7242_write_reg(lp, REG_CH_FREQ0, freq);
adf7242_write_reg(lp, REG_CH_FREQ1, freq >> 8);
adf7242_write_reg(lp, REG_CH_FREQ2, freq >> 16);
return adf7242_cmd(lp, CMD_RC_RX);
}
static int adf7242_set_hw_addr_filt(struct ieee802154_hw *hw,
struct ieee802154_hw_addr_filt *filt,
unsigned long changed)
{
struct adf7242_local *lp = hw->priv;
u8 reg;
dev_dbg(&lp->spi->dev, "%s :Changed=0x%lX\n", __func__, changed);
might_sleep();
if (changed & IEEE802154_AFILT_IEEEADDR_CHANGED) {
u8 addr[8], i;
memcpy(addr, &filt->ieee_addr, 8);
for (i = 0; i < 8; i++)
adf7242_write_reg(lp, REG_IEEE_ADDR_0 + i, addr[i]);
}
if (changed & IEEE802154_AFILT_SADDR_CHANGED) {
u16 saddr = le16_to_cpu(filt->short_addr);
adf7242_write_reg(lp, REG_SHORT_ADDR_0, saddr);
adf7242_write_reg(lp, REG_SHORT_ADDR_1, saddr >> 8);
}
if (changed & IEEE802154_AFILT_PANID_CHANGED) {
u16 pan_id = le16_to_cpu(filt->pan_id);
adf7242_write_reg(lp, REG_PAN_ID0, pan_id);
adf7242_write_reg(lp, REG_PAN_ID1, pan_id >> 8);
}
if (changed & IEEE802154_AFILT_PANC_CHANGED) {
adf7242_read_reg(lp, REG_AUTO_CFG, &reg);
if (filt->pan_coord)
reg |= IS_PANCOORD;
else
reg &= ~IS_PANCOORD;
adf7242_write_reg(lp, REG_AUTO_CFG, reg);
}
return 0;
}
static int adf7242_set_promiscuous_mode(struct ieee802154_hw *hw, bool on)
{
struct adf7242_local *lp = hw->priv;
dev_dbg(&lp->spi->dev, "%s : mode %d\n", __func__, on);
lp->promiscuous = on;
if (on) {
adf7242_write_reg(lp, REG_AUTO_CFG, 0);
return adf7242_write_reg(lp, REG_FFILT_CFG,
ACCEPT_BEACON_FRAMES |
ACCEPT_DATA_FRAMES |
ACCEPT_MACCMD_FRAMES |
ACCEPT_ALL_ADDRESS |
ACCEPT_ACK_FRAMES |
ACCEPT_RESERVED_FRAMES);
} else {
adf7242_write_reg(lp, REG_FFILT_CFG,
ACCEPT_BEACON_FRAMES |
ACCEPT_DATA_FRAMES |
ACCEPT_MACCMD_FRAMES |
ACCEPT_RESERVED_FRAMES);
return adf7242_write_reg(lp, REG_AUTO_CFG, RX_AUTO_ACK_EN);
}
}
static int adf7242_set_cca_ed_level(struct ieee802154_hw *hw, s32 mbm)
{
struct adf7242_local *lp = hw->priv;
s8 level = clamp_t(s8, mbm / 100, S8_MIN, S8_MAX);
dev_dbg(&lp->spi->dev, "%s : level %d\n", __func__, level);
return adf7242_write_reg(lp, REG_CCA1, level);
}
static int adf7242_xmit(struct ieee802154_hw *hw, struct sk_buff *skb)
{
struct adf7242_local *lp = hw->priv;
int ret;
set_bit(FLAG_XMIT, &lp->flags);
reinit_completion(&lp->tx_complete);
adf7242_cmd(lp, CMD_RC_PHY_RDY);
ret = adf7242_write_fbuf(lp, skb->data, skb->len);
if (ret)
goto err;
ret = adf7242_cmd(lp, CMD_RC_CSMACA);
if (ret)
goto err;
ret = wait_for_completion_interruptible_timeout(&lp->tx_complete,
HZ / 10);
if (ret < 0)
goto err;
if (ret == 0) {
dev_dbg(&lp->spi->dev, "Timeout waiting for TX interrupt\n");
ret = -ETIMEDOUT;
goto err;
}
if (lp->tx_stat != SUCCESS) {
dev_dbg(&lp->spi->dev,
"Error xmit: Retry count exceeded Status=0x%x\n",
lp->tx_stat);
ret = -ECOMM;
} else {
ret = 0;
}
err:
clear_bit(FLAG_XMIT, &lp->flags);
adf7242_cmd(lp, CMD_RC_RX);
return ret;
}
static int adf7242_rx(struct adf7242_local *lp)
{
struct sk_buff *skb;
size_t len;
int ret;
u8 lqi, len_u8, *data;
adf7242_read_reg(lp, 0, &len_u8);
len = len_u8;
if (!ieee802154_is_valid_psdu_len(len)) {
dev_dbg(&lp->spi->dev,
"corrupted frame received len %d\n", (int)len);
len = IEEE802154_MTU;
}
skb = dev_alloc_skb(len);
if (!skb) {
adf7242_cmd(lp, CMD_RC_RX);
return -ENOMEM;
}
data = skb_put(skb, len);
ret = adf7242_read_fbuf(lp, data, len, true);
if (ret < 0) {
kfree_skb(skb);
adf7242_cmd(lp, CMD_RC_RX);
return ret;
}
lqi = data[len - 2];
lp->rssi = data[len - 1];
adf7242_cmd(lp, CMD_RC_RX);
skb_trim(skb, len - 2);
ieee802154_rx_irqsafe(lp->hw, skb, lqi);
dev_dbg(&lp->spi->dev, "%s: ret=%d len=%d lqi=%d rssi=%d\n",
__func__, ret, (int)len, (int)lqi, lp->rssi);
return 0;
}
static void adf7242_debug(u8 irq1)
{
#ifdef DEBUG
u8 stat;
adf7242_status(lp, &stat);
dev_dbg(&lp->spi->dev, "%s IRQ1 = %X:\n%s%s%s%s%s%s%s%s\n",
__func__, irq1,
irq1 & IRQ_CCA_COMPLETE ? "IRQ_CCA_COMPLETE\n" : "",
irq1 & IRQ_SFD_RX ? "IRQ_SFD_RX\n" : "",
irq1 & IRQ_SFD_TX ? "IRQ_SFD_TX\n" : "",
irq1 & IRQ_RX_PKT_RCVD ? "IRQ_RX_PKT_RCVD\n" : "",
irq1 & IRQ_TX_PKT_SENT ? "IRQ_TX_PKT_SENT\n" : "",
irq1 & IRQ_CSMA_CA ? "IRQ_CSMA_CA\n" : "",
irq1 & IRQ_FRAME_VALID ? "IRQ_FRAME_VALID\n" : "",
irq1 & IRQ_ADDRESS_VALID ? "IRQ_ADDRESS_VALID\n" : "");
dev_dbg(&lp->spi->dev, "%s STATUS = %X:\n%s\n%s%s%s%s%s\n",
__func__, stat,
stat & STAT_RC_READY ? "RC_READY" : "RC_BUSY",
(stat & 0xf) == RC_STATUS_IDLE ? "RC_STATUS_IDLE" : "",
(stat & 0xf) == RC_STATUS_MEAS ? "RC_STATUS_MEAS" : "",
(stat & 0xf) == RC_STATUS_PHY_RDY ? "RC_STATUS_PHY_RDY" : "",
(stat & 0xf) == RC_STATUS_RX ? "RC_STATUS_RX" : "",
(stat & 0xf) == RC_STATUS_TX ? "RC_STATUS_TX" : "");
}
irqreturn_t adf7242_isr(int irq, void *data)
{
struct adf7242_local *lp = data;
unsigned xmit;
u8 irq1;
adf7242_wait_status(lp, RC_STATUS_PHY_RDY, RC_STATUS_MASK, __LINE__);
adf7242_read_reg(lp, REG_IRQ1_SRC1, &irq1);
adf7242_write_reg(lp, REG_IRQ1_SRC1, irq1);
if (!(irq1 & (IRQ_RX_PKT_RCVD | IRQ_CSMA_CA)))
dev_err(&lp->spi->dev, "%s :ERROR IRQ1 = 0x%X\n",
__func__, irq1);
adf7242_debug(irq1);
xmit = test_bit(FLAG_XMIT, &lp->flags);
if (xmit && (irq1 & IRQ_CSMA_CA)) {
if (ADF7242_REPORT_CSMA_CA_STAT) {
u8 astat;
adf7242_read_reg(lp, REG_AUTO_STATUS, &astat);
astat &= AUTO_STATUS_MASK;
dev_dbg(&lp->spi->dev, "AUTO_STATUS = %X:\n%s%s%s%s\n",
astat,
astat == SUCCESS ? "SUCCESS" : "",
astat ==
SUCCESS_DATPEND ? "SUCCESS_DATPEND" : "",
astat == FAILURE_CSMACA ? "FAILURE_CSMACA" : "",
astat == FAILURE_NOACK ? "FAILURE_NOACK" : "");
lp->tx_stat = astat;
} else {
lp->tx_stat = SUCCESS;
}
complete(&lp->tx_complete);
} else if (!xmit && (irq1 & IRQ_RX_PKT_RCVD) &&
(irq1 & IRQ_FRAME_VALID)) {
adf7242_rx(lp);
} else if (!xmit && test_bit(FLAG_START, &lp->flags)) {
dev_dbg(&lp->spi->dev, "%s:%d : ERROR IRQ1 = 0x%X\n",
__func__, __LINE__, irq1);
adf7242_cmd(lp, CMD_RC_PHY_RDY);
adf7242_write_reg(lp, REG_IRQ1_SRC1, 0xFF);
adf7242_cmd(lp, CMD_RC_RX);
} else {
dev_dbg(&lp->spi->dev, "%s:%d : ERROR IRQ1 = 0x%X, xmit %d\n",
__func__, __LINE__, irq1, xmit);
complete(&lp->tx_complete);
}
return IRQ_HANDLED;
}
static int adf7242_soft_reset(struct adf7242_local *lp, int line)
{
dev_warn(&lp->spi->dev, "%s (line %d)\n", __func__, line);
if (test_bit(FLAG_START, &lp->flags))
disable_irq_nosync(lp->spi->irq);
adf7242_cmd(lp, CMD_RC_PC_RESET_NO_WAIT);
usleep_range(200, 250);
adf7242_write_reg(lp, REG_PKT_CFG, ADDON_EN | BIT(2));
adf7242_cmd(lp, CMD_RC_PHY_RDY);
adf7242_set_promiscuous_mode(lp->hw, lp->promiscuous);
adf7242_set_csma_params(lp->hw, lp->min_be, lp->max_be,
lp->max_cca_retries);
adf7242_write_reg(lp, REG_IRQ1_SRC1, 0xFF);
if (test_bit(FLAG_START, &lp->flags)) {
enable_irq(lp->spi->irq);
return adf7242_cmd(lp, CMD_RC_RX);
}
return 0;
}
static int adf7242_hw_init(struct adf7242_local *lp)
{
int ret;
const struct firmware *fw;
adf7242_cmd(lp, CMD_RC_RESET);
adf7242_cmd(lp, CMD_RC_IDLE);
ret = request_firmware(&fw, FIRMWARE, &lp->spi->dev);
if (ret) {
dev_err(&lp->spi->dev,
"request_firmware() failed with %d\n", ret);
return ret;
}
ret = adf7242_upload_firmware(lp, (u8 *)fw->data, fw->size);
if (ret) {
dev_err(&lp->spi->dev,
"upload firmware failed with %d\n", ret);
return ret;
}
ret = adf7242_verify_firmware(lp, (u8 *)fw->data, fw->size);
if (ret) {
dev_err(&lp->spi->dev,
"verify firmware failed with %d\n", ret);
return ret;
}
adf7242_cmd(lp, CMD_RC_PC_RESET);
release_firmware(fw);
adf7242_write_reg(lp, REG_FFILT_CFG,
ACCEPT_BEACON_FRAMES |
ACCEPT_DATA_FRAMES |
ACCEPT_MACCMD_FRAMES |
ACCEPT_RESERVED_FRAMES);
adf7242_write_reg(lp, REG_AUTO_CFG, RX_AUTO_ACK_EN);
adf7242_write_reg(lp, REG_PKT_CFG, ADDON_EN | BIT(2));
adf7242_write_reg(lp, REG_EXTPA_MSC, 0xF1);
adf7242_write_reg(lp, REG_RXFE_CFG, 0x1D);
adf7242_write_reg(lp, REG_IRQ1_EN0, 0);
adf7242_write_reg(lp, REG_IRQ1_EN1, IRQ_RX_PKT_RCVD | IRQ_CSMA_CA);
adf7242_write_reg(lp, REG_IRQ1_SRC1, 0xFF);
adf7242_write_reg(lp, REG_IRQ1_SRC0, 0xFF);
adf7242_cmd(lp, CMD_RC_IDLE);
return 0;
}
static int adf7242_stats_show(struct seq_file *file, void *offset)
{
struct adf7242_local *lp = spi_get_drvdata(file->private);
u8 stat, irq1;
adf7242_status(lp, &stat);
adf7242_read_reg(lp, REG_IRQ1_SRC1, &irq1);
seq_printf(file, "IRQ1 = %X:\n%s%s%s%s%s%s%s%s\n", irq1,
irq1 & IRQ_CCA_COMPLETE ? "IRQ_CCA_COMPLETE\n" : "",
irq1 & IRQ_SFD_RX ? "IRQ_SFD_RX\n" : "",
irq1 & IRQ_SFD_TX ? "IRQ_SFD_TX\n" : "",
irq1 & IRQ_RX_PKT_RCVD ? "IRQ_RX_PKT_RCVD\n" : "",
irq1 & IRQ_TX_PKT_SENT ? "IRQ_TX_PKT_SENT\n" : "",
irq1 & IRQ_CSMA_CA ? "IRQ_CSMA_CA\n" : "",
irq1 & IRQ_FRAME_VALID ? "IRQ_FRAME_VALID\n" : "",
irq1 & IRQ_ADDRESS_VALID ? "IRQ_ADDRESS_VALID\n" : "");
seq_printf(file, "STATUS = %X:\n%s\n%s%s%s%s%s\n", stat,
stat & STAT_RC_READY ? "RC_READY" : "RC_BUSY",
(stat & 0xf) == RC_STATUS_IDLE ? "RC_STATUS_IDLE" : "",
(stat & 0xf) == RC_STATUS_MEAS ? "RC_STATUS_MEAS" : "",
(stat & 0xf) == RC_STATUS_PHY_RDY ? "RC_STATUS_PHY_RDY" : "",
(stat & 0xf) == RC_STATUS_RX ? "RC_STATUS_RX" : "",
(stat & 0xf) == RC_STATUS_TX ? "RC_STATUS_TX" : "");
seq_printf(file, "RSSI = %d\n", lp->rssi);
return 0;
}
static int adf7242_debugfs_init(struct adf7242_local *lp)
{
char debugfs_dir_name[DNAME_INLINE_LEN + 1] = "adf7242-";
struct dentry *stats;
strncat(debugfs_dir_name, dev_name(&lp->spi->dev), DNAME_INLINE_LEN);
lp->debugfs_root = debugfs_create_dir(debugfs_dir_name, NULL);
if (IS_ERR_OR_NULL(lp->debugfs_root))
return PTR_ERR_OR_ZERO(lp->debugfs_root);
stats = debugfs_create_devm_seqfile(&lp->spi->dev, "status",
lp->debugfs_root,
adf7242_stats_show);
return PTR_ERR_OR_ZERO(stats);
return 0;
}
static int adf7242_probe(struct spi_device *spi)
{
struct ieee802154_hw *hw;
struct adf7242_local *lp;
int ret, irq_type;
if (!spi->irq) {
dev_err(&spi->dev, "no IRQ specified\n");
return -EINVAL;
}
hw = ieee802154_alloc_hw(sizeof(*lp), &adf7242_ops);
if (!hw)
return -ENOMEM;
lp = hw->priv;
lp->hw = hw;
lp->spi = spi;
hw->priv = lp;
hw->parent = &spi->dev;
hw->extra_tx_headroom = 0;
hw->phy->supported.channels[0] = 0x7FFF800;
hw->flags = IEEE802154_HW_OMIT_CKSUM |
IEEE802154_HW_CSMA_PARAMS |
IEEE802154_HW_FRAME_RETRIES | IEEE802154_HW_AFILT |
IEEE802154_HW_PROMISCUOUS;
hw->phy->flags = WPAN_PHY_FLAG_TXPOWER |
WPAN_PHY_FLAG_CCA_ED_LEVEL |
WPAN_PHY_FLAG_CCA_MODE;
hw->phy->supported.cca_modes = BIT(NL802154_CCA_ENERGY);
hw->phy->supported.cca_ed_levels = adf7242_ed_levels;
hw->phy->supported.cca_ed_levels_size = ARRAY_SIZE(adf7242_ed_levels);
hw->phy->cca.mode = NL802154_CCA_ENERGY;
hw->phy->supported.tx_powers = adf7242_powers;
hw->phy->supported.tx_powers_size = ARRAY_SIZE(adf7242_powers);
hw->phy->supported.min_minbe = 0;
hw->phy->supported.max_minbe = 8;
hw->phy->supported.min_maxbe = 3;
hw->phy->supported.max_maxbe = 8;
hw->phy->supported.min_frame_retries = 0;
hw->phy->supported.max_frame_retries = 15;
hw->phy->supported.min_csma_backoffs = 0;
hw->phy->supported.max_csma_backoffs = 5;
ieee802154_random_extended_addr(&hw->phy->perm_extended_addr);
mutex_init(&lp->bmux);
init_completion(&lp->tx_complete);
lp->stat_xfer.len = 1;
lp->stat_xfer.tx_buf = &lp->buf_stat_tx;
lp->stat_xfer.rx_buf = &lp->buf_stat_rx;
lp->buf_stat_tx = CMD_SPI_NOP;
spi_message_init(&lp->stat_msg);
spi_message_add_tail(&lp->stat_xfer, &lp->stat_msg);
spi_set_drvdata(spi, lp);
ret = adf7242_hw_init(lp);
if (ret)
goto err_hw_init;
irq_type = irq_get_trigger_type(spi->irq);
if (!irq_type)
irq_type = IRQF_TRIGGER_HIGH;
ret = devm_request_threaded_irq(&spi->dev, spi->irq, NULL, adf7242_isr,
irq_type | IRQF_ONESHOT,
dev_name(&spi->dev), lp);
if (ret)
goto err_hw_init;
disable_irq(spi->irq);
ret = ieee802154_register_hw(lp->hw);
if (ret)
goto err_hw_init;
dev_set_drvdata(&spi->dev, lp);
adf7242_debugfs_init(lp);
dev_info(&spi->dev, "mac802154 IRQ-%d registered\n", spi->irq);
return ret;
err_hw_init:
mutex_destroy(&lp->bmux);
ieee802154_free_hw(lp->hw);
return ret;
}
static int adf7242_remove(struct spi_device *spi)
{
struct adf7242_local *lp = spi_get_drvdata(spi);
if (!IS_ERR_OR_NULL(lp->debugfs_root))
debugfs_remove_recursive(lp->debugfs_root);
ieee802154_unregister_hw(lp->hw);
mutex_destroy(&lp->bmux);
ieee802154_free_hw(lp->hw);
return 0;
}
