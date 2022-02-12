u8 rtl8xxxu_read8(struct rtl8xxxu_priv *priv, u16 addr)
{
struct usb_device *udev = priv->udev;
int len;
u8 data;
mutex_lock(&priv->usb_buf_mutex);
len = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
REALTEK_USB_CMD_REQ, REALTEK_USB_READ,
addr, 0, &priv->usb_buf.val8, sizeof(u8),
RTW_USB_CONTROL_MSG_TIMEOUT);
data = priv->usb_buf.val8;
mutex_unlock(&priv->usb_buf_mutex);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_REG_READ)
dev_info(&udev->dev, "%s(%04x) = 0x%02x, len %i\n",
__func__, addr, data, len);
return data;
}
u16 rtl8xxxu_read16(struct rtl8xxxu_priv *priv, u16 addr)
{
struct usb_device *udev = priv->udev;
int len;
u16 data;
mutex_lock(&priv->usb_buf_mutex);
len = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
REALTEK_USB_CMD_REQ, REALTEK_USB_READ,
addr, 0, &priv->usb_buf.val16, sizeof(u16),
RTW_USB_CONTROL_MSG_TIMEOUT);
data = le16_to_cpu(priv->usb_buf.val16);
mutex_unlock(&priv->usb_buf_mutex);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_REG_READ)
dev_info(&udev->dev, "%s(%04x) = 0x%04x, len %i\n",
__func__, addr, data, len);
return data;
}
u32 rtl8xxxu_read32(struct rtl8xxxu_priv *priv, u16 addr)
{
struct usb_device *udev = priv->udev;
int len;
u32 data;
mutex_lock(&priv->usb_buf_mutex);
len = usb_control_msg(udev, usb_rcvctrlpipe(udev, 0),
REALTEK_USB_CMD_REQ, REALTEK_USB_READ,
addr, 0, &priv->usb_buf.val32, sizeof(u32),
RTW_USB_CONTROL_MSG_TIMEOUT);
data = le32_to_cpu(priv->usb_buf.val32);
mutex_unlock(&priv->usb_buf_mutex);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_REG_READ)
dev_info(&udev->dev, "%s(%04x) = 0x%08x, len %i\n",
__func__, addr, data, len);
return data;
}
int rtl8xxxu_write8(struct rtl8xxxu_priv *priv, u16 addr, u8 val)
{
struct usb_device *udev = priv->udev;
int ret;
mutex_lock(&priv->usb_buf_mutex);
priv->usb_buf.val8 = val;
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
REALTEK_USB_CMD_REQ, REALTEK_USB_WRITE,
addr, 0, &priv->usb_buf.val8, sizeof(u8),
RTW_USB_CONTROL_MSG_TIMEOUT);
mutex_unlock(&priv->usb_buf_mutex);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_REG_WRITE)
dev_info(&udev->dev, "%s(%04x) = 0x%02x\n",
__func__, addr, val);
return ret;
}
int rtl8xxxu_write16(struct rtl8xxxu_priv *priv, u16 addr, u16 val)
{
struct usb_device *udev = priv->udev;
int ret;
mutex_lock(&priv->usb_buf_mutex);
priv->usb_buf.val16 = cpu_to_le16(val);
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
REALTEK_USB_CMD_REQ, REALTEK_USB_WRITE,
addr, 0, &priv->usb_buf.val16, sizeof(u16),
RTW_USB_CONTROL_MSG_TIMEOUT);
mutex_unlock(&priv->usb_buf_mutex);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_REG_WRITE)
dev_info(&udev->dev, "%s(%04x) = 0x%04x\n",
__func__, addr, val);
return ret;
}
int rtl8xxxu_write32(struct rtl8xxxu_priv *priv, u16 addr, u32 val)
{
struct usb_device *udev = priv->udev;
int ret;
mutex_lock(&priv->usb_buf_mutex);
priv->usb_buf.val32 = cpu_to_le32(val);
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
REALTEK_USB_CMD_REQ, REALTEK_USB_WRITE,
addr, 0, &priv->usb_buf.val32, sizeof(u32),
RTW_USB_CONTROL_MSG_TIMEOUT);
mutex_unlock(&priv->usb_buf_mutex);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_REG_WRITE)
dev_info(&udev->dev, "%s(%04x) = 0x%08x\n",
__func__, addr, val);
return ret;
}
static int
rtl8xxxu_writeN(struct rtl8xxxu_priv *priv, u16 addr, u8 *buf, u16 len)
{
struct usb_device *udev = priv->udev;
int blocksize = priv->fops->writeN_block_size;
int ret, i, count, remainder;
count = len / blocksize;
remainder = len % blocksize;
for (i = 0; i < count; i++) {
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
REALTEK_USB_CMD_REQ, REALTEK_USB_WRITE,
addr, 0, buf, blocksize,
RTW_USB_CONTROL_MSG_TIMEOUT);
if (ret != blocksize)
goto write_error;
addr += blocksize;
buf += blocksize;
}
if (remainder) {
ret = usb_control_msg(udev, usb_sndctrlpipe(udev, 0),
REALTEK_USB_CMD_REQ, REALTEK_USB_WRITE,
addr, 0, buf, remainder,
RTW_USB_CONTROL_MSG_TIMEOUT);
if (ret != remainder)
goto write_error;
}
return len;
write_error:
dev_info(&udev->dev,
"%s: Failed to write block at addr: %04x size: %04x\n",
__func__, addr, blocksize);
return -EAGAIN;
}
u32 rtl8xxxu_read_rfreg(struct rtl8xxxu_priv *priv,
enum rtl8xxxu_rfpath path, u8 reg)
{
u32 hssia, val32, retval;
hssia = rtl8xxxu_read32(priv, REG_FPGA0_XA_HSSI_PARM2);
if (path != RF_A)
val32 = rtl8xxxu_read32(priv, rtl8xxxu_rfregs[path].hssiparm2);
else
val32 = hssia;
val32 &= ~FPGA0_HSSI_PARM2_ADDR_MASK;
val32 |= (reg << FPGA0_HSSI_PARM2_ADDR_SHIFT);
val32 |= FPGA0_HSSI_PARM2_EDGE_READ;
hssia &= ~FPGA0_HSSI_PARM2_EDGE_READ;
rtl8xxxu_write32(priv, REG_FPGA0_XA_HSSI_PARM2, hssia);
udelay(10);
rtl8xxxu_write32(priv, rtl8xxxu_rfregs[path].hssiparm2, val32);
udelay(100);
hssia |= FPGA0_HSSI_PARM2_EDGE_READ;
rtl8xxxu_write32(priv, REG_FPGA0_XA_HSSI_PARM2, hssia);
udelay(10);
val32 = rtl8xxxu_read32(priv, rtl8xxxu_rfregs[path].hssiparm1);
if (val32 & FPGA0_HSSI_PARM1_PI)
retval = rtl8xxxu_read32(priv, rtl8xxxu_rfregs[path].hspiread);
else
retval = rtl8xxxu_read32(priv, rtl8xxxu_rfregs[path].lssiread);
retval &= 0xfffff;
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_RFREG_READ)
dev_info(&priv->udev->dev, "%s(%02x) = 0x%06x\n",
__func__, reg, retval);
return retval;
}
int rtl8xxxu_write_rfreg(struct rtl8xxxu_priv *priv,
enum rtl8xxxu_rfpath path, u8 reg, u32 data)
{
int ret, retval;
u32 dataaddr, val32;
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_RFREG_WRITE)
dev_info(&priv->udev->dev, "%s(%02x) = 0x%06x\n",
__func__, reg, data);
data &= FPGA0_LSSI_PARM_DATA_MASK;
dataaddr = (reg << FPGA0_LSSI_PARM_ADDR_SHIFT) | data;
if (priv->rtl_chip == RTL8192E) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_POWER_SAVE);
val32 &= ~0x20000;
rtl8xxxu_write32(priv, REG_FPGA0_POWER_SAVE, val32);
}
ret = rtl8xxxu_write32(priv, rtl8xxxu_rfregs[path].lssiparm, dataaddr);
if (ret != sizeof(dataaddr))
retval = -EIO;
else
retval = 0;
udelay(1);
if (priv->rtl_chip == RTL8192E) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_POWER_SAVE);
val32 |= 0x20000;
rtl8xxxu_write32(priv, REG_FPGA0_POWER_SAVE, val32);
}
return retval;
}
static int
rtl8xxxu_gen1_h2c_cmd(struct rtl8xxxu_priv *priv, struct h2c_cmd *h2c, int len)
{
struct device *dev = &priv->udev->dev;
int mbox_nr, retry, retval = 0;
int mbox_reg, mbox_ext_reg;
u8 val8;
mutex_lock(&priv->h2c_mutex);
mbox_nr = priv->next_mbox;
mbox_reg = REG_HMBOX_0 + (mbox_nr * 4);
mbox_ext_reg = REG_HMBOX_EXT_0 + (mbox_nr * 2);
retry = 100;
do {
val8 = rtl8xxxu_read8(priv, REG_HMTFR);
if (!(val8 & BIT(mbox_nr)))
break;
} while (retry--);
if (!retry) {
dev_info(dev, "%s: Mailbox busy\n", __func__);
retval = -EBUSY;
goto error;
}
if (len > sizeof(u32)) {
rtl8xxxu_write16(priv, mbox_ext_reg, le16_to_cpu(h2c->raw.ext));
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_H2C)
dev_info(dev, "H2C_EXT %04x\n",
le16_to_cpu(h2c->raw.ext));
}
rtl8xxxu_write32(priv, mbox_reg, le32_to_cpu(h2c->raw.data));
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_H2C)
dev_info(dev, "H2C %08x\n", le32_to_cpu(h2c->raw.data));
priv->next_mbox = (mbox_nr + 1) % H2C_MAX_MBOX;
error:
mutex_unlock(&priv->h2c_mutex);
return retval;
}
int
rtl8xxxu_gen2_h2c_cmd(struct rtl8xxxu_priv *priv, struct h2c_cmd *h2c, int len)
{
struct device *dev = &priv->udev->dev;
int mbox_nr, retry, retval = 0;
int mbox_reg, mbox_ext_reg;
u8 val8;
mutex_lock(&priv->h2c_mutex);
mbox_nr = priv->next_mbox;
mbox_reg = REG_HMBOX_0 + (mbox_nr * 4);
mbox_ext_reg = REG_HMBOX_EXT0_8723B + (mbox_nr * 4);
retry = 100;
do {
val8 = rtl8xxxu_read8(priv, REG_HMTFR);
if (!(val8 & BIT(mbox_nr)))
break;
} while (retry--);
if (!retry) {
dev_info(dev, "%s: Mailbox busy\n", __func__);
retval = -EBUSY;
goto error;
}
if (len > sizeof(u32)) {
rtl8xxxu_write32(priv, mbox_ext_reg,
le32_to_cpu(h2c->raw_wide.ext));
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_H2C)
dev_info(dev, "H2C_EXT %08x\n",
le32_to_cpu(h2c->raw_wide.ext));
}
rtl8xxxu_write32(priv, mbox_reg, le32_to_cpu(h2c->raw.data));
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_H2C)
dev_info(dev, "H2C %08x\n", le32_to_cpu(h2c->raw.data));
priv->next_mbox = (mbox_nr + 1) % H2C_MAX_MBOX;
error:
mutex_unlock(&priv->h2c_mutex);
return retval;
}
void rtl8xxxu_gen1_enable_rf(struct rtl8xxxu_priv *priv)
{
u8 val8;
u32 val32;
val8 = rtl8xxxu_read8(priv, REG_SPS0_CTRL);
val8 |= BIT(0) | BIT(3);
rtl8xxxu_write8(priv, REG_SPS0_CTRL, val8);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XAB_RF_PARM);
val32 &= ~(BIT(4) | BIT(5));
val32 |= BIT(3);
if (priv->rf_paths == 2) {
val32 &= ~(BIT(20) | BIT(21));
val32 |= BIT(19);
}
rtl8xxxu_write32(priv, REG_FPGA0_XAB_RF_PARM, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_TRX_PATH_ENABLE);
val32 &= ~OFDM_RF_PATH_TX_MASK;
if (priv->tx_paths == 2)
val32 |= OFDM_RF_PATH_TX_A | OFDM_RF_PATH_TX_B;
else if (priv->rtl_chip == RTL8192C || priv->rtl_chip == RTL8191C)
val32 |= OFDM_RF_PATH_TX_B;
else
val32 |= OFDM_RF_PATH_TX_A;
rtl8xxxu_write32(priv, REG_OFDM0_TRX_PATH_ENABLE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
val32 &= ~FPGA_RF_MODE_JAPAN;
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
if (priv->rf_paths == 2)
rtl8xxxu_write32(priv, REG_RX_WAIT_CCA, 0x63db25a0);
else
rtl8xxxu_write32(priv, REG_RX_WAIT_CCA, 0x631b25a0);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_AC, 0x32d95);
if (priv->rf_paths == 2)
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_AC, 0x32d95);
rtl8xxxu_write8(priv, REG_TXPAUSE, 0x00);
}
void rtl8xxxu_gen1_disable_rf(struct rtl8xxxu_priv *priv)
{
u8 sps0;
u32 val32;
sps0 = rtl8xxxu_read8(priv, REG_SPS0_CTRL);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XAB_RF_PARM);
val32 &= ~(BIT(3) | BIT(4) | BIT(5));
if (priv->rf_paths == 2)
val32 &= ~(BIT(19) | BIT(20) | BIT(21));
rtl8xxxu_write32(priv, REG_FPGA0_XAB_RF_PARM, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_TRX_PATH_ENABLE);
val32 &= ~OFDM_RF_PATH_TX_MASK;
rtl8xxxu_write32(priv, REG_OFDM0_TRX_PATH_ENABLE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
val32 |= FPGA_RF_MODE_JAPAN;
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
if (priv->rf_paths == 2)
rtl8xxxu_write32(priv, REG_RX_WAIT_CCA, 0x00db25a0);
else
rtl8xxxu_write32(priv, REG_RX_WAIT_CCA, 0x001b25a0);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_AC, 0);
if (priv->rf_paths == 2)
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_AC, 0);
sps0 &= ~(BIT(0) | BIT(3));
rtl8xxxu_write8(priv, REG_SPS0_CTRL, sps0);
}
static void rtl8xxxu_stop_tx_beacon(struct rtl8xxxu_priv *priv)
{
u8 val8;
val8 = rtl8xxxu_read8(priv, REG_FWHW_TXQ_CTRL + 2);
val8 &= ~BIT(6);
rtl8xxxu_write8(priv, REG_FWHW_TXQ_CTRL + 2, val8);
rtl8xxxu_write8(priv, REG_TBTT_PROHIBIT + 1, 0x64);
val8 = rtl8xxxu_read8(priv, REG_TBTT_PROHIBIT + 2);
val8 &= ~BIT(0);
rtl8xxxu_write8(priv, REG_TBTT_PROHIBIT + 2, val8);
}
static int rtl8xxxu_gen1_channel_to_group(int channel)
{
int group;
if (channel < 4)
group = 0;
else if (channel < 10)
group = 1;
else
group = 2;
return group;
}
int rtl8xxxu_gen2_channel_to_group(int channel)
{
int group;
if (channel < 3)
group = 0;
else if (channel < 6)
group = 1;
else if (channel < 9)
group = 2;
else if (channel < 12)
group = 3;
else
group = 4;
return group;
}
void rtl8xxxu_gen1_config_channel(struct ieee80211_hw *hw)
{
struct rtl8xxxu_priv *priv = hw->priv;
u32 val32, rsr;
u8 val8, opmode;
bool ht = true;
int sec_ch_above, channel;
int i;
opmode = rtl8xxxu_read8(priv, REG_BW_OPMODE);
rsr = rtl8xxxu_read32(priv, REG_RESPONSE_RATE_SET);
channel = hw->conf.chandef.chan->hw_value;
switch (hw->conf.chandef.width) {
case NL80211_CHAN_WIDTH_20_NOHT:
ht = false;
case NL80211_CHAN_WIDTH_20:
opmode |= BW_OPMODE_20MHZ;
rtl8xxxu_write8(priv, REG_BW_OPMODE, opmode);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
val32 &= ~FPGA_RF_MODE;
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA1_RF_MODE);
val32 &= ~FPGA_RF_MODE;
rtl8xxxu_write32(priv, REG_FPGA1_RF_MODE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_ANALOG2);
val32 |= FPGA0_ANALOG2_20MHZ;
rtl8xxxu_write32(priv, REG_FPGA0_ANALOG2, val32);
break;
case NL80211_CHAN_WIDTH_40:
if (hw->conf.chandef.center_freq1 >
hw->conf.chandef.chan->center_freq) {
sec_ch_above = 1;
channel += 2;
} else {
sec_ch_above = 0;
channel -= 2;
}
opmode &= ~BW_OPMODE_20MHZ;
rtl8xxxu_write8(priv, REG_BW_OPMODE, opmode);
rsr &= ~RSR_RSC_BANDWIDTH_40M;
if (sec_ch_above)
rsr |= RSR_RSC_UPPER_SUB_CHANNEL;
else
rsr |= RSR_RSC_LOWER_SUB_CHANNEL;
rtl8xxxu_write32(priv, REG_RESPONSE_RATE_SET, rsr);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
val32 |= FPGA_RF_MODE;
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA1_RF_MODE);
val32 |= FPGA_RF_MODE;
rtl8xxxu_write32(priv, REG_FPGA1_RF_MODE, val32);
val32 = rtl8xxxu_read32(priv, REG_CCK0_SYSTEM);
val32 &= ~CCK0_SIDEBAND;
if (!sec_ch_above)
val32 |= CCK0_SIDEBAND;
rtl8xxxu_write32(priv, REG_CCK0_SYSTEM, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM1_LSTF);
val32 &= ~OFDM_LSTF_PRIME_CH_MASK;
if (sec_ch_above)
val32 |= OFDM_LSTF_PRIME_CH_LOW;
else
val32 |= OFDM_LSTF_PRIME_CH_HIGH;
rtl8xxxu_write32(priv, REG_OFDM1_LSTF, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_ANALOG2);
val32 &= ~FPGA0_ANALOG2_20MHZ;
rtl8xxxu_write32(priv, REG_FPGA0_ANALOG2, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_POWER_SAVE);
val32 &= ~(FPGA0_PS_LOWER_CHANNEL | FPGA0_PS_UPPER_CHANNEL);
if (sec_ch_above)
val32 |= FPGA0_PS_UPPER_CHANNEL;
else
val32 |= FPGA0_PS_LOWER_CHANNEL;
rtl8xxxu_write32(priv, REG_FPGA0_POWER_SAVE, val32);
break;
default:
break;
}
for (i = RF_A; i < priv->rf_paths; i++) {
val32 = rtl8xxxu_read_rfreg(priv, i, RF6052_REG_MODE_AG);
val32 &= ~MODE_AG_CHANNEL_MASK;
val32 |= channel;
rtl8xxxu_write_rfreg(priv, i, RF6052_REG_MODE_AG, val32);
}
if (ht)
val8 = 0x0e;
else
val8 = 0x0a;
rtl8xxxu_write8(priv, REG_SIFS_CCK + 1, val8);
rtl8xxxu_write8(priv, REG_SIFS_OFDM + 1, val8);
rtl8xxxu_write16(priv, REG_R2T_SIFS, 0x0808);
rtl8xxxu_write16(priv, REG_T2T_SIFS, 0x0a0a);
for (i = RF_A; i < priv->rf_paths; i++) {
val32 = rtl8xxxu_read_rfreg(priv, i, RF6052_REG_MODE_AG);
if (hw->conf.chandef.width == NL80211_CHAN_WIDTH_40)
val32 &= ~MODE_AG_CHANNEL_20MHZ;
else
val32 |= MODE_AG_CHANNEL_20MHZ;
rtl8xxxu_write_rfreg(priv, i, RF6052_REG_MODE_AG, val32);
}
}
void rtl8xxxu_gen2_config_channel(struct ieee80211_hw *hw)
{
struct rtl8xxxu_priv *priv = hw->priv;
u32 val32, rsr;
u8 val8, subchannel;
u16 rf_mode_bw;
bool ht = true;
int sec_ch_above, channel;
int i;
rf_mode_bw = rtl8xxxu_read16(priv, REG_WMAC_TRXPTCL_CTL);
rf_mode_bw &= ~WMAC_TRXPTCL_CTL_BW_MASK;
rsr = rtl8xxxu_read32(priv, REG_RESPONSE_RATE_SET);
channel = hw->conf.chandef.chan->hw_value;
subchannel = 0;
switch (hw->conf.chandef.width) {
case NL80211_CHAN_WIDTH_20_NOHT:
ht = false;
case NL80211_CHAN_WIDTH_20:
rf_mode_bw |= WMAC_TRXPTCL_CTL_BW_20;
subchannel = 0;
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
val32 &= ~FPGA_RF_MODE;
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA1_RF_MODE);
val32 &= ~FPGA_RF_MODE;
rtl8xxxu_write32(priv, REG_FPGA1_RF_MODE, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_TX_PSDO_NOISE_WEIGHT);
val32 &= ~(BIT(30) | BIT(31));
rtl8xxxu_write32(priv, REG_OFDM0_TX_PSDO_NOISE_WEIGHT, val32);
break;
case NL80211_CHAN_WIDTH_40:
rf_mode_bw |= WMAC_TRXPTCL_CTL_BW_40;
if (hw->conf.chandef.center_freq1 >
hw->conf.chandef.chan->center_freq) {
sec_ch_above = 1;
channel += 2;
} else {
sec_ch_above = 0;
channel -= 2;
}
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
val32 |= FPGA_RF_MODE;
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA1_RF_MODE);
val32 |= FPGA_RF_MODE;
rtl8xxxu_write32(priv, REG_FPGA1_RF_MODE, val32);
val32 = rtl8xxxu_read32(priv, REG_CCK0_SYSTEM);
val32 &= ~CCK0_SIDEBAND;
if (!sec_ch_above)
val32 |= CCK0_SIDEBAND;
rtl8xxxu_write32(priv, REG_CCK0_SYSTEM, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM1_LSTF);
val32 &= ~OFDM_LSTF_PRIME_CH_MASK;
if (sec_ch_above)
val32 |= OFDM_LSTF_PRIME_CH_LOW;
else
val32 |= OFDM_LSTF_PRIME_CH_HIGH;
rtl8xxxu_write32(priv, REG_OFDM1_LSTF, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_POWER_SAVE);
val32 &= ~(FPGA0_PS_LOWER_CHANNEL | FPGA0_PS_UPPER_CHANNEL);
if (sec_ch_above)
val32 |= FPGA0_PS_UPPER_CHANNEL;
else
val32 |= FPGA0_PS_LOWER_CHANNEL;
rtl8xxxu_write32(priv, REG_FPGA0_POWER_SAVE, val32);
break;
case NL80211_CHAN_WIDTH_80:
rf_mode_bw |= WMAC_TRXPTCL_CTL_BW_80;
break;
default:
break;
}
for (i = RF_A; i < priv->rf_paths; i++) {
val32 = rtl8xxxu_read_rfreg(priv, i, RF6052_REG_MODE_AG);
val32 &= ~MODE_AG_CHANNEL_MASK;
val32 |= channel;
rtl8xxxu_write_rfreg(priv, i, RF6052_REG_MODE_AG, val32);
}
rtl8xxxu_write16(priv, REG_WMAC_TRXPTCL_CTL, rf_mode_bw);
rtl8xxxu_write8(priv, REG_DATA_SUBCHANNEL, subchannel);
if (ht)
val8 = 0x0e;
else
val8 = 0x0a;
rtl8xxxu_write8(priv, REG_SIFS_CCK + 1, val8);
rtl8xxxu_write8(priv, REG_SIFS_OFDM + 1, val8);
rtl8xxxu_write16(priv, REG_R2T_SIFS, 0x0808);
rtl8xxxu_write16(priv, REG_T2T_SIFS, 0x0a0a);
for (i = RF_A; i < priv->rf_paths; i++) {
val32 = rtl8xxxu_read_rfreg(priv, i, RF6052_REG_MODE_AG);
val32 &= ~MODE_AG_BW_MASK;
switch(hw->conf.chandef.width) {
case NL80211_CHAN_WIDTH_80:
val32 |= MODE_AG_BW_80MHZ_8723B;
break;
case NL80211_CHAN_WIDTH_40:
val32 |= MODE_AG_BW_40MHZ_8723B;
break;
default:
val32 |= MODE_AG_BW_20MHZ_8723B;
break;
}
rtl8xxxu_write_rfreg(priv, i, RF6052_REG_MODE_AG, val32);
}
}
void
rtl8xxxu_gen1_set_tx_power(struct rtl8xxxu_priv *priv, int channel, bool ht40)
{
struct rtl8xxxu_power_base *power_base = priv->power_base;
u8 cck[RTL8723A_MAX_RF_PATHS], ofdm[RTL8723A_MAX_RF_PATHS];
u8 ofdmbase[RTL8723A_MAX_RF_PATHS], mcsbase[RTL8723A_MAX_RF_PATHS];
u32 val32, ofdm_a, ofdm_b, mcs_a, mcs_b;
u8 val8;
int group, i;
group = rtl8xxxu_gen1_channel_to_group(channel);
cck[0] = priv->cck_tx_power_index_A[group] - 1;
cck[1] = priv->cck_tx_power_index_B[group] - 1;
if (priv->hi_pa) {
if (cck[0] > 0x20)
cck[0] = 0x20;
if (cck[1] > 0x20)
cck[1] = 0x20;
}
ofdm[0] = priv->ht40_1s_tx_power_index_A[group];
ofdm[1] = priv->ht40_1s_tx_power_index_B[group];
if (ofdm[0])
ofdm[0] -= 1;
if (ofdm[1])
ofdm[1] -= 1;
ofdmbase[0] = ofdm[0] + priv->ofdm_tx_power_index_diff[group].a;
ofdmbase[1] = ofdm[1] + priv->ofdm_tx_power_index_diff[group].b;
mcsbase[0] = ofdm[0];
mcsbase[1] = ofdm[1];
if (!ht40) {
mcsbase[0] += priv->ht20_tx_power_index_diff[group].a;
mcsbase[1] += priv->ht20_tx_power_index_diff[group].b;
}
if (priv->tx_paths > 1) {
if (ofdm[0] > priv->ht40_2s_tx_power_index_diff[group].a)
ofdm[0] -= priv->ht40_2s_tx_power_index_diff[group].a;
if (ofdm[1] > priv->ht40_2s_tx_power_index_diff[group].b)
ofdm[1] -= priv->ht40_2s_tx_power_index_diff[group].b;
}
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_CHANNEL)
dev_info(&priv->udev->dev,
"%s: Setting TX power CCK A: %02x, "
"CCK B: %02x, OFDM A: %02x, OFDM B: %02x\n",
__func__, cck[0], cck[1], ofdm[0], ofdm[1]);
for (i = 0; i < RTL8723A_MAX_RF_PATHS; i++) {
if (cck[i] > RF6052_MAX_TX_PWR)
cck[i] = RF6052_MAX_TX_PWR;
if (ofdm[i] > RF6052_MAX_TX_PWR)
ofdm[i] = RF6052_MAX_TX_PWR;
}
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_A_CCK1_MCS32);
val32 &= 0xffff00ff;
val32 |= (cck[0] << 8);
rtl8xxxu_write32(priv, REG_TX_AGC_A_CCK1_MCS32, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11);
val32 &= 0xff;
val32 |= ((cck[0] << 8) | (cck[0] << 16) | (cck[0] << 24));
rtl8xxxu_write32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11);
val32 &= 0xffffff00;
val32 |= cck[1];
rtl8xxxu_write32(priv, REG_TX_AGC_B_CCK11_A_CCK2_11, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_AGC_B_CCK1_55_MCS32);
val32 &= 0xff;
val32 |= ((cck[1] << 8) | (cck[1] << 16) | (cck[1] << 24));
rtl8xxxu_write32(priv, REG_TX_AGC_B_CCK1_55_MCS32, val32);
ofdm_a = ofdmbase[0] | ofdmbase[0] << 8 |
ofdmbase[0] << 16 | ofdmbase[0] << 24;
ofdm_b = ofdmbase[1] | ofdmbase[1] << 8 |
ofdmbase[1] << 16 | ofdmbase[1] << 24;
rtl8xxxu_write32(priv, REG_TX_AGC_A_RATE18_06,
ofdm_a + power_base->reg_0e00);
rtl8xxxu_write32(priv, REG_TX_AGC_B_RATE18_06,
ofdm_b + power_base->reg_0830);
rtl8xxxu_write32(priv, REG_TX_AGC_A_RATE54_24,
ofdm_a + power_base->reg_0e04);
rtl8xxxu_write32(priv, REG_TX_AGC_B_RATE54_24,
ofdm_b + power_base->reg_0834);
mcs_a = mcsbase[0] | mcsbase[0] << 8 |
mcsbase[0] << 16 | mcsbase[0] << 24;
mcs_b = mcsbase[1] | mcsbase[1] << 8 |
mcsbase[1] << 16 | mcsbase[1] << 24;
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS03_MCS00,
mcs_a + power_base->reg_0e10);
rtl8xxxu_write32(priv, REG_TX_AGC_B_MCS03_MCS00,
mcs_b + power_base->reg_083c);
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS07_MCS04,
mcs_a + power_base->reg_0e14);
rtl8xxxu_write32(priv, REG_TX_AGC_B_MCS07_MCS04,
mcs_b + power_base->reg_0848);
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS11_MCS08,
mcs_a + power_base->reg_0e18);
rtl8xxxu_write32(priv, REG_TX_AGC_B_MCS11_MCS08,
mcs_b + power_base->reg_084c);
rtl8xxxu_write32(priv, REG_TX_AGC_A_MCS15_MCS12,
mcs_a + power_base->reg_0e1c);
for (i = 0; i < 3; i++) {
if (i != 2)
val8 = (mcsbase[0] > 8) ? (mcsbase[0] - 8) : 0;
else
val8 = (mcsbase[0] > 6) ? (mcsbase[0] - 6) : 0;
rtl8xxxu_write8(priv, REG_OFDM0_XC_TX_IQ_IMBALANCE + i, val8);
}
rtl8xxxu_write32(priv, REG_TX_AGC_B_MCS15_MCS12,
mcs_b + power_base->reg_0868);
for (i = 0; i < 3; i++) {
if (i != 2)
val8 = (mcsbase[1] > 8) ? (mcsbase[1] - 8) : 0;
else
val8 = (mcsbase[1] > 6) ? (mcsbase[1] - 6) : 0;
rtl8xxxu_write8(priv, REG_OFDM0_XD_TX_IQ_IMBALANCE + i, val8);
}
}
static void rtl8xxxu_set_linktype(struct rtl8xxxu_priv *priv,
enum nl80211_iftype linktype)
{
u8 val8;
val8 = rtl8xxxu_read8(priv, REG_MSR);
val8 &= ~MSR_LINKTYPE_MASK;
switch (linktype) {
case NL80211_IFTYPE_UNSPECIFIED:
val8 |= MSR_LINKTYPE_NONE;
break;
case NL80211_IFTYPE_ADHOC:
val8 |= MSR_LINKTYPE_ADHOC;
break;
case NL80211_IFTYPE_STATION:
val8 |= MSR_LINKTYPE_STATION;
break;
case NL80211_IFTYPE_AP:
val8 |= MSR_LINKTYPE_AP;
break;
default:
goto out;
}
rtl8xxxu_write8(priv, REG_MSR, val8);
out:
return;
}
static void
rtl8xxxu_set_retry(struct rtl8xxxu_priv *priv, u16 short_retry, u16 long_retry)
{
u16 val16;
val16 = ((short_retry << RETRY_LIMIT_SHORT_SHIFT) &
RETRY_LIMIT_SHORT_MASK) |
((long_retry << RETRY_LIMIT_LONG_SHIFT) &
RETRY_LIMIT_LONG_MASK);
rtl8xxxu_write16(priv, REG_RETRY_LIMIT, val16);
}
static void
rtl8xxxu_set_spec_sifs(struct rtl8xxxu_priv *priv, u16 cck, u16 ofdm)
{
u16 val16;
val16 = ((cck << SPEC_SIFS_CCK_SHIFT) & SPEC_SIFS_CCK_MASK) |
((ofdm << SPEC_SIFS_OFDM_SHIFT) & SPEC_SIFS_OFDM_MASK);
rtl8xxxu_write16(priv, REG_SPEC_SIFS, val16);
}
static void rtl8xxxu_print_chipinfo(struct rtl8xxxu_priv *priv)
{
struct device *dev = &priv->udev->dev;
char *cut;
switch (priv->chip_cut) {
case 0:
cut = "A";
break;
case 1:
cut = "B";
break;
case 2:
cut = "C";
break;
case 3:
cut = "D";
break;
case 4:
cut = "E";
break;
default:
cut = "unknown";
}
dev_info(dev,
"RTL%s rev %s (%s) %iT%iR, TX queues %i, WiFi=%i, BT=%i, GPS=%i, HI PA=%i\n",
priv->chip_name, cut, priv->chip_vendor, priv->tx_paths,
priv->rx_paths, priv->ep_tx_count, priv->has_wifi,
priv->has_bluetooth, priv->has_gps, priv->hi_pa);
dev_info(dev, "RTL%s MAC: %pM\n", priv->chip_name, priv->mac_addr);
}
static int rtl8xxxu_identify_chip(struct rtl8xxxu_priv *priv)
{
struct device *dev = &priv->udev->dev;
u32 val32, bonding;
u16 val16;
val32 = rtl8xxxu_read32(priv, REG_SYS_CFG);
priv->chip_cut = (val32 & SYS_CFG_CHIP_VERSION_MASK) >>
SYS_CFG_CHIP_VERSION_SHIFT;
if (val32 & SYS_CFG_TRP_VAUX_EN) {
dev_info(dev, "Unsupported test chip\n");
return -ENOTSUPP;
}
if (val32 & SYS_CFG_BT_FUNC) {
if (priv->chip_cut >= 3) {
sprintf(priv->chip_name, "8723BU");
priv->rtl_chip = RTL8723B;
} else {
sprintf(priv->chip_name, "8723AU");
priv->usb_interrupts = 1;
priv->rtl_chip = RTL8723A;
}
priv->rf_paths = 1;
priv->rx_paths = 1;
priv->tx_paths = 1;
val32 = rtl8xxxu_read32(priv, REG_MULTI_FUNC_CTRL);
if (val32 & MULTI_WIFI_FUNC_EN)
priv->has_wifi = 1;
if (val32 & MULTI_BT_FUNC_EN)
priv->has_bluetooth = 1;
if (val32 & MULTI_GPS_FUNC_EN)
priv->has_gps = 1;
priv->is_multi_func = 1;
} else if (val32 & SYS_CFG_TYPE_ID) {
bonding = rtl8xxxu_read32(priv, REG_HPON_FSM);
bonding &= HPON_FSM_BONDING_MASK;
if (priv->fops->tx_desc_size ==
sizeof(struct rtl8xxxu_txdesc40)) {
if (bonding == HPON_FSM_BONDING_1T2R) {
sprintf(priv->chip_name, "8191EU");
priv->rf_paths = 2;
priv->rx_paths = 2;
priv->tx_paths = 1;
priv->rtl_chip = RTL8191E;
} else {
sprintf(priv->chip_name, "8192EU");
priv->rf_paths = 2;
priv->rx_paths = 2;
priv->tx_paths = 2;
priv->rtl_chip = RTL8192E;
}
} else if (bonding == HPON_FSM_BONDING_1T2R) {
sprintf(priv->chip_name, "8191CU");
priv->rf_paths = 2;
priv->rx_paths = 2;
priv->tx_paths = 1;
priv->usb_interrupts = 1;
priv->rtl_chip = RTL8191C;
} else {
sprintf(priv->chip_name, "8192CU");
priv->rf_paths = 2;
priv->rx_paths = 2;
priv->tx_paths = 2;
priv->usb_interrupts = 1;
priv->rtl_chip = RTL8192C;
}
priv->has_wifi = 1;
} else {
sprintf(priv->chip_name, "8188CU");
priv->rf_paths = 1;
priv->rx_paths = 1;
priv->tx_paths = 1;
priv->rtl_chip = RTL8188C;
priv->usb_interrupts = 1;
priv->has_wifi = 1;
}
switch (priv->rtl_chip) {
case RTL8188E:
case RTL8192E:
case RTL8723B:
switch (val32 & SYS_CFG_VENDOR_EXT_MASK) {
case SYS_CFG_VENDOR_ID_TSMC:
sprintf(priv->chip_vendor, "TSMC");
break;
case SYS_CFG_VENDOR_ID_SMIC:
sprintf(priv->chip_vendor, "SMIC");
priv->vendor_smic = 1;
break;
case SYS_CFG_VENDOR_ID_UMC:
sprintf(priv->chip_vendor, "UMC");
priv->vendor_umc = 1;
break;
default:
sprintf(priv->chip_vendor, "unknown");
}
break;
default:
if (val32 & SYS_CFG_VENDOR_ID) {
sprintf(priv->chip_vendor, "UMC");
priv->vendor_umc = 1;
} else {
sprintf(priv->chip_vendor, "TSMC");
}
}
val32 = rtl8xxxu_read32(priv, REG_GPIO_OUTSTS);
priv->rom_rev = (val32 & GPIO_RF_RL_ID) >> 28;
val16 = rtl8xxxu_read16(priv, REG_NORMAL_SIE_EP_TX);
if (val16 & NORMAL_SIE_EP_TX_HIGH_MASK) {
priv->ep_tx_high_queue = 1;
priv->ep_tx_count++;
}
if (val16 & NORMAL_SIE_EP_TX_NORMAL_MASK) {
priv->ep_tx_normal_queue = 1;
priv->ep_tx_count++;
}
if (val16 & NORMAL_SIE_EP_TX_LOW_MASK) {
priv->ep_tx_low_queue = 1;
priv->ep_tx_count++;
}
if (!priv->ep_tx_count) {
switch (priv->nr_out_eps) {
case 4:
case 3:
priv->ep_tx_low_queue = 1;
priv->ep_tx_count++;
case 2:
priv->ep_tx_normal_queue = 1;
priv->ep_tx_count++;
case 1:
priv->ep_tx_high_queue = 1;
priv->ep_tx_count++;
break;
default:
dev_info(dev, "Unsupported USB TX end-points\n");
return -ENOTSUPP;
}
}
return 0;
}
static int
rtl8xxxu_read_efuse8(struct rtl8xxxu_priv *priv, u16 offset, u8 *data)
{
int i;
u8 val8;
u32 val32;
rtl8xxxu_write8(priv, REG_EFUSE_CTRL + 1, offset & 0xff);
val8 = rtl8xxxu_read8(priv, REG_EFUSE_CTRL + 2);
val8 &= 0xfc;
val8 |= (offset >> 8) & 0x03;
rtl8xxxu_write8(priv, REG_EFUSE_CTRL + 2, val8);
val8 = rtl8xxxu_read8(priv, REG_EFUSE_CTRL + 3);
rtl8xxxu_write8(priv, REG_EFUSE_CTRL + 3, val8 & 0x7f);
val32 = rtl8xxxu_read32(priv, REG_EFUSE_CTRL);
for (i = 0; i < RTL8XXXU_MAX_REG_POLL; i++) {
val32 = rtl8xxxu_read32(priv, REG_EFUSE_CTRL);
if (val32 & BIT(31))
break;
}
if (i == RTL8XXXU_MAX_REG_POLL)
return -EIO;
udelay(50);
val32 = rtl8xxxu_read32(priv, REG_EFUSE_CTRL);
*data = val32 & 0xff;
return 0;
}
static int rtl8xxxu_read_efuse(struct rtl8xxxu_priv *priv)
{
struct device *dev = &priv->udev->dev;
int i, ret = 0;
u8 val8, word_mask, header, extheader;
u16 val16, efuse_addr, offset;
u32 val32;
val16 = rtl8xxxu_read16(priv, REG_9346CR);
if (val16 & EEPROM_ENABLE)
priv->has_eeprom = 1;
if (val16 & EEPROM_BOOT)
priv->boot_eeprom = 1;
if (priv->is_multi_func) {
val32 = rtl8xxxu_read32(priv, REG_EFUSE_TEST);
val32 = (val32 & ~EFUSE_SELECT_MASK) | EFUSE_WIFI_SELECT;
rtl8xxxu_write32(priv, REG_EFUSE_TEST, val32);
}
dev_dbg(dev, "Booting from %s\n",
priv->boot_eeprom ? "EEPROM" : "EFUSE");
rtl8xxxu_write8(priv, REG_EFUSE_ACCESS, EFUSE_ACCESS_ENABLE);
val16 = rtl8xxxu_read16(priv, REG_SYS_ISO_CTRL);
if (!(val16 & SYS_ISO_PWC_EV12V)) {
val16 |= SYS_ISO_PWC_EV12V;
rtl8xxxu_write16(priv, REG_SYS_ISO_CTRL, val16);
}
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
if (!(val16 & SYS_FUNC_ELDR)) {
val16 |= SYS_FUNC_ELDR;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
}
val16 = rtl8xxxu_read16(priv, REG_SYS_CLKR);
if (!(val16 & SYS_CLK_LOADER_ENABLE) || !(val16 & SYS_CLK_ANA8M)) {
val16 |= (SYS_CLK_LOADER_ENABLE | SYS_CLK_ANA8M);
rtl8xxxu_write16(priv, REG_SYS_CLKR, val16);
}
memset(priv->efuse_wifi.raw, 0xff, EFUSE_MAP_LEN);
efuse_addr = 0;
while (efuse_addr < EFUSE_REAL_CONTENT_LEN_8723A) {
u16 map_addr;
ret = rtl8xxxu_read_efuse8(priv, efuse_addr++, &header);
if (ret || header == 0xff)
goto exit;
if ((header & 0x1f) == 0x0f) {
offset = (header & 0xe0) >> 5;
ret = rtl8xxxu_read_efuse8(priv, efuse_addr++,
&extheader);
if (ret)
goto exit;
if ((extheader & 0x0f) == 0x0f)
continue;
offset |= ((extheader & 0xf0) >> 1);
word_mask = extheader & 0x0f;
} else {
offset = (header >> 4) & 0x0f;
word_mask = header & 0x0f;
}
map_addr = offset * 8;
if (map_addr >= EFUSE_MAP_LEN) {
dev_warn(dev, "%s: Illegal map_addr (%04x), "
"efuse corrupt!\n",
__func__, map_addr);
ret = -EINVAL;
goto exit;
}
for (i = 0; i < EFUSE_MAX_WORD_UNIT; i++) {
if (word_mask & BIT(i)) {
map_addr += 2;
continue;
}
ret = rtl8xxxu_read_efuse8(priv, efuse_addr++, &val8);
if (ret)
goto exit;
priv->efuse_wifi.raw[map_addr++] = val8;
ret = rtl8xxxu_read_efuse8(priv, efuse_addr++, &val8);
if (ret)
goto exit;
priv->efuse_wifi.raw[map_addr++] = val8;
}
}
exit:
rtl8xxxu_write8(priv, REG_EFUSE_ACCESS, EFUSE_ACCESS_DISABLE);
return ret;
}
void rtl8xxxu_reset_8051(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 sys_func;
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL + 1);
val8 &= ~BIT(0);
rtl8xxxu_write8(priv, REG_RSV_CTRL + 1, val8);
sys_func = rtl8xxxu_read16(priv, REG_SYS_FUNC);
sys_func &= ~SYS_FUNC_CPU_ENABLE;
rtl8xxxu_write16(priv, REG_SYS_FUNC, sys_func);
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL + 1);
val8 |= BIT(0);
rtl8xxxu_write8(priv, REG_RSV_CTRL + 1, val8);
sys_func |= SYS_FUNC_CPU_ENABLE;
rtl8xxxu_write16(priv, REG_SYS_FUNC, sys_func);
}
static int rtl8xxxu_start_firmware(struct rtl8xxxu_priv *priv)
{
struct device *dev = &priv->udev->dev;
int ret = 0, i;
u32 val32;
for (i = 0; i < RTL8XXXU_FIRMWARE_POLL_MAX; i++) {
val32 = rtl8xxxu_read32(priv, REG_MCU_FW_DL);
if (val32 & MCU_FW_DL_CSUM_REPORT)
break;
}
if (i == RTL8XXXU_FIRMWARE_POLL_MAX) {
dev_warn(dev, "Firmware checksum poll timed out\n");
ret = -EAGAIN;
goto exit;
}
val32 = rtl8xxxu_read32(priv, REG_MCU_FW_DL);
val32 |= MCU_FW_DL_READY;
val32 &= ~MCU_WINT_INIT_READY;
rtl8xxxu_write32(priv, REG_MCU_FW_DL, val32);
priv->fops->reset_8051(priv);
for (i = 0; i < RTL8XXXU_FIRMWARE_POLL_MAX; i++) {
val32 = rtl8xxxu_read32(priv, REG_MCU_FW_DL);
if (val32 & MCU_WINT_INIT_READY)
break;
udelay(100);
}
if (i == RTL8XXXU_FIRMWARE_POLL_MAX) {
dev_warn(dev, "Firmware failed to start\n");
ret = -EAGAIN;
goto exit;
}
if (priv->rtl_chip == RTL8723B)
rtl8xxxu_write8(priv, REG_HMTFR, 0x0f);
exit:
return ret;
}
static int rtl8xxxu_download_firmware(struct rtl8xxxu_priv *priv)
{
int pages, remainder, i, ret;
u8 val8;
u16 val16;
u32 val32;
u8 *fwptr;
val8 = rtl8xxxu_read8(priv, REG_SYS_FUNC + 1);
val8 |= 4;
rtl8xxxu_write8(priv, REG_SYS_FUNC + 1, val8);
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 |= SYS_FUNC_CPU_ENABLE;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
val8 = rtl8xxxu_read8(priv, REG_MCU_FW_DL);
if (val8 & MCU_FW_RAM_SEL) {
pr_info("do the RAM reset\n");
rtl8xxxu_write8(priv, REG_MCU_FW_DL, 0x00);
priv->fops->reset_8051(priv);
}
val8 = rtl8xxxu_read8(priv, REG_MCU_FW_DL);
val8 |= MCU_FW_DL_ENABLE;
rtl8xxxu_write8(priv, REG_MCU_FW_DL, val8);
val32 = rtl8xxxu_read32(priv, REG_MCU_FW_DL);
val32 &= ~BIT(19);
rtl8xxxu_write32(priv, REG_MCU_FW_DL, val32);
val8 = rtl8xxxu_read8(priv, REG_MCU_FW_DL);
val8 |= MCU_FW_DL_CSUM_REPORT;
rtl8xxxu_write8(priv, REG_MCU_FW_DL, val8);
pages = priv->fw_size / RTL_FW_PAGE_SIZE;
remainder = priv->fw_size % RTL_FW_PAGE_SIZE;
fwptr = priv->fw_data->data;
for (i = 0; i < pages; i++) {
val8 = rtl8xxxu_read8(priv, REG_MCU_FW_DL + 2) & 0xF8;
val8 |= i;
rtl8xxxu_write8(priv, REG_MCU_FW_DL + 2, val8);
ret = rtl8xxxu_writeN(priv, REG_FW_START_ADDRESS,
fwptr, RTL_FW_PAGE_SIZE);
if (ret != RTL_FW_PAGE_SIZE) {
ret = -EAGAIN;
goto fw_abort;
}
fwptr += RTL_FW_PAGE_SIZE;
}
if (remainder) {
val8 = rtl8xxxu_read8(priv, REG_MCU_FW_DL + 2) & 0xF8;
val8 |= i;
rtl8xxxu_write8(priv, REG_MCU_FW_DL + 2, val8);
ret = rtl8xxxu_writeN(priv, REG_FW_START_ADDRESS,
fwptr, remainder);
if (ret != remainder) {
ret = -EAGAIN;
goto fw_abort;
}
}
ret = 0;
fw_abort:
val16 = rtl8xxxu_read16(priv, REG_MCU_FW_DL);
val16 &= ~MCU_FW_DL_ENABLE;
rtl8xxxu_write16(priv, REG_MCU_FW_DL, val16);
return ret;
}
int rtl8xxxu_load_firmware(struct rtl8xxxu_priv *priv, char *fw_name)
{
struct device *dev = &priv->udev->dev;
const struct firmware *fw;
int ret = 0;
u16 signature;
dev_info(dev, "%s: Loading firmware %s\n", DRIVER_NAME, fw_name);
if (request_firmware(&fw, fw_name, &priv->udev->dev)) {
dev_warn(dev, "request_firmware(%s) failed\n", fw_name);
ret = -EAGAIN;
goto exit;
}
if (!fw) {
dev_warn(dev, "Firmware data not available\n");
ret = -EINVAL;
goto exit;
}
priv->fw_data = kmemdup(fw->data, fw->size, GFP_KERNEL);
if (!priv->fw_data) {
ret = -ENOMEM;
goto exit;
}
priv->fw_size = fw->size - sizeof(struct rtl8xxxu_firmware_header);
signature = le16_to_cpu(priv->fw_data->signature);
switch (signature & 0xfff0) {
case 0x92e0:
case 0x92c0:
case 0x88c0:
case 0x5300:
case 0x2300:
break;
default:
ret = -EINVAL;
dev_warn(dev, "%s: Invalid firmware signature: 0x%04x\n",
__func__, signature);
}
dev_info(dev, "Firmware revision %i.%i (signature 0x%04x)\n",
le16_to_cpu(priv->fw_data->major_version),
priv->fw_data->minor_version, signature);
exit:
release_firmware(fw);
return ret;
}
void rtl8xxxu_firmware_self_reset(struct rtl8xxxu_priv *priv)
{
u16 val16;
int i = 100;
rtl8xxxu_write8(priv, REG_HMTFR + 3, 0x20);
for (i = 100; i > 0; i--) {
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
if (!(val16 & SYS_FUNC_CPU_ENABLE)) {
dev_dbg(&priv->udev->dev,
"%s: Firmware self reset success!\n", __func__);
break;
}
udelay(50);
}
if (!i) {
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 &= ~SYS_FUNC_CPU_ENABLE;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
}
}
static int
rtl8xxxu_init_mac(struct rtl8xxxu_priv *priv)
{
struct rtl8xxxu_reg8val *array = priv->fops->mactable;
int i, ret;
u16 reg;
u8 val;
for (i = 0; ; i++) {
reg = array[i].reg;
val = array[i].val;
if (reg == 0xffff && val == 0xff)
break;
ret = rtl8xxxu_write8(priv, reg, val);
if (ret != 1) {
dev_warn(&priv->udev->dev,
"Failed to initialize MAC "
"(reg: %04x, val %02x)\n", reg, val);
return -EAGAIN;
}
}
if (priv->rtl_chip != RTL8723B && priv->rtl_chip != RTL8192E)
rtl8xxxu_write8(priv, REG_MAX_AGGR_NUM, 0x0a);
return 0;
}
int rtl8xxxu_init_phy_regs(struct rtl8xxxu_priv *priv,
struct rtl8xxxu_reg32val *array)
{
int i, ret;
u16 reg;
u32 val;
for (i = 0; ; i++) {
reg = array[i].reg;
val = array[i].val;
if (reg == 0xffff && val == 0xffffffff)
break;
ret = rtl8xxxu_write32(priv, reg, val);
if (ret != sizeof(val)) {
dev_warn(&priv->udev->dev,
"Failed to initialize PHY\n");
return -EAGAIN;
}
udelay(1);
}
return 0;
}
void rtl8xxxu_gen1_init_phy_bb(struct rtl8xxxu_priv *priv)
{
u8 val8, ldoa15, ldov12d, lpldo, ldohci12;
u16 val16;
u32 val32;
val8 = rtl8xxxu_read8(priv, REG_AFE_PLL_CTRL);
udelay(2);
val8 |= AFE_PLL_320_ENABLE;
rtl8xxxu_write8(priv, REG_AFE_PLL_CTRL, val8);
udelay(2);
rtl8xxxu_write8(priv, REG_AFE_PLL_CTRL + 1, 0xff);
udelay(2);
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 |= SYS_FUNC_BB_GLB_RSTN | SYS_FUNC_BBRSTB;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
val32 = rtl8xxxu_read32(priv, REG_AFE_XTAL_CTRL);
val32 &= ~AFE_XTAL_RF_GATE;
if (priv->has_bluetooth)
val32 &= ~AFE_XTAL_BT_GATE;
rtl8xxxu_write32(priv, REG_AFE_XTAL_CTRL, val32);
val8 = RF_ENABLE | RF_RSTB | RF_SDMRSTB;
rtl8xxxu_write8(priv, REG_RF_CTRL, val8);
if (priv->hi_pa)
rtl8xxxu_init_phy_regs(priv, rtl8188ru_phy_1t_highpa_table);
else if (priv->tx_paths == 2)
rtl8xxxu_init_phy_regs(priv, rtl8192cu_phy_2t_init_table);
else
rtl8xxxu_init_phy_regs(priv, rtl8723a_phy_1t_init_table);
if (priv->rtl_chip == RTL8188R && priv->hi_pa &&
priv->vendor_umc && priv->chip_cut == 1)
rtl8xxxu_write8(priv, REG_OFDM0_AGC_PARM1 + 2, 0x50);
if (priv->hi_pa)
rtl8xxxu_init_phy_regs(priv, rtl8xxx_agc_highpa_table);
else
rtl8xxxu_init_phy_regs(priv, rtl8xxx_agc_standard_table);
ldoa15 = LDOA15_ENABLE | LDOA15_OBUF;
ldov12d = LDOV12D_ENABLE | BIT(2) | (2 << LDOV12D_VADJ_SHIFT);
ldohci12 = 0x57;
lpldo = 1;
val32 = (lpldo << 24) | (ldohci12 << 16) | (ldov12d << 8) | ldoa15;
rtl8xxxu_write32(priv, REG_LDOA15_CTRL, val32);
}
static int rtl8xxxu_init_phy_bb(struct rtl8xxxu_priv *priv)
{
u8 val8;
u32 val32;
priv->fops->init_phy_bb(priv);
if (priv->tx_paths == 1 && priv->rx_paths == 2) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_TX_INFO);
val32 &= ~(BIT(0) | BIT(1));
val32 |= BIT(1);
rtl8xxxu_write32(priv, REG_FPGA0_TX_INFO, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA1_TX_INFO);
val32 &= ~0x300033;
val32 |= 0x200022;
rtl8xxxu_write32(priv, REG_FPGA1_TX_INFO, val32);
val32 = rtl8xxxu_read32(priv, REG_CCK0_AFE_SETTING);
val32 &= ~CCK0_AFE_RX_MASK;
val32 &= 0x00ffffff;
val32 |= 0x40000000;
val32 |= CCK0_AFE_RX_ANT_B;
rtl8xxxu_write32(priv, REG_CCK0_AFE_SETTING, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_TRX_PATH_ENABLE);
val32 &= ~(OFDM_RF_PATH_RX_MASK | OFDM_RF_PATH_TX_MASK);
val32 |= (OFDM_RF_PATH_RX_A | OFDM_RF_PATH_RX_B |
OFDM_RF_PATH_TX_B);
rtl8xxxu_write32(priv, REG_OFDM0_TRX_PATH_ENABLE, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_AGC_PARM1);
val32 &= ~(BIT(4) | BIT(5));
val32 |= BIT(4);
rtl8xxxu_write32(priv, REG_OFDM0_AGC_PARM1, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_CCK_RFON);
val32 &= ~(BIT(27) | BIT(26));
val32 |= BIT(27);
rtl8xxxu_write32(priv, REG_TX_CCK_RFON, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_CCK_BBON);
val32 &= ~(BIT(27) | BIT(26));
val32 |= BIT(27);
rtl8xxxu_write32(priv, REG_TX_CCK_BBON, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_OFDM_RFON);
val32 &= ~(BIT(27) | BIT(26));
val32 |= BIT(27);
rtl8xxxu_write32(priv, REG_TX_OFDM_RFON, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_OFDM_BBON);
val32 &= ~(BIT(27) | BIT(26));
val32 |= BIT(27);
rtl8xxxu_write32(priv, REG_TX_OFDM_BBON, val32);
val32 = rtl8xxxu_read32(priv, REG_TX_TO_TX);
val32 &= ~(BIT(27) | BIT(26));
val32 |= BIT(27);
rtl8xxxu_write32(priv, REG_TX_TO_TX, val32);
}
if (priv->has_xtalk) {
val32 = rtl8xxxu_read32(priv, REG_MAC_PHY_CTRL);
val8 = priv->xtalk;
val32 &= 0xff000fff;
val32 |= ((val8 | (val8 << 6)) << 12);
rtl8xxxu_write32(priv, REG_MAC_PHY_CTRL, val32);
}
if (priv->rtl_chip == RTL8192E)
rtl8xxxu_write32(priv, REG_AFE_XTAL_CTRL, 0x000f81fb);
return 0;
}
static int rtl8xxxu_init_rf_regs(struct rtl8xxxu_priv *priv,
struct rtl8xxxu_rfregval *array,
enum rtl8xxxu_rfpath path)
{
int i, ret;
u8 reg;
u32 val;
for (i = 0; ; i++) {
reg = array[i].reg;
val = array[i].val;
if (reg == 0xff && val == 0xffffffff)
break;
switch (reg) {
case 0xfe:
msleep(50);
continue;
case 0xfd:
mdelay(5);
continue;
case 0xfc:
mdelay(1);
continue;
case 0xfb:
udelay(50);
continue;
case 0xfa:
udelay(5);
continue;
case 0xf9:
udelay(1);
continue;
}
ret = rtl8xxxu_write_rfreg(priv, path, reg, val);
if (ret) {
dev_warn(&priv->udev->dev,
"Failed to initialize RF\n");
return -EAGAIN;
}
udelay(1);
}
return 0;
}
int rtl8xxxu_init_phy_rf(struct rtl8xxxu_priv *priv,
struct rtl8xxxu_rfregval *table,
enum rtl8xxxu_rfpath path)
{
u32 val32;
u16 val16, rfsi_rfenv;
u16 reg_sw_ctrl, reg_int_oe, reg_hssi_parm2;
switch (path) {
case RF_A:
reg_sw_ctrl = REG_FPGA0_XA_RF_SW_CTRL;
reg_int_oe = REG_FPGA0_XA_RF_INT_OE;
reg_hssi_parm2 = REG_FPGA0_XA_HSSI_PARM2;
break;
case RF_B:
reg_sw_ctrl = REG_FPGA0_XB_RF_SW_CTRL;
reg_int_oe = REG_FPGA0_XB_RF_INT_OE;
reg_hssi_parm2 = REG_FPGA0_XB_HSSI_PARM2;
break;
default:
dev_err(&priv->udev->dev, "%s:Unsupported RF path %c\n",
__func__, path + 'A');
return -EINVAL;
}
rfsi_rfenv = rtl8xxxu_read16(priv, reg_sw_ctrl);
rfsi_rfenv &= FPGA0_RF_RFENV;
val32 = rtl8xxxu_read32(priv, reg_int_oe);
val32 |= BIT(20);
rtl8xxxu_write32(priv, reg_int_oe, val32);
udelay(1);
val32 = rtl8xxxu_read32(priv, reg_int_oe);
val32 |= BIT(4);
rtl8xxxu_write32(priv, reg_int_oe, val32);
udelay(1);
val32 = rtl8xxxu_read32(priv, reg_hssi_parm2);
val32 &= ~FPGA0_HSSI_3WIRE_ADDR_LEN;
rtl8xxxu_write32(priv, reg_hssi_parm2, val32);
udelay(1);
val32 = rtl8xxxu_read32(priv, reg_hssi_parm2);
val32 &= ~FPGA0_HSSI_3WIRE_DATA_LEN;
rtl8xxxu_write32(priv, reg_hssi_parm2, val32);
udelay(1);
rtl8xxxu_init_rf_regs(priv, table, path);
val16 = rtl8xxxu_read16(priv, reg_sw_ctrl);
val16 &= ~FPGA0_RF_RFENV;
val16 |= rfsi_rfenv;
rtl8xxxu_write16(priv, reg_sw_ctrl, val16);
return 0;
}
static int rtl8xxxu_llt_write(struct rtl8xxxu_priv *priv, u8 address, u8 data)
{
int ret = -EBUSY;
int count = 0;
u32 value;
value = LLT_OP_WRITE | address << 8 | data;
rtl8xxxu_write32(priv, REG_LLT_INIT, value);
do {
value = rtl8xxxu_read32(priv, REG_LLT_INIT);
if ((value & LLT_OP_MASK) == LLT_OP_INACTIVE) {
ret = 0;
break;
}
} while (count++ < 20);
return ret;
}
int rtl8xxxu_init_llt_table(struct rtl8xxxu_priv *priv)
{
int ret;
int i;
u8 last_tx_page;
last_tx_page = priv->fops->total_page_num;
for (i = 0; i < last_tx_page; i++) {
ret = rtl8xxxu_llt_write(priv, i, i + 1);
if (ret)
goto exit;
}
ret = rtl8xxxu_llt_write(priv, last_tx_page, 0xff);
if (ret)
goto exit;
for (i = last_tx_page + 1; i < 0xff; i++) {
ret = rtl8xxxu_llt_write(priv, i, (i + 1));
if (ret)
goto exit;
}
ret = rtl8xxxu_llt_write(priv, 0xff, last_tx_page + 1);
if (ret)
goto exit;
exit:
return ret;
}
int rtl8xxxu_auto_llt_table(struct rtl8xxxu_priv *priv)
{
u32 val32;
int ret = 0;
int i;
val32 = rtl8xxxu_read32(priv, REG_AUTO_LLT);
val32 |= AUTO_LLT_INIT_LLT;
rtl8xxxu_write32(priv, REG_AUTO_LLT, val32);
for (i = 500; i; i--) {
val32 = rtl8xxxu_read32(priv, REG_AUTO_LLT);
if (!(val32 & AUTO_LLT_INIT_LLT))
break;
usleep_range(2, 4);
}
if (!i) {
ret = -EBUSY;
dev_warn(&priv->udev->dev, "LLT table init failed\n");
}
return ret;
}
static int rtl8xxxu_init_queue_priority(struct rtl8xxxu_priv *priv)
{
u16 val16, hi, lo;
u16 hiq, mgq, bkq, beq, viq, voq;
int hip, mgp, bkp, bep, vip, vop;
int ret = 0;
switch (priv->ep_tx_count) {
case 1:
if (priv->ep_tx_high_queue) {
hi = TRXDMA_QUEUE_HIGH;
} else if (priv->ep_tx_low_queue) {
hi = TRXDMA_QUEUE_LOW;
} else if (priv->ep_tx_normal_queue) {
hi = TRXDMA_QUEUE_NORMAL;
} else {
hi = 0;
ret = -EINVAL;
}
hiq = hi;
mgq = hi;
bkq = hi;
beq = hi;
viq = hi;
voq = hi;
hip = 0;
mgp = 0;
bkp = 0;
bep = 0;
vip = 0;
vop = 0;
break;
case 2:
if (priv->ep_tx_high_queue && priv->ep_tx_low_queue) {
hi = TRXDMA_QUEUE_HIGH;
lo = TRXDMA_QUEUE_LOW;
} else if (priv->ep_tx_normal_queue && priv->ep_tx_low_queue) {
hi = TRXDMA_QUEUE_NORMAL;
lo = TRXDMA_QUEUE_LOW;
} else if (priv->ep_tx_high_queue && priv->ep_tx_normal_queue) {
hi = TRXDMA_QUEUE_HIGH;
lo = TRXDMA_QUEUE_NORMAL;
} else {
ret = -EINVAL;
hi = 0;
lo = 0;
}
hiq = hi;
mgq = hi;
bkq = lo;
beq = lo;
viq = hi;
voq = hi;
hip = 0;
mgp = 0;
bkp = 1;
bep = 1;
vip = 0;
vop = 0;
break;
case 3:
beq = TRXDMA_QUEUE_LOW;
bkq = TRXDMA_QUEUE_LOW;
viq = TRXDMA_QUEUE_NORMAL;
voq = TRXDMA_QUEUE_HIGH;
mgq = TRXDMA_QUEUE_HIGH;
hiq = TRXDMA_QUEUE_HIGH;
hip = hiq ^ 3;
mgp = mgq ^ 3;
bkp = bkq ^ 3;
bep = beq ^ 3;
vip = viq ^ 3;
vop = viq ^ 3;
break;
default:
ret = -EINVAL;
}
if (!ret) {
val16 = rtl8xxxu_read16(priv, REG_TRXDMA_CTRL);
val16 &= 0x7;
val16 |= (voq << TRXDMA_CTRL_VOQ_SHIFT) |
(viq << TRXDMA_CTRL_VIQ_SHIFT) |
(beq << TRXDMA_CTRL_BEQ_SHIFT) |
(bkq << TRXDMA_CTRL_BKQ_SHIFT) |
(mgq << TRXDMA_CTRL_MGQ_SHIFT) |
(hiq << TRXDMA_CTRL_HIQ_SHIFT);
rtl8xxxu_write16(priv, REG_TRXDMA_CTRL, val16);
priv->pipe_out[TXDESC_QUEUE_VO] =
usb_sndbulkpipe(priv->udev, priv->out_ep[vop]);
priv->pipe_out[TXDESC_QUEUE_VI] =
usb_sndbulkpipe(priv->udev, priv->out_ep[vip]);
priv->pipe_out[TXDESC_QUEUE_BE] =
usb_sndbulkpipe(priv->udev, priv->out_ep[bep]);
priv->pipe_out[TXDESC_QUEUE_BK] =
usb_sndbulkpipe(priv->udev, priv->out_ep[bkp]);
priv->pipe_out[TXDESC_QUEUE_BEACON] =
usb_sndbulkpipe(priv->udev, priv->out_ep[0]);
priv->pipe_out[TXDESC_QUEUE_MGNT] =
usb_sndbulkpipe(priv->udev, priv->out_ep[mgp]);
priv->pipe_out[TXDESC_QUEUE_HIGH] =
usb_sndbulkpipe(priv->udev, priv->out_ep[hip]);
priv->pipe_out[TXDESC_QUEUE_CMD] =
usb_sndbulkpipe(priv->udev, priv->out_ep[0]);
}
return ret;
}
void rtl8xxxu_fill_iqk_matrix_a(struct rtl8xxxu_priv *priv, bool iqk_ok,
int result[][8], int candidate, bool tx_only)
{
u32 oldval, x, tx0_a, reg;
int y, tx0_c;
u32 val32;
if (!iqk_ok)
return;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XA_TX_IQ_IMBALANCE);
oldval = val32 >> 22;
x = result[candidate][0];
if ((x & 0x00000200) != 0)
x = x | 0xfffffc00;
tx0_a = (x * oldval) >> 8;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XA_TX_IQ_IMBALANCE);
val32 &= ~0x3ff;
val32 |= tx0_a;
rtl8xxxu_write32(priv, REG_OFDM0_XA_TX_IQ_IMBALANCE, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_ENERGY_CCA_THRES);
val32 &= ~BIT(31);
if ((x * oldval >> 7) & 0x1)
val32 |= BIT(31);
rtl8xxxu_write32(priv, REG_OFDM0_ENERGY_CCA_THRES, val32);
y = result[candidate][1];
if ((y & 0x00000200) != 0)
y = y | 0xfffffc00;
tx0_c = (y * oldval) >> 8;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XC_TX_AFE);
val32 &= ~0xf0000000;
val32 |= (((tx0_c & 0x3c0) >> 6) << 28);
rtl8xxxu_write32(priv, REG_OFDM0_XC_TX_AFE, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XA_TX_IQ_IMBALANCE);
val32 &= ~0x003f0000;
val32 |= ((tx0_c & 0x3f) << 16);
rtl8xxxu_write32(priv, REG_OFDM0_XA_TX_IQ_IMBALANCE, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_ENERGY_CCA_THRES);
val32 &= ~BIT(29);
if ((y * oldval >> 7) & 0x1)
val32 |= BIT(29);
rtl8xxxu_write32(priv, REG_OFDM0_ENERGY_CCA_THRES, val32);
if (tx_only) {
dev_dbg(&priv->udev->dev, "%s: only TX\n", __func__);
return;
}
reg = result[candidate][2];
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XA_RX_IQ_IMBALANCE);
val32 &= ~0x3ff;
val32 |= (reg & 0x3ff);
rtl8xxxu_write32(priv, REG_OFDM0_XA_RX_IQ_IMBALANCE, val32);
reg = result[candidate][3] & 0x3F;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XA_RX_IQ_IMBALANCE);
val32 &= ~0xfc00;
val32 |= ((reg << 10) & 0xfc00);
rtl8xxxu_write32(priv, REG_OFDM0_XA_RX_IQ_IMBALANCE, val32);
reg = (result[candidate][3] >> 6) & 0xF;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_RX_IQ_EXT_ANTA);
val32 &= ~0xf0000000;
val32 |= (reg << 28);
rtl8xxxu_write32(priv, REG_OFDM0_RX_IQ_EXT_ANTA, val32);
}
void rtl8xxxu_fill_iqk_matrix_b(struct rtl8xxxu_priv *priv, bool iqk_ok,
int result[][8], int candidate, bool tx_only)
{
u32 oldval, x, tx1_a, reg;
int y, tx1_c;
u32 val32;
if (!iqk_ok)
return;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XB_TX_IQ_IMBALANCE);
oldval = val32 >> 22;
x = result[candidate][4];
if ((x & 0x00000200) != 0)
x = x | 0xfffffc00;
tx1_a = (x * oldval) >> 8;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XB_TX_IQ_IMBALANCE);
val32 &= ~0x3ff;
val32 |= tx1_a;
rtl8xxxu_write32(priv, REG_OFDM0_XB_TX_IQ_IMBALANCE, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_ENERGY_CCA_THRES);
val32 &= ~BIT(27);
if ((x * oldval >> 7) & 0x1)
val32 |= BIT(27);
rtl8xxxu_write32(priv, REG_OFDM0_ENERGY_CCA_THRES, val32);
y = result[candidate][5];
if ((y & 0x00000200) != 0)
y = y | 0xfffffc00;
tx1_c = (y * oldval) >> 8;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XD_TX_AFE);
val32 &= ~0xf0000000;
val32 |= (((tx1_c & 0x3c0) >> 6) << 28);
rtl8xxxu_write32(priv, REG_OFDM0_XD_TX_AFE, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XB_TX_IQ_IMBALANCE);
val32 &= ~0x003f0000;
val32 |= ((tx1_c & 0x3f) << 16);
rtl8xxxu_write32(priv, REG_OFDM0_XB_TX_IQ_IMBALANCE, val32);
val32 = rtl8xxxu_read32(priv, REG_OFDM0_ENERGY_CCA_THRES);
val32 &= ~BIT(25);
if ((y * oldval >> 7) & 0x1)
val32 |= BIT(25);
rtl8xxxu_write32(priv, REG_OFDM0_ENERGY_CCA_THRES, val32);
if (tx_only) {
dev_dbg(&priv->udev->dev, "%s: only TX\n", __func__);
return;
}
reg = result[candidate][6];
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XB_RX_IQ_IMBALANCE);
val32 &= ~0x3ff;
val32 |= (reg & 0x3ff);
rtl8xxxu_write32(priv, REG_OFDM0_XB_RX_IQ_IMBALANCE, val32);
reg = result[candidate][7] & 0x3f;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_XB_RX_IQ_IMBALANCE);
val32 &= ~0xfc00;
val32 |= ((reg << 10) & 0xfc00);
rtl8xxxu_write32(priv, REG_OFDM0_XB_RX_IQ_IMBALANCE, val32);
reg = (result[candidate][7] >> 6) & 0xf;
val32 = rtl8xxxu_read32(priv, REG_OFDM0_AGCR_SSI_TABLE);
val32 &= ~0x0000f000;
val32 |= (reg << 12);
rtl8xxxu_write32(priv, REG_OFDM0_AGCR_SSI_TABLE, val32);
}
static bool rtl8xxxu_simularity_compare(struct rtl8xxxu_priv *priv,
int result[][8], int c1, int c2)
{
u32 i, j, diff, simubitmap, bound = 0;
int candidate[2] = {-1, -1};
bool retval = true;
if (priv->tx_paths > 1)
bound = 8;
else
bound = 4;
simubitmap = 0;
for (i = 0; i < bound; i++) {
diff = (result[c1][i] > result[c2][i]) ?
(result[c1][i] - result[c2][i]) :
(result[c2][i] - result[c1][i]);
if (diff > MAX_TOLERANCE) {
if ((i == 2 || i == 6) && !simubitmap) {
if (result[c1][i] + result[c1][i + 1] == 0)
candidate[(i / 4)] = c2;
else if (result[c2][i] + result[c2][i + 1] == 0)
candidate[(i / 4)] = c1;
else
simubitmap = simubitmap | (1 << i);
} else {
simubitmap = simubitmap | (1 << i);
}
}
}
if (simubitmap == 0) {
for (i = 0; i < (bound / 4); i++) {
if (candidate[i] >= 0) {
for (j = i * 4; j < (i + 1) * 4 - 2; j++)
result[3][j] = result[candidate[i]][j];
retval = false;
}
}
return retval;
} else if (!(simubitmap & 0x0f)) {
for (i = 0; i < 4; i++)
result[3][i] = result[c1][i];
} else if (!(simubitmap & 0xf0) && priv->tx_paths > 1) {
for (i = 4; i < 8; i++)
result[3][i] = result[c1][i];
}
return false;
}
bool rtl8xxxu_gen2_simularity_compare(struct rtl8xxxu_priv *priv,
int result[][8], int c1, int c2)
{
u32 i, j, diff, simubitmap, bound = 0;
int candidate[2] = {-1, -1};
int tmp1, tmp2;
bool retval = true;
if (priv->tx_paths > 1)
bound = 8;
else
bound = 4;
simubitmap = 0;
for (i = 0; i < bound; i++) {
if (i & 1) {
if ((result[c1][i] & 0x00000200))
tmp1 = result[c1][i] | 0xfffffc00;
else
tmp1 = result[c1][i];
if ((result[c2][i]& 0x00000200))
tmp2 = result[c2][i] | 0xfffffc00;
else
tmp2 = result[c2][i];
} else {
tmp1 = result[c1][i];
tmp2 = result[c2][i];
}
diff = (tmp1 > tmp2) ? (tmp1 - tmp2) : (tmp2 - tmp1);
if (diff > MAX_TOLERANCE) {
if ((i == 2 || i == 6) && !simubitmap) {
if (result[c1][i] + result[c1][i + 1] == 0)
candidate[(i / 4)] = c2;
else if (result[c2][i] + result[c2][i + 1] == 0)
candidate[(i / 4)] = c1;
else
simubitmap = simubitmap | (1 << i);
} else {
simubitmap = simubitmap | (1 << i);
}
}
}
if (simubitmap == 0) {
for (i = 0; i < (bound / 4); i++) {
if (candidate[i] >= 0) {
for (j = i * 4; j < (i + 1) * 4 - 2; j++)
result[3][j] = result[candidate[i]][j];
retval = false;
}
}
return retval;
} else {
if (!(simubitmap & 0x03)) {
for (i = 0; i < 2; i++)
result[3][i] = result[c1][i];
}
if (!(simubitmap & 0x0c)) {
for (i = 2; i < 4; i++)
result[3][i] = result[c1][i];
}
if (!(simubitmap & 0x30) && priv->tx_paths > 1) {
for (i = 4; i < 6; i++)
result[3][i] = result[c1][i];
}
if (!(simubitmap & 0x30) && priv->tx_paths > 1) {
for (i = 6; i < 8; i++)
result[3][i] = result[c1][i];
}
}
return false;
}
void
rtl8xxxu_save_mac_regs(struct rtl8xxxu_priv *priv, const u32 *reg, u32 *backup)
{
int i;
for (i = 0; i < (RTL8XXXU_MAC_REGS - 1); i++)
backup[i] = rtl8xxxu_read8(priv, reg[i]);
backup[i] = rtl8xxxu_read32(priv, reg[i]);
}
void rtl8xxxu_restore_mac_regs(struct rtl8xxxu_priv *priv,
const u32 *reg, u32 *backup)
{
int i;
for (i = 0; i < (RTL8XXXU_MAC_REGS - 1); i++)
rtl8xxxu_write8(priv, reg[i], backup[i]);
rtl8xxxu_write32(priv, reg[i], backup[i]);
}
void rtl8xxxu_save_regs(struct rtl8xxxu_priv *priv, const u32 *regs,
u32 *backup, int count)
{
int i;
for (i = 0; i < count; i++)
backup[i] = rtl8xxxu_read32(priv, regs[i]);
}
void rtl8xxxu_restore_regs(struct rtl8xxxu_priv *priv, const u32 *regs,
u32 *backup, int count)
{
int i;
for (i = 0; i < count; i++)
rtl8xxxu_write32(priv, regs[i], backup[i]);
}
void rtl8xxxu_path_adda_on(struct rtl8xxxu_priv *priv, const u32 *regs,
bool path_a_on)
{
u32 path_on;
int i;
if (priv->tx_paths == 1) {
path_on = priv->fops->adda_1t_path_on;
rtl8xxxu_write32(priv, regs[0], priv->fops->adda_1t_init);
} else {
path_on = path_a_on ? priv->fops->adda_2t_path_on_a :
priv->fops->adda_2t_path_on_b;
rtl8xxxu_write32(priv, regs[0], path_on);
}
for (i = 1 ; i < RTL8XXXU_ADDA_REGS ; i++)
rtl8xxxu_write32(priv, regs[i], path_on);
}
void rtl8xxxu_mac_calibration(struct rtl8xxxu_priv *priv,
const u32 *regs, u32 *backup)
{
int i = 0;
rtl8xxxu_write8(priv, regs[i], 0x3f);
for (i = 1 ; i < (RTL8XXXU_MAC_REGS - 1); i++)
rtl8xxxu_write8(priv, regs[i], (u8)(backup[i] & ~BIT(3)));
rtl8xxxu_write8(priv, regs[i], (u8)(backup[i] & ~BIT(5)));
}
static int rtl8xxxu_iqk_path_a(struct rtl8xxxu_priv *priv)
{
u32 reg_eac, reg_e94, reg_e9c, reg_ea4, val32;
int result = 0;
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x10008c1f);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x10008c1f);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_A, 0x82140102);
val32 = (priv->rf_paths > 1) ? 0x28160202 :
0x28160502;
rtl8xxxu_write32(priv, REG_RX_IQK_PI_A, val32);
if (priv->rf_paths > 1) {
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_B, 0x10008c22);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_B, 0x10008c22);
rtl8xxxu_write32(priv, REG_TX_IQK_PI_B, 0x82140102);
rtl8xxxu_write32(priv, REG_RX_IQK_PI_B, 0x28160202);
}
rtl8xxxu_write32(priv, REG_IQK_AGC_RSP, 0x001028d1);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf9000000);
rtl8xxxu_write32(priv, REG_IQK_AGC_PTS, 0xf8000000);
mdelay(1);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_e94 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_A);
reg_e9c = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_A);
reg_ea4 = rtl8xxxu_read32(priv, REG_RX_POWER_BEFORE_IQK_A_2);
if (!(reg_eac & BIT(28)) &&
((reg_e94 & 0x03ff0000) != 0x01420000) &&
((reg_e9c & 0x03ff0000) != 0x00420000))
result |= 0x01;
else
goto out;
if (!(reg_eac & BIT(27)) &&
((reg_ea4 & 0x03ff0000) != 0x01320000) &&
((reg_eac & 0x03ff0000) != 0x00360000))
result |= 0x02;
else
dev_warn(&priv->udev->dev, "%s: Path A RX IQK failed!\n",
__func__);
out:
return result;
}
static int rtl8xxxu_iqk_path_b(struct rtl8xxxu_priv *priv)
{
u32 reg_eac, reg_eb4, reg_ebc, reg_ec4, reg_ecc;
int result = 0;
rtl8xxxu_write32(priv, REG_IQK_AGC_CONT, 0x00000002);
rtl8xxxu_write32(priv, REG_IQK_AGC_CONT, 0x00000000);
mdelay(1);
reg_eac = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_A_2);
reg_eb4 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_B);
reg_ebc = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_B);
reg_ec4 = rtl8xxxu_read32(priv, REG_RX_POWER_BEFORE_IQK_B_2);
reg_ecc = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_B_2);
if (!(reg_eac & BIT(31)) &&
((reg_eb4 & 0x03ff0000) != 0x01420000) &&
((reg_ebc & 0x03ff0000) != 0x00420000))
result |= 0x01;
else
goto out;
if (!(reg_eac & BIT(30)) &&
(((reg_ec4 & 0x03ff0000) >> 16) != 0x132) &&
(((reg_ecc & 0x03ff0000) >> 16) != 0x36))
result |= 0x02;
else
dev_warn(&priv->udev->dev, "%s: Path B RX IQK failed!\n",
__func__);
out:
return result;
}
static void rtl8xxxu_phy_iqcalibrate(struct rtl8xxxu_priv *priv,
int result[][8], int t)
{
struct device *dev = &priv->udev->dev;
u32 i, val32;
int path_a_ok, path_b_ok;
int retry = 2;
const u32 adda_regs[RTL8XXXU_ADDA_REGS] = {
REG_FPGA0_XCD_SWITCH_CTRL, REG_BLUETOOTH,
REG_RX_WAIT_CCA, REG_TX_CCK_RFON,
REG_TX_CCK_BBON, REG_TX_OFDM_RFON,
REG_TX_OFDM_BBON, REG_TX_TO_RX,
REG_TX_TO_TX, REG_RX_CCK,
REG_RX_OFDM, REG_RX_WAIT_RIFS,
REG_RX_TO_RX, REG_STANDBY,
REG_SLEEP, REG_PMPD_ANAEN
};
const u32 iqk_mac_regs[RTL8XXXU_MAC_REGS] = {
REG_TXPAUSE, REG_BEACON_CTRL,
REG_BEACON_CTRL_1, REG_GPIO_MUXCFG
};
const u32 iqk_bb_regs[RTL8XXXU_BB_REGS] = {
REG_OFDM0_TRX_PATH_ENABLE, REG_OFDM0_TR_MUX_PAR,
REG_FPGA0_XCD_RF_SW_CTRL, REG_CONFIG_ANT_A, REG_CONFIG_ANT_B,
REG_FPGA0_XAB_RF_SW_CTRL, REG_FPGA0_XA_RF_INT_OE,
REG_FPGA0_XB_RF_INT_OE, REG_FPGA0_RF_MODE
};
if (t == 0) {
rtl8xxxu_save_regs(priv, adda_regs, priv->adda_backup,
RTL8XXXU_ADDA_REGS);
rtl8xxxu_save_mac_regs(priv, iqk_mac_regs, priv->mac_backup);
rtl8xxxu_save_regs(priv, iqk_bb_regs,
priv->bb_backup, RTL8XXXU_BB_REGS);
}
rtl8xxxu_path_adda_on(priv, adda_regs, true);
if (t == 0) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XA_HSSI_PARM1);
if (val32 & FPGA0_HSSI_PARM1_PI)
priv->pi_enabled = 1;
}
if (!priv->pi_enabled) {
rtl8xxxu_write32(priv, REG_FPGA0_XA_HSSI_PARM1, 0x01000100);
rtl8xxxu_write32(priv, REG_FPGA0_XB_HSSI_PARM1, 0x01000100);
}
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
val32 &= ~FPGA_RF_MODE_CCK;
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
rtl8xxxu_write32(priv, REG_OFDM0_TRX_PATH_ENABLE, 0x03a05600);
rtl8xxxu_write32(priv, REG_OFDM0_TR_MUX_PAR, 0x000800e4);
rtl8xxxu_write32(priv, REG_FPGA0_XCD_RF_SW_CTRL, 0x22204000);
if (!priv->no_pape) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XAB_RF_SW_CTRL);
val32 |= (FPGA0_RF_PAPE |
(FPGA0_RF_PAPE << FPGA0_RF_BD_CTRL_SHIFT));
rtl8xxxu_write32(priv, REG_FPGA0_XAB_RF_SW_CTRL, val32);
}
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XA_RF_INT_OE);
val32 &= ~BIT(10);
rtl8xxxu_write32(priv, REG_FPGA0_XA_RF_INT_OE, val32);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XB_RF_INT_OE);
val32 &= ~BIT(10);
rtl8xxxu_write32(priv, REG_FPGA0_XB_RF_INT_OE, val32);
if (priv->tx_paths > 1) {
rtl8xxxu_write32(priv, REG_FPGA0_XA_LSSI_PARM, 0x00010000);
rtl8xxxu_write32(priv, REG_FPGA0_XB_LSSI_PARM, 0x00010000);
}
rtl8xxxu_mac_calibration(priv, iqk_mac_regs, priv->mac_backup);
rtl8xxxu_write32(priv, REG_CONFIG_ANT_A, 0x00080000);
if (priv->tx_paths > 1)
rtl8xxxu_write32(priv, REG_CONFIG_ANT_B, 0x00080000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_write32(priv, REG_TX_IQK, 0x01007c00);
rtl8xxxu_write32(priv, REG_RX_IQK, 0x01004800);
for (i = 0; i < retry; i++) {
path_a_ok = rtl8xxxu_iqk_path_a(priv);
if (path_a_ok == 0x03) {
val32 = rtl8xxxu_read32(priv,
REG_TX_POWER_BEFORE_IQK_A);
result[t][0] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv,
REG_TX_POWER_AFTER_IQK_A);
result[t][1] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv,
REG_RX_POWER_BEFORE_IQK_A_2);
result[t][2] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv,
REG_RX_POWER_AFTER_IQK_A_2);
result[t][3] = (val32 >> 16) & 0x3ff;
break;
} else if (i == (retry - 1) && path_a_ok == 0x01) {
dev_dbg(dev, "%s: Path A IQK Only Tx Success!!\n",
__func__);
val32 = rtl8xxxu_read32(priv,
REG_TX_POWER_BEFORE_IQK_A);
result[t][0] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv,
REG_TX_POWER_AFTER_IQK_A);
result[t][1] = (val32 >> 16) & 0x3ff;
}
}
if (!path_a_ok)
dev_dbg(dev, "%s: Path A IQK failed!\n", __func__);
if (priv->tx_paths > 1) {
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x0);
rtl8xxxu_write32(priv, REG_FPGA0_XA_LSSI_PARM, 0x00010000);
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0x80800000);
rtl8xxxu_path_adda_on(priv, adda_regs, false);
for (i = 0; i < retry; i++) {
path_b_ok = rtl8xxxu_iqk_path_b(priv);
if (path_b_ok == 0x03) {
val32 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_B);
result[t][4] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_B);
result[t][5] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv, REG_RX_POWER_BEFORE_IQK_B_2);
result[t][6] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv, REG_RX_POWER_AFTER_IQK_B_2);
result[t][7] = (val32 >> 16) & 0x3ff;
break;
} else if (i == (retry - 1) && path_b_ok == 0x01) {
val32 = rtl8xxxu_read32(priv, REG_TX_POWER_BEFORE_IQK_B);
result[t][4] = (val32 >> 16) & 0x3ff;
val32 = rtl8xxxu_read32(priv, REG_TX_POWER_AFTER_IQK_B);
result[t][5] = (val32 >> 16) & 0x3ff;
}
}
if (!path_b_ok)
dev_dbg(dev, "%s: Path B IQK failed!\n", __func__);
}
rtl8xxxu_write32(priv, REG_FPGA0_IQK, 0);
if (t) {
if (!priv->pi_enabled) {
val32 = 0x01000000;
rtl8xxxu_write32(priv, REG_FPGA0_XA_HSSI_PARM1, val32);
rtl8xxxu_write32(priv, REG_FPGA0_XB_HSSI_PARM1, val32);
}
rtl8xxxu_restore_regs(priv, adda_regs, priv->adda_backup,
RTL8XXXU_ADDA_REGS);
rtl8xxxu_restore_mac_regs(priv, iqk_mac_regs, priv->mac_backup);
rtl8xxxu_restore_regs(priv, iqk_bb_regs,
priv->bb_backup, RTL8XXXU_BB_REGS);
rtl8xxxu_write32(priv, REG_FPGA0_XA_LSSI_PARM, 0x00032ed3);
if (priv->tx_paths > 1) {
rtl8xxxu_write32(priv, REG_FPGA0_XB_LSSI_PARM,
0x00032ed3);
}
rtl8xxxu_write32(priv, REG_TX_IQK_TONE_A, 0x01008c00);
rtl8xxxu_write32(priv, REG_RX_IQK_TONE_A, 0x01008c00);
}
}
void rtl8xxxu_gen2_prepare_calibrate(struct rtl8xxxu_priv *priv, u8 start)
{
struct h2c_cmd h2c;
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.bt_wlan_calibration.cmd = H2C_8723B_BT_WLAN_CALIBRATION;
h2c.bt_wlan_calibration.data = start;
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.bt_wlan_calibration));
}
void rtl8xxxu_gen1_phy_iq_calibrate(struct rtl8xxxu_priv *priv)
{
struct device *dev = &priv->udev->dev;
int result[4][8];
int i, candidate;
bool path_a_ok, path_b_ok;
u32 reg_e94, reg_e9c, reg_ea4, reg_eac;
u32 reg_eb4, reg_ebc, reg_ec4, reg_ecc;
s32 reg_tmp = 0;
bool simu;
memset(result, 0, sizeof(result));
candidate = -1;
path_a_ok = false;
path_b_ok = false;
rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
for (i = 0; i < 3; i++) {
rtl8xxxu_phy_iqcalibrate(priv, result, i);
if (i == 1) {
simu = rtl8xxxu_simularity_compare(priv, result, 0, 1);
if (simu) {
candidate = 0;
break;
}
}
if (i == 2) {
simu = rtl8xxxu_simularity_compare(priv, result, 0, 2);
if (simu) {
candidate = 0;
break;
}
simu = rtl8xxxu_simularity_compare(priv, result, 1, 2);
if (simu) {
candidate = 1;
} else {
for (i = 0; i < 8; i++)
reg_tmp += result[3][i];
if (reg_tmp)
candidate = 3;
else
candidate = -1;
}
}
}
for (i = 0; i < 4; i++) {
reg_e94 = result[i][0];
reg_e9c = result[i][1];
reg_ea4 = result[i][2];
reg_eac = result[i][3];
reg_eb4 = result[i][4];
reg_ebc = result[i][5];
reg_ec4 = result[i][6];
reg_ecc = result[i][7];
}
if (candidate >= 0) {
reg_e94 = result[candidate][0];
priv->rege94 = reg_e94;
reg_e9c = result[candidate][1];
priv->rege9c = reg_e9c;
reg_ea4 = result[candidate][2];
reg_eac = result[candidate][3];
reg_eb4 = result[candidate][4];
priv->regeb4 = reg_eb4;
reg_ebc = result[candidate][5];
priv->regebc = reg_ebc;
reg_ec4 = result[candidate][6];
reg_ecc = result[candidate][7];
dev_dbg(dev, "%s: candidate is %x\n", __func__, candidate);
dev_dbg(dev,
"%s: e94 =%x e9c=%x ea4=%x eac=%x eb4=%x ebc=%x ec4=%x "
"ecc=%x\n ", __func__, reg_e94, reg_e9c,
reg_ea4, reg_eac, reg_eb4, reg_ebc, reg_ec4, reg_ecc);
path_a_ok = true;
path_b_ok = true;
} else {
reg_e94 = reg_eb4 = priv->rege94 = priv->regeb4 = 0x100;
reg_e9c = reg_ebc = priv->rege9c = priv->regebc = 0x0;
}
if (reg_e94 && candidate >= 0)
rtl8xxxu_fill_iqk_matrix_a(priv, path_a_ok, result,
candidate, (reg_ea4 == 0));
if (priv->tx_paths > 1 && reg_eb4)
rtl8xxxu_fill_iqk_matrix_b(priv, path_b_ok, result,
candidate, (reg_ec4 == 0));
rtl8xxxu_save_regs(priv, rtl8xxxu_iqk_phy_iq_bb_reg,
priv->bb_recovery_backup, RTL8XXXU_BB_REGS);
}
static void rtl8723a_phy_lc_calibrate(struct rtl8xxxu_priv *priv)
{
u32 val32;
u32 rf_amode, rf_bmode = 0, lstf;
lstf = rtl8xxxu_read32(priv, REG_OFDM1_LSTF);
if (lstf & OFDM_LSTF_MASK) {
val32 = lstf & ~OFDM_LSTF_MASK;
rtl8xxxu_write32(priv, REG_OFDM1_LSTF, val32);
rf_amode = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_AC);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_AC,
(rf_amode & 0x8ffff) | 0x10000);
if (priv->tx_paths > 1) {
rf_bmode = rtl8xxxu_read_rfreg(priv, RF_B,
RF6052_REG_AC);
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_AC,
(rf_bmode & 0x8ffff) | 0x10000);
}
} else {
rtl8xxxu_write8(priv, REG_TXPAUSE, 0xff);
}
if (priv->fops->has_s0s1)
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_S0S1, 0xdfbe0);
val32 = rtl8xxxu_read_rfreg(priv, RF_A, RF6052_REG_MODE_AG);
val32 |= 0x08000;
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_MODE_AG, val32);
msleep(100);
if (priv->fops->has_s0s1)
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_S0S1, 0xdffe0);
if (lstf & OFDM_LSTF_MASK) {
rtl8xxxu_write32(priv, REG_OFDM1_LSTF, lstf);
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_AC, rf_amode);
if (priv->tx_paths > 1)
rtl8xxxu_write_rfreg(priv, RF_B, RF6052_REG_AC,
rf_bmode);
} else
rtl8xxxu_write8(priv, REG_TXPAUSE, 0x00);
}
static int rtl8xxxu_set_mac(struct rtl8xxxu_priv *priv)
{
int i;
u16 reg;
reg = REG_MACID;
for (i = 0; i < ETH_ALEN; i++)
rtl8xxxu_write8(priv, reg + i, priv->mac_addr[i]);
return 0;
}
static int rtl8xxxu_set_bssid(struct rtl8xxxu_priv *priv, const u8 *bssid)
{
int i;
u16 reg;
dev_dbg(&priv->udev->dev, "%s: (%pM)\n", __func__, bssid);
reg = REG_BSSID;
for (i = 0; i < ETH_ALEN; i++)
rtl8xxxu_write8(priv, reg + i, bssid[i]);
return 0;
}
static void
rtl8xxxu_set_ampdu_factor(struct rtl8xxxu_priv *priv, u8 ampdu_factor)
{
u8 vals[4] = { 0x41, 0xa8, 0x72, 0xb9 };
u8 max_agg = 0xf;
int i;
ampdu_factor = 1 << (ampdu_factor + 2);
if (ampdu_factor > max_agg)
ampdu_factor = max_agg;
for (i = 0; i < 4; i++) {
if ((vals[i] & 0xf0) > (ampdu_factor << 4))
vals[i] = (vals[i] & 0x0f) | (ampdu_factor << 4);
if ((vals[i] & 0x0f) > ampdu_factor)
vals[i] = (vals[i] & 0xf0) | ampdu_factor;
rtl8xxxu_write8(priv, REG_AGGLEN_LMT + i, vals[i]);
}
}
static void rtl8xxxu_set_ampdu_min_space(struct rtl8xxxu_priv *priv, u8 density)
{
u8 val8;
val8 = rtl8xxxu_read8(priv, REG_AMPDU_MIN_SPACE);
val8 &= 0xf8;
val8 |= density;
rtl8xxxu_write8(priv, REG_AMPDU_MIN_SPACE, val8);
}
static int rtl8xxxu_active_to_emu(struct rtl8xxxu_priv *priv)
{
u8 val8;
int count, ret = 0;
rtl8xxxu_write8(priv, REG_RF_CTRL, 0);
val8 = rtl8xxxu_read8(priv, REG_LEDCFG2);
val8 &= ~LEDCFG2_DPDT_SELECT;
rtl8xxxu_write8(priv, REG_LEDCFG2, val8);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 |= BIT(1);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
for (count = RTL8XXXU_MAX_REG_POLL; count; count--) {
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
if ((val8 & BIT(1)) == 0)
break;
udelay(10);
}
if (!count) {
dev_warn(&priv->udev->dev, "%s: Disabling MAC timed out\n",
__func__);
ret = -EBUSY;
goto exit;
}
val8 = rtl8xxxu_read8(priv, REG_SYS_ISO_CTRL);
val8 |= SYS_ISO_ANALOG_IPS;
rtl8xxxu_write8(priv, REG_SYS_ISO_CTRL, val8);
val8 = rtl8xxxu_read8(priv, REG_LDOA15_CTRL);
val8 &= ~LDOA15_ENABLE;
rtl8xxxu_write8(priv, REG_LDOA15_CTRL, val8);
exit:
return ret;
}
int rtl8xxxu_active_to_lps(struct rtl8xxxu_priv *priv)
{
u8 val8;
u8 val32;
int count, ret = 0;
rtl8xxxu_write8(priv, REG_TXPAUSE, 0xff);
for (count = RTL8XXXU_MAX_REG_POLL; count; count--) {
val32 = rtl8xxxu_read32(priv, 0x5f8);
if (!val32)
break;
udelay(10);
}
if (!count) {
dev_warn(&priv->udev->dev,
"%s: RX poll timed out (0x05f8)\n", __func__);
ret = -EBUSY;
goto exit;
}
val8 = rtl8xxxu_read8(priv, REG_SYS_FUNC);
val8 &= ~SYS_FUNC_BBRSTB;
rtl8xxxu_write8(priv, REG_SYS_FUNC, val8);
udelay(2);
val8 = rtl8xxxu_read8(priv, REG_SYS_FUNC);
val8 &= ~SYS_FUNC_BB_GLB_RSTN;
rtl8xxxu_write8(priv, REG_SYS_FUNC, val8);
val8 = rtl8xxxu_read8(priv, REG_CR);
val8 = CR_HCI_TXDMA_ENABLE | CR_HCI_RXDMA_ENABLE;
rtl8xxxu_write8(priv, REG_CR, val8);
val8 = rtl8xxxu_read8(priv, REG_CR + 1);
val8 &= ~BIT(1);
rtl8xxxu_write8(priv, REG_CR + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_DUAL_TSF_RST);
val8 |= DUAL_TSF_TX_OK;
rtl8xxxu_write8(priv, REG_DUAL_TSF_RST, val8);
exit:
return ret;
}
void rtl8xxxu_disabled_to_emu(struct rtl8xxxu_priv *priv)
{
u8 val8;
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~(BIT(3) | BIT(7));
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_GPIO_INTM + 2);
val8 &= ~BIT(0);
rtl8xxxu_write8(priv, REG_GPIO_INTM + 2, val8);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~(BIT(3) | BIT(4));
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
}
static int rtl8xxxu_emu_to_disabled(struct rtl8xxxu_priv *priv)
{
u8 val8;
rtl8xxxu_write8(priv, REG_APS_FSMCO + 3, 0x20);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 &= ~BIT(4);
val8 |= BIT(3);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_APS_FSMCO + 1);
val8 |= BIT(7);
rtl8xxxu_write8(priv, REG_APS_FSMCO + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_GPIO_INTM + 2);
val8 |= BIT(0);
rtl8xxxu_write8(priv, REG_GPIO_INTM + 2, val8);
return 0;
}
int rtl8xxxu_flush_fifo(struct rtl8xxxu_priv *priv)
{
struct device *dev = &priv->udev->dev;
u32 val32;
int retry, retval;
rtl8xxxu_write8(priv, REG_TXPAUSE, 0xff);
val32 = rtl8xxxu_read32(priv, REG_RXPKT_NUM);
val32 |= RXPKT_NUM_RW_RELEASE_EN;
rtl8xxxu_write32(priv, REG_RXPKT_NUM, val32);
retry = 100;
retval = -EBUSY;
do {
val32 = rtl8xxxu_read32(priv, REG_RXPKT_NUM);
if (val32 & RXPKT_NUM_RXDMA_IDLE) {
retval = 0;
break;
}
} while (retry--);
rtl8xxxu_write16(priv, REG_RQPN_NPQ, 0);
rtl8xxxu_write32(priv, REG_RQPN, 0x80000000);
mdelay(2);
if (!retry)
dev_warn(dev, "Failed to flush FIFO\n");
return retval;
}
void rtl8xxxu_gen1_usb_quirks(struct rtl8xxxu_priv *priv)
{
rtl8xxxu_write8(priv, 0xfe40, 0xe0);
rtl8xxxu_write8(priv, 0xfe41, 0x8d);
rtl8xxxu_write8(priv, 0xfe42, 0x80);
rtl8xxxu_write32(priv, REG_TXDMA_OFFSET_CHK, 0xfd0320);
if (!(!priv->chip_cut && priv->vendor_umc)) {
rtl8xxxu_write8(priv, 0xfe40, 0xe6);
rtl8xxxu_write8(priv, 0xfe41, 0x94);
rtl8xxxu_write8(priv, 0xfe42, 0x80);
rtl8xxxu_write8(priv, 0xfe40, 0xe0);
rtl8xxxu_write8(priv, 0xfe41, 0x19);
rtl8xxxu_write8(priv, 0xfe42, 0x80);
rtl8xxxu_write8(priv, 0xfe40, 0xe5);
rtl8xxxu_write8(priv, 0xfe41, 0x91);
rtl8xxxu_write8(priv, 0xfe42, 0x80);
rtl8xxxu_write8(priv, 0xfe40, 0xe2);
rtl8xxxu_write8(priv, 0xfe41, 0x81);
rtl8xxxu_write8(priv, 0xfe42, 0x80);
}
}
void rtl8xxxu_gen2_usb_quirks(struct rtl8xxxu_priv *priv)
{
u32 val32;
val32 = rtl8xxxu_read32(priv, REG_TXDMA_OFFSET_CHK);
val32 |= TXDMA_OFFSET_DROP_DATA_EN;
rtl8xxxu_write32(priv, REG_TXDMA_OFFSET_CHK, val32);
}
void rtl8xxxu_power_off(struct rtl8xxxu_priv *priv)
{
u8 val8;
u16 val16;
u32 val32;
if (priv->rtl_chip == RTL8188R) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_XCD_RF_PARM);
val32 |= BIT(1);
rtl8xxxu_write32(priv, REG_FPGA0_XCD_RF_PARM, val32);
}
rtl8xxxu_flush_fifo(priv);
rtl8xxxu_active_to_lps(priv);
rtl8xxxu_write8(priv, REG_RF_CTRL, 0x00);
if (rtl8xxxu_read8(priv, REG_MCU_FW_DL) & MCU_FW_RAM_SEL)
rtl8xxxu_firmware_self_reset(priv);
val16 = rtl8xxxu_read16(priv, REG_SYS_FUNC);
val16 &= ~SYS_FUNC_CPU_ENABLE;
rtl8xxxu_write16(priv, REG_SYS_FUNC, val16);
rtl8xxxu_write8(priv, REG_MCU_FW_DL, 0x00);
rtl8xxxu_active_to_emu(priv);
rtl8xxxu_emu_to_disabled(priv);
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL + 1);
val8 &= ~BIT(0);
rtl8xxxu_write8(priv, REG_RSV_CTRL + 1, val8);
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL + 1);
val8 |= BIT(0);
rtl8xxxu_write8(priv, REG_RSV_CTRL + 1, val8);
rtl8xxxu_write8(priv, REG_RSV_CTRL, 0x0e);
}
static void rtl8723bu_set_ps_tdma(struct rtl8xxxu_priv *priv,
u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5)
{
struct h2c_cmd h2c;
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.b_type_dma.cmd = H2C_8723B_B_TYPE_TDMA;
h2c.b_type_dma.data1 = arg1;
h2c.b_type_dma.data2 = arg2;
h2c.b_type_dma.data3 = arg3;
h2c.b_type_dma.data4 = arg4;
h2c.b_type_dma.data5 = arg5;
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.b_type_dma));
}
void rtl8xxxu_gen2_disable_rf(struct rtl8xxxu_priv *priv)
{
u32 val32;
val32 = rtl8xxxu_read32(priv, REG_RX_WAIT_CCA);
val32 &= ~(BIT(22) | BIT(23));
rtl8xxxu_write32(priv, REG_RX_WAIT_CCA, val32);
}
static void rtl8xxxu_init_queue_reserved_page(struct rtl8xxxu_priv *priv)
{
struct rtl8xxxu_fileops *fops = priv->fops;
u32 hq, lq, nq, eq, pubq;
u32 val32;
hq = 0;
lq = 0;
nq = 0;
eq = 0;
pubq = 0;
if (priv->ep_tx_high_queue)
hq = fops->page_num_hi;
if (priv->ep_tx_low_queue)
lq = fops->page_num_lo;
if (priv->ep_tx_normal_queue)
nq = fops->page_num_norm;
val32 = (nq << RQPN_NPQ_SHIFT) | (eq << RQPN_EPQ_SHIFT);
rtl8xxxu_write32(priv, REG_RQPN_NPQ, val32);
pubq = fops->total_page_num - hq - lq - nq - 1;
val32 = RQPN_LOAD;
val32 |= (hq << RQPN_HI_PQ_SHIFT);
val32 |= (lq << RQPN_LO_PQ_SHIFT);
val32 |= (pubq << RQPN_PUB_PQ_SHIFT);
rtl8xxxu_write32(priv, REG_RQPN, val32);
}
static int rtl8xxxu_init_device(struct ieee80211_hw *hw)
{
struct rtl8xxxu_priv *priv = hw->priv;
struct device *dev = &priv->udev->dev;
struct rtl8xxxu_fileops *fops = priv->fops;
bool macpower;
int ret;
u8 val8;
u16 val16;
u32 val32;
val8 = rtl8xxxu_read8(priv, REG_CR);
if (val8 == 0xea)
macpower = false;
else
macpower = true;
ret = fops->power_on(priv);
if (ret < 0) {
dev_warn(dev, "%s: Failed power on\n", __func__);
goto exit;
}
if (!macpower)
rtl8xxxu_init_queue_reserved_page(priv);
ret = rtl8xxxu_init_queue_priority(priv);
dev_dbg(dev, "%s: init_queue_priority %i\n", __func__, ret);
if (ret)
goto exit;
rtl8xxxu_write16(priv, REG_TRXFF_BNDY + 2, fops->trxff_boundary);
ret = rtl8xxxu_download_firmware(priv);
dev_dbg(dev, "%s: download_firmware %i\n", __func__, ret);
if (ret)
goto exit;
ret = rtl8xxxu_start_firmware(priv);
dev_dbg(dev, "%s: start_firmware %i\n", __func__, ret);
if (ret)
goto exit;
if (fops->phy_init_antenna_selection)
fops->phy_init_antenna_selection(priv);
ret = rtl8xxxu_init_mac(priv);
dev_dbg(dev, "%s: init_mac %i\n", __func__, ret);
if (ret)
goto exit;
ret = rtl8xxxu_init_phy_bb(priv);
dev_dbg(dev, "%s: init_phy_bb %i\n", __func__, ret);
if (ret)
goto exit;
ret = fops->init_phy_rf(priv);
if (ret)
goto exit;
if (priv->rtl_chip != RTL8723B && priv->rtl_chip != RTL8192E)
rtl8xxxu_write32(priv, REG_FPGA0_TX_INFO, 0x00000003);
val32 = FPGA0_RF_TRSW | FPGA0_RF_TRSWB | FPGA0_RF_ANTSW |
FPGA0_RF_ANTSWB |
((FPGA0_RF_ANTSW | FPGA0_RF_ANTSWB) << FPGA0_RF_BD_CTRL_SHIFT);
if (!priv->no_pape) {
val32 |= (FPGA0_RF_PAPE |
(FPGA0_RF_PAPE << FPGA0_RF_BD_CTRL_SHIFT));
}
rtl8xxxu_write32(priv, REG_FPGA0_XAB_RF_SW_CTRL, val32);
if (priv->rtl_chip != RTL8192E)
rtl8xxxu_write32(priv, REG_FPGA0_XA_RF_INT_OE, 0x66f60210);
if (!macpower) {
val8 = fops->total_page_num + 1;
rtl8xxxu_write8(priv, REG_TXPKTBUF_BCNQ_BDNY, val8);
rtl8xxxu_write8(priv, REG_TXPKTBUF_MGQ_BDNY, val8);
rtl8xxxu_write8(priv, REG_TXPKTBUF_WMAC_LBK_BF_HD, val8);
rtl8xxxu_write8(priv, REG_TRXFF_BNDY, val8);
rtl8xxxu_write8(priv, REG_TDECTRL + 1, val8);
}
val8 = (fops->pbp_rx << PBP_PAGE_SIZE_RX_SHIFT) |
(fops->pbp_tx << PBP_PAGE_SIZE_TX_SHIFT);
if (priv->rtl_chip != RTL8192E)
rtl8xxxu_write8(priv, REG_PBP, val8);
dev_dbg(dev, "%s: macpower %i\n", __func__, macpower);
if (!macpower) {
ret = fops->llt_init(priv);
if (ret) {
dev_warn(dev, "%s: LLT table init failed\n", __func__);
goto exit;
}
fops->usb_quirks(priv);
if (fops->has_tx_report) {
val8 = rtl8xxxu_read8(priv, REG_TX_REPORT_CTRL);
val8 |= TX_REPORT_CTRL_TIMER_ENABLE;
rtl8xxxu_write8(priv, REG_TX_REPORT_CTRL, val8);
rtl8xxxu_write8(priv, REG_TX_REPORT_CTRL + 1, 0x02);
rtl8xxxu_write16(priv, REG_TX_REPORT_TIME, 0xcdf0);
val8 = rtl8xxxu_read8(priv, 0xa3);
val8 &= 0xf8;
rtl8xxxu_write8(priv, 0xa3, val8);
}
}
rtl8xxxu_write8(priv, REG_RX_DRVINFO_SZ, 4);
if (priv->rtl_chip == RTL8192E) {
rtl8xxxu_write32(priv, REG_HIMR0, 0x00);
rtl8xxxu_write32(priv, REG_HIMR1, 0x00);
} else {
rtl8xxxu_write32(priv, REG_HISR, 0xffffffff);
rtl8xxxu_write32(priv, REG_HIMR, 0xffffffff);
}
rtl8xxxu_set_mac(priv);
rtl8xxxu_set_linktype(priv, NL80211_IFTYPE_STATION);
val32 = RCR_ACCEPT_PHYS_MATCH | RCR_ACCEPT_MCAST | RCR_ACCEPT_BCAST |
RCR_ACCEPT_MGMT_FRAME | RCR_HTC_LOC_CTRL |
RCR_APPEND_PHYSTAT | RCR_APPEND_ICV | RCR_APPEND_MIC;
rtl8xxxu_write32(priv, REG_RCR, val32);
rtl8xxxu_write32(priv, REG_MAR, 0xffffffff);
rtl8xxxu_write32(priv, REG_MAR + 4, 0xffffffff);
val32 = rtl8xxxu_read32(priv, REG_RESPONSE_RATE_SET);
val32 &= ~RESPONSE_RATE_BITMAP_ALL;
val32 |= RESPONSE_RATE_RRSR_CCK_ONLY_1M;
rtl8xxxu_write32(priv, REG_RESPONSE_RATE_SET, val32);
rtl8xxxu_set_spec_sifs(priv, 0x10, 0x10);
rtl8xxxu_set_retry(priv, 0x30, 0x30);
rtl8xxxu_set_spec_sifs(priv, 0x0a, 0x10);
rtl8xxxu_write16(priv, REG_MAC_SPEC_SIFS, 0x100a);
rtl8xxxu_write16(priv, REG_SIFS_CCK, 0x100a);
rtl8xxxu_write16(priv, REG_SIFS_OFDM, 0x100a);
rtl8xxxu_write32(priv, REG_EDCA_BE_PARAM, 0x005ea42b);
rtl8xxxu_write32(priv, REG_EDCA_BK_PARAM, 0x0000a44f);
rtl8xxxu_write32(priv, REG_EDCA_VI_PARAM, 0x005ea324);
rtl8xxxu_write32(priv, REG_EDCA_VO_PARAM, 0x002fa226);
rtl8xxxu_write32(priv, REG_DARFRC, 0x00000000);
rtl8xxxu_write32(priv, REG_DARFRC + 4, 0x10080404);
rtl8xxxu_write32(priv, REG_RARFRC, 0x04030201);
rtl8xxxu_write32(priv, REG_RARFRC + 4, 0x08070605);
val8 = rtl8xxxu_read8(priv, REG_FWHW_TXQ_CTRL);
val8 |= FWHW_TXQ_CTRL_AMPDU_RETRY;
rtl8xxxu_write8(priv, REG_FWHW_TXQ_CTRL, val8);
rtl8xxxu_write8(priv, REG_ACKTO, 0x40);
val16 = BEACON_DISABLE_TSF_UPDATE | (BEACON_DISABLE_TSF_UPDATE << 8);
rtl8xxxu_write16(priv, REG_BEACON_CTRL, val16);
rtl8xxxu_write16(priv, REG_TBTT_PROHIBIT, 0x6404);
rtl8xxxu_write8(priv, REG_DRIVER_EARLY_INT, DRIVER_EARLY_INT_TIME);
rtl8xxxu_write8(priv, REG_BEACON_DMA_TIME, BEACON_DMA_ATIME_INT_TIME);
rtl8xxxu_write16(priv, REG_BEACON_TCFG, 0x660F);
if (priv->rtl_chip == RTL8723B) {
val8 = rtl8xxxu_read8(priv, REG_RXDMA_PRO_8723B);
val8 &= ~(BIT(4) | BIT(5));
val8 |= BIT(4);
val8 |= BIT(1) | BIT(2) | BIT(3);
rtl8xxxu_write8(priv, REG_RXDMA_PRO_8723B, val8);
val8 = rtl8xxxu_read8(priv, REG_HT_SINGLE_AMPDU_8723B);
val8 |= BIT(7);
rtl8xxxu_write8(priv, REG_HT_SINGLE_AMPDU_8723B, val8);
rtl8xxxu_write16(priv, REG_MAX_AGGR_NUM, 0x0c14);
rtl8xxxu_write8(priv, REG_AMPDU_MAX_TIME_8723B, 0x5e);
rtl8xxxu_write32(priv, REG_AGGLEN_LMT, 0xffffffff);
rtl8xxxu_write8(priv, REG_RX_PKT_LIMIT, 0x18);
rtl8xxxu_write8(priv, REG_PIFS, 0x00);
rtl8xxxu_write8(priv, REG_USTIME_TSF_8723B, 0x50);
rtl8xxxu_write8(priv, REG_USTIME_EDCA, 0x50);
val8 = rtl8xxxu_read8(priv, REG_RSV_CTRL);
val8 |= BIT(5) | BIT(6);
rtl8xxxu_write8(priv, REG_RSV_CTRL, val8);
}
if (fops->init_aggregation)
fops->init_aggregation(priv);
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
val32 |= (FPGA_RF_MODE_CCK | FPGA_RF_MODE_OFDM);
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
rtl8xxxu_write32(priv, REG_CAM_CMD, CAM_CMD_POLLING | BIT(30));
fops->set_tx_power(priv, 1, false);
if (priv->rtl_chip != RTL8192E) {
val8 = rtl8xxxu_read8(priv, REG_LEDCFG2);
val8 |= LEDCFG2_DPDT_SELECT;
rtl8xxxu_write8(priv, REG_LEDCFG2, val8);
}
rtl8xxxu_write8(priv, REG_HWSEQ_CTRL, 0xff);
rtl8xxxu_write32(priv, REG_BAR_MODE_CTRL, 0x0201ffff);
rtl8xxxu_write16(priv, REG_FAST_EDCA_CTRL, 0);
if (fops->init_statistics)
fops->init_statistics(priv);
if (priv->rtl_chip == RTL8192E) {
val8 = rtl8xxxu_read8(priv, REG_QUEUE_CTRL);
val8 &= ~BIT(3);
rtl8xxxu_write8(priv, REG_QUEUE_CTRL, val8);
rtl8xxxu_write8(priv, REG_ACLK_MON, 0x00);
}
rtl8723a_phy_lc_calibrate(priv);
fops->phy_iq_calibrate(priv);
if (fops->gen2_thermal_meter)
rtl8xxxu_write_rfreg(priv,
RF_A, RF6052_REG_T_METER_8723B, 0x37cf8);
else
rtl8xxxu_write_rfreg(priv, RF_A, RF6052_REG_T_METER, 0x60);
val8 = ((30000 + NAV_UPPER_UNIT - 1) / NAV_UPPER_UNIT);
rtl8xxxu_write8(priv, REG_NAV_UPPER, val8);
if (priv->rtl_chip == RTL8723A) {
val32 = rtl8xxxu_read32(priv, REG_FPGA0_RF_MODE);
if ((val32 & 0xff000000) != 0x83000000) {
val32 |= FPGA_RF_MODE_CCK;
rtl8xxxu_write32(priv, REG_FPGA0_RF_MODE, val32);
}
} else if (priv->rtl_chip == RTL8192E) {
rtl8xxxu_write8(priv, REG_USB_HRPWM, 0x00);
}
val32 = rtl8xxxu_read32(priv, REG_FWHW_TXQ_CTRL);
val32 |= FWHW_TXQ_CTRL_XMIT_MGMT_ACK;
rtl8xxxu_write32(priv, REG_FWHW_TXQ_CTRL, val32);
if (priv->rtl_chip == RTL8192E) {
val32 = rtl8xxxu_read32(priv, REG_AFE_MISC);
rtl8xxxu_write8(priv, REG_8192E_LDOV12_CTRL, 0x75);
val32 &= 0xfff00fff;
val32 |= 0x0007e000;
rtl8xxxu_write32(priv, REG_AFE_MISC, val32);
}
exit:
return ret;
}
static void rtl8xxxu_cam_write(struct rtl8xxxu_priv *priv,
struct ieee80211_key_conf *key, const u8 *mac)
{
u32 cmd, val32, addr, ctrl;
int j, i, tmp_debug;
tmp_debug = rtl8xxxu_debug;
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_KEY)
rtl8xxxu_debug |= RTL8XXXU_DEBUG_REG_WRITE;
addr = key->keyidx << CAM_CMD_KEY_SHIFT;
ctrl = (key->cipher & 0x0f) << 2 | key->keyidx | CAM_WRITE_VALID;
for (j = 5; j >= 0; j--) {
switch (j) {
case 0:
val32 = ctrl | (mac[0] << 16) | (mac[1] << 24);
break;
case 1:
val32 = mac[2] | (mac[3] << 8) |
(mac[4] << 16) | (mac[5] << 24);
break;
default:
i = (j - 2) << 2;
val32 = key->key[i] | (key->key[i + 1] << 8) |
key->key[i + 2] << 16 | key->key[i + 3] << 24;
break;
}
rtl8xxxu_write32(priv, REG_CAM_WRITE, val32);
cmd = CAM_CMD_POLLING | CAM_CMD_WRITE | (addr + j);
rtl8xxxu_write32(priv, REG_CAM_CMD, cmd);
udelay(100);
}
rtl8xxxu_debug = tmp_debug;
}
static void rtl8xxxu_sw_scan_start(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, const u8 *mac)
{
struct rtl8xxxu_priv *priv = hw->priv;
u8 val8;
val8 = rtl8xxxu_read8(priv, REG_BEACON_CTRL);
val8 |= BEACON_DISABLE_TSF_UPDATE;
rtl8xxxu_write8(priv, REG_BEACON_CTRL, val8);
}
static void rtl8xxxu_sw_scan_complete(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct rtl8xxxu_priv *priv = hw->priv;
u8 val8;
val8 = rtl8xxxu_read8(priv, REG_BEACON_CTRL);
val8 &= ~BEACON_DISABLE_TSF_UPDATE;
rtl8xxxu_write8(priv, REG_BEACON_CTRL, val8);
}
void rtl8xxxu_update_rate_mask(struct rtl8xxxu_priv *priv, u32 ramask, int sgi)
{
struct h2c_cmd h2c;
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.ramask.cmd = H2C_SET_RATE_MASK;
h2c.ramask.mask_lo = cpu_to_le16(ramask & 0xffff);
h2c.ramask.mask_hi = cpu_to_le16(ramask >> 16);
h2c.ramask.arg = 0x80;
if (sgi)
h2c.ramask.arg |= 0x20;
dev_dbg(&priv->udev->dev, "%s: rate mask %08x, arg %02x, size %zi\n",
__func__, ramask, h2c.ramask.arg, sizeof(h2c.ramask));
rtl8xxxu_gen1_h2c_cmd(priv, &h2c, sizeof(h2c.ramask));
}
void rtl8xxxu_gen2_update_rate_mask(struct rtl8xxxu_priv *priv,
u32 ramask, int sgi)
{
struct h2c_cmd h2c;
u8 bw = 0;
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.b_macid_cfg.cmd = H2C_8723B_MACID_CFG_RAID;
h2c.b_macid_cfg.ramask0 = ramask & 0xff;
h2c.b_macid_cfg.ramask1 = (ramask >> 8) & 0xff;
h2c.b_macid_cfg.ramask2 = (ramask >> 16) & 0xff;
h2c.b_macid_cfg.ramask3 = (ramask >> 24) & 0xff;
h2c.ramask.arg = 0x80;
h2c.b_macid_cfg.data1 = 0;
if (sgi)
h2c.b_macid_cfg.data1 |= BIT(7);
h2c.b_macid_cfg.data2 = bw;
dev_dbg(&priv->udev->dev, "%s: rate mask %08x, arg %02x, size %zi\n",
__func__, ramask, h2c.ramask.arg, sizeof(h2c.b_macid_cfg));
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.b_macid_cfg));
}
void rtl8xxxu_gen1_report_connect(struct rtl8xxxu_priv *priv,
u8 macid, bool connect)
{
struct h2c_cmd h2c;
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.joinbss.cmd = H2C_JOIN_BSS_REPORT;
if (connect)
h2c.joinbss.data = H2C_JOIN_BSS_CONNECT;
else
h2c.joinbss.data = H2C_JOIN_BSS_DISCONNECT;
rtl8xxxu_gen1_h2c_cmd(priv, &h2c, sizeof(h2c.joinbss));
}
void rtl8xxxu_gen2_report_connect(struct rtl8xxxu_priv *priv,
u8 macid, bool connect)
{
#ifdef RTL8XXXU_GEN2_REPORT_CONNECT
struct h2c_cmd h2c;
memset(&h2c, 0, sizeof(struct h2c_cmd));
h2c.media_status_rpt.cmd = H2C_8723B_MEDIA_STATUS_RPT;
if (connect)
h2c.media_status_rpt.parm |= BIT(0);
else
h2c.media_status_rpt.parm &= ~BIT(0);
rtl8xxxu_gen2_h2c_cmd(priv, &h2c, sizeof(h2c.media_status_rpt));
#endif
}
void rtl8xxxu_gen1_init_aggregation(struct rtl8xxxu_priv *priv)
{
u8 agg_ctrl, usb_spec, page_thresh, timeout;
usb_spec = rtl8xxxu_read8(priv, REG_USB_SPECIAL_OPTION);
usb_spec &= ~USB_SPEC_USB_AGG_ENABLE;
rtl8xxxu_write8(priv, REG_USB_SPECIAL_OPTION, usb_spec);
agg_ctrl = rtl8xxxu_read8(priv, REG_TRXDMA_CTRL);
agg_ctrl &= ~TRXDMA_CTRL_RXDMA_AGG_EN;
if (!rtl8xxxu_dma_aggregation) {
rtl8xxxu_write8(priv, REG_TRXDMA_CTRL, agg_ctrl);
return;
}
agg_ctrl |= TRXDMA_CTRL_RXDMA_AGG_EN;
rtl8xxxu_write8(priv, REG_TRXDMA_CTRL, agg_ctrl);
page_thresh = (priv->fops->rx_agg_buf_size / 512);
if (rtl8xxxu_dma_agg_pages >= 0) {
if (rtl8xxxu_dma_agg_pages <= page_thresh)
timeout = page_thresh;
else if (rtl8xxxu_dma_agg_pages <= 6)
dev_err(&priv->udev->dev,
"%s: dma_agg_pages=%i too small, minium is 6\n",
__func__, rtl8xxxu_dma_agg_pages);
else
dev_err(&priv->udev->dev,
"%s: dma_agg_pages=%i larger than limit %i\n",
__func__, rtl8xxxu_dma_agg_pages, page_thresh);
}
rtl8xxxu_write8(priv, REG_RXDMA_AGG_PG_TH, page_thresh);
timeout = 4;
if (rtl8xxxu_dma_agg_timeout >= 0) {
if (rtl8xxxu_dma_agg_timeout <= 127)
timeout = rtl8xxxu_dma_agg_timeout;
else
dev_err(&priv->udev->dev,
"%s: Invalid dma_agg_timeout: %i\n",
__func__, rtl8xxxu_dma_agg_timeout);
}
rtl8xxxu_write8(priv, REG_RXDMA_AGG_PG_TH + 1, timeout);
rtl8xxxu_write8(priv, REG_USB_DMA_AGG_TO, timeout);
priv->rx_buf_aggregation = 1;
}
static void rtl8xxxu_set_basic_rates(struct rtl8xxxu_priv *priv, u32 rate_cfg)
{
u32 val32;
u8 rate_idx = 0;
rate_cfg &= RESPONSE_RATE_BITMAP_ALL;
val32 = rtl8xxxu_read32(priv, REG_RESPONSE_RATE_SET);
val32 &= ~RESPONSE_RATE_BITMAP_ALL;
val32 |= rate_cfg;
rtl8xxxu_write32(priv, REG_RESPONSE_RATE_SET, val32);
dev_dbg(&priv->udev->dev, "%s: rates %08x\n", __func__, rate_cfg);
while (rate_cfg) {
rate_cfg = (rate_cfg >> 1);
rate_idx++;
}
rtl8xxxu_write8(priv, REG_INIRTS_RATE_SEL, rate_idx);
}
static void
rtl8xxxu_bss_info_changed(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_bss_conf *bss_conf, u32 changed)
{
struct rtl8xxxu_priv *priv = hw->priv;
struct device *dev = &priv->udev->dev;
struct ieee80211_sta *sta;
u32 val32;
u8 val8;
if (changed & BSS_CHANGED_ASSOC) {
dev_dbg(dev, "Changed ASSOC: %i!\n", bss_conf->assoc);
rtl8xxxu_set_linktype(priv, vif->type);
if (bss_conf->assoc) {
u32 ramask;
int sgi = 0;
rcu_read_lock();
sta = ieee80211_find_sta(vif, bss_conf->bssid);
if (!sta) {
dev_info(dev, "%s: ASSOC no sta found\n",
__func__);
rcu_read_unlock();
goto error;
}
if (sta->ht_cap.ht_supported)
dev_info(dev, "%s: HT supported\n", __func__);
if (sta->vht_cap.vht_supported)
dev_info(dev, "%s: VHT supported\n", __func__);
ramask = (sta->supp_rates[0] & 0xfff) |
sta->ht_cap.mcs.rx_mask[0] << 12 |
sta->ht_cap.mcs.rx_mask[1] << 20;
if (sta->ht_cap.cap &
(IEEE80211_HT_CAP_SGI_40 | IEEE80211_HT_CAP_SGI_20))
sgi = 1;
rcu_read_unlock();
priv->fops->update_rate_mask(priv, ramask, sgi);
rtl8xxxu_write8(priv, REG_BCN_MAX_ERR, 0xff);
rtl8xxxu_stop_tx_beacon(priv);
rtl8xxxu_write16(priv, REG_BCN_PSR_RPT,
0xc000 | bss_conf->aid);
priv->fops->report_connect(priv, 0, true);
} else {
val8 = rtl8xxxu_read8(priv, REG_BEACON_CTRL);
val8 |= BEACON_DISABLE_TSF_UPDATE;
rtl8xxxu_write8(priv, REG_BEACON_CTRL, val8);
priv->fops->report_connect(priv, 0, false);
}
}
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
dev_dbg(dev, "Changed ERP_PREAMBLE: Use short preamble %i\n",
bss_conf->use_short_preamble);
val32 = rtl8xxxu_read32(priv, REG_RESPONSE_RATE_SET);
if (bss_conf->use_short_preamble)
val32 |= RSR_ACK_SHORT_PREAMBLE;
else
val32 &= ~RSR_ACK_SHORT_PREAMBLE;
rtl8xxxu_write32(priv, REG_RESPONSE_RATE_SET, val32);
}
if (changed & BSS_CHANGED_ERP_SLOT) {
dev_dbg(dev, "Changed ERP_SLOT: short_slot_time %i\n",
bss_conf->use_short_slot);
if (bss_conf->use_short_slot)
val8 = 9;
else
val8 = 20;
rtl8xxxu_write8(priv, REG_SLOT, val8);
}
if (changed & BSS_CHANGED_BSSID) {
dev_dbg(dev, "Changed BSSID!\n");
rtl8xxxu_set_bssid(priv, bss_conf->bssid);
}
if (changed & BSS_CHANGED_BASIC_RATES) {
dev_dbg(dev, "Changed BASIC_RATES!\n");
rtl8xxxu_set_basic_rates(priv, bss_conf->basic_rates);
}
error:
return;
}
static u32 rtl8xxxu_80211_to_rtl_queue(u32 queue)
{
u32 rtlqueue;
switch (queue) {
case IEEE80211_AC_VO:
rtlqueue = TXDESC_QUEUE_VO;
break;
case IEEE80211_AC_VI:
rtlqueue = TXDESC_QUEUE_VI;
break;
case IEEE80211_AC_BE:
rtlqueue = TXDESC_QUEUE_BE;
break;
case IEEE80211_AC_BK:
rtlqueue = TXDESC_QUEUE_BK;
break;
default:
rtlqueue = TXDESC_QUEUE_BE;
}
return rtlqueue;
}
static u32 rtl8xxxu_queue_select(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
u32 queue;
if (ieee80211_is_mgmt(hdr->frame_control))
queue = TXDESC_QUEUE_MGNT;
else
queue = rtl8xxxu_80211_to_rtl_queue(skb_get_queue_mapping(skb));
return queue;
}
static void rtl8xxxu_calc_tx_desc_csum(struct rtl8xxxu_txdesc32 *tx_desc)
{
__le16 *ptr = (__le16 *)tx_desc;
u16 csum = 0;
int i;
tx_desc->csum = cpu_to_le16(0);
for (i = 0; i < (sizeof(struct rtl8xxxu_txdesc32) / sizeof(u16)); i++)
csum = csum ^ le16_to_cpu(ptr[i]);
tx_desc->csum |= cpu_to_le16(csum);
}
static void rtl8xxxu_free_tx_resources(struct rtl8xxxu_priv *priv)
{
struct rtl8xxxu_tx_urb *tx_urb, *tmp;
unsigned long flags;
spin_lock_irqsave(&priv->tx_urb_lock, flags);
list_for_each_entry_safe(tx_urb, tmp, &priv->tx_urb_free_list, list) {
list_del(&tx_urb->list);
priv->tx_urb_free_count--;
usb_free_urb(&tx_urb->urb);
}
spin_unlock_irqrestore(&priv->tx_urb_lock, flags);
}
static struct rtl8xxxu_tx_urb *
rtl8xxxu_alloc_tx_urb(struct rtl8xxxu_priv *priv)
{
struct rtl8xxxu_tx_urb *tx_urb;
unsigned long flags;
spin_lock_irqsave(&priv->tx_urb_lock, flags);
tx_urb = list_first_entry_or_null(&priv->tx_urb_free_list,
struct rtl8xxxu_tx_urb, list);
if (tx_urb) {
list_del(&tx_urb->list);
priv->tx_urb_free_count--;
if (priv->tx_urb_free_count < RTL8XXXU_TX_URB_LOW_WATER &&
!priv->tx_stopped) {
priv->tx_stopped = true;
ieee80211_stop_queues(priv->hw);
}
}
spin_unlock_irqrestore(&priv->tx_urb_lock, flags);
return tx_urb;
}
static void rtl8xxxu_free_tx_urb(struct rtl8xxxu_priv *priv,
struct rtl8xxxu_tx_urb *tx_urb)
{
unsigned long flags;
INIT_LIST_HEAD(&tx_urb->list);
spin_lock_irqsave(&priv->tx_urb_lock, flags);
list_add(&tx_urb->list, &priv->tx_urb_free_list);
priv->tx_urb_free_count++;
if (priv->tx_urb_free_count > RTL8XXXU_TX_URB_HIGH_WATER &&
priv->tx_stopped) {
priv->tx_stopped = false;
ieee80211_wake_queues(priv->hw);
}
spin_unlock_irqrestore(&priv->tx_urb_lock, flags);
}
static void rtl8xxxu_tx_complete(struct urb *urb)
{
struct sk_buff *skb = (struct sk_buff *)urb->context;
struct ieee80211_tx_info *tx_info;
struct ieee80211_hw *hw;
struct rtl8xxxu_priv *priv;
struct rtl8xxxu_tx_urb *tx_urb =
container_of(urb, struct rtl8xxxu_tx_urb, urb);
tx_info = IEEE80211_SKB_CB(skb);
hw = tx_info->rate_driver_data[0];
priv = hw->priv;
skb_pull(skb, priv->fops->tx_desc_size);
ieee80211_tx_info_clear_status(tx_info);
tx_info->status.rates[0].idx = -1;
tx_info->status.rates[0].count = 0;
if (!urb->status)
tx_info->flags |= IEEE80211_TX_STAT_ACK;
ieee80211_tx_status_irqsafe(hw, skb);
rtl8xxxu_free_tx_urb(priv, tx_urb);
}
static void rtl8xxxu_dump_action(struct device *dev,
struct ieee80211_hdr *hdr)
{
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)hdr;
u16 cap, timeout;
if (!(rtl8xxxu_debug & RTL8XXXU_DEBUG_ACTION))
return;
switch (mgmt->u.action.u.addba_resp.action_code) {
case WLAN_ACTION_ADDBA_RESP:
cap = le16_to_cpu(mgmt->u.action.u.addba_resp.capab);
timeout = le16_to_cpu(mgmt->u.action.u.addba_resp.timeout);
dev_info(dev, "WLAN_ACTION_ADDBA_RESP: "
"timeout %i, tid %02x, buf_size %02x, policy %02x, "
"status %02x\n",
timeout,
(cap & IEEE80211_ADDBA_PARAM_TID_MASK) >> 2,
(cap & IEEE80211_ADDBA_PARAM_BUF_SIZE_MASK) >> 6,
(cap >> 1) & 0x1,
le16_to_cpu(mgmt->u.action.u.addba_resp.status));
break;
case WLAN_ACTION_ADDBA_REQ:
cap = le16_to_cpu(mgmt->u.action.u.addba_req.capab);
timeout = le16_to_cpu(mgmt->u.action.u.addba_req.timeout);
dev_info(dev, "WLAN_ACTION_ADDBA_REQ: "
"timeout %i, tid %02x, buf_size %02x, policy %02x\n",
timeout,
(cap & IEEE80211_ADDBA_PARAM_TID_MASK) >> 2,
(cap & IEEE80211_ADDBA_PARAM_BUF_SIZE_MASK) >> 6,
(cap >> 1) & 0x1);
break;
default:
dev_info(dev, "action frame %02x\n",
mgmt->u.action.u.addba_resp.action_code);
break;
}
}
void
rtl8xxxu_fill_txdesc_v1(struct ieee80211_hw *hw, struct ieee80211_hdr *hdr,
struct ieee80211_tx_info *tx_info,
struct rtl8xxxu_txdesc32 *tx_desc, bool sgi,
bool short_preamble, bool ampdu_enable, u32 rts_rate)
{
struct ieee80211_rate *tx_rate = ieee80211_get_tx_rate(hw, tx_info);
struct rtl8xxxu_priv *priv = hw->priv;
struct device *dev = &priv->udev->dev;
u32 rate;
u16 rate_flags = tx_info->control.rates[0].flags;
u16 seq_number;
if (rate_flags & IEEE80211_TX_RC_MCS &&
!ieee80211_is_mgmt(hdr->frame_control))
rate = tx_info->control.rates[0].idx + DESC_RATE_MCS0;
else
rate = tx_rate->hw_value;
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_TX)
dev_info(dev, "%s: TX rate: %d, pkt size %d\n",
__func__, rate, cpu_to_le16(tx_desc->pkt_size));
seq_number = IEEE80211_SEQ_TO_SN(le16_to_cpu(hdr->seq_ctrl));
tx_desc->txdw5 = cpu_to_le32(rate);
if (ieee80211_is_data(hdr->frame_control))
tx_desc->txdw5 |= cpu_to_le32(0x0001ff00);
tx_desc->txdw3 = cpu_to_le32((u32)seq_number << TXDESC32_SEQ_SHIFT);
if (ampdu_enable)
tx_desc->txdw1 |= cpu_to_le32(TXDESC32_AGG_ENABLE);
else
tx_desc->txdw1 |= cpu_to_le32(TXDESC32_AGG_BREAK);
if (ieee80211_is_mgmt(hdr->frame_control)) {
tx_desc->txdw5 = cpu_to_le32(rate);
tx_desc->txdw4 |= cpu_to_le32(TXDESC32_USE_DRIVER_RATE);
tx_desc->txdw5 |= cpu_to_le32(6 << TXDESC32_RETRY_LIMIT_SHIFT);
tx_desc->txdw5 |= cpu_to_le32(TXDESC32_RETRY_LIMIT_ENABLE);
}
if (ieee80211_is_data_qos(hdr->frame_control))
tx_desc->txdw4 |= cpu_to_le32(TXDESC32_QOS);
if (short_preamble)
tx_desc->txdw4 |= cpu_to_le32(TXDESC32_SHORT_PREAMBLE);
if (sgi)
tx_desc->txdw5 |= cpu_to_le32(TXDESC32_SHORT_GI);
tx_desc->txdw4 |= cpu_to_le32(rts_rate << TXDESC32_RTS_RATE_SHIFT);
if (rate_flags & IEEE80211_TX_RC_USE_RTS_CTS) {
tx_desc->txdw4 |= cpu_to_le32(TXDESC32_RTS_CTS_ENABLE);
tx_desc->txdw4 |= cpu_to_le32(TXDESC32_HW_RTS_ENABLE);
} else if (rate_flags & IEEE80211_TX_RC_USE_CTS_PROTECT) {
tx_desc->txdw4 |= cpu_to_le32(TXDESC32_CTS_SELF_ENABLE);
tx_desc->txdw4 |= cpu_to_le32(TXDESC32_HW_RTS_ENABLE);
}
}
void
rtl8xxxu_fill_txdesc_v2(struct ieee80211_hw *hw, struct ieee80211_hdr *hdr,
struct ieee80211_tx_info *tx_info,
struct rtl8xxxu_txdesc32 *tx_desc32, bool sgi,
bool short_preamble, bool ampdu_enable, u32 rts_rate)
{
struct ieee80211_rate *tx_rate = ieee80211_get_tx_rate(hw, tx_info);
struct rtl8xxxu_priv *priv = hw->priv;
struct device *dev = &priv->udev->dev;
struct rtl8xxxu_txdesc40 *tx_desc40;
u32 rate;
u16 rate_flags = tx_info->control.rates[0].flags;
u16 seq_number;
tx_desc40 = (struct rtl8xxxu_txdesc40 *)tx_desc32;
if (rate_flags & IEEE80211_TX_RC_MCS &&
!ieee80211_is_mgmt(hdr->frame_control))
rate = tx_info->control.rates[0].idx + DESC_RATE_MCS0;
else
rate = tx_rate->hw_value;
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_TX)
dev_info(dev, "%s: TX rate: %d, pkt size %d\n",
__func__, rate, cpu_to_le16(tx_desc40->pkt_size));
seq_number = IEEE80211_SEQ_TO_SN(le16_to_cpu(hdr->seq_ctrl));
tx_desc40->txdw4 = cpu_to_le32(rate);
if (ieee80211_is_data(hdr->frame_control)) {
tx_desc40->txdw4 |= cpu_to_le32(0x1f <<
TXDESC40_DATA_RATE_FB_SHIFT);
}
tx_desc40->txdw9 = cpu_to_le32((u32)seq_number << TXDESC40_SEQ_SHIFT);
if (ampdu_enable)
tx_desc40->txdw2 |= cpu_to_le32(TXDESC40_AGG_ENABLE);
else
tx_desc40->txdw2 |= cpu_to_le32(TXDESC40_AGG_BREAK);
if (ieee80211_is_mgmt(hdr->frame_control)) {
tx_desc40->txdw4 = cpu_to_le32(rate);
tx_desc40->txdw3 |= cpu_to_le32(TXDESC40_USE_DRIVER_RATE);
tx_desc40->txdw4 |=
cpu_to_le32(6 << TXDESC40_RETRY_LIMIT_SHIFT);
tx_desc40->txdw4 |= cpu_to_le32(TXDESC40_RETRY_LIMIT_ENABLE);
}
if (short_preamble)
tx_desc40->txdw5 |= cpu_to_le32(TXDESC40_SHORT_PREAMBLE);
tx_desc40->txdw4 |= cpu_to_le32(rts_rate << TXDESC40_RTS_RATE_SHIFT);
if (rate_flags & IEEE80211_TX_RC_USE_RTS_CTS) {
tx_desc40->txdw3 |= cpu_to_le32(TXDESC40_RTS_CTS_ENABLE);
tx_desc40->txdw3 |= cpu_to_le32(TXDESC40_HW_RTS_ENABLE);
} else if (rate_flags & IEEE80211_TX_RC_USE_CTS_PROTECT) {
tx_desc40->txdw3 |= cpu_to_le32(TXDESC40_CTS_SELF_ENABLE);
}
}
static void rtl8xxxu_tx(struct ieee80211_hw *hw,
struct ieee80211_tx_control *control,
struct sk_buff *skb)
{
struct ieee80211_hdr *hdr = (struct ieee80211_hdr *)skb->data;
struct ieee80211_tx_info *tx_info = IEEE80211_SKB_CB(skb);
struct rtl8xxxu_priv *priv = hw->priv;
struct rtl8xxxu_txdesc32 *tx_desc;
struct rtl8xxxu_tx_urb *tx_urb;
struct ieee80211_sta *sta = NULL;
struct ieee80211_vif *vif = tx_info->control.vif;
struct device *dev = &priv->udev->dev;
u32 queue, rts_rate;
u16 pktlen = skb->len;
u16 seq_number;
u16 rate_flag = tx_info->control.rates[0].flags;
int tx_desc_size = priv->fops->tx_desc_size;
int ret;
bool usedesc40, ampdu_enable, sgi = false, short_preamble = false;
if (skb_headroom(skb) < tx_desc_size) {
dev_warn(dev,
"%s: Not enough headroom (%i) for tx descriptor\n",
__func__, skb_headroom(skb));
goto error;
}
if (unlikely(skb->len > (65535 - tx_desc_size))) {
dev_warn(dev, "%s: Trying to send over-sized skb (%i)\n",
__func__, skb->len);
goto error;
}
tx_urb = rtl8xxxu_alloc_tx_urb(priv);
if (!tx_urb) {
dev_warn(dev, "%s: Unable to allocate tx urb\n", __func__);
goto error;
}
if (ieee80211_is_action(hdr->frame_control))
rtl8xxxu_dump_action(dev, hdr);
usedesc40 = (tx_desc_size == 40);
tx_info->rate_driver_data[0] = hw;
if (control && control->sta)
sta = control->sta;
tx_desc = skb_push(skb, tx_desc_size);
memset(tx_desc, 0, tx_desc_size);
tx_desc->pkt_size = cpu_to_le16(pktlen);
tx_desc->pkt_offset = tx_desc_size;
tx_desc->txdw0 =
TXDESC_OWN | TXDESC_FIRST_SEGMENT | TXDESC_LAST_SEGMENT;
if (is_multicast_ether_addr(ieee80211_get_DA(hdr)) ||
is_broadcast_ether_addr(ieee80211_get_DA(hdr)))
tx_desc->txdw0 |= TXDESC_BROADMULTICAST;
queue = rtl8xxxu_queue_select(hw, skb);
tx_desc->txdw1 = cpu_to_le32(queue << TXDESC_QUEUE_SHIFT);
if (tx_info->control.hw_key) {
switch (tx_info->control.hw_key->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
case WLAN_CIPHER_SUITE_TKIP:
tx_desc->txdw1 |= cpu_to_le32(TXDESC_SEC_RC4);
break;
case WLAN_CIPHER_SUITE_CCMP:
tx_desc->txdw1 |= cpu_to_le32(TXDESC_SEC_AES);
break;
default:
break;
}
}
ampdu_enable = false;
if (ieee80211_is_data_qos(hdr->frame_control) && sta) {
if (sta->ht_cap.ht_supported) {
u32 ampdu, val32;
ampdu = (u32)sta->ht_cap.ampdu_density;
val32 = ampdu << TXDESC_AMPDU_DENSITY_SHIFT;
tx_desc->txdw2 |= cpu_to_le32(val32);
ampdu_enable = true;
}
}
if (rate_flag & IEEE80211_TX_RC_SHORT_GI ||
(ieee80211_is_data_qos(hdr->frame_control) &&
sta && sta->ht_cap.cap &
(IEEE80211_HT_CAP_SGI_40 | IEEE80211_HT_CAP_SGI_20)))
sgi = true;
if (rate_flag & IEEE80211_TX_RC_USE_SHORT_PREAMBLE ||
(sta && vif && vif->bss_conf.use_short_preamble))
short_preamble = true;
if (rate_flag & IEEE80211_TX_RC_USE_RTS_CTS)
rts_rate = ieee80211_get_rts_cts_rate(hw, tx_info)->hw_value;
else if (rate_flag & IEEE80211_TX_RC_USE_CTS_PROTECT)
rts_rate = ieee80211_get_rts_cts_rate(hw, tx_info)->hw_value;
else
rts_rate = 0;
seq_number = IEEE80211_SEQ_TO_SN(le16_to_cpu(hdr->seq_ctrl));
priv->fops->fill_txdesc(hw, hdr, tx_info, tx_desc, sgi, short_preamble,
ampdu_enable, rts_rate);
rtl8xxxu_calc_tx_desc_csum(tx_desc);
usb_fill_bulk_urb(&tx_urb->urb, priv->udev, priv->pipe_out[queue],
skb->data, skb->len, rtl8xxxu_tx_complete, skb);
usb_anchor_urb(&tx_urb->urb, &priv->tx_anchor);
ret = usb_submit_urb(&tx_urb->urb, GFP_ATOMIC);
if (ret) {
usb_unanchor_urb(&tx_urb->urb);
rtl8xxxu_free_tx_urb(priv, tx_urb);
goto error;
}
return;
error:
dev_kfree_skb(skb);
}
static void rtl8xxxu_rx_parse_phystats(struct rtl8xxxu_priv *priv,
struct ieee80211_rx_status *rx_status,
struct rtl8723au_phy_stats *phy_stats,
u32 rxmcs)
{
if (phy_stats->sgi_en)
rx_status->enc_flags |= RX_ENC_FLAG_SHORT_GI;
if (rxmcs < DESC_RATE_6M) {
u8 cck_agc_rpt = phy_stats->cck_agc_rpt_ofdm_cfosho_a;
switch (cck_agc_rpt & 0xc0) {
case 0xc0:
rx_status->signal = -46 - (cck_agc_rpt & 0x3e);
break;
case 0x80:
rx_status->signal = -26 - (cck_agc_rpt & 0x3e);
break;
case 0x40:
rx_status->signal = -12 - (cck_agc_rpt & 0x3e);
break;
case 0x00:
rx_status->signal = 16 - (cck_agc_rpt & 0x3e);
break;
}
} else {
rx_status->signal =
(phy_stats->cck_sig_qual_ofdm_pwdb_all >> 1) - 110;
}
}
static void rtl8xxxu_free_rx_resources(struct rtl8xxxu_priv *priv)
{
struct rtl8xxxu_rx_urb *rx_urb, *tmp;
unsigned long flags;
spin_lock_irqsave(&priv->rx_urb_lock, flags);
list_for_each_entry_safe(rx_urb, tmp,
&priv->rx_urb_pending_list, list) {
list_del(&rx_urb->list);
priv->rx_urb_pending_count--;
usb_free_urb(&rx_urb->urb);
}
spin_unlock_irqrestore(&priv->rx_urb_lock, flags);
}
static void rtl8xxxu_queue_rx_urb(struct rtl8xxxu_priv *priv,
struct rtl8xxxu_rx_urb *rx_urb)
{
struct sk_buff *skb;
unsigned long flags;
int pending = 0;
spin_lock_irqsave(&priv->rx_urb_lock, flags);
if (!priv->shutdown) {
list_add_tail(&rx_urb->list, &priv->rx_urb_pending_list);
priv->rx_urb_pending_count++;
pending = priv->rx_urb_pending_count;
} else {
skb = (struct sk_buff *)rx_urb->urb.context;
dev_kfree_skb(skb);
usb_free_urb(&rx_urb->urb);
}
spin_unlock_irqrestore(&priv->rx_urb_lock, flags);
if (pending > RTL8XXXU_RX_URB_PENDING_WATER)
schedule_work(&priv->rx_urb_wq);
}
static void rtl8xxxu_rx_urb_work(struct work_struct *work)
{
struct rtl8xxxu_priv *priv;
struct rtl8xxxu_rx_urb *rx_urb, *tmp;
struct list_head local;
struct sk_buff *skb;
unsigned long flags;
int ret;
priv = container_of(work, struct rtl8xxxu_priv, rx_urb_wq);
INIT_LIST_HEAD(&local);
spin_lock_irqsave(&priv->rx_urb_lock, flags);
list_splice_init(&priv->rx_urb_pending_list, &local);
priv->rx_urb_pending_count = 0;
spin_unlock_irqrestore(&priv->rx_urb_lock, flags);
list_for_each_entry_safe(rx_urb, tmp, &local, list) {
list_del_init(&rx_urb->list);
ret = rtl8xxxu_submit_rx_urb(priv, rx_urb);
switch (ret) {
case 0:
break;
case -ENOMEM:
case -EAGAIN:
rtl8xxxu_queue_rx_urb(priv, rx_urb);
break;
default:
pr_info("failed to requeue urb %i\n", ret);
skb = (struct sk_buff *)rx_urb->urb.context;
dev_kfree_skb(skb);
usb_free_urb(&rx_urb->urb);
}
}
}
static void rtl8723bu_handle_c2h(struct rtl8xxxu_priv *priv,
struct sk_buff *skb)
{
struct rtl8723bu_c2h *c2h = (struct rtl8723bu_c2h *)skb->data;
struct device *dev = &priv->udev->dev;
int len;
len = skb->len - 2;
dev_dbg(dev, "C2H ID %02x seq %02x, len %02x source %02x\n",
c2h->id, c2h->seq, len, c2h->bt_info.response_source);
switch(c2h->id) {
case C2H_8723B_BT_INFO:
if (c2h->bt_info.response_source >
BT_INFO_SRC_8723B_BT_ACTIVE_SEND)
dev_dbg(dev, "C2H_BT_INFO WiFi only firmware\n");
else
dev_dbg(dev, "C2H_BT_INFO BT/WiFi coexist firmware\n");
if (c2h->bt_info.bt_has_reset)
dev_dbg(dev, "BT has been reset\n");
if (c2h->bt_info.tx_rx_mask)
dev_dbg(dev, "BT TRx mask\n");
break;
case C2H_8723B_BT_MP_INFO:
dev_dbg(dev, "C2H_MP_INFO ext ID %02x, status %02x\n",
c2h->bt_mp_info.ext_id, c2h->bt_mp_info.status);
break;
case C2H_8723B_RA_REPORT:
dev_dbg(dev,
"C2H RA RPT: rate %02x, unk %i, macid %02x, noise %i\n",
c2h->ra_report.rate, c2h->ra_report.dummy0_0,
c2h->ra_report.macid, c2h->ra_report.noisy_state);
break;
default:
dev_info(dev, "Unhandled C2H event %02x seq %02x\n",
c2h->id, c2h->seq);
print_hex_dump(KERN_INFO, "C2H content: ", DUMP_PREFIX_NONE,
16, 1, c2h->raw.payload, len, false);
break;
}
}
int rtl8xxxu_parse_rxdesc16(struct rtl8xxxu_priv *priv, struct sk_buff *skb)
{
struct ieee80211_hw *hw = priv->hw;
struct ieee80211_rx_status *rx_status;
struct rtl8xxxu_rxdesc16 *rx_desc;
struct rtl8723au_phy_stats *phy_stats;
struct sk_buff *next_skb = NULL;
__le32 *_rx_desc_le;
u32 *_rx_desc;
int drvinfo_sz, desc_shift;
int i, pkt_cnt, pkt_len, urb_len, pkt_offset;
urb_len = skb->len;
pkt_cnt = 0;
do {
rx_desc = (struct rtl8xxxu_rxdesc16 *)skb->data;
_rx_desc_le = (__le32 *)skb->data;
_rx_desc = (u32 *)skb->data;
for (i = 0;
i < (sizeof(struct rtl8xxxu_rxdesc16) / sizeof(u32)); i++)
_rx_desc[i] = le32_to_cpu(_rx_desc_le[i]);
if (!pkt_cnt)
pkt_cnt = rx_desc->pkt_cnt;
pkt_len = rx_desc->pktlen;
drvinfo_sz = rx_desc->drvinfo_sz * 8;
desc_shift = rx_desc->shift;
pkt_offset = roundup(pkt_len + drvinfo_sz + desc_shift +
sizeof(struct rtl8xxxu_rxdesc16), 128);
if (pkt_cnt > 1 &&
urb_len > (pkt_offset + sizeof(struct rtl8xxxu_rxdesc16)))
next_skb = skb_clone(skb, GFP_ATOMIC);
rx_status = IEEE80211_SKB_RXCB(skb);
memset(rx_status, 0, sizeof(struct ieee80211_rx_status));
skb_pull(skb, sizeof(struct rtl8xxxu_rxdesc16));
phy_stats = (struct rtl8723au_phy_stats *)skb->data;
skb_pull(skb, drvinfo_sz + desc_shift);
skb_trim(skb, pkt_len);
if (rx_desc->phy_stats)
rtl8xxxu_rx_parse_phystats(priv, rx_status, phy_stats,
rx_desc->rxmcs);
rx_status->mactime = rx_desc->tsfl;
rx_status->flag |= RX_FLAG_MACTIME_START;
if (!rx_desc->swdec)
rx_status->flag |= RX_FLAG_DECRYPTED;
if (rx_desc->crc32)
rx_status->flag |= RX_FLAG_FAILED_FCS_CRC;
if (rx_desc->bw)
rx_status->bw = RATE_INFO_BW_40;
if (rx_desc->rxht) {
rx_status->encoding = RX_ENC_HT;
rx_status->rate_idx = rx_desc->rxmcs - DESC_RATE_MCS0;
} else {
rx_status->rate_idx = rx_desc->rxmcs;
}
rx_status->freq = hw->conf.chandef.chan->center_freq;
rx_status->band = hw->conf.chandef.chan->band;
ieee80211_rx_irqsafe(hw, skb);
skb = next_skb;
if (skb)
skb_pull(next_skb, pkt_offset);
pkt_cnt--;
urb_len -= pkt_offset;
} while (skb && urb_len > 0 && pkt_cnt > 0);
return RX_TYPE_DATA_PKT;
}
int rtl8xxxu_parse_rxdesc24(struct rtl8xxxu_priv *priv, struct sk_buff *skb)
{
struct ieee80211_hw *hw = priv->hw;
struct ieee80211_rx_status *rx_status = IEEE80211_SKB_RXCB(skb);
struct rtl8xxxu_rxdesc24 *rx_desc =
(struct rtl8xxxu_rxdesc24 *)skb->data;
struct rtl8723au_phy_stats *phy_stats;
__le32 *_rx_desc_le = (__le32 *)skb->data;
u32 *_rx_desc = (u32 *)skb->data;
int drvinfo_sz, desc_shift;
int i;
for (i = 0; i < (sizeof(struct rtl8xxxu_rxdesc24) / sizeof(u32)); i++)
_rx_desc[i] = le32_to_cpu(_rx_desc_le[i]);
memset(rx_status, 0, sizeof(struct ieee80211_rx_status));
skb_pull(skb, sizeof(struct rtl8xxxu_rxdesc24));
phy_stats = (struct rtl8723au_phy_stats *)skb->data;
drvinfo_sz = rx_desc->drvinfo_sz * 8;
desc_shift = rx_desc->shift;
skb_pull(skb, drvinfo_sz + desc_shift);
if (rx_desc->rpt_sel) {
struct device *dev = &priv->udev->dev;
dev_dbg(dev, "%s: C2H packet\n", __func__);
rtl8723bu_handle_c2h(priv, skb);
dev_kfree_skb(skb);
return RX_TYPE_C2H;
}
if (rx_desc->phy_stats)
rtl8xxxu_rx_parse_phystats(priv, rx_status, phy_stats,
rx_desc->rxmcs);
rx_status->mactime = rx_desc->tsfl;
rx_status->flag |= RX_FLAG_MACTIME_START;
if (!rx_desc->swdec)
rx_status->flag |= RX_FLAG_DECRYPTED;
if (rx_desc->crc32)
rx_status->flag |= RX_FLAG_FAILED_FCS_CRC;
if (rx_desc->bw)
rx_status->bw = RATE_INFO_BW_40;
if (rx_desc->rxmcs >= DESC_RATE_MCS0) {
rx_status->encoding = RX_ENC_HT;
rx_status->rate_idx = rx_desc->rxmcs - DESC_RATE_MCS0;
} else {
rx_status->rate_idx = rx_desc->rxmcs;
}
rx_status->freq = hw->conf.chandef.chan->center_freq;
rx_status->band = hw->conf.chandef.chan->band;
ieee80211_rx_irqsafe(hw, skb);
return RX_TYPE_DATA_PKT;
}
static void rtl8xxxu_rx_complete(struct urb *urb)
{
struct rtl8xxxu_rx_urb *rx_urb =
container_of(urb, struct rtl8xxxu_rx_urb, urb);
struct ieee80211_hw *hw = rx_urb->hw;
struct rtl8xxxu_priv *priv = hw->priv;
struct sk_buff *skb = (struct sk_buff *)urb->context;
struct device *dev = &priv->udev->dev;
skb_put(skb, urb->actual_length);
if (urb->status == 0) {
priv->fops->parse_rx_desc(priv, skb);
skb = NULL;
rx_urb->urb.context = NULL;
rtl8xxxu_queue_rx_urb(priv, rx_urb);
} else {
dev_dbg(dev, "%s: status %i\n", __func__, urb->status);
goto cleanup;
}
return;
cleanup:
usb_free_urb(urb);
dev_kfree_skb(skb);
return;
}
static int rtl8xxxu_submit_rx_urb(struct rtl8xxxu_priv *priv,
struct rtl8xxxu_rx_urb *rx_urb)
{
struct rtl8xxxu_fileops *fops = priv->fops;
struct sk_buff *skb;
int skb_size;
int ret, rx_desc_sz;
rx_desc_sz = fops->rx_desc_size;
if (priv->rx_buf_aggregation && fops->rx_agg_buf_size) {
skb_size = fops->rx_agg_buf_size;
skb_size += (rx_desc_sz + sizeof(struct rtl8723au_phy_stats));
} else {
skb_size = IEEE80211_MAX_FRAME_LEN;
}
skb = __netdev_alloc_skb(NULL, skb_size, GFP_KERNEL);
if (!skb)
return -ENOMEM;
memset(skb->data, 0, rx_desc_sz);
usb_fill_bulk_urb(&rx_urb->urb, priv->udev, priv->pipe_in, skb->data,
skb_size, rtl8xxxu_rx_complete, skb);
usb_anchor_urb(&rx_urb->urb, &priv->rx_anchor);
ret = usb_submit_urb(&rx_urb->urb, GFP_ATOMIC);
if (ret)
usb_unanchor_urb(&rx_urb->urb);
return ret;
}
static void rtl8xxxu_int_complete(struct urb *urb)
{
struct rtl8xxxu_priv *priv = (struct rtl8xxxu_priv *)urb->context;
struct device *dev = &priv->udev->dev;
int ret;
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_INTERRUPT)
dev_dbg(dev, "%s: status %i\n", __func__, urb->status);
if (urb->status == 0) {
usb_anchor_urb(urb, &priv->int_anchor);
ret = usb_submit_urb(urb, GFP_ATOMIC);
if (ret)
usb_unanchor_urb(urb);
} else {
dev_dbg(dev, "%s: Error %i\n", __func__, urb->status);
}
}
static int rtl8xxxu_submit_int_urb(struct ieee80211_hw *hw)
{
struct rtl8xxxu_priv *priv = hw->priv;
struct urb *urb;
u32 val32;
int ret;
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb)
return -ENOMEM;
usb_fill_int_urb(urb, priv->udev, priv->pipe_interrupt,
priv->int_buf, USB_INTR_CONTENT_LENGTH,
rtl8xxxu_int_complete, priv, 1);
usb_anchor_urb(urb, &priv->int_anchor);
ret = usb_submit_urb(urb, GFP_KERNEL);
if (ret) {
usb_unanchor_urb(urb);
goto error;
}
val32 = rtl8xxxu_read32(priv, REG_USB_HIMR);
val32 |= USB_HIMR_CPWM;
rtl8xxxu_write32(priv, REG_USB_HIMR, val32);
error:
return ret;
}
static int rtl8xxxu_add_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct rtl8xxxu_priv *priv = hw->priv;
int ret;
u8 val8;
switch (vif->type) {
case NL80211_IFTYPE_STATION:
rtl8xxxu_stop_tx_beacon(priv);
val8 = rtl8xxxu_read8(priv, REG_BEACON_CTRL);
val8 |= BEACON_ATIM | BEACON_FUNCTION_ENABLE |
BEACON_DISABLE_TSF_UPDATE;
rtl8xxxu_write8(priv, REG_BEACON_CTRL, val8);
ret = 0;
break;
default:
ret = -EOPNOTSUPP;
}
rtl8xxxu_set_linktype(priv, vif->type);
return ret;
}
static void rtl8xxxu_remove_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct rtl8xxxu_priv *priv = hw->priv;
dev_dbg(&priv->udev->dev, "%s\n", __func__);
}
static int rtl8xxxu_config(struct ieee80211_hw *hw, u32 changed)
{
struct rtl8xxxu_priv *priv = hw->priv;
struct device *dev = &priv->udev->dev;
u16 val16;
int ret = 0, channel;
bool ht40;
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_CHANNEL)
dev_info(dev,
"%s: channel: %i (changed %08x chandef.width %02x)\n",
__func__, hw->conf.chandef.chan->hw_value,
changed, hw->conf.chandef.width);
if (changed & IEEE80211_CONF_CHANGE_RETRY_LIMITS) {
val16 = ((hw->conf.long_frame_max_tx_count <<
RETRY_LIMIT_LONG_SHIFT) & RETRY_LIMIT_LONG_MASK) |
((hw->conf.short_frame_max_tx_count <<
RETRY_LIMIT_SHORT_SHIFT) & RETRY_LIMIT_SHORT_MASK);
rtl8xxxu_write16(priv, REG_RETRY_LIMIT, val16);
}
if (changed & IEEE80211_CONF_CHANGE_CHANNEL) {
switch (hw->conf.chandef.width) {
case NL80211_CHAN_WIDTH_20_NOHT:
case NL80211_CHAN_WIDTH_20:
ht40 = false;
break;
case NL80211_CHAN_WIDTH_40:
ht40 = true;
break;
default:
ret = -ENOTSUPP;
goto exit;
}
channel = hw->conf.chandef.chan->hw_value;
priv->fops->set_tx_power(priv, channel, ht40);
priv->fops->config_channel(hw);
}
exit:
return ret;
}
static int rtl8xxxu_conf_tx(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u16 queue,
const struct ieee80211_tx_queue_params *param)
{
struct rtl8xxxu_priv *priv = hw->priv;
struct device *dev = &priv->udev->dev;
u32 val32;
u8 aifs, acm_ctrl, acm_bit;
aifs = param->aifs;
val32 = aifs |
fls(param->cw_min) << EDCA_PARAM_ECW_MIN_SHIFT |
fls(param->cw_max) << EDCA_PARAM_ECW_MAX_SHIFT |
(u32)param->txop << EDCA_PARAM_TXOP_SHIFT;
acm_ctrl = rtl8xxxu_read8(priv, REG_ACM_HW_CTRL);
dev_dbg(dev,
"%s: IEEE80211 queue %02x val %08x, acm %i, acm_ctrl %02x\n",
__func__, queue, val32, param->acm, acm_ctrl);
switch (queue) {
case IEEE80211_AC_VO:
acm_bit = ACM_HW_CTRL_VO;
rtl8xxxu_write32(priv, REG_EDCA_VO_PARAM, val32);
break;
case IEEE80211_AC_VI:
acm_bit = ACM_HW_CTRL_VI;
rtl8xxxu_write32(priv, REG_EDCA_VI_PARAM, val32);
break;
case IEEE80211_AC_BE:
acm_bit = ACM_HW_CTRL_BE;
rtl8xxxu_write32(priv, REG_EDCA_BE_PARAM, val32);
break;
case IEEE80211_AC_BK:
acm_bit = ACM_HW_CTRL_BK;
rtl8xxxu_write32(priv, REG_EDCA_BK_PARAM, val32);
break;
default:
acm_bit = 0;
break;
}
if (param->acm)
acm_ctrl |= acm_bit;
else
acm_ctrl &= ~acm_bit;
rtl8xxxu_write8(priv, REG_ACM_HW_CTRL, acm_ctrl);
return 0;
}
static void rtl8xxxu_configure_filter(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags, u64 multicast)
{
struct rtl8xxxu_priv *priv = hw->priv;
u32 rcr = rtl8xxxu_read32(priv, REG_RCR);
dev_dbg(&priv->udev->dev, "%s: changed_flags %08x, total_flags %08x\n",
__func__, changed_flags, *total_flags);
if (*total_flags & FIF_FCSFAIL)
rcr |= RCR_ACCEPT_CRC32;
else
rcr &= ~RCR_ACCEPT_CRC32;
if (*total_flags & FIF_BCN_PRBRESP_PROMISC)
rcr &= ~RCR_CHECK_BSSID_BEACON;
else
rcr |= RCR_CHECK_BSSID_BEACON;
if (*total_flags & FIF_CONTROL)
rcr |= RCR_ACCEPT_CTRL_FRAME;
else
rcr &= ~RCR_ACCEPT_CTRL_FRAME;
if (*total_flags & FIF_OTHER_BSS) {
rcr |= RCR_ACCEPT_AP;
rcr &= ~RCR_CHECK_BSSID_MATCH;
} else {
rcr &= ~RCR_ACCEPT_AP;
rcr |= RCR_CHECK_BSSID_MATCH;
}
if (*total_flags & FIF_PSPOLL)
rcr |= RCR_ACCEPT_PM;
else
rcr &= ~RCR_ACCEPT_PM;
rtl8xxxu_write32(priv, REG_RCR, rcr);
*total_flags &= (FIF_ALLMULTI | FIF_FCSFAIL | FIF_BCN_PRBRESP_PROMISC |
FIF_CONTROL | FIF_OTHER_BSS | FIF_PSPOLL |
FIF_PROBE_REQ);
}
static int rtl8xxxu_set_rts_threshold(struct ieee80211_hw *hw, u32 rts)
{
if (rts > 2347)
return -EINVAL;
return 0;
}
static int rtl8xxxu_set_key(struct ieee80211_hw *hw, enum set_key_cmd cmd,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
struct rtl8xxxu_priv *priv = hw->priv;
struct device *dev = &priv->udev->dev;
u8 mac_addr[ETH_ALEN];
u8 val8;
u16 val16;
u32 val32;
int retval = -EOPNOTSUPP;
dev_dbg(dev, "%s: cmd %02x, cipher %08x, index %i\n",
__func__, cmd, key->cipher, key->keyidx);
if (vif->type != NL80211_IFTYPE_STATION)
return -EOPNOTSUPP;
if (key->keyidx > 3)
return -EOPNOTSUPP;
switch (key->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
break;
case WLAN_CIPHER_SUITE_CCMP:
key->flags |= IEEE80211_KEY_FLAG_SW_MGMT_TX;
break;
case WLAN_CIPHER_SUITE_TKIP:
key->flags |= IEEE80211_KEY_FLAG_GENERATE_MMIC;
default:
return -EOPNOTSUPP;
}
if (key->flags & IEEE80211_KEY_FLAG_PAIRWISE) {
dev_dbg(dev, "%s: pairwise key\n", __func__);
ether_addr_copy(mac_addr, sta->addr);
} else {
dev_dbg(dev, "%s: group key\n", __func__);
eth_broadcast_addr(mac_addr);
}
val16 = rtl8xxxu_read16(priv, REG_CR);
val16 |= CR_SECURITY_ENABLE;
rtl8xxxu_write16(priv, REG_CR, val16);
val8 = SEC_CFG_TX_SEC_ENABLE | SEC_CFG_TXBC_USE_DEFKEY |
SEC_CFG_RX_SEC_ENABLE | SEC_CFG_RXBC_USE_DEFKEY;
val8 |= SEC_CFG_TX_USE_DEFKEY | SEC_CFG_RX_USE_DEFKEY;
rtl8xxxu_write8(priv, REG_SECURITY_CFG, val8);
switch (cmd) {
case SET_KEY:
key->hw_key_idx = key->keyidx;
key->flags |= IEEE80211_KEY_FLAG_GENERATE_IV;
rtl8xxxu_cam_write(priv, key, mac_addr);
retval = 0;
break;
case DISABLE_KEY:
rtl8xxxu_write32(priv, REG_CAM_WRITE, 0x00000000);
val32 = CAM_CMD_POLLING | CAM_CMD_WRITE |
key->keyidx << CAM_CMD_KEY_SHIFT;
rtl8xxxu_write32(priv, REG_CAM_CMD, val32);
retval = 0;
break;
default:
dev_warn(dev, "%s: Unsupported command %02x\n", __func__, cmd);
}
return retval;
}
static int
rtl8xxxu_ampdu_action(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_ampdu_params *params)
{
struct rtl8xxxu_priv *priv = hw->priv;
struct device *dev = &priv->udev->dev;
u8 ampdu_factor, ampdu_density;
struct ieee80211_sta *sta = params->sta;
enum ieee80211_ampdu_mlme_action action = params->action;
switch (action) {
case IEEE80211_AMPDU_TX_START:
dev_dbg(dev, "%s: IEEE80211_AMPDU_TX_START\n", __func__);
ampdu_factor = sta->ht_cap.ampdu_factor;
ampdu_density = sta->ht_cap.ampdu_density;
rtl8xxxu_set_ampdu_factor(priv, ampdu_factor);
rtl8xxxu_set_ampdu_min_space(priv, ampdu_density);
dev_dbg(dev,
"Changed HT: ampdu_factor %02x, ampdu_density %02x\n",
ampdu_factor, ampdu_density);
break;
case IEEE80211_AMPDU_TX_STOP_FLUSH:
dev_dbg(dev, "%s: IEEE80211_AMPDU_TX_STOP_FLUSH\n", __func__);
rtl8xxxu_set_ampdu_factor(priv, 0);
rtl8xxxu_set_ampdu_min_space(priv, 0);
break;
case IEEE80211_AMPDU_TX_STOP_FLUSH_CONT:
dev_dbg(dev, "%s: IEEE80211_AMPDU_TX_STOP_FLUSH_CONT\n",
__func__);
rtl8xxxu_set_ampdu_factor(priv, 0);
rtl8xxxu_set_ampdu_min_space(priv, 0);
break;
case IEEE80211_AMPDU_RX_START:
dev_dbg(dev, "%s: IEEE80211_AMPDU_RX_START\n", __func__);
break;
case IEEE80211_AMPDU_RX_STOP:
dev_dbg(dev, "%s: IEEE80211_AMPDU_RX_STOP\n", __func__);
break;
default:
break;
}
return 0;
}
static int rtl8xxxu_start(struct ieee80211_hw *hw)
{
struct rtl8xxxu_priv *priv = hw->priv;
struct rtl8xxxu_rx_urb *rx_urb;
struct rtl8xxxu_tx_urb *tx_urb;
unsigned long flags;
int ret, i;
ret = 0;
init_usb_anchor(&priv->rx_anchor);
init_usb_anchor(&priv->tx_anchor);
init_usb_anchor(&priv->int_anchor);
priv->fops->enable_rf(priv);
if (priv->usb_interrupts) {
ret = rtl8xxxu_submit_int_urb(hw);
if (ret)
goto exit;
}
for (i = 0; i < RTL8XXXU_TX_URBS; i++) {
tx_urb = kmalloc(sizeof(struct rtl8xxxu_tx_urb), GFP_KERNEL);
if (!tx_urb) {
if (!i)
ret = -ENOMEM;
goto error_out;
}
usb_init_urb(&tx_urb->urb);
INIT_LIST_HEAD(&tx_urb->list);
tx_urb->hw = hw;
list_add(&tx_urb->list, &priv->tx_urb_free_list);
priv->tx_urb_free_count++;
}
priv->tx_stopped = false;
spin_lock_irqsave(&priv->rx_urb_lock, flags);
priv->shutdown = false;
spin_unlock_irqrestore(&priv->rx_urb_lock, flags);
for (i = 0; i < RTL8XXXU_RX_URBS; i++) {
rx_urb = kmalloc(sizeof(struct rtl8xxxu_rx_urb), GFP_KERNEL);
if (!rx_urb) {
if (!i)
ret = -ENOMEM;
goto error_out;
}
usb_init_urb(&rx_urb->urb);
INIT_LIST_HEAD(&rx_urb->list);
rx_urb->hw = hw;
ret = rtl8xxxu_submit_rx_urb(priv, rx_urb);
}
exit:
rtl8xxxu_write16(priv, REG_RXFLTMAP2, 0xffff);
rtl8xxxu_write16(priv, REG_RXFLTMAP0, 0xffff);
rtl8xxxu_write32(priv, REG_OFDM0_XA_AGC_CORE1, 0x6954341e);
return ret;
error_out:
rtl8xxxu_free_tx_resources(priv);
rtl8xxxu_write16(priv, REG_RXFLTMAP2, 0x0000);
rtl8xxxu_write16(priv, REG_RXFLTMAP0, 0x0000);
return ret;
}
static void rtl8xxxu_stop(struct ieee80211_hw *hw)
{
struct rtl8xxxu_priv *priv = hw->priv;
unsigned long flags;
rtl8xxxu_write8(priv, REG_TXPAUSE, 0xff);
rtl8xxxu_write16(priv, REG_RXFLTMAP0, 0x0000);
rtl8xxxu_write16(priv, REG_RXFLTMAP2, 0x0000);
spin_lock_irqsave(&priv->rx_urb_lock, flags);
priv->shutdown = true;
spin_unlock_irqrestore(&priv->rx_urb_lock, flags);
usb_kill_anchored_urbs(&priv->rx_anchor);
usb_kill_anchored_urbs(&priv->tx_anchor);
if (priv->usb_interrupts)
usb_kill_anchored_urbs(&priv->int_anchor);
rtl8xxxu_write8(priv, REG_TXPAUSE, 0xff);
priv->fops->disable_rf(priv);
if (priv->usb_interrupts)
rtl8xxxu_write32(priv, REG_USB_HIMR, 0);
rtl8xxxu_free_rx_resources(priv);
rtl8xxxu_free_tx_resources(priv);
}
static int rtl8xxxu_parse_usb(struct rtl8xxxu_priv *priv,
struct usb_interface *interface)
{
struct usb_interface_descriptor *interface_desc;
struct usb_host_interface *host_interface;
struct usb_endpoint_descriptor *endpoint;
struct device *dev = &priv->udev->dev;
int i, j = 0, endpoints;
u8 dir, xtype, num;
int ret = 0;
host_interface = &interface->altsetting[0];
interface_desc = &host_interface->desc;
endpoints = interface_desc->bNumEndpoints;
for (i = 0; i < endpoints; i++) {
endpoint = &host_interface->endpoint[i].desc;
dir = endpoint->bEndpointAddress & USB_ENDPOINT_DIR_MASK;
num = usb_endpoint_num(endpoint);
xtype = usb_endpoint_type(endpoint);
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_USB)
dev_dbg(dev,
"%s: endpoint: dir %02x, # %02x, type %02x\n",
__func__, dir, num, xtype);
if (usb_endpoint_dir_in(endpoint) &&
usb_endpoint_xfer_bulk(endpoint)) {
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_USB)
dev_dbg(dev, "%s: in endpoint num %i\n",
__func__, num);
if (priv->pipe_in) {
dev_warn(dev,
"%s: Too many IN pipes\n", __func__);
ret = -EINVAL;
goto exit;
}
priv->pipe_in = usb_rcvbulkpipe(priv->udev, num);
}
if (usb_endpoint_dir_in(endpoint) &&
usb_endpoint_xfer_int(endpoint)) {
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_USB)
dev_dbg(dev, "%s: interrupt endpoint num %i\n",
__func__, num);
if (priv->pipe_interrupt) {
dev_warn(dev, "%s: Too many INTERRUPT pipes\n",
__func__);
ret = -EINVAL;
goto exit;
}
priv->pipe_interrupt = usb_rcvintpipe(priv->udev, num);
}
if (usb_endpoint_dir_out(endpoint) &&
usb_endpoint_xfer_bulk(endpoint)) {
if (rtl8xxxu_debug & RTL8XXXU_DEBUG_USB)
dev_dbg(dev, "%s: out endpoint num %i\n",
__func__, num);
if (j >= RTL8XXXU_OUT_ENDPOINTS) {
dev_warn(dev,
"%s: Too many OUT pipes\n", __func__);
ret = -EINVAL;
goto exit;
}
priv->out_ep[j++] = num;
}
}
exit:
priv->nr_out_eps = j;
return ret;
}
static int rtl8xxxu_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct rtl8xxxu_priv *priv;
struct ieee80211_hw *hw;
struct usb_device *udev;
struct ieee80211_supported_band *sband;
int ret;
int untested = 1;
udev = usb_get_dev(interface_to_usbdev(interface));
switch (id->idVendor) {
case USB_VENDOR_ID_REALTEK:
switch(id->idProduct) {
case 0x1724:
case 0x8176:
case 0x8178:
case 0x817f:
case 0x818b:
untested = 0;
break;
}
break;
case 0x7392:
if (id->idProduct == 0x7811)
untested = 0;
break;
case 0x050d:
if (id->idProduct == 0x1004)
untested = 0;
break;
case 0x20f4:
if (id->idProduct == 0x648b)
untested = 0;
break;
case 0x2001:
if (id->idProduct == 0x3308)
untested = 0;
break;
case 0x2357:
if (id->idProduct == 0x0109)
untested = 0;
break;
default:
break;
}
if (untested) {
rtl8xxxu_debug |= RTL8XXXU_DEBUG_EFUSE;
dev_info(&udev->dev,
"This Realtek USB WiFi dongle (0x%04x:0x%04x) is untested!\n",
id->idVendor, id->idProduct);
dev_info(&udev->dev,
"Please report results to Jes.Sorensen@gmail.com\n");
}
hw = ieee80211_alloc_hw(sizeof(struct rtl8xxxu_priv), &rtl8xxxu_ops);
if (!hw) {
ret = -ENOMEM;
priv = NULL;
goto exit;
}
priv = hw->priv;
priv->hw = hw;
priv->udev = udev;
priv->fops = (struct rtl8xxxu_fileops *)id->driver_info;
mutex_init(&priv->usb_buf_mutex);
mutex_init(&priv->h2c_mutex);
INIT_LIST_HEAD(&priv->tx_urb_free_list);
spin_lock_init(&priv->tx_urb_lock);
INIT_LIST_HEAD(&priv->rx_urb_pending_list);
spin_lock_init(&priv->rx_urb_lock);
INIT_WORK(&priv->rx_urb_wq, rtl8xxxu_rx_urb_work);
usb_set_intfdata(interface, hw);
ret = rtl8xxxu_parse_usb(priv, interface);
if (ret)
goto exit;
ret = rtl8xxxu_identify_chip(priv);
if (ret) {
dev_err(&udev->dev, "Fatal - failed to identify chip\n");
goto exit;
}
ret = rtl8xxxu_read_efuse(priv);
if (ret) {
dev_err(&udev->dev, "Fatal - failed to read EFuse\n");
goto exit;
}
ret = priv->fops->parse_efuse(priv);
if (ret) {
dev_err(&udev->dev, "Fatal - failed to parse EFuse\n");
goto exit;
}
rtl8xxxu_print_chipinfo(priv);
ret = priv->fops->load_firmware(priv);
if (ret) {
dev_err(&udev->dev, "Fatal - failed to load firmware\n");
goto exit;
}
ret = rtl8xxxu_init_device(hw);
if (ret)
goto exit;
hw->wiphy->max_scan_ssids = 1;
hw->wiphy->max_scan_ie_len = IEEE80211_MAX_DATA_LEN;
hw->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION);
hw->queues = 4;
sband = &rtl8xxxu_supported_band;
sband->ht_cap.ht_supported = true;
sband->ht_cap.ampdu_factor = IEEE80211_HT_MAX_AMPDU_64K;
sband->ht_cap.ampdu_density = IEEE80211_HT_MPDU_DENSITY_16;
sband->ht_cap.cap = IEEE80211_HT_CAP_SGI_20 | IEEE80211_HT_CAP_SGI_40;
memset(&sband->ht_cap.mcs, 0, sizeof(sband->ht_cap.mcs));
sband->ht_cap.mcs.rx_mask[0] = 0xff;
sband->ht_cap.mcs.rx_mask[4] = 0x01;
if (priv->rf_paths > 1) {
sband->ht_cap.mcs.rx_mask[1] = 0xff;
sband->ht_cap.cap |= IEEE80211_HT_CAP_SGI_40;
}
sband->ht_cap.mcs.tx_params = IEEE80211_HT_MCS_TX_DEFINED;
if (rtl8xxxu_ht40_2g) {
dev_info(&udev->dev, "Enabling HT_20_40 on the 2.4GHz band\n");
sband->ht_cap.cap |= IEEE80211_HT_CAP_SUP_WIDTH_20_40;
}
hw->wiphy->bands[NL80211_BAND_2GHZ] = sband;
hw->wiphy->rts_threshold = 2347;
SET_IEEE80211_DEV(priv->hw, &interface->dev);
SET_IEEE80211_PERM_ADDR(hw, priv->mac_addr);
hw->extra_tx_headroom = priv->fops->tx_desc_size;
ieee80211_hw_set(hw, SIGNAL_DBM);
ieee80211_hw_set(hw, HAS_RATE_CONTROL);
ieee80211_hw_set(hw, AMPDU_AGGREGATION);
wiphy_ext_feature_set(hw->wiphy, NL80211_EXT_FEATURE_CQM_RSSI_LIST);
ret = ieee80211_register_hw(priv->hw);
if (ret) {
dev_err(&udev->dev, "%s: Failed to register: %i\n",
__func__, ret);
goto exit;
}
return 0;
exit:
usb_set_intfdata(interface, NULL);
if (priv) {
kfree(priv->fw_data);
mutex_destroy(&priv->usb_buf_mutex);
mutex_destroy(&priv->h2c_mutex);
}
usb_put_dev(udev);
ieee80211_free_hw(hw);
return ret;
}
static void rtl8xxxu_disconnect(struct usb_interface *interface)
{
struct rtl8xxxu_priv *priv;
struct ieee80211_hw *hw;
hw = usb_get_intfdata(interface);
priv = hw->priv;
ieee80211_unregister_hw(hw);
priv->fops->power_off(priv);
usb_set_intfdata(interface, NULL);
dev_info(&priv->udev->dev, "disconnecting\n");
kfree(priv->fw_data);
mutex_destroy(&priv->usb_buf_mutex);
mutex_destroy(&priv->h2c_mutex);
if (priv->udev->state != USB_STATE_NOTATTACHED) {
dev_info(&priv->udev->dev,
"Device still attached, trying to reset\n");
usb_reset_device(priv->udev);
}
usb_put_dev(priv->udev);
ieee80211_free_hw(hw);
}
static int __init rtl8xxxu_module_init(void)
{
int res;
res = usb_register(&rtl8xxxu_driver);
if (res < 0)
pr_err(DRIVER_NAME ": usb_register() failed (%i)\n", res);
return res;
}
static void __exit rtl8xxxu_module_exit(void)
{
usb_deregister(&rtl8xxxu_driver);
}
