static bool
mrf24j40_short_reg_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case REG_RXMCR:
case REG_PANIDL:
case REG_PANIDH:
case REG_SADRL:
case REG_SADRH:
case REG_EADR0:
case REG_EADR1:
case REG_EADR2:
case REG_EADR3:
case REG_EADR4:
case REG_EADR5:
case REG_EADR6:
case REG_EADR7:
case REG_RXFLUSH:
case REG_ORDER:
case REG_TXMCR:
case REG_ACKTMOUT:
case REG_ESLOTG1:
case REG_SYMTICKL:
case REG_SYMTICKH:
case REG_PACON0:
case REG_PACON1:
case REG_PACON2:
case REG_TXBCON0:
case REG_TXNCON:
case REG_TXG1CON:
case REG_TXG2CON:
case REG_ESLOTG23:
case REG_ESLOTG45:
case REG_ESLOTG67:
case REG_TXPEND:
case REG_WAKECON:
case REG_FROMOFFSET:
case REG_TXBCON1:
case REG_GATECLK:
case REG_TXTIME:
case REG_HSYMTMRL:
case REG_HSYMTMRH:
case REG_SOFTRST:
case REG_SECCON0:
case REG_SECCON1:
case REG_TXSTBL:
case REG_RXSR:
case REG_INTCON:
case REG_TRISGPIO:
case REG_GPIO:
case REG_RFCTL:
case REG_SECCR2:
case REG_SLPACK:
case REG_BBREG0:
case REG_BBREG1:
case REG_BBREG2:
case REG_BBREG3:
case REG_BBREG4:
case REG_BBREG6:
case REG_CCAEDTH:
return true;
default:
return false;
}
}
static bool
mrf24j40_short_reg_readable(struct device *dev, unsigned int reg)
{
bool rc;
rc = mrf24j40_short_reg_writeable(dev, reg);
if (rc)
return rc;
switch (reg) {
case REG_TXSTAT:
case REG_INTSTAT:
return true;
default:
return false;
}
}
static bool
mrf24j40_short_reg_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case REG_TXSTAT:
case REG_INTSTAT:
case REG_RXFLUSH:
case REG_TXNCON:
case REG_SOFTRST:
case REG_RFCTL:
case REG_TXBCON0:
case REG_TXG1CON:
case REG_TXG2CON:
case REG_TXBCON1:
case REG_SECCON0:
case REG_RXSR:
case REG_SLPACK:
case REG_SECCR2:
case REG_BBREG6:
case REG_BBREG1:
return true;
default:
return false;
}
}
static bool
mrf24j40_short_reg_precious(struct device *dev, unsigned int reg)
{
switch (reg) {
case REG_INTSTAT:
return true;
default:
return false;
}
}
static bool
mrf24j40_long_reg_writeable(struct device *dev, unsigned int reg)
{
switch (reg) {
case REG_RFCON0:
case REG_RFCON1:
case REG_RFCON2:
case REG_RFCON3:
case REG_RFCON5:
case REG_RFCON6:
case REG_RFCON7:
case REG_RFCON8:
case REG_SLPCAL2:
case REG_SLPCON0:
case REG_SLPCON1:
case REG_WAKETIMEL:
case REG_WAKETIMEH:
case REG_REMCNTL:
case REG_REMCNTH:
case REG_MAINCNT0:
case REG_MAINCNT1:
case REG_MAINCNT2:
case REG_MAINCNT3:
case REG_TESTMODE:
case REG_ASSOEAR0:
case REG_ASSOEAR1:
case REG_ASSOEAR2:
case REG_ASSOEAR3:
case REG_ASSOEAR4:
case REG_ASSOEAR5:
case REG_ASSOEAR6:
case REG_ASSOEAR7:
case REG_ASSOSAR0:
case REG_ASSOSAR1:
case REG_UNONCE0:
case REG_UNONCE1:
case REG_UNONCE2:
case REG_UNONCE3:
case REG_UNONCE4:
case REG_UNONCE5:
case REG_UNONCE6:
case REG_UNONCE7:
case REG_UNONCE8:
case REG_UNONCE9:
case REG_UNONCE10:
case REG_UNONCE11:
case REG_UNONCE12:
return true;
default:
return false;
}
}
static bool
mrf24j40_long_reg_readable(struct device *dev, unsigned int reg)
{
bool rc;
rc = mrf24j40_long_reg_writeable(dev, reg);
if (rc)
return rc;
switch (reg) {
case REG_SLPCAL0:
case REG_SLPCAL1:
case REG_RFSTATE:
case REG_RSSI:
return true;
default:
return false;
}
}
static bool
mrf24j40_long_reg_volatile(struct device *dev, unsigned int reg)
{
switch (reg) {
case REG_SLPCAL0:
case REG_SLPCAL1:
case REG_SLPCAL2:
case REG_RFSTATE:
case REG_RSSI:
case REG_MAINCNT3:
return true;
default:
return false;
}
}
static int mrf24j40_long_regmap_write(void *context, const void *data,
size_t count)
{
struct spi_device *spi = context;
u8 buf[3];
if (count > 3)
return -EINVAL;
memcpy(buf, data, count);
buf[1] |= (1 << 4);
return spi_write(spi, buf, count);
}
static int
mrf24j40_long_regmap_read(void *context, const void *reg, size_t reg_size,
void *val, size_t val_size)
{
struct spi_device *spi = context;
return spi_write_then_read(spi, reg, reg_size, val, val_size);
}
static void write_tx_buf_complete(void *context)
{
struct mrf24j40 *devrec = context;
__le16 fc = ieee802154_get_fc_from_skb(devrec->tx_skb);
u8 val = BIT_TXNTRIG;
int ret;
if (ieee802154_is_ackreq(fc))
val |= BIT_TXNACKREQ;
devrec->tx_post_msg.complete = NULL;
devrec->tx_post_buf[0] = MRF24J40_WRITESHORT(REG_TXNCON);
devrec->tx_post_buf[1] = val;
ret = spi_async(devrec->spi, &devrec->tx_post_msg);
if (ret)
dev_err(printdev(devrec), "SPI write Failed for transmit buf\n");
}
static int write_tx_buf(struct mrf24j40 *devrec, u16 reg,
const u8 *data, size_t length)
{
u16 cmd;
int ret;
if (length > TX_FIFO_SIZE-2) {
dev_err(printdev(devrec), "write_tx_buf() was passed too large a buffer. Performing short write.\n");
length = TX_FIFO_SIZE-2;
}
cmd = MRF24J40_WRITELONG(reg);
devrec->tx_hdr_buf[0] = cmd >> 8 & 0xff;
devrec->tx_hdr_buf[1] = cmd & 0xff;
devrec->tx_len_buf[0] = 0x0;
devrec->tx_len_buf[1] = length;
devrec->tx_buf_trx.tx_buf = data;
devrec->tx_buf_trx.len = length;
ret = spi_async(devrec->spi, &devrec->tx_msg);
if (ret)
dev_err(printdev(devrec), "SPI write Failed for TX buf\n");
return ret;
}
static int mrf24j40_tx(struct ieee802154_hw *hw, struct sk_buff *skb)
{
struct mrf24j40 *devrec = hw->priv;
dev_dbg(printdev(devrec), "tx packet of %d bytes\n", skb->len);
devrec->tx_skb = skb;
return write_tx_buf(devrec, 0x000, skb->data, skb->len);
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
dev_dbg(printdev(devrec), "start\n");
return regmap_update_bits(devrec->regmap_short, REG_INTCON,
BIT_TXNIE | BIT_RXIE, 0);
}
static void mrf24j40_stop(struct ieee802154_hw *hw)
{
struct mrf24j40 *devrec = hw->priv;
dev_dbg(printdev(devrec), "stop\n");
regmap_update_bits(devrec->regmap_short, REG_INTCON,
BIT_TXNIE | BIT_TXNIE, BIT_TXNIE | BIT_TXNIE);
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
val = (channel - 11) << RFCON0_CH_SHIFT | RFOPT_RECOMMEND;
ret = regmap_update_bits(devrec->regmap_long, REG_RFCON0,
RFCON0_CH_MASK, val);
if (ret)
return ret;
ret = regmap_update_bits(devrec->regmap_short, REG_RFCTL, BIT_RFRST,
BIT_RFRST);
if (ret)
return ret;
ret = regmap_update_bits(devrec->regmap_short, REG_RFCTL, BIT_RFRST, 0);
if (!ret)
udelay(SET_CHANNEL_DELAY_US);
return ret;
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
regmap_write(devrec->regmap_short, REG_SADRH, addrh);
regmap_write(devrec->regmap_short, REG_SADRL, addrl);
dev_dbg(printdev(devrec),
"Set short addr to %04hx\n", filt->short_addr);
}
if (changed & IEEE802154_AFILT_IEEEADDR_CHANGED) {
u8 i, addr[8];
memcpy(addr, &filt->ieee_addr, 8);
for (i = 0; i < 8; i++)
regmap_write(devrec->regmap_short, REG_EADR0 + i,
addr[i]);
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
regmap_write(devrec->regmap_short, REG_PANIDH, panidh);
regmap_write(devrec->regmap_short, REG_PANIDL, panidl);
dev_dbg(printdev(devrec), "Set PANID to %04hx\n", filt->pan_id);
}
if (changed & IEEE802154_AFILT_PANC_CHANGED) {
u8 val;
int ret;
if (filt->pan_coord)
val = BIT_PANCOORD;
else
val = 0;
ret = regmap_update_bits(devrec->regmap_short, REG_RXMCR,
BIT_PANCOORD, val);
if (ret)
return ret;
dev_dbg(printdev(devrec), "Set Pan Coord to %s\n",
filt->pan_coord ? "on" : "off");
}
return 0;
}
static void mrf24j40_handle_rx_read_buf_unlock(struct mrf24j40 *devrec)
{
int ret;
devrec->rx_msg.complete = NULL;
devrec->rx_buf[0] = MRF24J40_WRITESHORT(REG_BBREG1);
devrec->rx_buf[1] = 0x00;
ret = spi_async(devrec->spi, &devrec->rx_msg);
if (ret)
dev_err(printdev(devrec), "failed to unlock rx buffer\n");
}
static void mrf24j40_handle_rx_read_buf_complete(void *context)
{
struct mrf24j40 *devrec = context;
u8 len = devrec->rx_buf[2];
u8 rx_local_buf[RX_FIFO_SIZE];
struct sk_buff *skb;
memcpy(rx_local_buf, devrec->rx_fifo_buf, len);
mrf24j40_handle_rx_read_buf_unlock(devrec);
skb = dev_alloc_skb(IEEE802154_MTU);
if (!skb) {
dev_err(printdev(devrec), "failed to allocate skb\n");
return;
}
memcpy(skb_put(skb, len), rx_local_buf, len);
ieee802154_rx_irqsafe(devrec->hw, skb, 0);
#ifdef DEBUG
print_hex_dump(KERN_DEBUG, "mrf24j40 rx: ", DUMP_PREFIX_OFFSET, 16, 1,
rx_local_buf, len, 0);
pr_debug("mrf24j40 rx: lqi: %02hhx rssi: %02hhx\n",
devrec->rx_lqi_buf[0], devrec->rx_lqi_buf[1]);
#endif
}
static void mrf24j40_handle_rx_read_buf(void *context)
{
struct mrf24j40 *devrec = context;
u16 cmd;
int ret;
if (!ieee802154_is_valid_psdu_len(devrec->rx_buf[2]))
devrec->rx_buf[2] = IEEE802154_MTU;
cmd = MRF24J40_READLONG(REG_RX_FIFO + 1);
devrec->rx_addr_buf[0] = cmd >> 8 & 0xff;
devrec->rx_addr_buf[1] = cmd & 0xff;
devrec->rx_fifo_buf_trx.len = devrec->rx_buf[2];
ret = spi_async(devrec->spi, &devrec->rx_buf_msg);
if (ret) {
dev_err(printdev(devrec), "failed to read rx buffer\n");
mrf24j40_handle_rx_read_buf_unlock(devrec);
}
}
static void mrf24j40_handle_rx_read_len(void *context)
{
struct mrf24j40 *devrec = context;
u16 cmd;
int ret;
devrec->rx_msg.complete = mrf24j40_handle_rx_read_buf;
devrec->rx_trx.len = 3;
cmd = MRF24J40_READLONG(REG_RX_FIFO);
devrec->rx_buf[0] = cmd >> 8 & 0xff;
devrec->rx_buf[1] = cmd & 0xff;
ret = spi_async(devrec->spi, &devrec->rx_msg);
if (ret) {
dev_err(printdev(devrec), "failed to read rx buffer length\n");
mrf24j40_handle_rx_read_buf_unlock(devrec);
}
}
static int mrf24j40_handle_rx(struct mrf24j40 *devrec)
{
devrec->rx_msg.complete = mrf24j40_handle_rx_read_len;
devrec->rx_trx.len = 2;
devrec->rx_buf[0] = MRF24J40_WRITESHORT(REG_BBREG1);
devrec->rx_buf[1] = BIT_RXDECINV;
return spi_async(devrec->spi, &devrec->rx_msg);
}
static int
mrf24j40_csma_params(struct ieee802154_hw *hw, u8 min_be, u8 max_be,
u8 retries)
{
struct mrf24j40 *devrec = hw->priv;
u8 val;
val = min_be << TXMCR_MIN_BE_SHIFT;
val |= retries << TXMCR_CSMA_RETRIES_SHIFT;
return regmap_update_bits(devrec->regmap_short, REG_TXMCR,
TXMCR_MIN_BE_MASK | TXMCR_CSMA_RETRIES_MASK,
val);
}
static int mrf24j40_set_cca_mode(struct ieee802154_hw *hw,
const struct wpan_phy_cca *cca)
{
struct mrf24j40 *devrec = hw->priv;
u8 val;
switch (cca->mode) {
case NL802154_CCA_ENERGY:
val = 2;
break;
case NL802154_CCA_CARRIER:
val = 1;
break;
case NL802154_CCA_ENERGY_CARRIER:
switch (cca->opt) {
case NL802154_CCA_OPT_ENERGY_CARRIER_AND:
val = 3;
break;
default:
return -EINVAL;
}
break;
default:
return -EINVAL;
}
return regmap_update_bits(devrec->regmap_short, REG_BBREG2,
BBREG2_CCA_MODE_MASK,
val << BBREG2_CCA_MODE_SHIFT);
}
static int mrf24j40_set_cca_ed_level(struct ieee802154_hw *hw, s32 mbm)
{
struct mrf24j40 *devrec = hw->priv;
int i;
for (i = 0; i < ARRAY_SIZE(mrf24j40_ed_levels_map); i++) {
if (mrf24j40_ed_levels_map[i][0] == mbm)
return regmap_write(devrec->regmap_short, REG_CCAEDTH,
mrf24j40_ed_levels_map[i][1]);
}
return -EINVAL;
}
static int mrf24j40_set_txpower(struct ieee802154_hw *hw, s32 mbm)
{
struct mrf24j40 *devrec = hw->priv;
s32 small_scale;
u8 val;
if (0 >= mbm && mbm > -1000) {
val = TXPWRL_0 << TXPWRL_SHIFT;
small_scale = mbm;
} else if (-1000 >= mbm && mbm > -2000) {
val = TXPWRL_10 << TXPWRL_SHIFT;
small_scale = mbm + 1000;
} else if (-2000 >= mbm && mbm > -3000) {
val = TXPWRL_20 << TXPWRL_SHIFT;
small_scale = mbm + 2000;
} else if (-3000 >= mbm && mbm > -4000) {
val = TXPWRL_30 << TXPWRL_SHIFT;
small_scale = mbm + 3000;
} else {
return -EINVAL;
}
switch (small_scale) {
case 0:
val |= (TXPWRS_0 << TXPWRS_SHIFT);
break;
case -50:
val |= (TXPWRS_0_5 << TXPWRS_SHIFT);
break;
case -120:
val |= (TXPWRS_1_2 << TXPWRS_SHIFT);
break;
case -190:
val |= (TXPWRS_1_9 << TXPWRS_SHIFT);
break;
case -280:
val |= (TXPWRS_2_8 << TXPWRS_SHIFT);
break;
case -370:
val |= (TXPWRS_3_7 << TXPWRS_SHIFT);
break;
case -490:
val |= (TXPWRS_4_9 << TXPWRS_SHIFT);
break;
case -630:
val |= (TXPWRS_6_3 << TXPWRS_SHIFT);
break;
default:
return -EINVAL;
}
return regmap_update_bits(devrec->regmap_long, REG_RFCON3,
TXPWRL_MASK | TXPWRS_MASK, val);
}
static int mrf24j40_set_promiscuous_mode(struct ieee802154_hw *hw, bool on)
{
struct mrf24j40 *devrec = hw->priv;
int ret;
if (on) {
ret = regmap_update_bits(devrec->regmap_short, REG_RXMCR,
BIT_PROMI | BIT_ERRPKT | BIT_NOACKRSP,
BIT_PROMI | BIT_ERRPKT | BIT_NOACKRSP);
} else {
ret = regmap_update_bits(devrec->regmap_short, REG_RXMCR,
BIT_PROMI | BIT_ERRPKT | BIT_NOACKRSP,
0);
}
return ret;
}
static void mrf24j40_intstat_complete(void *context)
{
struct mrf24j40 *devrec = context;
u8 intstat = devrec->irq_buf[1];
enable_irq(devrec->spi->irq);
if (intstat & BIT_TXNIF)
ieee802154_xmit_complete(devrec->hw, devrec->tx_skb, false);
if (intstat & BIT_RXIF)
mrf24j40_handle_rx(devrec);
}
static irqreturn_t mrf24j40_isr(int irq, void *data)
{
struct mrf24j40 *devrec = data;
int ret;
disable_irq_nosync(irq);
devrec->irq_buf[0] = MRF24J40_READSHORT(REG_INTSTAT);
ret = spi_async(devrec->spi, &devrec->irq_msg);
if (ret) {
enable_irq(irq);
return IRQ_NONE;
}
return IRQ_HANDLED;
}
static int mrf24j40_hw_init(struct mrf24j40 *devrec)
{
u32 irq_type;
int ret;
ret = regmap_write(devrec->regmap_short, REG_SOFTRST, 0x07);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_short, REG_PACON2, 0x98);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_short, REG_TXSTBL, 0x95);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_long, REG_RFCON0, 0x03);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_long, REG_RFCON1, 0x01);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_long, REG_RFCON2, 0x80);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_long, REG_RFCON6, 0x90);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_long, REG_RFCON7, 0x80);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_long, REG_RFCON8, 0x10);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_long, REG_SLPCON1, 0x21);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_short, REG_BBREG2, 0x80);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_short, REG_CCAEDTH, 0x60);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_short, REG_BBREG6, 0x40);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_short, REG_RFCTL, 0x04);
if (ret)
goto err_ret;
ret = regmap_write(devrec->regmap_short, REG_RFCTL, 0x0);
if (ret)
goto err_ret;
udelay(192);
ret = regmap_update_bits(devrec->regmap_short, REG_RXMCR, 0x03, 0x00);
if (ret)
goto err_ret;
if (spi_get_device_id(devrec->spi)->driver_data == MRF24J40MC) {
regmap_update_bits(devrec->regmap_long, REG_TESTMODE, 0x07,
0x07);
regmap_update_bits(devrec->regmap_short, REG_TRISGPIO, 0x08,
0x08);
regmap_update_bits(devrec->regmap_short, REG_GPIO, 0x08, 0x08);
regmap_write(devrec->regmap_long, REG_RFCON3, 0x28);
}
irq_type = irq_get_trigger_type(devrec->spi->irq);
if (irq_type == IRQ_TYPE_EDGE_RISING ||
irq_type == IRQ_TYPE_EDGE_FALLING)
dev_warn(&devrec->spi->dev,
"Using edge triggered irq's are not recommended, because it can cause races and result in a non-functional driver!\n");
switch (irq_type) {
case IRQ_TYPE_EDGE_RISING:
case IRQ_TYPE_LEVEL_HIGH:
ret = regmap_update_bits(devrec->regmap_long, REG_SLPCON0,
BIT_INTEDGE, BIT_INTEDGE);
if (ret)
goto err_ret;
break;
default:
break;
}
return 0;
err_ret:
return ret;
}
static void
mrf24j40_setup_tx_spi_messages(struct mrf24j40 *devrec)
{
spi_message_init(&devrec->tx_msg);
devrec->tx_msg.context = devrec;
devrec->tx_msg.complete = write_tx_buf_complete;
devrec->tx_hdr_trx.len = 2;
devrec->tx_hdr_trx.tx_buf = devrec->tx_hdr_buf;
spi_message_add_tail(&devrec->tx_hdr_trx, &devrec->tx_msg);
devrec->tx_len_trx.len = 2;
devrec->tx_len_trx.tx_buf = devrec->tx_len_buf;
spi_message_add_tail(&devrec->tx_len_trx, &devrec->tx_msg);
spi_message_add_tail(&devrec->tx_buf_trx, &devrec->tx_msg);
spi_message_init(&devrec->tx_post_msg);
devrec->tx_post_msg.context = devrec;
devrec->tx_post_trx.len = 2;
devrec->tx_post_trx.tx_buf = devrec->tx_post_buf;
spi_message_add_tail(&devrec->tx_post_trx, &devrec->tx_post_msg);
}
static void
mrf24j40_setup_rx_spi_messages(struct mrf24j40 *devrec)
{
spi_message_init(&devrec->rx_msg);
devrec->rx_msg.context = devrec;
devrec->rx_trx.len = 2;
devrec->rx_trx.tx_buf = devrec->rx_buf;
devrec->rx_trx.rx_buf = devrec->rx_buf;
spi_message_add_tail(&devrec->rx_trx, &devrec->rx_msg);
spi_message_init(&devrec->rx_buf_msg);
devrec->rx_buf_msg.context = devrec;
devrec->rx_buf_msg.complete = mrf24j40_handle_rx_read_buf_complete;
devrec->rx_addr_trx.len = 2;
devrec->rx_addr_trx.tx_buf = devrec->rx_addr_buf;
spi_message_add_tail(&devrec->rx_addr_trx, &devrec->rx_buf_msg);
devrec->rx_fifo_buf_trx.rx_buf = devrec->rx_fifo_buf;
spi_message_add_tail(&devrec->rx_fifo_buf_trx, &devrec->rx_buf_msg);
devrec->rx_lqi_trx.len = 2;
devrec->rx_lqi_trx.rx_buf = devrec->rx_lqi_buf;
spi_message_add_tail(&devrec->rx_lqi_trx, &devrec->rx_buf_msg);
}
static void
mrf24j40_setup_irq_spi_messages(struct mrf24j40 *devrec)
{
spi_message_init(&devrec->irq_msg);
devrec->irq_msg.context = devrec;
devrec->irq_msg.complete = mrf24j40_intstat_complete;
devrec->irq_trx.len = 2;
devrec->irq_trx.tx_buf = devrec->irq_buf;
devrec->irq_trx.rx_buf = devrec->irq_buf;
spi_message_add_tail(&devrec->irq_trx, &devrec->irq_msg);
}
static void mrf24j40_phy_setup(struct mrf24j40 *devrec)
{
ieee802154_random_extended_addr(&devrec->hw->phy->perm_extended_addr);
devrec->hw->phy->current_channel = 11;
devrec->hw->phy->supported.max_minbe = 3;
devrec->hw->phy->supported.min_maxbe = 5;
devrec->hw->phy->supported.max_maxbe = 5;
devrec->hw->phy->cca.mode = NL802154_CCA_CARRIER;
devrec->hw->phy->supported.cca_modes = BIT(NL802154_CCA_ENERGY) |
BIT(NL802154_CCA_CARRIER) |
BIT(NL802154_CCA_ENERGY_CARRIER);
devrec->hw->phy->supported.cca_opts = BIT(NL802154_CCA_OPT_ENERGY_CARRIER_AND);
devrec->hw->phy->cca_ed_level = -6900;
devrec->hw->phy->supported.cca_ed_levels = mrf24j40_ed_levels;
devrec->hw->phy->supported.cca_ed_levels_size = ARRAY_SIZE(mrf24j40_ed_levels);
switch (spi_get_device_id(devrec->spi)->driver_data) {
case MRF24J40:
case MRF24J40MA:
devrec->hw->phy->supported.tx_powers = mrf24j40ma_powers;
devrec->hw->phy->supported.tx_powers_size = ARRAY_SIZE(mrf24j40ma_powers);
devrec->hw->phy->flags |= WPAN_PHY_FLAG_TXPOWER;
break;
default:
break;
}
}
static int mrf24j40_probe(struct spi_device *spi)
{
int ret = -ENOMEM, irq_type;
struct ieee802154_hw *hw;
struct mrf24j40 *devrec;
dev_info(&spi->dev, "probe(). IRQ: %d\n", spi->irq);
hw = ieee802154_alloc_hw(sizeof(*devrec), &mrf24j40_ops);
if (!hw)
goto err_ret;
devrec = hw->priv;
devrec->spi = spi;
spi_set_drvdata(spi, devrec);
devrec->hw = hw;
devrec->hw->parent = &spi->dev;
devrec->hw->phy->supported.channels[0] = CHANNEL_MASK;
devrec->hw->flags = IEEE802154_HW_TX_OMIT_CKSUM | IEEE802154_HW_AFILT |
IEEE802154_HW_CSMA_PARAMS |
IEEE802154_HW_PROMISCUOUS;
devrec->hw->phy->flags = WPAN_PHY_FLAG_CCA_MODE |
WPAN_PHY_FLAG_CCA_ED_LEVEL;
mrf24j40_setup_tx_spi_messages(devrec);
mrf24j40_setup_rx_spi_messages(devrec);
mrf24j40_setup_irq_spi_messages(devrec);
devrec->regmap_short = devm_regmap_init_spi(spi,
&mrf24j40_short_regmap);
if (IS_ERR(devrec->regmap_short)) {
ret = PTR_ERR(devrec->regmap_short);
dev_err(&spi->dev, "Failed to allocate short register map: %d\n",
ret);
goto err_register_device;
}
devrec->regmap_long = devm_regmap_init(&spi->dev,
&mrf24j40_long_regmap_bus,
spi, &mrf24j40_long_regmap);
if (IS_ERR(devrec->regmap_long)) {
ret = PTR_ERR(devrec->regmap_long);
dev_err(&spi->dev, "Failed to allocate long register map: %d\n",
ret);
goto err_register_device;
}
if (spi->max_speed_hz > MAX_SPI_SPEED_HZ) {
dev_warn(&spi->dev, "spi clock above possible maximum: %d",
MAX_SPI_SPEED_HZ);
return -EINVAL;
}
ret = mrf24j40_hw_init(devrec);
if (ret)
goto err_register_device;
mrf24j40_phy_setup(devrec);
irq_type = irq_get_trigger_type(spi->irq);
if (!irq_type)
irq_type = IRQF_TRIGGER_LOW;
ret = devm_request_irq(&spi->dev, spi->irq, mrf24j40_isr,
irq_type, dev_name(&spi->dev), devrec);
if (ret) {
dev_err(printdev(devrec), "Unable to get IRQ");
goto err_register_device;
}
dev_dbg(printdev(devrec), "registered mrf24j40\n");
ret = ieee802154_register_hw(devrec->hw);
if (ret)
goto err_register_device;
return 0;
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
