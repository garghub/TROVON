static const char *mwl8k_cmd_name(__le16 cmd, char *buf, int bufsize)
{
u16 command = le16_to_cpu(cmd);
#define MWL8K_CMDNAME(x) case MWL8K_CMD_##x: do {\
snprintf(buf, bufsize, "%s", #x);\
return buf;\
} while (0)
switch (command & ~0x8000) {
MWL8K_CMDNAME(CODE_DNLD);
MWL8K_CMDNAME(GET_HW_SPEC);
MWL8K_CMDNAME(SET_HW_SPEC);
MWL8K_CMDNAME(MAC_MULTICAST_ADR);
MWL8K_CMDNAME(GET_STAT);
MWL8K_CMDNAME(RADIO_CONTROL);
MWL8K_CMDNAME(RF_TX_POWER);
MWL8K_CMDNAME(TX_POWER);
MWL8K_CMDNAME(RF_ANTENNA);
MWL8K_CMDNAME(SET_BEACON);
MWL8K_CMDNAME(SET_PRE_SCAN);
MWL8K_CMDNAME(SET_POST_SCAN);
MWL8K_CMDNAME(SET_RF_CHANNEL);
MWL8K_CMDNAME(SET_AID);
MWL8K_CMDNAME(SET_RATE);
MWL8K_CMDNAME(SET_FINALIZE_JOIN);
MWL8K_CMDNAME(RTS_THRESHOLD);
MWL8K_CMDNAME(SET_SLOT);
MWL8K_CMDNAME(SET_EDCA_PARAMS);
MWL8K_CMDNAME(SET_WMM_MODE);
MWL8K_CMDNAME(MIMO_CONFIG);
MWL8K_CMDNAME(USE_FIXED_RATE);
MWL8K_CMDNAME(ENABLE_SNIFFER);
MWL8K_CMDNAME(SET_MAC_ADDR);
MWL8K_CMDNAME(SET_RATEADAPT_MODE);
MWL8K_CMDNAME(BSS_START);
MWL8K_CMDNAME(SET_NEW_STN);
MWL8K_CMDNAME(UPDATE_ENCRYPTION);
MWL8K_CMDNAME(UPDATE_STADB);
MWL8K_CMDNAME(BASTREAM);
MWL8K_CMDNAME(GET_WATCHDOG_BITMAP);
default:
snprintf(buf, bufsize, "0x%x", cmd);
}
#undef MWL8K_CMDNAME
return buf;
}
static void mwl8k_hw_reset(struct mwl8k_priv *priv)
{
iowrite32(MWL8K_H2A_INT_RESET,
priv->regs + MWL8K_HIU_H2A_INTERRUPT_EVENTS);
iowrite32(MWL8K_H2A_INT_RESET,
priv->regs + MWL8K_HIU_H2A_INTERRUPT_EVENTS);
msleep(20);
}
static void mwl8k_release_fw(const struct firmware **fw)
{
if (*fw == NULL)
return;
release_firmware(*fw);
*fw = NULL;
}
static void mwl8k_release_firmware(struct mwl8k_priv *priv)
{
mwl8k_release_fw(&priv->fw_ucode);
mwl8k_release_fw(&priv->fw_helper);
}
static int mwl8k_request_fw(struct mwl8k_priv *priv,
const char *fname, const struct firmware **fw,
bool nowait)
{
if (*fw != NULL)
mwl8k_release_fw(fw);
if (nowait)
return request_firmware_nowait(THIS_MODULE, 1, fname,
&priv->pdev->dev, GFP_KERNEL,
priv, mwl8k_fw_state_machine);
else
return request_firmware(fw, fname, &priv->pdev->dev);
}
static int mwl8k_request_firmware(struct mwl8k_priv *priv, char *fw_image,
bool nowait)
{
struct mwl8k_device_info *di = priv->device_info;
int rc;
if (di->helper_image != NULL) {
if (nowait)
rc = mwl8k_request_fw(priv, di->helper_image,
&priv->fw_helper, true);
else
rc = mwl8k_request_fw(priv, di->helper_image,
&priv->fw_helper, false);
if (rc)
printk(KERN_ERR "%s: Error requesting helper fw %s\n",
pci_name(priv->pdev), di->helper_image);
if (rc || nowait)
return rc;
}
if (nowait) {
priv->fw_state = FW_STATE_LOADING_PREF;
rc = mwl8k_request_fw(priv, fw_image,
&priv->fw_ucode,
true);
} else
rc = mwl8k_request_fw(priv, fw_image,
&priv->fw_ucode, false);
if (rc) {
printk(KERN_ERR "%s: Error requesting firmware file %s\n",
pci_name(priv->pdev), fw_image);
mwl8k_release_fw(&priv->fw_helper);
return rc;
}
return 0;
}
static int
mwl8k_send_fw_load_cmd(struct mwl8k_priv *priv, void *data, int length)
{
void __iomem *regs = priv->regs;
dma_addr_t dma_addr;
int loops;
dma_addr = pci_map_single(priv->pdev, data, length, PCI_DMA_TODEVICE);
if (pci_dma_mapping_error(priv->pdev, dma_addr))
return -ENOMEM;
iowrite32(dma_addr, regs + MWL8K_HIU_GEN_PTR);
iowrite32(0, regs + MWL8K_HIU_INT_CODE);
iowrite32(MWL8K_H2A_INT_DOORBELL,
regs + MWL8K_HIU_H2A_INTERRUPT_EVENTS);
iowrite32(MWL8K_H2A_INT_DUMMY,
regs + MWL8K_HIU_H2A_INTERRUPT_EVENTS);
loops = 1000;
do {
u32 int_code;
int_code = ioread32(regs + MWL8K_HIU_INT_CODE);
if (int_code == MWL8K_INT_CODE_CMD_FINISHED) {
iowrite32(0, regs + MWL8K_HIU_INT_CODE);
break;
}
cond_resched();
udelay(1);
} while (--loops);
pci_unmap_single(priv->pdev, dma_addr, length, PCI_DMA_TODEVICE);
return loops ? 0 : -ETIMEDOUT;
}
static int mwl8k_load_fw_image(struct mwl8k_priv *priv,
const u8 *data, size_t length)
{
struct mwl8k_cmd_pkt *cmd;
int done;
int rc = 0;
cmd = kmalloc(sizeof(*cmd) + 256, GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->code = cpu_to_le16(MWL8K_CMD_CODE_DNLD);
cmd->seq_num = 0;
cmd->macid = 0;
cmd->result = 0;
done = 0;
while (length) {
int block_size = length > 256 ? 256 : length;
memcpy(cmd->payload, data + done, block_size);
cmd->length = cpu_to_le16(block_size);
rc = mwl8k_send_fw_load_cmd(priv, cmd,
sizeof(*cmd) + block_size);
if (rc)
break;
done += block_size;
length -= block_size;
}
if (!rc) {
cmd->length = 0;
rc = mwl8k_send_fw_load_cmd(priv, cmd, sizeof(*cmd));
}
kfree(cmd);
return rc;
}
static int mwl8k_feed_fw_image(struct mwl8k_priv *priv,
const u8 *data, size_t length)
{
unsigned char *buffer;
int may_continue, rc = 0;
u32 done, prev_block_size;
buffer = kmalloc(1024, GFP_KERNEL);
if (buffer == NULL)
return -ENOMEM;
done = 0;
prev_block_size = 0;
may_continue = 1000;
while (may_continue > 0) {
u32 block_size;
block_size = ioread32(priv->regs + MWL8K_HIU_SCRATCH);
if (block_size & 1) {
block_size &= ~1;
may_continue--;
} else {
done += prev_block_size;
length -= prev_block_size;
}
if (block_size > 1024 || block_size > length) {
rc = -EOVERFLOW;
break;
}
if (length == 0) {
rc = 0;
break;
}
if (block_size == 0) {
rc = -EPROTO;
may_continue--;
udelay(1);
continue;
}
prev_block_size = block_size;
memcpy(buffer, data + done, block_size);
rc = mwl8k_send_fw_load_cmd(priv, buffer, block_size);
if (rc)
break;
}
if (!rc && length != 0)
rc = -EREMOTEIO;
kfree(buffer);
return rc;
}
static int mwl8k_load_firmware(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
const struct firmware *fw = priv->fw_ucode;
int rc;
int loops;
if (!memcmp(fw->data, "\x01\x00\x00\x00", 4)) {
const struct firmware *helper = priv->fw_helper;
if (helper == NULL) {
printk(KERN_ERR "%s: helper image needed but none "
"given\n", pci_name(priv->pdev));
return -EINVAL;
}
rc = mwl8k_load_fw_image(priv, helper->data, helper->size);
if (rc) {
printk(KERN_ERR "%s: unable to load firmware "
"helper image\n", pci_name(priv->pdev));
return rc;
}
msleep(20);
rc = mwl8k_feed_fw_image(priv, fw->data, fw->size);
} else {
rc = mwl8k_load_fw_image(priv, fw->data, fw->size);
}
if (rc) {
printk(KERN_ERR "%s: unable to load firmware image\n",
pci_name(priv->pdev));
return rc;
}
iowrite32(MWL8K_MODE_STA, priv->regs + MWL8K_HIU_GEN_PTR);
loops = 500000;
do {
u32 ready_code;
ready_code = ioread32(priv->regs + MWL8K_HIU_INT_CODE);
if (ready_code == MWL8K_FWAP_READY) {
priv->ap_fw = 1;
break;
} else if (ready_code == MWL8K_FWSTA_READY) {
priv->ap_fw = 0;
break;
}
cond_resched();
udelay(1);
} while (--loops);
return loops ? 0 : -ETIMEDOUT;
}
static inline void mwl8k_remove_dma_header(struct sk_buff *skb, __le16 qos)
{
struct mwl8k_dma_data *tr;
int hdrlen;
tr = (struct mwl8k_dma_data *)skb->data;
hdrlen = ieee80211_hdrlen(tr->wh.frame_control);
if (hdrlen != sizeof(tr->wh)) {
if (ieee80211_is_data_qos(tr->wh.frame_control)) {
memmove(tr->data - hdrlen, &tr->wh, hdrlen - 2);
*((__le16 *)(tr->data - 2)) = qos;
} else {
memmove(tr->data - hdrlen, &tr->wh, hdrlen);
}
}
if (hdrlen != sizeof(*tr))
skb_pull(skb, sizeof(*tr) - hdrlen);
}
static void
mwl8k_add_dma_header(struct mwl8k_priv *priv, struct sk_buff *skb,
int head_pad, int tail_pad)
{
struct ieee80211_hdr *wh;
int hdrlen;
int reqd_hdrlen;
struct mwl8k_dma_data *tr;
wh = (struct ieee80211_hdr *)skb->data;
hdrlen = ieee80211_hdrlen(wh->frame_control);
if (priv->ap_fw && (hdrlen < (sizeof(struct ieee80211_cts)
+ REDUCED_TX_HEADROOM))) {
if (pskb_expand_head(skb, REDUCED_TX_HEADROOM, 0, GFP_ATOMIC)) {
wiphy_err(priv->hw->wiphy,
"Failed to reallocate TX buffer\n");
return;
}
skb->truesize += REDUCED_TX_HEADROOM;
}
reqd_hdrlen = sizeof(*tr) + head_pad;
if (hdrlen != reqd_hdrlen)
skb_push(skb, reqd_hdrlen - hdrlen);
if (ieee80211_is_data_qos(wh->frame_control))
hdrlen -= IEEE80211_QOS_CTL_LEN;
tr = (struct mwl8k_dma_data *)skb->data;
if (wh != &tr->wh)
memmove(&tr->wh, wh, hdrlen);
if (hdrlen != sizeof(tr->wh))
memset(((void *)&tr->wh) + hdrlen, 0, sizeof(tr->wh) - hdrlen);
tr->fwlen = cpu_to_le16(skb->len - sizeof(*tr) + tail_pad);
}
static void mwl8k_encapsulate_tx_frame(struct mwl8k_priv *priv,
struct sk_buff *skb)
{
struct ieee80211_hdr *wh;
struct ieee80211_tx_info *tx_info;
struct ieee80211_key_conf *key_conf;
int data_pad;
int head_pad = 0;
wh = (struct ieee80211_hdr *)skb->data;
tx_info = IEEE80211_SKB_CB(skb);
key_conf = NULL;
if (ieee80211_is_data(wh->frame_control))
key_conf = tx_info->control.hw_key;
data_pad = 0;
if (key_conf != NULL) {
head_pad = key_conf->iv_len;
switch (key_conf->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
data_pad = 4;
break;
case WLAN_CIPHER_SUITE_TKIP:
data_pad = 12;
break;
case WLAN_CIPHER_SUITE_CCMP:
data_pad = 8;
break;
}
}
mwl8k_add_dma_header(priv, skb, head_pad, data_pad);
}
static void mwl8k_rxd_8366_ap_init(void *_rxd, dma_addr_t next_dma_addr)
{
struct mwl8k_rxd_8366_ap *rxd = _rxd;
rxd->next_rxd_phys_addr = cpu_to_le32(next_dma_addr);
rxd->rx_ctrl = MWL8K_8366_AP_RX_CTRL_OWNED_BY_HOST;
}
static void mwl8k_rxd_8366_ap_refill(void *_rxd, dma_addr_t addr, int len)
{
struct mwl8k_rxd_8366_ap *rxd = _rxd;
rxd->pkt_len = cpu_to_le16(len);
rxd->pkt_phys_addr = cpu_to_le32(addr);
wmb();
rxd->rx_ctrl = 0;
}
static int
mwl8k_rxd_8366_ap_process(void *_rxd, struct ieee80211_rx_status *status,
__le16 *qos, s8 *noise)
{
struct mwl8k_rxd_8366_ap *rxd = _rxd;
if (!(rxd->rx_ctrl & MWL8K_8366_AP_RX_CTRL_OWNED_BY_HOST))
return -1;
rmb();
memset(status, 0, sizeof(*status));
status->signal = -rxd->rssi;
*noise = -rxd->noise_floor;
if (rxd->rate & MWL8K_8366_AP_RATE_INFO_MCS_FORMAT) {
status->flag |= RX_FLAG_HT;
if (rxd->rate & MWL8K_8366_AP_RATE_INFO_40MHZ)
status->flag |= RX_FLAG_40MHZ;
status->rate_idx = MWL8K_8366_AP_RATE_INFO_RATEID(rxd->rate);
} else {
int i;
for (i = 0; i < ARRAY_SIZE(mwl8k_rates_24); i++) {
if (mwl8k_rates_24[i].hw_value == rxd->rate) {
status->rate_idx = i;
break;
}
}
}
if (rxd->channel > 14) {
status->band = IEEE80211_BAND_5GHZ;
if (!(status->flag & RX_FLAG_HT))
status->rate_idx -= 5;
} else {
status->band = IEEE80211_BAND_2GHZ;
}
status->freq = ieee80211_channel_to_frequency(rxd->channel,
status->band);
*qos = rxd->qos_control;
if ((rxd->rx_status != MWL8K_8366_AP_RXSTAT_GENERAL_DECRYPT_ERR) &&
(rxd->rx_status & MWL8K_8366_AP_RXSTAT_DECRYPT_ERR_MASK) &&
(rxd->rx_status & MWL8K_8366_AP_RXSTAT_TKIP_DECRYPT_MIC_ERR))
status->flag |= RX_FLAG_MMIC_ERROR;
return le16_to_cpu(rxd->pkt_len);
}
static void mwl8k_rxd_sta_init(void *_rxd, dma_addr_t next_dma_addr)
{
struct mwl8k_rxd_sta *rxd = _rxd;
rxd->next_rxd_phys_addr = cpu_to_le32(next_dma_addr);
rxd->rx_ctrl = MWL8K_STA_RX_CTRL_OWNED_BY_HOST;
}
static void mwl8k_rxd_sta_refill(void *_rxd, dma_addr_t addr, int len)
{
struct mwl8k_rxd_sta *rxd = _rxd;
rxd->pkt_len = cpu_to_le16(len);
rxd->pkt_phys_addr = cpu_to_le32(addr);
wmb();
rxd->rx_ctrl = 0;
}
static int
mwl8k_rxd_sta_process(void *_rxd, struct ieee80211_rx_status *status,
__le16 *qos, s8 *noise)
{
struct mwl8k_rxd_sta *rxd = _rxd;
u16 rate_info;
if (!(rxd->rx_ctrl & MWL8K_STA_RX_CTRL_OWNED_BY_HOST))
return -1;
rmb();
rate_info = le16_to_cpu(rxd->rate_info);
memset(status, 0, sizeof(*status));
status->signal = -rxd->rssi;
*noise = -rxd->noise_level;
status->antenna = MWL8K_STA_RATE_INFO_ANTSELECT(rate_info);
status->rate_idx = MWL8K_STA_RATE_INFO_RATEID(rate_info);
if (rate_info & MWL8K_STA_RATE_INFO_SHORTPRE)
status->flag |= RX_FLAG_SHORTPRE;
if (rate_info & MWL8K_STA_RATE_INFO_40MHZ)
status->flag |= RX_FLAG_40MHZ;
if (rate_info & MWL8K_STA_RATE_INFO_SHORTGI)
status->flag |= RX_FLAG_SHORT_GI;
if (rate_info & MWL8K_STA_RATE_INFO_MCS_FORMAT)
status->flag |= RX_FLAG_HT;
if (rxd->channel > 14) {
status->band = IEEE80211_BAND_5GHZ;
if (!(status->flag & RX_FLAG_HT))
status->rate_idx -= 5;
} else {
status->band = IEEE80211_BAND_2GHZ;
}
status->freq = ieee80211_channel_to_frequency(rxd->channel,
status->band);
*qos = rxd->qos_control;
if ((rxd->rx_ctrl & MWL8K_STA_RX_CTRL_DECRYPT_ERROR) &&
(rxd->rx_ctrl & MWL8K_STA_RX_CTRL_DEC_ERR_TYPE))
status->flag |= RX_FLAG_MMIC_ERROR;
return le16_to_cpu(rxd->pkt_len);
}
static int mwl8k_rxq_init(struct ieee80211_hw *hw, int index)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_rx_queue *rxq = priv->rxq + index;
int size;
int i;
rxq->rxd_count = 0;
rxq->head = 0;
rxq->tail = 0;
size = MWL8K_RX_DESCS * priv->rxd_ops->rxd_size;
rxq->rxd = pci_alloc_consistent(priv->pdev, size, &rxq->rxd_dma);
if (rxq->rxd == NULL) {
wiphy_err(hw->wiphy, "failed to alloc RX descriptors\n");
return -ENOMEM;
}
memset(rxq->rxd, 0, size);
rxq->buf = kcalloc(MWL8K_RX_DESCS, sizeof(*rxq->buf), GFP_KERNEL);
if (rxq->buf == NULL) {
wiphy_err(hw->wiphy, "failed to alloc RX skbuff list\n");
pci_free_consistent(priv->pdev, size, rxq->rxd, rxq->rxd_dma);
return -ENOMEM;
}
for (i = 0; i < MWL8K_RX_DESCS; i++) {
int desc_size;
void *rxd;
int nexti;
dma_addr_t next_dma_addr;
desc_size = priv->rxd_ops->rxd_size;
rxd = rxq->rxd + (i * priv->rxd_ops->rxd_size);
nexti = i + 1;
if (nexti == MWL8K_RX_DESCS)
nexti = 0;
next_dma_addr = rxq->rxd_dma + (nexti * desc_size);
priv->rxd_ops->rxd_init(rxd, next_dma_addr);
}
return 0;
}
static int rxq_refill(struct ieee80211_hw *hw, int index, int limit)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_rx_queue *rxq = priv->rxq + index;
int refilled;
refilled = 0;
while (rxq->rxd_count < MWL8K_RX_DESCS && limit--) {
struct sk_buff *skb;
dma_addr_t addr;
int rx;
void *rxd;
skb = dev_alloc_skb(MWL8K_RX_MAXSZ);
if (skb == NULL)
break;
addr = pci_map_single(priv->pdev, skb->data,
MWL8K_RX_MAXSZ, DMA_FROM_DEVICE);
rxq->rxd_count++;
rx = rxq->tail++;
if (rxq->tail == MWL8K_RX_DESCS)
rxq->tail = 0;
rxq->buf[rx].skb = skb;
dma_unmap_addr_set(&rxq->buf[rx], dma, addr);
rxd = rxq->rxd + (rx * priv->rxd_ops->rxd_size);
priv->rxd_ops->rxd_refill(rxd, addr, MWL8K_RX_MAXSZ);
refilled++;
}
return refilled;
}
static void mwl8k_rxq_deinit(struct ieee80211_hw *hw, int index)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_rx_queue *rxq = priv->rxq + index;
int i;
if (rxq->rxd == NULL)
return;
for (i = 0; i < MWL8K_RX_DESCS; i++) {
if (rxq->buf[i].skb != NULL) {
pci_unmap_single(priv->pdev,
dma_unmap_addr(&rxq->buf[i], dma),
MWL8K_RX_MAXSZ, PCI_DMA_FROMDEVICE);
dma_unmap_addr_set(&rxq->buf[i], dma, 0);
kfree_skb(rxq->buf[i].skb);
rxq->buf[i].skb = NULL;
}
}
kfree(rxq->buf);
rxq->buf = NULL;
pci_free_consistent(priv->pdev,
MWL8K_RX_DESCS * priv->rxd_ops->rxd_size,
rxq->rxd, rxq->rxd_dma);
rxq->rxd = NULL;
}
static inline int
mwl8k_capture_bssid(struct mwl8k_priv *priv, struct ieee80211_hdr *wh)
{
return priv->capture_beacon &&
ieee80211_is_beacon(wh->frame_control) &&
!compare_ether_addr(wh->addr3, priv->capture_bssid);
}
static inline void mwl8k_save_beacon(struct ieee80211_hw *hw,
struct sk_buff *skb)
{
struct mwl8k_priv *priv = hw->priv;
priv->capture_beacon = false;
memset(priv->capture_bssid, 0, ETH_ALEN);
priv->beacon_skb = skb_copy(skb, GFP_ATOMIC);
if (priv->beacon_skb != NULL)
ieee80211_queue_work(hw, &priv->finalize_join_worker);
}
static inline struct mwl8k_vif *mwl8k_find_vif_bss(struct list_head *vif_list,
u8 *bssid)
{
struct mwl8k_vif *mwl8k_vif;
list_for_each_entry(mwl8k_vif,
vif_list, list) {
if (memcmp(bssid, mwl8k_vif->bssid,
ETH_ALEN) == 0)
return mwl8k_vif;
}
return NULL;
}
static int rxq_process(struct ieee80211_hw *hw, int index, int limit)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_vif *mwl8k_vif = NULL;
struct mwl8k_rx_queue *rxq = priv->rxq + index;
int processed;
processed = 0;
while (rxq->rxd_count && limit--) {
struct sk_buff *skb;
void *rxd;
int pkt_len;
struct ieee80211_rx_status status;
struct ieee80211_hdr *wh;
__le16 qos;
skb = rxq->buf[rxq->head].skb;
if (skb == NULL)
break;
rxd = rxq->rxd + (rxq->head * priv->rxd_ops->rxd_size);
pkt_len = priv->rxd_ops->rxd_process(rxd, &status, &qos,
&priv->noise);
if (pkt_len < 0)
break;
rxq->buf[rxq->head].skb = NULL;
pci_unmap_single(priv->pdev,
dma_unmap_addr(&rxq->buf[rxq->head], dma),
MWL8K_RX_MAXSZ, PCI_DMA_FROMDEVICE);
dma_unmap_addr_set(&rxq->buf[rxq->head], dma, 0);
rxq->head++;
if (rxq->head == MWL8K_RX_DESCS)
rxq->head = 0;
rxq->rxd_count--;
wh = &((struct mwl8k_dma_data *)skb->data)->wh;
if (mwl8k_capture_bssid(priv, (void *)skb->data))
mwl8k_save_beacon(hw, skb);
if (ieee80211_has_protected(wh->frame_control)) {
mwl8k_vif = mwl8k_find_vif_bss(&priv->vif_list,
wh->addr1);
if (mwl8k_vif != NULL &&
mwl8k_vif->is_hw_crypto_enabled == true) {
if (status.flag & RX_FLAG_MMIC_ERROR) {
struct mwl8k_dma_data *tr;
tr = (struct mwl8k_dma_data *)skb->data;
memset((void *)&(tr->data), 0, 4);
pkt_len += 4;
}
if (!ieee80211_is_auth(wh->frame_control))
status.flag |= RX_FLAG_IV_STRIPPED |
RX_FLAG_DECRYPTED |
RX_FLAG_MMIC_STRIPPED;
}
}
skb_put(skb, pkt_len);
mwl8k_remove_dma_header(skb, qos);
memcpy(IEEE80211_SKB_RXCB(skb), &status, sizeof(status));
ieee80211_rx_irqsafe(hw, skb);
processed++;
}
return processed;
}
static int mwl8k_txq_init(struct ieee80211_hw *hw, int index)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_tx_queue *txq = priv->txq + index;
int size;
int i;
txq->len = 0;
txq->head = 0;
txq->tail = 0;
size = MWL8K_TX_DESCS * sizeof(struct mwl8k_tx_desc);
txq->txd = pci_alloc_consistent(priv->pdev, size, &txq->txd_dma);
if (txq->txd == NULL) {
wiphy_err(hw->wiphy, "failed to alloc TX descriptors\n");
return -ENOMEM;
}
memset(txq->txd, 0, size);
txq->skb = kcalloc(MWL8K_TX_DESCS, sizeof(*txq->skb), GFP_KERNEL);
if (txq->skb == NULL) {
wiphy_err(hw->wiphy, "failed to alloc TX skbuff list\n");
pci_free_consistent(priv->pdev, size, txq->txd, txq->txd_dma);
return -ENOMEM;
}
for (i = 0; i < MWL8K_TX_DESCS; i++) {
struct mwl8k_tx_desc *tx_desc;
int nexti;
tx_desc = txq->txd + i;
nexti = (i + 1) % MWL8K_TX_DESCS;
tx_desc->status = 0;
tx_desc->next_txd_phys_addr =
cpu_to_le32(txq->txd_dma + nexti * sizeof(*tx_desc));
}
return 0;
}
static inline void mwl8k_tx_start(struct mwl8k_priv *priv)
{
iowrite32(MWL8K_H2A_INT_PPA_READY,
priv->regs + MWL8K_HIU_H2A_INTERRUPT_EVENTS);
iowrite32(MWL8K_H2A_INT_DUMMY,
priv->regs + MWL8K_HIU_H2A_INTERRUPT_EVENTS);
ioread32(priv->regs + MWL8K_HIU_INT_CODE);
}
static void mwl8k_dump_tx_rings(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
int i;
for (i = 0; i < mwl8k_tx_queues(priv); i++) {
struct mwl8k_tx_queue *txq = priv->txq + i;
int fw_owned = 0;
int drv_owned = 0;
int unused = 0;
int desc;
for (desc = 0; desc < MWL8K_TX_DESCS; desc++) {
struct mwl8k_tx_desc *tx_desc = txq->txd + desc;
u32 status;
status = le32_to_cpu(tx_desc->status);
if (status & MWL8K_TXD_STATUS_FW_OWNED)
fw_owned++;
else
drv_owned++;
if (tx_desc->pkt_len == 0)
unused++;
}
wiphy_err(hw->wiphy,
"txq[%d] len=%d head=%d tail=%d "
"fw_owned=%d drv_owned=%d unused=%d\n",
i,
txq->len, txq->head, txq->tail,
fw_owned, drv_owned, unused);
}
}
static int mwl8k_tx_wait_empty(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
DECLARE_COMPLETION_ONSTACK(tx_wait);
int retry;
int rc;
might_sleep();
if (!priv->pending_tx_pkts)
return 0;
retry = 0;
rc = 0;
spin_lock_bh(&priv->tx_lock);
priv->tx_wait = &tx_wait;
while (!rc) {
int oldcount;
unsigned long timeout;
oldcount = priv->pending_tx_pkts;
spin_unlock_bh(&priv->tx_lock);
timeout = wait_for_completion_timeout(&tx_wait,
msecs_to_jiffies(MWL8K_TX_WAIT_TIMEOUT_MS));
spin_lock_bh(&priv->tx_lock);
if (timeout) {
WARN_ON(priv->pending_tx_pkts);
if (retry)
wiphy_notice(hw->wiphy, "tx rings drained\n");
break;
}
if (priv->pending_tx_pkts < oldcount) {
wiphy_notice(hw->wiphy,
"waiting for tx rings to drain (%d -> %d pkts)\n",
oldcount, priv->pending_tx_pkts);
retry = 1;
continue;
}
priv->tx_wait = NULL;
wiphy_err(hw->wiphy, "tx rings stuck for %d ms\n",
MWL8K_TX_WAIT_TIMEOUT_MS);
mwl8k_dump_tx_rings(hw);
rc = -ETIMEDOUT;
}
spin_unlock_bh(&priv->tx_lock);
return rc;
}
static int mwl8k_tid_queue_mapping(u8 tid)
{
BUG_ON(tid > 7);
switch (tid) {
case 0:
case 3:
return IEEE80211_AC_BE;
break;
case 1:
case 2:
return IEEE80211_AC_BK;
break;
case 4:
case 5:
return IEEE80211_AC_VI;
break;
case 6:
case 7:
return IEEE80211_AC_VO;
break;
default:
return -1;
break;
}
}
static int
mwl8k_txq_reclaim(struct ieee80211_hw *hw, int index, int limit, int force)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_tx_queue *txq = priv->txq + index;
int processed;
processed = 0;
while (txq->len > 0 && limit--) {
int tx;
struct mwl8k_tx_desc *tx_desc;
unsigned long addr;
int size;
struct sk_buff *skb;
struct ieee80211_tx_info *info;
u32 status;
struct ieee80211_sta *sta;
struct mwl8k_sta *sta_info = NULL;
u16 rate_info;
struct ieee80211_hdr *wh;
tx = txq->head;
tx_desc = txq->txd + tx;
status = le32_to_cpu(tx_desc->status);
if (status & MWL8K_TXD_STATUS_FW_OWNED) {
if (!force)
break;
tx_desc->status &=
~cpu_to_le32(MWL8K_TXD_STATUS_FW_OWNED);
}
txq->head = (tx + 1) % MWL8K_TX_DESCS;
BUG_ON(txq->len == 0);
txq->len--;
priv->pending_tx_pkts--;
addr = le32_to_cpu(tx_desc->pkt_phys_addr);
size = le16_to_cpu(tx_desc->pkt_len);
skb = txq->skb[tx];
txq->skb[tx] = NULL;
BUG_ON(skb == NULL);
pci_unmap_single(priv->pdev, addr, size, PCI_DMA_TODEVICE);
mwl8k_remove_dma_header(skb, tx_desc->qos_control);
wh = (struct ieee80211_hdr *) skb->data;
tx_desc->pkt_phys_addr = 0;
tx_desc->pkt_len = 0;
info = IEEE80211_SKB_CB(skb);
if (ieee80211_is_data(wh->frame_control)) {
sta = info->control.sta;
if (sta) {
sta_info = MWL8K_STA(sta);
BUG_ON(sta_info == NULL);
rate_info = le16_to_cpu(tx_desc->rate_info);
if (RI_RATE_ID_MCS(rate_info) < 1 ||
RI_FORMAT(rate_info) == 0) {
sta_info->is_ampdu_allowed = false;
} else {
sta_info->is_ampdu_allowed = true;
}
}
}
ieee80211_tx_info_clear_status(info);
info->status.rates[0].idx = -1;
info->status.rates[0].count = 1;
if (MWL8K_TXD_SUCCESS(status))
info->flags |= IEEE80211_TX_STAT_ACK;
ieee80211_tx_status_irqsafe(hw, skb);
processed++;
}
return processed;
}
static void mwl8k_txq_deinit(struct ieee80211_hw *hw, int index)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_tx_queue *txq = priv->txq + index;
if (txq->txd == NULL)
return;
mwl8k_txq_reclaim(hw, index, INT_MAX, 1);
kfree(txq->skb);
txq->skb = NULL;
pci_free_consistent(priv->pdev,
MWL8K_TX_DESCS * sizeof(struct mwl8k_tx_desc),
txq->txd, txq->txd_dma);
txq->txd = NULL;
}
static struct mwl8k_ampdu_stream *
mwl8k_add_stream(struct ieee80211_hw *hw, struct ieee80211_sta *sta, u8 tid)
{
struct mwl8k_ampdu_stream *stream;
struct mwl8k_priv *priv = hw->priv;
int i;
for (i = 0; i < priv->num_ampdu_queues; i++) {
stream = &priv->ampdu[i];
if (stream->state == AMPDU_NO_STREAM) {
stream->sta = sta;
stream->state = AMPDU_STREAM_NEW;
stream->tid = tid;
stream->idx = i;
stream->txq_idx = MWL8K_TX_WMM_QUEUES + i;
wiphy_debug(hw->wiphy, "Added a new stream for %pM %d",
sta->addr, tid);
return stream;
}
}
return NULL;
}
static int
mwl8k_start_stream(struct ieee80211_hw *hw, struct mwl8k_ampdu_stream *stream)
{
int ret;
if (stream->state != AMPDU_STREAM_NEW)
return 0;
ret = ieee80211_start_tx_ba_session(stream->sta, stream->tid, 0);
if (ret)
wiphy_debug(hw->wiphy, "Failed to start stream for %pM %d: "
"%d\n", stream->sta->addr, stream->tid, ret);
else
wiphy_debug(hw->wiphy, "Started stream for %pM %d\n",
stream->sta->addr, stream->tid);
return ret;
}
static void
mwl8k_remove_stream(struct ieee80211_hw *hw, struct mwl8k_ampdu_stream *stream)
{
wiphy_debug(hw->wiphy, "Remove stream for %pM %d\n", stream->sta->addr,
stream->tid);
memset(stream, 0, sizeof(*stream));
}
static struct mwl8k_ampdu_stream *
mwl8k_lookup_stream(struct ieee80211_hw *hw, u8 *addr, u8 tid)
{
struct mwl8k_priv *priv = hw->priv;
int i;
for (i = 0 ; i < priv->num_ampdu_queues; i++) {
struct mwl8k_ampdu_stream *stream;
stream = &priv->ampdu[i];
if (stream->state == AMPDU_NO_STREAM)
continue;
if (!memcmp(stream->sta->addr, addr, ETH_ALEN) &&
stream->tid == tid)
return stream;
}
return NULL;
}
static inline bool mwl8k_ampdu_allowed(struct ieee80211_sta *sta, u8 tid)
{
struct mwl8k_sta *sta_info = MWL8K_STA(sta);
struct tx_traffic_info *tx_stats;
BUG_ON(tid >= MWL8K_MAX_TID);
tx_stats = &sta_info->tx_stats[tid];
return sta_info->is_ampdu_allowed &&
tx_stats->pkts > MWL8K_AMPDU_PACKET_THRESHOLD;
}
static inline void mwl8k_tx_count_packet(struct ieee80211_sta *sta, u8 tid)
{
struct mwl8k_sta *sta_info = MWL8K_STA(sta);
struct tx_traffic_info *tx_stats;
BUG_ON(tid >= MWL8K_MAX_TID);
tx_stats = &sta_info->tx_stats[tid];
if (tx_stats->start_time == 0)
tx_stats->start_time = jiffies;
if (jiffies - tx_stats->start_time > HZ) {
tx_stats->pkts = 0;
tx_stats->start_time = 0;
} else
tx_stats->pkts++;
}
static void
mwl8k_txq_xmit(struct ieee80211_hw *hw, int index, struct sk_buff *skb)
{
struct mwl8k_priv *priv = hw->priv;
struct ieee80211_tx_info *tx_info;
struct mwl8k_vif *mwl8k_vif;
struct ieee80211_sta *sta;
struct ieee80211_hdr *wh;
struct mwl8k_tx_queue *txq;
struct mwl8k_tx_desc *tx;
dma_addr_t dma;
u32 txstatus;
u8 txdatarate;
u16 qos;
int txpriority;
u8 tid = 0;
struct mwl8k_ampdu_stream *stream = NULL;
bool start_ba_session = false;
bool mgmtframe = false;
struct ieee80211_mgmt *mgmt = (struct ieee80211_mgmt *)skb->data;
wh = (struct ieee80211_hdr *)skb->data;
if (ieee80211_is_data_qos(wh->frame_control))
qos = le16_to_cpu(*((__le16 *)ieee80211_get_qos_ctl(wh)));
else
qos = 0;
if (ieee80211_is_mgmt(wh->frame_control))
mgmtframe = true;
if (priv->ap_fw)
mwl8k_encapsulate_tx_frame(priv, skb);
else
mwl8k_add_dma_header(priv, skb, 0, 0);
wh = &((struct mwl8k_dma_data *)skb->data)->wh;
tx_info = IEEE80211_SKB_CB(skb);
sta = tx_info->control.sta;
mwl8k_vif = MWL8K_VIF(tx_info->control.vif);
if (tx_info->flags & IEEE80211_TX_CTL_ASSIGN_SEQ) {
wh->seq_ctrl &= cpu_to_le16(IEEE80211_SCTL_FRAG);
wh->seq_ctrl |= cpu_to_le16(mwl8k_vif->seqno);
mwl8k_vif->seqno += 0x10;
}
txstatus = 0;
txdatarate = 0;
if (ieee80211_is_mgmt(wh->frame_control) ||
ieee80211_is_ctl(wh->frame_control)) {
txdatarate = 0;
qos |= MWL8K_QOS_QLEN_UNSPEC | MWL8K_QOS_EOSP;
} else if (ieee80211_is_data(wh->frame_control)) {
txdatarate = 1;
if (is_multicast_ether_addr(wh->addr1))
txstatus |= MWL8K_TXD_STATUS_MULTICAST_TX;
qos &= ~MWL8K_QOS_ACK_POLICY_MASK;
if (tx_info->flags & IEEE80211_TX_CTL_AMPDU)
qos |= MWL8K_QOS_ACK_POLICY_BLOCKACK;
else
qos |= MWL8K_QOS_ACK_POLICY_NORMAL;
}
if (unlikely(ieee80211_is_action(wh->frame_control) &&
mgmt->u.action.category == WLAN_CATEGORY_BACK &&
mgmt->u.action.u.addba_req.action_code == WLAN_ACTION_ADDBA_REQ &&
priv->ap_fw)) {
u16 capab = le16_to_cpu(mgmt->u.action.u.addba_req.capab);
tid = (capab & IEEE80211_ADDBA_PARAM_TID_MASK) >> 2;
index = mwl8k_tid_queue_mapping(tid);
}
txpriority = index;
if (priv->ap_fw && sta && sta->ht_cap.ht_supported
&& skb->protocol != cpu_to_be16(ETH_P_PAE)
&& ieee80211_is_data_qos(wh->frame_control)) {
tid = qos & 0xf;
mwl8k_tx_count_packet(sta, tid);
spin_lock(&priv->stream_lock);
stream = mwl8k_lookup_stream(hw, sta->addr, tid);
if (stream != NULL) {
if (stream->state == AMPDU_STREAM_ACTIVE) {
txpriority = stream->txq_idx;
index = stream->txq_idx;
} else if (stream->state == AMPDU_STREAM_NEW) {
} else {
wiphy_warn(hw->wiphy,
"Cannot send packet while ADDBA "
"dialog is underway.\n");
spin_unlock(&priv->stream_lock);
dev_kfree_skb(skb);
return;
}
} else {
if (mwl8k_ampdu_allowed(sta, tid)) {
stream = mwl8k_add_stream(hw, sta, tid);
if (stream != NULL)
start_ba_session = true;
}
}
spin_unlock(&priv->stream_lock);
}
dma = pci_map_single(priv->pdev, skb->data,
skb->len, PCI_DMA_TODEVICE);
if (pci_dma_mapping_error(priv->pdev, dma)) {
wiphy_debug(hw->wiphy,
"failed to dma map skb, dropping TX frame.\n");
if (start_ba_session) {
spin_lock(&priv->stream_lock);
mwl8k_remove_stream(hw, stream);
spin_unlock(&priv->stream_lock);
}
dev_kfree_skb(skb);
return;
}
spin_lock_bh(&priv->tx_lock);
txq = priv->txq + index;
if (txq->len >= MWL8K_TX_DESCS - 2) {
if (mgmtframe == false ||
txq->len == MWL8K_TX_DESCS) {
if (start_ba_session) {
spin_lock(&priv->stream_lock);
mwl8k_remove_stream(hw, stream);
spin_unlock(&priv->stream_lock);
}
spin_unlock_bh(&priv->tx_lock);
dev_kfree_skb(skb);
return;
}
}
BUG_ON(txq->skb[txq->tail] != NULL);
txq->skb[txq->tail] = skb;
tx = txq->txd + txq->tail;
tx->data_rate = txdatarate;
tx->tx_priority = txpriority;
tx->qos_control = cpu_to_le16(qos);
tx->pkt_phys_addr = cpu_to_le32(dma);
tx->pkt_len = cpu_to_le16(skb->len);
tx->rate_info = 0;
if (!priv->ap_fw && tx_info->control.sta != NULL)
tx->peer_id = MWL8K_STA(tx_info->control.sta)->peer_id;
else
tx->peer_id = 0;
if (priv->ap_fw)
tx->timestamp = cpu_to_le32(ioread32(priv->regs +
MWL8K_HW_TIMER_REGISTER));
wmb();
tx->status = cpu_to_le32(MWL8K_TXD_STATUS_FW_OWNED | txstatus);
txq->len++;
priv->pending_tx_pkts++;
txq->tail++;
if (txq->tail == MWL8K_TX_DESCS)
txq->tail = 0;
mwl8k_tx_start(priv);
spin_unlock_bh(&priv->tx_lock);
if (start_ba_session) {
spin_lock(&priv->stream_lock);
if (mwl8k_start_stream(hw, stream))
mwl8k_remove_stream(hw, stream);
spin_unlock(&priv->stream_lock);
}
}
static int mwl8k_fw_lock(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
if (priv->fw_mutex_owner != current) {
int rc;
mutex_lock(&priv->fw_mutex);
ieee80211_stop_queues(hw);
rc = mwl8k_tx_wait_empty(hw);
if (rc) {
ieee80211_wake_queues(hw);
mutex_unlock(&priv->fw_mutex);
return rc;
}
priv->fw_mutex_owner = current;
}
priv->fw_mutex_depth++;
return 0;
}
static void mwl8k_fw_unlock(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
if (!--priv->fw_mutex_depth) {
ieee80211_wake_queues(hw);
priv->fw_mutex_owner = NULL;
mutex_unlock(&priv->fw_mutex);
}
}
static int mwl8k_post_cmd(struct ieee80211_hw *hw, struct mwl8k_cmd_pkt *cmd)
{
DECLARE_COMPLETION_ONSTACK(cmd_wait);
struct mwl8k_priv *priv = hw->priv;
void __iomem *regs = priv->regs;
dma_addr_t dma_addr;
unsigned int dma_size;
int rc;
unsigned long timeout = 0;
u8 buf[32];
cmd->result = (__force __le16) 0xffff;
dma_size = le16_to_cpu(cmd->length);
dma_addr = pci_map_single(priv->pdev, cmd, dma_size,
PCI_DMA_BIDIRECTIONAL);
if (pci_dma_mapping_error(priv->pdev, dma_addr))
return -ENOMEM;
rc = mwl8k_fw_lock(hw);
if (rc) {
pci_unmap_single(priv->pdev, dma_addr, dma_size,
PCI_DMA_BIDIRECTIONAL);
return rc;
}
priv->hostcmd_wait = &cmd_wait;
iowrite32(dma_addr, regs + MWL8K_HIU_GEN_PTR);
iowrite32(MWL8K_H2A_INT_DOORBELL,
regs + MWL8K_HIU_H2A_INTERRUPT_EVENTS);
iowrite32(MWL8K_H2A_INT_DUMMY,
regs + MWL8K_HIU_H2A_INTERRUPT_EVENTS);
timeout = wait_for_completion_timeout(&cmd_wait,
msecs_to_jiffies(MWL8K_CMD_TIMEOUT_MS));
priv->hostcmd_wait = NULL;
mwl8k_fw_unlock(hw);
pci_unmap_single(priv->pdev, dma_addr, dma_size,
PCI_DMA_BIDIRECTIONAL);
if (!timeout) {
wiphy_err(hw->wiphy, "Command %s timeout after %u ms\n",
mwl8k_cmd_name(cmd->code, buf, sizeof(buf)),
MWL8K_CMD_TIMEOUT_MS);
rc = -ETIMEDOUT;
} else {
int ms;
ms = MWL8K_CMD_TIMEOUT_MS - jiffies_to_msecs(timeout);
rc = cmd->result ? -EINVAL : 0;
if (rc)
wiphy_err(hw->wiphy, "Command %s error 0x%x\n",
mwl8k_cmd_name(cmd->code, buf, sizeof(buf)),
le16_to_cpu(cmd->result));
else if (ms > 2000)
wiphy_notice(hw->wiphy, "Command %s took %d ms\n",
mwl8k_cmd_name(cmd->code,
buf, sizeof(buf)),
ms);
}
return rc;
}
static int mwl8k_post_pervif_cmd(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct mwl8k_cmd_pkt *cmd)
{
if (vif != NULL)
cmd->macid = MWL8K_VIF(vif)->macid;
return mwl8k_post_cmd(hw, cmd);
}
static void mwl8k_setup_2ghz_band(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
BUILD_BUG_ON(sizeof(priv->channels_24) != sizeof(mwl8k_channels_24));
memcpy(priv->channels_24, mwl8k_channels_24, sizeof(mwl8k_channels_24));
BUILD_BUG_ON(sizeof(priv->rates_24) != sizeof(mwl8k_rates_24));
memcpy(priv->rates_24, mwl8k_rates_24, sizeof(mwl8k_rates_24));
priv->band_24.band = IEEE80211_BAND_2GHZ;
priv->band_24.channels = priv->channels_24;
priv->band_24.n_channels = ARRAY_SIZE(mwl8k_channels_24);
priv->band_24.bitrates = priv->rates_24;
priv->band_24.n_bitrates = ARRAY_SIZE(mwl8k_rates_24);
hw->wiphy->bands[IEEE80211_BAND_2GHZ] = &priv->band_24;
}
static void mwl8k_setup_5ghz_band(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
BUILD_BUG_ON(sizeof(priv->channels_50) != sizeof(mwl8k_channels_50));
memcpy(priv->channels_50, mwl8k_channels_50, sizeof(mwl8k_channels_50));
BUILD_BUG_ON(sizeof(priv->rates_50) != sizeof(mwl8k_rates_50));
memcpy(priv->rates_50, mwl8k_rates_50, sizeof(mwl8k_rates_50));
priv->band_50.band = IEEE80211_BAND_5GHZ;
priv->band_50.channels = priv->channels_50;
priv->band_50.n_channels = ARRAY_SIZE(mwl8k_channels_50);
priv->band_50.bitrates = priv->rates_50;
priv->band_50.n_bitrates = ARRAY_SIZE(mwl8k_rates_50);
hw->wiphy->bands[IEEE80211_BAND_5GHZ] = &priv->band_50;
}
static void
mwl8k_set_ht_caps(struct ieee80211_hw *hw,
struct ieee80211_supported_band *band, u32 cap)
{
int rx_streams;
int tx_streams;
band->ht_cap.ht_supported = 1;
if (cap & MWL8K_CAP_MAX_AMSDU)
band->ht_cap.cap |= IEEE80211_HT_CAP_MAX_AMSDU;
if (cap & MWL8K_CAP_GREENFIELD)
band->ht_cap.cap |= IEEE80211_HT_CAP_GRN_FLD;
if (cap & MWL8K_CAP_AMPDU) {
hw->flags |= IEEE80211_HW_AMPDU_AGGREGATION;
band->ht_cap.ampdu_factor = IEEE80211_HT_MAX_AMPDU_64K;
band->ht_cap.ampdu_density = IEEE80211_HT_MPDU_DENSITY_NONE;
}
if (cap & MWL8K_CAP_RX_STBC)
band->ht_cap.cap |= IEEE80211_HT_CAP_RX_STBC;
if (cap & MWL8K_CAP_TX_STBC)
band->ht_cap.cap |= IEEE80211_HT_CAP_TX_STBC;
if (cap & MWL8K_CAP_SHORTGI_40MHZ)
band->ht_cap.cap |= IEEE80211_HT_CAP_SGI_40;
if (cap & MWL8K_CAP_SHORTGI_20MHZ)
band->ht_cap.cap |= IEEE80211_HT_CAP_SGI_20;
if (cap & MWL8K_CAP_DELAY_BA)
band->ht_cap.cap |= IEEE80211_HT_CAP_DELAY_BA;
if (cap & MWL8K_CAP_40MHZ)
band->ht_cap.cap |= IEEE80211_HT_CAP_SUP_WIDTH_20_40;
rx_streams = hweight32(cap & MWL8K_CAP_RX_ANTENNA_MASK);
tx_streams = hweight32(cap & MWL8K_CAP_TX_ANTENNA_MASK);
band->ht_cap.mcs.rx_mask[0] = 0xff;
if (rx_streams >= 2)
band->ht_cap.mcs.rx_mask[1] = 0xff;
if (rx_streams >= 3)
band->ht_cap.mcs.rx_mask[2] = 0xff;
band->ht_cap.mcs.rx_mask[4] = 0x01;
band->ht_cap.mcs.tx_params = IEEE80211_HT_MCS_TX_DEFINED;
if (rx_streams != tx_streams) {
band->ht_cap.mcs.tx_params |= IEEE80211_HT_MCS_TX_RX_DIFF;
band->ht_cap.mcs.tx_params |= (tx_streams - 1) <<
IEEE80211_HT_MCS_TX_MAX_STREAMS_SHIFT;
}
}
static void
mwl8k_set_caps(struct ieee80211_hw *hw, u32 caps)
{
struct mwl8k_priv *priv = hw->priv;
if ((caps & MWL8K_CAP_2GHZ4) || !(caps & MWL8K_CAP_BAND_MASK)) {
mwl8k_setup_2ghz_band(hw);
if (caps & MWL8K_CAP_MIMO)
mwl8k_set_ht_caps(hw, &priv->band_24, caps);
}
if (caps & MWL8K_CAP_5GHZ) {
mwl8k_setup_5ghz_band(hw);
if (caps & MWL8K_CAP_MIMO)
mwl8k_set_ht_caps(hw, &priv->band_50, caps);
}
}
static int mwl8k_cmd_get_hw_spec_sta(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_cmd_get_hw_spec_sta *cmd;
int rc;
int i;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_GET_HW_SPEC);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
memset(cmd->perm_addr, 0xff, sizeof(cmd->perm_addr));
cmd->ps_cookie = cpu_to_le32(priv->cookie_dma);
cmd->rx_queue_ptr = cpu_to_le32(priv->rxq[0].rxd_dma);
cmd->num_tx_queues = cpu_to_le32(mwl8k_tx_queues(priv));
for (i = 0; i < mwl8k_tx_queues(priv); i++)
cmd->tx_queue_ptrs[i] = cpu_to_le32(priv->txq[i].txd_dma);
cmd->num_tx_desc_per_queue = cpu_to_le32(MWL8K_TX_DESCS);
cmd->total_rxd = cpu_to_le32(MWL8K_RX_DESCS);
rc = mwl8k_post_cmd(hw, &cmd->header);
if (!rc) {
SET_IEEE80211_PERM_ADDR(hw, cmd->perm_addr);
priv->num_mcaddrs = le16_to_cpu(cmd->num_mcaddrs);
priv->fw_rev = le32_to_cpu(cmd->fw_rev);
priv->hw_rev = cmd->hw_rev;
mwl8k_set_caps(hw, le32_to_cpu(cmd->caps));
priv->ap_macids_supported = 0x00000000;
priv->sta_macids_supported = 0x00000001;
}
kfree(cmd);
return rc;
}
static int mwl8k_cmd_get_hw_spec_ap(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_cmd_get_hw_spec_ap *cmd;
int rc, i;
u32 api_version;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_GET_HW_SPEC);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
memset(cmd->perm_addr, 0xff, sizeof(cmd->perm_addr));
cmd->ps_cookie = cpu_to_le32(priv->cookie_dma);
rc = mwl8k_post_cmd(hw, &cmd->header);
if (!rc) {
int off;
api_version = le32_to_cpu(cmd->fw_api_version);
if (priv->device_info->fw_api_ap != api_version) {
printk(KERN_ERR "%s: Unsupported fw API version for %s."
" Expected %d got %d.\n", MWL8K_NAME,
priv->device_info->part_name,
priv->device_info->fw_api_ap,
api_version);
rc = -EINVAL;
goto done;
}
SET_IEEE80211_PERM_ADDR(hw, cmd->perm_addr);
priv->num_mcaddrs = le16_to_cpu(cmd->num_mcaddrs);
priv->fw_rev = le32_to_cpu(cmd->fw_rev);
priv->hw_rev = cmd->hw_rev;
mwl8k_set_caps(hw, le32_to_cpu(cmd->caps));
priv->ap_macids_supported = 0x000000ff;
priv->sta_macids_supported = 0x00000000;
priv->num_ampdu_queues = le32_to_cpu(cmd->num_of_ampdu_queues);
if (priv->num_ampdu_queues > MWL8K_MAX_AMPDU_QUEUES) {
wiphy_warn(hw->wiphy, "fw reported %d ampdu queues"
" but we only support %d.\n",
priv->num_ampdu_queues,
MWL8K_MAX_AMPDU_QUEUES);
priv->num_ampdu_queues = MWL8K_MAX_AMPDU_QUEUES;
}
off = le32_to_cpu(cmd->rxwrptr) & 0xffff;
iowrite32(priv->rxq[0].rxd_dma, priv->sram + off);
off = le32_to_cpu(cmd->rxrdptr) & 0xffff;
iowrite32(priv->rxq[0].rxd_dma, priv->sram + off);
priv->txq_offset[0] = le32_to_cpu(cmd->wcbbase0) & 0xffff;
priv->txq_offset[1] = le32_to_cpu(cmd->wcbbase1) & 0xffff;
priv->txq_offset[2] = le32_to_cpu(cmd->wcbbase2) & 0xffff;
priv->txq_offset[3] = le32_to_cpu(cmd->wcbbase3) & 0xffff;
for (i = 0; i < priv->num_ampdu_queues; i++)
priv->txq_offset[i + MWL8K_TX_WMM_QUEUES] =
le32_to_cpu(cmd->wcbbase_ampdu[i]) & 0xffff;
}
done:
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_hw_spec(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_cmd_set_hw_spec *cmd;
int rc;
int i;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_HW_SPEC);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->ps_cookie = cpu_to_le32(priv->cookie_dma);
cmd->rx_queue_ptr = cpu_to_le32(priv->rxq[0].rxd_dma);
cmd->num_tx_queues = cpu_to_le32(mwl8k_tx_queues(priv));
for (i = 0; i < mwl8k_tx_queues(priv); i++) {
int j = mwl8k_tx_queues(priv) - 1 - i;
cmd->tx_queue_ptrs[i] = cpu_to_le32(priv->txq[j].txd_dma);
}
cmd->flags = cpu_to_le32(MWL8K_SET_HW_SPEC_FLAG_HOST_DECR_MGMT |
MWL8K_SET_HW_SPEC_FLAG_HOSTFORM_PROBERESP |
MWL8K_SET_HW_SPEC_FLAG_HOSTFORM_BEACON |
MWL8K_SET_HW_SPEC_FLAG_ENABLE_LIFE_TIME_EXPIRY |
MWL8K_SET_HW_SPEC_FLAG_GENERATE_CCMP_HDR);
cmd->num_tx_desc_per_queue = cpu_to_le32(MWL8K_TX_DESCS);
cmd->total_rxd = cpu_to_le32(MWL8K_RX_DESCS);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static struct mwl8k_cmd_pkt *
__mwl8k_cmd_mac_multicast_adr(struct ieee80211_hw *hw, int allmulti,
struct netdev_hw_addr_list *mc_list)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_cmd_mac_multicast_adr *cmd;
int size;
int mc_count = 0;
if (mc_list)
mc_count = netdev_hw_addr_list_count(mc_list);
if (allmulti || mc_count > priv->num_mcaddrs) {
allmulti = 1;
mc_count = 0;
}
size = sizeof(*cmd) + mc_count * ETH_ALEN;
cmd = kzalloc(size, GFP_ATOMIC);
if (cmd == NULL)
return NULL;
cmd->header.code = cpu_to_le16(MWL8K_CMD_MAC_MULTICAST_ADR);
cmd->header.length = cpu_to_le16(size);
cmd->action = cpu_to_le16(MWL8K_ENABLE_RX_DIRECTED |
MWL8K_ENABLE_RX_BROADCAST);
if (allmulti) {
cmd->action |= cpu_to_le16(MWL8K_ENABLE_RX_ALL_MULTICAST);
} else if (mc_count) {
struct netdev_hw_addr *ha;
int i = 0;
cmd->action |= cpu_to_le16(MWL8K_ENABLE_RX_MULTICAST);
cmd->numaddr = cpu_to_le16(mc_count);
netdev_hw_addr_list_for_each(ha, mc_list) {
memcpy(cmd->addr[i], ha->addr, ETH_ALEN);
}
}
return &cmd->header;
}
static int mwl8k_cmd_get_stat(struct ieee80211_hw *hw,
struct ieee80211_low_level_stats *stats)
{
struct mwl8k_cmd_get_stat *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_GET_STAT);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
rc = mwl8k_post_cmd(hw, &cmd->header);
if (!rc) {
stats->dot11ACKFailureCount =
le32_to_cpu(cmd->stats[MWL8K_STAT_ACK_FAILURE]);
stats->dot11RTSFailureCount =
le32_to_cpu(cmd->stats[MWL8K_STAT_RTS_FAILURE]);
stats->dot11FCSErrorCount =
le32_to_cpu(cmd->stats[MWL8K_STAT_FCS_ERROR]);
stats->dot11RTSSuccessCount =
le32_to_cpu(cmd->stats[MWL8K_STAT_RTS_SUCCESS]);
}
kfree(cmd);
return rc;
}
static int
mwl8k_cmd_radio_control(struct ieee80211_hw *hw, bool enable, bool force)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_cmd_radio_control *cmd;
int rc;
if (enable == priv->radio_on && !force)
return 0;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_RADIO_CONTROL);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(MWL8K_CMD_SET);
cmd->control = cpu_to_le16(priv->radio_short_preamble ? 3 : 1);
cmd->radio_on = cpu_to_le16(enable ? 0x0001 : 0x0000);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
if (!rc)
priv->radio_on = enable;
return rc;
}
static int mwl8k_cmd_radio_disable(struct ieee80211_hw *hw)
{
return mwl8k_cmd_radio_control(hw, 0, 0);
}
static int mwl8k_cmd_radio_enable(struct ieee80211_hw *hw)
{
return mwl8k_cmd_radio_control(hw, 1, 0);
}
static int
mwl8k_set_radio_preamble(struct ieee80211_hw *hw, bool short_preamble)
{
struct mwl8k_priv *priv = hw->priv;
priv->radio_short_preamble = short_preamble;
return mwl8k_cmd_radio_control(hw, 1, 1);
}
static int mwl8k_cmd_rf_tx_power(struct ieee80211_hw *hw, int dBm)
{
struct mwl8k_cmd_rf_tx_power *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_RF_TX_POWER);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(MWL8K_CMD_SET);
cmd->support_level = cpu_to_le16(dBm);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_tx_power(struct ieee80211_hw *hw,
struct ieee80211_conf *conf,
unsigned short pwr)
{
struct ieee80211_channel *channel = conf->channel;
struct mwl8k_cmd_tx_power *cmd;
int rc;
int i;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_TX_POWER);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(MWL8K_CMD_SET_LIST);
if (channel->band == IEEE80211_BAND_2GHZ)
cmd->band = cpu_to_le16(0x1);
else if (channel->band == IEEE80211_BAND_5GHZ)
cmd->band = cpu_to_le16(0x4);
cmd->channel = channel->hw_value;
if (conf->channel_type == NL80211_CHAN_NO_HT ||
conf->channel_type == NL80211_CHAN_HT20) {
cmd->bw = cpu_to_le16(0x2);
} else {
cmd->bw = cpu_to_le16(0x4);
if (conf->channel_type == NL80211_CHAN_HT40MINUS)
cmd->sub_ch = cpu_to_le16(0x3);
else if (conf->channel_type == NL80211_CHAN_HT40PLUS)
cmd->sub_ch = cpu_to_le16(0x1);
}
for (i = 0; i < MWL8K_TX_POWER_LEVEL_TOTAL; i++)
cmd->power_level_list[i] = cpu_to_le16(pwr);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int
mwl8k_cmd_rf_antenna(struct ieee80211_hw *hw, int antenna, int mask)
{
struct mwl8k_cmd_rf_antenna *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_RF_ANTENNA);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->antenna = cpu_to_le16(antenna);
cmd->mode = cpu_to_le16(mask);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_beacon(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u8 *beacon, int len)
{
struct mwl8k_cmd_set_beacon *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd) + len, GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_BEACON);
cmd->header.length = cpu_to_le16(sizeof(*cmd) + len);
cmd->beacon_len = cpu_to_le16(len);
memcpy(cmd->beacon, beacon, len);
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_pre_scan(struct ieee80211_hw *hw)
{
struct mwl8k_cmd_set_pre_scan *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_PRE_SCAN);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int
mwl8k_cmd_set_post_scan(struct ieee80211_hw *hw, const __u8 *mac)
{
struct mwl8k_cmd_set_post_scan *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_POST_SCAN);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->isibss = 0;
memcpy(cmd->bssid, mac, ETH_ALEN);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_rf_channel(struct ieee80211_hw *hw,
struct ieee80211_conf *conf)
{
struct ieee80211_channel *channel = conf->channel;
struct mwl8k_cmd_set_rf_channel *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_RF_CHANNEL);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(MWL8K_CMD_SET);
cmd->current_channel = channel->hw_value;
if (channel->band == IEEE80211_BAND_2GHZ)
cmd->channel_flags |= cpu_to_le32(0x00000001);
else if (channel->band == IEEE80211_BAND_5GHZ)
cmd->channel_flags |= cpu_to_le32(0x00000004);
if (conf->channel_type == NL80211_CHAN_NO_HT ||
conf->channel_type == NL80211_CHAN_HT20)
cmd->channel_flags |= cpu_to_le32(0x00000080);
else if (conf->channel_type == NL80211_CHAN_HT40MINUS)
cmd->channel_flags |= cpu_to_le32(0x000001900);
else if (conf->channel_type == NL80211_CHAN_HT40PLUS)
cmd->channel_flags |= cpu_to_le32(0x000000900);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static void legacy_rate_mask_to_array(u8 *rates, u32 mask)
{
int i;
int j;
mask &= 0x1fef;
for (i = 0, j = 0; i < 14; i++) {
if (mask & (1 << i))
rates[j++] = mwl8k_rates_24[i].hw_value;
}
}
static int
mwl8k_cmd_set_aid(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u32 legacy_rate_mask)
{
struct mwl8k_cmd_update_set_aid *cmd;
u16 prot_mode;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_AID);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->aid = cpu_to_le16(vif->bss_conf.aid);
memcpy(cmd->bssid, vif->bss_conf.bssid, ETH_ALEN);
if (vif->bss_conf.use_cts_prot) {
prot_mode = MWL8K_FRAME_PROT_11G;
} else {
switch (vif->bss_conf.ht_operation_mode &
IEEE80211_HT_OP_MODE_PROTECTION) {
case IEEE80211_HT_OP_MODE_PROTECTION_20MHZ:
prot_mode = MWL8K_FRAME_PROT_11N_HT_40MHZ_ONLY;
break;
case IEEE80211_HT_OP_MODE_PROTECTION_NONHT_MIXED:
prot_mode = MWL8K_FRAME_PROT_11N_HT_ALL;
break;
default:
prot_mode = MWL8K_FRAME_PROT_DISABLED;
break;
}
}
cmd->protection_mode = cpu_to_le16(prot_mode);
legacy_rate_mask_to_array(cmd->supp_rates, legacy_rate_mask);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int
mwl8k_cmd_set_rate(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
u32 legacy_rate_mask, u8 *mcs_rates)
{
struct mwl8k_cmd_set_rate *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_RATE);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
legacy_rate_mask_to_array(cmd->legacy_rates, legacy_rate_mask);
memcpy(cmd->mcs_set, mcs_rates, 16);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_finalize_join(struct ieee80211_hw *hw, void *frame,
int framelen, int dtim)
{
struct mwl8k_cmd_finalize_join *cmd;
struct ieee80211_mgmt *payload = frame;
int payload_len;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_FINALIZE_JOIN);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->sleep_interval = cpu_to_le32(dtim ? dtim : 1);
payload_len = framelen - ieee80211_hdrlen(payload->frame_control);
if (payload_len < 0)
payload_len = 0;
else if (payload_len > MWL8K_FJ_BEACON_MAXLEN)
payload_len = MWL8K_FJ_BEACON_MAXLEN;
memcpy(cmd->beacon_data, &payload->u.beacon, payload_len);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int
mwl8k_cmd_set_rts_threshold(struct ieee80211_hw *hw, int rts_thresh)
{
struct mwl8k_cmd_set_rts_threshold *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_RTS_THRESHOLD);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(MWL8K_CMD_SET);
cmd->threshold = cpu_to_le16(rts_thresh);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_slot(struct ieee80211_hw *hw, bool short_slot_time)
{
struct mwl8k_cmd_set_slot *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_SLOT);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(MWL8K_CMD_SET);
cmd->short_slot = short_slot_time;
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int
mwl8k_cmd_set_edca_params(struct ieee80211_hw *hw, __u8 qnum,
__u16 cw_min, __u16 cw_max,
__u8 aifs, __u16 txop)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_cmd_set_edca_params *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_EDCA_PARAMS);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(MWL8K_SET_EDCA_ALL);
cmd->txop = cpu_to_le16(txop);
if (priv->ap_fw) {
cmd->ap.log_cw_max = cpu_to_le32(ilog2(cw_max + 1));
cmd->ap.log_cw_min = cpu_to_le32(ilog2(cw_min + 1));
cmd->ap.aifs = aifs;
cmd->ap.txq = qnum;
} else {
cmd->sta.log_cw_max = (u8)ilog2(cw_max + 1);
cmd->sta.log_cw_min = (u8)ilog2(cw_min + 1);
cmd->sta.aifs = aifs;
cmd->sta.txq = qnum;
}
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_wmm_mode(struct ieee80211_hw *hw, bool enable)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_cmd_set_wmm_mode *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_WMM_MODE);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(!!enable);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
if (!rc)
priv->wmm_enabled = enable;
return rc;
}
static int mwl8k_cmd_mimo_config(struct ieee80211_hw *hw, __u8 rx, __u8 tx)
{
struct mwl8k_cmd_mimo_config *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_MIMO_CONFIG);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32((u32)MWL8K_CMD_SET);
cmd->rx_antenna_map = rx;
cmd->tx_antenna_map = tx;
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_use_fixed_rate_sta(struct ieee80211_hw *hw)
{
struct mwl8k_cmd_use_fixed_rate_sta *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_USE_FIXED_RATE);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(MWL8K_USE_AUTO_RATE);
cmd->rate_type = cpu_to_le32(MWL8K_UCAST_RATE);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int
mwl8k_cmd_use_fixed_rate_ap(struct ieee80211_hw *hw, int mcast, int mgmt)
{
struct mwl8k_cmd_use_fixed_rate_ap *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_USE_FIXED_RATE);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(MWL8K_USE_AUTO_RATE);
cmd->multicast_rate = mcast;
cmd->management_rate = mgmt;
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_enable_sniffer(struct ieee80211_hw *hw, bool enable)
{
struct mwl8k_cmd_enable_sniffer *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_ENABLE_SNIFFER);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(!!enable);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_mac_addr(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u8 *mac)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_vif *mwl8k_vif = MWL8K_VIF(vif);
struct mwl8k_cmd_set_mac_addr *cmd;
int mac_type;
int rc;
mac_type = MWL8K_MAC_TYPE_PRIMARY_AP;
if (vif != NULL && vif->type == NL80211_IFTYPE_STATION) {
if (mwl8k_vif->macid + 1 == ffs(priv->sta_macids_supported))
mac_type = MWL8K_MAC_TYPE_PRIMARY_CLIENT;
else
mac_type = MWL8K_MAC_TYPE_SECONDARY_CLIENT;
} else if (vif != NULL && vif->type == NL80211_IFTYPE_AP) {
if (mwl8k_vif->macid + 1 == ffs(priv->ap_macids_supported))
mac_type = MWL8K_MAC_TYPE_PRIMARY_AP;
else
mac_type = MWL8K_MAC_TYPE_SECONDARY_AP;
}
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_MAC_ADDR);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
if (priv->ap_fw) {
cmd->mbss.mac_type = cpu_to_le16(mac_type);
memcpy(cmd->mbss.mac_addr, mac, ETH_ALEN);
} else {
memcpy(cmd->mac_addr, mac, ETH_ALEN);
}
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_rateadapt_mode(struct ieee80211_hw *hw, __u16 mode)
{
struct mwl8k_cmd_set_rate_adapt_mode *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_RATEADAPT_MODE);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le16(MWL8K_CMD_SET);
cmd->mode = cpu_to_le16(mode);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_get_watchdog_bitmap(struct ieee80211_hw *hw, u8 *bitmap)
{
struct mwl8k_cmd_get_watchdog_bitmap *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_GET_WATCHDOG_BITMAP);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
rc = mwl8k_post_cmd(hw, &cmd->header);
if (!rc)
*bitmap = cmd->bitmap;
kfree(cmd);
return rc;
}
static void mwl8k_watchdog_ba_events(struct work_struct *work)
{
int rc;
u8 bitmap = 0, stream_index;
struct mwl8k_ampdu_stream *streams;
struct mwl8k_priv *priv =
container_of(work, struct mwl8k_priv, watchdog_ba_handle);
rc = mwl8k_cmd_get_watchdog_bitmap(priv->hw, &bitmap);
if (rc)
return;
if (bitmap == INVALID_BA)
return;
stream_index = bitmap - MWL8K_TX_WMM_QUEUES;
BUG_ON(stream_index >= priv->num_ampdu_queues);
streams = &priv->ampdu[stream_index];
if (streams->state == AMPDU_STREAM_ACTIVE)
ieee80211_stop_tx_ba_session(streams->sta, streams->tid);
return;
}
static int mwl8k_cmd_bss_start(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, int enable)
{
struct mwl8k_cmd_bss_start *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_BSS_START);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->enable = cpu_to_le32(enable);
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
kfree(cmd);
return rc;
}
static int
mwl8k_check_ba(struct ieee80211_hw *hw, struct mwl8k_ampdu_stream *stream)
{
struct mwl8k_cmd_bastream *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_BASTREAM);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(MWL8K_BA_CHECK);
cmd->create_params.queue_id = stream->idx;
memcpy(&cmd->create_params.peer_mac_addr[0], stream->sta->addr,
ETH_ALEN);
cmd->create_params.tid = stream->tid;
cmd->create_params.flags =
cpu_to_le32(BASTREAM_FLAG_IMMEDIATE_TYPE) |
cpu_to_le32(BASTREAM_FLAG_DIRECTION_UPSTREAM);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static int
mwl8k_create_ba(struct ieee80211_hw *hw, struct mwl8k_ampdu_stream *stream,
u8 buf_size)
{
struct mwl8k_cmd_bastream *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_BASTREAM);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(MWL8K_BA_CREATE);
cmd->create_params.bar_thrs = cpu_to_le32((u32)buf_size);
cmd->create_params.window_size = cpu_to_le32((u32)buf_size);
cmd->create_params.queue_id = stream->idx;
memcpy(cmd->create_params.peer_mac_addr, stream->sta->addr, ETH_ALEN);
cmd->create_params.tid = stream->tid;
cmd->create_params.curr_seq_no = cpu_to_le16(0);
cmd->create_params.reset_seq_no_flag = 1;
cmd->create_params.param_info =
(stream->sta->ht_cap.ampdu_factor &
IEEE80211_HT_AMPDU_PARM_FACTOR) |
((stream->sta->ht_cap.ampdu_density << 2) &
IEEE80211_HT_AMPDU_PARM_DENSITY);
cmd->create_params.flags =
cpu_to_le32(BASTREAM_FLAG_IMMEDIATE_TYPE |
BASTREAM_FLAG_DIRECTION_UPSTREAM);
rc = mwl8k_post_cmd(hw, &cmd->header);
wiphy_debug(hw->wiphy, "Created a BA stream for %pM : tid %d\n",
stream->sta->addr, stream->tid);
kfree(cmd);
return rc;
}
static void mwl8k_destroy_ba(struct ieee80211_hw *hw,
struct mwl8k_ampdu_stream *stream)
{
struct mwl8k_cmd_bastream *cmd;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return;
cmd->header.code = cpu_to_le16(MWL8K_CMD_BASTREAM);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(MWL8K_BA_DESTROY);
cmd->destroy_params.ba_context = cpu_to_le32(stream->idx);
mwl8k_post_cmd(hw, &cmd->header);
wiphy_debug(hw->wiphy, "Deleted BA stream index %d\n", stream->idx);
kfree(cmd);
}
static int mwl8k_cmd_set_new_stn_add(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct mwl8k_cmd_set_new_stn *cmd;
u32 rates;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_NEW_STN);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->aid = cpu_to_le16(sta->aid);
memcpy(cmd->mac_addr, sta->addr, ETH_ALEN);
cmd->stn_id = cpu_to_le16(sta->aid);
cmd->action = cpu_to_le16(MWL8K_STA_ACTION_ADD);
if (hw->conf.channel->band == IEEE80211_BAND_2GHZ)
rates = sta->supp_rates[IEEE80211_BAND_2GHZ];
else
rates = sta->supp_rates[IEEE80211_BAND_5GHZ] << 5;
cmd->legacy_rates = cpu_to_le32(rates);
if (sta->ht_cap.ht_supported) {
cmd->ht_rates[0] = sta->ht_cap.mcs.rx_mask[0];
cmd->ht_rates[1] = sta->ht_cap.mcs.rx_mask[1];
cmd->ht_rates[2] = sta->ht_cap.mcs.rx_mask[2];
cmd->ht_rates[3] = sta->ht_cap.mcs.rx_mask[3];
cmd->ht_capabilities_info = cpu_to_le16(sta->ht_cap.cap);
cmd->mac_ht_param_info = (sta->ht_cap.ampdu_factor & 3) |
((sta->ht_cap.ampdu_density & 7) << 2);
cmd->is_qos_sta = 1;
}
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_new_stn_add_self(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct mwl8k_cmd_set_new_stn *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_NEW_STN);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
memcpy(cmd->mac_addr, vif->addr, ETH_ALEN);
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_set_new_stn_del(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u8 *addr)
{
struct mwl8k_cmd_set_new_stn *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_SET_NEW_STN);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
memcpy(cmd->mac_addr, addr, ETH_ALEN);
cmd->action = cpu_to_le16(MWL8K_STA_ACTION_REMOVE);
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_cmd_update_encryption_enable(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
u8 *addr,
u8 encr_type)
{
struct mwl8k_cmd_update_encryption *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_UPDATE_ENCRYPTION);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(MWL8K_ENCR_ENABLE);
memcpy(cmd->mac_addr, addr, ETH_ALEN);
cmd->encr_type = encr_type;
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
kfree(cmd);
return rc;
}
static int mwl8k_encryption_set_cmd_info(struct mwl8k_cmd_set_key *cmd,
u8 *addr,
struct ieee80211_key_conf *key)
{
cmd->header.code = cpu_to_le16(MWL8K_CMD_UPDATE_ENCRYPTION);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->length = cpu_to_le16(sizeof(*cmd) -
offsetof(struct mwl8k_cmd_set_key, length));
cmd->key_id = cpu_to_le32(key->keyidx);
cmd->key_len = cpu_to_le16(key->keylen);
memcpy(cmd->mac_addr, addr, ETH_ALEN);
switch (key->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
cmd->key_type_id = cpu_to_le16(MWL8K_ALG_WEP);
if (key->keyidx == 0)
cmd->key_info = cpu_to_le32(MWL8K_KEY_FLAG_WEP_TXKEY);
break;
case WLAN_CIPHER_SUITE_TKIP:
cmd->key_type_id = cpu_to_le16(MWL8K_ALG_TKIP);
cmd->key_info = (key->flags & IEEE80211_KEY_FLAG_PAIRWISE)
? cpu_to_le32(MWL8K_KEY_FLAG_PAIRWISE)
: cpu_to_le32(MWL8K_KEY_FLAG_TXGROUPKEY);
cmd->key_info |= cpu_to_le32(MWL8K_KEY_FLAG_MICKEY_VALID
| MWL8K_KEY_FLAG_TSC_VALID);
break;
case WLAN_CIPHER_SUITE_CCMP:
cmd->key_type_id = cpu_to_le16(MWL8K_ALG_CCMP);
cmd->key_info = (key->flags & IEEE80211_KEY_FLAG_PAIRWISE)
? cpu_to_le32(MWL8K_KEY_FLAG_PAIRWISE)
: cpu_to_le32(MWL8K_KEY_FLAG_TXGROUPKEY);
break;
default:
return -ENOTSUPP;
}
return 0;
}
static int mwl8k_cmd_encryption_set_key(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
u8 *addr,
struct ieee80211_key_conf *key)
{
struct mwl8k_cmd_set_key *cmd;
int rc;
int keymlen;
u32 action;
u8 idx;
struct mwl8k_vif *mwl8k_vif = MWL8K_VIF(vif);
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
rc = mwl8k_encryption_set_cmd_info(cmd, addr, key);
if (rc < 0)
goto done;
idx = key->keyidx;
if (key->flags & IEEE80211_KEY_FLAG_PAIRWISE)
action = MWL8K_ENCR_SET_KEY;
else
action = MWL8K_ENCR_SET_GROUP_KEY;
switch (key->cipher) {
case WLAN_CIPHER_SUITE_WEP40:
case WLAN_CIPHER_SUITE_WEP104:
if (!mwl8k_vif->wep_key_conf[idx].enabled) {
memcpy(mwl8k_vif->wep_key_conf[idx].key, key,
sizeof(*key) + key->keylen);
mwl8k_vif->wep_key_conf[idx].enabled = 1;
}
keymlen = key->keylen;
action = MWL8K_ENCR_SET_KEY;
break;
case WLAN_CIPHER_SUITE_TKIP:
keymlen = MAX_ENCR_KEY_LENGTH + 2 * MIC_KEY_LENGTH;
break;
case WLAN_CIPHER_SUITE_CCMP:
keymlen = key->keylen;
break;
default:
rc = -ENOTSUPP;
goto done;
}
memcpy(cmd->key_material, key->key, keymlen);
cmd->action = cpu_to_le32(action);
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
done:
kfree(cmd);
return rc;
}
static int mwl8k_cmd_encryption_remove_key(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
u8 *addr,
struct ieee80211_key_conf *key)
{
struct mwl8k_cmd_set_key *cmd;
int rc;
struct mwl8k_vif *mwl8k_vif = MWL8K_VIF(vif);
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
rc = mwl8k_encryption_set_cmd_info(cmd, addr, key);
if (rc < 0)
goto done;
if (key->cipher == WLAN_CIPHER_SUITE_WEP40 ||
WLAN_CIPHER_SUITE_WEP104)
mwl8k_vif->wep_key_conf[key->keyidx].enabled = 0;
cmd->action = cpu_to_le32(MWL8K_ENCR_REMOVE_KEY);
rc = mwl8k_post_pervif_cmd(hw, vif, &cmd->header);
done:
kfree(cmd);
return rc;
}
static int mwl8k_set_key(struct ieee80211_hw *hw,
enum set_key_cmd cmd_param,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta,
struct ieee80211_key_conf *key)
{
int rc = 0;
u8 encr_type;
u8 *addr;
struct mwl8k_vif *mwl8k_vif = MWL8K_VIF(vif);
if (vif->type == NL80211_IFTYPE_STATION)
return -EOPNOTSUPP;
if (sta == NULL)
addr = hw->wiphy->perm_addr;
else
addr = sta->addr;
if (cmd_param == SET_KEY) {
rc = mwl8k_cmd_encryption_set_key(hw, vif, addr, key);
if (rc)
goto out;
if ((key->cipher == WLAN_CIPHER_SUITE_WEP40)
|| (key->cipher == WLAN_CIPHER_SUITE_WEP104))
encr_type = MWL8K_UPDATE_ENCRYPTION_TYPE_WEP;
else
encr_type = MWL8K_UPDATE_ENCRYPTION_TYPE_MIXED;
rc = mwl8k_cmd_update_encryption_enable(hw, vif, addr,
encr_type);
if (rc)
goto out;
mwl8k_vif->is_hw_crypto_enabled = true;
} else {
rc = mwl8k_cmd_encryption_remove_key(hw, vif, addr, key);
if (rc)
goto out;
mwl8k_vif->is_hw_crypto_enabled = false;
}
out:
return rc;
}
static int mwl8k_cmd_update_stadb_add(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct mwl8k_cmd_update_stadb *cmd;
struct peer_capability_info *p;
u32 rates;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_UPDATE_STADB);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(MWL8K_STA_DB_MODIFY_ENTRY);
memcpy(cmd->peer_addr, sta->addr, ETH_ALEN);
p = &cmd->peer_info;
p->peer_type = MWL8K_PEER_TYPE_ACCESSPOINT;
p->basic_caps = cpu_to_le16(vif->bss_conf.assoc_capability);
p->ht_support = sta->ht_cap.ht_supported;
p->ht_caps = cpu_to_le16(sta->ht_cap.cap);
p->extended_ht_caps = (sta->ht_cap.ampdu_factor & 3) |
((sta->ht_cap.ampdu_density & 7) << 2);
if (hw->conf.channel->band == IEEE80211_BAND_2GHZ)
rates = sta->supp_rates[IEEE80211_BAND_2GHZ];
else
rates = sta->supp_rates[IEEE80211_BAND_5GHZ] << 5;
legacy_rate_mask_to_array(p->legacy_rates, rates);
memcpy(p->ht_rates, sta->ht_cap.mcs.rx_mask, 16);
p->interop = 1;
p->amsdu_enabled = 0;
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc ? rc : p->station_id;
}
static int mwl8k_cmd_update_stadb_del(struct ieee80211_hw *hw,
struct ieee80211_vif *vif, u8 *addr)
{
struct mwl8k_cmd_update_stadb *cmd;
int rc;
cmd = kzalloc(sizeof(*cmd), GFP_KERNEL);
if (cmd == NULL)
return -ENOMEM;
cmd->header.code = cpu_to_le16(MWL8K_CMD_UPDATE_STADB);
cmd->header.length = cpu_to_le16(sizeof(*cmd));
cmd->action = cpu_to_le32(MWL8K_STA_DB_DEL_ENTRY);
memcpy(cmd->peer_addr, addr, ETH_ALEN);
rc = mwl8k_post_cmd(hw, &cmd->header);
kfree(cmd);
return rc;
}
static irqreturn_t mwl8k_interrupt(int irq, void *dev_id)
{
struct ieee80211_hw *hw = dev_id;
struct mwl8k_priv *priv = hw->priv;
u32 status;
status = ioread32(priv->regs + MWL8K_HIU_A2H_INTERRUPT_STATUS);
if (!status)
return IRQ_NONE;
if (status & MWL8K_A2H_INT_TX_DONE) {
status &= ~MWL8K_A2H_INT_TX_DONE;
tasklet_schedule(&priv->poll_tx_task);
}
if (status & MWL8K_A2H_INT_RX_READY) {
status &= ~MWL8K_A2H_INT_RX_READY;
tasklet_schedule(&priv->poll_rx_task);
}
if (status & MWL8K_A2H_INT_BA_WATCHDOG) {
status &= ~MWL8K_A2H_INT_BA_WATCHDOG;
ieee80211_queue_work(hw, &priv->watchdog_ba_handle);
}
if (status)
iowrite32(~status, priv->regs + MWL8K_HIU_A2H_INTERRUPT_STATUS);
if (status & MWL8K_A2H_INT_OPC_DONE) {
if (priv->hostcmd_wait != NULL)
complete(priv->hostcmd_wait);
}
if (status & MWL8K_A2H_INT_QUEUE_EMPTY) {
if (!mutex_is_locked(&priv->fw_mutex) &&
priv->radio_on && priv->pending_tx_pkts)
mwl8k_tx_start(priv);
}
return IRQ_HANDLED;
}
static void mwl8k_tx_poll(unsigned long data)
{
struct ieee80211_hw *hw = (struct ieee80211_hw *)data;
struct mwl8k_priv *priv = hw->priv;
int limit;
int i;
limit = 32;
spin_lock_bh(&priv->tx_lock);
for (i = 0; i < mwl8k_tx_queues(priv); i++)
limit -= mwl8k_txq_reclaim(hw, i, limit, 0);
if (!priv->pending_tx_pkts && priv->tx_wait != NULL) {
complete(priv->tx_wait);
priv->tx_wait = NULL;
}
spin_unlock_bh(&priv->tx_lock);
if (limit) {
writel(~MWL8K_A2H_INT_TX_DONE,
priv->regs + MWL8K_HIU_A2H_INTERRUPT_STATUS);
} else {
tasklet_schedule(&priv->poll_tx_task);
}
}
static void mwl8k_rx_poll(unsigned long data)
{
struct ieee80211_hw *hw = (struct ieee80211_hw *)data;
struct mwl8k_priv *priv = hw->priv;
int limit;
limit = 32;
limit -= rxq_process(hw, 0, limit);
limit -= rxq_refill(hw, 0, limit);
if (limit) {
writel(~MWL8K_A2H_INT_RX_READY,
priv->regs + MWL8K_HIU_A2H_INTERRUPT_STATUS);
} else {
tasklet_schedule(&priv->poll_rx_task);
}
}
static void mwl8k_tx(struct ieee80211_hw *hw, struct sk_buff *skb)
{
struct mwl8k_priv *priv = hw->priv;
int index = skb_get_queue_mapping(skb);
if (!priv->radio_on) {
wiphy_debug(hw->wiphy,
"dropped TX frame since radio disabled\n");
dev_kfree_skb(skb);
return;
}
mwl8k_txq_xmit(hw, index, skb);
}
static int mwl8k_start(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
int rc;
rc = request_irq(priv->pdev->irq, mwl8k_interrupt,
IRQF_SHARED, MWL8K_NAME, hw);
if (rc) {
priv->irq = -1;
wiphy_err(hw->wiphy, "failed to register IRQ handler\n");
return -EIO;
}
priv->irq = priv->pdev->irq;
tasklet_enable(&priv->poll_tx_task);
tasklet_enable(&priv->poll_rx_task);
iowrite32(MWL8K_A2H_EVENTS, priv->regs + MWL8K_HIU_A2H_INTERRUPT_MASK);
iowrite32(MWL8K_A2H_EVENTS,
priv->regs + MWL8K_HIU_A2H_INTERRUPT_STATUS_MASK);
rc = mwl8k_fw_lock(hw);
if (!rc) {
rc = mwl8k_cmd_radio_enable(hw);
if (!priv->ap_fw) {
if (!rc)
rc = mwl8k_cmd_enable_sniffer(hw, 0);
if (!rc)
rc = mwl8k_cmd_set_pre_scan(hw);
if (!rc)
rc = mwl8k_cmd_set_post_scan(hw,
"\x00\x00\x00\x00\x00\x00");
}
if (!rc)
rc = mwl8k_cmd_set_rateadapt_mode(hw, 0);
if (!rc)
rc = mwl8k_cmd_set_wmm_mode(hw, 0);
mwl8k_fw_unlock(hw);
}
if (rc) {
iowrite32(0, priv->regs + MWL8K_HIU_A2H_INTERRUPT_MASK);
free_irq(priv->pdev->irq, hw);
priv->irq = -1;
tasklet_disable(&priv->poll_tx_task);
tasklet_disable(&priv->poll_rx_task);
}
return rc;
}
static void mwl8k_stop(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
int i;
mwl8k_cmd_radio_disable(hw);
ieee80211_stop_queues(hw);
iowrite32(0, priv->regs + MWL8K_HIU_A2H_INTERRUPT_MASK);
if (priv->irq != -1) {
free_irq(priv->pdev->irq, hw);
priv->irq = -1;
}
cancel_work_sync(&priv->finalize_join_worker);
cancel_work_sync(&priv->watchdog_ba_handle);
if (priv->beacon_skb != NULL)
dev_kfree_skb(priv->beacon_skb);
tasklet_disable(&priv->poll_tx_task);
tasklet_disable(&priv->poll_rx_task);
for (i = 0; i < mwl8k_tx_queues(priv); i++)
mwl8k_txq_reclaim(hw, i, INT_MAX, 1);
}
static int mwl8k_add_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_vif *mwl8k_vif;
u32 macids_supported;
int macid, rc;
struct mwl8k_device_info *di;
if (priv->sniffer_enabled) {
wiphy_info(hw->wiphy,
"unable to create STA interface because sniffer mode is enabled\n");
return -EINVAL;
}
di = priv->device_info;
switch (vif->type) {
case NL80211_IFTYPE_AP:
if (!priv->ap_fw && di->fw_image_ap) {
if (!list_empty(&priv->vif_list))
return -EBUSY;
rc = mwl8k_reload_firmware(hw, di->fw_image_ap);
if (rc)
return rc;
}
macids_supported = priv->ap_macids_supported;
break;
case NL80211_IFTYPE_STATION:
if (priv->ap_fw && di->fw_image_sta) {
if (!list_empty(&priv->vif_list))
return -EBUSY;
rc = mwl8k_reload_firmware(hw, di->fw_image_sta);
if (rc)
return rc;
}
macids_supported = priv->sta_macids_supported;
break;
default:
return -EINVAL;
}
macid = ffs(macids_supported & ~priv->macids_used);
if (!macid--)
return -EBUSY;
mwl8k_vif = MWL8K_VIF(vif);
memset(mwl8k_vif, 0, sizeof(*mwl8k_vif));
mwl8k_vif->vif = vif;
mwl8k_vif->macid = macid;
mwl8k_vif->seqno = 0;
memcpy(mwl8k_vif->bssid, vif->addr, ETH_ALEN);
mwl8k_vif->is_hw_crypto_enabled = false;
mwl8k_cmd_set_mac_addr(hw, vif, vif->addr);
if (priv->ap_fw)
mwl8k_cmd_set_new_stn_add_self(hw, vif);
priv->macids_used |= 1 << mwl8k_vif->macid;
list_add_tail(&mwl8k_vif->list, &priv->vif_list);
return 0;
}
static void mwl8k_remove_interface(struct ieee80211_hw *hw,
struct ieee80211_vif *vif)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_vif *mwl8k_vif = MWL8K_VIF(vif);
if (priv->ap_fw)
mwl8k_cmd_set_new_stn_del(hw, vif, vif->addr);
mwl8k_cmd_set_mac_addr(hw, vif, "\x00\x00\x00\x00\x00\x00");
priv->macids_used &= ~(1 << mwl8k_vif->macid);
list_del(&mwl8k_vif->list);
}
static int mwl8k_config(struct ieee80211_hw *hw, u32 changed)
{
struct ieee80211_conf *conf = &hw->conf;
struct mwl8k_priv *priv = hw->priv;
int rc;
if (conf->flags & IEEE80211_CONF_IDLE) {
mwl8k_cmd_radio_disable(hw);
return 0;
}
rc = mwl8k_fw_lock(hw);
if (rc)
return rc;
rc = mwl8k_cmd_radio_enable(hw);
if (rc)
goto out;
rc = mwl8k_cmd_set_rf_channel(hw, conf);
if (rc)
goto out;
if (conf->power_level > 18)
conf->power_level = 18;
if (priv->ap_fw) {
if (conf->flags & IEEE80211_CONF_CHANGE_POWER) {
rc = mwl8k_cmd_tx_power(hw, conf, conf->power_level);
if (rc)
goto out;
}
rc = mwl8k_cmd_rf_antenna(hw, MWL8K_RF_ANTENNA_RX, 0x3);
if (rc)
wiphy_warn(hw->wiphy, "failed to set # of RX antennas");
rc = mwl8k_cmd_rf_antenna(hw, MWL8K_RF_ANTENNA_TX, 0x7);
if (rc)
wiphy_warn(hw->wiphy, "failed to set # of TX antennas");
} else {
rc = mwl8k_cmd_rf_tx_power(hw, conf->power_level);
if (rc)
goto out;
rc = mwl8k_cmd_mimo_config(hw, 0x7, 0x7);
}
out:
mwl8k_fw_unlock(hw);
return rc;
}
static void
mwl8k_bss_info_changed_sta(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_bss_conf *info, u32 changed)
{
struct mwl8k_priv *priv = hw->priv;
u32 ap_legacy_rates = 0;
u8 ap_mcs_rates[16];
int rc;
if (mwl8k_fw_lock(hw))
return;
if ((changed & BSS_CHANGED_ASSOC) && !vif->bss_conf.assoc)
priv->capture_beacon = false;
if (vif->bss_conf.assoc) {
struct ieee80211_sta *ap;
rcu_read_lock();
ap = ieee80211_find_sta(vif, vif->bss_conf.bssid);
if (ap == NULL) {
rcu_read_unlock();
goto out;
}
if (hw->conf.channel->band == IEEE80211_BAND_2GHZ) {
ap_legacy_rates = ap->supp_rates[IEEE80211_BAND_2GHZ];
} else {
ap_legacy_rates =
ap->supp_rates[IEEE80211_BAND_5GHZ] << 5;
}
memcpy(ap_mcs_rates, ap->ht_cap.mcs.rx_mask, 16);
rcu_read_unlock();
}
if ((changed & BSS_CHANGED_ASSOC) && vif->bss_conf.assoc) {
rc = mwl8k_cmd_set_rate(hw, vif, ap_legacy_rates, ap_mcs_rates);
if (rc)
goto out;
rc = mwl8k_cmd_use_fixed_rate_sta(hw);
if (rc)
goto out;
}
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
rc = mwl8k_set_radio_preamble(hw,
vif->bss_conf.use_short_preamble);
if (rc)
goto out;
}
if (changed & BSS_CHANGED_ERP_SLOT) {
rc = mwl8k_cmd_set_slot(hw, vif->bss_conf.use_short_slot);
if (rc)
goto out;
}
if (vif->bss_conf.assoc &&
(changed & (BSS_CHANGED_ASSOC | BSS_CHANGED_ERP_CTS_PROT |
BSS_CHANGED_HT))) {
rc = mwl8k_cmd_set_aid(hw, vif, ap_legacy_rates);
if (rc)
goto out;
}
if (vif->bss_conf.assoc &&
(changed & (BSS_CHANGED_ASSOC | BSS_CHANGED_BEACON_INT))) {
memcpy(priv->capture_bssid, vif->bss_conf.bssid, ETH_ALEN);
priv->capture_beacon = true;
}
out:
mwl8k_fw_unlock(hw);
}
static void
mwl8k_bss_info_changed_ap(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_bss_conf *info, u32 changed)
{
int rc;
if (mwl8k_fw_lock(hw))
return;
if (changed & BSS_CHANGED_ERP_PREAMBLE) {
rc = mwl8k_set_radio_preamble(hw,
vif->bss_conf.use_short_preamble);
if (rc)
goto out;
}
if (changed & BSS_CHANGED_BASIC_RATES) {
int idx;
int rate;
idx = ffs(vif->bss_conf.basic_rates);
if (idx)
idx--;
if (hw->conf.channel->band == IEEE80211_BAND_2GHZ)
rate = mwl8k_rates_24[idx].hw_value;
else
rate = mwl8k_rates_50[idx].hw_value;
mwl8k_cmd_use_fixed_rate_ap(hw, rate, rate);
}
if (changed & (BSS_CHANGED_BEACON_INT | BSS_CHANGED_BEACON)) {
struct sk_buff *skb;
skb = ieee80211_beacon_get(hw, vif);
if (skb != NULL) {
mwl8k_cmd_set_beacon(hw, vif, skb->data, skb->len);
kfree_skb(skb);
}
}
if (changed & BSS_CHANGED_BEACON_ENABLED)
mwl8k_cmd_bss_start(hw, vif, info->enable_beacon);
out:
mwl8k_fw_unlock(hw);
}
static void
mwl8k_bss_info_changed(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
struct ieee80211_bss_conf *info, u32 changed)
{
struct mwl8k_priv *priv = hw->priv;
if (!priv->ap_fw)
mwl8k_bss_info_changed_sta(hw, vif, info, changed);
else
mwl8k_bss_info_changed_ap(hw, vif, info, changed);
}
static u64 mwl8k_prepare_multicast(struct ieee80211_hw *hw,
struct netdev_hw_addr_list *mc_list)
{
struct mwl8k_cmd_pkt *cmd;
cmd = __mwl8k_cmd_mac_multicast_adr(hw, 0, mc_list);
return (unsigned long)cmd;
}
static int
mwl8k_configure_filter_sniffer(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags)
{
struct mwl8k_priv *priv = hw->priv;
if (!list_empty(&priv->vif_list)) {
if (net_ratelimit())
wiphy_info(hw->wiphy,
"not enabling sniffer mode because STA interface is active\n");
return 0;
}
if (!priv->sniffer_enabled) {
if (mwl8k_cmd_enable_sniffer(hw, 1))
return 0;
priv->sniffer_enabled = true;
}
*total_flags &= FIF_PROMISC_IN_BSS | FIF_ALLMULTI |
FIF_BCN_PRBRESP_PROMISC | FIF_CONTROL |
FIF_OTHER_BSS;
return 1;
}
static struct mwl8k_vif *mwl8k_first_vif(struct mwl8k_priv *priv)
{
if (!list_empty(&priv->vif_list))
return list_entry(priv->vif_list.next, struct mwl8k_vif, list);
return NULL;
}
static void mwl8k_configure_filter(struct ieee80211_hw *hw,
unsigned int changed_flags,
unsigned int *total_flags,
u64 multicast)
{
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_cmd_pkt *cmd = (void *)(unsigned long)multicast;
if (priv->ap_fw) {
*total_flags &= FIF_ALLMULTI | FIF_BCN_PRBRESP_PROMISC;
kfree(cmd);
return;
}
if (*total_flags & (FIF_CONTROL | FIF_OTHER_BSS) &&
mwl8k_configure_filter_sniffer(hw, changed_flags, total_flags)) {
kfree(cmd);
return;
}
*total_flags &= FIF_ALLMULTI | FIF_BCN_PRBRESP_PROMISC;
if (mwl8k_fw_lock(hw)) {
kfree(cmd);
return;
}
if (priv->sniffer_enabled) {
mwl8k_cmd_enable_sniffer(hw, 0);
priv->sniffer_enabled = false;
}
if (changed_flags & FIF_BCN_PRBRESP_PROMISC) {
if (*total_flags & FIF_BCN_PRBRESP_PROMISC) {
mwl8k_cmd_set_pre_scan(hw);
} else {
struct mwl8k_vif *mwl8k_vif;
const u8 *bssid;
mwl8k_vif = mwl8k_first_vif(priv);
if (mwl8k_vif != NULL)
bssid = mwl8k_vif->vif->bss_conf.bssid;
else
bssid = "\x01\x00\x00\x00\x00\x00";
mwl8k_cmd_set_post_scan(hw, bssid);
}
}
if (*total_flags & FIF_ALLMULTI) {
kfree(cmd);
cmd = __mwl8k_cmd_mac_multicast_adr(hw, 1, NULL);
}
if (cmd != NULL) {
mwl8k_post_cmd(hw, cmd);
kfree(cmd);
}
mwl8k_fw_unlock(hw);
}
static int mwl8k_set_rts_threshold(struct ieee80211_hw *hw, u32 value)
{
return mwl8k_cmd_set_rts_threshold(hw, value);
}
static int mwl8k_sta_remove(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct mwl8k_priv *priv = hw->priv;
if (priv->ap_fw)
return mwl8k_cmd_set_new_stn_del(hw, vif, sta->addr);
else
return mwl8k_cmd_update_stadb_del(hw, vif, sta->addr);
}
static int mwl8k_sta_add(struct ieee80211_hw *hw,
struct ieee80211_vif *vif,
struct ieee80211_sta *sta)
{
struct mwl8k_priv *priv = hw->priv;
int ret;
int i;
struct mwl8k_vif *mwl8k_vif = MWL8K_VIF(vif);
struct ieee80211_key_conf *key;
if (!priv->ap_fw) {
ret = mwl8k_cmd_update_stadb_add(hw, vif, sta);
if (ret >= 0) {
MWL8K_STA(sta)->peer_id = ret;
if (sta->ht_cap.ht_supported)
MWL8K_STA(sta)->is_ampdu_allowed = true;
ret = 0;
}
} else {
ret = mwl8k_cmd_set_new_stn_add(hw, vif, sta);
}
for (i = 0; i < NUM_WEP_KEYS; i++) {
key = IEEE80211_KEY_CONF(mwl8k_vif->wep_key_conf[i].key);
if (mwl8k_vif->wep_key_conf[i].enabled)
mwl8k_set_key(hw, SET_KEY, vif, sta, key);
}
return ret;
}
static int mwl8k_conf_tx(struct ieee80211_hw *hw, u16 queue,
const struct ieee80211_tx_queue_params *params)
{
struct mwl8k_priv *priv = hw->priv;
int rc;
rc = mwl8k_fw_lock(hw);
if (!rc) {
BUG_ON(queue > MWL8K_TX_WMM_QUEUES - 1);
memcpy(&priv->wmm_params[queue], params, sizeof(*params));
if (!priv->wmm_enabled)
rc = mwl8k_cmd_set_wmm_mode(hw, 1);
if (!rc) {
int q = MWL8K_TX_WMM_QUEUES - 1 - queue;
rc = mwl8k_cmd_set_edca_params(hw, q,
params->cw_min,
params->cw_max,
params->aifs,
params->txop);
}
mwl8k_fw_unlock(hw);
}
return rc;
}
static int mwl8k_get_stats(struct ieee80211_hw *hw,
struct ieee80211_low_level_stats *stats)
{
return mwl8k_cmd_get_stat(hw, stats);
}
static int mwl8k_get_survey(struct ieee80211_hw *hw, int idx,
struct survey_info *survey)
{
struct mwl8k_priv *priv = hw->priv;
struct ieee80211_conf *conf = &hw->conf;
if (idx != 0)
return -ENOENT;
survey->channel = conf->channel;
survey->filled = SURVEY_INFO_NOISE_DBM;
survey->noise = priv->noise;
return 0;
}
static int
mwl8k_ampdu_action(struct ieee80211_hw *hw, struct ieee80211_vif *vif,
enum ieee80211_ampdu_mlme_action action,
struct ieee80211_sta *sta, u16 tid, u16 *ssn,
u8 buf_size)
{
int i, rc = 0;
struct mwl8k_priv *priv = hw->priv;
struct mwl8k_ampdu_stream *stream;
u8 *addr = sta->addr;
if (!(hw->flags & IEEE80211_HW_AMPDU_AGGREGATION))
return -ENOTSUPP;
spin_lock(&priv->stream_lock);
stream = mwl8k_lookup_stream(hw, addr, tid);
switch (action) {
case IEEE80211_AMPDU_RX_START:
case IEEE80211_AMPDU_RX_STOP:
break;
case IEEE80211_AMPDU_TX_START:
*ssn = 0;
if (stream == NULL) {
wiphy_warn(hw->wiphy, "Unexpected call to %s. "
"Proceeding anyway.\n", __func__);
stream = mwl8k_add_stream(hw, sta, tid);
}
if (stream == NULL) {
wiphy_debug(hw->wiphy, "no free AMPDU streams\n");
rc = -EBUSY;
break;
}
stream->state = AMPDU_STREAM_IN_PROGRESS;
spin_unlock(&priv->stream_lock);
for (i = 0; i < MAX_AMPDU_ATTEMPTS; i++) {
rc = mwl8k_check_ba(hw, stream);
if (!rc)
break;
msleep(1000);
}
spin_lock(&priv->stream_lock);
if (rc) {
wiphy_err(hw->wiphy, "Stream for tid %d busy after %d"
" attempts\n", tid, MAX_AMPDU_ATTEMPTS);
mwl8k_remove_stream(hw, stream);
rc = -EBUSY;
break;
}
ieee80211_start_tx_ba_cb_irqsafe(vif, addr, tid);
break;
case IEEE80211_AMPDU_TX_STOP:
if (stream == NULL)
break;
if (stream->state == AMPDU_STREAM_ACTIVE) {
spin_unlock(&priv->stream_lock);
mwl8k_destroy_ba(hw, stream);
spin_lock(&priv->stream_lock);
}
mwl8k_remove_stream(hw, stream);
ieee80211_stop_tx_ba_cb_irqsafe(vif, addr, tid);
break;
case IEEE80211_AMPDU_TX_OPERATIONAL:
BUG_ON(stream == NULL);
BUG_ON(stream->state != AMPDU_STREAM_IN_PROGRESS);
spin_unlock(&priv->stream_lock);
rc = mwl8k_create_ba(hw, stream, buf_size);
spin_lock(&priv->stream_lock);
if (!rc)
stream->state = AMPDU_STREAM_ACTIVE;
else {
spin_unlock(&priv->stream_lock);
mwl8k_destroy_ba(hw, stream);
spin_lock(&priv->stream_lock);
wiphy_debug(hw->wiphy,
"Failed adding stream for sta %pM tid %d\n",
addr, tid);
mwl8k_remove_stream(hw, stream);
}
break;
default:
rc = -ENOTSUPP;
}
spin_unlock(&priv->stream_lock);
return rc;
}
static void mwl8k_finalize_join_worker(struct work_struct *work)
{
struct mwl8k_priv *priv =
container_of(work, struct mwl8k_priv, finalize_join_worker);
struct sk_buff *skb = priv->beacon_skb;
struct ieee80211_mgmt *mgmt = (void *)skb->data;
int len = skb->len - offsetof(struct ieee80211_mgmt, u.beacon.variable);
const u8 *tim = cfg80211_find_ie(WLAN_EID_TIM,
mgmt->u.beacon.variable, len);
int dtim_period = 1;
if (tim && tim[1] >= 2)
dtim_period = tim[3];
mwl8k_cmd_finalize_join(priv->hw, skb->data, skb->len, dtim_period);
dev_kfree_skb(skb);
priv->beacon_skb = NULL;
}
static int mwl8k_request_alt_fw(struct mwl8k_priv *priv)
{
int rc;
printk(KERN_ERR "%s: Error requesting preferred fw %s.\n"
"Trying alternative firmware %s\n", pci_name(priv->pdev),
priv->fw_pref, priv->fw_alt);
rc = mwl8k_request_fw(priv, priv->fw_alt, &priv->fw_ucode, true);
if (rc) {
printk(KERN_ERR "%s: Error requesting alt fw %s\n",
pci_name(priv->pdev), priv->fw_alt);
return rc;
}
return 0;
}
static void mwl8k_fw_state_machine(const struct firmware *fw, void *context)
{
struct mwl8k_priv *priv = context;
struct mwl8k_device_info *di = priv->device_info;
int rc;
switch (priv->fw_state) {
case FW_STATE_INIT:
if (!fw) {
printk(KERN_ERR "%s: Error requesting helper fw %s\n",
pci_name(priv->pdev), di->helper_image);
goto fail;
}
priv->fw_helper = fw;
rc = mwl8k_request_fw(priv, priv->fw_pref, &priv->fw_ucode,
true);
if (rc && priv->fw_alt) {
rc = mwl8k_request_alt_fw(priv);
if (rc)
goto fail;
priv->fw_state = FW_STATE_LOADING_ALT;
} else if (rc)
goto fail;
else
priv->fw_state = FW_STATE_LOADING_PREF;
break;
case FW_STATE_LOADING_PREF:
if (!fw) {
if (priv->fw_alt) {
rc = mwl8k_request_alt_fw(priv);
if (rc)
goto fail;
priv->fw_state = FW_STATE_LOADING_ALT;
} else
goto fail;
} else {
priv->fw_ucode = fw;
rc = mwl8k_firmware_load_success(priv);
if (rc)
goto fail;
else
complete(&priv->firmware_loading_complete);
}
break;
case FW_STATE_LOADING_ALT:
if (!fw) {
printk(KERN_ERR "%s: Error requesting alt fw %s\n",
pci_name(priv->pdev), di->helper_image);
goto fail;
}
priv->fw_ucode = fw;
rc = mwl8k_firmware_load_success(priv);
if (rc)
goto fail;
else
complete(&priv->firmware_loading_complete);
break;
default:
printk(KERN_ERR "%s: Unexpected firmware loading state: %d\n",
MWL8K_NAME, priv->fw_state);
BUG_ON(1);
}
return;
fail:
priv->fw_state = FW_STATE_ERROR;
complete(&priv->firmware_loading_complete);
device_release_driver(&priv->pdev->dev);
mwl8k_release_firmware(priv);
}
static int mwl8k_init_firmware(struct ieee80211_hw *hw, char *fw_image,
bool nowait)
{
struct mwl8k_priv *priv = hw->priv;
int rc;
mwl8k_hw_reset(priv);
rc = mwl8k_request_firmware(priv, fw_image, nowait);
if (rc) {
wiphy_err(hw->wiphy, "Firmware files not found\n");
return rc;
}
if (nowait)
return rc;
rc = mwl8k_load_firmware(hw);
if (rc)
wiphy_err(hw->wiphy, "Cannot start firmware\n");
mwl8k_release_firmware(priv);
return rc;
}
static int mwl8k_init_txqs(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
int rc = 0;
int i;
for (i = 0; i < mwl8k_tx_queues(priv); i++) {
rc = mwl8k_txq_init(hw, i);
if (rc)
break;
if (priv->ap_fw)
iowrite32(priv->txq[i].txd_dma,
priv->sram + priv->txq_offset[i]);
}
return rc;
}
static int mwl8k_probe_hw(struct ieee80211_hw *hw)
{
struct mwl8k_priv *priv = hw->priv;
int rc = 0;
int i;
if (priv->ap_fw) {
priv->rxd_ops = priv->device_info->ap_rxd_ops;
if (priv->rxd_ops == NULL) {
wiphy_err(hw->wiphy,
"Driver does not have AP firmware image support for this hardware\n");
goto err_stop_firmware;
}
} else {
priv->rxd_ops = &rxd_sta_ops;
}
priv->sniffer_enabled = false;
priv->wmm_enabled = false;
priv->pending_tx_pkts = 0;
rc = mwl8k_rxq_init(hw, 0);
if (rc)
goto err_stop_firmware;
rxq_refill(hw, 0, INT_MAX);
priv->num_ampdu_queues = 0;
if (!priv->ap_fw) {
rc = mwl8k_init_txqs(hw);
if (rc)
goto err_free_queues;
}
iowrite32(0, priv->regs + MWL8K_HIU_A2H_INTERRUPT_STATUS);
iowrite32(0, priv->regs + MWL8K_HIU_A2H_INTERRUPT_MASK);
iowrite32(MWL8K_A2H_INT_TX_DONE|MWL8K_A2H_INT_RX_READY|
MWL8K_A2H_INT_BA_WATCHDOG,
priv->regs + MWL8K_HIU_A2H_INTERRUPT_CLEAR_SEL);
iowrite32(MWL8K_A2H_INT_OPC_DONE,
priv->regs + MWL8K_HIU_A2H_INTERRUPT_STATUS_MASK);
rc = request_irq(priv->pdev->irq, mwl8k_interrupt,
IRQF_SHARED, MWL8K_NAME, hw);
if (rc) {
wiphy_err(hw->wiphy, "failed to register IRQ handler\n");
goto err_free_queues;
}
memset(priv->ampdu, 0, sizeof(priv->ampdu));
iowrite32(MWL8K_A2H_EVENTS, priv->regs + MWL8K_HIU_A2H_INTERRUPT_MASK);
if (priv->ap_fw) {
rc = mwl8k_cmd_get_hw_spec_ap(hw);
if (!rc)
rc = mwl8k_init_txqs(hw);
if (!rc)
rc = mwl8k_cmd_set_hw_spec(hw);
} else {
rc = mwl8k_cmd_get_hw_spec_sta(hw);
}
if (rc) {
wiphy_err(hw->wiphy, "Cannot initialise firmware\n");
goto err_free_irq;
}
rc = mwl8k_cmd_radio_disable(hw);
if (rc) {
wiphy_err(hw->wiphy, "Cannot disable\n");
goto err_free_irq;
}
rc = mwl8k_cmd_set_mac_addr(hw, NULL, "\x00\x00\x00\x00\x00\x00");
if (rc) {
wiphy_err(hw->wiphy, "Cannot clear MAC address\n");
goto err_free_irq;
}
iowrite32(0, priv->regs + MWL8K_HIU_A2H_INTERRUPT_MASK);
free_irq(priv->pdev->irq, hw);
wiphy_info(hw->wiphy, "%s v%d, %pm, %s firmware %u.%u.%u.%u\n",
priv->device_info->part_name,
priv->hw_rev, hw->wiphy->perm_addr,
priv->ap_fw ? "AP" : "STA",
(priv->fw_rev >> 24) & 0xff, (priv->fw_rev >> 16) & 0xff,
(priv->fw_rev >> 8) & 0xff, priv->fw_rev & 0xff);
return 0;
err_free_irq:
iowrite32(0, priv->regs + MWL8K_HIU_A2H_INTERRUPT_MASK);
free_irq(priv->pdev->irq, hw);
err_free_queues:
for (i = 0; i < mwl8k_tx_queues(priv); i++)
mwl8k_txq_deinit(hw, i);
mwl8k_rxq_deinit(hw, 0);
err_stop_firmware:
mwl8k_hw_reset(priv);
return rc;
}
static int mwl8k_reload_firmware(struct ieee80211_hw *hw, char *fw_image)
{
int i, rc = 0;
struct mwl8k_priv *priv = hw->priv;
mwl8k_stop(hw);
mwl8k_rxq_deinit(hw, 0);
for (i = 0; i < mwl8k_tx_queues(priv); i++)
mwl8k_txq_deinit(hw, i);
rc = mwl8k_init_firmware(hw, fw_image, false);
if (rc)
goto fail;
rc = mwl8k_probe_hw(hw);
if (rc)
goto fail;
rc = mwl8k_start(hw);
if (rc)
goto fail;
rc = mwl8k_config(hw, ~0);
if (rc)
goto fail;
for (i = 0; i < MWL8K_TX_WMM_QUEUES; i++) {
rc = mwl8k_conf_tx(hw, i, &priv->wmm_params[i]);
if (rc)
goto fail;
}
return rc;
fail:
printk(KERN_WARNING "mwl8k: Failed to reload firmware image.\n");
return rc;
}
static int mwl8k_firmware_load_success(struct mwl8k_priv *priv)
{
struct ieee80211_hw *hw = priv->hw;
int i, rc;
rc = mwl8k_load_firmware(hw);
mwl8k_release_firmware(priv);
if (rc) {
wiphy_err(hw->wiphy, "Cannot start firmware\n");
return rc;
}
hw->extra_tx_headroom =
sizeof(struct mwl8k_dma_data) - sizeof(struct ieee80211_cts);
hw->extra_tx_headroom -= priv->ap_fw ? REDUCED_TX_HEADROOM : 0;
hw->channel_change_time = 10;
hw->queues = MWL8K_TX_WMM_QUEUES;
hw->flags |= IEEE80211_HW_SIGNAL_DBM | IEEE80211_HW_HAS_RATE_CONTROL;
hw->vif_data_size = sizeof(struct mwl8k_vif);
hw->sta_data_size = sizeof(struct mwl8k_sta);
priv->macids_used = 0;
INIT_LIST_HEAD(&priv->vif_list);
priv->radio_on = 0;
priv->radio_short_preamble = 0;
INIT_WORK(&priv->finalize_join_worker, mwl8k_finalize_join_worker);
INIT_WORK(&priv->watchdog_ba_handle, mwl8k_watchdog_ba_events);
tasklet_init(&priv->poll_tx_task, mwl8k_tx_poll, (unsigned long)hw);
tasklet_disable(&priv->poll_tx_task);
tasklet_init(&priv->poll_rx_task, mwl8k_rx_poll, (unsigned long)hw);
tasklet_disable(&priv->poll_rx_task);
priv->cookie = pci_alloc_consistent(priv->pdev, 4, &priv->cookie_dma);
if (priv->cookie == NULL)
return -ENOMEM;
mutex_init(&priv->fw_mutex);
priv->fw_mutex_owner = NULL;
priv->fw_mutex_depth = 0;
priv->hostcmd_wait = NULL;
spin_lock_init(&priv->tx_lock);
spin_lock_init(&priv->stream_lock);
priv->tx_wait = NULL;
rc = mwl8k_probe_hw(hw);
if (rc)
goto err_free_cookie;
hw->wiphy->interface_modes = 0;
if (priv->ap_macids_supported || priv->device_info->fw_image_ap)
hw->wiphy->interface_modes |= BIT(NL80211_IFTYPE_AP);
if (priv->sta_macids_supported || priv->device_info->fw_image_sta)
hw->wiphy->interface_modes |= BIT(NL80211_IFTYPE_STATION);
rc = ieee80211_register_hw(hw);
if (rc) {
wiphy_err(hw->wiphy, "Cannot register device\n");
goto err_unprobe_hw;
}
return 0;
err_unprobe_hw:
for (i = 0; i < mwl8k_tx_queues(priv); i++)
mwl8k_txq_deinit(hw, i);
mwl8k_rxq_deinit(hw, 0);
err_free_cookie:
if (priv->cookie != NULL)
pci_free_consistent(priv->pdev, 4,
priv->cookie, priv->cookie_dma);
return rc;
}
static int __devinit mwl8k_probe(struct pci_dev *pdev,
const struct pci_device_id *id)
{
static int printed_version;
struct ieee80211_hw *hw;
struct mwl8k_priv *priv;
struct mwl8k_device_info *di;
int rc;
if (!printed_version) {
printk(KERN_INFO "%s version %s\n", MWL8K_DESC, MWL8K_VERSION);
printed_version = 1;
}
rc = pci_enable_device(pdev);
if (rc) {
printk(KERN_ERR "%s: Cannot enable new PCI device\n",
MWL8K_NAME);
return rc;
}
rc = pci_request_regions(pdev, MWL8K_NAME);
if (rc) {
printk(KERN_ERR "%s: Cannot obtain PCI resources\n",
MWL8K_NAME);
goto err_disable_device;
}
pci_set_master(pdev);
hw = ieee80211_alloc_hw(sizeof(*priv), &mwl8k_ops);
if (hw == NULL) {
printk(KERN_ERR "%s: ieee80211 alloc failed\n", MWL8K_NAME);
rc = -ENOMEM;
goto err_free_reg;
}
SET_IEEE80211_DEV(hw, &pdev->dev);
pci_set_drvdata(pdev, hw);
priv = hw->priv;
priv->hw = hw;
priv->pdev = pdev;
priv->device_info = &mwl8k_info_tbl[id->driver_data];
priv->sram = pci_iomap(pdev, 0, 0x10000);
if (priv->sram == NULL) {
wiphy_err(hw->wiphy, "Cannot map device SRAM\n");
goto err_iounmap;
}
priv->regs = pci_iomap(pdev, 1, 0x10000);
if (priv->regs == NULL) {
priv->regs = pci_iomap(pdev, 2, 0x10000);
if (priv->regs == NULL) {
wiphy_err(hw->wiphy, "Cannot map device registers\n");
goto err_iounmap;
}
}
init_completion(&priv->firmware_loading_complete);
di = priv->device_info;
if (ap_mode_default && di->fw_image_ap) {
priv->fw_pref = di->fw_image_ap;
priv->fw_alt = di->fw_image_sta;
} else if (!ap_mode_default && di->fw_image_sta) {
priv->fw_pref = di->fw_image_sta;
priv->fw_alt = di->fw_image_ap;
} else if (ap_mode_default && !di->fw_image_ap && di->fw_image_sta) {
printk(KERN_WARNING "AP fw is unavailable. Using STA fw.");
priv->fw_pref = di->fw_image_sta;
} else if (!ap_mode_default && !di->fw_image_sta && di->fw_image_ap) {
printk(KERN_WARNING "STA fw is unavailable. Using AP fw.");
priv->fw_pref = di->fw_image_ap;
}
rc = mwl8k_init_firmware(hw, priv->fw_pref, true);
if (rc)
goto err_stop_firmware;
return rc;
err_stop_firmware:
mwl8k_hw_reset(priv);
err_iounmap:
if (priv->regs != NULL)
pci_iounmap(pdev, priv->regs);
if (priv->sram != NULL)
pci_iounmap(pdev, priv->sram);
pci_set_drvdata(pdev, NULL);
ieee80211_free_hw(hw);
err_free_reg:
pci_release_regions(pdev);
err_disable_device:
pci_disable_device(pdev);
return rc;
}
static void __devexit mwl8k_shutdown(struct pci_dev *pdev)
{
printk(KERN_ERR "===>%s(%u)\n", __func__, __LINE__);
}
static void __devexit mwl8k_remove(struct pci_dev *pdev)
{
struct ieee80211_hw *hw = pci_get_drvdata(pdev);
struct mwl8k_priv *priv;
int i;
if (hw == NULL)
return;
priv = hw->priv;
wait_for_completion(&priv->firmware_loading_complete);
if (priv->fw_state == FW_STATE_ERROR) {
mwl8k_hw_reset(priv);
goto unmap;
}
ieee80211_stop_queues(hw);
ieee80211_unregister_hw(hw);
tasklet_kill(&priv->poll_tx_task);
tasklet_kill(&priv->poll_rx_task);
mwl8k_hw_reset(priv);
for (i = 0; i < mwl8k_tx_queues(priv); i++)
mwl8k_txq_reclaim(hw, i, INT_MAX, 1);
for (i = 0; i < mwl8k_tx_queues(priv); i++)
mwl8k_txq_deinit(hw, i);
mwl8k_rxq_deinit(hw, 0);
pci_free_consistent(priv->pdev, 4, priv->cookie, priv->cookie_dma);
unmap:
pci_iounmap(pdev, priv->regs);
pci_iounmap(pdev, priv->sram);
pci_set_drvdata(pdev, NULL);
ieee80211_free_hw(hw);
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init mwl8k_init(void)
{
return pci_register_driver(&mwl8k_driver);
}
static void __exit mwl8k_exit(void)
{
pci_unregister_driver(&mwl8k_driver);
}
