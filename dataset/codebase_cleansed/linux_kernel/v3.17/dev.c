static void rtl8187_iowrite_async_cb(struct urb *urb)
{
kfree(urb->context);
}
static void rtl8187_iowrite_async(struct rtl8187_priv *priv, __le16 addr,
void *data, u16 len)
{
struct usb_ctrlrequest *dr;
struct urb *urb;
struct rtl8187_async_write_data {
u8 data[4];
struct usb_ctrlrequest dr;
} *buf;
int rc;
buf = kmalloc(sizeof(*buf), GFP_ATOMIC);
if (!buf)
return;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
kfree(buf);
return;
}
dr = &buf->dr;
dr->bRequestType = RTL8187_REQT_WRITE;
dr->bRequest = RTL8187_REQ_SET_REG;
dr->wValue = addr;
dr->wIndex = 0;
dr->wLength = cpu_to_le16(len);
memcpy(buf, data, len);
usb_fill_control_urb(urb, priv->udev, usb_sndctrlpipe(priv->udev, 0),
(unsigned char *)dr, buf, len,
rtl8187_iowrite_async_cb, buf);
usb_anchor_urb(urb, &priv->anchored);
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (rc < 0) {
kfree(buf);
usb_unanchor_urb(urb);
}
usb_free_urb(urb);
}
static inline void rtl818x_iowrite32_async(struct rtl8187_priv *priv,
__le32 *addr, u32 val)
{
__le32 buf = cpu_to_le32(val);
rtl8187_iowrite_async(priv, cpu_to_le16((unsigned long)addr),
&buf, sizeof(buf));
}
void rtl8187_write_phy(struct ieee80211_hw *dev, u8 addr, u32 data)
{
struct rtl8187_priv *priv = dev->priv;
data <<= 8;
data |= addr | 0x80;
rtl818x_iowrite8(priv, &priv->map->PHY[3], (data >> 24) & 0xFF);
rtl818x_iowrite8(priv, &priv->map->PHY[2], (data >> 16) & 0xFF);
rtl818x_iowrite8(priv, &priv->map->PHY[1], (data >> 8) & 0xFF);
rtl818x_iowrite8(priv, &priv->map->PHY[0], data & 0xFF);
}
static void rtl8187_tx_cb(struct urb *urb)
{
struct sk_buff *skb = (struct sk_buff *)urb->context;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_hw *hw = info->rate_driver_data[0];
struct rtl8187_priv *priv = hw->priv;
skb_pull(skb, priv->is_rtl8187b ? sizeof(struct rtl8187b_tx_hdr) :
sizeof(struct rtl8187_tx_hdr));
ieee80211_tx_info_clear_status(info);
if (!(urb->status) && !(info->flags & IEEE80211_TX_CTL_NO_ACK)) {
if (priv->is_rtl8187b) {
skb_queue_tail(&priv->b_tx_status.queue, skb);
while (skb_queue_len(&priv->b_tx_status.queue) > 5) {
struct sk_buff *old_skb;
dev_dbg(&priv->udev->dev,
"transmit status queue full\n");
old_skb = skb_dequeue(&priv->b_tx_status.queue);
ieee80211_tx_status_irqsafe(hw, old_skb);
}
return;
} else {
info->flags |= IEEE80211_TX_STAT_ACK;
}
}
if (priv->is_rtl8187b)
ieee80211_tx_status_irqsafe(hw, skb);
else {
skb_queue_tail(&priv->b_tx_status.queue, skb);
ieee80211_queue_delayed_work(hw, &priv->work, 0);
}
}
static void rtl8187_tx(struct ieee80211_hw *dev,
struct ieee80211_tx_control *control,
struct sk_buff *skb)
{
struct rtl8187_priv *priv = dev->priv;
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
struct ieee80211_hdr *tx_hdr = (struct ieee80211_hdr *)(skb->data);
unsigned int ep;
void *buf;
struct urb *urb;
__le16 rts_dur = 0;
u32 flags;
int rc;
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
kfree_skb(skb);
return;
}
flags = skb->len;
flags |= RTL818X_TX_DESC_FLAG_NO_ENC;
flags |= ieee80211_get_tx_rate(dev, info)->hw_value << 24;
if (ieee80211_has_morefrags(tx_hdr->frame_control))
flags |= RTL818X_TX_DESC_FLAG_MOREFRAG;
if (info->control.rates[0].flags & IEEE80211_TX_RC_USE_RTS_CTS) {
flags |= RTL818X_TX_DESC_FLAG_RTS;
flags |= ieee80211_get_rts_cts_rate(dev, info)->hw_value << 19;
rts_dur = ieee80211_rts_duration(dev, priv->vif,
skb->len, info);
} else if (info->control.rates[0].flags & IEEE80211_TX_RC_USE_CTS_PROTECT) {
flags |= RTL818X_TX_DESC_FLAG_RTS | RTL818X_TX_DESC_FLAG_CTS;
flags |= ieee80211_get_rts_cts_rate(dev, info)->hw_value << 19;
rts_dur = ieee80211_ctstoself_duration(dev, priv->vif,
skb->len, info);
}
if (info->flags & IEEE80211_TX_CTL_ASSIGN_SEQ) {
if (info->flags & IEEE80211_TX_CTL_FIRST_FRAGMENT)
priv->seqno += 0x10;
tx_hdr->seq_ctrl &= cpu_to_le16(IEEE80211_SCTL_FRAG);
tx_hdr->seq_ctrl |= cpu_to_le16(priv->seqno);
}
if (!priv->is_rtl8187b) {
struct rtl8187_tx_hdr *hdr =
(struct rtl8187_tx_hdr *)skb_push(skb, sizeof(*hdr));
hdr->flags = cpu_to_le32(flags);
hdr->len = 0;
hdr->rts_duration = rts_dur;
hdr->retry = cpu_to_le32((info->control.rates[0].count - 1) << 8);
buf = hdr;
ep = 2;
} else {
unsigned int epmap[4] = { 6, 7, 5, 4 };
u16 fc = le16_to_cpu(tx_hdr->frame_control);
struct rtl8187b_tx_hdr *hdr =
(struct rtl8187b_tx_hdr *)skb_push(skb, sizeof(*hdr));
struct ieee80211_rate *txrate =
ieee80211_get_tx_rate(dev, info);
memset(hdr, 0, sizeof(*hdr));
hdr->flags = cpu_to_le32(flags);
hdr->rts_duration = rts_dur;
hdr->retry = cpu_to_le32((info->control.rates[0].count - 1) << 8);
hdr->tx_duration =
ieee80211_generic_frame_duration(dev, priv->vif,
info->band,
skb->len, txrate);
buf = hdr;
if ((fc & IEEE80211_FCTL_FTYPE) == IEEE80211_FTYPE_MGMT)
ep = 12;
else
ep = epmap[skb_get_queue_mapping(skb)];
}
info->rate_driver_data[0] = dev;
info->rate_driver_data[1] = urb;
usb_fill_bulk_urb(urb, priv->udev, usb_sndbulkpipe(priv->udev, ep),
buf, skb->len, rtl8187_tx_cb, skb);
urb->transfer_flags |= URB_ZERO_PACKET;
usb_anchor_urb(urb, &priv->anchored);
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (rc < 0) {
usb_unanchor_urb(urb);
kfree_skb(skb);
}
usb_free_urb(urb);
}
static void rtl8187_rx_cb(struct urb *urb)
{
struct sk_buff *skb = (struct sk_buff *)urb->context;
struct rtl8187_rx_info *info = (struct rtl8187_rx_info *)skb->cb;
struct ieee80211_hw *dev = info->dev;
struct rtl8187_priv *priv = dev->priv;
struct ieee80211_rx_status rx_status = { 0 };
int rate, signal;
u32 flags;
unsigned long f;
spin_lock_irqsave(&priv->rx_queue.lock, f);
__skb_unlink(skb, &priv->rx_queue);
spin_unlock_irqrestore(&priv->rx_queue.lock, f);
skb_put(skb, urb->actual_length);
if (unlikely(urb->status)) {
dev_kfree_skb_irq(skb);
return;
}
if (!priv->is_rtl8187b) {
struct rtl8187_rx_hdr *hdr =
(typeof(hdr))(skb_tail_pointer(skb) - sizeof(*hdr));
flags = le32_to_cpu(hdr->flags);
signal = -4 - ((27 * hdr->agc) >> 6);
rx_status.antenna = (hdr->signal >> 7) & 1;
rx_status.mactime = le64_to_cpu(hdr->mac_time);
} else {
struct rtl8187b_rx_hdr *hdr =
(typeof(hdr))(skb_tail_pointer(skb) - sizeof(*hdr));
flags = le32_to_cpu(hdr->flags);
signal = 14 - hdr->agc / 2;
rx_status.antenna = (hdr->rssi >> 7) & 1;
rx_status.mactime = le64_to_cpu(hdr->mac_time);
}
rx_status.signal = signal;
priv->signal = signal;
rate = (flags >> 20) & 0xF;
skb_trim(skb, flags & 0x0FFF);
rx_status.rate_idx = rate;
rx_status.freq = dev->conf.chandef.chan->center_freq;
rx_status.band = dev->conf.chandef.chan->band;
rx_status.flag |= RX_FLAG_MACTIME_START;
if (flags & RTL818X_RX_DESC_FLAG_SPLCP)
rx_status.flag |= RX_FLAG_SHORTPRE;
if (flags & RTL818X_RX_DESC_FLAG_CRC32_ERR)
rx_status.flag |= RX_FLAG_FAILED_FCS_CRC;
memcpy(IEEE80211_SKB_RXCB(skb), &rx_status, sizeof(rx_status));
ieee80211_rx_irqsafe(dev, skb);
skb = dev_alloc_skb(RTL8187_MAX_RX);
if (unlikely(!skb)) {
return;
}
info = (struct rtl8187_rx_info *)skb->cb;
info->urb = urb;
info->dev = dev;
urb->transfer_buffer = skb_tail_pointer(skb);
urb->context = skb;
skb_queue_tail(&priv->rx_queue, skb);
usb_anchor_urb(urb, &priv->anchored);
if (usb_submit_urb(urb, GFP_ATOMIC)) {
usb_unanchor_urb(urb);
skb_unlink(skb, &priv->rx_queue);
dev_kfree_skb_irq(skb);
}
}
static int rtl8187_init_urbs(struct ieee80211_hw *dev)
{
struct rtl8187_priv *priv = dev->priv;
struct urb *entry = NULL;
struct sk_buff *skb;
struct rtl8187_rx_info *info;
int ret = 0;
while (skb_queue_len(&priv->rx_queue) < 32) {
skb = __dev_alloc_skb(RTL8187_MAX_RX, GFP_KERNEL);
if (!skb) {
ret = -ENOMEM;
goto err;
}
entry = usb_alloc_urb(0, GFP_KERNEL);
if (!entry) {
ret = -ENOMEM;
goto err;
}
usb_fill_bulk_urb(entry, priv->udev,
usb_rcvbulkpipe(priv->udev,
priv->is_rtl8187b ? 3 : 1),
skb_tail_pointer(skb),
RTL8187_MAX_RX, rtl8187_rx_cb, skb);
info = (struct rtl8187_rx_info *)skb->cb;
info->urb = entry;
info->dev = dev;
skb_queue_tail(&priv->rx_queue, skb);
usb_anchor_urb(entry, &priv->anchored);
ret = usb_submit_urb(entry, GFP_KERNEL);
usb_put_urb(entry);
if (ret) {
skb_unlink(skb, &priv->rx_queue);
usb_unanchor_urb(entry);
goto err;
}
}
return ret;
err:
kfree_skb(skb);
usb_kill_anchored_urbs(&priv->anchored);
return ret;
}
static void rtl8187b_status_cb(struct urb *urb)
{
struct ieee80211_hw *hw = (struct ieee80211_hw *)urb->context;
struct rtl8187_priv *priv = hw->priv;
u64 val;
unsigned int cmd_type;
if (unlikely(urb->status))
return;
val = le64_to_cpu(priv->b_tx_status.buf);
cmd_type = (val >> 30) & 0x3;
if (cmd_type == 1) {
unsigned int pkt_rc, seq_no;
bool tok;
struct sk_buff *skb;
struct ieee80211_hdr *ieee80211hdr;
unsigned long flags;
pkt_rc = val & 0xFF;
tok = val & (1 << 15);
seq_no = (val >> 16) & 0xFFF;
spin_lock_irqsave(&priv->b_tx_status.queue.lock, flags);
skb_queue_reverse_walk(&priv->b_tx_status.queue, skb) {
ieee80211hdr = (struct ieee80211_hdr *)skb->data;
if ((le16_to_cpu(ieee80211hdr->seq_ctrl)
& 0xFFF) == seq_no)
break;
}
if (skb != (struct sk_buff *) &priv->b_tx_status.queue) {
struct ieee80211_tx_info *info = IEEE80211_SKB_CB(skb);
__skb_unlink(skb, &priv->b_tx_status.queue);
if (tok)
info->flags |= IEEE80211_TX_STAT_ACK;
info->status.rates[0].count = pkt_rc + 1;
ieee80211_tx_status_irqsafe(hw, skb);
}
spin_unlock_irqrestore(&priv->b_tx_status.queue.lock, flags);
}
usb_anchor_urb(urb, &priv->anchored);
if (usb_submit_urb(urb, GFP_ATOMIC))
usb_unanchor_urb(urb);
}
static int rtl8187b_init_status_urb(struct ieee80211_hw *dev)
{
struct rtl8187_priv *priv = dev->priv;
struct urb *entry;
int ret = 0;
entry = usb_alloc_urb(0, GFP_KERNEL);
if (!entry)
return -ENOMEM;
usb_fill_bulk_urb(entry, priv->udev, usb_rcvbulkpipe(priv->udev, 9),
&priv->b_tx_status.buf, sizeof(priv->b_tx_status.buf),
rtl8187b_status_cb, dev);
usb_anchor_urb(entry, &priv->anchored);
ret = usb_submit_urb(entry, GFP_KERNEL);
if (ret)
usb_unanchor_urb(entry);
usb_free_urb(entry);
return ret;
}
static void rtl8187_set_anaparam(struct rtl8187_priv *priv, bool rfon)
{
u32 anaparam, anaparam2;
u8 anaparam3, reg;
if (!priv->is_rtl8187b) {
if (rfon) {
anaparam = RTL8187_RTL8225_ANAPARAM_ON;
anaparam2 = RTL8187_RTL8225_ANAPARAM2_ON;
} else {
anaparam = RTL8187_RTL8225_ANAPARAM_OFF;
anaparam2 = RTL8187_RTL8225_ANAPARAM2_OFF;
}
} else {
if (rfon) {
anaparam = RTL8187B_RTL8225_ANAPARAM_ON;
anaparam2 = RTL8187B_RTL8225_ANAPARAM2_ON;
anaparam3 = RTL8187B_RTL8225_ANAPARAM3_ON;
} else {
anaparam = RTL8187B_RTL8225_ANAPARAM_OFF;
anaparam2 = RTL8187B_RTL8225_ANAPARAM2_OFF;
anaparam3 = RTL8187B_RTL8225_ANAPARAM3_OFF;
}
}
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD,
RTL818X_EEPROM_CMD_CONFIG);
reg = rtl818x_ioread8(priv, &priv->map->CONFIG3);
reg |= RTL818X_CONFIG3_ANAPARAM_WRITE;
rtl818x_iowrite8(priv, &priv->map->CONFIG3, reg);
rtl818x_iowrite32(priv, &priv->map->ANAPARAM, anaparam);
rtl818x_iowrite32(priv, &priv->map->ANAPARAM2, anaparam2);
if (priv->is_rtl8187b)
rtl818x_iowrite8(priv, &priv->map->ANAPARAM3A, anaparam3);
reg &= ~RTL818X_CONFIG3_ANAPARAM_WRITE;
rtl818x_iowrite8(priv, &priv->map->CONFIG3, reg);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD,
RTL818X_EEPROM_CMD_NORMAL);
}
static int rtl8187_cmd_reset(struct ieee80211_hw *dev)
{
struct rtl8187_priv *priv = dev->priv;
u8 reg;
int i;
reg = rtl818x_ioread8(priv, &priv->map->CMD);
reg &= (1 << 1);
reg |= RTL818X_CMD_RESET;
rtl818x_iowrite8(priv, &priv->map->CMD, reg);
i = 10;
do {
msleep(2);
if (!(rtl818x_ioread8(priv, &priv->map->CMD) &
RTL818X_CMD_RESET))
break;
} while (--i);
if (!i) {
wiphy_err(dev->wiphy, "Reset timeout!\n");
return -ETIMEDOUT;
}
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_LOAD);
i = 10;
do {
msleep(4);
if (!(rtl818x_ioread8(priv, &priv->map->EEPROM_CMD) &
RTL818X_EEPROM_CMD_CONFIG))
break;
} while (--i);
if (!i) {
wiphy_err(dev->wiphy, "eeprom reset timeout!\n");
return -ETIMEDOUT;
}
return 0;
}
static int rtl8187_init_hw(struct ieee80211_hw *dev)
{
struct rtl8187_priv *priv = dev->priv;
u8 reg;
int res;
rtl8187_set_anaparam(priv, true);
rtl818x_iowrite16(priv, &priv->map->INT_MASK, 0);
msleep(200);
rtl818x_iowrite8(priv, (u8 *)0xFE18, 0x10);
rtl818x_iowrite8(priv, (u8 *)0xFE18, 0x11);
rtl818x_iowrite8(priv, (u8 *)0xFE18, 0x00);
msleep(200);
res = rtl8187_cmd_reset(dev);
if (res)
return res;
rtl8187_set_anaparam(priv, true);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, 0);
rtl818x_iowrite8(priv, &priv->map->GPIO0, 0);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, (4 << 8));
rtl818x_iowrite8(priv, &priv->map->GPIO0, 1);
rtl818x_iowrite8(priv, &priv->map->GP_ENABLE, 0);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
rtl818x_iowrite16(priv, (__le16 *)0xFFF4, 0xFFFF);
reg = rtl818x_ioread8(priv, &priv->map->CONFIG1);
reg &= 0x3F;
reg |= 0x80;
rtl818x_iowrite8(priv, &priv->map->CONFIG1, reg);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);
rtl818x_iowrite32(priv, &priv->map->INT_TIMEOUT, 0);
rtl818x_iowrite8(priv, &priv->map->WPA_CONF, 0);
rtl818x_iowrite8(priv, &priv->map->RATE_FALLBACK, 0);
rtl818x_iowrite8(priv, &priv->map->RESP_RATE, (8 << 4) | 0);
rtl818x_iowrite16(priv, &priv->map->BRSR, 0x01F3);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, 0);
rtl818x_iowrite8(priv, &priv->map->GPIO0, 0);
reg = rtl818x_ioread8(priv, (u8 *)0xFE53);
rtl818x_iowrite8(priv, (u8 *)0xFE53, reg | (1 << 7));
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, (4 << 8));
rtl818x_iowrite8(priv, &priv->map->GPIO0, 0x20);
rtl818x_iowrite8(priv, &priv->map->GP_ENABLE, 0);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, 0x80);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, 0x80);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x80);
msleep(100);
rtl818x_iowrite32(priv, &priv->map->RF_TIMING, 0x000a8008);
rtl818x_iowrite16(priv, &priv->map->BRSR, 0xFFFF);
rtl818x_iowrite32(priv, &priv->map->RF_PARA, 0x00100044);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD,
RTL818X_EEPROM_CMD_CONFIG);
rtl818x_iowrite8(priv, &priv->map->CONFIG3, 0x44);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD,
RTL818X_EEPROM_CMD_NORMAL);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FF7);
msleep(100);
priv->rf->init(dev);
rtl818x_iowrite16(priv, &priv->map->BRSR, 0x01F3);
reg = rtl818x_ioread8(priv, &priv->map->PGSELECT) & ~1;
rtl818x_iowrite8(priv, &priv->map->PGSELECT, reg | 1);
rtl818x_iowrite16(priv, (__le16 *)0xFFFE, 0x10);
rtl818x_iowrite8(priv, &priv->map->TALLY_SEL, 0x80);
rtl818x_iowrite8(priv, (u8 *)0xFFFF, 0x60);
rtl818x_iowrite8(priv, &priv->map->PGSELECT, reg);
return 0;
}
static int rtl8187b_init_hw(struct ieee80211_hw *dev)
{
struct rtl8187_priv *priv = dev->priv;
int res, i;
u8 reg;
rtl8187_set_anaparam(priv, true);
rtl818x_iowrite8(priv, (u8 *)0xFF61, 0x10);
reg = rtl818x_ioread8(priv, (u8 *)0xFF62);
rtl818x_iowrite8(priv, (u8 *)0xFF62, reg & ~(1 << 5));
rtl818x_iowrite8(priv, (u8 *)0xFF62, reg | (1 << 5));
res = rtl8187_cmd_reset(dev);
if (res)
return res;
rtl8187_set_anaparam(priv, true);
rtl818x_iowrite16(priv, (__le16 *)0xFF34, 0x0FFF);
reg = rtl818x_ioread8(priv, &priv->map->CW_CONF);
reg |= RTL818X_CW_CONF_PERPACKET_RETRY;
rtl818x_iowrite8(priv, &priv->map->CW_CONF, reg);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFFE0, 0x0FFF, 1);
rtl818x_iowrite8_idx(priv, (u8 *)0xFFE2, 0x00, 1);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFFD4, 0xFFFF, 1);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD,
RTL818X_EEPROM_CMD_CONFIG);
reg = rtl818x_ioread8(priv, &priv->map->CONFIG1);
rtl818x_iowrite8(priv, &priv->map->CONFIG1, (reg & 0x3F) | 0x80);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD,
RTL818X_EEPROM_CMD_NORMAL);
rtl818x_iowrite8(priv, &priv->map->WPA_CONF, 0);
for (i = 0; i < ARRAY_SIZE(rtl8187b_reg_table); i++) {
rtl818x_iowrite8_idx(priv,
(u8 *)(uintptr_t)
(rtl8187b_reg_table[i][0] | 0xFF00),
rtl8187b_reg_table[i][1],
rtl8187b_reg_table[i][2]);
}
rtl818x_iowrite16(priv, &priv->map->TID_AC_MAP, 0xFA50);
rtl818x_iowrite16(priv, &priv->map->INT_MIG, 0);
rtl818x_iowrite32_idx(priv, (__le32 *)0xFFF0, 0, 1);
rtl818x_iowrite32_idx(priv, (__le32 *)0xFFF4, 0, 1);
rtl818x_iowrite8_idx(priv, (u8 *)0xFFF8, 0, 1);
rtl818x_iowrite32(priv, &priv->map->RF_TIMING, 0x00004001);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFF72, 0x569A, 2);
rtl818x_iowrite16(priv, &priv->map->RFPinsOutput, 0x0480);
rtl818x_iowrite16(priv, &priv->map->RFPinsSelect, 0x2488);
rtl818x_iowrite16(priv, &priv->map->RFPinsEnable, 0x1FFF);
msleep(100);
priv->rf->init(dev);
reg = RTL818X_CMD_TX_ENABLE | RTL818X_CMD_RX_ENABLE;
rtl818x_iowrite8(priv, &priv->map->CMD, reg);
rtl818x_iowrite16(priv, &priv->map->INT_MASK, 0xFFFF);
rtl818x_iowrite8(priv, (u8 *)0xFE41, 0xF4);
rtl818x_iowrite8(priv, (u8 *)0xFE40, 0x00);
rtl818x_iowrite8(priv, (u8 *)0xFE42, 0x00);
rtl818x_iowrite8(priv, (u8 *)0xFE42, 0x01);
rtl818x_iowrite8(priv, (u8 *)0xFE40, 0x0F);
rtl818x_iowrite8(priv, (u8 *)0xFE42, 0x00);
rtl818x_iowrite8(priv, (u8 *)0xFE42, 0x01);
reg = rtl818x_ioread8(priv, (u8 *)0xFFDB);
rtl818x_iowrite8(priv, (u8 *)0xFFDB, reg | (1 << 2));
rtl818x_iowrite16_idx(priv, (__le16 *)0xFF72, 0x59FA, 3);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFF74, 0x59D2, 3);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFF76, 0x59D2, 3);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFF78, 0x19FA, 3);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFF7A, 0x19FA, 3);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFF7C, 0x00D0, 3);
rtl818x_iowrite8(priv, (u8 *)0xFF61, 0);
rtl818x_iowrite8_idx(priv, (u8 *)0xFF80, 0x0F, 1);
rtl818x_iowrite8_idx(priv, (u8 *)0xFF83, 0x03, 1);
rtl818x_iowrite8(priv, (u8 *)0xFFDA, 0x10);
rtl818x_iowrite8_idx(priv, (u8 *)0xFF4D, 0x08, 2);
rtl818x_iowrite32(priv, &priv->map->HSSI_PARA, 0x0600321B);
rtl818x_iowrite16_idx(priv, (__le16 *)0xFFEC, 0x0800, 1);
priv->slot_time = 0x9;
priv->aifsn[0] = 2;
priv->aifsn[1] = 2;
priv->aifsn[2] = 7;
priv->aifsn[3] = 3;
rtl818x_iowrite8(priv, &priv->map->ACM_CONTROL, 0);
rtl818x_iowrite8(priv, &priv->map->MSR, RTL818X_MSR_ENEDCA);
return 0;
}
static void rtl8187_work(struct work_struct *work)
{
struct rtl8187_priv *priv = container_of(work, struct rtl8187_priv,
work.work);
struct ieee80211_tx_info *info;
struct ieee80211_hw *dev = priv->dev;
static u16 retry;
u16 tmp;
u16 avg_retry;
int length;
mutex_lock(&priv->conf_mutex);
tmp = rtl818x_ioread16(priv, (__le16 *)0xFFFA);
length = skb_queue_len(&priv->b_tx_status.queue);
if (unlikely(!length))
length = 1;
if (unlikely(tmp < retry))
tmp = retry;
avg_retry = (tmp - retry) / length;
while (skb_queue_len(&priv->b_tx_status.queue) > 0) {
struct sk_buff *old_skb;
old_skb = skb_dequeue(&priv->b_tx_status.queue);
info = IEEE80211_SKB_CB(old_skb);
info->status.rates[0].count = avg_retry + 1;
if (info->status.rates[0].count > RETRY_COUNT)
info->flags &= ~IEEE80211_TX_STAT_ACK;
ieee80211_tx_status_irqsafe(dev, old_skb);
}
retry = tmp;
mutex_unlock(&priv->conf_mutex);
}
static int rtl8187_start(struct ieee80211_hw *dev)
{
struct rtl8187_priv *priv = dev->priv;
u32 reg;
int ret;
mutex_lock(&priv->conf_mutex);
ret = (!priv->is_rtl8187b) ? rtl8187_init_hw(dev) :
rtl8187b_init_hw(dev);
if (ret)
goto rtl8187_start_exit;
init_usb_anchor(&priv->anchored);
priv->dev = dev;
if (priv->is_rtl8187b) {
reg = RTL818X_RX_CONF_MGMT |
RTL818X_RX_CONF_DATA |
RTL818X_RX_CONF_BROADCAST |
RTL818X_RX_CONF_NICMAC |
RTL818X_RX_CONF_BSSID |
(7 << 13 ) |
(7 << 10 ) |
RTL818X_RX_CONF_RX_AUTORESETPHY |
RTL818X_RX_CONF_ONLYERLPKT |
RTL818X_RX_CONF_MULTICAST;
priv->rx_conf = reg;
rtl818x_iowrite32(priv, &priv->map->RX_CONF, reg);
reg = rtl818x_ioread8(priv, &priv->map->TX_AGC_CTL);
reg &= ~RTL818X_TX_AGC_CTL_PERPACKET_GAIN;
reg &= ~RTL818X_TX_AGC_CTL_PERPACKET_ANTSEL;
reg &= ~RTL818X_TX_AGC_CTL_FEEDBACK_ANT;
rtl818x_iowrite8(priv, &priv->map->TX_AGC_CTL, reg);
rtl818x_iowrite32(priv, &priv->map->TX_CONF,
RTL818X_TX_CONF_HW_SEQNUM |
RTL818X_TX_CONF_DISREQQSIZE |
(RETRY_COUNT << 8 ) |
(RETRY_COUNT << 0 ) |
(7 << 21 ));
ret = rtl8187_init_urbs(dev);
if (ret)
goto rtl8187_start_exit;
ret = rtl8187b_init_status_urb(dev);
if (ret)
usb_kill_anchored_urbs(&priv->anchored);
goto rtl8187_start_exit;
}
rtl818x_iowrite16(priv, &priv->map->INT_MASK, 0xFFFF);
rtl818x_iowrite32(priv, &priv->map->MAR[0], ~0);
rtl818x_iowrite32(priv, &priv->map->MAR[1], ~0);
ret = rtl8187_init_urbs(dev);
if (ret)
goto rtl8187_start_exit;
reg = RTL818X_RX_CONF_ONLYERLPKT |
RTL818X_RX_CONF_RX_AUTORESETPHY |
RTL818X_RX_CONF_BSSID |
RTL818X_RX_CONF_MGMT |
RTL818X_RX_CONF_DATA |
(7 << 13 ) |
(7 << 10 ) |
RTL818X_RX_CONF_BROADCAST |
RTL818X_RX_CONF_NICMAC;
priv->rx_conf = reg;
rtl818x_iowrite32(priv, &priv->map->RX_CONF, reg);
reg = rtl818x_ioread8(priv, &priv->map->CW_CONF);
reg &= ~RTL818X_CW_CONF_PERPACKET_CW;
reg |= RTL818X_CW_CONF_PERPACKET_RETRY;
rtl818x_iowrite8(priv, &priv->map->CW_CONF, reg);
reg = rtl818x_ioread8(priv, &priv->map->TX_AGC_CTL);
reg &= ~RTL818X_TX_AGC_CTL_PERPACKET_GAIN;
reg &= ~RTL818X_TX_AGC_CTL_PERPACKET_ANTSEL;
reg &= ~RTL818X_TX_AGC_CTL_FEEDBACK_ANT;
rtl818x_iowrite8(priv, &priv->map->TX_AGC_CTL, reg);
reg = RTL818X_TX_CONF_CW_MIN |
(7 << 21 ) |
RTL818X_TX_CONF_NO_ICV;
rtl818x_iowrite32(priv, &priv->map->TX_CONF, reg);
reg = rtl818x_ioread8(priv, &priv->map->CMD);
reg |= RTL818X_CMD_TX_ENABLE;
reg |= RTL818X_CMD_RX_ENABLE;
rtl818x_iowrite8(priv, &priv->map->CMD, reg);
INIT_DELAYED_WORK(&priv->work, rtl8187_work);
rtl8187_start_exit:
mutex_unlock(&priv->conf_mutex);
return ret;
}
static void rtl8187_stop(struct ieee80211_hw *dev)
{
struct rtl8187_priv *priv = dev->priv;
struct sk_buff *skb;
u32 reg;
mutex_lock(&priv->conf_mutex);
rtl818x_iowrite16(priv, &priv->map->INT_MASK, 0);
reg = rtl818x_ioread8(priv, &priv->map->CMD);
reg &= ~RTL818X_CMD_TX_ENABLE;
reg &= ~RTL818X_CMD_RX_ENABLE;
rtl818x_iowrite8(priv, &priv->map->CMD, reg);
priv->rf->stop(dev);
rtl8187_set_anaparam(priv, false);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
reg = rtl818x_ioread8(priv, &priv->map->CONFIG4);
rtl818x_iowrite8(priv, &priv->map->CONFIG4, reg | RTL818X_CONFIG4_VCOOFF);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);
while ((skb = skb_dequeue(&priv->b_tx_status.queue)))
dev_kfree_skb_any(skb);
usb_kill_anchored_urbs(&priv->anchored);
mutex_unlock(&priv->conf_mutex);
if (!priv->is_rtl8187b)
cancel_delayed_work_sync(&priv->work);
}
static u64 rtl8187_get_tsf(struct ieee80211_hw *dev, struct ieee80211_vif *vif)
{
struct rtl8187_priv *priv = dev->priv;
return rtl818x_ioread32(priv, &priv->map->TSFT[0]) |
(u64)(rtl818x_ioread32(priv, &priv->map->TSFT[1])) << 32;
}
static void rtl8187_beacon_work(struct work_struct *work)
{
struct rtl8187_vif *vif_priv =
container_of(work, struct rtl8187_vif, beacon_work.work);
struct ieee80211_vif *vif =
container_of((void *)vif_priv, struct ieee80211_vif, drv_priv);
struct ieee80211_hw *dev = vif_priv->dev;
struct ieee80211_mgmt *mgmt;
struct sk_buff *skb;
if (ieee80211_queue_stopped(dev, 0))
goto resched;
skb = ieee80211_beacon_get(dev, vif);
if (!skb)
goto resched;
mgmt = (struct ieee80211_mgmt *)skb->data;
mgmt->u.beacon.timestamp = cpu_to_le64(rtl8187_get_tsf(dev, vif));
skb_set_queue_mapping(skb, 0);
rtl8187_tx(dev, NULL, skb);
resched:
schedule_delayed_work(&vif_priv->beacon_work,
usecs_to_jiffies(1024 * vif->bss_conf.beacon_int));
}
static int rtl8187_add_interface(struct ieee80211_hw *dev,
struct ieee80211_vif *vif)
{
struct rtl8187_priv *priv = dev->priv;
struct rtl8187_vif *vif_priv;
int i;
int ret = -EOPNOTSUPP;
mutex_lock(&priv->conf_mutex);
if (priv->vif)
goto exit;
switch (vif->type) {
case NL80211_IFTYPE_STATION:
case NL80211_IFTYPE_ADHOC:
break;
default:
goto exit;
}
ret = 0;
priv->vif = vif;
vif_priv = (struct rtl8187_vif *)&vif->drv_priv;
vif_priv->dev = dev;
INIT_DELAYED_WORK(&vif_priv->beacon_work, rtl8187_beacon_work);
vif_priv->enable_beacon = false;
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
for (i = 0; i < ETH_ALEN; i++)
rtl818x_iowrite8(priv, &priv->map->MAC[i],
((u8 *)vif->addr)[i]);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);
exit:
mutex_unlock(&priv->conf_mutex);
return ret;
}
static void rtl8187_remove_interface(struct ieee80211_hw *dev,
struct ieee80211_vif *vif)
{
struct rtl8187_priv *priv = dev->priv;
mutex_lock(&priv->conf_mutex);
priv->vif = NULL;
mutex_unlock(&priv->conf_mutex);
}
static int rtl8187_config(struct ieee80211_hw *dev, u32 changed)
{
struct rtl8187_priv *priv = dev->priv;
struct ieee80211_conf *conf = &dev->conf;
u32 reg;
mutex_lock(&priv->conf_mutex);
reg = rtl818x_ioread32(priv, &priv->map->TX_CONF);
rtl818x_iowrite32(priv, &priv->map->TX_CONF,
reg | RTL818X_TX_CONF_LOOPBACK_MAC);
priv->rf->set_chan(dev, conf);
msleep(10);
rtl818x_iowrite32(priv, &priv->map->TX_CONF, reg);
rtl818x_iowrite16(priv, &priv->map->ATIM_WND, 2);
rtl818x_iowrite16(priv, &priv->map->ATIMTR_INTERVAL, 100);
rtl818x_iowrite16(priv, &priv->map->BEACON_INTERVAL, 100);
rtl818x_iowrite16(priv, &priv->map->BEACON_INTERVAL_TIME, 100);
mutex_unlock(&priv->conf_mutex);
return 0;
}
static void rtl8187_conf_erp(struct rtl8187_priv *priv, bool use_short_slot,
bool use_short_preamble)
{
if (priv->is_rtl8187b) {
u8 difs, eifs;
u16 ack_timeout;
int queue;
if (use_short_slot) {
priv->slot_time = 0x9;
difs = 0x1c;
eifs = 0x53;
} else {
priv->slot_time = 0x14;
difs = 0x32;
eifs = 0x5b;
}
rtl818x_iowrite8(priv, &priv->map->SIFS, 0x22);
rtl818x_iowrite8(priv, &priv->map->SLOT, priv->slot_time);
rtl818x_iowrite8(priv, &priv->map->DIFS, difs);
rtl818x_iowrite8(priv, (u8 *)&priv->map->BRSR + 1, eifs);
ack_timeout = 112 + 48 + difs;
if (use_short_preamble)
ack_timeout += 72;
else
ack_timeout += 144;
rtl818x_iowrite8(priv, &priv->map->CARRIER_SENSE_COUNTER,
DIV_ROUND_UP(ack_timeout, 4));
for (queue = 0; queue < 4; queue++)
rtl818x_iowrite8(priv, (u8 *) rtl8187b_ac_addr[queue],
priv->aifsn[queue] * priv->slot_time +
SIFS_TIME);
} else {
rtl818x_iowrite8(priv, &priv->map->SIFS, 0x22);
if (use_short_slot) {
rtl818x_iowrite8(priv, &priv->map->SLOT, 0x9);
rtl818x_iowrite8(priv, &priv->map->DIFS, 0x14);
rtl818x_iowrite8(priv, &priv->map->EIFS, 91 - 0x14);
} else {
rtl818x_iowrite8(priv, &priv->map->SLOT, 0x14);
rtl818x_iowrite8(priv, &priv->map->DIFS, 0x24);
rtl818x_iowrite8(priv, &priv->map->EIFS, 91 - 0x24);
}
}
}
static void rtl8187_bss_info_changed(struct ieee80211_hw *dev,
struct ieee80211_vif *vif,
struct ieee80211_bss_conf *info,
u32 changed)
{
struct rtl8187_priv *priv = dev->priv;
struct rtl8187_vif *vif_priv;
int i;
u8 reg;
vif_priv = (struct rtl8187_vif *)&vif->drv_priv;
if (changed & BSS_CHANGED_BSSID) {
mutex_lock(&priv->conf_mutex);
for (i = 0; i < ETH_ALEN; i++)
rtl818x_iowrite8(priv, &priv->map->BSSID[i],
info->bssid[i]);
if (priv->is_rtl8187b)
reg = RTL818X_MSR_ENEDCA;
else
reg = 0;
if (is_valid_ether_addr(info->bssid)) {
if (vif->type == NL80211_IFTYPE_ADHOC)
reg |= RTL818X_MSR_ADHOC;
else
reg |= RTL818X_MSR_INFRA;
}
else
reg |= RTL818X_MSR_NO_LINK;
rtl818x_iowrite8(priv, &priv->map->MSR, reg);
mutex_unlock(&priv->conf_mutex);
}
if (changed & (BSS_CHANGED_ERP_SLOT | BSS_CHANGED_ERP_PREAMBLE))
rtl8187_conf_erp(priv, info->use_short_slot,
info->use_short_preamble);
if (changed & BSS_CHANGED_BEACON_ENABLED)
vif_priv->enable_beacon = info->enable_beacon;
if (changed & (BSS_CHANGED_BEACON_ENABLED | BSS_CHANGED_BEACON)) {
cancel_delayed_work_sync(&vif_priv->beacon_work);
if (vif_priv->enable_beacon)
schedule_work(&vif_priv->beacon_work.work);
}
}
static u64 rtl8187_prepare_multicast(struct ieee80211_hw *dev,
struct netdev_hw_addr_list *mc_list)
{
return netdev_hw_addr_list_count(mc_list);
}
static void rtl8187_configure_filter(struct ieee80211_hw *dev,
unsigned int changed_flags,
unsigned int *total_flags,
u64 multicast)
{
struct rtl8187_priv *priv = dev->priv;
if (changed_flags & FIF_FCSFAIL)
priv->rx_conf ^= RTL818X_RX_CONF_FCS;
if (changed_flags & FIF_CONTROL)
priv->rx_conf ^= RTL818X_RX_CONF_CTRL;
if (changed_flags & FIF_OTHER_BSS)
priv->rx_conf ^= RTL818X_RX_CONF_MONITOR;
if (*total_flags & FIF_ALLMULTI || multicast > 0)
priv->rx_conf |= RTL818X_RX_CONF_MULTICAST;
else
priv->rx_conf &= ~RTL818X_RX_CONF_MULTICAST;
*total_flags = 0;
if (priv->rx_conf & RTL818X_RX_CONF_FCS)
*total_flags |= FIF_FCSFAIL;
if (priv->rx_conf & RTL818X_RX_CONF_CTRL)
*total_flags |= FIF_CONTROL;
if (priv->rx_conf & RTL818X_RX_CONF_MONITOR)
*total_flags |= FIF_OTHER_BSS;
if (priv->rx_conf & RTL818X_RX_CONF_MULTICAST)
*total_flags |= FIF_ALLMULTI;
rtl818x_iowrite32_async(priv, &priv->map->RX_CONF, priv->rx_conf);
}
static int rtl8187_conf_tx(struct ieee80211_hw *dev,
struct ieee80211_vif *vif, u16 queue,
const struct ieee80211_tx_queue_params *params)
{
struct rtl8187_priv *priv = dev->priv;
u8 cw_min, cw_max;
if (queue > 3)
return -EINVAL;
cw_min = fls(params->cw_min);
cw_max = fls(params->cw_max);
if (priv->is_rtl8187b) {
priv->aifsn[queue] = params->aifs;
rtl818x_iowrite32(priv, rtl8187b_ac_addr[queue],
(params->txop << 16) | (cw_max << 12) |
(cw_min << 8) | (params->aifs *
priv->slot_time + SIFS_TIME));
} else {
if (queue != 0)
return -EINVAL;
rtl818x_iowrite8(priv, &priv->map->CW_VAL,
cw_min | (cw_max << 4));
}
return 0;
}
static void rtl8187_eeprom_register_read(struct eeprom_93cx6 *eeprom)
{
struct ieee80211_hw *dev = eeprom->data;
struct rtl8187_priv *priv = dev->priv;
u8 reg = rtl818x_ioread8(priv, &priv->map->EEPROM_CMD);
eeprom->reg_data_in = reg & RTL818X_EEPROM_CMD_WRITE;
eeprom->reg_data_out = reg & RTL818X_EEPROM_CMD_READ;
eeprom->reg_data_clock = reg & RTL818X_EEPROM_CMD_CK;
eeprom->reg_chip_select = reg & RTL818X_EEPROM_CMD_CS;
}
static void rtl8187_eeprom_register_write(struct eeprom_93cx6 *eeprom)
{
struct ieee80211_hw *dev = eeprom->data;
struct rtl8187_priv *priv = dev->priv;
u8 reg = RTL818X_EEPROM_CMD_PROGRAM;
if (eeprom->reg_data_in)
reg |= RTL818X_EEPROM_CMD_WRITE;
if (eeprom->reg_data_out)
reg |= RTL818X_EEPROM_CMD_READ;
if (eeprom->reg_data_clock)
reg |= RTL818X_EEPROM_CMD_CK;
if (eeprom->reg_chip_select)
reg |= RTL818X_EEPROM_CMD_CS;
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, reg);
udelay(10);
}
static int rtl8187_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct ieee80211_hw *dev;
struct rtl8187_priv *priv;
struct eeprom_93cx6 eeprom;
struct ieee80211_channel *channel;
const char *chip_name;
u16 txpwr, reg;
u16 product_id = le16_to_cpu(udev->descriptor.idProduct);
int err, i;
u8 mac_addr[ETH_ALEN];
dev = ieee80211_alloc_hw(sizeof(*priv), &rtl8187_ops);
if (!dev) {
printk(KERN_ERR "rtl8187: ieee80211 alloc failed\n");
return -ENOMEM;
}
priv = dev->priv;
priv->is_rtl8187b = (id->driver_info == DEVICE_RTL8187B);
priv->io_dmabuf = kmalloc(sizeof(*priv->io_dmabuf), GFP_KERNEL);
if (!priv->io_dmabuf) {
err = -ENOMEM;
goto err_free_dev;
}
mutex_init(&priv->io_mutex);
SET_IEEE80211_DEV(dev, &intf->dev);
usb_set_intfdata(intf, dev);
priv->udev = udev;
usb_get_dev(udev);
skb_queue_head_init(&priv->rx_queue);
BUILD_BUG_ON(sizeof(priv->channels) != sizeof(rtl818x_channels));
BUILD_BUG_ON(sizeof(priv->rates) != sizeof(rtl818x_rates));
memcpy(priv->channels, rtl818x_channels, sizeof(rtl818x_channels));
memcpy(priv->rates, rtl818x_rates, sizeof(rtl818x_rates));
priv->map = (struct rtl818x_csr *)0xFF00;
priv->band.band = IEEE80211_BAND_2GHZ;
priv->band.channels = priv->channels;
priv->band.n_channels = ARRAY_SIZE(rtl818x_channels);
priv->band.bitrates = priv->rates;
priv->band.n_bitrates = ARRAY_SIZE(rtl818x_rates);
dev->wiphy->bands[IEEE80211_BAND_2GHZ] = &priv->band;
dev->flags = IEEE80211_HW_HOST_BROADCAST_PS_BUFFERING |
IEEE80211_HW_SIGNAL_DBM |
IEEE80211_HW_RX_INCLUDES_FCS;
dev->max_rates = 1;
dev->max_rate_tries = RETRY_COUNT;
eeprom.data = dev;
eeprom.register_read = rtl8187_eeprom_register_read;
eeprom.register_write = rtl8187_eeprom_register_write;
if (rtl818x_ioread32(priv, &priv->map->RX_CONF) & (1 << 6))
eeprom.width = PCI_EEPROM_WIDTH_93C66;
else
eeprom.width = PCI_EEPROM_WIDTH_93C46;
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_CONFIG);
udelay(10);
eeprom_93cx6_multiread(&eeprom, RTL8187_EEPROM_MAC_ADDR,
(__le16 __force *)mac_addr, 3);
if (!is_valid_ether_addr(mac_addr)) {
printk(KERN_WARNING "rtl8187: Invalid hwaddr! Using randomly "
"generated MAC address\n");
eth_random_addr(mac_addr);
}
SET_IEEE80211_PERM_ADDR(dev, mac_addr);
channel = priv->channels;
for (i = 0; i < 3; i++) {
eeprom_93cx6_read(&eeprom, RTL8187_EEPROM_TXPWR_CHAN_1 + i,
&txpwr);
(*channel++).hw_value = txpwr & 0xFF;
(*channel++).hw_value = txpwr >> 8;
}
for (i = 0; i < 2; i++) {
eeprom_93cx6_read(&eeprom, RTL8187_EEPROM_TXPWR_CHAN_4 + i,
&txpwr);
(*channel++).hw_value = txpwr & 0xFF;
(*channel++).hw_value = txpwr >> 8;
}
eeprom_93cx6_read(&eeprom, RTL8187_EEPROM_TXPWR_BASE,
&priv->txpwr_base);
reg = rtl818x_ioread8(priv, &priv->map->PGSELECT) & ~1;
rtl818x_iowrite8(priv, &priv->map->PGSELECT, reg | 1);
priv->asic_rev = rtl818x_ioread8(priv, (u8 *)0xFFFE) & 0x3;
rtl818x_iowrite8(priv, &priv->map->PGSELECT, reg);
rtl818x_iowrite8(priv, &priv->map->EEPROM_CMD, RTL818X_EEPROM_CMD_NORMAL);
if (!priv->is_rtl8187b) {
u32 reg32;
reg32 = rtl818x_ioread32(priv, &priv->map->TX_CONF);
reg32 &= RTL818X_TX_CONF_HWVER_MASK;
switch (reg32) {
case RTL818X_TX_CONF_R8187vD_B:
chip_name = "RTL8187BvB(early)";
priv->is_rtl8187b = 1;
priv->hw_rev = RTL8187BvB;
break;
case RTL818X_TX_CONF_R8187vD:
chip_name = "RTL8187vD";
break;
default:
chip_name = "RTL8187vB (default)";
}
} else {
switch (rtl818x_ioread8(priv, (u8 *)0xFFE1)) {
case RTL818X_R8187B_B:
chip_name = "RTL8187BvB";
priv->hw_rev = RTL8187BvB;
break;
case RTL818X_R8187B_D:
chip_name = "RTL8187BvD";
priv->hw_rev = RTL8187BvD;
break;
case RTL818X_R8187B_E:
chip_name = "RTL8187BvE";
priv->hw_rev = RTL8187BvE;
break;
default:
chip_name = "RTL8187BvB (default)";
priv->hw_rev = RTL8187BvB;
}
}
if (!priv->is_rtl8187b) {
for (i = 0; i < 2; i++) {
eeprom_93cx6_read(&eeprom,
RTL8187_EEPROM_TXPWR_CHAN_6 + i,
&txpwr);
(*channel++).hw_value = txpwr & 0xFF;
(*channel++).hw_value = txpwr >> 8;
}
} else {
eeprom_93cx6_read(&eeprom, RTL8187_EEPROM_TXPWR_CHAN_6,
&txpwr);
(*channel++).hw_value = txpwr & 0xFF;
eeprom_93cx6_read(&eeprom, 0x0A, &txpwr);
(*channel++).hw_value = txpwr & 0xFF;
eeprom_93cx6_read(&eeprom, 0x1C, &txpwr);
(*channel++).hw_value = txpwr & 0xFF;
(*channel++).hw_value = txpwr >> 8;
}
priv->rfkill_mask = RFKILL_MASK_8187_89_97;
if (product_id == 0x8197 || product_id == 0x8198) {
eeprom_93cx6_read(&eeprom, RTL8187_EEPROM_SELECT_GPIO, &reg);
if (reg & 0xFF00)
priv->rfkill_mask = RFKILL_MASK_8198;
}
dev->vif_data_size = sizeof(struct rtl8187_vif);
dev->wiphy->interface_modes = BIT(NL80211_IFTYPE_STATION) |
BIT(NL80211_IFTYPE_ADHOC) ;
if ((id->driver_info == DEVICE_RTL8187) && priv->is_rtl8187b)
printk(KERN_INFO "rtl8187: inconsistency between id with OEM"
" info!\n");
priv->rf = rtl8187_detect_rf(dev);
dev->extra_tx_headroom = (!priv->is_rtl8187b) ?
sizeof(struct rtl8187_tx_hdr) :
sizeof(struct rtl8187b_tx_hdr);
if (!priv->is_rtl8187b)
dev->queues = 1;
else
dev->queues = 4;
err = ieee80211_register_hw(dev);
if (err) {
printk(KERN_ERR "rtl8187: Cannot register device\n");
goto err_free_dmabuf;
}
mutex_init(&priv->conf_mutex);
skb_queue_head_init(&priv->b_tx_status.queue);
wiphy_info(dev->wiphy, "hwaddr %pM, %s V%d + %s, rfkill mask %d\n",
mac_addr, chip_name, priv->asic_rev, priv->rf->name,
priv->rfkill_mask);
#ifdef CONFIG_RTL8187_LEDS
eeprom_93cx6_read(&eeprom, 0x3F, &reg);
reg &= 0xFF;
rtl8187_leds_init(dev, reg);
#endif
rtl8187_rfkill_init(dev);
return 0;
err_free_dmabuf:
kfree(priv->io_dmabuf);
usb_set_intfdata(intf, NULL);
usb_put_dev(udev);
err_free_dev:
ieee80211_free_hw(dev);
return err;
}
static void rtl8187_disconnect(struct usb_interface *intf)
{
struct ieee80211_hw *dev = usb_get_intfdata(intf);
struct rtl8187_priv *priv;
if (!dev)
return;
#ifdef CONFIG_RTL8187_LEDS
rtl8187_leds_exit(dev);
#endif
rtl8187_rfkill_exit(dev);
ieee80211_unregister_hw(dev);
priv = dev->priv;
usb_reset_device(priv->udev);
usb_put_dev(interface_to_usbdev(intf));
kfree(priv->io_dmabuf);
ieee80211_free_hw(dev);
}
